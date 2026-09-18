#!/bin/sh
# link_check.sh - prove the built kext links against the running kernel and its
# dependency kexts, WITHOUT loading anything into the kernel.
#
# Uses `kextload -n -s`: -n = neither load nor start, -s = write symbol files,
# which makes kextload run the real kernel-extension linker (kld) over the kext in
# user space. A missing symbol, or a branch that can't reach its target
# ("relocation overflow"), is reported exactly as it would be at load time.
#
# Run ON the Tiger machine after `sh Tools/build_kext.sh` with a NON-default KEXT_ID,
# so the dry-run copy can never collide with the installed com.apple.ATIRadeonX1000:
#     KEXT_ID=com.example.ATIRadeonX1000.linktest sh Tools/build_kext.sh
#     sh Tools/link_check.sh com.example.ATIRadeonX1000.linktest
#
# The dependency load addresses below are the ones `kextstat` reports on the G5
# (IOPCIFamily/IOGraphicsFamily/IONDRVSupport); adjust if yours differ. The kext's
# own address must be near the real kexts' range (~0x5xxxxx-0x6xxxxx): a far-away
# address (e.g. 0x2000000) makes 24-bit `bl` branches to kernel code overflow.
set -e
ID=${1:?usage: link_check.sh <KEXT_ID used for the build>}
case "$ID" in com.apple.*) echo "refusing to use an Apple bundle id ($ID)"; exit 2;; esac
OUT=${OUT:-/tmp/kext_build}
T=/tmp/kext_linkcheck
sudo rm -rf "$T"; sudo mkdir "$T"
sudo cp -R "$OUT/ATIRadeonX1000.kext" "$T/"
sudo chown -R root:wheel "$T"
rm -rf "$T.syms"; mkdir "$T.syms"
kextload -n \
    -a $ID@0x600000 \
    -a com.apple.iokit.IOPCIFamily@0x4ec000 \
    -a com.apple.iokit.IOGraphicsFamily@0x54e000 \
    -a com.apple.iokit.IONDRVSupport@0x572000 \
    -s "$T.syms" -v 3 "$T/ATIRadeonX1000.kext" 2>&1 | grep -v "clear relationships\|added cached\|repository" | tail -15
if kextstat | grep -q "$ID"; then echo "UNEXPECTED: kext is loaded"; exit 1; fi
ls "$T.syms/$ID.sym" >/dev/null && echo "LINK OK: $ID linked against kernel + dependencies (not loaded)"
