#!/bin/sh
# make_patch.sh - record the hand edits made to a mechanically ported Sources/*_Port.cpp as Tools/renames/patches/<name>.patch (see Tools/apply_renames.py).
# Usage: sh Tools/renames/make_patch.sh Sources/<File>_Port.cpp      (run from the repo root, after editing the file in the working tree)
# The patch is the difference between the file as committed with its existing patch taken back out (the text a re-port + the rename table produces)
# and the file as it is now, so it carries every earlier hand edit too. Review `git diff` before committing.
set -e
F=$1; P=Tools/renames/patches/$(basename "$F" .cpp).patch; T=$(mktemp -d)
mkdir -p "$T/a/Sources" "$T/b/Sources"
git show "HEAD:$F" > "$T/a/$F"
[ -f "$P" ] && patch -R -s -p1 -d "$T/a" < "$P"
cp "$F" "$T/b/$F"
( cd "$T" && diff -u "a/$F" "b/$F" ) > "$P" || true
rm -rf "$T"
python3 Tools/apply_renames.py --check
