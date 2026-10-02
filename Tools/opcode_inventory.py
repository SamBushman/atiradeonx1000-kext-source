#!/usr/bin/env python3
"""opcode_inventory.py - issue #42 criterion 2: which command-stream opcodes do the shipped kext's three `process_command_buffer` dispatchers handle?

Reads the STOCK kext (fat Mach-O; PPC slice, via Tools/userspace/machoutil.py), disassembles each dispatcher with Capstone and recovers the set of opcodes (the top byte of each
32-bit command word: `srwi r,w,24` / `rlwinm r,w,0,0,7`) that the function compares against:
  literal    `cmplwi/cmpwi rOP, imm` where rOP holds the srwi-extracted opcode
  masked     `lis rK, hi` with (hi & 0xff) == 0 and a cmpw/cmplw of that register against an rlwinm-masked word  -> opcode hi>>8
  range      `addi rT, rOP, -lo` ; `cmplwi rT, n` ; ub/bgt   -> opcodes lo .. lo+n
  table      not decoded; a `mtctr` after a `lwzx` is reported, and the opcode set is flagged INCOMPLETE only if the table index derives from the opcode
This is a *heuristic* extraction (the output states how many compare sites each opcode came from) cross-checked, per context, against the literal `0x??000000` comparisons present
in Sources/*process_command_buffer_Port.cpp. Opcodes found by only one of the two methods are listed so a human can settle them (GAPS.md section 2 did that by hand for GL).

Usage: opcode_inventory.py [--kext PATH] [--src DIR] [-o Tests/pm4_opcode_inventory.md]
"""
import argparse, os, re, sys
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "userspace"))
import machoutil
import capstone

DISPATCHERS = [("GL", "ATIR500GLContext::process_command_buffer", 0x2b820, "ATIR500GLContext_process_command_buffer_Port.cpp"),
               ("2D", "ATIR5002DContext::process_command_buffer", 0x326d0, "ATIR5002DContext_process_command_buffer_Port.cpp"),
               ("DVD", "ATIR500DVDContext::process_command_buffer", 0x357c0, "ATIR500DVDContext_process_command_buffer_Port.cpp")]


def func_end(m, start, text_end):
    """next higher symbol value in __text (the kext is an MH_OBJECT; local symbols are present), else the next dispatcher start / end of text"""
    higher = sorted(s["value"] for s in m.syms if start < s["value"] < text_end and s.get("sect", 0) == 1)
    return higher[0] if higher else text_end


def analyse(m, start, end):
    cs = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
    cs.detail = False
    ins = list(cs.disasm(m.read(start, end - start), start))
    opreg, maskreg = {}, {}          # reg -> insn index where it was set to the extracted opcode / masked word
    lis, sub = {}, {}                # reg -> (hi, idx) / reg -> (lo, srcreg, idx)
    found = {}                       # opcode -> list of (kind, address)
    table = []
    for i, x in enumerate(ins):
        mn, ops = x.mnemonic, [o.strip() for o in x.op_str.split(",")]
        def add(op, kind):
            if 0 <= op <= 0xff:
                found.setdefault(op, []).append((kind, x.address))
        # a write to a register invalidates what we knew about it (register reuse); the setters below re-add it
        src_is_op = len(ops) > 1 and ops[1] in opreg
        copy = None
        if mn == "mr" and len(ops) > 1:   # register copies carry what we know about the source
            copy = tuple(d.get(ops[1]) for d in (opreg, maskreg, lis, sub))
        if not (mn.startswith(("st", "cmp", "b", "mt", "nop", "dcb", "sync", "isync", "eieio")) or mn in ("mtctr", "mtlr")):
            # only the opcode-derived registers are invalidated: the masked word and the lis constants are loop-carried across basic blocks (a linear scan cannot tell which
            # writes are on the path to a later compare), so they are kept and the 24-instruction window on `lis` bounds the staleness
            for d in (opreg, sub):
                d.pop(ops[0], None)
        if copy:
            for d, v in zip((opreg, maskreg, lis, sub), copy):
                if v is not None:
                    d[ops[0]] = v
        if mn == "srwi" and ops[2] in ("0x18", "24"):
            opreg[ops[0]] = i
        elif mn == "rlwinm" and ops[2:] == ["0", "0", "7"]:
            maskreg[ops[0]] = i
        elif mn == "lis":
            try:
                hi = int(ops[1], 0) & 0xffff
                lis[ops[0]] = (hi, i)
            except ValueError:
                pass
        elif mn == "addi" and src_is_op:
            try:
                sub[ops[0]] = (-int(ops[2], 0), ops[1], i)
            except ValueError:
                pass
        elif mn in ("cmplwi", "cmpwi") and len(ops) >= 3:
            reg = ops[1]
            try:
                imm = int(ops[2], 0)
            except ValueError:
                continue
            if reg in opreg and i - opreg[reg] < 60:
                add(imm & 0xffff, "literal")
            elif reg in sub and i - sub[reg][2] < 6 and imm >= 0:
                lo = sub[reg][0]
                for o in range(lo, lo + imm + 1):
                    add(o, "range %02x-%02x" % (lo, lo + imm))
        elif mn in ("cmpw", "cmplw") and len(ops) >= 3:
            a, b = ops[1], ops[2]
            for r1, r2 in ((a, b), (b, a)):
                if r1 in lis and r2 in maskreg and i - lis[r1][1] < 24 and (lis[r1][0] & 0xff) == 0:
                    add(lis[r1][0] >> 8, "masked")
        elif mn == "mtctr":
            # a table dispatch if a lwzx precedes it closely
            if any(p.mnemonic == "lwzx" for p in ins[max(0, i - 4):i]):
                # which register indexed the table, and was it the opcode? (the compare+bgt bound check precedes the lwzx)
                idx = None
                for p in ins[max(0, i - 12):i]:
                    if p.mnemonic in ("cmplwi", "cmpwi"):
                        po = [o.strip() for o in p.op_str.split(",")]
                        idx = (po[1], po[2]) if len(po) >= 3 else None
                from_opcode = bool(idx) and (idx[0] in opreg or idx[0] in sub)
                table.append((x.address, from_opcode, idx[1] if idx else "?"))
    return found, table, len(ins)


def source_opcodes(path):
    s = open(path, errors="replace").read()
    out = set()
    for m_ in re.finditer(r"0x([0-9a-fA-F]{1,2})000000\b", s):
        v = int(m_.group(1), 16)
        if v < 0x80:
            out.add(v)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    here = os.path.dirname(os.path.abspath(__file__))
    ap.add_argument("--kext", default=os.path.join(here, "..", "..", "tiger-hd-pull", "ATIRadeonX1000.kext.bin"))
    ap.add_argument("--src", default=os.path.join(here, "..", "Sources"))
    ap.add_argument("-o")
    a = ap.parse_args()
    m = machoutil.load(a.kext)
    text = [s for s in m.secs if s["name"] == "__text"][0]
    text_end = text["addr"] + text["size"]
    out = ["# Command-stream opcode inventory of the stock kext (issue #42 criterion 2)", "",
           "Generated by `Tools/opcode_inventory.py` from `tiger-hd-pull/ATIRadeonX1000.kext.bin` (stock 4.1.9, PPC slice). The opcode is the top byte of each 32-bit command word. "
           "Opcodes come from compare sites in the disassembly of each context's `process_command_buffer`; the last column cross-checks against the literal `0x??000000` constants in the C++ port. "
           "**Heuristic**: a table dispatch (`lwzx`+`mtctr`) or a comparison form not recognised would be missed; those are flagged below. Whether a real client ever emits an opcode is NOT established here "
           "(see `Tests/consumer_scenarios.md` for the capture plan).", ""]
    for ctx, name, start, srcfile in DISPATCHERS:
        end = func_end(m, start, text_end)
        found, table, n = analyse(m, start, end)
        srcset = source_opcodes(os.path.join(a.src, srcfile))
        asmset = set(found)
        out += ["## %s - `%s` @ 0x%x (%d instructions, to 0x%x)" % (ctx, name, start, n, end), "",
                "Opcodes recovered from the disassembly: %d; literal opcode constants in the C++ port: %d." % (len(asmset), len(srcset)), ""]
        for taddr, from_opcode, bound in table:
            if from_opcode:
                out += ["**Opcode table dispatch** at 0x%x (bound %s): opcodes reached only through it are NOT in the list below (INCOMPLETE)." % (taddr, bound), ""]
            else:
                out += ["Indirect jump table at 0x%x (bound %s) is indexed by a data word, not by the opcode: a sub-switch inside one handler, does not affect the opcode set." % (taddr, bound), ""]
        out += ["| opcode | compare sites (disasm) | kind(s) | in C++ source |", "|---|---|---|---|"]
        for op in sorted(asmset | srcset):
            sites = found.get(op, [])
            kinds = sorted(set(k for k, _ in sites))
            out.append("| 0x%02x | %d | %s | %s |" % (op, len(sites), ", ".join(kinds) or "-", "yes" if op in srcset else "no"))
        only_asm, only_src = sorted(asmset - srcset), sorted(srcset - asmset)
        out += ["", "Only in the disassembly: %s." % (", ".join("0x%02x" % o for o in only_asm) or "none"),
                "Only in the C++ literals: %s (constants in the source that are not opcode compares, e.g. data words, show up here)." % (", ".join("0x%02x" % o for o in only_src) or "none"), ""]
        sys.stderr.write("%s: %d asm opcodes, %d src constants, tables at %s\n" % (ctx, len(asmset), len(srcset), [(hex(t[0]), t[1]) for t in table]))
    txt = "\n".join(out) + "\n"
    if a.o:
        open(a.o, "w").write(txt)
    else:
        sys.stdout.write(txt)


if __name__ == "__main__":
    main()
