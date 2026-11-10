#!/bin/sh
# gleng_interpose_run.sh REBUILT_IMAGE LEDGER NARGS TRIALS PROFILE LOG [CTL_IMPORT]  - the import-interposer differential (fnfuzz FNFUZZ_INTERPOSE=1) over a ledger from
# `FNFUZZ_IMPORTS=1 FNFUZZ_RZ_STORED=1 FNFUZZ_ALLOW_EXIT=1 fnfuzz_gen.py gleng ...` and the argument counts of `import_nargs.py`. PROFILE = default | narrow | graph (fnfuzz FNFUZZ_PROFILE).
# CTL_IMPORT: name of an import whose answers the REBUILT side's stubs perturb (a mismatch control: functions that use the answer must be reported).
cd "$(dirname "$0")"
ST=/System/Library/Frameworks/OpenGL.framework/Resources/GLEngine.bundle/GLEngine
[ "$5" = default ] && P= || P=$5
FNFUZZ_PROFILE=$P FNFUZZ_IMPORT_CTL=$7 FNFUZZ_IMPORT_NARGS=$3 FNFUZZ_INTERPOSE=1 ${FNFUZZ:-./fnfuzz} $2 $ST "$1" $4 > "$6" 2>&1
