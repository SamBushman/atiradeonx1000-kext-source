/*
 * ATIRadeonX1000Types.h
 *
 * Shared struct/type definitions used across the ATIRadeonX1000 kext class
 * hierarchy. Reconstructed from Ghidra decompilation of the real shipped
 * kext (Tiger, ATIRadeonX1000.kext.bin) - see the g5-h264-gpu-decode repo's
 * promo4-client/reveng/ for the underlying analysis this draws from.
 *
 * Confidence: mixed, marked per-struct. See ../README.md for the tier
 * definitions (CONFIRMED / INFERRED / UNKNOWN).
 */

#ifndef ATIRADEONX1000_TYPES_H
#define ATIRADEONX1000_TYPES_H

#include <IOKit/IOTypes.h>

/*
 * VendorCommandDescriptor - CONFIRMED shape, INFERRED field names.
 *
 * The argument to every context class's process_command_buffer(). Real
 * decompiled signature: process_command_buffer(VendorCommandDescriptor*).
 * The command-processing loop in every context class reads a base pointer
 * and length from this descriptor before walking the actual command
 * stream - the exact field layout was never independently confirmed
 * (process_command_buffer's prologue was read many times, but a dedicated
 * struct-layout pass on VendorCommandDescriptor itself was not done this
 * project). Field names/order below are INFERRED from the two values every
 * context class's prologue clearly extracts (a buffer pointer, a length).
 */
struct VendorCommandDescriptor {
    void *          commandBuffer;   /* INFERRED: base of the command stream to process */
    UInt32          commandLength;   /* INFERRED: length in bytes or dwords - not confirmed which */
    /* UNKNOWN: real struct is very likely larger than this - only the
     * fields actually dereferenced in the traced prologues are represented.
     * TODO: a dedicated decompile of the struct's use across all four
     * process_command_buffer implementations would nail this down exactly. */
};

/*
 * VendorCommandBufferHeader - CONFIRMED fields at +0x1c and +0x40 only.
 *
 * Real decompiled signature: init_command_buffer_header(VendorCommandBufferHeader*, unsigned long, unsigned long).
 * ATIR500GLContext::start() (kext offset 0x28540) directly initializes two
 * fields of the object this + 0xe0 points at:
 *     *(undefined4 *)(*(int *)(this + 0xe0) + 0x1c) = 9;
 *     *(undefined4 *)(*(int *)(this + 0xe0) + 0x40) = 0x1000000;
 * The `+0x1c` field lines up with this project's client-side finding (a
 * different binary, ATIRadeonX1000GLDriver.bundle, confirmed a "chain-link"
 * field at a `+0x1c`-from-base offset in FUN_0002c790's literal
 * initializer - see stage3g-cursor-field-misidentified.md in the other
 * repo). Whether the KERNEL's `this+0xe0`-relative +0x1c and the
 * USERSPACE bundle's own +0x1c-from-its-own-base are literally the same
 * shared-memory byte was never proven directly (they're reached via two
 * independently-computed base pointers in two different binaries) - kept
 * here as a real, named, but separately-tracked hypothesis rather than
 * silently assumed.
 */
struct VendorCommandBufferHeader {
    UInt8   _unknown_00[0x1c];
    UInt32  chainLinkOrGeneration;  /* +0x1c, CONFIRMED written (value 9 at context start) */
    UInt8   _unknown_20[0x40 - 0x1c - 4];
    UInt32  initialSizeOrFlags;     /* +0x40, CONFIRMED written (value 0x1000000 at context start) */
    /* UNKNOWN: real total size not established - this struct is a
     * placeholder wide enough to name the two confirmed fields. */
};

/*
 * VendorContextBufferHeader - UNKNOWN layout.
 *
 * Real decompiled signature: init_context_buffer_header(VendorContextBufferHeader*, unsigned long).
 * Never decompiled beyond its name and argument count this project.
 * TODO: decompile IOATIR500GLContext::init_context_buffer_header (kext
 * offset 0x7490) to fill this in.
 */
struct VendorContextBufferHeader {
    UInt8 _opaque[4];  /* UNKNOWN size - placeholder only */
};

/*
 * VendorTextureBuffer - CONFIRMED several fields, from direct, repeated
 * use across new_texture/delete_texture/reclaim_resources/get_data_buffer/
 * add_texture_to_stream/remove_texture_from_stream (all read this session
 * and in earlier sessions - see stage3/stage4/stage9 docs).
 *
 * This is a real, shared, doubly-linked, reference-counted GPU buffer
 * object used for BOTH textures and generic data buffers (get_data_buffer
 * pools these same objects for command-buffer-adjacent scratch space).
 */
struct VendorTextureBuffer {
    UInt32          field_0x00;
    UInt32          field_0x04;         /* CONFIRMED: nonzero => "has a real backing IOMemoryDescriptor" gate seen in get_data_buffer/create_transfer */
    void *          memoryDescriptor;   /* +0x08, CONFIRMED: passed to vtable calls shaped like IOMemoryDescriptor methods (retain/release at +0x14/+0x18) */
    UInt32          field_0x0c;
    void *          gartMapping;        /* +0x10, CONFIRMED: real GART/IOMemoryMap-shaped pointer, released via vtable+0x18 in multiple call sites */
    UInt8           _pad_0x14[0x24 - 0x14];
    void *          surfaceOrFormatInfo; /* +0x24, CONFIRMED: doubly-linked-list node ("prev") in purge_texture/get_data_buffer, and dereferenced for format-table lookups elsewhere (+0x14 sub-offset used for pixel format bits in write_r500_3d_blit_state_packet-adjacent code) */
    void *          listNext;            /* +0x28, CONFIRMED: doubly-linked-list node ("next"), same call sites as +0x24 */
    UInt8           _pad_0x2c[0x3c - 0x2c];
    UInt32          streamListNext;      /* +0x3c, CONFIRMED: singly-linked "next" pointer used by reclaim_resources' free-list and add/remove_texture_from_stream */
    UInt8           _pad_0x40[0x48 - 0x40];
    UInt32          transferBufferFlag;  /* +0x48, CONFIRMED: nonzero gates a distinct "transfer buffer" code path vs. plain texture in multiple functions (get_data_buffer, purge_texture) */
    UInt8           _pad_0x4c[0x50 - 0x4c];
    UInt32          poolSizeClass;       /* +0x50, CONFIRMED: compared against the accelerator's current buffer-size threshold (this+0x5d8 on IOATIR500Accelerator) in get_data_buffer to decide whether to recycle or reallocate */
    UInt8           _pad_0x54[0x5c - 0x54];
    UInt32          generationTag;       /* +0x5c, CONFIRMED: stamped with the requesting context's generation counter in get_data_buffer, read back in wait_image/wait-for-stamp style functions */
    /* UNKNOWN: real total struct size not established beyond +0x5c plus
     * whatever padding the field at +0x54 (byte "pVVar1[0x54] = 1/0" seen
     * in reclaim_resources/get_data_buffer, a "resident"/"in flight" flag)
     * needs. */
};

/*
 * VendorTransferBuffer - CONFIRMED shape overlaps VendorTextureBuffer at
 * several offsets (both are handled by the same freeToAllocGART/
 * map_transfer_to_GART machinery) but is used as its own distinct type in
 * every real decompiled signature (map_transfer_to_GART(VendorTransferBuffer*),
 * freeToAllocGART(..., VendorTransferBuffer*), doIDCT's own two per-plane
 * ping-pong buffer pointers). Modeled here as its own type per the real
 * signatures, even though its confirmed fields (+4 real-backing flag, +0x14
 * mapped GART pointer, +0x5c generation tag) line up with VendorTextureBuffer -
 * plausibly the same underlying allocation with two different C++ types in
 * the original source (a real common base class is a reasonable guess, not
 * confirmed - see the INFERRED note below).
 */
struct VendorTransferBuffer {
    UInt32          field_0x00;
    UInt32          realBackingFlag;    /* +0x04, CONFIRMED gate: doIDCT/get_data_buffer/create_transfer all branch on this before calling map_transfer_to_GART */
    UInt8           _pad_0x08[0x14 - 0x08];
    void *          gartMappedPointer;  /* +0x14, CONFIRMED: the real GPU-visible address after map_transfer_to_GART runs, per doIDCT's direct use */
    UInt8           _pad_0x18[0x3c - 0x18];
    UInt32          listNext;           /* +0x3c, CONFIRMED: singly-linked "next" pointer, freeToAllocGART's cached-ring walk */
    UInt8           _pad_0x40[0x50 - 0x40];
    UInt32          poolSizeClass;      /* +0x50, INFERRED by analogy with VendorTextureBuffer's identical-offset field */
    UInt8           _pad_0x54[0x5c - 0x54];
    UInt32          generationTag;      /* +0x5c, CONFIRMED: same generation-tag pattern as VendorTextureBuffer, used identically */
    /*
     * INFERRED, not confirmed: VendorTextureBuffer and VendorTransferBuffer
     * sharing field offsets this consistently strongly suggests a real
     * common base class in the original source (something like
     * "VendorGPUBuffer"). Not modeled as an actual C++ base class here
     * because the exact split point between shared and buffer-type-specific
     * fields was never independently confirmed - keeping them as two
     * flat structs is the more honest (if less elegant) reconstruction.
     */
};

/*
 * ATIR500SurfaceBuffer - CONFIRMED several fields from build_scissor,
 * GetTextureOffset, get_surface_size/get_surface_info, and the capstone
 * register-map trace (restore_state_destroyed_by_pageoff indexes an array
 * of these per mip level via `pAVar77 + mipIndex*4 + 0x40`).
 */
struct ATIR500SurfaceBuffer {
    UInt8   _pad_0x00[0x08];
    UInt32  gpuBaseAddress;      /* +0x08, CONFIRMED: real per-surface base address, added into every offset computation seen this project */
    UInt8   _pad_0x0c[0x14 - 0x0c];
    UInt16  width;               /* +0x14, CONFIRMED: real pixel width, used throughout pitch/offset math */
    UInt8   _pad_0x16[0x16 - 0x16];
    UInt16  bytesPerRow;         /* +0x16, CONFIRMED: real real pitch-adjacent value ("uVar73 * *(ushort*)(pAVar77+0x16)" pitch formulas throughout) */
    UInt8   _pad_0x18[0x1c - 0x18];
    UInt16  heightOrRows;        /* +0x1c, CONFIRMED: used identically to width in scissor/clip clamping */
    UInt16  extra1e;             /* +0x1e, CONFIRMED: paired with +0x1c in get_surface_size's non-mip branch */
    UInt8   _pad_0x20[0x28 - 0x20];
    UInt32  formatOrTilingBits;  /* +0x28, CONFIRMED: real per-mip dirty/format bitmask, checked in page_off_texture */
    UInt8   _pad_0x2c[0x38 - 0x2c];
    UInt8   tilingConfigByte0;   /* +0x38, CONFIRMED: real tiling-config byte, feeds the &1/&6/&7 bit tests throughout the capstone register-write code */
    UInt8   tilingConfigByte1;   /* +0x39, CONFIRMED: same family, &3 bit test */
    UInt8   formatTableIndex;    /* +0x3a, CONFIRMED: real index into the DAT_0004d2e0/DAT_0004d2e4-style format lookup tables (`* 0x1c` stride) */
    UInt8   _pad_0x3b;
    UInt32  mipOffsets[16];      /* +0x40.., CONFIRMED: real per-mip-level GPU offset array, indexed by `mipIndex*4 + 0x40` throughout the capstone/blit-state-packet code */
};

/*
 * register_tracking_state - CONFIRMED field-by-field against the capstone
 * register map (see stage4-complete-register-tracking-state-map.md). This
 * is Apple's own "everything that must survive a VRAM eviction" snapshot -
 * restore_state_destroyed_by_pageoff() serializes exactly these fields
 * back out as real PM4 register writes.
 */
struct register_tracking_state {
    UInt32 sc_edgerule;              /* +0x00 -> SC_EDGERULE (0x43a8) */
    UInt32 sc_screendoor;            /* +0x04 -> SC_SCREENDOOR (0x43e8) */
    UInt32 field_0x08;
    UInt32 gb_aa_config;             /* +0x0c -> GB_AA_CONFIG (0x4020) */
    UInt32 sc_hyperz_en;             /* +0x14 -> SC_HYPERZ_EN (0x43a4), compute_sc_hyperz_en's output slot */
    UInt32 zb_bw_cntl;               /* +0x18 -> ZB_BW_CNTL (0x4f1c), compute_zb_bw_cntl's output slot */
    UInt32 zb_zstencilcntl;          /* +0x1c -> ZB_ZSTENCILCNTL (0x4f04) */
    UInt32 vap_cntl_status;          /* +0x20 -> VAP_CNTL_STATUS (0x2140) */
    UInt32 vap_clip_cntl;            /* +0x24 -> VAP_CLIP_CNTL (0x221c) */
    UInt32 vap_vte_cntl;             /* +0x28 -> VAP_VTE_CNTL (0x20b0) */
    UInt32 su_cull_mode;             /* +0x2c -> SU_CULL_MODE (0x42b8) */
    UInt32 rb3d_dither_ctl;          /* +0x30 -> RB3D_DITHER_CTL (0x4e50) */
    UInt32 vap_out_vtx_fmt_0;        /* +0x3c -> VAP_OUT_VTX_FMT_0 (0x2090) */
    UInt32 vap_out_vtx_fmt_1;        /* +0x40 -> VAP_OUT_VTX_FMT_1 (0x2094) */
    UInt32 vap_vtx_size;             /* +0x44 -> VAP_VTX_SIZE (0x20b4) */
    UInt32 vap_prog_stream_cntl_0;   /* +0x48 -> VAP_PROG_STREAM_CNTL_0 (0x2150) */
    UInt32 vap_prog_stream_cntl_ext_0; /* +0x4c -> VAP_PROG_STREAM_CNTL_EXT_0 (0x21e0) */
    UInt32 zb_cntl;                  /* +0x50 -> ZB_CNTL (0x4f00) */
    UInt32 fg_fog_blend;             /* +0x54 -> FG_FOG_BLEND (0x4bc0) */
    UInt32 fg_alpha_func;            /* +0x58 -> FG_ALPHA_FUNC (0x4bd4) */
    UInt32 ga_poly_mode;             /* +0x5c -> GA_POLY_MODE (0x4288) */
    UInt32 rb3d_blendcntl;           /* +0x60 -> RB3D_BLENDCNTL (0x4e04) */
    UInt32 ga_color_control;         /* +0x64 -> GA_COLOR_CONTROL (0x4278) */
    UInt32 tx_enable;                /* +0x6c -> TX_ENABLE (0x4104) */
    UInt32 gb_ps3_enable;            /* +0x70 -> GB:PS3_ENABLE (0x4118) */
    UInt32 ga_us_vector[11];         /* +0x74.. -> GA_US_VECTOR_INDEX/DATA (0x4250/0x4254) burst, shader instruction words */
    UInt32 ga_color_control_ps3;     /* real field within/adjacent to the vector burst above -> GA_COLOR_CONTROL_PS3 (0x4258) - exact sub-offset not independently isolated, see stage4 capstone doc */
    UInt32 us_out_fmt_1;             /* -> US_OUT_FMT_1 (0x46a8) */
    UInt32 us_out_fmt_2;             /* -> US_OUT_FMT_2 (0x46ac) */
    UInt32 us_out_fmt_3;             /* -> US_OUT_FMT_3 (0x46b0) */
    UInt32 rs_count;                 /* -> RS_COUNT (0x4300) */
    UInt32 us_fc_ctrl;               /* +0x88 -> US_FC_CTRL (0x4624) */
    UInt32 us_pixsize;               /* +0x8c -> US_PIXSIZE (0x4604) */
    UInt32 us_code_range;            /* +0x90 -> US_CODE_RANGE (0x4634) */
    UInt32 us_code_offset;           /* +0x94 -> US_CODE_OFFSET (0x4638) */
    UInt32 us_code_addr;             /* +0x98 -> US_CODE_ADDR (0x4630) */
    UInt32 us_out_fmt_0;             /* +0x9c -> US_OUT_FMT_0 (0x46a4) */
    UInt32 rs_inst_count;            /* +0xa0 -> RS_INST_COUNT (0x4304) */
    UInt32 rs_inst_0;                /* +0xa4 -> RS_INST_0 (0x4320) */
    UInt32 rs_ip_0;                  /* +0xa8 -> RS_IP_0 (0x4074) */
    UInt32 tx_offset[16];            /* +0xac.. -> TX_OFFSET_[0-15] (0x4540-0x457c) */
    /* UNKNOWN: real total size beyond this point (RB3D_COLOR_CHANNEL_MASK
     * at +0xd0 and RB3D_ROPCNTL at +0xd8 are confirmed to exist per the
     * capstone doc but their exact byte gap from tx_offset[] here wasn't
     * independently re-derived for this reconstruction - left as a
     * trailer rather than guessed at.) */
    UInt8  _trailer_unconfirmed[0x40];
};
#define OFFSETOF_rb3d_color_channel_mask 0xd0   /* CONFIRMED address, UNKNOWN exact struct member split */
#define OFFSETOF_rb3d_ropcntl            0xd8   /* CONFIRMED address, UNKNOWN exact struct member split */

/*
 * r500_3d_blit_state_packet_struct - CONFIRMED to be ~0x2f4 bytes
 * (write_r500_3d_blit_state_packet / restore_state_destroyed_by_pageoff
 * both memcpy a global template of exactly this size,
 * `FUN_000314c4(dest, &_g_r500_3d_blit_state_packet, 0x2f4)`), and to be
 * laid out as a real, dense array of (register-index, value) Type-0-style
 * PM4 pairs matching everything in register_tracking_state above plus the
 * TX_FILTER/TX_FORMAT arrays and SC_CLIP_RULE/RB3D_CCTL literals from the
 * capstone doc. The EXACT field-by-field struct (as opposed to "a 0x2f4-byte
 * buffer of dwords this project knows how to interpret index-by-index") was
 * never reconstructed as clean named members - represented honestly as a
 * raw buffer here rather than guessed at member-by-member.
 */
struct r500_3d_blit_state_packet_struct {
    UInt32 dwords[0x2f4 / 4];  /* CONFIRMED total size; UNKNOWN per-dword field breakdown beyond what stage4's capstone doc already indexes by raw offset */
};

/*
 * r500_zdecompress_restore_add_on_packet_struct - UNKNOWN layout beyond
 * its name and the fact write_r500_zdecompress_restore_add_on_packet takes
 * a pointer to one. Never decompiled this project.
 */
struct r500_zdecompress_restore_add_on_packet_struct {
    UInt8 _opaque[4]; /* UNKNOWN size - placeholder only */
};

/*
 * sATIDVDIDCTInfo - CONFIRMED several fields from doIDCT's real trace
 * (stage4-real-hardware-idct-engine-found.md / stage5's doIDCT decode).
 */
struct sATIDVDIDCTInfo {
    UInt8   _pad_0x00[0x7c];
    UInt32  submitCookie;        /* +0x7c, CONFIRMED: passed straight through to a vtable call at the very top of doIDCT */
    UInt32  hwAccelerator;       /* +0x8c, CONFIRMED: real ATIRadeonX1000* pointer, used for every field-access/vtable-call in doIDCT */
    UInt8   _pad_0x90[0xf8 - 0x90];
    UInt32  surfaceInfo;         /* +0xf8, CONFIRMED: real surface-geometry pointer, fields +0x94/+0x9a read as field heights */
    UInt8   _pad_0xfc[0x150 - 0xfc];
    UInt32  lastSubmittedTag;    /* +0x150, CONFIRMED: written from submit_idct_buffer_consumed's return value */
    UInt32  lastConsumedTagLuma; /* +0x154, CONFIRMED: mirrors +0x150 for the luma-plane (param_2+0xc==0) case */
    UInt8   _pad_0x158[0x164 - 0x158];
    UInt32  lumaBufferAField_0x164; /* +0x164, CONFIRMED: real ping-pong-buffer selector flag for the luma plane */
    UInt32  lumaBufferA;         /* +0x168, CONFIRMED: real VendorTransferBuffer-shaped pointer (luma plane, buffer A) */
    UInt8   _pad_0x16c[0x184 - 0x16c];
    UInt32  lumaBufferB;         /* +0x184, CONFIRMED: real VendorTransferBuffer-shaped pointer (luma plane, buffer B) */
    UInt8   _pad_0x188[0x1a0 - 0x188];
    UInt32  chromaBufferAField_0x1a0; /* +0x1a0, CONFIRMED: same ping-pong pattern for chroma */
    UInt32  chromaBufferA;       /* +0x1a4, CONFIRMED */
    UInt8   _pad_0x1a8[0x1c0 - 0x1a8];
    UInt32  chromaBufferB;       /* +0x1c0, CONFIRMED */
    /* UNKNOWN: real total size not established beyond these confirmed
     * offsets. */
};

/*
 * sIOGLNewTextureData / sIOGLNewTextureReturnData / sIOGLContextReadBufferData -
 * UNKNOWN layout. Only their names, argument positions, and the small
 * number of leading dwords actually dereferenced in new_texture/read_buffer
 * are confirmed (see the switch-on-type-tag dispatch in
 * IOATIR500GLContext::new_texture and the geometry fields read at the top
 * of IOATIR500GLContext::read_buffer). These are real Apple IOKit
 * userland<->kernel structs (the "sIOGL*" prefix matches Apple's own
 * IOKit Graphics naming convention for this era) - a full field-accurate
 * reconstruction would need Apple's own (never published for this driver)
 * private headers, or a live trace of a real glTexImage2D/glReadPixels call.
 */
struct sIOGLNewTextureData {
    UInt32 typeTag;      /* +0x00, CONFIRMED: the real switch discriminant in new_texture (0/1/2/3/6/7) */
    UInt32 field_0x04;   /* CONFIRMED used as a dimension/size argument in every switch case */
    UInt32 field_0x08;   /* CONFIRMED used similarly */
    UInt32 field_0x0c;   /* CONFIRMED used similarly (format tag in some cases) */
    UInt32 field_0x10;   /* CONFIRMED used in the type==7 case only */
    /* UNKNOWN beyond this point */
};
struct sIOGLNewTextureReturnData {
    UInt32 outLow;   /* +0x00 */
    UInt32 outHigh;  /* +0x04 */
    /* UNKNOWN beyond this point */
};
struct sIOGLContextReadBufferData {
    UInt32 x, y, w, h;      /* +0x00/+0x04/+0x08/+0x0c, CONFIRMED: real clipped-rect geometry in read_buffer */
    UInt32 sourceSelector;  /* +0x10, CONFIRMED: real switch discriminant selecting which of 9 real source buffers (front/back/aux, matching the same 0/1/2/3/4/7/8/10/11-style enum family seen in opcode 0x2a/0x29's attachment tables) */
    UInt32 destOffset;      /* +0x14, CONFIRMED: real destination-buffer byte offset */
    UInt32 destPitchOrRowBytes; /* +0x18, CONFIRMED: real destination row stride */
    /* UNKNOWN beyond this point */
};

/*
 * VendorExternalMethod - CONFIRMED shape: a real 24-byte (6-dword) struct,
 * read directly off raw kext bytes this project dumped this session (see
 * stage5-iouserclient-external-method-api-complete.md). Every context
 * class's external-method table (regular table, extra-selector table, and
 * the GL context's special single-entry selector-20 slot) is a real,
 * static array of these.
 *
 * Real dword layout, confirmed by reading every entry of every table:
 *   [0] target   - always 0 in the static template; patched live to the
 *                  real target object pointer by getTargetAndMethodForIndex
 *                  at call time (CONFIRMED: this dword is 0 in 100% of the
 *                  ~90 real entries this project dumped across all four
 *                  context classes).
 *   [1] flags    - CONFIRMED constant 0xffff in every single entry dumped.
 *                  Real meaning UNKNOWN - by shape/position this matches
 *                  classic IOExternalMethod's `flags` (IOOptionBits) field,
 *                  but this driver's real encoding was never independently
 *                  decoded (a constant value across ~90 real, functionally
 *                  different entries is itself informative: whatever
 *                  scalar-vs-structure/sync-vs-async distinction classic
 *                  IOExternalMethod's flags field usually carries is
 *                  evidently NOT encoded here, or is encoded identically
 *                  for every method in this driver).
 *   [2] function - CONFIRMED real function pointer, resolved to a real
 *                  symbol for every entry this project dumped.
 *   [3] count0   - CONFIRMED small integer, by call-site cross-reference
 *                  (stage7's IOServiceOpen-caller confirmation) this is
 *                  the real scalar/structure INPUT count.
 *   [4] count1   - CONFIRMED small integer; by the same cross-reference,
 *                  the real scalar/structure OUTPUT count for most
 *                  entries, though a few entries (e.g. GL selector 6)
 *                  show a real call site treating a different field as
 *                  the output count - see the per-table source files for
 *                  entry-by-entry notes where this project's confidence
 *                  is lower.
 *   [5] count2   - CONFIRMED small integer, present in every entry;
 *                  UNKNOWN precise meaning (a third count - plausibly a
 *                  structure-output *size* distinct from a scalar-output
 *                  *count* - not independently confirmed).
 *
 * 0xffffffff appears in several `count0`/`count1` slots (e.g. GL
 * selector 7's `read_buffer`, selector 10's `new_texture`) - CONFIRMED
 * real (read directly off the raw bytes), INFERRED to mean "variable
 * size" (the classic IOKit `kIOUCVariableStructureSize` sentinel is
 * `0xffffffff` in real Apple headers from this era, which matches).
 */
struct VendorExternalMethod {
    UInt32 target;    /* always 0 in the static template */
    UInt32 flags;     /* always 0xffff, confirmed constant, real meaning UNKNOWN */
    void  *function;
    UInt32 count0;
    UInt32 count1;
    UInt32 count2;
};

#endif /* ATIRADEONX1000_TYPES_H */
