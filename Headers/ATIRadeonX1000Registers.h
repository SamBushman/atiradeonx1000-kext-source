/*
 * ATIRadeonX1000Registers.h
 *
 * The real R580/R5xx MMIO register map as confirmed by this project's
 * reverse-engineering, gathered from three independent sources that agreed
 * everywhere they overlapped: Ghidra decompilation of the shipped kext and
 * ATIRadeonX1000GA.plugin, AMD's own register-set PDFs (r3xx_3d_registers,
 * r5xx_accel_v15), and KolibriOS's open-source R580-aware driver code.
 *
 * All addresses are byte offsets from the card's MMIO base
 * (this project never independently confirmed where that base is mapped
 * from within the kext object itself for every context - see
 * ATIRadeonX1000.h's mmioBase field note).
 *
 * Confidence: CONFIRMED unless individually marked otherwise. See
 * ../README.md for tier definitions.
 */

#ifndef ATIRADEONX1000_REGISTERS_H
#define ATIRADEONX1000_REGISTERS_H

/* ---- Command processor / ring buffer ---- */
#define CP_RB_WPTR                 0x0714  /* main 3D ring write pointer; write-only, real bit-packing confirmed in submit_ring_data: (v<<0x18)|((v&0x700)<<8) */
#define IDCT_RING_WPTR             0x1fa0  /* INFERRED name: the independent IDCT engine's own ring write pointer - same bit-packing formula as CP_RB_WPTR, confirmed structurally distinct (stage4-real-hardware-idct-engine-found.md); official register name unknown */

/* IDCT-adjacent registers, INFERRED names (no AMD doc coverage found for
 * this generation's video/IDCT block - addresses and real per-block-submit
 * behavior are confirmed from submit_idct_buffer_consumed; names are this
 * project's own placeholders). */
#define IDCT_COEFF_ADDR_0          0x1fe0
#define IDCT_COEFF_ADDR_1          0x1fe4
#define IDCT_COEFF_ADDR_2          0x1fec
#define IDCT_COEFF_ADDR_3          0x1ff0
#define IDCT_UNKNOWN_1f8c          0x1f8c
#define IDCT_COEFF_ADDR_4          0x1ffc
#define IDCT_COEFF_ADDR_5          0x1ff8
#define IDCT_UNKNOWN_1fa8          0x1fa8
#define IDCT_UNKNOWN_1fac          0x1fac
#define IDCT_TRIGGER_PULSE         0x1fb4  /* written 6x with value 0 per submission, INFERRED to be a per-macroblock-subblock "process" strobe */

/* ---- Scissor / clipping (SC) ---- */
#define SC_EDGERULE                0x43a8
#define SC_SCREENDOOR              0x43e8  /* confirmed real default 0x0 (nothing visible) unless explicitly set; KolibriOS sets 0xffffff */
#define SC_HYPERZ_EN               0x43a4  /* compute_sc_hyperz_en()'s real output register */
#define SC_CLIP_RULE               0x43d0  /* confirmed 0xaaaa in five independent contexts this project found - the single most-cross-validated constant in the whole reveng effort */

/* ---- Geometry assembly / vertex (GA, GB, VAP) ---- */
#define GA_POLY_MODE               0x4288
#define GA_COLOR_CONTROL           0x4278
#define GA_COLOR_CONTROL_PS3       0x4258  /* "PS3-mode" shadow of GA_COLOR_CONTROL */
#define GA_US_VECTOR_INDEX         0x4250
#define GA_US_VECTOR_DATA          0x4254
#define GA_POINT_S0                0x4200
#define GA_POINT_T0                0x4204
#define GA_POINT_S1                0x4208
#define GA_POINT_T1                0x420c
#define GA_POINT_SIZE              0x421c
#define GB_MSPOS0                  0x4010
#define GB_MSPOS1                  0x4014
#define GB_AA_CONFIG               0x4020
#define GB_ENABLE                  0x4008
#define GB_PS3_ENABLE              0x4118  /* real master enable for the driver's extended "PS3" shading mode */
#define VAP_CNTL_STATUS            0x2140
#define VAP_CLIP_CNTL              0x221c
#define VAP_VTE_CNTL               0x20b0
#define VAP_OUT_VTX_FMT_0          0x2090
#define VAP_OUT_VTX_FMT_1          0x2094
#define VAP_VTX_SIZE               0x20b4
#define VAP_PROG_STREAM_CNTL_0     0x2150
#define VAP_PROG_STREAM_CNTL_EXT_0 0x21e0
#define SU_CULL_MODE               0x42b8
#define RS_COUNT                   0x4300
#define RS_INST_COUNT              0x4304
#define RS_INST_0                  0x4320
#define RS_IP_0                    0x4074

/* ---- Fragment shader unit (US) ---- */
#define US_CONFIG                  0x4600  /* the clearest "turn the fragment shader unit on" register found this project */
#define US_PIXSIZE                 0x4604
#define US_FC_CTRL                 0x4624
#define US_CODE_ADDR               0x4630
#define US_CODE_RANGE              0x4634
#define US_CODE_OFFSET             0x4638
#define US_OUT_FMT_0               0x46a4
#define US_OUT_FMT_1               0x46a8
#define US_OUT_FMT_2               0x46ac
#define US_OUT_FMT_3               0x46b0
#define US_ALU_RGBA_INST_VAL       0x2049  /* not a register address - a real shader-instruction-word literal (top 16 bits of a real ALU instruction dword), confirmed independently in ATIRadeonX1000GA.plugin's _radeon3DCopySetup/_radeon3DFillSetup AND this project's own hand-derived AMD-doc encoding */
#define US_CMN_INST_VAL            0x78105 /* same category: confirmed literal from _radeon3DFillSetup, not a register address */

/* ---- Texture units (TX), 16 units, 4 bytes apart within each block ---- */
#define TX_INVALTAGS               0x4100
#define TX_ENABLE                  0x4104
#define TX_OFFSET(unit)            (0x4540 + 4*(unit))   /* unit 0-15 */
#define TX_FILTER0(unit)           (0x4400 + 4*(unit))
#define TX_FILTER1(unit)           (0x4440 + 4*(unit))
#define TX_FORMAT0(unit)           (0x4480 + 4*(unit))
#define TX_FORMAT1(unit)           (0x44c0 + 4*(unit))

/* ---- Render backend / color buffer (RB3D) ---- */
#define RB3D_CCTL                  0x4e00
#define RB3D_BLENDCNTL             0x4e04
#define RB3D_COLOR_CHANNEL_MASK    0x4e0c  /* also reachable via a second real index this project confirmed decodes to the same byte address (0x1383) - a real, deliberate register alias, not a bug */
#define RB3D_DITHER_CTL            0x4e50
#define RB3D_ROPCNTL               0x4e18  /* also reachable via index 0x1386, same alias pattern as RB3D_COLOR_CHANNEL_MASK */
#define RB3D_COLOROFFSET0          0x4e28
#define RB3D_COLORPITCH0           0x4e38

/* ---- Depth/stencil + HyperZ (ZB) ---- */
#define ZB_CNTL                    0x4f00
#define ZB_ZSTENCILCNTL            0x4f04
#define ZB_STENCILREFMASK          0x4f08
#define ZB_ZCACHE_CTLSTAT          0x4f18
#define ZB_BW_CNTL                 0x4f1c  /* compute_zb_bw_cntl()'s real output register */
#define ZB_FORMAT                  0x4f10
#define ZB_ZTOP                    0x4f14
#define ZB_DEPTHOFFSET             0x4f20
#define ZB_DEPTHPITCH              0x4f24
#define ZB_DEPTHCLEARVALUE         0x4f28
#define ZB_UNDOCUMENTED_0x4f30     0x4f30  /* CONFIRMED real, undocumented in both local AMD PDF revisions - falls in a genuine gap between ZB_DEPTHCLEARVALUE and ZB_HIZ_OFFSET in the doc's own register list. Traced value: the direct, unmodified result of a real HZMEM_GetBlockOffset() call. Same value also written to the equally-undocumented 0x4e64 in the same burst. */
#define ZB_UNDOCUMENTED_0x4f34     0x4f34  /* CONFIRMED real, same undocumented-gap situation as 0x4f30; carries a real HiZ tile-aligned Y-dimension value */
#define ZB_UNDOCUMENTED_0x4e64     0x4e64  /* CONFIRMED real, receives the identical value written to ZB_UNDOCUMENTED_0x4f30 in the same function */
#define ZB_HIZ_OFFSET              0x4f44
#define ZB_HIZ_WRINDEX             0x4f48
#define ZB_HIZ_DWORD               0x4f4c
#define ZB_HIZ_RDINDEX             0x4f50
#define ZB_HIZ_PITCH               0x4f54
#define ZB_ZPASS_DATA              0x4f58
#define ZB_ZPASS_ADDR              0x4f5c
#define ZB_DEPTHXY_OFFSET          0x4f60
#define ZB_FIFO_SIZE               0x4fd0
#define ZB_STENCILREFMASK_BF       0x4fd4

/*
 * Two registers seen written by the driver at real, consistent indices but
 * never resolved against either locally-available AMD PDF revision even
 * after three independent sightings across this project's sessions.
 * INFERRED to be real hardware registers (both fall inside legitimate
 * register-block gaps, not obviously out-of-range), just undocumented in
 * these particular doc revisions.
 */
#define UNDOCUMENTED_REG_INDEX_0x13cc_BYTE  0x4f30  /* == ZB_UNDOCUMENTED_0x4f30 above, kept for cross-reference by the raw register index this project originally found it under */
#define UNDOCUMENTED_REG_INDEX_0x0d0b_BYTE  0x342c  /* seen in write_kernel_context_buffer_regs and opcode 0x37's handler; real purpose not established */

/*
 * A distinct class of value this project learned NOT to assume is a real
 * register: opcode 0x28's embedded "(index, value)" pair at raw index
 * 0x50b (byte address 0x142c) is a real, driver-internal SOFTWARE
 * bookkeeping field the kext's own generated command stream carries and
 * later reads back - not real MMIO at all (it sits well outside any real
 * register block). Not defined here as a register on purpose - see
 * stage4-opcode-range-0x02-0x31-traced.md in the other repo for the full
 * reasoning. Anyone extending this header with a new "(index, value)"
 * pair found in the embedded opcode language should check it against a
 * real register block's address range before assuming it's MMIO.
 */

/*
 * read_regs / write_regs / write_2_regs external methods (2D and DVD
 * contexts only - see ATIR5002DContext.h / ATIR500DVDContext.h) mask the
 * caller-supplied offset with this exact value before use - CONFIRMED
 * directly from the decompiled bodies of all four real implementations
 * (ATIR5002DContext and ATIR500DVDContext each have their own read_regs/
 * write_regs, byte-identical in shape). This means only registers in
 * [0, REGISTER_ACCESS_WINDOW_MASK] are reachable through those external
 * methods - most of the map above (everything in the 0x2000-0x5000 range)
 * is NOT reachable that way.
 */
#define REGISTER_ACCESS_WINDOW_MASK 0x1ffc

/*
 * SC_CLIP_RULE_VALUE_0xAAAA - CONFIRMED literal value written to
 * SC_CLIP_RULE throughout this driver (write_kernel_context_buffer_regs,
 * the capstone restore_state_destroyed_by_pageoff trace, and others) -
 * the single most cross-validated constant in this whole project (six
 * independent sightings across this project's full history, most
 * recently in write_kernel_context_buffer_regs's own full transcription).
 */
#define SC_CLIP_RULE_VALUE_0xAAAA 0xaaaa

/*
 * Real float/double data constants at fixed kext addresses, used by
 * opcode 0x31's (Sources/ATIR500GLContext_FSAAResolveBlit.cpp) and
 * opcode 0x04's (Sources/ATIR500GLContext_ProcessCommandBuffer.cpp)
 * real floating-point math. Centralized here (rather than declared
 * separately in each .cpp) since both real call sites need them.
 * Values UNKNOWN - not read out of the binary's __literal4/__literal8
 * sections this pass; see GAPS.md.
 */
extern "C" const double DOUBLE_0004c3a8; /* kext offset 0x4c3a8 - CONFIRMED role: 2^52, the standard "magic bias" for software int-to-double conversion */
extern "C" const double DOUBLE_0004c3b0; /* kext offset 0x4c3b0 - CONFIRMED role: a second bias constant, used for one specific operand pair in each real call site - not independently verified whether numerically identical to DOUBLE_0004c3a8 */
extern "C" const double DOUBLE_0004c3b8; /* kext offset 0x4c3b8 - CONFIRMED real, distinct THIRD constant, found in opcode 0x04's real HyperZ fast-clear trace - used as a real multiplicative scale factor (not a bias subtracted before use, unlike the other two) */
extern "C" const float  FLOAT_0004c370;  /* kext offset 0x4c370 - role UNKNOWN, used as the zero-case fallback for reciprocal scale factors (plausibly 0.0f or 1.0f) */
extern "C" const float  FLOAT_0004c374;  /* kext offset 0x4c374 - role UNKNOWN, real numerator in per-axis reciprocal-scale divisions (plausibly a fixed texture-space extent) */
extern "C" const float  FLOAT_0004c37c;  /* kext offset 0x4c37c - role UNKNOWN, real subpixel/fixed-point scale applied to coordinate DELTAS (plausibly 16.0f for R5xx's 12.4 fixed-point vertex format) */
extern "C" const float  FLOAT_0004c380;  /* kext offset 0x4c380 - role UNKNOWN, real scale applied to coordinate SUMS (plausibly 0.5f for a midpoint, or a texture-space normalization constant) */

/*
 * _HZDATA / HZMEM_GetBlockOffset - CONFIRMED real, named HiZ memory-
 * manager type and function this project found directly in the kext's
 * own symbol table (a real Apple-internal helper, not reconstructed by
 * this project). Real signature INFERRED from call-site shape
 * (`HZMEM_GetBlockOffset(&accel->hizDataAt0x870, surfaceRecordField0x28, blockKind)`).
 * `_HZDATA`'s own internal layout was never decompiled - opaque here.
 */
struct _HZDATA;
extern "C" UInt32 HZMEM_GetBlockOffset(_HZDATA *hizData, UInt32 surfaceHzField, UInt32 blockKind);
/*
 * FIXED this pass: HZMEM_GetBlockCount/HZMEM_IsPartial were already being
 * called throughout ATIR500GLContext_ProcessCommandBuffer.cpp and
 * ATIR500GLContext_RegisterState.cpp (real, CONFIRMED sibling functions to
 * HZMEM_GetBlockOffset, same real call shape) but were never actually
 * declared anywhere in this project's headers - a real gap that would have
 * failed to compile. Same real signature shape as HZMEM_GetBlockOffset.
 */
extern "C" UInt32 HZMEM_GetBlockCount(_HZDATA *hizData, UInt32 surfaceHzField, UInt32 blockKind);
extern "C" UInt32 HZMEM_IsPartial(_HZDATA *hizData, UInt32 surfaceHzField, UInt32 blockKind);
/*
 * HZMEM_Alloc - CONFIRMED real, found this pass in opcode 0x41's real
 * body (real depth/stencil HyperZ block auto-allocation). Real signature
 * INFERRED from its two real call-site shapes:
 *   HZMEM_Alloc(hizData, 0xffffffff, 0, tileDim, size)       - fresh alloc
 *   HZMEM_Alloc(hizData, existingBlockHandle, 1, tileDim, size) - a second,
 *     related allocation given an already-allocated block (stencil
 *     following depth) - the real meaning of the second/third parameters
 *     is INFERRED (a "previous block" handle and a "chain to it" flag),
 *     not independently confirmed against HZMEM_Alloc's own body.
 */
extern "C" UInt32 HZMEM_Alloc(_HZDATA *hizData, UInt32 existingBlockOrSentinel, UInt32 chainFlag, UInt32 tileDim, UInt32 size);

/*
 * FormatTableLookup_0x0004d2dc / FormatTableLookup_0x0004d2e0 -
 * INFERRED helper wrapping this project's own naming for two real,
 * confirmed-to-exist binary data tables (`DAT_0004d2dc`/`DAT_0004d2e0` in
 * the raw decompile) indexed by `ATIR500SurfaceBuffer::formatTableIndex * 0x1c`
 * throughout build_scissor, write_kernel_context_buffer_regs, and the
 * opcode 0x37 trace. These are real pixel-FORMAT DESCRIPTOR tables (not
 * code) - their raw bytes were never extracted from the binary into this
 * reconstruction. A real implementation should read them directly out of
 * the kext's __const section at those addresses rather than guess at
 * their content structurally.
 */
extern "C" UInt32 FormatTableLookup_0x0004d2dc(UInt32 byteOffset);
extern "C" UInt32 FormatTableLookup_0x0004d2e0(UInt32 byteOffset);
/* FormatTableLookup_0x0004d2e4 - a THIRD real, confirmed-to-exist format
 * table (`DAT_0004d2e4` in the raw decompile), found this pass in opcode
 * 0x31's real trace (Sources/ATIR500GLContext_FSAAResolveBlit.cpp) -
 * same real indexing convention (`formatTableIndex * 0x1c`) as the other
 * two. Raw table content not extracted from the binary this pass. */
extern "C" UInt32 FormatTableLookup_0x0004d2e4(UInt32 byteOffset);

#endif /* ATIRADEONX1000_REGISTERS_H */
