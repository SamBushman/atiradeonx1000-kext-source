# faults.sh SPEC LEDGER LISTFILE TRIAL: first fault (top 3 frames) of each listed row, rebuilt image 4966
cd ~/rung3/fnf_237
for n in `cat $3`; do
  r=`PRECALL=Compiler__initStaticLocals TAILN=60 sh nf.sh $1 $2 $n ${4:-3} 2>&1 | grep "^#[0-2] " | sed 's/ ()//; s/0x[0-9a-f]* in //' | tr '\n' ' '`
  echo "$n :: $r"
done
