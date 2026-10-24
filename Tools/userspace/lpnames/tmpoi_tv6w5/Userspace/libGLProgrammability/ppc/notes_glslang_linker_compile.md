# libGLProgrammability: linker, compileNode family, PP stream compiler, ShCompile - fork E6 (round 4)

Tier legend as in the other notes. CONFIRMED = a symbol name, string, accessor body or constant in the code shows it; INFERRED = the role is clear from use and the 3Dlabs glslang design.
All offsets are bytes from the object pointer. Evidence comes from the accessor bodies (`Binding__*`, `ParseSymbol__*`, `ParseSymbolTable__*`, `BindingTable__*`) and from the functions named in `names_E6_*.tsv`.

## ParseSymbol (0x64 bytes, `operator_new(100)`)

| offset | field | evidence |
|---|---|---|
| +0x00 | chunk (`_PPStreamChunk*`, owned when +0x44 != 0) | `ParseSymbol__SetChunk` frees the old chunk only when +0x44 is set, stores the new one and sets +0x44 = 1 |
| +0x04 | next symbol in the hash bucket | `ParseSymbolTable__NextSymbolInHash` returns `*(sym+4)` |
| +0x08 | next symbol in the table's list | `ParseSymbolTable__NextSymbol` returns `*(sym+8)`; the table head is `*(table+0)` |
| +0x0c | parse-tree type (`TType*`) | `ParseSymbol__SetParseTreeType` stores it and calls ResolveOpenGLType; `ClearCompilerTempData` zeroes +0xc and +0x10 of every symbol |
| +0x10 | (compiler temp, cleared by ClearCompilerTempData) | `ParseSymbolTable__ClearCompilerTempData` |
| +0x14 | name (malloc'd C string) | `ParseSymbol__SetName` |
| +0x18 | direct-index array (ints) | `ParseSymbol__GetDirectIndex(i)` = `*(this+0x18 + i*4)` |
| +0x1c | name hash (sum of the characters) | `SetName` accumulates `*(this+0x1c) += c` |
| +0x20 | name length | `SetName`, `RemoveArrayIndex` tests the last character |
| +0x24 | direct-index count | `RemoveDirectIndex` decrements it |
| +0x2c | OpenGL type (ushort, 0x7ffe/0x7fff for indirect/array-element markers) | `Binding__GetOpenGLType` reads the same field of a Binding; `equalOperands` tests 0x7ffe / 0x7fff |
| +0x2e | array size (ushort) | `SetParseTreeType` stores `type+6` or 1 |
| +0x44 | owns-chunk flag | `SetChunk` |
| +0x48 / +0x4c | (copied by operator=) | `ParseSymbol::operator=` copies them; +0x4c is the "is array of struct" flag computed by ResolveOpenGLType |
| +0x60 | active/used flag consulted by the linker | `AllocateTextureUnitsForVaryings` tests `*(sym+0x60) != 0` for kind-0 chunks |

The chunk (`*symbol`) starts with a kind byte (0, 2, 3, 4 seen in the linker): 0 uniform/temp, 2 fragment-side varying, 3 constant, 4 vertex-side varying. Its header word at +0xc carries the register class in bits 16..20 (0x60000 vertex output texcoord set, 0x70000 fragment input texcoord set, 0x110000 constant) and the register index in the low 5 or 16 bits.

## Binding (output of the binding table)

+0 next binding, +4 next binding in hash bucket, +0xc hash key (`GetHash(n)` = key % n), +0x14 location, +0x18 declared size (`GetDecSize`), +0x1c actual size, +0x20 active index, +0x24 OpenGL type (ushort, `GetBindingBasicSize` = `GetVec4sForType(type)`), +0x2c client-request flag, +0x30 built-in flag. All from the one-instruction accessors `Binding__Get*/Set*/Is*`.

## BindingTable counters

+4 first attrib request binding, +0xc first attrib binding, +0x14 first uniform binding, +0x1c number of active attribute bindings, +0x20 number of active uniform bindings, +0x24 size of active user uniforms, +0x28 size of active user attributes, +0x2c / +0x30 size of active vertex / fragment uniforms, +0x34 size of active attributes, +0x38 / +0x3c maximum attribute / uniform name length, +0x40 / +0x44 number of active vertex / fragment samplers. All from `BindingTable__Get*` accessors.

## TGenericLinker per-stage arrays

Stage 0 is vertex, stage 1 fragment. Per-stage slots (`this + stage*4 + off`): +0x08 compiler objects, +0x10 per-object symbol tables, +0x18 per-object PP streams, +0x20 number of shader objects, +0x28 merged `ParseSymbolTable`, +0x30 merged `_PPStream` (created by `MergeCompilers`; type word `0x8b31` GL_VERTEX_SHADER / `0x8b30` GL_FRAGMENT_SHADER), +0x38 merged `FunctionTable`; +0x74 highest texture coordinate set used, +0x78 mask of used coordinate sets, +0x84 info sink.

`MergeCompilers(stage)`: for every shader object it copies the operation chunk list (chunk `+0xc` low 18 bits = operation index, offset by the running total of previous objects), renames `gl__While*` / `gl__If*` labels by overwriting four characters with `%04d` of the object index (so labels stay unique), shifts the function table's first/last operation by the same base, copies the parameter-binding chunks, merges symbols by name through `FindGlobalSymbolByName` (type and array-size mismatch are link errors), shifts constants of class 0x11 into the merged constant list and finally frees everything again on failure. The vertex stage additionally needs one object with its flag at `object+0xa4` (error otherwise).

`AllocateTextureUnitsForVaryings`: counts the texture coordinate sets used by vertex outputs (class 0x60000) and fragment inputs (class 0x70000), fails with a "too many varying" error above 0x20 slots, then allocates a 128-byte slot map (8 sets x 4 components of ints holding allocation ids) first-fit by component width 4, 3, 2, 1, records the chosen set/component pairs in a stack plan, and finally patches the output bindings of both stages (`_PPStreamAddOutputBinding` with word `component mask << 24 | set | 0x4060000`).

## compileNode family (tree to PP stream)

The 14-word `_PPStreamOperation` record (see notes_glslang_layouts.md) is built on the stack by `TIntermAggregate`, `TIntermLoop`, `TIntermSelection` and `TIntermBranch` `compileNode` exactly as in `TIntermBinary` / `TIntermUnary`: word 12 receives the node's line (vtable slot 0 `getLine`) and word 13 the length of the label text that is passed as the `str` argument of `TPPStreamCompiler::AddOperation`. The record locals are therefore named `opHeader ... opLine, opLabelLength`.

* `TIntermLoop::compileNode` (opcodes 0x1a8 loop begin, 0x205 / 0x215 conditional, 0x150 and 0x164 branches): builds four labels from `compiler+0x8c` (a running label counter): `gl__WhileBody_N`, `gl__WhileEnd_N`, `gl__WhileStart_N`, `gl__WhileEndIf_N`; `ParseWhileLoopStack__push(compiler+0x5c, bodyLabel, endLabel)` records the break target.
* `TIntermSelection::compileNode`: labels `gl__IfElse_N` and `gl__IfEnd_N`; when the condition operand carries a compile-time constant (`operand+4`) only the live arm is compiled; otherwise it emits a conditional branch (opcode 0x215), the true block, an unconditional branch (opcode 0x160 with the end label), the else label and the false block. A true block consisting of one kill is merged into a conditional discard.
* `TIntermBranch::compileNode`: `this+8` is the branch kind: 0x62 discard (emits the kill operation with a constant -1.0f source), 99 return (copies parameters back, assigns the return value slot and emits a branch to the function end), 100 break (branch to `ParseWhileLoopStack__breakLabel`), 0x65 continue.
* `TIntermAggregate::compileNode`: `this+0x30` is the aggregate operator; operator 3 is a function definition (adds the label, a `FunctionTable` entry, pushes the function on `ParseFunctionStack`; `main(` records its first operation), operator 1/2 enter and leave a sequence scope (`compiler+0x98` nesting counter); function-call arguments are copied into new `ParseOperand`s before the call and written back afterwards.

## `ShCompile(handle, shaderStrings, numStrings, optLevel, debugOptions)`

`handle` vtable slot 8 returns the `TCompiler` (+4 infoSink, +8 language). The function takes the global pool allocator lock, builds a `TParseContext` on its stack (intermediate pointer, symbol-table level vector, infoSink, language, tree root at +0x18 of the context, error flag, error count, an extension-behaviour `std::map<string,TBehavior>` and a second `std::map<string,string>`), pushes two symbol table levels on top of the built-in table (at most 3 levels are allowed: "Wrong symbol table level"), parses the preprocessor built-in string and the user strings with `PaParseStrings`, post-processes the tree (`TIntermediate::postProcess`), optionally dumps it (`debugOptions & 1`) and hands it to the compiler vtable (slot 0x34 optLevel, 0x38 debugOptions, 0x14 compile). Messages: "Parser found no code to compile in source strings.", "N compilation errors. No code generated.", "No errors. No code generation or linking was requested."

## ARB parameter binding parser (`_PPParserParseParamBinding`)

Parses `program.env[n]`, `program.local[n]`, `state.material.front|back.ambient|diffuse|specular|emission|shininess`, `state.light[n]....`, `state.normalscale` and further `state.*` items into the binding record `{bindingWord, ordinal}` given to `_PPStreamAddParamBinding`. The class goes in bits 16..20 of the first word: 1 program.local, 2 program.env, 3 light, 5 material, 0x12 normalscale; the low 16 bits hold the array element, bit 0 is the front/back selector for material.

## Not recovered

`AllocateTextureUnitsForVaryings` second half (the per-stage patch of output bindings) and `FixOutputReads` still carry reused scalars (`uVar3`, `uVar9`, `iVar4`, `iVar19`); `TPPStreamCompiler::constructElement`, `copyPropagateCompilerTemp`, `constructFromOperand`, `assignOperands`, `_DetectConstantLoopsSimple`, `_UnrollConstantLoopsSimple`, `_InlineFunctionsBranch`, `_AddToAvailableCopyTable` and `_PPParserPreprocessString` were read but only partly named: their remaining placeholders are reused across several roles inside goto-heavy code.
