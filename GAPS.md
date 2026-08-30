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

`Sources/ATIR500GLContext_ProcessCommandBuffer.cpp` has a named, correctly-dispatched handler for every
real opcode this project ever catalogued, but several bodies are honest stubs pointing at the exact
source document to transcribe from rather than full reconstructions:

- Opcodes `0x02-0x05` (HyperZ/HiZ block management) - categorized, never bit-traced (a deliberate scoping
  choice at the time, given the redesign proposal skips HyperZ entirely).
- Opcode `0x26`/`0x27` (transfer-buffer bind/unbind) - real refcount/lookup body not transcribed.
- Opcode `0x28` (single render-target + scissor) - real per-mip offset/pitch formula not transcribed
  (shares its shape with `write_kernel_context_buffer_regs`, see below).
- ~~Opcode `0x29` (vertex-format switch table)~~ RESOLVED - the real 8-case enum-remapping switch was
  confirmed and transcribed via `discard_command_buffer`'s independent trace of the same opcode (see
  section 5's discovery of opcode `0x36`, found the same way). One real open item remains: whether this
  main execute-path handler processes a fixed 4 slots (as `discard_command_buffer` does) or the dynamic
  `attachmentCount` - not independently re-confirmed for this exact function.
- ~~Opcode `0x2a` (render-target-pair + scissor)~~ RESOLVED - fully transcribed (`RTOffsetTilingBurst`
  reused twice, real duplicated scissor-Y write into two record slots).
- Opcode `0x2b` (explicit flush) - real pending-count bookkeeping fields not mapped to named struct
  fields yet.
- ~~Opcode `0x2c` (mip-aware scissor intersect)~~ RESOLVED - fully transcribed via `RTOffsetTilingBurst`.
  Real, notable finding: this opcode reads BOTH `this+0x354` and `this+0x358` together as a Y/X pair,
  which is new evidence for (but doesn't resolve) section 3's open `build_scissor` question about
  `this+0x354` never being written.
- ~~Opcode `0x2f` (HyperZ commit)~~ RESOLVED - fully transcribed, including the real trailing raw vtable
  call through slot `+0x5a4`. That slot's real virtual-method NAME is still unknown (called via a raw
  function-pointer cast, not invented) - a small residual gap, not a missing transcription.
- ~~Opcode `0x30` (FSAA resolve setup)~~ RESOLVED - fully transcribed. Found and fixed a real bug in this
  project's own `IOATIR500Surface::resolve_fsaa_buffer` declaration while doing so: it was missing one of
  four real trailing dword parameters the actual call site passes.
- **Opcode `0x31` (FSAA resolve blit) - entirely stubbed.** This is the single largest remaining gap in
  the whole file: a complete textured-quad draw with real floating-point NDC/viewport math and US-block
  shader headers, reusing the same `_g_r500_3d_blit_state_packet` template as
  `restore_state_destroyed_by_pageoff`. Full real trace already exists in
  `g5-h264-gpu-decode`'s `promo4-client/reveng/stage4-opcode-range-0x02-0x31-traced.md`.
- Opcodes `0x37`/`0x38`/`0x39` (deferred texture/render-target offset patch, address fixup, vertex-
  attribute binding) and the `0x3a/0x3b/0x3d/0x3e/0x3f/0x40/0x43` texture-load family, plus `0x44`/`0x45`
  - all have real, complete traces already written up in `stage4-embedded-opcode-table-completed.md` and
  its follow-ups; none transcribed into this reconstruction's C++ yet.

## 3. Register-state serialization: mostly done, one open question, two functions still bodies-empty

`write_kernel_context_buffer_regs` and `build_scissor` in `Sources/ATIR500GLContext_RegisterState.cpp`
have now been fully transcribed from a complete real decompile (not just summarized) - real per-mip
offset/tiling math, every register write in real order, HZMEM_GetBlockOffset calls, and a 6th independent
sighting of `SC_CLIP_RULE = 0xaaaa`.

**A real, open question this transcription surfaced**: `build_scissor`'s real decompiled body only ever
writes `this+0x358` (`scissorX`) - it never touches `this+0x354` (`scissorY`) at all. This calls into
question this project's earlier assumption (from the opcode 0x28/0x29/0x2a traces, where both fields are
embedded together into the command stream) that the two are a simple Y/X coordinate pair. Either
`this+0x354` is computed by a different function this project never traced, or the field's real role is
something other than a plain "Y" value. **Does not require hardware** - needs either a fresh decompile of
whatever function writes `this+0x354`, or a live trace correlating both fields against real on-screen
scissor behavior (the latter would need hardware).

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
**fully reconstructed** from complete real decompiles (closing most of issue #5). Still real, confirmed-
to-exist, but only lightly sampled (not fully transcribed, given their size/density):
`load_texture`/`alloc_and_load_texture`/`compact_current_textures`/`submit_context_buffer` - each would need a fresh
targeted Ghidra decompile pass or transcription from this project's existing stage docs where one already
covers it.

## 5. `IOATIR500Accelerator`'s four context-factory vtable slots are a real tooling ceiling, not a gap

`newUserClient`'s four real vtable slots (`+0x5d4/0x5d8/0x5dc/0x5e0`) read as zero in every Ghidra import
attempted - an unsupported Mach-O relocation type (`PPC_RELOC_LOCAL_SECTDIFF`, decimal 15), not a
driver-logic gap. Closing this needs either a Ghidra version/plugin that supports this relocation type,
or hand-parsing the kext's raw Mach-O relocation table (no `otool`/`llvm-objdump` was available in the
environment this was written in either - a second, smaller tooling gap).

## 6. The base classes' own construction/initialization was never decompiled from scratch

`ATIRadeonX1000` (the hardware class) and the four `IO`-prefixed base user-client classes' own field
layouts were all learned *indirectly*, through other functions dereferencing them - no function was ever
decompiled specifically to answer "what does this class's own constructor initialize, in order, from
offset zero." This means real field ordering relative to each other (not just each field's own existence)
is uncertain in several places - see e.g. `ATIRadeonX1000.h`'s note about `deviceActiveFlag`'s uncertain
position relative to the command lock and MMIO base fields. Also unknown: which function actually
populates `IOATIR500GLContext`'s `regularMethodTable` at `+0x2a0` (confirmed to exist, confirmed NOT to be
`ATIR500GLContext::start()`, which only sets the special selector-20 slot).

## 7. The 2D and DVD contexts' own embedded command-buffer languages are entirely unimplemented

`ATIR5002DContext`/`ATIR500DVDContext` both have a real, confirmed, extensive `process_command_buffer` of
their own (same mechanism as GL's, different opcode numbers) - neither has been reconstructed into C++ at
all here, only confirmed to exist and sampled at a categorical level (see
`stage9-gl-remaining-methods-gart-pool-power-interrupts.md`). DVD's is flagged there as the single best
future target given direct evidence of real YUV 4:2:0 plane-geometry math and a texture-sampler-state
record - directly relevant to this project's H.264 goal.

## 8. `IOATIR500Surface`'s remaining lock/shape methods have no bodies

Of the 19 real selectors, only the video-relevant overlay family (5 methods) and a handful of others
sampled for confirmation (`surface_control`, `surface_flush`, `get_state`, `set_shape`, `surface_read`,
`surface_query_lock`, one lock/unlock pair) have any real decompiled content behind them anywhere in this
project's history. The remaining ~9 (`surface_read_lock_options`, `surface_write_lock_options`,
`surface_write_unlock_options`, `set_shape_backing`, `set_id_mode`, `set_scale`, `surface_write_lock`,
`surface_write_unlock`, `set_shape_backing_length`) were never independently decompiled at all - their
real behavior is inferred by strong analogy with the ones that were, not confirmed.

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
