#!/bin/sh
# cfw.sh OUT ROUNDS ITERS VARIANTS...  : interleaved cfwarm (first-flush + steady) per GLDriver variant, rotating order
O=$1; R=$2; IT=$3; shift 3; : > $O
B=/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle/Contents/MacOS/ATIRadeonX1000GLDriver
rd=1
while [ $rd -le $R ]; do
  for v in "$@"; do
    case $v in stock) F=GLDriver.stock;; *) F=GLDriver.$v;; esac
    got=`timeout 60 ssh G5 "sudo cp /Users/bushmas/rung3/final_eval/inst209/$F /tmp/g.swap && sudo chown root:wheel /tmp/g.swap && sudo chmod 755 /tmp/g.swap && sudo mv /tmp/g.swap $B && md5 -q $B"`
    [ -n "$got" ] || { echo "SWAP FAILED $v" >> $O; exit 1; }
    timeout 600 ssh G5 "cd /Users/bushmas/rung3 && ./cfwarm $IT" | grep "#1 \|#2 \|#5 " | sed "s/^/$v $rd /" >> $O
    sleep 2
  done
  set -- "$@"; first=$1; shift; set -- "$@" $first
  rd=$((rd+1))
done
ssh G5 "sudo cp /Users/bushmas/rung3/final_eval/inst209/GLDriver.stock /tmp/g.swap && sudo chown root:wheel /tmp/g.swap && sudo chmod 755 /tmp/g.swap && sudo mv /tmp/g.swap $B && md5 -q $B" >> $O
echo DONE >> $O
