#pragma once

// Documented.
#define WIN_1507 10240
#define WIN_1511 10586
#define WIN_1607 14393
#define WIN_1703 15063
#define WIN_1709 16299
#define WIN_1803 17134
#define WIN_1809 17763
#define WIN_1903 18362
#define WIN_1909 18363
#define WIN_2004 19041
#define WIN_20H2 19042
#define WIN_21H1 19043
#define WIN_21H2 19044
#define WIN_22H2 19045
#define WIN_1121H2 22000
#define WIN_1122H2 22621

#define IMAGE_DOS_SIGNATURE                 0x5A4D
#define IMAGE_NT_SIGNATURE                  0x00004550

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES    16

#define IMAGE_DIRECTORY_ENTRY_EXPORT          0   // Export Directory
#define IMAGE_DIRECTORY_ENTRY_IMPORT          1   // Import Directory
#define IMAGE_DIRECTORY_ENTRY_RESOURCE        2   // Resource Directory
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION       3   // Exception Directory
#define IMAGE_DIRECTORY_ENTRY_SECURITY        4   // Security Directory
#define IMAGE_DIRECTORY_ENTRY_BASERELOC       5   // Base Relocation Table
#define IMAGE_DIRECTORY_ENTRY_DEBUG           6   // Debug Directory
#define IMAGE_DIRECTORY_ENTRY_ARCHITECTURE    7   // Architecture Specific Data

#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR       8   // RVA of GP
#define IMAGE_DIRECTORY_ENTRY_TLS             9   // TLS Directory
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    10   // Load Configuration Directory
#define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   11   // Bound Import Directory headers
#define IMAGE_DIRECTORY_ENTRY_IAT            12   // Import Address Table
#define IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   13   // Delay Load Import Descriptors
#define IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14   // COM Runtime descriptor

typedef unsigned long       DWORD;
typedef unsigned short      WORD;
typedef unsigned char       BYTE;

typedef struct _IMAGE_DOS_HEADER {      // DOS .EXE header
	WORD   e_magic;                     // Magic number
	WORD   e_cblp;                      // Bytes on last page of file
	WORD   e_cp;                        // Pages file
	WORD   e_crlc;                      // Relocations
	WORD   e_cparhdr;                   // Size of header paragraphs
	WORD   e_minalloc;                  // Minimum extra paragraphs needed
	WORD   e_maxalloc;                  // Maximum extra paragraphs needed
	WORD   e_ss;                        // Initial (relative) SS value
	WORD   e_sp;                        // Initial SP value
	WORD   e_csum;                      // Checksum
	WORD   e_ip;                        // Initial IP value
	WORD   e_cs;                        // Initial (relative) CS value
	WORD   e_lfarlc;                    // File address of relocation table
	WORD   e_ovno;                      // Overlay number
	WORD   e_res[4];                    // Reserved words
	WORD   e_oemid;                     // OEM identifier (for e_oeminfo)
	WORD   e_oeminfo;                   // OEM information; e_oemid specific
	WORD   e_res2[10];                  // Reserved words
	LONG   e_lfanew;                    // File address of new exe header
} IMAGE_DOS_HEADER, * PIMAGE_DOS_HEADER;

typedef struct _IMAGE_FILE_HEADER {
	WORD    Machine;
	WORD    NumberOfSections;
	DWORD   TimeDateStamp;
	DWORD   PointerToSymbolTable;
	DWORD   NumberOfSymbols;
	WORD    SizeOfOptionalHeader;
	WORD    Characteristics;
} IMAGE_FILE_HEADER, * PIMAGE_FILE_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY {
	ULONG   VirtualAddress;
	ULONG   Size;
} IMAGE_DATA_DIRECTORY, * PIMAGE_DATA_DIRECTORY;

typedef struct _IMAGE_EXPORT_DIRECTORY {
	DWORD   Characteristics;
	DWORD   TimeDateStamp;
	WORD    MajorVersion;
	WORD    MinorVersion;
	DWORD   Name;
	DWORD   Base;
	DWORD   NumberOfFunctions;
	DWORD   NumberOfNames;
	DWORD   AddressOfFunctions;     // RVA from base of image
	DWORD   AddressOfNames;         // RVA from base of image
	DWORD   AddressOfNameOrdinals;  // RVA from base of image
} IMAGE_EXPORT_DIRECTORY, * PIMAGE_EXPORT_DIRECTORY;

typedef struct _IMAGE_OPTIONAL_HEADER {
	WORD        Magic;
	BYTE        MajorLinkerVersion;
	BYTE        MinorLinkerVersion;
	DWORD       SizeOfCode;
	DWORD       SizeOfInitializedData;
	DWORD       SizeOfUninitializedData;
	DWORD       AddressOfEntryPoint;
	DWORD       BaseOfCode;
	ULONGLONG   ImageBase;
	DWORD       SectionAlignment;
	DWORD       FileAlignment;
	WORD        MajorOperatingSystemVersion;
	WORD        MinorOperatingSystemVersion;
	WORD        MajorImageVersion;
	WORD        MinorImageVersion;
	WORD        MajorSubsystemVersion;
	WORD        MinorSubsystemVersion;
	DWORD       Win32VersionValue;
	DWORD       SizeOfImage;
	DWORD       SizeOfHeaders;
	DWORD       CheckSum;
	WORD        Subsystem;
	WORD        DllCharacteristics;
	ULONGLONG   SizeOfStackReserve;
	ULONGLONG   SizeOfStackCommit;
	ULONGLONG   SizeOfHeapReserve;
	ULONGLONG   SizeOfHeapCommit;
	DWORD       LoaderFlags;
	DWORD       NumberOfRvaAndSizes;
	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER, * PIMAGE_OPTIONAL_HEADER;

typedef struct _FULL_IMAGE_NT_HEADERS {
	DWORD Signature;
	IMAGE_FILE_HEADER FileHeader;
	IMAGE_OPTIONAL_HEADER OptionalHeader;
} FULL_IMAGE_NT_HEADERS, * PFULL_IMAGE_NT_HEADERS;

#pragma warning(default : 4214)

typedef struct _PEB_LDR_DATA
{
	ULONG Length;                                                           //0x0
	UCHAR Initialized;                                                      //0x4
	PVOID SsHandle;                                                         //0x8
	LIST_ENTRY InLoadOrderModuleList;                               //0x10
	LIST_ENTRY InMemoryOrderModuleList;                             //0x20
	LIST_ENTRY InInitializationOrderModuleList;                     //0x30
	PVOID EntryInProgress;                                                  //0x40
	UCHAR ShutdownInProgress;                                               //0x48
	PVOID ShutdownThreadId;                                                 //0x50
} PEB_LDR_DATA, * PPEB_LDR_DATA;

typedef struct _LDR_DATA_TABLE_ENTRY {
	LIST_ENTRY InLoadOrderLinks;
	LIST_ENTRY InMemoryOrderLinks;
	PVOID Reserved2[2];
	PVOID DllBase;
	PVOID EntryPoint;
	PVOID Reserved3;
	UNICODE_STRING FullDllName;
	BYTE Reserved4[8];
	PVOID Reserved5[3];
	union {
		ULONG CheckSum;
		PVOID Reserved6;
	};
	ULONG TimeDateStamp;
} LDR_DATA_TABLE_ENTRY, * PLDR_DATA_TABLE_ENTRY;

typedef struct _RTL_USER_PROCESS_PARAMETERS {
	BYTE           Reserved1[16];
	PVOID          Reserved2[10];
	UNICODE_STRING ImagePathName;
	UNICODE_STRING CommandLine;
} RTL_USER_PROCESS_PARAMETERS, * PRTL_USER_PROCESS_PARAMETERS;

typedef struct _REAL_PEB {
	BYTE Reserved1[2];
	BYTE BeingDebugged;
	BYTE Reserved2[21];
	PPEB_LDR_DATA LoaderData;
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
	BYTE Reserved3[520];
	PVOID PostProcessInitRoutine;
	BYTE Reserved4[136];
	ULONG SessionId;
} REALPEB, * PREALPEB;

// Undocumented.
extern "C" POBJECT_TYPE* IoDriverObjectType;

typedef VOID(*PKNORMAL_ROUTINE) (
	PVOID NormalContext,
	PVOID SystemArgument1,
	PVOID SystemArgument2);

typedef VOID(*PKKERNEL_ROUTINE) (
	PKAPC Apc,
	PKNORMAL_ROUTINE* NormalRoutine,
	PVOID* NormalContext,
	PVOID* SystemArgument1,
	PVOID* SystemArgument2);

typedef VOID (*PKRUNDOWN_ROUTINE) (
	 PKAPC Apc);

typedef struct _PS_PROTECTION
{
	UCHAR Type : 3;
	UCHAR Audit : 1;
	UCHAR Signer : 4;
} PS_PROTECTION, * PPS_PROTECTION;

typedef struct _PROCESS_SIGNATURE 
{
	UCHAR SignatureLevel;
	UCHAR SectionSignatureLevel;
	PS_PROTECTION Protection;
} PROCESS_SIGNATURE, * PPROCESS_SIGNATURE;

typedef struct _SYSTEM_THREAD_INFORMATION
{
	LARGE_INTEGER KernelTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER CreateTime;
	ULONG WaitTime;
	PVOID StartAddress;
	CLIENT_ID ClientId;
	KPRIORITY Priority;
	LONG BasePriority;
	ULONG ContextSwitches;
	ULONG ThreadState;
	KWAIT_REASON WaitReason;
}SYSTEM_THREAD_INFORMATION, * PSYSTEM_THREAD_INFORMATION;

typedef struct _SYSTEM_PROCESS_INFO
{
	ULONG NextEntryOffset;
	ULONG NumberOfThreads;
	LARGE_INTEGER WorkingSetPrivateSize;
	ULONG HardFaultCount;
	ULONG NumberOfThreadsHighWatermark;
	ULONGLONG CycleTime;
	LARGE_INTEGER CreateTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER KernelTime;
	UNICODE_STRING ImageName;
	KPRIORITY BasePriority;
	HANDLE UniqueProcessId;
	HANDLE InheritedFromUniqueProcessId;
	ULONG HandleCount;
	ULONG SessionId;
	ULONG_PTR UniqueProcessKey;
	SIZE_T PeakVirtualSize;
	SIZE_T VirtualSize;
	ULONG PageFaultCount;
	SIZE_T PeakWorkingSetSize;
	SIZE_T WorkingSetSize;
	SIZE_T QuotaPeakPagedPoolUsage;
	SIZE_T QuotaPagedPoolUsage;
	SIZE_T QuotaPeakNonPagedPoolUsage;
	SIZE_T QuotaNonPagedPoolUsage;
	SIZE_T PagefileUsage;
	SIZE_T PeakPagefileUsage;
	SIZE_T PrivatePageCount;
	LARGE_INTEGER ReadOperationCount;
	LARGE_INTEGER WriteOperationCount;
	LARGE_INTEGER OtherOperationCount;
	LARGE_INTEGER ReadTransferCount;
	LARGE_INTEGER WriteTransferCount;
	LARGE_INTEGER OtherTransferCount;
	SYSTEM_THREAD_INFORMATION Threads[1];
}SYSTEM_PROCESS_INFO, * PSYSTEM_PROCESS_INFO;

enum SignatureType
{
	PsProtectedTypeNone = 0,
	PsProtectedTypeProtectedLight = 1,
	PsProtectedTypeProtected = 2
};

enum SignatureSigner
{
	PsProtectedSignerNone = 0,      // 0
	PsProtectedSignerAuthenticode,  // 1
	PsProtectedSignerCodeGen,       // 2
	PsProtectedSignerAntimalware,   // 3
	PsProtectedSignerLsa,           // 4
	PsProtectedSignerWindows,       // 5
	PsProtectedSignerWinTcb,        // 6
	PsProtectedSignerWinSystem,     // 7
	PsProtectedSignerApp,           // 8
	PsProtectedSignerMax            // 9
};

enum KAPC_ENVIRONMENT {
	OriginalApcEnvironment,
	AttachedApcEnvironment,
	CurrentApcEnvironment,
	InsertApcEnvironment
};

enum SYSTEM_INFORMATION_CLASS {
	SystemBasicInformation = 0,
	SystemProcessorInformation = 1,
	SystemPerformanceInformation = 2,
	SystemTimeOfDayInformation = 3,
	SystemPathInformation = 4,
	SystemProcessInformation = 5,
	SystemCallCountInformation = 6,
	SystemDeviceInformation = 7,
	SystemProcessorPerformanceInformation = 8,
	SystemFlagsInformation = 9,
	SystemCallTimeInformation = 10,
	SystemModuleInformation = 11,
	SystemLocksInformation = 12,
	SystemStackTraceInformation = 13,
	SystemPagedPoolInformation = 14,
	SystemNonPagedPoolInformation = 15,
	SystemHandleInformation = 16,
	SystemObjectInformation = 17,
	SystemPageFileInformation = 18,
	SystemVdmInstemulInformation = 19,
	SystemVdmBopInformation = 20,
	SystemFileCacheInformation = 21,
	SystemPoolTagInformation = 22,
	SystemInterruptInformation = 23,
	SystemDpcBehaviorInformation = 24,
	SystemFullMemoryInformation = 25,
	SystemLoadGdiDriverInformation = 26,
	SystemUnloadGdiDriverInformation = 27,
	SystemTimeAdjustmentInformation = 28,
	SystemSummaryMemoryInformation = 29,
	SystemMirrorMemoryInformation = 30,
	SystemPerformanceTraceInformation = 31,
	SystemObsolete0 = 32,
	SystemExceptionInformation = 33,
	SystemCrashDumpStateInformation = 34,
	SystemKernelDebuggerInformation = 35,
	SystemContextSwitchInformation = 36,
	SystemRegistryQuotaInformation = 37,
	SystemExtendServiceTableInformation = 38,
	SystemPrioritySeperation = 39,
	SystemVerifierAddDriverInformation = 40,
	SystemVerifierRemoveDriverInformation = 41,
	SystemProcessorIdleInformation = 42,
	SystemLegacyDriverInformation = 43,
	SystemCurrentTimeZoneInformation = 44,
	SystemLookasideInformation = 45,
	SystemTimeSlipNotification = 46,
	SystemSessionCreate = 47,
	SystemSessionDetach = 48,
	SystemSessionInformation = 49,
	SystemRangeStartInformation = 50,
	SystemVerifierInformation = 51,
	SystemVerifierThunkExtend = 52,
	SystemSessionProcessInformation = 53,
	SystemLoadGdiDriverInSystemSpace = 54,
	SystemNumaProcessorMap = 55,
	SystemPrefetcherInformation = 56,
	SystemExtendedProcessInformation = 57,
	SystemRecommendedSharedDataAlignment = 58,
	SystemComPlusPackage = 59,
	SystemNumaAvailableMemory = 60,
	SystemProcessorPowerInformation = 61,
	SystemEmulationBasicInformation = 62,
	SystemEmulationProcessorInformation = 63,
	SystemExtendedHandleInformation = 64,
	SystemLostDelayedWriteInformation = 65,
	SystemBigPoolInformation = 66,
	SystemSessionPoolTagInformation = 67,
	SystemSessionMappedViewInformation = 68,
	SystemHotpatchInformation = 69,
	SystemObjectSecurityMode = 70,
	SystemWatchdogTimerHandler = 71,
	SystemWatchdogTimerInformation = 72,
	SystemLogicalProcessorInformation = 73,
	SystemWow64SharedInformationObsolete = 74,
	SystemRegisterFirmwareTableInformationHandler = 75,
	SystemFirmwareTableInformation = 76,
	SystemModuleInformationEx = 77,
	SystemVerifierTriageInformation = 78,
	SystemSuperfetchInformation = 79,
	SystemMemoryListInformation = 80,
	SystemFileCacheInformationEx = 81,
	SystemThreadPriorityClientIdInformation = 82,
	SystemProcessorIdleCycleTimeInformation = 83,
	SystemVerifierCancellationInformation = 84,
	SystemProcessorPowerInformationEx = 85,
	SystemRefTraceInformation = 86,
	SystemSpecialPoolInformation = 87,
	SystemProcessIdInformation = 88,
	SystemErrorPortInformation = 89,
	SystemBootEnvironmentInformation = 90,
	SystemHypervisorInformation = 91,
	SystemVerifierInformationEx = 92,
	SystemTimeZoneInformation = 93,
	SystemImageFileExecutionOptionsInformation = 94,
	SystemCoverageInformation = 95,
	SystemPrefetchPatchInformation = 96,
	SystemVerifierFaultsInformation = 97,
	SystemSystemPartitionInformation = 98,
	SystemSystemDiskInformation = 99,
	SystemProcessorPerformanceDistribution = 100,
	SystemNumaProximityNodeInformation = 101,
	SystemDynamicTimeZoneInformation = 102,
	SystemCodeIntegrityInformation = 103,
	SystemProcessorMicrocodeUpdateInformation = 104,
	SystemProcessorBrandString = 105,
	SystemVirtualAddressInformation = 106,
	SystemLogicalProcessorAndGroupInformation = 107,
	SystemProcessorCycleTimeInformation = 108,
	SystemStoreInformation = 109,
	SystemRegistryAppendString = 110,
	SystemAitSamplingValue = 111,
	SystemVhdBootInformation = 112,
	SystemCpuQuotaInformation = 113,
	SystemNativeBasicInformation = 114,
	SystemErrorPortTimeouts = 115,
	SystemLowPriorityIoInformation = 116,
	SystemBootEntropyInformation = 117,
	SystemVerifierCountersInformation = 118,
	SystemPagedPoolInformationEx = 119,
	SystemSystemPtesInformationEx = 120,
	SystemNodeDistanceInformation = 121,
	SystemAcpiAuditInformation = 122,
	SystemBasicPerformanceInformation = 123,
	SystemQueryPerformanceCounterInformation = 124,
	SystemSessionBigPoolInformation = 125,
	SystemBootGraphicsInformation = 126,
	SystemScrubPhysicalMemoryInformation = 127,
	SystemBadPageInformation = 128,
	SystemProcessorProfileControlArea = 129,
	SystemCombinePhysicalMemoryInformation = 130,
	SystemEntropyInterruptTimingInformation = 131,
	SystemConsoleInformation = 132,
	SystemPlatformBinaryInformation = 133,
	SystemPolicyInformation = 134,
	SystemHypervisorProcessorCountInformation = 135,
	SystemDeviceDataInformation = 136,
	SystemDeviceDataEnumerationInformation = 137,
	SystemMemoryTopologyInformation = 138,
	SystemMemoryChannelInformation = 139,
	SystemBootLogoInformation = 140,
	SystemProcessorPerformanceInformationEx = 141,
	SystemCriticalProcessErrorLogInformation = 142,
	SystemSecureBootPolicyInformation = 143,
	SystemPageFileInformationEx = 144,
	SystemSecureBootInformation = 145,
	SystemEntropyInterruptTimingRawInformation = 146,
	SystemPortableWorkspaceEfiLauncherInformation = 147,
	SystemFullProcessInformation = 148,
	SystemKernelDebuggerInformationEx = 149,
	SystemBootMetadataInformation = 150,
	SystemSoftRebootInformation = 151,
	SystemElamCertificateInformation = 152,
	SystemOfflineDumpConfigInformation = 153,
	SystemProcessorFeaturesInformation = 154,
	SystemRegistryReconciliationInformation = 155,
	SystemEdidInformation = 156,
	SystemManufacturingInformation = 157,
	SystemEnergyEstimationConfigInformation = 158,
	SystemHypervisorDetailInformation = 159,
	SystemProcessorCycleStatsInformation = 160,
	SystemVmGenerationCountInformation = 161,
	SystemTrustedPlatformModuleInformation = 162,
	SystemKernelDebuggerFlags = 163,
	SystemCodeIntegrityPolicyInformation = 164,
	SystemIsolatedUserModeInformation = 165,
	SystemHardwareSecurityTestInterfaceResultsInformation = 166,
	SystemSingleModuleInformation = 167,
	SystemAllowedCpuSetsInformation = 168,
	SystemVsmProtectionInformation = 169,
	SystemInterruptCpuSetsInformation = 170,
	SystemSecureBootPolicyFullInformation = 171,
	SystemCodeIntegrityPolicyFullInformation = 172,
	SystemAffinitizedInterruptProcessorInformation = 173,
	SystemRootSiloInformation = 174,
	SystemCpuSetInformation = 175,
	SystemCpuSetTagInformation = 176,
	SystemWin32WerStartCallout = 177,
	SystemSecureKernelProfileInformation = 178,
	SystemCodeIntegrityPlatformManifestInformation = 179,
	SystemInterruptSteeringInformation = 180,
	SystemSupportedProcessorArchitectures = 181,
	SystemMemoryUsageInformation = 182,
	SystemCodeIntegrityCertificateInformation = 183,
	SystemPhysicalMemoryInformation = 184,
	SystemControlFlowTransition = 185,
	SystemKernelDebuggingAllowed = 186,
	SystemActivityModerationExeState = 187,
	SystemActivityModerationUserSettings = 188,
	SystemCodeIntegrityPoliciesFullInformation = 189,
	SystemCodeIntegrityUnlockInformation = 190,
	SystemIntegrityQuotaInformation = 191,
	SystemFlushInformation = 192,
	SystemProcessorIdleMaskInformation = 193,
	SystemSecureDumpEncryptionInformation = 194,
	SystemWriteConstraintInformation = 195,
	SystemKernelVaShadowInformation = 196,
	SystemHypervisorSharedPageInformation = 197,
	SystemFirmwareBootPerformanceInformation = 198,
	SystemCodeIntegrityVerificationInformation = 199,
	SystemFirmwarePartitionInformation = 200,
	SystemSpeculationControlInformation = 201,
	SystemDmaGuardPolicyInformation = 202,
	SystemEnclaveLaunchControlInformation = 203,
	SystemWorkloadAllowedCpuSetsInformation = 204,
	SystemCodeIntegrityUnlockModeInformation = 205,
	SystemLeapSecondInformation = 206,
	SystemFlags2Information = 207,
	SystemSecurityModelInformation = 208,
	SystemCodeIntegritySyntheticCacheInformation = 209,
	SystemFeatureConfigurationInformation = 210,
	SystemFeatureConfigurationSectionInformation = 211,
	SystemFeatureUsageSubscriptionInformation = 212,
	SystemSecureSpeculationControlInformation = 213,
	SystemSpacesBootInformation = 214,
	SystemFwRamdiskInformation = 215,
	SystemWheaIpmiHardwareInformation = 216,
	SystemDifSetRuleClassInformation = 217,
	SystemDifClearRuleClassInformation = 218,
	SystemDifApplyPluginVerificationOnDriver = 219,
	SystemDifRemovePluginVerificationOnDriver = 220,
	SystemShadowStackInformation = 221,
	SystemBuildVersionInformation = 222,
	SystemPoolLimitInformation = 223,
	SystemCodeIntegrityAddDynamicStore = 224,
	SystemCodeIntegrityClearDynamicStores = 225,
	SystemDifPoolTrackingInformation = 226,
	SystemPoolZeroingInformation = 227,
	SystemDpcWatchdogInformation = 228,
	SystemDpcWatchdogInformation2 = 229,
	SystemSupportedProcessorArchitectures2 = 230,
	SystemSingleProcessorRelationshipInformation = 231,
	SystemXfgCheckFailureInformation = 232,
	SystemIommuStateInformation = 233,
	SystemHypervisorMinrootInformation = 234,
	SystemHypervisorBootPagesInformation = 235,
	SystemPointerAuthInformation = 236,
	SystemSecureKernelDebuggerInformation = 237,
	SystemOriginalImageFeatureInformation = 238,
	MaxSystemInfoClass = 239
};

// Prototypes
typedef NTSTATUS(NTAPI* tZwProtectVirtualMemory)(
	HANDLE ProcessHandle,
	PVOID* BaseAddress,
	SIZE_T* NumberOfBytesToProtect,
	ULONG NewAccessProtection,
	PULONG OldAccessProtection);

typedef NTSTATUS(NTAPI* tMmCopyVirtualMemory)(
	PEPROCESS SourceProcess,
	PVOID SourceAddress,
	PEPROCESS TargetProcess,
	PVOID TargetAddress,
	SIZE_T BufferSize,
	KPROCESSOR_MODE PreviousMode,
	PSIZE_T ReturnSize);

typedef PPEB(NTAPI* tPsGetProcessPeb)(
	PEPROCESS Process);

typedef NTSTATUS(NTAPI* tObReferenceObjectByName)(
	PUNICODE_STRING ObjectName,
	ULONG Attributes,
	PACCESS_STATE AccessState,
	ACCESS_MASK DesiredAccess,
	POBJECT_TYPE ObjectType,
	KPROCESSOR_MODE AccessMode,
	PVOID ParseContext,
	PVOID* Object);

typedef NTSTATUS(NTAPI* tNtfsIrpFunction)(
	PDEVICE_OBJECT DeviceObject,
	PIRP Irp);

typedef NTSTATUS(NTAPI* tIoCreateDriver)(
	PUNICODE_STRING DriverName,
	PDRIVER_INITIALIZE InitializationFunction);

typedef VOID(NTAPI* tKeInitializeApc)(
	PKAPC Apc,
	PKTHREAD Thread,
	KAPC_ENVIRONMENT Environment,
	PKKERNEL_ROUTINE KernelRoutine,
	PKRUNDOWN_ROUTINE RundownRoutine,
	PKNORMAL_ROUTINE NormalRoutine,
	KPROCESSOR_MODE ApcMode,
	PVOID NormalContext);

typedef BOOLEAN(NTAPI* tKeInsertQueueApc)(
	PKAPC Apc,
	PVOID SystemArgument1,
	PVOID SystemArgument2,
	KPRIORITY Increment);

typedef BOOLEAN(NTAPI* tKeTestAlertThread)(
	KPROCESSOR_MODE AlertMode);

typedef NTSTATUS(NTAPI* tZwQuerySystemInformation)(
	SYSTEM_INFORMATION_CLASS SystemInformationClass,
	PVOID SystemInformation,
	ULONG SystemInformationLength,
	PULONG ReturnLength);

// Offset finding functions.

/*
* Description:
* GetTokenOffset is responsible for getting the main thread's token offset depends on the windows version.
*
* Parameters:
* There are no parameters.
*
* Returns:
* @tokenOffset [ULONG] -- Offset of the main thread's token.
*/
ULONG GetTokenOffset() {
	ULONG tokenOffset = (ULONG)STATUS_UNSUCCESSFUL;
	RTL_OSVERSIONINFOW osVersion = { sizeof(osVersion) };
	NTSTATUS result = RtlGetVersion(&osVersion);

	if (NT_SUCCESS(result)) {
		switch (osVersion.dwBuildNumber) {
		case WIN_1903:
		case WIN_1909:
			tokenOffset = 0x360;
			break;
		case WIN_1507:
		case WIN_1511:
		case WIN_1607:
		case WIN_1703:
		case WIN_1709:
		case WIN_1803:
		case WIN_1809:
			tokenOffset = 0x358;
			break;
		default:
			tokenOffset = 0x4b8;
			break;
		}
	}

	return tokenOffset;
}

/*
* Description:
* GetSignatureLevelOffset is responsible for getting the signature level offset depends on the windows version.
*
* Parameters:
* There are no parameters.
*
* Returns:
* @signatureLevelOffset [UINT64] -- Offset of the process' signature level.
*/
ULONG GetSignatureLevelOffset() {
	ULONG signatureLevelOffset = (ULONG)STATUS_UNSUCCESSFUL;
	RTL_OSVERSIONINFOW osVersion = { sizeof(osVersion) };
	NTSTATUS result = RtlGetVersion(&osVersion);

	if (NT_SUCCESS(result)) {
		switch (osVersion.dwBuildNumber) {
		case WIN_1903:
		case WIN_1909:
			signatureLevelOffset = 0x6f8;
			break;
		case WIN_1703:
		case WIN_1709:
		case WIN_1803:
		case WIN_1809:
			signatureLevelOffset = 0x6c8;
			break;
		case WIN_1607:
			signatureLevelOffset = 0x6c0;
			break;
		case WIN_1511:
			signatureLevelOffset = 0x6b0;
			break;
		case WIN_1507:
			signatureLevelOffset = 0x6a8;
			break;
		default:
			signatureLevelOffset = 0x878;
			break;
		}
	}

	return signatureLevelOffset;
}
/*
* Description:
* GetActiveProcessLinksOffset is responsible for getting the active process link offset depends on the windows version.
*
* Parameters:
* There are no parameters.
*
* Returns:
* @activeProcessLinks [ULONG] -- Offset of active process links.
*/
ULONG GetActiveProcessLinksOffset() {
	ULONG activeProcessLinks = (ULONG)STATUS_UNSUCCESSFUL;
	RTL_OSVERSIONINFOW osVersion = { sizeof(osVersion) };
	NTSTATUS result = RtlGetVersion(&osVersion);

	if (NT_SUCCESS(result)) {
		switch (osVersion.dwBuildNumber) {
		case WIN_1507:
		case WIN_1511:
		case WIN_1607:
		case WIN_1903:
		case WIN_1909:
			activeProcessLinks = 0x2f0;
			break;
		case WIN_1703:
		case WIN_1709:
		case WIN_1803:
		case WIN_1809:
			activeProcessLinks = 0x2e8;
			break;
		default:
			activeProcessLinks = 0x448;
			break;
		}
	}

	return activeProcessLinks;
}


/*
* Description:
* GetProcessLockOffset is responsible for getting the ProcessLock offset depends on the windows version.
*
* Parameters:
* There are no parameters.
*
* Returns:
* @processLockOffset [ULONG] -- Offset of ProcessLock.
*/
ULONG GetProcessLockOffset() {
	ULONG processLockOffset = (ULONG)STATUS_UNSUCCESSFUL;
	RTL_OSVERSIONINFOW osVersion = { sizeof(osVersion) };
	NTSTATUS result = RtlGetVersion(&osVersion);

	if (NT_SUCCESS(result)) {
		switch (osVersion.dwBuildNumber) {
		case WIN_1507:
		case WIN_1511:
		case WIN_1607:
		case WIN_1703:
		case WIN_1709:
		case WIN_1803:
		case WIN_1809:
			processLockOffset = 0x2d8;
			break;
		case WIN_1903:
		case WIN_1909:
			processLockOffset = 0x2e0;
			break;
		default:
			processLockOffset = 0x438;
			break;
		}
	}

	return processLockOffset;
}

/*
* Description:
* GetThreadListEntryOffset is responsible for getting the thread list entry offset depends on the windows version.
*
* Parameters:
* There are no parameters.
*
* Returns:
* @threadListEntry [ULONG] -- Offset of thread list entry.
*/
ULONG GetThreadListEntryOffset() {
	ULONG threadListEntry = (ULONG)STATUS_UNSUCCESSFUL;
	RTL_OSVERSIONINFOW osVersion = { sizeof(osVersion) };
	NTSTATUS result = RtlGetVersion(&osVersion);

	if (NT_SUCCESS(result)) {
		switch (osVersion.dwBuildNumber) {
		case WIN_1507:
		case WIN_1511:
			threadListEntry = 0x690;
			break;
		case WIN_1607:
			threadListEntry = 0x698;
			break;
		case WIN_1703:
			threadListEntry = 0x6a0;
			break;
		case WIN_1709:
		case WIN_1803:
		case WIN_1809:
			threadListEntry = 0x6a8;
			break;
		case WIN_1903:
		case WIN_1909:
			threadListEntry = 0x6b8;
			break;
		case WIN_2004:
		case WIN_20H2:
		case WIN_21H1:
		case WIN_21H2:
			threadListEntry = 0x4e8;
			break;
		default:
			threadListEntry = 0x538;
			break;
		}
	}

	return threadListEntry;
}

/*
* Description:
* GetThreadLockOffset is responsible for getting the ThreadLock offset depends on the windows version.
*
* Parameters:
* There are no parameters.
*
* Returns:
* @threadLockOffset [ULONG] -- Offset of ProcessLock.
*/
ULONG GetThreadLockOffset() {
	ULONG threadLockOffset = (ULONG)STATUS_UNSUCCESSFUL;
	RTL_OSVERSIONINFOW osVersion = { sizeof(osVersion) };
	NTSTATUS result = RtlGetVersion(&osVersion);

	if (NT_SUCCESS(result)) {
		switch (osVersion.dwBuildNumber) {
		case WIN_1507:
		case WIN_1511:
			threadLockOffset = 0x6a8;
			break;
		case WIN_1607:
			threadLockOffset = 0x6b0;
			break;
		case WIN_1703:
			threadLockOffset = 0x6b8;
			break;
		case WIN_1709:
		case WIN_1803:
		case WIN_1809:
			threadLockOffset = 0x6c0;
			break;
		case WIN_1903:
		case WIN_1909:
			threadLockOffset = 0x6d0;
			break;
		case WIN_2004:
		case WIN_20H2:
		case WIN_21H1:
		case WIN_21H2:
			threadLockOffset = 0x500;
			break;
		default:
			threadLockOffset = 0x550;
			break;
		}
	}

	return threadLockOffset;
}
