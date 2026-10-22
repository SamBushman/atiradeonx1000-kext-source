#!/bin/sh
# emit.sh FUNCTION SPEC  -> rows on stdout, webs computed on the pristine (main) text so numbering is stable
cd ~/wt/D6 && python3 Tools/userspace/find_webs.py /tmp/d6pristine/ppc "$1" --emit "$2"
