#!/usr/bin/env python3
"""udp_log_receiver.py - receiver half of the G5 live crash-log capture pair.

Run this on the DEV machine (not the G5) BEFORE starting any crash-prone test:
    python3 Tools/udp_log_receiver.py [port] [logfile]
Defaults: port 9167, logfile /tmp/claude-1000/.../scratchpad/g5_klog_mirror.log (cwd-relative
'g5_klog_mirror.log' if no scratchpad env is set).

Pairs with Tools/klog_udp_mirror.c running on the G5. Every line is timestamped on arrival and
flushed + fsync'd immediately, so a crash that happens any amount of time later never loses a
line that already made it over the wire - this machine's own disk reliability is all that matters,
not the G5's. Prints each line to stdout too, so it can just be left running in a terminal/background
shell and watched live during a test.

Ctrl-C to stop. The log file is append-only across runs (never truncated), so restarting the
receiver mid-session is always safe.
"""
import socket
import sys
import os
import datetime

port = int(sys.argv[1]) if len(sys.argv) > 1 else 9167
logfile = sys.argv[2] if len(sys.argv) > 2 else "g5_klog_mirror.log"

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("0.0.0.0", port))

print(f"udp_log_receiver: listening on UDP :{port}, writing to {logfile}")

with open(logfile, "a", buffering=1) as f:
    while True:
        try:
            data, addr = sock.recvfrom(4096)
        except KeyboardInterrupt:
            break
        line = data.decode("utf-8", errors="replace")
        ts = datetime.datetime.now().isoformat(timespec="milliseconds")
        out = f"{ts} {addr[0]} {line}"
        print(out, flush=True)
        f.write(out + "\n")
        f.flush()
        os.fsync(f.fileno())
