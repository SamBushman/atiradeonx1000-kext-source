/*
 * GhidraExterns.h - kernel/IOKit data symbols the mechanically ported bodies load by VALUE. The decompile labels every
 * such zero-immediate data reference `_ASICSupportsAGP`; the real target of each site was taken from the kext's Mach-O
 * relocation table (Tools/func_relocs.py) and is named here with an asm label carrying the real symbol.
 */
#ifndef GHIDRAEXTERNS_H
#define GHIDRAEXTERNS_H

#include "ATIRadeonX1000Types.h"

extern "C" UInt32 GH_IOFramebuffer_metaClass asm("__ZN13IOFramebuffer9metaClassE");
extern "C" UInt32 GH_IOService_metaClass asm("__ZN9IOService9metaClassE");
extern "C" UInt32 GH_IOAGPDevice_metaClass asm("__ZN11IOAGPDevice9metaClassE");
extern "C" UInt32 GH_OSNumber_metaClass asm("__ZN8OSNumber9metaClassE");
extern "C" UInt32 GH_IONDRVFramebuffer_metaClass asm("__ZN17IONDRVFramebuffer9metaClassE");
extern "C" UInt32 GH_gIODTPlane asm("_gIODTPlane");
extern "C" UInt32 GH_gIOServicePlane asm("_gIOServicePlane");
extern "C" UInt32 GH_IOPCIDevice_metaClass asm("__ZN11IOPCIDevice9metaClassE");
extern "C" UInt32 GH_OSString_metaClass asm("__ZN8OSString9metaClassE");
extern "C" UInt32 GH_OSData_metaClass asm("__ZN6OSData9metaClassE");
extern "C" UInt32 GH_OSBoolean_metaClass asm("__ZN9OSBoolean9metaClassE");
extern "C" UInt32 GH_OSArray_metaClass asm("__ZN7OSArray9metaClassE");
extern "C" UInt32 GH_OSDictionary_metaClass asm("__ZN12OSDictionary9metaClassE");
extern "C" int GH_page_shift asm("_page_shift");
extern "C" int GH_page_size asm("_page_size");
extern "C" int GH_kernel_task asm("_kernel_task");

#endif
