#!/bin/sh
# Tests/destructive/peer_ack.sh SSH_HOST [REMOTE_DIR]  - run from a SECOND machine (the dev machine), issue #87 criteria 2+3.
# 1. checks this machine's git working tree is clean and pushed (nothing unpushed that a G5 crash could not lose anyway, but nothing lost either);
# 2. touches REMOTE_DIR/results/peer_ack on the G5 over ssh (proves a second ssh session is open and answering);
# 3. then prints the command that mirrors the write-ahead log here: run  nc -ul PORT  on this machine and pass --mirror THIS_HOST:PORT to the test.
H=${1:?usage: peer_ack.sh SSH_HOST [REMOTE_DIR]}
D=${2:-/tmp/rb_cur/Tests/destructive}
[ -z "`git status --porcelain`" ] || { echo "dev tree not clean - commit first"; exit 1; }
git fetch -q 2>/dev/null; [ -z "`git log @{u}.. 2>/dev/null`" ] || { echo "unpushed commits on the dev machine - push first"; exit 1; }
ssh $H "mkdir -p '$D/results' && touch '$D/results/peer_ack' && echo peer ack written on \`hostname\`" || { echo "ssh to $H failed"; exit 1; }
echo "now run in a separate terminal here:  nc -ul 9999"
echo "and start the test with:  --mirror `hostname`:9999"
