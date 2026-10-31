# r07 leftovers (GLDriver data labels and goto labels)

Rows: `names_r07_data.tsv` (209 `DAT_`), `names_r07_ptr.tsv` (233 `PTR_` slots), `names_r07_labels.tsv` (100 labels).

## Counts (distinct names in part_*.c / link/symbol_map.tsv)
| kind | before r07 | after r07 |
|---|---|---|
| DAT_ | 346 | ~199 (the rest are named) |
| PTR_ | 633 | ~412 |
| LAB_/switchD_ | 114 | 14 |

## Why the rest are left
- **PTR_ -> anonymous `LD_` bss globals (~409):** the slot is named after its target, and the target has no name yet. Naming them needs a per-global read of every user. Left on purpose.
- **PTR_ with `orph` targets (2):** `PTR_DAT_001e8ae4` (target `orph_4c544+12` is not an identifier) and `PTR_orph_1d8910_001eb328` (alias at the same address as the renamed `PTR_DAT_001eb328`).
- **DAT_ with no code use:** zero/select constants never read directly, 4-byte `__const` words, `eh_frame` symbols, bss neighbours of `0x1fa5e8`.
- **Vertex-type bitfield tables at 0x1d92a8, 0x1d9358, 0x1d9408, 0x1d94b8:** the field meaning is not settled; a guessed name would be wrong.
- **Labels (14):** the label sits at the end of a loop body or inside an asm-like callback sequence, and the role depends on a variable that is itself still a placeholder (e.g. the ffvpEmitDirectionalLight / ffvpEmitLight emit-callback labels LAB_000980d0, LAB_00097d70, LAB_00097d1c, LAB_00098038, LAB_00097fd4, LAB_00099084, LAB_000996c0, LAB_0009991c, LAB_00099980, LAB_0009966c, plus LAB_000972c8, LAB_00097360). Each calls one of three emit callbacks (ctx offsets 0x12ec/0x12f0/0x12f4) with swizzle and constant-table arguments; the callbacks are not identified.

## Gates
- r07a (data rows): SPLIT-EQUIVALENT, `datacheck.sh` DATA-IDENTICAL (92 link files, 1677 symbols).
- r07b (labels): see the report.
- `datacheck.sh` now sorts `symbol_map.tsv` before diffing, so row order does not count as a difference.
