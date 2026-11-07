#!/bin/sh
# ws_relaunch_ku.sh IMG SHA (runs ON the G5 over ssh, after the kext swap + unstick): kill the live WindowServer and immediately relaunch it by hand with the rebuilt userspace
# environment, so the rebuilt GA plug-in (2D), GLDriver (Quartz Extreme / compositing GL) and, if it loads there, the VADriver are the ones WindowServer maps (Phase 4 KU side).
# Technique and why no plist edit: Tests/windowserver_capture_notes.md ("manual kill + immediate manual relaunch"). The wrapper lives on the BOOT volume (/Users/Shared), the images under ~/rung3.
# Proof (rule 0): the redirect log lists every NSCreateObjectFileImageFromFile WindowServer did ("redirected to" = a rebuilt image mapped, "passthrough" = stock). Output log: /Users/Shared/ws_ku_redirect.log (copy it into the evidence dir).
IMG=${1:?img}; SHA=${2:?sha}; R=$HOME/rung3; U=$R/us_$IMG
LOG=/Users/Shared/ws_ku_redirect.log; W=/Users/Shared/ws_ku_wrapper.sh
cat > $W <<EOW
#!/bin/sh
export DYLD_INSERT_LIBRARIES=$R/src_$SHA/Tools/userspace/gld_redirect.dylib
export GLD_REDIRECT_MAP=ATIRadeonX1000GLDriver=$R/gld_$IMG/gld_link/ATIRadeonX1000GLDriver_renamed,ATIRadeonX1000GA=$U/ga/ATIRadeonX1000GA,ATIRadeonX1000VADriver=$U/va/ATIRadeonX1000VADriver
export GLD_REDIRECT_LOG=$LOG
export DYLD_LIBRARY_PATH=$R/final_eval/dyld_dir_$IMG
exec /System/Library/Frameworks/ApplicationServices.framework/Frameworks/CoreGraphics.framework/Resources/WindowServer "\$@"
EOW
chmod 755 $W; rm -f $LOG; touch $LOG; chmod 666 $LOG
WSPID=`ps auxww | awk '/[W]indowServer -daemon/{print $2}'`; [ -n "$WSPID" ] || { echo "ws_relaunch_ku: WindowServer not found"; exit 1; }
OLDGUI=`ps -U "$(id -un)" -o pid,command | awk '/CoreServices\/pbs$/ || /Dock\.app\/Contents\/MacOS\/Dock/ {print $1}'`
echo "ws_relaunch_ku: killing WindowServer $WSPID and relaunching through $W"
sudo kill $WSPID
nohup $W -daemon > /Users/Shared/ws_ku_manual.log 2>&1 < /dev/null & disown -a
sleep 6
[ -z "$OLDGUI" ] || { kill $OLDGUI 2>/dev/null; sleep 1; kill -9 $OLDGUI 2>/dev/null; }
ps auxww | grep "[W]indowServer"
echo "ws_relaunch_ku: redirect log:"; cat $LOG
