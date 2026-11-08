#!/bin/sh
# Phase 2 / arm run: Phase 1 steps 1-4 with the environment of ONE arm, into ~/rung3/final_eval/rebuilt<ARM>_*.   Run on the G5, detached:  sh phase2_arm.sh U|K|KU
#   U  = stock kext + rebuilt userspace (GLDriver via gld_redirect, libGL + libGLProgrammability via DYLD_LIBRARY_PATH)
#   K  = rebuilt kext + stock userspace (no environment)
#   KU = rebuilt kext + rebuilt userspace
# GA / VA are loaded by WindowServer / the video stack, not by these workloads: they are proven and exercised in Phase 4 (WindowServer relaunch).
ARM=${1:?U|K|KU}; SHA=${SHA:?set SHA}; IMG=${IMG:?set IMG}; S=$HOME/rung3/src_$SHA; E=$HOME/rung3/final_eval; W=$HOME/rung3/opwork_$SHA; P=$E/rebuilt${ARM}
R_GLD=$HOME/rung3/gld_$IMG/gld_link/ATIRadeonX1000GLDriver_renamed; UD=$HOME/rung3/us_$IMG; DD=$E/dyld_dir_$IMG
mkdir -p $E $DD; rm -f $DD/*; ln -s $UD/libgl/libGL.dylib $DD/libGL.dylib; ln -s $UD/glprog/libGLProgrammability.dylib $DD/libGLProgrammability.dylib
case $ARM in
  U|KU) export GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO=$R_GLD DYLD_INSERT_LIBRARIES=$S/Tools/userspace/gld_redirect.dylib DYLD_LIBRARY_PATH=$DD GLD_REDIRECT_LOG=${P}_redirect.log; : > $GLD_REDIRECT_LOG;;
  K) unset GLD_REDIRECT_FROM GLD_REDIRECT_TO DYLD_INSERT_LIBRARIES DYLD_LIBRARY_PATH GLD_REDIRECT_LOG;;
  *) echo "bad arm"; exit 2;;
esac
echo "=== arm $ARM start $(date)  kextstat: $(kextstat | grep ATIRadeonX1000)"
env | egrep "^(GLD_|DYLD_)" | sed 's/^/env: /'
# loaded-image proof (rule 0): which libGL / libGLProgrammability / GLDriver this arm's processes really map
cd $S/Tests/userspace
DYLD_PRINT_LIBRARIES=1 ./libgl_test2 > ${P}_proof_libgl.txt 2>&1; echo "proof libgl_test2 rc=$?"
grep -i "libGL\|libGLProgrammability" ${P}_proof_libgl.txt | head -6
GLD_REDIRECT_LOG=${P}_proof_gld.txt ./cgl_probe > ${P}_proof_cgl_probe.txt 2>&1; echo "proof cgl_probe rc=$?"; grep -c "redirected to" ${P}_proof_gld.txt 2>/dev/null
cd $S/Tests
echo "=== step 1 normal $(date)"; OUT=${P}_baseline_normal.txt sh compare_to_baseline.sh; echo "rc=$?"
echo "=== step 1 deep $(date)"; DEEP=1 OUT=${P}_baseline_deep.txt sh compare_to_baseline.sh; echo "rc=$?"
echo "=== step 2 GL feature suite $(date)"; sh run_gl_feature_suite.sh ${P}_gl 120 > ${P}_gl.log 2>&1; echo "rc=$?"; tail -2 ${P}_gl.log
echo "=== step 3 perf_collect $(date)"; sh perf_collect.sh ${P}_perf 5 50000 100 > ${P}_perf.log 2>&1; echo "rc=$?"; tail -2 ${P}_perf.log
echo "=== step 4 opcode battery $(date)"; cd $W && SRC=$S sh run_all_opcode_workloads.sh ${P}_opcodes > ${P}_opcodes.log 2>&1; echo "rc=$?"; cat ${P}_opcodes/groups.txt
echo "=== arm $ARM DONE $(date)"
