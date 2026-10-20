#!/usr/bin/env python3
"""union_coverage.py - union instruction coverage per function over all cases of a difftest --json report.
Usage: union_coverage.py [-r] REPORT.json [FUNCTION-substring ...]   (-r: list the uncovered ranges as offsets from the function entry)
A function tested by many per-slice cases (process_command_buffer opcodes) is judged by the union, not by any single case."""
import json, sys, collections
args = [a for a in sys.argv[1:] if a != '-r']; ranges = '-r' in sys.argv
data = json.load(open(args[0])); filt = args[1:]
fn = collections.defaultdict(lambda: [set(), set(), 0, 0, 0])
for d in data:
    f = d.get('function')
    if not f or (filt and not any(x in f for x in filt)): continue
    e = fn[f]
    for lo, hi in d.get('visited_stock', []): e[0].update(range(lo, hi, 4))
    for lo, hi in d.get('visited_rebuilt', []): e[1].update(range(lo, hi, 4))
    e[2] = max(e[2], d.get('size_stock', 0)); e[3] = max(e[3], d.get('size_rebuilt', 0)); e[4] += 1
for f, (vs, vr, ss, sr, n) in sorted(fn.items(), key=lambda kv: len(kv[1][1]) * 4 / max(kv[1][3], 1)):
    print('%5.1f%% stock %5.1f%% rebuilt  %2d cases  %s' % (100.0 * len(vs) * 4 / max(ss, 1), 100.0 * len(vr) * 4 / max(sr, 1), n, f))
    if ranges and sr:
        miss = [o for o in range(0, sr, 4) if o not in vr]; out = []
        for o in miss:
            if out and o == out[-1][1]: out[-1][1] = o + 4
            else: out.append([o, o + 4])
        print('    uncovered (rebuilt): ' + ' '.join('%x-%x' % (a, b) for a, b in out))
