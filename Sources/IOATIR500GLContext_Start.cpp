/*
 * IOATIR500GLContext_Start.cpp
 *
 * IOATIR500GLContext::start - CONFIRMED, fully transcribed from a real
 * decompile (kext offset 0x7690). Previously unlocated - this is a
 * separate, distinct function from ATIR500GLContext::start (0x28540,
 * the 3D subclass's own start(), already transcribed in
 * Sources/ATIR500GLContext_RegisterState.cpp's sibling files), and is
 * the real answer to a long-standing open question (issue #10): it's the
 * function that populates `regularMethodTable` at +0x2a0.
 *
 * Also, on the success path, allocates this context's IOATIR500Shared
 * handle and links the context into the accelerator's live-context list
 * at accelerator+0x60 - independently confirming
 * IOATIR500Accelerator::liveGLContextListHead's offset from the writer
 * side (previously only known from freeWaitToAllocGART's reader side).
 *
 * Confidence: CONFIRMED for control flow and every field offset touched.
 * The large zero-init block (this+0x7c..this+0x2a4ish) is transcribed
 * offset-by-offset from the real decompile, but most of those individual
 * fields' semantic roles are UNKNOWN beyond "zeroed at context start" -
 * named narratively below rather than invented, matching this project's
 * existing convention for ATIR500GLContext::start's own zero-init block.
 * `allocAllContextBuffers`, `getVRAMDescriptors`, and `allocCommandBuffer`
 * are called but not independently decompiled - see their declarations
 * in IOATIR500GLContext.h / IOATIR500Accelerator.h.
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIRadeonX1000Types.h"

/* FIXED (issue #1, first build attempt): was a local (function-scope)
 * `extern "C" ...` declaration. gcc-4.0.1's C++03 grammar does not
 * allow a linkage-specification as a block-declaration at all - a real
 * syntax error, not a portability nit. Hoisted to file scope, same real
 * target. */
extern "C" void IOATIR500Shared_release(IOATIR500Shared *) asm("__ZNK8OSObject7releaseEv");

/* (re-ported mechanically: see IOATIR500GLContext_start_Port.cpp) */

