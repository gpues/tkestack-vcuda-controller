
/*
 * On Windows, set up methods for DLL export
 * define NVML_STATIC_IMPORT when using nvml_loader library
 */
#if defined _WINDOWS
#    if !defined NVML_STATIC_IMPORT
#        if defined NVML_LIB_EXPORT
#            define DECLDIR __declspec(dllexport)
#        else
#            define DECLDIR __declspec(dllimport)
#        endif
#    else
#        define DECLDIR
#    endif
#else
#    define DECLDIR
#endif
/**
 * NVML API versioning support
 */
#define NVML_API_VERSION 11
#define NVML_API_VERSION_STR "11"
/**
 * Defining NVML_NO_UNVERSIONED_FUNC_DEFS will disable "auto upgrading" of APIs.
 * e.g. the user will have to call nvmlInit_v2 instead of nvmlInit. Enable this
 * guard if you need to support older versions of the API
 */
#define NVML_STRUCT_VERSION(data, ver) (unsigned int)(sizeof(nvml##data##_v##ver##_t) | (ver << 24U))

/***************************************************************************************************/
/** @defgroup nvmlDeviceStructs Device Structs
 *  @{
 */
/***************************************************************************************************/

/**
 * Special constant that some fields take when they are not available.
 * Used when only part of the struct is not available.
 *
 * Each structure explicitly states when to check for this value.
 */
#define NVML_VALUE_NOT_AVAILABLE (-1)

typedef struct nvmlDevice_st *nvmlDevice_t;

/**
 * Buffer size guaranteed to be large enough for pci bus id
 */
#define NVML_DEVICE_PCI_BUS_ID_BUFFER_SIZE 32

/**
 * Buffer size guaranteed to be large enough for pci bus id for ::busIdLegacy
 */
#define NVML_DEVICE_PCI_BUS_ID_BUFFER_V2_SIZE 16

/**
 * PCI information about a GPU device.
 */
typedef struct nvmlPciInfo_st {
    char busIdLegacy[NVML_DEVICE_PCI_BUS_ID_BUFFER_V2_SIZE]; //!< The legacy tuple domain:bus:device.function PCI identifier (&amp; NULL terminator)
    unsigned int domain;                                     //!< The PCI domain on which the device's bus resides, 0 to 0xffffffff
    unsigned int bus;                                        //!< The bus on which the device resides, 0 to 0xff
    unsigned int device;                                     //!< The device's id on the bus, 0 to 31
    unsigned int pciDeviceId;                                //!< The combined 16-bit device id and 16-bit vendor id

    // Added in NVML 2.285 API
    unsigned int pciSubSystemId; //!< The 32-bit Sub System Device ID

    char busId[NVML_DEVICE_PCI_BUS_ID_BUFFER_SIZE]; //!< The tuple domain:bus:device.function PCI identifier (&amp; NULL terminator)
} nvmlPciInfo_t;

/**
 * PCI format string for ::busIdLegacy
 */
#define NVML_DEVICE_PCI_BUS_ID_LEGACY_FMT "%04X:%02X:%02X.0"

/**
 * PCI format string for ::busId
 */
#define NVML_DEVICE_PCI_BUS_ID_FMT "%08X:%02X:%02X.0"

/**
 * Utility macro for filling the pci bus id format from a nvmlPciInfo_t
 */
#define NVML_DEVICE_PCI_BUS_ID_FMT_ARGS(pciInfo) (pciInfo)->domain, (pciInfo)->bus, (pciInfo)->device

/**
 * Detailed ECC error counts for a device.
 *
 * @deprecated  Different GPU families can have different memory error counters
 *              See \ref nvmlDeviceGetMemoryErrorCounter
 */
typedef struct nvmlEccErrorCounts_st {
    unsigned long long l1Cache;      //!< L1 cache errors
    unsigned long long l2Cache;      //!< L2 cache errors
    unsigned long long deviceMemory; //!< Device memory errors
    unsigned long long registerFile; //!< Register file errors
} nvmlEccErrorCounts_t;

/**
 * Utilization information for a device.
 * Each sample period may be between 1 second and 1/6 second, depending on the product being queried.
 */
typedef struct nvmlUtilization_st {
    unsigned int gpu;    //!< Percent of time over the past sample period during which one or more kernels was executing on the GPU
    unsigned int memory; //!< Percent of time over the past sample period during which global (device) memory was being read or written
} nvmlUtilization_t;

/**
 * Memory allocation information for a device (v1).
 * The total amount is equal to the sum of the amounts of free and used memory.
 */
typedef struct nvmlMemory_st {
    unsigned long long total; //!< Total physical device memory (in bytes)
    unsigned long long free;  //!< Unallocated device memory (in bytes)
    unsigned long long used;  //!< Sum of Reserved and Allocated device memory (in bytes).
    //!< Note that the driver/GPU always sets aside a small amount of memory for bookkeeping
} nvmlMemory_t;

/**
 * Memory allocation information for a device (v2).
 *
 * Version 2 adds versioning for the struct and the amount of system-reserved memory as an output.
 * @note The \ref nvmlMemory_v2_t.used amount also includes the \ref nvmlMemory_v2_t.reserved amount.
 */
typedef struct nvmlMemory_v2_st {
    unsigned int version;        //!< Structure format version (must be 2)
    unsigned long long total;    //!< Total physical device memory (in bytes)
    unsigned long long reserved; //!< Device memory (in bytes) reserved for system use (driver or firmware)
    unsigned long long free;     //!< Unallocated device memory (in bytes)
    unsigned long long used;     //!< Allocated device memory (in bytes). Note that the driver/GPU always sets aside a small amount of memory for bookkeeping
} nvmlMemory_v2_t;

#define nvmlMemory_v2 NVML_STRUCT_VERSION(Memory, 2)

/**
 * BAR1 Memory allocation Information for a device
 */
typedef struct nvmlBAR1Memory_st {
    unsigned long long bar1Total; //!< Total BAR1 Memory (in bytes)
    unsigned long long bar1Free;  //!< Unallocated BAR1 Memory (in bytes)
    unsigned long long bar1Used;  //!< Allocated Used Memory (in bytes)
} nvmlBAR1Memory_t;

/**
 * Information about running compute processes on the GPU, legacy version
 * for older versions of the API.
 */
typedef struct nvmlProcessInfo_v1_st {
    unsigned int pid;                 //!< Process ID
    unsigned long long usedGpuMemory; //!< Amount of used GPU memory in bytes.
    //! Under WDDM, \ref NVML_VALUE_NOT_AVAILABLE is always reported
    //! because Windows KMD manages all the memory and not the NVIDIA driver
} nvmlProcessInfo_v1_t;

/**
 * Information about running compute processes on the GPU
 */
typedef struct nvmlProcessInfo_v2_st {
    unsigned int pid;                 //!< Process ID
    unsigned long long usedGpuMemory; //!< Amount of used GPU memory in bytes.
    //! Under WDDM, \ref NVML_VALUE_NOT_AVAILABLE is always reported
    //! because Windows KMD manages all the memory and not the NVIDIA driver
    unsigned int gpuInstanceId; //!< If MIG is enabled, stores a valid GPU instance ID. gpuInstanceId is set to
    //  0xFFFFFFFF otherwise.
    unsigned int computeInstanceId; //!< If MIG is enabled, stores a valid compute instance ID. computeInstanceId is set to
    //  0xFFFFFFFF otherwise.
} nvmlProcessInfo_v2_t;

/**
 * Information about running compute processes on the GPU
 * Version 2 adds versioning for the struct
 */
typedef struct nvmlProcessInfo_st {
    unsigned int pid;                 //!< Process ID
    unsigned long long usedGpuMemory; //!< Amount of used GPU memory in bytes.
    //! Under WDDM, \ref NVML_VALUE_NOT_AVAILABLE is always reported
    //! because Windows KMD manages all the memory and not the NVIDIA driver
    unsigned int gpuInstanceId; //!< If MIG is enabled, stores a valid GPU instance ID. gpuInstanceId is set to
    //  0xFFFFFFFF otherwise.
    unsigned int computeInstanceId; //!< If MIG is enabled, stores a valid compute instance ID. computeInstanceId is set to
    //  0xFFFFFFFF otherwise.
} nvmlProcessInfo_t;

typedef struct nvmlDeviceAttributes_st {
    unsigned int multiprocessorCount;       //!< Streaming Multiprocessor count
    unsigned int sharedCopyEngineCount;     //!< Shared Copy Engine count
    unsigned int sharedDecoderCount;        //!< Shared Decoder Engine count
    unsigned int sharedEncoderCount;        //!< Shared Encoder Engine count
    unsigned int sharedJpegCount;           //!< Shared JPEG Engine count
    unsigned int sharedOfaCount;            //!< Shared OFA Engine count
    unsigned int gpuInstanceSliceCount;     //!< GPU instance slice count
    unsigned int computeInstanceSliceCount; //!< Compute instance slice count
    unsigned long long memorySizeMB;        //!< Device memory size (in MiB)
} nvmlDeviceAttributes_t;

/**
 * Possible values that classify the remap availability for each bank. The max
 * field will contain the number of banks that have maximum remap availability
 * (all reserved rows are available). None means that there are no reserved
 * rows available.
 */
typedef struct nvmlRowRemapperHistogramValues_st {
    unsigned int max;
    unsigned int high;
    unsigned int partial;
    unsigned int low;
    unsigned int none;
} nvmlRowRemapperHistogramValues_t;

/**
 * Enum to represent type of bridge chip
 */
typedef enum nvmlBridgeChipType_enum { NVML_BRIDGE_CHIP_PLX = 0, NVML_BRIDGE_CHIP_BRO4 = 1 } nvmlBridgeChipType_t;

/**
 * Maximum number of NvLink links supported
 */
#define NVML_NVLINK_MAX_LINKS 18

/**
 * Enum to represent the NvLink utilization counter packet units
 */
typedef enum nvmlNvLinkUtilizationCountUnits_enum {
    NVML_NVLINK_COUNTER_UNIT_CYCLES = 0,   // count by cycles
    NVML_NVLINK_COUNTER_UNIT_PACKETS = 1,  // count by packets
    NVML_NVLINK_COUNTER_UNIT_BYTES = 2,    // count by bytes
    NVML_NVLINK_COUNTER_UNIT_RESERVED = 3, // count reserved for internal use
    // this must be last
    NVML_NVLINK_COUNTER_UNIT_COUNT
} nvmlNvLinkUtilizationCountUnits_t;

/**
 * Enum to represent the NvLink utilization counter packet types to count
 *  ** this is ONLY applicable with the units as packets or bytes
 *  ** as specified in \a nvmlNvLinkUtilizationCountUnits_t
 *  ** all packet filter descriptions are target GPU centric
 *  ** these can be "OR'd" together
 */
typedef enum nvmlNvLinkUtilizationCountPktTypes_enum {
    NVML_NVLINK_COUNTER_PKTFILTER_NOP = 0x1,         // no operation packets
    NVML_NVLINK_COUNTER_PKTFILTER_READ = 0x2,        // read packets
    NVML_NVLINK_COUNTER_PKTFILTER_WRITE = 0x4,       // write packets
    NVML_NVLINK_COUNTER_PKTFILTER_RATOM = 0x8,       // reduction atomic requests
    NVML_NVLINK_COUNTER_PKTFILTER_NRATOM = 0x10,     // non-reduction atomic requests
    NVML_NVLINK_COUNTER_PKTFILTER_FLUSH = 0x20,      // flush requests
    NVML_NVLINK_COUNTER_PKTFILTER_RESPDATA = 0x40,   // responses with data
    NVML_NVLINK_COUNTER_PKTFILTER_RESPNODATA = 0x80, // responses without data
    NVML_NVLINK_COUNTER_PKTFILTER_ALL = 0xFF         // all packets
} nvmlNvLinkUtilizationCountPktTypes_t;

/**
 * Struct to define the NVLINK counter controls
 */
typedef struct nvmlNvLinkUtilizationControl_st {
    nvmlNvLinkUtilizationCountUnits_t units;
    nvmlNvLinkUtilizationCountPktTypes_t pktfilter;
} nvmlNvLinkUtilizationControl_t;

/**
 * Enum to represent NvLink queryable capabilities
 */
typedef enum nvmlNvLinkCapability_enum {
    NVML_NVLINK_CAP_P2P_SUPPORTED = 0,  // P2P over NVLink is supported
    NVML_NVLINK_CAP_SYSMEM_ACCESS = 1,  // Access to system memory is supported
    NVML_NVLINK_CAP_P2P_ATOMICS = 2,    // P2P atomics are supported
    NVML_NVLINK_CAP_SYSMEM_ATOMICS = 3, // System memory atomics are supported
    NVML_NVLINK_CAP_SLI_BRIDGE = 4,     // SLI is supported over this link
    NVML_NVLINK_CAP_VALID = 5,          // Link is supported on this device
    // should be last
    NVML_NVLINK_CAP_COUNT
} nvmlNvLinkCapability_t;

/**
 * Enum to represent NvLink queryable error counters
 */
typedef enum nvmlNvLinkErrorCounter_enum {
    NVML_NVLINK_ERROR_DL_REPLAY = 0,   // Data link transmit replay error counter
    NVML_NVLINK_ERROR_DL_RECOVERY = 1, // Data link transmit recovery error counter
    NVML_NVLINK_ERROR_DL_CRC_FLIT = 2, // Data link receive flow control digit CRC error counter
    NVML_NVLINK_ERROR_DL_CRC_DATA = 3, // Data link receive data CRC error counter
    NVML_NVLINK_ERROR_DL_ECC_DATA = 4, // Data link receive data ECC error counter

    // this must be last
    NVML_NVLINK_ERROR_COUNT
} nvmlNvLinkErrorCounter_t;

/**
 * Enum to represent NvLink's remote device type
 */
typedef enum nvmlIntNvLinkDeviceType_enum { NVML_NVLINK_DEVICE_TYPE_GPU = 0x00, NVML_NVLINK_DEVICE_TYPE_IBMNPU = 0x01, NVML_NVLINK_DEVICE_TYPE_SWITCH = 0x02, NVML_NVLINK_DEVICE_TYPE_UNKNOWN = 0xFF } nvmlIntNvLinkDeviceType_t;

/**
 * Represents level relationships within a system between two GPUs
 * The enums are spaced to allow for future relationships
 */
typedef enum nvmlGpuLevel_enum {
    NVML_TOPOLOGY_INTERNAL = 0,    // e.g. Tesla K80
    NVML_TOPOLOGY_SINGLE = 10,     // all devices that only need traverse a single PCIe switch
    NVML_TOPOLOGY_MULTIPLE = 20,   // all devices that need not traverse a host bridge
    NVML_TOPOLOGY_HOSTBRIDGE = 30, // all devices that are connected to the same host bridge
    NVML_TOPOLOGY_NODE = 40,       // all devices that are connected to the same NUMA node but possibly multiple host bridges
    NVML_TOPOLOGY_SYSTEM = 50      // all devices in the system

    // there is purposefully no COUNT here because of the need for spacing above
} nvmlGpuTopologyLevel_t;

/* Compatibility for CPU->NODE renaming */
#define NVML_TOPOLOGY_CPU NVML_TOPOLOGY_NODE

/* P2P Capability Index Status*/
typedef enum nvmlGpuP2PStatus_enum {
    NVML_P2P_STATUS_OK = 0,
    NVML_P2P_STATUS_CHIPSET_NOT_SUPPORED,
    NVML_P2P_STATUS_GPU_NOT_SUPPORTED,
    NVML_P2P_STATUS_IOH_TOPOLOGY_NOT_SUPPORTED,
    NVML_P2P_STATUS_DISABLED_BY_REGKEY,
    NVML_P2P_STATUS_NOT_SUPPORTED,
    NVML_P2P_STATUS_UNKNOWN

} nvmlGpuP2PStatus_t;

/* P2P Capability Index*/
typedef enum nvmlGpuP2PCapsIndex_enum { NVML_P2P_CAPS_INDEX_READ = 0, NVML_P2P_CAPS_INDEX_WRITE, NVML_P2P_CAPS_INDEX_NVLINK, NVML_P2P_CAPS_INDEX_ATOMICS, NVML_P2P_CAPS_INDEX_PROP, NVML_P2P_CAPS_INDEX_UNKNOWN } nvmlGpuP2PCapsIndex_t;

/**
 * Maximum limit on Physical Bridges per Board
 */
#define NVML_MAX_PHYSICAL_BRIDGE (128)

/**
 * Information about the Bridge Chip Firmware
 */
typedef struct nvmlBridgeChipInfo_st {
    nvmlBridgeChipType_t type; //!< Type of Bridge Chip
    unsigned int fwVersion;    //!< Firmware Version. 0=Version is unavailable
} nvmlBridgeChipInfo_t;

/**
 * This structure stores the complete Hierarchy of the Bridge Chip within the board. The immediate
 * bridge is stored at index 0 of bridgeInfoList, parent to immediate bridge is at index 1 and so forth.
 */
typedef struct nvmlBridgeChipHierarchy_st {
    unsigned char bridgeCount;                                     //!< Number of Bridge Chips on the Board
    nvmlBridgeChipInfo_t bridgeChipInfo[NVML_MAX_PHYSICAL_BRIDGE]; //!< Hierarchy of Bridge Chips on the board
} nvmlBridgeChipHierarchy_t;

/**
 *  Represents Type of Sampling Event
 */
typedef enum nvmlSamplingType_enum {
    NVML_TOTAL_POWER_SAMPLES = 0,        //!< To represent total power drawn by GPU
    NVML_GPU_UTILIZATION_SAMPLES = 1,    //!< To represent percent of time during which one or more kernels was executing on the GPU
    NVML_MEMORY_UTILIZATION_SAMPLES = 2, //!< To represent percent of time during which global (device) memory was being read or written
    NVML_ENC_UTILIZATION_SAMPLES = 3,    //!< To represent percent of time during which NVENC remains busy
    NVML_DEC_UTILIZATION_SAMPLES = 4,    //!< To represent percent of time during which NVDEC remains busy
    NVML_PROCESSOR_CLK_SAMPLES = 5,      //!< To represent processor clock samples
    NVML_MEMORY_CLK_SAMPLES = 6,         //!< To represent memory clock samples

    // Keep this last
    NVML_SAMPLINGTYPE_COUNT
} nvmlSamplingType_t;

/**
 * Represents the queryable PCIe utilization counters
 */
typedef enum nvmlPcieUtilCounter_enum {
    NVML_PCIE_UTIL_TX_BYTES = 0, // 1KB granularity
    NVML_PCIE_UTIL_RX_BYTES = 1, // 1KB granularity

    // Keep this last
    NVML_PCIE_UTIL_COUNT
} nvmlPcieUtilCounter_t;

/**
 * Represents the type for sample value returned
 */
typedef enum nvmlValueType_enum {
    NVML_VALUE_TYPE_DOUBLE = 0,
    NVML_VALUE_TYPE_UNSIGNED_INT = 1,
    NVML_VALUE_TYPE_UNSIGNED_LONG = 2,
    NVML_VALUE_TYPE_UNSIGNED_LONG_LONG = 3,
    NVML_VALUE_TYPE_SIGNED_LONG_LONG = 4,

    // Keep this last
    NVML_VALUE_TYPE_COUNT
} nvmlValueType_t;

/**
 * Union to represent different types of Value
 */
typedef union nvmlValue_st
{
    double dVal;               //!< If the value is double
    unsigned int uiVal;        //!< If the value is unsigned int
    unsigned long ulVal;       //!< If the value is unsigned long
    unsigned long long ullVal; //!< If the value is unsigned long long
    signed long long sllVal;   //!< If the value is signed long long
} nvmlValue_t;

/**
 * Information for Sample
 */
typedef struct nvmlSample_st {
    unsigned long long timeStamp; //!< CPU Timestamp in microseconds
    nvmlValue_t sampleValue;      //!< Sample Value
} nvmlSample_t;

/**
 * Represents type of perf policy for which violation times can be queried
 */
typedef enum nvmlPerfPolicyType_enum {
    NVML_PERF_POLICY_POWER = 0,           //!< How long did power violations cause the GPU to be below application clocks
    NVML_PERF_POLICY_THERMAL = 1,         //!< How long did thermal violations cause the GPU to be below application clocks
    NVML_PERF_POLICY_SYNC_BOOST = 2,      //!< How long did sync boost cause the GPU to be below application clocks
    NVML_PERF_POLICY_BOARD_LIMIT = 3,     //!< How long did the board limit cause the GPU to be below application clocks
    NVML_PERF_POLICY_LOW_UTILIZATION = 4, //!< How long did low utilization cause the GPU to be below application clocks
    NVML_PERF_POLICY_RELIABILITY = 5,     //!< How long did the board reliability limit cause the GPU to be below application clocks

    NVML_PERF_POLICY_TOTAL_APP_CLOCKS = 10,  //!< Total time the GPU was held below application clocks by any limiter (0 - 5 above)
    NVML_PERF_POLICY_TOTAL_BASE_CLOCKS = 11, //!< Total time the GPU was held below base clocks

    // Keep this last
    NVML_PERF_POLICY_COUNT
} nvmlPerfPolicyType_t;

/**
 * Struct to hold perf policy violation status data
 */
typedef struct nvmlViolationTime_st {
    unsigned long long referenceTime; //!< referenceTime represents CPU timestamp in microseconds
    unsigned long long violationTime; //!< violationTime in Nanoseconds
} nvmlViolationTime_t;

#define NVML_MAX_THERMAL_SENSORS_PER_GPU 3

typedef enum {
    NVML_THERMAL_TARGET_NONE = 0,
    NVML_THERMAL_TARGET_GPU = 1,          //!< GPU core temperature requires NvPhysicalGpuHandle
    NVML_THERMAL_TARGET_MEMORY = 2,       //!< GPU memory temperature requires NvPhysicalGpuHandle
    NVML_THERMAL_TARGET_POWER_SUPPLY = 4, //!< GPU power supply temperature requires NvPhysicalGpuHandle
    NVML_THERMAL_TARGET_BOARD = 8,        //!< GPU board ambient temperature requires NvPhysicalGpuHandle
    NVML_THERMAL_TARGET_VCD_BOARD = 9,    //!< Visual Computing Device Board temperature requires NvVisualComputingDeviceHandle
    NVML_THERMAL_TARGET_VCD_INLET = 10,   //!< Visual Computing Device Inlet temperature requires NvVisualComputingDeviceHandle
    NVML_THERMAL_TARGET_VCD_OUTLET = 11,  //!< Visual Computing Device Outlet temperature requires NvVisualComputingDeviceHandle

    NVML_THERMAL_TARGET_ALL = 15,
    NVML_THERMAL_TARGET_UNKNOWN = -1,
} nvmlThermalTarget_t;

typedef enum {
    NVML_THERMAL_CONTROLLER_NONE = 0,
    NVML_THERMAL_CONTROLLER_GPU_INTERNAL,
    NVML_THERMAL_CONTROLLER_ADM1032,
    NVML_THERMAL_CONTROLLER_ADT7461,
    NVML_THERMAL_CONTROLLER_MAX6649,
    NVML_THERMAL_CONTROLLER_MAX1617,
    NVML_THERMAL_CONTROLLER_LM99,
    NVML_THERMAL_CONTROLLER_LM89,
    NVML_THERMAL_CONTROLLER_LM64,
    NVML_THERMAL_CONTROLLER_G781,
    NVML_THERMAL_CONTROLLER_ADT7473,
    NVML_THERMAL_CONTROLLER_SBMAX6649,
    NVML_THERMAL_CONTROLLER_VBIOSEVT,
    NVML_THERMAL_CONTROLLER_OS,
    NVML_THERMAL_CONTROLLER_NVSYSCON_CANOAS,
    NVML_THERMAL_CONTROLLER_NVSYSCON_E551,
    NVML_THERMAL_CONTROLLER_MAX6649R,
    NVML_THERMAL_CONTROLLER_ADT7473S,
    NVML_THERMAL_CONTROLLER_UNKNOWN = -1,
} nvmlThermalController_t;

typedef struct {
    unsigned int count;
    struct {
        nvmlThermalController_t controller;
        int defaultMinTemp;
        int defaultMaxTemp;
        int currentTemp;
        nvmlThermalTarget_t target;
    } sensor[NVML_MAX_THERMAL_SENSORS_PER_GPU];

} nvmlGpuThermalSettings_t;

/** @} */

/***************************************************************************************************/
/** @defgroup nvmlDeviceEnumvs Device Enums
 *  @{
 */
/***************************************************************************************************/

/**
 * Generic enable/disable enum.
 */
typedef enum nvmlEnableState_enum {
    NVML_FEATURE_DISABLED = 0, //!< Feature disabled
    NVML_FEATURE_ENABLED = 1   //!< Feature enabled
} nvmlEnableState_t;

//! Generic flag used to specify the default behavior of some functions. See description of particular functions for details.
#define nvmlFlagDefault 0x00
//! Generic flag used to force some behavior. See description of particular functions for details.
#define nvmlFlagForce 0x01

/**
 *  * The Brand of the GPU
 *   */
typedef enum nvmlBrandType_enum {
    NVML_BRAND_UNKNOWN = 0,
    NVML_BRAND_QUADRO = 1,
    NVML_BRAND_TESLA = 2,
    NVML_BRAND_NVS = 3,
    NVML_BRAND_GRID = 4, // Deprecated from API reporting. Keeping definition for backward compatibility.
    NVML_BRAND_GEFORCE = 5,
    NVML_BRAND_TITAN = 6,
    NVML_BRAND_NVIDIA_VAPPS = 7,                                // NVIDIA Virtual Applications
    NVML_BRAND_NVIDIA_VPC = 8,                                  // NVIDIA Virtual PC
    NVML_BRAND_NVIDIA_VCS = 9,                                  // NVIDIA Virtual Compute Server
    NVML_BRAND_NVIDIA_VWS = 10,                                 // NVIDIA RTX Virtual Workstation
    NVML_BRAND_NVIDIA_CLOUD_GAMING = 11,                        // NVIDIA Cloud Gaming
    NVML_BRAND_NVIDIA_VGAMING = NVML_BRAND_NVIDIA_CLOUD_GAMING, // Deprecated from API reporting. Keeping definition for backward compatibility.
    NVML_BRAND_QUADRO_RTX = 12,
    NVML_BRAND_NVIDIA_RTX = 13,
    NVML_BRAND_NVIDIA = 14,
    NVML_BRAND_GEFORCE_RTX = 15, // Unused
    NVML_BRAND_TITAN_RTX = 16,   // Unused

    // Keep this last
    NVML_BRAND_COUNT
} nvmlBrandType_t;

/**
 * Temperature thresholds.
 */
typedef enum nvmlTemperatureThresholds_enum {
    NVML_TEMPERATURE_THRESHOLD_SHUTDOWN = 0, // Temperature at which the GPU will
    // shut down for HW protection
    NVML_TEMPERATURE_THRESHOLD_SLOWDOWN = 1, // Temperature at which the GPU will
    // begin HW slowdown
    NVML_TEMPERATURE_THRESHOLD_MEM_MAX = 2, // Memory Temperature at which the GPU will
    // begin SW slowdown
    NVML_TEMPERATURE_THRESHOLD_GPU_MAX = 3, // GPU Temperature at which the GPU
    // can be throttled below base clock
    NVML_TEMPERATURE_THRESHOLD_ACOUSTIC_MIN = 4, // Minimum GPU Temperature that can be
    // set as acoustic threshold
    NVML_TEMPERATURE_THRESHOLD_ACOUSTIC_CURR = 5, // Current temperature that is set as
    // acoustic threshold.
    NVML_TEMPERATURE_THRESHOLD_ACOUSTIC_MAX = 6, // Maximum GPU temperature that can be
    // set as acoustic threshold.
    // Keep this last
    NVML_TEMPERATURE_THRESHOLD_COUNT
} nvmlTemperatureThresholds_t;

/**
 * Temperature sensors.
 */
typedef enum nvmlTemperatureSensors_enum {
    NVML_TEMPERATURE_GPU = 0, //!< Temperature sensor for the GPU die

    // Keep this last
    NVML_TEMPERATURE_COUNT
} nvmlTemperatureSensors_t;

/**
 * Compute mode.
 *
 * NVML_COMPUTEMODE_EXCLUSIVE_PROCESS was added in CUDA 4.0.
 * Earlier CUDA versions supported a single exclusive mode,
 * which is equivalent to NVML_COMPUTEMODE_EXCLUSIVE_THREAD in CUDA 4.0 and beyond.
 */
typedef enum nvmlComputeMode_enum {
    NVML_COMPUTEMODE_DEFAULT = 0,           //!< Default compute mode -- multiple contexts per device
    NVML_COMPUTEMODE_EXCLUSIVE_THREAD = 1,  //!< Support Removed
    NVML_COMPUTEMODE_PROHIBITED = 2,        //!< Compute-prohibited mode -- no contexts per device
    NVML_COMPUTEMODE_EXCLUSIVE_PROCESS = 3, //!< Compute-exclusive-process mode -- only one context per device, usable from multiple threads at a time

    // Keep this last
    NVML_COMPUTEMODE_COUNT
} nvmlComputeMode_t;

/**
 * Max Clock Monitors available
 */
#define MAX_CLK_DOMAINS 32

/**
 * Clock Monitor error types
 */
typedef struct nvmlClkMonFaultInfo_struct {
    /**
     * The Domain which faulted
     */
    unsigned int clkApiDomain;

    /**
     * Faults Information
     */
    unsigned int clkDomainFaultMask;
} nvmlClkMonFaultInfo_t;

/**
 * Clock Monitor Status
 */
typedef struct nvmlClkMonStatus_status {
    /**
     * Fault status Indicator
     */
    unsigned int bGlobalStatus;

    /**
     * Total faulted domain numbers
     */
    unsigned int clkMonListSize;

    /**
     * The fault Information structure
     */
    nvmlClkMonFaultInfo_t clkMonList[MAX_CLK_DOMAINS];
} nvmlClkMonStatus_t;

/**
 * ECC bit types.
 *
 * @deprecated See \ref nvmlMemoryErrorType_t for a more flexible type
 */
#define nvmlEccBitType_t nvmlMemoryErrorType_t

/**
 * Single bit ECC errors
 *
 * @deprecated Mapped to \ref NVML_MEMORY_ERROR_TYPE_CORRECTED
 */
#define NVML_SINGLE_BIT_ECC NVML_MEMORY_ERROR_TYPE_CORRECTED

/**
 * Double bit ECC errors
 *
 * @deprecated Mapped to \ref NVML_MEMORY_ERROR_TYPE_UNCORRECTED
 */
#define NVML_DOUBLE_BIT_ECC NVML_MEMORY_ERROR_TYPE_UNCORRECTED

/**
 * Memory error types
 */
typedef enum nvmlMemoryErrorType_enum {
    /**
     * A memory error that was corrected
     *
     * For ECC errors, these are single bit errors
     * For Texture memory, these are errors fixed by resend
     */
    NVML_MEMORY_ERROR_TYPE_CORRECTED = 0,
    /**
     * A memory error that was not corrected
     *
     * For ECC errors, these are double bit errors
     * For Texture memory, these are errors where the resend fails
     */
    NVML_MEMORY_ERROR_TYPE_UNCORRECTED = 1,

    // Keep this last
    NVML_MEMORY_ERROR_TYPE_COUNT //!< Count of memory error types

} nvmlMemoryErrorType_t;

/**
 * ECC counter types.
 *
 * Note: Volatile counts are reset each time the driver loads. On Windows this is once per boot. On Linux this can be more frequent.
 *       On Linux the driver unloads when no active clients exist. If persistence mode is enabled or there is always a driver
 *       client active (e.g. X11), then Linux also sees per-boot behavior. If not, volatile counts are reset each time a compute app
 *       is run.
 */
typedef enum nvmlEccCounterType_enum {
    NVML_VOLATILE_ECC = 0,  //!< Volatile counts are reset each time the driver loads.
    NVML_AGGREGATE_ECC = 1, //!< Aggregate counts persist across reboots (i.e. for the lifetime of the device)

    // Keep this last
    NVML_ECC_COUNTER_TYPE_COUNT //!< Count of memory counter types
} nvmlEccCounterType_t;

/**
 * Clock types.
 *
 * All speeds are in Mhz.
 */
typedef enum nvmlClockType_enum {
    NVML_CLOCK_GRAPHICS = 0, //!< Graphics clock domain
    NVML_CLOCK_SM = 1,       //!< SM clock domain
    NVML_CLOCK_MEM = 2,      //!< Memory clock domain
    NVML_CLOCK_VIDEO = 3,    //!< Video encoder/decoder clock domain

    // Keep this last
    NVML_CLOCK_COUNT //!< Count of clock types
} nvmlClockType_t;

/**
 * Clock Ids.  These are used in combination with nvmlClockType_t
 * to specify a single clock value.
 */
typedef enum nvmlClockId_enum {
    NVML_CLOCK_ID_CURRENT = 0,            //!< Current actual clock value
    NVML_CLOCK_ID_APP_CLOCK_TARGET = 1,   //!< Target application clock
    NVML_CLOCK_ID_APP_CLOCK_DEFAULT = 2,  //!< Default application clock target
    NVML_CLOCK_ID_CUSTOMER_BOOST_MAX = 3, //!< OEM-defined maximum clock rate

    // Keep this last
    NVML_CLOCK_ID_COUNT //!< Count of Clock Ids.
} nvmlClockId_t;

/**
 * Driver models.
 *
 * Windows only.
 */

typedef enum nvmlDriverModel_enum {
    NVML_DRIVER_WDDM = 0, //!< WDDM driver model -- GPU treated as a display device
    NVML_DRIVER_WDM = 1   //!< WDM (TCC) model (recommended) -- GPU treated as a generic device
} nvmlDriverModel_t;

#define NVML_MAX_GPU_PERF_PSTATES 16

/**
 * Allowed PStates.
 */
typedef enum nvmlPStates_enum {
    NVML_PSTATE_0 = 0,       //!< Performance state 0 -- Maximum Performance
    NVML_PSTATE_1 = 1,       //!< Performance state 1
    NVML_PSTATE_2 = 2,       //!< Performance state 2
    NVML_PSTATE_3 = 3,       //!< Performance state 3
    NVML_PSTATE_4 = 4,       //!< Performance state 4
    NVML_PSTATE_5 = 5,       //!< Performance state 5
    NVML_PSTATE_6 = 6,       //!< Performance state 6
    NVML_PSTATE_7 = 7,       //!< Performance state 7
    NVML_PSTATE_8 = 8,       //!< Performance state 8
    NVML_PSTATE_9 = 9,       //!< Performance state 9
    NVML_PSTATE_10 = 10,     //!< Performance state 10
    NVML_PSTATE_11 = 11,     //!< Performance state 11
    NVML_PSTATE_12 = 12,     //!< Performance state 12
    NVML_PSTATE_13 = 13,     //!< Performance state 13
    NVML_PSTATE_14 = 14,     //!< Performance state 14
    NVML_PSTATE_15 = 15,     //!< Performance state 15 -- Minimum Performance
    NVML_PSTATE_UNKNOWN = 32 //!< Unknown performance state
} nvmlPstates_t;

/**
 * GPU Operation Mode
 *
 * GOM allows to reduce power usage and optimize GPU throughput by disabling GPU features.
 *
 * Each GOM is designed to meet specific user needs.
 */
typedef enum nvmlGom_enum {
    NVML_GOM_ALL_ON = 0, //!< Everything is enabled and running at full speed

    NVML_GOM_COMPUTE = 1, //!< Designed for running only compute tasks. Graphics operations
    //!< are not allowed

    NVML_GOM_LOW_DP = 2 //!< Designed for running graphics applications that don't require
    //!< high bandwidth double precision
} nvmlGpuOperationMode_t;

/**
 * Available infoROM objects.
 */
typedef enum nvmlInforomObject_enum {
    NVML_INFOROM_OEM = 0,   //!< An object defined by OEM
    NVML_INFOROM_ECC = 1,   //!< The ECC object determining the level of ECC support
    NVML_INFOROM_POWER = 2, //!< The power management object

    // Keep this last
    NVML_INFOROM_COUNT //!< This counts the number of infoROM objects the driver knows about
} nvmlInforomObject_t;

/**
 * Return values for NVML API calls.
 */
typedef enum nvmlReturn_enum {
    // cppcheck-suppress *
    NVML_SUCCESS = 0,                          //!< The operation was successful
    NVML_ERROR_UNINITIALIZED = 1,              //!< NVML was not first initialized with nvmlInit()
    NVML_ERROR_INVALID_ARGUMENT = 2,           //!< A supplied argument is invalid
    NVML_ERROR_NOT_SUPPORTED = 3,              //!< The requested operation is not available on target device
    NVML_ERROR_NO_PERMISSION = 4,              //!< The current user does not have permission for operation
    NVML_ERROR_ALREADY_INITIALIZED = 5,        //!< Deprecated: Multiple initializations are now allowed through ref counting
    NVML_ERROR_NOT_FOUND = 6,                  //!< A query to find an object was unsuccessful
    NVML_ERROR_INSUFFICIENT_SIZE = 7,          //!< An input argument is not large enough
    NVML_ERROR_INSUFFICIENT_POWER = 8,         //!< A device's external power cables are not properly attached
    NVML_ERROR_DRIVER_NOT_LOADED = 9,          //!< NVIDIA driver is not loaded
    NVML_ERROR_TIMEOUT = 10,                   //!< User provided timeout passed
    NVML_ERROR_IRQ_ISSUE = 11,                 //!< NVIDIA Kernel detected an interrupt issue with a GPU
    NVML_ERROR_LIBRARY_NOT_FOUND = 12,         //!< NVML Shared Library couldn't be found or loaded
    NVML_ERROR_FUNCTION_NOT_FOUND = 13,        //!< Local version of NVML doesn't implement this function
    NVML_ERROR_CORRUPTED_INFOROM = 14,         //!< infoROM is corrupted
    NVML_ERROR_GPU_IS_LOST = 15,               //!< The GPU has fallen off the bus or has otherwise become inaccessible
    NVML_ERROR_RESET_REQUIRED = 16,            //!< The GPU requires a reset before it can be used again
    NVML_ERROR_OPERATING_SYSTEM = 17,          //!< The GPU control device has been blocked by the operating system/cgroups
    NVML_ERROR_LIB_RM_VERSION_MISMATCH = 18,   //!< RM detects a driver/library version mismatch
    NVML_ERROR_IN_USE = 19,                    //!< An operation cannot be performed because the GPU is currently in use
    NVML_ERROR_MEMORY = 20,                    //!< Insufficient memory
    NVML_ERROR_NO_DATA = 21,                   //!< No data
    NVML_ERROR_VGPU_ECC_NOT_SUPPORTED = 22,    //!< The requested vgpu operation is not available on target device, becasue ECC is enabled
    NVML_ERROR_INSUFFICIENT_RESOURCES = 23,    //!< Ran out of critical resources, other than memory
    NVML_ERROR_FREQ_NOT_SUPPORTED = 24,        //!< Ran out of critical resources, other than memory
    NVML_ERROR_ARGUMENT_VERSION_MISMATCH = 25, //!< The provided version is invalid/unsupported
    NVML_ERROR_DEPRECATED = 26,                //!< The requested functionality has been deprecated
    NVML_ERROR_UNKNOWN = 999                   //!< An internal driver error occurred
} nvmlReturn_t;

/**
 * See \ref nvmlDeviceGetMemoryErrorCounter
 */
typedef enum nvmlMemoryLocation_enum {
    NVML_MEMORY_LOCATION_L1_CACHE = 0,       //!< GPU L1 Cache
    NVML_MEMORY_LOCATION_L2_CACHE = 1,       //!< GPU L2 Cache
    NVML_MEMORY_LOCATION_DRAM = 2,           //!< Turing+ DRAM
    NVML_MEMORY_LOCATION_DEVICE_MEMORY = 2,  //!< GPU Device Memory
    NVML_MEMORY_LOCATION_REGISTER_FILE = 3,  //!< GPU Register File
    NVML_MEMORY_LOCATION_TEXTURE_MEMORY = 4, //!< GPU Texture Memory
    NVML_MEMORY_LOCATION_TEXTURE_SHM = 5,    //!< Shared memory
    NVML_MEMORY_LOCATION_CBU = 6,            //!< CBU
    NVML_MEMORY_LOCATION_SRAM = 7,           //!< Turing+ SRAM
    // Keep this last
    NVML_MEMORY_LOCATION_COUNT //!< This counts the number of memory locations the driver knows about
} nvmlMemoryLocation_t;

/**
 * Causes for page retirement
 */
typedef enum nvmlPageRetirementCause_enum {
    NVML_PAGE_RETIREMENT_CAUSE_MULTIPLE_SINGLE_BIT_ECC_ERRORS = 0, //!< Page was retired due to multiple single bit ECC error
    NVML_PAGE_RETIREMENT_CAUSE_DOUBLE_BIT_ECC_ERROR = 1,           //!< Page was retired due to double bit ECC error

    // Keep this last
    NVML_PAGE_RETIREMENT_CAUSE_COUNT
} nvmlPageRetirementCause_t;

/**
 * API types that allow changes to default permission restrictions
 */
typedef enum nvmlRestrictedAPI_enum {
    NVML_RESTRICTED_API_SET_APPLICATION_CLOCKS = 0, //!< APIs that change application clocks, see nvmlDeviceSetApplicationsClocks
    //!< and see nvmlDeviceResetApplicationsClocks
    NVML_RESTRICTED_API_SET_AUTO_BOOSTED_CLOCKS = 1, //!< APIs that enable/disable Auto Boosted clocks
    //!< see nvmlDeviceSetAutoBoostedClocksEnabled
    // Keep this last
    NVML_RESTRICTED_API_COUNT
} nvmlRestrictedAPI_t;

/** @} */

/***************************************************************************************************/
/** @addtogroup virtualGPU
 *  @{
 */
/***************************************************************************************************/
/** @defgroup nvmlVirtualGpuEnums vGPU Enums
 *  @{
 */
/***************************************************************************************************/

/*!
 * GPU virtualization mode types.
 */
typedef enum nvmlGpuVirtualizationMode {
    NVML_GPU_VIRTUALIZATION_MODE_NONE = 0,        //!< Represents Bare Metal GPU
    NVML_GPU_VIRTUALIZATION_MODE_PASSTHROUGH = 1, //!< Device is associated with GPU-Passthorugh
    NVML_GPU_VIRTUALIZATION_MODE_VGPU = 2,        //!< Device is associated with vGPU inside virtual machine.
    NVML_GPU_VIRTUALIZATION_MODE_HOST_VGPU = 3,   //!< Device is associated with VGX hypervisor in vGPU mode
    NVML_GPU_VIRTUALIZATION_MODE_HOST_VSGA = 4    //!< Device is associated with VGX hypervisor in vSGA mode
} nvmlGpuVirtualizationMode_t;

/**
 * Host vGPU modes
 */
typedef enum nvmlHostVgpuMode_enum {
    NVML_HOST_VGPU_MODE_NON_SRIOV = 0, //!< Non SR-IOV mode
    NVML_HOST_VGPU_MODE_SRIOV = 1      //!< SR-IOV mode
} nvmlHostVgpuMode_t;

/*!
 * Types of VM identifiers
 */
typedef enum nvmlVgpuVmIdType {
    NVML_VGPU_VM_ID_DOMAIN_ID = 0, //!< VM ID represents DOMAIN ID
    NVML_VGPU_VM_ID_UUID = 1       //!< VM ID represents UUID
} nvmlVgpuVmIdType_t;

/**
 * vGPU GUEST info state
 */
typedef enum nvmlVgpuGuestInfoState_enum {
    NVML_VGPU_INSTANCE_GUEST_INFO_STATE_UNINITIALIZED = 0, //!< Guest-dependent fields uninitialized
    NVML_VGPU_INSTANCE_GUEST_INFO_STATE_INITIALIZED = 1    //!< Guest-dependent fields initialized
} nvmlVgpuGuestInfoState_t;

/**
 * vGPU software licensable features
 */
typedef enum {
    NVML_GRID_LICENSE_FEATURE_CODE_UNKNOWN = 0,                                              //!< Unknown
    NVML_GRID_LICENSE_FEATURE_CODE_VGPU = 1,                                                 //!< Virtual GPU
    NVML_GRID_LICENSE_FEATURE_CODE_NVIDIA_RTX = 2,                                           //!< Nvidia RTX
    NVML_GRID_LICENSE_FEATURE_CODE_VWORKSTATION = NVML_GRID_LICENSE_FEATURE_CODE_NVIDIA_RTX, //!< Deprecated, do not use.
    NVML_GRID_LICENSE_FEATURE_CODE_GAMING = 3,                                               //!< Gaming
    NVML_GRID_LICENSE_FEATURE_CODE_COMPUTE = 4                                               //!< Compute
} nvmlGridLicenseFeatureCode_t;

/**
 * Status codes for license expiry
 */
#define NVML_GRID_LICENSE_EXPIRY_NOT_AVAILABLE 0  //!< Expiry information not available
#define NVML_GRID_LICENSE_EXPIRY_INVALID 1        //!< Invalid expiry or error fetching expiry
#define NVML_GRID_LICENSE_EXPIRY_VALID 2          //!< Valid expiry
#define NVML_GRID_LICENSE_EXPIRY_NOT_APPLICABLE 3 //!< Expiry not applicable
#define NVML_GRID_LICENSE_EXPIRY_PERMANENT 4      //!< Permanent expiry

/**
 * vGPU queryable capabilities
 */
typedef enum nvmlVgpuCapability_enum {
    NVML_VGPU_CAP_NVLINK_P2P = 0,           //!< P2P over NVLink is supported
    NVML_VGPU_CAP_GPUDIRECT = 1,            //!< GPUDirect capability is supported
    NVML_VGPU_CAP_MULTI_VGPU_EXCLUSIVE = 2, //!< vGPU profile cannot be mixed with other vGPU profiles in same VM
    NVML_VGPU_CAP_EXCLUSIVE_TYPE = 3,       //!< vGPU profile cannot run on a GPU alongside other profiles of different type
    NVML_VGPU_CAP_EXCLUSIVE_SIZE = 4,       //!< vGPU profile cannot run on a GPU alongside other profiles of different size
    // Keep this last
    NVML_VGPU_CAP_COUNT
} nvmlVgpuCapability_t;

/**
 * vGPU driver queryable capabilities
 */
typedef enum nvmlVgpuDriverCapability_enum {
    NVML_VGPU_DRIVER_CAP_HETEROGENEOUS_MULTI_VGPU = 0, //!< Supports mixing of different vGPU profiles within one guest VM
    // Keep this last
    NVML_VGPU_DRIVER_CAP_COUNT
} nvmlVgpuDriverCapability_t;

/**
 * Device vGPU queryable capabilities
 */
typedef enum nvmlDeviceVgpuCapability_enum {
    NVML_DEVICE_VGPU_CAP_FRACTIONAL_MULTI_VGPU = 0,            //!< Fractional vGPU profiles on this GPU can be used in multi-vGPU configurations
    NVML_DEVICE_VGPU_CAP_HETEROGENEOUS_TIMESLICE_PROFILES = 1, //!< Supports concurrent execution of timesliced vGPU profiles of differing types
    NVML_DEVICE_VGPU_CAP_HETEROGENEOUS_TIMESLICE_SIZES = 2,    //!< Supports concurrent execution of timesliced vGPU profiles of differing framebuffer sizes
    // Keep this last
    NVML_DEVICE_VGPU_CAP_COUNT
} nvmlDeviceVgpuCapability_t;

/** @} */

/***************************************************************************************************/

/** @defgroup nvmlVgpuConstants vGPU Constants
 *  @{
 */
/***************************************************************************************************/

/**
 * Buffer size guaranteed to be large enough for \ref nvmlVgpuTypeGetLicense
 */
#define NVML_GRID_LICENSE_BUFFER_SIZE 128

#define NVML_VGPU_NAME_BUFFER_SIZE 64

#define NVML_GRID_LICENSE_FEATURE_MAX_COUNT 3

#define INVALID_GPU_INSTANCE_PROFILE_ID 0xFFFFFFFF

#define INVALID_GPU_INSTANCE_ID 0xFFFFFFFF

/*!
 * Macros for vGPU instance's virtualization capabilities bitfield.
 */
#define NVML_VGPU_VIRTUALIZATION_CAP_MIGRATION 0 : 0
#define NVML_VGPU_VIRTUALIZATION_CAP_MIGRATION_NO 0x0
#define NVML_VGPU_VIRTUALIZATION_CAP_MIGRATION_YES 0x1

/*!
 * Macros for pGPU's virtualization capabilities bitfield.
 */
#define NVML_VGPU_PGPU_VIRTUALIZATION_CAP_MIGRATION 0 : 0
#define NVML_VGPU_PGPU_VIRTUALIZATION_CAP_MIGRATION_NO 0x0
#define NVML_VGPU_PGPU_VIRTUALIZATION_CAP_MIGRATION_YES 0x1

/** @} */

/***************************************************************************************************/
/** @defgroup nvmlVgpuStructs vGPU Structs
 *  @{
 */
/***************************************************************************************************/

typedef unsigned int nvmlVgpuTypeId_t;

typedef unsigned int nvmlVgpuInstance_t;

/**
 * Structure to store Utilization Value and vgpuInstance
 */
typedef struct nvmlVgpuInstanceUtilizationSample_st {
    nvmlVgpuInstance_t vgpuInstance; //!< vGPU Instance
    unsigned long long timeStamp;    //!< CPU Timestamp in microseconds
    nvmlValue_t smUtil;              //!< SM (3D/Compute) Util Value
    nvmlValue_t memUtil;             //!< Frame Buffer Memory Util Value
    nvmlValue_t encUtil;             //!< Encoder Util Value
    nvmlValue_t decUtil;             //!< Decoder Util Value
} nvmlVgpuInstanceUtilizationSample_t;

/**
 * Structure to store Utilization Value, vgpuInstance and subprocess information
 */
typedef struct nvmlVgpuProcessUtilizationSample_st {
    nvmlVgpuInstance_t vgpuInstance;              //!< vGPU Instance
    unsigned int pid;                             //!< PID of process running within the vGPU VM
    char processName[NVML_VGPU_NAME_BUFFER_SIZE]; //!< Name of process running within the vGPU VM
    unsigned long long timeStamp;                 //!< CPU Timestamp in microseconds
    unsigned int smUtil;                          //!< SM (3D/Compute) Util Value
    unsigned int memUtil;                         //!< Frame Buffer Memory Util Value
    unsigned int encUtil;                         //!< Encoder Util Value
    unsigned int decUtil;                         //!< Decoder Util Value
} nvmlVgpuProcessUtilizationSample_t;

/**
 * vGPU scheduler policies
 */
#define NVML_VGPU_SCHEDULER_POLICY_UNKNOWN 0
#define NVML_VGPU_SCHEDULER_POLICY_BEST_EFFORT 1
#define NVML_VGPU_SCHEDULER_POLICY_EQUAL_SHARE 2
#define NVML_VGPU_SCHEDULER_POLICY_FIXED_SHARE 3

#define NVML_SUPPORTED_VGPU_SCHEDULER_POLICY_COUNT 3

#define NVML_SCHEDULER_SW_MAX_LOG_ENTRIES 200

/**
 * Union to represent the vGPU Scheduler Parameters
 */
typedef union
{
    struct {
        unsigned int avgFactor; //!< Average factor in compensating the timeslice for Adaptive Round Robin mode
        unsigned int timeslice; //!< The timeslice in ns for each software run list as configured, or the default value otherwise
    } vgpuSchedDataWithARR;

    struct {
        unsigned int timeslice; //!< The timeslice in ns for each software run list as configured, or the default value otherwise
    } vgpuSchedData;

} nvmlVgpuSchedulerParams_t;

/**
 * Structure to store the state and logs of a software runlist
 */
typedef struct nvmlVgpuSchedulerLogEntries_st {
    unsigned long long timestamp;                //!< Timestamp in ns when this software runlist was preeempted
    unsigned long long timeRunTotal;             //!< Total time in ns this software runlist has run
    unsigned long long timeRun;                  //!< Time in ns this software runlist ran before preemption
    unsigned int swRunlistId;                    //!< Software runlist Id
    unsigned long long targetTimeSlice;          //!< The actual timeslice after deduction
    unsigned long long cumulativePreemptionTime; //!< Preemption time in ns for this SW runlist
} nvmlVgpuSchedulerLogEntry_t;

/**
 * Structure to store a vGPU software scheduler log
 */
typedef struct nvmlVgpuSchedulerLog_st {
    unsigned int engineId;        //!< Engine whose software runlist log entries are fetched
    unsigned int schedulerPolicy; //!< Scheduler policy
    unsigned int isEnabledARR;    //!< Flag to check Adaptive Round Robin scheduler mode
    nvmlVgpuSchedulerParams_t schedulerParams;
    unsigned int entriesCount; //!< Count of log entries fetched
    nvmlVgpuSchedulerLogEntry_t logEntries[NVML_SCHEDULER_SW_MAX_LOG_ENTRIES];
} nvmlVgpuSchedulerLog_t;

/**
 * Structure to store the vGPU scheduler state
 */
typedef struct nvmlVgpuSchedulerGetState_st {
    unsigned int schedulerPolicy; //!< Scheduler policy
    unsigned int isEnabledARR;    //!< Flag to check Adaptive Round Robin scheduler mode
    nvmlVgpuSchedulerParams_t schedulerParams;
} nvmlVgpuSchedulerGetState_t;

/**
 * Union to represent the vGPU Scheduler set Parameters
 */
typedef union
{
    struct {
        unsigned int avgFactor; //!< Average factor in compensating the timeslice for Adaptive Round Robin mode
        unsigned int frequency; //!< Frequency for Adaptive Round Robin mode
    } vgpuSchedDataWithARR;

    struct {
        unsigned int timeslice; //!< The timeslice in ms(milliseconds) for each software run list as configured, or the default value otherwise
    } vgpuSchedData;

} nvmlVgpuSchedulerSetParams_t;

/**
 * Structure to set the vGPU scheduler state
 */
typedef struct nvmlVgpuSchedulerSetState_st {
    unsigned int schedulerPolicy; //!< Scheduler policy
    unsigned int enableARRMode;   //!< Flag to enable/disable Adaptive Round Robin scheduler
    nvmlVgpuSchedulerSetParams_t schedulerParams;
} nvmlVgpuSchedulerSetState_t;

/**
 * Structure to store the vGPU scheduler capabilities
 */
typedef struct nvmlVgpuSchedulerCapabilities_st {
    unsigned int supportedSchedulers[NVML_SUPPORTED_VGPU_SCHEDULER_POLICY_COUNT]; //!< List the supported vGPU schedulers on the device
    unsigned int maxTimeslice;                                                    //!< Maximum timeslice value in ns
    unsigned int minTimeslice;                                                    //!< Minimum timeslice value in ns
    unsigned int isArrModeSupported;                                              //!< Flag to check Adaptive Round Robin mode enabled/disabled.
    unsigned int maxFrequencyForARR;                                              //!< Maximum frequency for Adaptive Round Robin mode
    unsigned int minFrequencyForARR;                                              //!< Minimum frequency for Adaptive Round Robin mode
    unsigned int maxAvgFactorForARR;                                              //!< Maximum averaging factor for Adaptive Round Robin mode
    unsigned int minAvgFactorForARR;                                              //!< Minimum averaging factor for Adaptive Round Robin mode
} nvmlVgpuSchedulerCapabilities_t;

/**
 * Structure to store the vGPU license expiry details
 */
typedef struct nvmlVgpuLicenseExpiry_st {
    unsigned int year;    //!< Year of license expiry
    unsigned short month; //!< Month of license expiry
    unsigned short day;   //!< Day of license expiry
    unsigned short hour;  //!< Hour of license expiry
    unsigned short min;   //!< Minutes of license expiry
    unsigned short sec;   //!< Seconds of license expiry
    unsigned char status; //!< License expiry status
} nvmlVgpuLicenseExpiry_t;

/**
 * vGPU license state
 */
#define NVML_GRID_LICENSE_STATE_UNKNOWN 0                 //!< Unknown state
#define NVML_GRID_LICENSE_STATE_UNINITIALIZED 1           //!< Uninitialized state
#define NVML_GRID_LICENSE_STATE_UNLICENSED_UNRESTRICTED 2 //!< Unlicensed unrestricted state
#define NVML_GRID_LICENSE_STATE_UNLICENSED_RESTRICTED 3   //!< Unlicensed restricted state
#define NVML_GRID_LICENSE_STATE_UNLICENSED 4              //!< Unlicensed state
#define NVML_GRID_LICENSE_STATE_LICENSED 5                //!< Licensed state

typedef struct nvmlVgpuLicenseInfo_st {
    unsigned char isLicensed;              //!< License status
    nvmlVgpuLicenseExpiry_t licenseExpiry; //!< License expiry information
    unsigned int currentState;             //!< Current license state
} nvmlVgpuLicenseInfo_t;

/**
 * Structure to store utilization value and process Id
 */
typedef struct nvmlProcessUtilizationSample_st {
    unsigned int pid;             //!< PID of process
    unsigned long long timeStamp; //!< CPU Timestamp in microseconds
    unsigned int smUtil;          //!< SM (3D/Compute) Util Value
    unsigned int memUtil;         //!< Frame Buffer Memory Util Value
    unsigned int encUtil;         //!< Encoder Util Value
    unsigned int decUtil;         //!< Decoder Util Value
} nvmlProcessUtilizationSample_t;

/**
 * Structure to store license expiry date and time values
 */
typedef struct nvmlGridLicenseExpiry_st {
    unsigned int year;    //!< Year value of license expiry
    unsigned short month; //!< Month value of license expiry
    unsigned short day;   //!< Day value of license expiry
    unsigned short hour;  //!< Hour value of license expiry
    unsigned short min;   //!< Minutes value of license expiry
    unsigned short sec;   //!< Seconds value of license expiry
    unsigned char status; //!< License expiry status
} nvmlGridLicenseExpiry_t;

/**
 * Structure containing vGPU software licensable feature information
 */
typedef struct nvmlGridLicensableFeature_st {
    nvmlGridLicenseFeatureCode_t featureCode;        //!< Licensed feature code
    unsigned int featureState;                       //!< Non-zero if feature is currently licensed, otherwise zero
    char licenseInfo[NVML_GRID_LICENSE_BUFFER_SIZE]; //!< Deprecated.
    char productName[NVML_GRID_LICENSE_BUFFER_SIZE]; //!< Product name of feature
    unsigned int featureEnabled;                     //!< Non-zero if feature is enabled, otherwise zero
    nvmlGridLicenseExpiry_t licenseExpiry;           //!< License expiry structure containing date and time
} nvmlGridLicensableFeature_t;

/**
 * Structure to store vGPU software licensable features
 */
typedef struct nvmlGridLicensableFeatures_st {
    int isGridLicenseSupported;                                                              //!< Non-zero if vGPU Software Licensing is supported on the system, otherwise zero
    unsigned int licensableFeaturesCount;                                                    //!< Entries returned in \a gridLicensableFeatures array
    nvmlGridLicensableFeature_t gridLicensableFeatures[NVML_GRID_LICENSE_FEATURE_MAX_COUNT]; //!< Array of vGPU software licensable features.
} nvmlGridLicensableFeatures_t;

/**
 * GSP firmware
 */
#define NVML_GSP_FIRMWARE_VERSION_BUF_SIZE 0x40

/**
 * Simplified chip architecture
 */
#define NVML_DEVICE_ARCH_KEPLER 2  // Devices based on the NVIDIA Kepler architecture
#define NVML_DEVICE_ARCH_MAXWELL 3 // Devices based on the NVIDIA Maxwell architecture
#define NVML_DEVICE_ARCH_PASCAL 4  // Devices based on the NVIDIA Pascal architecture
#define NVML_DEVICE_ARCH_VOLTA 5   // Devices based on the NVIDIA Volta architecture
#define NVML_DEVICE_ARCH_TURING 6  // Devices based on the NVIDIA Turing architecture

#define NVML_DEVICE_ARCH_AMPERE 7 // Devices based on the NVIDIA Ampere architecture

#define NVML_DEVICE_ARCH_ADA 8 // Devices based on the NVIDIA Ada architecture

#define NVML_DEVICE_ARCH_HOPPER 9 // Devices based on the NVIDIA Hopper architecture

#define NVML_DEVICE_ARCH_UNKNOWN 0xffffffff // Anything else, presumably something newer

typedef unsigned int nvmlDeviceArchitecture_t;

/**
 * PCI bus types
 */
#define NVML_BUS_TYPE_UNKNOWN 0
#define NVML_BUS_TYPE_PCI 1
#define NVML_BUS_TYPE_PCIE 2
#define NVML_BUS_TYPE_FPCI 3
#define NVML_BUS_TYPE_AGP 4

typedef unsigned int nvmlBusType_t;

/**
 * Device Power Modes
 */

/**
 * Device Fan control policy
 */
#define NVML_FAN_POLICY_TEMPERATURE_CONTINOUS_SW 0
#define NVML_FAN_POLICY_MANUAL 1

typedef unsigned int nvmlFanControlPolicy_t;

/**
 * Device Power Source
 */
#define NVML_POWER_SOURCE_AC 0x00000000
#define NVML_POWER_SOURCE_BATTERY 0x00000001

typedef unsigned int nvmlPowerSource_t;

/*
 * Device PCIE link Max Speed
 */
#define NVML_PCIE_LINK_MAX_SPEED_INVALID 0x00000000
#define NVML_PCIE_LINK_MAX_SPEED_2500MBPS 0x00000001
#define NVML_PCIE_LINK_MAX_SPEED_5000MBPS 0x00000002
#define NVML_PCIE_LINK_MAX_SPEED_8000MBPS 0x00000003
#define NVML_PCIE_LINK_MAX_SPEED_16000MBPS 0x00000004
#define NVML_PCIE_LINK_MAX_SPEED_32000MBPS 0x00000005
#define NVML_PCIE_LINK_MAX_SPEED_64000MBPS 0x00000006

/*
 * Adaptive clocking status
 */
#define NVML_ADAPTIVE_CLOCKING_INFO_STATUS_DISABLED 0x00000000
#define NVML_ADAPTIVE_CLOCKING_INFO_STATUS_ENABLED 0x00000001

#define NVML_MAX_GPU_UTILIZATIONS 8
typedef enum nvmlGpuUtilizationDomainId_t {
    NVML_GPU_UTILIZATION_DOMAIN_GPU = 0, //!< Graphics engine domain
    NVML_GPU_UTILIZATION_DOMAIN_FB = 1,  //!< Frame buffer domain
    NVML_GPU_UTILIZATION_DOMAIN_VID = 2, //!< Video engine domain
    NVML_GPU_UTILIZATION_DOMAIN_BUS = 3, //!< Bus interface domain
} nvmlGpuUtilizationDomainId_t;

typedef struct nvmlGpuDynamicPstatesInfo_st {
    unsigned int flags; //!< Reserved for future use
    struct {
        unsigned int bIsPresent;   //!< Set if this utilization domain is present on this GPU
        unsigned int percentage;   //!< Percentage of time where the domain is considered busy in the last 1-second interval
        unsigned int incThreshold; //!< Utilization threshold that can trigger a perf-increasing P-State change when crossed
        unsigned int decThreshold; //!< Utilization threshold that can trigger a perf-decreasing P-State change when crossed
    } utilization[NVML_MAX_GPU_UTILIZATIONS];
} nvmlGpuDynamicPstatesInfo_t;

/** @} */
/** @} */

/***************************************************************************************************/
/** @defgroup nvmlFieldValueEnums Field Value Enums
 *  @{
 */
/***************************************************************************************************/

/**
 * Field Identifiers.
 *
 * All Identifiers pertain to a device. Each ID is only used once and is guaranteed never to change.
 */
#define NVML_FI_DEV_ECC_CURRENT 1 //!< Current ECC mode. 1=Active. 0=Inactive
#define NVML_FI_DEV_ECC_PENDING 2 //!< Pending ECC mode. 1=Active. 0=Inactive
/* ECC Count Totals */
#define NVML_FI_DEV_ECC_SBE_VOL_TOTAL 3 //!< Total single bit volatile ECC errors
#define NVML_FI_DEV_ECC_DBE_VOL_TOTAL 4 //!< Total double bit volatile ECC errors
#define NVML_FI_DEV_ECC_SBE_AGG_TOTAL 5 //!< Total single bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_DBE_AGG_TOTAL 6 //!< Total double bit aggregate (persistent) ECC errors
/* Individual ECC locations */
#define NVML_FI_DEV_ECC_SBE_VOL_L1 7   //!< L1 cache single bit volatile ECC errors
#define NVML_FI_DEV_ECC_DBE_VOL_L1 8   //!< L1 cache double bit volatile ECC errors
#define NVML_FI_DEV_ECC_SBE_VOL_L2 9   //!< L2 cache single bit volatile ECC errors
#define NVML_FI_DEV_ECC_DBE_VOL_L2 10  //!< L2 cache double bit volatile ECC errors
#define NVML_FI_DEV_ECC_SBE_VOL_DEV 11 //!< Device memory single bit volatile ECC errors
#define NVML_FI_DEV_ECC_DBE_VOL_DEV 12 //!< Device memory double bit volatile ECC errors
#define NVML_FI_DEV_ECC_SBE_VOL_REG 13 //!< Register file single bit volatile ECC errors
#define NVML_FI_DEV_ECC_DBE_VOL_REG 14 //!< Register file double bit volatile ECC errors
#define NVML_FI_DEV_ECC_SBE_VOL_TEX 15 //!< Texture memory single bit volatile ECC errors
#define NVML_FI_DEV_ECC_DBE_VOL_TEX 16 //!< Texture memory double bit volatile ECC errors
#define NVML_FI_DEV_ECC_DBE_VOL_CBU 17 //!< CBU double bit volatile ECC errors
#define NVML_FI_DEV_ECC_SBE_AGG_L1 18  //!< L1 cache single bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_DBE_AGG_L1 19  //!< L1 cache double bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_SBE_AGG_L2 20  //!< L2 cache single bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_DBE_AGG_L2 21  //!< L2 cache double bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_SBE_AGG_DEV 22 //!< Device memory single bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_DBE_AGG_DEV 23 //!< Device memory double bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_SBE_AGG_REG 24 //!< Register File single bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_DBE_AGG_REG 25 //!< Register File double bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_SBE_AGG_TEX 26 //!< Texture memory single bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_DBE_AGG_TEX 27 //!< Texture memory double bit aggregate (persistent) ECC errors
#define NVML_FI_DEV_ECC_DBE_AGG_CBU 28 //!< CBU double bit aggregate ECC errors

/* Page Retirement */
#define NVML_FI_DEV_RETIRED_SBE 29     //!< Number of retired pages because of single bit errors
#define NVML_FI_DEV_RETIRED_DBE 30     //!< Number of retired pages because of double bit errors
#define NVML_FI_DEV_RETIRED_PENDING 31 //!< If any pages are pending retirement. 1=yes. 0=no.

/* NvLink Flit Error Counters */
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L0 32    //!< NVLink flow control CRC  Error Counter for Lane 0
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L1 33    //!< NVLink flow control CRC  Error Counter for Lane 1
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L2 34    //!< NVLink flow control CRC  Error Counter for Lane 2
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L3 35    //!< NVLink flow control CRC  Error Counter for Lane 3
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L4 36    //!< NVLink flow control CRC  Error Counter for Lane 4
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L5 37    //!< NVLink flow control CRC  Error Counter for Lane 5
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_TOTAL 38 //!< NVLink flow control CRC  Error Counter total for all Lanes

/* NvLink CRC Data Error Counters */
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L0 39    //!< NVLink data CRC Error Counter for Lane 0
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L1 40    //!< NVLink data CRC Error Counter for Lane 1
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L2 41    //!< NVLink data CRC Error Counter for Lane 2
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L3 42    //!< NVLink data CRC Error Counter for Lane 3
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L4 43    //!< NVLink data CRC Error Counter for Lane 4
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L5 44    //!< NVLink data CRC Error Counter for Lane 5
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_TOTAL 45 //!< NvLink data CRC Error Counter total for all Lanes

/* NvLink Replay Error Counters */
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L0 46    //!< NVLink Replay Error Counter for Lane 0
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L1 47    //!< NVLink Replay Error Counter for Lane 1
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L2 48    //!< NVLink Replay Error Counter for Lane 2
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L3 49    //!< NVLink Replay Error Counter for Lane 3
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L4 50    //!< NVLink Replay Error Counter for Lane 4
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L5 51    //!< NVLink Replay Error Counter for Lane 5
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_TOTAL 52 //!< NVLink Replay Error Counter total for all Lanes

/* NvLink Recovery Error Counters */
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L0 53    //!< NVLink Recovery Error Counter for Lane 0
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L1 54    //!< NVLink Recovery Error Counter for Lane 1
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L2 55    //!< NVLink Recovery Error Counter for Lane 2
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L3 56    //!< NVLink Recovery Error Counter for Lane 3
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L4 57    //!< NVLink Recovery Error Counter for Lane 4
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L5 58    //!< NVLink Recovery Error Counter for Lane 5
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_TOTAL 59 //!< NVLink Recovery Error Counter total for all Lanes

/* NvLink Bandwidth Counters */
/*
 * NVML_FI_DEV_NVLINK_BANDWIDTH_* field values are now deprecated.
 * Please use the following field values instead:
 * NVML_FI_DEV_NVLINK_THROUGHPUT_DATA_TX
 * NVML_FI_DEV_NVLINK_THROUGHPUT_DATA_RX
 * NVML_FI_DEV_NVLINK_THROUGHPUT_RAW_TX
 * NVML_FI_DEV_NVLINK_THROUGHPUT_RAW_RX
 */
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L0 60    //!< NVLink Bandwidth Counter for Counter Set 0, Lane 0
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L1 61    //!< NVLink Bandwidth Counter for Counter Set 0, Lane 1
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L2 62    //!< NVLink Bandwidth Counter for Counter Set 0, Lane 2
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L3 63    //!< NVLink Bandwidth Counter for Counter Set 0, Lane 3
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L4 64    //!< NVLink Bandwidth Counter for Counter Set 0, Lane 4
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L5 65    //!< NVLink Bandwidth Counter for Counter Set 0, Lane 5
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_TOTAL 66 //!< NVLink Bandwidth Counter Total for Counter Set 0, All Lanes

/* NvLink Bandwidth Counters */
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L0 67    //!< NVLink Bandwidth Counter for Counter Set 1, Lane 0
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L1 68    //!< NVLink Bandwidth Counter for Counter Set 1, Lane 1
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L2 69    //!< NVLink Bandwidth Counter for Counter Set 1, Lane 2
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L3 70    //!< NVLink Bandwidth Counter for Counter Set 1, Lane 3
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L4 71    //!< NVLink Bandwidth Counter for Counter Set 1, Lane 4
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L5 72    //!< NVLink Bandwidth Counter for Counter Set 1, Lane 5
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_TOTAL 73 //!< NVLink Bandwidth Counter Total for Counter Set 1, All Lanes

/* NVML Perf Policy Counters */
#define NVML_FI_DEV_PERF_POLICY_POWER 74             //!< Perf Policy Counter for Power Policy
#define NVML_FI_DEV_PERF_POLICY_THERMAL 75           //!< Perf Policy Counter for Thermal Policy
#define NVML_FI_DEV_PERF_POLICY_SYNC_BOOST 76        //!< Perf Policy Counter for Sync boost Policy
#define NVML_FI_DEV_PERF_POLICY_BOARD_LIMIT 77       //!< Perf Policy Counter for Board Limit
#define NVML_FI_DEV_PERF_POLICY_LOW_UTILIZATION 78   //!< Perf Policy Counter for Low GPU Utilization Policy
#define NVML_FI_DEV_PERF_POLICY_RELIABILITY 79       //!< Perf Policy Counter for Reliability Policy
#define NVML_FI_DEV_PERF_POLICY_TOTAL_APP_CLOCKS 80  //!< Perf Policy Counter for Total App Clock Policy
#define NVML_FI_DEV_PERF_POLICY_TOTAL_BASE_CLOCKS 81 //!< Perf Policy Counter for Total Base Clocks Policy

/* Memory temperatures */
#define NVML_FI_DEV_MEMORY_TEMP 82 //!< Memory temperature for the device

/* Energy Counter */
#define NVML_FI_DEV_TOTAL_ENERGY_CONSUMPTION 83 //!< Total energy consumption for the GPU in mJ since the driver was last reloaded

/* NVLink Speed */
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L0 84     //!< NVLink Speed in MBps for Link 0
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L1 85     //!< NVLink Speed in MBps for Link 1
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L2 86     //!< NVLink Speed in MBps for Link 2
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L3 87     //!< NVLink Speed in MBps for Link 3
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L4 88     //!< NVLink Speed in MBps for Link 4
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L5 89     //!< NVLink Speed in MBps for Link 5
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_COMMON 90 //!< Common NVLink Speed in MBps for active links

#define NVML_FI_DEV_NVLINK_LINK_COUNT 91 //!< Number of NVLinks present on the device

#define NVML_FI_DEV_RETIRED_PENDING_SBE 92 //!< If any pages are pending retirement due to SBE. 1=yes. 0=no.
#define NVML_FI_DEV_RETIRED_PENDING_DBE 93 //!< If any pages are pending retirement due to DBE. 1=yes. 0=no.

#define NVML_FI_DEV_PCIE_REPLAY_COUNTER 94          //!< PCIe replay counter
#define NVML_FI_DEV_PCIE_REPLAY_ROLLOVER_COUNTER 95 //!< PCIe replay rollover counter

/* NvLink Flit Error Counters */
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L6 96   //!< NVLink flow control CRC  Error Counter for Lane 6
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L7 97   //!< NVLink flow control CRC  Error Counter for Lane 7
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L8 98   //!< NVLink flow control CRC  Error Counter for Lane 8
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L9 99   //!< NVLink flow control CRC  Error Counter for Lane 9
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L10 100 //!< NVLink flow control CRC  Error Counter for Lane 10
#define NVML_FI_DEV_NVLINK_CRC_FLIT_ERROR_COUNT_L11 101 //!< NVLink flow control CRC  Error Counter for Lane 11

/* NvLink CRC Data Error Counters */
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L6 102  //!< NVLink data CRC Error Counter for Lane 6
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L7 103  //!< NVLink data CRC Error Counter for Lane 7
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L8 104  //!< NVLink data CRC Error Counter for Lane 8
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L9 105  //!< NVLink data CRC Error Counter for Lane 9
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L10 106 //!< NVLink data CRC Error Counter for Lane 10
#define NVML_FI_DEV_NVLINK_CRC_DATA_ERROR_COUNT_L11 107 //!< NVLink data CRC Error Counter for Lane 11

/* NvLink Replay Error Counters */
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L6 108  //!< NVLink Replay Error Counter for Lane 6
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L7 109  //!< NVLink Replay Error Counter for Lane 7
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L8 110  //!< NVLink Replay Error Counter for Lane 8
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L9 111  //!< NVLink Replay Error Counter for Lane 9
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L10 112 //!< NVLink Replay Error Counter for Lane 10
#define NVML_FI_DEV_NVLINK_REPLAY_ERROR_COUNT_L11 113 //!< NVLink Replay Error Counter for Lane 11

/* NvLink Recovery Error Counters */
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L6 114  //!< NVLink Recovery Error Counter for Lane 6
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L7 115  //!< NVLink Recovery Error Counter for Lane 7
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L8 116  //!< NVLink Recovery Error Counter for Lane 8
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L9 117  //!< NVLink Recovery Error Counter for Lane 9
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L10 118 //!< NVLink Recovery Error Counter for Lane 10
#define NVML_FI_DEV_NVLINK_RECOVERY_ERROR_COUNT_L11 119 //!< NVLink Recovery Error Counter for Lane 11

/* NvLink Bandwidth Counters */
/*
 * NVML_FI_DEV_NVLINK_BANDWIDTH_* field values are now deprecated.
 * Please use the following field values instead:
 * NVML_FI_DEV_NVLINK_THROUGHPUT_DATA_TX
 * NVML_FI_DEV_NVLINK_THROUGHPUT_DATA_RX
 * NVML_FI_DEV_NVLINK_THROUGHPUT_RAW_TX
 * NVML_FI_DEV_NVLINK_THROUGHPUT_RAW_RX
 */
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L6 120  //!< NVLink Bandwidth Counter for Counter Set 0, Lane 6
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L7 121  //!< NVLink Bandwidth Counter for Counter Set 0, Lane 7
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L8 122  //!< NVLink Bandwidth Counter for Counter Set 0, Lane 8
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L9 123  //!< NVLink Bandwidth Counter for Counter Set 0, Lane 9
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L10 124 //!< NVLink Bandwidth Counter for Counter Set 0, Lane 10
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C0_L11 125 //!< NVLink Bandwidth Counter for Counter Set 0, Lane 11

/* NvLink Bandwidth Counters */
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L6 126  //!< NVLink Bandwidth Counter for Counter Set 1, Lane 6
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L7 127  //!< NVLink Bandwidth Counter for Counter Set 1, Lane 7
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L8 128  //!< NVLink Bandwidth Counter for Counter Set 1, Lane 8
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L9 129  //!< NVLink Bandwidth Counter for Counter Set 1, Lane 9
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L10 130 //!< NVLink Bandwidth Counter for Counter Set 1, Lane 10
#define NVML_FI_DEV_NVLINK_BANDWIDTH_C1_L11 131 //!< NVLink Bandwidth Counter for Counter Set 1, Lane 11

/* NVLink Speed */
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L6 132  //!< NVLink Speed in MBps for Link 6
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L7 133  //!< NVLink Speed in MBps for Link 7
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L8 134  //!< NVLink Speed in MBps for Link 8
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L9 135  //!< NVLink Speed in MBps for Link 9
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L10 136 //!< NVLink Speed in MBps for Link 10
#define NVML_FI_DEV_NVLINK_SPEED_MBPS_L11 137 //!< NVLink Speed in MBps for Link 11

/**
 * NVLink throughput counters field values
 *
 * Link ID needs to be specified in the scopeId field in nvmlFieldValue_t.
 * A scopeId of UINT_MAX returns aggregate value summed up across all links
 * for the specified counter type in fieldId.
 */
#define NVML_FI_DEV_NVLINK_THROUGHPUT_DATA_TX 138 //!< NVLink TX Data throughput in KiB
#define NVML_FI_DEV_NVLINK_THROUGHPUT_DATA_RX 139 //!< NVLink RX Data throughput in KiB
#define NVML_FI_DEV_NVLINK_THROUGHPUT_RAW_TX 140  //!< NVLink TX Data + protocol overhead in KiB
#define NVML_FI_DEV_NVLINK_THROUGHPUT_RAW_RX 141  //!< NVLink RX Data + protocol overhead in KiB

/* Row Remapper */
#define NVML_FI_DEV_REMAPPED_COR 142     //!< Number of remapped rows due to correctable errors
#define NVML_FI_DEV_REMAPPED_UNC 143     //!< Number of remapped rows due to uncorrectable errors
#define NVML_FI_DEV_REMAPPED_PENDING 144 //!< If any rows are pending remapping. 1=yes 0=no
#define NVML_FI_DEV_REMAPPED_FAILURE 145 //!< If any rows failed to be remapped 1=yes 0=no

/**
 * Remote device NVLink ID
 *
 * Link ID needs to be specified in the scopeId field in nvmlFieldValue_t.
 */
#define NVML_FI_DEV_NVLINK_REMOTE_NVLINK_ID 146 //!< Remote device NVLink ID

/**
 * NVSwitch: connected NVLink count
 */
#define NVML_FI_DEV_NVSWITCH_CONNECTED_LINK_COUNT 147 //!< Number of NVLinks connected to NVSwitch

/* NvLink ECC Data Error Counters
 *
 * Lane ID needs to be specified in the scopeId field in nvmlFieldValue_t.
 *
 */
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L0 148    //!< NVLink data ECC Error Counter for Link 0
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L1 149    //!< NVLink data ECC Error Counter for Link 1
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L2 150    //!< NVLink data ECC Error Counter for Link 2
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L3 151    //!< NVLink data ECC Error Counter for Link 3
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L4 152    //!< NVLink data ECC Error Counter for Link 4
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L5 153    //!< NVLink data ECC Error Counter for Link 5
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L6 154    //!< NVLink data ECC Error Counter for Link 6
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L7 155    //!< NVLink data ECC Error Counter for Link 7
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L8 156    //!< NVLink data ECC Error Counter for Link 8
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L9 157    //!< NVLink data ECC Error Counter for Link 9
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L10 158   //!< NVLink data ECC Error Counter for Link 10
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_L11 159   //!< NVLink data ECC Error Counter for Link 11
#define NVML_FI_DEV_NVLINK_ECC_DATA_ERROR_COUNT_TOTAL 160 //!< NvLink data ECC Error Counter total for all Links

#define NVML_FI_DEV_NVLINK_ERROR_DL_REPLAY 161
#define NVML_FI_DEV_NVLINK_ERROR_DL_RECOVERY 162
#define NVML_FI_DEV_NVLINK_ERROR_DL_CRC 163
#define NVML_FI_DEV_NVLINK_GET_SPEED 164
#define NVML_FI_DEV_NVLINK_GET_STATE 165
#define NVML_FI_DEV_NVLINK_GET_VERSION 166

#define NVML_FI_DEV_NVLINK_GET_POWER_STATE 167
#define NVML_FI_DEV_NVLINK_GET_POWER_THRESHOLD 168

#define NVML_FI_DEV_PCIE_L0_TO_RECOVERY_COUNTER 169

#define NVML_FI_MAX 170 //!< One greater than the largest field ID defined above

/**
 * Information for a Field Value Sample
 */
typedef struct nvmlFieldValue_st {
    unsigned int fieldId;      //!< ID of the NVML field to retrieve. This must be set before any call that uses this struct. See the constants starting with NVML_FI_ above.
    unsigned int scopeId;      //!< Scope ID can represent data used by NVML depending on fieldId's context. For example, for NVLink throughput counter data, scopeId can represent linkId.
    long long timestamp;       //!< CPU Timestamp of this value in microseconds since 1970
    long long latencyUsec;     //!< How long this field value took to update (in usec) within NVML. This may be averaged across several fields that are serviced by the same driver call.
    nvmlValueType_t valueType; //!< Type of the value stored in value
    nvmlReturn_t nvmlReturn;   //!< Return code for retrieving this value. This must be checked before looking at value, as value is undefined if nvmlReturn != NVML_SUCCESS
    nvmlValue_t value;         //!< Value for this field. This is only valid if nvmlReturn == NVML_SUCCESS
} nvmlFieldValue_t;

/** @} */

/***************************************************************************************************/
/** @defgroup nvmlUnitStructs Unit Structs
 *  @{
 */
/***************************************************************************************************/

typedef struct nvmlUnit_st *nvmlUnit_t;

/**
 * Description of HWBC entry
 */
typedef struct nvmlHwbcEntry_st {
    unsigned int hwbcId;
    char firmwareVersion[32];
} nvmlHwbcEntry_t;

/**
 * Fan state enum.
 */
typedef enum nvmlFanState_enum {
    NVML_FAN_NORMAL = 0, //!< Fan is working properly
    NVML_FAN_FAILED = 1  //!< Fan has failed
} nvmlFanState_t;

/**
 * Led color enum.
 */
typedef enum nvmlLedColor_enum {
    NVML_LED_COLOR_GREEN = 0, //!< GREEN, indicates good health
    NVML_LED_COLOR_AMBER = 1  //!< AMBER, indicates problem
} nvmlLedColor_t;

/**
 * LED states for an S-class unit.
 */
typedef struct nvmlLedState_st {
    char cause[256];      //!< If amber, a text description of the cause
    nvmlLedColor_t color; //!< GREEN or AMBER
} nvmlLedState_t;

/**
 * Static S-class unit info.
 */
typedef struct nvmlUnitInfo_st {
    char name[96];            //!< Product name
    char id[96];              //!< Product identifier
    char serial[96];          //!< Product serial number
    char firmwareVersion[96]; //!< Firmware version
} nvmlUnitInfo_t;

/**
 * Power usage information for an S-class unit.
 * The power supply state is a human readable string that equals "Normal" or contains
 * a combination of "Abnormal" plus one or more of the following:
 *
 *    - High voltage
 *    - Fan failure
 *    - Heatsink temperature
 *    - Current limit
 *    - Voltage below UV alarm threshold
 *    - Low-voltage
 *    - SI2C remote off command
 *    - MOD_DISABLE input
 *    - Short pin transition
 */
typedef struct nvmlPSUInfo_st {
    char state[256];      //!< The power supply state
    unsigned int current; //!< PSU current (A)
    unsigned int voltage; //!< PSU voltage (V)
    unsigned int power;   //!< PSU power draw (W)
} nvmlPSUInfo_t;

/**
 * Fan speed reading for a single fan in an S-class unit.
 */
typedef struct nvmlUnitFanInfo_st {
    unsigned int speed;   //!< Fan speed (RPM)
    nvmlFanState_t state; //!< Flag that indicates whether fan is working properly
} nvmlUnitFanInfo_t;

/**
 * Fan speed readings for an entire S-class unit.
 */
typedef struct nvmlUnitFanSpeeds_st {
    nvmlUnitFanInfo_t fans[24]; //!< Fan speed data for each fan
    unsigned int count;         //!< Number of fans in unit
} nvmlUnitFanSpeeds_t;

/** @} */

/***************************************************************************************************/
/** @addtogroup nvmlEvents
 *  @{
 */
/***************************************************************************************************/

/**
 * Handle to an event set
 */
typedef struct nvmlEventSet_st *nvmlEventSet_t;

/** @defgroup nvmlEventType Event Types
 * @{
 * Event Types which user can be notified about.
 * See description of particular functions for details.
 *
 * See \ref nvmlDeviceRegisterEvents and \ref nvmlDeviceGetSupportedEventTypes to check which devices
 * support each event.
 *
 * Types can be combined with bitwise or operator '|' when passed to \ref nvmlDeviceRegisterEvents
 */
//! Event about single bit ECC errors
/**
 * \note A corrected texture memory error is not an ECC error, so it does not generate a single bit event
 */
#define nvmlEventTypeSingleBitEccError 0x0000000000000001LL

//! Event about double bit ECC errors
/**
 * \note An uncorrected texture memory error is not an ECC error, so it does not generate a double bit event
 */
#define nvmlEventTypeDoubleBitEccError 0x0000000000000002LL

//! Event about PState changes
/**
 *  \note On Fermi architecture PState changes are also an indicator that GPU is throttling down due to
 *  no work being executed on the GPU, power capping or thermal capping. In a typical situation,
 *  Fermi-based GPU should stay in P0 for the duration of the execution of the compute process.
 */
#define nvmlEventTypePState 0x0000000000000004LL

//! Event that Xid critical error occurred
#define nvmlEventTypeXidCriticalError 0x0000000000000008LL

//! Event about clock changes
/**
 * Kepler only
 */
#define nvmlEventTypeClock 0x0000000000000010LL

//! Event about AC/Battery power source changes
#define nvmlEventTypePowerSourceChange 0x0000000000000080LL

//! Event about MIG configuration changes
#define nvmlEventMigConfigChange 0x0000000000000100LL

//! Mask with no events
#define nvmlEventTypeNone 0x0000000000000000LL

//! Mask of all events
#define nvmlEventTypeAll (nvmlEventTypeNone | nvmlEventTypeSingleBitEccError | nvmlEventTypeDoubleBitEccError | nvmlEventTypePState | nvmlEventTypeClock | nvmlEventTypeXidCriticalError | nvmlEventTypePowerSourceChange | nvmlEventMigConfigChange)
/** @} */

/**
 * Information about occurred event
 */
typedef struct nvmlEventData_st {
    nvmlDevice_t device;          //!< Specific device where the event occurred
    unsigned long long eventType; //!< Information about what specific event occurred
    unsigned long long eventData; //!< Stores XID error for the device in the event of nvmlEventTypeXidCriticalError,
    //   eventData is 0 for any other event. eventData is set as 999 for unknown xid error.
    unsigned int gpuInstanceId; //!< If MIG is enabled and nvmlEventTypeXidCriticalError event is attributable to a GPU
    //   instance, stores a valid GPU instance ID. gpuInstanceId is set to 0xFFFFFFFF
    //   otherwise.
    unsigned int computeInstanceId; //!< If MIG is enabled and nvmlEventTypeXidCriticalError event is attributable to a
    //   compute instance, stores a valid compute instance ID. computeInstanceId is set to
    //   0xFFFFFFFF otherwise.
} nvmlEventData_t;

/** @} */

/***************************************************************************************************/
/** @addtogroup nvmlClocksThrottleReasons
 *  @{
 */
/***************************************************************************************************/

/** Nothing is running on the GPU and the clocks are dropping to Idle state
 * \note This limiter may be removed in a later release
 */
#define nvmlClocksThrottleReasonGpuIdle 0x0000000000000001LL

/** GPU clocks are limited by current setting of applications clocks
 *
 * @see nvmlDeviceSetApplicationsClocks
 * @see nvmlDeviceGetApplicationsClock
 */
#define nvmlClocksThrottleReasonApplicationsClocksSetting 0x0000000000000002LL

/**
 * @deprecated Renamed to \ref nvmlClocksThrottleReasonApplicationsClocksSetting
 *             as the name describes the situation more accurately.
 */
#define nvmlClocksThrottleReasonUserDefinedClocks nvmlClocksThrottleReasonApplicationsClocksSetting

/** SW Power Scaling algorithm is reducing the clocks below requested clocks
 *
 * @see nvmlDeviceGetPowerUsage
 * @see nvmlDeviceSetPowerManagementLimit
 * @see nvmlDeviceGetPowerManagementLimit
 */
#define nvmlClocksThrottleReasonSwPowerCap 0x0000000000000004LL

/** HW Slowdown (reducing the core clocks by a factor of 2 or more) is engaged
 *
 * This is an indicator of:
 *   - temperature being too high
 *   - External Power Brake Assertion is triggered (e.g. by the system power supply)
 *   - Power draw is too high and Fast Trigger protection is reducing the clocks
 *   - May be also reported during PState or clock change
 *      - This behavior may be removed in a later release.
 *
 * @see nvmlDeviceGetTemperature
 * @see nvmlDeviceGetTemperatureThreshold
 * @see nvmlDeviceGetPowerUsage
 */
#define nvmlClocksThrottleReasonHwSlowdown 0x0000000000000008LL

/** Sync Boost
 *
 * This GPU has been added to a Sync boost group with nvidia-smi or DCGM in
 * order to maximize performance per watt. All GPUs in the sync boost group
 * will boost to the minimum possible clocks across the entire group. Look at
 * the throttle reasons for other GPUs in the system to see why those GPUs are
 * holding this one at lower clocks.
 *
 */
#define nvmlClocksThrottleReasonSyncBoost 0x0000000000000010LL

/** SW Thermal Slowdown
 *
 * This is an indicator of one or more of the following:
 *  - Current GPU temperature above the GPU Max Operating Temperature
 *  - Current memory temperature above the Memory Max Operating Temperature
 *
 */
#define nvmlClocksThrottleReasonSwThermalSlowdown 0x0000000000000020LL

/** HW Thermal Slowdown (reducing the core clocks by a factor of 2 or more) is engaged
 *
 * This is an indicator of:
 *   - temperature being too high
 *
 * @see nvmlDeviceGetTemperature
 * @see nvmlDeviceGetTemperatureThreshold
 * @see nvmlDeviceGetPowerUsage
 */
#define nvmlClocksThrottleReasonHwThermalSlowdown 0x0000000000000040LL

/** HW Power Brake Slowdown (reducing the core clocks by a factor of 2 or more) is engaged
 *
 * This is an indicator of:
 *   - External Power Brake Assertion being triggered (e.g. by the system power supply)
 *
 * @see nvmlDeviceGetTemperature
 * @see nvmlDeviceGetTemperatureThreshold
 * @see nvmlDeviceGetPowerUsage
 */
#define nvmlClocksThrottleReasonHwPowerBrakeSlowdown 0x0000000000000080LL

/** GPU clocks are limited by current setting of Display clocks
 *
 * @see bug 1997531
 */
#define nvmlClocksThrottleReasonDisplayClockSetting 0x0000000000000100LL

/** Bit mask representing no clocks throttling
 *
 * Clocks are as high as possible.
 * */
#define nvmlClocksThrottleReasonNone 0x0000000000000000LL

/** Bit mask representing all supported clocks throttling reasons
 * New reasons might be added to this list in the future
 */
#define nvmlClocksThrottleReasonAll (nvmlClocksThrottleReasonNone | nvmlClocksThrottleReasonGpuIdle | nvmlClocksThrottleReasonApplicationsClocksSetting | nvmlClocksThrottleReasonSwPowerCap | nvmlClocksThrottleReasonHwSlowdown | nvmlClocksThrottleReasonSyncBoost | nvmlClocksThrottleReasonSwThermalSlowdown | nvmlClocksThrottleReasonHwThermalSlowdown | nvmlClocksThrottleReasonHwPowerBrakeSlowdown | nvmlClocksThrottleReasonDisplayClockSetting)
/** @} */

/***************************************************************************************************/
/** @defgroup nvmlAccountingStats Accounting Statistics
 *  @{
 *
 *  Set of APIs designed to provide per process information about usage of GPU.
 *
 *  @note All accounting statistics and accounting mode live in nvidia driver and reset
 *        to default (Disabled) when driver unloads.
 *        It is advised to run with persistence mode enabled.
 *
 *  @note Enabling accounting mode has no negative impact on the GPU performance.
 */
/***************************************************************************************************/

/**
 * Describes accounting statistics of a process.
 */
typedef struct nvmlAccountingStats_st {
    unsigned int gpuUtilization; //!< Percent of time over the process's lifetime during which one or more kernels was executing on the GPU.
    //! Utilization stats just like returned by \ref nvmlDeviceGetUtilizationRates but for the life time of a
    //! process (not just the last sample period).
    //! Set to NVML_VALUE_NOT_AVAILABLE if nvmlDeviceGetUtilizationRates is not supported

    unsigned int memoryUtilization; //!< Percent of time over the process's lifetime during which global (device) memory was being read or written.
    //! Set to NVML_VALUE_NOT_AVAILABLE if nvmlDeviceGetUtilizationRates is not supported

    unsigned long long maxMemoryUsage; //!< Maximum total memory in bytes that was ever allocated by the process.
    //! Set to NVML_VALUE_NOT_AVAILABLE if nvmlProcessInfo_t->usedGpuMemory is not supported

    unsigned long long time; //!< Amount of time in ms during which the compute context was active. The time is reported as 0 if
    //!< the process is not terminated

    unsigned long long startTime; //!< CPU Timestamp in usec representing start time for the process

    unsigned int isRunning; //!< Flag to represent if the process is running (1 for running, 0 for terminated)

    unsigned int reserved[5]; //!< Reserved for future use
} nvmlAccountingStats_t;

/** @} */

/***************************************************************************************************/
/** @defgroup nvmlEncoderStructs Encoder Structs
 *  @{
 */
/***************************************************************************************************/

/**
 * Represents type of encoder for capacity can be queried
 */
typedef enum nvmlEncoderQueryType_enum {
    NVML_ENCODER_QUERY_H264 = 0, //!< H264 encoder
    NVML_ENCODER_QUERY_HEVC = 1  //!< HEVC encoder
} nvmlEncoderType_t;

/**
 * Structure to hold encoder session data
 */
typedef struct nvmlEncoderSessionInfo_st {
    unsigned int sessionId;          //!< Unique session ID
    unsigned int pid;                //!< Owning process ID
    nvmlVgpuInstance_t vgpuInstance; //!< Owning vGPU instance ID (only valid on vGPU hosts, otherwise zero)
    nvmlEncoderType_t codecType;     //!< Video encoder type
    unsigned int hResolution;        //!< Current encode horizontal resolution
    unsigned int vResolution;        //!< Current encode vertical resolution
    unsigned int averageFps;         //!< Moving average encode frames per second
    unsigned int averageLatency;     //!< Moving average encode latency in microseconds
} nvmlEncoderSessionInfo_t;

/** @} */

/***************************************************************************************************/
/** @defgroup nvmlFBCStructs Frame Buffer Capture Structures
 *  @{
 */
/***************************************************************************************************/

/**
 * Represents frame buffer capture session type
 */
typedef enum nvmlFBCSessionType_enum {
    NVML_FBC_SESSION_TYPE_UNKNOWN = 0, //!< Unknwon
    NVML_FBC_SESSION_TYPE_TOSYS,       //!< ToSys
    NVML_FBC_SESSION_TYPE_CUDA,        //!< Cuda
    NVML_FBC_SESSION_TYPE_VID,         //!< Vid
    NVML_FBC_SESSION_TYPE_HWENC        //!< HEnc
} nvmlFBCSessionType_t;

/**
 * Structure to hold frame buffer capture sessions stats
 */
typedef struct nvmlFBCStats_st {
    unsigned int sessionsCount;  //!< Total no of sessions
    unsigned int averageFPS;     //!< Moving average new frames captured per second
    unsigned int averageLatency; //!< Moving average new frame capture latency in microseconds
} nvmlFBCStats_t;

#define NVML_NVFBC_SESSION_FLAG_DIFFMAP_ENABLED 0x00000001            //!< Bit specifying differential map state.
#define NVML_NVFBC_SESSION_FLAG_CLASSIFICATIONMAP_ENABLED 0x00000002  //!< Bit specifying classification map state.
#define NVML_NVFBC_SESSION_FLAG_CAPTURE_WITH_WAIT_NO_WAIT 0x00000004  //!< Bit specifying if capture was requested as non-blocking call.
#define NVML_NVFBC_SESSION_FLAG_CAPTURE_WITH_WAIT_INFINITE 0x00000008 //!< Bit specifying if capture was requested as blocking call.
#define NVML_NVFBC_SESSION_FLAG_CAPTURE_WITH_WAIT_TIMEOUT 0x00000010  //!< Bit specifying if capture was requested as blocking call with timeout period.

/**
 * Structure to hold FBC session data
 */
typedef struct nvmlFBCSessionInfo_st {
    unsigned int sessionId;           //!< Unique session ID
    unsigned int pid;                 //!< Owning process ID
    nvmlVgpuInstance_t vgpuInstance;  //!< Owning vGPU instance ID (only valid on vGPU hosts, otherwise zero)
    unsigned int displayOrdinal;      //!< Display identifier
    nvmlFBCSessionType_t sessionType; //!< Type of frame buffer capture session
    unsigned int sessionFlags;        //!< Session flags (one or more of NVML_NVFBC_SESSION_FLAG_XXX).
    unsigned int hMaxResolution;      //!< Max horizontal resolution supported by the capture session
    unsigned int vMaxResolution;      //!< Max vertical resolution supported by the capture session
    unsigned int hResolution;         //!< Horizontal resolution requested by caller in capture call
    unsigned int vResolution;         //!< Vertical resolution requested by caller in capture call
    unsigned int averageFPS;          //!< Moving average new frames captured per second
    unsigned int averageLatency;      //!< Moving average new frame capture latency in microseconds
} nvmlFBCSessionInfo_t;

/** @} */

/***************************************************************************************************/
/** @defgroup nvmlDrainDefs definitions related to the drain state
 *  @{
 */
/***************************************************************************************************/

/**
 *  Is the GPU device to be removed from the kernel by nvmlDeviceRemoveGpu()
 */
typedef enum nvmlDetachGpuState_enum { NVML_DETACH_GPU_KEEP = 0, NVML_DETACH_GPU_REMOVE } nvmlDetachGpuState_t;

/**
 *  Parent bridge PCIe link state requested by nvmlDeviceRemoveGpu()
 */
typedef enum nvmlPcieLinkState_enum { NVML_PCIE_LINK_KEEP = 0, NVML_PCIE_LINK_SHUT_DOWN } nvmlPcieLinkState_t;

/** @} */

#define NVML_GPU_FABRIC_UUID_LEN 16

#define NVML_GPU_FABRIC_STATE_NOT_SUPPORTED 0
#define NVML_GPU_FABRIC_STATE_NOT_STARTED 1
#define NVML_GPU_FABRIC_STATE_IN_PROGRESS 2
#define NVML_GPU_FABRIC_STATE_COMPLETED 3

typedef unsigned char nvmlGpuFabricState_t;

typedef struct {
    char clusterUuid[NVML_GPU_FABRIC_UUID_LEN]; //!< Uuid of the cluster to which this GPU belongs
    nvmlReturn_t status;                        //!< Error status, if any. Must be checked only if state returns "complete".
    unsigned int partitionId;                   //!< ID of the fabric partition to which this GPU belongs
    nvmlGpuFabricState_t state;                 //!< Current state of GPU registration process
} nvmlGpuFabricInfo_t;
/** @} */

/***************************************************************************************************/
/** @defgroup nvmlConstants Constants
 *  @{
 */
/***************************************************************************************************/

/**
 * Buffer size guaranteed to be large enough for \ref nvmlDeviceGetInforomVersion and \ref nvmlDeviceGetInforomImageVersion
 */
#define NVML_DEVICE_INFOROM_VERSION_BUFFER_SIZE 16

/**
 * Buffer size guaranteed to be large enough for storing GPU identifiers.
 */
#define NVML_DEVICE_UUID_BUFFER_SIZE 80

/**
 * Buffer size guaranteed to be large enough for \ref nvmlDeviceGetUUID
 */
#define NVML_DEVICE_UUID_V2_BUFFER_SIZE 96

/**
 * Buffer size guaranteed to be large enough for \ref nvmlDeviceGetBoardPartNumber
 */
#define NVML_DEVICE_PART_NUMBER_BUFFER_SIZE 80

/**
 * Buffer size guaranteed to be large enough for \ref nvmlSystemGetDriverVersion
 */
#define NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE 80

/**
 * Buffer size guaranteed to be large enough for \ref nvmlSystemGetNVMLVersion
 */
#define NVML_SYSTEM_NVML_VERSION_BUFFER_SIZE 80

/**
 * Buffer size guaranteed to be large enough for storing GPU device names.
 */
#define NVML_DEVICE_NAME_BUFFER_SIZE 64

/**
 * Buffer size guaranteed to be large enough for \ref nvmlDeviceGetName
 */
#define NVML_DEVICE_NAME_V2_BUFFER_SIZE 96

/**
 * Buffer size guaranteed to be large enough for \ref nvmlDeviceGetSerial
 */
#define NVML_DEVICE_SERIAL_BUFFER_SIZE 30

/**
 * Buffer size guaranteed to be large enough for \ref nvmlDeviceGetVbiosVersion
 */
#define NVML_DEVICE_VBIOS_VERSION_BUFFER_SIZE 32

/** @} */

/***************************************************************************************************/
/** @defgroup GPM NVML GPM
 *  @{
 */
/***************************************************************************************************/
/** @defgroup nvmlGpmEnums GPM Enums
 *  @{
 */
/***************************************************************************************************/

/* GPM Metric Identifiers */
typedef enum {
    NVML_GPM_METRIC_GRAPHICS_UTIL = 1,            /* Percentage of time any compute/graphics app was active on the GPU. 0.0 - 100.0 */
    NVML_GPM_METRIC_SM_UTIL = 2,                  /* Percentage of SMs that were busy. 0.0 - 100.0 */
    NVML_GPM_METRIC_SM_OCCUPANCY = 3,             /* Percentage of warps that were active vs theoretical maximum. 0.0 - 100.0 */
    NVML_GPM_METRIC_INTEGER_UTIL = 4,             /* Percentage of time the GPU's SMs were doing integer operations. 0.0 - 100.0 */
    NVML_GPM_METRIC_ANY_TENSOR_UTIL = 5,          /* Percentage of time the GPU's SMs were doing ANY tensor operations. 0.0 - 100.0 */
    NVML_GPM_METRIC_DFMA_TENSOR_UTIL = 6,         /* Percentage of time the GPU's SMs were doing DFMA tensor operations. 0.0 - 100.0 */
    NVML_GPM_METRIC_HMMA_TENSOR_UTIL = 7,         /* Percentage of time the GPU's SMs were doing HMMA tensor operations. 0.0 - 100.0 */
    NVML_GPM_METRIC_IMMA_TENSOR_UTIL = 9,         /* Percentage of time the GPU's SMs were doing IMMA tensor operations. 0.0 - 100.0 */
    NVML_GPM_METRIC_DRAM_BW_UTIL = 10,            /* Percentage of DRAM bw used vs theoretical maximum. 0.0 - 100.0 */
    NVML_GPM_METRIC_FP64_UTIL = 11,               /* Percentage of time the GPU's SMs were doing non-tensor FP64 math. 0.0 - 100.0 */
    NVML_GPM_METRIC_FP32_UTIL = 12,               /* Percentage of time the GPU's SMs were doing non-tensor FP32 math. 0.0 - 100.0 */
    NVML_GPM_METRIC_FP16_UTIL = 13,               /* Percentage of time the GPU's SMs were doing non-tensor FP16 math. 0.0 - 100.0 */
    NVML_GPM_METRIC_PCIE_TX_PER_SEC = 20,         /* PCIe traffic from this GPU in MiB/sec */
    NVML_GPM_METRIC_PCIE_RX_PER_SEC = 21,         /* PCIe traffic to this GPU in MiB/sec */
    NVML_GPM_METRIC_NVDEC_0_UTIL = 30,            /* Percent utilization of NVDEC 0. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVDEC_1_UTIL = 31,            /* Percent utilization of NVDEC 1. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVDEC_2_UTIL = 32,            /* Percent utilization of NVDEC 2. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVDEC_3_UTIL = 33,            /* Percent utilization of NVDEC 3. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVDEC_4_UTIL = 34,            /* Percent utilization of NVDEC 4. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVDEC_5_UTIL = 35,            /* Percent utilization of NVDEC 5. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVDEC_6_UTIL = 36,            /* Percent utilization of NVDEC 6. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVDEC_7_UTIL = 37,            /* Percent utilization of NVDEC 7. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVJPG_0_UTIL = 40,            /* Percent utilization of NVJPG 0. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVJPG_1_UTIL = 41,            /* Percent utilization of NVJPG 1. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVJPG_2_UTIL = 42,            /* Percent utilization of NVJPG 2. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVJPG_3_UTIL = 43,            /* Percent utilization of NVJPG 3. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVJPG_4_UTIL = 44,            /* Percent utilization of NVJPG 4. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVJPG_5_UTIL = 45,            /* Percent utilization of NVJPG 5. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVJPG_6_UTIL = 46,            /* Percent utilization of NVJPG 6. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVJPG_7_UTIL = 47,            /* Percent utilization of NVJPG 7. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVOFA_0_UTIL = 50,            /* Percent utilization of NVOFA 0. 0.0 - 100.0 */
    NVML_GPM_METRIC_NVLINK_TOTAL_RX_PER_SEC = 60, /* NvLink read bandwidth for all links in MiB/sec */
    NVML_GPM_METRIC_NVLINK_TOTAL_TX_PER_SEC = 61, /* NvLink write bandwidth for all links in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L0_RX_PER_SEC = 62,    /* NvLink read bandwidth for link 0 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L0_TX_PER_SEC = 63,    /* NvLink write bandwidth for link 0 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L1_RX_PER_SEC = 64,    /* NvLink read bandwidth for link 1 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L1_TX_PER_SEC = 65,    /* NvLink write bandwidth for link 1 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L2_RX_PER_SEC = 66,    /* NvLink read bandwidth for link 2 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L2_TX_PER_SEC = 67,    /* NvLink write bandwidth for link 2 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L3_RX_PER_SEC = 68,    /* NvLink read bandwidth for link 3 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L3_TX_PER_SEC = 69,    /* NvLink write bandwidth for link 3 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L4_RX_PER_SEC = 70,    /* NvLink read bandwidth for link 4 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L4_TX_PER_SEC = 71,    /* NvLink write bandwidth for link 4 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L5_RX_PER_SEC = 72,    /* NvLink read bandwidth for link 5 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L5_TX_PER_SEC = 73,    /* NvLink write bandwidth for link 5 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L6_RX_PER_SEC = 74,    /* NvLink read bandwidth for link 6 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L6_TX_PER_SEC = 75,    /* NvLink write bandwidth for link 6 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L7_RX_PER_SEC = 76,    /* NvLink read bandwidth for link 7 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L7_TX_PER_SEC = 77,    /* NvLink write bandwidth for link 7 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L8_RX_PER_SEC = 78,    /* NvLink read bandwidth for link 8 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L8_TX_PER_SEC = 79,    /* NvLink write bandwidth for link 8 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L9_RX_PER_SEC = 80,    /* NvLink read bandwidth for link 9 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L9_TX_PER_SEC = 81,    /* NvLink write bandwidth for link 9 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L10_RX_PER_SEC = 82,   /* NvLink read bandwidth for link 10 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L10_TX_PER_SEC = 83,   /* NvLink write bandwidth for link 10 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L11_RX_PER_SEC = 84,   /* NvLink read bandwidth for link 11 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L11_TX_PER_SEC = 85,   /* NvLink write bandwidth for link 11 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L12_RX_PER_SEC = 86,   /* NvLink read bandwidth for link 12 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L12_TX_PER_SEC = 87,   /* NvLink write bandwidth for link 12 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L13_RX_PER_SEC = 88,   /* NvLink read bandwidth for link 13 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L13_TX_PER_SEC = 89,   /* NvLink write bandwidth for link 13 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L14_RX_PER_SEC = 90,   /* NvLink read bandwidth for link 14 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L14_TX_PER_SEC = 91,   /* NvLink write bandwidth for link 14 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L15_RX_PER_SEC = 92,   /* NvLink read bandwidth for link 15 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L15_TX_PER_SEC = 93,   /* NvLink write bandwidth for link 15 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L16_RX_PER_SEC = 94,   /* NvLink read bandwidth for link 16 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L16_TX_PER_SEC = 95,   /* NvLink write bandwidth for link 16 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L17_RX_PER_SEC = 96,   /* NvLink read bandwidth for link 17 in MiB/sec */
    NVML_GPM_METRIC_NVLINK_L17_TX_PER_SEC = 97,   /* NvLink write bandwidth for link 17 in MiB/sec */
    NVML_GPM_METRIC_MAX = 98,                     /* Maximum value above +1. Note that changing this
                                                                         should also change NVML_GPM_METRICS_GET_VERSION
                                                                         due to struct size change */
} nvmlGpmMetricId_t;

/** @} */ // @defgroup nvmlGpmEnums

/***************************************************************************************************/
/** @defgroup nvmlGpmStructs GPM Structs
 *  @{
 */
/***************************************************************************************************/

/* Handle to an allocated GPM sample allocated with nvmlGpmSampleAlloc()
   Free this with nvmlGpmSampleFree() */
typedef struct nvmlGpmSample_st *nvmlGpmSample_t;

typedef struct {
    unsigned int metricId;   /*  IN: NVML_GPM_METRIC_? #define of which metric to retrieve */
    nvmlReturn_t nvmlReturn; /* OUT: Status of this metric. If this is nonzero, then value is not valid */
    double value;            /* OUT: Value of this metric. Is only valid if nvmlReturn is 0 (NVML_SUCCESS) */
    struct {
        char *shortName;
        char *longName;
        char *unit;
    } metricInfo; /* OUT: Metric name and unit. Those can be NULL if not defined */
} nvmlGpmMetric_t;

typedef struct {
    unsigned int version;                         /* IN: Set to NVML_GPM_METRICS_GET_VERSION */
    unsigned int numMetrics;                      /* IN: How many metrics to retrieve in metrics[] */
    nvmlGpmSample_t sample1;                      /* IN: Sample buffer */
    nvmlGpmSample_t sample2;                      /* IN: Sample buffer */
    nvmlGpmMetric_t metrics[NVML_GPM_METRIC_MAX]; /* IN/OUT: Array of metrics. Set metricId on call.
                                                       see nvmlReturn and value on return */
} nvmlGpmMetricsGet_t;

#define NVML_GPM_METRICS_GET_VERSION 1

typedef struct {
    unsigned int version;           /* IN: Set to NVML_GPM_SUPPORT_VERSION */
    unsigned int isSupportedDevice; /* OUT: Indicates device support */
} nvmlGpmSupport_t;

#define NVML_GPM_SUPPORT_VERSION 1

/***************************************************************************************************/
/** @defgroup nvmlMultiInstanceGPU Multi Instance GPU Management
 * This chapter describes NVML operations that are associated with Multi Instance GPU management.
 *  @{
 */
/***************************************************************************************************/

/**
 * Disable Multi Instance GPU mode.
 */
#define NVML_DEVICE_MIG_DISABLE 0x0

/**
 * Enable Multi Instance GPU mode.
 */
#define NVML_DEVICE_MIG_ENABLE 0x1

/**
 * GPU instance profiles.
 *
 * These macros should be passed to \ref nvmlDeviceGetGpuInstanceProfileInfo to retrieve the
 * detailed information about a GPU instance such as profile ID, engine counts.
 */
#define NVML_GPU_INSTANCE_PROFILE_1_SLICE 0x0
#define NVML_GPU_INSTANCE_PROFILE_2_SLICE 0x1
#define NVML_GPU_INSTANCE_PROFILE_3_SLICE 0x2
#define NVML_GPU_INSTANCE_PROFILE_4_SLICE 0x3
#define NVML_GPU_INSTANCE_PROFILE_7_SLICE 0x4
#define NVML_GPU_INSTANCE_PROFILE_8_SLICE 0x5
#define NVML_GPU_INSTANCE_PROFILE_6_SLICE 0x6
#define NVML_GPU_INSTANCE_PROFILE_1_SLICE_REV1 0x7
#define NVML_GPU_INSTANCE_PROFILE_2_SLICE_REV1 0x8
#define NVML_GPU_INSTANCE_PROFILE_1_SLICE_REV2 0x9
#define NVML_GPU_INSTANCE_PROFILE_COUNT 0xA

typedef struct nvmlGpuInstancePlacement_st {
    unsigned int start; //!< Index of first occupied memory slice
    unsigned int size;  //!< Number of memory slices occupied
} nvmlGpuInstancePlacement_t;

/**
 * GPU instance profile information.
 */
typedef struct nvmlGpuInstanceProfileInfo_st {
    unsigned int id;                  //!< Unique profile ID within the device
    unsigned int isP2pSupported;      //!< Peer-to-Peer support
    unsigned int sliceCount;          //!< GPU Slice count
    unsigned int instanceCount;       //!< GPU instance count
    unsigned int multiprocessorCount; //!< Streaming Multiprocessor count
    unsigned int copyEngineCount;     //!< Copy Engine count
    unsigned int decoderCount;        //!< Decoder Engine count
    unsigned int encoderCount;        //!< Encoder Engine count
    unsigned int jpegCount;           //!< JPEG Engine count
    unsigned int ofaCount;            //!< OFA Engine count
    unsigned long long memorySizeMB;  //!< Memory size in MBytes
} nvmlGpuInstanceProfileInfo_t;

/**
 * GPU instance profile information (v2).
 *
 * Version 2 adds the \ref nvmlGpuInstanceProfileInfo_v2_t.version field
 * to the start of the structure, and the \ref nvmlGpuInstanceProfileInfo_v2_t.name
 * field to the end. This structure is not backwards-compatible with
 * \ref nvmlGpuInstanceProfileInfo_t.
 */
typedef struct nvmlGpuInstanceProfileInfo_v2_st {
    unsigned int version;                       //!< Structure version identifier (set to \ref nvmlGpuInstanceProfileInfo_v2)
    unsigned int id;                            //!< Unique profile ID within the device
    unsigned int isP2pSupported;                //!< Peer-to-Peer support
    unsigned int sliceCount;                    //!< GPU Slice count
    unsigned int instanceCount;                 //!< GPU instance count
    unsigned int multiprocessorCount;           //!< Streaming Multiprocessor count
    unsigned int copyEngineCount;               //!< Copy Engine count
    unsigned int decoderCount;                  //!< Decoder Engine count
    unsigned int encoderCount;                  //!< Encoder Engine count
    unsigned int jpegCount;                     //!< JPEG Engine count
    unsigned int ofaCount;                      //!< OFA Engine count
    unsigned long long memorySizeMB;            //!< Memory size in MBytes
    char name[NVML_DEVICE_NAME_V2_BUFFER_SIZE]; //!< Profile name
} nvmlGpuInstanceProfileInfo_v2_t;

/**
 * Version identifier value for \ref nvmlGpuInstanceProfileInfo_v2_t.version.
 */
#define nvmlGpuInstanceProfileInfo_v2 NVML_STRUCT_VERSION(GpuInstanceProfileInfo, 2)

typedef struct nvmlGpuInstanceInfo_st {
    nvmlDevice_t device;                  //!< Parent device
    unsigned int id;                      //!< Unique instance ID within the device
    unsigned int profileId;               //!< Unique profile ID within the device
    nvmlGpuInstancePlacement_t placement; //!< Placement for this instance
} nvmlGpuInstanceInfo_t;

typedef struct nvmlGpuInstance_st *nvmlGpuInstance_t;

/**
 * Compute instance profiles.
 *
 * These macros should be passed to \ref nvmlGpuInstanceGetComputeInstanceProfileInfo to retrieve the
 * detailed information about a compute instance such as profile ID, engine counts
 */
#define NVML_COMPUTE_INSTANCE_PROFILE_1_SLICE 0x0
#define NVML_COMPUTE_INSTANCE_PROFILE_2_SLICE 0x1
#define NVML_COMPUTE_INSTANCE_PROFILE_3_SLICE 0x2
#define NVML_COMPUTE_INSTANCE_PROFILE_4_SLICE 0x3
#define NVML_COMPUTE_INSTANCE_PROFILE_7_SLICE 0x4
#define NVML_COMPUTE_INSTANCE_PROFILE_8_SLICE 0x5
#define NVML_COMPUTE_INSTANCE_PROFILE_6_SLICE 0x6
#define NVML_COMPUTE_INSTANCE_PROFILE_1_SLICE_REV1 0x7
#define NVML_COMPUTE_INSTANCE_PROFILE_COUNT 0x8

#define NVML_COMPUTE_INSTANCE_ENGINE_PROFILE_SHARED 0x0 //!< All the engines except multiprocessors would be shared
#define NVML_COMPUTE_INSTANCE_ENGINE_PROFILE_COUNT 0x1

typedef struct nvmlComputeInstancePlacement_st {
    unsigned int start; //!< Index of first occupied compute slice
    unsigned int size;  //!< Number of compute slices occupied
} nvmlComputeInstancePlacement_t;

/**
 * Compute instance profile information.
 */
typedef struct nvmlComputeInstanceProfileInfo_st {
    unsigned int id;                    //!< Unique profile ID within the GPU instance
    unsigned int sliceCount;            //!< GPU Slice count
    unsigned int instanceCount;         //!< Compute instance count
    unsigned int multiprocessorCount;   //!< Streaming Multiprocessor count
    unsigned int sharedCopyEngineCount; //!< Shared Copy Engine count
    unsigned int sharedDecoderCount;    //!< Shared Decoder Engine count
    unsigned int sharedEncoderCount;    //!< Shared Encoder Engine count
    unsigned int sharedJpegCount;       //!< Shared JPEG Engine count
    unsigned int sharedOfaCount;        //!< Shared OFA Engine count
} nvmlComputeInstanceProfileInfo_t;

/**
 * Compute instance profile information (v2).
 *
 * Version 2 adds the \ref nvmlComputeInstanceProfileInfo_v2_t.version field
 * to the start of the structure, and the \ref nvmlComputeInstanceProfileInfo_v2_t.name
 * field to the end. This structure is not backwards-compatible with
 * \ref nvmlComputeInstanceProfileInfo_t.
 */
typedef struct nvmlComputeInstanceProfileInfo_v2_st {
    unsigned int version;                       //!< Structure version identifier (set to \ref nvmlComputeInstanceProfileInfo_v2)
    unsigned int id;                            //!< Unique profile ID within the GPU instance
    unsigned int sliceCount;                    //!< GPU Slice count
    unsigned int instanceCount;                 //!< Compute instance count
    unsigned int multiprocessorCount;           //!< Streaming Multiprocessor count
    unsigned int sharedCopyEngineCount;         //!< Shared Copy Engine count
    unsigned int sharedDecoderCount;            //!< Shared Decoder Engine count
    unsigned int sharedEncoderCount;            //!< Shared Encoder Engine count
    unsigned int sharedJpegCount;               //!< Shared JPEG Engine count
    unsigned int sharedOfaCount;                //!< Shared OFA Engine count
    char name[NVML_DEVICE_NAME_V2_BUFFER_SIZE]; //!< Profile name
} nvmlComputeInstanceProfileInfo_v2_t;

/**
 * Version identifier value for \ref nvmlComputeInstanceProfileInfo_v2_t.version.
 */
#define nvmlComputeInstanceProfileInfo_v2 NVML_STRUCT_VERSION(ComputeInstanceProfileInfo, 2)

typedef struct nvmlComputeInstanceInfo_st {
    nvmlDevice_t device;                      //!< Parent device
    nvmlGpuInstance_t gpuInstance;            //!< Parent GPU instance
    unsigned int id;                          //!< Unique instance ID within the GPU instance
    unsigned int profileId;                   //!< Unique profile ID within the GPU instance
    nvmlComputeInstancePlacement_t placement; //!< Placement for this instance within the GPU instance's compute slice range {0, sliceCount}
} nvmlComputeInstanceInfo_t;

typedef struct nvmlComputeInstance_st *nvmlComputeInstance_t;

/** @} */ // @defgroup CCU

#define NVML_NVLINK_POWER_STATE_HIGH_SPEED 0x0
#define NVML_NVLINK_POWER_STATE_LOW 0x1

#define NVML_NVLINK_LOW_POWER_THRESHOLD_MIN 0x1
#define NVML_NVLINK_LOW_POWER_THRESHOLD_MAX 0x1FFF
#define NVML_NVLINK_LOW_POWER_THRESHOLD_RESET 0xFFFFFFFF

/* Structure containing Low Power parameters */
typedef struct nvmlNvLinkPowerThres_st {
    unsigned int lowPwrThreshold; //!< Low power threshold (in units of 100us)
} nvmlNvLinkPowerThres_t;

/***************************************************************************************************/
/** @defgroup nvmlExcludedGpuQueries Excluded GPU Queries
 * This chapter describes NVML operations that are associated with excluded GPUs.
 *  @{
 */
/***************************************************************************************************/

/**
 * Excluded GPU device information
 **/
typedef struct nvmlExcludedDeviceInfo_st {
    nvmlPciInfo_t pciInfo;                   //!< The PCI information for the excluded GPU
    char uuid[NVML_DEVICE_UUID_BUFFER_SIZE]; //!< The ASCII string UUID for the excluded GPU
} nvmlExcludedDeviceInfo_t;

/***************************************************************************************************/
/** @defgroup nvml vGPU Migration
 * This chapter describes operations that are associated with vGPU Migration.
 *  @{
 */
/***************************************************************************************************/

/**
 * Structure representing range of vGPU versions.
 */
typedef struct nvmlVgpuVersion_st {
    unsigned int minVersion; //!< Minimum vGPU version.
    unsigned int maxVersion; //!< Maximum vGPU version.
} nvmlVgpuVersion_t;

/**
 * vGPU metadata structure.
 */
typedef struct nvmlVgpuMetadata_st {
    unsigned int version;                                            //!< Current version of the structure
    unsigned int revision;                                           //!< Current revision of the structure
    nvmlVgpuGuestInfoState_t guestInfoState;                         //!< Current state of Guest-dependent fields
    char guestDriverVersion[NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE]; //!< Version of driver installed in guest
    char hostDriverVersion[NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE];  //!< Version of driver installed in host
    unsigned int reserved[6];                                        //!< Reserved for internal use
    unsigned int vgpuVirtualizationCaps;                             //!< vGPU virtualizaion capabilities bitfileld
    unsigned int guestVgpuVersion;                                   //!< vGPU version of guest driver
    unsigned int opaqueDataSize;                                     //!< Size of opaque data field in bytes
    char opaqueData[4];                                              //!< Opaque data
} nvmlVgpuMetadata_t;

/**
 * Physical GPU metadata structure
 */
typedef struct nvmlVgpuPgpuMetadata_st {
    unsigned int version;                                           //!< Current version of the structure
    unsigned int revision;                                          //!< Current revision of the structure
    char hostDriverVersion[NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE]; //!< Host driver version
    unsigned int pgpuVirtualizationCaps;                            //!< Pgpu virtualizaion capabilities bitfileld
    unsigned int reserved[5];                                       //!< Reserved for internal use
    nvmlVgpuVersion_t hostSupportedVgpuRange;                       //!< vGPU version range supported by host driver
    unsigned int opaqueDataSize;                                    //!< Size of opaque data field in bytes
    char opaqueData[4];                                             //!< Opaque data
} nvmlVgpuPgpuMetadata_t;

/**
 * vGPU VM compatibility codes
 */
typedef enum nvmlVgpuVmCompatibility_enum {
    NVML_VGPU_VM_COMPATIBILITY_NONE = 0x0,      //!< vGPU is not runnable
    NVML_VGPU_VM_COMPATIBILITY_COLD = 0x1,      //!< vGPU is runnable from a cold / powered-off state (ACPI S5)
    NVML_VGPU_VM_COMPATIBILITY_HIBERNATE = 0x2, //!< vGPU is runnable from a hibernated state (ACPI S4)
    NVML_VGPU_VM_COMPATIBILITY_SLEEP = 0x4,     //!< vGPU is runnable from a sleeped state (ACPI S3)
    NVML_VGPU_VM_COMPATIBILITY_LIVE = 0x8       //!< vGPU is runnable from a live/paused (ACPI S0)
} nvmlVgpuVmCompatibility_t;

/**
 *  vGPU-pGPU compatibility limit codes
 */
typedef enum nvmlVgpuPgpuCompatibilityLimitCode_enum {
    NVML_VGPU_COMPATIBILITY_LIMIT_NONE = 0x0,         //!< Compatibility is not limited.
    NVML_VGPU_COMPATIBILITY_LIMIT_HOST_DRIVER = 0x1,  //!< ompatibility is limited by host driver version.
    NVML_VGPU_COMPATIBILITY_LIMIT_GUEST_DRIVER = 0x2, //!< Compatibility is limited by guest driver version.
    NVML_VGPU_COMPATIBILITY_LIMIT_GPU = 0x4,          //!< Compatibility is limited by GPU hardware.
    NVML_VGPU_COMPATIBILITY_LIMIT_OTHER = 0x80000000  //!< Compatibility is limited by an undefined factor.
} nvmlVgpuPgpuCompatibilityLimitCode_t;

/**
 * vGPU-pGPU compatibility structure
 */
typedef struct nvmlVgpuPgpuCompatibility_st {
    nvmlVgpuVmCompatibility_t vgpuVmCompatibility;               //!< Compatibility of vGPU VM. See \ref nvmlVgpuVmCompatibility_t
    nvmlVgpuPgpuCompatibilityLimitCode_t compatibilityLimitCode; //!< Limiting factor for vGPU-pGPU compatibility. See \ref nvmlVgpuPgpuCompatibilityLimitCode_t
} nvmlVgpuPgpuCompatibility_t;

/***************************************************************************************************/

/** @defgroup nvmlAffinity CPU and Memory Affinity
 *  This chapter describes NVML operations that are associated with CPU and memory
 *  affinity.
 *  @{
 */
/***************************************************************************************************/

//! Scope of NUMA node for affinity queries
#define NVML_AFFINITY_SCOPE_NODE 0
//! Scope of processor socket for affinity queries
#define NVML_AFFINITY_SCOPE_SOCKET 1

typedef unsigned int nvmlAffinityScope_t;
