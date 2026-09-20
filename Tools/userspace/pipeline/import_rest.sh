#!/bin/sh
cd ~/Documents/ATI-X1900-Decomp/ghidra-projects
for f in ATIRadeonX1000GA.plugin.bin.ppc ATIRadeonX1000GA.plugin.bin.i386 ATIRadeonX1000VADriver.bundle.bin.ppc ATIRadeonX1000VADriver.bundle.bin.i386 ATIRadeonX1000GLDriver.bundle.bin.i386; do
  ~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless $PWD/rest-proj RestProject -import /tmp/spec/slices/$f -overwrite > /tmp/spec/import_$f.log 2>&1
  echo "done $f" >> /tmp/spec/import_rest.done
done
