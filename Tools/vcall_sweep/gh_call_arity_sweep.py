#!/usr/bin/env python3
"""gh_call_arity_sweep.py - dropped-argument sweep for direct `GH_xxx(...)` kernel/IOKit calls (the sibling of vcall_arity_sweep.py).

Ghidra-ported sources declare external functions as `extern "C" UInt32 GH_x(...) asm("_mangled")` (untyped variadic), so a missing argument compiles
silently; the shipped code often leaves an argument live in a register (e.g. r6 = _page_size) which Ghidra's decompile omits (#175).
This demangles each GH_ symbol (c++filt), counts the declared parameters, and flags call sites that pass FEWER arguments than the declared count
(member functions need one more for `this`, so a flagged site may under-count even further). Every hit must be confirmed against stock
(Tools/vcall_sweep/ppcdisasm.py on the shipped kext around the call) - some callees ignore trailing parameters.
Usage: python3 Tools/vcall_sweep/gh_call_arity_sweep.py   (from the repo root)"""
import re, glob, subprocess, collections
decl = {}
for f in glob.glob("Headers/*.h") + glob.glob("Sources/*.cpp"):
    for m in re.finditer(r'extern "C"\s+\w+\s+(GH_\w+)\(\.\.\.\)\s*asm\("_?(_Z\w+)"\)', open(f, errors="replace").read()):
        decl[m.group(1)] = m.group(2)
names = list(decl.values())
out = subprocess.run(["c++filt"], input="\n".join(names), capture_output=True, text=True).stdout.split("\n")
def nparams(d):
    m = re.search(r'\((.*)\)(?: const)?$', d)
    if not m: return None
    s = m.group(1).strip()
    if s in ("", "void"): return 0
    depth = 0; n = 1
    for c in s:
        if c in "(<": depth += 1
        elif c in ")>": depth -= 1
        elif c == "," and depth == 0: n += 1
    return n
dem = {k: (out[i], nparams(out[i])) for i, k in enumerate(decl)}
def split_args(s):
    depth = 0; n = 0; cur = ""
    for c in s:
        if c in "([{": depth += 1
        elif c in ")]}": depth -= 1
        if c == "," and depth == 0: n += 1; cur = ""
        else: cur += c
    return (n + 1) if s.strip() else 0
hits = []
for f in sorted(glob.glob("Sources/*.cpp")):
    s = open(f, errors="replace").read()
    for m in re.finditer(r'\b(GH_\w+)\s*\(', s):
        name = m.group(1)
        ls = s.rfind("\n", 0, m.start()) + 1
        if 'extern "C"' in s[ls:m.start()]: continue   # the declaration itself
        if name not in dem or dem[name][1] is None: continue
        i = m.end(); depth = 1; j = i
        while j < len(s) and depth:
            if s[j] == "(": depth += 1
            elif s[j] == ")": depth -= 1
            j += 1
        passed = split_args(s[i:j-1]); want = dem[name][1]
        if passed < want:
            line = s.count("\n", 0, m.start()) + 1
            hits.append((f, line, name, passed, want, dem[name][0]))
for f, line, name, passed, want, d in hits:
    print("%s:%d  %s passes %d, declares %d: %s" % (f, line, name, passed, want, d[:110]))
print(len(hits), "short call sites;", len(decl), "GH_ externs")
