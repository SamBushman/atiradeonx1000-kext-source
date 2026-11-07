#!/bin/sh
# ku_env.sh on|off IMG SHA (runs ON the G5 over ssh): give the rebuilt userspace to every process launchd starts from now on - in particular WindowServer, which loads the GA plug-in (2D) and the GLDriver (compositing GL) -
# by setting the environment in the ROOT launchd context (`sudo launchctl setenv`, Tiger launchctl): DYLD_INSERT_LIBRARIES=gld_redirect.dylib, GLD_REDIRECT_MAP (GLDriver, GA, VADriver) and DYLD_LIBRARY_PATH (rebuilt libGL + libGLProgrammability).
# Then restart WindowServer (the unstick step of the hot-swap does; or RESTART_WS=1 here) so it is respawned with it. `off` unsets all four (a reboot also clears them).
# A by-hand relaunch of WindowServer (Tests/windowserver_capture_notes.md) lost the race against launchd's own respawn on Nov 7 and left the STOCK WindowServer running while the log of the short-lived manual instance looked like success: the environment route is deterministic.
# env: NOLOG=1 = do not set GLD_REDIRECT_LOG (the log file shifts the heap and slows timed runs, #232); otherwise every process appends its redirect lines to /Users/Shared/ws_ku_redirect.log = the loaded-image proof (copy it into the evidence).
# The environment reaches ALL later processes of the session (loginwindow, Dock, Finder, ssh shells): this is the KU arm for the whole machine; use it only on a boot that is rebooted afterwards.
MODE=${1:?on|off}; IMG=${2:-}; SHA=${3:-}; R=$HOME/rung3; LOG=/Users/Shared/ws_ku_redirect.log
case $MODE in
off) for v in DYLD_INSERT_LIBRARIES GLD_REDIRECT_MAP GLD_REDIRECT_LOG DYLD_LIBRARY_PATH; do sudo launchctl unsetenv $v; done; echo "ku_env: off";;
on)
  [ -n "$IMG" ] && [ -n "$SHA" ] || { echo "usage: ku_env.sh on IMG SHA"; exit 2; }
  sudo launchctl setenv DYLD_INSERT_LIBRARIES $R/src_$SHA/Tools/userspace/gld_redirect.dylib
  sudo launchctl setenv GLD_REDIRECT_MAP ATIRadeonX1000GLDriver=$R/gld_$IMG/gld_link/ATIRadeonX1000GLDriver_renamed,ATIRadeonX1000GA=$R/us_$IMG/ga/ATIRadeonX1000GA,ATIRadeonX1000VADriver=$R/us_$IMG/va/ATIRadeonX1000VADriver
  sudo launchctl setenv DYLD_LIBRARY_PATH $R/final_eval/dyld_dir_$IMG
  if [ "$NOLOG" = 1 ]; then sudo launchctl unsetenv GLD_REDIRECT_LOG; else rm -f $LOG 2>/dev/null; sudo sh -c "rm -f $LOG; touch $LOG; chmod 666 $LOG"; sudo launchctl setenv GLD_REDIRECT_LOG $LOG; fi
  echo "ku_env: on (img $IMG, sha $SHA, NOLOG=${NOLOG:-0})"; sudo launchctl getenv DYLD_INSERT_LIBRARIES
  if [ "$RESTART_WS" = 1 ]; then P=`ps auxww | awk '/[W]indowServer -daemon/{print $2}'`; sudo kill $P; sleep 12; ps auxww | grep "[W]indowServer"; fi;;
*) echo "bad mode"; exit 2;;
esac
