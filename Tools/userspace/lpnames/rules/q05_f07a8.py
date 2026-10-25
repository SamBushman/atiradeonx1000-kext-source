import re
EVIDENCE = 'copy-propagation worklist of FUN_000f07a8: consumer instructions and their select words are kept on two stack vectors (arena B); roles read off the defining expressions'
OVR = {
 ('iVar4',6):'destRegisterOffset', ('iVar10',0):'destRegister',
 ('iVar15',0):'pushedSelectWord', ('iVar15',11):'pushedSelectWord', ('iVar15',23):'pushedSelectWord', ('iVar15',1):'poppedSelectWord',
 ('iVar15',4):'lanesLeft', ('iVar15',9):'lanesLeft', ('iVar15',16):'lanesLeft', ('iVar15',19):'lanesLeft',
 ('iVar15',8):'sourceIndex', ('iVar15',13):'sourceIndex', ('iVar15',15):'sourceIndex', ('iVar15',21):'lastSourceIndex',
 ('iVar15',3):'destRecord', ('iVar15',10):'destKindClass', ('iVar15',17):'destKindClass',
 ('iVar9',0):'laneIndex', ('iVar9',3):'sourceIndex', ('iVar9',4):'sourceIndex',
 ('piVar3',0):'hwDescription', ('piVar3',1):'moveSource', ('piVar3',2):'consumer',
 ('piVar14',0):'maskStackTop', ('piVar14',1):'maskStackSlot', ('piVar14',2):'maskStackSlot', ('piVar14',4):'maskStackSlot', ('piVar14',9):'maskStackSlot',
 ('piVar14',3):'selectBytePtr', ('piVar14',5):'selectBytePtr', ('piVar14',6):'consumerSource', ('piVar14',7):'hwDescriptionObj', ('piVar14',8):'sourceOperandVReg',
 ('puVar5',0):'consumerStackAlloc', ('puVar6',0):'maskStackAlloc', ('puVar11',0):'consumerStack', ('puVar12',0):'maskStack',
 ('puVar7',0):'consumerStackSlot', ('puVar7',2):'consumerStackSlot', ('puVar7',3):'consumerStackSlot', ('puVar7',4):'consumerStackSlot', ('puVar7',6):'consumerStackSlot',
 ('puVar7',1):'consumerStackTop', ('puVar7',5):'identityCursor',
 ('uVar2',0):'initialCapacity', ('uVar2',2):'consumerStackCount', ('uVar2',5):'consumerStackCount', ('uVar2',7):'consumerStackCount', ('uVar2',9):'consumerStackCount', ('uVar2',11):'consumerStackCount',
 ('uVar2',1):'maskStackCount', ('uVar2',3):'maskStackCount', ('uVar2',4):'maskStackCount', ('uVar2',6):'maskStackCount', ('uVar2',8):'maskStackCount', ('uVar2',10):'maskStackCount',
 ('uVar13',0):'consumerStackCountInit',
}
import sys, os
sys.path.insert(0, os.path.join(os.getcwd(), 'Tools/userspace'))
import find_webs as F
def live(var, lines):
    return any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), F.CURRENT[x]) for x in lines)
def name(var, k, defs, lines, ctx):
    if not live(var, lines): return None
    return OVR.get((var, k))
