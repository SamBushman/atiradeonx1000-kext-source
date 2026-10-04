#!/usr/bin/env python3
"""frame_rate_from_log.py - issue #44 follow-up: real GL-application frame rate from a timestamped
Tools/userspace/opcode_recorder.c log.

A GL client's flush (IOConnectMapMemory of the flush memory type) submits the current command buffer and
IS the real-world analogue of "finished a frame" for an app that flushes once per rendered frame (the
common case for a real app's main loop - confirmed for the Godot workloads this script was built against:
see Tests/consumer_scenarios.md's "OpenGL, real application" row). The recorder's FLUSH lines now carry
t_us (added alongside this script); the interval between consecutive FLUSH t_us values for the SAME
connection is a real per-frame time. This is NOT simulated or synthetic - it is mined directly from an
unmodified run of the real app under Tools/userspace/opcode_recorder.c, the same capture mechanism already
used for opcode coverage (#42), just reading a field that capture already produces once the recorder change
in the same commit as this script is built and the workload is re-run.

Caveats, stated plainly:
* Only GL connections are meaningful for "frame rate" in the usual sense - 2D/DVD flushes do not correspond
  to rendered frames the same way. The report below still reports the stat for every connection/type found,
  but only treat the GL numbers as "frame rate".
* A connection that flushes more than once per rendered frame (uncommon, but not provably absent for every
  possible client) would overstate the derived FPS; this script reports the raw inter-flush interval
  statistics, not an assumption-laundered "frame rate" - read the connection/type context before trusting
  a number as literally "how many frames per second this app achieved".
* The first FLUSH line for a connection has no prior FLUSH to diff against and is dropped from the interval
  statistics (reported as "first_flush_t_us" for reference only).

Usage: frame_rate_from_log.py LOG [LOG ...]
"""
import sys
import re
import collections

LINE_RE = re.compile(r"^FLUSH\tconn=(0x[0-9a-f]+)\ttype=(\w+)\t.*\tt_us=([\d.]+)")


def load(path):
    per_conn = collections.OrderedDict()
    with open(path) as f:
        for line in f:
            m = LINE_RE.match(line)
            if not m:
                continue
            conn, ctype, t_us = m.group(1), m.group(2), float(m.group(3))
            per_conn.setdefault((conn, ctype), []).append(t_us)
    return per_conn


def stats(name, ctype, times):
    if len(times) < 2:
        print(f"{name} conn={ctype} first_flush_t_us={times[0]:.2f} (only 1 flush - no interval to report)")
        return
    deltas = [times[i + 1] - times[i] for i in range(len(times) - 1)]
    deltas.sort()
    n = len(deltas)
    fps = [1e6 / d if d > 0 else float("inf") for d in deltas]
    fps.sort()

    def pct(lst, p):
        return lst[int(n * p)] if n > 1 else lst[0]

    print(
        f"{name} conn={ctype} flushes={len(times)} intervals={n} "
        f"frame_time_us: min={deltas[0]:.1f} p10={pct(deltas, 0.1):.1f} median={deltas[n // 2]:.1f} "
        f"p90={pct(deltas, 0.9):.1f} max={deltas[-1]:.1f} | "
        f"derived_fps: min={fps[0]:.1f} median={fps[n // 2]:.1f} max={fps[-1]:.1f}"
    )


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 1
    for path in argv[1:]:
        per_conn = load(path)
        if not per_conn:
            print(f"{path}: no FLUSH lines with t_us found (log predates the t_us field, or no flushes occurred)")
            continue
        for (conn, ctype), times in per_conn.items():
            stats(f"{path} {conn}", ctype, times)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
