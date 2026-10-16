#!/bin/sh
# run_all.sh - every differential function test (stock vs rebuilt). Needs the stock kext binary ($STOCK_KEXT) and a rebuilt one ($REBUILT_KEXT,
# produced by Tools/difftest/build_rebuilt.sh). Usage: sh Tests/difftest/run_all.sh [difftest.py options]
cd "$(dirname "$0")/../.." || exit 2
python3 Tools/difftest/difftest.py "$@" Tests/difftest/surface_cases.py Tests/difftest/surface_auto_cases.py
