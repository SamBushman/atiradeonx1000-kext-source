#!/bin/sh
# runInst.sh TAG : GL feature suite on the INSTALLED driver (no gld_redirect), compared with the stock outputs in final_eval/nov1/gl_stock
T=$HOME/rung3/final_eval/nov2/gls_inst_$1
unset GLD_REDIRECT_FROM GLD_REDIRECT_TO DYLD_INSERT_LIBRARIES
rm -rf $T $T.cmp $T.done
cd $HOME/rung3/src_575ad528/Tests && sh run_gl_feature_suite.sh $T 120 > $T.log 2>&1
for f in $T/*.out; do b=`basename $f`; grep -v "^gld_redirect" $f > $HOME/rung3/final_eval/nov2/oo.a; grep -v "^gld_redirect" $HOME/rung3/final_eval/nov1/gl_stock/$b > $HOME/rung3/final_eval/nov2/oo.b; if [ ! -s $HOME/rung3/final_eval/nov2/oo.a ]; then echo EMPTY $b; elif ! cmp -s $HOME/rung3/final_eval/nov2/oo.a $HOME/rung3/final_eval/nov2/oo.b; then echo DIFF $b; fi; done > $T.cmp
echo done > $T.done
