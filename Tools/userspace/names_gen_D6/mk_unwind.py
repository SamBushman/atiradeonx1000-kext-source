import re,glob,os
D=os.path.expanduser('~/wt/D6/Userspace/libGLProgrammability/ppc/')
text={}
for pf in sorted(glob.glob('/tmp/d6pristine/ppc/part_*.c')):
    L=open(pf).read().split('\n'); i=0
    while i<len(L):
        m=re.match(r'^/\* (\S+) @',L[i])
        if m:
            j=i+1
            while j<len(L) and not L[j].startswith('/* '): j+=1
            text[m.group(1)]='\n'.join(L[i:j]); i=j
        else: i+=1
def ids(fn): return set(re.findall(r'[A-Za-z_]\w*',text[fn]))
SRC={'fde':'GCC 4.0 unwind-dw2-fde.c','dw2':'GCC 4.0 unwind-dw2.c','pe':'GCC unwind-pe.h'}
def rows(fns, table, src):
    out=[]
    for fn in fns:
        if fn not in text: print('missing',fn); continue
        I=ids(fn)
        for old,(new,tier,ev) in table.items():
            if old in I and new not in I:
                out.append('local\t%s\t%s\t%s\t%s\t%s (%s)\n'%(fn,old,new,tier,ev,src))
    return out
R=[]
# read_encoded_value_with_base (three copies)
R+=rows(['_read_encoded_value_with_base_97c1c498','_read_encoded_value_with_base_97c1a468','__Z28read_encoded_value_with_basehjPKhPj'],{
 'param_1':('encoding','CONFIRMED','DW_EH_PE_* encoding byte: 0x50 aligned, &0xf format, &0x70 application, 0x80 indirect'),
 'param_2':('base','CONFIRMED','base added to relative values (pcrel uses the field address instead)'),
 'param_3':('p','CONFIRMED','pointer to the encoded value'),
 'param_4':('val','CONFIRMED','output: decoded value'),
 'puVar1':('next','CONFIRMED','pointer returned: just past the encoded value'),
 'local_2c':('result','CONFIRMED','decoded value (an array slot in the decompile)'),
 'local_30':('utmp','CONFIRMED','uleb128 temporary')},SRC['pe'])
R+=rows(['_read_sleb128_97c1c44c','_read_sleb128_97c1a41c','__Z12read_sleb128PKhPi'],{
 'param_1':('p','CONFIRMED','byte pointer being decoded'),'param_2':('val','CONFIRMED','output: decoded signed value'),
 'bVar1':('byte','CONFIRMED','current byte'),'uVar2':('shiftForByte','CONFIRMED','shift for the current 7-bit group (shift & 0x3f)'),
 'uVar3':('shift','CONFIRMED','number of bits consumed so far'),'uVar4':('result','CONFIRMED','accumulated value')},SRC['pe'])
R+=rows(['_read_uleb128_97c1c41c','_read_uleb128_97c1a3ec','__Z12read_uleb128PKhPj'],{
 'param_1':('p','CONFIRMED','byte pointer being decoded'),'param_2':('val','CONFIRMED','output: decoded unsigned value'),
 'bVar1':('byte','CONFIRMED','current byte'),'uVar2':('shiftForByte','CONFIRMED','shift for the current 7-bit group (shift & 0x3f)'),
 'uVar3':('shift','CONFIRMED','number of bits consumed so far'),'uVar4':('result','CONFIRMED','accumulated value')},SRC['pe'])
R+=rows(['_size_of_encoded_value_97c1c3a4','_size_of_encoded_value_97c1a2c8','__Z21size_of_encoded_valueh'],{
 'param_1':('encoding','CONFIRMED','DW_EH_PE_* encoding byte (0xff = omit)'),'uVar1':('format','CONFIRMED','encoding & 7: absptr/udata2/udata4/udata8 selector'),
 'uVar2':('valueSize','CONFIRMED','size in bytes of the encoded value')},SRC['pe'])
R+=rows(['_base_of_encoded_value','__Z21base_of_encoded_valuehP15_Unwind_Context'],{
 'param_1':('encoding','CONFIRMED','DW_EH_PE_* encoding byte (0xff = omit)'),'param_2':('context','CONFIRMED','struct _Unwind_Context * passed to __Unwind_GetTextRelBase/GetDataRelBase/GetRegionStart'),
 'uVar2':('application','CONFIRMED','encoding & 0x70: abs/pcrel/textrel/datarel/funcrel/aligned'),'bVar1':('isPcrelOrAligned','INFERRED','application == pcrel (0x10) or aligned (0x50): no base needed')},SRC['pe'])
# extract_cie_info
R+=rows(['_extract_cie_info'],{
 'param_1':('cie','CONFIRMED','const struct dwarf_cie * : augmentation string at +9'),'param_2':('context','CONFIRMED','struct _Unwind_Context *'),'param_3':('fs','CONFIRMED','_Unwind_FrameState *: eh_ptr +0x3a0, personality +0x390, data_align +0x394, code_align +0x398, retaddr_column +0x39c, fde_encoding +0x39d, lsda_encoding +0x39e, saw_z +0x39f'),
 'pcVar11':('aug','CONFIRMED','cie->augmentation string'),'pcVar9':('p0','CONFIRMED','first byte after the augmentation string (p), char view'),
 'pcVar1':('ehPtrSrc','CONFIRMED','location of the "eh" extended augmentation pointer, copied to fs->eh_ptr'),'pbVar8':('ret','CONFIRMED','end of the augmentation data (set when saw_z), else 0'),
 'pbVar10':('p','CONFIRMED','current read pointer after retaddr_column'),'puVar7':('pAfterSleb','CONFIRMED','pointer returned by read_sleb128 (points at the return address column byte)'),
 'uVar2':('retaddrColumn','CONFIRMED','*p: fs->retaddr_column'),'cVar3':('augChar','CONFIRMED','current augmentation character: z L R P'),
 'bVar4':('personalityEncoding','CONFIRMED','*p of the P augmentation'),'uVar6':('dwarfBase','CONFIRMED','base_of_encoded_value(*p, context)'),'local_30':('utmp','CONFIRMED','uleb128 temporary')},SRC['dw2'])
R+=rows(['_get_cie_encoding'],{
 'param_1':('cie','CONFIRMED','const struct dwarf_cie * : augmentation string at +9'),'iVar2':('pAfterSleb','CONFIRMED','pointer returned by read_sleb128 (return address column byte)'),
 'uVar3':('pAfterUleb','CONFIRMED','pointer returned by the first read_uleb128 (code alignment)'),'pbVar4':('p','CONFIRMED','read pointer into the augmentation data'),
 'bVar5':('fdeEncoding','CONFIRMED','R augmentation byte, 0 when absent'),'pcVar6':('aug','CONFIRMED','augmentation character cursor after the z'),'cVar1':('augChar','CONFIRMED','current augmentation character: R P L'),
 'auStack_20':('utmp','CONFIRMED','uleb128 temporary'),'auStack_1c':('stmp','CONFIRMED','sleb128 temporary'),'auStack_18':('personality','CONFIRMED','_Unwind_Ptr personality slot read and discarded')},SRC['fde'])
R+=rows(['_linear_search_fdes'],{
 'param_1':('ob','CONFIRMED','struct object *: pc_begin +0, s.b bit-field +0x10, u.single +0x14'),'param_2':('thisFde','CONFIRMED','const fde * cursor over the FDE list'),'param_3':('pc','CONFIRMED','the pc being looked up'),
 'iVar1':('cie','CONFIRMED','CIE of this FDE: (char*)this_fde + 4 - this_fde->CIE_delta'),'iVar7':('lastCie','CONFIRMED','last CIE whose encoding was read'),
 'uVar8':('encoding','CONFIRMED','ob->s.b.encoding (bits 21..28 of +0x10)'),'uVar3':('mixedEncoding','CONFIRMED','get_cie_encoding(cie) result when encodings are mixed'),
 'uVar5':('pcBegin','CONFIRMED','pc_begin read from the FDE, masked to its encoded size'),'uVar4':('afterPcBegin','CONFIRMED','pointer returned after reading pc_begin'),
 'piVar6':('last','CONFIRMED','ob->u.single: end of the FDE list'),'local_40':('pcBeginValue','CONFIRMED','pc_begin read through read_encoded_value_with_base'),
 'local_3c':('pcRange','CONFIRMED','pc_range read through read_encoded_value_with_base')},SRC['fde'])
R+=rows(['_frame_heapsort'],{
 'param_1':('ob','CONFIRMED','struct object *'),'param_2':('fdeCompare','CONFIRMED','fde_compare_t comparison function'),'param_3':('erratic','CONFIRMED','struct fde_vector *: count at +4, array at +8'),
 'uVar6':('n','CONFIRMED','erratic->count, decremented while sorting'),'puVar8':('a','CONFIRMED','erratic->array'),'uVar10':('heapBuildIndex','CONFIRMED','m/2 countdown of the heap construction loop'),
 'uVar5':('i','CONFIRMED','frame_downheap parent index'),'iVar7':('leftChildIndexMinus1','INFERRED','2*i: j-1 where j = 2*i+1 is the left child'),'uVar1':('tmp','CONFIRMED','swap temporary'),'uVar2':('tmp2','CONFIRMED','swap temporary'),
 'iVar3':('compareResult','CONFIRMED','result of fde_compare'),'iVar4':('compareResult2','CONFIRMED','result of the second fde_compare'),'iVar9':('byteOffsetOfI2','INFERRED','i*8: byte offset of the child pair a[2*i+1]'),
 'uVar5':('i','CONFIRMED','frame_downheap parent index')},SRC['fde'])
R+=rows(['_fde_split'],{
 'param_1':('ob','CONFIRMED','struct object *'),'param_2':('fdeCompare','CONFIRMED','fde_compare_t'),'param_3':('linear','CONFIRMED','struct fde_vector * (count +4, array +8)'),'param_4':('erratic','CONFIRMED','struct fde_vector * (count +4, array +8)'),
 'uVar7':('n','CONFIRMED','linear->count'),'puVar9':('prevLink','INFERRED','saved link of the marker chain'),'puVar10':('chain','CONFIRMED','current chain head: &marker or a previous element slot'),
 'puVar11':('linearElement','CONFIRMED','cursor over linear->array'),'puVar12':('markerElement','CONFIRMED','cursor over the marker array (erratic->array used as marker storage)'),
 'iVar2':('erraticCount','CONFIRMED','number of erratic entries moved'),'iVar13':('linearCount','CONFIRMED','number of linear entries kept'),
 'piVar3':('src','CONFIRMED','read cursor over linear->array'),'piVar4':('marker','CONFIRMED','read cursor over the marker array'),'piVar5':('dstErratic','CONFIRMED','write cursor for erratic->array'),'piVar6':('dstLinear','CONFIRMED','write cursor for linear->array'),'iVar1':('markerValue','CONFIRMED','marker entry of the current element')},SRC['fde'])
R+=rows(['_classify_object_over_fdes'],{
 'param_1':('ob','CONFIRMED','struct object *: pc_begin +0, s.b +0x10, u.single +0x14'),'param_2':('thisFde','CONFIRMED','const fde * cursor'),'iVar7':('count','CONFIRMED','number of FDEs counted (the return value)'),
 'iVar8':('lastCie','CONFIRMED','last CIE examined'),'uVar9':('encoding','CONFIRMED','get_cie_encoding of the last CIE'),'uVar6':('baseAddress','CONFIRMED','base_from_object(encoding, ob)'),
 'iVar2':('cie','CONFIRMED','CIE of this FDE'),'uVar1':('bits','CONFIRMED','ob->s.b word'),'uVar3':('objEncoding','CONFIRMED','ob->s.b.encoding'),'uVar4':('sizeMask','CONFIRMED','mask of the encoded pc_begin size'),
 'piVar5':('last','CONFIRMED','ob->u.single: end of the list'),'local_40':('pcBegin','CONFIRMED','pc_begin read from the FDE')},SRC['fde'])
R+=rows(['_add_fdes'],{
 'param_1':('ob','CONFIRMED','struct object *'),'param_2':('accu','CONFIRMED','struct fde_accumulator *: linear vector at +0'),'param_3':('thisFde','CONFIRMED','const fde * cursor'),
 'iVar7':('lastCie','CONFIRMED','last CIE examined'),'uVar8':('encoding','CONFIRMED','ob->s.b.encoding'),'baseAddress':('baseAddress','CONFIRMED','base_from_object'),'uVar5':('mixedEncoding','CONFIRMED','get_cie_encoding when mixed'),
 'piVar6':('last','CONFIRMED','ob->u.single'),'uVar1':('pcBegin','CONFIRMED','pc_begin masked to its encoded size'),'iVar2':('cie','CONFIRMED','CIE of this FDE (also the linear vector pointer)'),'iVar3':('count','CONFIRMED','linear->count before the increment'),'local_40':('pcBeginValue','CONFIRMED','pc_begin read value')},SRC['fde'])
R+=rows(['_uw_frame_state_for','___frame_state_for'],{
 'param_1':('context','CONFIRMED','struct _Unwind_Context *: ra +0x1c0, lsda +0x1c4, bases tbase/dbase/func +0x1c8.., ra copy +0x1d0'),'param_2':('fs','CONFIRMED','_Unwind_FrameState * (0x3a4 bytes, memset to 0)'),
 'uVar1':('status','CONFIRMED','_Unwind_Reason_Code: 5 end of stack, 3 fatal phase 1 error, 0 ok'),'piVar3':('fde','CONFIRMED','const fde * found by _Unwind_Find_FDE(ra - 1)'),'iVar2':('cieDelta','CONFIRMED','fde->CIE_delta'),
 'iVar6':('cie','CONFIRMED','(char*)fde + 4 - fde->CIE_delta'),'iVar4':('insnPtr','CONFIRMED','pointer returned by extract_cie_info: start of the CIE initial instructions'),'iVar5':('augEnd','CONFIRMED','end of the FDE augmentation data (0 when no z)'),
 'iVar2':('cieDelta','CONFIRMED','fde->CIE_delta'),'uVar7':('lsdaEncoding','CONFIRMED','fs->lsda_encoding (+0x39e)'),'local_30':('utmp','CONFIRMED','uleb128 temporary')},SRC['dw2'])
open(os.path.expanduser('~/wt/D6/Userspace/libGLProgrammability/ppc/names_D6_unwind.tsv'),'w').write('# local rows, fork D6: libgcc DWARF2 unwinder (statically linked GCC 4.0 unwind-dw2*.c), names follow the GCC sources\n'+''.join(R))
print(len(R))
