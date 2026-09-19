#!/bin/sh
# remote_build.sh - copy the tree to the Tiger box, build the kext there, and print only failures + the link summary.
# Usage: sh Tools/remote_build.sh [ssh-host]   (default G5).  Builds into /tmp/kbN on the remote and prints the dir.
H=${1:-G5}
T=$(mktemp -d)
tar czf "$T/src.tgz" Headers Sources Tools Resources
scp -q "$T/src.tgz" $H:/tmp/rb_src.tgz
ssh $H 'rm -rf /tmp/rb_cur; mkdir /tmp/rb_cur && cd /tmp/rb_cur && tar xzf /tmp/rb_src.tgz && OPT="'"$OPT"'" OUT=/tmp/rb_cur/out KEXT_ID=com.example.ATIRadeonX1000.linktest sh Tools/build_kext.sh 2>&1 | grep -v "^bundle\|^objects" | head -'${LINES_MAX:-60}
rm -rf "$T"
