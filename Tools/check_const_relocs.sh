#!/bin/sh
# check_const_relocs.sh OBJDIR - fail if any object has a relocation against a DATA symbol in __TEXT,__const.
# Such a word (gcc hoists the address of an extern into the constant pool) makes Tiger's kextload crash in kld_file_prepare_for_link (NULL dereference)
# at load time. Vtable/C++ symbols (__Z*) and ___cxa_pure_virtual are the normal __const relocations and are allowed.
bad=0
for o in "$1"/*.o; do
    otool -rv "$o" 2>/dev/null | awk -v f="$(basename $o)" '/^Relocation information \(__TEXT,__const\)/{c=1;next} /^Relocation information/{c=0} c && $4=="True" && $NF !~ /^__Z/ && $NF != "___cxa_pure_virtual" {print f ": relocation against " $NF " in __TEXT,__const"}'
done > "$1/../const_relocs.txt"
if [ -s "$1/../const_relocs.txt" ]; then cat "$1/../const_relocs.txt"; echo "check_const_relocs: FAIL (kextload would crash)"; exit 1; fi
echo "check_const_relocs: ok"
