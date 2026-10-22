# GLDriver: the GL context (`ctx`) and the state-update layer

Recovered from the corpus (`part_*.c`), the kext sources (kernel side of the same protocol) and the register headers. Every field has a row in
`fields_gld.tsv` with tier and evidence; `apply_fields.py` turned the numeric offsets into `GLD_<name>` constants (`gld_ctx_fields.h`), which
leaves the compiled objects byte-identical (`verify_names.sh`: IDENTICAL). Tiers: CONFIRMED = another artifact fixes the meaning (kernel source,
documented register, API enum, a malloc/free pair); INFERRED = clear from use, nothing names it.

## 1. `ctx` is not one structure

The name `ctx` was given by earlier rounds to the first parameter of many functions. Three different objects hide behind it:

| object | where | evidence |
|---|---|---|
| **GLDContext** (`malloc(0x2b98)` in `_gldCreateContext`) | the 94 functions in `gld_scope.txt` (`_gld*` entry points and their helpers, addresses below 0x3d600) | allocated and filled by `_gldCreateContext`; the only object with an `IOConnect` handle at +4 |
| **ARB program assembler context** | 35 token emitters `FUN_00065ea0..FUN_0006ec10` and `FUN_00083e10..FUN_000864e0` (called only through the table at the `nl_symbol_ptr` section) | `ctx+0x758` capacity, `ctx+0x75c` token buffer, `ctx+0x3d4` allocator vtable (alloc at +0xc, free at +0x18): growable `uint` token vector; not a GLDContext |
| **GLSL compiler / optimizer object** | the 0x17xxxx..0x18xxxx and 0x4xxxx.. `ctx`-named functions that dereference `+0xb0` and `+0x238` | `+0xb0` is read 562 times and never written outside constructors; `+0x238` is a pointer in the compiler, but the *retire counter* in GLDContext |

Do not apply GLDContext field names outside `gld_scope.txt`. `ctx+0x238` and `ctx+0xb0` mean different things in the two worlds.

## 2. Kernel connection and memory maps

`_gldCreateContext` opens the renderer service (`IOServiceOpen(library->services[ctx->rendererIndex], ...)`, optional `IOConnectAddClient` for a
shared context), reads the hardware config (kernel selector 3), then maps five client memories. The type numbers are the `clientMemoryForType`
cases of `Sources/IOATIR500GLContext_clientMemoryForType_Port.cpp`:

| type | user fields | kernel meaning | user use |
|---|---|---|---|
| 0 | `retireCounter` +0x238 (options 0x101) | accelerator+0xac descriptor | little-endian 32-bit retired stamp; `FUN_0001a0d0` tests `stamp - retired < 1` |
| 1 | `ringMap` +0x1e4 / `ringMapSize` +0x1e8 | command buffer | the packet ring: `+0x10` free words, `+0x18` current stamp, `+0x1c` first header word, `+0x20` first packet |
| 2 | `contextBufferMap` +0x208 / `ctx+0x20c` | context buffer (0x8000 bytes) | word `+0xc` = words used; refilled through selector 18 |
| 4 | `statusRegion` +0x218 / `ctx+0x21c` | status region (grows x2) | 8-byte entries `{stamp, pending}` indexed by fence id |

Kernel selectors the user side calls (`kGLRegularMethods`): 0 set_surface (`_gldAttachDrawable`), 1 set_swap_rect (pname 200/0xc9),
2 set_swap_interval (pname 0xde/0xcb), 3 get_config, 4 get_status, 5 get_surface_size, 6 get_surface_info, 8 finish (`_gldFinish`),
9 wait_for_stamp (`_gldFinishObject`, FUN_00009bd0), 10 new_texture, 11 delete_texture, 12 become_global_shared (pname 0x124),
14 scale_surface (pname 0x12a), 15 purge_texture, 16 set_surface_volatile_state (pname 0x132), 17 reclaim_resources
(`_gldReclaimContext`), 18 get_data_buffer, 19 set_stereo (pname 0x1f96).

## 3. The packet ring

`lastHeader` (+0x1d8), `writeCursor` (+0x1dc), `ringLimit` (+0x1e0), `ringMap` (+0x1e4). A packet builder reserves space (`writeCursor + N <=
ringLimit`, else `FUN_0001a0f0(ctx, 0x1000000)` submits), writes its words, then OR-s the length in words into the previous header
(`*lastHeader |= (new - lastHeader) >> 2`) and makes the new packet the last header. Submit (`FUN_0001a0f0`) closes the ring with the
terminator word (0x01000000), publishes `(ringLimit - cursor) + (reserveEnd - reserveStart) + 0x25` free words, re-maps the ring (type 1),
restarts at `ringMap + 0x20` (after the 0x13d6 preamble packet when `hasPreamble`), and bumps `submitEpoch`. `_gldFlush` submits when
`writeCursor > ringMap + 0x28`; `_gldFinish` submits and then spins on kernel selector 8.

An embedded stream object lives at +0x240 (`commandStream`); its allocate callback is at +0x2998 (`streamAllocate(commandStream, nWords)`) and its
set-current callback at +0x299c, with the current pointer at +0x298c and a soft limit at +0x2994 (`writeCursor + 0x6000` words).

Packet word conventions seen in the builders: register-write pairs are `(register id, value)` where the id is the register byte offset / 4
(0x1393 = RB3D_DSTCACHE_CTLSTAT 0x4e4c, 0x5c8 = 0x1720 ...); an id with bits 16+ set is a count (`0x11004` = two values starting at 0x1004);
type words: `0x33000000` register list, `0x35000000` textured-draw setup (carries a 0x2f4-byte memcpy of the hardware context shadow),
`0x3a000000` stream split (`FUN_0001dff0`), `0x34000000` fence signal (`FUN_0001a670`: `{0x34000000, fenceId}`), `0x44000000` upload descriptor.

## 4. Register shadows (+0x1c8c .. +0x2588)

The four state packet builders (`FUN_000369f0`, `FUN_00034200`, `FUN_00028350`, `FUN_0002a3d0`) re-emit the driver's state by copying
`ctx` words into register-write pairs. Pairing each word with the id written next to it (and checking all four builders against each
other) names the shadow of 46 registers, e.g. `GLD_sc_edgerule` (+0x1cfc, id 0x10ea), `GLD_zb_cntl` (+0x1ce0), `GLD_vap_clip_cntl` (+0x1db4),
`GLD_us_out_fmt_0..3` (+0x257c..), the texture arrays `GLD_tx_filter0/1`, `GLD_tx_format0/1/2` (16 words each, stride 0x40), and the two
pointers `GLD_vap_prog_stream_cntl_0_ptr` / `_ext_0_ptr` (+0x2680/+0x2684) into the embedded arrays at +0x2630/+0x2650. Names come from
`Headers/ATIRadeonX1000Registers.h` where it has the register (CONFIRMED) and from `R3xx_3D_Registers.pdf` otherwise (INFERRED). 28 locals in
those builders are named after the field they copy (`names_R4_shadow.tsv`).

## 5. The layout (GLDContext, 0x2b98 bytes)

Fields named in `fields_gld.tsv` (offset, name, tier). Gaps are unknown.

| off | name | tier | | off | name | tier |
|---|---|---|---|---|---|---|
| 0x00 | rendererIndex (not a macro: `*ctx`) | CONFIRMED | | 0x1d8 | lastHeader | CONFIRMED |
| 0x04 | connect | CONFIRMED | | 0x1dc | writeCursor | CONFIRMED |
| 0x08 | cacheLineSize | INFERRED | | 0x1e0 | ringLimit | CONFIRMED |
| 0x0c | mutex | CONFIRMED | | 0x1e4 / 0x1e8 | ringMap / ringMapSize | CONFIRMED |
| 0x10 | engineState | INFERRED | | 0x1ec / 0x1f0 | reserveStart / reserveEnd | INFERRED |
| 0x14 | capsBlock | INFERRED | | 0x1f4..0x204 | dataCursor, dataLimit, dataBase, dataBufferId, dataRefillCount | INFERRED |
| 0x18 | engineObjects | INFERRED | | 0x208 / 0x20c | contextBufferMap / Size | CONFIRMED |
| 0x1c | dispatchTable | INFERRED | | 0x210 / 0x214 | vertexChunkList / Count | INFERRED |
| 0x24, 0x28 | hwConfig0, hwConfig1 | CONFIRMED | | 0x218 / 0x21c | statusRegion / Size | CONFIRMED |
| 0x3c | drawableFlags | INFERRED | | 0x220 | fenceBitmap | CONFIRMED |
| 0x40..0x7c | stateCopy | INFERRED | | 0x224..0x234 | queryPool, queryPoolBytes, queryBitmap, queryCapacity, queryRecord | INFERRED/CONFIRMED |
| 0xf8..0x108 | attachedDrawable, drawableIdHigh/Low, drawableWidth/Height | CONFIRMED/INFERRED | | 0x238 | retireCounter | CONFIRMED |
| 0x124..0x130 | swapRectX/Y/Width/Height | CONFIRMED | | 0x23c | submitEpoch | INFERRED |
| 0x134..0x13c | scaleFlags, scaleX, scaleY | CONFIRMED | | 0x240 | commandStream | INFERRED |
| 0x141..0x147 | softwareBufferFormat, swapIntervalNumerator/Denominator, swapRectEnabled, scaleEnabled, surfaceVolatile | mixed | | 0x298c..0x299c | streamCurrent, streamSoftLimit, streamAllocate, streamSetCurrent | INFERRED/CONFIRMED |
| 0x148 / 0x14c | softwareBuffer / Size | CONFIRMED | | 0x2b7e | hasPreamble | CONFIRMED |
| 0x150 | boundFramebuffer | CONFIRMED | | 0x2b90 / 0x2b94 | listSelf / listNext | CONFIRMED |
| 0x154..0x160 | renderFlags, renderBufferMask, renderWidth, renderHeight | INFERRED | | 0x1c8c..0x2588 | register shadows (section 4) | CONFIRMED/INFERRED |
| 0x178 | lastError | CONFIRMED | | | | |
| 0x18c..0x1a8 | unitObject0..7 | INFERRED | | | | |
| 0x1cc | currentProgram | INFERRED | | | | |
| 0x1d4 | currentVertexArray | CONFIRMED | | | | |

Still unnamed (seen, role unproven): +0x20 (byte read by `_gldAllocVertexBuffer`, `_gldUpdateDispatch`), +0x21 (set by pname 0x29a, 1 - (v == 0)),
+0x30..+0x38 and +0x11c/+0x120/+0x164..+0x188 (initialised by `_gldCreateContext`, copied by `_gldAttachDrawable`), +0x143 (set to 1 when the drawable
is not a pbuffer), the dirty-bit words `_gldUpdateDispatch` uses (+0x26b8 per-unit flag mask, +0x26bd/+0x2a43/+0x2a44/+0x2a69 flag bytes,
+0x26c0/+0x26c4/+0x26c8 dirty accumulators, +0x29c0/+0x29dc/+0x29e8/+0x29ec/+0x29fc), +0x2a54/+0x2a58 (pixel zoom x/y as floats, read by
glBitmap), +0x2b7c (y axis inverted: set to 1 when the drawable is not a pbuffer), +0x2a80 (swap-interval override).

## 6. Neighbouring structures

* **capsBlock** (`ctx+0x14`, 5th `_gldCreateContext` argument): `FUN_00017750` fills it with the renderer limits (max texture size 0x1000,
  two limits of 0x20, a float pair 1.0 and 64.0, the DXT enums 0x83f0..0x83f3, ...). Word 0 bit 1 follows the drawable type; byte +0x26 follows
  stereo (`_gldSetInteger` 0x1f96).
* **engineObjects** (`ctx+0x18`): texture bindings `[16 units][5 targets]` at +0 (20 bytes per unit; targets in the order cube map, 3D,
  rectangle, 2D, 1D from `_gldSetInteger` pname 0x29c), +0x190..0x1a0 per-unit slots, +0x194 current vertex array, +0x19c current program.
* **engineState** (`ctx+0x10`, the GL engine's own state): pixel-store state read by glBitmap/glDrawPixels at +0x2e6c row length, +0x2e74 skip
  rows, +0x2e78 skip pixels, +0x2e80 alignment, +0x2e84 swap bytes, +0x2e85 LSB first (the GL_UNPACK_* set, INFERRED from the unpack loops);
  +0x2e0a (fog enabled) and +0x2de0..+0x2dec (fog colour RGBA, floats) from the colour blend in glBitmap.
* **ring map header** (`ringMap`): +0x10 free words, +0x18 stamp, +0x1c first header, +0x20 first packet.

## 7. Functions identified

| function | role | basis |
|---|---|---|
| `FUN_0001a0f0` | submit the ring | terminator 0x01000000, re-map type 1, stamp/epoch bookkeeping |
| `FUN_0001a0d0` | retire test (`stamp - retired < 1`) | reads `retireCounter` |
| `FUN_0001a670` | signal a fence | writes `{0x34000000, id}`, marks `statusRegion[id]` pending |
| `FUN_0001dff0` | start a new packet in the stream | `streamAllocate`, header link, 0x3a000000 |
| `FUN_00016670` | glBitmap through point/quad vertices | unpack loops, zoom, raster colour, y-inversion; named in `names_R4_bitmap.tsv` |
| `FUN_00016fc0` | draw/read buffer enum -> internal buffer index | 0x400..0x40b |
| `FUN_00017160` | update drawable flags from a pbuffer target | 0xde0/0xde1/0x84f5/0x8513 (1D/2D/rectangle/cube map) |
| `FUN_00017100` | swap-interval override for pnames 0xcb/0xde | `ctx+0x2a80` |
| `FUN_00017750` | fill the renderer limits block | constants listed above |
| `FUN_00017a40` | fold pixel-format depth/stencil bits into the flags | |
| `FUN_00007020` | drop the attached drawable and the renderer connection use count | |
| `FUN_00009b70`, `FUN_00009bd0`, `FUN_00009cd0`, `FUN_00009d70` | query record allocation / wait / growth | `_gldCreateQuery` |
| `FUN_000369f0` | texture sub-image upload through the 3D engine: copy into the staging buffer (byte-swap modes 0..3), then a 0x35000000 textured-quad packet | selector 18 refills, staging cursor |
| `FUN_00028350`, `FUN_0002a3d0` | glDrawPixels / glReadPixels class pixel transfers (state packets as above) | shared packet builders |

## 8. Method notes

* Field offsets: scripted over every `ctx + N`, `ctx[N]`, `(int)ctx + N` and the hoisted `((unsigned char *)0xN)[ctx]` forms; a word-pointer `ctx`
  (`int *ctx` in `_gldAttachDrawable`, `_gldCreateContext`'s local) is scaled by 4. The first version skipped statement lines that start with `*(`
  because it took them for comment lines; corrected.
* Registers: pair detection (`value` follows `reg id`, or follows a count header) validated across four independent builders.
* `names_R4_shadow.tsv`, `names_R4_copies.tsv`, `names_R4_bitmap.tsv`, `names_R4_misc.tsv`: row sources; `find_webs.py` now also parses
  wrapped `if (...)` conditions (`if (cond)` with the body or the brace on the next line).

## 8. Fork X additions (state update, pixel transfer, texture upload, program constants)

**Dirty-bit protocol (`_gldUpdateDispatch`).** The `dirtyBits` argument is five words: word 0 (bit 31 = full validate, 0x80/0x100 framebuffer changes),
word 1 (low 16 bits = texture units to re-resolve), words 2 and 3 (program, framebuffer, vertex-program mode: 0x5400000, 0x4500000, 0x10000000), word 4.
Pending bits accumulated since the last validate live in `ctx+0x26c0` (word 2), `ctx+0x26c4` (word 3) and `ctx+0x26c8` (update flags). For every dirty unit
the bound texture is found in `engineObjects[unit row (stride 0x14)][target]` (first target whose enable bit in the engine state record, stride 0x7c, is set;
5 targets: cube map, 3D, rectangle, 2D, 1D), made complete with FUN_00032100 when its flags say so, and the unit object `ctx+0x18c+unit*4` is set to it
(or 0); `ctx+0x26b8` collects the units whose texture was modified and FUN_000a7ee0 applies them. The function then rewrites the dispatch table
(`param_2`: +0x18..+0x3c entry points chosen by the program flag, +0x58/+0x5c/+0x60 finish/flush/clear chosen by the render flags) and returns 4 + flags.

**Pixel transfer and texture functions identified (basis in brackets):**

| function | role | basis |
|---|---|---|
| `FUN_00029290`, `FUN_00029294` | glReadPixels (two decompiles of the same code, entry stub at 0x29290) | GL enums 0x1901/0x1902/0x80e1, kernel selector 7 with a 7-word request {x, y, w, h, format, address, pitch}, scratch buffer at +0x2b74 |
| `FUN_00028350` | read-back through a textured blit into a client-memory surface (`surfaceInfo`) | RGBA/float special case, 0x35000000 setup packet, float rectangle clip, 32-byte alignment test |
| `FUN_00018a40` | glDrawPixels with pixel zoom | raster position, zoom factors, `_glgPixelCenters`, 0x7fe-wide tiles handed to FUN_00029c00 |
| `FUN_0002a3d0` | draw from a client-memory surface | same packet as FUN_00028350 with the unpack state (+0x2e6c) and a raster origin |
| `FUN_000369f0` | glTexSubImage-style upload | hardware chunk upload (0x44000000 packet, 0x1e000-byte chunks), textured-quad path (0x35000000) and surface-to-texture copy (`sourceSurface`) |
| `FUN_00034200` | glGenerateMipmap | 0x37000000 packet, per-level quads with half-texel bias 1/128, halves width/height/depth per pass |
| `FUN_0001ecd0` | vertex-array draw (DrawArrays/DrawElements) | primitive mode switch (1/8 even, 4 triangles, 7 quads), index types 0x1401/0x1403/0x1405, 0x39000000 packet |
| `FUN_00024fe0`, `FUN_0003b870`, `FUN_0003d590` | fill the program constant table from operand descriptors | operand word: bits 16..20 file (1 literal pool, 2 environment, 3 state), state groups with strides 0x80 / 0x240, matrices at +0x1860/+0x1e60 |
| `FUN_0003c400` | translate a shader object into a hardware program | target enum 0x8b30/0x8b31, per-instruction opcode field >>0x12 & 0xff |

**Engine state (`ctx+0x10`) offsets used by these functions** (INFERRED unless a kernel/GL name fixes them): +0x2e48/+0x2e4c pixel zoom x/y (floats),
+0x2e6c.. unpack state (row length, skip rows/pixels, alignment, swap bytes +0x2e84, LSB first +0x2e85), +0x2e50 pack state, +0x2db8 read buffer enum,
+0x2d66/+0x2d84/+0x2ddc/+0x2dc8/+0x2e0a/+0x2e33 enable bytes read when rebuilding `drawPixelsFlags`, +0x30b0/+0x30b4 framebuffer-object attachment flags,
+0x31d4 + unit*0x7c target enable bits, +0x4308/+0x4310 program environment/local parameter arrays, +0x24c0..+0x24f8, +0x28c0 state parameter blocks.

**ARB program assembler (`arb_scope.txt`, prefix `ARB_`).** The 38 emitters keep an instruction array (`instrArray` +0x3c8, `instrCount` +0x3cc,
`currentInstr` +0x3dc, `instrCapacity` +0x3e0, 0x10-byte records) and a token stream (`tokenCount` +0x754, `tokenCapacity` +0x758, `tokenBuffer` +0x75c), both
grown with `allocator` (+0x3d4: alloc at +0xc, free at +0x18). The emitter parameters follow one layout: dst (file, index, write mask[4]) then per source
(file, index, select[4], negate[4]); the files are 6-bit, indexes 16-bit, and a source packs 3-bit selects and 1-bit negates into one swizzle word.
