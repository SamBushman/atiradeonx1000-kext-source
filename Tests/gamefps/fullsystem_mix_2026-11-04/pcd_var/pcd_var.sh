#!/bin/sh
O=/var/home/sam/g5logs/nov2_209/pcd_var; rm -rf $O; mkdir -p $O
B=/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle/Contents/MacOS/ATIRadeonX1000GLDriver
swap() { case $1 in stock) F=GLDriver.stock;; *) F=GLDriver.$1;; esac
  got=`timeout 60 ssh G5 "sudo cp /Users/bushmas/rung3/final_eval/inst209/$F /tmp/g.swap && sudo chown root:wheel /tmp/g.swap && sudo chmod 755 /tmp/g.swap && sudo mv /tmp/g.swap $B && md5 -q $B"`
  [ -n "$got" ] || { echo "SWAP FAILED $1" > $O/FAIL; exit 1; }; echo "$1 $got" >> $O/swaps.txt; }
for rd in 1 2 3; do
  case $rd in 1) V="stock fe83266b 525fa848 mix";; 2) V="mix 525fa848 fe83266b stock";; 3) V="525fa848 mix stock fe83266b";; esac
  for v in $V; do
    swap $v
    for t in "arb prog" "matrix change" "tex rebind" "lighting"; do
      ssh G5 "cd ~/rung3 && PCD_ONLY='$t' PCD_REPS=7 PCD_MUL=100 ./pcd 2>&1" | sed "s/^/$v $rd /" >> $O/res.txt
    done
  done
done
swap mix; echo DONE > $O/done
