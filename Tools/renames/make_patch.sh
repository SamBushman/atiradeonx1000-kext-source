#!/bin/sh
# make_patch.sh - record the hand edits made to a mechanically ported Sources/*_Port.cpp as Tools/renames/patches/<name>.patch (see Tools/apply_renames.py).
# Usage: sh Tools/renames/make_patch.sh Sources/<File>_Port.cpp      (run from the repo root, after editing the file in the working tree)
# The patch is the difference between the file as a re-port would leave it (the committed file with its committed patch taken back out, then the CURRENT
# rename tables applied to it) and the file as it is now, so it carries every earlier hand edit too and stays valid when the tables gain new rows.
# Review `git diff` before committing.
set -e
F=$1; P=Tools/renames/patches/$(basename "$F" .cpp).patch; T=$(mktemp -d)
mkdir -p "$T/Sources" "$T/Headers" "$T/Tools/renames/patches" "$T/b/Sources"
cp -R Sources/. "$T/Sources/"; cp -R Headers/. "$T/Headers/"; cp Tools/renames/*.tsv "$T/Tools/renames/"
git show "HEAD:$F" > "$T/$F"
if git cat-file -e "HEAD:$P" 2>/dev/null; then git show "HEAD:$P" | patch -R -s -p1 -d "$T"; fi
python3 Tools/apply_renames.py --root "$T" > /dev/null || { echo "make_patch: applying the rename tables to the re-ported text failed"; exit 1; }
mkdir -p "$T/a/Sources"; cp "$T/$F" "$T/a/$F"; cp "$F" "$T/b/$F"
( cd "$T" && diff -u "a/$F" "b/$F" ) > "$P" || true
rm -rf "$T"
python3 Tools/apply_renames.py --check
