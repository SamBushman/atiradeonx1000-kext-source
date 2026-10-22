exec(open(os.path.expanduser('~/g5logs/D6/mk_unwind.py')).read().split("R=[]")[0]) if False else None
import re,glob,os
D=os.path.expanduser('~/wt/D6/Userspace/libGLProgrammability/ppc/')
src=open(os.path.expanduser('~/g5logs/D6/mk_unwind.py')).read()
pre=src.split("R=[]\n")[0]
exec(pre)
R=[]
R+=rows(['_execute_stack_op'],{
 'param_1':('opPtr','CONFIRMED','const unsigned char * : DWARF expression being evaluated, opcode byte at *opPtr'),'param_2':('opEnd','CONFIRMED','end of the expression'),'param_3':('context','CONFIRMED','struct _Unwind_Context *'),'param_4':('initial','CONFIRMED','initial stack value (stack[0] = initial)'),
 'auStack_14c':('stackFrameWords','CONFIRMED','stack frame whose word 3 is stack[0]: _Unwind_Word stack[64] plus three header words'),
 'uVar8':('stackElt','CONFIRMED','number of elements on the DWARF stack'),'uVar9':('newStackElt','CONFIRMED','stack_elt after popping'),'uVar10':('op','CONFIRMED','current dwarf_location_atom opcode (DW_OP_*)'),
 'puVar3':('result','CONFIRMED','value pushed back on the stack'),'local_40':('operand','CONFIRMED','popped top of stack / decoded operand'),'uVar6':('first','CONFIRMED','second-from-top operand of a binary op'),
 'local_3c':('stmp','CONFIRMED','signed leb128 temporary (DW_OP_consts)'),'local_30':('utmp','CONFIRMED','unsigned leb128 temporary (DW_OP_constu, DW_OP_plus_uconst, DW_OP_regx...)'),
 'local_34':('offsetOrIndex','CONFIRMED','branch offset of DW_OP_bra/skip, or the index of DW_OP_pick'),'uVar2':('branchOffset','CONFIRMED','signed 16-bit offset of DW_OP_bra/DW_OP_skip'),
 'bVar1':('size','CONFIRMED','operand size byte of DW_OP_deref_size / the low byte of an 8-byte constant'),'puVar7':('opPtrNext','CONFIRMED','op_ptr after the opcode and its operands'),'iVar4':('stackByteOffset','INFERRED','byte offset into the stack frame of the element being picked')},SRC['dw2'])
R+=rows(['_execute_cfa_program'],{
 'param_1':('insnPtr','CONFIRMED','const unsigned char * : CFA instruction cursor'),'param_2':('insnEnd','CONFIRMED','end of the CFA instruction stream'),'param_3':('context','CONFIRMED','struct _Unwind_Context * (ra at +0x1c0, lsda at +0x1d4)'),
 'param_4':('fs','CONFIRMED','_Unwind_FrameState *: regs.reg[] 8 bytes each {loc, how}, regs.prev +0x378, cfa_offset +0x37c, cfa_reg +0x380, cfa_exp +0x384, cfa_how +0x388, pc +0x38c, data_align +0x394, code_align +0x398, fde_encoding +0x39d'),
 'bVar1':('insn','CONFIRMED','current CFA opcode byte (DW_CFA_*)'),'bVar5':('insnClass','CONFIRMED','insn & 0xc0: advance_loc / offset / restore classes'),'puVar12':('insnNext','CONFIRMED','insn_ptr after the opcode and its operands'),
 'uVar8':('pc','CONFIRMED','fs->pc, compared with context->ra to stop'),'uVar3':('delta','CONFIRMED','delta of advance_loc1/2/4'),'iVar2':('scaledValue','INFERRED','operand times the code/data alignment factor'),'iVar9':('dataAlign','CONFIRMED','fs->data_align (+0x394)'),
 'local_2c':('reg','CONFIRMED','register number operand'),'local_30':('offset','CONFIRMED','unsigned leb128 operand'),'local_28':('reg2','CONFIRMED','second register / offset operand (DW_CFA_register)'),'local_24':('soffset','CONFIRMED','signed leb128 operand'),
 'uVar6':('pAfterReg','CONFIRMED','pointer returned after reading the register operand'),'puVar7':('ulebTarget','INFERRED','destination of a leb128 read: &reg or context->lsda'),
 'puVar4':('unusedRs','CONFIRMED','free list of alloca\'d frame_state_reg_info copies (remember_state)'),'puVar10':('oldRs','CONFIRMED','stack of remembered register states (DW_CFA_remember_state)'),'puVar11':('nextOldRs','INFERRED','remembered state popped to become oldRs'),'puVar13':('newUnusedRs','INFERRED','new head of the free list')},SRC['dw2'])
R+=rows(['__Unwind_Find_registered_FDE'],{
 'param_1':('pc','CONFIRMED','pc being looked up'),'param_2':('bases','CONFIRMED','struct dwarf_eh_bases * output: tbase, dbase, func'),'puVar8':('ob','CONFIRMED','struct object * : pc_begin +0, tbase +4, dbase +8, u +0xc, s.b +0x10, next +0x18'),
 'iVar7':('ret','CONFIRMED','the FDE found (return value)'),'puVar3':('cursor','CONFIRMED','cursor over seen_objects'),'puVar6':('linkSlot','CONFIRMED','address of the link to patch when inserting into seen_objects'),'puVar1':('nextSlot','CONFIRMED','&cursor->next'),
 'bVar2':('notFound','INFERRED','no FDE found in seen_objects'),'uVar4':('encoding','CONFIRMED','ob->s.b.encoding, or the CIE encoding when mixed')},SRC['fde'])
R+=rows(['__Unwind_RaiseException_Phase2'],{
 'param_1':('exc','CONFIRMED','struct _Unwind_Exception * (private_2 at +0x10)'),'param_2':('context','CONFIRMED','struct _Unwind_Context *'),'auStack_3c0':('fs','CONFIRMED','_Unwind_FrameState (0x390 bytes of registers etc. up to personality)'),
 'iVar3':('code','CONFIRMED','_Unwind_Reason_Code of uw_frame_state_for'),'iVar4':('result','CONFIRMED','_Unwind_Reason_Code of the personality call or phase result'),'uVar1':('isHandlerFrame','CONFIRMED','context.ra == exc->private_2: this is the frame the search phase picked'),
 'bVar2':('notContinueUnwind','INFERRED','personality result != _URC_CONTINUE_UNWIND'),'local_30':('personality','CONFIRMED','fs.personality (frame state +0x390)')},SRC['dw2'])
R+=rows(['__Unwind_ForcedUnwind_Phase2'],{
 'param_1':('exc','CONFIRMED','struct _Unwind_Exception * (stop at +0xc, stop_argument at +0x10)'),'param_2':('context','CONFIRMED','struct _Unwind_Context *'),'pcVar3':('stop','CONFIRMED','_Unwind_Stop_Fn exc->private_1'),'a6':('stopArg','CONFIRMED','exc->private_2: stop_argument'),
 'iVar1':('code','CONFIRMED','_Unwind_Reason_Code of uw_frame_state_for'),'a1':('action','CONFIRMED','_Unwind_Action passed to stop: _UA_FORCE_UNWIND|_UA_CLEANUP_PHASE (+ _UA_END_OF_STACK when code == 5)'),'iVar2':('stopCode','CONFIRMED','_Unwind_Reason_Code returned by the stop function'),
 'local_40':('personality','CONFIRMED','fs.personality'),'auStack_3d0':('fs','CONFIRMED','_Unwind_FrameState')},SRC['dw2'])
R+=rows(['_fde_mixed_encoding_compare'],{'param_1':('ob','CONFIRMED','struct object *'),'param_2':('x','CONFIRMED','const fde * x'),'param_3':('y','CONFIRMED','const fde * y'),'uVar1':('encoding','CONFIRMED','get_cie_encoding of the FDE\'s CIE'),'local_30':('xPcBegin','CONFIRMED','pc_begin of x'),'local_2c':('yPcBegin','CONFIRMED','pc_begin of y'),'uVar2':('result','CONFIRMED','-1, 0 or 1')},SRC['fde'])
R+=rows(['_fde_single_encoding_compare'],{'param_1':('ob','CONFIRMED','struct object *'),'param_2':('x','CONFIRMED','const fde * x'),'param_3':('y','CONFIRMED','const fde * y'),'local_30':('xPcBegin','CONFIRMED','pc_begin of x'),'local_2c':('yPcBegin','CONFIRMED','pc_begin of y'),'uVar1':('result','CONFIRMED','-1, 0 or 1')},SRC['fde'])
R+=rows(['_fde_unencoded_compare'],{'param_1':('ob','CONFIRMED','struct object *'),'param_2':('x','CONFIRMED','const fde * x'),'param_3':('y','CONFIRMED','const fde * y')},SRC['fde'])
R+=rows(['___deregister_frame_info_bases'],{'pvVar1':('ob','CONFIRMED','struct object * being searched'),'puVar2':('linkSlot','CONFIRMED','address of the link to unlink')},SRC['fde'])
open(D+'names_D6_unwind.tsv','a').write(''.join(R)); print(len(R))
