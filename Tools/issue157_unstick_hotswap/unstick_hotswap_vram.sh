#!/bin/sh
# Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh - issue #157. Run ON the Tiger G5, AFTER a
# hot-swap (kextunload/kextload of ATIRadeonX1000) and BEFORE any T3 test that uses t3_surface(), to
# give the hot-swapped instance's VRAM pool real capacity - without this, Surface::set_shape and
# everything built on t3_surface() fails with NoResources (see issue #157 for the full root-cause
# trace). Confirmed working end to end: t3_2d_lock_unlock PASSes afterward, matching the original
# boot-time Phase S baseline exactly.
#
# Needs physical/console access consideration: this briefly, visibly changes the real screen
# resolution (switches away and back automatically, ~4 seconds total) and restarts WindowServer
# (every GUI app's windows redraw; no data loss, but visible). Run only with the same authorization
# as any other hot-swap/live-kext-testing step in this project.
#
# Usage: sh Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh
set -e
D=$(cd "$(dirname "$0")" && pwd)

echo "unstick_hotswap_vram: finding WindowServer..."
WSPID=$(ps auxww | awk '/[W]indowServer -daemon/{print $2}')
[ -n "$WSPID" ] || { echo "unstick_hotswap_vram: WindowServer not found"; exit 1; }
echo "unstick_hotswap_vram: killing WindowServer (pid $WSPID) so it restarts fresh against the hot-swapped instance"
sudo kill -9 "$WSPID"
sleep 3
NEWPID=$(ps auxww | awk '/[W]indowServer -daemon/{print $2}')
[ -n "$NEWPID" ] || { echo "unstick_hotswap_vram: WindowServer did not respawn"; exit 1; }
echo "unstick_hotswap_vram: WindowServer respawned as pid $NEWPID"

echo "unstick_hotswap_vram: running request_probe (framebuffer discovery)..."
if [ ! -x /tmp/request_probe ]; then
    REPO=$(cd "$D/../.." && pwd)
    gcc -arch ppc -o /tmp/request_probe "$REPO/Tools/request_probe.c" -framework IOKit -framework CoreFoundation
fi
/tmp/request_probe

echo "unstick_hotswap_vram: building force_mode_change..."
gcc -std=c99 -Wall -o /tmp/force_mode_change "$D/force_mode_change.c" -framework ApplicationServices

echo "unstick_hotswap_vram: forcing a real mode-set (switches away and back automatically)..."
/tmp/force_mode_change

echo "unstick_hotswap_vram: done - VRAM pool should now be populated (verify with Tools/issue157_probe if needed)"
