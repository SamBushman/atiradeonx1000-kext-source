#!/usr/bin/env python3
"""t3_read_buffer_source_analyze.py DIR [DIR ...]  -- read the output of Tools/t3_experiment_one.sh for t3_gl_read_buffer_source
(DIR has t3_gl_read_buffer_source.log, before.png, after.png) and print the answers to the five questions in the test header.
Prints facts only: counts, equalities, hit positions. It does not decide anything; the conclusions go into
Tests/destructive/phaseS_rerun/EVIDENCE.md by hand, with the DIR names as sources.
Needs `pngtopnm` (netpbm) for the screenshot search; without it question 4 is reported as 'not run'."""
import os, re, subprocess, sys

OBS = re.compile(r"NOTE obs call=(\d+) kind=(\S+) fill=([0-9a-f]+) t=(\d+)ms r=(0x[0-9a-f]+) changed=(\d+) inside=(\d+) outside=(\d+) list=(\S*)")

def parse(path):
    obs = {}
    for line in open(path, errors="replace"):
        m = OBS.search(line)
        if m:
            call, kind, fill, t, r, ch, ins, outs, lst = m.groups()
            d = {}
            for it in filter(None, lst.split(",")):
                off, val = it.split(":")
                d[int(off, 16)] = int(val, 16)
            obs[(int(call), int(t))] = dict(kind=kind, fill=int(fill, 16), r=r, changed=int(ch), inside=int(ins), outside=int(outs), bytes=d)
    return obs

def ppm(png):
    try:
        raw = subprocess.run(["pngtopnm", png], capture_output=True, check=True).stdout
    except Exception as e:
        return None
    m = re.match(rb"P6\s+(\d+)\s+(\d+)\s+(\d+)\s", raw)
    if not m:
        return None
    w, h = int(m.group(1)), int(m.group(2))
    return w, h, raw[m.end():]

def pixel_variants(b4):
    a, b, c, d = b4
    return {"ARGB": bytes((b, c, d)), "RGBA": bytes((a, b, c)), "BGRA": bytes((c, b, a)), "ABGR": bytes((d, c, b))}

def search(img, pat):
    w, h, data = img
    hits, i = [], data.find(pat)
    while i != -1 and len(hits) < 5:
        if i % 3 == 0:
            hits.append(((i // 3) % w, (i // 3) // w))
        i = data.find(pat, i + 1)
    return hits, data.count(pat)

def report(d):
    log = os.path.join(d, "t3_gl_read_buffer_source.log")
    if not os.path.exists(log):
        log = os.path.join(d, "t3_gl_read_buffer_source.log")
    obs = parse(log)
    print("== %s: %d obs rows" % (d, len(obs)))
    if not obs:
        return
    calls = sorted({c for c, _ in obs})
    times = sorted({t for _, t in obs})
    print("Q1 content over time (changed bytes at t=%s ms; 'same' = identical offset:value set to the t=0 sample):" % "/".join(map(str, times)))
    for c in calls:
        base = obs.get((c, 0))
        row = []
        for t in times:
            o = obs.get((c, t))
            row.append("-" if o is None else "%d%s" % (o["changed"], "" if o["bytes"] == base["bytes"] else "*"))
        print("  call %d %-12s fill %02x r=%s: %s  (* = differs from t=0)" % (c, base["kind"], base["fill"], base["r"], " ".join(row)))
    fin = {c: obs[(c, times[-1])] for c in calls if (c, times[-1]) in obs}
    print("Q2/Q3 final (t=%d ms) bytes, pairwise: two samples agree if every offset changed in BOTH has the same value (a byte equal to its prefill is invisible)" % times[-1])
    def agree(a, b):
        common = set(a["bytes"]) & set(b["bytes"])
        return all(a["bytes"][k] == b["bytes"][k] for k in common), len(common)
    for i in calls:
        for j in calls:
            if i < j and i in fin and j in fin:
                ok, n = agree(fin[i], fin[j])
                print("  call %d (%s %02x) vs call %d (%s %02x): %s on %d common changed offsets" % (i, fin[i]["kind"], fin[i]["fill"], j, fin[j]["kind"], fin[j]["fill"], "AGREE" if ok else "DIFFER", n))
    print("Q4 screenshot search (final-sample bytes of each call; first 4-byte unit at the lowest changed offset; hits = (x,y) of the pixel, total count):")
    shots = {n: ppm(os.path.join(d, n + ".png")) for n in ("before", "after")}
    if not all(shots.values()):
        print("  not run (pngtopnm missing or a screenshot is missing)")
        return
    for c in calls:
        o = fin.get(c)
        if not o or len(o["bytes"]) < 4:
            print("  call %d: fewer than 4 changed bytes, nothing to search" % c)
            continue
        offs = sorted(o["bytes"])
        start = offs[0] - offs[0] % 4
        unit = [o["bytes"].get(start + k) for k in range(4)]
        if None in unit:
            print("  call %d: unit at offset %#x incomplete (%s)" % (c, start, unit))
            continue
        for name, pat in pixel_variants(unit).items():
            res = []
            for sn, img in shots.items():
                hits, total = search(img, pat)
                res.append("%s: %d (%s)" % (sn, total, ",".join("%d/%d" % h for h in hits[:3])))
            print("  call %d unit@%#x %s as %-4s %s | %s" % (c, start, " ".join("%02x" % x for x in unit), name, res[0], res[1]))
    print("Q4b structure: the changed bytes grouped by row (row stride = the call's row_bytes 64) and 4-byte unit, then searched in the screenshots as a COLUMN of units (same x, rows y..y+3) and as a ROW of units (x..x+3 at one y), in the four channel orders:")
    for c in calls:
        o = fin.get(c)
        if not o:
            continue
        units = {}
        for off, v in o["bytes"].items():
            units.setdefault((off // 64, (off % 64) // 4), {})[off % 4] = v
        keys = sorted(units)
        print("  call %d units (row,unit): %s" % (c, " ".join("%d.%d=%s" % (r_, u_, "".join("%02x" % units[(r_, u_)].get(k, 0) for k in range(4))) for r_, u_ in keys)))
        if c != calls[0]:
            continue  # the searches are identical for calls that agree (Q2/Q3 above); search the first call only
        vals = [tuple(units[k].get(i) for i in range(4)) for k in keys]
        if None in [x for v in vals for x in v] or len(vals) < 2:
            print("  incomplete units: not searched")
            continue
        for name in ("ARGB", "RGBA", "BGRA", "ABGR"):
            trip = [pixel_variants(v)[name] for v in vals]
            for sn, img in shots.items():
                w, h, data = img
                for shape in ("column", "row"):
                    hits, total = [], 0
                    if shape == "row":
                        pat = b"".join(trip); i = data.find(pat)
                        while i != -1 and total < 100000:
                            if i % 3 == 0:
                                total += 1; hits.append(((i // 3) % w, (i // 3) // w))
                            i = data.find(pat, i + 1)
                    else:
                        i = data.find(trip[0])
                        while i != -1 and total < 100000:
                            if i % 3 == 0:
                                x, y = (i // 3) % w, (i // 3) // w
                                if y + len(trip) <= h and all(data[((y + j) * w + x) * 3:((y + j) * w + x) * 3 + 3] == trip[j] for j in range(len(trip))):
                                    total += 1; hits.append((x, y))
                            i = data.find(trip[0], i + 1)
                    print("  %-4s %-6s in %-6s: %d hit(s) %s" % (name, shape, sn, total, hits[:3]))
    print("  A hit count in the thousands (a flat desktop colour) proves nothing; a small count at a screen position that matches the surface's expected place, found in both channel/position checks, would.")

for d in sys.argv[1:]:
    report(d)
