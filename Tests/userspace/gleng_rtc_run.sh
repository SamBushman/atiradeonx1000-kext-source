#!/bin/sh
# gleng_rtc_run.sh REBUILT_IMAGE [NTRIALS=300] [CTL=0]  - run the RTC-builder mock (gleng_mock_rtcbuild, built next to this script on the G5) over gleng_rtc_spec.txt against the stock GLEngine.
# The spec's rebuilt addresses and the CELLS addresses (PTR__gle_processor / PTR__glePushInstructions / PTR__gleRTCNoop, 0x11204c/0x112054/0x112058 in the stock) belong to ONE image layout:
# those below are right for images 8121a342 .. 08cb353f; after a layout change regenerate them from `nm` (PTR__gle_processor_0011204c etc., and the builder / chunk / retfn rebuilt FILE addresses).
cd "$(dirname "$0")"
ST=/System/Library/Frameworks/OpenGL.framework/Resources/GLEngine.bundle/GLEngine
./gleng_mock_rtcbuild $ST "$1" _gliAttachDrawable 107ad8 135360 11204c,14338c,112054,143394,143398 4174 56c0 42c0 5510 ${2:-300} ${3:-0} < gleng_rtc_spec.txt
