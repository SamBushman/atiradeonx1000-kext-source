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
STOCK=${STOCK_GLD:-$HOME/Documents/ATI-X1900-Decomp/tiger-hd-pull/ATIRadeonX1000GLDriver.bundle.bin}
GDATA=${GLD_GHIDRA_DATA:-$HOME/Documents/ATI-X1900-Decomp/work-bugwf/link/gld_data.tsv}
mkdir -p "$EV"; rm -rf "$EV/gld_link"
python3 Tools/userspace/link_corpus.py Userspace/ATIRadeonX1000GLDriver/ppc "$STOCK" "$GDATA" "$EV/gld_link" --config Tools/userspace/link_config/gld.json > "$EV/link.log" 2>&1 || { tail -5 "$EV/link.log"; exit 2; }
python3 Tools/userspace/fix_link_tree.py "$EV/gld_link" || exit 2
sed -i 's#^gcc -arch ppc -bundle#gcc -B/usr/local/opt/ld64/bin/ -arch ppc -bundle#' "$EV/gld_link/build.sh"
tar czf "$EV/gld_link.tgz" -C "$EV" gld_link && scp -q "$EV/gld_link.tgz" $H:rung3/gld_$SHA.tgz || exit 2
ssh $H "cd rung3 && rm -rf gld_$SHA && mkdir gld_$SHA && cd gld_$SHA && tar xzf ../gld_$SHA.tgz && cd gld_link && (PATH=/usr/local/opt/ld64/bin:\$PATH sh build.sh ATIRadeonX1000GLDriver_renamed > ../build.log 2>&1; echo \$? > ../build.rc) </dev/null"
ssh $H "cd rung3/gld_$SHA && cat build.rc && grep -c 'COMPILE FAIL' build.log; grep -v 'COMPILE FAIL' build.log | head -20; ls -l gld_link/ATIRadeonX1000GLDriver_renamed"
[ "$(ssh $H cat rung3/gld_$SHA/build.rc)" = 0 ] && ssh $H "test -s rung3/gld_$SHA/gld_link/ATIRadeonX1000GLDriver_renamed" && echo "BUILT $SHA: ~/rung3/gld_$SHA/gld_link/ATIRadeonX1000GLDriver_renamed"
