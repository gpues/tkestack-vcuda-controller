package main

import (
	"encoding/json"
	"github.com/NVIDIA/gpu-monitoring-tools/bindings/go/nvml"
	"io/ioutil"
	"log"
	"os"
	"path/filepath"
	"strconv"
	"strings"
	"sync"
	"time"
)

type Nml struct {
	lock              sync.Mutex
	cache             [][]nvml.ProcessInfo
	once              sync.Once
	driver            string
	kubeletConfigPath string
	cudaCacheDir      string
	mapRecord         map[[2]string]string
}

func (n *Nml) syncUsedGPUPid() {
	n.cache = [][]nvml.ProcessInfo{}
	count, err := nvml.GetDeviceCount()
	if err != nil {

	}
	for i := uint(0); i < count; i++ {
		device, err := nvml.NewDevice(i)
		if err != nil {
		}
		pids, err := device.GetAllRunningProcesses()
		if err != nil {
			return
		}
		n.cache = append(n.cache, pids)
	}
}

const (
	systemd   = "systemd"
	cGroupFs  = "cgroupfs"
	cacheName = "vcuda.cache"
)

func (n *Nml) cGroupDriver() string {
	n.once.Do(func() {
		kubeletConfig, err := ioutil.ReadFile(n.kubeletConfigPath)
		if err != nil {
			log.Fatalln(err)
		}
		content := string(kubeletConfig)
		pos := strings.LastIndex(content, "cgroupDriver:")
		if pos < 0 {
			n.driver = ""
		}
		if strings.Contains(content, systemd) {
			n.driver = systemd
		}
		if strings.Contains(content, cGroupFs) {
			n.driver = cGroupFs
		}
	})
	if n.driver == "" {
		log.Fatalln("can not identify cgroup driver")
	}
	return n.driver
}

func (n *Nml) initDriver() string {
	n.once.Do(func() {
		kubeletConfig, err := ioutil.ReadFile(n.kubeletConfigPath)
		if err != nil {
			log.Fatalln(err)
		}
		content := string(kubeletConfig)
		pos := strings.LastIndex(content, "cgroupDriver:")
		if pos < 0 {
			n.driver = ""
		}
		if strings.Contains(content, systemd) {
			n.driver = systemd
		}
		if strings.Contains(content, cGroupFs) {
			n.driver = cGroupFs
		}
	})
	if n.driver == "" {
		log.Fatalln("can not identify cgroup driver")
	}
	return n.driver
}
func (n *Nml) GetContainerAllGpuPidInfo(QOSClass, podID, containerID string) [][]nvml.ProcessInfo {
	//filename := ""
	//qos := strings.ToLower(QOSClass)
	//switch n.cGroupDriver() {
	//case cGroupFs:
	//	filename = fmt.Sprintf("/sysinfo/fs/cgroup/memory/kubepods/%s/pod%s/%s/tasks", qos, podID, strings.TrimPrefix(containerID, "docker://"))
	//case systemd:
	//	cGroupUid := strings.ReplaceAll(podID, "-", "_")
	//	filename = fmt.Sprintf("/sysinfo/fs/cgroup/systemd/kubepods.slice/kubepods-%s.slice/kubepods-%s-pod%s.slice/docker-%s.scope/tasks", qos, qos, cGroupUid, strings.TrimPrefix(containerID, "docker://"))
	//}
	var pids []string
	content := ``
	//content, _ := os.ReadFile(filename)
	pids = strings.Split(string(content), "\n")
	n.lock.Lock()
	defer n.lock.Unlock()
	var res = make([][]nvml.ProcessInfo, len(n.cache))
	for gpuID, infos := range n.cache {
		var t []nvml.ProcessInfo
		for _, pid := range pids {
			for _, info := range infos {
				if pid == strconv.FormatUint(uint64(info.PID), 10) {
					t = append(t, info)
					break
				}
			}
		}
		res[gpuID] = t
	}
	os.MkdirAll(filepath.Join(n.cudaCacheDir, podID, containerID), os.ModeDir)
	n.mapRecord[[2]string{podID, containerID}] = filepath.Join(n.cudaCacheDir, podID, containerID, cacheName)
	marshal, _ := json.Marshal(res)
	os.WriteFile(n.mapRecord[[2]string{podID, containerID}], marshal, os.ModePerm)
	return res
}

func NewNml(kubeletConfigPath, cudaCacheDir string) *Nml {
	n := &Nml{
		kubeletConfigPath: kubeletConfigPath,
		cudaCacheDir:      cudaCacheDir,
		mapRecord:         map[[2]string]string{},
	}
	n.cGroupDriver()
	go func() {
		ticker := time.NewTicker(time.Second * 5)
		for {
			select {
			case <-ticker.C:
				n.syncUsedGPUPid()
				ticker.Reset(time.Second * 5)
			}
		}
	}()
	return n
}

const defaultMaxFileSize = 100 << 10 // 假设文件最大为 100k
const defaultMemMapSize = 1 << 10    // 假设映射的内存大小为 1k

func main() {
	n := NewNml(
		"/var/lib/kubelet/config.yaml",
		"./cache",
	)
	n.GetContainerAllGpuPidInfo("a", "b", "")
}
