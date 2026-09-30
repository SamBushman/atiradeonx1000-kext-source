#!/bin/bash
# relink.sh NAME : link_corpus -> G5 build -> local copies rebuilt_NAME.{bin,nm}
N=$1; cd ~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source; W=~/Documents/ATI-X1900-Decomp
rm -rf /tmp/lk_$N; python3 Tools/userspace/link_corpus.py Userspace/ATIRadeonX1000GLDriver/ppc $W/tiger-hd-pull/ATIRadeonX1000GLDriver.bundle.bin $W/work-bugwf/link/gld_data.tsv /tmp/lk_$N --config Tools/userspace/link_config/gld.json > /tmp/lk_$N.log 2>&1 || { echo LINKFAIL; exit 1; }
cd /tmp && tar cf lk_$N.tar lk_$N && scp -q lk_$N.tar G5:/tmp/lk_$N.tar
ssh G5 "cd '/Volumes/Test HD/claude_bugwf' && rm -rf gld_$N lk_$N && tar xf /tmp/lk_$N.tar && mv lk_$N gld_$N && cd gld_$N && (nohup sh build.sh out_$N > build.log 2>&1 < /dev/null & disown -a); sleep 1"
sleep 45
for i in $(seq 1 80); do n=$(ssh G5 "ps auxww | grep -c '[b]uild.sh'"); [ "$n" = 0 ] && break; sleep 8; done
ssh G5 "cd '/Volumes/Test HD/claude_bugwf/gld_$N'; grep -c 'COMPILE FAIL' build.log; ls out_$N >/dev/null" || { echo BUILDFAIL; exit 1; }
cd /tmp/emu; scp -q "G5:/Volumes/Test\ HD/claude_bugwf/gld_$N/out_$N" rebuilt_$N.bin; ssh G5 "nm -n '/Volumes/Test HD/claude_bugwf/gld_$N/out_$N'" > rebuilt_$N.nm; echo OK
