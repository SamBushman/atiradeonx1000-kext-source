# yyparse: how the per-case temporaries were named (names_R1b.tsv)

Evidence that is new compared with notes_yyparse_grammar.md / notes_ttype_layout.md. Everything below is read from the binary (the dylib symbol table and the corpus text).

## Class identification through vtables (CONFIRMED)
* The dylib keeps its vtable symbols: `__ZTV9TFunction`, `__ZTV9TVariable`, `__ZTV16TIntermAggregate`, `__ZTV13TIntermBinary`, `__ZTV12TIntermTyped`, `__ZTV7TSymbol`, ... with the exact method symbol in every slot (`__ZNK12TIntermTyped7isArrayEv` ...).
* A vptr points at `__ZTV + 8`, so virtual slot k is at vptr + 4k. In yyparse, `(**(code **)(*node + 0x54))(node)` is slot 21 of TIntermTyped = `isArray`, `+0x50` isMatrix, `+0x58` isVector, `+0x48` getNominalSize, `+0x40` getBasicType, `+0x44` getQualifier, `+0x38` getType (returns a TType by value: first argument is the hidden result pointer), `+0x3c` getTypePointer, `+0x34` setType, `+0x18` getAsConstantUnion, `+0x1c` getAsAggregate, `+0x20` getAsBinaryNode, `+0x24` getAsSelectionNode, `+0x28` getAsSymbolNode.
* `PTR_vtable_a7b7c0f4` / `...c0b4` / `...c0d0` in the text are `nl_symbol_ptr` entries: imports of `__ZTV9TFunction`, `__ZTV9TVariable`, `__ZTV16TIntermAggregate`. `&PTR___ZN5TTypeD1Ev_a7b7d640` is the TType vtable (the symbol `__ZTV5TType` is at that address - 8).
* The constant `0xa7b8374c` is a base address the code adds offsets to: `0xa7b8374c + -0x610c = 0xa7b7d640` = the TType vtable address; the variables holding it are named `picBase`, the sums `typeVtable`.
* Pool allocation sizes: TType 0x28, TFunction 0x54, TVariable 0x40, std::basic_string (pool_allocator, `{allocator, _M_p}`) 8.

## TParseContext (INFERRED, 3Dlabs layout confirmed by use)
`+0` TIntermediate (first argument of every TIntermediate__* call), `+4` TSymbolTable: its +0/+4 pair is the begin/end of the level vector (sized with `(end - begin) >> 2`), `+0xc` is the unique-id counter (`++nextId`).

## std::string reference counting (INFERRED)
`P = S + -4` (S = string data pointer `_M_p`), `old = *P`, then `lwarx/stwcx` through `storeWordConditionalIndexed(old - 1, 0, P)`, repeated until `cr0` is set, then `if (old < 1) free`: the COW release of the `_Rep` refcount word (`refCountPtr`, `oldRefCount`, `newRefCount`). `*(S + 4)` followed by a store at `data[*(data - 0xc)]` is `c_str()` (`stringData`).

## Value-stack loads
In the action of rule N, `yyvsp + off` is symbol `$k` with `k = n + floor(off / 0x2c)` and field `off mod 0x2c` (+0 line, +4 op / lexical value, +8 node, +0xc node2, +0x10.. type words); the variable is named `<symbol><Field>` from the rule's right-hand side (Tools/userspace/yygrammar/rules.py with mid-rule actions numbered as bison numbers them). Only used when the case body is entered through its `case` label only.

## Not named, and why
The register-reused copies that live across all the cases (`pTVar3` = yyvalNode copy is named `resultNode`; `pTVar31`/`pTVar32`/`local_750` copy yyval union words; the `local_850 .. local_7cc` stack TType / TPublicType / std::string temporaries) join several roles into one web, as notes_ttype_layout.md says; no single name is true for them. The stack TType objects have `+0` vtable and the bit-field word at `+0x24` (`local_850` / `local_82c`, `local_820` / `local_7fc`, `local_7f0` / `local_7cc`).
