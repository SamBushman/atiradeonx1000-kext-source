/* NOTE 2026-09-19: 2 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
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

/* (re-ported mechanically: see IOATIR500Surface_add_gl_context_to_list_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_remove_gl_context_from_list_Port.cpp) */

