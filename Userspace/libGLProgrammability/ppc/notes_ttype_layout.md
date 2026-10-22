# yyparse data layouts recovered from the binary (libGLProgrammability, Tiger PPC)

Every entry says where in `part_006.c` (function `yyparse`) the evidence is. Tiers: CONFIRMED = the code shows it by values, strings or sizes; INFERRED = the 3Dlabs
`glslang.y`/`ParseHelper` source this compiler descends from names it and the code agrees; UNKNOWN = a field the code touches but nothing names.

## The value stack entry (YYSTYPE) is 0x2c bytes  (CONFIRMED)

`yyvsp` advances by 0x2c per symbol (`yyvsp = yyvsp + 0x2c`, `_memcpy(yyvsp, yylval, 0x2c)`; `yyval` is the 0x2c-byte block `yyval, local_87c .. local_858`, copied from
`yyvsp + (1 - yyr2[rule]) * 0x2c` - the first right-hand-side symbol - before each action: `_memcpy(&yyval, yyvsp + (1 - yyr2) * 0x2c, 0x2c)`).
Symbol `$k` of a rule with `n` symbols is at `yyvsp + (k - n) * 0x2c`.

| offset | lexer token (`lex`) | non-terminal (`interm`) | evidence |
|---|---|---|---|
| +0x00 | `line` (source line, int) | `line` | every `TParseContext__error(parseContext, *(char **)yyvsp, ...)` passes it first; rules 83-92 (`*=` ... `|=`) do `yyval = *(uint *)yyvsp` |
| +0x04 | `string` (TString *) / `i` / `f` / `b` | `op` (TOperator) | case 1 reads `*(yyvsp + 4)` as the identifier TString and prints it; case 3 reads it as the int constant (`>> 0x1f` abs, `0xffff <` overflow test); rules 82-92 store the operator code in it (`local_87c = 0x76 ... 0x84`) |
| +0x08 | `symbol` (TSymbol *) | `intermTypedNode` / `intermNode` / `nodePair.node1` (TIntermNode *) | case 1: `pTVar3 = *(yyvsp + 8)` is NULL -> "undeclared identifier"; case 0x5e: `addComma(.., *(yyvsp + -0x50), *(yyvsp + 8))` takes `$1` and `$3` nodes at +8 |
| +0x0c | - | `nodePair.node2` | second word of the node union (rules with two nodes, e.g. selection/for rest) |
| +0x10 .. +0x28 | - | union: `TPublicType type` (7 words) / `TFunction *function` / `TParameter param` / `TTypeLine typeLine` / `TTypeList *typeList` | rules 132-157 fill 7 words here; rule 101/102 (function header parameters) read `*(yyvsp + 0x10)` as the function and `(yyvsp + 0x10)` as a `TParameter` pushed into the function's `std::vector<TParameter>` at function+0xc (`M_insert_aux`) |

This is the 3Dlabs `%union { struct { TSourceLoc line; union{string,f,i,b}; TSymbol *symbol; } lex; struct { TSourceLoc line; TOperator op; union{intermNode, nodePair, intermTypedNode, intermAggregate}; union{type, function, param, typeLine, typeList}; } interm; }` (INFERRED name, CONFIRMED sizes/offsets).

The yyval locals therefore are: `yyval` +0 (line), `local_87c` +4 (op), `local_878` +8 (node), `local_874` +0xc (node2), `local_870 .. local_858` +0x10 .. +0x28 (type union words).

## TPublicType (7 words = yyval +0x10 .. +0x28)  (CONFIRMED by the type_specifier / type_qualifier rules)

Rule 132 (`type_specifier : VOID_TYPE`, `case 0x84`): `local_870 = 0` (type), `local_86c = (symbolTable.size() < 4)` (qualifier), `local_868 = 1` (size), `local_864 = 0` (matrix), `local_860 = 0` (array), `local_85c = 0` (userDef), `local_858 = *(yyvsp)` (line).
Static initialisers for `type_qualifier` (rules 128-131, `DAT_97c356fc ...` 7-word objects): `{0, qual, 1, 0, 0, 0, 0}` with qual = 2 (const), 3 (attribute), 4 (varying), 6 (uniform).

| word | name (3Dlabs `TPublicType`) | values seen |
|---|---|---|
| 0 | `type` (TBasicType) | 0 void, 1 float, 2 int, 3 bool (rules 132-135); samplers/struct above |
| 1 | `qualifier` (TQualifier) | 0 temporary, 1 global, 2 const, 3 attribute, 4 varying, 6 uniform |
| 2 | `size` | 1..4 (vec2 = 2 ...) |
| 3 | `matrix` (bool) | 1 for mat2/3/4 |
| 4 | `array` (bool) | 0 |
| 5 | `userDef` (TType * for structs / TYPE_NAME) | 0 |
| 6 | `line` | `*(yyvsp)` |

There is also a stack `TPublicType` temporary `local_830 .. local_818` used by rules 133-157 before it is copied into `yyval` (type = `local_830`, qualifier = `local_82c`, size = `local_828`, matrix = `local_824`, array = `local_820`, userDef = `local_81c`, line = `local_818`; `case 0x84` stores them in that order). `local_82c` is reused as the TType bit-field word in rules 3-5 (see below), so it is not a stable name.

## TType bit-field word, at TType + 0x30  (CONFIRMED values)

Rules 3, 4, 5 (int/float/bool constant) build a TType on the stack (`local_850` vtable `&PTR___ZN5TTypeD1Ev`, eight zero words `local_84c .. local_830`, bit-field word `local_82c`):

* `local_82c & 0x9ff | 0x4100800` (INTCONSTANT), `& 0x7ff | 0x4080000` (FLOATCONSTANT), `& 0x1807ff | 0x4180000` (BOOLCONSTANT), then `& 0xfffff9ff | 0x800`.
* Decoding: bits [31:25] = qualifier (2 = const), bits [24:19] = basic type (1 float, 2 int, 3 bool), bits [18:11] = size (0x800 = bit 11 = 1), bit 10 = matrix, bit 9 = array, bits [8:0] untouched (UNKNOWN, preserved by `& 0x1ff`).
* Rule 1 builds `TType(EbtFloat)` for an undeclared identifier: `local_82c & 0x1ff | 0x80800` = qualifier 0 (temporary), type 1 (float), size 1 ✓.

Object layout of the pool-allocated 0x40-byte `TVariable`/`TIntermSymbol`-style records built in case 1: `+0 vtable`, `+4 name (TString *)`, `+8 uniqueId` (`++symbolTable->nextId`, `piVar61[3]`), `+0xc` embedded TType: vtable `&PTR___ZN5TTypeD1Ev` at +0xc, eight words +0x10 .. +0x2c, bit-field word +0x30, three zero words +0x34 .. +0x3c.

## Calls whose argument roles name register leftovers

`TParseContext__error` is `(parseContext, line, reason, token, extraInfo, ...)`: in every action `param_4`/`param_5` (registers r6/r7) are loaded with the string literal passed as `token`/`extraInfo` just before the call; they are call-argument scratch (Ghidra shows the unused register parameters of `yyparse`, which really takes only `parseContext`).
