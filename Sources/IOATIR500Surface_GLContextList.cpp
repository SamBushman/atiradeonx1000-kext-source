/*
 * IOATIR500Surface_GLContextList.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `add_gl_context_to_list` and `remove_gl_context_from_list` - the
 * real singly-linked-list maintenance for the GL-context list rooted
 * at this surface's own +0x88 field (the same real list
 * `update_contexts`/`reset_req_bits` already established elsewhere in
 * this file set), each node's own "next" link at its own +0x84.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500GLContext.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

void IOATIR500Surface::add_gl_context_to_list(IOATIR500GLContext *context) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *ctx = reinterpret_cast<UInt8 *>(context);
    U32At(ctx, 0x84) = U32At(self, 0x88);
    U32At(self, 0x88) = reinterpret_cast<UInt32>(context);
    U32At(self, 0xc18) |= U32At(ctx, 0x8c);
}

void IOATIR500Surface::remove_gl_context_from_list(IOATIR500GLContext *context) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *ctx = reinterpret_cast<UInt8 *>(context);
    UInt8 *node = *reinterpret_cast<UInt8 **>(self + 0x88);
    if (node == ctx) {
        U32At(self, 0x88) = U32At(ctx, 0x84);
    } else {
        UInt8 *prev;
        do {
            prev = node;
            node = *reinterpret_cast<UInt8 **>(prev + 0x84);
            if (node == nullptr) break;
        } while (node != ctx);
        U32At(prev, 0x84) = U32At(ctx, 0x84);
    }
    U32At(ctx, 0x84) = 0;
    reset_req_bits();
}
