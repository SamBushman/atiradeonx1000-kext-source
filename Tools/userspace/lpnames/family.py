#!/usr/bin/env python3
"""family.py DIR RULES SPECOUT FN...

Run classwebs.py-style classification of EVERY placeholder variable of each FN with one shared RULES file (NAME<TAB>REGEX<TAB>EVIDENCE: REGEX is searched in the
right-hand side of each definition of a web; first rule matching all definitions wins).  For functions that share inlined code (same helper expanded in
each) a rule set written once names the same role in all of them.  Appends `VAR<TAB>webs<TAB>NAME<TAB>INFERRED<TAB>EVIDENCE` per FN to SPECOUT.<FN>
(feed to emit_webs.py) and prints what is left unclassified per variable."""
import sys, os, re, subprocess
here = os.path.dirname(os.path.abspath(__file__))
d, rules, out = sys.argv[1:4]
PH = re.compile(r'^(?:[a-z]{0,3}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|param_\d+|in_[a-z0-9]+|[a-z]?Stack_[0-9a-f]+|extraout_\w+)$')
for fn in sys.argv[4:]:
    ph = subprocess.run([sys.executable, os.path.join(here, 'ph.py'), d, fn], capture_output=True, text=True).stdout
    vars_ = []
    for l in ph.splitlines():
        if l.startswith(fn + ':'):
            for t in l.split(':', 1)[1].split():
                v = t.rsplit('*', 1)[0]
                if PH.match(v): vars_.append(v)
    spec = '%s.%s' % (out, fn)
    if os.path.exists(spec): os.remove(spec)
    for v in vars_:
        r = subprocess.run([sys.executable, os.path.join(here, 'classwebs.py'), d, fn, v, rules, spec], capture_output=True, text=True)
        left = [l for l in r.stdout.splitlines() if l.startswith('unhandled')]
        print('%s %s %s' % (fn, v, left[0] if left else r.stderr[-120:]))
