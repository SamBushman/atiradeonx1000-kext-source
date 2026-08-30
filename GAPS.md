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
`0x2d` (reserved/dead, same shape as the already-known `0x17/0x1a/0x1d/0x20/0x23` gaps), `0x33` (a real
inline color+Z-buffer register burst), `0x34` (a real query/fence-slot allocator), and `0x35` (another
render-target generation-stamp opcode) - plus a fifth, `0x32`, that WAS known by number but whose real body
had never been located (a large depth-flush + per-tile texture-fetch-register-patch function, the closest
thing in this language to opcode 0x31's own tile loop). All five are now fully transcribed.

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
  offset patch, address fixup, vertex-attribute binding). `0x37`'s transcription has one honestly-flagged
  unconfirmed inference (a read of `uVar75` with no visible assignment in that opcode's own text); `0x38`'s
  has one honestly-flagged disambiguation (a `puVar65[2]` read that textually appears after that same slot
  was overwritten - modeled as reading the pre-overwrite value, not independently confirmed against raw
  machine code).
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
  slot, the densest single-register patch outside opcode 0x31; `0x40` uses a third, previously-unused
  format table (`FormatTableLookup_0x0004d2e4`).
- ~~Opcode `0x41`~~ RESOLVED - fully transcribed, the largest single opcode after 0x31. Real per-color-
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
(`ATIR500SurfaceBuffer::hyperZEligible`/`zbBandwidthEligible`). `restore_state_destroyed_by_pageoff`'s
transcription is dense (~120 real pairs) and comes with an explicit caveat in the file about
transposition risk - one was already caught and fixed, others may remain; spot-check any specific
value against the raw decompile before relying on it for a real test.

## 4. Several real internal helper functions - most now reconstructed

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

**Still deferred, given its size** (~380 lines, dense per-mip/tiling math): `load_texture` - see
`Headers/ATIR500GLContext.h`'s declaration.

**Also found, not yet resolved**: opcode 0x29's real execute-path handler was cross-checked against
`discard_command_buffer`'s independent trace of the same opcode, and both agree on the 8-case switch table
- but one open question remains unconfirmed: whether the EXECUTE-path handler processes a fixed 4 slots
(as the discard path does) or the dynamic `record[1]` attachment count opcode 0x41 uses for its own,
separate per-attachment loop. A fresh, targeted re-read of opcode 0x29's real loop-bound computation would
settle this.

**Also found, not yet resolved**: `discard_command_buffer`'s own handling of opcode 0x3b (query-buffer
bind's cleanup/discard-path counterpart) is explicitly deferred in that file's own comment - it correctly
identifies a real vtable call at offset `+0x14c` on a memory-descriptor-shaped object plus a real
four-field zero (`+0x210/+0x218/+0x21c/+0x220`), but the full real body was never transcribed. This is
independent of - and does not block - opcode 0x3b's real EXECUTE-path body, which this project's
`handle_query_buffer_bind` (in `ATIR500GLContext_ProcessCommandBuffer.cpp`) fully transcribes.

~~**A real, unnamed virtual method** at vtable offset `+0x5a4`...~~ **RESOLVED (issue #12.1)**: it's
`ATIR500GLContext::invalidate()` - see section 6 and `Headers/ATIR500GLContext.h`.

**A real, open opcode-0x31 tail-integration question** (found finishing the opcode language this pass):
opcode 0x31's handler (`ATIR500GLContext_handle_fsaa_resolve_blit`) is the one confirmed opcode whose real
ending returns an explicitly-computed next-record pointer rather than relying on the header's own encoded
distance field (every other opcode in the language does the latter). The dispatch loop's `if (next !=
record)` branch advances straight to that pointer without running the tail's real "is the buffer now fully
consumed" exit-descriptor-write check, but the real decompile shows this opcode's real ending DOES fall
into that same shared check. Whether this ever actually diverges from real hardware behavior is
unconfirmed - see that function's own updated header comment.

## 5. `IOATIR500Accelerator`'s four context-factory vtable slots are a real tooling ceiling, not a gap

`newUserClient`'s four real vtable slots (`+0x5d4/0x5d8/0x5dc/0x5e0`) read as zero in every Ghidra import
attempted - an unsupported Mach-O relocation type (`PPC_RELOC_LOCAL_SECTDIFF`, decimal 15), not a
driver-logic gap. Closing this needs either a Ghidra version/plugin that supports this relocation type,
or hand-parsing the kext's raw Mach-O relocation table (no `otool`/`llvm-objdump` was available in the
environment this was written in either - a second, smaller tooling gap).

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

## 7. The 2D and DVD contexts' own embedded command-buffer languages - 2D RESOLVED, DVD skeleton-mapped

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

DVD's `process_command_buffer` (0x357c0, ~0x39a0 bytes) remains the real, comparably-large-to-GL
undertaking described above - not touched further this pass.

## 8. `IOATIR500Surface`'s remaining lock/shape methods - MOSTLY RESOLVED

Of the 19 real selectors, only the video-relevant overlay family (5 methods) and a handful of others
sampled for confirmation (`surface_control`, `surface_flush`, `get_state`, `set_shape`, `surface_read`,
`surface_query_lock`, one lock/unlock pair) had any real decompiled content behind them. Of the remaining
~9, **6 are now RESOLVED this pass**: `surface_read_lock_options`, `surface_write_lock_options`,
`surface_write_unlock_options`, `surface_write_lock`, `surface_write_unlock`, `set_scale` are all fully
transcribed from complete real decompiles - see `Sources/IOATIR500Surface_LockShape.cpp`. Real signature
corrections found along the way: several of these had the wrong parameter count or return type
(`IOReturn` vs real `void`); `set_scale` in particular had a completely wrong shape - this project had
guessed raw `UInt32 xScale, UInt32 yScale` where the real 2nd parameter is a real `IOAccelSurfaceScaling*`
struct pointer. Also formally declared the two shared internal helpers these all forward into
(`surface_lock_options`/`surface_unlock_options`, previously only referenced in comments) and two more
real, previously-undeclared internal helpers found as their own real functions:
`surface_write_lock_int`/`surface_write_unlock_int`.

**Still deferred, given their size/density**: `set_id_mode` (~184 lines) and `set_shape_backing`/
`set_shape_backing_length` (thin forwards into a shared, also-large `set_shape_backing_length_ext`, ~236
lines) - real signatures corrected to match the real mangled symbols, but bodies not transcribed. See
`Headers/IOATIR500Surface.h`.

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
