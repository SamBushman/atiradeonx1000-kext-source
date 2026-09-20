/* NOTE 2026-09-19: 6 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500Surface_Overlay.cpp
 *
 * The real overlay/subpicture/deinterlace family - CONFIRMED, and the
 * source of this project's most significant unexpected finding for the
 * H.264 project: three of these five real functions are EMPTY, real,
 * intentional no-ops in this exact shipped kext build. See
 * stage8-dvd-overlay-and-2d-acceleration-decoded.md for the full
 * reasoning this led to (video presentation almost certainly happens via
 * an ordinary textured-quad blit, not a dedicated hardware overlay plane,
 * on this GPU generation).
 *
 * Confidence: CONFIRMED. These bodies are not simplified or abridged -
 * this genuinely is everything the real functions do.
 *
 * RE-HOMED (issue #16): these six real mangled symbols all name
 * `ATIR500Surface::` (the concrete subclass) as their receiver, not
 * `IOATIR500Surface::` (the base class) this file previously used -
 * bodies unchanged, only the class qualifier moved. See
 * Headers/ATIR500Surface.h for the real base/subclass split account.
 */

#include "../Headers/ATIR500Surface.h"

/* (re-ported mechanically: see ATIR500Surface_disable_overlay_Port.cpp) */


/* (re-ported mechanically: see ATIR500Surface_enable_overlay_Port.cpp) */


/* (re-ported mechanically: see ATIR500Surface_showbuffer_Port.cpp) */


/* (re-ported mechanically: see ATIR500Surface_dvd_setup_subpicture_Port.cpp) */


/*
 * dvd_setup_overlay - the ONE real, non-stub member of this family.
 * CONFIRMED: stores real geometry and sets a real dirty/enable flag -
 * the same fields setup_buffers (ATIR500DVDContext, a distinct real
 * function) also writes via a different call path, confirming a single
 * shared geometry record.
 */
/* (re-ported mechanically: see ATIR500Surface_dvd_setup_overlay_Port.cpp) */


/*
 * enable_deint - CONFIRMED real, stores the mode; nothing this project
 * decompiled anywhere reads this field back.
 */
/* (re-ported mechanically: see ATIR500Surface_enable_deint_Port.cpp) */

