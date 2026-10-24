# libGLProgrammability: joined / overlay names that cannot be split (lp13, parts 004/005/007/008/009/011)

Every entry says why the gate (`gate.sh`, split_equiv + `-Wuninitialized`) or the storage layout forbids one name per role. Where a role list was
possible the name now describes the storage (`...Overlay`, `...Scratch`, `...Reg`) instead of listing roles with `Or`.

## Address-taken frame storage shared by different lifetimes (apply_names cannot split address-taken locals)

| function | variable | what shares the slot |
|---|---|---|
| `OutputConstantUnion` | `typeTemp1Overlay` | getType() TType temporary, then the `%d (%s)` sprintf buffer and the std::string rep |
| `TIntermBinary__promote`, `TIntermediate__promoteConstantUnion`, `TParseContext__addConstVectorNode`, `TIntermBinary__indirectNode` | `typeTempOverlay` | TType temporary (getType out parameter) and the `[%d]` / location text buffer |
| `TIntermBinary__compileNode` | `operandDescOverlay` | first word of the 8-byte operand descriptor out-parameter and the `[%d]` sprintf buffer |
| `TParseContext__extensionErrorCheck` | `allocatorOverlay`, `mapIterOverlay`, `mapEndOverlay` | pool allocator argument block / lower_bound iterator / insert result / message strings |
| `TParseContext__arrayErrorCheck` | `stackTypeBitsOverlay`, `stackTypeStructureOverlay`, `stackTypeTypeNameOverlay`, `stackTypeWord14Overlay`, `stackTypeWord1cOverlay`, `stackTypeWord20Overlay` | fake-struct words of two stack TType temporaries (stackType and stackTypeB) at the same stack offsets |
| `TIntermConstantUnion__fold` | `unaryTypeWord4Overlay`, `binaryTypeWord4Overlay`, `compareTypeWord4Overlay`, `tailTypeWord4Overlay`, `rightTypeOverlay` | stack TType temporaries whose word 4 / rep also hold the `%d:%d` location text |
| `TGenericLinker__FixOutputReads` | `opChunkScratchWord` | op chunk cursor in the scan loop, then the packed (register, index) halfword pair read through `&` |

## One web (the gate rejected the split, or both defs reach the same use)

| function | name | reason |
|---|---|---|
| `Binding__SetNameFromArrayName` | `nameLengthCountdown` | def at the strlen copy and def `= bracketPos` both reach the checksum loop (`goto LAB_97bb0358`): same web |
| `TIntermAggregate__compileNode` | `lastCallArg3Ptr` | op-header pointer (AddOperation arg 3) and param-slot pointer (assignOperands arg 3) both reach the later stale-r5 forwards |
| `TIntermUnary__compileNode` | `opWordScratch` | operator code, PP stream type and op2 header word reach the shared `emitFinalOp` stale r10 argument |
| `TParseContext__parseMatrixFields` | `fieldTextLengthReg` | length def and the two terminator-char defs all reach the stale 7th argument of `error()` |
| `TParseContext__constructorErrorCheck` | `savedR10`, `paramSizeResult` | `savedR10`: three defs of the r10 spill slot; `paramSizeResult`: r4 carrier (size query results and `extraout_r4_N` stale reloads) |
| `ParseSymbolTable__FindNextParamSymbolByName` | `matchResult` | split into symbol cursor / strncmp result failed gate lpM1 (DATAFLOW) |
| `TPoolAllocator__allocate` | `allocationResult` | split into entry offset / returned address failed gates lpM3 (UNINIT, DATAFLOW): the entry def reaches the fast-path return |
| `TParseContext__integerErrorCheck` | `basicTypeThenSize` | `if (x == 2 && (x = f(), x == 1))` on one line: lhs/rhs cannot separate the use of the first value from the def of the second |
| `TGenericLinker__AllocateTextureUnitsForVaryings` | `typeOrVec4Count` | `while (x = GetVec4sForType(x), vec4Index < x)`: argument, result and compare are one statement |

## Still joined (work not finished): `TIntermConstantUnion__fold`

15 whole-function locals (`rightOrResultValue`, `refCountOrVtable`, `thisOrRightCursor`, `bitsOrLine`, `nodeOrVtable`, `sizeOrArrayOrIndex`,
`resultOrOffset`, `countOrResult`, `sizeOrIndex`, `newNodeOrRightArg`, `typeBitsOrLoc`, `typeFieldOrInt`, `resultOrRightFloats`, `sizeOrLoopIndex`,
`flagOrCompare`) = 240 def-use webs (find_webs). They are not unsplittable; the split needs a name per web (idioms: `bits >> 0x13 & 0x3f` basic type
field, `(*(code*)**this)(this)` source location, `puVar = PTR_vtable` refcount destroy idiom, `param_2 - 0x13` operator offset, ...). Tracked as open.
