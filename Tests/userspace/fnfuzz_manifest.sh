#!/bin/sh
# fnfuzz_manifest.sh - record (and compare) the exact state a sweep ran against: checksums of the harness binary, both images, the ledger, the scripts and
# the FNFUZZ_* environment. Added Nov 15 at the user's request: a sweep that is interrupted and continued (or whose outputs are trusted later) must be able to
# PROVE its harness/driver/ledger did not change, with checksums rather than file times.
#
#   fnfuzz_manifest.sh write OUT FNFUZZ LEDGER STOCK REBUILT TRIALS [EXTRAFILE...]   write manifest to OUT (stdout if OUT is -)
#   fnfuzz_manifest.sh files LABEL FILE...                                            manifest of arbitrary files (e.g. what an old run used)
#   fnfuzz_manifest.sh cmp A B                                                        exit 0 if the checksum/env lines of A and B are identical, else print the differences, exit 1
#
# Lines: `file <role> <md5> <bytes> <path>`, `env FNFUZZ_X=value`, `trials N`, `ledger_rows N`; `#`-lines (date, host, ls -l times) are informational and ignored by cmp.
# Portable sh (Tiger: `md5 -q`, BSD ls; Linux: md5sum).

sum_of() { if command -v md5sum >/dev/null 2>&1; then md5sum "$1" | awk '{print $1}'; else md5 -q "$1"; fi; }
bytes_of() { wc -c < "$1" | tr -d ' '; }
emit_file() { # role path
  if [ -f "$2" ]; then echo "file $1 `sum_of "$2"` `bytes_of "$2"` $2"; echo "# `ls -l "$2"`"
  else echo "file $1 MISSING 0 $2"; fi
}
header() { echo "# fnfuzz manifest v1 `date` on `uname -n` (`uname -srm`)"; echo "# cwd `pwd`"; }
envlines() { env | grep '^FNFUZZ_' | grep -v '^FNFUZZ_RESUME=' | grep -v '^FNFUZZ_MANIFEST_LAYOUT=' | sort | sed 's/^/env /'; }

case "$1" in
write)
  [ $# -ge 7 ] || { echo "usage: $0 write OUT FNFUZZ LEDGER STOCK REBUILT TRIALS [EXTRAFILE...]" >&2; exit 2; }
  OUT=$2; FZ=$3; LED=$4; STK=$5; REB=$6; TR=$7; shift 7
  {
    header
    emit_file harness "$FZ"; emit_file ledger "$LED"; emit_file stock "$STK"; emit_file rebuilt "$REB"
    emit_file script "$0"
    [ -f "$FZ.c" ] && emit_file source "$FZ.c"
    [ -f "$FZ.build" ] && { emit_file build "$FZ.build"; sed 's/^/buildinfo /' "$FZ.build"; }
    [ -n "$FNFUZZ_MANIFEST_LAYOUT" ] && echo "layout $FNFUZZ_MANIFEST_LAYOUT"
    [ -n "$FNFUZZ_PAR_SCRIPT" ] && emit_file script "$FNFUZZ_PAR_SCRIPT"
    [ -n "$FNFUZZ_DATA" ] && emit_file data "$FNFUZZ_DATA"
    for f in "$@"; do emit_file extra "$f"; done
    echo "trials $TR"
    echo "ledger_rows `awk -F'\t' 'NF >= 7 && $1 ~ /^[0-9]+$/' "$LED" | wc -l | tr -d ' '`"
    envlines
  } > "${OUT}.tmp$$" 2>&1
  if [ "$OUT" = - ]; then cat "${OUT}.tmp$$"; rm -f "${OUT}.tmp$$"; else mv "${OUT}.tmp$$" "$OUT"; fi ;;
files)
  L=$2; shift 2
  { header; for f in "$@"; do emit_file "$L" "$f"; done; } ;;
cmp)
  grep -v '^#' "$2" > "$2.cmpA$$" 2>/dev/null; grep -v '^#' "$3" > "$3.cmpB$$" 2>/dev/null
  if cmp -s "$2.cmpA$$" "$3.cmpB$$"; then rc=0; else echo "manifest differs ($2 vs $3):"; diff "$2.cmpA$$" "$3.cmpB$$"; rc=1; fi
  rm -f "$2.cmpA$$" "$3.cmpB$$"; exit $rc ;;
*) echo "usage: $0 write|files|cmp ..." >&2; exit 2 ;;
esac
