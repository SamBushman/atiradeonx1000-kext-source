#!/bin/sh
# gate.sh TAG [BASE_REV] : full gate on libGLProgrammability; prints verdict + untruncated problem list per part
cd $(git rev-parse --show-toplevel)
D=Userspace/libGLProgrammability/ppc
SPLITS=1 TAG=$1 sh Tools/userspace/verify_names.sh $D ${2:-HEAD} > ~/g5logs/$1.log 2>&1
T=/tmp/vn_Userspace_libGLProgrammability_ppc_$1
echo "VERDICT: $(tail -1 ~/g5logs/$1.log)"
for p in $T/cand.part_*.dis; do
  b=$(basename $p .dis); b=${b#cand.}
  python3 Tools/userspace/split_equiv.py $T/base.$b.dis $T/cand.$b.dis $T/base.$b.warn $T/cand.$b.warn 2>&1 | grep -v '^MERGE' | cut -c1-160 | sed "s/^/$b: /" | head -12
  python3 Tools/userspace/split_equiv.py $T/base.$b.dis $T/cand.$b.dis $T/base.$b.warn $T/cand.$b.warn 2>&1 | grep '^MERGE' | sort | uniq -c | cut -c1-160 | sed "s/^/$b: /" | head -8
done
