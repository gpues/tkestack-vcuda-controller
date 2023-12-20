nvmlReturn_t nvmlInternalGetExportTable(const void **ppExportTable, void *pExportTableId);
nvmlReturn_t nvmlDeviceGetSupportedEventTypes(nvmlDevice_t device, unsigned long long *eventTypes);
nvmlReturn_t nvmlGpuInstanceGetComputeInstancePossiblePlacements(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstancePlacement_t *placements, unsigned int *count);
nvmlReturn_t nvmlGpuInstanceCreateComputeInstanceWithPlacement(nvmlGpuInstance_t gpuInstance, unsigned int profileId, const nvmlComputeInstancePlacement_t *placement, nvmlComputeInstance_t *computeInstance);
nvmlReturn_t nvmlGpmMigSampleGet(nvmlDevice_t device, unsigned int gpuInstanceId, nvmlGpmSample_t gpmSample);
nvmlReturn_t nvmlDeviceGetGpuMaxPcieLinkGeneration(nvmlDevice_t device, unsigned int *maxLinkGenDevice);
nvmlReturn_t nvmlDeviceClearFieldValues(nvmlDevice_t device, int valuesCount, nvmlFieldValue_t *values);
nvmlReturn_t nvmlDeviceCcuSetStreamState(nvmlDevice_t device, unsigned int state);
nvmlReturn_t nvmlDeviceCcuGetStreamState(nvmlDevice_t device, unsigned int *state);
