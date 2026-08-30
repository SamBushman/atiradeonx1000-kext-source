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
 */

#include "../Headers/IOATIR500Surface.h"

void IOATIR500Surface::disable_overlay(void) {
    /* CONFIRMED: real function body is empty. Nothing here. */
}

void IOATIR500Surface::enable_overlay(void) {
    /* CONFIRMED: real function body is empty. Nothing here. */
}

void IOATIR500Surface::showbuffer(UInt32 bufferIndex, UInt32 param2) {
    (void)bufferIndex; (void)param2;
    /* CONFIRMED: real function body is empty. Nothing here. */
}

void IOATIR500Surface::dvd_setup_subpicture(UInt32 param1, UInt32 param2, UInt32 param3) {
    (void)param1; (void)param2; (void)param3;
    /* CONFIRMED: real function body is empty. Nothing here. */
}

/*
 * dvd_setup_overlay - the ONE real, non-stub member of this family.
 * CONFIRMED: stores real geometry and sets a real dirty/enable flag -
 * the same fields setup_buffers (ATIR500DVDContext, a distinct real
 * function) also writes via a different call path, confirming a single
 * shared geometry record.
 */
void IOATIR500Surface::dvd_setup_overlay(UInt32 x, UInt32 y, UInt32 w, UInt32 h) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    *reinterpret_cast<UInt16 *>(self + 0x94) = static_cast<UInt16>(x);
    *reinterpret_cast<UInt16 *>(self + 0x96) = static_cast<UInt16>(h); /* CONFIRMED real param order: h before w at these offsets */
    *reinterpret_cast<UInt16 *>(self + 0x9a) = static_cast<UInt16>(w);
    *reinterpret_cast<UInt16 *>(self + 0x98) = static_cast<UInt16>(y);
    *reinterpret_cast<UInt32 *>(self + 0xd94) = 1; /* CONFIRMED real dirty/enable flag */
}

/*
 * enable_deint - CONFIRMED real, stores the mode; nothing this project
 * decompiled anywhere reads this field back.
 */
void IOATIR500Surface::enable_deint(UInt32 mode) {
    *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(this) + 0xdac) = mode;
}
