#!/bin/sh
# build_userspace_images.sh - build ALL FIVE renamed userspace images from the CURRENT corpora on the Tiger G5 (the whole-stack arm of Tests/full_evaluation_runbook.md).
#   sh Tools/userspace/build_userspace_images.sh [ssh-host=G5] [out-dir-on-dev=~/g5logs/us_images]    (run from the repository root, tree committed)
# Result on the host: ~/rung3/us_<sha>/{gld,libgl,glprog,ga,va}/ - the GLDriver via build_gld_image.sh (-> ~/rung3/gld_<sha>/gld_link/ATIRadeonX1000GLDriver_renamed, the file gld_redirect points at), and for the other four the image
# under the STOCK install name (so DYLD_LIBRARY_PATH / the system loaders pick it up for the whole process; a dlopen of a copy with the stock name would return the already-loaded system image, so side-by-side tests rebuild with INSTALL=...).
#   (plus ~/rung3/us_<sha>/sbs/{libGL,libGLProgrammability}.dylib under a different install name, for the side-by-side tests)
#   ~/rung3/us_<sha>/libgl/libGL.dylib   ~/rung3/us_<sha>/glprog/libGLProgrammability.dylib   ~/rung3/us_<sha>/ga/ATIRadeonX1000GA.plugin   ~/rung3/us_<sha>/va/ATIRadeonX1000VADriver
# Exit 0 only if every image linked. Inputs: stock binaries in $TIGER (~/Documents/ATI-X1900-Decomp/tiger-hd-pull), Ghidra data dumps in $LINK (work-bugwf/link), OpenGL headers in $GLH (default: fetched from the host).
H=${1:-G5}; EV=${2:-$HOME/g5logs/us_images}; SHA=$(git rev-parse --short HEAD) || exit 2
TIGER=${TIGER:-$HOME/Documents/ATI-X1900-Decomp/tiger-hd-pull}; LINK=${LINK:-$HOME/Documents/ATI-X1900-Decomp/work-bugwf/link}
GLH=${GLH:-$EV/glhdr}
mkdir -p "$EV" "$GLH"
[ -f "$GLH/gl.h" ] || scp -q $H:/System/Library/Frameworks/OpenGL.framework/Headers/gl.h $H:/System/Library/Frameworks/OpenGL.framework/Headers/glext.h "$GLH/" || exit 2
export GL_HEADERS=$GLH SCRATCH_LINK=$LINK
rc=0
# GLDriver: the existing script (renamed bundle image, stock install name)
sh Tools/userspace/build_gld_image.sh $H "$EV/gld" > "$EV/gld.log" 2>&1 || { echo "GLDriver build FAILED (see $EV/gld.log)"; tail -5 "$EV/gld.log"; rc=1; }
# the other four: name  corpus  stock-binary  data-dump  config  output-file
build_one() {
    n=$1; corpus=$2; stock=$3; data=$4; cfg=$5; out=$6
    d="$EV/${n}_link"; rm -rf "$d"
    python3 Tools/userspace/link_corpus.py "Userspace/$corpus/ppc" "$TIGER/$stock" "$LINK/$data" "$d" --config "Tools/userspace/link_config/$cfg" > "$EV/$n.link.log" 2>&1 || { echo "$n: link_corpus FAILED"; tail -5 "$EV/$n.link.log"; rc=1; return; }
    python3 Tools/userspace/fix_link_tree.py "$d" >> "$EV/$n.link.log" 2>&1 || { echo "$n: fix_link_tree FAILED"; tail -5 "$EV/$n.link.log"; rc=1; return; }
    tar czf "$EV/$n.tgz" -C "$EV" "${n}_link" && scp -q "$EV/$n.tgz" $H:rung3/us_$SHA.$n.tgz || { echo "$n: ship FAILED"; rc=1; return; }
    ssh $H "cd rung3 && mkdir -p us_$SHA && cd us_$SHA && rm -rf $n ${n}_link && tar xzf ../us_$SHA.$n.tgz && mv ${n}_link $n && cd $n && (PATH=/usr/local/opt/ld64/bin:\$PATH sh build.sh $out > ../$n.build.log 2>&1; echo \$? > ../$n.build.rc) </dev/null"
    # the two dylibs also get a copy under a DIFFERENT install name (sbs/): the side-by-side tests of Tests/userspace dlopen stock and rebuilt in one process, and a dlopen of a
    # copy that keeps the stock name returns the already-loaded system image
    case $n in libgl|glprog) ssh $H "cd rung3/us_$SHA && mkdir -p sbs && cd $n && PATH=/usr/local/opt/ld64/bin:\$PATH INSTALL=\$HOME/rung3/us_$SHA/sbs/$out sh build.sh ../sbs/$out > ../$n.sbs.log 2>&1" </dev/null || { echo "$n: side-by-side build FAILED"; rc=1; } ;; esac
    if [ "$(ssh $H cat rung3/us_$SHA/$n.build.rc)" = 0 ] && ssh $H "test -s rung3/us_$SHA/$n/$out"; then echo "BUILT $n: ~/rung3/us_$SHA/$n/$out"; else echo "$n: host build FAILED"; ssh $H "tail -8 rung3/us_$SHA/$n.build.log"; rc=1; fi
}
build_one libgl libGL libGL.dylib libgl_data.tsv libGL.json libGL.dylib
build_one glprog libGLProgrammability libGLProgrammability.dylib glprog_data.tsv glprog.json libGLProgrammability.dylib
build_one ga ATIRadeonX1000GA ATIRadeonX1000GA.plugin.bin ga_data.tsv ga.json ATIRadeonX1000GA
build_one va ATIRadeonX1000VADriver ATIRadeonX1000VADriver.bundle.bin va_data.tsv va.json ATIRadeonX1000VADriver
[ $rc = 0 ] && echo "ALL FIVE IMAGES BUILT for $SHA"
exit $rc
