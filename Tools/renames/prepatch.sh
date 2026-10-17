#!/bin/sh
# prepatch.sh - print a ported function as the `use` rows of the rename tables see it: the committed file with its committed patch taken back out and the
# def/decl rows applied, but no `use` rows and no patch (use rows are applied BEFORE the patches, so their from/to anchors must match this text).
# Usage: sh Tools/renames/prepatch.sh Sources/<File>_Port.cpp       (run from the repository root)
set -e
F=$1; P=Tools/renames/patches/$(basename "$F" .cpp).patch; T=$(mktemp -d)
mkdir -p "$T/Sources" "$T/Headers" "$T/Tools/renames/patches"
cp -R Sources/. "$T/Sources/"; cp -R Headers/. "$T/Headers/"; cp Tools/renames/*.tsv "$T/Tools/renames/"
git show "HEAD:$F" > "$T/$F"
if git cat-file -e "HEAD:$P" 2>/dev/null; then git show "HEAD:$P" | patch -R -s -p1 -d "$T"; fi
python3 Tools/apply_renames.py --no-use --root "$T" > /dev/null || true
cat "$T/$F"; rm -rf "$T"
