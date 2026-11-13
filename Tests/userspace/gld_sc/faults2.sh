# faults2.sh SPEC LEDGER LISTFILE TRIAL : first fault (signal + top frames) of each listed row (nfh.sh, spinning rows interrupted after 8 s)
cd ~/rung3/fnf_237
for n in `cat $3`; do
  r=`HEADN=40 sh nfh.sh $1 $2 $n ${4:-3} 8 2>&1 | egrep -a "^(Program|#[0-3] )|^Reason" | sed 's/ ()//; s/0x[0-9a-f]* in //; s/Program received signal //; s/, Could not access memory.//' | tr '\n' ' '`
  echo "$n :: $r"
done
