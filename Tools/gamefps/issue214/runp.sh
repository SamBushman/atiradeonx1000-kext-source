#!/bin/sh
# usage: runp.sh TAG  (env exports in ~/rung3/runp_env_$TAG)  -> ~/g5logs/probe214d/$TAG.txt, recorder tsv ~/g5logs/probe214d/$TAG.tsv
TAG=$1
cd $HOME/rung3
. $HOME/rung3/runp_env_$TAG
O=$HOME/g5logs/probe214d
export IOKIT_RECORD_LOG=$O/$TAG.tsv IOKIT_RECORD_CB_BYTES=0x20000 DYLD_INSERT_LIBRARIES=$HOME/rung3/iokit_record.dylib
rm -f $O/$TAG.*
./gl_doom_replay_probe > $O/$TAG.txt 2>&1 < /dev/null &
pid=$!; i=0
while kill -0 $pid 2>/dev/null && [ $i -lt 120 ]; do sleep 1; i=`expr $i + 1`; done
kill $pid 2>/dev/null; sleep 2; kill -9 $pid 2>/dev/null
echo "DONE ran ${i}s" >> $O/$TAG.txt
