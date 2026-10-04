#!/bin/sh
# install_guard_on_g5.sh (dev machine) - ship this folder to the G5 as /tmp/va_cap2, build the guard shim, the self-test and the harness there (gcc 4.0.1), and run ONLY the guard self-test
# (calls already proven live on stock; nothing GUI, no doIDCT, no command buffer). The harness itself is run separately in the console session.
H=${1:-G5}; cd "`dirname "$0"`" || exit 1
python3 gen_ava_vectors.py . >/dev/null || exit 1
tar czf /tmp/va_cap2.tgz iokit_guard_va.c guard_selftest.c ava_drive.c ava_vectors.h && scp -q /tmp/va_cap2.tgz $H:/tmp/va_cap2.tgz && ssh $H 'rm -rf /tmp/va_cap2 && mkdir /tmp/va_cap2 && cd /tmp/va_cap2 && tar xzf /tmp/va_cap2.tgz && gcc -dynamiclib -o iokit_guard_va.dylib iokit_guard_va.c -framework IOKit -framework CoreFoundation && gcc -o guard_selftest guard_selftest.c -framework IOKit -framework CoreFoundation && gcc -o ava_drive ava_drive.c -F/System/Library/PrivateFrameworks -framework AppleVA -framework ApplicationServices && echo BUILD_OK && GUARD_LOG=/tmp/va_cap2/self.tsv DYLD_INSERT_LIBRARIES=/tmp/va_cap2/iokit_guard_va.dylib ./guard_selftest'
