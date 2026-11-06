#!/usr/bin/env python3
"""readonly_locals.py CORPUS_DIR  (issue #201)  - local arrays that the C only ever READS: `T name[N];` with no `name[i] = ..`, no `&name`, no bare `name`
(array decay: passed to a callee / stored / cast) anywhere in the function.  Such an array is either dead or a window onto memory the original wrote
through another pointer (the #216 case: `tempASelect[4]` was `tempA + 24`, the swizzle half of the operand ffvpAllocTempRegister fills through `tempA`) -
the rebuilt code then reads uninitialised stack.  Prints function, array, size, reads."""
import re, glob, sys
DECL = re.compile(r'^\s+(?:unsigned\s+)?(?:u?int|undefined\d?|float|double|short|ushort|byte|char|longlong|ulonglong|code)\s+(\w+)\s*\[\s*(\w+)\s*\];', re.M)
for f in sorted(glob.glob(sys.argv[1] + '/part_*.c')):
    t = open(f).read()
    for fm in re.finditer(r'(?m)^/\* (\S+) @ 0x[0-9a-f]+ .*?\*/\n(.*?)(?=^/\* \S+ @ 0x|\Z)', t, re.S):
        fn, body = fm.group(1), fm.group(2)
        for d in DECL.finditer(body):
            nm = d.group(1)
            rest = body[:d.start()] + body[d.end():]
            names = [nm]
            for dm in re.finditer(r'#define\s+(\w+)\s+' + re.escape(nm) + r'\[[^\]]*\]', body):      # Ghidra's `#define alias arr[k]` names
                names.append(dm.group(1))
            rest = re.sub(r'#define\s+\w+\s+' + re.escape(nm) + r'\[[^\]]*\][^\n]*\n', '\n', rest)
            idx_read = 0; other = 0
            for k, name in enumerate(names):
                for m in re.finditer(r'(?<![\w.>])' + re.escape(name) + r'\b', rest):
                    after = rest[m.end():m.end() + 64]; before = rest[max(0, m.start() - 24):m.start()]
                    if re.search(r'&\s*(\([^)]*\)\s*)?$', before): other += 1; continue          # &arr[i] / (T)&arr[i]: address taken
                    if k == 0:
                        im = re.match(r'\s*\[[^\]]*\]\s*(=(?!=)|[-+*/|&^]=|\+\+|--)?', after)
                        if im:
                            if im.group(1): other += 1
                            else: idx_read += 1
                        else: other += 1
                    else:                                                                       # alias of one element
                        im = re.match(r'\s*(=(?!=)|[-+*/|&^]=|\+\+|--)', after)
                        if im: other += 1
                        else: idx_read += 1
            if other == 0 and idx_read: print('%s\t%s\t%s\t%s[%s]\t%d reads' % (f.split('/')[-1], fn, nm, d.group(0).split()[0], d.group(2), idx_read))
