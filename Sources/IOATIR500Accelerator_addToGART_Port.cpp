/*
 * IOATIR500Accelerator_addToGART_Port.cpp
 *
 * IOATIR500Accelerator::addToGART (real addr 0x5220, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
 * Tools/port_fn.py); replaces the earlier hand-written body, which the callee/atomics comparison (Tools/callee_compare.py) showed had
 * dropped or simplified parts of the original.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIR5002DContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"



/* real addr 0x5220 */
/* CORRECTED (#86): the mechanical port took Ghidra's param_1 (which is `this`, r3) for the descriptor and emitted a tail call through the
 * descriptor's own vtable. The shipped body (otool -tV, 0x5220) loads `this`' vtable, reads the byte count at this+0x830 and calls
 * vtable slot +0x590 (addToMinMaxGART) on `this` with (descriptor = r4, outOffset = r5, minOffset = 0, maxOffset = (this[0x830] >> 2) << page_shift). */
IOReturn IOATIR500Accelerator::addToGART(IOMemoryDescriptor *descriptor, UInt32 *result) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    /* the shipped body tail-calls: the callee's r3 is this function's result (the earlier `void` typing, issue #26, hid it) */
    return addToMinMaxGART(descriptor, result, 0, (M<UInt32>(self + 0x830) >> 2) << GH_page_shift);
}
