#!/bin/sh
# build_gleng_image.sh - build the machine-transcribed GLEngine bundle image from the CURRENT Userspace/GLEngine corpus on the Tiger G5.
#   sh Tools/userspace/build_gleng_image.sh [ssh-host=G5] [out-dir-on-dev=~/g5logs/gleng-corpus/link]    (run from the repository root)
# Steps: link_corpus.py (dev) -> fix_link_tree.py -> ship -> build.sh on the host with ld64 first in PATH. Result on the host:
#   ~/rung3/gleng_<sha>/gleng_link/GLEngine_rebuilt  (a bundle with the stock's 17 exports; the stock is OpenGL.framework/Resources/GLEngine.bundle/GLEngine).
# Inputs: the stock GLEngine (Apple's, Tiger 10.4.11, md5 02f4a2854a95be1f2853baeb99ae22b3; STOCK_GLENGINE=) and the Ghidra gs/DumpData.java output of the
# analysed copy (GLENGINE_GHIDRA_DATA=; the corpus archive carries it as Userspace/GLEngine/ppc/ghidra/gleng_data.tsv.xz).
# Same optimisation/code model as the GLDriver image: -O2 -mtune=970, -mdynamic-no-pic (stock addresses its globals directly).
H=${1:-G5}; EV=${2:-$HOME/g5logs/gleng-corpus/link}; SHA=$(git rev-parse --short HEAD) || exit 2
export LINK_OPT=${LINK_OPT:--O2 -mtune=970} LINK_PIC=${LINK_PIC:--mdynamic-no-pic}
STOCK=${STOCK_GLENGINE:-$HOME/Documents/ATI-X1900-Decomp/tiger-hd-pull/GLEngine.bundle.bin}
GDATA=${GLENGINE_GHIDRA_DATA:-$EV/gleng_data.tsv}
if [ ! -f "$GDATA" ]; then
    mkdir -p "$EV"; xz -dc Userspace/GLEngine/ppc/ghidra/gleng_data.tsv.xz > "$EV/gleng_data.tsv" && xz -dc Userspace/GLEngine/ppc/ghidra/gleng_data.tsv.syms.xz > "$EV/gleng_data.tsv.syms" || { echo "no Ghidra data dump"; exit 2; }
    GDATA="$EV/gleng_data.tsv"
fi
[ -f "$STOCK" ] || { echo "stock GLEngine not found at $STOCK (set STOCK_GLENGINE=; Apple's file, not in the repo)"; exit 2; }
mkdir -p "$EV"; rm -rf "$EV/gleng_link"
python3 Tools/userspace/link_corpus.py Userspace/GLEngine/ppc "$STOCK" "$GDATA" "$EV/gleng_link" --config Tools/userspace/link_config/gleng.json > "$EV/link.log" 2>&1 || { tail -5 "$EV/link.log"; exit 2; }
python3 Tools/userspace/fix_link_tree.py "$EV/gleng_link" || exit 2
# ld64 (not the stock ld) must do the final link: the stock ld rejects the rebuilt libGLProgrammability's load commands and mis-links images of this size
sed -i 's#^gcc -arch ppc -bundle#gcc -B/usr/local/opt/ld64/bin/ -arch ppc -bundle#' "$EV/gleng_link/build.sh"
tar czf "$EV/gleng_link.tgz" -C "$EV" gleng_link && scp -q "$EV/gleng_link.tgz" $H:rung3/gleng_$SHA.tgz || { echo "ship FAILED"; exit 2; }
ssh $H "cd rung3 && rm -rf gleng_$SHA && mkdir gleng_$SHA && cd gleng_$SHA && tar xzf ../gleng_$SHA.tgz && cd gleng_link && (PATH=/usr/local/opt/ld64/bin:\$PATH sh build.sh GLEngine_rebuilt > ../build.log 2>&1; echo \$? > ../build.rc) </dev/null"
if [ "$(ssh $H cat rung3/gleng_$SHA/build.rc)" = 0 ] && ssh $H "test -s rung3/gleng_$SHA/gleng_link/GLEngine_rebuilt"; then echo "BUILT: ~/rung3/gleng_$SHA/gleng_link/GLEngine_rebuilt"; ssh $H "grep -c 'COMPILE FAIL' rung3/gleng_$SHA/build.log"; exit 0; fi
echo "host build FAILED"; ssh $H "grep -v '^In file' rung3/gleng_$SHA/build.log | sed 's/^part_[0-9]*.c:[0-9]*: //' | sort | uniq -c | sort -rn | head -15"
exit 1
