"""Hand fixes for the few functions whose Ghidra text the mechanical rewrites cannot make compile or print correctly (issue #71).

Each entry maps a function name to f(raw, converted) -> final text; `raw` is Ghidra's (K&R-converted) text, `converted` is the mechanical result.

Rules every patch follows:
  * it carries a comment naming the stock instructions it was derived from (address range in the stock binary) and the equivalent C;
  * it is CHECKED: every substitution must find its pattern exactly the expected number of times, otherwise `PatchError` stops the corpus
    build (Ghidra's variable names shift between decompiler runs, so a pattern that silently stopped matching would leave the old, wrong
    call in the corpus);
  * it is SCOPED to the binary whose function it is (`CORPUS_SCOPE`, set by build_corpus.py / verify_corpus.sh from the slice file name):
    `FUN_<addr>` names exist in several binaries, and an unscoped patch would fire (or fail) in the wrong one.

Scopes: glprog = libGLProgrammability.dylib (ppc), gld = ATIRadeonX1000GLDriver.bundle (ppc), gld-i386 = its i386 slice (dump not archived,
patch not exercised by the current pipeline), ga / va / libgl = the other ppc images.
"""
import re


class PatchError(Exception):
    pass


def scope_of_slice(path):
    """Corpus scope of a Mach-O slice file name (`ATIRadeonX1000GLDriver.bundle.bin.ppc`, `libGL.dylib`, ...)."""
    n = path.rsplit('/', 1)[-1]
    arch = 'i386' if n.endswith('.i386') else 'ppc'
    for key, sc in (('libGLProgrammability', 'glprog'), ('GLDriver', 'gld'), ('VADriver', 'va'), ('GA.plugin', 'ga'), ('libGL.dylib', 'libgl')):
        if key in n:
            return sc + ('-i386' if arch == 'i386' else '')
    return None


def _subs(text, subs, what):
    """Apply (old, new[, count]) substitutions; each `old` must occur exactly `count` (default 1) times."""
    for s in subs:
        old, new = s[0], s[1]
        n = s[2] if len(s) > 2 else 1
        got = text.count(old)
        if got != n:
            raise PatchError('%s: pattern %r found %d time(s), expected %d' % (what, old[:100], got, n))
        text = text.replace(old, new)
    return text


def _re_subs(text, pat, repl, n, what):
    text, got = re.subn(pat, repl, text)
    if got != n:
        raise PatchError('%s: regex %r matched %d time(s), expected %d' % (what, pat[:100], got, n))
    return text


def _raw_with(what, subs):
    return lambda raw, conv: _subs(raw, subs, what)


def _conv_with(what, subs):
    return lambda raw, conv: _subs(conv, subs, what)


def _scoped(scope, fn):
    fn.scope = scope
    return fn


# --- yyparse (glprog, stock 0x97ba373c, 34436 bytes) -------------------------------------------------------------------------------
# Two calls of vector<TTypeLine>::_M_insert_aux(this, position, &value) that Ghidra printed with no arguments (the callee is an import whose
# demangled signature takes iterator/reference objects by value). Registers at the `bl` are read from the machine code:
#   site 1, `bl _M_insert_aux` at 0x97baac74 (window 0x97baac34..0x97baac74):
#       r3 = vector (V), r4 = *(V+8) = the insert position, r5 = *(*(r24+0x10)+4) + r25   [0x97baac38 lwz r2,0x10(r24); 0x97baac40 lwz r2,4(r2);
#       0x97baac44 add r5,r2,r25]. r24 is the parser stack frame P, r25 the running index I; the value being inserted is the TTypeLine at
#       *(P[4] + 4) + I.  C:  insert_aux(V, pos, *(int *)(P[4] + 4) + I)
#   site 2, `bl _M_insert_aux` at 0x97baadfc (window 0x97baadb8..0x97baadfc):
#       r3 = vector (*(r30+0x2480)), r4 = *(r3+8) = the position, r5 = r24 + 0x10 = &P[4] [0x97baadbc addi r5,r24,0x10].
#       C:  insert_aux(V, pos, &P[4])
# P (r24) and I (r25) get a different Ghidra name in every decompile, so the pattern is structural; both sites assert.
# (RETIRED 2026-09-25 - see the note in PATCHES; the derivation above is kept as the record of what the machine code passes.)


# --- TIntermediate::removeChildNode (glprog) -------------------------------------------------------------------------------------
# (a) removeChildNode(TVector&, TType&, int&, iterator&, TIntermAggregate*), stock 0x97b964e8: `bl vector<TIntermNode*>::erase(iterator)` at 0x97b967e8.
#     Window 0x97b967dc..0x97b967e8: r5 = *(r27+4) + index*4 (`lwz r5,4(r27); add r5,r5,r0`), stored through the iterator argument
#     (`stw r5,0(r25)` at 0x97b967e4); r3 = &result, r4 = this. erase(&result, this, position) with position = *param_5.
# (b) removeChildNode(TIntermTyped*, TType*, TIntermAggregate*), stock 0x97b96820: `bl _M_insert_aux(this, pos, &value)` at 0x97b96938.
#     Window 0x97b968fc..0x97b96938: r3 = this (r30), r4 = pos (r2 = *(r30+8)), r5 = *(r3_result + 4) [0x97b96904 lwz r5,4(r3): the element the else
#     branch copies, `*(iVar3 + 4)` in the decompile]. (The second insert_aux call of this function, 0x97b969a8, has r5 = r11 + r9 computed at
#     0x97b9697c and was already printed correctly.)  C:  insert_aux(this, pos, *(int *)(iVar3 + 4))
# (RETIRED 2026-09-25 - see the note in PATCHES.)

# --- std::operator+(const char*, const string&) on pool strings (glprog, stock 0x97c32b88) ------------------------------------------
# `s + t` = append: replace(end(), end(), t, t + strlen(t)). Ghidra passed the pool allocator (uVar6) as the object of the two `replace` calls; the
# machine code passes the string being built: the calls at 0x97c32c94 and 0x97c32cb4 each have `or r3,r27,r27` immediately before (0x97c32c90 /
# 0x97c32cb0), and r27 = param_1 (`or r27,r3,r3` at 0x97c32b9c).  C:  replace(param_1, ...)  instead of  replace(uVar6, ...)
# RETIRED (issue #71): the wrong object was a symptom of the by-value iterator/tag parameters of the _M_replace/_M_replace_safe callees (Ghidra's
# "Heritage AFTER dead removal" at the call). With those parameters flattened in the analysed copy (gs/FlattenStructParams.java) the re-decompile
# passes param_1 itself, so the patch no longer applies and is not needed.

# --- 4-byte constructor aliases (glprog) ------------------------------------------------------------------------------------------
# `__ZNSsC2IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE` (stock 0x97c16984) and the `PKc` variant (0x97c169dc): each is one `b <C4 ctor>`
# (a C2 -> C4 forwarder, 4 bytes, no prologue), so r3..r6 - the object and the constructor's own arguments - are passed through untouched.
# C: forward this, param_2, param_3, param_4 to the C4 constructor.
# (RETIRED 2026-09-25 - see the note in PATCHES.)


def _body(what, body, decl_subs=()):
    """Replace the whole function body (from the first `{` line) with `body`; `decl_subs` fix K&R parameter declarations first."""
    def f(raw, conv):
        conv = _subs(conv, decl_subs, what)
        k = conv.find('\n{\n')
        if k < 0:
            raise PatchError('%s: no body' % what)
        return conv[:k + 1] + body
    return f


# --- the private C++ unwinder's three entry points (glprog) -------------------------------------------------------------------------
# _Unwind_RaiseException (stock 0x97c1bb6c), _Unwind_ForcedUnwind (0x97c1bd8c), _Unwind_Resume (0x97c1be20) are libgcc's unwind.inc (gcc 4.0), compiled
# with __builtin_unwind_init and __builtin_eh_return: the prologue is `li r11,-frame; bl save_world` (the millicode saves every register and makes the
# frame), the exit is `b eh_rest_world_r10` with r10 = the stack adjustment and the handler address stored in the LR slot (0x968(r1) / 0x5b8(r1)).
# Ghidra cannot see the frame save_world creates: the decompile addressed the locals at entry-sp + x (STACKARG, in_stack_), i.e. inside the CALLERS'
# frames, and called save_world / eh_rest_world_r10 as ordinary functions - the rebuilt _Unwind_RaiseException passed a garbage context and died
# (SIGBUS in uw_init_context_1, Tests/userspace/eh_test.cpp). The bodies below are that source, field offsets read from the machine code:
#   context 0x1d8 bytes (memcpy 0x1d8 at 0x97c1bbac), its return address at +0x1c0 (uw_init_context_1 0x97c1b79c; 0x3e0(r1) = cur + 0x1c0);
#   fs.personality at +0x390 (0x790(r1), fs at 0x400(r1)); personality(1, _UA_SEARCH_PHASE, exception_class (r5:r6), exc, &cur) at 0x97c1bbdc..0x97c1bbf8;
#   6 = _URC_HANDLER_FOUND, 8 = _URC_CONTINUE_UNWIND, else 3 = _URC_FATAL_PHASE1_ERROR; uw_frame_state_for 5 = _URC_END_OF_STACK;
#   private_1 / private_2 = exc + 0xc / + 0x10 (0 and cur.ra = uw_identify_context, 0x97c1bc34..0x97c1bc38); Phase2 result 7 = _URC_INSTALL_CONTEXT,
#   then uw_install_context_1(&this, &cur) is the offset and cur.ra the handler (0x97c1bc6c..0x97c1bc84); ForcedUnwind stores stop / stop_argument
#   (0x97c1bde4 / 0x97c1bdec); Resume picks the phase-2 routine by private_1 == 0 (0x97c1be68) and aborts unless it returns 7 (0x97c1be98).
# The compiler generates the save_world / eh_rest_world_r10 calls itself (link_config glprog.json drops the stock copies as toolchain millicode).
_UW_LOCALS = """  double this_context[0x1d8 / 8], cur_context[0x1d8 / 8];
  double fs[0x3d0 / 8];
  long offset;
  int code;
"""
_UW_INIT = """  __builtin_unwind_init();
  ((int (*)())_uw_init_context_1)(this_context, __builtin_dwarf_cfa(), __builtin_return_address(0));
  _memcpy(cur_context, this_context, 0x1d8);
"""
_UW_INSTALL = """  offset = ((int (*)())_uw_install_context_1)(this_context, cur_context);
  __builtin_eh_return(offset, __builtin_frob_return_addr(*(void **)((char *)cur_context + 0x1c0)));
"""
_UW_RAISE = "{\n" + _UW_LOCALS + _UW_INIT + """  while (1) {
    void *pers;
    code = ((int (*)())_uw_frame_state_for)(cur_context, fs);
    if (code == 5) return 5;
    if (code != 0) return 3;
    pers = *(void **)((char *)fs + 0x390);
    if (pers != 0) {
      code = ((int (*)(int, int, unsigned long long, void *, void *))pers)(1, 1, exception_object->exception_class, exception_object, cur_context);
      if (code == 6) break;
      if (code != 8) return 3;
    }
    ((int (*)())_uw_update_context)(cur_context, fs);
  }
  exception_object->private_1 = 0;
  exception_object->private_2 = *(unsigned long *)((char *)cur_context + 0x1c0);
  _memcpy(cur_context, this_context, 0x1d8);
  code = ((int (*)())__Unwind_RaiseException_Phase2)(exception_object, cur_context);
  if (code != 7) return code;
""" + _UW_INSTALL + "}\n"
_UW_FORCED = "{\n" + _UW_LOCALS + _UW_INIT + """  exception_object->private_1 = (unsigned long)stop;
  exception_object->private_2 = (unsigned long)stop_parameter;
  code = ((int (*)())__Unwind_ForcedUnwind_Phase2)(exception_object, cur_context);
  if (code != 7) return code;
""" + _UW_INSTALL + "}\n"
_UW_RESUME = "{\n" + _UW_LOCALS + _UW_INIT + """  if (exception_object->private_1 == 0)
    code = ((int (*)())__Unwind_RaiseException_Phase2)(exception_object, cur_context);
  else
    code = ((int (*)())__Unwind_ForcedUnwind_Phase2)(exception_object, cur_context);
  if (code != 7) _abort();
""" + _UW_INSTALL + "}\n"


def _fix_two_empty_cases(conv):
    n = conv.count('case "":')
    if n != 2:
        raise PatchError('FUN_000cea6c (0xcea6c): expected 2 `case "":` labels, found %d' % n)
    # the range test in front of the switch is the same constant: `cmplwi cr7,r9,0x5; bgt` sends 6..15 to the `?` case, Ghidra printed `pcVar4 < ""` (the zero
    # byte at header address 6). Compiled, the test was always true and the `?` name was never written (found by the pure-function fuzz)
    if conv.count('if (pcVar4 < "") {') != 1:
        raise PatchError('FUN_000cea6c (0xcea6c): expected one `if (pcVar4 < "") {`')
    return conv.replace('case "":', 'case 4:', 1).replace('case "":', 'case 5:', 1).replace('if (pcVar4 < "") {', 'if ((uint)pcVar4 < 6) {', 1)


PATCHES = {
    # RETIRED 2026-09-25 (issue #71): yyparse (both TTypeLine _M_insert_aux sites), removeChildNode#1 (erase), removeChildNode#2 (_M_insert_aux) and the
    # two C2 -> C4 constructor aliases. Each dropped/misplaced argument was a symptom of the callee's by-value iterator / tag parameters (a
    # `__normal_iterator` struct, a 1-byte `forward_iterator_tag` with UNASSIGNED storage), which make the decompiler lose the argument registers.
    # With those parameters flattened to undefined4 in the analysed copy (gs/FlattenStructParams.java, all 148 such functions) the re-decompile
    # prints exactly the registers these patches derived from the machine code (checked site by site against the windows documented above:
    # yyparse site 1 `*(P[4] + 4) + I`, site 2 `P + 4`; erase's third argument = the position just stored through param_5; insert_aux's
    # `*(iVar3 + 4)`; the aliases forward this, param_2..param_4), so the patches no longer apply and are not needed.
    # yy_flex_alloc / yy_flex_realloc / yy_flex_free (glprog, stock 0x97baddd0 / 0x97baddd4 / 0x97baddd8, 4 bytes each): one `b <stub>` - a tail call of
    # the libSystem stub for _malloc / _realloc / _free (stock.dis: `b 0x97c1e0c0 ; symbol stub for: _malloc`, `b 0x97c1e020 ; _realloc`, `b 0x97c1e0a0 ;
    # _free`), so the caller's r3 (r4) are the callee's arguments and its result is the return value. Ghidra printed each as `(*(code *)PTR_LAB_...)();`
    # - a call through the lazy pointer with NO arguments and no return value (issue #67; found by scanning the corpora for argument-less calls through
    # code pointers). It only worked at -O0 because nothing happened to clobber r3 between the prologue and the call. PTR_LAB_a7b7c1c8 / ...b4 / ...c4 are
    # the __la_symbol_ptr slots of _malloc / _realloc / _free (link/symbol_map.tsv). C: call the import by name, pass the arguments, return the result.
    'yy_flex_alloc': _scoped('glprog', lambda raw, conv: _re_subs(conv, r'\(\*\(code \*\)PTR_LAB_a7b7c1c8\)\([^;]*\);\n  return;', 'return _malloc(param_1);', 1, 'yy_flex_alloc (0x97baddd0)')),
    'yy_flex_realloc': _scoped('glprog', lambda raw, conv: _re_subs(conv, r'\(\*\(code \*\)PTR_LAB_a7b7c1b4\)\([^;]*\);\n  return;', 'return _realloc(param_1,param_2);', 1, 'yy_flex_realloc (0x97baddd4)')),
    'yy_flex_free': _scoped('glprog', lambda raw, conv: _re_subs(conv, r'\(\*\(code \*\)PTR_LAB_a7b7c1c4\)\([^;]*\);\n  return;', 'return _free(param_1);', 1, 'yy_flex_free (0x97baddd8)')),

    # yyparse (glprog, stock 0x97ba373c): bison's stack growth uses alloca (`yyss = alloca(..)` / `yyvs = alloca(..)`, each `stwux r1,r1,rN` + a copy of
    # the back chain). Ghidra models r1 as a plain variable (puVar4 = entry-sp - 0x2cf0, then puVar4 -= size), so the recompile "allocated" the two new
    # stacks in the memory below its own real sp, where the next call's frame (yylex...) overwrote them: a shader nested more than 200 levels deep
    # (`e_deep_parens`: 176 parentheses grow the 200-entry stack) crashed in yyparse. Real alloca instead. The same variable is the base of the
    # outgoing stack-argument words (`puVar4[0xe..0x10]` = 0x38+(r1) words of the 11-argument call of arrayErrorCheck): a local array holds them,
    # not the memory at a guessed offset in the frame.
    'yyparse': _scoped('glprog', lambda raw, conv: _subs(conv, [
        ('  undefined4 *puVar4;\n', '  undefined4 *puVar4;\n  undefined4 yy_outargs[0x14];\n'),
        ('  puVar4 = (undefined4 *)&STACKARG(0xffffd310);\n', '  puVar4 = yy_outargs;\n'),
        ('      puVar18 = (undefined4 *)((int)puVar4 - ((uint)(local_60 + 0x1e) & 0xfffffff0));\n      *puVar18 = *puVar4;\n', ''),
        ('      pTVar7 = (unsigned char *)(puVar18 + 0x14);\n', '      pTVar7 = (unsigned char *)__builtin_alloca((uint)local_60 + 0x40);\n'),
        ('      puVar4 = (undefined4 *)((int)puVar18 - ((int)pTVar41 * 0x2c + 0x1eU & 0xfffffff0));\n      *puVar4 = *puVar18;\n      pTVar3 = (unsigned char *)(puVar4 + 0x14);\n',
         '      pTVar3 = (unsigned char *)__builtin_alloca((int)pTVar41 * 0x2c + 0x40);\n')], 'yyparse (0x97ba373c)')),

    # TGenericLinker::GetBindingTableString (glprog, stock 0x97bb4894): the second sprintf has SEVEN variadic arguments; the seventh is a stack argument
    # (`stw r23,0x38(r1)` before the call at 0x97bb495c: r23 = the tables string GetString(3)). The call-site override (OverrideVariadicCalls) gives it
    # Ghidra's SysV stack slot, so the decompile read an uninitialised local `in_stack_ffffff88` and the rebuilt binding table stopped after the uniform
    # count ("No Client Attribute Requests", the attribute / uniform binding lists were missing: GLSL differential v_builtin_vars).
    'TGenericLinker__GetBindingTableString': _scoped('glprog', _conv_with('TGenericLinker::GetBindingTableString (0x97bb4894)', [('a5,in_stack_ffffff88);', 'a5,uVar1);')])),

    # --- data symbols Ghidra typed inconsistently (word index in one function, byte offset in another) -----------------------------------
    # _gPollAllocThreadData (glprog, data 0xa7b7ba1c) is a pointer to an 8-byte record { TPoolAllocator *pool; int; } (InitializeGlobalPools, stock
    # 0x97b9fe54: `bl operator new(8); stw r30,4(r3); stw r3,0(r28); stw r29,0(r3)` - word stores at +0 and +4). The corpus declares it `unsigned char *`
    # (build_corpus.py's default for a dereferenced undeclared name), so `*p`, `p[1] = 0` compiled to BYTE accesses: GetGlobalPoolAllocator returned the low
    # byte of the pool pointer and the rebuilt ShInitialize crashed inside TPoolAllocator::allocate (found by the GLSL differential test, issue #67/#70).
    # The declaration is now `unsigned int *` (EXTRA_DECL_FIXES in build_corpus.py); the one byte-offset use keeps its byte meaning:
    # GetCompilerPoolAllocator (0x97b9ff94): `lwz r3,slot; addi r3,r3,4; blr` = the address of the second word, p + 4 BYTES.
    'GetCompilerPoolAllocator': _scoped('glprog', _conv_with('GetCompilerPoolAllocator (0x97b9ff94)', [
        ('return _gPollAllocThreadData + 4;', 'return (int)((unsigned char *)_gPollAllocThreadData + 4);')])),
    # _yy_current_buffer (glprog) is a YY_BUFFER_STATE pointer, declared `unsigned char *` so the byte-offset uses (`*(int *)(_yy_current_buffer + 0xc)`) are
    # right; yy_load_buffer_state (stock 0x97bad9fc) is printed with WORD indices (`_yy_current_buffer[4]`, `[2]`, `*`), which on a byte pointer read
    # bytes: stock `lwz r0,0x10(r11); lwz r10,8(r11); lwz r0,0(r11)` = yy_n_chars, yy_buf_pos, yy_input_file. C: explicit word loads at +0x10, +8, +0.
    'yy_load_buffer_state': _scoped('glprog', _conv_with('yy_load_buffer_state (0x97bad9fc)', [
        ('_yy_n_chars = _yy_current_buffer[4];', '_yy_n_chars = (unsigned char *)*(unsigned int *)(_yy_current_buffer + 0x10);'),
        ('_yy_c_buf_p = (undefined1 *)_yy_current_buffer[2];', '_yy_c_buf_p = (undefined1 *)*(unsigned int *)(_yy_current_buffer + 8);'),
        ('_yyin = *_yy_current_buffer;', '_yyin = *(void **)_yy_current_buffer;')])),

    # _InitAtomTable (glprog, stock 0x97b85da0): the single-character atoms. `stb r0,0x41(r1)` (NUL) and `stb r2,0x40(r1)` (the character), then
    # `addi r4,r1,0x40; bl _AddAtomFixed` (0x97b85e64..0x97b85e80): a two-byte STRING on the stack, its address passed to _AddAtomFixed, which reads it
    # up to the NUL. Ghidra printed it as two unrelated scalars (`char local_20; undefined1 local_1f;`); at -O0 they were not adjacent, so the string was
    # not terminated, _AddAtomFixed ran off it, overwrote the saved registers and the rebuilt InitPreprocessor crashed on return (found by the GLSL
    # differential test; the same class as the byte-buffer rewrites of `rewrites.py`). C: one array, the scalars are its elements.
    '_InitAtomTable': _scoped('glprog', _conv_with('_InitAtomTable (0x97b85da0)', [
        ('  char local_20;\n  undefined1 local_1f;\n', '  char local_20_str[2];\n#define local_20 local_20_str[0]\n#define local_1f local_20_str[1]\n'),
        ('  return uVar6;\n}', '  return uVar6;\n#undef local_20\n#undef local_1f\n}')])),

    # _str_ungetch (glprog, stock 0x97b88a8c) is ONE function, but Ghidra split it after its first instruction: the exported entry `lwz r2,0x18(r3)`
    # (the input source's cursor) is a clipped 4-byte entry and the rest became FUN_97b88a90, which reads that r2 (`lbz r0,-1(r2)`, `stb r0,0(r2)`)
    # as an uninitialised `unaff_r2`. Nothing enters 0x97b88a90 except by falling through from the entry (no branch or data word targets it), so the
    # register always holds the entry's load. Found when the rebuilt GLSL front end crashed in FUN_97b88a90 reading 0x1fffffff (issue #72).
    'FUN_97b88a90': _scoped('glprog', _conv_with('FUN_97b88a90 (0x97b88a8c entry)', [
        ('  undefined1 *unaff_r2;\n', '  undefined1 *unaff_r2 = *(undefined1 **)(param_1 + 0x18);   /* set by the entry _str_ungetch: lwz r2,0x18(r3) */\n')])),
    # _unlinkScope (glprog, stock 0x97b89f00): the same split. Entry `lwz r2,0(r3)` (scope->next), then FUN_97b89f04 tests and stores through that r2
    # (`cmpwi r2,0; ...; stw r0,4(r2)`); only reached by falling through from the entry.
    'FUN_97b89f04': _scoped('glprog', _conv_with('FUN_97b89f04 (0x97b89f00 entry)', [
        ('  int unaff_r2;\n', '  int unaff_r2 = (int)*param_1;   /* set by the entry _unlinkScope: lwz r2,0(r3) */\n')])),

    # GLDriver FUN_000a6f70 (stock 0xa6f70, 8 bytes): `li r4,1; b _calloc` - a tail call, so the function returns calloc's result in r3, and both
    # callers store it (0xb4960 `stw r3,0xc(r28)`, 0xb4acc `stw r3,0x10(r27)`; also installed as a function pointer at +0x24c). Ghidra prints the tail
    # call through the import stub as a void call even with a 4-byte return type committed (SetValueReturn.java), so the C returned nothing (issue #70).
    'FUN_000a6f70': _scoped('gld', _conv_with('FUN_000a6f70 (0xa6f70)', [('  _calloc(param_1,1);\n  return;\n', '  return (int)_calloc(param_1,1);\n')])),

    # The software vertex-program emulator's scalar built-ins in the coalesced text (GLDriver 0x1d05b0 cos, 0x1d0794 sin, 0x1d06ec rsqrt, 0x1d0820 sqrt; found by the
    # pure-function fuzz: FUN_001d06ec scaled by 1/sqrt(whatever f1 held)). Ghidra printed the libm calls - and, in sin / cos, the virtual call in front of them
    # (`lwz r3,0x30c(r6); lwz r2,0(r3); lwz r0,0xe0(r2); bctrl`: this = *(param_4 + 0x30c), the angle conversion) - WITHOUT their arguments: `lfs f1,4(r5)`
    # is the operand and reaches `bl _sqrt` / the virtual call in f1, the virtual call's double result is the operand of `bl _cos` / `bl _sin` (0x1d061c, 0x1d07fc).
    'FUN_001d05b0': _scoped('gld', _conv_with('FUN_001d05b0 (0x1d05b0)', [(
        '    (**(code **)(**(int **)(param_4 + 0x30c) + 0xe0))();\n    dVar1 = (double)_cos();',
        '    dVar1 = (double)_cos(((double (*)(int, double))*(code **)(**(int **)(param_4 + 0x30c) + 0xe0))(*(int *)(param_4 + 0x30c), (double)*(float *)(param_3 + 4)));')])),
    'FUN_001d0794': _scoped('gld', _conv_with('FUN_001d0794 (0x1d0794)', [(
        '    (**(code **)(**(int **)(param_4 + 0x30c) + 0xe0))();\n    dVar1 = (double)_sin();',
        '    dVar1 = (double)_sin(((double (*)(int, double))*(code **)(**(int **)(param_4 + 0x30c) + 0xe0))(*(int *)(param_4 + 0x30c), (double)*(float *)(param_3 + 4)));')])),
    'FUN_001d06ec': _scoped('gld', _conv_with('FUN_001d06ec (0x1d06ec)', [('dVar2 = (double)_sqrt();', 'dVar2 = (double)_sqrt((double)*(float *)(param_3 + 4));')])),
    'FUN_001d0820': _scoped('gld', _conv_with('FUN_001d0820 (0x1d0820)', [('dVar2 = (double)_sqrt();', 'dVar2 = (double)_sqrt((double)*(float *)(param_3 + 4));')])),

    # TIntermSymbol::traverse(TIntermTraverser*) (glprog, stock 0x97b97d40, 20 bytes): `lwz r12,0(r4); cmpwi r12,0; beqlr; mtspr ctr,r12; bctr` - a tail
    # call of the traverser's visitSymbol callback (*(traverser+0)) with r3 = this (the symbol) and r4 = the traverser, both untouched. Ghidra printed
    # `(**(code **)param_2)();` with no arguments (found by the tiny-function scan of issue #67/#70). C: pass (this, param_2).
    # (The indirect-call override of Stage B3 prints the tail call with `this` only - the decompiler applies a tail jump's override to r3 alone - so the
    # patch stays, matching any argument list.)
    'TIntermSymbol__traverse': _scoped('glprog', lambda raw, conv: _re_subs(conv, r'\(\*\*\(code \*\*\)param_2\)\([^;]*\);', '(**(code **)param_2)(this,param_2);', 1, 'TIntermSymbol::traverse (0x97b97d40)')),

    # __cxxabiv1::__terminate / __unexpected (glprog, stock 0x97c19de8 / 0x97c19e44): `mtspr ctr,r3; bctrl` (0x97c19df4..0x97c19dfc) calls the handler
    # passed in r3. Ghidra typed the handler as a plain byte pointer; C: call it as a function pointer.
    # the private unwinder's entry points: see _UW_RAISE above (ForcedUnwind's `stop` is a function pointer - stock stores the whole r4, 0x97c1bde4 -
    # Ghidra typed it `unsigned char`)
    '__Unwind_RaiseException': _scoped('glprog', _body('_Unwind_RaiseException (0x97c1bb6c)', _UW_RAISE)),
    '__Unwind_ForcedUnwind': _scoped('glprog', _body('_Unwind_ForcedUnwind (0x97c1bd8c)', _UW_FORCED, (('  unsigned char stop;\n', '  void *stop;\n'),))),
    '__Unwind_Resume': _scoped('glprog', _body('_Unwind_Resume (0x97c1be20)', _UW_RESUME)),
    # _InterpreterEmulateOp (glprog, stock 0x97bcdd50): the noise() opcodes call _InterpreterNoiseGeneratorCalculate1D..4D(state, in, out) with
    # `addi r3,r23,4; addi r4,r1,0x70; addi r5,r1,0x60; bl` (0x97bd0b98..0x97bd0be0). The decompiler shows r4 as `local_130 + 4` (local_130 is the
    # float[12] at r1+0x60) but prints r5 as the function's own untouched `in_r5` - it loses that `addi` (it does so for these four sites only;
    # callarg_check.py, stack-address arguments). C: the output is `local_130` itself.
    '_InterpreterEmulateOp': _scoped('glprog', lambda raw, conv: _re_subs(conv, r'(_InterpreterNoiseGeneratorCalculate[1-4]D\)?\s*\(param_1 \+ 1,local_130 \+ 4,)in_r5\)', r'\1local_130)', 4, '_InterpreterEmulateOp noise output (0x97bd0ba0..)')),
    '__cxxabiv1____terminate': _scoped('glprog', lambda raw, conv: _re_subs(conv, r'\(\*param_1\)\(([^;]*)\);', r'((int (*)())param_1)(\1);', 1, '__terminate (0x97c19de8)')),
    '__cxxabiv1____unexpected': _scoped('glprog', lambda raw, conv: _re_subs(conv, r'\(\*param_1\)\(([^;]*)\);', r'((int (*)())param_1)(\1);', 1, '__unexpected (0x97c19e44)')),

    # TIntermAggregate::addToPragmaTable (glprog, stock 0x97b96d18): `bl std::_Rb_tree<...>::operator=(const _Rb_tree&)` at 0x97b96db8.
    # The sanitiser keeps the `=` of a templated `operator=`, so the call read as an assignment (call lost). C: a call to that operator= with
    # (this, other), which is the r3/r4 the stock passes.
    'TIntermAggregate__addToPragmaTable': _scoped('glprog', lambda raw, conv: _re_subs(
        conv, r'\b(std___Rb_tree_\w+_operator)=\(', r'\1_(', 1, 'addToPragmaTable (0x97b96d18)')),

    # ___initialize_Cplusplus (glprog, stock 0x97b85418): `bl __dyld_func_lookup(name, &out)` at 0x97b8543c leaves the looked-up address in the
    # stack slot 0x38(r1); `lwz r12,0x38(r1); cmpwi r12,0; beq; ...; mtspr ctr,r12; bctrl` (0x97b85440..0x97b85458) calls it when non-null.
    # C: cast the out-parameter word to a function pointer and call it.
    '___initialize_Cplusplus': _scoped('glprog', _conv_with('___initialize_Cplusplus (0x97b85418)', [
        ('(*uStack_28)(', '((int (*)())uStack_28)('), ('uStack_28 != (code *)0x0', '(void *)uStack_28 != (void *)0')])),

    # --- GLDriver (ppc) ------------------------------------------------------------------------------------------------------
    # FUN_0007c760 (stock 0x7c760): `li r5,0x800; li r4,0; addi r3,r7,0xc50; bl _memset` (0x7db74..0x7db80) - the immediate 0x800 is memset's length. Ghidra
    # fitted the Mach-O `dylib_command` type onto the constant 0x800 (= 0x7f4 + 8 (dylib) + 4 (timestamp)) in a dead assignment to the r5 argument
    # register. C: the plain constant 0x800.
    'FUN_0007c760': _scoped('gld', _conv_with('FUN_0007c760 (0x7c760)', [
        ('&(*(GhidraMachOCommand *)0x000007f4).dylib.timestamp', '(unsigned int *)0x800')])),

    # FUN_000cea6c (stock 0xcea6c): `rlwinm r9,r30,24,28,31; cmplwi r9,5; bgt 0xceb40; lwzx; mtspr ctr; bctr` (0xcea98..0xceacc): a switch on
    # (word >> 8) & 0xf with cases 0..5 (0xceae8 'r', 0xceaf4 'a', 0xceb00 'o', 0xceb0c string, 0xceb28 't', 0xceb34 'v') and default '?'. The selector is
    # typed as a pointer, so Ghidra printed the case values 4 and 5 (the fourth and fifth `case` line) as the empty string found at those addresses.
    # C: `case 4:` / `case 5:`.
    'FUN_000cea6c': _scoped('gld', lambda raw, conv: _fix_two_empty_cases(conv)),

    # FUN_000c6470 (stock 0xc6470): SUB42 of a pointer argument: the corpus macro GBITS's (dead) float branch cannot type-check a pointer.
    # `SUB42(p,0)` is the low 32 bits of the pointer, the same word on ppc32. C: cast the pointer to unsigned long first.
    'FUN_000c6470': _scoped('gld', _conv_with('FUN_000c6470 (0xc6470)', [
        ('SUB42(param_3,0)', 'SUB42((unsigned long)param_3,0)')])),

    # --- GLDriver i386 (dump not archived; not exercised by the current pipeline) ---------------------------------------------------
    # local_28 is a pointer to a record (indexed as local_28[0x26]); Ghidra declared it as a one-element array of undefined4
    'FUN_001984c6': _scoped('gld-i386', _raw_with('FUN_001984c6', [('undefined4 local_28[1];', 'int *local_28;')])),
    # 128-bit register shift left by 32 bits (pslldq 4): bytes move up by four, low dword becomes zero
    'FUN_000b50a3': _scoped('gld-i386', lambda raw, conv: _re_subs(
        conv, r'(auVar\d+) = (auVar\d+) << 0x20;', r'{ unsigned char t_[16]; _memset(t_, 0, 16); _memcpy(t_ + 4, \2, 12); _memcpy(\1, t_, 16); }', 1, 'FUN_000b50a3')),
}

# RETIRED patches (issue #71): each of these used to fix a call Ghidra printed without arguments (or a pointer-typed switch), from register values read
# off the machine code. The call-accurate re-decompile of issue #61 (committed signatures, `CommitLiveSigs.java`) prints them correctly on its own, so the
# pattern no longer occurs in the dump (`PATCH_DIAG=1` lists it as PATCH-FAIL) and the patch was deleted rather than left as silently dead code. The
# corpus text is what the patch used to produce; the stock registers below are what it was derived from:
#   FUN_00092570 (0x92570)  `bl 0x92350` at 0x925ac            r3 = param_1        corpus: FUN_00092350(param_1)               (part_013.c)
#   FUN_000934f0 (0x934f0)  inlines the same call               r3 = param_1        corpus: FUN_00092350(param_1)               (part_014.c)
#   FUN_00168468 (0x168468) `bl 0x164df4` at 0x168adc           r3 = piVar3         corpus: FUN_00164df4(piVar3)                (part_044.c)
#   FUN_0014700c (0x14700c) `bl 0x146edc` at 0x147020           r3,r4 = param_1,2   corpus: FUN_00146edc(param_1,param_2)       (part_043.c)
#   FUN_00135334 (0x135334) `bl 0x134ba4` at 0x135358           r3..r5 = param_1..3 corpus: FUN_00134ba4(param_1,param_2,param_3) (part_041.c)
#   _RegisterCanMerge (glprog 0x97c09de0) `bl _RegisterIsMergeable` 0x97c09e1c, 0x97c09e2c   r3 = param_1 / param_2   corpus: _RegisterIsMergeable(param_1) (part_018.c)
#   _DumpTokenStream (0x97b8adb0), TParseContext::constructBuiltIn (0x97b9eddc): pointer-typed switch selector -> `switch((int)x)` and integer case
#   labels; ghidra2c's own normalisation (`case (T*)N:` and pointer-typed `switch`) does this for every function now.
# `case_7f8f8` (a computed call in glprog) no longer exists as a function: its bytes are the asm block `raw/raw_code.c` (byte-verified), so its patch was removed.


# Declarations of undeclared data symbols that build_corpus.py's type heuristic gets wrong (it types a dereferenced name `unsigned char *`), by scope.
# The machine code is the authority for each; see the patch comments above for the evidence.
EXTRA_DECL_FIXES = {
    'glprog': {
        # pointer to an 8-byte record of two words (InitializeGlobalPools, stock 0x97b9fe54: stw at +0 and +4)
        '_gPollAllocThreadData': 'extern unsigned int *_gPollAllocThreadData;',
        # SGI allocator chunk cursor (_S_chunk_alloc, stock 0x97c178f4): Ghidra types it `undefined4 *`; the leftover piece is put on a free list with
        # `*_S_start_free = list[i]` = `stw`. The heuristic `unsigned char *` compiled that as `stb`: the block's link word kept its old high bytes
        # (0x10000000) and corrupted the 8-byte free list (found by the 141-shader differential: 3rd compile in one process crashed in vector::_M_insert_aux).
        '_S_start_free': 'extern unsigned int *_S_start_free;',
    },
}


# functions whose text is complete except for stated, understood gaps (recorded in the ledger status column)
NOTES = {
    '_ShCompile': 'converted (four constant-selector switch `bctr` sites rewritten as direct `b` in the analysed copy so the decompiler follows them; see gs/PatchConstSwitch.java)',
}
