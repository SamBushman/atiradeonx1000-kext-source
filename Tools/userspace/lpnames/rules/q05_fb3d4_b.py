import re, sys, os
sys.path.insert(0, os.path.join(os.getcwd(), 'Tools/userspace'))
import find_webs as F
EVIDENCE = 'FUN_000fb3d4 (source operand translation): role read off the defining expression of the web'
def live(var, lines):
    return any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), F.CURRENT[x]) for x in lines)
OVR = {('uVar22',0):'descriptorWord', ('uVar22',1):'descriptorWord', ('uVar22',3):'descriptorWord', ('uVar22',4):'descriptorWord', ('uVar22',5):'descriptorWord', ('uVar22',7):'descriptorWord',
       ('uVar22',2):'stackTopIndex', ('uVar22',6):'swizzleWord',
       ('uVar23',0):'hasExtensionWord', ('uVar24',0):'registerType',
       ('uVar34',0):'registerType2', ('uVar34',1):'movTableCount', ('uVar34',2):'movTableCount', ('uVar34',3):'movTableCount', ('uVar34',4):'newTempIndex2',
       ('uVar35',0):'arenaA2', ('uVar35',3):'arenaA2', ('uVar35',4):'arenaA2', ('uVar35',5):'arenaA2', ('uVar35',1):'registerFile2', ('uVar35',2):'registerFile2',
       ('uVar35',7):'registerFile2', ('uVar35',8):'registerFile2', ('uVar35',9):'registerFile2', ('uVar35',10):'registerFile2', ('uVar35',11):'registerFile2', ('uVar35',12):'registerFile2',
       ('uVar35',6):'instWord0xc8', ('uVar35',14):'packedLaneSource1', ('uVar35',15):'constantSelectWord2', ('uVar35',16):'operandSelectWord2',
       ('uVar12',0):'registerMap', ('uVar12',1):'packedLaneSource2', ('uVar12',2):'registerFile3', ('uVar12',3):'registerFile3', ('uVar12',4):'registerFile3',
       ('uVar12',5):'operandSelectWord3', ('uVar14',0):'registerFile4',
       ('dVar4',0):'tokenWord', ('dVar4',1):'tokenWord', ('dVar4',2):'tokenWord', ('dVar4',3):'tokenWord',
       ('piVar7',1):'hwDescription', ('piVar7',2):'hwDescription', ('piVar7',3):'hwDescription', ('piVar7',4):'hwDescription', ('piVar7',5):'movInst', ('piVar7',0):'stackTopEntry',
       ('pvVar15',1):'mulInst', ('puVar37',0):'movTableVector', ('puVar37',1):'movTableVector', ('puVar37',2):'movTableVector', ('puVar33',0):'newInstObj',
       ('pcVar36',0):'hwVirtualSlot88'}
def name(var, k, defs, lines, ctx):
    if not live(var, lines): return None
    return OVR.get((var, k))
