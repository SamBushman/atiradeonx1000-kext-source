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
 * opcode 0x2d's (Sources/ATIR500GLContext_FSAAResolveBlit.cpp -
 * CORRECTED, issue #12 item 4: this file's content was previously
 * misattributed to opcode 0x31, which has no floating-point math at all -
 * see that file's header comment) and opcode 0x04's
 * (Sources/ATIR500GLContext_ProcessCommandBuffer.cpp) real floating-point
 * math. Centralized here (rather than declared separately in each .cpp)
 * since both real call sites need them. Values UNKNOWN - not read out of
 * the binary's __literal4/__literal8 sections this pass; see GAPS.md.
 */
/* RESOLVED (issue #14): all seven real values read directly from the kext
 * binary's own data section. `DOUBLE_0004c3a8` is exactly 2^52+2^31
 * (0x4330000080000000) - the magic-bias constant WITH the sign-flip XOR
 * already folded in, for converting an already-`^0x80000000`'d value
 * (signed int-to-double). `DOUBLE_0004c3b0` is exactly 2^52
 * (0x4330000000000000) - the plain bias, for values used WITHOUT the XOR
 * (unsigned int-to-double) - confirmed numerically DISTINCT from
 * `DOUBLE_0004c3a8`, resolving the "not independently verified" caveat
 * below. Both match the literal `4503601774854144.0`/`4503599627370496.0`
 * constants this project's DVD-context and `resolve_fsaa_buffer`
 * transcriptions had already independently derived and used inline
 * elsewhere (`ATIR500DVDContext_ProcessCommandBuffer.cpp`,
 * `ATIR500Surface_ResolveFSAABuffer.cpp`) - a real cross-confirmation. */
extern "C" const double DOUBLE_0004c3a8; /* kext offset 0x4c3a8 - CONFIRMED real value 4503601774854144.0 (0x4330000080000000): the "magic bias" for signed (pre-XORed) int-to-double conversion */
extern "C" const double DOUBLE_0004c3b0; /* kext offset 0x4c3b0 - CONFIRMED real value 4503599627370496.0 (0x4330000000000000): the plain 2^52 bias for unsigned int-to-double conversion - confirmed numerically distinct from DOUBLE_0004c3a8 */
extern "C" const double DOUBLE_0004c3b8; /* kext offset 0x4c3b8 - CONFIRMED real value 0.5: a real multiplicative scale factor (not a bias subtracted before use, unlike the other two) */
extern "C" const float  FLOAT_0004c370;  /* kext offset 0x4c370 - CONFIRMED real value 0.0f: the zero-case fallback for reciprocal scale factors, exactly as guessed */
extern "C" const float  FLOAT_0004c374;  /* kext offset 0x4c374 - CONFIRMED real value 1.0f: a true reciprocal numerator (`1.0f / x`), not a fixed texture-space extent as this project's earlier guess had it - REVISES that guess */
extern "C" const float  FLOAT_0004c37c;  /* kext offset 0x4c37c - CONFIRMED real value 6.0f - REVISES this project's earlier guess of 16.0f for R5xx 12.4 fixed-point; real role still not independently pinned down beyond "a coordinate-delta scale factor" */
extern "C" const float  FLOAT_0004c380;  /* kext offset 0x4c380 - CONFIRMED real value 0.5f: a real midpoint-averaging scale (`(a+b)*0.5f`), exactly as guessed */

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
 * FormatTableLookup_0x0004d2dc / FormatTableLookup_0x0004d2e0 /
 * FormatTableLookup_0x0004d2e4 - RESOLVED (issue #14). These are NOT three
 * independent tables - real structural finding: they're three adjacent
 * `UInt32` FIELDS (`+0xc`/`+0x10`/`+0x14`) within ONE real, named,
 * 7-dword/28-byte-stride struct array this project found directly in the
 * kext's own symbol table: `_ati_format_info_table` (real base address
 * `0x4d2d0`, NOT `0x4d2dc` - this project's own field-offset-derived
 * naming for these three accessors predates knowing the real struct
 * base, hence the "misaligned by 0xc" addresses baked into their names).
 * Real, disassembly-confirmed EXACTLY 48 entries (indices 0-47) - bounded
 * with certainty by a real self-index field (`entry[0] == index << 24`)
 * that increments cleanly for all 48 real entries and then breaks
 * completely at a 49th slot, which real kext symbols
 * (`out_fmt`/`rb3d_dst_format`/`texture_type`/`gMetaClass`) immediately
 * beyond confirm is unrelated data, not a 49th format. Real per-entry
 * layout (`AtiFormatInfoEntry`, `ATIRadeonX1000Types.h`): self-index,
 * a constant shared by all 48 entries (`0x00045a14`), a per-format field
 * no current caller in this project reads, the three fields these
 * accessors expose, and a second all-48-entries constant (`0xff000000`).
 * Real content (all 48 entries, all 7 fields) now backs these three
 * accessors - see `kAtiFormatInfoTable` in
 * `Sources/ATIRadeonX1000_DataTables.cpp`. Indexing convention unchanged
 * for every existing call site (`formatTableIndex * 0x1c` still
 * addresses the right entry's own base; these functions internally
 * account for the real `0xc` struct-base correction).
 */
extern "C" UInt32 FormatTableLookup_0x0004d2dc(UInt32 byteOffset);
extern "C" UInt32 FormatTableLookup_0x0004d2e0(UInt32 byteOffset);
extern "C" UInt32 FormatTableLookup_0x0004d2e4(UInt32 byteOffset);

/*
 * SamplesTableLookup - RESOLVED (issue #14). Real table (`_samplesTable`,
 * kext address `0x4c268`) content now extracted for its whole real used
 * range (byte offsets `0x00`-`0x3c`, 16 real `UInt32` entries) - see
 * `kSamplesTable` in `Sources/ATIRadeonX1000_DataTables.cpp`. Real
 * content: every entry is 0 except index 4 (byte offset `0x10`, value
 * `2`) and index 6 (byte offset `0x18`, value `3`) - consistent with a
 * real "raw hardware sample-count field -> normalized 0-3 sample-mode"
 * remap table where only two raw bit patterns this driver actually emits
 * map to a non-zero mode. CAUTION found while extracting: a real,
 * different, unrelated local static also named `samplesTable` exists in
 * the kext (mangled `ATIR500Surface::load_3d_blit`-local, kext address
 * `0x4c2f4`) - confirmed NOT the same symbol as this one (`_samplesTable`
 * at `0x4c268`, the one this project's own `resolve_fsaa_buffer`
 * transcription actually references) before trusting either.
 */
extern "C" UInt32 SamplesTableLookup(UInt32 byteOffset);

/*
 * ============================================================================
 * The ~24 opaque FUN_XXXXXXXX helpers - issue #15 STILL OPEN. Real
 * narrowing found below, but the issue's actual ask (identifying what
 * these functions are) is NOT satisfied - corrected after an earlier
 * pass wrongly closed this issue; see GAPS.md section 12 and the issue's
 * own reopen comment for the full account of that correction.
 * ============================================================================
 *
 * Every one of the 28 real kext-local `FUN_XXXXXXXX` symbols this project
 * had called opaquely throughout (`FUN_00007424`, `FUN_000147f0`,
 * `FUN_00014810`, `FUN_00014820`, `FUN_00014850`, `FUN_00015870`,
 * `FUN_000158b0`, `FUN_000158c0`, `FUN_000158d0`, `FUN_000158e0`,
 * `FUN_00015a84`, `FUN_00015aa4`, `FUN_000286dc`, `FUN_00029da8`,
 * `FUN_0002a864`, `FUN_000314c4`, `FUN_000334cc`, `FUN_0003577c`,
 * `FUN_000357ac`, `FUN_000390dc`, `FUN_0003911c`, `FUN_0003913c`,
 * `FUN_00044868`, `FUN_00044d74`, `FUN_0001a194`, `FUN_0001a274`,
 * `FUN_0001a2e4`, `FUN_0001a204`) is, in the real kext binary, a REAL
 * LAZY-BINDING STUB TRAMPOLINE - not a local function this project failed
 * to decompile. (`FUN_00044d74` added by the issue #17 investigation -
 * `ATIR500Surface::back_resolve_fsaa_buffer`'s own call-site instance of
 * the same real stub, independently confirmed via direct disassembly to
 * have the identical 4-instruction shape - almost certainly the same real
 * external target as `FUN_00044868`, just this call site's own distinct
 * per-reference stub symbol; does not change this issue's own open
 * status. `FUN_0001a194`/`FUN_0001a274`/`FUN_0001a2e4`/`FUN_0001a204`
 * added by the issue #21 investigation - `ATIRadeonX1000`'s four
 * context-factory methods' own real allocator calls, each its own
 * per-call-site stub instance, almost certainly all resolving to
 * `operator new(unsigned long)` rather than the same external target as
 * the other 24 - a real, distinct external symbol from this catalog's
 * other entries, still genuinely unidentified either way; does not
 * change this issue's own open status.)
 * Each one's real body is exactly the same real 4-instruction sequence
 * (`lis r12,0x0; ori r12,r12,0x0; mtspr CTR,r12; bctr`), with LITERAL
 * ZERO immediates in the static binary - a real external-symbol call
 * stub whose actual target gets patched in only when the kext is loaded
 * onto real hardware (by Apple's `kxld` linker, resolving against
 * whatever kernel/companion-kext symbol table exists at boot time), the
 * SAME real category of "genuinely not present in this static file"
 * limitation issue #6 already established for the accelerator's own
 * four context-factory vtable words.
 *
 * FOUND, not assumed: this project's original issue #15 filing expected
 * ~24 small internal functions with real, if opaque, bodies to
 * decompile. Direct inspection (every one of the 23 addresses has a
 * function defined, `bodySize=16` bytes, `params=0`) immediately showed
 * the trampoline shape; CONFIRMED it's a genuine unresolved-external
 * case (not just an un-analyzed local call) via three independent
 * checks, matching the same rigor issue #6 already used: (1) this
 * binary has NO `LC_DYSYMTAB` at all (an older, Tiger/Leopard-era kext
 * format lacking the dynamic-linking load command modern Mach-O
 * binaries use for lazy stubs - a real, confirmed structural fact about
 * this specific file, not an analysis gap); (2) the `__text` section's
 * own per-section relocation table (`nreloc=11622`) was read directly
 * and did NOT resolve to any real symbol name at these specific
 * addresses; (3) Ghidra's own original full-analysis import (not just
 * this pass's own read-only re-checks) recorded ZERO real references
 * from any of these 23 stub addresses - the same tool that correctly
 * resolves thousands of other real internal calls throughout this same
 * binary found nothing to resolve here either.
 *
 * A twenty-fourth symbol from this project's own original issue #15
 * filing, `FUN_0002c790`, is REMOVED from this list - a real
 * miscategorization caught during this investigation: that address
 * belongs to a completely different, out-of-scope binary
 * (`ATIRadeonX1000GLDriver.bundle`, a userspace driver - see
 * `ATIRadeonX1000Types.h`'s own `VendorCommandBufferHeader` comment for
 * the original citation), not this kext at all - no function is defined
 * there in this kext's own Ghidra project, correctly, since it was
 * never really part of this binary.
 *
 * This project's own earlier ROLE-LEVEL inferences (derived from real
 * call-site signature/usage analysis, independent of ever seeing these
 * functions' own bodies) remain the real, standing understanding for
 * each - lock/unlock pairs, an alloc/free pair, transfer-buffer
 * GART-mapping helpers, atomic packed-counter/refcount helpers, and the
 * blit-state-packet template-copy helper (see each symbol's own
 * declaration site for its specific role). This predates the current
 * investigation and is NOT the same as satisfying issue #15's actual
 * ask ("confirmed... once identified") - no real symbol name has been
 * recovered for any of these 23 functions. What this pass DID establish
 * with certainty is WHY no further static decompilation work will ever
 * recover more than role-level inference: there is no local body to
 * decompile in this file, full stop. Recovering each stub's exact real
 * symbol name (e.g. confirming `FUN_000147f0` really is `IOLockLock` or
 * equivalent) would require either live kxld-resolved memory on real
 * hardware, or a real kernel/IOKit KPI export-symbol list to
 * cross-reference against by address - neither available in this
 * sandboxed environment. Issue #15 stays open until one of those paths
 * is actually available, same standing as issue #6.
 */

#endif /* ATIRADEONX1000_REGISTERS_H */
