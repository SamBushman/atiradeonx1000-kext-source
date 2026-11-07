#!/bin/sh
# phase4_dvd_bisect.sh OUTROOT (dev machine): which rebuilt userspace component turns the DVD Player picture black.
# Context: final-eval Phase 4, KU (rebuilt kext + all rebuilt userspace) showed a BLACK video window with dvd=1 contexts and a running counter,
# while S direct-launched (stock kext hot-swapped, no rebuilt env) showed the picture in the same small top-left window -> not a launch-shape artifact.
# Each variant = fresh boot, stock kext hot-swapped over the boot-time one + unstick (control S), DVD Player DIRECT-launched (side_launch.command)
# with the environment of exactly ONE rebuilt component, then dvd_disc_compare.sh (screenshots + hw watch counts).
#   VA = rebuilt ATIRadeonX1000VADriver only          GA = rebuilt ATIRadeonX1000GA only (process-level)
#   VAREC = rebuilt VADriver + the passive IOKit recorder (iokit_record_va.dylib: every IOConnectMapMemory with its returned address, MIG selectors) -> proof/rec.tsv;  STOCKREC = the same recorder with NO rebuilt component (control)
#   VAWATCH = rebuilt VADriver + va_ctx_watch.dylib (polls the VA context's +0x14 connect handle and reports pc/lr/back-chain of every thread when it changes) -> proof/ctxwatch.txt
#   GL = rebuilt GLDriver + libGL + libGLProgrammability (GLD_REDIRECT_MAP + DYLD_LIBRARY_PATH)
# env: SHA IMG (G5 tree src_<SHA>, images us_<IMG>/gld_<IMG>), STOCK_DIR (default stockkext), VARIANTS (default "VA GL GA"), SECS_DVD (60).
# Evidence: OUTROOT/<variant>/{proof,dvd}; proof/side_launch_redirect.log + side_launch_dyld.txt prove which images the DVD Player really mapped.
O=${1:?outroot}; SHA=${SHA:?SHA}; IMG=${IMG:-$SHA}; SECS_DVD=${SECS_DVD:-60}; T=$(cd "$(dirname "$0")" && pwd); mkdir -p "$O"
. "$T/reboot_wait.sh"
R=\$HOME/rung3
for v in ${VARIANTS:-VA GL GA}; do
  D="$O/$v"; mkdir -p "$D/proof"
  reboot_wait; echo "$v: booted $(date)" >> "$O/sides.log"
  scp -q "$T/app_sweep.command" "$T/side_launch.command" G5:rung3/
  scp -q "$T"/userspace/va_capture/play_with_recorder_*.command "$T/userspace/va_capture/auto_play.command" G5:rung3/va_cap/
  ssh G5 "chmod +x $R/side_launch.command; : > $R/side_env; rm -f $R/side_launch_app $R/side_launch_done; kextstat | grep ATIRadeonX1000" > "$D/proof/boot_kext.txt" 2>&1
  timeout 100 ssh G5 "sh $R/swap.sh ${STOCK_DIR:-stockkext} 2>&1 | tail -1; sh $R/src_$SHA/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock; kextstat | grep ATIRadeonX1000" > "$D/proof/swap.txt" 2>&1 || { echo "$v: swap FAILED $(date)" >> "$O/sides.log"; exit 1; }
  sleep 30
  GLDM=ATIRadeonX1000GLDriver=\$HOME/rung3/gld_$IMG/gld_link/ATIRadeonX1000GLDriver_renamed
  GAM=ATIRadeonX1000GA=\$HOME/rung3/us_$IMG/ga/ATIRadeonX1000GA
  VAM=ATIRadeonX1000VADriver=\$HOME/rung3/us_$IMG/va/ATIRadeonX1000VADriver
  case $v in
    VA) MAP=$VAM; DLP="";;
    GA) MAP=$GAM; DLP="";;
    VAREC|VAWATCH) MAP=$VAM; DLP="";;
    STOCKREC) MAP=""; DLP="";;
    GL) MAP=$GLDM; DLP="export DYLD_LIBRARY_PATH=\$HOME/rung3/final_eval/dyld_dir_$IMG";;
    *) echo "bad variant $v"; exit 2;;
  esac
  REC=""; case $v in *REC) REC="\$HOME/rung3/va_cap/iokit_record_va.dylib:";; VAWATCH) REC="\$HOME/rung3/va_cap/va_ctx_watch.dylib:";; esac
  { [ -n "$MAP" ] && echo "export GLD_REDIRECT_MAP=$MAP"; [ -n "$DLP" ] && echo "$DLP"; case $v in *REC) echo "export IOKIT_RECORD_LOG=\$HOME/rung3/va_cap/rec_$v.tsv VA_DUMP_MAX=0";; VAWATCH) echo "export VA_WATCH_LOG=\$HOME/rung3/va_cap/ctxwatch.txt VA_WATCH_MAX=300";; esac; echo "SIDE_INSERT=${REC}\$HOME/rung3/src_$SHA/Tools/userspace/gld_redirect.dylib"; } > "$D/proof/side_env.local"
  scp -q "$D/proof/side_env.local" G5:rung3/side_env
  CLICK_X=125 CLICK_Y2=148 CLICK_XB=759 SEQ=boot SIDE_LAUNCH=1 sh "$T/dvd_disc_compare.sh" "$D/dvd" $SECS_DVD
  for f in side_launch_redirect.log side_launch_dyld.txt; do scp -q G5:rung3/$f "$D/proof/" 2>/dev/null; done
  case $v in *REC) scp -q G5:rung3/va_cap/rec_$v.tsv "$D/proof/rec.tsv" 2>/dev/null;; VAWATCH) scp -q G5:rung3/va_cap/ctxwatch.txt "$D/proof/ctxwatch.txt" 2>/dev/null;; esac
  echo "$v: done $(date)" >> "$O/sides.log"
done
reboot_wait; echo "final reboot done $(date)" >> "$O/sides.log"; echo "done" >> "$O/sides.log"
