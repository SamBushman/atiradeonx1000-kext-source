#!/bin/sh
# side_launch.command (runs on the G5 inside the Aqua session via `open -a Terminal`): launch ONE application with the side environment of the Phase 4 run ($HOME/rung3/side_env; on the KU side it exports the rebuilt-userspace
# variables and sets SIDE_INSERT = gld_redirect.dylib, on the other sides it is empty and the app is started with `open -a` as usual). The app name comes from $HOME/rung3/side_launch_app (a .command cannot take arguments).
# Proof of the loaded images: $HOME/rung3/side_launch_redirect.log (the "redirected to" lines) and side_launch_dyld.txt (DYLD_PRINT_LIBRARIES: libGL / libGLProgrammability paths).
read APPNAME < $HOME/rung3/side_launch_app
APP="/Applications/$APPNAME.app"
[ -f $HOME/rung3/side_env ] && . $HOME/rung3/side_env
EXE=`defaults read "$APP/Contents/Info" CFBundleExecutable 2>/dev/null`
rm -f $HOME/rung3/side_launch_redirect.log $HOME/rung3/side_launch_dyld.txt
if [ -n "$SIDE_INSERT" ] && [ -n "$EXE" ]; then
  ( cd /; GLD_REDIRECT_LOG=$HOME/rung3/side_launch_redirect.log DYLD_INSERT_LIBRARIES="$SIDE_INSERT" DYLD_PRINT_LIBRARIES=1 "$APP/Contents/MacOS/$EXE" > $HOME/rung3/side_launch_app.out 2> $HOME/rung3/side_launch_dyld.txt < /dev/null & )
else
  open -a "$APPNAME"
fi
echo launched > $HOME/rung3/side_launch_done
