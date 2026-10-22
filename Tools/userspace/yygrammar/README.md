# yygrammar - recover yyparse's grammar from the bison tables

Run in this directory: `GLPROG_DYLIB=<libGLProgrammability.dylib> python3 -I tables.py` (writes tables.json), `python3 -I grammar.py` (rebuilds the LALR automaton, g.pkl),
`python3 -I verify.py` (checks `rules.py` - the 3Dlabs glslang.y rules in bison numbering - against yyr1/yyr2 and the automaton), `python3 -I mknotes.py`
(writes Userspace/libGLProgrammability/ppc/notes_yyparse_grammar.md). `gl.py` is the token list (3Dlabs order plus the two ATI rect samplers).
