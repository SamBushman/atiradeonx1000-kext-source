#!/bin/sh
# disassemble.sh BINARY OUT.dis [ssh-host] - `otool -arch ppc -tV` of a kext binary, made on the Tiger machine (the only place otool understands it).
H=${3:-G5}
scp -q "$1" $H:disasm_tmp.bin && ssh $H 'otool -arch ppc -tV ~/disasm_tmp.bin; rm -f ~/disasm_tmp.bin' > "$2" && echo "wrote $2 ($(wc -l < "$2") lines)"
