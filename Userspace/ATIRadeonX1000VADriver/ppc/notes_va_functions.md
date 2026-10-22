# ATIRadeonX1000VADriver: what the 116 `FUN_` functions are

Fork V1. The bundle has four exports (`_AVACreateRenderer`, `_AVACreateRendererDVDExt`, `_AVACreateRendererDisplayExt`, `_AVAGetRendererInfo`), no RTTI
and no useful strings, so every name below rests on structure. The evidence column says which kind. Names are ours (`ava_<role>`); tier CONFIRMED means
the role is proven by something external to our reading (a kernel selector number, a quoted string, byte-identical code to a symbol-named function in
another binary, address arithmetic); INFERRED is our reading of what the function does; UNKNOWN is a descriptive placeholder.

## How the evidence was gathered

1. **Function-pointer tables.** `_AVACreateRenderer` fills a 0x64-byte renderer record; the slots are `PTR_FUN_0000f130..f198`, which are `__nl_symbol_ptr`
   entries (0xf124..) holding local function addresses. Resolved slot -> function: +0x10 `ava_create_context`, +0x14 `ava_destroy_context`,
   +0x18 `ava_check_stamps`, +0x1c `ava_wait_for_stamps`, +0x20/+0x24 `ava_get_property`/`ava_set_property`, +0x28/+0x2c `ava_get_attribute`/`ava_set_attribute`,
   +0x34 `ava_decode_picture`, +0x38 `ava_queue_display`, +0x3c `ava_setup_decode`, +0x40 `ava_declare_surface_images`, +0x44 `ava_get_surface_descs`,
   +0x48 `ava_get_image_descs`, +0x4c `ava_new_handle`, +0x50 `ava_slot20_enqueue`, +0x54 `ava_get_frame`, +0x58 `ava_destroy_renderer`.
   DVDExt (0x20 bytes): +8 `ava_setup_subpicture`, +0xc `ava_display_subpicture`, +0x10 `ava_dvd_ext_emit_packet_0d`, +0x14 `ava_release_subpicture`,
   +0x18 `ava_set_macrovision`. DisplayExt (0x1c bytes): +8 `ava_display_refresh`, +0xc `ava_render_slot`, +0x10/+0x14 two no-op slots.
2. **Kernel selectors.** The DVD user client's table (Headers/IOATIR500DVDContext.h: 0 set_surface, 1 get_config, 2 get_status, 3 get_surface_size,
   4 lock_all_buffers, 5 unlock_memory, 6 write_buffer, 7 finish, 8 declare_image, 9 delete_image, 10 show_buffer, 11 dvd_setup_overlay,
   12 dvd_enable_overlay, 13 read_regs, 14 write_regs, 15 dvd_setup_subpicture, 16 set_macrovision, 17 dvd_enable_deint, 18 doIDCT,
   19 wait_for_stamps, 20 check_stamps, 21 setup_buffers) names the wrappers that call a selector with a literal.
3. **The AppleVA side.** `Tools/userspace/va_capture/ava_drive.c` drives `DVDDriverOpenDeviceImpl/DecodeImpl/CloseDeviceImpl/GetFrameImpl` of
   AppleVA.framework, which call this renderer; its descriptor layout and pixel formats match `ava_decode_picture` and `ava_get_frame`.
4. **Command-stream idioms.** Ring cursor ctx+0x30/+0x34/+0x38 (same protocol as GLDriver's notes_gl_context.md, section 3), packet words decoded as
   R500 register ids (byte offset / 4: 0x1095 = GA_US_VECTOR_DATA 0x4254, 0x1002 = GB_ENABLE, 0x1040 = TX_INVALTAGS, 0x10c0 = RS_COUNT) and type-3
   packets (0xc0103500 = PACKET3 opcode 0x35, 3D_DRAW_IMMD_2). Many "tagged" packets `0xNN000000` are VA-specific.
5. **Byte-shape match.** The C-runtime shims (0x1070..0x20d4) are instruction-for-instruction identical (branch targets and D-form immediates masked)
   to the symbol-named atexit/dyld functions of the GA binary (and of GLDriver); the 32-byte `mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr` functions
   are PIC jump thunks whose target is computed from the displacement (an import's picsymbolstub1 entry, or a local function).

## Not named

`FUN_0000cf98`, `FUN_0000cfa4`, `FUN_0000cfa8`, `FUN_0000cfe8`: empty functions (return only) after the code, 12/4/24/44 bytes; no role evidence.

## Table

| address | old name | new name | tier | evidence |
|---|---|---|---|---|
| 0x1070 | FUN_00001070 | `dyld_stub_binding_helper` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function dyld_stub_binding_helper in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x10a0 | FUN_000010a0 | `__dyld_func_lookup` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function __dyld_func_lookup in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x10c0 | FUN_000010c0 | `_cxa_atexit_check_2` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _cxa_atexit_check_2 in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x10e8 | FUN_000010e8 | `_cxa_atexit_check_1` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _cxa_atexit_check_1 in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x1160 | FUN_00001160 | `_check_cxa_atexit` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _check_cxa_atexit in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x122c | FUN_0000122c | `_find_atexit_10_3` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _find_atexit_10_3 in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x1424 | FUN_00001424 | `pic_jump_strcmp_1424` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd100 = picsymbolstub1 entry 7 (lazy pointer of _strcmp) and jumps to it |
| 0x1444 | FUN_00001444 | `pic_jump_dyld_func_lookup_1444` | CONFIRMED | PIC jump thunk: computes 0x10a0 and jumps to the local function FUN_000010a0 |
| 0x1464 | FUN_00001464 | `_get_globals` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _get_globals in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x1674 | FUN_00001674 | `pic_jump_keymgr_set_and_unlock_processwide_ptr_1674` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd0a0 = picsymbolstub1 entry 4 (lazy pointer of __keymgr_set_and_unlock_processwide_ptr) and jumps to it |
| 0x1694 | FUN_00001694 | `pic_jump_check_cxa_atexit_1694` | CONFIRMED | PIC jump thunk: computes 0x1160 and jumps to the local function FUN_00001160 |
| 0x16b4 | FUN_000016b4 | `pic_jump_dlsym_16b4` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd0c0 = picsymbolstub1 entry 5 (lazy pointer of _dlsym) and jumps to it |
| 0x16d4 | FUN_000016d4 | `pic_jump_find_atexit_10_3_16d4` | CONFIRMED | PIC jump thunk: computes 0x122c and jumps to the local function FUN_0000122c |
| 0x16f4 | FUN_000016f4 | `pic_jump_dlopen_16f4` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd020 = picsymbolstub1 entry 0 (lazy pointer of _dlopen) and jumps to it |
| 0x1714 | FUN_00001714 | `pic_jump_calloc_1714` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd0e0 = picsymbolstub1 entry 6 (lazy pointer of _calloc) and jumps to it |
| 0x1734 | FUN_00001734 | `pic_jump_keymgr_get_and_lock_processwide_ptr_1734` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd060 = picsymbolstub1 entry 2 (lazy pointer of __keymgr_get_and_lock_processwide_ptr) and jumps to it |
| 0x1754 | FUN_00001754 | `_add_routine` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _add_routine in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x1860 | FUN_00001860 | `pic_jump_keymgr_set_and_unlock_processwide_ptr_1860` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd0a0 = picsymbolstub1 entry 4 (lazy pointer of __keymgr_set_and_unlock_processwide_ptr) and jumps to it |
| 0x1880 | FUN_00001880 | `pic_jump_malloc_1880` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd040 = picsymbolstub1 entry 1 (lazy pointer of _malloc) and jumps to it |
| 0x18a0 | FUN_000018a0 | `_run_routines` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _run_routines in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x19c4 | FUN_000019c4 | `pic_jump_keymgr_get_and_lock_processwide_ptr_19c4` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd060 = picsymbolstub1 entry 2 (lazy pointer of __keymgr_get_and_lock_processwide_ptr) and jumps to it |
| 0x19e4 | FUN_000019e4 | `pic_jump_free_19e4` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd080 = picsymbolstub1 entry 3 (lazy pointer of _free) and jumps to it |
| 0x1a04 | FUN_00001a04 | `pic_jump_keymgr_set_and_unlock_processwide_ptr_1a04` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd0a0 = picsymbolstub1 entry 4 (lazy pointer of __keymgr_set_and_unlock_processwide_ptr) and jumps to it |
| 0x1a24 | FUN_00001a24 | `_cxa_atexit_wrapper` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _cxa_atexit_wrapper in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x1b5c | FUN_00001b5c | `pic_jump_run_routines_1b5c` | CONFIRMED | PIC jump thunk: computes 0x18a0 and jumps to the local function FUN_000018a0 |
| 0x1b7c | FUN_00001b7c | `pic_jump_keymgr_set_and_unlock_processwide_ptr_1b7c` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd0a0 = picsymbolstub1 entry 4 (lazy pointer of __keymgr_set_and_unlock_processwide_ptr) and jumps to it |
| 0x1b9c | FUN_00001b9c | `pic_jump_keymgr_get_and_lock_processwide_ptr_1b9c` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd060 = picsymbolstub1 entry 2 (lazy pointer of __keymgr_get_and_lock_processwide_ptr) and jumps to it |
| 0x1bbc | FUN_00001bbc | `_our_atexit` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _our_atexit in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x1c78 | FUN_00001c78 | `pic_jump_keymgr_set_and_unlock_processwide_ptr_1c78` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd0a0 = picsymbolstub1 entry 4 (lazy pointer of __keymgr_set_and_unlock_processwide_ptr) and jumps to it |
| 0x1c98 | FUN_00001c98 | `pic_jump_run_routines_1c98` | CONFIRMED | PIC jump thunk: computes 0x18a0 and jumps to the local function FUN_000018a0 |
| 0x1cb8 | FUN_00001cb8 | `pic_jump_keymgr_get_and_lock_processwide_ptr_1cb8` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd060 = picsymbolstub1 entry 2 (lazy pointer of __keymgr_get_and_lock_processwide_ptr) and jumps to it |
| 0x1cd8 | FUN_00001cd8 | `_atexit_common` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _atexit_common in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x1f78 | FUN_00001f78 | `pic_jump_malloc_1f78` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd040 = picsymbolstub1 entry 1 (lazy pointer of _malloc) and jumps to it |
| 0x1f98 | FUN_00001f98 | `pic_jump_keymgr_set_and_unlock_processwide_ptr_1f98` | CONFIRMED | PIC jump thunk (mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr): computes 0xd0a0 = picsymbolstub1 entry 4 (lazy pointer of __keymgr_set_and_unlock_processwide_ptr) and jumps to it |
| 0x1fb8 | FUN_00001fb8 | `pic_jump_add_routine_1fb8` | CONFIRMED | PIC jump thunk: computes 0x1754 and jumps to the local function FUN_00001754 |
| 0x1fd8 | FUN_00001fd8 | `pic_jump_get_globals_1fd8` | CONFIRMED | PIC jump thunk: computes 0x1464 and jumps to the local function FUN_00001464 |
| 0x1ff8 | FUN_00001ff8 | `___cxa_atexit` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function ___cxa_atexit in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x2058 | FUN_00002058 | `pic_jump_atexit_common_2058` | CONFIRMED | PIC jump thunk: computes 0x1cd8 and jumps to the local function FUN_00001cd8 |
| 0x2078 | FUN_00002078 | `_atexit` | CONFIRMED | same instruction words (branch targets and D-form immediates masked, same size) as the named function _atexit in the ATIRadeonX1000GA corpus (symbol-table name); the C runtime atexit shim linked into every bundle |
| 0x20d4 | FUN_000020d4 | `pic_jump_atexit_common_20d4` | CONFIRMED | PIC jump thunk: computes 0x1cd8 and jumps to the local function FUN_00001cd8 |
| 0x2340 | FUN_00002340 | `ava_destroy_renderer` | INFERRED | renderer slot 0x16 (+0x58); frees the DisplayExt and DVDExt globals, the info block (renderer+0xc) and the renderer itself |
| 0x2570 | FUN_00002570 | `ava_create_context` | CONFIRMED | renderer slot 4; CGDisplayIDToOpenGLDisplayMask, IOServiceOpen(type 3 = DVD user client, Tools/userspace/va_capture/README), kernel selector 1 (get_config), IOConnectMapMemory types 1/4/5/2, selector 0 (set_surface); AppleVA DVDDriverOpenDeviceImpl returns its context (Tools/userspace/va_capture/ava_drive.c) |
| 0x2930 | FUN_00002930 | `ava_delete_image` | CONFIRMED | io_connect_method_scalarI_structureI selector 9 = IOATIR500DVDContext::delete_image (Headers/IOATIR500DVDContext.h); then frees the backing memory and the record |
| 0x29c0 | FUN_000029c0 | `ava_release_image` | INFERRED | emits packet tag 0x2b+id (7 words 0x80000000) and submits the ring; paired with ava_acquire_image(0x19+id); called as release before ava_delete_image (ava_release_subpicture, ava_get_frame) |
| 0x2b70 | FUN_00002b70 | `ava_destroy_context` | CONFIRMED | renderer slot 5; IOServiceClose(ctx+0x14), frees the 25 plane tables, deletes the images, releases packets 0/1, frees ctx (0x15408 bytes allocated by ava_create_context) |
| 0x2c70 | FUN_00002c70 | `ava_check_stamps` | CONFIRMED | renderer slot 6; kernel selector 0x14 = 20 = check_stamps (Headers/IOATIR500DVDContext.h, Tests/test_deep_t2.c row 9: two stamps in, bothDone out) |
| 0x2d00 | FUN_00002d00 | `ava_wait_for_stamps` | CONFIRMED | renderer slot 7; kernel selector 0x13 = 19 = wait_for_stamps (two stamps in) |
| 0x2d80 | FUN_00002d80 | `ava_get_property` | INFERRED | renderer slot 8: property 3 -> 4, property 4 -> ctx+0x120 (the deinterlace mode set by ava_set_property); anything else -> error |
| 0x2dc0 | FUN_00002dc0 | `ava_set_property` | INFERRED | renderer slot 9; property 4 stores ctx+0x120 and, for value 4, emits ava_emit_deint_enable_packet; slot pair with ava_get_property |
| 0x2e10 | FUN_00002e10 | `ava_get_attribute` | INFERRED | renderer slot 10; identical body to ava_get_property; pairs with ava_set_attribute (slot 11) |
| 0x2e50 | FUN_00002e50 | `ava_set_attribute` | INFERRED | renderer slot 11; attributes 4, 0x17 hue (clamped +-pi), 0x18 saturation (0..3), 0x19 brightness (-1..1), 0x1a contrast (0.25..4), 0x1b (calls ava_render_slot), 0x1c source rectangle; then selectors 0x11 (dvd_enable_deint), 0x15 (setup_buffers), 0 (set_surface), 4 (lock_all_buffers) |
| 0x3350 | FUN_00003350 | `ava_declare_image` | CONFIRMED | kernel selector 8 = IOATIR500DVDContext::declare_image (address, length -> handle); allocates the 0x34-byte image record and the pixel storage; pixel formats yuv2 0x32767579, yuvs 0x79757673, argb 0x61726762, rgba 0x72676261, ar15 0x61723135, 8, 0x20 (the same set ava_get_frame accepts) |
| 0x3630 | FUN_00003630 | `ava_declare_surface_images` | INFERRED | renderer slot 0x10; count must equal ctx+0x54; declares one image per caller surface description (ava_declare_image) and releases them all on failure; stores the descriptions at +0x178.. |
| 0x37b0 | FUN_000037b0 | `ava_get_surface_descs` | INFERRED | renderer slot 0x11; copies words 0..3 and 7 of each per-surface record (ctx+0x55c + 0x38..) into the caller descriptors |
| 0x3830 | FUN_00003830 | `ava_get_image_descs` | INFERRED | renderer slot 0x12; copies back the descriptions ava_declare_surface_images stored at +0x178..+0x194 |
| 0x38c0 | FUN_000038c0 | `ava_new_handle` | INFERRED | renderer slot 0x13; clears the per-slot stamps (+0x56c/+0x570), returns {0, ctx+0xac4} and advances the handle counter modulo 10000 (the same handle protocol as ava_decode_picture) |
| 0x3930 | FUN_00003930 | `ava_decode_picture` | CONFIRMED | renderer slot 0xd; picParams layout equals the descriptor ava_drive.c passes to DVDDriverDecodeImpl (type, picture_structure, alt, dst, fwd, bwd, MB records at +0xc, coefficients at +0x10); emits one macroblock per record (ava_emit_macroblock), then ava_emit_picture_setup_packet / ava_end_picture |
| 0x3cd0 | FUN_00003cd0 | `ava_acquire_image` | INFERRED | emits packet tag 0x19+id (switch on the image id: refcounter at +0x151b4/+0x153bc ...) paired with ava_release_image (0x2b+id) |
| 0x3fc0 | FUN_00003fc0 | `ava_get_frame` | CONFIRMED | renderer slot 0x15 (+0x54): AppleVA DVDDriverGetFrameImpl modes 2 yuvs, 8 yuv2, 16 argb, 32 rgba, 64 ar15 (ava_drive.c); converts the decoded frame into the caller buffer with ava_render_convert_frame / ava_render_convert_frame_yuv2 and the hue/saturation and brightness/contrast passes |
| 0x4280 | FUN_00004280 | `ava_slot20_enqueue` | UNKNOWN | renderer slot 0x14: acquire image (opcodeBase+0xc), a no-op callback, release; returns a new handle; role of arg unknown |
| 0x4340 | FUN_00004340 | `ava_setup_decode` | INFERRED | renderer slot 0xf: sizes (+0x578/+0x57c rounded to 16), per-plane tables, kernel selector 0x15 (setup_buffers) + 0 (set_surface), declares the frame and block images (+0x1518c, +0x15394), builds the stage programs and the block grid |
| 0x4740 | FUN_00004740 | `ava_render_slot` | INFERRED | DisplayExt slot 3: runs the effect passes of a slot (ava_render_hue_saturation_pass, ava_render_brightness_contrast_pass, ava_render_scale_pass) or the deinterlace pass, then submits |
| 0x49f0 | FUN_000049f0 | `ava_noop_49f0` | CONFIRMED | body is a single blr; DisplayExt slot 4 |
| 0x4a00 | FUN_00004a00 | `ava_noop_4a00` | CONFIRMED | body is a single blr; DisplayExt slot 5 |
| 0x4a10 | FUN_00004a10 | `ava_queue_display` | INFERRED | renderer slot 0xe: stores the source and destination rectangles for a surface (+0x13dec.., +0x13e50..), marks it pending (+0x540) and returns a handle |
| 0x4b40 | FUN_00004b40 | `ava_display_refresh` | INFERRED | DisplayExt slot 2: for each surface and field emits packets 0x05/0x06, then ava_render_slot(0) |
| 0x4fa0 | FUN_00004fa0 | `ava_setup_subpicture` | CONFIRMED | DVDExt slot 2; prints "Number of subpicture bitmap exceed the maximum set."; declares the subpicture images, selectors 0x15 and 0 |
| 0x51f0 | FUN_000051f0 | `ava_release_subpicture` | INFERRED | DVDExt slot 5; releases image 3 then deletes the subpicture images (ava_delete_image) |
| 0x5280 | FUN_00005280 | `ava_set_macrovision` | CONFIRMED | DVDExt slot 6; kernel selector 0x10 = set_macrovision with attribute 0x92 and the value (Tests/destructive/t3_dvd_macrovision.c) |
| 0x52f0 | FUN_000052f0 | `ava_display_subpicture` | INFERRED | DVDExt slot 3; packs the palette, flushes it (ava_dcache_flush_range), emits packet 0x0d and runs ava_render_subpicture_pass |
| 0x56a0 | FUN_000056a0 | `ava_dvd_ext_emit_packet_0d` | UNKNOWN | DVDExt slot 4; emits a 0x0d000000 packet with ctx+0x60/+0x64/+0x68 when slotId equals ctx+0x558 |
| 0x58b0 | FUN_000058b0 | `ava_init_context_state` | INFERRED | called by ava_create_context: points the ring cursors at the mapped ring, sets the two IDCT list cursors (+0x1511c/+0x15140), writes the initial state words (setup buffer +0x20.. register-id/value pairs, GB/SU/RS registers) |
| 0x5d60 | FUN_00005d60 | `ava_noop_5d60` | CONFIRMED | body is a single blr |
| 0x5d70 | FUN_00005d70 | `ava_build_block_grid` | INFERRED | builds the packed (y<<16/x) corner words of every 16x16 and 8x8 block of the frame (rows step 16 then 8), stores the section word counts at +0x153fc/+0x15400 |
| 0x5fd0 | FUN_00005fd0 | `ava_submit_idct_list` | CONFIRMED | calls kernel selector 0x12 = doIDCT with the 0x38-byte request struct (issue #140: Tools/userspace/va_capture/va_callsites.txt) |
| 0x6120 | FUN_00006120 | `ava_submit_idct_list_and_remap` | INFERRED | ava_submit_idct_list then IOConnectMapMemory type 4 (list A) or 5 (list B) and resets the list cursors |
| 0x6230 | FUN_00006230 | `ava_build_stage_program` | INFERRED | writes a fragment-program/state word block (US/RS register ids and values) for variant 1 or 2 and a half-height flag |
| 0x6d90 | FUN_00006d90 | `ava_build_stage_programs` | INFERRED | calls ava_build_stage_program for variants 1,2 x half-height 0,1 (ctx+0x15294..) with the frame width/height in float |
| 0x7020 | FUN_00007020 | `ava_emit_stage_programs` | INFERRED | copies the stored stage programs (ctx+0x15294.. lengths +0x15298..) into a command list by mode |
| 0x7270 | FUN_00007270 | `ava_emit_block_table_entries` | INFERRED | copies ranges of 0x18-byte entries from the constant tables at 0xd4ec/0xd5c4, sets bit 0x2000000 on the last, writes them with ava_emit_us_vector_data |
| 0x7490 | FUN_00007490 | `ava_emit_block_packet` | INFERRED | emits a block packet (0xc0003a00 type-3 header with wordCount+5, 0xdeadbeef marker) and the block table entries |
| 0x7760 | FUN_00007760 | `ava_push_reservation_word` | INFERRED | stores one word at the reservation cursor of list 1/3/4; fails and clears the reservation when the list is full |
| 0x7850 | FUN_00007850 | `ava_emit_picture_setup_packet` | INFERRED | emits a 0x12000000 packet (field, picture structure, surfaces ctx+0x568/+0x56c/+0x570) into the main ring |
| 0x7de0 | FUN_00007de0 | `ava_pad_command_lists` | INFERRED | pads both IDCT lists with 0xffff1000 skip packets and a final 0x80000000 / 0xc0001000 packet |
| 0x7f80 | FUN_00007f80 | `ava_end_picture` | INFERRED | submits list A and B (ava_submit_idct_list_and_remap), pads the lists, flushes plane data (ava_dcache_flush_range) and ends the picture |
| 0x83e0 | FUN_000083e0 | `ava_reserve_list_words` | INFERRED | reserves words in list A (ctx+0x1511c) or B (+0x15140); when full submits (ava_submit_idct_list_and_remap, or ava_emit_picture_setup_packet + ava_end_picture) |
| 0x8510 | FUN_00008510 | `ava_emit_macroblock` | INFERRED | writes one macroblock: sums the six block flags, reserves words, writes the header (flag bits, picture structure) and the macroblock address row/column, copies the payload words |
| 0x8690 | FUN_00008690 | `ava_begin_reservation` | INFERRED | records a reservation of wordCount words in list 1/3/4 (start, cursor, end) in the reservation record |
| 0x8800 | FUN_00008800 | `ava_clear_list_marker` | UNKNOWN | stores 0 at *(ctx+0x15164) - 0xc |
| 0x8820 | FUN_00008820 | `ava_emit_mb_motion_vectors` | INFERRED | switch on the macroblock motion type (mbInfo+10): packs the motion vectors (value*0x8000 & 0xffff0000 / ...) of the forward/backward predictions |
| 0x9670 | FUN_00009670 | `ava_get_driver_name` | CONFIRMED | returns the C string "ATIRadeonX1000" |
| 0x9690 | FUN_00009690 | `ava_noop_9690` | CONFIRMED | body is a single blr; called by ava_slot20_enqueue |
| 0x96a0 | FUN_000096a0 | `ava_emit_state_preamble` | INFERRED | writes register ids 0x1002 (GB_ENABLE) and 0x1040 (TX_INVALTAGS) with the 0x10030000 count word |
| 0x9700 | FUN_00009700 | `ava_emit_shader_stage_setup` | INFERRED | writes per-stage register ids 0x101d.. and 0x10c0 (RS_COUNT) and the 0xf688f688 instruction words |
| 0x9930 | FUN_00009930 | `ava_emit_register_data` | INFERRED | copies count data words after a register header word |
| 0x9980 | FUN_00009980 | `ava_emit_us_vector_data` | CONFIRMED | register id 0x1095 = byte offset 0x4254 = GA_US_VECTOR_DATA (Headers/ATIRadeonX1000Registers.h) |
| 0x99b0 | FUN_000099b0 | `ava_emit_shader_constants` | INFERRED | writes two constant blocks through ava_emit_us_vector_data (index 0x10000 and 0) and returns the cursor + 0xe |
| 0x9ac0 | FUN_00009ac0 | `ava_emit_textured_quad` | INFERRED | writes a 0xc0103500 type-3 draw packet (PACKET3 opcode 0x35 = 3D_DRAW_IMMD_2) with the source/destination corner floats |
| 0x9c80 | FUN_00009c80 | `ava_render_hue_saturation_pass` | INFERRED | packet tag 0x42; uses cos/sin of the hue angle for the colour matrix constants; quad draw |
| 0xa110 | FUN_0000a110 | `ava_render_brightness_contrast_pass` | INFERRED | packet tag 0x3f; two constants (brightness/contrast) and a quad draw |
| 0xa4e0 | FUN_0000a4e0 | `ava_render_convert_frame` | INFERRED | packet tag 0x44; frame conversion for yuvs/argb/rgba/ar15 (format code at +0x8 selects the output); called by ava_get_frame |
| 0xaa00 | FUN_0000aa00 | `ava_render_convert_frame_yuv2` | INFERRED | packet tag 0x43; frame conversion for yuv2; called by ava_get_frame for 0x32767579 |
| 0xae80 | FUN_0000ae80 | `ava_render_scale_pass` | INFERRED | scales the clip/source rectangle (ctx+0x10c..0x112) to the surface with float math; called by ava_render_slot |
| 0xb7f0 | FUN_0000b7f0 | `ava_render_source_rect_pass` | INFERRED | packet tag 0x0a; source rectangle from ctx+0x124..0x12a (set by attribute 0x1c) |
| 0xbbc0 | FUN_0000bbc0 | `ava_render_pass_47` | UNKNOWN | packet tag 0x47 pass with a quad draw; callers not found (indirect) |
| 0xbf20 | FUN_0000bf20 | `ava_dcache_flush_range` | INFERRED | dcbst over the cache lines of [address, address+length) using the line size at ctx+0x144, then dcbf |
| 0xbf70 | FUN_0000bf70 | `ava_dcache_flush_range_sync` | INFERRED | dcbf over the range, then sync and isync |
| 0xbfc0 | FUN_0000bfc0 | `ava_emit_deint_enable_packet` | INFERRED | emits packet 0x15000000 with 0x20202020; called when the deinterlace property is set to 4 |
| 0xc160 | FUN_0000c160 | `ava_emit_deint_field_quad` | INFERRED | builds the field quad (field 1 or 2, flip flag) of the deinterlace pass |
| 0xc4b0 | FUN_0000c4b0 | `ava_render_deinterlace_pass` | INFERRED | packet tag 0x3d; two calls of ava_emit_deint_field_quad (fields 1 and 2) |
| 0xcaa0 | FUN_0000caa0 | `ava_deinterlace_frame` | INFERRED | calls ava_render_deinterlace_pass |
| 0xcb00 | FUN_0000cb00 | `ava_render_subpicture_pass` | INFERRED | packet tag 0x18; subpicture palette constants and quad; called by ava_display_subpicture |
