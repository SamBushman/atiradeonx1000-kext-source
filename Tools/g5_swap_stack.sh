#!/bin/sh
# /Library/ATIRadeonX1000-Rebuilt/swap.sh rebuilt|stock   (run as: sudo sh swap.sh MODE)
# Puts the REBUILT or the STOCK X1900 stack into the system paths of this (Tiger HD) volume, from the copies kept next to this script:
#   rebuilt/  = our ATIRadeonX1000 kext binary + GLDriver + GA plug-in + VADriver + libGL + libGLProgrammability (md5.txt inside)
#   stock/    = Apple's originals as found on 2026-11-08 (md5.txt inside) + the stock Extensions.mkext / Extensions.kextcache / kernelcache
# Every file is copied to a temp name in its own directory, given root:wheel and its mode, md5-checked against the md5.txt, then moved over the target (atomic: a running process keeps its old inode).
# Then /System/Library/Extensions is touched so that the prelinked kernelcache is out of date and kextd loads the installed kext at the next boot.  REBOOT afterwards.
# DRY=1 (sudo env DRY=1 sh swap.sh MODE) copies and md5-checks every file to a temp name and removes it again, replacing nothing.
# Nothing here depends on Test HD.  If the GUI does not come up after a reboot, ssh in and run:  sudo sh /Library/ATIRadeonX1000-Rebuilt/swap.sh stock ; sudo reboot
MODE=${1:?rebuilt|stock}; B=`dirname $0`; case $MODE in rebuilt|stock) ;; *) echo "bad mode"; exit 2;; esac
S=/System/Library/Extensions; F=/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries
put() { # NAME-IN-DIR TARGET MODE
  src=$B/$MODE/$1; dst=$2; mode=$3; tmp=$dst.swap.$$
  want=`awk -v n="($1)" '$2==n {print $4}' $B/$MODE/md5.txt`
  cp $src $tmp && chown root:wheel $tmp && chmod $mode $tmp || { echo "FAIL copy $1"; rm -f $tmp; return 1; }
  got=`md5 -q $tmp 2>/dev/null || md5 $tmp | awk '{print $NF}'`
  [ "$got" = "$want" ] || { echo "FAIL md5 $1 got $got want $want"; rm -f $tmp; return 1; }
  if [ "$DRY" = 1 ]; then rm -f $tmp; echo "dry ok $1 (md5 $got) would go to $dst"; return 0; fi
  mv $tmp $dst && echo "ok $1 -> $dst"
}
put kext_ATIRadeonX1000 $S/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000 644 || exit 1
put gld_ATIRadeonX1000GLDriver $S/ATIRadeonX1000GLDriver.bundle/Contents/MacOS/ATIRadeonX1000GLDriver 755 || exit 1
put ga_ATIRadeonX1000GA $S/ATIRadeonX1000GA.plugin/Contents/MacOS/ATIRadeonX1000GA 755 || exit 1
put va_ATIRadeonX1000VADriver $S/ATIRadeonX1000VADriver.bundle/Contents/MacOS/ATIRadeonX1000VADriver 755 || exit 1
put libGLProgrammability.dylib $F/libGLProgrammability.dylib 755 || exit 1
put libGL.dylib $F/libGL.dylib 755 || exit 1
if [ $MODE = stock ]; then
  put Extensions.mkext /System/Library/Extensions.mkext 644 || exit 1
  put Extensions.kextcache /System/Library/Extensions.kextcache 644 || exit 1
  put kernelcache.86C01707 /System/Library/Caches/com.apple.kernelcaches/kernelcache.86C01707 644 || exit 1
fi
[ "$DRY" = 1 ] && { echo "dry run: nothing replaced"; exit 0; }
touch $S && echo "touched $S; now reboot (sudo reboot)"
