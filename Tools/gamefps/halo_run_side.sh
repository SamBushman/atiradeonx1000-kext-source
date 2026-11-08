#!/bin/sh
# halo_run_side.sh - ONE Halo (Mac 1.0.9) built-in timedemo run on the Tiger G5, driven entirely over ssh (no person at the console).
#   sh halo_run_side.sh LABEL WIDTHxHEIGHT PRESET [REPEATS=1]       run ON the G5 (from ~/rung3/gamefps), PRESET = high | low | keep
# What it does: patches the player profile (resolution + the 8 quality bytes at 0xa6e) and the prefs plist (GameDisplay + "Graphics Options": hardware
# shaders / FSAA / lens flare / model detail / detail objects), launches Halo in the Aqua session (`open -a Terminal`), drives the launcher dialog with
# Tools/gui_input (click the title bar to activate it, tick "Run Time Demo", press OK), waits for ~/Documents/Halo/Timedemo.txt (a deterministic
# 4700-frame demo: Frames, Total Time, average fps, "Below N fps" histogram, and the video options it actually ran with), saves it as
# OUT/LABEL_runK.txt together with a mid-run screenshot and the stdout of Halo.
# Presets (the 8 profile bytes are specular, shadows, decals, particles, texture quality, ... : decoded by experiment, see OUT/decode_*):
#   high = PS+VS shaders, lens flare high, model detail high, detail objects on, every quality byte at its maximum
#   low  = shaders off (fixed function), lens flare off, model detail low, detail objects off, every quality byte 0
# FSAA stays Off in both: the point is the driver's fixed rendering path, and multisample is a separate feature test.
# Clicks use the dialog position seen on the 1920x1080 console: title bar (960,112), Run Time Demo (771,447), OK (1133,653).
L=${1:?label}; RES=${2:?WxH}; P=${3:?high|low|keep}; N=${4:-1}
W=${RES%x*}; H=${RES#*x}
OUT=$HOME/rung3/gamefps/halo/$L; mkdir -p "$OUT"
PROF=$HOME/Documents/Halo/ppc/savegames/Sam       # the profile Halo reads (lastprof.txt): blam.sav; saved/player_profiles/default_profile is NOT used
PL=com.macsoft.halo
GI=${GI:-$HOME/rung3/src_575ad528/Tools/gui_input}
ORIG=$HOME/rung3/gamefps/halo/orig; mkdir -p $ORIG
[ -f $ORIG/blam.sav ] || { cp $PROF/blam.sav $ORIG/; defaults read $PL > $ORIG/plist.txt; cp $HOME/Library/Preferences/$PL.plist $ORIG/; }

hex4() { printf '%08x' $1; }
patch_bytes() {    # patch_bytes OFFSET "octal escapes"  in both profile files
    for f in blam.sav; do printf "$2" | dd of=$PROF/$f bs=1 seek=$1 conv=notrunc 2>/dev/null; done
}
oct2() { printf '\\%03o\\%03o' $(($1 / 256)) $(($1 % 256)); }
# resolution: profile 0xa68 = width(2) height(2), plist GameDisplay word 2 = same pair
patch_bytes $((0xa68)) "$(oct2 $W)$(oct2 $H)"
# words: 00000000 0b4390d8 WWWWHHHH 00200000 003c0000 80000000 80000000 00000001
NEWGD="00000000 0b4390d8 $(hex4 $((W * 65536 + H))) 00200000 003c0000 80000000 80000000 00000001"
defaults write $PL GameDisplay -data "`echo $NEWGD | tr -d ' '`"
case $P in
 high) Q='\002\002\002\002\002\002\002\002'; GO="00000002 00000000 00000002 00000002 00000001 00000000 00000001 00000000 32333032 00000000 32333033 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001";;
 low)  Q='\000\000\000\000\000\000\000\000'; GO="00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 32333032 00000000 32333033 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001";;
 keep) Q=; GO=;;
esac
[ -n "$Q" ] && patch_bytes $((0xa6e)) "$Q"
[ -n "$GO" ] && defaults write $PL "Graphics Options" -data "`echo $GO | tr -d ' '`"

k=1
while [ $k -le $N ]; do
    for p in `ps auxww | grep "[.]/Halo" | awk '{print $2}'`; do kill $p; done; sleep 3
    rm -f $HOME/Documents/Halo/Timedemo.txt
    # `open -a Halo.app` fails from an ssh session (CFMessagePort bootstrap): run ./Halo from a Terminal .command, which lives in the Aqua session
    # HALO_ENV=name sources ~/rung3/ut_env_<name> (GLD_REDIRECT_* + DYLD_INSERT_LIBRARIES: run the renamed GLDriver image through gld_redirect.dylib without installing it)
    ENVLINE=; [ -n "$HALO_ENV" ] && ENVLINE=". $HOME/rung3/ut_env_$HALO_ENV"
    printf '#!/bin/sh\ncd /Applications/Halo.app/Contents/MacOS\n%s\n./Halo > %s/stdout_run%s.txt 2>&1\nexit\n' "$ENVLINE" "$OUT" "$k" > $OUT/run.command; chmod +x $OUT/run.command
    open -a Terminal $OUT/run.command
    i=0; while [ $i -lt 40 ] && ! ps auxww | grep -q "[.]/Halo"; do sleep 1; i=`expr $i + 1`; done
    sleep 10
    # the first click after the dialog appears only activates it; click the "Run Time Demo" box until its pixels turn blue (pngpix.py reads the screenshot; checked = r < 150)
    $GI click 960 112; sleep 2; t=0
    while [ $t -lt 4 ]; do
        $GI click 771 447; sleep 2; screencapture -x $OUT/dialog_run$k.png
        r=`/usr/local/bin/python3 $HOME/rung3/gamefps/pngpix.py $OUT/dialog_run$k.png 766 442 10 10 | sed 's/.*(\([0-9]*\),.*/\1/'`
        [ "$r" -lt 150 ] 2>/dev/null && break; t=`expr $t + 1`
    done
    echo "$L run$k: Run Time Demo box r=$r after `expr $t + 1` click(s)"
    $GI click 1133 653
    sleep 30; screencapture -x $OUT/mid_run$k.png
    i=0; while [ ! -f $HOME/Documents/Halo/Timedemo.txt ] && [ $i -lt 600 ]; do sleep 2; i=`expr $i + 2`; done
    sleep 3
    if [ -f $HOME/Documents/Halo/Timedemo.txt ]; then cp $HOME/Documents/Halo/Timedemo.txt $OUT/${L}_run$k.txt; echo "$L run$k: `grep 'Average frame rate' $OUT/${L}_run$k.txt`"; else echo "$L run$k: NO Timedemo.txt after ${i}s"; fi
    for p in `ps auxww | grep "[.]/Halo" | awk '{print $2}'`; do kill $p; done; sleep 3
    k=`expr $k + 1`
done
