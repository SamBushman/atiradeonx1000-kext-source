#!/bin/sh
# run_rung3.sh NAME [ava_drive args...]  (on the G5, inside the console session) - rung 3: ava_drive under the guard with doIDCT FORWARDED (GUARD_FORWARD=${GF:-18}). Issue #140 / #87.
cd "$HOME/rung3/va" || exit 1
N=$1; shift
rm -f $N.out $N.tsv $N.tsv.mem
RB_DUMP=$HOME/rung3/va/$N GUARD_LOG=$HOME/rung3/va/$N.tsv GUARD_FORWARD=${GF:-18} DYLD_INSERT_LIBRARIES=$HOME/rung3/va/iokit_guard_va.dylib WATCHDOG_S=${WATCHDOG_S:-60} ./ava_drive "$@" > $N.out 2>&1
echo "EXIT=$?" >> $N.out
