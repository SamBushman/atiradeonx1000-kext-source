#!/bin/sh
# build_gld_image.sh - build the machine-transcribed ATIRadeonX1000GLDriver bundle image from the CURRENT corpus (renamed names included) on the Tiger G5.
#   sh Tools/userspace/build_gld_image.sh [ssh-host=G5] [out-dir-on-dev=~/g5logs/gld_image]    (run from the repository root)
# Steps: link_corpus.py (dev) -> fix_link_tree.py (renamed `L...` names are file-local assembler labels on Mach-O) -> ship -> build.sh on the host with ld64 first
# in PATH and -B (the stock ld mis-links this size). Result on the host: ~/rung3/gld_<sha>/gld_link/ATIRadeonX1000GLDriver_renamed (install name = stock's).
# Needs the stock binary and the Ghidra data dump (paths below); exit 0 only if the host link produced the image.
H=${1:-G5}; EV=${2:-$HOME/g5logs/gld_image}; SHA=$(git rev-parse --short HEAD) || exit 2
# optimisation level of the image: -O2 -mtune=970 by default (stock's own code has the -mtune=970 nop padding; issue #209: -O0 was 20-39% slower than stock in UT2004/Doom 3,
# -O1 left state-change paths 5-9% slower). LINK_OPT=-O1 / -O0 give the older images; the GL suite is byte-identical to stock at -O1 and -O2 -mtune=970.
export LINK_OPT=${LINK_OPT:--O2 -mtune=970}
# code model: stock reaches its globals with direct pc-relative/absolute addressing; -fPIC adds a non-lazy-pointer load per global access (1862 NL pointers), which cost
# the state-change draw paths 5-8% (pcd microbench: arb env +7.5% -> -0.1%, UT2004 DM-Antalus_high min -5.0% -> -1.9%). -mdynamic-no-pic matches stock. LINK_PIC=-fPIC restores the old image.
export LINK_PIC=${LINK_PIC:--mdynamic-no-pic}
# the parts that are almost entirely shader-compiler code (Compiler__/Scheduler__/RegAlloc__/PackState__/Program__/IRInst__/ValueKey__/R300*/Khan*/Fudo*...) are built -Os: the first flush on a
# fresh context runs that compiler, and -Os code is 3-4% smaller and +1-2% faster there, while the draw/state parts stay -O2 (issue #212; -Os everywhere makes draw100 +3-4%).
# LINK_OPT_ALT_FILES="" builds everything at LINK_OPT.
export LINK_OPT_ALT=${LINK_OPT_ALT:--Os -mtune=970}
export LINK_OPT_ALT_FILES=${LINK_OPT_ALT_FILES-part_008 part_009 part_017 part_024 part_036 part_039 part_040 part_043 part_044 part_045 part_046 part_047 part_048 part_049 part_050 part_051 part_052 part_056}
STOCK=${STOCK_GLD:-$HOME/Documents/ATI-X1900-Decomp/tiger-hd-pull/ATIRadeonX1000GLDriver.bundle.bin}
GDATA=${GLD_GHIDRA_DATA:-$HOME/Documents/ATI-X1900-Decomp/work-bugwf/link/gld_data.tsv}
# GLD_GHIDRA_DATA (Ghidra gs/DumpData.java output for the stock GLDriver) is archived in the repo; use that unless a local copy is given.
if [ ! -f "$GDATA" ]; then
    mkdir -p "$EV"; xz -dc Userspace/ATIRadeonX1000GLDriver/ppc/ghidra/gld_data.tsv.xz > "$EV/gld_data.tsv" || { echo "cannot read the archived Ghidra data (need xz, run from the repository root)"; exit 2; }
    GDATA="$EV/gld_data.tsv"
fi
# the stock binary is Apple's and is not in the repo: copy /System/Library/Extensions/ATIRadeonX1000GLDriver.bundle/Contents/MacOS/ATIRadeonX1000GLDriver from your own Tiger 10.4.11 install (md5 5d63b5e3d86e770daa6aee657bc784c2) and pass STOCK_GLD=
[ -f "$STOCK" ] || { echo "stock GLDriver binary not found at $STOCK (set STOCK_GLD=/path/to/ATIRadeonX1000GLDriver)"; exit 2; }
mkdir -p "$EV"; rm -rf "$EV/gld_link"
python3 Tools/userspace/link_corpus.py Userspace/ATIRadeonX1000GLDriver/ppc "$STOCK" "$GDATA" "$EV/gld_link" --config Tools/userspace/link_config/gld.json > "$EV/link.log" 2>&1 || { tail -5 "$EV/link.log"; exit 2; }
python3 Tools/userspace/fix_link_tree.py "$EV/gld_link" || exit 2
sed -i 's#^gcc -arch ppc -bundle#gcc -B/usr/local/opt/ld64/bin/ -arch ppc -bundle#' "$EV/gld_link/build.sh"
tar czf "$EV/gld_link.tgz" -C "$EV" gld_link && scp -q "$EV/gld_link.tgz" $H:rung3/gld_$SHA.tgz || exit 2
ssh $H "cd rung3 && rm -rf gld_$SHA && mkdir gld_$SHA && cd gld_$SHA && tar xzf ../gld_$SHA.tgz && cd gld_link && (PATH=/usr/local/opt/ld64/bin:\$PATH sh build.sh ATIRadeonX1000GLDriver_renamed > ../build.log 2>&1; echo \$? > ../build.rc) </dev/null"
ssh $H "cd rung3/gld_$SHA && cat build.rc && grep -c 'COMPILE FAIL' build.log; grep -v 'COMPILE FAIL' build.log | head -20; ls -l gld_link/ATIRadeonX1000GLDriver_renamed"
[ "$(ssh $H cat rung3/gld_$SHA/build.rc)" = 0 ] && ssh $H "test -s rung3/gld_$SHA/gld_link/ATIRadeonX1000GLDriver_renamed" && echo "BUILT $SHA: ~/rung3/gld_$SHA/gld_link/ATIRadeonX1000GLDriver_renamed"
