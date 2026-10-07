#!/usr/bin/env python3
"""panic_symbolicate.py - issue #43 criterion 3: map a Tiger `panic.log` entry back to functions of ATIRadeonX1000.kext.

Mac OS X 10.4 panic logs give raw addresses plus the load address of each kext named in the backtrace ("com.apple.ATIRadeonX1000(4.1.9)@0x588000"). The kext is an MH_OBJECT whose
local symbols give each function's offset in __text; the loaded text starts PAD bytes after the load address. PAD = **0x1000** for the stock 4.1.9 kext on this machine. (An earlier note used
0xce0, the Mach-O header size; that is WRONG: with 0xce0 no backtrace frame follows a call instruction and the chain is nonsense. With 0x1000 every kext frame of the 2026-10-01 panic follows a
`bl`, and the 2026-09-18 panic resolves to `ATIR500Surface::getFramebufferIndex()+0x8`, `lwz r0,0xd64(r3)` with DAR 0xd64 - the documented DVD set_macrovision NULL-surface cause.)
`--find-pad` re-derives PAD from a log for any kext binary (a rebuilt kext's layout may differ): it tries every 4-byte-aligned pad and keeps the one for which the most kext return addresses
follow a call instruction. Always run it, and check the faulting instruction is a load/store whose offset equals DAR, before trusting a symbolication.

Every address (PC, LR, each backtrace word; DAR is data and is not mapped) that falls inside the ATIRadeonX1000 text range is resolved to symbol+offset, with the instructions around PC/LR;
other addresses are labelled kernel (< 0x100000), other kext/kernel (no symbols available), or user (>= 0xC0000000).

Usage:  panic_symbolicate.py PANIC.LOG [--kext tiger-hd-pull/ATIRadeonX1000.kext.bin | a rebuilt kext binary] [--pad 0x1000 | --find-pad] [--entry N]
Use the rebuilt kext's own binary (same --pad) to symbolicate a Phase R panic against OUR build; the symbol file must be the exact build that was loaded.
The report per entry: header, panic string, exception registers, resolved PC/LR, and the backtrace with names. Exit 0 if at least one address was resolved in the kext, 1 if none, 2 on parse errors.
"""
import argparse, bisect, os, re, subprocess, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "userspace"))
import machoutil

HEX = re.compile(r"0x[0-9A-Fa-f]{1,8}")
MOD = re.compile(r"^\s*(?P<name>[\w.\-]+)\((?P<ver>[^)]*)\)@(?P<base>0x[0-9a-fA-F]+)")


def demangle(names):
    try:
        p = subprocess.run(["c++filt"], input="\n".join(n[1:] if n.startswith("_") else n for n in names), capture_output=True, text=True, timeout=30)
        out = p.stdout.split("\n")
        return dict(zip(names, out)) if len(out) >= len(names) else {n: n for n in names}
    except Exception:
        return {n: n for n in names}


class Symtab:
    def __init__(self, path):
        m = machoutil.load(path)
        text = [s for s in m.secs if s["name"] == "__text"][0]
        self.size = text["size"]
        self.m = m
        syms = sorted({(s["value"], s["name"]) for s in m.syms if s.get("sect") == 1 and s["name"]})
        self.addrs = [a for a, _ in syms]
        self.names = [n for _, n in syms]
        self.dm = demangle(self.names)

    def disasm(self, off, before=2, after=1):
        """instructions around a text offset (Capstone PPC), the faulting one marked; [] when capstone is unavailable"""
        try:
            import capstone
        except ImportError:
            return []
        cs = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
        start = max(0, off - 4 * before)
        return [("=>" if i.address == off else "  ", i.address, i.mnemonic, i.op_str) for i in cs.disasm(self.m.read(start, 4 * (before + after + 1)), start)]

    def lookup(self, off):
        if not (0 <= off < self.size):
            return None
        i = bisect.bisect_right(self.addrs, off) - 1
        if i < 0:
            return None
        return "%s+0x%x" % (self.dm.get(self.names[i], self.names[i]), off - self.addrs[i])


def parse(text):
    """-> list of entries: dict(date, title, regs, backtrace[], mods{name: base})"""
    entries = []
    for chunk in re.split(r"\n\*{5,}\n", text):
        if "panic(" not in chunk and "Unresolved kernel trap" not in chunk:
            continue
        e = {"date": "", "title": "", "regs": {}, "bt": [], "mods": {}}
        lines = chunk.split("\n")
        for ln in lines:
            if re.match(r"^(Mon|Tue|Wed|Thu|Fri|Sat|Sun) \w{3} +\d+ ", ln) and not e["date"]:
                e["date"] = ln.strip()
            if not e["title"] and (ln.startswith("panic(") or ln.startswith("Unresolved kernel trap")):
                e["title"] = ln.strip()
        in_bt = False
        for ln in lines:
            if "PC=0x" in ln and not e["regs"]:
                for k, v in re.findall(r"(PC|LR|DAR|DSISR|R1|XCP|MSR)=(0x[0-9A-Fa-f]+)", ln):
                    e["regs"][k] = int(v, 16)
                xm = re.search(r"XCP=0x[0-9A-Fa-f]+ \(([^)]*)\)", ln)
                if xm:
                    e["xcp"] = xm.group(1)
            if "Backtrace:" in ln:
                in_bt = True
                continue
            if in_bt:
                toks = HEX.findall(ln)
                if toks and not ln.strip().startswith(("Kernel", "backtrace", "Proceeding")):
                    e["bt"] += [int(t, 16) for t in toks if len(t) > 5]
                elif "Kernel loadable" in ln or "Proceeding" in ln:
                    in_bt = False
            mm = MOD.match(ln)
            if mm and "dependency" not in ln:
                e["mods"][mm.group("name")] = int(mm.group("base"), 16)
        if e["bt"] and e["bt"][0] in e["bt"][1:]:
            e["bt"] = e["bt"][:e["bt"].index(e["bt"][0], 1)]
        entries.append(e)
    return entries


def label(addr, mods, st, pad, prefix):
    for name, base in mods.items():
        if name.startswith(prefix):
            r = st.lookup(addr - base - pad)
            if r:
                return "kext %s" % r
    if addr >= 0xC0000000:
        return "user"
    if addr < 0x00100000:
        return "kernel"
    return "other kext/kernel (no symbols)"


def follows_call(st, off):
    try:
        import capstone
    except ImportError:
        return False
    cs = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
    if off < 4 or off >= st.size:
        return False
    i = list(cs.disasm(st.m.read(off - 4, 4), off - 4))
    return bool(i) and i[0].mnemonic in ("bl", "bla", "bctrl", "blrl")


def find_pad(st, entries, prefix):
    """-> (best pad, frames matched, frames total, runner-up score)"""
    frames = []
    for e in entries:
        base = [b for k, b in e["mods"].items() if k.startswith(prefix)][0]
        frames += [w - base for w in e["bt"] if base <= w < base + 0x80000]
    if not frames:
        return None
    scores = sorted(((sum(follows_call(st, f - pad) for f in frames), -pad) for pad in range(0, 0x8000, 4)), reverse=True)
    return -scores[0][1], scores[0][0], len(frames), scores[1][0]


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("log")
    ap.add_argument("--kext", default=os.path.join(here, "..", "..", "tiger-hd-pull", "ATIRadeonX1000.kext.bin"))
    ap.add_argument("--pad", type=lambda s: int(s, 0), default=0x1000)
    ap.add_argument("--find-pad", action="store_true", help="derive PAD from the log: the pad for which most kext frames follow a call instruction")
    ap.add_argument("--entry", type=int, help="only the Nth ATI-related entry (1-based); default: all entries that name the kext")
    ap.add_argument("--module-prefix", default="com.apple.ATIRadeonX1000",
                     help="match panic-log module names starting with this instead of the stock bundle id - "
                          "needed for a locally-built test kext loaded under its own id (e.g. com.example.ATIRadeonX1000.stage3test)")
    a = ap.parse_args()
    st = Symtab(a.kext)
    ents = [e for e in parse(open(a.log, errors="replace").read()) if any(k.startswith(a.module_prefix) for k in e["mods"])]
    if a.entry:
        ents = ents[a.entry - 1:a.entry]
    if not ents:
        print("no panic entry naming a module starting with %r found" % a.module_prefix); return 2
    resolved = 0
    if a.find_pad:
        fp = find_pad(st, ents, a.module_prefix)
        if not fp:
            print("--find-pad: no kext frames in the log"); return 2
        a.pad = fp[0]
        print("pad 0x%x: %d of %d kext frames follow a call instruction (runner-up %d)%s" % (fp[0], fp[1], fp[2], fp[3], "" if fp[1] > fp[3] else "  ** AMBIGUOUS **"))
    for n, e in enumerate(ents, 1):
        print("== entry %d: %s" % (n, e["date"] or "(no date)"))
        print("   %s" % e["title"])
        if e["regs"]:
            r = e["regs"]
            print("   %s  DAR=0x%x DSISR=0x%x" % (e.get("xcp", ""), r.get("DAR", 0), r.get("DSISR", 0)))
            for k in ("PC", "LR"):
                if k in r:
                    lb = label(r[k], e["mods"], st, a.pad, a.module_prefix)
                    resolved += lb.startswith("kext")
                    print("   %s = 0x%08x  %s" % (k, r[k], lb))
                    if lb.startswith("kext"):
                        for base_name, base in e["mods"].items():
                            if base_name.startswith(a.module_prefix):
                                for mark, ad, mn, op in st.disasm(r[k] - base - a.pad):
                                    print("        %s %05x  %s %s" % (mark, ad, mn, op))
        for k, b in e["mods"].items():
            if k.startswith(a.module_prefix):
                print("   module %s base 0x%x text starts 0x%x" % (k, b, b + a.pad))
        for i, w in enumerate(e["bt"]):
            lb = label(w, e["mods"], st, a.pad, a.module_prefix)
            resolved += lb.startswith("kext")
            print("   #%-2d 0x%08x  %s" % (i, w, lb))
    return 0 if resolved else 1


if __name__ == "__main__":
    sys.exit(main())
