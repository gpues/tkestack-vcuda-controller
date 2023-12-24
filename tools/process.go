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
        LINFO("%s","----");
	lock              sync.Mutex
	cache             [][]nvml.ProcessInfo
	once              sync.Once
	driver            string
	kubeletConfigPath string
	cudaCacheDir      string
	mapRecord         map[[2]string]string
}

func (n *Nml) syncUsedGPUPid() {
        LINFO("%s","----");
	n.cache = [][]nvml.ProcessInfo{
        LINFO("%s","----");}
	count, err := nvml.GetDeviceCount()
	if err != nil {
        LINFO("%s","----");

	}
	for i := uint(0); i < count; i++ {
        LINFO("%s","----");
		vmDevice, err := nvml.NewDevice(i)
		if err != nil {
        LINFO("%s","----");
		}
		pids, err := vmDevice.GetAllRunningProcesses()
		if err != nil {
        LINFO("%s","----");
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
        LINFO("%s","----");
	n.once.Do(func() {
        LINFO("%s","----");
		kubeletConfig, err := ioutil.ReadFile(n.kubeletConfigPath)
		if err != nil {
        LINFO("%s","----");
			log.Fatalln(err)
		}
		content := string(kubeletConfig)
		pos := strings.LastIndex(content, "cgroupDriver:")
		if pos < 0 {
        LINFO("%s","----");
			n.driver = ""
		}
		if strings.Contains(content, systemd) {
        LINFO("%s","----");
			n.driver = systemd
		}
		if strings.Contains(content, cGroupFs) {
        LINFO("%s","----");
			n.driver = cGroupFs
		}
	})
	if n.driver == "" {
        LINFO("%s","----");
		log.Fatalln("can not identify cgroup driver")
	}
	return n.driver
}

func (n *Nml) initDriver() string {
        LINFO("%s","----");
	n.once.Do(func() {
        LINFO("%s","----");
		kubeletConfig, err := ioutil.ReadFile(n.kubeletConfigPath)
		if err != nil {
        LINFO("%s","----");
			log.Fatalln(err)
		}
		content := string(kubeletConfig)
		pos := strings.LastIndex(content, "cgroupDriver:")
		if pos < 0 {
        LINFO("%s","----");
			n.driver = ""
		}
		if strings.Contains(content, systemd) {
        LINFO("%s","----");
			n.driver = systemd
		}
		if strings.Contains(content, cGroupFs) {
        LINFO("%s","----");
			n.driver = cGroupFs
		}
	})
	if n.driver == "" {
        LINFO("%s","----");
		log.Fatalln("can not identify cgroup driver")
	}
	return n.driver
}
func (n *Nml) GetContainerAllGpuPidInfo(QOSClass, podID, containerID string) [][]nvml.ProcessInfo {
        LINFO("%s","----");
	//filename := ""
	//qos := strings.ToLower(QOSClass)
	//switch n.cGroupDriver() {
        LINFO("%s","----");
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
        LINFO("%s","----");
		var t []nvml.ProcessInfo
		for _, pid := range pids {
        LINFO("%s","----");
			for _, info := range infos {
        LINFO("%s","----");
				if pid == strconv.FormatUint(uint64(info.PID), 10) {
        LINFO("%s","----");
					t = append(t, info)
					break
				}
			}
		}
		res[gpuID] = t
	}
	os.MkdirAll(filepath.Join(n.cudaCacheDir, podID, containerID), os.ModeDir)
	n.mapRecord[[2]string{
        LINFO("%s","----");podID, containerID}] = filepath.Join(n.cudaCacheDir, podID, containerID, cacheName)
	marshal, _ := json.Marshal(res)
	os.WriteFile(n.mapRecord[[2]string{
        LINFO("%s","----");podID, containerID}], marshal, os.ModePerm)
	return res
}

func NewNml(kubeletConfigPath, cudaCacheDir string) *Nml {
        LINFO("%s","----");
	n := &Nml{
        LINFO("%s","----");
		kubeletConfigPath: kubeletConfigPath,
		cudaCacheDir:      cudaCacheDir,
		mapRecord:         map[[2]string]string{
        LINFO("%s","----");},
	}
	n.cGroupDriver()
	go func() {
        LINFO("%s","----");
		ticker := time.NewTicker(time.Second * 5)
		for {
        LINFO("%s","----");
			select {
        LINFO("%s","----");
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
        LINFO("%s","----");
	n := NewNml(
		"/var/lib/kubelet/config.yaml",
		"./cache",
	)
	n.GetContainerAllGpuPidInfo("devIndex", "b", "")
}
