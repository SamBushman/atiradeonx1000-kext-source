# GLDriver parts 043-067, fork lp23: IR peephole / scheduler pack-state naming

Tables: `names_gW_1.tsv` (autoweb, callee-parameter names), `names_gW_2.tsv`/`_3`/`_4` (the use-pair exchange patterns), `names_gW_5.tsv` (PackState), `names_gW_6.tsv` (Program__valueNumberInst),
`names_gW_7.tsv` (millicode + small helpers), `names_gW_8.tsv` (ValueKey params), `names_gW_9.tsv`/`_10.tsv` (inline arena-vector temporaries), `names_gW_11.tsv` (IRInst field loads), `names_gW_12.tsv` (use predicates).
Tools: `Tools/userspace/lpnames/autoweb.py` (modes: callee parameter names, `--vec`, `--instfield`), `ptrloop.py`, `ren2.py`.

## Layouts recovered (all INFERRED from several functions; offsets from the code)

* **Operand use** = a two-word pair `{consumer instruction, operand index}`. `IRInst__getOperandSource(*u, u[1])` is the source feeding that operand; the consumer's *other* source operand of a two-source instruction is
  index `(idx % 2) + 1` (Ghidra writes it `idx + ((idx>>1) + (idx<0 && idx&1)) * -2 + 1`). Operand records sit at `inst + 0x8c + n*0x18`: +4 source, +8 register, +0xc register offset, +0x10 select word,
  +0x14 flags (bit 0 negate, bit 1 abs); so `inst+0x94/0x98/0x9c` = destination register / offset / select, `inst+0xb8` / `+0xd0` = flags of source operands 1 / 2, `+0xa0 + n*0x18` = flags of operand n.
* **IRInst fields used by the patterns**: +0x14 flags (0x200 = has an extra source), +0x84 operand count, +0x88 -> opcode info (+8 = opcode; 0x13 = IrMulFloat, 0x12 = IrAddFloat), +0x120 saturate, +0x124 result scale code, +0x160 instruction counter.
* **ValueKey** (the object `Program__valueNumberInst` numbers): `+0xb0` the instruction, `[0..3]` per-lane value numbers, `[0x8e]` the program; the program holds per-value hash vectors at `+0x408/+0x40c` and the counter at `+0x478`.
* **Arena vector** header (`Arena__alloc(arena, 0x14)`): `[0]` arena, `[1]` capacity, `[2]` size, `[3]` data, `[4]` arena; the Vector object is the header + 4 (`[0]` capacity, `[1]` size, `[2]` data, `[3]` arena). Push/pop are inlined by the compiler everywhere
  (`_memset(size*4 + data, 0, 4)` / `Vector__elementRefGrow`), which is where the many `vectorSize`, `vectorFilledCount`, `elementRef` temporaries come from.
* **PackState slot table** (`PackState__buildSlotTable`, FUN_0018c1c8): six register entries as two triples (`slotTable[0..2]`, `slotTable[3..5]`) with per-entry fill counts; a register is placed in an entry when the RegKind / flags (+0x14 & 0x40) /
  +0x94 tests of the entries agree (the same test appears inline in FUN_0018bc94, FUN_0018c7f4, FUN_0018c980).

## Functions named

`Inst__swapMatchedOperandsBetweenUses` (FUN_0014f420), `Inst__swapSharedTermBetweenUses` (FUN_0014e9e4), `Inst__reassociateUsePair` (FUN_001506d0), `Use__negationParityEqual` (FUN_0014699c), `Use__sourceIsPlainSingleUse` (FUN_00146cd8),
`PackState__buildSlotTable` (FUN_0018c1c8), `ValueKey__rebuild`, `signToCompareCode`, `IROperand__copyRegisterAndSelect`, `DListNode__unlinkAndDelete`, `List__freeAllNodes`, `Inst__opcodeOrSourcesDiffer`,
`Inst__writtenLanesAllMatchValue`, `Inst__allWrittenLanesSatisfy`, FPR millicode `_savef14/22/24/25/26/27/28`, `_restf14` (0x1a322c..0x1a327c, from the Mach-O disassembly).

## Still open in this range

* The other peephole giants (FUN_00152ea8, FUN_0015f44c, FUN_001541f0, FUN_00156d48, FUN_001621c8, FUN_00161748, FUN_00159b58, FUN_00184ef0, Inst__takeOutCommonFactor, R300MachineAssembler__assembleAluInstruction, FUN_00181f00's
  non-vector webs, FUN_00160eb0, FUN_00174e0c): names need a function-by-function read; the cheap rules (callee parameter names, inline vector idiom, IRInst field loads) are exhausted by `autoweb.py`.
* `FUN_00186a88` keeps pointer-valued `loopIndex*` names: renaming them to `loopPtr*` breaks 23 anchors of `names_I1_p049.tsv`/`names_gW_1.tsv` rows (anchors encode intermediate names) and was reverted for that function only.
* `FUN_00161748` and `FUN_00189c24`: the autoweb rows were rejected by the gate (UNINIT / DATAFLOW) and removed; they keep their placeholders.
* `FUN_000f2da8` (select-word compatibility test, 3 call sites here) is outside this range (part_025).
