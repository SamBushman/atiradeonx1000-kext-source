# Shader-compiler IR and pass framework in ATIRadeonX1000GLDriver (ppc)

Reverse-engineering notes. Everything here was recovered by static analysis of this corpus (`part_*.c`, `data/*.c`); the facts are marked
**CONFIRMED** (the binary shows it: RTTI, strings, a layout read and written by one function and used by another), **INFERRED** (the role is clear from use,
nothing names it) or **UNKNOWN**. Generated tables: `class_methods.tsv` (every function that stores a class vtable or sits in a vtable slot),
`names_R2_*.tsv` (the names this analysis produced).

## 1. The binary contains the compiler's C++ RTTI (CONFIRMED)

The driver embeds ATI's shader compiler (R300/R520 "Khan/Fudo" family). Its classes keep their Itanium-ABI RTTI: every vtable is `[offset-to-top=0][typeinfo*][slots...]`,
the typeinfo is `[__si_class_type_info vptr][mangled name*][base typeinfo*]` (`__DATA,__const_coal` at `0x1f0f08..`, names in `__TEXT,__const_coal` at `0x1cc164..`).
Reading them gives 356 class names and the full single-inheritance tree (the tree below is the output of a scan over the data sections, not hand-written).
A constructor/destructor stores `vtable+8` (the address of slot 0) at `*this`; in the corpus that is `&PTR_FUN_<slot0>` or `PTR_DAT_<nl_symbol_ptr entry> + 8`
(the non-lazy pointer holds the vtable address). 872 functions are classified in `class_methods.tsv`: 110 constructors, 265 deleting destructors
(they end in `operator_delete`), 361 complete destructors, 136 virtual-slot functions (classified by position in the vtable).

Slot meaning: slot 0 = complete destructor, slot 1 = deleting destructor (GCC 4 layout). For the `Block` family slot 2 is a clone factory
(`FUN_000e9e88`: allocate `0x130` bytes from the compiler's arena, run the copy constructor `FUN_000e9d68`, return the object; INFERRED name `clone`).

### 1.1 Class tree (vtable address, slot count, a few methods)

- `DListNode` (vtable `0x1f1008`, 2 slots) - FUN_00171e68 dtor, FUN_001cd810 virtual-slot0, FUN_001cd834 virtual-slot1
  - `Block` (vtable `0x1e9b00`, 3 slots) - FUN_000e9d68 ctor, FUN_000e9f00 ctor, FUN_000ea020 ctor, FUN_000ea148 ctor, FUN_000ea270 dtor, FUN_000ebbb0 virtual-slot0...
    - `AnyBlock` (vtable `0x1f1158`, 3 slots) - FUN_000e9e88 virtual-slot2, FUN_000ea3c0 ctor, FUN_000ea478 ctor, FUN_001cde9c virtual-slot0, FUN_001cdec0 virtual-slot1
    - `BreakOrContinueBlock` (vtable `0x1f1100`, 3 slots) - FUN_001ce388 virtual-slot0, FUN_001ce3ac virtual-slot1
      - `BreakBlock` (vtable `0x1e9e18`, 3 slots) - FUN_000ebe70 ctor, FUN_000ebeb4 ctor, FUN_000ebef8 virtual-slot2, FUN_000ec070 ctor, FUN_000ec0c8 ctor, FUN_001ce53c virtual-slot0...
      - `ContinueBlock` (vtable `0x1e9e70`, 3 slots) - FUN_000ebf70 ctor, FUN_000ebfb4 ctor, FUN_000ebff8 virtual-slot2, FUN_000ec120 ctor, FUN_000ec178 ctor, FUN_001ce414 virtual-slot1...
    - `EntryBlock` (vtable `0x1e9f20`, 4 slots) - FUN_000e7cf0 virtual-slot3, FUN_000eab70 ctor, FUN_000eabbc ctor, FUN_001cde34 virtual-slot1, FUN_001ce518 virtual-slot0
    - `ExitBlock` (vtable `0x1e9ec8`, 3 slots) - FUN_000eaae8 ctor, FUN_000eab2c ctor, FUN_001ce48c virtual-slot0, FUN_001ce4b0 virtual-slot1
    - `FuncEndBlock` (vtable `0x1e9b58`, 3 slots) - FUN_000eb2b0 ctor, FUN_000eb300 virtual-slot2, FUN_000eb378 ctor, FUN_001cdf28 virtual-slot0, FUN_001cdf4c virtual-slot1
    - `IfFooter` (vtable `0x1e9d68`, 3 slots) - FUN_000eb068 ctor, FUN_000eb0ac virtual-slot2, FUN_000eb124 ctor, FUN_0012e56c ctor, FUN_001ce270 virtual-slot0, FUN_001ce294 virtual-slot1...
      - `IfFooterStatic` (vtable `0x1e9dc0`, 3 slots) - FUN_000eb7e0 ctor, FUN_000eb824 ctor, FUN_000eb868 virtual-slot2
    - `IfHeader` (vtable `0x1e9cb8`, 3 slots) - FUN_000ea530 ctor, FUN_000ea600 ctor, FUN_000ea6d0 ctor, FUN_000eb168 ctor, FUN_000eb1d0 virtual-slot2, FUN_000eb248 ctor...
      - `IfHeaderStatic` (vtable `0x1e9d10`, 3 slots) - FUN_000eb8e0 ctor, FUN_000eb924 ctor, FUN_000eb968 virtual-slot2, FUN_000eb9e0 ctor, FUN_000ebac8 ctor
    - `LoopFooter` (vtable `0x1e9c08`, 3 slots) - FUN_000eadd0 ctor, FUN_000eae20 virtual-slot2, FUN_000eae98 ctor, FUN_001ce040 virtual-slot0, FUN_001ce064 virtual-slot1
    - `LoopHeader` (vtable `0x1e9bb0`, 3 slots) - FUN_000eaee8 ctor, FUN_000eaf6c virtual-slot2, FUN_000eafe4 ctor, FUN_001cdfb4 virtual-slot0, FUN_001cdfd8 virtual-slot1
    - `MirrorBlock` (vtable `0x1f64b8`, 3 slots) - FUN_001d85a0 virtual-slot1, FUN_001d8608 virtual-slot0
    - `PostLoopFooter` (vtable `0x1e9c60`, 3 slots) - FUN_000ea828 ctor, FUN_000eacb8 ctor, FUN_000ead08 virtual-slot2, FUN_000ead80 ctor, FUN_000eb3c8 ctor, FUN_001ce0cc virtual-slot0...
  - `IRInst` (vtable `0x1e9fc0`, 5 slots) - FUN_0010502c ctor, FUN_001051b0 ctor, FUN_001cd908 dtor, FUN_001cd970 dtor, FUN_001cd9c4 dtor, FUN_001cda2c dtor...
    - `IRAlu` (vtable `0x1f1308`, 5 slots) - FUN_00105a44 virtual-slot4, FUN_00105b7c virtual-slot3, FUN_0010647c virtual-slot2
      - `IRBinary` (vtable `0x1f1530`, 5 slots)
        - `IRCmp2` (vtable `0x1f15d8`, 5 slots)
        - `IRKill2` (vtable `0x1f1468`, 5 slots)
      - `IRExport` (vtable `0x1ea110`, 5 slots) - FUN_001085b0 ctor, FUN_00108918 ctor
        - `IRExportColorAndFog` (vtable `0x1f1748`, 5 slots)
        - `IRGeomExport` (vtable `0x1f1690`, 5 slots)
      - `IRTrinary` (vtable `0x1f2660`, 5 slots)
      - `IRUnary` (vtable `0x1f25b8`, 5 slots)
        - `IRMov` (vtable `0x1f24f0`, 5 slots)
      - `IRZeroary` (vtable `0x1f2718`, 5 slots)
        - `IRNop` (vtable `0x1f27d0`, 5 slots)
    - `IRFetch` (vtable `0x1f18c8`, 5 slots)
      - `IRMemLoad` (vtable `0x1f1970`, 5 slots)
      - `IRMemStore` (vtable `0x1f1800`, 5 slots)
      - `IRTextureFetch` (vtable `0x1f1af0`, 5 slots)
        - `IRTextureFetchGradients` (vtable `0x1f1a28`, 5 slots)
      - `IRVertexFetch` (vtable `0x1f1b98`, 5 slots) - FUN_001073dc ctor, FUN_00107420 ctor
    - `IRPseudo` (vtable `0x1f0f60`, 5 slots) - FUN_001cd86c virtual-slot0, FUN_001cd8b0 virtual-slot1
      - `IRCmp1S` (vtable `0x1f13b0`, 5 slots)
      - `IREndCallRoutine` (vtable `0x1e9840`, 5 slots)
      - `IREndMakeCall` (vtable `0x1e9990`, 5 slots)
      - `IREntry` (vtable `0x1f2380`, 5 slots) - FUN_00108d10 ctor, FUN_00108d5c ctor
      - `IRExit` (vtable `0x1f22c8`, 5 slots) - FUN_00108da8 ctor, FUN_00108df4 ctor
      - `IRHeader` (vtable `0x1f2438`, 5 slots)
      - `IRImmedConstBuff` (vtable `0x1f1dc0`, 5 slots)
      - `IRLoad` (vtable `0x1f1260`, 5 slots)
        - `IRLoadConst` (vtable `0x1ea458`, 5 slots) - FUN_00104e20 virtual-slot3, FUN_00109614 ctor, FUN_001096bc ctor, FUN_00109938 ctor, FUN_001099dc ctor
        - `IRLoadInterp` (vtable `0x1f20a0`, 5 slots)
        - `IRLoadMemBuffer` (vtable `0x1f1fe8`, 5 slots) - FUN_00109100 ctor, FUN_0010914c ctor
        - `IRLoadMemBufferIndex` (vtable `0x1f1f30`, 5 slots) - FUN_00109068 ctor, FUN_001090b4 ctor
        - `IRLoadTemp` (vtable `0x1f2158`, 5 slots)
        - `IRLoadVertex` (vtable `0x1f2210`, 5 slots)
        - `IRUndefined` (vtable `0x1f1e78`, 5 slots)
      - `IRLoopStart` (vtable `0x1f1c50`, 5 slots)
      - `IRMerge` (vtable `0x1f1d08`, 5 slots)
      - `IRMix` (vtable `0x1ea068`, 5 slots) - FUN_00106ba0 virtual-slot2, FUN_0010a140 ctor, FUN_0010a1c0 ctor
      - `IRPhiNode` (vtable `0x1ea1b8`, 5 slots) - FUN_00106780 virtual-slot2, FUN_0010a2bc ctor, FUN_0010a398 ctor
      - `IRPresub1` (vtable `0x1ea260`, 5 slots) - FUN_00106cb4 virtual-slot2, FUN_00109f00 ctor, FUN_00109f50 ctor
      - `IRPresub2` (vtable `0x1ea308`, 5 slots) - FUN_0010673c virtual-slot2, FUN_0010a01c ctor, FUN_0010a070 ctor
      - `IRProjection` (vtable `0x1ea3b0`, 5 slots) - FUN_001066e8 virtual-slot2, FUN_00109dcc ctor, FUN_00109e28 ctor
      - `IRStartCallRoutine` (vtable `0x1e9798`, 5 slots)
      - `IRStartMakeCall` (vtable `0x1e98e8`, 5 slots)
  - `SchedNode` (vtable `0x1f6520`, 2 slots) - FUN_001d862c virtual-slot0, FUN_001d8660 virtual-slot1
- `HwChip` (vtable `0x1f2890`, 2 slots) - FUN_001d01b0 virtual-slot0, FUN_001d01d4 deleting-dtor
  - `KhanChip` (vtable `0x1ead60`, 3 slots) - FUN_0010e050 ctor, FUN_0010e114 ctor, FUN_001d834c deleting-dtor, FUN_001d8380 virtual-slot0
    - `FudoChip` (vtable `0x1eb5e0`, 3 slots) - FUN_00191c6c virtual-slot2, FUN_001d8af4 deleting-dtor, FUN_001d8b7c virtual-slot0
- `HwLimits` (vtable `0x1ea5a8`, 2 slots) - FUN_0010dad8 dtor, FUN_0010db58 dtor, FUN_001cffa4 virtual-slot0, FUN_001cffc8 deleting-dtor
  - `KhanPs` (vtable `0x1ead80`, 2 slots) - FUN_00128fd0 ctor, FUN_00129130 ctor, FUN_001d8318 deleting-dtor, FUN_001d83b4 virtual-slot0
    - `FudoPs` (vtable `0x1eb448`, 2 slots) - FUN_00191efc ctor, FUN_001920e0 ctor, FUN_001d8b38 deleting-dtor, FUN_001d8bc0 virtual-slot0
  - `KhanVs` (vtable `0x1eaf18`, 2 slots) - FUN_0012a578 ctor, FUN_0012a6c0 ctor, FUN_001d84ac deleting-dtor, FUN_001d84e0 virtual-slot0, FUN_001d8514 deleting-dtor, FUN_001d8548 dtor
    - `FudoVs` (vtable `0x1eb0b8`, 2 slots) - FUN_0012a808 ctor, FUN_0012a8bc ctor
- `MachineAssembler` (vtable `0x1e9a38`, 1 slots) - FUN_00196e3c dtor, FUN_0019b91c dtor, FUN_0019b9ac dtor, FUN_0019deb0 dtor, FUN_0019df54 dtor, FUN_001cd7ec virtual-slot0
  - `R300MachineAssembler` (vtable `0x1eb698`, 10 slots) - FUN_00195574 virtual-slot6, FUN_00195578 virtual-slot8, FUN_00195580 virtual-slot3, FUN_00195584 virtual-slot9, FUN_001955f8 virtual-slot2, FUN_001961c8 virtual-slot4...
    - `R520MachineAssembler` (vtable `0x1eb9a0`, 10 slots) - FUN_0019ef50 virtual-slot5, FUN_0019f860 virtual-slot9, FUN_0019fccc virtual-slot4, FUN_001d8f58 virtual-slot1, FUN_001d8fc0 virtual-slot0
  - `R300VMachineAssembler` (vtable `0x1eb800`, 3 slots) - FUN_0019a618 virtual-slot2, FUN_0019ba3c virtual-slot1
    - `R520VMachineAssembler` (vtable `0x1eb8d0`, 3 slots) - FUN_0019dcb0 virtual-slot1
- `OpcodeInfo` (vtable `0x1f28f8`): 256 `Ir<Name>` subclasses (one per IR opcode: IrAdd, IrMul, IrMad, IrDot4, IrRecipSqrtFF, IrTextureMap..., see list below); non-virtual, only destructors are generated
- `ResourceModel` (vtable `0x1eb258`, 2 slots) - FUN_001d86b4 virtual-slot1, FUN_001d8874 virtual-slot0
  - `R300SchedModel` (vtable `0x1eb320`, 0 slots) - FUN_001d8944 dtor
    - `R520SchedModel` (vtable `0x1eb600`, 5 slots) - FUN_00189604 virtual-slot2, FUN_0018f42c virtual-slot4, FUN_0018f55c virtual-slot3, FUN_00191e28 ctor, FUN_001d8c18 virtual-slot1, FUN_001d8c70 virtual-slot0
  - `R300VSchedModel` (vtable `0x1eb3b8`, 5 slots) - FUN_0018f824 virtual-slot2, FUN_001904b8 virtual-slot4, FUN_001906c8 virtual-slot3, FUN_001d8a28 virtual-slot0, FUN_001d8a5c virtual-slot1
- `ThreadModel` (vtable `0x1eb2e8`, 2 slots) - FUN_001d87a8 virtual-slot1, FUN_001d8850 virtual-slot0
- `VRegInfo` (vtable `0x1f6170`, 2 slots) - FUN_001d7950 virtual-slot0, FUN_001d7974 virtual-slot1
  - `AddrIndexedSet` (vtable `0x1f6358`, 2 slots) - FUN_001d7b68 virtual-slot0, FUN_001d7b9c virtual-slot1
  - `ExportAddress` (vtable `0x1f61a8`, 2 slots) - FUN_001d7cdc virtual-slot0, FUN_001d7d10 virtual-slot1
  - `ExportSlot` (vtable `0x1ea7e8`, 3 slots) - FUN_001241fc virtual-slot2, FUN_0012622c ctor, FUN_00126378 ctor, FUN_001d7ecc virtual-slot0, FUN_001d7f00 virtual-slot1
  - `ExportValue` (vtable `0x1ea740`, 2 slots) - FUN_00124e68 ctor, FUN_001250dc ctor, FUN_001d7d58 virtual-slot0, FUN_001d7d8c virtual-slot1
  - `FixedValue` (vtable `0x1ea890`, 3 slots) - FUN_0012447c virtual-slot2, FUN_001245a8 ctor, FUN_00124724 ctor, FUN_001d8040 virtual-slot0, FUN_001d8074 virtual-slot1
  - `ImmedConstBuffer` (vtable `0x1ea8c8`, 3 slots) - FUN_001230e4 virtual-slot2, FUN_001261a4 ctor, FUN_001261e8 ctor, FUN_001d79ac virtual-slot1, FUN_001d80bc virtual-slot0
  - `Interpolator` (vtable `0x1ea778`, 2 slots) - FUN_00125350 ctor, FUN_001257b0 ctor, FUN_001d7dd4 virtual-slot0, FUN_001d7e08 virtual-slot1
  - `LoopIndexedSet` (vtable `0x1f6248`, 2 slots) - FUN_001d7c60 virtual-slot0, FUN_001d7c94 virtual-slot1
    - `LoopIndexedConstSet` (vtable `0x1f62c8`, 2 slots) - FUN_001264c4 ctor, FUN_00126538 ctor, FUN_001d80f0 virtual-slot0, FUN_001d8134 virtual-slot1
    - `LoopIndexedInputSet` (vtable `0x1f6280`, 2 slots) - FUN_001265ac ctor, FUN_00126620 ctor, FUN_001d818c virtual-slot0, FUN_001d81d0 virtual-slot1
    - `LoopIndexedOutputSet` (vtable `0x1f61f0`, 2 slots) - FUN_00126080 ctor, FUN_00126694 ctor, FUN_001d8228 virtual-slot0, FUN_001d826c virtual-slot1
  - `LoopRegister` (vtable `0x1f6310`, 2 slots) - FUN_001d7be4 virtual-slot0, FUN_001d7c18 virtual-slot1
  - `Physical` (vtable `0x1f6430`, 2 slots) - FUN_00125c10 ctor, FUN_00125c8c ctor, FUN_001d7aec virtual-slot0, FUN_001d7b20 virtual-slot1
  - `Resource` (vtable `0x1ea820`, 3 slots) - FUN_0012434c virtual-slot2, FUN_00125d08 ctor, FUN_00125d60 ctor, FUN_001d7f48 virtual-slot0, FUN_001d7f7c virtual-slot1
  - `TempValue` (vtable `0x1ea7b0`, 3 slots) - FUN_00124938 ctor, FUN_00124e04 ctor, FUN_001d79f4 dtor, FUN_001d7a3c dtor, FUN_001d7a70 dtor, FUN_001d7ab8 dtor...
    - `PrimitiveIndex` (vtable `0x1f63a0`, 3 slots) - FUN_001240a8 virtual-slot2, FUN_0012499c ctor, FUN_00125db8 ctor
    - `StandardIndex` (vtable `0x1f63e8`, 3 slots) - FUN_00124b24 ctor, FUN_00124c94 ctor
  - `VertexRegister` (vtable `0x1ea858`, 3 slots) - FUN_00123288 virtual-slot2, FUN_001248a0 ctor, FUN_001248ec ctor, FUN_001d7fc4 virtual-slot0, FUN_001d7ff8 virtual-slot1


### 1.2 `OpcodeInfo` subclasses (one per IR opcode)

`OpcodeInfo` (vtable `0x1f28f8`) has 256 subclasses named `Ir<Opcode>` with no virtual functions. They are the opcode descriptors
that an `IRInst` points at (`IRInst+0x88`, section 3): Add, AddConst0, AddConst1, AddFloat, AddInt, AddPrev, Alloc, AllocColor, AllocInterp, AllocMem, AllocPos, AndInt, AshrInt, CbLoad, Ceil, CmovEQ, CmovGE, CmovGT, CmovNE, Cmp1D, Cmp1S, Cmp2, Cnd05, CndE, CndE1, CndEFloat, CndEInt, CndGE, CndGE1, CndGEFloat, CndGEInt, CndGT, CndGT1, CndGTFloat, CndGTInt, CondJmp, Cos, Cube, Cut, Dot2Add, Dot2AddIEEE, Dot3, Dot3IEEE, Dot4, Dot4IEEE, Dp3Add, Dst, Dsx, Dsx1, Dsy, Dsy1, DxLogp, DyamicReturn, DyamicReturnSwitch, Emit, EmitThenCut, EndCall, EndMakeCall, Entry, Epilog, Exit, Exp, Export, ExportFloat, ExportRing, F2Int, F2UInt, Fetch3DNoiseMap, FetchLoad, FetchMultiSample, FetchShaderCall, FetchShadowMap, FetchTextureLOD, FetchTextureMap, FetchTextureMapBias, FetchTextureMapGradients, FetchTextureMapKill, FetchTextureMapProj, FetchTextureUncached, FetchVertex, Floor, FloorFloat, Fract, FractFloat, GetBorderColorFraction, GetCompTexLod, GetGradients, GetResource, GetWeights, Header, ImmedConstBuffer, ImmedConstLoad, Int2F, KillE, KillEFloat, KillGE, KillGEFloat, KillGT, KillGTFloat, KillNE, KillNEFloat, KillOne, LdBuffer, Lit, Load, LoadAbstractState, LoadConst, LoadInterp, LoadPhysical, LoadTemp, LoadTempDefault, LogClamp, LogIEEE, LogInternal, LoopIndex, LoopStart, LshlInt, LshrInt, Mad, Max, Max4, MaxDx10, MaxFloat, MaxInt, MaxUInt, MemInit, Merge, Min, MinDx10, MinFloat, MinInt, MinUInt, Mix, Mov, MovFloat, MovaFloor, MovaFloorFloat, MovaFloorGprInt, MovaFloorInt, MovaFlr, MovaRound, MovaRoundFloat, Mul, MulAdd, MulAddFloat, MulAddIEEE, MulConst0, MulConst1, MulFloat, MulHiInt, MulHiUInt, MulIEEE, MulLit, MulLowInt, MulLowUInt, MulPrev, MulPrev2, Nop, Nop1, NotInt, OpDp, OpSop, OrInt, Phi, PixelLoopFetch, Pow, PredSetClr, PredSetE, PredSetEInt, PredSetEPush, PredSetEPushInt, PredSetGE, PredSetGEInt, PredSetGEPush, PredSetGEPushInt, PredSetGT, PredSetGTInt, PredSetGTPush, PredSetGTPushInt, PredSetInv, PredSetLEInt, PredSetLEPushInt, PredSetLTInt, PredSetLTPushInt, PredSetNE, PredSetNEInt, PredSetNEPush, PredSetNEPushInt, PredSetPop, PredSetRst, PresubAdd, PresubBX2Neg, PresubInvert, PresubSub, Projection, Prolog, PsColorFog, R300ExpBaseE, R300Expp, RecipClamp, RecipFF, RecipIEEE, RecipInt, RecipInternal, RecipSqrtClamp, RecipSqrtFF, RecipSqrtIEEE, RecipSqrtInternal, RecipUInt, Ret, RoundNearestEven, SampleC, SampleCLZ, SampleG, SampleL, Scatter, ScratchLoad, ScratchStore, SetE, SetEFloat, SetEInt, SetE_Dx10, SetFilter4Weights, SetGE, SetGEFloat, SetGEInt, SetGE_Dx10, SetGE_uint, SetGT, SetGTDx10, SetGTFloat, SetGTInt, SetGTUint, SetGradientsH, SetGradientsV, SetNE, SetNEFloat, SetNEInt, SetNE_Dx10, SetTexLod, Sin, Sqrt, StartCallRoutine, StartMakeCall, Sub, SubConst0, SubConst1, SubInt, SubPrev, Trunc, TruncFloat, UInt2F, Undefined, VertexLoopFetch, WhileStart, XorInt.

## 2. Infrastructure used everywhere

| function | what it is | evidence |
|---|---|---|
| `FUN_00193e18(arena, size)` | **Arena::alloc** - bump allocator. `size` rounded up to 4; if `cursor+size > limit` calls `FUN_00193d98` (grow: new chunk of at least 0x2fd8 bytes, chunk list at +4, `FUN_000e1564` allocates it). Records the last allocation at +0x14, returns the cursor. Arena fields: +8 cursor, +0x10 limit, +0x14 last allocation, +0x28 "may rewind" flag | CONFIRMED (code) |
| `FUN_00193cc0(arena, p)` | **Arena::free** - only rewinds when `p` is the last allocation: zeroes `[p, cursor)` and sets cursor back | CONFIRMED |
| objects `new`ed in an arena | the arena pointer is stored in the word **before** the object (`block = alloc(size+4); block[0]=arena; obj = block+1`); free uses `*(obj-4)`. Used by `Block` (0x130 = 0x12c + 4), `IRInst`-family (0x168) and vectors (0x14) | CONFIRMED (`FUN_000e9e88`, `FUN_000e8938`, `FUN_000e8a08`) |
| `FUN_0019423c(vec, index)` | **Vector::ElementRef** - growable array of `{capacity, count, data, arena}` (words 0..3). Grows (doubling capacity), copies, frees the old data into the arena, bumps `count` to `index+1`, returns `&data[index]`. Callers inline the fast path: if `index < capacity`, then (if `count <= index`, zero-fill and `count = index+1`), `p = &data[index]` | CONFIRMED |
| Block ctors / `FUN_000e8a08` | create 0x14-byte vector blocks from the arena: `blk[0]=arena; blk[1]=2 (capacity); blk[2]=0 (count); blk[3]=data=alloc(8); blk[4]=arena` | CONFIRMED |
| bit sets | `alloc(words*4+0xc)`: `[arena][words][bit count][bits...]`, e.g. in the pass `FUN_000fd5c8`; `FUN_000e8124(compiler, ...)` finds/sets a free bit in the bit set at `compiler+0x3bc` (used to hand out Block slot ids) | INFERRED |
| `DListNode` (`FUN_001940a8` init, `FUN_00193fb4` clear, `FUN_00193f64/f94` insert back/front, `FUN_0019401c` unlink) | intrusive doubly linked list; the list head is a sentinel whose vtable is `DListNode`'s | CONFIRMED (`FUN_001940a8` stores the vtable, count, sentinel links) |

## 3. `IRInst` (CONFIRMED unless marked)

Constructors `FUN_001051b0(this, opcode, compiler)` and `FUN_0010502c` (same body; `FUN_001070f8(this, opcode, compiler)` is `IRPseudo`: it calls `FUN_001051b0`, ORs `0x18000` into the flags
and sets the `IRPseudo` vtable). The opcode is passed by every leaf class (`IREntry` passes `0x87`, `IRExit` `0x88`, `IRPhiNode` `0x8e`, `IRExport` `0x30` through `FUN_001071a8`).

| offset | field | evidence |
|---|---|---|
| +0x00 | vtable | ctor |
| +0x04/+0x08 | list links (prev/next, `DListNode`-style), zeroed | ctor |
| +0x10 | debug vector (only when `*(compiler+0x6c4)+0x30 & 0x80`: allocated from the arena at `compiler+0x378`) | ctor |
| +0x14 | flag word; bit 0 set by the ctor; `FUN_00103d50(obj, mask, set)` sets/clears bits in it | CONFIRMED (`FUN_00103d50`), bit meaning UNKNOWN |
| +0x88 | opcode info = `FUN_00112f54(opcode)` = `*(&DAT_001fc2b0 + opcode*4)`; the opcode's `Ir<Name>` object; its virtual `[0]` is called with `(info, inst, compiler)` right after construction | CONFIRMED |
| +0x8c.. | 5 inline operand records of 0x18 bytes (`FUN_00104bbc` resets one) | CONFIRMED |
| +0x118 | growable vector of further operand records (operand index >= 5) | CONFIRMED (`FUN_001054ec`) |
| +0x14c | instruction id = `compiler->+0x324++` | CONFIRMED |
| +0x158 | owning `Block` (set by `FUN_000e8938`) | CONFIRMED |
| +0x15c (byte), +0x160 | flags, UNKNOWN | ctor |

Operand access: `FUN_001054ec(inst, n)` returns the record (`n<5`: `inst+0x8c+n*0x18`, else element `n-5` of the vector at `+0x118`); `FUN_00105594(inst, n)` returns the record's field `+4`
(0 if absent), used by callers as a virtual-register object (INFERRED: it has a vector at `+0x10`). `FUN_001046c8(inst, n, src)` stores `src` into record `n`
(`+0` = src, `+8` = src[2], `+0xc` = src[1]) and for `n == 0` caches a virtual call result (`src->vfn[9]()`) at `inst+0x128`.
`FUN_001043f0(opcode, compiler)` is the instruction factory: class index from `FUN_00113388` (the program object at `compiler+0x30c`, virtual slot `0x16c/4`, entry `+0x30` of a 0x38-byte per-opcode record), the registered
constructor table at `&DAT_001ea4fc` (8-byte entries), then `inst+0x88 = FUN_00112f54(opcode)`.

## 4. `Block` (control-flow graph node) (CONFIRMED unless marked)

`FUN_000e9d68(this, src)` is the copy constructor, `FUN_000e9f00`/`FUN_000ea020`/`FUN_000ea148` are variants that build a fresh block (`this[0x2a] = compiler`).
Block derives `DListNode` (vtable `0x1f1008`); `this+0x90` (word 0x24) is an embedded `DListNode`, the list of the block's instructions, and `this+0xc8/+0xcc` are two pseudo instructions created by `FUN_000e8938`
(`FUN_00108d5c` = `IREntry`, `FUN_00108df4` = `IRExit`, each with `+0x158` set back to the block). `FUN_000e8a08` allocates the block's 2-entry vectors
(`+0xc4,+0xd0,+0xf4,+0xf8,...`).

| offset | field |
|---|---|
| +0x0c | copied from the source block (word 3) |
| +0xa8 | compiler |
| +0xac | parent/owner (copied from source, 0 in fresh blocks) - UNKNOWN role |
| +0xb0 | block id = `compiler->+0x32c++` |
| +0xb4 | slot id from `FUN_000e8124(compiler..)` (bit-set allocation) - INFERRED |
| +0xe4/+0xe8, +0x118 | initial values `0x7fffffff` (a pair) and `0xffffffff` - UNKNOWN meaning |

Subclasses (section 1.1): structured-control-flow blocks (`IfHeader`/`IfFooter` (+`Static`), `LoopHeader`/`LoopFooter`/`PostLoopFooter`, `Break/ContinueBlock`, `Entry/Exit/FuncEndBlock`, `AnyBlock`, `MirrorBlock`).

## 5. Compiler context

The object most pass functions receive (a parameter or `pass+8`). Fields established by use:

| offset | field | evidence |
|---|---|---|
| +0x374 | arena A | first argument of `FUN_00193e18` (Block's vectors) |
| +0x378 | arena B | first argument of `FUN_00193e18` (pass work vectors/bit sets, IRInst debug vector) |
| +0x324 | next instruction id | `IRInst` ctor |
| +0x32c | next block id | `Block` ctor |
| +0x30c | the program/function object; virtual calls at slots `0x60/4`, `0x16c/4` | `FUN_000e07dc`, `FUN_00113388` |
| +0x384 (900) | head of a listener list; `FUN_000ed7e4(compiler, name)` calls virtual slot `0x48/4` of each listener with the pass name | CONFIRMED (`FUN_000ed7e4`) |
| +0x3a0 | entry block (passed to `FUN_000e79d0`, `FUN_000ec3ac`) | INFERRED |
| +0x3bc | bit set handing out ids | INFERRED |
| +0x3c4 | vector of all instructions; `FUN_000ed7e4` clears bit 0 of `+0x14` in each | CONFIRMED |
| +0x6c4 | target/options object (flags at `+0x30`; bit `0x80` = keep debug vectors) | CONFIRMED |
| +0xc/+0x18 | callbacks (`(**(code **)(compiler + 0xc))(n)`); in some functions the parameter named `compiler` is a different object | UNKNOWN |

## 6. Passes

`FUN_000ed7e4(compiler, "name")` marks the start of a pass (notifies listeners, clears per-instruction dirty bits). Functions that call it with a literal:

| function | pass name |
|---|---|
| `FUN_001214fc` | `ssa_build` |
| `FUN_0012ab80` | `optimize_control_flow` |
| `FUN_0012ccc0` | `loop_trans` |
| `FUN_0012d2f0` | `flatten_ifs` |
| `FUN_001300b0` | `remove_empty_graphs` |
| `FUN_00135fb0` | `color_graph` (register allocation by graph colouring) |
| `FUN_0013d160` | `rewrite` |
| `FUN_00145670` | `post_pack_insts` |
| `FUN_00171714` | `sched_preprocess`, `schedule_inst` |
| `FUN_00184ab4` | `minreg_order` |

Tunable counters read from the options (strings only; their readers are not identified): `max_copy_folds max_vn_kills max_vn_transforms max_copy_merges max_copy_props max_mix_insts max_presubs max_mov_and_shift max_useless_phis max_balance_conversions max_coalesce_loops max_spill_loops max_inst_hoists max_mad_mul_to_d2a max_mad_d2a_to_dp3 max_add_add_to_dp3 max_add_mul_to_mad max_add_mad_mul_to_mov_mad_mad max_reassociate max_reconst_alu max_remove_cnd_input max_r600_minimize_cf_attempts max_flatten_if rearrange_tree_depth limit_registers limit_instructions`.

## 7. Register-kind table (`&DAT_001ea904`, 0x10-byte entries; CONFIRMED layout, names are the table's own abbreviations)

Entry = `{flags, ?, handler, name*}`; `FUN_00126760(kind)` returns `flags & 1`. Kinds 0-69: 0 `Rt`, 1 `C`, 2 `B`, 3 `I`, 4 `SLOT`, 5 `EP`, 6 `ES`, 7 `EZ`, 8 `EC`, 9 `EM`, 10 `F`, 11 `K`, 12 `BARY`, 13 `PRIM`, 14 `QUAD`, 15 `P`, 16 `AP`, 17 `AV`, 18 `PARAM`, 19 `IN`, 20 `INTEX`, 21 `INC0`, 22 `INC1`, 23 `INFOG`, 24 `INS`, 25 `V`, 26 `FACE`, 27 `SPRITE`, 28 `LOD`, 29 `GRAD`, 30 `SI`, 31 `A`, 32 `KN`, 33 `MFN`, 34 `WP`, 35 `PIVO`, 36 `SA`, 37 `CBI`, 38 `LOOP`, 39 `CLI`, 40 `VLI`, 41 `OLI`, 42 `ADDR`, 43 `MEM`, 44 `IC_RSC`, 45 `P_RSC`, 46 `M_RSC`, 47 `TXK`, 48 `PSB`, 49 `U`, 50 `ENC`, 51 `FP`, 52 `PRED`, 53 `MIX`, 54 `Vx`, 55 `Call_RSC`, 56 `BLK`, 57 `TBI`, 58 `SMB`, 59 `SMI`, 60 `cb`, 61 `RTA`, 62 `CLD`, 63 `CUD`, 64 `VPA`, 65 `TPL`, 66 `icb`, 67 `kc`, 68 `CK`.

## 8. What this unlocked in the corpus

`names_R2_params.tsv` (typed parameters), `names_R2_idioms.tsv` (arena/vector/operand webs) and `names_R2_locals.tsv` (typed locals) are produced from sections 2-4.
The method table is `class_methods.tsv`; renaming the `FUN_` functions themselves to `Class::method` was not done (it would change symbols the corpus verification compares by name).

## 9. Not established (honest list)

Meaning of most `Block` words beyond section 4, the `IRInst` flag bits, the compiler's other ~100 fields, the virtual slots 2-4 of `IRInst`, the mapping from opcode number to `Ir<Name>` (the `&DAT_001fc2b0` table is filled at run time by code not
attributed here), what `FUN_00105594`'s result is exactly, and the code of the optimisation passes other than their entry points.
