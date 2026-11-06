#!/bin/sh
# usage: d3check.sh TAG  -> prints NORMAL | WEDGED | wait
D=$HOME/gamefps/doom3/$1
L=$D/gllog.txt
if test -f $D/summary.txt; then echo NORMAL; exit 0; fi
if grep -q 'DRAWE 4 2388' $L 2>/dev/null && ps -axo state,command | grep '[d]hewm3' | grep -q '^[UE]'; then
  a=`wc -l < $L`; sleep 20; b=`wc -l < $L`
  if test -f $D/summary.txt; then echo NORMAL
  elif test "$a" = "$b"; then echo WEDGED
  else echo wait; fi
else echo wait; fi
