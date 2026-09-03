# Known gaps and next steps

A consolidated list of every real `TODO`/`UNKNOWN` this reconstruction pass left behind, grouped by
theme. Mirrored into GitHub issues on this repo for tracking. See `README.md` for the confidence-tier
definitions this list uses.

## 1. Compilation has never been attempted

The single largest gap: nothing in this repo has been built. There is no Tiger/Leopard IOKit SDK or
PowerPC kext toolchain available in the environment this was written in. **Requires real hardware/
toolchain access to close.** See `README.md`'s "What to do when hardware is available again" section for
the concrete first steps.

## 2. `process_command_buffer`'s opcode handlers - the largest reconstruction gap

**Status: COMPLETE.** Every real opcode this driver's embedded marker language actually dispatches is now
transcribed. This was verified mechanically, not just by inspection: grepping the complete raw decompile
for every `uVar38 <op> 0x??000000` comparison actually present in the function's ~3315 lines produces the
exact same opcode set this project's dispatch `switch` now handles (either via an explicit `case` or via
one of the two confirmed opcode-range checks, `0x06-0x15` and `0x16-0x25`) - nothing left over on either
side. Along the way, this pass found this project's ORIGINAL opcode inventory (built earlier from staged
narrative documents, not a full mechanical sweep) had actually missed FOUR real opcodes entirely -
`0x2d` (**CORRECTED, issue #12 item 4**: originally cataloged here as reserved/dead, same shape as the
`0x17/0x1a/0x1d/0x20/0x23` gaps - it isn't; it's a real, large FSAA-resolve-blit handler, see the opcode
0x31/0x2d resolution below in this section for the full writeup), `0x33` (a real inline color+Z-buffer register burst), `0x34` (a real
query/fence-slot allocator), and `0x35` (another render-target generation-stamp opcode) - plus a fifth,
`0x32`, that WAS known by number but whose real body had never been located (a large depth-flush +
per-tile texture-fetch-register-patch function, the closest thing in this language to opcode 0x2d's own
tile loop - also CORRECTED from an earlier "0x31" mislabel, see the opcode 0x31/0x2d resolution below in this section). All five are now fully
transcribed.

**Major structural corrections this pass** (found while transcribing the remaining opcodes, by finally
reading the complete raw decompile rather than the excerpts used earlier): this project's model of the
function's own SKELETON - not just individual opcode bodies - had several real, disclosed mistakes, now
fixed:

- **Opcodes `0x06-0x15` are a real FULL TEXTURE BIND, not a plain unbind.** This project's earlier pass
  wrongly lumped this whole 16-value range into the same simple unbind handler as the real, separate
  `0x16-0x25` family. The real range is checked as literally the FIRST condition in the whole per-record
  dispatch and does unbind-old + table-lookup-new + `add_texture_to_stream` + format-field setup +
  `WriteTextureOffset` - see `handle_texture_bind`'s own header comment for the full real sequence. Fixing
  this also surfaced and fixed two real header-signature bugs it depends on:
  `IOATIR500Surface::resolve_fsaa_buffer` and `surface_buffer_idx_mask` were both missing real parameters.
- **There is no real PM4 Type-0/Type-2/Type-3 packet dispatch anywhere in this function.** This project's
  earlier version of this file invented that pre-check by analogy with generic AMD PM4 command-processor
  knowledge, not from this specific decompile - confirmed absent by a complete read of the real loop top.
  Removed, along with the now-dead `PM4_TYPE`/`PM4_TYPE0_COUNT`/`PM4_TYPE0_BASE`/`PM4_TYPE3_OPCODE` helpers.
- **The walk's real initial record pointer comes from `this` itself, not the `descriptor` parameter.** The
  real starting point is `&(*(VendorCommandBufferHeader**)(this+0xe0))->chainLinkOrGeneration` (offset
  `+0x1c`) - this function processes a command stream it owns internally. `VendorCommandDescriptor`
  (the `descriptor` parameter) is real, but is used PURELY AS AN OUTPUT, written only right before every
  real return - see its own corrected doc comment in `ATIRadeonX1000Types.h`.
- **The real exit tail (`LAB_00031340`) is a pause/resume mechanism, not a plain "return success."** When
  the walk reaches a record whose real distance is (or is forced to) zero, the function does NOT just
  return - it writes four real fields describing pending/leftover state into `descriptor` and returns a
  real accumulated status code. This project's earlier "if distance==0, return kIOReturnSuccess" was a
  real oversimplification, now replaced with the full real mechanism (see `ProcessCommandBufferState`'s
  new `forceTerminate` flag and the dispatch loop's own tail comment).
- **Self-consuming a record does NOT mean "advance by a fixed amount."** Several already-transcribed
  handlers (the plain unbind family, opcode `0x27`, opcode `0x36`) had wrongly modeled
  `*record = 0x80000000; return record + 1;` - the real driver has no such per-opcode fixed advance;
  EVERY opcode, self-consuming or not, relies on the shared tail's distance-based advance using the
  CURRENT record's own natural embedded distance field. Fixed to `return record;` (this file's
  established "use the generic advance" signal) at all three sites.

**Update: as of this pass, every opcode in `Sources/ATIR500GLContext_ProcessCommandBuffer.cpp` is fully
transcribed from complete real decompiles - no stub handlers remain.** The per-opcode history below is
kept for the record of what was found and corrected along the way:

- ~~Opcodes `0x02-0x05` (HyperZ/HiZ block management)~~ RESOLVED - all four fully transcribed from complete
  real decompiles, including opcode `0x05`'s real cross-context HiZ state sharing.
- ~~Opcodes `0x06-0x15`~~ RESOLVED (and RETARGETED - see this section's own header above: this is a real
  full texture BIND, a much larger real operation than the plain unbind this project first assumed).
- ~~Opcode `0x26`/`0x27` (transfer-buffer bind/unbind)~~ RESOLVED - both fully transcribed.
- ~~Opcode `0x28` (single render-target + scissor)~~ RESOLVED - fully transcribed via `RTOffsetTilingBurst`.
- ~~Opcode `0x29` (vertex-format switch table)~~ RESOLVED - the real 8-case enum-remapping switch was
  confirmed and transcribed via `discard_command_buffer`'s independent trace of the same opcode (see
  section 5's discovery of opcode `0x36`, found the same way). One real open item remains: whether this
  main execute-path handler processes a fixed 4 slots (as `discard_command_buffer` does) or the dynamic
  `attachmentCount` - not independently re-confirmed for this exact function.
- ~~Opcode `0x2a` (render-target-pair + scissor)~~ RESOLVED - fully transcribed (`RTOffsetTilingBurst`
  reused twice, real duplicated scissor-Y write into two record slots).
- ~~Opcode `0x2b` (explicit flush)~~ RESOLVED - fully transcribed, threaded through
  `ProcessCommandBufferState`.
- ~~Opcode `0x2c` (mip-aware scissor intersect)~~ RESOLVED - fully transcribed via `RTOffsetTilingBurst`.
  Real, notable finding: this opcode reads BOTH `this+0x354` and `this+0x358` together as a Y/X pair,
  which is new evidence for (but doesn't resolve) section 3's open `build_scissor` question about
  `this+0x354` never being written.
- ~~Opcode `0x2f` (HyperZ commit)~~ RESOLVED - fully transcribed, including the real trailing vtable call
  through slot `+0x5a4`. ~~That slot's real virtual-method NAME is still unknown~~ **RESOLVED (issue
  #12.1)**: it's `ATIR500GLContext::invalidate()` (kext offset 0x26fb0, real body fully transcribed - a
  one-line dirty-bit set on the object at `this+0x108`). Verified via the vtable slot's real raw bytes
  cross-checked against a second, already-known-correct slot on the same vtable before trusting it (see
  `Headers/ATIR500GLContext.h`'s `invalidate()` declaration for the full method). All six real call sites
  (opcodes 0x02-0x05/0x29/0x2f/0x41 and `restore_state_destroyed_by_pageoff`) updated to call it by name.
- ~~Opcode `0x30` (FSAA resolve setup)~~ RESOLVED - fully transcribed. Found and fixed a real bug in this
  project's own `IOATIR500Surface::resolve_fsaa_buffer` declaration while doing so: it was missing one of
  four real trailing dword parameters the actual call site passes.
- **Opcode `0x31` (FSAA resolve blit) - entirely stubbed.** This is the single largest remaining gap in
  the whole file: a complete textured-quad draw with real floating-point NDC/viewport math and US-block
  shader headers, reusing the same `_g_r500_3d_blit_state_packet` template as
  `restore_state_destroyed_by_pageoff`. Full real trace already exists in
  `g5-h264-gpu-decode`'s `promo4-client/reveng/stage4-opcode-range-0x02-0x31-traced.md`.
- ~~Opcodes `0x37`/`0x38`/`0x39`~~ RESOLVED - all three fully transcribed (deferred texture/render-target
  offset patch, address fixup, vertex-attribute binding). Both `0x37`'s and `0x38`'s open low-confidence
  flags are now RESOLVED (issue #12 item 5, see below):
  - `0x37`'s "read of `uVar75` with no visible assignment" is fully explained: a closer re-read of this
    opcode's own real preamble finds a real, previously-untranscribed `uVar71 = puVar61[2];` read right at
    the top of the whole opcode block, before either sub-branch runs. That's the real source (`record[2]`) -
    this project's earlier guess (the destroyed original `uVar38` entry count) had plausible shape but was
    not the real answer. No remaining ambiguity; see `handle_deferred_offset_patch`'s own comment.
  - `0x38`'s `puVar65[2]` read-after-overwrite is UPGRADED from "not independently confirmed" to confirmed
    via strong structural corroboration: the directly adjacent opcode `0x3d` in the same function does the
    textually identical "self-consume 4 dwords to `0x80000000`, then use a value from the same slot"
    pattern, but there Ghidra's own decompile cleanly introduces a pre-overwrite temporary rather than
    re-reading through the store - the same real compiler idiom, just rendered two different ways by the
    decompiler for two textually-identical real cases. See `handle_address_fixup`'s own comment for the
    full argument.
- ~~Opcode `0x3a`~~ RESOLVED - a real, unconditional 17-slot clear (the vertex-attribute-slot range opcode
  0x39 populates). Also fixed a real infinite-loop-shaped bug this same opcode's transcription in
  `discard_command_buffer` had (a loop-bound comparison that could never become true), and removed a
  fabricated `record[1]`-driven conditional gate that a full read of the real execute-path body does not
  support.
- ~~Opcode `0x3d`~~ RESOLVED - a trivial real forward to `IOATIR500Surface::set_volatile_state`. Also fixed
  that method's own declared signature (was `UInt32*` state passed as a value at the real call site, not
  taken by reference as this project's header previously modeled with an added `&`).
- ~~Opcodes `0x3b`/`0x3e`/`0x3f`/`0x40`/`0x43`~~ RESOLVED - all five fully transcribed as individually
  distinct handlers (`handle_query_buffer_bind`, `handle_rt0_texture_commit`,
  `handle_rendertarget_tiling_commit`, `handle_index_buffer_commit`, `handle_texture_commit_with_generation`),
  replacing the earlier catch-all stub that wrongly assumed all five (plus `0x3a`/`0x3d`) were
  "structurally identical." Real, notable findings: a THIRD distinct atomic-decrement magnitude
  (`-0x10000`, used by `0x3e`/`0x43`, alongside the already-known `-1` and `-0xffff`); `0x40` is the one
  variant in this family that does NOT call `restore_state_destroyed_by_pageoff` even when gated on;
  `0x3f` reuses the same format table five times in a real cascading bit-patch sequence into one register
  slot, the densest single-register patch outside opcode 0x2d/0x31 (**CORRECTED, issue #12 item 4**: this
  cascading idiom turns out to appear at BOTH real opcodes 0x2d and 0x31, not just the one then labeled
  "0x31" - see the opcode 0x31/0x2d resolution earlier in this section); `0x40` uses a third, previously-unused format table (`FormatTableLookup_0x0004d2e4`).
- ~~Opcode `0x41`~~ RESOLVED - fully transcribed, the largest single opcode after 0x2d (**CORRECTED, issue
  #12 item 4**: was "0x31" - see the opcode 0x31/0x2d resolution earlier in this section). Real per-color-
  attachment loop populating the `this+0x3b2` alternate-mode table (the SAME table opcodes
  0x02-0x05/0x28/0x29/0x2a/0x2c read), a separate depth-attachment bind with real HyperZ block auto-
  allocation (`HZMEM_Alloc`, newly declared this pass), and a separate stencil-attachment bind that reuses
  the depth bind's own staging field (`this+0x348`) for a second, distinct purpose - confirmed real, not a
  transcription artifact. Found and declared a real, previously-unknown helper function this opcode calls
  three times (`get_texture`) - its own body was not independently decompiled, called opaquely rather than
  guessed-and-inlined. Also found that `HZMEM_GetBlockCount`/`HZMEM_IsPartial` were already being called
  throughout this project's own code without ever being declared anywhere - a real gap, now fixed
  (ATIRadeonX1000Registers.h). One real transcription bug caught during review: a big-endian byte-order
  mixup extracting the low/high bytes of a 16-bit value (`this+0x5d4`/`this+0x5d5`) - fixed.
- ~~Opcodes `0x44`/`0x45`/`0x46`~~ RESOLVED - **every opcode in `process_command_buffer` is now fully
  transcribed.** `0x44` (transfer-buffer GART completion) - real, notable finding: the first place this
  project has found `map_transfer_to_GART` called directly from inside `process_command_buffer` itself
  (inline, not deferred) rather than only from the bind-family opcodes. `0x45` (real
  `build_surface_from_texture` + a newly-found `IOATIR500Surface::decompress_and_flush_depth_buffer` call
  pair, now declared) - real, notable finding: this project's earlier naming had 0x45 confused with "fast
  clear"; 0x46 is the real fast-clear opcode, 0x45 is a real depth-buffer flush/decompress mechanism.
  `0x46` re-verified against a fresh, complete read of its real call site (`process_kATIGLStreamFastClearColor(this,puVar65)`,
  no extra arguments) - the existing handler was already correct.

## 3. Register-state serialization: mostly done, one open question, two functions still bodies-empty

`write_kernel_context_buffer_regs` and `build_scissor` in `Sources/ATIR500GLContext_RegisterState.cpp`
have now been fully transcribed from a complete real decompile (not just summarized) - real per-mip
offset/tiling math, every register write in real order, HZMEM_GetBlockOffset calls, and a 6th independent
sighting of `SC_CLIP_RULE = 0xaaaa`.

~~**A real, open question this transcription surfaced**: `build_scissor`'s real decompiled body only ever
writes `this+0x358` (`scissorX`) - it never touches `this+0x354` (`scissorY`) at all.~~ **RESOLVED (issue
#11)**: an exhaustive whole-kext scan (every instruction in the binary, not just this class) for the
literal offset `0x354` finds exactly three real references and no others - `ATIR500GLContext::start`
zero-initializes it once, `write_kernel_context_buffer_regs` relays it verbatim alongside `scissorX`, and
opcode 0x2c's handler in `process_command_buffer` takes the pairwise MAX of it (split into high/low
16-bit halves) against the incoming record's own bound, exactly as this project's opcode traces already
assumed. So the two fields genuinely are used as a paired bound, and no other function anywhere writes
`this+0x354` by direct offset - it is always the constructor's 0 in every path this project has traced,
which makes it a functional no-op in opcode 0x2c's MAX clamp (0 never wins). Two narrower possibilities
remain, worth a note but not further open work: a write via a computed (non-literal) offset this scan
can't see, or this value is legitimately always 0 on real hardware and not a bug at all. See
`Sources/ATIR500GLContext_RegisterState.cpp`'s `build_scissor` comment for the full trace.

~~`restore_state_destroyed_by_pageoff` (the capstone function) and `compute_sc_hyperz_en`/
`compute_zb_bw_cntl`'s real bit-level HyperZ decision logic remain TODO stubs~~ **RESOLVED**: all three
are now fully transcribed from complete real decompiles (`Sources/ATIR500GLContext_RestoreState.cpp`,
`Sources/ATIR500GLContext_RegisterState.cpp`). This closes issue #4 entirely. `compute_sc_hyperz_en`/
`compute_zb_bw_cntl` revealed and named two real per-surface flags
(`ATIR500SurfaceBuffer::hyperZEligible`/`zbBandwidthEligible`).

`restore_state_destroyed_by_pageoff`'s dense ~120-pair transcription's transposition-risk caveat is now
**RESOLVED (issue #12 item 6)** - a full systematic spot-check (not sampled) re-verified every single
(index, value) pair against a fresh re-decompile; all ~120 check out exactly, including the one
transposition already caught in an earlier pass (confirmed still correct, not re-broken). One SEPARATE
real bug WAS found and fixed outside the pair table this pass: the ring-buffer-slot completion-stamp
accumulator was at `accel+0x1e0` instead of the real `accel+0x780` (the raw decompile indexes it via a
real `int*`-typed local, `piVar9[0x1e0]` = dword index, i.e. byte offset `0x1e0*4`, not a raw byte offset
as originally transcribed) - independently cross-confirmed against `ATIR500GLContext_TextureLoad.cpp`'s
`compact_current_textures`, which calls the identical real vtable+0x54c stamp-accumulator against
`accel+0x780` and already named this exact function/field pairing in its own header comment (the two
files disagreed with each other before this fix). The rest of the function's scaffolding (header-block
copy, dword-count/pad computation, `map_transfer_to_GART`/`submit_buffer` tail) was also individually
re-checked and found already correct. See `Sources/ATIR500GLContext_RestoreState.cpp`'s own header comment
for the full writeup.

## 4. Several real internal helper functions - RESOLVED (issue #5), all now reconstructed

`build_scissor`, `GetTextureOffset`/`WriteTextureOffset`, `GetVertexArrayOffset`/`WriteVertexArrayOffset`,
`GetQueryOffset`, `add_texture_to_stream`/`remove_texture_from_stream`, `map_transfer_to_GART`,
`process_kATIGLStreamFastClearColor`, `build_surface_from_texture`, `discard_command_buffer` are now all
**fully reconstructed** from complete real decompiles.

**RESOLVED this pass (issue #5)**: `alloc_and_load_texture`, `compact_current_textures`,
`submit_context_buffer`, `get_texture`, and `convertIOGLBufferToBufIdx` are now ALL fully transcribed too -
see `Sources/ATIR500GLContext_TextureLoad.cpp` and (for `convertIOGLBufferToBufIdx`, a real free function,
not a member) `Sources/ATIR500GLContext_ProcessCommandBuffer.cpp`. Real findings along the way:
- `get_texture` was close to this project's own guess (the "pending-flush + alloc_and_load_texture +
  restore_state + map_transfer_to_GART" bundle), plus a real atomic packed-counter update this project
  hadn't anticipated.
- `alloc_and_load_texture` is really `void` and `compact_current_textures` really returns a value - this
  project had the two return types swapped. Two more return-type drifts fixed along the way:
  `write_kernel_context_buffer_regs` (declared `void`, really `UInt32`) and `submit_context_buffer`
  (declared `IOReturn`, really `void`).
- `submit_context_buffer` directly confirms what `invalidate()`'s dirty bit (this+0x108's +0x1c, bit 0) is
  *for*: it's the real trigger deciding whether to do a full register-state flush or just reuse the
  current ring-buffer slot - a clean cross-reference to issue #12.1's resolution.
- Four new real methods surfaced as call sites and declared (bodies not independently decompiled):
  `IOATIR500Accelerator::freeToAllocTextureVRAM`, `IOATIR500Surface::alloc_surfaces_keep`,
  `IOATIR500Surface::move_buffer_to_backing_store`, `IOATIR500Surface::copy_buffer_from_backing_store`.

**RESOLVED (final piece of issue #5)**: `load_texture` (~380 lines, dense per-mip/tiling math) is now also
fully transcribed - see `Sources/ATIR500GLContext_TextureLoad.cpp`'s own detailed header comment. Issue #5
is now fully closed - all six originally-declared-but-bodyless internal helpers are reconstructed. Notable
findings:
- Two more real vtable slots surfaced, both on a "memory-descriptor-shaped" object reached through the
  texture's own `memoryDescriptor` field (+0x08): +0x14c (a real second call site for the same slot
  `ATIR500GLContext_DiscardBuffer.cpp`'s opcode 0x3b trace uses - that trace is now itself RESOLVED, issue
  #12 item 3, see below) and +0xd0/+0x18 (get-hardware-tiling-info / release, not previously seen anywhere
  else in this project until this pass's opcode 0x3b resolution independently confirmed the same +0xd0/+0x18
  pair there too).
- Confirmed cross-reference: the per-face dirty/loaded bitmask array this function scans (`mip+0x1c`/
  `mip+0x28`, up to 6 UInt16 entries) is the exact same memory `alloc_and_load_texture`/
  `compact_current_textures` already zero out via their six explicit `mip[0x28..0x32]=0` writes during
  eviction - direct confirmation those six writes really are "clear the per-face loaded-bitmask array."
- Confirmed cross-reference: `load_texture`'s "linear" tiling path sets `accelerator+0xb90=1` - the exact
  same "mid-pageoff" flag `get_texture` checks before calling `restore_state_destroyed_by_pageoff`, and
  `submit_context_buffer` clears at its own start. `load_texture` is the real producer of that flag.
- The function's two tiling paths (dispatched on a real sign-bit test, `hwInfo[8] < 0`) build genuinely
  different per-tile PM4 register bursts - informally "macro-tiled" (3 fields/tile) vs "linear" (5
  fields/tile, plus a per-level `hwShiftA`/`hwShiftB` recurrence) below, not real driver terminology.
- Like `write_kernel_context_buffer_regs`/`restore_state_destroyed_by_pageoff` elsewhere in this project,
  the deepest per-tile arithmetic (particularly the "linear" path's per-level recurrence and the
  "macro-tiled" path's LOD-bias computation, which reads from a real but structurally-UNKNOWN-beyond-this-
  one-use `pAVar22`-shaped object) is transcribed faithfully from the real decompile but dense enough to
  warrant an independent spot-check - or live hardware verification - before fully trusting any single bit
  position. See the function's own header comment for the exact caveat.

~~**Also found, not yet resolved**: opcode 0x29's real execute-path handler...~~ **RESOLVED (issue #12.2)**:
a fresh, targeted re-decompile of `process_command_buffer` (via a real Ghidra headless script, not a
narrative excerpt) shows the real handler initializes its loop counter to a literal `4` and decrements it
exactly 4 times (`iVar55 = 4; do { ...; iVar55 = iVar55 + -1; } while (iVar55 != 0);`) - a genuinely FIXED
4-slot loop, matching `discard_command_buffer`'s independent trace exactly. NOT the dynamic `record[1]`
attachment-count pattern opcode 0x41 uses. Confirmed directly from the real decompile, not inferred.

~~**Also found, not yet resolved**: `discard_command_buffer`'s own handling of opcode 0x3b...~~
**RESOLVED (issue #12 item 3)**: fully transcribed this pass, from a fresh complete decompile of
`discard_command_buffer` (already on hand from the issue #12 item 4 investigation, kext offset 0x27580).
Real structure: releases the old bound query buffer's reference (-1 atomic decrement, same field shape as
`ReleaseBoundTextureSlot` but not routed through that helper), takes a reference on the new one via the
SAME real atomic add-(-0xffff) packed-dual-counter idiom `ATIR500GLContext::get_texture`
(`ATIR500GLContext_TextureLoad.cpp`) independently established on the identical field shape (a mip
record's own +0x10) - confirming that idiom is a general "mark this texture outstanding" mechanism, not
specific to `get_texture` - then the real vtable+0x14c call (on `newTex+0x54`'s own +8 indirection) to
(re)establish a GART/memory-descriptor-shaped mapping handle, a real vtable+0xd0 lookup of a hardware-info
block, and the real four-field zero (`+0x210/+0x218/+0x21c/+0x220`) within THAT block at a
`record[3]*0x20` byte offset (not a fixed object, as this project's earlier partial note implied).

Real, honestly-flagged anomaly found and left unresolved: the raw decompile's final step - releasing the
mapping handle via vtable+0x18 - is UNCONDITIONAL, running even along the control-flow path where the
local holding that handle was never assigned away from a literal null (when `newTex+0x54 == 0`, or when
the vtable+0x14c call itself returns null). A real vtable call through a definitely-null pointer would
crash; transcribed exactly as found rather than silently "fixed," since this project cannot confirm
whether some real invariant elsewhere in the kext guarantees this can't actually happen. Worth a live
hardware/disassembly check if ever exercised with `newTex+0x54 == 0`. Also real: on the initial
shared-allocator lookup failure, this function's real behavior forces the loop's distance to 0, aborting
the ENTIRE discard walk immediately (not just skipping this one opcode) - not previously documented for
this function. See `Sources/ATIR500GLContext_DiscardBuffer.cpp`'s own opcode-0x3b comment for the full
writeup.

~~**A real, unnamed virtual method** at vtable offset `+0x5a4`...~~ **RESOLVED (issue #12.1)**: it's
`ATIR500GLContext::invalidate()` - see section 6 and `Headers/ATIR500GLContext.h`.

**RESOLVED (issue #12 item 4)** - was "UPGRADED to a confirmed dispatch-table bug" in an earlier pass of
this same investigation (that pass found the bug but not the fix - the two paragraphs immediately below
are that earlier state's own writeup, preserved for the record):

> `ATIR500GLContext_ProcessCommandBuffer.cpp`'s dispatch table wires `case 0x31000000` to
> `ATIR500GLContext_handle_fsaa_resolve_blit` (the content of `Sources/ATIR500GLContext_FSAAResolveBlit.cpp`)
> - but this is wrong on two independently-confirmed counts: (1) the real opcode 0x31 is NOT that content -
> a fresh decompile of `process_command_buffer`'s real `if (uVar34 == 0x31000000)` branch shows a short
> (~180-line), purely-integer handler ending with a completely ordinary `goto LAB_00031340;`, nothing like
> `FSAAResolveBlit.cpp`'s ~500 lines; (2) `FSAAResolveBlit.cpp`'s content is also NOT
> `ATIR500Surface::resolve_fsaa_buffer` (opcode 0x30's real callee, the other working hypothesis) - a fresh
> decompile of that real symbol (kext offset 0x43e60) is a completely different, Surface-relative-offset
> function. What `FSAAResolveBlit.cpp` actually contains was, at that point, genuinely unidentified.

**The fix, found this pass**: `FSAAResolveBlit.cpp`'s own header comments cite the specific helper call its
content makes - `FUN_000314c4(puVar65, &_g_r500_3d_blit_state_packet, 0x2f4)`. Grepping a fresh, complete
`process_command_buffer` decompile for that exact call surfaced its real location: the `else` branch of a
real `if (uVar34 != 0x2d000000) { ...0x2b/0x2c/0x2f/0x30 handling...; goto LAB_00031340; }` exclusion check
further down the function. **`FSAAResolveBlit.cpp`'s content is opcode 0x2d's real handler**, not 0x31's -
confirmed unambiguous by grepping the whole ~3300-line decompile for `0x2d000000`, which appears exactly
once (this one branch). This also retroactively corrects section 2's earlier catalog entry, which had
listed `0x2d` as "reserved/dead, same shape as 0x17/0x1a/0x1d/0x20/0x23" - it isn't; that earlier check
(`0x2d`'s own exclusion-check search) missed that the real branch is an inverted `!=` condition's `else`,
not a `case`/`==` match, which is why the earlier sweep didn't find it.

With `FSAAResolveBlit.cpp`'s true identity settled, **the real opcode 0x31 was transcribed fresh** from the
actual `if (uVar34 == 0x31000000)` branch, exactly matching the ~180-line purely-integer shape the earlier
pass had already characterized: a real attachment-index remap (`{7,10}->7`, `{8,11}->8`, else `6`, gated by
a `self+0x8c & 0x80` capability bit), a real surface/scratch-buffer pair selection depending on
`self+0x3bc` (normal vs. alternate mode, the same two-mode pattern used throughout this class), one or two
calls to the already-declared `ATIR500Surface::decompress_and_flush_depth_buffer`, then a real per-mip/tile
register-burst write for both surface records (reusing `FormatTableLookup_0x0004d2e0`/`_0x0004d2dc`/`_0x0004d2e4`,
including the SAME 5-step cascading-mask idiom already found in opcode 0x3f - now confirmed to appear at
three real sites, not two), and a real per-tile texture-offset patch loop with the same self-referential
read-before-write pattern (`slot[1]` read as an operand in the same statement that overwrites it) already
flagged in `FSAAResolveBlit.cpp`. Ends in a completely ordinary fall-through - confirms the earlier pass's
finding that the REAL opcode 0x31 has no special tail handling, unlike opcode 0x2d (see below).

**Both fixed in the source tree**: `ATIR500GLContext_ProcessCommandBuffer.cpp` now has
`case 0x2d000000: next = ATIR500GLContext_handle_fsaa_resolve_blit(this, record); break;` (removed from the
reserved-noop group) and `case 0x31000000: next = handle_depth_buffer_resolve(this, record); break;` (the
new, real handler, defined in that same file). `FSAAResolveBlit.cpp`'s header comment is updated to the
correct opcode 0x2d identity; its content, transcription, and open tail-integration question (below) are
otherwise unchanged - they were already correct, just filed under the wrong opcode number.

**One open item survives the re-attribution, now correctly pointed at 0x2d instead of 0x31**: opcode 0x2d's
handler returns `local_d0`, an explicitly-computed pointer distinct from `record` (its real tile loop
consumes a data-dependent dword count the header's encoded distance field can't represent generically).
The dispatch loop's `if (next != record)` branch advances straight to `local_d0` but does NOT run the
tail's real exit-descriptor-write/status-return check in that case, whereas the real decompile shows this
opcode's ending DOES fall into that same shared check. Whether that matters in practice depends on whether
`local_d0` can ever coincide with a real "buffer now fully consumed" position - NOT independently confirmed
either way; a genuine, still-open question, now correctly scoped to opcode 0x2d only (the real opcode 0x31
was independently confirmed this pass to have no such exception).

`ATIR500Surface::resolve_fsaa_buffer` remains genuinely UNKNOWN/opaque (its header comment already
correctly says so, and nothing this pass found bears on it).

## 5. `IOATIR500Accelerator`'s four context-factory vtable slots - NAMES RESOLVED, raw values still open

**Names/purpose effectively RESOLVED**, and by a completely different, more reliable method than decoding
the vtable itself: `newUserClient`'s four real vtable slots (`+0x5d4/0x5d8/0x5dc/0x5e0`) map to
`createSurfaceContext`/`create2DContext`/`createDVDContext`/`createGLContext` respectively - type 0
(Surface) and type 1 (GL) are CONFIRMED via real `IOServiceOpen(...)` call sites in this project's own
downloaded userspace binaries (`_gldAttachDrawable`, `_gldCreateContext`); type 2 (2D) and type 3 (DVD)
are INFERRED by elimination. See `Headers/IOATIR500Accelerator.h`'s updated declarations.

**The four words' raw numeric CONTENTS remain unresolved** - a real, exhaustively-investigated dead end
this pass, not the `PPC_RELOC_LOCAL_SECTDIFF` (type 15) tooling gap originally logged. A Ghidra headless
script parsing the raw Mach-O structures directly (not just the higher-level analyzed Program - see
`Headers/IOATIR500Accelerator.h`'s full writeup) found the real relocation entries are type 0
(`GENERIC_RELOC_VANILLA`), non-scattered, non-external - ruling out SECTDIFF entirely. Also ruled out:
plain absolute address (the raw values point into unrelated data - a video-mode table, and this class's
own destructor), section ordinal (binary has only 10 sections total, values are in the hundreds of
thousands), symbol-table index (values mostly out of bounds for the 1215-entry symbol table), a parsing
bug (manual raw-byte reads agree byte-for-byte with Ghidra's own parse), and a separate `LC_DYSYMTAB`
local-relocation table (confirmed absent from this file). Leading hypothesis, unconfirmed: these slots
were never locally overridden in this compiled object and only ever got their real addresses via Apple's
kext-load-time "vtable patching" (`kxld`) against the live kernel - if true, the real numeric values may
not exist anywhere in this static file at all, and only a live kxld-relocated memory read on real
hardware could recover them. Lower priority now than when this issue was filed, since the actually
load-bearing information (the real names above) is already solid, and a numeric value can't be verified
without a real compile+link anyway (see gap 1).

## 6. The base classes' own construction/initialization - RESOLVED (issue #10)

~~`ATIRadeonX1000` (the hardware class) and the four `IO`-prefixed base user-client classes' own field
layouts were all learned *indirectly*... field ordering relative to each other... is uncertain...~~

The actual constructors (`ATIRadeonX1000::ATIRadeonX1000`, and the four `IO*Context`/`IOATIR500Surface`
constructors) turn out to be thin trampolines that only call an imported base-class constructor and set
the vtable pointer - none of them touch this project's own fields at all. Real per-instance state is set
in each class's `start()`, matching the standard IOKit pattern. Decompiling
`ATIRadeonX1000::start` directly (kext offset 0x1f750) found real, repeated, self-consistent accesses to
all three previously-uncertain fields from ATIRadeonX1000's *own* methods (not just via other classes'
pointers, which is strictly stronger evidence): `deviceActiveFlag` (+0x80) as a real byte flag in 6
independent functions, `commandLock` (+0x840) as a real lock-pointer word in 6 independent functions, and
`mmioBase` (+0x860) set once in `start()` and mirrored to three other fields. All three are self-consistent
in access width and semantics everywhere they appear - the "unordered" struct hack in `ATIRadeonX1000.h`
has been replaced with a normal, correctly-ordered layout.

Separately, **`regularMethodTable`'s populator is now found**: `IOATIR500GLContext::start` (kext offset
0x7690) - a previously entirely unlocated function, distinct from `ATIR500GLContext::start` (0x28540, the
*subclass's* start, which only sets the special selector-20 slot). Fully transcribed into
`Sources/IOATIR500GLContext_Start.cpp`. Bonus finds from that same decompile: `clientHandle`'s concrete
real type is `IOATIR500Shared*` (a real, allocated-here class this project has still not reconstructed -
see the new minimal `Headers/IOATIR500Shared.h`), and `IOATIR500Accelerator::liveGLContextListHead`
(`+0x60`) is now CONFIRMED (was INFERRED) via this function's real list-insertion write, which also
surfaced a brand new field: `IOATIR500GLContext::nextLiveContext` (`+0x80`), the intrusive "next" link for
the accelerator's live-GL-context list.

## 7. The 2D and DVD contexts' own embedded command-buffer languages - 2D RESOLVED, DVD MOSTLY RESOLVED (dispatcher assembled, 1 opcode remains)

`ATIR5002DContext`/`ATIR500DVDContext` both have a real, confirmed, extensive `process_command_buffer` of
their own (same underlying mechanism as GL's - top-byte opcode dispatch over a `this+0xa4+0x1c`-based
record stream, self-consuming low-24-bit distance fields, same `0x80000000`-sentinel exit-descriptor
write at buffer end - just different opcode numbers/semantics). Real address: DVD 0x357c0
(`ATIR500DVDContext::process_command_buffer`), 2D 0x326d0. DVD alone is ~0x39a0 bytes of real machine
code - about 61% of GL's own `process_command_buffer` (~0x5db0 bytes), which took this project many
dedicated commits across a full session to fully transcribe. **This is genuinely comparable in scope to
that whole effort, not a small remaining item** - full completion needs its own dedicated multi-session
pass, same as GL's did.

**This pass established the real skeleton** (the essential first step, matching how GL's own
`stage3-embedded-opcode-language.md` began before opcode-by-opcode work started) and characterized several
real opcode families in detail, without yet transcribing them into compilable C++:

- **Confirmed real opcode range**: 0x02, 0x04-0x0d, 0x12-0x25, 0x26-0x39, 0x3a-0x3f, 0x42-0x44, 0x46-0x47
  (~55 distinct top-byte values dispatched on) - extracted directly from the real decompile's full
  if/else-chain, not sampled.
- **Opcodes 0x1e-0x25, 0x26-0x2a (via one shared handler)**: a real "bind texture unit N" family, N
  derived directly from the opcode value itself (`(opcode - 0x1e) * 4`-ish indexing into a per-unit
  texture-slot array at `this+0x104`) - the SAME real add_texture_to_stream / GART-map / transfer-buffer-
  list-splice pattern this project already fully reconstructed for GL's `alloc_and_load_texture`/
  `get_texture` this pass (issue #5) - directly reusable understanding.
- **Opcodes 0x26-0x39-ish (a second shared handler)**: the mirror-image real "unbind texture unit N"
  family - calls `remove_texture_from_stream` and a real `IOATIR500Shared::delete_texture` (a real,
  previously-undiscovered method on that still-unreconstructed class - see issue #10's
  `Headers/IOATIR500Shared.h`).
- **Opcodes 0x5/0x6 and 0xa/0xb/0xc/0xd**: real, dense per-mip YUV surface setup handlers - CONFIRMED
  direct evidence of the real YUV 4:2:0 combined luma+chroma plane-size formula
  (`height * pitch * 3 >> 1`, appearing at multiple real call sites) and real PM4 register writes forming
  what looks like a texture-sampler-state record (`0x1393`/`0x5c8`/`0xd0b` family), using the SAME real
  format-lookup tables (`DAT_0004d2e0`/`DAT_0004d2dc`) GL's own `build_scissor`/
  `write_kernel_context_buffer_regs` already reference - directly relevant to this project's H.264 goal,
  and the highest-value remaining target.
- Several trivial shared exit paths (malformed-opcode-abort, plain distance-only skip, sentinel-write)
  identified and are cheap to transcribe once opcode-by-opcode work resumes.

~~2D's `process_command_buffer` (0x326d0) is much smaller... and was not examined this pass~~ **RESOLVED**:
2D's own opcode language is now **fully transcribed** from a complete real decompile - see
`Sources/ATIR5002DContext_ProcessCommandBuffer.cpp`. Unlike GL/DVD, it's small enough (~0xe40 bytes, ~15%
of GL's size) that the real binary keeps every opcode inline in one function rather than splitting into
separate handlers, which made a full pass tractable in one sitting. Real confirmed opcode range: 0x2-0xe,
0x10-0x13 (14 distinct top-byte values). Real findings:
- Four real texture-bind opcode families (0x3/0x4, 0x7/0x8, 0x10, 0x13), each reusing the exact same
  `sharedAllocator`-indexed lookup and the SAME two accelerator-level lists (`+0x600`/`+0x5dc` and
  `+0x6d0`/`+0x69c`) this project already reconstructed for GL (issue #5) - directly transferable
  understanding paid off here.
- `this+200` (0xc8) carries the exact same "pending write batch" dirty-bit idiom as GL's own
  `invalidate()`/`submit_context_buffer` (`this+0x108` there) - same real pattern, different per-class
  field offset, now confirmed on a THIRD context class after DVD's own equivalent.
- `sharedAllocator` (`this+0x88`, already declared on `IOATIR5002DContext`) is a real `IOATIR500Shared*`
  owning a real texture-lookup-by-index table at its own `+0x10`/`+0x14` - independently confirming the
  same layout DVD's `this+0x84` and GL's own texture lists already established.
- Three real opcode pairs (0x9/0xa, 0xb/0xc, 0xd/0xe) share exactly two real output shapes (a short
  `0x1150`-family write and a longer sentinel-plus-sampler-state write), differing only in how the source
  mip record is looked up (fixed per-index array, `find_surface_for_id` + `alloc_surfaces_keep`, or the
  bound-surface-or-fallback-index pattern also used by opcodes 0x11/0x12).
- One correctness bug caught and fixed during transcription (not present in the shipped driver, an error
  in this project's own first-draft C++): an unrecognized opcode value is a plain pass-through in the real
  binary (just consumes the record's own natural distance), NOT the harsh "reset the whole accumulated
  count to zero" abort that real bounds-check failures trigger - the two real exit paths look superficially
  similar but are meaningfully different, confirmed by checking every real `goto` site in the raw decompile
  individually rather than assuming.

**DVD - real further progress this pass**: eight real opcode groups are now fully transcribed from complete
real decompiles - see `Sources/ATIR500DVDContext_ProcessCommandBuffer.cpp`. Together they cover 41 real
opcodes with genuine handlers, plus four more confirmed to need none at all:
- **Bind** (0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e-0x25, 0x26-0x2a, 0x2d - 19 opcodes): real "bind texture unit N"
  logic, N derived directly from the opcode value. Reuses the exact same `sharedAllocator`-indexed lookup
  and the same two accelerator-level lists (`+0x600`/`+0x5dc`, `+0x6d0`/`+0x69c`) already reconstructed for
  GL and 2D this session (issue #5) - the skeleton pass's prediction that this understanding would
  transfer held up a second time.
- **Unbind** (0x2b, 0x2c, 0x2e-0x30, 0x32-0x34, 0x36-0x3c - 15 opcodes): the mirror-image cleanup-only
  path, real refcount-gated `IOATIR500Shared::delete_texture` (a real, newly-declared method - see
  `Headers/IOATIR500Shared.h`).
- **Opcode 0x02**: sets the function's own overall return value to 3 - a real, deliberate difference from
  GL's and 2D's own opcode 0x2, which both set 1 instead.
- **Opcode 0x04**: a real explicit-flush opcode - same real shape as GL's own opcode 0x2b - flushes any
  pending write batch and writes a plain sentinel, no other real payload.
- **Opcodes 0x5/0x6**: a real texture-sampler-state PM4 record pair, sharing an identical header/tail
  template with opcode 0xd's own setup (also now resolved - see below) - real confirmation that template
  is a general "sampler state" shape reused across multiple real source kinds. Real per-mip lookup through
  `boundSurface`, and a second independent sighting of the real YUV 4:2:0 combined-plane formula
  (`height*pitch*3 >> 1`) this project's earlier DVD skeleton pass first found in opcode 0xd.
- **Opcode 0xd**: a third real sighting of the same sampler-state header/tail template, real per-source
  branch (transfer buffer from the same per-unit slot array bind/unbind use, or a fixed record embedded in
  `boundSurface` itself).
- **Opcode 0xa** (the densest opcode in this cluster, and the highest-value target for the H.264 goal):
  real per-mip Y/UV plane pitch+offset setup, gated on a real "engine ready" flag and vtable call. A THIRD
  independent sighting of the YUV 4:2:0 combined-plane formula - this time applied to the Y-plane base
  itself, not just a chroma offset - plus a real UV-plane offset built from the luma-plane size. Finishes
  with the same real format-table-driven tiling word (`FormatTableLookup_0x0004d2e0`/`_0x0004d2dc`) GL's
  own `build_scissor`/`write_kernel_context_buffer_regs` already use.
- **Opcode 0xb**: a single-plane cousin of 0xa (no Y/UV split), same real per-source branch shape as
  opcode 0xd and the same format-table tiling-word computation.
- **Opcode 0xc confirmed to have NO real handler** - re-reading the raw decompile's brace structure
  precisely (not just its surface `goto` targets) shows it falls straight through to the same trivial-abort
  path as opcodes 0x07/0x08/0x09, all four wrongly assumed part of "real work remaining" by earlier passes.
- Real, previously-undocumented fields found and declared: `sharedAllocator` (+0x84, `IOATIR500Shared*` -
  same real +0x10/+0x14 table layout as 2D's own, now confirmed on a second class independently),
  `commandBufferBase` (+0xa4), `ringSlotZeroCheck` (+0x94), `pendingTransferBuffer` (+0x90),
  `lastSubmitResult` (+0xa0) - all mirroring roles this project already named on GL/2D's own equivalents.
- Three real bugs caught during transcription (own first-draft errors, not present in the shipped driver):
  the bind handler's flush path must use the record count *saved before* it's reset to zero, not the live
  (by-then-zeroed) counter; two 16-bit field reads in the sampler-state handler were initially coded via a
  32-bit read plus a `& 0xffff` mask, which reads the WRONG two bytes on a big-endian target Ghidra had
  already flagged as a real `ushort`; and opcode 0xc was initially assumed to share a body with 0xa/0xb/0xd
  before a careful brace-by-brace re-read showed it doesn't.
- **Honestly-flagged real anomaly, not resolved**: opcodes 0xa and 0xb's own real decompiled bodies both
  read a local variable (`local_64`/`local_58`) as part of a tiling-word bitmask (`... & 0xfe00c001`)
  before ever assigning it within the function - a genuine uninitialized-stack-local read in the real
  compiled driver, or a Ghidra stack-slot-reuse artifact this project cannot distinguish from static
  analysis alone. Modeled as 0 in both transcriptions rather than silently guessing a "real" value.

**Correction to this project's own earlier opcode-range accounting**: DVD has NO real opcode 0x11 at all -
an earlier pass's "remaining opcodes" list wrongly included it, apparently carried over by mistake from the
UNRELATED opcode 0x11 this project already resolved on the 2D context (a real, different opcode language -
see section 7's own 2D writeup). Mechanically re-confirmed by grepping the complete raw decompile for every
real `uVar17 ==/!= 0x??000000` comparison: 0x12 is the smallest value actually dispatched on in that
neighborhood.

**Real, high-value finding this pass**: opcode 0x12's own real body spans roughly 750+ lines of raw
decompile (loop-based, multiple fixed-size local arrays, dense per-plane geometry math) - comparable in
scale to GL's own opcode 0x2d, which this project's history (section 2 above) explicitly flagged as "the
single largest remaining gap" in the entire GL reconstruction (**CORRECTED, issue #12 item 4**: was
"0x31" at the time this note was written; see the opcode 0x31/0x2d resolution in section 2 above - the real GL opcode 0x31
is much smaller and is now fully transcribed). NOT attempted this pass; needs its own dedicated pass, not
a continuation of this session's per-opcode cadence.

Still open: ~18 real opcodes (0x12 [very large, see above], 0x14-0x18, 0x31, 0x35, 0x3d-0x3f, 0x42-0x44,
0x46-0x47) - the rest are dense per-mip YUV/tiling math comparable in density to GL's own richest opcodes
(real floating-point double arithmetic, multiple format-table lookups per opcode), not yet examined in
detail. `process_command_buffer` itself is not yet assembled as one function - the transcribed handlers are
free functions awaiting a completed dispatcher.

**Methodology note for continuing this**: this pass's manual reading of the raw decompile's brace
structure produced two real opcode-boundary mistakes this session that needed correcting after the fact
(opcode 0x1d wrongly modeled as separate from the bind family in an earlier commit; opcode 0x11 wrongly
carried into the "remaining" list, as above). A future pass should cross-check routing against the real
compiled branch instructions (raw disassembly) before trusting an opcode boundary inferred from decompiled
C brace nesting alone, especially for the deepest-nested parts of this function.

**MAJOR PROGRESS, later pass: `process_command_buffer` is now ASSEMBLED AND WIRED as a real dispatcher**
(`ATIR500DVDContext::process_command_buffer`, declared in the header and implemented in
`Sources/ATIR500DVDContext_ProcessCommandBuffer.cpp`) - previously the transcribed handlers existed only
as free functions with nothing calling them. Eight more real opcodes/groups transcribed this pass: 0x13
(a texture-fetch setup previously not even catalogued as a gap - an earlier pass's opcode inventory had
skipped it entirely), and 0x3e/0x3f/0x42/0x43+0x44 (one real shared handler, see below)/0x46/0x47 - all
in the smaller-opcode end of the previously-"remaining ~18" list. The methodology note above was acted on
directly this pass: every opcode boundary (transcribed or still-open) was verified via direct PPC
branch-instruction tracing of a fresh disassembly dump, not decompiled-C brace nesting - which caught a
THIRD ambiguous region (around opcodes 0x14/0x15) before it could become a third mistake, and gave every
still-open opcode a real, disassembly-confirmed target address (recorded directly in the dispatcher's own
source, so a future pass never has to re-derive the mapping - see below).

**Three real corrections to this project's own opcode accounting**, all found via that same disassembly
tracing:
1. Opcode 0x2d is really part of the UNBIND family (`LAB_00037880`), not BIND (`LAB_00037620`) as an
   earlier pass's prose had listed - caught before ever being wired into committed code (no dispatcher
   existed yet), not fixed after the fact.
2. Opcode 0x35 is ALSO a real unbind opcode - previously not catalogued in either list at all.
3. Opcode 0x31 was already correctly known to be a real unbind opcode (present in an earlier pass's
   "remaining opcodes" list) but had never actually been wired to `handle_texture_unbind` in any
   dispatcher - fixed by simply including it; no new decompile work needed.

**Two real logic bugs caught and fixed in the ALREADY-COMMITTED handlers**, found while working out the
dispatcher's own shared state:
1. `handle_texture_bind`'s real bounds/null-lookup failure target is the HARD-ABORT path
   (`LAB_00039030` - the whole walk's running position resets to 0), not a plain single-opcode skip as
   originally modeled (a bare `return;`, silently equivalent to "use the natural distance"). Fixed by
   changing its return type to `bool`, matching `handle_opcode_0a`/`0b`'s own established convention.
2. `local_64`/`local_58` (read by opcodes 0xa/0xb respectively, and now also `local_60`/`local_5c` for
   opcode 0x46) are real FUNCTION-SCOPE `process_command_buffer` variables - zero-initialized ONCE before
   the dispatch loop starts, NOT fresh per-call locals. Each one's own self-referential update
   (`local_X = (new bits) | (local_X & mask)`) means it genuinely persists, masked, across every real call
   to its opcode within one `process_command_buffer` invocation - a command buffer containing the same
   opcode more than once would have later occurrences see bits left behind by earlier ones. An earlier
   pass modeled each as a fresh `UInt32 local_X = 0;` local to its own handler function every call, losing
   this real persistence - now threaded through as real shared dispatcher state (by-reference parameters)
   instead.

**Real, notable structural finding**: opcodes 0x43 and 0x44 are, per a direct byte-for-byte disassembly
comparison, REAL, IDENTICAL setup code (0x44 reaches the exact same real merge point 0x43's own natural
fall-through does, via an explicit `goto` in the raw decompile) - a genuine driver/compiler artifact, not
a transcription shortcut. Transcribed as one shared handler, `handle_opcode_43_44`.

**LATER CONTINUATION, same pass**: four more real opcodes transcribed and wired - 0x14 (a dense 6-way-branch,
3-output multi-plane YUV/tiling burst), 0x16 (the densest opcode transcribed this pass: a 12-way branch
producing FIVE real output values from two independent per-mip records), 0x18 (a real two-transfer-buffer
fetch setup, each independently GART-mapped/spliced), and 0x15 (structurally unique in this whole cluster -
the only opcode that does NOT index a per-`record[N]` mip array; it reads a real FIXED sub-record embedded
in `boundSurface` at `+0x7b0`, transcribed via direct PPC instruction decoding since no matching
decompiled-C region for it could be found in the raw decompile output this project has on hand - a real
gap in Ghidra's own C rendering for that address range). One more real logic bug caught and fixed in THIS
PASS'S OWN draft before committing (not a stale earlier bug): an early draft of the opcode 0x16 handler
used `rowSize` instead of the real `blendedBase` in two of its twelve branches' `outE` formula - caught by
re-checking every branch individually against the raw decompile.

**STILL LATER CONTINUATION, same pass**: opcode 0x3d transcribed and wired - the densest opcode this whole
pass produced. A real self-consuming record (its own leading 7 dwords zeroed before any output is written)
producing TWO separate 5-plane `0x1150`-`0x1154` PM4 bursts across a real 4-way branch with 9 tracked
output values, plus a real THIRD source beyond the usual two per-mip records: `boundSurface`'s own fixed
`+0x7b0` sub-record (the SAME real "plane descriptor" opcode 0x15 already established, confirmed reused by
a second opcode at the same real `+0x7b8`/`+0x7c8` fields, plus two more fields of its own,
`+0x7e8`/`+0x7e9`). One more real logic bug caught and fixed in THIS PASS'S OWN draft before committing: an
early draft computed the first burst's destination pointer as `record + record[5]` using ordinary C++
pointer arithmetic directly on `record[5]`'s value - but real, direct disassembly verification (the exact
`lwz`/`rlwinm`/`add` instruction sequence) showed the real machine code reads `record[5]` AFTER it has
already been self-consumed to `0x80000000`, then scales it by 4 for pointer arithmetic, which overflows
real 32-bit address arithmetic exactly back to 0 - meaning the real destination is always just `record`
itself. Rewritten to assign `record` directly (mathematically identical to the real behavior) rather than
relying on the same overflow in C++, which is undefined behavior rather than the modular arithmetic real
machine code performs. (Real evidence, incidentally, that `record[6]`/`burst2Off` for the SECOND burst is
NOT subject to the same issue - it's captured into a real stack local, `local_74`, BEFORE the self-consume
runs, confirmed via the same disassembly pass.)

**STILL LATER CONTINUATION (a fresh session resuming this same pass)**: opcode 0x17 transcribed and wired -
the last real gap this section used to list alongside 0x12. An earlier continuation had attempted this
exact opcode and deliberately stopped mid-branch: like 0x15, it has no matching region anywhere in
Ghidra's own C decompile of the enclosing giant function (confirmed by grepping for its own distinctive
offset constant, same negative result 0x15 got), and partway through hand-decoding one branch from raw
disassembly a register appeared to hold an unexplained value with no traceable origin - correctly judged
too risky to guess at, so that attempt was abandoned and documented rather than committed. Resuming from
this opcode's real function entry (`0x372b4`) rather than mid-function (where the earlier attempt had
started reading) resolved it cleanly: the "unexplained" register was simply `rowSize`
(`heightDelta * pitch`), computed once in real shared setup, in the exact same role as `handle_opcode_14`'s
own `rowSize` local - the ambiguity was an artifact of where the reading had started, not a real gap in
the trace. Real structure: a 3-output analog of `handle_opcode_14`'s own 6-way branch (same
`record[5] != 1` / `record[1]` mode / `record[4]` altFlag split, same `rowSize`/`blendedBase` YUV 4:2:0
formula, same shared `LAB_00038870` tail), verified instruction-by-instruction against `handle_opcode_14`'s
own already-committed tail-construction code and found to match exactly (same mask constants throughout).
One genuinely interesting, directly-confirmed real asymmetry (not smoothed over): for the "mode is neither
2 nor 3" case, the real `altFlag == 0`/`altFlag != 0` formulas are swapped between the `record[5] != 1` and
`record[5] == 1` outer branches - independently derived from four separate, non-adjacent instruction
addresses, so transcribed as observed rather than "corrected" toward the more intuitive symmetric mapping.
Also tried, and abandoned as unhelpful, a Ghidra experiment to decompile just 0x17's address range as an
isolated function (via `createFunction` in a read-only headless pass) - PPC flow-following just pulled in
the entire shared-tail network again, producing an even larger, no cleaner result than the existing giant
decompile; direct disassembly tracing remained the only real path for this opcode.

**Still open, real disassembly-verified address on record** (in the dispatcher's own explicit
not-yet-transcribed `case`, so a future pass can go straight to decompiling without re-deriving the
mapping) - down to ONE opcode from the original seven: opcode 0x12 (`0x35c04`, ~750 real lines - the
single largest remaining gap in this function, comparable in scale to GL's own opcode 0x2d). This
dispatcher explicitly falls through to the natural-distance default for it, with a loud comment - a KNOWN
GAP, not a confirmed real no-op; do not trust it for this opcode value on real hardware. Genuinely still a
nontrivial remaining item, though the cluster is now down to just this one from the original ~18.

## 8. `IOATIR500Surface`'s remaining lock/shape methods - FULLY RESOLVED

Of the 19 real selectors, only the video-relevant overlay family (5 methods) and a handful of others
sampled for confirmation (`surface_control`, `surface_flush`, `get_state`, `set_shape`, `surface_read`,
`surface_query_lock`, one lock/unlock pair) had any real decompiled content behind them. Of the remaining
~9, an earlier pass resolved 6: `surface_read_lock_options`, `surface_write_lock_options`,
`surface_write_unlock_options`, `surface_write_lock`, `surface_write_unlock`, `set_scale` - all fully
transcribed from complete real decompiles - see `Sources/IOATIR500Surface_LockShape.cpp`. Real signature
corrections found along the way: several of these had the wrong parameter count or return type
(`IOReturn` vs real `void`); `set_scale` in particular had a completely wrong shape - this project had
guessed raw `UInt32 xScale, UInt32 yScale` where the real 2nd parameter is a real `IOAccelSurfaceScaling*`
struct pointer. Also formally declared the two shared internal helpers these all forward into
(`surface_lock_options`/`surface_unlock_options`, previously only referenced in comments) and two more
real, previously-undeclared internal helpers found as their own real functions:
`surface_write_lock_int`/`surface_write_unlock_int`.

**RESOLVED, this pass: the final 3 (`set_id_mode`, `set_shape_backing`, `set_shape_backing_length`), plus
the shared `set_shape_backing_length_ext` (~236 lines) they tail-call - issue #8 is now fully closed, every
one of Surface's 19 real external methods has real decompiled content behind it.** See
`Sources/IOATIR500Surface_LockShape.cpp` for all four (each with its own detailed header comment).

Real, notable findings:
- `set_id_mode`'s real parameter count (2, not 3) had to be independently confirmed via direct disassembly
  of its own prologue - Ghidra's own no-analysis decompile mislabeled its second parameter "param_3" for
  unrelated internal reasons, which would have led this project to declare a phantom 3rd parameter had it
  been trusted blindly.
- `set_shape_backing`/`set_shape_backing_length`'s real argument setup couldn't be recovered from a
  no-analysis decompile at all (Ghidra rendered both as bare, argument-less tail calls) - both were
  instead transcribed directly from the raw PPC disassembly's own register moves, cross-checked against
  the real PPC32 SysV/Darwin calling convention. `set_shape_backing_length` turned out to have a real,
  previously-undocumented validation gate of its own (a real size-vs-region check, rejecting BEFORE ever
  reaching `set_shape_backing_length_ext`) - not just a bare forward as this project's earlier note
  assumed.
- `set_id_mode` and `set_shape_backing_length_ext` share several real fields (`+0xbe8`/`+0xc14`/`+0xc1c`/
  `+0xbf8`, the accelerator's own `id*8+0xd60/+0xd64`/`id*0x94+0xcac`/`id*0x78+...` per-ID arrays, and the
  same real accelerator vtable+0x540/+0x544 allocate/commit pair) - genuinely the same "surface ID slot"
  concept in both functions, confirmed by direct cross-reference, not assumed from similar-looking code.
- **Two real transcription bugs caught and fixed during this project's own re-review**, before ever
  committing: (1) a swapped parameter pair in `set_shape_backing_length_ext` - Ghidra's own no-analysis
  parameter numbering (`param_2`..`param_8`, skipping `param_1` for the implicit `this`) had to be mapped
  onto the real 7-parameter mangled signature by hand, and an early draft of this mapping mixed up which
  local corresponded to which real parameter in two spots (a boolean flag testing the wrong parameter, and
  a region-normalization block writing zero into the wrong pair of parameters) - caught by re-deriving the
  mapping from the mangled name and cross-checking every use site individually, not by any tooling. (2) A
  dword-index-vs-byte-offset scaling bug on a completion-stamp accumulator (`accelerator+0x1f0` written
  instead of the real `accelerator+0x1f0*4 = accelerator+0x7c0`) - the SAME class of mistake already found
  and fixed once in issue #12 item 6, caught this time before it was ever committed by specifically
  checking every `int*`-typed local's indexing for this exact pattern.
- A fourth, previously-unknown completion-stamp accumulator field found: `accelerator+0x7c0`, alongside
  the already-known `+0x704`/`+0x780`/`+0x7bc` - all via the same real accelerator vtable+0x54c/+0x558
  family of calls, each accumulating into its own distinct field per caller.
- Honest, unreconstructed gap acknowledged rather than guessed around: this project has not reconstructed
  Apple's own real `IOAccelDeviceRegion` struct layout (a real, forward-declared-only Apple type - see
  `Headers/IOATIR500Surface.h`'s own top note). `set_shape_backing_length_ext`'s dense per-rect copy loop
  and its region-relative field reads are transcribed via raw byte offsets rather than a guessed struct
  layout; one specific field (`region+8`) is read as BOTH a 16-bit and a 32-bit value at different points,
  consistent with a real packed 32-bit field rather than a transcription error - see that function's own
  header comment for the full argument.

## 9. This reconstruction covers the kext only, not the userspace binaries

By design - see `README.md`. `ATIRadeonX1000GLDriver.bundle`, `ATIRadeonX1000GA.plugin`,
`ATIRadeonX1000VADriver.bundle`, `libGLProgrammability.dylib`, `AGL.framework`, `OpenGL.framework`, and
`libGL.dylib` are all real, separately-decompiled binaries this project's `g5-h264-gpu-decode` repo has
extensive notes on, but none of them are userspace kernel extensions and reconstructing them as
"compilable source" would mean a different kind of project (a from-scratch OpenGL/AGL/CFPlugIn
implementation) - out of scope here.

## 10. ~~`Info.plist`'s PCI device-ID match string is an unverified placeholder~~ RESOLVED

Closed without hardware: this project already had read-only access to the real, shipped kext's own
`Info.plist` (pulled from the Tiger HD earlier in the `g5-h264-gpu-decode` project) - it just hadn't been
opened yet. Reading it resolved this AND corrected two bigger things:

- The real `IOClass` is `ATIRadeonX1000` itself (the concrete subclass), not `IOATIR500Accelerator` (its
  base class) - this project's class hierarchy had the relationship backwards, now fixed in
  `Headers/ATIRadeonX1000.h`/`Headers/IOATIR500Accelerator.h` and every context class's `accelerator`
  field type.
- The real dependencies are `IOGraphicsFamily`/`IONDRVSupport`/`IOPCIFamily`, not `IOAcceleratorFamily`
  as originally guessed by name-analogy.
- Real bonus finds: two previously-unknown driver config flags (`ATIEnableWideBlitSupport`/
  `ATIUseTearingWideBlit`, plausibly relevant to the already-analyzed blit opcodes - nobody has traced
  which function reads them) and real GPU sensor-properties (thermal monitoring, low priority for this
  project's goals but a genuine new fact).
