#!/bin/sh
# make_image_set.sh NEW BASE [ga=IMG] [va=IMG] [glprog=IMG] [libgl=IMG] [gld=IMG]     (run ON the G5)
# Compose a userspace image SET named NEW out of symlinks into the sets of already-built images: every component comes from BASE unless overridden (component=IMG).
# Why: a fix often lands in ONE image after the others were built and evaluated (Nov 7: VA fix cb67fa1e = us_5d632cc5/va, everything else from 9904dde8 -> "ku233"). Rebuilding all five images
# only to carry one changed binary wastes hours; the composite set is exactly "the evaluated images + the one fixed image". Record the composition in the manifest (md5 of each binary).
# Layout it creates (the layout every arm script expects, see Tools/userspace/ku_env.sh and Tools/gamefps/make_game_env.sh):
#   ~/rung3/us_NEW/{ga,va,glprog,libgl}  ~/rung3/gld_NEW  ~/rung3/final_eval/dyld_dir_NEW/{libGL.dylib,libGLProgrammability.dylib}
# Use NEW as IMG with ku_env.sh / make_game_env.sh / soak_ku_run.sh and the SHA of the tree whose Tools/userspace/gld_redirect.dylib is used (any staged tree works, it does not depend on the images).
NEW=${1:?new set name}; BASE=${2:?base set (sha)}; shift 2; R=$HOME/rung3
ga=$BASE; va=$BASE; glprog=$BASE; libgl=$BASE; gld=$BASE
for kv in "$@"; do k=${kv%%=*}; v=${kv#*=}; case $k in ga|va|glprog|libgl|gld) eval "$k=$v";; *) echo "bad component $k"; exit 2;; esac; done
for p in $R/us_$ga/ga $R/us_$va/va $R/us_$glprog/glprog/libGLProgrammability.dylib $R/us_$libgl/libgl/libGL.dylib $R/gld_$gld; do [ -e "$p" ] || { echo "missing $p"; exit 1; }; done
mkdir -p $R/us_$NEW $R/final_eval/dyld_dir_$NEW
rm -f $R/us_$NEW/ga $R/us_$NEW/va $R/us_$NEW/glprog $R/us_$NEW/libgl $R/gld_$NEW $R/final_eval/dyld_dir_$NEW/libGL.dylib $R/final_eval/dyld_dir_$NEW/libGLProgrammability.dylib
ln -s $R/us_$ga/ga $R/us_$NEW/ga; ln -s $R/us_$va/va $R/us_$NEW/va; ln -s $R/us_$glprog/glprog $R/us_$NEW/glprog; ln -s $R/us_$libgl/libgl $R/us_$NEW/libgl
ln -s $R/gld_$gld $R/gld_$NEW
ln -s $R/us_$libgl/libgl/libGL.dylib $R/final_eval/dyld_dir_$NEW/libGL.dylib; ln -s $R/us_$glprog/glprog/libGLProgrammability.dylib $R/final_eval/dyld_dir_$NEW/libGLProgrammability.dylib
echo "set $NEW: ga=$ga va=$va glprog=$glprog libgl=$libgl gld=$gld"
for f in $R/us_$NEW/ga/ATIRadeonX1000GA $R/us_$NEW/va/ATIRadeonX1000VADriver $R/gld_$NEW/gld_link/ATIRadeonX1000GLDriver_renamed $R/final_eval/dyld_dir_$NEW/libGL.dylib $R/final_eval/dyld_dir_$NEW/libGLProgrammability.dylib; do md5 $f; done
