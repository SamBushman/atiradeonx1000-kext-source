#!/usr/local/bin/python3
"""
Systematic fix for the FUN_0019423c/FUN_00194208 growable-vector header split-locals defect
(issue #64), across the whole GLDriver corpus.

FUN_0019423c(header, idx) ALWAYS reads header[0..3] (capacity, count, dataptr, arena) - even on
its "no grow needed" path it unconditionally reallocs+copies+frees using all 4 words. So every
call site "FUN_0019423c(&NAME, ...)" requires NAME and the three locals immediately below it in
the same declaration style (NAME_hex-4, -8, -0xc, same "local_" prefix) to be ONE contiguous
buffer, not four separate locals.

This script:
  1. Finds every "FUN_0019423c(&local_XX" call site in every part_*.c file.
  2. Groups them by (file, capacity-name).
  3. For each group, finds the enclosing function (by nearest preceding "/* FUN_... */" comment)
     - a header used by calls in DIFFERENT functions is treated separately per function, since each
       function has its own declaration block.
  4. Verifies the 4 expected declarations (capacity/count/dataptr/arena, by hex arithmetic on the
     capacity name) exist as separate single-line scalar declarations within that function's own
     declaration block, and aren't already fixed (no existing "#define NAME" for the capacity name
     already present before the function's closing brace).
  5. Replaces the 4 declarations with one byte buffer + 4 macros (preserving each original
     variable's type for its accessor), and appends #undef guards after the function's own closing
     brace - but only for names that actually collide with a DIFFERENT function's use of the same
     name elsewhere in the file (checked automatically); always-safe to add anyway, so always added.
  6. Skips (reports, does not touch) anything that doesn't match the expected shape exactly, rather
     than guessing.

Run with --dry-run first to review the plan, then without it to apply.
"""
import sys, re, glob, os

CORPUS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "Userspace", "ATIRadeonX1000GLDriver", "ppc")
CALL_RE = re.compile(r'FUN_0019423c\(&(local_[0-9a-f]+)\b')
FUN_MARKER_RE = re.compile(r'^/\* (FUN_[0-9a-fA-F]+|_[A-Za-z_][A-Za-z0-9_]*) @ 0x([0-9a-fA-F]+) \((\d+) bytes\) \*/$')
DECL_RE_TMPL = r'^(\s*)((?:unsigned char|undefined1|undefined2|undefined4|undefined8|undefined|uint|int|char|short|long|float|double|code|void)\s*\**\s*\**)\s*{name}\s*;\s*$'

FIELD_NAMES = ['capacity', 'count', 'dataptr', 'arena']

def hexname(prefix, val):
    return f'{prefix}{val:x}'

def parse_name(name):
    m = re.match(r'^(local_)([0-9a-f]+)$', name)
    if not m:
        return None
    return m.group(1), int(m.group(2), 16)

def find_function_boundaries(lines):
    """Return list of (start_line_idx(0-based), name, end_line_idx_exclusive) for every FUN_ marker."""
    markers = []
    for i, l in enumerate(lines):
        m = FUN_MARKER_RE.match(l.rstrip('\n'))
        if m:
            markers.append((i, m.group(1)))
    bounds = []
    for idx, (start, name) in enumerate(markers):
        end = markers[idx+1][0] if idx+1 < len(markers) else len(lines)
        bounds.append((start, name, end))
    return bounds

def find_enclosing(bounds, line_idx):
    for start, name, end in bounds:
        if start <= line_idx < end:
            return start, name, end
    return None

def find_closing_brace(lines, start, end):
    """Find the line index of the function's own closing brace (a lone '}' at column 0) within
    [start, end). Returns None if not found (huge functions may have many nested '}' - we want
    the LAST '}' at column 0 before `end`, since these part files don't indent top-level closes)."""
    for i in range(end - 1, start, -1):
        if lines[i].rstrip('\n') == '}':
            return i
    return None

def main():
    dry_run = '--dry-run' in sys.argv
    files = sorted(glob.glob(os.path.join(CORPUS, 'part_*.c')))
    plan = []  # list of dicts describing each fix to apply
    skipped = []

    for path in files:
        with open(path) as f:
            text = f.read()
        lines = text.split('\n')
        # keep trailing structure: split('\n') on a text ending in \n gives a trailing '' element;
        # we work with indices into this list and join with '\n' at the end (drop last if empty
        # matches original itself, so join always reconstructs correctly as long as we don't
        # add/remove the trailing '' improperly - we won't touch it).

        bounds = find_function_boundaries(lines)
        if not bounds:
            continue

        # collect all capacity names actually used in a FUN_0019423c call, per line
        call_sites = []
        for i, l in enumerate(lines):
            for m in CALL_RE.finditer(l):
                call_sites.append((i, m.group(1)))

        if not call_sites:
            continue

        # group by (function bounds, capacity name)
        groups = {}
        for line_idx, capname in call_sites:
            enc = find_enclosing(bounds, line_idx)
            if enc is None:
                skipped.append((path, line_idx, capname, "no enclosing function"))
                continue
            key = (enc, capname)
            groups.setdefault(key, []).append(line_idx)

        for (enc, capname), call_lines in groups.items():
            fstart, fname, fend = enc
            parsed = parse_name(capname)
            if parsed is None:
                skipped.append((path, fname, capname, "name doesn't match local_HEX"))
                continue
            prefix, capval = parsed
            names = [hexname(prefix, capval - 4*k) for k in range(4)]  # capacity,count,dataptr,arena
            assert names[0] == capname

            # Already fixed? (a #define for capname exists between fstart and fend)
            already = any(re.match(rf'^\s*#define\s+{re.escape(capname)}\b', lines[i])
                          for i in range(fstart, fend))
            if already:
                continue  # silently skip, already handled (e.g. by an earlier manual fix this session)

            # Find each of the 4 declarations as single-line scalar decls within [fstart, fend)
            decl_lines = {}
            decl_types = {}
            ok = True
            for nm in names:
                pat = re.compile(DECL_RE_TMPL.format(name=re.escape(nm)))
                found = None
                for i in range(fstart, fend):
                    mm = pat.match(lines[i])
                    if mm:
                        found = i
                        decl_types[nm] = mm.group(2).strip()
                        break
                if found is None:
                    ok = False
                    skipped.append((path, fname, capname, f"declaration for {nm} not found as a plain scalar decl"))
                    break
                decl_lines[nm] = found
            if not ok:
                continue

            # The 4 declarations must be exactly consecutive lines (capacity first line, then
            # count, dataptr, arena directly below, in that order) - this matches every instance
            # seen manually this session. If not consecutive-in-that-order, skip for manual review.
            ordered = [decl_lines[nm] for nm in names]
            if ordered != sorted(ordered) or ordered[-1] - ordered[0] != 3:
                skipped.append((path, fname, capname, f"declarations not 4 consecutive lines: {ordered}"))
                continue

            # Check for name collisions across the WHOLE file (outside this function) for each name
            collisions = {}
            for nm in names:
                for i, l in enumerate(lines):
                    if fstart <= i < fend:
                        continue
                    if re.search(rf'\b{re.escape(nm)}\b', l):
                        collisions[nm] = True
                        break

            closing = find_closing_brace(lines, fstart, fend)
            if closing is None:
                skipped.append((path, fname, capname, "could not find function's closing brace"))
                continue

            plan.append({
                'path': path,
                'fname': fname,
                'capname': capname,
                'names': names,
                'decl_first_line': ordered[0],
                'decl_last_line': ordered[-1],
                'decl_types': decl_types,
                'closing_line': closing,
                'collisions': [nm for nm in names if collisions.get(nm)],
                'ncalls': len(call_lines),
            })

    print(f"=== PLAN: {len(plan)} fixes across {len(set(p['path'] for p in plan))} files ===")
    for p in plan:
        print(f"{os.path.basename(p['path'])}: {p['fname']} header={p['capname']} "
              f"lines {p['decl_first_line']+1}-{p['decl_last_line']+1} closing@{p['closing_line']+1} "
              f"calls={p['ncalls']} collisions={p['collisions']}")
    print(f"\n=== SKIPPED: {len(skipped)} (need manual review) ===")
    for s in skipped:
        print(s)

    if dry_run:
        print("\n--dry-run: no files modified.")
        return

    # Apply fixes, grouped per file, processing bottom-to-top by line number so earlier edits
    # don't shift line numbers for edits still to come in the same file.
    by_file = {}
    for p in plan:
        by_file.setdefault(p['path'], []).append(p)

    for path, fixes in by_file.items():
        with open(path) as f:
            lines = f.read().split('\n')

        # Build ALL edit operations (both the declaration-block replacement AND the #undef
        # insertion) for every fix in this file into one flat list, each tagged with the line
        # index it targets, then apply strictly in descending line-index order. This is required
        # because a fix's own #undef sits at a MUCH higher line index (the function's closing
        # brace) than its declaration edit, and several fixes in the same function share one
        # closing-brace line - processing bottom-to-top per-fix (as a prior version of this script
        # did) leaves earlier (higher-index) insertions stale by the time a later, lower-index
        # declaration edit is applied, since that later edit's own insertion shifts every index
        # above it - corrupting the closing-line target for edits not yet applied. A single global
        # descending pass avoids this: every edit is applied while all edits below it in the file
        # are still at their original (or already-shifted-consistently) indices.
        ops = []  # list of (line_idx, kind, payload) - kind in {'undef', 'decl'}
        for p in fixes:
            names = p['names']
            capname, countname, ptrname, arenaname = names
            undef_block = '\n'.join(f'#undef {nm}' for nm in names)
            ops.append((p['closing_line'], 'undef', undef_block))

            indent = re.match(r'^(\s*)', lines[p['decl_first_line']]).group(1)
            buf = f'{capname}_buf'
            comment = (
                f"{indent}/* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) "
                f"used with FUN_0019423c - {capname}/{countname}/{ptrname}/{arenaname} are its four words "
                f"by their own hex offsets. FUN_0019423c unconditionally reads all four on every call "
                f"(even its \"no grow needed\" path reallocs+copies+frees), so they must be one contiguous "
                f"buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. "
                f"Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */\n"
            )
            new_decl = (
                comment +
                f"{indent}unsigned char {buf} [0x10];\n"
                f"{indent}#define {capname} (*({decl_types_cast(p['decl_types'][capname])} *)({buf} + 0x00))\n"
                f"{indent}#define {countname} (*({decl_types_cast(p['decl_types'][countname])} *)({buf} + 0x04))\n"
                f"{indent}#define {ptrname} (*({decl_types_cast(p['decl_types'][ptrname])} *)({buf} + 0x08))\n"
                f"{indent}#define {arenaname} (*({decl_types_cast(p['decl_types'][arenaname])} *)({buf} + 0x0c))"
            )
            ops.append((p['decl_first_line'], 'decl', (p['decl_last_line'], new_decl)))

        # Sort strictly descending by line index. For ops sharing the same index (multiple undef
        # blocks at one shared closing brace), order among them doesn't matter - all are pure
        # appends to that one line.
        ops.sort(key=lambda o: o[0], reverse=True)

        for line_idx, kind, payload in ops:
            if kind == 'undef':
                lines[line_idx] = lines[line_idx] + '\n' + payload
            else:
                last_line, new_decl = payload
                lines[line_idx:last_line+1] = [new_decl]

        with open(path, 'w') as f:
            f.write('\n'.join(lines))
        print(f"Applied {len(fixes)} fixes to {path}")

def decl_types_cast(t):
    # normalize a declared type into a valid cast target
    t = t.strip()
    if t in ('undefined4', 'undefined2', 'undefined1', 'undefined8'):
        return t
    return t

if __name__ == '__main__':
    main()
