# libGLProgrammability: GLSL front end, PP stream compiler and statically linked runtime - layouts recovered by fork D6

Tier legend as in the other notes: CONFIRMED = a constructor, accessor, symbol name or value shows it; INFERRED = the 3Dlabs `glslang` / GCC 4.0 source this code descends from names it and the code agrees.
The dylib keeps real C++ symbols (`__ZTV...`, mangled method names), so class and method names are exact where a symbol exists. All offsets are bytes from the object pointer.

## TType (stack or embedded object), 0x28 bytes

| offset | field | evidence |
|---|---|---|
| +0x00 | vtable (`&PTR___ZN5TTypeD1Ev`) | every stack TType starts with this store |
| +0x04 | arraySize | `TType::setType(basic, size, matrix, array, arraySize)` writes it (`*(this+4) = param_6`) |
| +0x08 | structure (TTypeList*) | `setType(.., TType* userDef)` copies `userDef+8`; `TType__setStructSize` iterates it |
| +0x0c | fieldName (TString*) | `TType::getFieldName` returns `*(this+0xc)`; `setFieldName` writes it |
| +0x10 | typeName (TString*) | `TType::getTypeName` returns `*(this+0x10)`; `setTypeName` allocates an 8-byte TString |
| +0x14 | (unknown) | copied by the TVariable copy, zero in every constructor seen |
| +0x18 | structureSize | written by `TType__setStructSize` (`*(this+0x18) = total`) |
| +0x1c, +0x20 | (unknown) | copied, zero |
| +0x24 | bit-field word | `isArray` = bit 9, `isMatrix` = bit 10, nominal size = bits 18..11 (`getNominalSize`), basic type = bits 24..19 (`getBasicType`), qualifier = bits 31..25 (`getQualifier`) |

TType vtable (`__ZTV5TType`): 0/1 destructors, 2/3 `setType`, 4 `setTypeName`, 5 `setFieldName`, 6 `getTypeName`, 7 `getFieldName`, 8 `getBasicType`, 9 `getQualifier`, 10 `changeQualifier`, 11 `getNominalSize`, 12 `getInstanceSize`, 13 `isMatrix`, 14 `isArray`, 15 `isVector`.

A stack TType overlaps other stack objects: the compiler reuses the area for different, non-simultaneous objects (a second TType, TStrings, the PP operation record). Names in `names_D6_stacktype.tsv` therefore join every role of a slot with `Or`.

## TPublicType, passed by value = seven words

type (+0), qualifier (+4), size (+8), matrix (+0xc), array (+0x10), userDef (+0x14, TType*), line (+0x18). By the PowerPC ABI a by-value TPublicType is passed in r6..r10 plus two stack words:
in `TParseContext::arrayErrorCheck(this, line, TString&, TPublicType, TIntermTyped* arraySize)` params 4..10 are the seven words and param 11 is the array-size node. The earlier `names_P_mang.tsv` rows that called param_4 `publicType` and
param_5 `intermTyped` were wrong for this by-value case and were corrected (`ptType`, `ptQualifier`).

## TVariable (0x40 bytes, pool allocated)

+0 vtable (`PTR_vtable_a7b7c0b4 + 8`), +4 name (TString*), +8 uniqueId (`++symbolTable.nextId`), +0xc embedded TType (its vtable is stored at +0xc; bit-field word at +0x30), +0x34 (zero), +0x38 const union array pointer
(allocated on first use by `executeInitializer`: `nominalSize (squared when matrix) * 4` bytes). Evidence: `TParseContext::executeInitializer`, `arrayErrorCheck`, `IdentifyBuiltIns` build it field by field.

## TSymbolTable

`TParseContext+4` = symbol table pointer. Level vector: begin `*(table+0)`, end `*(table+4)` (levels are 4-byte pointers), `+0xc` = nextId counter. A symbol lookup (`find(name, &builtIn, &sameScope)`) walks the levels from the last
down to 0 with `std::_Rb_tree::find` on `level+4`; `builtIn = (index == 0)`, `sameScope = (index == levels.size()-1)` (the two outputs of `arrayErrorCheck`).
The inlined insert of a new TVariable has a fixed stack frame relative to the stack TType base B: B+0x10 allocator argument, B-0x30/-0x34 insert result copy, B-0x40/-0x44 map insert result, B-0x50 name copy TString, B-0x54 its chars, B-0x58 the variable, B-0x60 destroy allocator argument.

## Class fields established from accessors

| class | offset | field |
|---|---|---|
| TIntermNode | +4 | line (`getLine`) |
| TIntermBinary | +0x30 | operator (`*(this+0x30)` compared with EOpIndexDirect 0x2d, EOpIndexIndirect 0x2e, 0x2f ...) |
| TIntermBinary | +0x34 / +0x38 | left / right (`getLeft` / `getRight`) |
| TIntermUnary | +0x34 | operand (`getOperand`) |
| TIntermSelection | +0x30 / +0x34 / +0x38 | condition / trueBlock / falseBlock |
| TIntermSymbol | +0x30 | id (`getId`) |
| TCompiler | +4 | infoSink (`getInfoSink`) |
| TGenericLinker | +0x28 / +0x2c | vertex / fragment ParseSymbolTable (`NextSymbol(*(this+0x28), ...)`) |
| TGenericLinker | +0x30 | ppStreamManager; +0x38 FunctionTable; +0x40 shaderLocalParamRemapTable; +0x48 numShaderLocalParams; +0x74/+0x78 highest used / bit mask of texture coordinate sets |
| TGenericLinker | +0x84 | info sink (`TInfoSinkBase::append("ERROR: ")`) |
| TPPStreamCompiler | +0x68 | ParseSymbolTable passed to `ParseSymbolTable__processOperand` |
| TPPStreamCompiler | +0x70 / +0x74 | ppStream (`_PPStreamAddOperation(*(this+0x70), ...)`) / getPPStream |

TIntermBinary vtable (`__ZTV14TIntermBinary`), slot offsets from the vptr: +0 getLine, +4 setLine, +8 traverse, +0xc compileNode, +0x10 indirectNode, +0x14 getAsTyped, +0x18 getAsConstantUnion, +0x1c getAsAggregate,
+0x20 getAsBinaryNode, +0x24 getAsSelectionNode, +0x28 getAsSymbolNode, +0x34 setType, +0x38 getType, +0x3c getTypePointer, +0x40 getBasicType, +0x44 getQualifier, +0x48 getNominalSize, +0x4c getSize,
+0x50 isMatrix, +0x54 isArray, +0x58 isVector, +0x5c promote, +0x60 setLeft, +0x64 setRight, +0x68 getLeft, +0x6c getRight. TIntermAggregate adds +0x60 setOperator, +0x64 getSequence, +0x68 setName, +0x6c getName, +0x70 setUserDefined, +0x74 isUserDefined.

## `_PPStreamOperation`: the compile-time operation record, 14 words (0x38 bytes)

Passed by address to `_PPStreamAddOperation(stream, &rec, ...)` / `TPPStreamCompiler::AddOperation(this, operand, &rec, str, n)` and filled by `_PPParserParseOperation` (text -> record) and the `TInterm*::compileNode` methods (tree -> record).

| word | field | evidence |
|---|---|---|
| 0 | header: opcode in bits 25..18 (`(opcode & 0xff) << 0x12`), operand class bits above | `_PPParserParseOperation: local_90 = (param_2 & 0xff) << 0x12`; `TIntermBinary::compileNode` sets `0x880000` (MUL = 0x22), `0x7c0000` (ADD = 0x1f) |
| 1 | flags / modifiers | `local_8c = (param_3 & 3) << 0x12 | ...` |
| 2-3 | destination operand descriptor | `_PPParserParseDestination(parser, &rec+8)`; `ParseOperand::GetAsDestVar` returns two words |
| 4-5 / 6-7 / 8-9 | source 0 / 1 / 2 descriptors | `_PPParserParseSourceVar(parser, &rec+0x10 ...)`, `GetAsSourceVar` returns two words |
| 10-11 | auxiliary (condition / branch) operand, zero-initialised | `_PPParserParseBranchCondition(parser, &rec+8)` |
| 12 | source line | `parser+0x18`; `compileNode` stores `this->getLine()` (vtable slot 0) |
| 13 | copy of the parser state word | `local_5c = local_50` |

## libgcc (statically linked GCC 4.0 DWARF2 unwinder)

`_Unwind_FrameState` (0x3a4 bytes): regs.reg[111] {loc +0, how +4} at 8*i; regs.prev +0x378; cfa_offset +0x37c; cfa_reg +0x380; cfa_exp +0x384; cfa_how +0x388; pc +0x38c; personality +0x390; data_align +0x394;
code_align +0x398; retaddr_column +0x39c; fde_encoding +0x39d; lsda_encoding +0x39e; saw_z +0x39f; eh_ptr +0x3a0.
`_Unwind_Context`: ra +0x1c0, lsda +0x1c4, bases (tbase +0x1c8, dbase +0x1cc, func +0x1d0 copy used as fs->pc), +0x1d4 signal-frame/args-size area.
`struct object` (unwind-dw2-fde): pc_begin +0, tbase +4, dbase +8, u.single/array +0xc, s.b bit-field +0x10 (mixed_encoding bit 29, encoding bits 28..21; the other bits are read as `sorted`/`from_array`/`count` by search_object), +0x14 end of the FDE list (Apple's extra `fde_end`: the loops stop at `*(ob+0x14)`), next object +0x18.
All the unwinder functions (`execute_cfa_program`, `execute_stack_op`, `extract_cie_info`, `uw_frame_state_for`, `linear_search_fdes`, `frame_heapsort`, `fde_split`, `classify_object_over_fdes`, `add_fdes`, the three `read_encoded_value_with_base`,
`read_{u,s}leb128`, `size_of_encoded_value`, `base_of_encoded_value`, the two `_Unwind_*_Phase2` and the FDE comparators) are named from the GCC sources in `names_D6_unwind.tsv`.

## libstdc++ 4.0 (statically linked)

`std::vector<T, pool_allocator<T>>`: +0 allocator, +4 start, +8 finish, +0xc end_of_storage. COW `std::string`: +0 character pointer; `_Rep` at data-0xc: length (-0xc), capacity (-8), refcount (-4);
`std::string` copy release = `refCountPtr = data - 4; old = *refCountPtr; lwarx/stwcx store old-1; if (old < 1) _Rep::_M_destroy`. That idiom (181+ sites) is named in `names_D6_refcount.tsv`.

## Not recovered

The linker's slot allocator (`AllocateTextureUnitsForVaryings`: a 128-byte, 8x4 map of texture coordinate slots, binding word masks `0xf0000`/`0x1f` of the ParseSymbol binding), the per-case PP stream construction in `TPPStreamCompiler::construct*`
and the inlined `TType` copies of `TParseContext::constructorErrorCheck` are only partly named; they need the ParseSymbol/Binding layouts, which have accessors but no constructor in the corpus.
