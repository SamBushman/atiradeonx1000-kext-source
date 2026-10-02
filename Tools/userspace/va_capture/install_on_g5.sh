#!/bin/sh
# install_on_g5.sh (dev machine) - copy this folder to the G5 as /tmp/va_cap, build the recorder there (gcc 4.0.1: `gcc -dynamiclib ... -framework IOKit -framework CoreFoundation`) and run its self-test
# (a passive recording of the already-proven-safe Surface get_state). Nothing is played and no kext call besides get_state is made.
H=${1:-G5}; cd "`dirname "$0"`" || exit 1
tar czf /tmp/va_cap.tgz . && scp -q /tmp/va_cap.tgz $H:/tmp/va_cap.tgz && ssh $H 'rm -rf /tmp/va_cap && mkdir /tmp/va_cap && cd /tmp/va_cap && tar xzf /tmp/va_cap.tgz && gcc -dynamiclib -o iokit_record_va.dylib iokit_record_va.c -framework IOKit -framework CoreFoundation && gcc -o record_selftest record_selftest.c -framework IOKit -framework CoreFoundation && IOKIT_RECORD_LOG=/tmp/va_cap/self.tsv DYLD_INSERT_LIBRARIES=/tmp/va_cap/iokit_record_va.dylib ./record_selftest && chmod +x *.command *.sh && echo INSTALL_OK'
