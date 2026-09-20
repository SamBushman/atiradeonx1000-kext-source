/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Accelerator_NewUserClient.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `IOATIR500Accelerator::newUserClient` - real addr 0x2070. The header's
 * own already-thorough comment (`Headers/IOATIR500Accelerator.h`)
 * documents the real type dispatch and factory slots; this file adds
 * the actual C++ transcription.
 *
 * Real body: dispatches on `type` to one of four real factory vtable
 * slots (`+0x5d4`/`+0x5e0`/`+0x5d8`/`+0x5dc` - already-established
 * `new_surface`/`new_gl_context`/`new_2d_context`/`new_dvd_context`).
 * `type==0` (Surface) additionally allocates a real `OSDictionary` of
 * one entry (`"IOUserClientCrossEndianCompatible"` -> `kOSBooleanTrue`)
 * and passes it as the new client's `open`-style properties argument;
 * every other type passes `nullptr` there instead. Tags the new
 * client's own `+0x78` field with the caller's task, then calls three
 * more real vtable methods on it (`+0x150`, `+0x3a4`, `+0x348` - exact
 * Apple virtual-method identities UNKNOWN, referenced only by vtable
 * slot in the real decompile, matching this project's own header
 * comment) - unwinding (`+0x3a8`/`+0x18`) and releasing the properties
 * dictionary on any failure.
 *
 * Confidence: CONFIRMED for control flow and every real offset - a
 * real, complete, standalone decompile.
 */

#include "../Headers/IOATIR500Accelerator.h"

namespace {
typedef void *(*FactoryFn)(void *);
typedef bool (*InitFn)(void *, void *);
typedef bool (*BoolArgFn)(void *, void *);
typedef void (*VoidArgFn)(void *, void *);
typedef void (*ReleaseFn)(void *);
typedef bool (*SetObjectFn)(void *, const char *, void *);
} // namespace

/* both real mangled names CONFIRMED via Ghidra's own external-symbol
 * import table (ground truth, not guessed) - see this project's
 * established `DumpExternals2`/`DumpExternalData` technique. */
extern "C" void *OSDictionary_withCapacity(UInt32 capacity) asm("__ZN12OSDictionary12withCapacityEj");
extern "C" void *g_kOSBooleanTrue asm("_kOSBooleanTrue");

/* (re-ported mechanically: see IOATIR500Accelerator_newUserClient_Port.cpp) */

