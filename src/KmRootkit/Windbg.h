#pragma once
/*
* 0: kd> dt _EPROCESS
nt!_EPROCESS
   +0x000 Pcb              : _KPROCESS
   +0x2d8 ProcessLock      : _EX_PUSH_LOCK
   +0x2e0 UniqueProcessId  : Ptr64 Void
   +0x2e8 ActiveProcessLinks : _LIST_ENTRY
   +0x2f8 RundownProtect   : _EX_RUNDOWN_REF
   +0x300 Flags2           : Uint4B
   +0x300 JobNotReallyActive : Pos 0, 1 Bit
   +0x300 AccountingFolded : Pos 1, 1 Bit
   +0x300 NewProcessReported : Pos 2, 1 Bit
   +0x300 ExitProcessReported : Pos 3, 1 Bit
   +0x300 ReportCommitChanges : Pos 4, 1 Bit
   +0x300 LastReportMemory : Pos 5, 1 Bit
   +0x300 ForceWakeCharge  : Pos 6, 1 Bit
   +0x300 CrossSessionCreate : Pos 7, 1 Bit
   +0x300 NeedsHandleRundown : Pos 8, 1 Bit
   +0x300 RefTraceEnabled  : Pos 9, 1 Bit
   +0x300 PicoCreated      : Pos 10, 1 Bit
   +0x300 EmptyJobEvaluated : Pos 11, 1 Bit
   +0x300 DefaultPagePriority : Pos 12, 3 Bits
   +0x300 PrimaryTokenFrozen : Pos 15, 1 Bit
   +0x300 ProcessVerifierTarget : Pos 16, 1 Bit
   +0x300 RestrictSetThreadContext : Pos 17, 1 Bit
   +0x300 AffinityPermanent : Pos 18, 1 Bit
   +0x300 AffinityUpdateEnable : Pos 19, 1 Bit
   +0x300 PropagateNode    : Pos 20, 1 Bit
   +0x300 ExplicitAffinity : Pos 21, 1 Bit
   +0x300 ProcessExecutionState : Pos 22, 2 Bits
   +0x300 EnableReadVmLogging : Pos 24, 1 Bit
   +0x300 EnableWriteVmLogging : Pos 25, 1 Bit
   +0x300 FatalAccessTerminationRequested : Pos 26, 1 Bit
   +0x300 DisableSystemAllowedCpuSet : Pos 27, 1 Bit
   +0x300 ProcessStateChangeRequest : Pos 28, 2 Bits
   +0x300 ProcessStateChangeInProgress : Pos 30, 1 Bit
   +0x300 InPrivate        : Pos 31, 1 Bit
   +0x304 Flags            : Uint4B
   +0x304 CreateReported   : Pos 0, 1 Bit
   +0x304 NoDebugInherit   : Pos 1, 1 Bit
   +0x304 ProcessExiting   : Pos 2, 1 Bit
   +0x304 ProcessDelete    : Pos 3, 1 Bit
   +0x304 ManageExecutableMemoryWrites : Pos 4, 1 Bit
   +0x304 VmDeleted        : Pos 5, 1 Bit
   +0x304 OutswapEnabled   : Pos 6, 1 Bit
   +0x304 Outswapped       : Pos 7, 1 Bit
   +0x304 FailFastOnCommitFail : Pos 8, 1 Bit
   +0x304 Wow64VaSpace4Gb  : Pos 9, 1 Bit
   +0x304 AddressSpaceInitialized : Pos 10, 2 Bits
   +0x304 SetTimerResolution : Pos 12, 1 Bit
   +0x304 BreakOnTermination : Pos 13, 1 Bit
   +0x304 DeprioritizeViews : Pos 14, 1 Bit
   +0x304 WriteWatch       : Pos 15, 1 Bit
   +0x304 ProcessInSession : Pos 16, 1 Bit
   +0x304 OverrideAddressSpace : Pos 17, 1 Bit
   +0x304 HasAddressSpace  : Pos 18, 1 Bit
   +0x304 LaunchPrefetched : Pos 19, 1 Bit
   +0x304 Background       : Pos 20, 1 Bit
   +0x304 VmTopDown        : Pos 21, 1 Bit
   +0x304 ImageNotifyDone  : Pos 22, 1 Bit
   +0x304 PdeUpdateNeeded  : Pos 23, 1 Bit
   +0x304 VdmAllowed       : Pos 24, 1 Bit
   +0x304 ProcessRundown   : Pos 25, 1 Bit
   +0x304 ProcessInserted  : Pos 26, 1 Bit
   +0x304 DefaultIoPriority : Pos 27, 3 Bits
   +0x304 ProcessSelfDelete : Pos 30, 1 Bit
   +0x304 SetTimerResolutionLink : Pos 31, 1 Bit
   +0x308 CreateTime       : _LARGE_INTEGER
   +0x310 ProcessQuotaUsage : [2] Uint8B
   +0x320 ProcessQuotaPeak : [2] Uint8B
   +0x330 PeakVirtualSize  : Uint8B
   +0x338 VirtualSize      : Uint8B
   +0x340 SessionProcessLinks : _LIST_ENTRY
   +0x350 ExceptionPortData : Ptr64 Void
   +0x350 ExceptionPortValue : Uint8B
   +0x350 ExceptionPortState : Pos 0, 3 Bits
   +0x358 Token            : _EX_FAST_REF
   +0x360 MmReserved       : Uint8B
   +0x368 AddressCreationLock : _EX_PUSH_LOCK
   +0x370 PageTableCommitmentLock : _EX_PUSH_LOCK
   +0x378 RotateInProgress : Ptr64 _ETHREAD
   +0x380 ForkInProgress   : Ptr64 _ETHREAD
   +0x388 CommitChargeJob  : Ptr64 _EJOB
   +0x390 CloneRoot        : _RTL_AVL_TREE
   +0x398 NumberOfPrivatePages : Uint8B
   +0x3a0 NumberOfLockedPages : Uint8B
   +0x3a8 Win32Process     : Ptr64 Void
   +0x3b0 Job              : Ptr64 _EJOB
   +0x3b8 SectionObject    : Ptr64 Void
   +0x3c0 SectionBaseAddress : Ptr64 Void
   +0x3c8 Cookie           : Uint4B
   +0x3d0 WorkingSetWatch  : Ptr64 _PAGEFAULT_HISTORY
   +0x3d8 Win32WindowStation : Ptr64 Void
   +0x3e0 InheritedFromUniqueProcessId : Ptr64 Void
   +0x3e8 Spare0           : Ptr64 Void
   +0x3f0 OwnerProcessId   : Uint8B
   +0x3f8 Peb              : Ptr64 _PEB
   +0x400 Session          : Ptr64 _MM_SESSION_SPACE
   +0x408 Spare1           : Ptr64 Void
   +0x410 QuotaBlock       : Ptr64 _EPROCESS_QUOTA_BLOCK
   +0x418 ObjectTable      : Ptr64 _HANDLE_TABLE
   +0x420 DebugPort        : Ptr64 Void
   +0x428 WoW64Process     : Ptr64 _EWOW64PROCESS
   +0x430 DeviceMap        : Ptr64 Void
   +0x438 EtwDataSource    : Ptr64 Void
   +0x440 PageDirectoryPte : Uint8B
   +0x448 ImageFilePointer : Ptr64 _FILE_OBJECT
   +0x450 ImageFileName    : [15] UChar
   +0x45f PriorityClass    : UChar
   +0x460 SecurityPort     : Ptr64 Void
   +0x468 SeAuditProcessCreationInfo : _SE_AUDIT_PROCESS_CREATION_INFO
   +0x470 JobLinks         : _LIST_ENTRY
   +0x480 HighestUserAddress : Ptr64 Void
   +0x488 ThreadListHead   : _LIST_ENTRY
   +0x498 ActiveThreads    : Uint4B
   +0x49c ImagePathHash    : Uint4B
   +0x4a0 DefaultHardErrorProcessing : Uint4B
   +0x4a4 LastThreadExitStatus : Int4B
   +0x4a8 PrefetchTrace    : _EX_FAST_REF
   +0x4b0 LockedPagesList  : Ptr64 Void
   +0x4b8 ReadOperationCount : _LARGE_INTEGER
   +0x4c0 WriteOperationCount : _LARGE_INTEGER
   +0x4c8 OtherOperationCount : _LARGE_INTEGER
   +0x4d0 ReadTransferCount : _LARGE_INTEGER
   +0x4d8 WriteTransferCount : _LARGE_INTEGER
   +0x4e0 OtherTransferCount : _LARGE_INTEGER
   +0x4e8 CommitChargeLimit : Uint8B
   +0x4f0 CommitCharge     : Uint8B
   +0x4f8 CommitChargePeak : Uint8B
   +0x500 Vm               : _MMSUPPORT_FULL
   +0x610 MmProcessLinks   : _LIST_ENTRY
   +0x620 ModifiedPageCount : Uint4B
   +0x624 ExitStatus       : Int4B
   +0x628 VadRoot          : _RTL_AVL_TREE
   +0x630 VadHint          : Ptr64 Void
   +0x638 VadCount         : Uint8B
   +0x640 VadPhysicalPages : Uint8B
   +0x648 VadPhysicalPagesLimit : Uint8B
   +0x650 AlpcContext      : _ALPC_PROCESS_CONTEXT
   +0x670 TimerResolutionLink : _LIST_ENTRY
   +0x680 TimerResolutionStackRecord : Ptr64 _PO_DIAG_STACK_RECORD
   +0x688 RequestedTimerResolution : Uint4B
   +0x68c SmallestTimerResolution : Uint4B
   +0x690 ExitTime         : _LARGE_INTEGER
   +0x698 InvertedFunctionTable : Ptr64 _INVERTED_FUNCTION_TABLE
   +0x6a0 InvertedFunctionTableLock : _EX_PUSH_LOCK
   +0x6a8 ActiveThreadsHighWatermark : Uint4B
   +0x6ac LargePrivateVadCount : Uint4B
   +0x6b0 ThreadListLock   : _EX_PUSH_LOCK
   +0x6b8 WnfContext       : Ptr64 Void
   +0x6c0 ServerSilo       : Ptr64 _EJOB
   +0x6c8 SignatureLevel   : UChar
   +0x6c9 SectionSignatureLevel : UChar
   +0x6ca Protection       : _PS_PROTECTION
   +0x6cb HangCount        : Pos 0, 3 Bits
   +0x6cb GhostCount       : Pos 3, 3 Bits
   +0x6cb PrefilterException : Pos 6, 1 Bit
   +0x6cc Flags3           : Uint4B
   +0x6cc Minimal          : Pos 0, 1 Bit
   +0x6cc ReplacingPageRoot : Pos 1, 1 Bit
   +0x6cc Crashed          : Pos 2, 1 Bit
   +0x6cc JobVadsAreTracked : Pos 3, 1 Bit
   +0x6cc VadTrackingDisabled : Pos 4, 1 Bit
   +0x6cc AuxiliaryProcess : Pos 5, 1 Bit
   +0x6cc SubsystemProcess : Pos 6, 1 Bit
   +0x6cc IndirectCpuSets  : Pos 7, 1 Bit
   +0x6cc RelinquishedCommit : Pos 8, 1 Bit
   +0x6cc HighGraphicsPriority : Pos 9, 1 Bit
   +0x6cc CommitFailLogged : Pos 10, 1 Bit
   +0x6cc ReserveFailLogged : Pos 11, 1 Bit
   +0x6cc SystemProcess    : Pos 12, 1 Bit
   +0x6cc HideImageBaseAddresses : Pos 13, 1 Bit
   +0x6cc AddressPolicyFrozen : Pos 14, 1 Bit
   +0x6cc ProcessFirstResume : Pos 15, 1 Bit
   +0x6cc ForegroundExternal : Pos 16, 1 Bit
   +0x6cc ForegroundSystem : Pos 17, 1 Bit
   +0x6cc HighMemoryPriority : Pos 18, 1 Bit
   +0x6cc EnableProcessSuspendResumeLogging : Pos 19, 1 Bit
   +0x6cc EnableThreadSuspendResumeLogging : Pos 20, 1 Bit
   +0x6cc SecurityDomainChanged : Pos 21, 1 Bit
   +0x6cc SecurityFreezeComplete : Pos 22, 1 Bit
   +0x6cc VmProcessorHost  : Pos 23, 1 Bit
   +0x6d0 DeviceAsid       : Int4B
   +0x6d8 SvmData          : Ptr64 Void
   +0x6e0 SvmProcessLock   : _EX_PUSH_LOCK
   +0x6e8 SvmLock          : Uint8B
   +0x6f0 SvmProcessDeviceListHead : _LIST_ENTRY
   +0x700 LastFreezeInterruptTime : Uint8B
   +0x708 DiskCounters     : Ptr64 _PROCESS_DISK_COUNTERS
   +0x710 PicoContext      : Ptr64 Void
   +0x718 EnclaveTable     : Ptr64 Void
   +0x720 EnclaveNumber    : Uint8B
   +0x728 EnclaveLock      : _EX_PUSH_LOCK
   +0x730 HighPriorityFaultsAllowed : Uint4B
   +0x738 EnergyContext    : Ptr64 _PO_PROCESS_ENERGY_CONTEXT
   +0x740 VmContext        : Ptr64 Void
   +0x748 SequenceNumber   : Uint8B
   +0x750 CreateInterruptTime : Uint8B
   +0x758 CreateUnbiasedInterruptTime : Uint8B
   +0x760 TotalUnbiasedFrozenTime : Uint8B
   +0x768 LastAppStateUpdateTime : Uint8B
   +0x770 LastAppStateUptime : Pos 0, 61 Bits
   +0x770 LastAppState     : Pos 61, 3 Bits
   +0x778 SharedCommitCharge : Uint8B
   +0x780 SharedCommitLock : _EX_PUSH_LOCK
   +0x788 SharedCommitLinks : _LIST_ENTRY
   +0x798 AllowedCpuSets   : Uint8B
   +0x7a0 DefaultCpuSets   : Uint8B
   +0x798 AllowedCpuSetsIndirect : Ptr64 Uint8B
   +0x7a0 DefaultCpuSetsIndirect : Ptr64 Uint8B
   +0x7a8 DiskIoAttribution : Ptr64 Void
   +0x7b0 DxgProcess       : Ptr64 Void
   +0x7b8 Win32KFilterSet  : Uint4B
   +0x7c0 ProcessTimerDelay : _PS_INTERLOCKED_TIMER_DELAY_VALUES
   +0x7c8 KTimerSets       : Uint4B
   +0x7cc KTimer2Sets      : Uint4B
   +0x7d0 ThreadTimerSets  : Uint4B
   +0x7d8 VirtualTimerListLock : Uint8B
   +0x7e0 VirtualTimerListHead : _LIST_ENTRY
   +0x7f0 WakeChannel      : _WNF_STATE_NAME
   +0x7f0 WakeInfo         : _PS_PROCESS_WAKE_INFORMATION
   +0x820 MitigationFlags  : Uint4B
   +0x820 MitigationFlagsValues : <unnamed-tag>
   +0x824 MitigationFlags2 : Uint4B
   +0x824 MitigationFlags2Values : <unnamed-tag>
   +0x828 PartitionObject  : Ptr64 Void
   +0x830 SecurityDomain   : Uint8B
   +0x838 ParentSecurityDomain : Uint8B
   +0x840 CoverageSamplerContext : Ptr64 Void
   +0x848 MmHotPatchContext : Ptr64 Void




*kd> dt nt!_LIST_ENTRY
   +0x000 Flink            : Ptr64 _LIST_ENTRY
   +0x008 Blink            : Ptr64 _LIST_ENTRY






kd> dt nt!_TOKEN
   +0x000 TokenSource      : _TOKEN_SOURCE
   +0x010 TokenId          : _LUID
   +0x018 AuthenticationId : _LUID
   +0x020 ParentTokenId    : _LUID
   +0x028 ExpirationTime   : _LARGE_INTEGER
   +0x030 TokenLock        : Ptr64 _ERESOURCE
   +0x038 ModifiedId       : _LUID
   +0x040 Privileges       : _SEP_TOKEN_PRIVILEGES
   +0x058 AuditPolicy      : _SEP_AUDIT_POLICY
   +0x078 SessionId        : Uint4B
   +0x07c UserAndGroupCount : Uint4B
   +0x080 RestrictedSidCount : Uint4B
   +0x084 VariableLength   : Uint4B
   +0x088 DynamicCharged   : Uint4B
   +0x08c DynamicAvailable : Uint4B
   +0x090 DefaultOwnerIndex : Uint4B
   +0x098 UserAndGroups    : Ptr64 _SID_AND_ATTRIBUTES
   +0x0a0 RestrictedSids   : Ptr64 _SID_AND_ATTRIBUTES
   +0x0a8 PrimaryGroup     : Ptr64 Void
   +0x0b0 DynamicPart      : Ptr64 Uint4B
   +0x0b8 DefaultDacl      : Ptr64 _ACL
   +0x0c0 TokenType        : _TOKEN_TYPE
   +0x0c4 ImpersonationLevel : _SECURITY_IMPERSONATION_LEVEL
   +0x0c8 TokenFlags       : Uint4B
   +0x0cc TokenInUse       : UChar
   +0x0d0 IntegrityLevelIndex : Uint4B
   +0x0d4 MandatoryPolicy  : Uint4B
   +0x0d8 LogonSession     : Ptr64 _SEP_LOGON_SESSION_REFERENCES
   +0x0e0 OriginatingLogonSession : _LUID
   +0x0e8 SidHash          : _SID_AND_ATTRIBUTES_HASH
   +0x1f8 RestrictedSidHash : _SID_AND_ATTRIBUTES_HASH
   +0x308 pSecurityAttributes : Ptr64 _AUTHZBASEP_SECURITY_ATTRIBUTES_INFORMATION
   +0x310 Package          : Ptr64 Void
   +0x318 Capabilities     : Ptr64 _SID_AND_ATTRIBUTES
   +0x320 CapabilityCount  : Uint4B
   +0x328 CapabilitiesHash : _SID_AND_ATTRIBUTES_HASH
   +0x438 LowboxNumberEntry : Ptr64 _SEP_LOWBOX_NUMBER_ENTRY
   +0x440 LowboxHandlesEntry : Ptr64 _SEP_CACHED_HANDLES_ENTRY
   +0x448 pClaimAttributes : Ptr64 _AUTHZBASEP_CLAIM_ATTRIBUTES_COLLECTION
   +0x450 TrustLevelSid    : Ptr64 Void
   +0x458 TrustLinkedToken : Ptr64 _TOKEN
   +0x460 IntegrityLevelSidValue : Ptr64 Void
   +0x468 TokenSidValues   : Ptr64 _SEP_SID_VALUES_BLOCK
   +0x470 IndexEntry       : Ptr64 _SEP_LUID_TO_INDEX_MAP_ENTRY
   +0x478 DiagnosticInfo   : Ptr64 _SEP_TOKEN_DIAG_TRACK_ENTRY
   +0x480 BnoIsolationHandlesEntry : Ptr64 _SEP_CACHED_HANDLES_ENTRY
   +0x488 SessionObject    : Ptr64 Void
   +0x490 VariablePart     : Uint8B





* kd> dps nt!KeServiceDescriptorTable L10
fffff806`226fb880  fffff806`22620e10 nt!KiServiceTable
fffff806`226fb888  00000000`00000000
fffff806`226fb890  00000000`000001cf
fffff806`226fb898  fffff806`22621550 nt!KiArgumentTable
fffff806`226fb8a0  00000000`00000000
fffff806`226fb8a8  00000000`00000000
fffff806`226fb8b0  00000000`00000000
fffff806`226fb8b8  00000000`00000000
fffff806`226fb8c0  fffff806`223db180 nt!KiBreakpointTrap
fffff806`226fb8c8  fffff806`223db480 nt!KiOverflowTrap
fffff806`226fb8d0  fffff806`223dfb00 nt!KiRaiseSecurityCheckFailure
fffff806`226fb8d8  fffff806`223dfe40 nt!KiRaiseAssertion
fffff806`226fb8e0  fffff806`223e0180 nt!KiDebugServiceTrap
fffff806`226fb8e8  fffff806`223e0bc0 nt!KiSystemCall64
fffff806`226fb8f0  fffff806`223e0700 nt!KiSystemCall32
fffff806`226fb8f8  00000000`00000000






*0: kd> dps nt!KiServiceTable l10
fffff806`22620e10  fd13b200`fccb5104
fffff806`22620e18  03d23900`0219a602
fffff806`22620e20  fdb29500`01abc700
fffff806`22620e28  01eebc06`012e8905
fffff806`22620e30  01ee3a01`012d9b05
fffff806`22620e38  01386100`01352b00
fffff806`22620e40  013efa00`01df1c00
fffff806`22620e48  01aae300`01347300
fffff806`22620e50  012f1601`01473e01
fffff806`22620e58  014da802`01f89800
fffff806`22620e60  02088e00`0135fc00
fffff806`22620e68  01a22502`01a1bf01
fffff806`22620e70  0131f401`0128f602
fffff806`22620e78  01f44405`01e40b01
fffff806`22620e80  0176f903`011be700
fffff806`22620e88  03ca8800`01e34900

*1: kd> u ZwQueryDirectoryFile L10
nt!ZwQueryDirectoryFile:
fffff802`64848bc0 488bc4          mov     rax,rsp
fffff802`64848bc3 fa              cli
fffff802`64848bc4 4883ec10        sub     rsp,10h
fffff802`64848bc8 50              push    rax
fffff802`64848bc9 9c              pushfq
fffff802`64848bca 6a10            push    10h
fffff802`64848bcc 488d055d700000  lea     rax,[nt!KiServiceLinkage (fffff802`6484fc30)]
fffff802`64848bd3 50              push    rax
fffff802`64848bd4 b835000000      mov     eax,35h
fffff802`64848bd9+ e9623f0100      jmp     nt!KiServiceInternal (fffff802`6485cb40) 
fffff802`64848bde c3              ret
fffff802`64848bdf 90              nop
nt!ZwQuerySystemInformation:
fffff802`64848be0 488bc4          mov     rax,rsp
fffff802`64848be3 fa              cli
fffff802`64848be4 4883ec10        sub     rsp,10h
fffff802`64848be8 50              push    rax


*1: kd> U nt!KiServiceInternal L10
nt!KiServiceInternal:
fffff802`6485cb40 4883ec08        sub     rsp,8
fffff802`6485cb44 55              push    rbp
fffff802`6485cb45 4881ec58010000  sub     rsp,158h
fffff802`6485cb4c 488dac2480000000 lea     rbp,[rsp+80h]
fffff802`6485cb54 48899dc0000000  mov     qword ptr [rbp+0C0h],rbx
fffff802`6485cb5b 4889bdc8000000  mov     qword ptr [rbp+0C8h],rdi
fffff802`6485cb62 4889b5d0000000  mov     qword ptr [rbp+0D0h],rsi
fffff802`6485cb69 fb              sti
fffff802`6485cb6a 65488b1c2588010000 mov   rbx,qword ptr gs:[188h]
fffff802`6485cb73 0f0d8b90000000  prefetchw [rbx+90h]
fffff802`6485cb7a 0fb6bb32020000  movzx   edi,byte ptr [rbx+232h]
fffff802`6485cb81 40887da8        mov     byte ptr [rbp-58h],dil
fffff802`6485cb85 c6833202000000  mov     byte ptr [rbx+232h],0
fffff802`6485cb8c 4c8b9390000000  mov     r10,qword ptr [rbx+90h]
fffff802`6485cb93 4c8995b8000000  mov     qword ptr [rbp+0B8h],r10
fffff802`6485cb9a 4c8d1d4f030000  lea     r11,[nt!KiSystemServiceStart (fffff802`6485cef0)]

nt!KiSystemServiceStart:
fffff802`6485cef0 4889a390000000  mov     qword ptr [rbx+90h],rsp
fffff802`6485cef7 8bf8            mov     edi,eax
fffff802`6485cef9 c1ef07          shr     edi,7
fffff802`6485cefc 83e720          and     edi,20h
fffff802`6485ceff 25ff0f0000      and     eax,0FFFh
nt!KiSystemServiceRepeat:
fffff802`6485cf04 4c8d15 75a93100  lea     r10,[nt!KeServiceDescriptorTable (fffff802`64b77880)]
fffff802`6485cf0b 4c8d1d6e3a3000  lea     r11,[nt!KeServiceDescriptorTableShadow (fffff802`64b60980)]
fffff802`6485cf12 f7437880000000  test    dword ptr [rbx+78h],80h


1: kd> u nt!NtQueryDirectoryFile L20
nt!NtQueryDirectoryFile:
fffff803`6d012d80 4053            push    rbx
fffff803`6d012d82 4883ec50        sub     rsp,50h
fffff803`6d012d86 f69c24a0000000  neg     byte ptr [rsp+0A0h]


fffff803`6d012d8d 488bda          mov     rbx,rdx
fffff803`6d012d90 1ac0            sbb     al,al
fffff803`6d012d92 2402            and     al,2
fffff803`6d012d94 440fb6d8        movzx   r11d,al
fffff803`6d012d98 418ac3          mov     al,r11b
fffff803`6d012d9b 0c01            or      al,1
fffff803`6d012d9d 80bc24b000000000 cmp     byte ptr [rsp+0B0h],0
fffff803`6d012da5 440fb6d0        movzx   r10d,al
fffff803`6d012da9 488b8424a8000000 mov     rax,qword ptr [rsp+0A8h]
fffff803`6d012db1 450f44d3        cmove   r10d,r11d
fffff803`6d012db5 4889442448      mov     qword ptr [rsp+48h],rax
fffff803`6d012dba 8b842498000000  mov     eax,dword ptr [rsp+98h]
fffff803`6d012dc1 410fb6d2        movzx   edx,r10b
fffff803`6d012dc5 89542440        mov     dword ptr [rsp+40h],edx
fffff803`6d012dc9 488bd3          mov     rdx,rbx
fffff803`6d012dcc 89442438        mov     dword ptr [rsp+38h],eax
fffff803`6d012dd0 8b842490000000  mov     eax,dword ptr [rsp+90h]
fffff803`6d012dd7 89442430        mov     dword ptr [rsp+30h],eax
fffff803`6d012ddb 488b842488000000 mov     rax,qword ptr [rsp+88h]
fffff803`6d012de3 4889442428      mov     qword ptr [rsp+28h],rax
fffff803`6d012de8 488b842480000000 mov     rax,qword ptr [rsp+80h]
fffff803`6d012df0 4889442420      mov     qword ptr [rsp+20h],rax
fffff803`6d012df5 e8e68af8ff      call    nt!NtQueryDirectoryFileEx (fffff803`6cf9b8e0)



fffff803`6d012dfa 4883c450        add     rsp,50h
fffff803`6d012dfe 5b              pop     rbx
fffff803`6d012dff c3              ret



Dumping IDT: fffff80764a58000

00:	fffff807623c7500 nt!KiDivideErrorFault
01:	fffff807623c7800 nt!KiDebugTrapOrFault	Stack = 0xFFFFF80764A7A000
02:	fffff807623c7cc0 nt!KiNmiInterrupt	Stack = 0xFFFFF80764A76000
03:	fffff807623c8180 nt!KiBreakpointTrap
04:	fffff807623c8480 nt!KiOverflowTrap
05:	fffff807623c8780 nt!KiBoundFault
06:	fffff807623c8c80 nt!KiInvalidOpcodeFault
07:	fffff807623c9140 nt!KiNpxNotAvailableFault
08:	fffff807623c9400 nt!KiDoubleFaultAbort	Stack = 0xFFFFF80764A74000
09:	fffff807623c96c0 nt!KiNpxSegmentOverrunAbort
0a:	fffff807623c9980 nt!KiInvalidTssFault
0b:	fffff807623c9c40 nt!KiSegmentNotPresentFault
0c:	fffff807623c9fc0 nt!KiStackFault
0d:	fffff807623ca300 nt!KiGeneralProtectionFault
0e:	fffff807623ca640 nt!KiPageFault
0f:	fffff807623bf678 nt!KiIsrThunk+0x78
10:	fffff807623cac80 nt!KiFloatingErrorFault
11:	fffff807623cb000 nt!KiAlignmentFault
12:	fffff807623cb300 nt!KiMcheckAbort	Stack = 0xFFFFF80764A78000
13:	fffff807623cbdc0 nt!KiXmmException
14:	fffff807623cc180 nt!KiVirtualizationException
15:	fffff807623cc640 nt!KiControlProtectionFault
16:	fffff807623bf6b0 nt!KiIsrThunk+0xB0
17:	fffff807623bf6b8 nt!KiIsrThunk+0xB8
18:	fffff807623bf6c0 nt!KiIsrThunk+0xC0
19:	fffff807623bf6c8 nt!KiIsrThunk+0xC8
1a:	fffff807623bf6d0 nt!KiIsrThunk+0xD0
1b:	fffff807623bf6d8 nt!KiIsrThunk+0xD8
1c:	fffff807623bf6e0 nt!KiIsrThunk+0xE0
1d:	fffff807623bf6e8 nt!KiIsrThunk+0xE8
1e:	fffff807623bf6f0 nt!KiIsrThunk+0xF0
1f:	fffff807623c0e40 nt!KiApcInterrupt
20:	fffff807623c29f0 nt!KiSwInterrupt
21:	fffff807623bf708 nt!KiIsrThunk+0x108
22:	fffff807623bf710 nt!KiIsrThunk+0x110
23:	fffff807623bf718 nt!KiIsrThunk+0x118
24:	fffff807623bf720 nt!KiIsrThunk+0x120
25:	fffff807623bf728 nt!KiIsrThunk+0x128
26:	fffff807623bf730 nt!KiIsrThunk+0x130
27:	fffff807623bf738 nt!KiIsrThunk+0x138
28:	fffff807623bf740 nt!KiIsrThunk+0x140
29:	fffff807623ccb00 nt!KiRaiseSecurityCheckFailure
2a:	fffff807623bf750 nt!KiIsrThunk+0x150
2b:	fffff807623bf758 nt!KiIsrThunk+0x158
2c:	fffff807623cce40 nt!KiRaiseAssertion
2d:	fffff807623cd180 nt!KiDebugServiceTrap
2e:	fffff807623bf770 nt!KiIsrThunk+0x170
2f:	fffff807623c2f90 nt!KiDpcInterrupt
30:	fffff807623c13c0 nt!KiHvInterrupt
31:	fffff807623c16a0 nt!KiVmbusInterrupt0
32:	fffff807623c1980 nt!KiVmbusInterrupt1
33:	fffff807623c1c60 nt!KiVmbusInterrupt2
34:	fffff807623c1f40 nt!KiVmbusInterrupt3
35:	fffff807623bf7a8 0xfffff80762c2ba90 (KINTERRUPT fffff80762c64fe0)

36:	fffff807623bf7b0 nt!KiIsrThunk+0x1B0
37:	fffff807623bf7b8 nt!KiIsrThunk+0x1B8
38:	fffff807623bf7c0 nt!KiIsrThunk+0x1C0
39:	fffff807623bf7c8 nt!KiIsrThunk+0x1C8
3a:	fffff807623bf7d0 nt!KiIsrThunk+0x1D0
3b:	fffff807623bf7d8 nt!KiIsrThunk+0x1D8
3c:	fffff807623bf7e0 nt!KiIsrThunk+0x1E0
3d:	fffff807623bf7e8 nt!KiIsrThunk+0x1E8
3e:	fffff807623bf7f0 nt!KiIsrThunk+0x1F0
3f:	fffff807623bf7f8 nt!KiIsrThunk+0x1F8
40:	fffff807623bf800 nt!KiIsrThunk+0x200
41:	fffff807623bf808 nt!KiIsrThunk+0x208
42:	fffff807623bf810 nt!KiIsrThunk+0x210
43:	fffff807623bf818 nt!KiIsrThunk+0x218
44:	fffff807623bf820 nt!KiIsrThunk+0x220
45:	fffff807623bf828 nt!KiIsrThunk+0x228
46:	fffff807623bf830 nt!KiIsrThunk+0x230
47:	fffff807623bf838 nt!KiIsrThunk+0x238
48:	fffff807623bf840 nt!KiIsrThunk+0x240
49:	fffff807623bf848 nt!KiIsrThunk+0x248
4a:	fffff807623bf850 nt!KiIsrThunk+0x250
4b:	fffff807623bf858 nt!KiIsrThunk+0x258
4c:	fffff807623bf860 nt!KiIsrThunk+0x260
4d:	fffff807623bf868 nt!KiIsrThunk+0x268
4e:	fffff807623bf870 nt!KiIsrThunk+0x270
4f:	fffff807623bf878 nt!KiIsrThunk+0x278
50:	fffff807623bf880 0xfffff80764c2e180 (KINTERRUPT ffffa501c2baa8c0)

51:	fffff807623bf888 0xfffff80764c2e180 (KINTERRUPT ffffa501c24ca500)

52:	fffff807623bf890 0xfffff80764c2e180 (KINTERRUPT ffffa501c2baab40)

53:	fffff807623bf898 0xfffff80764f126a0 (KINTERRUPT ffffa501c2baa140)

54:	fffff807623bf8a0 0xfffff807653d7430 (KINTERRUPT ffffa501c32933c0)

55:	fffff807623bf8a8 nt!KiIsrThunk+0x2A8
56:	fffff807623bf8b0 nt!KiIsrThunk+0x2B0
57:	fffff807623bf8b8 nt!KiIsrThunk+0x2B8
58:	fffff807623bf8c0 nt!KiIsrThunk+0x2C0
59:	fffff807623bf8c8 nt!KiIsrThunk+0x2C8
5a:	fffff807623bf8d0 nt!KiIsrThunk+0x2D0
5b:	fffff807623bf8d8 nt!KiIsrThunk+0x2D8
5c:	fffff807623bf8e0 nt!KiIsrThunk+0x2E0
5d:	fffff807623bf8e8 nt!KiIsrThunk+0x2E8
5e:	fffff807623bf8f0 nt!KiIsrThunk+0x2F0
5f:	fffff807623bf8f8 nt!KiIsrThunk+0x2F8
60:	fffff807623bf900 0xfffff80765c729e0 (KINTERRUPT ffffa501c2baa000)

61:	fffff807623bf908 0xfffff80764c2e180 (KINTERRUPT ffffa501c24ca640)

62:	fffff807623bf910 0xfffff80764c2e180 (KINTERRUPT ffffa501c2baac80)

63:	fffff807623bf918 0xfffff80764f126a0 (KINTERRUPT ffffa501c2baa500)

64:	fffff807623bf920 0xfffff80765d27880 (KINTERRUPT ffffa501c3293b40)

65:	fffff807623bf928 nt!KiIsrThunk+0x328
66:	fffff807623bf930 nt!KiIsrThunk+0x330
67:	fffff807623bf938 nt!KiIsrThunk+0x338
68:	fffff807623bf940 nt!KiIsrThunk+0x340
69:	fffff807623bf948 nt!KiIsrThunk+0x348
6a:	fffff807623bf950 nt!KiIsrThunk+0x350
6b:	fffff807623bf958 nt!KiIsrThunk+0x358
6c:	fffff807623bf960 nt!KiIsrThunk+0x360
6d:	fffff807623bf968 nt!KiIsrThunk+0x368
6e:	fffff807623bf970 nt!KiIsrThunk+0x370
6f:	fffff807623bf978 nt!KiIsrThunk+0x378
70:	fffff807623bf980 0xfffff80765bf7ef0 (KINTERRUPT ffffa501c3293c80)

71:	fffff807623bf988 0xfffff80764c2e180 (KINTERRUPT ffffa501c24ca780)

72:	fffff807623bf990 0xfffff80764c2e180 (KINTERRUPT ffffa501c2baadc0)

73:	fffff807623bf998 0xfffff80764eb31c0 (KINTERRUPT ffffa501c2baa640)

74:	fffff807623bf9a0 0xfffff80765d91450 (KINTERRUPT ffffa501c3293500)

75:	fffff807623bf9a8 nt!KiIsrThunk+0x3A8
76:	fffff807623bf9b0 nt!KiIsrThunk+0x3B0
77:	fffff807623bf9b8 nt!KiIsrThunk+0x3B8
78:	fffff807623bf9c0 nt!KiIsrThunk+0x3C0
79:	fffff807623bf9c8 nt!KiIsrThunk+0x3C8
7a:	fffff807623bf9d0 nt!KiIsrThunk+0x3D0
7b:	fffff807623bf9d8 nt!KiIsrThunk+0x3D8
7c:	fffff807623bf9e0 nt!KiIsrThunk+0x3E0
7d:	fffff807623bf9e8 nt!KiIsrThunk+0x3E8
7e:	fffff807623bf9f0 nt!KiIsrThunk+0x3F0
7f:	fffff807623bf9f8 nt!KiIsrThunk+0x3F8
80:	fffff807623bfa00 0xfffff80765bf6050 (KINTERRUPT ffffa501c3293dc0)

81:	fffff807623bfa08 0xfffff80764c2e180 (KINTERRUPT ffffa501c24ca8c0)

82:	fffff807623bfa10 0xfffff80764c2e180 (KINTERRUPT ffffa501c24ca000)

83:	fffff807623bfa18 0xfffff80764eb31c0 (KINTERRUPT ffffa501c2baa780)

84:	fffff807623bfa20 0xfffff80765d27880 (KINTERRUPT ffffa501c3293a00)

					 0xfffff807664c4060 (KINTERRUPT ffffa501c3293000)

85:	fffff807623bfa28 nt!KiIsrThunk+0x428
86:	fffff807623bfa30 nt!KiIsrThunk+0x430
87:	fffff807623bfa38 nt!KiIsrThunk+0x438
88:	fffff807623bfa40 nt!KiIsrThunk+0x440
89:	fffff807623bfa48 nt!KiIsrThunk+0x448
8a:	fffff807623bfa50 nt!KiIsrThunk+0x450
8b:	fffff807623bfa58 nt!KiIsrThunk+0x458
8c:	fffff807623bfa60 nt!KiIsrThunk+0x460
8d:	fffff807623bfa68 nt!KiIsrThunk+0x468
8e:	fffff807623bfa70 nt!KiIsrThunk+0x470
8f:	fffff807623bfa78 nt!KiIsrThunk+0x478
90:	fffff807623bfa80 nt!KiIsrThunk+0x480
91:	fffff807623bfa88 0xfffff80764c2e180 (KINTERRUPT ffffa501c24caa00)

92:	fffff807623bfa90 0xfffff80764c2e180 (KINTERRUPT ffffa501c24ca140)

93:	fffff807623bfa98 0xfffff80764fce320 (KINTERRUPT ffffa501c2baa280)

94:	fffff807623bfaa0 0xfffff80f4b4d40a0 (KINTERRUPT ffffa501c3293640)

95:	fffff807623bfaa8 nt!KiIsrThunk+0x4A8
96:	fffff807623bfab0 nt!KiIsrThunk+0x4B0
97:	fffff807623bfab8 nt!KiIsrThunk+0x4B8
98:	fffff807623bfac0 nt!KiIsrThunk+0x4C0
99:	fffff807623bfac8 nt!KiIsrThunk+0x4C8
9a:	fffff807623bfad0 nt!KiIsrThunk+0x4D0
9b:	fffff807623bfad8 nt!KiIsrThunk+0x4D8
9c:	fffff807623bfae0 nt!KiIsrThunk+0x4E0
9d:	fffff807623bfae8 nt!KiIsrThunk+0x4E8
9e:	fffff807623bfaf0 nt!KiIsrThunk+0x4F0
9f:	fffff807623bfaf8 nt!KiIsrThunk+0x4F8
a0:	fffff807623bfb00 nt!KiIsrThunk+0x500
a1:	fffff807623bfb08 0xfffff80764c2e180 (KINTERRUPT ffffa501c24cab40)

a2:	fffff807623bfb10 0xfffff80764c2e180 (KINTERRUPT ffffa501c24ca280)

a3:	fffff807623bfb18 0xfffff80764fce320 (KINTERRUPT ffffa501c2baa3c0)

a4:	fffff807623bfb20 0xfffff80f4b4d40a0 (KINTERRUPT ffffa501c3293780)

a5:	fffff807623bfb28 0xfffff807653d7430 (KINTERRUPT ffffa501c3293140)

a6:	fffff807623bfb30 nt!KiIsrThunk+0x530
a7:	fffff807623bfb38 nt!KiIsrThunk+0x538
a8:	fffff807623bfb40 nt!KiIsrThunk+0x540
a9:	fffff807623bfb48 nt!KiIsrThunk+0x548
aa:	fffff807623bfb50 nt!KiIsrThunk+0x550
ab:	fffff807623bfb58 nt!KiIsrThunk+0x558
ac:	fffff807623bfb60 nt!KiIsrThunk+0x560
ad:	fffff807623bfb68 nt!KiIsrThunk+0x568
ae:	fffff807623bfb70 nt!KiIsrThunk+0x570
af:	fffff807623bfb78 nt!KiIsrThunk+0x578
b0:	fffff807623bfb80 0xfffff80f4b6c55b0 (KINTERRUPT ffffa501c24cadc0)

b1:	fffff807623bfb88 0xfffff80764c2e180 (KINTERRUPT ffffa501c24cac80)

b2:	fffff807623bfb90 0xfffff80764c2e180 (KINTERRUPT ffffa501c24ca3c0)

b3:	fffff807623bfb98 0xfffff80764c2e180 (KINTERRUPT ffffa501c2baaa00)

b4:	fffff807623bfba0 0xfffff80f4b4d40a0 (KINTERRUPT ffffa501c32938c0)

b5:	fffff807623bfba8 0xfffff807653d7430 (KINTERRUPT ffffa501c3293280)

b6:	fffff807623bfbb0 nt!KiIsrThunk+0x5B0
b7:	fffff807623bfbb8 nt!KiIsrThunk+0x5B8
b8:	fffff807623bfbc0 nt!KiIsrThunk+0x5C0
b9:	fffff807623bfbc8 nt!KiIsrThunk+0x5C8
ba:	fffff807623bfbd0 nt!KiIsrThunk+0x5D0
bb:	fffff807623bfbd8 nt!KiIsrThunk+0x5D8
bc:	fffff807623bfbe0 nt!KiIsrThunk+0x5E0
bd:	fffff807623bfbe8 nt!KiIsrThunk+0x5E8
be:	fffff807623bfbf0 nt!KiIsrThunk+0x5F0
bf:	fffff807623bfbf8 nt!KiIsrThunk+0x5F8
c0:	fffff807623bfc00 nt!KiIsrThunk+0x600
c1:	fffff807623bfc08 nt!KiIsrThunk+0x608
c2:	fffff807623bfc10 nt!KiIsrThunk+0x610
c3:	fffff807623bfc18 nt!KiIsrThunk+0x618
c4:	fffff807623bfc20 nt!KiIsrThunk+0x620
c5:	fffff807623bfc28 nt!KiIsrThunk+0x628
c6:	fffff807623bfc30 nt!KiIsrThunk+0x630
c7:	fffff807623bfc38 nt!KiIsrThunk+0x638
c8:	fffff807623bfc40 nt!KiIsrThunk+0x640
c9:	fffff807623bfc48 nt!KiIsrThunk+0x648
ca:	fffff807623bfc50 nt!KiIsrThunk+0x650
cb:	fffff807623bfc58 nt!KiIsrThunk+0x658
cc:	fffff807623bfc60 nt!KiIsrThunk+0x660
cd:	fffff807623bfc68 nt!KiIsrThunk+0x668
ce:	fffff807623bfc70 0xfffff80762c34e90 (KINTERRUPT fffff80762c659e0)

cf:	fffff807623bfc78 nt!KiIsrThunk+0x678
d0:	fffff807623bfc80 nt!KiIsrThunk+0x680
d1:	fffff807623bfc88 0xfffff80762bfe240 (KINTERRUPT fffff80762c657e0)

d2:	fffff807623bfc90 0xfffff80762bff460 (KINTERRUPT fffff80762c656e0)

d3:	fffff807623bfc98 nt!KiIsrThunk+0x698
d4:	fffff807623bfca0 nt!KiIsrThunk+0x6A0
d5:	fffff807623bfca8 nt!KiIsrThunk+0x6A8
d6:	fffff807623bfcb0 nt!KiIsrThunk+0x6B0
d7:	fffff807623bfcb8 0xfffff80762c2bad0 (KINTERRUPT fffff80762c654e0)

d8:	fffff807623bfcc0 0xfffff80762c2bb50 (KINTERRUPT fffff80762c652e0)

d9:	fffff807623bfcc8 nt!KiIsrThunk+0x6C8
da:	fffff807623bfcd0 nt!KiIsrThunk+0x6D0
db:	fffff807623bfcd8 nt!KiIsrThunk+0x6D8
dc:	fffff807623bfce0 nt!KiIsrThunk+0x6E0
dd:	fffff807623bfce8 nt!KiIsrThunk+0x6E8
de:	fffff807623bfcf0 nt!KiIsrThunk+0x6F0
df:	fffff807623bfcf8 0xfffff80762c2bb20 (KINTERRUPT fffff80762c651e0)

e0:	fffff807623bfd00 nt!KiIsrThunk+0x700
e1:	fffff807623c3460 nt!KiIpiInterrupt
e2:	fffff807623bfd10 0xfffff80762c069b0 (KINTERRUPT fffff80762c653e0)

e3:	fffff807623bfd18 0xfffff80762c2bab0 (KINTERRUPT fffff80762c650e0)

e4:	fffff807623bfd20 nt!KiIsrThunk+0x720
e5:	fffff807623bfd28 nt!KiIsrThunk+0x728
e6:	fffff807623bfd30 nt!KiIsrThunk+0x730
e7:	fffff807623bfd38 nt!KiIsrThunk+0x738
e8:	fffff807623bfd40 nt!KiIsrThunk+0x740
e9:	fffff807623bfd48 nt!KiIsrThunk+0x748
ea:	fffff807623bfd50 nt!KiIsrThunk+0x750
eb:	fffff807623bfd58 nt!KiIsrThunk+0x758
ec:	fffff807623bfd60 nt!KiIsrThunk+0x760
ed:	fffff807623bfd68 nt!KiIsrThunk+0x768
ee:	fffff807623bfd70 nt!KiIsrThunk+0x770
ef:	fffff807623bfd78 nt!KiIsrThunk+0x778
f0:	fffff807623bfd80 nt!KiIsrThunk+0x780
f1:	fffff807623bfd88 nt!KiIsrThunk+0x788
f2:	fffff807623bfd90 nt!KiIsrThunk+0x790
f3:	fffff807623bfd98 nt!KiIsrThunk+0x798
f4:	fffff807623bfda0 nt!KiIsrThunk+0x7A0
f5:	fffff807623bfda8 nt!KiIsrThunk+0x7A8
f6:	fffff807623bfdb0 nt!KiIsrThunk+0x7B0
f7:	fffff807623bfdb8 nt!KiIsrThunk+0x7B8
f8:	fffff807623bfdc0 nt!KiIsrThunk+0x7C0
f9:	fffff807623bfdc8 nt!KiIsrThunk+0x7C8
fa:	fffff807623bfdd0 nt!KiIsrThunk+0x7D0
fb:	fffff807623bfdd8 nt!KiIsrThunk+0x7D8
fc:	fffff807623bfde0 nt!KiIsrThunk+0x7E0
fd:	fffff807623bfde8 0xfffff80762c2ec90 (KINTERRUPT fffff80762c658e0)

fe:	fffff807623bfdf0 0xfffff80762c296f0 (KINTERRUPT fffff80762c655e0)

ff:	fffff807623bfdf8 nt!KiIsrThunk+0x7F8


Registers
MSRs
These must be accessed through rdmsr and wrmsr
STAR (0xC0000081) - Ring 0 and Ring 3 Segment bases, as well as SYSCALL EIP.
Low 32 bits = SYSCALL EIP, bits 32-47 are kernel segment base, bits 48-63 are user segment base.

LSTAR (0xC0000082) - The kernel's RIP SYSCALL entry for 64 bit software.
CSTAR (0xC0000083) - The kernel's RIP for SYSCALL in compatibility mode.
SFMASK (0xC0000084) - The low 32 bits are the SYSCALL flag mask. If a bit in this is set, the corresponding bit in rFLAGS is cleared.


*/
