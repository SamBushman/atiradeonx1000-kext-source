/*
 * ATIR500Surface_ConstRun.cpp
 *
 * The contiguous run of five small constant tables at the end of the shipped kext's __const (stock addresses
 * 0x4c268..0x4c310), emitted with the stock's own symbol names, sizes and order:
 *
 *   _samplesTable                       28 bytes  (global table, SamplesTableLookup)
 *   shape_surface()::C.146              56 bytes  (compiler copy of an all-zero 14-word initialiser)
 *   load_3d_blit()::mspos1Table         28 bytes
 *   load_3d_blit()::mspos0Table         28 bytes
 *   load_3d_blit()::samplesTable        28 bytes
 *
 * The stock code indexes each 28-byte table with a 4-bit index (up to 16 words, i.e. past its end) and therefore reads into
 * whatever follows it. Keeping the five in the stock's order with no padding makes those over-reads land on the same words
 * as in the stock kext (the neighbouring table, or zero from C.146). The last table's over-read leaves __const; the nine words
 * the stock has there are kept as `_load3dSamplesTablePastEnd` (ours-only symbol) so that over-read returns the stock's
 * bytes too. Emitted as assembler data because a C++ compiler is free to reorder, pad, or rename separate objects.
 *
 * (Issue #62 items 1: replaces kShapeSurfaceDefaultMipTable and the 16-word copies of the three load_3d_blit statics and of
 * _samplesTable, which had the neighbours' words baked into each array.)
 */

asm(
    ".const\n"
    ".align 2\n"
    ".private_extern _samplesTable\n"                  /* the stock's five symbols are local to its one object; here they are referenced from several, so private-extern */
    ".private_extern __ZZN14ATIR500Surface13shape_surfaceEvE5C.146\n"
    ".private_extern __ZZN14ATIR500Surface12load_3d_blitEPmP20ATIR500SurfaceBufferE11mspos1Table\n"
    ".private_extern __ZZN14ATIR500Surface12load_3d_blitEPmP20ATIR500SurfaceBufferE11mspos0Table\n"
    ".private_extern __ZZN14ATIR500Surface12load_3d_blitEPmP20ATIR500SurfaceBufferE12samplesTable\n"
    "_samplesTable:\n"
    "    .long 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000003\n"
    "__ZZN14ATIR500Surface13shape_surfaceEvE5C.146:\n"
    "    .long 0,0,0,0,0,0,0,0,0,0,0,0,0,0\n"
    "__ZZN14ATIR500Surface12load_3d_blitEPmP20ATIR500SurfaceBufferE11mspos1Table:\n"
    "    .long 0x06666666, 0x06666666, 0x03393939, 0x06666666, 0x01171717, 0x06666666, 0x017b37b9\n"
    "__ZZN14ATIR500Surface12load_3d_blitEPmP20ATIR500SurfaceBufferE11mspos0Table:\n"
    "    .long 0x66666666, 0x66666666, 0x33393993, 0x66666666, 0x11a4417a, 0x66666666, 0x11951153\n"
    "__ZZN14ATIR500Surface12load_3d_blitEPmP20ATIR500SurfaceBufferE12samplesTable:\n"
    "    .long 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000003\n"
    "_load3dSamplesTablePastEnd:\n"
    "    .long 0x00005b00, 0x00008650, 0x0000c4f0, 0x0000f040, 0x00014130, 0x00018910, 0x00019a50, 0x0001b3f0, 0x000273f0\n"
    ".text\n"
);
