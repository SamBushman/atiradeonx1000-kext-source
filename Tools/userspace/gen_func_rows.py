#!/usr/bin/env python3
"""gen_func_rows.py DIR > DIR/names_F1_func.tsv - `func` rows (Tools/userspace/apply_names.py) for the functions of the GLDriver corpus that its embedded C++ RTTI identifies.

Inputs: DIR/class_methods.tsv (fork R2b: every function that stores a class vtable or sits in a vtable slot, from the binary's typeinfo/vtables; see
DIR/notes_compiler_ir.md) and the corpus text DIR/part_*.c.

A row is emitted only when the corpus text of the function confirms the table:
  ctor / dtor / deleting dtor   the vtable pointer is stored at `*<first parameter>` (not into some other object the function builds), and the stored
                                value is a vtable (`&PTR_FUN_<slot0>` or `PTR_DAT_<nl_symbol_ptr> + 8`)
  virtual slot N                the vtable table lists the function in slot N of that class (class_methods.tsv 'evidence' says so)
  pass entry                    the function passes a string literal to FUN_000ed7e4(program, "name") (the pass-begin call), and is one of the
                                functions fork R2b identified as pass entries (notes_compiler_ir.md section 6)
Names: `Class__ctor`, `Class__dtor`, `Class__deleting_dtor`, `Class__clone` (Block-family slot 2), `Class__vslotN`, `pass_<name>`. A (class, role) that occurs in
more than one function gets the address as a suffix on every member (`Class__ctor_e9d68`) - the constructor variants (copy, default, ...) are not told apart.
Slot 0/1 of a vtable are the complete and the deleting destructor (GCC 4 layout). Tiers: CONFIRMED where the table and the corpus text agree and the
role is fixed by the ABI (vtable store, slots 0/1); INFERRED for `clone` and `pass_*` (their meaning is read from behaviour / a string)."""
import re, sys, os, glob

d = sys.argv[1]
IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]*$')
rows = [l.rstrip('\n').split('\t') for l in open(os.path.join(d, 'class_methods.tsv'))][1:]
BLOCK = set()
for r in rows:       # Block family: slot 2 is the clone factory (R2b section 4.1)
    pass

# function text by name
text = {}
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    cur, buf = None, []
    for l in open(pf).read().split('\n'):
        m = re.match(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\) \*/$', l)
        if m:
            if cur: text[cur] = '\n'.join(buf)
            cur, buf = m.group(1), []
        elif cur: buf.append(l)
    if cur: text[cur] = '\n'.join(buf)


def first_param(t):
    m = re.search(r'^\w[\w \*]*?\s\**(\w+)\(([^)]*)\)', t, re.M)
    # K&R: `int FUN_x(this, param_2)` -> first parameter name
    m = re.search(r'^[^\n(]*\(([A-Za-z_]\w*)', t, re.M)
    return m.group(1) if m else None


VT = r'(?:&PTR_FUN_[0-9a-f]+|PTR_DAT_[0-9a-f]+\s*\+\s*8|\(undefined \*\)&PTR_FUN_[0-9a-f]+|puVar\w+|[A-Za-z_]\w*)'


def stores_vtable_at_this(t, p):
    # `*this = &PTR_FUN_...;` or `*this = puVar1;` right after `puVar1 = PTR_DAT_xxx + 8;`
    for m in re.finditer(r'^\s*\*\(?[a-z ]*\**\)?\s*%s\s*=\s*([^;]+);' % re.escape(p), t, re.M):
        v = m.group(1).strip()
        if re.match(r'(\(undefined \*\*?\))?&PTR_FUN_[0-9a-f]+$', v): return True
        if re.match(r'(\(undefined \*\)\s*)?PTR_DAT_[0-9a-f]+\s*\+\s*8$', v): return True
        if re.match(r'[A-Za-z_]\w*$', v) and re.search(r'^\s*%s\s*=\s*(PTR_DAT_[0-9a-f]+\s*\+\s*8|&PTR_FUN_[0-9a-f]+)' % re.escape(v), t, re.M): return True
    return False


cand = []
for addr, name, cls, role, ev in rows:
    if not name.startswith('FUN_') or not IDENT.match(cls): continue
    t = text.get(name)
    if t is None: continue
    cand.append((addr, name, cls, role, ev, t))

items = []        # (old, class, rolekey, tier, evidence)
skipped = {}
for addr, name, cls, role, ev, t in cand:
    slot = re.search(r'virtual-slot(\d+)', role)
    p = first_param(t)
    if role == 'ctor': key, tier = 'ctor', 'CONFIRMED'
    elif role == 'deleting-dtor': key, tier = 'deleting_dtor', 'CONFIRMED'
    elif role.startswith('dtor'): key, tier = 'dtor', 'CONFIRMED'
    elif slot and slot.group(1) == '0': key, tier = 'dtor', 'CONFIRMED'
    elif slot and slot.group(1) == '1': key, tier = 'deleting_dtor', 'CONFIRMED'
    elif slot and slot.group(1) == '2' and re.search(r'Block\[2\]|AnyBlock|IfHeader|IfFooter|Loop|Break|Continue|FuncEnd|Exit|Entry|Mirror', cls + ev): key, tier = 'clone', 'INFERRED'
    elif slot: key, tier = 'vslot' + slot.group(1), 'UNKNOWN'
    else: skipped.setdefault('role ' + role, []).append(name); continue
    if key in ('ctor', 'dtor', 'deleting_dtor') and 'vtable slot of' not in ev:
        if not (p and stores_vtable_at_this(t, p)):
            skipped.setdefault('no vtable store at *first-parameter (%s)' % key, []).append(name); continue
    slotm = re.search(r'vtable slot of ([A-Za-z0-9_]+)\[', ev)
    inslot = bool(slot) or bool(slotm and key in ('dtor', 'deleting_dtor') and re.search(r'\[%d\]' % (0 if key == 'dtor' else 1), ev))
    if slot and slotm: cls = slotm.group(1)       # a slot function shared by derived classes belongs to the first (base-most) class listed
    items.append((name, cls, key, tier, ev, int(addr, 16), inslot))

grp = {}
for name, cls, key, tier, ev, a, inslot in items: grp.setdefault((cls, key), []).append((name, inslot))
out, newnames = [], {}
for name, cls, key, tier, ev, a, inslot in items:
    base = '%s__%s' % (cls, key)
    g = grp[(cls, key)]
    slots = [n for n, i in g if i]
    plain = (inslot and len(slots) == 1) or (not slots and len(g) == 1)      # the vtable-slot function of a class is THE dtor / deleting dtor; other variants carry their address
    new = base if plain else '%s_%x' % (base, a)
    if new in newnames: skipped.setdefault('duplicate new name', []).append(name); continue
    newnames[new] = name
    if key.startswith('vslot'): ev2 = 'vtable of %s slot %s (R2b class_methods.tsv: %s)' % (cls, key[5:], ev)
    elif key == 'clone': ev2 = 'Block-family vtable slot 2: allocates a block of the same class from the compiler arena and copy-constructs it (notes_compiler_ir.md 4.1); name is ours'
    elif key in ('dtor', 'deleting_dtor') and 'vtable slot of' in ev: ev2 = 'vtable slot %d of %s = %s (GCC 4 layout); %s' % (0 if key == 'dtor' else 1, cls, 'complete destructor' if key == 'dtor' else 'deleting destructor', ev)
    elif key == 'deleting_dtor': ev2 = 'stores the %s vtable at *this and ends in operator delete (deleting destructor); %s' % (cls, ev)
    else: ev2 = 'stores the %s vtable at *this (%s); %s' % (cls, key, ev)
    out.append(('func', name, new, tier, ev2))

# pass entries (R2b notes section 6) - only if the function itself passes the literal to the pass-begin function
PASSES = {'FUN_001214fc': ['ssa_build'], 'FUN_0012ab80': ['optimize_control_flow'], 'FUN_0012ccc0': ['loop_trans'], 'FUN_0012d2f0': ['flatten_ifs'],
          'FUN_001300b0': ['remove_empty_graphs'], 'FUN_00135fb0': ['color_graph'], 'FUN_0013d160': ['rewrite'], 'FUN_00145670': ['post_pack_insts'],
          'FUN_00171714': ['sched_preprocess', 'schedule_inst'], 'FUN_00184ab4': ['minreg_order']}
done = {o[1] for o in out}
for fn, lits in PASSES.items():
    t = text.get(fn)
    if t is None or fn in done: continue
    if not all(re.search(r'FUN_000ed7e4[^;]*"%s"' % re.escape(l), t) for l in lits):
        skipped.setdefault('pass literal not in function', []).append(fn); continue
    new = 'pass_' + '_and_'.join(lits)
    if new in newnames: continue
    newnames[new] = fn
    out.append(('func', fn, new, 'INFERRED', 'calls the pass-begin function FUN_000ed7e4(program, %s) with the literal(s) %s (R2b notes_compiler_ir.md section 6); the name is the pass string' % (' / '.join('"%s"' % l for l in lits), ', '.join(lits))))

print('# func rows for Userspace/ATIRadeonX1000GLDriver/ppc (Tools/userspace/gen_func_rows.py); func<TAB>old<TAB>new<TAB>tier<TAB>evidence')
for r in sorted(out, key=lambda r: r[1]): print('\t'.join(r))
sys.stderr.write('%d func rows; skipped: %s\n' % (len(out), {k: len(v) for k, v in skipped.items()}))
