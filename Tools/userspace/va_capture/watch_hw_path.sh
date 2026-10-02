#!/bin/sh
# watch_hw_path.sh [SECONDS] [OUTFILE] - run ON THE G5 (read-only) while a player plays a stream: once per second records how many ATIR500DVDContext / ATIR500GLContext / ATIR5002DContext /
# ATIR500Surface user clients exist and the ATI kext lines of kextstat. A DVD context that appears only during playback means the player is using this driver's hardware (VA/IDCT) path;
# no DVD context at all means it decodes in software and this capture approach cannot observe doIDCT. Uses only ioreg and kextstat.
N=${1:-120}; OUT=${2:-/tmp/va_cap/hw_watch.log}; mkdir -p "`dirname "$OUT"`"; : > "$OUT"
echo "# watch_hw_path start `date`" >> "$OUT"
i=0; MAXDVD=0
while [ $i -lt $N ]; do
    R=`/usr/sbin/ioreg -l -w0 2>/dev/null`
    D=`echo "$R" | grep -c "<class ATIR500DVDContext"`; G=`echo "$R" | grep -c "<class ATIR500GLContext"`
    T=`echo "$R" | grep -c "<class ATIR5002DContext"`; S=`echo "$R" | grep -c "<class ATIR500Surface"`
    echo "t=$i dvd=$D gl=$G 2d=$T surface=$S" >> "$OUT"
    [ "$D" -gt "$MAXDVD" ] && MAXDVD=$D
    i=$((i+1)); sleep 1
done
kextstat | grep -i ati >> "$OUT"
echo "# max DVD contexts seen: $MAXDVD  (0 = the hardware IDCT path was NOT used)" >> "$OUT"
tail -2 "$OUT"
