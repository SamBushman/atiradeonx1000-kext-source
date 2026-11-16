#!/usr/bin/env python3
"""test_rewrites.py - checks rewrites.rewrite_pair_results on the call shapes that reached the rebuilt GLDriver unrewritten (issue #294):
an assignment inside a comma expression / condition, and a call through a local `code *` variable.  The result of every such call (r3) must be moved to the high word of the pair variable."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import rewrites
SRC = '''int f(this)
{
  undefined8 queryResult;
  undefined8 allocResult90;
  code *ctxPtr24c;
  undefined4 verifyResultCode;
  queryResult = (**(code **)(*currentInst + 0x34))(currentInst);
  if (((a == 0) && (queryResult = (**(code **)(*currentInst + 0x38))(currentInst), verifyResultCode = (undefined4)queryResult,
      (int)((ulonglong)queryResult >> 0x20) == 0)) && (b != 0x8e)) {
    x = 1;
  }
  allocResult90 = (*ctxPtr24c)(0x90);
}
'''
out, n = rewrites.rewrite_pair_results(SRC, set())
ok = n == 3 and out.count('GH_PAIR_HI(') == 3 and 'allocResult90 = GH_PAIR_HI(((*ctxPtr24c)(0x90)), allocResult90)' in out and 'queryResult = GH_PAIR_HI(((**(code **)(*currentInst + 0x38))(currentInst)), queryResult), verifyResultCode' in out
print('rewrite_pair_results shapes:', 'ok' if ok else 'FAILED (%d rewrites)\n%s' % (n, out)); sys.exit(0 if ok else 1)
