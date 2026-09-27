#!/usr/bin/env python3
"""test_patches.py - issue #71 criterion 2: every hand patch in patches.py must FAIL LOUDLY when its pattern is absent. Each patch is applied to text that contains none
of its patterns (an empty function, and an unrelated one); anything but PatchError - including a silent pass-through - is a failure."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import patches
bad = 0
for name, fn in sorted(patches.PATCHES.items()):
    for text in ('', 'int unrelated(param_1)\n  int param_1;\n{\n  return param_1 + 1;\n}\n'):
        try:
            fn(text, text)
        except patches.PatchError:
            continue
        except Exception as e:
            print('FAIL %s: raised %s instead of PatchError' % (name, type(e).__name__)); bad += 1; break
        print('FAIL %s: applied silently to text without its pattern' % name); bad += 1; break
print('%d patches checked, %d failures' % (len(patches.PATCHES), bad))
sys.exit(1 if bad else 0)
