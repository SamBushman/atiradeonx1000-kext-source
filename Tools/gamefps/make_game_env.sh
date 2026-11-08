#!/bin/sh
# make_game_env.sh IMG SHA   (run ON the G5)  -> $HOME/rung3/ut_env_IMG, the userspace arm for the real-game benchmarks (GAME_ENV=IMG for ut2004_run_side.sh / doom3_run_side.sh, HALO_ENV=IMG for halo_run_side.sh).
# Same variables as Tools/userspace/ku_env.sh (rebuilt GLDriver + GA + VADriver through gld_redirect.dylib, rebuilt libGL / libGLProgrammability through DYLD_LIBRARY_PATH) but NEVER GLD_REDIRECT_LOG:
# the log file adds a heap allocation and slows the timed runs 6-10 % (#232). The loaded-image proof is taken in a separate untimed run (cgl_probe with a log, or DYLD_PRINT_LIBRARIES) and saved with the evidence.
IMG=${1:?img}; SHA=${2:?sha}; R=$HOME/rung3; F=$R/ut_env_$IMG
for p in $R/src_$SHA/Tools/userspace/gld_redirect.dylib $R/gld_$IMG/gld_link/ATIRadeonX1000GLDriver_renamed $R/us_$IMG/ga/ATIRadeonX1000GA $R/us_$IMG/va/ATIRadeonX1000VADriver $R/final_eval/dyld_dir_$IMG/libGL.dylib; do [ -f $p ] || { echo "missing $p"; exit 1; }; done
cat > $F <<EOF
export DYLD_INSERT_LIBRARIES=$R/src_$SHA/Tools/userspace/gld_redirect.dylib
export GLD_REDIRECT_MAP=ATIRadeonX1000GLDriver=$R/gld_$IMG/gld_link/ATIRadeonX1000GLDriver_renamed,ATIRadeonX1000GA=$R/us_$IMG/ga/ATIRadeonX1000GA,ATIRadeonX1000VADriver=$R/us_$IMG/va/ATIRadeonX1000VADriver
export DYLD_LIBRARY_PATH=$R/final_eval/dyld_dir_$IMG
unset GLD_REDIRECT_LOG GLD_REDIRECT_FROM GLD_REDIRECT_TO
EOF
echo "wrote $F"; cat $F
