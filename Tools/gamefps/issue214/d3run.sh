#!/bin/sh
# usage: d3run.sh TAG "ENVLINE..."   -> launches Doom keep-only run with extra env, waits for wedge or normal exit, prints verdict
TAG=$1; shift
EXTRA="$*"
ssh G5 "cd ~/gamefps && sed \"s/^d3t[0-9]* /$TAG /\" d3_tag > d3_tag.n && mv d3_tag.n d3_tag && grep -v D3GL_ d3_trace_env > d3_trace_env.n && mv d3_trace_env.n d3_trace_env && for kv in $EXTRA; do echo \"export \$kv\" >> d3_trace_env; done; tail -3 d3_trace_env; open -a Terminal ~/gamefps/doom3_trace.command"
sleep 8
i=0
while [ $i -lt 90 ]; do
  r=`ssh -o ConnectTimeout=5 G5 "sh ~/gamefps/d3check.sh $TAG" 2>/dev/null`
  case "$r" in NORMAL|WEDGED) echo "$TAG $EXTRA => $r"; exit 0;; esac
  sleep 5; i=`expr $i + 1`
done
echo "$TAG $EXTRA => TIMEOUT"
