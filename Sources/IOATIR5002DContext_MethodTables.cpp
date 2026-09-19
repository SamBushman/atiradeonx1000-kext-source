/*
 * IOATIR5002DContext_MethodTables.cpp
 *
 * The two static external-method tables of the 2D context, transcribed from the shipped kext (each is the local
 * static `start(IOService*)::methodDescs` of its class's start()). The `target` word is 0 in the shipped template
 * (getTargetAndMethodForIndex patches nothing - it returns `this` separately); 0xffff is the constant second word;
 * the last three words are (flags, count0, count1) with the standard IOExternalMethod meaning (0 ScalarIScalarO,
 * 2 ScalarIStructO, 3 StructIStructO, 4 ScalarIStructI; 0xffffffff = variable size). Cross-checked against
 * Tools/dump_method_tables.py on the stock kext.
 *
 *   kTwoDBaseMethods      IOATIR5002DContext::start(IOService*)::methodDescs @ 0x47e30, selectors 0-15
 *   kTwoDRegisterMethods  ATIR5002DContext::start(IOService*)::methodDescs   @ 0x4a4d8, selectors 16-18
 */

#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/ATIR5002DContext.h"
#include <libkern/c++/OSMetaClass.h>

#define BASE(fn) OSMemberFunctionCast(void *, static_cast<IOATIR5002DContext *>(0), &IOATIR5002DContext::fn)
#define REGS(fn) OSMemberFunctionCast(void *, static_cast<ATIR5002DContext *>(0), &ATIR5002DContext::fn)

extern const VendorExternalMethod kTwoDBaseMethods[16] = {
    /*  0 */ { 0, 0xffff, BASE(set_surface),                 2, 2, 0xffffffff },
    /*  1 */ { 0, 0xffff, BASE(get_config),                  0, 0, 2 },
    /*  2 */ { 0, 0xffff, BASE(get_surface_info),            2, 2, 0xffffffff },
    /*  3 */ { 0, 0xffff, BASE(swap_surface),                0, 1, 1 },
    /*  4 */ { 0, 0xffff, BASE(scale_surface),               0, 3, 0 },
    /*  5 */ { 0, 0xffff, BASE(lock_memory),                 0, 1, 2 },
    /*  6 */ { 0, 0xffff, BASE(unlock_memory),               0, 1, 1 },
    /*  7 */ { 0, 0xffff, BASE(finish),                      4, 1, 0 },
    /*  8 */ { 0, 0xffff, BASE(declare_image),               0, 3, 1 },
    /*  9 */ { 0, 0xffff, BASE(create_image),                0, 2, 2 },
    /* 10 */ { 0, 0xffff, BASE(create_transfer),             0, 2, 2 },
    /* 11 */ { 0, 0xffff, BASE(delete_image),                4, 1, 0 },
    /* 12 */ { 0, 0xffff, BASE(wait_image),                  4, 1, 0 },
    /* 13 */ { 0, 0xffff, BASE(set_surface_paging_options),  3, 12, 12 },
    /* 14 */ { 0, 0xffff, BASE(set_surface_vsync_options),   3, 12, 12 },
    /* 15 */ { 0, 0xffff, BASE(set_macrovision),             4, 1, 0 },
};

extern const VendorExternalMethod kTwoDRegisterMethods[3] = {
    /* 16 */ { 0, 0xffff, REGS(read_regs),    3, 0xffffffff, 0xffffffff },
    /* 17 */ { 0, 0xffff, REGS(write_regs),   4, 0, 0xffffffff },
    /* 18 */ { 0, 0xffff, REGS(write_2_regs), 4, 2, 0xffffffff },
};
