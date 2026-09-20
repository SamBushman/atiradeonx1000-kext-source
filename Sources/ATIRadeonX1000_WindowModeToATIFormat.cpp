/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIRadeonX1000_WindowModeToATIFormat.cpp
 *
 * RESOLVED (issue #35): `window_mode_to_ati_format`'s real body, real
 * addr 0x3a810. Declared (with a real-mangled-name `asm` alias) in
 * `Sources/ATIR500Surface_ShapeSurface.cpp`, its only real caller; body
 * lives in its own file since it's a plain C-linkage free function, not
 * a class method.
 *
 * Real body: a plain switch on the low 4 bits of `windowModeBits`,
 * mapping a real "window pixel format" selector to a real ATI hardware
 * surface-format code (the same real numbering space this project's
 * other format tables use elsewhere, e.g.
 * `ATIRadeonX1000_DataTables.cpp`'s `ati_format_info_table`) - not
 * cross-referenced against that table's own entries this pass (their
 * real numeric agreement, if any, is a genuine open question, not
 * assumed). Every case value and its real hardware format code below is
 * transcribed exactly as decompiled; any window-mode value not listed
 * (including `case 0`/`1`/`2`/`5`/`0xe`/`0xf`, real gaps in the real
 * switch) real-falls-through to the `default` case, returning `0`.
 *
 * Confidence: CONFIRMED for control flow and every real case
 * value/return - a simple, unambiguous switch, no pointer arithmetic of
 * any kind. No C++ compiler was available in the sandboxed environment
 * this was written in (same standing limitation as every other file in
 * this project).
 */

#include "../Headers/ATIRadeonX1000Types.h"

extern "C" UInt32 window_mode_to_ati_format(UInt32 windowModeBits) asm("__Z25window_mode_to_ati_formatm");

/* (re-ported mechanically: see window_mode_to_ati_format_Port.cpp) */
