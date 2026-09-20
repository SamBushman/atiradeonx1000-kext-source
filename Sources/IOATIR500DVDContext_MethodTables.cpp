/*
 * IOATIR500DVDContext_MethodTables.cpp
 *
 * The two static external-method tables of the DVD context, transcribed from the shipped kext (each is the local
 * static `start(IOService*)::methodDescs` of its class's start()). Layout as in IOATIR5002DContext_MethodTables.cpp:
 * {target = 0, 0xffff, function, flags, count0, count1}, cross-checked against Tools/dump_method_tables.py.
 *
 *   kDVDBaseMethods  IOATIR500DVDContext::start(IOService*)::methodDescs @ 0x485e8, selectors 0-9
 *   kDVDSubMethods   ATIR500DVDContext::start(IOService*)::methodDescs   @ 0x4ab58, selectors 10-21
 */

#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include <libkern/c++/OSMetaClass.h>

#define BASE(fn) OSMemberFunctionCast(void *, static_cast<IOATIR500DVDContext *>(0), &IOATIR500DVDContext::fn)
#define SUB(fn)  OSMemberFunctionCast(void *, static_cast<ATIR500DVDContext *>(0), &ATIR500DVDContext::fn)

extern const VendorExternalMethod kDVDBaseMethods[10] asm("__ZZN19IOATIR500DVDContext5startEP9IOServiceE11methodDescs");   /* stock: the function-local static `methodDescs` of start(IOService*) */
extern const VendorExternalMethod kDVDBaseMethods[10] = {
    /*  0 */ { 0, 0xffff, BASE(set_surface),      4, 3, 0 },
    /*  1 */ { 0, 0xffff, BASE(get_config),       0, 0, 2 },
    /*  2 */ { 0, 0xffff, BASE(get_status),       0, 0, 1 },
    /*  3 */ { 0, 0xffff, BASE(get_surface_size), 0, 0, 2 },
    /*  4 */ { 0, 0xffff, BASE(lock_all_buffers), 2, 1, 256 },
    /*  5 */ { 0, 0xffff, BASE(unlock_memory),    0, 1, 1 },
    /*  6 */ { 0, 0xffff, BASE(write_buffer),     3, 0xffffffff, 0 },
    /*  7 */ { 0, 0xffff, BASE(finish),           4, 0, 0 },
    /*  8 */ { 0, 0xffff, BASE(declare_image),    0, 3, 1 },
    /*  9 */ { 0, 0xffff, BASE(delete_image),     4, 1, 0 },
};

extern const VendorExternalMethod kDVDSubMethods[12] asm("__ZZN17ATIR500DVDContext5startEP9IOServiceE11methodDescs");   /* stock: the function-local static `methodDescs` of start(IOService*) */
extern const VendorExternalMethod kDVDSubMethods[12] = {
    /* 10 */ { 0, 0xffff, SUB(show_buffer),          0, 2, 0 },
    /* 11 */ { 0, 0xffff, SUB(dvd_setup_overlay),    0, 5, 0 },
    /* 12 */ { 0, 0xffff, SUB(dvd_enable_overlay),   0, 1, 0 },
    /* 13 */ { 0, 0xffff, SUB(read_regs),            3, 0xffffffff, 0xffffffff },
    /* 14 */ { 0, 0xffff, SUB(write_regs),           0, 2, 0 },
    /* 15 */ { 0, 0xffff, SUB(dvd_setup_subpicture), 0, 4, 0 },
    /* 16 */ { 0, 0xffff, SUB(set_macrovision),      0, 2, 0 },
    /* 17 */ { 0, 0xffff, SUB(dvd_enable_deint),     0, 1, 0 },
    /* 18 */ { 0, 0xffff, SUB(doIDCT),               3, 0xffffffff, 0 },
    /* 19 */ { 0, 0xffff, SUB(wait_for_stamps),      4, 2, 0 },
    /* 20 */ { 0, 0xffff, SUB(check_stamps),         0, 2, 1 },
    /* 21 */ { 0, 0xffff, SUB(setup_buffers),        0, 5, 0 },
};
