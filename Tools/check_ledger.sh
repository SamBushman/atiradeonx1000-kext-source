#!/bin/sh
# check_ledger.sh - after Tools/remote_build.sh: pull the rebuilt kext, regenerate the ledger, and diff vtables.
# Usage: sh Tools/check_ledger.sh [ssh-host] [class ...]   (classes limit the vtable diff)
H=${1:-G5}; shift
STOCK=${STOCK:-$HOME/Documents/ATI-X1900-Decomp/tiger-hd-pull/ATIRadeonX1000.kext.bin}
T=${TMPDIR:-/tmp}/ledger_check; mkdir -p $T
scp -q $H:/tmp/rb_cur/out/ATIRadeonX1000 $T/ours.bin
ssh $H 'nm /tmp/rb_cur/out/ATIRadeonX1000 | awk "\$2==\"T\"||\$2==\"t\"{print \$3}" | sort -u' > $T/defined.txt
python3 Tools/build_ledger.py Ledger/kext_ppc_functions.tsv $STOCK $T/defined.txt > Ledger/kext_ppc_ledger.tsv
CLS=${*:-"IOATIR500Accelerator ATIRadeonX1000 IOATIR500GLContext ATIR500GLContext IOATIR5002DContext ATIR5002DContext IOATIR500DVDContext ATIR500DVDContext IOATIR500Surface ATIR500Surface IOATIR500Shared ATIR500Memory"}
python3 Tools/vtable_map.py $STOCK $CLS | sed 's/ @ 0x[0-9a-f]* ([_a-z]*)//' > $T/vt_stock.txt
python3 Tools/vtable_map.py $T/ours.bin $CLS | sed 's/ @ 0x[0-9a-f]* ([_a-z]*)//' > $T/vt_ours.txt
echo "vtable lines differing: $(diff $T/vt_stock.txt $T/vt_ours.txt | grep -c '^[<>]')"
