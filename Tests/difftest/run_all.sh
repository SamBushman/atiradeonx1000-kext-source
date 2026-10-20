#!/bin/sh
# run_all.sh - every differential function test (stock vs rebuilt). Needs the stock kext binary ($STOCK_KEXT) and a rebuilt one ($REBUILT_KEXT,
# produced by Tools/difftest/build_rebuilt.sh). Usage: sh Tests/difftest/run_all.sh [difftest.py options]
cd "$(dirname "$0")/../.." || exit 2
python3 Tools/difftest/difftest.py -j "${JOBS:-8}" "$@" Tests/difftest/surface_cases.py Tests/difftest/surface_auto_cases.py Tests/difftest/registers_cases.py Tests/difftest/hand_cases.py Tests/difftest/hand_cases_A.py Tests/difftest/hand_cases_B.py Tests/difftest/hand_cases_C.py Tests/difftest/hand_cases_D.py Tests/difftest/hand_cases_CMFT.py Tests/difftest/hand_cases_U4P.py Tests/difftest/hand_cases_U6P.py Tests/difftest/hand_cases_P1.py Tests/difftest/hand_cases_P2.py Tests/difftest/hand_cases_N6.py Tests/difftest/all_classes_cases.py
