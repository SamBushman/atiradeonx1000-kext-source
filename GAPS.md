# Known gaps and next steps

A consolidated list of every real `TODO`/`UNKNOWN` this reconstruction pass left behind, grouped by
theme. Mirrored into GitHub issues on this repo for tracking. See `README.md` for the confidence-tier
definitions this list uses.

## 1. Compilation has never been attempted

The single largest gap: nothing in this repo has been built. There is no Tiger/Leopard IOKit SDK or
PowerPC kext toolchain available in the environment this was written in. **Requires real hardware/
toolchain access to close.** See `README.md`'s "What to do when hardware is available again" section for
the concrete first steps.

## 2. `process_command_buffer`'s opcode handlers (GL context) - FULLY RESOLVED (issue #13's two residual items closed)

**Status: COMPLETE.** Every real opcode this driver's embedded marker language actually dispatches is now
transcribed. This was verified mechanically, not just by inspection: grepping the complete raw decompile
for every `uVar38 <op> 0x??000000` comparison actually present in the function's ~3315 lines produces the
exact same opcode set this project's dispatch `switch` now handles (either via an explicit `case` or via
one of the two confirmed opcode-range checks, `0x06-0x15` and `0x16-0x25`) - nothing left over on either
side. Along the way, this pass found this project's ORIGINAL opcode inventory (built earlier from staged
narrative documents, not a full mechanical sweep) had actually missed FOUR real opcodes entirely -
`0x2d` (**CORRECTED, issue #12 item 4**: originally cataloged here as reserved/dead, same shape as the
`0x17/0x1a/0x1d/0x20/0x23` gaps - it isn't; it's a real, large FSAA-resolve-blit handler, see the opcode
0x31/0x2d resolution below in this section for the full writeup; those other five turned out to share this
exact same real mistake too - see the later continuation paragraph below, they are not reserved/dead
either), `0x33` (a real inline color+Z-buffer register burst), `0x34` (a real
query/fence-slot allocator), and `0x35` (another render-target generation-stamp opcode) - plus a fifth,
`0x32`, that WAS known by number but whose real body had never been located (a large depth-flush +
per-tile texture-fetch-register-patch function, the closest thing in this language to opcode 0x2d's own
tile loop - also CORRECTED from an earlier "0x31" mislabel, see the opcode 0x31/0x2d resolution below in this section). All five are now fully
transcribed.

**LATER CONTINUATION (issue #13 follow-up audit, prompted by "are there lower-confidence parts of the
decompilation this project can now revise given other work?")**: a real fourth misattribution found and
fixed, the exact same class of mistake as the opcode 0x31/0x2d one below - a decompile-text search for a
literal `== 0x1X000000` match, rather than a disassembly-verified branch trace. Opcodes `0x17`/`0x1a`/
`0x1d`/`0x20`/`0x23` were believed real, dead, reserved no-ops (`handle_reserved_noop`) because no exact
textual match for their own opcode constant could be found anywhere in the decompile - the same reasoning
shape that caused the 0x31/0x2d mistake. Prompted by having a fresh, complete disassembly dump of this
whole function on hand already (captured for the issue #13 `local_d0` investigation), a direct trace of
all sixteen real top-level comparisons for the `0x16-0x25` range showed EVERY ONE of them - the eleven
already believed to be `handle_remove_texture_from_stream` and the five believed reserved - branches to
the exact same real address (`0x2e820`), independently confirmed by disassembling that address directly
to be `handle_remove_texture_from_stream`'s own real content (slot lookup, atomic refcount decrement,
conditional delete-if-last-reference, slot cleared) - not a no-op, no gaps. `handle_reserved_noop` removed
entirely; all sixteen values now route through the one real handler, which was already written generically
enough (its own index formula, independently verified byte-for-byte against the real `subis`/`rlwinm`
sequence at `0x2e820`) to need no changes itself - only the dispatch wiring was wrong. See the dispatch
`switch`'s own range-check comment in `Sources/ATIR500GLContext_ProcessCommandBuffer.cpp` for the full
account. Worth noting as a reusable technique: whenever this project captures a fresh disassembly dump for
one investigation, it's worth a quick cross-check against nearby dispatch-table claims before discarding
it - this is the second real bug (after 0x31/0x2d) found exactly that way on this exact function.

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
  section 5's discovery of opcode `0x36`, found the same way). ~~One real open item remains: whether this
  main execute-path handler processes a fixed 4 slots...~~ **RESOLVED (issue #12 item 2)**: a fresh,
  complete re-decompile of `process_command_buffer` confirmed the real handler initializes its loop
  counter to a literal `4` and decrements it exactly 4 times - genuinely a fixed 4-slot loop, matching
  `discard_command_buffer`'s independent trace exactly. Confirmed, not inferred.
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
- ~~Opcode `0x31` (FSAA resolve blit) - entirely stubbed.~~ **RESOLVED, but via a real identity
  correction, not a direct fill-in of this stub (issue #12 item 4, commit `2236b56`)**: the ~500-line
  textured-quad content this bullet originally described (real floating-point NDC/viewport math, US-block
  shader headers, the `_g_r500_3d_blit_state_packet` template) turned out to be a misattributed real
  handler for opcode `0x2d`, not `0x31` - confirmed by tracing its own `FUN_000314c4(...)` call back to a
  real `if (uVar34 != 0x2d000000)` exclusion check's `else` branch, the literal-once-in-the-whole-decompile
  `0x2d000000` constant leaving no ambiguity. The REAL opcode `0x31` was then transcribed fresh, as
  `handle_depth_buffer_resolve`: a short, purely-integer handler (attachment-index remap, normal/alternate
  surface-pair selection, one or two `decompress_and_flush_depth_buffer` calls, a per-mip/tile
  register-burst write). This correction rippled into several files' stale cross-references
  (`ATIR500GLContext.h`, `ATIRadeonX1000Registers.h`, `ATIR500DVDContext.h`/`.cpp`), all swept and fixed at
  the same time. One small residual question survived this re-attribution and is tracked in issue #13.
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

## 3. Register-state serialization - FULLY RESOLVED

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

Real, honestly-flagged anomaly, accepted as-is when issue #12 item 3 closed rather than a still-open
question: the raw decompile's final step - releasing the mapping handle via vtable+0x18 - is UNCONDITIONAL,
running even along the control-flow path where the local holding that handle was never assigned away from
a literal null (when `newTex+0x54 == 0`, or when
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

**RESOLVED (issue #13 item 1)**: the open item that survived the re-attribution, about whether opcode
0x2d's `local_d0` (an explicitly-computed pointer distinct from `record`) ever needed the shared
exit-descriptor-write/status-return check the dispatch loop's `next != record` branch was skipping for it.
Settled with a direct disassembly trace of the real compiled opcode body (`0x2d034`-`0x2deb4`): `record`
and the two real registers `LAB_00031340`'s own tail uses to advance/exit are set once at the real loop
top (from the record's own standard embedded distance field) and are PROVABLY never touched anywhere in
this opcode's whole ~600-instruction real body. `local_d0` is real, but purely internal - used only for
this opcode's own trailing self-pad step, never fed back as a distinct next-record pointer. The real
compiled code falls through to the exact same shared tail as every other opcode, using the exact same
unmodified distance field - not an exception at all. This means this project's earlier model (returning
`local_d0`, dispatch loop advancing straight to it and skipping the real exit check) was a real bug, not
just an unverified caveat - fixed in both `ATIR500GLContext_handle_fsaa_resolve_blit` (now always returns
`record` unchanged) and the dispatcher's own `case 0x2d000000`. See that function's own header comment for
the full trace.

**RESOLVED (issue #13 item 2)**: `ATIR500Surface::resolve_fsaa_buffer` is no longer opaque - fully
transcribed (`Sources/ATIR500Surface_ResolveFSAABuffer.cpp`). Real top-level structure: a single flag-bit
test (`this+0xbe8 & 0x700000`) selects between two entirely different real resolve strategies - a
per-plane MSAA burst plus floating-point NDC viewport blit (flag clear), or a HyperZ-block-driven resolve
using `HZMEM_GetBlockOffset`/`HZMEM_GetBlockCount` with a completely different real PM4 burst shape (flag
set) - never a minor variation of one path, two genuinely distinct real mechanisms. Found and named three
previously-undocumented real fields on `ATIR500SurfaceBuffer` (`+0x30`/`+0x36`/`+0x3c`) and two new
`IOATIR500Surface` fields (`surfaceBuffersByFormat`/`fixedSurfaceBuffer`) along the way - see
`ATIRadeonX1000Types.h`/`IOATIR500Surface.h`. Also declared a fourth real format-lookup table
(`SamplesTableLookup`, `ATIRadeonX1000Registers.h`), matching the existing `FormatTableLookup_0x0004d2e0/
dc/e4` convention.

## 5. `IOATIR500Accelerator`'s four context-factory vtable slots - FULLY RESOLVED, issue #6

**Both the names/purpose AND the raw numeric values are now resolved.** Names: `newUserClient`'s four
real vtable slots (`+0x5d4/0x5d8/0x5dc/0x5e0`) map to `createSurfaceContext`/`create2DContext`/
`createDVDContext`/`createGLContext` respectively - type 0 (Surface) and type 1 (GL) CONFIRMED via real
`IOServiceOpen(...)` call sites in this project's own downloaded userspace binaries, type 2 (2D) and type
3 (DVD) INFERRED by elimination.

**The key correction that resolved the raw values**: every earlier attempt read these four words off
`IOATIR500Accelerator`'s OWN vtable (`__ZTV20IOATIR500Accelerator`, `0x46970`) and correctly proved that
copy is genuine linker placeholder content (not `PPC_RELOC_LOCAL_SECTDIFF` as first logged, but real,
exhaustively-ruled-out `GENERIC_RELOC_VANILLA` placeholder bytes - ruled out plain absolute address,
section ordinal, symbol-table index, a parsing bug, and a separate `LC_DYSYMTAB` table). True, but beside
the point: no real object in this driver is ever a bare `IOATIR500Accelerator` - every real instance is
the concrete `ATIRadeonX1000` subclass, which has its OWN real vtable
(`__ZTV14ATIRadeonX1000`, `0x491c8`) that DOES locally override all four slots. Reading that vtable
directly gives real values that independently CONFIRM the existing name mapping exactly:
`+0x5d4`→`ATIRadeonX1000::new_surface` (`0x1a140`), `+0x5d8`→`new_2d_context` (`0x1a220`),
`+0x5dc`→`new_dvd_context` (`0x1a290`), `+0x5e0`→`new_gl_context` (`0x1a1b0`). See
`Headers/IOATIR500Accelerator.h`/`Headers/ATIRadeonX1000.h`'s updated declarations for the full account.

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

## 7. The 2D and DVD contexts' own embedded command-buffer languages - FULLY RESOLVED (both 2D and DVD)

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

**FINAL CONTINUATION - ISSUE #7 FULLY RESOLVED**: opcode 0x12 (`0x35c04`-`0x364c0`, ~750 real decompile
lines) transcribed and wired, closing out the last remaining opcode in this whole issue. Two independent
real transfer buffers (`record[1]`/`record[5]`-indexed), each GART-mapped and linked-list-spliced via the
exact same real sequence `handle_opcode_18` already established (reused verbatim, not re-derived), feed an
8-entry stride table that's split across two real, near-mirror 30-slot PM4 bursts (`record[6]`/`record[7]`-
indexed) - each burst a `0x832`/`0x833` header, a 5-slot `0x1150`-`0x1154` block from the stride table, a
4-way-branched `0x1155`/`0x1156` pair, a 4-slot `0x1157`-`0x115c` block from two more independent per-mip
records, and a real caller-data-driven variable-length trailing loop.

That trailing loop independently re-confirms (via direct disassembly instruction tracing, not decompile
pointer-type inference) the exact same real 32-bit-address-arithmetic-overflow idiom `handle_opcode_3d`
already documented (a self-consuming `0x80000000` sentinel immediately reused in pointer-index arithmetic
that overflows back to 0) - this time inside a genuine multi-iteration loop rather than a one-time
computation, a second convergent data point that this is a real, deliberate compiler pattern in this
codebase, not a one-off curiosity.

**A real false lead was chased and ruled out** while locating this opcode's true body: Ghidra's own C
decompile renders a second, textually-adjacent-looking block right after 0x12's real content (a
mode-2/3/other Y/UV formula using `boundSurface+0x7b8`/`+0x7c8`, superficially resembling
`handle_opcode_14`/`16`/`17`'s own shape) that, by proximity and indentation, looks like it might continue
being part of 0x12. Direct disassembly cross-check disproved this conclusively: 0x12's real address range
(`0x35c04`-`0x364c0`) contains exactly one real shared-exit branch (`b 0x00039028`, at the very end), and
zero occurrences of `b 0x0003903c` - the exit target that block's own decompile "goto" names. A full
re-derivation of every real dispatch-table target in the whole enclosing function (done specifically to
chase this down) showed every single one already accounted for by an already-committed handler, confirming
that block is either a Ghidra rendering artifact of already-covered content or genuinely dead/unreachable
code - either way, not a live gap. See `handle_opcode_12`'s own header comment for the full account; worth
remembering as a concrete instance of this file's own established rule that decompile text/proximity is
never sufficient on its own for structural claims about this giant function.

**Issue #7 status: FULLY RESOLVED.** Every real DVD opcode this project found - 50 with genuine handlers,
plus 4 confirmed real hard-abort paths with no other handler - now has real, disassembly-verified behavior
wired into `process_command_buffer`'s dispatcher, closing out the last of the original ~18 open items.

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

## 11. Real binary data tables/constants never pulled from the kext - RESOLVED, issue #14

**RESOLVED.** All four items' real raw content read directly from `ATIRadeonX1000.kext.bin`'s own data
sections via a Ghidra headless script against the already-imported project - see
`Sources/ATIRadeonX1000_DataTables.cpp` for all of it.

Real structural finding along the way: `FormatTableLookup_0x0004d2dc/e0/e4` are NOT three independent
tables - they're three adjacent `UInt32` fields (`+0xc`/`+0x10`/`+0x14`) within ONE real, named struct
array this project found directly in the kext's own symbol table, `_ati_format_info_table` (real base
`0x4d2d0` - twelve bytes before what this project's own historical field-offset-derived naming assumed
was the table's start). Real, disassembly-confirmed exactly 48 entries: a self-index field
(`entry[0] == index << 24`) increments cleanly for all 48 and then breaks completely at a 49th slot, which
real kext symbols immediately beyond (`out_fmt`/`rb3d_dst_format`/`texture_type`/`gMetaClass`) confirm is
unrelated data. All 48 entries' full 7-field content now backs the three accessors, indexing convention
unchanged for every existing call site.

`SamplesTableLookup`'s real table (`_samplesTable`, kext address `0x4c268`) - real content extracted for
its whole real used range: every entry is 0 except two (values `2` and `3`). Caught a real mix-up risk
before it happened: a *different*, unrelated local static also named `samplesTable` exists in the kext
(`ATIR500Surface::load_3d_blit`-local, address `0x4c2f4`) - confirmed which one this project's own
`resolve_fsaa_buffer` transcription actually references before extracting either.

`_g_r500_3d_blit_state_packet`'s real address (`0x4c768`) and all 189 real dwords now extracted and
captured - satisfies the issue's own stated "at minimum the raw bytes" bar. Per-field semantic naming
(walking all 189 dwords against the capstone register-map doc, the same way `register_tracking_state` was)
remains a real, still-open, separate task - not pursued this pass, flagged in the struct's own header
comment for whoever picks it up.

`FLOAT_0004c370/374/37c/380`/`DOUBLE_0004c3a8/3b0/3b8` - all seven real IEEE-754 values now known exactly
(all clean, "designed" values: `0.0f`/`1.0f`/`6.0f`/`0.5f`, and the two magic-bias doubles at
`4503601774854144.0`/`4503599627370496.0` plus a third `0.5` double). Two real corrections to this
project's own earlier guesses: `FLOAT_0004c374` is a true reciprocal numerator (`1.0f`), not "a fixed
texture-space extent" as guessed; `FLOAT_0004c37c` is `6.0f`, not the guessed `16.0f` for R5xx 12.4
fixed-point. `DOUBLE_0004c3a8`'s real value also directly cross-confirms the literal
`4503601774854144.0` magic-bias constant this project's DVD-context and `resolve_fsaa_buffer`
transcriptions had already independently derived and used inline elsewhere - a nice convergent check.

## 12. ~24 opaque `FUN_XXXXXXXX` helper functions - STILL OPEN, issue #15 (real narrowing, not resolved)

**CORRECTED**: an earlier pass of this file marked this RESOLVED - that was premature and has been
reverted (a user correction caught it). The real narrowing below is genuine, durable progress, but it does
NOT satisfy this issue's own actual ask (identifying what these functions really are) - it only explains
why that identification isn't achievable through static analysis alone. Same standing as issue #6: real
progress, still open, needs hardware or an external symbol source to actually close.

Real finding that changes the SHAPE of the remaining work: these are NOT local functions this project
failed to decompile - direct inspection showed every one of the 23 real kext-local addresses (a 24th,
`FUN_0002c790`, turned out to be a real miscategorization - see below, that correction stands) is a real
lazy-binding external-symbol stub trampoline: the identical real 4-instruction sequence
(`lis r12,0x0; ori r12,r12,0x0; mtspr CTR,r12; bctr`) with LITERAL ZERO immediates in the static binary,
not a body with any real logic to decompile at all.

Confirmed this is genuinely unresolvable via static analysis alone (not just an unanalyzed local call) via
three independent checks, matching the same rigor issue #6 already used on this same binary: (1) this kext
has NO `LC_DYSYMTAB` at all - a real, structural fact about this specific Tiger/Leopard-era binary format,
not an analysis gap; (2) the `__text` section's own per-section relocation table (`nreloc=11622`) was read
directly and produced nothing resolvable at these specific addresses; (3) Ghidra's own original
full-analysis import recorded zero real references from any of these 23 addresses - the same tool that
correctly resolves thousands of other real internal calls throughout this binary found nothing to resolve
here either. **What's still genuinely missing, and what it would actually take to get it**: the real
target symbol name/address for each stub, recoverable only via (a) a live kxld-resolved memory read on
real hardware (the kernel patches these trampolines' immediates at kext-load time - reading that live
memory then cross-referencing against a live kernel symbol map would give real names), or (b) a real
kernel/IOKit KPI export-symbol list to cross-reference by address, neither available in this sandboxed
environment. Same real category of limitation as issue #6's accelerator vtable slots, now confirmed for a
second, much larger group of symbols in this same binary - and, like issue #6, staying open until one of
those two paths actually closes it.

**Real correction to this project's own issue #15 filing**: `FUN_0002c790` was miscategorized - that
address belongs to a completely different, out-of-scope binary (`ATIRadeonX1000GLDriver.bundle`, a
userspace driver), not this kext at all. No function is defined there in this kext's own Ghidra project,
correctly, since it was never really part of this binary.

This project's own earlier role-level inferences (lock/unlock pairs, an alloc/free pair, transfer-buffer
GART-mapping helpers, atomic refcount helpers, the blit-state-packet template-copy helper) remain the real,
standing understanding for each - derived from real call-site analysis, independent of ever seeing these
functions' own bodies. **This is NOT the same as satisfying issue #15's own "confirmed... once identified"
bar** - role-level inference existed before this pass too; what this pass actually added is the structural
proof that no further static decompilation can ever recover more than that, not an identification. Full
account and complete symbol list in the comprehensive note at the end of `Headers/ATIRadeonX1000Registers.h`.

## 13. `IOATIR500Surface` was never split into a real base/subclass pair - RESOLVED, issue #16

Now matches GL/DVD/2D's real `IOATIR500XContext`/`ATIR500XContext` base/subclass pattern:
`Headers/ATIR500Surface.h` is the new concrete subclass, `Headers/IOATIR500Surface.h` stays the base.

Every method this project had already declared on the old unified class was checked against its own
real mangled symbol name in the kext's symbol table (the same ground-truth source used to establish
every other base/subclass boundary in this project) - not guessed. Eight real `ATIR500Surface::`
(subclass) receivers were found and re-homed:

- The whole overlay/subpicture/deinterlace family - `disable_overlay`, `enable_overlay`, `showbuffer`,
  `dvd_setup_subpicture`, `dvd_setup_overlay`, `enable_deint` (`Sources/ATIR500Surface_Overlay.cpp`).
  Previously-unknown finding from this sweep: this whole family belongs on the subclass, not the base
  as this project's earlier unified-class model had it.
- `resolve_fsaa_buffer` (already known subclass, issue #13) - now formally reflected in the hierarchy.
- `decompress_and_flush_depth_buffer` - confirmed subclass receiver; own body still not independently
  decompiled (unchanged standing gap, only the class placement changed).

Every other already-declared method (~37: lock/shape family, `get_state`, `surface_control` family,
buffer-backing-store family, etc.) was checked and confirmed to remain real `IOATIR500Surface::` (base)
receivers - no guessing involved either way.

Also confirmed real subclass members from the same symbol sweep, but deliberately left undeclared
(out of this issue's scope - re-homing already-declared members, not new decompilation):
`getTargetAndMethodForIndex` (real kext offset `0x3ac80`) and `invalidate` (`0x3acb0`), matching the
same subclass-owns-dispatch pattern GL/DVD/2D already established. Addresses recorded in
`Headers/ATIR500Surface.h`'s header comment for a future decompile pass.

All 6 real call sites of the re-homed methods (all in `Sources/ATIR500GLContext_ProcessCommandBuffer.cpp`)
verified to use the correct `ATIR500Surface *` pointer type; swept the rest of the codebase and confirmed
no other file calls any of the 8 re-homed methods.

## 14. `back_resolve_fsaa_buffer` - RESOLVED, issue #17

Full real decompile obtained and transcribed (`Sources/ATIR500Surface_BackResolveFSAABuffer.cpp`). Real
signature: first parameter genuinely unused, second indexes `surfaceBuffersByFormat` (same real
per-format-code array `resolve_fsaa_buffer` uses), third is the same output-record-pointer convention.

Real structural relationship to `resolve_fsaa_buffer` (issue #13) - confirmed NOT simply that function run
backwards: same two `ATIR500SurfaceBuffer*` sources (`fixedSurfaceBuffer`/`surfaceBuffersByFormat[idx]`)
but their slot-group roles are SWAPPED; no top-level HyperZ-vs-float-blit branch (`this+0xbe8`'s flag
survives only as one extra register write); no HyperZ block machinery at all; the float tail computes a
single per-axis half-extent from the surface's own dimensions rather than a caller-supplied rectangle, and
branches on a real PER-SURFACE tiling check (not the top-level flag) to pick between a plain and a
sign-flipped magic-bias conversion.

No real internal caller found - a full Ghidra cross-reference sweep for this function's address found only
one hit, typed "Entry Point (EXTERNAL)" with no containing function.

**Real bug found and fixed in `resolve_fsaa_buffer` (issue #13) along the way**: cross-checking this
function's real `+0x20` field read and real `this+0xbe8` top-level flag read against `resolve_fsaa_buffer`'s
already-committed transcription surfaced two real misattributions there - a `bytesPerRow` field wrongly
aliased onto a distinct real `+0x20` field (now named `basePitch`, `ATIRadeonX1000Types.h`), and an
`accelerator+0xbe8` read that should have been `this+0xbe8` (confirmed via three other already-committed
files - `IOATIR500Surface_LockShape.cpp`, `ATIR500GLContext_RegisterState.cpp`,
`ATIR500GLContext_ProcessCommandBuffer.cpp` - all independently agreeing `+0xbe8` is a real Surface-object
field, not accelerator-owned). Both fixed in `Sources/ATIR500Surface_ResolveFSAABuffer.cpp`; the rest of
that file was re-verified line-by-line against its own raw decompile and found accurate.

Also found: `FUN_00044d74` (this function's blit-state-packet-template-copy call) is a real, separate
lazy-binding stub instance - added to issue #15's stub catalog (`ATIRadeonX1000Registers.h`); does not
change that issue's own open status.

## 15. `IOATIR500Surface`'s remaining raw-vtable-offset calls - RESOLVED, issue #18

12 real, distinct `IOATIR500Surface`/`ATIR500Surface` vtable slots (8 in the original filing, 4 more
found while wiring the rest in) resolved via the same technique that resolved issue #6: reading
`ATIR500Surface`'s own concrete-subclass vtable (`__ZTV14ATIR500Surface`, `0x4bbe0`) directly, since every
real Surface object in this driver is that subclass (issue #16).

- `+0x5b4`/`+0x5b8`/`+0x5bc` → `update_ref_stamps`/`increment_refcounts`/`decrement_refcounts` (base-level,
  not subclass-overridden - `remove_texture_from_stream`/`add_texture_to_stream`,
  `IOATIR500GLContext_TextureStream.cpp`).
- `+0x5c4` → `invalidate` (subclass-only override, same real per-context dirty-bit pattern issue #12.1
  already established for `ATIR500GLContext`).
- `+0x5cc`/`+0x5d0` → `dealloc_surface`/`alloc_surface_buffer` (`compact_current_textures`'s
  `evictSurfaceBuffers` helper, `ATIR500GLContext_TextureLoad.cpp`).
- `+0x5fc`/`+0x600` → `prepare_vram`/`complete_vram` (`surface_write_lock_int`/`unlock_int`,
  `IOATIR500Surface_LockShape.cpp`) - real mangled parameter type is `ATIR500SurfaceBuffer*`, not the
  generic `void*` this project's call sites had inferred.
- `+0x5a8`/`+0x5dc` → `resetFullScreen`/`is_flip_allowed` (`set_id_mode`, `IOATIR500Surface_LockShape.cpp`)
  - found mid-wiring, not in the original 8-slot filing (no explicit "names UNKNOWN" comment had flagged
  them, but the same real gap).
- `+0x5c8`/`+0x5b0` → `shape_surface`/`is_surface_size_supported`
  (`set_shape_backing_length_ext`, same file) - `is_surface_size_supported`'s real mangled parameter
  types are `short`, not the `SInt32` the call site had inferred.

All 12 declarations added to `Headers/IOATIR500Surface.h` (the base - required even where the real
override is subclass-only, since every real call site reaches them through a base-typed pointer via
ordinary virtual dispatch, not a subclass-typed one). Every raw vtable-offset cast this touched replaced
with a real named call. None of the real function bodies (base or subclass) independently decompiled this
pass - only the vtable slot values/real names were in scope.

## 16. `IOATIR500Accelerator`/`ATIRadeonX1000`'s remaining raw-vtable-offset calls - RESOLVED, issue #19

9 real, distinct vtable slots (7 in the original filing, 2 more found while wiring the rest in) resolved
the same way as issue #6/#18 - reading `ATIRadeonX1000`'s own concrete-subclass vtable
(`__ZTV14ATIRadeonX1000`, `0x491c8`) directly.

- `+0x524`/`+0x528` → `deallocate_texture`/`allocate_texture` (`alloc_and_load_texture`,
  `ATIR500GLContext_TextureLoad.cpp`) - `deallocate_texture` takes NO texture parameter, contrary to what
  its name alone suggests.
- `+0x530` → `setup3D` (`IOATIR500GLContext::start()`) - this call was previously left ENTIRELY UNCALLED
  in the transcription (only a comment recorded the real decompile line); now actually wired into the
  real failure-path control flow.
- `+0x54c`/`+0x558` → `waitForTimeStamp`/`sleepForTimeStamp`, extending the already-known
  `waitForRetiredTimeStamp`/`waitForTimeStampNoLock`/`waitForConsumedIDCTTimeStamp` fence-wait family to
  its real full 8-member set (`compact_current_textures`/`submit_context_buffer`/
  `restore_state_destroyed_by_pageoff`/`surface_write_lock_int`/`set_shape_backing_length_ext`).
- `+0x5a8` → `addTransferToGART` (`map_transfer_to_GART`, `IOATIR500GLContext_TextureStream.cpp`) - takes
  NO buffer parameter, contrary to what its name alone suggests.
- `+0x5ec` → confirmed as the real vtable slot for the ALREADY-declared `waitForConsumedIDCTTimeStamp`
  (`ATIR500DVDContext_ProcessCommandBuffer.cpp`'s opcode `0x0a`/`0x12` handlers).
- `+0x540`/`+0x544` → `tmpAllocVRAM`/`tmpDeallocVRAM` (`IOATIR500Surface::set_id_mode`/
  `set_shape_backing_length_ext`) - found mid-wiring, not in the original 7-slot filing.

All declarations added to `Headers/ATIRadeonX1000.h`. Real parameter/return types corrected against each
call site's own existing typedef where this project's earlier guesses (in the issue's own filing) turned
out wrong (e.g. `waitForTimeStamp`/`sleepForTimeStamp` return `UInt32`, not `IOReturn`).

## 17. `IOATIR500Shared` / the texture-adjacent GART-handle object - PARTIAL PROGRESS, issue #20 still open

`init` (`+0x48`) resolved via the same base/subclass-vtable-read technique - real addr `0x16aa0`.
`+0x18`/`+0xd0` on `IOATIR500Shared`'s own vtable (`__ZTV15IOATIR500Shared`, `0x48f28`) confirmed genuine
placeholder content (raw 0), the SAME real category issue #6 established for the accelerator's factory
slots - `IOATIR500Shared` has no known subclass in this project (unlike Surface/Accelerator), so this is
the concrete vtable and there is no further subclass to check.

**New finding**: `IOATIR500Shared`'s own vtable is only `0xd8` bytes long (`0x48f28` to the next real
symbol, `__ZTVN15IOATIR500Shared9MetaClassE` at `0x49000`) - so `+0x14c` (the third offset this issue's
own texture-adjacent object calls) is mathematically OUT OF BOUNDS for this class's vtable. This rules
out `IOATIR500Shared` as that object's real class - it is confirmed to be a DIFFERENT, still-unidentified,
longer-vtable class. Real identity of that object (reached via `texture+0x54`, then `+8`) remains open.

**New cross-reference (issue #23's `allocate_texture` decompile)**: the SAME real `+0x14c`/`+0xd0`/`+0x18`
pattern this issue already flagged also appears in `ATIRadeonX1000::allocate_texture`, called on a
texture's own `+8` field (not `+0x54+8` as the Surface-side call sites use) with the exact same real
argument shape (`_ASICSupportsAGP, 0, 1, 0, 0`) already documented in `ATIR500GLContext_TextureLoad.cpp`/
`ATIR500GLContext_DiscardBuffer.cpp`. New data point, not a resolution: the object returned by `+0x14c`
has its own real `+0xd0` method returning something with a readable `+0x20` field, and is released via
`+0x18` immediately after use - real class identity for either object still not determined.

## 18. Bodies for the 25 vtable-slot methods issues #6/#18/#19/#20 only named - PARTIAL PROGRESS, issues #21-24

Filed as 4 follow-up issues (#21 accelerator factory methods, #22 Surface vtable slots, #23 accelerator
vtable slots, #24 `IOATIR500Shared::init`/GART-handle-object identity) after confirming those earlier
issues only added declarations, never decompiled bodies.

**Fully resolved this pass** (issue #21, CLOSED): all 4 real context-factory bodies
(`ATIRadeonX1000_ContextFactories.cpp`) - trivially uniform allocate-then-placement-construct pattern,
real per-class allocation sizes found as a bonus (`ATIR500Surface` `0xdbc`, `ATIR5002DContext` `0x12c`,
`ATIR500DVDContext` `0x1e0`, `ATIR500GLContext` `0x690` bytes). Real covariant return types corrected
(concrete subclass pointers, not the placeholder `IOUserClient*`). Real allocator calls confirmed to be 4
more instances of the same lazy-binding-stub pattern issue #15 catalogs - added there.

**Small/simple members resolved this pass** (issues #22/#23/#24, PARTIAL): `update_ref_stamps`/
`increment_refcounts`/`decrement_refcounts` (real, previously-unknown finding: a genuine no-op trio,
matching the overlay family's own "real empty stub" pattern), `invalidate` (Surface), `prepare_vram`/
`complete_vram` base bodies (trivial), `is_flip_allowed`/`is_surface_size_supported` (both base and
subclass, full), `setup3D`, `tmpAllocVRAM`/`tmpDeallocVRAM`, `addTransferToGART` (base and subclass),
`IOATIR500Shared::init`/`alloc_handles` (declared, `init`'s own body transcribed).

**Three real bugs caught and fixed along the way**, all from cross-checking a fresh decompile against
already-committed code from earlier in this same session:
1. `setup3D` was declared on the wrong class (`ATIRadeonX1000`, the subclass) - its own vtable slot has
   the IDENTICAL address on the base class too, meaning it's genuinely not overridden; moved to
   `IOATIR500Accelerator.h`.
2. `addTransferToGART`'s real signature takes a `VendorTransferBuffer*` parameter at both the base and
   subclass level - issue #19's own filing had it taking none, and the one real call site
   (`map_transfer_to_GART`) was passing nothing at all, a real crash risk against the real callee's own
   unconditional pointer dereferences. Fixed; that same investigation also surfaced a genuine, unresolved
   uncertainty about whether `map_transfer_to_GART`'s own gating condition on the call's "return value" is
   real or a calling-convention artifact (neither `addTransferToGART` level ever sets a real return value
   in its own decompiled body) - left open, conservatively made unconditional rather than guessed at.
3. `tmpAllocVRAM`'s real return type is a real, meaningful `bool` (confirmed via decompiling the new
   `ATIR500Memory::alloc` class it delegates to, which has genuine `return 1;`/`return 0;` control flow) -
   not the `void*` this project's original issue #19 filing and both real call sites had assumed.

**New, substantial, previously-unknown real class found**: `ATIR500Memory` (own real vtable, at least a
dozen real methods, a genuine free-list VRAM/GART pool allocator) - only 2 of its own methods decompiled
(the ones needed to fix the bug above), left as its own minimal shell (`Headers/ATIR500Memory.h`) rather
than fully investigated; worth its own future issue.

**Also resolved since** (issue #23): `waitForTimeStamp`/`sleepForTimeStamp`/`waitForConsumedIDCTTimeStamp`
(`Sources/ATIRadeonX1000_TimeStampWait.cpp`) - three real, independently-compiled instances of one real
hardware-fence busy-wait-with-periodic-block algorithm, differing only in which hardware timestamp they
poll and which real per-call-site lazy-binding stub instances (12 more added to issue #15's catalog) they
call for the shared timing/scheduling primitives (real identities INFERRED from argument shape and
standard XNU convention, not confirmed). And `allocate_texture`/`deallocate_texture`
(`Sources/ATIRadeonX1000_TextureVRAM.cpp`) - both real and dense, `allocate_texture` also cross-referencing
issue #20's own unresolved GART-handle-object mystery (new data posted there). **Real signature bug caught
and fixed**: `deallocate_texture`'s real body takes a `VendorTextureBuffer*` parameter - issue #19's own
filing had it taking none, and both real call sites (`ATIR500GLContext_TextureLoad.cpp`) were passing
nothing at all; fixed. Two more new real functions found and declared as a side effect:
`HZMEM_Free`/`IOATIR500Accelerator::pageOffDataBuffer` (own bodies not decompiled).

**Still deferred, substantial real functions** (issue #22 stays open for these): `dealloc_surface`'s
subclass override, `alloc_surface_buffer`, `prepare_vram`'s subclass override, `resetFullScreen`'s
subclass override (which itself surfaced ANOTHER real, uncatalogued Surface vtable slot, `+0x5e0`, called
with real arguments `id, 0, 1` - not investigated), and `shape_surface` (a real outlier, ~19KB of raw
decompile - by far the largest single function this project has ever decompiled).

## 19. `map_transfer_to_GART`'s real gating condition - RESOLVED (as much as possible), issue #26

Filed after fixing `addTransferToGART`'s signature (gap 18) surfaced a genuine, then-unresolved question:
does `addTransferToGART` (and by extension `map_transfer_to_GART`'s own gate around `freeToAllocGART`)
ever produce a real, meaningful return value, or is the previous transcription's captured "result" a
calling-convention artifact?

Decompiled `IOATIR500Accelerator`'s own `+0x5a0` vtable slot - a real, already-named symbol,
`addToGART(IOMemoryDescriptor*, unsigned long*)`, real addr `0x5220` (base) / `0x1a480` (subclass, a
trivial pass-through override with no added logic). Both levels are CONFIRMED genuinely `void` - neither
ever sets a real return value in its own control flow. `addToGART`'s own real body makes one further
delegating call, to a standard Apple `IOMemoryDescriptor` vtable slot (`+0x590`) - a real, well-known Apple
base class this project doesn't reverse-engineer, so its own real behavior stays formally unconfirmed.

This is strong (not airtight) confirmation that no real signal exists anywhere in the
`map_transfer_to_GART` → `addTransferToGART` → `addToGART` chain - the conservative unconditional fix
already applied to `map_transfer_to_GART` is the correct final transcription, not a placeholder. See
`Sources/ATIRadeonX1000_VtableSlotBodies.cpp` and `Headers/IOATIR500Accelerator.h`'s own header comments
for the full account.
