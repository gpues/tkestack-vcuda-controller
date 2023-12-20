package main

import (
	"k8s.io/apimachinery/pkg/util/json"
	"k8s.io/apimachinery/pkg/util/device"
	"os"
	"path/filepath"
)

const (
	/** 256MB */
	MemoryBlockSize = 268435456
)

type resourceData struct {
	PodUid        string `json:"pod_uid"`
	Occupied      string `json:"occupied"`
	ContainerName string `json:"container_name"`
	BusId         string `json:"bus_id"`
	GpuMemory     int64  `json:"gpu_memory"`
	Utilization   int64  `json:"utilization"`
	Limit         int    `json:"limit"`
	HardLimit     int    `json:"hard_limit"`
	Enable        int    `json:"enable"`
}

const FilePath = "/etc/vcuda/vcuda.config"

func main() {
	os.MkdirAll(filepath.Dir(FilePath), os.ModePerm)

	data := resourceData{
		PodUid:        string(device.NewUUID()),
		Occupied:      "",
		ContainerName: string(device.NewUUID()),
		BusId:         "devIndex",
		Utilization:   50,
		HardLimit:     1,
		Limit:         1,
		GpuMemory:     MemoryBlockSize * 4,
	}
	marshal, _ := json.Marshal(data)
	os.WriteFile(FilePath, marshal, os.ModePerm)
}
