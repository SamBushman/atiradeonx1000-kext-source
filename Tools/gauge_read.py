#!/usr/bin/env python3
"""gauge_read.py - issue #44 (2D/desktop-compositing automation): reads Quartz Debug's Frame Meter (an analog needle
gauge, 0-90 scale - NOT a digital counter) from a screencapture PNG, via plain-stdlib PNG decoding (zlib+struct, no
PIL/numpy needed anywhere in this pipeline, matching this project's dependency-light convention).

Calibration (derived 2026-10-06, Tests/baseline/perf/dvd... no wait, see Tests/baseline/perf/desktop_compositing_*
for the full derivation notes): the needle's rest ("0") position and the gauge's tick-mark angular spacing were
measured directly from real screenshots, cross-validated two independent ways (extrapolating the measured tick
spacing to find where "0" should be landed within 0.15 degrees of the directly-measured idle needle angle) - this
is a real calibration, not an assumed "standard gauge" layout.

Usage: gauge_read.py capture1.png [capture2.png ...]
  Prints one line per file: <filename> <value>  (or "no-needle-found" if the red-pixel scan found nothing, e.g. a
  corrupted/partial capture)
"""
import sys, struct, zlib, math, glob, os

# --- calibration constants (screen pixel space, 1920x1080) ---
NEEDLE_SCAN_BOX = (0, 800, 310, 1020)   # (x0, y0, x1, y1) - region containing the whole gauge, excludes the Dock
PIVOT = (150.6, 970.2)                   # needle pivot, from the intersection of two independently-measured needle lines
ZERO_ANGLE_DEG = 150.0                   # measured directly: atan2(dy,dx) from PIVOT to the idle (value=0) needle centroid
DEG_PER_UNIT = 2.643                     # measured from 7 tick-mark clusters (20..80), (1.32 - (-157.28)) / 6 gaps / 10


def read_png(path):
    with open(path, 'rb') as f:
        data = f.read()
    if data[:8] != b'\x89PNG\r\n\x1a\n':
        raise ValueError('not a PNG: %s' % path)
    pos = 8
    width = height = bitdepth = colortype = None
    idat = b''
    while pos < len(data):
        length = struct.unpack('>I', data[pos:pos + 4])[0]
        ctype = data[pos + 4:pos + 8]
        chunk = data[pos + 8:pos + 8 + length]
        if ctype == b'IHDR':
            width, height, bitdepth, colortype = struct.unpack('>IIBB', chunk[:10])
        elif ctype == b'IDAT':
            idat += chunk
        elif ctype == b'IEND':
            break
        pos += 8 + length + 4
    raw = zlib.decompress(idat)
    if colortype == 2:
        channels = 3
    elif colortype == 6:
        channels = 4
    else:
        raise ValueError('unsupported PNG colortype %d (need RGB or RGBA)' % colortype)
    if bitdepth != 8:
        raise ValueError('unsupported PNG bitdepth %d (need 8)' % bitdepth)
    stride = width * channels
    rows = []
    prev = bytearray(stride)
    p = 0
    for _ in range(height):
        ftype = raw[p]
        p += 1
        line = bytearray(raw[p:p + stride])
        p += stride
        for x in range(stride):
            a = line[x - channels] if x >= channels else 0
            b = prev[x]
            c = prev[x - channels] if x >= channels else 0
            if ftype == 0:
                pass
            elif ftype == 1:
                line[x] = (line[x] + a) & 0xff
            elif ftype == 2:
                line[x] = (line[x] + b) & 0xff
            elif ftype == 3:
                line[x] = (line[x] + (a + b) // 2) & 0xff
            elif ftype == 4:
                pp = a + b - c
                pa, pb, pc = abs(pp - a), abs(pp - b), abs(pp - c)
                pr = a if (pa <= pb and pa <= pc) else (b if pb <= pc else c)
                line[x] = (line[x] + pr) & 0xff
        prev = line
        rows.append([tuple(line[x * channels:x * channels + 3]) for x in range(width)])
    return width, height, rows


def needle_centroid(rows):
    x0, y0, x1, y1 = NEEDLE_SCAN_BOX
    xs = []
    ys = []
    for y in range(y0, y1):
        row = rows[y]
        for x in range(x0, x1):
            r, g, b = row[x]
            if r > 150 and g < 90 and b < 90:
                xs.append(x)
                ys.append(y)
    if not xs:
        return None
    return sum(xs) / len(xs), sum(ys) / len(ys)


def angle_to_value(raw_deg):
    a = raw_deg
    if a > ZERO_ANGLE_DEG - 50:  # the only branch where the gauge's sweep wraps across atan2's +-180 seam
        a -= 360
    zero_unwrapped = ZERO_ANGLE_DEG - 360
    return (a - zero_unwrapped) / DEG_PER_UNIT


def read_gauge(png_path):
    _, _, rows = read_png(png_path)
    c = needle_centroid(rows)
    if c is None:
        return None
    dx, dy = c[0] - PIVOT[0], c[1] - PIVOT[1]
    raw_deg = math.degrees(math.atan2(dy, dx))
    return angle_to_value(raw_deg)


if __name__ == '__main__':
    paths = []
    for arg in sys.argv[1:]:
        paths.extend(sorted(glob.glob(arg)))
    for p in paths:
        try:
            v = read_gauge(p)
        except Exception as e:
            print(f"{os.path.basename(p)} ERROR {e}")
            continue
        print(f"{os.path.basename(p)} {'no-needle-found' if v is None else ('%.2f' % v)}")
