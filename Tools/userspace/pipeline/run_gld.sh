cd ~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source
SP=/tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad
python3 Tools/userspace/ghidra2c.py $SP/all_gld /tmp/spec/gld_c 60 0-1a3624 1cd664-1d8fe4 || exit 1
cp Tools/userspace/ghidra_c.h /tmp/spec/gld_c/
tar czf /tmp/spec/gld_c.tgz -C /tmp/spec gld_c; scp -q /tmp/spec/gld_c.tgz G5:/tmp/gld_c.tgz
ssh G5 'rm -rf /tmp/gld_c; cd /tmp && tar xzf gld_c.tgz && sh /tmp/compile_c.sh 2>&1 | tail -14'
rm -rf /tmp/spec/gld_err; mkdir /tmp/spec/gld_err; scp -q G5:/tmp/gld_c/part_*.err /tmp/spec/gld_err/
