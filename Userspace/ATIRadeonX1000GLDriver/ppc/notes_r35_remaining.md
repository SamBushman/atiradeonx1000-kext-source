# r35: name the remaining anonymous LD_<addr> link-layer objects in GLDriver

The Oct 31 handoff's "~409 PTR_ pointers to anonymous LD_ bss globals" turned out to be almost entirely stale
cache: the committed `link/symbol_map.tsv`/`exports.txt`/`rewrites.txt` predate most of this project's later
naming rounds (no round had ever re-run `link_corpus.py` for GLDriver and recommitted the output). Re-running it
against the current corpus (same stock binary, same `gld_data.tsv`, same `Tools/userspace/link_config/gld.json`)
drops the `LD_` count straight to 8, with no code change - the other 401 were already resolved by r04/r06/r07/r13/r24/r26's
`data`/`target` rows; the committed link/ snapshot had simply never been regenerated to show it.

## The real 8
6 of the 8 already have a real name via an existing `data` row for the same address (the row renames the Ghidra
`DAT_<addr>` label wherever it's used directly in C source; `link_corpus.py`'s `ld()` function, which resolves a
pointer-word's target label, only ever consults `target` rows - never `data` rows - so an address reached ONLY
through a pointer slot still shows up as `LD_<addr>` until a matching `target` row exists too):
- `LD_1d9f34` -> `textureFormatTable_001d9f34` (names_r07_data.tsv)
- `LD_1aa818` -> `laneWordSplatTable_001aa818` (names_r11_data.tsv)
- `LD_1dca64` -> `KhanPsOpcodeTraits_001dca64` (names_r07_data.tsv)
- `LD_1df1fc` -> `KhanVsOpcodeTraits_001df1fc` (names_r07_data.tsv)
- `LD_1dbd84` -> `swizzleWordsYYYX_001dbd84` (names_r07_data.tsv)
- `LD_1dbd14` -> `swizzleWordsXYZW_001dbd14` (names_r07_data.tsv)

The 7th had no existing name at all: `LD_1a4524` is the C string "1D" (a texture-target keyword, alongside "2D"/"3D"
at the adjacent addresses, part of `arbfpKeywordTable_001e9158`'s string set), reached only through that table's
pointer word. Named `s_1D_1a4524` (the project's `s_<text>_<addr>` cstring convention; digit-leading text already
has precedent, e.g. `s_0x55_..._1a6a0c`).

The 8th, `LD_1fa5e8`, is deliberately left alone per notes_r24_remaining.md: it already has a real name
(`zeroWords4_001fa5e8`) and is kept as a `.set` alias by design (making the pointer word use the real name would
be a `link_corpus.py` behavior change, not a naming change).

## Tool fix needed
Adding the 6 "already has a data row" target rows tripped `apply_names.py --check`'s own validator: it refuses a
target `new` name that "already occurs in the corpus", with no exception for the legitimate case where the target
row's job IS to point at the same address a `data` row already named (the two mechanisms don't talk to each other -
`ld()` genuinely has no fallback to `data` rows, so the target row is still necessary even though the name exists).
Patched the check (`Tools/userspace/apply_names.py` main(), target-row validation block) to allow a `new` name that
already occurs when it is the existing `data` row's name for the exact same address (parsed numerically from both
old fields - `DAT_<addr>`/`PTR_<addr>` is zero-padded to 8 hex digits, `LD_<addr>` is not, so the comparison has to
be numeric, not a string match). Re-verified 0 errors across all four userspace binaries after the fix, so it
didn't loosen anything else.

## Verification
`apply_names.py --check`: 0 errors (all 4 binaries). Re-ran `link_corpus.py` with the new rows: `LD_` count 8 -> 1
(only the deliberate 1fa5e8). Ran `Tools/userspace/datacheck.sh` properly (both sides freshly linked from their own
git revision - the committed link/ snapshot is NOT an input to this check, confirmed by both sides reporting
identical "630 typed data decls, 1674 data labels emitted" counts): `data.s`/`symbol_map.tsv` differ from origin/main
in exactly 6 places, each a clean `LD_<addr>` -> `DAT_<addr>` swap (link_corpus.py's own collision-avoidance: it
won't reuse a name that a `data` row already declared as a real C global for the raw assembly label, so it falls
back to the grep-able `DAT_<addr>` form instead of the full pretty name - still a real improvement over the opaque
`LD_<addr>`, just not the prettiest possible one). No `.c` source file changed in this round (target rows never
touch C text), so no compile gate was needed; `datacheck.sh`'s fresh-vs-fresh comparison is the correct and
sufficient check for this kind of change.

## One cosmetic loose end (not a correctness issue)
`LD_1a4524`'s target row IS correctly picked up by `symbol_map.tsv` (shows `s_1D_1a4524`), but NOT by the raw label
`link_corpus.py` emits inline inside the `.cstring` blob at that byte offset (`data.s` still literally emits
`LD_1a4524:` there) - the cstring-run emission code path doesn't consult `ld()`/the `targets` set the same way the
word-table emission path does. Did not chase this further: it changes nothing observable (the byte content and the
pointer word that reaches it are unaffected either way) and `symbol_map.tsv`, the human-facing reference, already
shows the real name. Left as a known `link_corpus.py` quirk for whoever next touches cstring-target labeling.

## Not attempted here
Updating the committed `link/exports.txt`/`rewrites.txt`/`symbol_map.tsv` snapshot files: they are stale by a wide
margin (a fresh regen is ~1300 lines shorter, reflecting years of later naming/cleanup work that was never
resynced) and are not read by any automated gate (`verify_names.sh`/`gate.sh` compile part_*.c directly;
`datacheck.sh` links both sides fresh and never touches the committed snapshot). Refreshing them properly is a
separate, larger job - flagging rather than guessing at a full resync in this round.
