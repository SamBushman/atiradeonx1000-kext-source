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
- Opcode `0x29` (vertex-format switch table) - the 8-case enum-remapping switch itself not transcribed.
- Opcode `0x2a` (render-target-pair + scissor) - real per-slot bind body not transcribed.
- Opcode `0x2b` (explicit flush) - real pending-count bookkeeping fields not mapped to named struct
  fields yet.
- Opcode `0x2c` (mip-aware scissor intersect) - real per-mip computation not transcribed.
- Opcode `0x2f` (HyperZ commit) - the trailing vtable call's real virtual method name is unknown.
- Opcode `0x30` (FSAA resolve setup) - real format-code switch not transcribed.
- **Opcode `0x31` (FSAA resolve blit) - entirely stubbed.** This is the single largest remaining gap in
  the whole file: a complete textured-quad draw with real floating-point NDC/viewport math and US-block
  shader headers, reusing the same `_g_r500_3d_blit_state_packet` template as
  `restore_state_destroyed_by_pageoff`. Full real trace already exists in
  `g5-h264-gpu-decode`'s `promo4-client/reveng/stage4-opcode-range-0x02-0x31-traced.md`.
- Opcodes `0x37`/`0x38`/`0x39` (deferred texture/render-target offset patch, address fixup, vertex-
  attribute binding) and the `0x3a/0x3b/0x3d/0x3e/0x3f/0x40/0x43` texture-load family, plus `0x44`/`0x45`
  - all have real, complete traces already written up in `stage4-embedded-opcode-table-completed.md` and
  its follow-ups; none transcribed into this reconstruction's C++ yet.

## 3. Register-state serialization functions are structurally complete but body-empty

`write_kernel_context_buffer_regs` and `restore_state_destroyed_by_pageoff` in
`Sources/ATIR500GLContext_RegisterState.cpp` document every real register/value pair they're confirmed to
write (in exact real order, per the capstone register map), but the actual `dwordBuffer[i] = ...`
statements are left as a TODO block rather than written out - this is mechanical, well-documented work,
just not yet done. `compute_sc_hyperz_en`/`compute_zb_bw_cntl`'s real bit-level decision logic is also not
transcribed (only their confirmed default-case return values are).

## 4. Several real internal helper functions are declared but have no `.cpp` body at all

`build_scissor`, `GetTextureOffset`/`WriteTextureOffset`, `GetVertexArrayOffset`/`WriteVertexArrayOffset`,
`GetQueryOffset`, `add_texture_to_stream`/`remove_texture_from_stream`/`load_texture`/
`alloc_and_load_texture`/`compact_current_textures`, `map_transfer_to_GART`,
`process_kATIGLStreamFastClearColor`, `build_surface_from_texture`, `submit_context_buffer`,
`discard_command_buffer` - all real, confirmed to exist and have a confirmed *role* (see the header
comments in `Headers/ATIR500GLContext.h`), none have a source file yet. Each would need either a fresh
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

## 10. `Info.plist`'s PCI device-ID match string is an unverified placeholder

See the file's own inline comment. **Requires real hardware** to close (or, short of that, reading the
real, already-loaded `ATIRadeonX1000.kext`'s own `Info.plist` directly off the Tiger HD this project has
read-only access to, which was simply never done - a pure oversight, not a hardware-access gap).
