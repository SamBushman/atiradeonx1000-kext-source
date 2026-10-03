#!/usr/bin/env python3
"""opcode_usage.py - issue #42 criterion 2: merge opcode_recorder logs and compare what real workloads emit with the opcodes the stock dispatchers handle.

Input: workload logs written by Tools/userspace/opcode_recorder.c (one file per process run), each given as NAME=PATH; the inventory is Tests/pm4_opcode_inventory.md
(from Tools/opcode_inventory.py: the opcodes the stock process_command_buffer of each context compares against).
Per context (GL / 2D / DVD) the report gives: flushes, records and words observed; for every observed opcode its record/word counts and which workloads emitted it;
  * observed AND in the inventory   -> coverage
  * observed but NOT in the inventory -> either the recorder's record format is wrong for that stream, or the opcode takes the dispatcher's default path (opcode 0x00 is the
    raw/padding record); each is listed so it can be settled by hand - a long list means the format assumption is broken
  * in the inventory but never observed -> the gap a workload still has to fill
and the anomaly count (records that overrun a buffer, buffers that never terminate). Exit 0, or 1 if anomalies were recorded.

Usage: opcode_usage.py [--inventory Tests/pm4_opcode_inventory.md] [-o Tests/pm4_opcode_usage.md] NAME=LOG [NAME=LOG ...]
"""
import argparse, collections, os, re, sys

CTX = {"gl": "GL", "2d": "2D", "dvd": "DVD"}


def load_inventory(path):
    inv, cur = {}, None
    for ln in open(path):
        m = re.match(r"^## (GL|2D|DVD) ", ln)
        if m:
            cur = m.group(1); inv[cur] = set(); continue
        m = re.match(r"^\| 0x([0-9a-f]{2}) \|", ln)
        if m and cur:
            inv[cur].add(int(m.group(1), 16))
    return inv


def load_logs(items):
    """-> data[ctx][workload] = {opcode: [records, words]}, flushes[ctx][workload], anomalies, processes[workload]"""
    data = collections.defaultdict(lambda: collections.defaultdict(lambda: collections.defaultdict(lambda: [0, 0])))
    flushes = collections.defaultdict(lambda: collections.defaultdict(int)); anomalies = 0; strays = 0; procs = collections.defaultdict(int)
    for item in items:
        name, _, path = item.partition("=")
        if not path:
            raise SystemExit("expected NAME=LOG, got %r" % item)
        procs[name] += 1
        last = {}                                   # (pid, ctx) -> (flushes, hist): the recorder writes cumulative TOTAL snapshots, the last one per process wins
        for ln in open(path, errors="replace"):
            f = ln.rstrip("\n").split("\t")
            if f[0] == "ANOMALY":
                anomalies += 1
            if f[0] == "STRAY":
                strays += 1
            if f[0] != "TOTAL":
                continue
            kv = dict(x.split("=", 1) for x in f[1:] if "=" in x and not x.startswith("HIST"))
            ctx = CTX.get(kv.get("type"))
            if not ctx:
                continue
            hist = [x for x in f[1:] if x.startswith("HIST")][0].split()[1:] if any(x.startswith("HIST") for x in f[1:]) else []
            last[(kv.get("pid", "?"), ctx)] = (int(kv.get("flushes", 0)), hist)
        for (pid, ctx), (nfl, hist) in last.items():
            flushes[ctx][name] += nfl
            for h in hist:
                op, r, w = h.split(":")
                d = data[ctx][name][int(op, 16)]
                d[0] += int(r); d[1] += int(w)
    return data, flushes, anomalies, strays, procs


def render(inv, data, flushes, anomalies, strays, procs):
    out = ["# Command-stream opcode usage by real workloads (issue #42 criterion 2)", "",
           "Recorded on the stock kext (4.1.9, G5, Tiger) with `Tools/userspace/opcode_recorder.c`, merged by `Tools/opcode_usage.py`, compared with the dispatcher inventory in `Tests/pm4_opcode_inventory.md`.",
           "Counts are buffers submitted through the flush-map path (the kernel's `process_command_buffer`); buffers processed by other kernel paths are not counted.", "",
           "Workloads: " + ", ".join("`%s` (%d run%s)" % (n, c, "" if c == 1 else "s") for n, c in sorted(procs.items())), ""]
    for ctx in ("GL", "2D", "DVD"):
        ops = collections.defaultdict(lambda: [0, 0, set()])
        for wl, h in data.get(ctx, {}).items():
            for op, (r, w) in h.items():
                ops[op][0] += r; ops[op][1] += w; ops[op][2].add(wl)
        total_fl = sum(flushes.get(ctx, {}).values())
        out += ["## %s" % ctx, ""]
        if not ops:
            out += ["No `%s` flushes recorded by any workload (flushes: %d)." % (ctx, total_fl), "",
                    "Inventory: %d opcodes, none observed." % len(inv.get(ctx, ())), ""]
            continue
        covered = sorted(o for o in ops if o in inv[ctx]); extra = sorted(o for o in ops if o not in inv[ctx]); missing = sorted(inv[ctx] - set(ops))
        out += ["Flushes: %d.  Records: %d.  Words: %d.  Distinct opcodes observed: %d of %d in the inventory (**%.0f %% coverage**); observed but not in the inventory: %d."
                % (total_fl, sum(v[0] for v in ops.values()), sum(v[1] for v in ops.values()), len(covered), len(inv[ctx]), 100.0 * len(covered) / max(1, len(inv[ctx])), len(extra)), "",
                "| opcode | records | words | in inventory | workloads |", "|---|---:|---:|---|---|"]
        for op in sorted(ops):
            r, w, wls = ops[op]
            out.append("| 0x%02x | %d | %d | %s | %s |" % (op, r, w, "yes" if op in inv[ctx] else "**NO**", ", ".join(sorted(wls))))
        out += ["", "Observed but NOT in the inventory: %s." % (", ".join("0x%02x" % o for o in extra) or "none") +
                ("  (0x00 is observed as 1-word pads and as large register-state blocks and is not compared against by the dispatcher, so it presumably takes the default path - to be confirmed; any other entry here needs checking.)" if 0 in extra else ""),
                "", "In the inventory but never observed (%d): %s." % (len(missing), ", ".join("0x%02x" % o for o in missing) or "none"), ""]
    out += ["Anomalies recorded (record overruns a buffer / buffer never terminates / unreadable mapping): **%d**." % anomalies,
            "Stray words (one word between the end of the last record and a zero terminator, logged as STRAY, not as an anomaly): %d." % strays, ""]
    return "\n".join(out) + "\n"


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--inventory", default=os.path.join(here, "..", "Tests", "pm4_opcode_inventory.md"))
    ap.add_argument("-o"); ap.add_argument("logs", nargs="+")
    a = ap.parse_args()
    inv = load_inventory(a.inventory)
    data, flushes, anomalies, strays, procs = load_logs(a.logs)
    txt = render(inv, data, flushes, anomalies, strays, procs)
    if a.o:
        open(a.o, "w").write(txt)
    else:
        sys.stdout.write(txt)
    return 1 if anomalies else 0


if __name__ == "__main__":
    sys.exit(main())
