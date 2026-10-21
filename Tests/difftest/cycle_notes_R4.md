# Estimated-cycle notes (fork R4, non-GL-context functions)

Ratio = difftest estimated cycles, rebuilt / shipped (same inputs). "before" is main be49733 (`~/g5logs/INT/final.json`), "after" is this branch built on the G5 (`~/g5logs/R4/r7.json`, 898/898 PASS).

The FormatTableLookup_* inlining (fork R1, `Headers/ATIRadeonX1000Registers.h` + `ATIRadeonX1000_DataTables.cpp`) was applied in the measuring tree to see the combined effect; it is NOT part of the R4 commits.

## Root causes found and fixed

* **Open-coded byte swaps** (`x<<24 | (x&0xff00)<<8 | ...`): Ghidra expands the shipped `stwbrx` into shifts; gcc compiled the shifts. 48 sites now call `storeWordByteReversed` (`Headers/ATIRadeonX1000PPCIntrinsics.h`). `load_promo4_micro_code` 1.42 -> ~1.0, `SWDSInit`, GART/Xdct register writes.
* **Unsigned divisions where the shipped code divides signed** (`divwu` vs `divw`, 20 cycles each, and a different result for values with the high bit set): `(UInt32)M<UInt16>(..) / (fmt >> 0x14 & 0xf)` and `0x20 / bytesPerPixel` in ~40 places (build_swap, load_3d_blit, resolve/back_resolve_fsaa_buffer, SWDSWriteBlitToCmdBuf, alloc_surface_buffer, DVD process_command_buffer, 2D get_buffer_info, buffer_map_offset, get_offset_of_sample_0). Duplicate divisions (`x = 0x20/a; if (0x20/a <= y)`) now compute once, as shipped.
* **float arithmetic in double**: Ghidra renders single-precision ops as `(double)(float)(a op b)` over `double` variables; gcc emitted double op + `frsp` + `fmr`. `Tools/renames/floatify.py` turns the float-valued variables into `float` and the int->double bias idiom into `(float)(SInt32)x` (bit-identical, difftest-gated). build_swap, pcl_CopyPix, write_3dtexquad, SWDSWriteBlitToCmdBuf, resolve/back_resolve_fsaa_buffer, load_3d_blit, DVD pcb.
* **Cache flush sequences**: the shipped code uses `dcbf/dcbst rA,rB` with the line base in rA (no add per line) and ends the "out" flush with a dummy `lwzx` of the flushed line; the decompile lost both. New `dataCacheBlock*Indexed` / `touchWordIndexed` intrinsics; flush_memory_for_in/out, submit_ring_data, submit_buffer, submit_buffer_retired, submit_idct_buffer_consumed, pageoff_dirty_texture_with_cpu. (The dropped dummy read is a behaviour difference, not only speed.)
* **Spin loops that re-read their operands**: the FIFO-space polls re-loaded `ringPointerBase`/`ringWritePointerOffset` (volatile) every iteration and masked with `& 0xffff`; the shipped loop keeps both in registers (`lwbrx rD,rA,rB`) with no mask. `loadWordByteReversedIndexed`; submit_buffer_retired, submit_idct_buffer_consumed.
* **`extsh` before 16-bit stores**: assigning an int to a volatile 16-bit lvalue makes gcc 4.0.1 sign-extend first; new `storeHalf(&M<UInt16>(..), v)` is one `sth` like the shipped code (dvd_setup_overlay 1.57 -> 1.00, SWDSInit, setup_buffers, shape_surface...).

## Cases that moved

| before | after | est. cycles/run (shipped) | case |
|---|---|---|---|
| 1.57 | 1.00 | 7 | ATIR500Surface::dvd_setup_overlay(int, int, int, int) |
| 1.51 | 1.12 | 400 | ATIR500Surface::back_resolve_fsaa_buffer(unsigned long, unsigned long, unsigned long*) |
| 1.42 | 0.97 | 7962 | ATIRadeonX1000::load_promo4_micro_code() |
| 1.40 | 1.05 | 571 | ATIRadeonX1000::SWDSWriteBlitToCmdBuf(unsigned long*, unsigned long, bool, unsigned long) |
| 1.36 | 1.25 | 28 | ATIR500DVDContext::setup_buffers(unsigned long, unsigned long, unsigned long, unsigned lon |
| 1.36 | 1.04 | 565 | ATIRadeonX1000::SWDSWriteBlitToCmdBuf [hand H2] |
| 1.30 | 1.05 | 1744 | ATIR500Surface::build_swap |
| 1.30 | 1.30 | 10 | IOATIR500Surface::set_dvd_context(IOATIR500DVDContext*) |
| 1.30 | 1.13 | 245 | ATIR500Surface::shape_surface() |
| 1.24 | 1.00 | 1418 | IOATIR500Accelerator::flush_memory_for_in(void const*, unsigned long) |
| 1.24 | 1.04 | 1644 | ATIRadeonX1000::submit_idct_buffer_consumed [hand H2] |
| 1.23 | 1.10 | 535 | ATIR500Surface::shape_surface modes H3 |
| 1.23 | 1.23 | 101 | IOATIR500Surface::attach_buffer_backing_store(ATIR500SurfaceBuffer*, IOMemoryDescriptor*,  |
| 1.22 | 1.03 | 61 | ATIRadeonX1000::clearInGART |
| 1.22 | 1.03 | 24 | ATIRadeonX1000::pageOnPCIeGART() |
| 1.21 | 1.06 | 363 | ATIR500Surface::copy_buffer_using_DMA |
| 1.21 | 1.09 | 630 | ATIR500Surface::resolve_fsaa_buffer |
| 1.21 | 1.14 | 1005 | pcl_CopyPix [hand H2] |
| 1.21 | 1.21 | 22 | IOATIR500Shared::free_buf_handle |
| 1.20 | 1.14 | 919 | __Z11pcl_CopyPixPmP16pcl_ParamsR500_tbb |
| 1.18 | 1.08 | 216 | ATIRadeonX1000::SWDSInit() |
| 1.18 | 1.08 | 353 | ATIRadeonX1000::SWDSInit [hand H2] |
| 1.18 | 1.18 | 13 | IOATIR500DVDContext::get_status(unsigned long*) |
| 1.17 | 1.07 | 58 | ATIR500DVDContext::write_regs(unsigned long, unsigned long) |
| 1.17 | 1.00 | 6 | IOATIR500DVDContext::add_texture_to_stream(VendorTextureBuffer*) |
| 1.16 | 1.02 | 94 | ATIRadeonX1000::SWDSShutdown() |
| 1.16 | 1.03 | 62008357 | ATIRadeonX1000::submit_idct_buffer_consumed [hand H2 fifo overflow] |
| 1.16 | 1.03 | 63000177 | ATIRadeonX1000::submit_buffer_retired [hand H2 fifo overflow] |
| 1.15 | 1.15 | 341 | ATIR5002DContext::submit_context_buffer |
| 1.15 | 1.15 | 13 | IOATIR500Surface::is_surface_size_supported H3 |
| 1.14 | 1.14 | 53 | IOATIR500Surface::alloc_surfaces_retry(unsigned long, eLockType) |
| 1.13 | 1.00 | 318 | ATIRadeonX1000::submit_ring_data [hand H2] |
| 1.13 | 1.00 | 106 | ATIRadeonX1000::shutdownPCIeGART() |
| 1.13 | 1.03 | 59 | ATIR5002DContext::write_2_regs |
| 1.13 | 1.13 | 61 | IOATIR500Surface::alloc_surface(unsigned long, bool) |
| 1.13 | 1.13 | 330 | IOATIR500Accelerator::stop |
| 1.13 | 1.11 | 195 | ATIRadeonX1000::addToPCIeGART |
| 1.13 | 1.13 | 39 | IOATIR500Surface::remove_2d_context_from_list(IOATIR5002DContext*) |
| 1.13 | 1.13 | 56 | IOATIR500Surface::alloc_surface buffers H3 |
| 1.13 | 1.13 | 38 | ATIRadeonX1000::disable_GPUSensor [hand H2] |
| 1.12 | 1.00 | 199 | ATIRadeonX1000::start_xdct_engine() |
| 1.12 | 1.03 | 64 | ATIRadeonX1000::reserveInGART [hand H2] |
| 1.12 | 1.12 | 14 | IOATIR500DVDContext::get_surface_size |
| 1.12 | 1.12 | 52 | IOATIR500Shared::free_handles() |
| 1.12 | 1.12 | 26 | ATIRadeonX1000::enable_GPUSensor() |
| 1.11 | 1.11 | 39 | ATIRadeonX1000::enable_GPUSensor [hand H2] |
| 1.11 | 1.06 | 444 | ATIRadeonX1000::set_display_mode_and_vram |
| 1.11 | 1.11 | 47 | IOATIR500DVDContext::finish |
| 1.10 | 1.10 | 59 | IOATIR500Accelerator::addOrphanTexture |
| 1.10 | 1.10 | 59 | IOATIR500Surface::alloc_surface_keep(IOATIR500Surface*, VendorTextureBuffer**, long, unsig |
| 1.10 | 1.10 | 58 | IOATIR500Surface::alloc_surface_keep buffers H3 |
| 1.10 | 1.10 | 59 | IOATIR500Accelerator::freeCommandBuffer |
| 1.10 | 1.10 | 20 | IOATIR500Accelerator::unmapVendorTransferBuffer |
| 1.10 | 1.10 | 224 | ATIR500Memory::add_to_stack() |

## What is left (non-GL functions still above 1.10 after this branch; all pass difftest)

Absolute cost is small for nearly all of them (estimated cycles per call in the table above). The remaining causes, with the evidence:

1. **Volatile object-field accessors.** `M<T>(self + kClass_field)` is a `volatile` lvalue, so gcc emits every access the Ghidra text spells (the shipped code is plain member access: fields stay in registers, repeated stores fold).
   Measured on `IOATIR500Accelerator::stop`: 258 instructions (`lwz` 86) with `M<>`, 241 (`lwz` 69) with a non-volatile `F<T>` accessor for the `self + k...` forms, shipped 232 (`lwz` 63).
   Affects `IOATIR500Accelerator::stop` (1.13), `ATIR5002DContext::submit_context_buffer` (1.15), `attach_buffer_backing_store`, `alloc_surface*`, `remove_*_context_from_list`, `ATIR500Memory::add_to_stack` ...
   NOT changed here: it is a policy change for every file (a polled object field would be hoisted out of its loop by gcc, as it would have been in the shipped source if that field were not declared volatile there) and it needs a per-function review of polling loops.
2. **Register images built with bitfields in the shipped source.** The shipped code uses `rlwimi` (insert field) where the decompile has `a & m | b & n | ...` that gcc 4.0.1 does not turn into `rlwimi`: `SWDSInit` (rlwimi 7 vs 0), `SWDSWriteBlitToCmdBuf` (23 vs 0), `shape_surface` (18 vs 0), `build_swap` (22 vs 0), `pcl_CopyPix` (7 vs 0). Matching it needs the real bitfield structs (the register layouts), not a mechanical rewrite.
3. **`pcl_CopyPix` 1.14**: after the float/divide/byte-swap fixes the remainder is extra `lwz`/`stw` (79 vs 49 loads) from volatile reads of the parameter block that the shipped code reads once, plus 7 `rlwimi`.
4. **Tiny functions** (`set_dvd_context`, `get_status`, `is_surface_size_supported`, `free_buf_handle`, `get_surface_size`, `enable/disable_GPUSensor`): 2-5 estimated cycles per call, caused by `nop` padding gcc inserts for the G5 dispatch groups after a volatile access; the shipped build has them elsewhere. Not worth source distortion.

## Behaviour differences found along the way (fixed)
* The dummy `lwzx` of the flushed line after `dcbf; sync; isync` was missing in 9 flush sequences (`flush_memory_for_out`, `submit_ring_data` x3, `submit_buffer`, `submit_buffer_retired`, `submit_idct_buffer_consumed` x2, `pageoff_dirty_texture_with_cpu`); `ATIRadeonX1000::start` had been fixed earlier (#187).
* ~40 unsigned divisions where the shipped code divides signed (different result when the dividend has the high bit set).
