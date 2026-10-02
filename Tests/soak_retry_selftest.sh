#!/bin/sh
# Tests/soak_retry_selftest.sh - issue #43: proves the TRANSIENT RETRY RULE of Tests/soak.sh with a fake harness (no hardware needed; also runs on the G5's old sh).
#   sh soak_retry_selftest.sh            prints one line per scenario and "SELFTEST PASS"/"SELFTEST FAIL"
T=/tmp/soak_selftest.$$; mkdir -p $T; cp "`dirname "$0"`/soak.sh" $T/soak.sh; cd $T || exit 1
cat > ref.txt <<'EOR'
[OK] GL get_config(sel 3) -> 0x00000000 (kIOReturnSuccess)
[OK] DVD dvd_setup_overlay unbound -> Error r=0xe00002bc
[OK] DVD dvd_enable_deint(1) bound -> success r=0x00000000
[OK] Surface get_state(sel 2) -> 0x00000000 (kIOReturnSuccess)

136 calls made (136 asserted, 0 recorded-only), 0 unexpected result(s), 0 skipped (shape-known, not live-tested)
EOR
# variants: (a) NotReady on two DVD lines (the real 2026-10-02 shape), (b) a different code on a DVD line, (c) NotReady on a NON-DVD line, (d) a changed value
sed -e 's/DVD dvd_setup_overlay unbound -> Error r=0xe00002bc/DVD dvd_setup_overlay unbound -> Error r=0xe00002d8/' -e 's/DVD dvd_enable_deint(1) bound -> success r=0x00000000/DVD dvd_enable_deint(1) bound -> success r=0xe00002d8/' -e 's/0 unexpected/2 unexpected/' ref.txt > var_a.txt
sed -e 's/DVD dvd_enable_deint(1) bound -> success r=0x00000000/DVD dvd_enable_deint(1) bound -> success r=0xe00002c2/' -e 's/0 unexpected/1 unexpected/' ref.txt > var_b.txt
sed -e 's/Surface get_state(sel 2) -> 0x00000000 (kIOReturnSuccess)/Surface get_state(sel 2) -> 0xe00002d8 (NotReady)/' -e 's/0 unexpected/1 unexpected/' ref.txt > var_c.txt
sed -e 's/GL get_config(sel 3) -> 0x00000000/GL get_config(sel 3) -> 0x00000001/' ref.txt > var_d.txt
cat > fake.sh <<'EOF2'
#!/bin/sh
# FAKE_VARIANT file is returned on the call numbers listed in FAKE_CALLS (comma separated, "all>=N" = every call from N on); otherwise the reference
c=`cat count 2>/dev/null || echo 0`; c=`expr $c + 1`; echo $c > count
case "$FAKE_CALLS" in all\>=*) n=`echo "$FAKE_CALLS" | sed 's/all>=//'`; if [ $c -ge $n ]; then cat $FAKE_VARIANT; exit 0; fi;; *) case ",$FAKE_CALLS," in *",$c,"*) cat $FAKE_VARIANT; exit 0;; esac;; esac
cat ref.txt
EOF2
chmod +x fake.sh; echo true > /dev/null
fail=0
run() { # name calls variant expect_regex_in_log expect_exit [extra env...]
  nm=$1; calls=$2; var=$3; want=$4; wexit=$5; shift 5
  rm -f count soak.log soak.log.hwup; env FAKE_CALLS="$calls" FAKE_VARIANT=$var PERF_CMD=true PARITY_CMD=./fake.sh LOG=$T/soak.log RETRY_WAIT=0 "$@" sh ./soak.sh 2 > /dev/null 2>&1; rc=$?
  if grep -q "$want" soak.log && [ $rc -eq $wexit ]; then echo "ok   $nm (exit $rc)"; else echo "FAIL $nm: wanted /$want/ exit $wexit, got exit $rc"; grep -E "TRANSIENT|STEP|STOPPED|DONE" soak.log | head -6; fail=1; fi
}
# calls: round 1 parity=1 deep=2, round 2 parity=3 deep=4, ...
run "A  one NotReady-only transient, rerun matches -> recovered, soak completes"   "3"          var_a.txt "TRANSIENT-RECOVERED r2 parity after 1" 0
run "A2 transient on the deep step too"                                            "4"          var_a.txt "TRANSIENT-RECOVERED r2 deep after 1" 0
run "A3 two consecutive reruns still NotReady, third matches -> recovered"         "3,4"        var_a.txt "TRANSIENT-RECOVERED r2 parity after 2" 0
run "B  persistent NotReady (all calls from 3 on) -> STEP-DIFF after 3 retries"    "all>=3"     var_a.txt "STEP-DIFF r2 parity differs from .* (retries used: 3)" 1
run "C  different code on a DVD line -> fails at once, no retry"                   "3"          var_b.txt "STEP-DIFF r2 parity differs from .* (retries used: 0)" 1
run "D  NotReady on a non-DVD line -> fails at once, no retry"                     "3"          var_c.txt "STEP-DIFF r2 parity differs from .* (retries used: 0)" 1
run "E  changed value on a non-DVD line -> fails at once, no retry"                "3"          var_d.txt "STEP-DIFF r2 parity differs from .* (retries used: 0)" 1
run "F  budget: 2 recovered transients with TRANSIENT_MAX_PER_HOUR=2 -> allowed (2 in hour 1)" "3,5" var_a.txt "transients_recovered=2" 0 TRANSIENT_MAX_PER_HOUR=2
run "G  budget: 3 recovered transients with TRANSIENT_MAX_PER_HOUR=2 -> exceeds the 2 allowed in hour 1" "3,5,7" var_a.txt "TRANSIENT-BUDGET exceeded: 3 > 2" 1 TRANSIENT_MAX_PER_HOUR=2
run "H  budget: 2 recovered transients with TRANSIENT_MAX_PER_HOUR=1 -> exceeds the 1 allowed in hour 1" "3,5" var_a.txt "TRANSIENT-BUDGET exceeded: 2 > 1" 1 TRANSIENT_MAX_PER_HOUR=1
cd /; rm -rf $T
[ $fail -eq 0 ] && echo "SELFTEST PASS" || { echo "SELFTEST FAIL"; exit 1; }
