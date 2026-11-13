# nf.sh SPEC LEDGER NAME TRIAL  -- rebuilt image 4966, no repair: where does the first fault happen
cd ~/rung3/fnf_237
export FNFUZZ_PRECALL=${PRECALL:-} FNFUZZ_GRAPHSPEC=$1 FNFUZZ_DATA=vt_4966.tsv FNFUZZ_STACKFILL=0 FNFUZZ_NANCANON=1 FNFUZZ_FLOATARGS=0 FNFUZZ_INTERPOSE=1 FNFUZZ_IMPORT_NARGS=gld_nargs.tsv FNFUZZ_VT=1 FNFUZZ_PROFILE=graph FNFUZZ_ONE=R:$4
printf "run\nbt 8\nx/9i \$pc-24\ninfo registers r2 r3 r4 r5 r9 r11 r12 r28 r29 r30 r31\nquit\n" | gdb --args ../gleng_fz/fnfuzz_gs55 $2 /Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver $HOME/rung3/gld_49663019/gld_link/ATIRadeonX1000GLDriver_renamed 20 $3 2>&1 | grep -v "^warning\|^Reading\|^Could not\|^\.\.\.\|^$\|^GNU\|^Copyright\|^welcome\|^Type\|^There is\|^This GDB\|^interposer\|^gdb\|^Re-enabling" | tail -${TAILN:-30}
