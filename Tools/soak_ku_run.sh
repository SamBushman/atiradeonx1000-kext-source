#!/bin/sh
# soak_ku_run.sh IMG SHA     (run ON the G5, detached: `(nohup sh ~/rung3/srchead/Tools/soak_ku_run.sh ku233 9904dde8 > out 2>&1 < /dev/null &)`)
# The Phase 5 soak with the KU userspace exported for the soak's OWN processes (perf_baseline GL churn, parity harness). An ssh shell does NOT inherit the launchd environment that ku_env.sh sets (Nov 7: the
# first 4 h "KU" soak ran its GL workload on the STOCK GLDriver and only WindowServer was KU; found with DYLD_PRINT_LIBRARIES after the run), so it has to be exported here.
# Needs: the stock-booted G5 hot-swapped to the rebuilt kext + unstick, `NOLOG=1 sh ku_env.sh on IMG SHA` + WindowServer restart if the WS-side KU proof is wanted (Phase 5 in Tests/full_evaluation_runbook.md).
# Log $E/soak_ku2.log (+ .hwup); redirect proof $E/soak_ku2_redirect.log = one `-> redirected to .../gld_IMG/...` line per perf_baseline process: the count must equal the number of rounds. Here (not for timed runs) the redirect log is fine.
IMG=${1:?img}; SHA=${2:?sha}; R=$HOME/rung3; E=$R/final_eval
export DYLD_INSERT_LIBRARIES=$R/src_$SHA/Tools/userspace/gld_redirect.dylib
export GLD_REDIRECT_MAP=ATIRadeonX1000GLDriver=$R/gld_$IMG/gld_link/ATIRadeonX1000GLDriver_renamed,ATIRadeonX1000GA=$R/us_$IMG/ga/ATIRadeonX1000GA,ATIRadeonX1000VADriver=$R/us_$IMG/va/ATIRadeonX1000VADriver
export DYLD_LIBRARY_PATH=$E/dyld_dir_$IMG
export GLD_REDIRECT_LOG=$E/soak_ku2_redirect.log; : > $GLD_REDIRECT_LOG
cd ${SOAKDIR:-$R/srchead/Tests} && LOG=$E/soak_ku2.log MASK_INSTANCE_COUNTS=1 exec sh soak.sh ${DURATION:-14400}
