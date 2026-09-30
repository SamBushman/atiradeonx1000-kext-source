#!/bin/bash
# probe.sh NAME [N]: run cgl_probe N times against the rebuilt out_NAME
ssh G5 "cd '/Volumes/Test HD/claude_bugwf/h79'; export DYLD_INSERT_LIBRARIES='/Volumes/Test HD/claude_bugwf/h79/gld_redirect.dylib' GLD_REDIRECT_FROM=/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle GLD_REDIRECT_TO='/Volumes/Test HD/claude_bugwf/gld_$1/out_$1'; for i in \1 2 3; do ./cgl_probe 2>&1 | grep -v gld_redirect | tail -5; echo rc=\${PIPESTATUS[0]}; done"
