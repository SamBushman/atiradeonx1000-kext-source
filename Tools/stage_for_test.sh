#!/bin/sh
# stage_for_test.sh - prepare the current tree for the G5 test campaign: build the REAL kext (-Os, production bundle id) AND every test program,
# leaving both on the G5 under ~/rung3 next to each other, without loading anything.
#   sh Tools/stage_for_test.sh [ssh-host=G5]          (run from the repository root; the tree must be committed: the staging dir is named after HEAD)
# Result on the host:  ~/rung3/src_<sha>/ (sources + built tests, Tests/build_all.out has the per-file list)  and  ~/rung3/kext_build_<sha>/ATIRadeonX1000.kext
# Exit 0 only if the kext linked AND Tests/build_all.sh built every test (0 failed, 0 unaccounted).
H=${1:-G5}; SHA=$(git rev-parse --short HEAD) || exit 2
git diff --quiet HEAD -- Headers Sources Tools Tests Resources || echo "warning: uncommitted changes are staged under the name of $SHA"
ssh $H 'ps auxww | egrep -i "godot|soak|kextload|crashdump" | grep -v egrep' | grep -v " Z " && echo "warning: stale processes above (precheck)"
T=$(mktemp -d); tar czf "$T/s.tgz" --exclude=Tools/userspace --exclude=__pycache__ --exclude=Tests/baseline --exclude=Tests/difftest Headers Sources Tools Resources Tests || exit 2
scp -q "$T/s.tgz" $H:rung3/src_$SHA.tgz || exit 2; rm -rf "$T"
ssh $H "cd rung3 && rm -rf src_$SHA kext_build_$SHA && mkdir src_$SHA && cd src_$SHA && tar xzf ../src_$SHA.tgz && OPT=-Os OUT=\$HOME/rung3/kext_build_$SHA sh Tools/build_kext.sh > ../build_$SHA.log 2>&1; echo \$? > ../build_$SHA.rc"
[ "$(ssh $H cat rung3/build_$SHA.rc)" = 0 ] || { echo "KEXT BUILD FAILED:"; ssh $H "tail -15 rung3/build_$SHA.log"; exit 1; }
echo "kext: ~/rung3/kext_build_$SHA/ATIRadeonX1000.kext  md5 $(ssh $H "md5 -q rung3/kext_build_$SHA/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000 2>/dev/null || md5 rung3/kext_build_$SHA/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000")"
ssh $H "cd rung3/src_$SHA/Tests && sh build_all.sh > build_all.out 2>&1; rc=\$?; grep -v '^built' build_all.out; exit \$rc" ; rc=$?
[ $rc = 0 ] && echo "STAGED $SHA: kext + all tests built on $H (nothing loaded)" || echo "TESTS NOT ALL BUILT (see rung3/src_$SHA/Tests/build_all.err)"
exit $rc
