#!/bin/sh
# runs ava_drive under the guard inside the console (Aqua) session; $1 = run name, $2.. = ava_drive args
cd /tmp/va_cap2 || exit 1
N=$1; shift
rm -f run_$N.out run_$N.tsv run_$N.tsv.mem
GUARD_LOG=/tmp/va_cap2/run_$N.tsv DYLD_INSERT_LIBRARIES=/tmp/va_cap2/iokit_guard_va.dylib WATCHDOG_S=90 ./ava_drive "$@" > run_$N.out 2>&1
echo "EXIT=$?" >> run_$N.out
