#include "decls.h"

/* ava_decode_picture @ 0x3930 (916 bytes) */
int ava_decode_picture(ctx, picParams, outResult)
  int ctx;
  byte *picParams;
  undefined4 *outResult;
{
  bool notLast;
  int *statCursor;
  undefined4 status;
  int slotOrMbCursor;
  undefined4 *statEntry;
  int statCountdown;
  int totalWords;
  int fieldIndex;
  uint macroblockCount;
  uint *descTable;
  uint mbIndex;
  uint nextMbIndex;
  int mbCursorOrCount;
  int unusedWords;
  undefined4 picExtra [8];
  
  descTable = (uint *)(ctx + 0x55c);
  descTable[(char)picParams[6] + 0x150] = 0;
  descTable[(char)picParams[6] + 0x155] = 0;
  if (*picParams == 1) {
    descTable[(char)picParams[6] + 0x14b] = 0;
  }
  if ((descTable[(char)picParams[7] + 0x14b] == 0) && (descTable[(char)picParams[8] + 0x14b] == 0)) {
    slotOrMbCursor = *(int *)(ctx + 0xac4);
    fieldIndex = 0;
    descTable[(char)picParams[6] + 0x14b] = 0;
    descTable[slotOrMbCursor * 2 + 0x15b] = 0;
    descTable[*(int *)(ctx + 0xac4) * 2 + 0x15c] = 0;
    *(int *)(ctx + 0x568) = (int)(char)picParams[6];
    *(int *)(ctx + 0x56c) = (int)(char)picParams[7];
    *(int *)(ctx + 0x570) = (int)(char)picParams[8];
    picExtra[0] = *(undefined4 *)(picParams + 0x10);
    slotOrMbCursor = *(int *)(picParams + 0xc);
    do {
      *descTable = (uint)picParams[2];
      *(uint *)(ctx + 0x560) = (uint)*picParams;
      *(byte *)(ctx + 0x564) = picParams[4];
      if (fieldIndex == 0) {
        *(undefined1 *)(ctx + 0x574) = 0;
      }
      else {
        *(undefined1 *)(ctx + 0x574) = 1;
      }
      if (*descTable == 3) {
        macroblockCount = *(int *)(ctx + 0x580) * *(int *)(ctx + 0x584);
      }
      else {
        macroblockCount = (uint)(*(int *)(ctx + 0x580) * *(int *)(ctx + 0x584)) >> 1;
      }
      if (*(int *)(ctx + 0x560) == 1) {
        if (macroblockCount != 0) {
          mbCursorOrCount = slotOrMbCursor;
          mbIndex = 0;
          do {
            nextMbIndex = mbIndex + 1;
            slotOrMbCursor = mbCursorOrCount + 0x1c;
            ((int (*)())ava_emit_macroblock)(ctx,mbCursorOrCount,picExtra,mbIndex,0);
            mbCursorOrCount = slotOrMbCursor;
            mbIndex = nextMbIndex;
          } while (nextMbIndex < macroblockCount);
        }
      }
      else {
        mbCursorOrCount = 0x19;
        statEntry = (undefined4 *)(ctx + 0x1442c);
        do {
          *statEntry = 0;
          statEntry[-1] = *(int *)(ctx + 0x14424) + -1;
          statEntry = statEntry + 3;
          mbCursorOrCount = mbCursorOrCount + -1;
        } while (mbCursorOrCount != 0);
        if (macroblockCount != 0) {
          mbIndex = 0;
          do {
            if (*(char *)(slotOrMbCursor + 0x14) == '\0') {
              ((int (*)())ava_emit_macroblock)(ctx,slotOrMbCursor,picExtra,mbIndex,0);
            }
            else {
              ((int (*)())ava_emit_macroblock)(ctx,slotOrMbCursor,picExtra,mbIndex,1);
              ((int (*)())ava_emit_mb_motion_vectors)(ctx,slotOrMbCursor,mbIndex);
            }
            mbIndex = mbIndex + 1;
            slotOrMbCursor = slotOrMbCursor + 0x1c;
          } while (mbIndex < macroblockCount);
        }
        statCursor = (int *)(ctx + 0x1442c);
        mbCursorOrCount = 0;
        totalWords = 0;
        statCountdown = 0x19;
        do {
          if (*statCursor != 0) {
            totalWords = totalWords + *statCursor;
            mbCursorOrCount = mbCursorOrCount + 1;
          }
          unusedWords = (*(int *)(ctx + 0x14424) - statCursor[-1]) + -1;
          if (unusedWords != 0) {
            mbCursorOrCount = mbCursorOrCount + 1;
            totalWords = totalWords + unusedWords;
          }
          statCountdown = statCountdown + -1;
          statCursor = statCursor + 3;
        } while (statCountdown != 0);
        ((int (*)())ava_emit_picture_setup_packet)(ctx,(mbCursorOrCount * 0x80 + totalWords) * 2 + 1000);
      }
      ((int (*)())ava_end_picture)(ctx);
      if (*descTable == 3) break;
      notLast = fieldIndex != 1;
      picParams = picParams + 1;
      fieldIndex = fieldIndex + 1;
    } while (notLast);
    status = *(undefined4 *)(ctx + 0xac4);
    *outResult = 0;
    outResult[1] = status;
    status = 0;
    *(uint *)(ctx + 0xac4) = (*(int *)(ctx + 0xac4) + 1U) % 10000;
  }
  else {
    status = 0xffffffff;
    descTable[(char)picParams[6] + 0x14b] = 1;
  }
  return status;
}

/* ava_acquire_image @ 0x3cd0 (672 bytes) */
int ava_acquire_image(ctx, syncId)
  int ctx;
  int syncId;
{
  undefined *taskPortPtr;
  uint *lastHeader;
  int *fillCursor;
  int *payload;
  int mapBaseOrCount;
  int *refCounter;
  int *cmdWrite;
  char reservationHeld;
  byte condReg0;
  
  taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
  cmdWrite = *(int **)(ctx + 0x34);
  if (*(int **)(ctx + 0x38) <= cmdWrite + 8) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                        ctx + 0x44,1);
    mapBaseOrCount = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBaseOrCount + 0x20;
    *(int *)(ctx + 0x30) = mapBaseOrCount + 0x1c;
    *(int *)(ctx + 0x38) = mapBaseOrCount + 0x20 + *(int *)(mapBaseOrCount + 0x10) * 4;
    *(undefined4 *)(mapBaseOrCount + 0x1c) = 0;
    cmdWrite = *(int **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(int **)(ctx + 0x34) = cmdWrite + 8;
  payload = cmdWrite + 1;
  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
  *(int **)(ctx + 0x30) = cmdWrite;
  *cmdWrite = syncId * 0x1000000 + 0x19000000;
  fillCursor = payload;
  switch(syncId) {
  case 0:
    refCounter = *(int **)(ctx + 0x151b4);
    break;
  case 1:
    refCounter = *(int **)(ctx + 0x153bc);
    break;
  case 2:
    refCounter = *(int **)(ctx + 0x170);
    goto setRefCounter;
  case 3:
    refCounter = *(int **)(ctx + 0x1d8);
    goto setRefCounter;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    refCounter = *(int **)(syncId * 100 + ctx + 0xb0);
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
    refCounter = *(int **)(syncId * 100 + ctx + 0x38c);
    break;
  case 0x11:
    refCounter = *(int **)(ctx + 0xa44);
setRefCounter:
    refCounter = (int *)*refCounter;
    fillCursor = cmdWrite + 2;
    *payload = *refCounter;
    refCounter = refCounter + 4;
    do {
      if (reservationHeld != '\0') {
        mapBaseOrCount = storeWordConditionalIndexed(*refCounter + 1,0,refCounter);
        *refCounter = mapBaseOrCount;
        condReg0 = 2;
      }
    } while (!(bool)(condReg0 >> 1 & 1));
  default:
    goto syncIdDefault;
  }
  fillCursor = cmdWrite + 2;
  refCounter = (int *)*refCounter;
  *payload = *refCounter;
  refCounter = refCounter + 4;
  do {
    if (reservationHeld != '\0') {
      mapBaseOrCount = storeWordConditionalIndexed(*refCounter + 1,0,refCounter);
      *refCounter = mapBaseOrCount;
      condReg0 = 2;
    }
  } while (!(bool)(condReg0 >> 1 & 1));
syncIdDefault:
  mapBaseOrCount = 6;
  do {
    *fillCursor = -0x80000000;
    taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
    fillCursor = fillCursor + 1;
    mapBaseOrCount = mapBaseOrCount + -1;
  } while (mapBaseOrCount != 0);
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                      ctx + 0x44,1);
  mapBaseOrCount = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = mapBaseOrCount + 0x20;
  *(int *)(ctx + 0x30) = mapBaseOrCount + 0x1c;
  *(int *)(ctx + 0x38) = mapBaseOrCount + 0x20 + *(int *)(mapBaseOrCount + 0x10) * 4;
  *(undefined4 *)(mapBaseOrCount + 0x1c) = 0;
  return;
}

/* ava_get_frame @ 0x3fc0 (696 bytes) */
int ava_get_frame(ctx, surfaceIndex, surfaceDesc, outResult, unused1, unused2, unused3, unused4)
  int ctx;
  uint surfaceIndex;
  undefined4 *surfaceDesc;
  undefined4 *outResult;
  undefined4 unused1;
  undefined4 unused2;
  undefined4 unused3;
  undefined4 unused4;
{
  uint featureFlags;
  int fourcc;
  undefined4 descWord0;
  undefined4 descWord1;
  undefined4 fourccArg;
  undefined4 failStatus;
  int descTableOrResult;
  
  descTableOrResult = ctx + 0x55c;
  if (((surfaceDesc[6] == 0) || ((int)surfaceIndex < 0)) || (*(uint *)(ctx + 0x54) <= surfaceIndex)) {
    return 0xfffffff9;
  }
  fourcc = surfaceDesc[3];
  if (((fourcc != 0x79757673) && (fourcc != 0x32767579)) &&
     ((fourcc != 0x61726762 && ((fourcc != 0x72676261 && (fourcc != 0x61723135)))))) {
    return 0xfffffffb;
  }
  if ((*(int *)(ctx + 0x120) == 0) || (*(int *)(surfaceIndex * 4 + descTableOrResult + 0x554) == 0)) {
    featureFlags = *(uint *)(ctx + 0x11c);
    if ((featureFlags & 2) != 0) {
      ((int (*)())ava_render_brightness_contrast_pass)(ctx,surfaceIndex,0);
      featureFlags = *(uint *)(ctx + 0x11c);
    }
    if ((featureFlags & 4) != 0) {
      ((int (*)())ava_render_hue_saturation_pass)(ctx,surfaceIndex,0);
    }
  }
  else {
    featureFlags = *(uint *)(ctx + 0x11c);
    if ((featureFlags & 2) != 0) {
      ((int (*)())ava_render_brightness_contrast_pass)(ctx,surfaceIndex,1);
      featureFlags = *(uint *)(ctx + 0x11c);
    }
    if ((featureFlags & 4) != 0) {
      ((int (*)())ava_render_hue_saturation_pass)(ctx,surfaceIndex,1);
    }
  }
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + descTableOrResult + 0x56c) = 0;
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + descTableOrResult + 0x570) = 0;
  descWord0 = *surfaceDesc;
  descWord1 = surfaceDesc[1];
  fourccArg = surfaceDesc[3];
  descTableOrResult = ava_declare_image(ctx,ctx + 0xa1c,*(undefined4 *)(ctx + 0xa80),descWord0,descWord1,fourccArg,
                       surfaceDesc[6]);
  failStatus = 0xfffffffd;
  if (descTableOrResult != 0) {
    return 0xfffffffd;
  }
  ((int (*)())ava_acquire_image)(ctx,0x11);
  featureFlags = surfaceDesc[3];
  if (featureFlags != 0x61726762) {
    if (featureFlags < 0x61726763) {
      if (featureFlags == 0x32767579) {
loopCallAvaRenderConvertFrameYuv2:
        ((int (*)())ava_render_convert_frame_yuv2)(ctx,surfaceIndex,surfaceDesc);
        goto callAvaWaitForStamps;
      }
      if (featureFlags != 0x61723135) goto callAvaWaitForStamps;
    }
    else if (featureFlags != 0x72676261) {
      if (featureFlags != 0x79757673) goto callAvaWaitForStamps;
      goto loopCallAvaRenderConvertFrameYuv2;
    }
  }
  ((int (*)())ava_render_convert_frame)(ctx,surfaceIndex,surfaceDesc);
callAvaWaitForStamps:
  ava_wait_for_stamps(ctx,0,*(undefined4 *)(ctx + 0xac4));
  ((int (*)())ava_dcache_flush_range_sync)(ctx,surfaceDesc[6],surfaceDesc[1] * surfaceDesc[2],descWord0,descWord1,fourccArg,failStatus,unused4);
  ava_release_image(ctx,0x11);
  ava_delete_image(ctx,ctx + 0xa1c,0);
  descWord0 = *(undefined4 *)(ctx + 0xac4);
  *outResult = 0;
  outResult[1] = descWord0;
  *(uint *)(ctx + 0xac4) = (*(int *)(ctx + 0xac4) + 1U) % 10000;
  return 0;
}

/* ava_slot20_enqueue @ 0x4280 (192 bytes) */
int ava_slot20_enqueue(ctx, arg, opcodeBase, outSlot)
  int ctx;
  undefined4 arg;
  int opcodeBase;
  undefined4 *outSlot;
{
  uint packetIndex;
  undefined4 slotIndex;
  
  packetIndex = opcodeBase + 0xcU & 0xff;
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + ctx + 0x55c + 0x56c) = 0;
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + ctx + 0x55c + 0x570) = 0;
  ((int (*)())ava_acquire_image)(ctx,packetIndex);
  ((int (*)())ava_noop_9690)(ctx,arg,opcodeBase);
  ava_release_image(ctx,packetIndex);
  slotIndex = *(undefined4 *)(ctx + 0xac4);
  *outSlot = 0;
  outSlot[1] = slotIndex;
  *(uint *)(ctx + 0xac4) = (*(int *)(ctx + 0xac4) + 1U) % 10000;
  return 0;
}

/* ava_setup_decode @ 0x4340 (988 bytes) */
int ava_setup_decode(ctx, sizeInfo, requestedCount)
  int ctx;
  int *sizeInfo;
  uint requestedCount;
{
  bool notLast;
  uint heightOrCtrlOrPlaneAddr;
  int allocOrRowBase;
  undefined4 r4AfterCall;
  undefined4 bufferOrStatus;
  undefined4 allocAlign;
  undefined4 allocFlags;
  uint widthOrCount;
  int planeTableA;
  uint widthPlus15OrBit;
  uint *planeEntry;
  int indexOrStatus;
  int *tableCursor;
  int descCursor;
  uint surfaceCount;
  undefined4 *freeCursor;
  int innerCount;
  double fpPassThrough1;
  double fpPassThrough2;
  double fpPassThrough3;
  double fpPassThrough4;
  double fpPassThrough5;
  double fpPassThrough6;
  double fpPassThrough7;
  double fpPassThrough8;
  double fpPassThrough9;
  double fpPassThrough10;
  undefined4 scalarOut0;
  undefined4 scalarIn0;
  uint scalarIn1;
  undefined4 scalarIn2;
  undefined4 scalarIn3;
  uint scalarIn4;
  
  descCursor = ctx + 0x55c;
  surfaceCount = *(uint *)(ctx + 0x54);
  if ((surfaceCount != requestedCount) || (surfaceCount == 0)) {
    return 0xfffffff9;
  }
  if (surfaceCount < 6) {
    widthPlus15OrBit = *(int *)*sizeInfo + 0xf;
    widthOrCount = widthPlus15OrBit & 0xfffffff0;
    *(uint *)(ctx + 0x578) = widthOrCount;
    heightOrCtrlOrPlaneAddr = *(int *)(*sizeInfo + 4) + 0xf;
    *(uint *)(ctx + 0x57c) = heightOrCtrlOrPlaneAddr & 0xfffffff0;
    if ((widthPlus15OrBit & 0xf0) != 0) {
      widthOrCount = (widthPlus15OrBit & 0xffffff00) + 0x100;
    }
    *(uint *)(ctx + 0x588) = widthOrCount;
    *(uint *)(ctx + 0x580) = widthPlus15OrBit >> 4;
    *(uint *)(ctx + 0x584) = heightOrCtrlOrPlaneAddr >> 4;
    indexOrStatus = 0;
    *(undefined2 *)(ctx + 0x126) = 0;
    tableCursor = (int *)(ctx + 0x14430);
    *(undefined2 *)(ctx + 0x124) = 0;
    *(short *)(ctx + 0x12a) = (short)*(undefined4 *)(ctx + 0x578);
    *(short *)(ctx + 0x128) = (short)*(undefined4 *)(ctx + 0x57c);
    *(int *)(ctx + 0x14424) = *(int *)(ctx + 0x580) * *(int *)(ctx + 0x584);
    do {
      allocOrRowBase = _malloc(*(int *)(ctx + 0x14424) << 2);
      *tableCursor = allocOrRowBase;
      if (allocOrRowBase == 0) {
        if (0 < indexOrStatus) {
          freeCursor = (undefined4 *)(ctx + 0x14430);
          descCursor = 0;
          do {
            bufferOrStatus = *freeCursor;
            descCursor = descCursor + 1;
            freeCursor = freeCursor + 3;
            _free(bufferOrStatus);
          } while (descCursor != indexOrStatus);
        }
        goto setBufferOrStatus;
      }
      notLast = indexOrStatus != 0x18;
      tableCursor = tableCursor + 3;
      indexOrStatus = indexOrStatus + 1;
    } while (notLast);
    heightOrCtrlOrPlaneAddr = *(uint *)(ctx + 0xa84);
    indexOrStatus = 0;
    widthOrCount = surfaceCount;
    do {
      widthPlus15OrBit = indexOrStatus + 10;
      indexOrStatus = indexOrStatus + 1;
      heightOrCtrlOrPlaneAddr = heightOrCtrlOrPlaneAddr | 1 << (widthPlus15OrBit & 0x3f);
      widthOrCount = widthOrCount - 1;
    } while (widthOrCount != 0);
    *(uint *)(ctx + 0xa84) = heightOrCtrlOrPlaneAddr;
    if ((surfaceCount < 5) && ((int)surfaceCount < 5)) {
      widthOrCount = surfaceCount + 10;
      indexOrStatus = 0xf - widthOrCount;
      do {
        widthPlus15OrBit = widthOrCount & 0x3f;
        widthOrCount = widthOrCount + 1;
        heightOrCtrlOrPlaneAddr = heightOrCtrlOrPlaneAddr & ~(1 << widthPlus15OrBit);
        indexOrStatus = indexOrStatus + -1;
      } while (indexOrStatus != 0);
      *(uint *)(ctx + 0xa84) = heightOrCtrlOrPlaneAddr;
    }
    scalarIn1 = *(undefined4 *)(ctx + 0x578);
    scalarIn2 = *(undefined4 *)(ctx + 0x57c);
    scalarIn4 = *(uint *)(ctx + 0xa84) | 0x20000;
    *(uint *)(ctx + 0xa84) = scalarIn4;
    scalarIn3 = 0;
    scalarOut0 = 0;
    scalarIn0 = 0;
    indexOrStatus = _io_connect_method_scalarI_scalarO
                       (*(undefined4 *)(ctx + 0x14),0x15,&scalarIn0,5,0,&scalarOut0);
    if (indexOrStatus == 0) {
      scalarIn0 = *(undefined4 *)(ctx + 0xc);
      scalarIn1 = *(uint *)(ctx + 0x18) & 0xffff4000;
      scalarIn2 = 1;
      indexOrStatus = _io_connect_method_scalarI_structureI
                         (*(undefined4 *)(ctx + 0x14),0,&scalarIn0,3,0,0);
      if (indexOrStatus == 0) {
        *(undefined4 *)(ctx + 0x28) = *(undefined4 *)(ctx + 0x578);
        *(undefined4 *)(ctx + 0x2c) = *(undefined4 *)(ctx + 0x57c);
        indexOrStatus = ava_declare_image(ctx,ctx + 0x1518c,*(undefined4 *)(ctx + 0x151f0),
                              *(uint *)(ctx + 0x578) >> 4,
                              (*(uint *)(ctx + 0x57c) >> 1 & 0x7ffffff8) *
                              *(int *)(ctx + 0x54),0x20,0);
        if (indexOrStatus == 0) {
          indexOrStatus = 0;
          planeTableA = ctx + 0x151ec;
          allocOrRowBase = ctx + 0x1523c;
          *(undefined4 *)(ctx + 0x58c) = *(undefined4 *)(ctx + 0x151a4);
          widthOrCount = *(uint *)(ctx + 0x57c) >> 4;
          heightOrCtrlOrPlaneAddr = *(int *)(ctx + 0x1518c) + 0xffU & 0xffffff00;
          do {
            planeEntry = (uint *)(planeTableA + 8);
            innerCount = 4;
            do {
              *planeEntry = heightOrCtrlOrPlaneAddr;
              planeEntry = planeEntry + 1;
              heightOrCtrlOrPlaneAddr = heightOrCtrlOrPlaneAddr + (widthOrCount * *(int *)(ctx + 0x151a4) & 0xfffffffc);
              innerCount = innerCount + -1;
            } while (innerCount != 0);
            planeEntry = (uint *)(allocOrRowBase + 8);
            innerCount = 4;
            do {
              *planeEntry = heightOrCtrlOrPlaneAddr;
              planeEntry = planeEntry + 1;
              heightOrCtrlOrPlaneAddr = heightOrCtrlOrPlaneAddr + (widthOrCount * *(int *)(ctx + 0x151a4) & 0xfffffffc);
              innerCount = innerCount + -1;
            } while (innerCount != 0);
            notLast = indexOrStatus != 4;
            planeTableA = planeTableA + 0x10;
            allocOrRowBase = allocOrRowBase + 0x10;
            indexOrStatus = indexOrStatus + 1;
          } while (notLast);
          ((int (*)())ava_acquire_image)(ctx,0);
          bufferOrStatus = *(undefined4 *)(ctx + 0x153f8);
          allocAlign = 0x20;
          allocFlags = 0;
          widthOrCount = *(uint *)(ctx + 0x578) >> 4;
          allocOrRowBase = (*(uint *)(ctx + 0x57c) >> 4) * 0x18;
          indexOrStatus = ava_declare_image(ctx,ctx + 0x15394,bufferOrStatus,widthOrCount,allocOrRowBase,0x20,0);
          if (indexOrStatus == 0) {
            fpPassThrough1 = (double)((int (*)())ava_acquire_image)(ctx,1);
            ((void (*)())ava_build_stage_programs)(ctx,fpPassThrough1,fpPassThrough2,fpPassThrough3,fpPassThrough4,fpPassThrough5,fpPassThrough6,fpPassThrough7,fpPassThrough8,
                         fpPassThrough9,fpPassThrough10);
            ((int (*)())ava_build_block_grid)(ctx,r4AfterCall,bufferOrStatus,widthOrCount,allocOrRowBase,allocAlign,allocFlags,planeTableA);
            DAT_0000f1a8 = *(undefined4 *)(ctx + 0x578);
            DAT_0000f1a4 = *(undefined4 *)(ctx + 0x57c);
            do {
              *(undefined4 *)(descCursor + 0x38) = *(undefined4 *)(ctx + 0x578);
              *(undefined4 *)(descCursor + 0x3c) = *(undefined4 *)(ctx + 0x57c);
              bufferOrStatus = *(undefined4 *)(ctx + 0x588);
              *(undefined4 *)(descCursor + 0x44) = 0x59563132;
              *(undefined4 *)(descCursor + 0x54) = 1;
              *(undefined4 *)(descCursor + 0x40) = bufferOrStatus;
              descCursor = descCursor + 0x40;
              surfaceCount = surfaceCount - 1;
            } while (surfaceCount != 0);
            return 0;
          }
        }
        goto setBufferOrStatus;
      }
    }
    bufferOrStatus = 0xfffffffb;
  }
  else {
setBufferOrStatus:
    bufferOrStatus = 0xfffffffd;
  }
  return bufferOrStatus;
}

/* ava_render_slot @ 0x4740 (664 bytes) */
int ava_render_slot(ctx, slotIndex, flags, position, enable)
  int ctx;
  int slotIndex;
  undefined4 flags;
  undefined4 *position;
  int enable;
{
  undefined *mapMemoryType;
  uint effectFlags;
  int slotEntry;
  undefined4 positionX;
  uint *lastHeader;
  int slotTable;
  double fpPassThrough;
  double fpPassThrough2;
  double fpPassThrough3;
  double fpPassThrough4;
  int slotOffset;
  int mapBase;
  
  slotOffset = slotIndex * 4;
  slotTable = ctx + 0x55c;
  slotEntry = slotOffset + slotTable;
  if (*(int *)(slotEntry + 0x52c) != 0) {
    return;
  }
  if (*(int *)(slotEntry + 0x554) == 0) {
    if (*(int *)(ctx + 0x120) != 0) {
      if (*(int *)(slotEntry + 0x540) == 1) {
        if (*(int *)(ctx + 0x120) == 4) {
          ((int (*)())ava_deinterlace_frame)(ctx,ctx + 0x14348 + slotIndex * 0x14,ctx + 0x143ac + slotIndex * 0x18
                       ,1);
        }
        ((int (*)())ava_deinterlace_frame)(ctx,slotIndex * 0x14 + ctx + 0x14348,slotIndex * 0x18 + ctx + 0x143ac,2
                    );
        *(undefined4 *)(slotOffset + slotTable + 0x554) = 1;
        goto checkCtx;
      }
      goto checkSlotOffset;
    }
  }
  else {
checkCtx:
    if (*(int *)(ctx + 0x120) != 0) {
checkSlotOffset:
      if (*(int *)(slotOffset + slotTable + 0x554) != 0) {
        effectFlags = *(uint *)(ctx + 0x11c);
        if ((effectFlags & 2) != 0) {
          ((int (*)())ava_render_brightness_contrast_pass)(ctx,slotIndex,1);
          effectFlags = *(uint *)(ctx + 0x11c);
        }
        if ((effectFlags & 4) != 0) {
          ((int (*)())ava_render_hue_saturation_pass)(ctx,slotIndex,1);
        }
        fpPassThrough = (double)((int (*)())ava_render_source_rect_pass)(ctx,slotIndex,1);
        goto storeCtx;
      }
    }
  }
  effectFlags = *(uint *)(ctx + 0x11c);
  if ((effectFlags & 2) != 0) {
    ((int (*)())ava_render_brightness_contrast_pass)(ctx,slotIndex,0);
    effectFlags = *(uint *)(ctx + 0x11c);
  }
  if ((effectFlags & 4) != 0) {
    ((int (*)())ava_render_hue_saturation_pass)(ctx,slotIndex,0);
  }
  fpPassThrough = (double)((int (*)())ava_render_source_rect_pass)(ctx,slotIndex,0);
storeCtx:
  *(int *)(ctx + 0x118) = enable;
  if (enable != 0) {
    *(undefined4 *)(ctx + 0x114) = flags;
    positionX = *position;
    *(undefined4 *)(ctx + 0x110) = position[1];
    *(undefined4 *)(ctx + 0x10c) = positionX;
    ((void (*)())ava_render_scale_pass)(ctx,fpPassThrough,fpPassThrough2,fpPassThrough3,fpPassThrough4);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x2000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                      ctx + 0x44,1);
  mapBase = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = mapBase + 0x20;
  *(int *)(ctx + 0x30) = mapBase + 0x1c;
  *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
  *(undefined4 *)(mapBase + 0x1c) = 0;
  if ((*(uint *)(*(int *)(ctx + 0x40) + 0x14) & 2) == 0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)(*(int *)(ctx + 0x50) + 0xc) + 0xc))
            (*(undefined4 *)(ctx + 4),*(undefined4 *)(ctx + 8),
             *(undefined4 *)(ctx + 0xc));
  return;
}

/* ava_noop_49f0 @ 0x49f0 (4 bytes) */
int ava_noop_49f0()
{
  return;
}

/* ava_noop_4a00 @ 0x4a00 (4 bytes) */
int ava_noop_4a00()
{
  return;
}

/* ava_queue_display @ 0x4a10 (296 bytes) */
int ava_queue_display(ctx, srcRect, dstRect, outSlot)
  int ctx;
  char *srcRect;
  undefined4 *dstRect;
  undefined4 *outSlot;
{
  undefined4 srcWord0;
  int entry;
  undefined4 slotIndex;
  undefined4 srcWord3;
  undefined4 srcWord2;
  int table;
  
  table = ctx + 0x55c;
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + table + 0x56c) = 0;
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + table + 0x570) = 0;
  srcWord0 = *(undefined4 *)srcRect;
  srcWord2 = *(undefined4 *)(srcRect + 8);
  srcWord3 = *(undefined4 *)(srcRect + 0xc);
  slotIndex = *(undefined4 *)(ctx + 0xac4);
  entry = *srcRect * 0x14 + table;
  *(undefined4 *)(entry + 0x13df0) = *(undefined4 *)(srcRect + 4);
  *(undefined4 *)(entry + 0x13dec) = srcWord0;
  *(undefined4 *)(entry + 0x13df4) = srcWord2;
  *(undefined4 *)(entry + 0x13df8) = srcWord3;
  *(undefined4 *)(entry + 0x13dfc) = *(undefined4 *)(srcRect + 0x10);
  srcWord2 = dstRect[1];
  srcWord3 = dstRect[2];
  srcWord0 = dstRect[3];
  entry = *srcRect * 0x18 + table;
  *(undefined4 *)(entry + 0x13e50) = *dstRect;
  *(undefined4 *)(entry + 0x13e54) = srcWord2;
  *(undefined4 *)(entry + 0x13e58) = srcWord3;
  *(undefined4 *)(entry + 0x13e5c) = srcWord0;
  srcWord0 = dstRect[4];
  *(undefined4 *)(entry + 0x13e64) = dstRect[5];
  *(undefined4 *)(entry + 0x13e60) = srcWord0;
  *(undefined4 *)(*srcRect * 4 + table + 0x540) = 1;
  outSlot[1] = slotIndex;
  *outSlot = 0;
  *(uint *)(ctx + 0xac4) = (*(int *)(ctx + 0xac4) + 1U) % 10000;
  return 0;
}

/* ava_display_refresh @ 0x4b40 (1116 bytes) */
int ava_display_refresh(ctx)
  int ctx;
{
  undefined *taskPortPtr;
  int mapBase;
  uint *lastHeader;
  undefined4 *cmdWrite;
  int mapSizePtrOrBase;
  int mapAddrPtr;
  uint surfaceIndex;
  
  taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
  if (*(int *)(ctx + 0x54) != 0) {
    surfaceIndex = 0;
    mapAddrPtr = ctx + 0x40;
    mapSizePtrOrBase = ctx + 0x44;
    do {
      cmdWrite = *(undefined4 **)(ctx + 0x34);
      if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x10) {
        lastHeader = *(uint **)(ctx + 0x30);
        *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
        *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
        **(undefined4 **)(ctx + 0x34) = 0x1000000;
        _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,mapAddrPtr,mapSizePtrOrBase,1);
        mapBase = *(int *)(ctx + 0x40);
        *(int *)(ctx + 0x34) = mapBase + 0x20;
        *(int *)(ctx + 0x30) = mapBase + 0x1c;
        *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
        *(undefined4 *)(mapBase + 0x1c) = 0;
        cmdWrite = *(undefined4 **)(ctx + 0x34);
      }
      lastHeader = *(uint **)(ctx + 0x30);
      *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x10;
      *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
      *(undefined4 **)(ctx + 0x30) = cmdWrite;
      *cmdWrite = 0x5000000;
      cmdWrite[1] = surfaceIndex;
      cmdWrite[2] = 0;
      cmdWrite[3] = 0;
      cmdWrite = *(undefined4 **)(ctx + 0x34);
      if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x10) {
        lastHeader = *(uint **)(ctx + 0x30);
        *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
        *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
        **(undefined4 **)(ctx + 0x34) = 0x1000000;
        _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,mapAddrPtr,mapSizePtrOrBase,1);
        mapBase = *(int *)(ctx + 0x40);
        *(int *)(ctx + 0x34) = mapBase + 0x20;
        *(int *)(ctx + 0x30) = mapBase + 0x1c;
        *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
        *(undefined4 *)(mapBase + 0x1c) = 0;
        cmdWrite = *(undefined4 **)(ctx + 0x34);
      }
      lastHeader = *(uint **)(ctx + 0x30);
      *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x10;
      *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
      *(undefined4 **)(ctx + 0x30) = cmdWrite;
      *cmdWrite = 0x6000000;
      cmdWrite[1] = surfaceIndex;
      cmdWrite[2] = 0;
      cmdWrite[3] = 0x80;
      if ((*(uint *)(ctx + 0x11c) & 1) != 0) {
        cmdWrite = *(undefined4 **)(ctx + 0x34);
        if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x10) {
          lastHeader = *(uint **)(ctx + 0x30);
          *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
          *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
          **(undefined4 **)(ctx + 0x34) = 0x1000000;
          _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,mapAddrPtr,mapSizePtrOrBase,1)
          ;
          mapBase = *(int *)(ctx + 0x40);
          *(int *)(ctx + 0x34) = mapBase + 0x20;
          *(int *)(ctx + 0x30) = mapBase + 0x1c;
          *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
          *(undefined4 *)(mapBase + 0x1c) = 0;
          cmdWrite = *(undefined4 **)(ctx + 0x34);
        }
        lastHeader = *(uint **)(ctx + 0x30);
        *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x10;
        *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
        *(undefined4 **)(ctx + 0x30) = cmdWrite;
        *cmdWrite = 0x5000000;
        cmdWrite[1] = surfaceIndex;
        cmdWrite[2] = 1;
        cmdWrite[3] = 0;
        cmdWrite = *(undefined4 **)(ctx + 0x34);
        if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x10) {
          lastHeader = *(uint **)(ctx + 0x30);
          *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
          *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
          **(undefined4 **)(ctx + 0x34) = 0x1000000;
          _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,mapAddrPtr,mapSizePtrOrBase,1)
          ;
          mapBase = *(int *)(ctx + 0x40);
          *(int *)(ctx + 0x34) = mapBase + 0x20;
          *(int *)(ctx + 0x30) = mapBase + 0x1c;
          *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
          *(undefined4 *)(mapBase + 0x1c) = 0;
          cmdWrite = *(undefined4 **)(ctx + 0x34);
        }
        lastHeader = *(uint **)(ctx + 0x30);
        *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x10;
        *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
        *(undefined4 **)(ctx + 0x30) = cmdWrite;
        *cmdWrite = 0x6000000;
        cmdWrite[1] = surfaceIndex;
        cmdWrite[2] = 1;
        cmdWrite[3] = 0x80;
      }
      surfaceIndex = surfaceIndex + 1;
    } while (surfaceIndex < *(uint *)(ctx + 0x54));
  }
  taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                      ctx + 0x44,1);
  mapSizePtrOrBase = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = mapSizePtrOrBase + 0x20;
  *(int *)(ctx + 0x30) = mapSizePtrOrBase + 0x1c;
  *(int *)(ctx + 0x38) = mapSizePtrOrBase + 0x20 + *(int *)(mapSizePtrOrBase + 0x10) * 4;
  *(undefined4 *)(mapSizePtrOrBase + 0x1c) = 0;
  ((int (*)())ava_render_slot)(ctx,0,(int)(char)*(undefined4 *)(ctx + 0x114),ctx + 0x10c,0);
  return;
}

/* ava_setup_subpicture @ 0x4fa0 (552 bytes) */
int ava_setup_subpicture(ctx, subpicParams)
  int ctx;
  uint *subpicParams;
{
  undefined4 status;
  int cursor;
  uint countOrAlignedWidth;
  int countOrStatus;
  uint index;
  int countdown;
  int outCountOrResult;
  int scalarIn0;
  uint scalarIn1;
  undefined4 scalarIn2;
  int scalarIn3;
  uint scalarIn4;
  
  countOrAlignedWidth = *subpicParams;
  *(uint *)(ctx + 0x5c) = countOrAlignedWidth;
  if (countOrAlignedWidth < 9) {
    *(undefined4 *)(ctx + 0x60) = 0x2d0;
    if ((*(int *)(ctx + 0x57c) == 0x240) || (*(int *)(ctx + 0x57c) == 0x120)) {
      *(undefined4 *)(ctx + 100) = 0x240;
    }
    else {
      *(undefined4 *)(ctx + 100) = 0x1e0;
    }
    countOrAlignedWidth = *(uint *)(ctx + 0x60);
    if ((countOrAlignedWidth & 0xff) != 0) {
      countOrAlignedWidth = (countOrAlignedWidth & 0xffffff00) + 0x100;
    }
    countOrStatus = *(int *)(ctx + 0x5c);
    *(uint *)(ctx + 0x68) = countOrAlignedWidth;
    if (countOrStatus != 0) {
      cursor = ctx;
      countdown = countOrStatus;
      if (countOrStatus == 0) {
        countdown = 1;
      }
      do {
        *(uint *)(cursor + 0x6c) = subpicParams[0x15];
        subpicParams = subpicParams + 1;
        *(uint *)(cursor + 0xbc) = *subpicParams;
        cursor = cursor + 4;
        countdown = countdown + -1;
      } while (countdown != 0);
    }
    countOrAlignedWidth = 0;
    if (countOrStatus != 0) {
      index = 0;
      cursor = ctx + 0x218;
      countOrStatus = ctx;
      do {
        countdown = ava_declare_image(ctx,cursor,*(undefined4 *)(countOrStatus + 0x538),0xc0,
                             *(undefined4 *)(ctx + 100),8,*(undefined4 *)(countOrStatus + 0x6c));
        if (countdown != 0) goto setStatus;
        countOrAlignedWidth = *(uint *)(ctx + 0x5c);
        index = index + 1;
        cursor = cursor + 100;
        countOrStatus = countOrStatus + 4;
      } while (index < countOrAlignedWidth);
    }
    outCountOrResult = ava_declare_image(ctx,ctx + 0x1b0,*(undefined4 *)(ctx + 0x214),0x20,countOrAlignedWidth,0x20
                            ,0);
    if (outCountOrResult == 0) {
      ((int (*)())ava_acquire_image)(ctx,3);
      scalarIn2 = *(undefined4 *)(ctx + 0x57c);
      scalarIn1 = *(undefined4 *)(ctx + 0x578);
      scalarIn4 = *(uint *)(ctx + 0xa84) | 0x10000;
      *(uint *)(ctx + 0xa84) = scalarIn4;
      scalarIn0 = outCountOrResult;
      scalarIn3 = outCountOrResult;
      countOrStatus = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(ctx + 0x14),0x15,&scalarIn0,5,0,&outCountOrResult);
      if (countOrStatus == 0) {
        scalarIn0 = *(int *)(ctx + 0xc);
        scalarIn1 = *(uint *)(ctx + 0x18) & 0xffff4000;
        scalarIn2 = 1;
        countOrStatus = _io_connect_method_scalarI_structureI
                          (*(undefined4 *)(ctx + 0x14),0,&scalarIn0,3,0,0);
        if (countOrStatus == 0) {
          return 0;
        }
      }
      status = 0xfffffffb;
    }
    else {
setStatus:
      status = 0xfffffffd;
    }
  }
  else {
    _puts("Number of subpicture bitmap exceed the maximum set.");
    status = 0xfffffffd;
  }
  return status;
}

/* ava_release_subpicture @ 0x51f0 (136 bytes) */
int ava_release_subpicture(ctx)
  int ctx;
{
  uint index;
  int mapping;
  
  ava_release_image(ctx,3);
  ava_delete_image(ctx,ctx + 0x1b0,1);
  if (*(int *)(ctx + 0x5c) != 0) {
    index = 0;
    mapping = ctx + 0x218;
    do {
      index = index + 1;
      ava_delete_image(ctx,mapping,0);
      mapping = mapping + 100;
    } while (index < *(uint *)(ctx + 0x5c));
  }
  return 0;
}

/* ava_set_macrovision @ 0x5280 (108 bytes) */
int ava_set_macrovision(ctx, value)
  int ctx;
  undefined4 value;
{
  undefined4 status;
  int kr;
  undefined4 outCount;
  undefined4 scalarIn0;
  undefined4 scalarIn1;
  
  outCount = 0;
  scalarIn0 = 0x92;
  scalarIn1 = value;
  kr = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(ctx + 0x14),0x10,&scalarIn0,2,0,&outCount);
  status = 0xfffffffb;
  if ((kr != -0x11) && (status = 0xfffffff9, kr != -0x32)) {
    status = 0;
  }
  return status;
}

/* ava_display_subpicture @ 0x52f0 (924 bytes) */
int ava_display_subpicture(ctx, subpicture, unused1, unused2, unused3)
  int ctx;
  byte *subpicture;
  undefined4 unused1;
  undefined4 unused2;
  undefined4 unused3;
{
  uint selector;
  undefined *taskPortPtr;
  uint *lastHeaderOrPalette;
  undefined4 status;
  undefined4 *destEntry;
  uint alphaOrOffset;
  uint *wordsBase;
  int mapBaseOrRectLeft;
  byte subpicIndex;
  int colorEntry;
  uint *wordsCursor;
  undefined4 *cmdWriteOrDst;
  uint shiftOrByteOffset;
  uint packedPalette;
  int rectRightOrCount;
  uint rectAndPalette [10];
  
  taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
  subpicIndex = *subpicture;
  if (*(int *)(ctx + 0x558) != (int)(char)subpicIndex) {
    cmdWriteOrDst = *(undefined4 **)(ctx + 0x34);
    if (*(undefined4 **)(ctx + 0x38) <= cmdWriteOrDst + 0x10) {
      lastHeaderOrPalette = *(uint **)(ctx + 0x30);
      *lastHeaderOrPalette = (int)cmdWriteOrDst - (int)lastHeaderOrPalette >> 2 | *lastHeaderOrPalette;
      *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
      **(undefined4 **)(ctx + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                          ctx + 0x44,1);
      mapBaseOrRectLeft = *(int *)(ctx + 0x40);
      *(int *)(ctx + 0x34) = mapBaseOrRectLeft + 0x20;
      *(int *)(ctx + 0x30) = mapBaseOrRectLeft + 0x1c;
      *(int *)(ctx + 0x38) = mapBaseOrRectLeft + 0x20 + *(int *)(mapBaseOrRectLeft + 0x10) * 4;
      *(undefined4 *)(mapBaseOrRectLeft + 0x1c) = 0;
      cmdWriteOrDst = *(undefined4 **)(ctx + 0x34);
    }
    lastHeaderOrPalette = *(uint **)(ctx + 0x30);
    *(undefined4 **)(ctx + 0x34) = cmdWriteOrDst + 0x10;
    *lastHeaderOrPalette = (int)cmdWriteOrDst - (int)lastHeaderOrPalette >> 2 | *lastHeaderOrPalette;
    *(undefined4 **)(ctx + 0x30) = cmdWriteOrDst;
    *cmdWriteOrDst = 0xd000000;
    cmdWriteOrDst[1] = 2;
    cmdWriteOrDst[2] = 1;
    taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
    lastHeaderOrPalette = *(uint **)(ctx + 0x30);
    *lastHeaderOrPalette = *(int *)(ctx + 0x34) - (int)lastHeaderOrPalette >> 2 | *lastHeaderOrPalette;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                        ctx + 0x44,1);
    mapBaseOrRectLeft = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBaseOrRectLeft + 0x20;
    *(int *)(ctx + 0x30) = mapBaseOrRectLeft + 0x1c;
    *(int *)(ctx + 0x38) = mapBaseOrRectLeft + 0x20 + *(int *)(mapBaseOrRectLeft + 0x10) * 4;
    *(undefined4 *)(mapBaseOrRectLeft + 0x1c) = 0;
    subpicIndex = *subpicture;
  }
  *(int *)(ctx + 0x558) = (int)(char)subpicIndex;
  status = *(undefined4 *)(subpicture + 0x12);
  *(undefined4 *)(ctx + 0x110) = *(undefined4 *)(subpicture + 0x16);
  *(undefined4 *)(ctx + 0x10c) = status;
  mapBaseOrRectLeft = (int)*(short *)(subpicture + 2);
  rectRightOrCount = (int)*(short *)(subpicture + 6);
  packedPalette = *(uint *)(subpicture + 0x28);
  rectAndPalette[0] = *(uint *)(subpicture + 2);
  rectAndPalette[1] = *(uint *)(subpicture + 6);
  if ((((rectRightOrCount - mapBaseOrRectLeft < 1) || ((int)*(short *)(subpicture + 8) - (int)*(short *)(subpicture + 4) < 1))
      || (rectRightOrCount < 0)) ||
     (((mapBaseOrRectLeft < 0 || (*(short *)(subpicture + 8) < 0)) || (*(short *)(subpicture + 4) < 0)))) {
    status = 0xfffffff9;
  }
  else {
    mapBaseOrRectLeft = *(int *)(subpicture + 0x2c);
    shiftOrByteOffset = 0;
    lastHeaderOrPalette = rectAndPalette + 2;
    rectRightOrCount = 4;
    do {
      alphaOrOffset = 0xff;
      selector = packedPalette >> (shiftOrByteOffset & 0x3f) & 0xf;
      colorEntry = mapBaseOrRectLeft + (packedPalette >> (shiftOrByteOffset + 0x10 & 0x3f) & 0xf) * 4;
      if (selector != 0xf) {
        alphaOrOffset = selector * 0xf;
      }
      *(uint *)(shiftOrByteOffset + (int)lastHeaderOrPalette) =
           alphaOrOffset | (uint)*(byte *)(colorEntry + 3) << 0x18 | (uint)*(byte *)(colorEntry + 2) << 0x10 |
                   (uint)*(byte *)(colorEntry + 1) << 8;
      shiftOrByteOffset = shiftOrByteOffset + 4;
      rectRightOrCount = rectRightOrCount + -1;
    } while (rectRightOrCount != 0);
    status = 0x10;
    packedPalette = 0;
    wordsBase = rectAndPalette;
    mapBaseOrRectLeft = 0x10;
    subpictureSlotIndex_0000f1ac = (subpictureSlotIndex_0000f1ac + 1U) -
                   ((subpictureSlotIndex_0000f1ac + 1U) / *(uint *)(ctx + 0x5c)) * *(uint *)(ctx + 0x5c);
    cmdWriteOrDst = (undefined4 *)((*(int *)(ctx + 0x1b0) + 0xffU & 0xffffff00) + subpictureSlotIndex_0000f1ac * 0x80)
    ;
    do {
      destEntry = cmdWriteOrDst;
      shiftOrByteOffset = packedPalette & 0xfffffffc;
      selector = packedPalette & 3;
      packedPalette = packedPalette + 1;
      wordsCursor = wordsBase + selector;
      *destEntry = *(undefined4 *)((int)rectAndPalette + shiftOrByteOffset + 8);
      destEntry[1] = rectAndPalette[selector + 2];
      mapBaseOrRectLeft = mapBaseOrRectLeft + -1;
      cmdWriteOrDst = destEntry + 2;
    } while (mapBaseOrRectLeft != 0);
    ((int (*)())ava_dcache_flush_range)(ctx,destEntry + -0x1e,0x80,lastHeaderOrPalette,0x10,wordsBase,wordsCursor,packedPalette);
    ((int (*)())ava_dcache_flush_range)(ctx,*(undefined4 *)((char)*subpicture * 4 + ctx + 0x6c),
                 *(int *)(ctx + 100) * 0xc0,lastHeaderOrPalette,status,wordsBase,wordsCursor,packedPalette);
    ((int (*)())ava_acquire_image)(ctx,*subpicture + 4 & 0xff);
    ((int (*)())ava_render_subpicture_pass)(ctx,rectAndPalette[0],rectAndPalette[1],(char)*subpicture + 4,subpictureSlotIndex_0000f1ac);
    ava_release_image(ctx,*subpicture + 4 & 0xff);
    status = 0;
  }
  return status;
}

/* ava_dvd_ext_emit_packet_0d @ 0x56a0 (512 bytes) */
int ava_dvd_ext_emit_packet_0d(ctx, slotId)
  int ctx;
  int slotId;
{
  undefined *mapMemoryType;
  uint *lastHeader;
  int mapBase;
  undefined4 *cmdWrite;
  
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  if (slotId == *(int *)(ctx + 0x558)) {
    cmdWrite = *(undefined4 **)(ctx + 0x34);
    if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x10) {
      lastHeader = *(uint **)(ctx + 0x30);
      *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
      *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
      **(undefined4 **)(ctx + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                          ctx + 0x44,1);
      mapBase = *(int *)(ctx + 0x40);
      *(int *)(ctx + 0x34) = mapBase + 0x20;
      *(int *)(ctx + 0x30) = mapBase + 0x1c;
      *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
      *(undefined4 *)(mapBase + 0x1c) = 0;
      cmdWrite = *(undefined4 **)(ctx + 0x34);
    }
    lastHeader = *(uint **)(ctx + 0x30);
    *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x10;
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = cmdWrite;
    *cmdWrite = 0xd000000;
    cmdWrite[1] = 2;
    cmdWrite[2] = 1;
    cmdWrite[3] = *(undefined4 *)(ctx + 0x60);
    cmdWrite[4] = *(undefined4 *)(ctx + 100);
    cmdWrite[5] = *(undefined4 *)(ctx + 0x68);
    mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                        ctx + 0x44,1);
    mapBase = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBase + 0x20;
    *(int *)(ctx + 0x30) = mapBase + 0x1c;
    *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
    *(undefined4 *)(mapBase + 0x1c) = 0;
  }
  if ((*(uint *)(*(int *)(ctx + 0x40) + 0x14) & 2) != 0) {
    (**(code **)(*(int *)(*(int *)(ctx + 0x50) + 0xc) + 0xc))
              (*(undefined4 *)(ctx + 4),*(undefined4 *)(ctx + 8),
               *(undefined4 *)(ctx + 0xc));
  }
  return 0;
}

/* ava_init_context_state @ 0x58b0 (1196 bytes) */
int ava_init_context_state(ctx)
  int ctx;
{
  int ringBBody;
  int ringBase;
  int ringALength;
  int setupBuf;
  
  ringBase = *(int *)(ctx + 0x40);
  setupBuf = *(int *)(ctx + 0x48);
  *(int *)(ctx + 0x34) = ringBase + 0x20;
  *(int *)(ctx + 0x30) = ringBase + 0x1c;
  *(int *)(ctx + 0x38) = ringBase + 0x20 + *(int *)(ringBase + 0x10) * 4;
  *(undefined4 *)(ringBase + 0x1c) = 0;
  ringBase = *(int *)(ctx + 0x14554) + 0x20;
  ringBBody = *(int *)(ctx + 0x1455c) + 0x20;
  *(int *)(ctx + 0x1511c) = ringBase;
  *(int *)(ctx + 0x15124) = ringBase;
  ringALength = *(int *)(*(int *)(ctx + 0x14554) + 0x10);
  *(int *)(ctx + 0x15140) = ringBBody;
  *(int *)(ctx + 0x15148) = ringBBody;
  *(int *)(ctx + 0x15120) = ringALength * 4 + ringBase + -4;
  *(int *)(ctx + 0x15144) = *(int *)(*(int *)(ctx + 0x1455c) + 0x10) * 4 + ringBBody + -4;
  *(uint *)(setupBuf + 0x1c) = *(uint *)(setupBuf + 0x1c) | 1;
  *(undefined4 *)(setupBuf + 0x20) = 0x10a4;
  *(undefined4 *)(setupBuf + 0x24) = 0;
  *(undefined4 *)(setupBuf + 0x28) = 0x10a3;
  *(undefined4 *)(setupBuf + 0x2c) = 5;
  *(undefined4 *)(setupBuf + 0x30) = 0x10a2;
  *(undefined4 *)(setupBuf + 0x34) = 0;
  *(undefined4 *)(setupBuf + 0x38) = 0x850;
  *(undefined4 *)(setupBuf + 0x3c) = 0x102;
  *(undefined4 *)(setupBuf + 0x40) = 0x8a1;
  *(undefined4 *)(setupBuf + 0x44) = 0;
  *(undefined4 *)(setupBuf + 0x48) = 0x820;
  *(undefined4 *)(setupBuf + 0x4c) = 0x300856;
  *(undefined4 *)(setupBuf + 0x50) = 0x887;
  *(undefined4 *)(setupBuf + 0x54) = 0x10000;
  *(undefined4 *)(setupBuf + 0x58) = 0x82c;
  *(undefined4 *)(setupBuf + 0x5c) = 0x300;
  *(undefined4 *)(setupBuf + 0x60) = 0x84d;
  *(undefined4 *)(setupBuf + 100) = 0xffff;
  *(undefined4 *)(setupBuf + 0x68) = 0x84e;
  *(undefined4 *)(setupBuf + 0x6c) = 0;
  *(undefined4 *)(setupBuf + 0x70) = 0x877;
  *(undefined4 *)(setupBuf + 0x74) = 0;
  *(undefined4 *)(setupBuf + 0x78) = 0x888;
  *(undefined4 *)(setupBuf + 0x7c) = 0x3f800000;
  *(undefined4 *)(setupBuf + 0x80) = 0x889;
  *(undefined4 *)(setupBuf + 0x84) = 0x3f800000;
  *(undefined4 *)(setupBuf + 0x88) = 0x88a;
  *(undefined4 *)(setupBuf + 0x8c) = 0x3f800000;
  *(undefined4 *)(setupBuf + 0x90) = 0x88b;
  *(undefined4 *)(setupBuf + 0x94) = 0x3f800000;
  *(undefined **)(setupBuf + 0x98) = ((unsigned char *)0x00001002U);
  *(undefined4 *)(setupBuf + 0x9c) = 0;
  *(undefined **)(setupBuf + 0xa0) = ((unsigned char *)0x00001008U);
  *(undefined4 *)(setupBuf + 0xa4) = 0;
  *(undefined **)(setupBuf + 0xa8) = ((unsigned char *)0x00001004U);
  *(undefined4 *)(setupBuf + 0xac) = 0x78888888;
  *(undefined **)(setupBuf + 0xb0) = ((unsigned char *)0x00001005U);
  *(undefined4 *)(setupBuf + 0xb4) = 0x8888888;
  *(undefined4 *)(setupBuf + 0xb8) = 0x10a8;
  *(undefined4 *)(setupBuf + 0xbc) = 0;
  *(undefined4 *)(setupBuf + 0xc0) = 0x10ae;
  *(undefined4 *)(setupBuf + 0xc4) = 0;
  *(undefined4 *)(setupBuf + 200) = 0x12f5;
  *(undefined4 *)(setupBuf + 0xcc) = 0;
  *(undefined4 *)(setupBuf + 0xd0) = 0x1394;
  *(undefined4 *)(setupBuf + 0xd4) = 0;
  *(undefined4 *)(setupBuf + 0xd8) = 0x12f0;
  *(undefined4 *)(setupBuf + 0xdc) = 0;
  *(undefined4 *)(setupBuf + 0xe0) = 0x13c0;
  *(undefined4 *)(setupBuf + 0xe4) = 0;
  *(undefined4 *)(setupBuf + 0xe8) = 0x13c7;
  *(undefined4 *)(setupBuf + 0xec) = 0;
  *(undefined4 *)(setupBuf + 0xf0) = 0x1381;
  *(undefined4 *)(setupBuf + 0xf4) = 0;
  *(undefined4 *)(setupBuf + 0xf8) = 0x1383;
  *(undefined4 *)(setupBuf + 0xfc) = 0xf;
  *(undefined4 *)(setupBuf + 0x100) = 0x1386;
  *(undefined4 *)(setupBuf + 0x104) = 0;
  *(undefined4 *)(setupBuf + 0x108) = 0x10e9;
  *(undefined4 *)(setupBuf + 0x10c) = 0;
  *(undefined4 *)(setupBuf + 0x110) = 0x10ea;
  *(undefined4 *)(setupBuf + 0x114) = 0xa5294a5;
  *(undefined4 *)(setupBuf + 0x118) = 0x10f8;
  *(undefined4 *)(setupBuf + 0x11c) = 0;
  *(undefined4 *)(setupBuf + 0x120) = 0x10f9;
  *(undefined4 *)(setupBuf + 0x124) = 0x3ffffff;
  *(undefined4 *)(setupBuf + 0x128) = 0x10ec;
  *(undefined4 *)(setupBuf + 300) = 0;
  *(undefined4 *)(setupBuf + 0x130) = 0x10ed;
  *(undefined4 *)(setupBuf + 0x134) = 0x3ffffff;
  *(undefined4 *)(setupBuf + 0x138) = 0x10ee;
  *(undefined4 *)(setupBuf + 0x13c) = 0;
  *(undefined4 *)(setupBuf + 0x140) = 0x10ef;
  *(undefined4 *)(setupBuf + 0x144) = 0x3ffffff;
  *(undefined4 *)(setupBuf + 0x148) = 0x10f0;
  *(undefined4 *)(setupBuf + 0x14c) = 0;
  *(undefined4 *)(setupBuf + 0x150) = 0x10f1;
  *(undefined4 *)(setupBuf + 0x154) = 0x3ffffff;
  *(undefined4 *)(setupBuf + 0x158) = 0x10f2;
  *(undefined4 *)(setupBuf + 0x15c) = 0;
  *(undefined4 *)(setupBuf + 0x160) = 0x10f3;
  *(undefined4 *)(setupBuf + 0x164) = 0x3ffffff;
  *(undefined4 *)(setupBuf + 0x168) = 0x10f4;
  *(undefined4 *)(setupBuf + 0x16c) = 0xffff;
  *(undefined4 *)(setupBuf + 0x170) = 0x10fa;
  *(undefined4 *)(setupBuf + 0x174) = 0xffffff;
  *(undefined4 *)(setupBuf + 0x178) = 0x10fb;
  *(undefined4 *)(setupBuf + 0x17c) = 0;
  *(int *)(setupBuf + 0x14) = (setupBuf + 0x180) - (setupBuf + 0x20) >> 2;
  return;
}

/* ava_noop_5d60 @ 0x5d60 (4 bytes) */
int ava_noop_5d60()
{
  return;
}

/* ava_build_block_grid @ 0x5d70 (600 bytes) */
int ava_build_block_grid(ctx, unused1, unused2, rowOrScratch, unused3, unused4, unused5, colOrScratch)
  int ctx;
  undefined4 unused1;
  undefined4 unused2;
  uint rowOrScratch;
  undefined4 unused3;
  undefined4 unused4;
  undefined4 unused5;
  uint colOrScratch;
{
  int sectionWords;
  uint *quadCursor;
  uint topLeft;
  uint row;
  uint width;
  uint quadCount;
  uint *rowStart;
  uint topRight;
  uint yBottomShifted;
  uint height;
  
  height = *(uint *)(ctx + 0x57c);
  width = *(uint *)(ctx + 0x578);
  quadCursor = (uint *)(*(int *)(ctx + 0x15394) + 0xffU & 0xffffff00);
  if (height == 0) {
    quadCount = 0;
    sectionWords = 0;
  }
  else {
    row = 0;
    quadCount = 0;
    rowStart = quadCursor;
    do {
      quadCursor = rowStart;
      if (width != 0) {
        rowOrScratch = row << 0x10;
        colOrScratch = 0;
        yBottomShifted = (row + 0x10) * 0x10000;
        topLeft = rowOrScratch;
        topRight = yBottomShifted;
        do {
          *(uint *)((int)rowStart + colOrScratch) = topLeft;
          colOrScratch = colOrScratch + 0x10;
          quadCursor[1] = topRight;
          quadCount = quadCount + 1;
          topRight = colOrScratch | yBottomShifted;
          topLeft = colOrScratch | rowOrScratch;
          quadCursor[2] = topRight;
          quadCursor[3] = topLeft;
          quadCursor = quadCursor + 4;
        } while (colOrScratch < width);
      }
      row = row + 0x10;
      rowStart = quadCursor;
    } while (row < height);
    sectionWords = quadCount << 2;
  }
  *(int *)(ctx + 0x153fc) = sectionWords;
  if (height != 0) {
    row = 0;
    rowStart = quadCursor;
    do {
      quadCursor = rowStart;
      if (width != 0) {
        rowOrScratch = row << 0x10;
        colOrScratch = 0;
        yBottomShifted = (row + 8) * 0x10000;
        topLeft = rowOrScratch;
        topRight = yBottomShifted;
        do {
          *(uint *)((int)rowStart + colOrScratch) = topLeft;
          colOrScratch = colOrScratch + 0x10;
          quadCursor[1] = topRight;
          quadCount = quadCount + 1;
          topRight = colOrScratch | yBottomShifted;
          topLeft = colOrScratch | rowOrScratch;
          quadCursor[2] = topRight;
          quadCursor[3] = topLeft;
          quadCursor = quadCursor + 4;
        } while (colOrScratch < width);
      }
      row = row + 8;
      rowStart = quadCursor;
    } while (row < height);
    sectionWords = quadCount << 2;
  }
  height = height >> 1;
  width = width >> 1;
  *(int *)(ctx + 0x15400) = sectionWords;
  if (height != 0) {
    row = 0;
    do {
      if (width != 0) {
        rowOrScratch = row << 0x10;
        topRight = 0;
        colOrScratch = (row + 8) * 0x10000;
        yBottomShifted = colOrScratch;
        topLeft = rowOrScratch;
        do {
          topRight = topRight + 8;
          *quadCursor = topLeft;
          quadCursor[1] = yBottomShifted;
          topLeft = topRight | rowOrScratch;
          yBottomShifted = topRight | colOrScratch;
          quadCount = quadCount + 1;
          quadCursor[3] = topLeft;
          quadCursor[2] = yBottomShifted;
          quadCursor = quadCursor + 4;
        } while (topRight < width);
      }
      row = row + 8;
    } while (row < height);
    sectionWords = quadCount << 2;
  }
  *(int *)(ctx + 0x15404) = sectionWords;
  if (height != 0) {
    rowOrScratch = 0;
    do {
      if (width != 0) {
        quadCount = rowOrScratch << 0x10;
        topLeft = 0;
        colOrScratch = (rowOrScratch + 4) * 0x10000;
        row = colOrScratch;
        yBottomShifted = quadCount;
        do {
          topLeft = topLeft + 8;
          *quadCursor = yBottomShifted;
          quadCursor[1] = row;
          yBottomShifted = topLeft | quadCount;
          row = topLeft | colOrScratch;
          quadCursor[3] = yBottomShifted;
          quadCursor[2] = row;
          quadCursor = quadCursor + 4;
        } while (topLeft < width);
      }
      rowOrScratch = rowOrScratch + 4;
    } while (rowOrScratch < height);
  }
  ((int (*)())ava_dcache_flush_range)(ctx,*(int *)(ctx + 0x15394) + 0xffU & 0xffffff00,
               *(int *)(ctx + 0x153a8) * *(int *)(ctx + 0x153ac),rowOrScratch,width,quadCount,quadCursor,
               colOrScratch);
  return;
}

/* ava_submit_idct_list @ 0x5fd0 (320 bytes) */
int ava_submit_idct_list(ctx, listSelect)
  int ctx;
  int listSelect;
{
  bool isSecondList;
  uint modeBits;
  int status;
  uint requestHeight;
  undefined4 outResult;
  undefined4 requestInterlace;
  undefined4 requestFlag;
  undefined4 requestSurface;
  int requestList;
  int requestWordCount;
  uint requestFlags;
  undefined4 requestExtra;
  uint requestSize;
  
  isSecondList = listSelect != 0;
  outResult = 0;
  if (isSecondList) {
    requestWordCount = *(int *)(ctx + 0x15148) - *(int *)(ctx + 0x15140);
  }
  else {
    requestWordCount = *(int *)(ctx + 0x15124) - *(int *)(ctx + 0x1511c);
  }
  requestWordCount = requestWordCount >> 2;
  if (requestWordCount == 0) {
    return 1;
  }
  if (*(int *)(ctx + 0x55c) == 3) {
    requestHeight = *(uint *)(ctx + 0x57c);
    requestInterlace = 0;
  }
  else {
    requestInterlace = 1;
    requestHeight = *(uint *)(ctx + 0x57c) >> 1;
    if (*(int *)(ctx + 0x55c) == 2) {
      requestFlag = 1;
      goto setRequestSurface;
    }
  }
  requestFlag = 0;
setRequestSurface:
  requestSurface = *(undefined4 *)(ctx + 0x568);
  if (isSecondList) {
    modeBits = 0;
  }
  else {
    modeBits = 0x20;
  }
  requestFlags = modeBits | (*(byte *)(ctx + 0x564) & 3) << 3 | 0x10080;
  if (isSecondList) {
    requestExtra = 0x8000;
  }
  else {
    requestExtra = 0;
  }
  requestSize = requestHeight << 0x10 | *(uint *)(ctx + 0x578);
  requestList = listSelect;
  status = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(ctx + 0x14),0x12,&requestInterlace,0x38,0,&outResult);
  if (status == 0) {
    return 1;
  }
  return 0;
}

/* ava_submit_idct_list_and_remap @ 0x6120 (252 bytes) */
int ava_submit_idct_list_and_remap(ctx, listSelect)
  int ctx;
  int listSelect;
{
  int bufferStart;
  undefined4 submitResult;
  int mappedBase;
  
  submitResult = ((int (*)())ava_submit_idct_list)(ctx,listSelect);
  if (listSelect == 0) {
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),4,*(undefined4 *)ptrTo_machTaskSelf_0000f1a0,
                        ctx + 0x14554,ctx + 0x14558,1);
    mappedBase = *(int *)(ctx + 0x14554);
    bufferStart = mappedBase + 0x20;
    *(int *)(ctx + 0x1511c) = bufferStart;
    *(int *)(ctx + 0x15124) = bufferStart;
    *(int *)(ctx + 0x15120) = *(int *)(mappedBase + 0x10) * 4 + bufferStart + -4;
    *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + ctx + 0xac8) = *(undefined4 *)(mappedBase + 0x18)
    ;
  }
  else {
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),5,*(undefined4 *)ptrTo_machTaskSelf_0000f1a0,
                        ctx + 0x1455c,ctx + 0x14560,1);
    bufferStart = *(int *)(ctx + 0x1455c) + 0x20;
    *(int *)(ctx + 0x15140) = bufferStart;
    *(int *)(ctx + 0x15148) = bufferStart;
    *(int *)(ctx + 0x15144) = *(int *)(*(int *)(ctx + 0x1455c) + 0x10) * 4 + bufferStart + -4;
  }
  return submitResult;
}

/* ava_build_stage_program @ 0x6230 (2900 bytes) */
int ava_build_stage_program(ctx, outProgram, variant, halfHeight)
  int ctx;
  undefined4 *outProgram;
  int variant;
  int halfHeight;
{
  uint mbPitchWords;
  undefined4 *program;
  undefined4 *programEnd;
  uint mbHeight;
  uint chromaWidthMinus1;
  int uvTable;
  int widthMbOrTmp;
  int pitch;
  uint heightOrHalfPitch;
  int width;
  uint widthMinus1OrHeight;
  
  widthMbOrTmp = *(int *)(ctx + 0x580);
  if (halfHeight == 0) {
    mbHeight = *(uint *)(ctx + 0x584);
  }
  else {
    mbHeight = *(uint *)(ctx + 0x584) >> 1;
  }
  mbPitchWords = *(uint *)(ctx + 0x58c) >> 2;
  if (variant == 1) {
    pitch = *(int *)(ctx + 0x588);
    width = *(int *)(ctx + 0x578);
    heightOrHalfPitch = *(uint *)(ctx + 0x57c);
    uvTable = ctx + 0x152b4;
    program = (undefined4 *)((int (*)())ava_emit_state_preamble)(outProgram);
    *program = 0x850;
    program[1] = 0x102;
    program[2] = 0x830;
    program[3] = 2;
    program[4] = 0x831;
    program[5] = 0x1010101;
    program[6] = 0x854;
    program[7] = 0x26060006;
    program[8] = 0x878;
    program[9] = 0xf688f688;
    program[10] = 0x824;
    program[0xb] = 1;
    program[0xc] = 0x825;
    program[0xd] = 2;
    program[0xe] = ((unsigned char *)0x0000101dU);
    program[0xf] = 0x28ffe040;
    program[0x10] = 0x10c8;
    program[0x11] = 0x50;
    program[0x12] = 0x000010c0;
    program[0x13] = 0x40002;
    program[0x14] = 0x10c1;
    program[0x15] = 0;
    program[0x16] = 0x1100;
    program[0x17] = 0x30000a92;
    program[0x18] = 0x1101;
    program[0x19] = 0x40000a92;
    program[0x1a] = 0x1102;
    program[0x1b] = 0x30000a92;
    program[0x1c] = 0x1103;
    program[0x1d] = 0x40000a92;
    program[0x1e] = 0x110a;
    program[0x1f] = 0x20000a92;
    program[0x20] = 0x110b;
    program[0x21] = 0x20000a92;
    program[0x22] = 0x110c;
    program[0x23] = 0x20000a92;
    program[0x24] = 0x1104;
    program[0x25] = 0x1492;
    program[0x26] = 0x1105;
    program[0x27] = 0x1492;
    program[0x28] = 0x1106;
    program[0x29] = 0x1492;
    program[0x2a] = 0x1107;
    program[0x2b] = 0x10001492;
    program[0x2c] = 0x1108;
    program[0x2d] = 0x10001492;
    program[0x2e] = 0x1109;
    program[0x2f] = 0x10001492;
    program[0x30] = 0x1110;
    program[0x31] = 0;
    program[0x32] = 0x1111;
    program[0x33] = 0;
    program[0x34] = 0x1112;
    program[0x35] = 0;
    program[0x36] = 0x1113;
    program[0x37] = 0;
    program[0x38] = 0x111a;
    program[0x39] = 0;
    program[0x3a] = 0x111b;
    program[0x3b] = 0;
    program[0x3c] = 0x111c;
    program[0x3d] = 0;
    program[0x3e] = 0x1114;
    program[0x3f] = 0x4000;
    program[0x40] = 0x1115;
    program[0x41] = 0x4000;
    program[0x42] = 0x1116;
    program[0x43] = 0x4000;
    program[0x44] = 0x1117;
    program[0x45] = 0x4000;
    program[0x46] = 0x1118;
    program[0x47] = 0x4000;
    program[0x48] = 0x1119;
    program[0x49] = 0x4000;
    mbHeight = (mbHeight - 1) * 0x800 | widthMbOrTmp - 1U | 0x80000000;
    program[0x4a] = 0x1120;
    program[0x4b] = mbHeight;
    program[0x4c] = 0x1121;
    program[0x4d] = mbHeight;
    program[0x4e] = 0x1122;
    program[0x4f] = mbHeight;
    program[0x50] = 0x1123;
    program[0x51] = mbHeight;
    widthMinus1OrHeight = width - 1;
    mbHeight = (heightOrHalfPitch - 1) * 0x800 | widthMinus1OrHeight | 0x80000000;
    program[0x52] = 0x1124;
    program[0x53] = mbHeight;
    program[0x54] = 0x1127;
    program[0x55] = mbHeight;
    program[0x56] = 0x112a;
    program[0x57] = mbHeight;
    mbHeight = widthMinus1OrHeight | ((heightOrHalfPitch >> 1) - 1) * 0x800 | 0x80000000;
    program[0x58] = 0x1125;
    program[0x59] = mbHeight;
    program[0x5a] = 0x1126;
    program[0x5b] = mbHeight;
    program[0x5c] = 0x1128;
    program[0x5d] = mbHeight;
    program[0x5e] = 0x1129;
    program[0x5f] = mbHeight;
    program[0x60] = 0x112b;
    program[0x61] = mbHeight;
    program[0x62] = 0x112c;
    program[99] = mbHeight;
    program[100] = 0x1130;
    program[0x65] = 0x80108be4;
    program[0x66] = 0x1131;
    program[0x67] = 0x88108be4;
    program[0x68] = 0x1132;
    program[0x69] = 0x90108be4;
    program[0x6a] = 0x1133;
    program[0x6b] = 0x98108be4;
    program[0x6c] = 0x1134;
    program[0x6d] = 0xa0104000;
    program[0x6e] = 0x1135;
    program[0x6f] = 0xa8104000;
    program[0x70] = 0x1136;
    program[0x71] = 0xb0104000;
    program[0x72] = 0x1137;
    program[0x73] = 0xb8104000;
    program[0x74] = 0x1138;
    program[0x75] = 0xc0104000;
    program[0x76] = 0x1139;
    program[0x77] = 0xc8104000;
    program[0x78] = 0x113a;
    program[0x79] = 0xd0104036;
    program[0x7a] = 0x113b;
    program[0x7b] = 0xd8104036;
    program[0x7c] = 0x113c;
    program[0x7d] = 0xe0104036;
    program[0x7e] = 0x1140;
    widthMbOrTmp = mbPitchWords - 1;
    program[0x7f] = widthMbOrTmp;
    program[0x80] = 0x1141;
    program[0x81] = widthMbOrTmp;
    program[0x82] = 0x1142;
    program[0x83] = widthMbOrTmp;
    program[0x84] = 0x1143;
    program[0x85] = widthMbOrTmp;
    program[0x86] = 0x114a;
    program[0x87] = pitch + -1;
    program[0x88] = 0x114b;
    widthMbOrTmp = pitch * 2 + -1;
    program[0x89] = widthMbOrTmp;
    program[0x8a] = 0x114c;
    program[0x8b] = widthMbOrTmp;
    program[0x8c] = 0x1180;
    program[0x8d] = 0;
    program[0x8e] = 0x11ad;
    program[0x8f] = 0;
    program[0x90] = 0x1189;
    program[0x91] = 0;
    program[0x92] = 0x1181;
    program[0x93] = 5;
    program[0x94] = 0x11a9;
    program[0x95] = 0x0000aa00;
    program[0x96] = 0x11aa;
    program[0x97] = 0xf;
    program[0x98] = 0x11ab;
    program[0x99] = 0xf;
    program[0x9a] = 0x11ac;
    programEnd = program + 0x9c;
    program[0x9b] = 0xf;
  }
  else {
    widthMinus1OrHeight = *(uint *)(ctx + 0x57c);
    uvTable = ctx + 0x15324;
    heightOrHalfPitch = *(uint *)(ctx + 0x588) >> 1;
    mbHeight = (mbHeight - 1) * 0x800 | widthMbOrTmp - 1U | 0x80000000;
    *outProgram = 0x1120;
    outProgram[1] = mbHeight;
    outProgram[2] = 0x1121;
    outProgram[3] = mbHeight;
    outProgram[4] = 0x1122;
    outProgram[5] = mbHeight;
    outProgram[6] = 0x1123;
    outProgram[7] = mbHeight;
    chromaWidthMinus1 = (*(uint *)(ctx + 0x578) >> 1) - 1;
    mbHeight = ((widthMinus1OrHeight >> 1) - 1) * 0x800 | chromaWidthMinus1 | 0x80000000;
    outProgram[8] = 0x1124;
    outProgram[9] = mbHeight;
    outProgram[10] = 0x1127;
    outProgram[0xb] = mbHeight;
    outProgram[0xc] = 0x112a;
    outProgram[0xd] = mbHeight;
    mbHeight = chromaWidthMinus1 | ((widthMinus1OrHeight >> 2) - 1) * 0x800 | 0x80000000;
    outProgram[0xe] = 0x1125;
    outProgram[0xf] = mbHeight;
    outProgram[0x10] = 0x1126;
    outProgram[0x11] = mbHeight;
    outProgram[0x12] = 0x1128;
    outProgram[0x13] = mbHeight;
    outProgram[0x14] = 0x1129;
    outProgram[0x15] = mbHeight;
    outProgram[0x16] = 0x112b;
    outProgram[0x17] = mbHeight;
    outProgram[0x18] = 0x112c;
    outProgram[0x19] = mbHeight;
    outProgram[0x1a] = 0x1130;
    outProgram[0x1b] = 0x80108064;
    outProgram[0x1c] = 0x1131;
    outProgram[0x1d] = 0x88108064;
    outProgram[0x1e] = 0x1132;
    outProgram[0x1f] = 0x90108064;
    outProgram[0x20] = 0x1133;
    outProgram[0x21] = 0x98108064;
    outProgram[0x22] = 0x1134;
    outProgram[0x23] = 0xa0060003;
    outProgram[0x24] = 0x1135;
    outProgram[0x25] = 0xa8060003;
    outProgram[0x26] = 0x1136;
    outProgram[0x27] = 0xb0060003;
    outProgram[0x28] = 0x1137;
    outProgram[0x29] = 0xb8060003;
    outProgram[0x2a] = 0x1138;
    outProgram[0x2b] = 0xc0060003;
    outProgram[0x2c] = 0x1139;
    outProgram[0x2d] = 0xc8060003;
    outProgram[0x2e] = 0x113a;
    outProgram[0x2f] = 0xd0060077;
    outProgram[0x30] = 0x113b;
    outProgram[0x31] = 0xd8060077;
    outProgram[0x32] = 0x113c;
    outProgram[0x33] = 0xe0060077;
    outProgram[0x34] = 0x1140;
    widthMbOrTmp = mbPitchWords - 1;
    outProgram[0x35] = widthMbOrTmp;
    outProgram[0x36] = 0x1141;
    outProgram[0x37] = widthMbOrTmp;
    outProgram[0x38] = 0x1142;
    outProgram[0x39] = widthMbOrTmp;
    outProgram[0x3a] = 0x1143;
    outProgram[0x3b] = widthMbOrTmp;
    outProgram[0x3c] = 0x114a;
    outProgram[0x3d] = heightOrHalfPitch - 1;
    outProgram[0x3e] = 0x114b;
    widthMbOrTmp = heightOrHalfPitch * 2 + -1;
    outProgram[0x3f] = widthMbOrTmp;
    outProgram[0x40] = 0x114c;
    outProgram[0x41] = widthMbOrTmp;
    outProgram[0x42] = 0x11a9;
    programEnd = outProgram + 0x44;
    outProgram[0x43] = 0x1b00;
  }
  widthMbOrTmp = ((int (*)())ava_emit_us_vector_data)(programEnd,0x10000,0x1c,uvTable);
  return widthMbOrTmp - (int)outProgram >> 2;
}

/* ava_build_stage_programs @ 0x6d90 (644 bytes) */
void ava_build_stage_programs(int ctx,double fpArg1,double fpArg2,double fpArg3,double fpArg4,double fpArg5,double fpArg6,double fpArg7,double fpArg8,double fpArg9,double fpArg10)
{
  float widthF;
  float heightF;
  float halfHeightF;
  float kTwoThenInvHeight;
  float s16MaxOverTwoWidth;
  float twoOverWidth;
  float oneAndHalfOverFourWidth;
  uint halfHeightAligned;
  double intToDoubleMagic;
  float kOne;
  float kFour;
  float kInv255;
  float kS16Max;
  float kEight;
  float kOnePointFive;
  undefined4 programHandle;
  undefined4 savedHeight;
  
  kTwoThenInvHeight = FLOAT_0000d458;
  kOnePointFive = FLOAT_0000d454;
  kEight = FLOAT_0000d450;
  kS16Max = FLOAT_0000d44c;
  kFour = FLOAT_0000d444;
  kOne = FLOAT_0000d43c;
  intToDoubleMagic = DOUBLE_0000d418;
  halfHeightAligned = (*(uint *)(ctx + 0x57c) >> 1) + 0xf & 0xfffffff0;
  *(float *)(ctx + 0x152cc) = FLOAT_0000d43c;
  *(float *)(ctx + 0x152d0) = kOne;
  kInv255 = FLOAT_0000d448;
  *(float *)(ctx + 0x152b4) = FLOAT_0000d448;
  *(float *)(ctx + 0x152b8) = kInv255;
  *(undefined4 *)(ctx + 0x152dc) = 0;
  *(undefined4 *)(ctx + 0x152e0) = 0;
  *(float *)(ctx + 0x152bc) = kInv255;
  *(float *)(ctx + 0x152c0) = kInv255;
  *(float *)(ctx + 0x152ec) = kOne;
  *(float *)(ctx + 0x152f0) = kOne;
  widthF = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(ctx + 0x578)) - intToDoubleMagic);
  twoOverWidth = kTwoThenInvHeight / widthF;
  halfHeightF = kOnePointFive / (widthF * kEight);
  *(undefined4 *)(ctx + 0x152fc) = 0;
  oneAndHalfOverFourWidth = kOnePointFive / (widthF * kFour);
  *(undefined4 *)(ctx + 0x15300) = 0;
  heightF = (float)((double)CONCAT44(0x43300000,*(uint *)(ctx + 0x57c)) - intToDoubleMagic);
  *(undefined4 *)(ctx + 0x1530c) = 0;
  *(undefined4 *)(ctx + 0x15310) = 0;
  *(float *)(ctx + 0x15330) = kInv255;
  *(float *)(ctx + 0x15360) = kOne;
  *(float *)(ctx + 0x15384) = twoOverWidth;
  *(float *)(ctx + 0x152f4) = halfHeightF;
  *(float *)(ctx + 0x152d4) = halfHeightF;
  kTwoThenInvHeight = kTwoThenInvHeight / heightF;
  s16MaxOverTwoWidth = kS16Max / (widthF + widthF);
  *(float *)(ctx + 0x15364) = oneAndHalfOverFourWidth;
  halfHeightF = (float)((double)CONCAT44(0x43300000,halfHeightAligned) - intToDoubleMagic);
  *(float *)(ctx + 0x15378) = kTwoThenInvHeight;
  *(float *)(ctx + 0x15318) = kTwoThenInvHeight;
  *(float *)(ctx + 0x152e4) = s16MaxOverTwoWidth;
  *(float *)(ctx + 0x152c4) = s16MaxOverTwoWidth;
  *(float *)(ctx + 0x152c8) = kS16Max / (heightF + heightF);
  *(float *)(ctx + 0x152d8) = kOnePointFive / (heightF * kEight);
  *(float *)(ctx + 0x15368) = kOnePointFive / (halfHeightF * kFour);
  *(float *)(ctx + 0x15304) = kOne / widthF;
  *(float *)(ctx + 0x15314) = kOne / widthF;
  *(float *)(ctx + 0x152e8) = kS16Max / (halfHeightF + halfHeightF);
  *(float *)(ctx + 0x152f8) = kOnePointFive / (halfHeightF * kEight);
  *(float *)(ctx + 0x15358) = kS16Max / halfHeightF;
  *(float *)(ctx + 0x15388) = kFour / heightF;
  *(float *)(ctx + 0x15348) = kOnePointFive / (heightF * kFour);
  *(undefined4 *)(ctx + 0x1531c) = 0;
  *(undefined4 *)(ctx + 0x15320) = 0;
  *(undefined4 *)(ctx + 0x1534c) = 0;
  *(undefined4 *)(ctx + 0x15350) = 0;
  *(undefined4 *)(ctx + 0x1536c) = 0;
  *(undefined4 *)(ctx + 0x15370) = 0;
  *(undefined4 *)(ctx + 0x1537c) = 0;
  *(undefined4 *)(ctx + 0x15380) = 0;
  *(undefined4 *)(ctx + 0x1538c) = 0;
  *(undefined4 *)(ctx + 0x15390) = 0;
  *(float *)(ctx + 0x15324) = kInv255;
  *(float *)(ctx + 0x15328) = kInv255;
  *(float *)(ctx + 0x1532c) = kInv255;
  *(float *)(ctx + 0x1533c) = kOne;
  *(float *)(ctx + 0x15340) = kOne;
  *(float *)(ctx + 0x1535c) = kOne;
  *(float *)(ctx + 0x15354) = kS16Max / widthF;
  *(float *)(ctx + 0x15308) = kOne / heightF;
  *(float *)(ctx + 0x15334) = kS16Max / widthF;
  *(float *)(ctx + 0x15344) = oneAndHalfOverFourWidth;
  *(float *)(ctx + 0x15374) = twoOverWidth;
  *(float *)(ctx + 0x15338) = kS16Max / heightF;
  programHandle = ((int (*)())ava_build_stage_program)(ctx,*(undefined4 *)(ctx + 0x15294),1,0);
  *(undefined4 *)(ctx + 0x15298) = programHandle;
  programHandle = ((int (*)())ava_build_stage_program)(ctx,*(undefined4 *)(ctx + 0x1529c),2,0);
  savedHeight = *(undefined4 *)(ctx + 0x57c);
  *(uint *)(ctx + 0x57c) = halfHeightAligned << 1;
  *(undefined4 *)(ctx + 0x152a0) = programHandle;
  programHandle = ((int (*)())ava_build_stage_program)(ctx,*(undefined4 *)(ctx + 0x152a4),1,1);
  *(undefined4 *)(ctx + 0x152a8) = programHandle;
  programHandle = ((int (*)())ava_build_stage_program)(ctx,*(undefined4 *)(ctx + 0x152ac),2,1);
  *(undefined4 *)(ctx + 0x57c) = savedHeight;
  *(undefined4 *)(ctx + 0x152b0) = programHandle;
  return;
}

/* ava_emit_stage_programs @ 0x7020 (592 bytes) */
int ava_emit_stage_programs(ctx, cmdPtr, mode)
  int ctx;
  undefined4 *cmdPtr;
  int mode;
{
  uint halfPitch;
  int wordCountOrLimit;
  undefined4 *cmdCursor;
  int pitchOrLimit;
  
  if (mode == 1) {
    pitchOrLimit = *(int *)(ctx + 0x588);
    if (*(int *)(ctx + 0x55c) == 3) {
      _memcpy(cmdPtr,*(undefined4 *)(ctx + 0x15294),*(int *)(ctx + 0x15298) << 2);
      wordCountOrLimit = *(int *)(ctx + 0x15298);
    }
    else {
      _memcpy(cmdPtr,*(undefined4 *)(ctx + 0x152a4),*(int *)(ctx + 0x152a8) << 2);
      wordCountOrLimit = *(int *)(ctx + 0x152a8);
    }
    cmdCursor = cmdPtr + wordCountOrLimit;
    *cmdCursor = 0x1144;
    wordCountOrLimit = pitchOrLimit + -1;
    cmdCursor[1] = wordCountOrLimit;
    cmdCursor[2] = 0x1147;
    cmdCursor[3] = wordCountOrLimit;
    cmdCursor[4] = 0x1145;
    pitchOrLimit = pitchOrLimit * 2 + -1;
    cmdCursor[5] = pitchOrLimit;
    cmdCursor[6] = 0x1146;
    cmdCursor[7] = pitchOrLimit;
    cmdCursor[8] = 0x1148;
    cmdCursor[9] = pitchOrLimit;
    cmdCursor[10] = 0x1149;
    cmdCursor[0xb] = pitchOrLimit;
    cmdCursor = cmdCursor + 0xc;
    pitchOrLimit = 0x1e;
    do {
      *cmdCursor = 0x80000000;
      cmdCursor = cmdCursor + 1;
      pitchOrLimit = pitchOrLimit + -1;
    } while (pitchOrLimit != 0);
  }
  else {
    *cmdPtr = ((unsigned char *)0x00001040U);
    cmdCursor = cmdPtr + 2;
    cmdPtr[1] = 0;
    halfPitch = *(uint *)(ctx + 0x588) >> 1;
    if (*(int *)(ctx + 0x55c) == 3) {
      _memcpy(cmdCursor,*(undefined4 *)(ctx + 0x1529c),*(int *)(ctx + 0x152a0) << 2);
      pitchOrLimit = *(int *)(ctx + 0x152a0);
    }
    else {
      _memcpy(cmdCursor,*(undefined4 *)(ctx + 0x152ac),*(int *)(ctx + 0x152b0) << 2);
      pitchOrLimit = *(int *)(ctx + 0x152b0);
    }
    cmdCursor = cmdCursor + pitchOrLimit;
    *cmdCursor = 0x1144;
    pitchOrLimit = halfPitch - 1;
    cmdCursor[1] = pitchOrLimit;
    cmdCursor[2] = 0x1147;
    cmdCursor[3] = pitchOrLimit;
    cmdCursor[4] = 0x1145;
    pitchOrLimit = halfPitch * 2 + -1;
    cmdCursor[5] = pitchOrLimit;
    cmdCursor[6] = 0x1146;
    cmdCursor[7] = pitchOrLimit;
    cmdCursor[8] = 0x1148;
    cmdCursor[9] = pitchOrLimit;
    cmdCursor[10] = 0x1149;
    cmdCursor[0xb] = pitchOrLimit;
    cmdCursor = cmdCursor + 0xc;
    pitchOrLimit = 0x1e;
    do {
      *cmdCursor = 0x80000000;
      cmdCursor = cmdCursor + 1;
      pitchOrLimit = pitchOrLimit + -1;
    } while (pitchOrLimit != 0);
  }
  return cmdCursor;
}

/* ava_emit_block_table_entries @ 0x7270 (544 bytes) */
int ava_emit_block_table_entries(cmdPtr, ranges, variant)
  undefined4 cmdPtr;
  int *ranges;
  int variant;
{
  int rangeLengthOrLast;
  undefined4 *cmdAfterEntries;
  undefined *tableBase;
  int rangeLength;
  int entriesSoFar;
  int entriesAfterNext;
  uint entries [244];
  
  tableBase = &UNK_0000d5c4;
  rangeLength = (ranges[1] - *ranges) + 1;
  _memcpy(entries,&UNK_0000d5c4 + *ranges * 0x18,rangeLength * 0x18);
  rangeLengthOrLast = (ranges[7] - ranges[6]) + 1;
  entriesSoFar = rangeLength + rangeLengthOrLast;
  _memcpy(entries + rangeLength * 6,&UNK_0000d4ec + ranges[6] * 0x18,rangeLengthOrLast * 0x18);
  rangeLengthOrLast = entriesSoFar + -1;
  entries[rangeLength * 6] = entries[rangeLength * 6] | 0x400;
  entries[rangeLengthOrLast * 6] = entries[rangeLengthOrLast * 6] | 4;
  entries[rangeLengthOrLast * 6 + 1] = entries[rangeLengthOrLast * 6 + 1] | 0x2000000;
  rangeLengthOrLast = (ranges[5] - ranges[4]) + 1;
  entriesAfterNext = entriesSoFar + rangeLengthOrLast;
  _memcpy(entries + entriesSoFar * 6,&UNK_0000d5c4 + ranges[4] * 0x18,rangeLengthOrLast * 0x18);
  rangeLength = ranges[10];
  rangeLengthOrLast = ranges[0xb];
  entries[entriesSoFar * 6] = entries[entriesSoFar * 6] | 4;
  rangeLengthOrLast = (rangeLengthOrLast - rangeLength) + 1;
  entriesSoFar = entriesAfterNext + rangeLengthOrLast;
  _memcpy(entries + entriesAfterNext * 6,&UNK_0000d4ec + rangeLength * 0x18,rangeLengthOrLast * 0x18);
  rangeLengthOrLast = entriesSoFar + -1;
  entries[entriesAfterNext * 6] = entries[entriesAfterNext * 6] | 0x400;
  entries[rangeLengthOrLast * 6] = entries[rangeLengthOrLast * 6] | 4;
  entries[rangeLengthOrLast * 6 + 1] = entries[rangeLengthOrLast * 6 + 1] | 0x2000000;
  if (variant == 2) {
    tableBase = &UNK_0000d474;
  }
  rangeLength = (ranges[9] - ranges[8]) + 1;
  entriesAfterNext = entriesSoFar + rangeLength;
  rangeLengthOrLast = entriesAfterNext + -1;
  _memcpy(entries + entriesSoFar * 6,tableBase + ranges[8] * 0x18,rangeLength * 0x18);
  entries[entriesSoFar * 6] = entries[entriesSoFar * 6] | 4;
  entries[rangeLengthOrLast * 6] = entries[rangeLengthOrLast * 6] | 0x100;
  cmdAfterEntries = (undefined4 *)((int (*)())ava_emit_us_vector_data)(cmdPtr,0,(uint)(entriesAfterNext * 0x18) >> 2,entries);
  *cmdAfterEntries = 0x118e;
  cmdAfterEntries[1] = 0;
  cmdAfterEntries[2] = 0x118c;
  cmdAfterEntries[3] = rangeLengthOrLast * 0x10000;
  cmdAfterEntries[4] = 0x118d;
  cmdAfterEntries[5] = rangeLengthOrLast * 0x10000;
  return cmdAfterEntries + 6;
}

/* ava_emit_block_packet @ 0x7490 (696 bytes) */
int ava_emit_block_packet(ctx, blockType, wordCount, srcWords, alternateTable, stream)
  int ctx;
  uint blockType;
  int wordCount;
  undefined4 *srcWords;
  int alternateTable;
  int stream;
{
  int pictureType;
  undefined4 word;
  undefined4 *cmdCursor;
  uint chromaFlag;
  undefined *programEntry;
  uint pitchWords;
  undefined4 *cmdBuf;
  
  if (alternateTable == 0) {
    if (*(int *)(ctx + 0x55c) == 3) {
      programEntry = &UNK_0000dd00 + blockType * 0x34;
    }
    else {
      programEntry = &UNK_0000d7ec + blockType * 0x34;
    }
  }
  else if (*(int *)(ctx + 0x55c) == 3) {
    programEntry = &UNK_0000e658 + blockType * 0x34;
  }
  else {
    programEntry = &UNK_0000e144 + blockType * 0x34;
  }
  if (stream != 1) {
    pictureType = *(int *)(ctx + 0x55c);
    if ((pictureType == 3) && (blockType < 3)) {
      pitchWords = *(uint *)(ctx + 0x588) >> 1;
    }
    else {
      pitchWords = *(uint *)(ctx + 0x588);
    }
    cmdBuf = *(undefined4 **)(ctx + 0x1517c);
  }
  else {
    pictureType = *(int *)(ctx + 0x55c);
    if ((pictureType == 3) && (blockType < 3)) {
      pitchWords = *(uint *)(ctx + 0x588);
    }
    else {
      pitchWords = *(int *)(ctx + 0x588) << 1;
    }
    cmdBuf = *(undefined4 **)(ctx + 0x15174);
  }
  if (pictureType == 3) {
    if ((((blockType - 5 < 2) || (blockType == 9)) || (blockType == 10)) ||
       (((blockType == 0xf || (blockType == 0x10)) ||
        ((blockType == 0x11 || (chromaFlag = 0, blockType == 0x12)))))) {
      chromaFlag = 1;
    }
  }
  else {
    chromaFlag = (uint)(pictureType == 2);
  }
  *cmdBuf = 0x1393;
  cmdBuf[1] = 10;
  cmdBuf[2] = 0x5c8;
  cmdBuf[3] = 0x20000;
  cmdBuf[4] = ((unsigned char *)0x00001040U);
  cmdBuf[5] = 0;
  cmdCursor = (undefined4 *)((int (*)())ava_emit_block_table_entries)(cmdBuf + 6,programEntry,stream);
  *cmdCursor = ((unsigned char *)0x00001041U);
  cmdCursor[1] = *(undefined4 *)(programEntry + 0x30);
  cmdCursor[2] = (wordCount + 5) * 0x10000 | 0xc0003a00;
  cmdCursor[3] = 0xc0000;
  *(int *)(ctx + 0x15188) = (int)(cmdCursor + 4) - (int)cmdBuf >> 2;
  cmdCursor[4] = chromaFlag;
  cmdCursor[5] = pitchWords;
  cmdCursor[6] = wordCount << 0x12 | 0x81d;
  cmdBuf = cmdCursor + 8;
  cmdCursor[7] = wordCount;
  for (; wordCount != 0; wordCount = wordCount + -1) {
    word = *srcWords;
    srcWords = srcWords + 1;
    *cmdBuf = word;
    cmdBuf = cmdBuf + 1;
  }
  *cmdBuf = 0xdeadbeef;
  cmdBuf[1] = 0x1393;
  cmdBuf[2] = 10;
  if (stream != 1) {
    *(undefined4 **)(ctx + 0x1517c) = cmdBuf + 3;
  }
  else {
    *(undefined4 **)(ctx + 0x15174) = cmdBuf + 3;
  }
  return;
}

/* ava_push_reservation_word @ 0x7760 (204 bytes) */
int ava_push_reservation_word(reservation, value, listSelect)
  int *reservation;
  undefined4 value;
  int listSelect;
{
  undefined4 *slot;
  
  if (listSelect == 3) {
    if (reservation[5] != 0) {
      slot = (undefined4 *)reservation[8];
      reservation[8] = (int)(slot + 1);
      *slot = value;
      return 1;
    }
  }
  else if (listSelect == 4) {
    if (reservation[10] != 0) {
      slot = (undefined4 *)reservation[0xd];
      reservation[0xd] = (int)(slot + 1);
      *slot = value;
      return 1;
    }
  }
  else if ((listSelect == 1) && (*reservation != 0)) {
    slot = (undefined4 *)reservation[3];
    if (slot <= (undefined4 *)reservation[4]) {
      reservation[3] = (int)(slot + 1);
      reservation[1] = reservation[1] + 1;
      *slot = value;
      return 1;
    }
    reservation[10] = 0;
    *reservation = 0;
    reservation[5] = 0;
    return 0;
  }
  return 0;
}

/* ava_emit_picture_setup_packet @ 0x7850 (1416 bytes) */
int ava_emit_picture_setup_packet(ctx, ringWords)
  int ctx;
  int ringWords;
{
  bool notLast;
  undefined *taskPortPtr;
  uint *lastHeader;
  int mapBaseOrAddr;
  int ringBaseOrMid;
  undefined4 *ringLimit;
  uint wordsLeft;
  undefined4 *header14;
  undefined4 *cmdWriteB;
  undefined4 *programStart;
  int remainingWords;
  int surfaceIndex;
  int *entryHeader;
  int statEntry;
  
  header14 = *(undefined4 **)(ctx + 0x34);
  if (*(undefined4 **)(ctx + 0x38) <= header14 + 0xe) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)header14 - (int)lastHeader >> 2 | *lastHeader;
    taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                        ctx + 0x44,1);
    mapBaseOrAddr = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBaseOrAddr + 0x20;
    *(int *)(ctx + 0x30) = mapBaseOrAddr + 0x1c;
    *(int *)(ctx + 0x38) = mapBaseOrAddr + 0x20 + *(int *)(mapBaseOrAddr + 0x10) * 4;
    *(undefined4 *)(mapBaseOrAddr + 0x1c) = 0;
    header14 = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = header14 + 0xe;
  *lastHeader = (int)header14 - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = header14;
  *header14 = 0x12000000;
  header14[1] = 0;
  if (*(char *)(ctx + 0x574) == '\0') {
    header14[2] = 0;
  }
  else {
    header14[2] = 1;
  }
  mapBaseOrAddr = *(int *)(ctx + 0x55c);
  if (mapBaseOrAddr == 2) {
    header14[3] = 1;
  }
  else {
    header14[3] = 0;
    if (mapBaseOrAddr == 3) {
      header14[4] = 0;
      goto storeHeader14;
    }
  }
  header14[4] = 1;
storeHeader14:
  header14[5] = 1;
  header14[6] = -0x80000000;
  header14[7] = -0x80000000;
  header14[8] = *(undefined4 *)(ctx + 0x15400);
  header14[9] = *(undefined4 *)(ctx + 0x568);
  header14[10] = *(undefined4 *)(ctx + 0x56c);
  header14[0xb] = *(undefined4 *)(ctx + 0x570);
  if (*(int *)(ctx + 0x560) == 3) {
    header14[0xc] = 1;
  }
  else {
    header14[0xc] = 0;
  }
  header14[0xd] = 1;
  cmdWriteB = *(undefined4 **)(ctx + 0x34);
  ringLimit = *(undefined4 **)(ctx + 0x38);
  if (ringLimit <= cmdWriteB + 2) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWriteB - (int)lastHeader >> 2 | *lastHeader;
    taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                        ctx + 0x44,1);
    mapBaseOrAddr = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBaseOrAddr + 0x20;
    *(int *)(ctx + 0x30) = mapBaseOrAddr + 0x1c;
    *(int *)(ctx + 0x38) = mapBaseOrAddr + 0x20 + *(int *)(mapBaseOrAddr + 0x10) * 4;
    *(undefined4 *)(mapBaseOrAddr + 0x1c) = 0;
    cmdWriteB = *(undefined4 **)(ctx + 0x34);
    ringLimit = *(undefined4 **)(ctx + 0x38);
  }
  programStart = cmdWriteB + 2;
  *(undefined4 **)(ctx + 0x34) = programStart;
  *cmdWriteB = 0x80000000;
  cmdWriteB[1] = 0x80000000;
  if (ringLimit <= programStart + ringWords) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)programStart - (int)lastHeader >> 2 | *lastHeader;
    taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                        ctx + 0x44,1);
    mapBaseOrAddr = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBaseOrAddr + 0x20;
    *(int *)(ctx + 0x30) = mapBaseOrAddr + 0x1c;
    *(int *)(ctx + 0x38) = mapBaseOrAddr + 0x20 + *(int *)(mapBaseOrAddr + 0x10) * 4;
    *(undefined4 *)(mapBaseOrAddr + 0x1c) = 0;
    programStart = *(undefined4 **)(ctx + 0x34);
  }
  *(undefined4 **)(ctx + 0x34) = programStart + ringWords;
  *(undefined4 **)(ctx + 0x15164) = programStart;
  *(undefined4 **)(ctx + 0x1516c) = programStart;
  *(undefined4 **)(ctx + 0x15170) = programStart;
  *(undefined4 **)(ctx + 0x15168) = programStart + ringWords + -1;
  mapBaseOrAddr = ((int (*)())ava_emit_stage_programs)(ctx,programStart,1);
  ringBaseOrMid = *(int *)(ctx + 0x15164);
  *(int *)(ctx + 0x15174) = mapBaseOrAddr;
  header14[6] = mapBaseOrAddr - ringBaseOrMid >> 2;
  mapBaseOrAddr = *(int *)(ctx + 0x15168) - mapBaseOrAddr;
  wordsLeft = mapBaseOrAddr >> 2;
  ringBaseOrMid = ringBaseOrMid + ((mapBaseOrAddr >> 3) + (uint)((int)wordsLeft < 0 && (wordsLeft & 1) != 0)) * 4;
  *(int *)(ctx + 0x15178) = ringBaseOrMid;
  mapBaseOrAddr = ((int (*)())ava_emit_stage_programs)(ctx,ringBaseOrMid,2);
  *(int *)(ctx + 0x1517c) = mapBaseOrAddr;
  header14[7] = mapBaseOrAddr - *(int *)(ctx + 0x15164) >> 2;
  surfaceIndex = 0;
  ringBaseOrMid = ctx + 0x14428;
  mapBaseOrAddr = 0;
  do {
    statEntry = ringBaseOrMid + mapBaseOrAddr;
    remainingWords = (*(int *)(ctx + 0x14424) - *(int *)(ringBaseOrMid + mapBaseOrAddr)) + -1;
    if (remainingWords != 0) {
      entryHeader = *(int **)(ctx + 0x15174);
      *(int **)(ctx + 0x15174) = entryHeader + 2;
      ((int (*)())ava_emit_block_packet)(ctx,surfaceIndex,remainingWords,*(int *)(ringBaseOrMid + mapBaseOrAddr) * 4 + *(int *)(statEntry + 8) + 4,1,1)
      ;
      *entryHeader = (*(int *)(ctx + 0x15174) - (int)entryHeader >> 2) + -2;
      entryHeader[1] = *(int *)(ctx + 0x15188);
      entryHeader = *(int **)(ctx + 0x1517c);
      *(int **)(ctx + 0x1517c) = entryHeader + 2;
      ((int (*)())ava_emit_block_packet)(ctx,surfaceIndex,remainingWords,*(int *)(ringBaseOrMid + mapBaseOrAddr) * 4 + *(int *)(statEntry + 8) + 4,1,2)
      ;
      *entryHeader = (*(int *)(ctx + 0x1517c) - (int)entryHeader >> 2) + -2;
      entryHeader[1] = *(int *)(ctx + 0x15188);
    }
    if (*(int *)(statEntry + 4) != 0) {
      entryHeader = *(int **)(ctx + 0x15174);
      *(int **)(ctx + 0x15174) = entryHeader + 2;
      ((int (*)())ava_emit_block_packet)(ctx,surfaceIndex,*(undefined4 *)(statEntry + 4),*(undefined4 *)(statEntry + 8),0,1);
      *entryHeader = (*(int *)(ctx + 0x15174) - (int)entryHeader >> 2) + -2;
      entryHeader[1] = *(int *)(ctx + 0x15188);
      entryHeader = *(int **)(ctx + 0x1517c);
      *(int **)(ctx + 0x1517c) = entryHeader + 2;
      ((int (*)())ava_emit_block_packet)(ctx,surfaceIndex,*(undefined4 *)(statEntry + 4),*(undefined4 *)(statEntry + 8),0,2);
      *entryHeader = (*(int *)(ctx + 0x1517c) - (int)entryHeader >> 2) + -2;
      entryHeader[1] = *(int *)(ctx + 0x15188);
    }
    notLast = surfaceIndex != 0x18;
    mapBaseOrAddr = mapBaseOrAddr + 0xc;
    surfaceIndex = surfaceIndex + 1;
  } while (notLast);
  header14 = *(undefined4 **)(ctx + 0x15174);
  *(undefined4 **)(ctx + 0x15174) = header14 + 1;
  *header14 = 0;
  header14 = *(undefined4 **)(ctx + 0x1517c);
  *(undefined4 **)(ctx + 0x1517c) = header14 + 1;
  *header14 = 0;
  return;
}

/* ava_pad_command_lists @ 0x7de0 (416 bytes) */
int ava_pad_command_lists(listState)
  int listState;
{
  int chunkCount;
  int chunkCount2;
  uint wordsLeft;
  uint *packetHeader;
  undefined4 *cmdCursor;
  
  cmdCursor = *(undefined4 **)(listState + 0x10);
  wordsLeft = *(int *)(listState + 0x14) - (int)cmdCursor >> 2;
  if (0x4001 < wordsLeft) {
    chunkCount = (wordsLeft - 0x4002) / 0x4001 + 1;
    if (wordsLeft == 0x4001) {
      chunkCount = 1;
    }
    do {
      *cmdCursor = 0xffff1000;
      wordsLeft = wordsLeft - 0x4001;
      cmdCursor = cmdCursor + 0x4001;
      chunkCount = chunkCount + -1;
    } while (chunkCount != 0);
    *(undefined4 **)(listState + 0x10) = cmdCursor;
  }
  if (wordsLeft != 0) {
    if (wordsLeft < 2) {
      cmdCursor = *(undefined4 **)(listState + 0x10);
      *(undefined4 **)(listState + 0x10) = cmdCursor + 1;
      *cmdCursor = 0x80000000;
    }
    else {
      packetHeader = *(uint **)(listState + 0x10);
      *(uint **)(listState + 0x10) = packetHeader + 1;
      *packetHeader = (wordsLeft - 2) * 0x10000 | 0xc0001000;
    }
  }
  cmdCursor = *(undefined4 **)(listState + 0x18);
  chunkCount = *(int *)(listState + 4) - (int)cmdCursor >> 2;
  wordsLeft = chunkCount + 1;
  if (0x4001 < wordsLeft) {
    chunkCount2 = (chunkCount - 0x4001U) / 0x4001 + 1;
    if (chunkCount == 0x4000) {
      chunkCount2 = 1;
    }
    do {
      *cmdCursor = 0xffff1000;
      wordsLeft = wordsLeft - 0x4001;
      cmdCursor = cmdCursor + 0x4001;
      chunkCount2 = chunkCount2 + -1;
    } while (chunkCount2 != 0);
    *(undefined4 **)(listState + 0x18) = cmdCursor;
  }
  if (wordsLeft == 0) {
    return;
  }
  if (1 < wordsLeft) {
    packetHeader = *(uint **)(listState + 0x18);
    *(uint **)(listState + 0x18) = packetHeader + 1;
    *packetHeader = (wordsLeft - 2) * 0x10000 | 0xc0001000;
    return;
  }
  cmdCursor = *(undefined4 **)(listState + 0x18);
  *(undefined4 **)(listState + 0x18) = cmdCursor + 1;
  *cmdCursor = 0x80000000;
  return;
}

/* ava_end_picture @ 0x7f80 (1072 bytes) */
int ava_end_picture(ctx)
  int ctx;
{
  int *chromaEntry;
  bool notLast;
  undefined *taskPortPtr;
  uint *lastHeader;
  int mapBaseOrPlaneWords;
  int programRingOrPitch;
  int mapMemoryArg4;
  int mapMemoryArg5;
  undefined4 *ringLimit;
  undefined4 regDefault;
  undefined4 *cmdWriteB;
  undefined4 *cmdWrite;
  undefined4 regValue;
  int *descTable;
  int planeIndex;
  int surfaceIndexOrScratch;
  int *planeCursor;
  
  descTable = (int *)(ctx + 0x55c);
  surfaceIndexOrScratch = *(int *)(ctx + 0x568);
  if (*(int *)(ctx + 0x560) == 1) {
    if (*(int *)(ctx + 0x15124) == *(int *)(ctx + 0x1511c)) {
      return;
    }
    surfaceIndexOrScratch = ((int (*)())ava_submit_idct_list_and_remap)(ctx,0);
    if (surfaceIndexOrScratch != 0) {
      return;
    }
    descTable[*(int *)(ctx + 0x568) + 0x14b] = 1;
    return;
  }
  if ((((*(int *)(ctx + 0x55c) == 3) || (*(char *)(ctx + 0x574) != '\0')) &&
      (*(int *)(ctx + 0x15124) != *(int *)(ctx + 0x1511c))) &&
     (programRingOrPitch = ((int (*)())ava_submit_idct_list_and_remap)(ctx,0), programRingOrPitch == 0)) {
    descTable[*(int *)(ctx + 0x568) + 0x14b] = 1;
  }
  if (*(int *)(ctx + 0x15148) == *(int *)(ctx + 0x15140)) {
    cmdWrite = *(undefined4 **)(ctx + 0x34);
    ringLimit = *(undefined4 **)(ctx + 0x38);
  }
  else {
    programRingOrPitch = ((int (*)())ava_submit_idct_list_and_remap)(ctx,1);
    if (programRingOrPitch == 0) {
      surfaceIndexOrScratch = *(int *)(ctx + 0x15164);
      descTable[*(int *)(ctx + 0x568) + 0x14b] = 1;
      *(undefined4 *)(surfaceIndexOrScratch + -0xc) = 0;
      goto setTaskPortPtr;
    }
    programRingOrPitch = *(int *)(ctx + 0x15164);
    *(undefined4 *)(programRingOrPitch + -8) = 0x5c8;
    *(undefined4 *)(programRingOrPitch + -4) = 0x8000000;
    taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
    cmdWriteB = *(undefined4 **)(ctx + 0x34);
    ringLimit = *(undefined4 **)(ctx + 0x38);
    if (ringLimit <= cmdWriteB + 2) {
      lastHeader = *(uint **)(ctx + 0x30);
      mapMemoryArg4 = ctx + 0x40;
      mapMemoryArg5 = ctx + 0x44;
      *lastHeader = (int)cmdWriteB - (int)lastHeader >> 2 | *lastHeader;
      *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
      **(undefined4 **)(ctx + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,mapMemoryArg4,mapMemoryArg5,1);
      programRingOrPitch = *(int *)(ctx + 0x40);
      *(int *)(ctx + 0x34) = programRingOrPitch + 0x20;
      *(int *)(ctx + 0x30) = programRingOrPitch + 0x1c;
      *(int *)(ctx + 0x38) = programRingOrPitch + 0x20 + *(int *)(programRingOrPitch + 0x10) * 4;
      *(undefined4 *)(programRingOrPitch + 0x1c) = 0;
      cmdWriteB = *(undefined4 **)(ctx + 0x34);
      ringLimit = *(undefined4 **)(ctx + 0x38);
    }
    cmdWrite = cmdWriteB + 2;
    *(undefined4 **)(ctx + 0x34) = cmdWrite;
    *cmdWriteB = 0x7eb;
    cmdWriteB[1] = 0x4000;
  }
  taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
  planeIndex = ctx + 0x44;
  programRingOrPitch = ctx + 0x40;
  if (ringLimit <= cmdWrite + 4) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,programRingOrPitch,planeIndex,1);
    mapBaseOrPlaneWords = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBaseOrPlaneWords + 0x20;
    *(int *)(ctx + 0x30) = mapBaseOrPlaneWords + 0x1c;
    *(int *)(ctx + 0x38) = mapBaseOrPlaneWords + 0x20 + *(int *)(mapBaseOrPlaneWords + 0x10) * 4;
    *(undefined4 *)(mapBaseOrPlaneWords + 0x1c) = 0;
    cmdWrite = *(undefined4 **)(ctx + 0x34);
    mapMemoryArg4 = programRingOrPitch;
    mapMemoryArg5 = planeIndex;
  }
  *(undefined4 **)(ctx + 0x34) = cmdWrite + 4;
  *cmdWrite = 0x1393;
  regValue = 10;
  cmdWrite[1] = 10;
  regDefault = 0x5c8;
  cmdWrite[2] = 0x5c8;
  cmdWrite[3] = 0x20000;
  planeIndex = 0;
  ((int (*)())ava_pad_command_lists)(ctx + 0x15164);
  programRingOrPitch = *(int *)(ctx + 0x151a4);
  mapBaseOrPlaneWords = (*(uint *)(ctx + 0x57c) >> 4) * programRingOrPitch;
  planeCursor = descTable + surfaceIndexOrScratch * 4 + 0x5326;
  do {
    ((int (*)())ava_dcache_flush_range)(ctx,*planeCursor,mapBaseOrPlaneWords,mapMemoryArg4,mapMemoryArg5,regDefault,programRingOrPitch,regValue);
    chromaEntry = planeCursor + 0x14;
    planeCursor = planeCursor + 1;
    ((int (*)())ava_dcache_flush_range)(ctx,*chromaEntry,mapBaseOrPlaneWords,mapMemoryArg4,mapMemoryArg5,regDefault,programRingOrPitch,regValue);
    notLast = planeIndex != 3;
    planeIndex = planeIndex + 1;
  } while (notLast);
setTaskPortPtr:
  taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                      ctx + 0x44,1);
  surfaceIndexOrScratch = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = surfaceIndexOrScratch + 0x20;
  *(int *)(ctx + 0x30) = surfaceIndexOrScratch + 0x1c;
  *(int *)(ctx + 0x38) = surfaceIndexOrScratch + 0x20 + *(int *)(surfaceIndexOrScratch + 0x10) * 4;
  *(undefined4 *)(surfaceIndexOrScratch + 0x1c) = 0;
  descTable[*(int *)(ctx + 0xac4) * 2 + 0x15c] = *(int *)(*(int *)(ctx + 0x40) + 0x18);
  if (((*descTable != 3) && (*(char *)(ctx + 0x574) == '\0')) &&
     (*(int *)(ctx + 0x15124) != *(int *)(ctx + 0x1511c))) {
    ((int (*)())ava_submit_idct_list_and_remap)(ctx,0);
    return;
  }
  return;
}

/* ava_reserve_list_words @ 0x83e0 (300 bytes) */
int ava_reserve_list_words(ctx, wordsNeeded, listSelect)
  int ctx;
  int wordsNeeded;
  int listSelect;
{
  uint newCursor;
  int *entryCursor;
  int chunkCount;
  int entriesLeft;
  undefined4 *resetCursor;
  int totalWords;
  int bufferState;
  int pendingWords;
  
  if (listSelect != 0) {
    bufferState = ctx + 0x15140;
  }
  else {
    bufferState = ctx + 0x1511c;
  }
  newCursor = *(int *)(bufferState + 8) + wordsNeeded * 4;
  if (*(uint *)(bufferState + 4) < newCursor) {
    if (listSelect != 0) {
      chunkCount = 0;
      totalWords = 0;
      entriesLeft = 0x19;
      entryCursor = (int *)(ctx + 0x1442c);
      do {
        if (*entryCursor != 0) {
          totalWords = totalWords + *entryCursor;
          chunkCount = chunkCount + 1;
        }
        pendingWords = (*(int *)(ctx + 0x14424) - entryCursor[-1]) + -1;
        if (pendingWords != 0) {
          chunkCount = chunkCount + 1;
          totalWords = totalWords + pendingWords;
        }
        entriesLeft = entriesLeft + -1;
        entryCursor = entryCursor + 3;
      } while (entriesLeft != 0);
      ((int (*)())ava_emit_picture_setup_packet)(ctx,(totalWords + chunkCount * 0x80) * 2 + 1000);
      ((int (*)())ava_end_picture)(ctx);
      resetCursor = (undefined4 *)(ctx + 0x1442c);
      chunkCount = 0x19;
      do {
        *resetCursor = 0;
        resetCursor[-1] = *(int *)(ctx + 0x14424) + -1;
        resetCursor = resetCursor + 3;
        chunkCount = chunkCount + -1;
      } while (chunkCount != 0);
    }
    else {
      ((int (*)())ava_submit_idct_list_and_remap)(ctx,0);
    }
    newCursor = wordsNeeded * 4 + *(int *)(bufferState + 8);
  }
  *(uint *)(bufferState + 8) = newCursor;
  return;
}

/* ava_emit_macroblock @ 0x8510 (372 bytes) */
int ava_emit_macroblock(ctx, mbHeader, wordStream, mbAddress, listSelect)
  int ctx;
  int mbHeader;
  undefined4 *wordStream;
  uint mbAddress;
  undefined4 listSelect;
{
  byte *flagByte;
  int flagCursor;
  uint *outHeader;
  uint *outWords;
  int payloadWords;
  uint flagWordOrRow;
  uint *srcCursor;
  int flagsLeft;
  
  flagsLeft = 6;
  payloadWords = 0;
  srcCursor = (uint *)*wordStream;
  flagCursor = mbHeader;
  do {
    flagByte = (byte *)(flagCursor + 0x16);
    flagCursor = flagCursor + 1;
    payloadWords = payloadWords + (uint)*flagByte;
    flagsLeft = flagsLeft + -1;
  } while (flagsLeft != 0);
  if (payloadWords == 0) {
    *(undefined1 *)(ctx + 0x590) = 1;
  }
  else {
    *(undefined1 *)(ctx + 0x590) = 0;
    outHeader = (uint *)((int (*)())ava_reserve_list_words)(ctx,payloadWords + 2,listSelect);
    flagWordOrRow = 0x80000000;
    if (*(char *)(mbHeader + 0x15) == '\0') {
      flagWordOrRow = 0;
    }
    *outHeader = -(uint)*(byte *)(mbHeader + 0x1b) >> 0x19 & 0x40 |
              -(uint)*(byte *)(mbHeader + 0x1a) >> 0x18 & 0x80 |
              -(uint)*(byte *)(mbHeader + 0x19) >> 0x17 & 0x100 |
              -(uint)*(byte *)(mbHeader + 0x18) >> 0x16 & 0x200 |
              -(uint)*(byte *)(mbHeader + 0x17) >> 0x15 & 0x400 |
              -(uint)*(byte *)(mbHeader + 0x16) >> 0x14 & 0x800 |
              flagWordOrRow | (uint)*(byte *)(ctx + 0x564) << 0x19;
    outWords = outHeader + 2;
    flagWordOrRow = mbAddress / *(uint *)(ctx + 0x580);
    outHeader[1] = flagWordOrRow << 0x14 | (mbAddress - flagWordOrRow * *(uint *)(ctx + 0x580)) * 0x10;
    if (payloadWords + 2 != 2) {
      do {
        *outWords = *srcCursor;
        srcCursor = srcCursor + 1;
        outWords = outWords + 1;
        payloadWords = payloadWords + -1;
      } while (payloadWords != 0);
    }
    *wordStream = srcCursor;
  }
  return;
}

/* ava_begin_reservation @ 0x8690 (344 bytes) */
int ava_begin_reservation(ctx, listState, reservation, wordCount, listSelect)
  undefined4 ctx;
  int listState;
  undefined4 *reservation;
  int wordCount;
  int listSelect;
{
  uint newCursor;
  undefined4 *reservationCursor;
  
  if (listSelect == 3) {
    reservationCursor = reservation + 8;
    reservation[7] = *(undefined4 *)(listState + 0x18);
    *(int *)(listState + 0x18) = wordCount * 4 + *(int *)(listState + 0x18);
    reservation[5] = 1;
    reservation[8] = reservation[7];
    reservation[9] = *(int *)(listState + 0x18) + -8;
  }
  else if (listSelect == 4) {
    reservationCursor = reservation + 0xd;
    reservation[0xc] = *(undefined4 *)(listState + 0x20);
    *(int *)(listState + 0x20) = wordCount * 4 + *(int *)(listState + 0x20);
    reservation[10] = 1;
    reservation[0xd] = reservation[0xc];
    reservation[0xe] = *(int *)(listState + 0x20) + -8;
  }
  else {
    reservationCursor = (undefined4 *)0x0;
    if (listSelect == 1) {
      reservation[2] = *(undefined4 *)(listState + 0x10);
      newCursor = wordCount * 4 + *(int *)(listState + 0x10);
      *(uint *)(listState + 0x10) = newCursor;
      if (newCursor < *(uint *)(listState + 0x14)) {
        reservation[1] = 1;
        reservationCursor = reservation + 3;
        *reservation = 1;
        reservation[3] = reservation[2];
        reservation[4] = *(int *)(listState + 0x10) + -8;
      }
      else {
        *(uint *)(listState + 0x10) = newCursor + wordCount * -4;
        ((int (*)())ava_end_picture)(ctx);
        reservationCursor = reservation + 3;
        reservation[2] = *(undefined4 *)(listState + 0x10);
        *(int *)(listState + 0x10) = wordCount * 4 + *(int *)(listState + 0x10);
        reservation[1] = 1;
        *reservation = 1;
        reservation[3] = reservation[2];
        reservation[4] = *(int *)(listState + 0x10) + -8;
      }
    }
  }
  return reservationCursor;
}

/* ava_clear_list_marker @ 0x8800 (28 bytes) */
int ava_clear_list_marker(ctx)
  int ctx;
{
  *(undefined4 *)(*(int *)(ctx + 0x15164) + -0xc) = 0;
  return;
}

/* ava_emit_mb_motion_vectors @ 0x8820 (3588 bytes) */
int ava_emit_mb_motion_vectors(ctx, mbInfo, mbIndex)
  int ctx;
  short *mbInfo;
  uint mbIndex;
{
  short mvTmp1;
  short mvTmp2;
  short mvTmp3;
  short mvTmp4;
  short mvTmp5;
  short mvTmp6;
  int mbPosOrListEntry;
  int mbOffsetBytes;
  int surfaceOrListBase;
  int descOrSurfaceEntry;
  int mbColumn;
  uint mbRow;
  
  descOrSurfaceEntry = ctx + 0x55c;
  mbOffsetBytes = mbIndex * 4;
  surfaceOrListBase = *(int *)(ctx + 0x568);
  mbRow = mbIndex / *(uint *)(ctx + 0x580);
  mbColumn = mbIndex - mbRow * *(uint *)(ctx + 0x580);
  mbPosOrListEntry = mbColumn + mbRow * (*(uint *)(ctx + 0x58c) >> 2);
  if (*(int *)(ctx + 0x55c) == 3) {
    switch(*(undefined1 *)(mbInfo + 10)) {
    default:
      return;
    case 1:
      descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
      surfaceOrListBase = ctx + 0x14428;
      *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c98) + mbPosOrListEntry * 4) = CONCAT22(mbInfo[1],*mbInfo);
      *(uint *)(mbPosOrListEntry * 4 + *(int *)(descOrSurfaceEntry + 0x14ce8)) =
           ((int)mbInfo[1] - ((int)mbInfo[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)*mbInfo - ((int)*mbInfo >> 0x1f)) >> 1 & 0xffff;
      if (*(char *)(ctx + 0x590) == '\0') {
        mbPosOrListEntry = *(int *)(ctx + 0x14428);
        *(int *)(mbPosOrListEntry * 4 + *(int *)(ctx + 0x14430)) = mbOffsetBytes;
        *(int *)(ctx + 0x14428) = mbPosOrListEntry + -1;
        return;
      }
      goto setMbPosOrListEntry;
    case 2:
      descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
      surfaceOrListBase = ctx + 0x14434;
      *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c9c) + mbPosOrListEntry * 4) = CONCAT22(mbInfo[3],mbInfo[2]);
      *(uint *)(mbPosOrListEntry * 4 + *(int *)(descOrSurfaceEntry + 0x14cec)) =
           ((int)mbInfo[3] - ((int)mbInfo[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)mbInfo[2] - ((int)mbInfo[2] >> 0x1f)) >> 1 & 0xffff;
      if (*(char *)(ctx + 0x590) == '\0') {
        mbPosOrListEntry = *(int *)(ctx + 0x14434);
        *(int *)(mbPosOrListEntry * 4 + *(int *)(ctx + 0x1443c)) = mbOffsetBytes;
        *(int *)(ctx + 0x14434) = mbPosOrListEntry + -1;
        return;
      }
setMbPosOrListEntry:
      mbPosOrListEntry = *(int *)(surfaceOrListBase + 4);
      *(int *)(mbPosOrListEntry * 4 + *(int *)(surfaceOrListBase + 8)) = mbOffsetBytes;
      *(int *)(surfaceOrListBase + 4) = mbPosOrListEntry + 1;
      return;
    case 3:
      mbPosOrListEntry = mbPosOrListEntry * 4;
      descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
      *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c98) + mbPosOrListEntry) = CONCAT22(mbInfo[1],*mbInfo);
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14c9c)) = CONCAT22(mbInfo[3],mbInfo[2]);
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ce8)) =
           ((int)mbInfo[1] - ((int)mbInfo[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)*mbInfo - ((int)*mbInfo >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cec)) =
           ((int)mbInfo[3] - ((int)mbInfo[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)mbInfo[2] - ((int)mbInfo[2] >> 0x1f)) >> 1 & 0xffff;
      if (*(char *)(ctx + 0x590) != '\0') {
        mbPosOrListEntry = *(int *)(ctx + 0x14444);
        *(int *)(mbPosOrListEntry * 4 + *(int *)(ctx + 0x14448)) = mbOffsetBytes;
        *(int *)(ctx + 0x14444) = mbPosOrListEntry + 1;
        return;
      }
      mbPosOrListEntry = *(int *)(ctx + 0x14440);
      *(int *)(mbPosOrListEntry * 4 + *(int *)(ctx + 0x14448)) = mbOffsetBytes;
      *(int *)(ctx + 0x14440) = mbPosOrListEntry + -1;
      return;
    case 5:
      mbPosOrListEntry = mbPosOrListEntry * 4;
      mvTmp1 = mbInfo[5];
      descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
      mvTmp2 = mbInfo[4];
      *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c98) + mbPosOrListEntry) = CONCAT22(mbInfo[1],*mbInfo);
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ca0)) = CONCAT22(mvTmp1,mvTmp2);
      mvTmp1 = mbInfo[5];
      mvTmp2 = mbInfo[4];
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ce8)) =
           ((int)mbInfo[1] - ((int)mbInfo[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)*mbInfo - ((int)*mbInfo >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cf0)) =
           ((int)mvTmp1 - ((int)mvTmp1 >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)mvTmp2 - ((int)mvTmp2 >> 0x1f)) >> 1 & 0xffff;
      mbOffsetBytes = mbOffsetBytes + *(int *)(ctx + 0x153fc);
      mbPosOrListEntry = ctx + 0x14428 + (uint)*(byte *)(mbInfo + 8) * 0xc;
      if (*(char *)(ctx + 0x590) == '\0') {
        descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x24);
        *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x2c)) = mbOffsetBytes;
        *(int *)(mbPosOrListEntry + 0x24) = descOrSurfaceEntry + -1;
      }
      else {
        descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x28);
        *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x2c)) = mbOffsetBytes;
        *(int *)(mbPosOrListEntry + 0x28) = descOrSurfaceEntry + 1;
      }
      mbPosOrListEntry = ctx + 0x14428 + (uint)*(byte *)(mbInfo + 9) * 0xc;
      descOrSurfaceEntry = mbPosOrListEntry + 0x3c;
      if (*(char *)(ctx + 0x590) == '\0') {
        descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x3c);
        *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x44)) = mbOffsetBytes;
        *(int *)(mbPosOrListEntry + 0x3c) = descOrSurfaceEntry + -1;
        return;
      }
      break;
    case 6:
      mbPosOrListEntry = mbPosOrListEntry * 4;
      mvTmp1 = mbInfo[7];
      descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
      mvTmp2 = mbInfo[6];
      *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c9c) + mbPosOrListEntry) = CONCAT22(mbInfo[3],mbInfo[2]);
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ca4)) = CONCAT22(mvTmp1,mvTmp2);
      mvTmp1 = mbInfo[7];
      mvTmp2 = mbInfo[6];
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cec)) =
           ((int)mbInfo[3] - ((int)mbInfo[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)mbInfo[2] - ((int)mbInfo[2] >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cf4)) =
           ((int)mvTmp1 - ((int)mvTmp1 >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)mvTmp2 - ((int)mvTmp2 >> 0x1f)) >> 1 & 0xffff;
      mbOffsetBytes = mbOffsetBytes + *(int *)(ctx + 0x153fc);
      mbPosOrListEntry = ctx + 0x14428 + (uint)*(byte *)((int)mbInfo + 0x11) * 0xc;
      if (*(char *)(ctx + 0x590) == '\0') {
        descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x54);
        *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x5c)) = mbOffsetBytes;
        *(int *)(mbPosOrListEntry + 0x54) = descOrSurfaceEntry + -1;
      }
      else {
        descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x58);
        *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x5c)) = mbOffsetBytes;
        *(int *)(mbPosOrListEntry + 0x58) = descOrSurfaceEntry + 1;
      }
      mbPosOrListEntry = ctx + 0x14428 + (uint)*(byte *)((int)mbInfo + 0x13) * 0xc;
      descOrSurfaceEntry = mbPosOrListEntry + 0x6c;
      if (*(char *)(ctx + 0x590) == '\0') {
        descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x6c);
        *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x74)) = mbOffsetBytes;
        *(int *)(mbPosOrListEntry + 0x6c) = descOrSurfaceEntry + -1;
        return;
      }
      break;
    case 7:
      mbPosOrListEntry = mbPosOrListEntry * 4;
      mvTmp4 = mbInfo[2];
      mvTmp5 = mbInfo[6];
      descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
      mvTmp1 = mbInfo[3];
      mvTmp2 = mbInfo[5];
      mvTmp3 = mbInfo[7];
      mvTmp6 = mbInfo[4];
      *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c98) + mbPosOrListEntry) = CONCAT22(mbInfo[1],*mbInfo);
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14c9c)) = CONCAT22(mvTmp1,mvTmp4);
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ca0)) = CONCAT22(mvTmp2,mvTmp6);
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ca4)) = CONCAT22(mvTmp3,mvTmp5);
      mvTmp1 = mbInfo[3];
      mvTmp2 = mbInfo[2];
      mvTmp3 = mbInfo[5];
      mvTmp4 = mbInfo[6];
      mvTmp5 = mbInfo[4];
      mvTmp6 = mbInfo[7];
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ce8)) =
           ((int)mbInfo[1] - ((int)mbInfo[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)*mbInfo - ((int)*mbInfo >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cec)) =
           ((int)mvTmp1 - ((int)mvTmp1 >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)mvTmp2 - ((int)mvTmp2 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cf0)) =
           ((int)mvTmp3 - ((int)mvTmp3 >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)mvTmp5 - ((int)mvTmp5 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cf4)) =
           ((int)mvTmp6 - ((int)mvTmp6 >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)mvTmp4 - ((int)mvTmp4 >> 0x1f)) >> 1 & 0xffff;
      mbOffsetBytes = mbOffsetBytes + *(int *)(ctx + 0x153fc);
      mbPosOrListEntry = ctx + 0x14428 +
              ((uint)*(byte *)((int)mbInfo + 0x11) * 2 + (uint)*(byte *)(mbInfo + 8)) * 0xc;
      if (*(char *)(ctx + 0x590) == '\0') {
        descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x84);
        *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x8c)) = mbOffsetBytes;
        *(int *)(mbPosOrListEntry + 0x84) = descOrSurfaceEntry + -1;
      }
      else {
        descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x88);
        *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x8c)) = mbOffsetBytes;
        *(int *)(mbPosOrListEntry + 0x88) = descOrSurfaceEntry + 1;
      }
      mbPosOrListEntry = ctx + 0x14428 +
              ((uint)*(byte *)((int)mbInfo + 0x13) * 2 + (uint)*(byte *)(mbInfo + 9)) * 0xc;
      descOrSurfaceEntry = mbPosOrListEntry + 0xb4;
      if (*(char *)(ctx + 0x590) == '\0') {
        descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0xb4);
        *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0xbc)) = mbOffsetBytes;
        *(int *)(mbPosOrListEntry + 0xb4) = descOrSurfaceEntry + -1;
        return;
      }
    }
    mbPosOrListEntry = *(int *)(descOrSurfaceEntry + 4);
    *(int *)(mbPosOrListEntry * 4 + *(int *)(descOrSurfaceEntry + 8)) = mbOffsetBytes;
    *(int *)(descOrSurfaceEntry + 4) = mbPosOrListEntry + 1;
    return;
  }
  switch(*(undefined1 *)(mbInfo + 10)) {
  default:
    goto mbInfoCase0;
  case 1:
    descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
    surfaceOrListBase = ctx + 0x14428;
    *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c98) + mbPosOrListEntry * 4) = CONCAT22(mbInfo[1],*mbInfo);
    *(uint *)(mbPosOrListEntry * 4 + *(int *)(descOrSurfaceEntry + 0x14ce8)) =
         ((int)mbInfo[1] - ((int)mbInfo[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)*mbInfo - ((int)*mbInfo >> 0x1f)) >> 1 & 0xffff;
    mbPosOrListEntry = (uint)*(byte *)(mbInfo + 8) * 0xc;
    descOrSurfaceEntry = surfaceOrListBase + mbPosOrListEntry;
    if (*(char *)(ctx + 0x590) == '\0') {
      mbColumn = *(int *)(surfaceOrListBase + mbPosOrListEntry);
      *(int *)(mbColumn * 4 + *(int *)(descOrSurfaceEntry + 8)) = mbOffsetBytes;
      *(int *)(surfaceOrListBase + mbPosOrListEntry) = mbColumn + -1;
      return;
    }
    break;
  case 2:
    descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
    *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c9c) + mbPosOrListEntry * 4) = CONCAT22(mbInfo[3],mbInfo[2]);
    *(uint *)(mbPosOrListEntry * 4 + *(int *)(descOrSurfaceEntry + 0x14cec)) =
         ((int)mbInfo[3] - ((int)mbInfo[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)mbInfo[2] - ((int)mbInfo[2] >> 0x1f)) >> 1 & 0xffff;
    mbPosOrListEntry = ctx + 0x14428 + (uint)*(byte *)((int)mbInfo + 0x11) * 0xc;
    descOrSurfaceEntry = mbPosOrListEntry + 0x18;
    if (*(char *)(ctx + 0x590) == '\0') {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x18);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x20)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 0x18) = descOrSurfaceEntry + -1;
      return;
    }
    break;
  case 3:
    mbPosOrListEntry = mbPosOrListEntry * 4;
    descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
    *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c98) + mbPosOrListEntry) = CONCAT22(mbInfo[1],*mbInfo);
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14c9c)) = CONCAT22(mbInfo[3],mbInfo[2]);
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ce8)) =
         ((int)mbInfo[1] - ((int)mbInfo[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)*mbInfo - ((int)*mbInfo >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cec)) =
         ((int)mbInfo[3] - ((int)mbInfo[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)mbInfo[2] - ((int)mbInfo[2] >> 0x1f)) >> 1 & 0xffff;
    mbPosOrListEntry = ctx + 0x14428 +
            ((uint)*(byte *)((int)mbInfo + 0x11) * 2 + (uint)*(byte *)(mbInfo + 8)) * 0xc;
    descOrSurfaceEntry = mbPosOrListEntry + 0x30;
    if (*(char *)(ctx + 0x590) == '\0') {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x30);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x38)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 0x30) = descOrSurfaceEntry + -1;
      return;
    }
    break;
  case 5:
    mbPosOrListEntry = mbPosOrListEntry * 4;
    mvTmp1 = mbInfo[5];
    descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
    mvTmp2 = mbInfo[4];
    *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c98) + mbPosOrListEntry) = CONCAT22(mbInfo[1],*mbInfo);
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ca0)) = CONCAT22(mvTmp1,mvTmp2);
    mvTmp1 = mbInfo[5];
    mvTmp2 = mbInfo[4];
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ce8)) =
         ((int)mbInfo[1] - ((int)mbInfo[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)*mbInfo - ((int)*mbInfo >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cf0)) =
         ((int)mvTmp1 - ((int)mvTmp1 >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)mvTmp2 - ((int)mvTmp2 >> 0x1f)) >> 1 & 0xffff;
    mbPosOrListEntry = ctx + 0x14428 + (uint)*(byte *)(mbInfo + 8) * 0xc;
    mbOffsetBytes = (mbColumn + mbRow * *(int *)(ctx + 0x580) * 2) * 4 + *(int *)(ctx + 0x153fc);
    if (*(char *)(ctx + 0x590) == '\0') {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x60);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x68)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 0x60) = descOrSurfaceEntry + -1;
    }
    else {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 100);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x68)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 100) = descOrSurfaceEntry + 1;
    }
    mbPosOrListEntry = ctx + 0x14428 + (uint)*(byte *)(mbInfo + 9) * 0xc;
    mbOffsetBytes = mbOffsetBytes + *(int *)(ctx + 0x580) * 4;
    descOrSurfaceEntry = mbPosOrListEntry + 0x78;
    if (*(char *)(ctx + 0x590) == '\0') {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x78);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x80)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 0x78) = descOrSurfaceEntry + -1;
      return;
    }
    goto setMbPosOrListEntry2;
  case 6:
    mbPosOrListEntry = mbPosOrListEntry * 4;
    mvTmp1 = mbInfo[7];
    descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
    mvTmp2 = mbInfo[6];
    *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c9c) + mbPosOrListEntry) = CONCAT22(mbInfo[3],mbInfo[2]);
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ca4)) = CONCAT22(mvTmp1,mvTmp2);
    mvTmp1 = mbInfo[7];
    mvTmp2 = mbInfo[6];
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cec)) =
         ((int)mbInfo[3] - ((int)mbInfo[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)mbInfo[2] - ((int)mbInfo[2] >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cf4)) =
         ((int)mvTmp1 - ((int)mvTmp1 >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)mvTmp2 - ((int)mvTmp2 >> 0x1f)) >> 1 & 0xffff;
    mbPosOrListEntry = ctx + 0x14428 + (uint)*(byte *)((int)mbInfo + 0x11) * 0xc;
    mbOffsetBytes = (mbColumn + mbRow * *(int *)(ctx + 0x580) * 2) * 4 + *(int *)(ctx + 0x153fc);
    if (*(char *)(ctx + 0x590) == '\0') {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x90);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x98)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 0x90) = descOrSurfaceEntry + -1;
    }
    else {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0x94);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0x98)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 0x94) = descOrSurfaceEntry + 1;
    }
    mbPosOrListEntry = ctx + 0x14428 + (uint)*(byte *)((int)mbInfo + 0x13) * 0xc;
    mbOffsetBytes = mbOffsetBytes + *(int *)(ctx + 0x580) * 4;
    descOrSurfaceEntry = mbPosOrListEntry + 0xa8;
    if (*(char *)(ctx + 0x590) == '\0') {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0xa8);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0xb0)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 0xa8) = descOrSurfaceEntry + -1;
      return;
    }
    goto setMbPosOrListEntry2;
  case 7:
    mbPosOrListEntry = mbPosOrListEntry * 4;
    mvTmp4 = mbInfo[2];
    mvTmp5 = mbInfo[6];
    descOrSurfaceEntry = surfaceOrListBase * 0x10 + descOrSurfaceEntry;
    mvTmp1 = mbInfo[3];
    mvTmp2 = mbInfo[5];
    mvTmp3 = mbInfo[7];
    mvTmp6 = mbInfo[4];
    *(uint *)(*(int *)(descOrSurfaceEntry + 0x14c98) + mbPosOrListEntry) = CONCAT22(mbInfo[1],*mbInfo);
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14c9c)) = CONCAT22(mvTmp1,mvTmp4);
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ca0)) = CONCAT22(mvTmp2,mvTmp6);
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ca4)) = CONCAT22(mvTmp3,mvTmp5);
    mvTmp1 = mbInfo[3];
    mvTmp2 = mbInfo[2];
    mvTmp3 = mbInfo[5];
    mvTmp4 = mbInfo[6];
    mvTmp5 = mbInfo[4];
    mvTmp6 = mbInfo[7];
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14ce8)) =
         ((int)mbInfo[1] - ((int)mbInfo[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)*mbInfo - ((int)*mbInfo >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cec)) =
         ((int)mvTmp1 - ((int)mvTmp1 >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)mvTmp2 - ((int)mvTmp2 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cf0)) =
         ((int)mvTmp3 - ((int)mvTmp3 >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)mvTmp5 - ((int)mvTmp5 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(mbPosOrListEntry + *(int *)(descOrSurfaceEntry + 0x14cf4)) =
         ((int)mvTmp6 - ((int)mvTmp6 >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)mvTmp4 - ((int)mvTmp4 >> 0x1f)) >> 1 & 0xffff;
    mbPosOrListEntry = ctx + 0x14428 +
            ((uint)*(byte *)((int)mbInfo + 0x11) * 2 + (uint)*(byte *)(mbInfo + 8)) * 0xc;
    mbOffsetBytes = (mbColumn + mbRow * *(int *)(ctx + 0x580) * 2) * 4 + *(int *)(ctx + 0x153fc);
    if (*(char *)(ctx + 0x590) == '\0') {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0xc0);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 200)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 0xc0) = descOrSurfaceEntry + -1;
    }
    else {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0xc4);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 200)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 0xc4) = descOrSurfaceEntry + 1;
    }
    mbOffsetBytes = mbOffsetBytes + *(int *)(ctx + 0x580) * 4;
    mbPosOrListEntry = ctx + 0x14428 +
            ((uint)*(byte *)((int)mbInfo + 0x13) * 2 + (uint)*(byte *)(mbInfo + 9)) * 0xc;
    descOrSurfaceEntry = mbPosOrListEntry + 0xf0;
    if (*(char *)(ctx + 0x590) == '\0') {
      descOrSurfaceEntry = *(int *)(mbPosOrListEntry + 0xf0);
      *(int *)(descOrSurfaceEntry * 4 + *(int *)(mbPosOrListEntry + 0xf8)) = mbOffsetBytes;
      *(int *)(mbPosOrListEntry + 0xf0) = descOrSurfaceEntry + -1;
      return;
    }
setMbPosOrListEntry2:
    mbPosOrListEntry = *(int *)(descOrSurfaceEntry + 4);
    *(int *)(mbPosOrListEntry * 4 + *(int *)(descOrSurfaceEntry + 8)) = mbOffsetBytes;
    *(int *)(descOrSurfaceEntry + 4) = mbPosOrListEntry + 1;
    goto mbInfoCase0;
  }
  mbPosOrListEntry = *(int *)(descOrSurfaceEntry + 4);
  *(int *)(mbPosOrListEntry * 4 + *(int *)(descOrSurfaceEntry + 8)) = mbOffsetBytes;
  *(int *)(descOrSurfaceEntry + 4) = mbPosOrListEntry + 1;
mbInfoCase0:
  return;
}

/* ava_get_driver_name @ 0x9670 (28 bytes) */
int ava_get_driver_name()
{
  return "ATIRadeonX1000";
}

/* ava_noop_9690 @ 0x9690 (4 bytes) */
int ava_noop_9690()
{
  return;
}

/* ava_emit_state_preamble @ 0x96a0 (96 bytes) */
int ava_emit_state_preamble(cmdPtr)
  undefined4 *cmdPtr;
{
  *cmdPtr = 0x5c8;
  cmdPtr[1] = 0x10030000;
  cmdPtr[2] = ((unsigned char *)0x00001002U);
  cmdPtr[3] = 0;
  cmdPtr[4] = 0x1381;
  cmdPtr[5] = 0;
  cmdPtr[6] = ((unsigned char *)0x00001040U);
  cmdPtr[7] = 0;
  return cmdPtr + 8;
}

/* ava_emit_shader_stage_setup @ 0x9700 (528 bytes) */
int ava_emit_shader_stage_setup(cmdPtr, stageCount)
  undefined4 *cmdPtr;
  uint stageCount;
{
  uint *nextEntry;
  int *tableCursor;
  int *entryCursor;
  uint stageMaskOrNext;
  uint stageIndex;
  int halfIndex;
  undefined4 programWord;
  
  *cmdPtr = 0x850;
  cmdPtr[1] = 0x102;
  cmdPtr[2] = 0x854;
  if (stageCount == 1) {
    programWord = 0x26010001;
  }
  else {
    programWord = 0x6010001;
  }
  cmdPtr[3] = programWord;
  cmdPtr[4] = 0x878;
  tableCursor = cmdPtr + 6;
  cmdPtr[5] = 0xf688f688;
  if (1 < (int)stageCount) {
    entryCursor = tableCursor;
    stageIndex = 1;
    do {
      halfIndex = ((int)stageIndex >> 1) + (uint)((int)stageIndex < 0 && (stageIndex & 1) != 0);
      stageMaskOrNext = stageIndex + 2;
      *entryCursor = halfIndex + 0x855;
      entryCursor[1] = (uint)(stageCount == stageIndex + 1) << 0xd | (stageIndex + 6) * 0x100 |
                  (uint)(stageCount == stageMaskOrNext) << 0x1d | (stageIndex + 7) * 0x1000000 | 0x10001;
      entryCursor[2] = halfIndex + 0x879;
      tableCursor = entryCursor + 4;
      entryCursor[3] = -0x9770978;
      entryCursor = tableCursor;
      stageIndex = stageMaskOrNext;
    } while ((int)stageMaskOrNext < (int)stageCount);
  }
  *tableCursor = 0x824;
  tableCursor[1] = 1;
  if (0 < (int)stageCount) {
    stageMaskOrNext = 0;
    stageIndex = stageCount;
    do {
      stageMaskOrNext = stageMaskOrNext | stageMaskOrNext << 3 | 2;
      stageIndex = stageIndex - 1;
    } while (stageIndex != 0);
  }
  else {
    stageMaskOrNext = 0;
  }
  tableCursor[2] = 0x825;
  tableCursor[3] = stageMaskOrNext;
  tableCursor[4] = (int)0x000010c0;
  tableCursor[5] = stageCount << 1 | 0x40000;
  tableCursor[6] = 0x10c1;
  entryCursor = tableCursor + 8;
  tableCursor[7] = stageCount - 1;
  if (0 < (int)stageCount) {
    stageIndex = 0;
    halfIndex = 1;
    do {
      *entryCursor = (int)(((unsigned char *)0x0000101dU) + stageIndex);
      entryCursor[1] = stageIndex << 1 | halfIndex << 6 | 0x28ffe000;
      entryCursor[2] = stageIndex + 0x10c8;
      nextEntry = (uint *)(entryCursor + 3);
      entryCursor = entryCursor + 4;
      *nextEntry = stageIndex | stageIndex << 5 | 0x10;
      stageIndex = stageIndex + 1;
      halfIndex = halfIndex + 2;
      stageCount = stageCount - 1;
    } while (stageCount != 0);
    return entryCursor;
  }
  return entryCursor;
}

/* ava_emit_register_data @ 0x9930 (80 bytes) */
int ava_emit_register_data(cmdPtr, registerHeader, data, count)
  uint *cmdPtr;
  uint registerHeader;
  uint *data;
  int count;
{
  uint word;
  
  *cmdPtr = (count + -1) * 0x10000 | registerHeader | 0x8000;
  for (; cmdPtr = cmdPtr + 1, count != 0; count = count + -1) {
    word = *data;
    data = data + 1;
    *cmdPtr = word;
  }
  return cmdPtr;
}

/* ava_emit_us_vector_data @ 0x9980 (48 bytes) */
int ava_emit_us_vector_data(cmdPtr, registerValue, count, data)
  undefined4 *cmdPtr;
  undefined4 registerValue;
  undefined4 count;
  undefined4 data;
{
  undefined4 nextPtr;
  
  *cmdPtr = 0x1094;
  cmdPtr[1] = registerValue;
  nextPtr = ((int (*)())ava_emit_register_data)(cmdPtr + 2,0x1095,data,count);
  return nextPtr;
}

/* ava_emit_shader_constants @ 0x99b0 (264 bytes) */
int ava_emit_shader_constants(cmdPtr, constBlockB, constCountB, constBlockA, constWordsA, flagsWord)
  undefined4 *cmdPtr;
  int constBlockB;
  int constCountB;
  int constBlockA;
  uint constWordsA;
  undefined4 flagsWord;
{
  int countField;
  
  if (constBlockA != 0) {
    cmdPtr = (undefined4 *)((int (*)())ava_emit_us_vector_data)(cmdPtr,0x10000,(constWordsA & 0xfffffff) << 2,constBlockA);
  }
  if (constBlockB != 0) {
    cmdPtr = (undefined4 *)((int (*)())ava_emit_us_vector_data)(cmdPtr,0,(uint)(constCountB * 0x18) >> 2,constBlockB);
  }
  *cmdPtr = 0x1180;
  cmdPtr[1] = 0;
  cmdPtr[2] = 0x11ad;
  cmdPtr[3] = 0;
  cmdPtr[4] = 0x1181;
  cmdPtr[5] = flagsWord;
  cmdPtr[6] = 0x118c;
  countField = (constCountB + -1) * 0x10000;
  cmdPtr[7] = countField;
  cmdPtr[8] = 0x118d;
  cmdPtr[9] = countField;
  cmdPtr[10] = 0x118e;
  cmdPtr[0xb] = 0;
  cmdPtr[0xc] = 0x1189;
  cmdPtr[0xd] = 0;
  return cmdPtr + 0xe;
}

/* ava_emit_textured_quad @ 0x9ac0 (424 bytes) */
int ava_emit_textured_quad(cmdPtr, srcCoords, dstCoords, srcWidth, srcHeight)
  undefined4 *cmdPtr;
  float *srcCoords;
  undefined4 *dstCoords;
  undefined4 srcWidth;
  undefined4 srcHeight;
{
  undefined4 dstTop;
  undefined4 dstRight;
  float uLeft;
  float uRight;
  float vTop;
  float vBottom;
  undefined4 dstLeft;
  undefined4 dstBottom;
  
  *cmdPtr = 0x82d;
  cmdPtr[1] = 4;
  cmdPtr[2] = 0xc0103500;
  cmdPtr[3] = 0x4083d;
  if (srcCoords == (float *)0x0) {
    vTop = 0.0;
    vBottom = 1.0;
    uLeft = 0.0;
    uRight = 1.0;
  }
  else {
    vTop = (float)((double)CONCAT44(0x43300000,srcHeight) - DOUBLE_0000d418);
    uLeft = (float)((double)CONCAT44(0x43300000,srcWidth) - DOUBLE_0000d418);
    vBottom = srcCoords[3] / vTop;
    uRight = srcCoords[1] / uLeft;
    uLeft = *srcCoords / uLeft;
    vTop = srcCoords[2] / vTop;
  }
  dstLeft = *dstCoords;
  cmdPtr[4] = dstLeft;
  dstTop = dstCoords[2];
  cmdPtr[5] = dstTop;
  cmdPtr[6] = uLeft;
  cmdPtr[7] = vTop;
  cmdPtr[8] = dstLeft;
  dstBottom = dstCoords[3];
  cmdPtr[9] = dstBottom;
  cmdPtr[10] = uLeft;
  cmdPtr[0xb] = vBottom;
  dstRight = dstCoords[1];
  cmdPtr[0xc] = dstRight;
  cmdPtr[0xd] = dstBottom;
  cmdPtr[0xe] = uRight;
  cmdPtr[0xf] = vBottom;
  cmdPtr[0x10] = dstRight;
  cmdPtr[0x11] = dstTop;
  cmdPtr[0x12] = uRight;
  cmdPtr[0x13] = vTop;
  cmdPtr[0x14] = 0x1393;
  cmdPtr[0x15] = 10;
  return cmdPtr + 0x16;
}

/* ava_render_hue_saturation_pass @ 0x9c80 (1160 bytes) */
int ava_render_hue_saturation_pass(ctx, headerWord, enableFlag)
  int ctx;
  undefined4 headerWord;
  int enableFlag;
{
  float hueAngle;
  float saturation;
  float contrast;
  uint quadWidth;
  uint halfHeight;
  undefined *mapMemoryType;
  uint *lastHeader;
  undefined4 cmdAfterClear;
  undefined4 *cmdWrite;
  uint sizeWord;
  uint pitchBytes;
  double cosHue;
  double sinHue;
  undefined4 dstLeft;
  float dstRight;
  undefined4 dstTop;
  float dstBottom;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  int mapBase;
  int fillCount;
  int pitchWordsMinus1;
  
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  cmdWrite = *(undefined4 **)(ctx + 0x34);
  pitchBytes = *(uint *)(ctx + 0x588);
  quadWidth = *(uint *)(ctx + 0x578) >> 2;
  halfHeight = *(uint *)(ctx + 0x57c) >> 1;
  if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x90) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                        ctx + 0x44,1);
    mapBase = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBase + 0x20;
    *(int *)(ctx + 0x30) = mapBase + 0x1c;
    *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
    *(undefined4 *)(mapBase + 0x1c) = 0;
    cmdWrite = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x90;
  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = cmdWrite;
  *cmdWrite = 0x42000000;
  cmdWrite[1] = headerWord;
  cmdWrite[2] = (uint)(enableFlag != 0);
  cmdWrite = cmdWrite + 3;
  fillCount = 7;
  do {
    *cmdWrite = 0x80000000;
    cmdWrite = cmdWrite + 1;
    fillCount = fillCount + -1;
  } while (fillCount != 0);
  cmdAfterClear = ((int (*)())ava_emit_state_preamble)(cmdWrite);
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_stage_setup)(cmdAfterClear,1);
  *cmdWrite = ((unsigned char *)0x00001041U);
  cmdWrite[1] = 3;
  cmdWrite[2] = 0x1100;
  cmdWrite[3] = 0xa92;
  cmdWrite[4] = 0x1110;
  cmdWrite[5] = 0;
  cmdWrite[6] = 0x1120;
  sizeWord = quadWidth - 1 | (halfHeight - 1) * 0x800 | 0x80000000;
  cmdWrite[7] = sizeWord;
  cmdWrite[8] = 0x1130;
  cmdWrite[9] = 0xa60c;
  cmdWrite[10] = 0x1140;
  pitchWordsMinus1 = (pitchBytes >> 2) - 1;
  cmdWrite[0xb] = pitchWordsMinus1;
  cmdWrite[0xc] = 0x1101;
  cmdWrite[0xd] = 0x10000a92;
  cmdWrite[0xe] = 0x1111;
  cmdWrite[0xf] = 0;
  cmdWrite[0x10] = 0x1121;
  cmdWrite[0x11] = sizeWord;
  cmdWrite[0x12] = 0x1131;
  cmdWrite[0x13] = 0x4340c;
  cmdWrite[0x14] = 0x1141;
  cmdWrite[0x15] = pitchWordsMinus1;
  hueAngle = *(float *)(ctx + 300);
  saturation = *(float *)(ctx + 0x138);
  contrast = *(float *)(ctx + 0x130);
  cosHue = _cos((double)hueAngle);
  sinHue = _sin((double)hueAngle);
  hueSaturationConstReg0X_0000f004 = (float)(cosHue * (double)saturation * (double)contrast);
  hueSaturationConstReg2X_0000f024 = (float)((double)contrast * (double)saturation * -sinHue);
  hueSaturationConstReg2Y_0000f028 = -hueSaturationConstReg2X_0000f024;
  hueSaturationConstReg1Y_0000f018 = ((hueSaturationConstReg2X_0000f024 + (1.0 - hueSaturationConstReg0X_0000f004)) * 128.0) / 255.0;
  hueSaturationConstReg1X_0000f014 = (((1.0 - hueSaturationConstReg0X_0000f004) - hueSaturationConstReg2X_0000f024) * 128.0) / 255.0;
  hueSaturationConstReg0Y_0000f008 = hueSaturationConstReg0X_0000f004;
  hueSaturationConstReg0Z_0000f00c = hueSaturationConstReg0X_0000f004;
  hueSaturationConstReg0W_0000f010 = hueSaturationConstReg0X_0000f004;
  hueSaturationConstReg1Z_0000f01c = hueSaturationConstReg1X_0000f014;
  hueSaturationConstReg1W_0000f020 = hueSaturationConstReg1Y_0000f018;
  hueSaturationConstReg2Z_0000f02c = hueSaturationConstReg2X_0000f024;
  hueSaturationConstReg2W_0000f030 = hueSaturationConstReg2Y_0000f028;
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_constants)(cmdWrite + 0x16,&hueSaturationShaderProgram_0000ea9c,4,&hueSaturationConstReg0X_0000f004,3,3);
  *cmdWrite = 0x11a9;
  cmdWrite[1] = 0x1b00;
  cmdWrite[2] = 0x11aa;
  cmdWrite[3] = 0xf;
  cmdWrite[4] = 0x11ab;
  cmdWrite[5] = 0xf;
  cmdWrite[6] = 0x11ac;
  cmdWrite[7] = 0xf;
  i2dLo1 = quadWidth ^ 0x80000000;
  i2dLo2 = halfHeight ^ 0x80000000;
  i2dHi2 = 0x43300000;
  i2dHi1 = 0x43300000;
  dstTop = 0;
  dstLeft = 0;
  dstBottom = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0);
  dstRight = (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0);
  ((int (*)())ava_emit_textured_quad)(cmdWrite + 8,0,&dstLeft,quadWidth,halfHeight);
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                      ctx + 0x44,1);
  mapBase = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = mapBase + 0x20;
  *(int *)(ctx + 0x30) = mapBase + 0x1c;
  *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
  *(undefined4 *)(mapBase + 0x1c) = 0;
  return;
}

/* ava_render_brightness_contrast_pass @ 0xa110 (964 bytes) */
int ava_render_brightness_contrast_pass(ctx, headerWord, enableFlag)
  int ctx;
  undefined4 headerWord;
  int enableFlag;
{
  uint quadWidth;
  undefined *mapMemoryType;
  uint *lastHeader;
  undefined4 cmdAfterClear;
  undefined4 *cmdWrite;
  uint pitchBytes;
  uint surfaceHeight;
  undefined4 dstLeft;
  float dstRight;
  undefined4 dstTop;
  float dstBottom;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  int mapBase;
  int fillCount;
  
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  cmdWrite = *(undefined4 **)(ctx + 0x34);
  pitchBytes = *(uint *)(ctx + 0x588);
  surfaceHeight = *(uint *)(ctx + 0x57c);
  quadWidth = *(uint *)(ctx + 0x578) >> 2;
  if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x78) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                        ctx + 0x44,1);
    mapBase = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBase + 0x20;
    *(int *)(ctx + 0x30) = mapBase + 0x1c;
    *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
    *(undefined4 *)(mapBase + 0x1c) = 0;
    cmdWrite = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x78;
  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = cmdWrite;
  *cmdWrite = 0x3f000000;
  cmdWrite[1] = headerWord;
  cmdWrite[2] = (uint)(enableFlag != 0);
  cmdWrite = cmdWrite + 3;
  fillCount = 9;
  do {
    *cmdWrite = 0x80000000;
    cmdWrite = cmdWrite + 1;
    fillCount = fillCount + -1;
  } while (fillCount != 0);
  cmdAfterClear = ((int (*)())ava_emit_state_preamble)(cmdWrite);
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_stage_setup)(cmdAfterClear,1);
  *cmdWrite = ((unsigned char *)0x00001041U);
  cmdWrite[1] = 1;
  cmdWrite[2] = 0x1100;
  cmdWrite[3] = 0xa92;
  cmdWrite[4] = 0x1110;
  cmdWrite[5] = 0;
  cmdWrite[6] = 0x1120;
  cmdWrite[7] = quadWidth - 1 | (surfaceHeight - 1) * 0x800 | 0x80000000;
  cmdWrite[8] = 0x1130;
  cmdWrite[9] = 0xa60c;
  cmdWrite[10] = 0x1140;
  cmdWrite[0xb] = (pitchBytes >> 2) - 1;
  brightnessContrastConstReg0X_0000f034 = *(undefined4 *)(ctx + 0x138);
  brightnessContrastConstReg1X_0000f044 = ((1.0 - *(float *)(ctx + 0x138)) * 128.0) / 255.0 + *(float *)(ctx + 0x134)
  ;
  brightnessContrastConstReg0Y_0000f038 = brightnessContrastConstReg0X_0000f034;
  brightnessContrastConstReg0Z_0000f03c = brightnessContrastConstReg0X_0000f034;
  brightnessContrastConstReg0W_0000f040 = brightnessContrastConstReg0X_0000f034;
  brightnessContrastConstReg1Y_0000f048 = brightnessContrastConstReg1X_0000f044;
  brightnessContrastConstReg1Z_0000f04c = brightnessContrastConstReg1X_0000f044;
  brightnessContrastConstReg1W_0000f050 = brightnessContrastConstReg1X_0000f044;
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_constants)(cmdWrite + 0xc,&brightnessContrastShaderProgram_0000eafc,2,&brightnessContrastConstReg0X_0000f034,2,2);
  *cmdWrite = 0x11a9;
  cmdWrite[1] = 0x1b00;
  cmdWrite[2] = 0x11aa;
  cmdWrite[3] = 0xf;
  cmdWrite[4] = 0x11ab;
  cmdWrite[5] = 0xf;
  cmdWrite[6] = 0x11ac;
  cmdWrite[7] = 0xf;
  i2dLo1 = quadWidth ^ 0x80000000;
  i2dLo2 = surfaceHeight ^ 0x80000000;
  i2dHi2 = 0x43300000;
  i2dHi1 = 0x43300000;
  dstTop = 0;
  dstLeft = 0;
  dstBottom = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0);
  dstRight = (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0);
  ((int (*)())ava_emit_textured_quad)(cmdWrite + 8,0,&dstLeft,quadWidth,surfaceHeight);
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                      ctx + 0x44,1);
  mapBase = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = mapBase + 0x20;
  *(int *)(ctx + 0x30) = mapBase + 0x1c;
  *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
  *(undefined4 *)(mapBase + 0x1c) = 0;
  return;
}

/* ava_render_convert_frame @ 0xa4e0 (1304 bytes) */
int ava_render_convert_frame(ctx, slotIndex, pixelDesc)
  int ctx;
  int slotIndex;
  int pixelDesc;
{
  undefined *mapMemoryType;
  uint *lastHeader;
  undefined4 cmdAfterClear;
  uint surfaceWidth;
  uint pitchBytes;
  uint surfaceHeight;
  undefined4 *cmdWrite;
  undefined4 dstLeft;
  float dstRight;
  undefined4 dstTop;
  float dstBottom;
  undefined4 i2dHi1;
  undefined4 i2dLo1;
  undefined4 i2dHi2;
  undefined4 i2dLo2;
  int mapBase;
  int fillCount;
  int formatCode;
  
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  cmdWrite = *(undefined4 **)(ctx + 0x34);
  if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0xb0) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                        ctx + 0x44,1);
    mapBase = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBase + 0x20;
    *(int *)(ctx + 0x30) = mapBase + 0x1c;
    *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
    *(undefined4 *)(mapBase + 0x1c) = 0;
    cmdWrite = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = cmdWrite + 0xb0;
  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = cmdWrite;
  *cmdWrite = 0x44000000;
  cmdWrite[1] = slotIndex;
  cmdWrite[2] = 0x11;
  cmdWrite[3] = (uint)(*(int *)(slotIndex * 4 + ctx + 0x55c + 0x554) != 0);
  cmdWrite[4] = *(undefined4 *)(ctx + 0x11c);
  cmdWrite = cmdWrite + 5;
  fillCount = 5;
  do {
    *cmdWrite = 0x80000000;
    cmdWrite = cmdWrite + 1;
    fillCount = fillCount + -1;
  } while (fillCount != 0);
  cmdAfterClear = ((int (*)())ava_emit_state_preamble)(cmdWrite);
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_stage_setup)(cmdAfterClear,1);
  *cmdWrite = 0x1100;
  cmdWrite[1] = 0xa92;
  cmdWrite[2] = 0x1110;
  cmdWrite[3] = 0;
  cmdWrite[4] = 0x1120;
  surfaceHeight = *(uint *)(ctx + 0x57c);
  surfaceWidth = *(uint *)(ctx + 0x578);
  cmdWrite[5] = (surfaceHeight - 1) * 0x800 | surfaceWidth - 1 | 0x80000000;
  cmdWrite[6] = 0x1130;
  cmdWrite[7] = 0x10120800;
  cmdWrite[8] = 0x1140;
  pitchBytes = *(uint *)(ctx + 0x588);
  cmdWrite[9] = pitchBytes - 1;
  cmdWrite[10] = 0x1101;
  cmdWrite[0xb] = 0x10000a92;
  cmdWrite[0xc] = 0x1111;
  cmdWrite[0xd] = 0;
  cmdWrite[0xe] = 0x1121;
  cmdWrite[0xf] = ((surfaceHeight >> 1) - 1) * 0x800 | (surfaceWidth >> 1) - 1 | 0x80000000;
  cmdWrite[0x10] = 0x1131;
  cmdWrite[0x11] = 0x18044803;
  cmdWrite[0x12] = 0x1141;
  cmdWrite[0x13] = (pitchBytes >> 1) - 1;
  cmdWrite[0x14] = ((unsigned char *)0x00001041U);
  cmdWrite[0x15] = 3;
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_constants)(cmdWrite + 0x16,&convertAndSourceRectShaderProgram_0000eb7c,7,&convertAndSourceRectShaderConstants_0000eb2c,5,3);
  formatCode = *(int *)(pixelDesc + 0xc);
  if (((formatCode == 0x61726762) || (formatCode == 0x61723135)) || (formatCode != 0x72676261)) {
    *cmdWrite = 0x11a9;
    cmdWrite[1] = 0x1b00;
  }
  else {
    *cmdWrite = 0x11a9;
    cmdWrite[1] = 0x6c00;
  }
  cmdWrite[2] = 0x11aa;
  cmdWrite[3] = 0xf;
  cmdWrite[4] = 0x11ab;
  cmdWrite[5] = 0xf;
  cmdWrite[6] = 0x11ac;
  cmdWrite[7] = 0xf;
  cmdWrite[8] = 0x1393;
  cmdWrite[9] = 10;
  if (formatCode == 0x61723135) {
    cmdWrite[10] = 0x138e;
    cmdWrite[0xb] = *(uint *)(pixelDesc + 8) >> 1 & 0x3ffe | 0x680000;
  }
  else {
    cmdWrite[10] = 0x138e;
    cmdWrite[0xb] = *(uint *)(pixelDesc + 8) >> 2 & 0x3ffe | 0xd00000;
  }
  i2dLo1 = *(undefined4 *)(ctx + 0x578);
  i2dLo2 = *(undefined4 *)(ctx + 0x57c);
  i2dHi2 = 0x43300000;
  i2dHi1 = 0x43300000;
  dstTop = 0;
  dstLeft = 0;
  dstRight = (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503599627370496.0);
  dstBottom = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503599627370496.0);
  cmdWrite = (undefined4 *)((int (*)())ava_emit_textured_quad)(cmdWrite + 0xc,0,&dstLeft,i2dLo1,i2dLo2);
  *cmdWrite = 0x5c8;
  cmdWrite[1] = 0x10030000;
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                      ctx + 0x44,1);
  mapBase = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = mapBase + 0x20;
  *(int *)(ctx + 0x30) = mapBase + 0x1c;
  *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
  *(undefined4 *)(mapBase + 0x1c) = 0;
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + ctx + 0x55c + 0x570) =
       *(undefined4 *)(*(int *)(ctx + 0x40) + 0x18);
  return;
}

/* ava_render_convert_frame_yuv2 @ 0xaa00 (1152 bytes) */
int ava_render_convert_frame_yuv2(ctx, slotIndex, pixelDesc)
  int ctx;
  int slotIndex;
  int pixelDesc;
{
  uint halfWidth;
  undefined *mapMemoryType;
  uint pitchBytes;
  uint *lastHeader;
  undefined4 cmdAfterClear;
  undefined4 *cmdWrite;
  uint surfaceHeight;
  undefined4 dstLeft;
  float dstRight;
  undefined4 dstTop;
  float dstBottom;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  int mapBase;
  int fillCount;
  int pitchWordsMinus1;
  
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  cmdWrite = *(undefined4 **)(ctx + 0x34);
  pitchBytes = *(uint *)(ctx + 0x588);
  surfaceHeight = *(uint *)(ctx + 0x57c);
  halfWidth = *(uint *)(ctx + 0x578) >> 1;
  if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x88) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                        ctx + 0x44,1);
    mapBase = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBase + 0x20;
    *(int *)(ctx + 0x30) = mapBase + 0x1c;
    *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
    *(undefined4 *)(mapBase + 0x1c) = 0;
    cmdWrite = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x88;
  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = cmdWrite;
  *cmdWrite = 0x43000000;
  cmdWrite[1] = slotIndex;
  cmdWrite[2] = 0x11;
  cmdWrite[3] = (uint)(*(int *)(slotIndex * 4 + ctx + 0x55c + 0x554) != 0);
  cmdWrite[4] = *(undefined4 *)(ctx + 0x11c);
  cmdWrite = cmdWrite + 5;
  fillCount = 6;
  do {
    *cmdWrite = 0x80000000;
    cmdWrite = cmdWrite + 1;
    fillCount = fillCount + -1;
  } while (fillCount != 0);
  cmdAfterClear = ((int (*)())ava_emit_state_preamble)(cmdWrite);
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_stage_setup)(cmdAfterClear,1);
  *cmdWrite = ((unsigned char *)0x00001041U);
  cmdWrite[1] = 3;
  cmdWrite[2] = 0x1100;
  cmdWrite[3] = 0xa92;
  cmdWrite[4] = 0x1110;
  cmdWrite[5] = 0;
  cmdWrite[6] = 0x1120;
  cmdWrite[7] = halfWidth - 1 | (surfaceHeight - 1) * 0x800 | 0x80000000;
  cmdWrite[8] = 0x1130;
  cmdWrite[9] = 0x10060803;
  cmdWrite[10] = 0x1140;
  pitchWordsMinus1 = (pitchBytes >> 1) - 1;
  cmdWrite[0xb] = pitchWordsMinus1;
  cmdWrite[0xc] = 0x1101;
  cmdWrite[0xd] = 0x10000a92;
  cmdWrite[0xe] = 0x1111;
  cmdWrite[0xf] = 0;
  cmdWrite[0x10] = 0x1121;
  cmdWrite[0x11] = halfWidth - 1 |
                 (((int)surfaceHeight >> 1) + (uint)((int)surfaceHeight < 0 && (surfaceHeight & 1) != 0) + -1) * 0x800 |
                 0x80000000;
  cmdWrite[0x12] = 0x1131;
  cmdWrite[0x13] = 0x1810c003;
  cmdWrite[0x14] = 0x1141;
  cmdWrite[0x15] = pitchWordsMinus1;
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_constants)(cmdWrite + 0x16,&convertFrameYuv2ShaderProgram_0000ec24,4,0,0,3);
  *cmdWrite = 0x11a9;
  cmdWrite[1] = 0x1b00;
  cmdWrite[2] = 0x11aa;
  cmdWrite[3] = 0xf;
  cmdWrite[4] = 0x11ab;
  cmdWrite[5] = 0xf;
  cmdWrite[6] = 0x11ac;
  cmdWrite[7] = 0xf;
  cmdWrite[8] = 0x1393;
  cmdWrite[9] = 10;
  cmdWrite[10] = 0x138e;
  cmdWrite[0xb] = *(uint *)(pixelDesc + 8) >> 2 & 0x3ffe | 0xd00000;
  i2dLo1 = halfWidth ^ 0x80000000;
  i2dLo2 = surfaceHeight ^ 0x80000000;
  i2dHi2 = 0x43300000;
  i2dHi1 = 0x43300000;
  dstTop = 0;
  dstLeft = 0;
  dstBottom = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0);
  dstRight = (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0);
  cmdWrite = (undefined4 *)((int (*)())ava_emit_textured_quad)(cmdWrite + 0xc,0,&dstLeft,halfWidth,surfaceHeight);
  *cmdWrite = 0x5c8;
  cmdWrite[1] = 0x10030000;
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                      ctx + 0x44,1);
  mapBase = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = mapBase + 0x20;
  *(int *)(ctx + 0x30) = mapBase + 0x1c;
  *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
  *(undefined4 *)(mapBase + 0x1c) = 0;
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + ctx + 0x55c + 0x570) =
       *(undefined4 *)(*(int *)(ctx + 0x40) + 0x18);
  return;
}

/* ava_render_scale_pass @ 0xae80 (2380 bytes) */
void ava_render_scale_pass(int ctx,double fpPassThrough,double unusedFp2,double unusedFp3,double unusedFp4)
{
  float srcHeightOrSrcTopScaled;
  float srcWidthOrSrcLeftScaled;
  float clipLeftOrWidthF;
  float heightFOrClipRightF;
  float clipBottomF;
  float surfaceHeightF;
  short clipLeft;
  short srcRight;
  short srcLeft;
  short clipTop;
  float srcRightScaled;
  float clippedLeft;
  float centerX;
  float srcBottomScaled;
  float clippedTop;
  float centerY;
  float scaleX;
  float scaleY;
  undefined *mapMemoryType;
  uint *lastHeader;
  undefined4 cmdAfterClear;
  int surfaceHeight;
  short clipBottom;
  short clipRight;
  undefined4 *cmdWrite;
  float srcCoordLeft;
  float srcCoordRight;
  float srcCoordTop;
  float srcCoordBottom;
  float dstOffsetLeft;
  float dstOffsetRight;
  float dstOffsetTop;
  float dstOffsetBottom;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  int i2dLo2;
  undefined4 i2dHi3;
  undefined4 i2dLo3;
  undefined4 i2dHi4;
  uint i2dLo4;
  undefined4 i2dHi5;
  uint i2dLo5;
  undefined4 i2dHi6;
  int i2dLo6;
  undefined4 i2dHi7;
  undefined4 i2dLo7;
  undefined4 i2dHi8;
  uint i2dLo8;
  undefined4 i2dHi9;
  uint i2dLo9;
  undefined4 i2dHi10;
  uint i2dLo10;
  undefined4 i2dHi11;
  int i2dLo11;
  undefined4 i2dHi12;
  undefined4 i2dLo12;
  undefined4 i2dHi13;
  uint i2dLo13;
  undefined4 i2dHi14;
  uint i2dLo14;
  undefined4 i2dHi15;
  int i2dLo15;
  undefined4 i2dHi16;
  undefined4 i2dLo16;
  undefined4 i2dHi17;
  uint i2dLo17;
  undefined4 i2dHi18;
  uint i2dLo18;
  undefined4 i2dHi19;
  uint i2dLo19;
  undefined4 i2dHi20;
  uint i2dLo20;
  undefined4 i2dHi21;
  uint i2dLo21;
  undefined4 i2dHi22;
  uint i2dLo22;
  undefined4 i2dHi23;
  uint i2dLo23;
  undefined4 i2dHi24;
  uint i2dLo24;
  undefined4 i2dHi25;
  uint i2dLo25;
  undefined4 i2dHi26;
  uint i2dLo26;
  undefined4 i2dHi27;
  uint i2dLo27;
  undefined4 i2dHi28;
  int i2dLo28;
  undefined4 i2dHi29;
  uint i2dLo29;
  undefined4 i2dHi30;
  int i2dLo30;
  undefined4 i2dHi31;
  uint i2dLo31;
  undefined4 i2dHi32;
  uint i2dLo32;
  undefined4 i2dHi33;
  uint i2dLo33;
  longlong d2iScratch1;
  undefined4 i2dHi34;
  uint i2dLo34;
  longlong d2iScratch2;
  undefined4 i2dHi35;
  uint i2dLo35;
  int surfaceWidth;
  int mapBase;
  int fillCount;
  
  clipLeft = *(short *)(ctx + 0x126);
  if ((int)clipLeft == 0) {
    surfaceWidth = *(int *)(ctx + 0x578);
    if ((*(short *)(ctx + 0x12a) != surfaceWidth) || (*(short *)(ctx + 0x124) != 0)) {
      surfaceHeight = *(int *)(ctx + 0x57c);
      goto setSrcRight;
    }
    surfaceHeight = *(int *)(ctx + 0x57c);
    if (*(short *)(ctx + 0x128) != surfaceHeight) goto setSrcRight;
    i2dHi1 = 0x43300000;
    i2dHi2 = 0x43300000;
    i2dHi4 = 0x43300000;
    i2dHi5 = 0x43300000;
    i2dHi6 = 0x43300000;
    i2dHi8 = 0x43300000;
    i2dLo4 = (int)*(short *)(ctx + 0x112) ^ 0x80000000;
    i2dLo1 = (int)*(short *)(ctx + 0x10e) ^ 0x80000000;
    i2dLo8 = (int)*(short *)(ctx + 0x110) ^ 0x80000000;
    i2dLo5 = (int)*(short *)(ctx + 0x10c) ^ 0x80000000;
    i2dLo9 = (int)*(short *)(ctx + 0x112) - (int)*(short *)(ctx + 0x10e) ^ 0x80000000;
    i2dLo10 = (int)*(short *)(ctx + 0x110) - (int)*(short *)(ctx + 0x10c) ^ 0x80000000;
    i2dLo3 = *(undefined4 *)(ctx + 0x60);
    i2dLo7 = *(undefined4 *)(ctx + 100);
    i2dHi3 = 0x43300000;
    i2dHi7 = 0x43300000;
    srcHeightOrSrcTopScaled = (float)((double)CONCAT44(0x43300000,surfaceWidth) - 4503599627370496.0);
    srcWidthOrSrcLeftScaled = (float)((double)CONCAT44(0x43300000,surfaceHeight) - 4503599627370496.0);
    srcCoordRight = (float)((double)CONCAT44(0x43300000,i2dLo3) - 4503599627370496.0);
    clipLeftOrWidthF = (float)((double)CONCAT44(0x43300000,i2dLo7) - 4503599627370496.0);
    srcCoordLeft = ((float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0) * srcHeightOrSrcTopScaled) /
                srcCoordRight;
    srcCoordRight = ((float)((double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0) * srcHeightOrSrcTopScaled) /
                srcCoordRight;
    srcCoordTop = ((float)((double)CONCAT44(0x43300000,i2dLo5) - 4503601774854144.0) * srcWidthOrSrcLeftScaled) /
                clipLeftOrWidthF;
    i2dHi10 = 0x43300000;
    i2dHi9 = 0x43300000;
    dstOffsetTop = 0.0;
    dstOffsetLeft = 0.0;
    dstOffsetBottom = (float)((double)CONCAT44(0x43300000,i2dLo10) - 4503601774854144.0);
    dstOffsetRight = (float)((double)CONCAT44(0x43300000,i2dLo9) - 4503601774854144.0);
    srcCoordBottom = ((float)((double)CONCAT44(0x43300000,i2dLo8) - 4503601774854144.0) * srcWidthOrSrcLeftScaled) /
                clipLeftOrWidthF;
    i2dLo2 = surfaceWidth;
    i2dLo6 = surfaceHeight;
  }
  else {
    surfaceHeight = *(int *)(ctx + 0x57c);
    surfaceWidth = *(int *)(ctx + 0x578);
setSrcRight:
    srcRight = *(short *)(ctx + 0x112);
    i2dHi11 = 0x43300000;
    i2dHi14 = 0x43300000;
    i2dLo14 = (int)srcRight ^ 0x80000000;
    i2dLo12 = *(undefined4 *)(ctx + 0x60);
    i2dLo19 = (int)clipLeft ^ 0x80000000;
    i2dHi12 = 0x43300000;
    srcLeft = *(short *)(ctx + 0x10e);
    i2dHi19 = 0x43300000;
    i2dHi13 = 0x43300000;
    i2dHi15 = 0x43300000;
    i2dHi17 = 0x43300000;
    i2dHi18 = 0x43300000;
    i2dLo17 = (int)*(short *)(ctx + 0x10c) ^ 0x80000000;
    i2dLo13 = (int)srcLeft ^ 0x80000000;
    i2dLo18 = (int)*(short *)(ctx + 0x110) ^ 0x80000000;
    srcHeightOrSrcTopScaled = (float)((double)CONCAT44(0x43300000,surfaceWidth) - 4503599627370496.0);
    i2dLo16 = *(undefined4 *)(ctx + 100);
    i2dHi16 = 0x43300000;
    srcWidthOrSrcLeftScaled = (float)((double)CONCAT44(0x43300000,i2dLo12) - 4503599627370496.0);
    srcRightScaled = (srcHeightOrSrcTopScaled * (float)((double)CONCAT44(0x43300000,i2dLo14) - 4503601774854144.0)) / srcWidthOrSrcLeftScaled
    ;
    clipLeftOrWidthF = (float)((double)CONCAT44(0x43300000,i2dLo19) - 4503601774854144.0);
    heightFOrClipRightF = (float)((double)CONCAT44(0x43300000,surfaceHeight) - 4503599627370496.0);
    srcWidthOrSrcLeftScaled = ((float)((double)CONCAT44(0x43300000,i2dLo13) - 4503601774854144.0) * srcHeightOrSrcTopScaled) / srcWidthOrSrcLeftScaled;
    srcHeightOrSrcTopScaled = (float)((double)CONCAT44(0x43300000,i2dLo16) - 4503599627370496.0);
    srcBottomScaled = (heightFOrClipRightF * (float)((double)CONCAT44(0x43300000,i2dLo18) - 4503601774854144.0)) / srcHeightOrSrcTopScaled
    ;
    srcHeightOrSrcTopScaled = ((float)((double)CONCAT44(0x43300000,i2dLo17) - 4503601774854144.0) * heightFOrClipRightF) / srcHeightOrSrcTopScaled;
    i2dLo11 = surfaceWidth;
    i2dLo15 = surfaceHeight;
    if (srcRightScaled <= clipLeftOrWidthF) goto callRestf24;
    if (srcRightScaled <= clipLeftOrWidthF) {
      clipRight = *(short *)(ctx + 0x12a);
loopSetI2dLo21:
      i2dLo21 = (int)clipRight ^ 0x80000000;
      i2dHi21 = 0x43300000;
      heightFOrClipRightF = (float)((double)CONCAT44(0x43300000,i2dLo21) - 4503601774854144.0);
      if (heightFOrClipRightF <= srcWidthOrSrcLeftScaled) goto callRestf24;
      clippedLeft = srcWidthOrSrcLeftScaled;
      if (srcWidthOrSrcLeftScaled - clipLeftOrWidthF < 0.0) {
        clippedLeft = clipLeftOrWidthF;
      }
      if (-(srcWidthOrSrcLeftScaled - clipLeftOrWidthF) < 0.0) {
        clippedLeft = srcWidthOrSrcLeftScaled;
      }
    }
    else {
      clipRight = *(short *)(ctx + 0x12a);
      i2dHi20 = 0x43300000;
      i2dLo20 = (int)clipRight ^ 0x80000000;
      if ((float)((double)CONCAT44(0x43300000,i2dLo20) - 4503601774854144.0) <= srcRightScaled)
      goto loopSetI2dLo21;
      clippedLeft = clipLeftOrWidthF;
      heightFOrClipRightF = srcRightScaled;
      if (clipLeftOrWidthF <= srcWidthOrSrcLeftScaled) {
        clippedLeft = srcWidthOrSrcLeftScaled;
      }
    }
    clipTop = *(short *)(ctx + 0x124);
    i2dHi22 = 0x43300000;
    i2dLo22 = (int)clipTop ^ 0x80000000;
    clipLeftOrWidthF = (float)((double)CONCAT44(0x43300000,i2dLo22) - 4503601774854144.0);
    if (srcBottomScaled <= clipLeftOrWidthF) goto callRestf24;
    if (srcBottomScaled <= clipLeftOrWidthF) {
      clipBottom = *(short *)(ctx + 0x128);
loopSetI2dLo24:
      i2dLo24 = (int)clipBottom ^ 0x80000000;
      i2dHi24 = 0x43300000;
      clipBottomF = (float)((double)CONCAT44(0x43300000,i2dLo24) - 4503601774854144.0);
      if (clipBottomF <= srcHeightOrSrcTopScaled) goto callRestf24;
      clippedTop = srcHeightOrSrcTopScaled;
      if (srcHeightOrSrcTopScaled - clipLeftOrWidthF < 0.0) {
        clippedTop = clipLeftOrWidthF;
      }
      if (-(srcHeightOrSrcTopScaled - clipLeftOrWidthF) < 0.0) {
        clippedTop = srcHeightOrSrcTopScaled;
      }
    }
    else {
      clipBottom = *(short *)(ctx + 0x128);
      i2dHi23 = 0x43300000;
      i2dLo23 = (int)clipBottom ^ 0x80000000;
      if ((float)((double)CONCAT44(0x43300000,i2dLo23) - 4503601774854144.0) <= srcBottomScaled)
      goto loopSetI2dLo24;
      clippedTop = clipLeftOrWidthF;
      clipBottomF = srcBottomScaled;
      if (clipLeftOrWidthF <= srcHeightOrSrcTopScaled) {
        clippedTop = srcHeightOrSrcTopScaled;
      }
    }
    i2dLo29 = (int)clipRight - (int)clipLeft ^ 0x80000000;
    i2dHi28 = 0x43300000;
    i2dHi29 = 0x43300000;
    i2dHi30 = 0x43300000;
    i2dHi31 = 0x43300000;
    i2dHi32 = 0x43300000;
    i2dHi33 = 0x43300000;
    i2dHi25 = 0x43300000;
    i2dHi26 = 0x43300000;
    i2dHi27 = 0x43300000;
    i2dLo31 = (int)clipBottom - (int)clipTop ^ 0x80000000;
    i2dLo32 = (int)clipRight + (int)clipLeft ^ 0x80000000;
    i2dLo33 = (int)clipBottom + (int)clipTop ^ 0x80000000;
    i2dLo25 = (int)srcRight - (int)srcLeft ^ 0x80000000;
    i2dLo27 = (int)*(short *)(ctx + 0x110) - (int)*(short *)(ctx + 0x10c) ^ 0x80000000;
    i2dLo26 = (int)srcRight - (int)srcLeft ^ 0x80000000;
    clipLeftOrWidthF = (float)((double)CONCAT44(0x43300000,surfaceWidth) - 4503599627370496.0);
    surfaceHeightF = (float)((double)CONCAT44(0x43300000,surfaceHeight) - 4503599627370496.0);
    scaleX = clipLeftOrWidthF / (float)((double)CONCAT44(0x43300000,i2dLo29) - 4503601774854144.0);
    dstOffsetTop = (float)((double)CONCAT44(0x43300000,i2dLo27) - 4503601774854144.0);
    scaleY = surfaceHeightF / (float)((double)CONCAT44(0x43300000,i2dLo31) - 4503601774854144.0);
    centerX = (float)((double)CONCAT44(0x43300000,i2dLo32) - 4503601774854144.0) * 0.5;
    centerY = (float)((double)CONCAT44(0x43300000,i2dLo33) - 4503601774854144.0) * 0.5;
    dstOffsetLeft = ((clippedLeft - srcWidthOrSrcLeftScaled) / (srcRightScaled - srcWidthOrSrcLeftScaled)) *
                (float)((double)CONCAT44(0x43300000,i2dLo25) - 4503601774854144.0);
    dstOffsetRight = (1.0 - (srcRightScaled - heightFOrClipRightF) / (srcRightScaled - srcWidthOrSrcLeftScaled)) *
                (float)((double)CONCAT44(0x43300000,i2dLo26) - 4503601774854144.0);
    dstOffsetBottom = (1.0 - (srcBottomScaled - clipBottomF) / (srcBottomScaled - srcHeightOrSrcTopScaled)) * dstOffsetTop;
    dstOffsetTop = ((clippedTop - srcHeightOrSrcTopScaled) / (srcBottomScaled - srcHeightOrSrcTopScaled)) * dstOffsetTop;
    i2dHi35 = 0x43300000;
    i2dHi34 = 0x43300000;
    srcCoordRight = scaleX * (heightFOrClipRightF - centerX) + centerX;
    centerX = scaleX * (clippedLeft - centerX) + centerX;
    srcCoordLeft = centerX;
    if (centerX < 0.0) {
      srcCoordLeft = 0.0;
    }
    i2dLo34 = (uint)(int)(scaleY * (clippedTop - centerY) + centerY);
    d2iScratch1 = (longlong)(int)i2dLo34;
    if (-centerX < 0.0) {
      srcCoordLeft = centerX;
    }
    i2dLo35 = (uint)(int)(scaleY * (clipBottomF - centerY) + centerY);
    d2iScratch2 = (longlong)(int)i2dLo35;
    srcHeightOrSrcTopScaled = clipLeftOrWidthF;
    if (srcCoordRight - clipLeftOrWidthF < 0.0) {
      srcHeightOrSrcTopScaled = srcCoordRight;
    }
    if (-(srcCoordRight - clipLeftOrWidthF) < 0.0) {
      srcCoordRight = srcHeightOrSrcTopScaled;
    }
    i2dLo34 = i2dLo34 ^ 0x80000000;
    i2dLo35 = i2dLo35 ^ 0x80000000;
    srcHeightOrSrcTopScaled = (float)((double)CONCAT44(0x43300000,i2dLo34) - 4503601774854144.0);
    srcCoordBottom = (float)((double)CONCAT44(0x43300000,i2dLo35) - 4503601774854144.0);
    srcCoordTop = srcHeightOrSrcTopScaled;
    if (srcHeightOrSrcTopScaled < 0.0) {
      srcCoordTop = 0.0;
    }
    if (-srcHeightOrSrcTopScaled < 0.0) {
      srcCoordTop = srcHeightOrSrcTopScaled;
    }
    srcHeightOrSrcTopScaled = surfaceHeightF;
    if (srcCoordBottom - surfaceHeightF < 0.0) {
      srcHeightOrSrcTopScaled = srcCoordBottom;
    }
    i2dLo28 = surfaceWidth;
    i2dLo30 = surfaceHeight;
    if (-(srcCoordBottom - surfaceHeightF) < 0.0) {
      srcCoordBottom = srcHeightOrSrcTopScaled;
    }
  }
  cmdWrite = *(undefined4 **)(ctx + 0x34);
  if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x70) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                        ctx + 0x44,1);
    mapBase = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBase + 0x20;
    *(int *)(ctx + 0x30) = mapBase + 0x1c;
    *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
    *(undefined4 *)(mapBase + 0x1c) = 0;
    cmdWrite = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x70;
  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = cmdWrite;
  *cmdWrite = 0xb000000;
  cmdWrite[1] = 2;
  cmdWrite[2] = 1;
  cmdWrite = cmdWrite + 3;
  fillCount = 10;
  do {
    *cmdWrite = 0x80000000;
    cmdWrite = cmdWrite + 1;
    fillCount = fillCount + -1;
  } while (fillCount != 0);
  cmdAfterClear = ((int (*)())ava_emit_state_preamble)(cmdWrite);
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_stage_setup)(cmdAfterClear,1);
  *cmdWrite = 0x1100;
  cmdWrite[1] = 0xa92;
  cmdWrite[2] = 0x1110;
  cmdWrite[3] = 0;
  cmdWrite[4] = 0x1120;
  cmdWrite[5] = ((int)*(short *)(ctx + 0x112) - (int)*(short *)(ctx + 0x10e)) - 1U |
               (((int)*(short *)(ctx + 0x110) - (int)*(short *)(ctx + 0x10c)) + -1) * 0x800
               | 0x80000000;
  cmdWrite[6] = 0x1130;
  cmdWrite[7] = 0xa60c;
  cmdWrite[8] = 0x1140;
  cmdWrite[9] = *(int *)(ctx + 0x68) + -1;
  cmdWrite[10] = ((unsigned char *)0x00001041U);
  cmdWrite[0xb] = 1;
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_constants)(cmdWrite + 0xc,&scalePassShaderProgram_0000ec84,2,0,0,1);
  *cmdWrite = 0x11a9;
  cmdWrite[1] = 0x1b00;
  cmdWrite[2] = 0x11aa;
  cmdWrite[3] = 0xf;
  cmdWrite[4] = 0x11ab;
  cmdWrite[5] = 0xf;
  cmdWrite[6] = 0x11ac;
  cmdWrite[7] = 0xf;
  cmdWrite[8] = 0x1381;
  cmdWrite[9] = 0x27260005;
  fpPassThrough = (double)((int (*)())ava_emit_textured_quad)(cmdWrite + 10,&dstOffsetLeft,&srcCoordLeft,
                                  (int)*(short *)(ctx + 0x112) -
                                  (int)*(short *)(ctx + 0x10e),
                                  (int)*(short *)(ctx + 0x110) -
                                  (int)*(short *)(ctx + 0x10c));
callRestf24:
  ((int (*)())_restf24)(fpPassThrough);
  return;
}

/* ava_render_source_rect_pass @ 0xb7f0 (964 bytes) */
int ava_render_source_rect_pass(ctx, headerWord, enableFlag)
  int ctx;
  undefined4 headerWord;
  int enableFlag;
{
  undefined *mapMemoryType;
  uint *lastHeader;
  undefined4 cmdAfterClear;
  uint surfaceWidth;
  undefined4 *cmdWrite;
  uint surfaceHeight;
  float srcLeft;
  float srcRight;
  float srcTop;
  float srcBottom;
  undefined4 dstLeft;
  float dstRight;
  undefined4 dstTop;
  float dstBottom;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 i2dHi3;
  uint i2dLo3;
  undefined4 i2dHi4;
  uint i2dLo4;
  undefined4 i2dHi5;
  undefined4 i2dLo5;
  undefined4 i2dHi6;
  undefined4 i2dLo6;
  int mapBase;
  int fillCount;
  
  cmdWrite = *(undefined4 **)(ctx + 0x34);
  if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0xb0) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                        ctx + 0x44,1);
    mapBase = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBase + 0x20;
    *(int *)(ctx + 0x30) = mapBase + 0x1c;
    *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
    *(undefined4 *)(mapBase + 0x1c) = 0;
    cmdWrite = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = cmdWrite + 0xb0;
  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = cmdWrite;
  *cmdWrite = 0xa000000;
  cmdWrite[1] = headerWord;
  cmdWrite[2] = (uint)(enableFlag != 0);
  cmdWrite[3] = *(undefined4 *)(ctx + 0x11c);
  cmdWrite = cmdWrite + 4;
  fillCount = 0x10;
  do {
    *cmdWrite = 0x80000000;
    cmdWrite = cmdWrite + 1;
    fillCount = fillCount + -1;
  } while (fillCount != 0);
  cmdAfterClear = ((int (*)())ava_emit_state_preamble)(cmdWrite);
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_stage_setup)(cmdAfterClear,1);
  *cmdWrite = 0x1100;
  cmdWrite[1] = 0x1492;
  cmdWrite[2] = 0x1110;
  cmdWrite[3] = 0;
  cmdWrite[4] = 0x1120;
  surfaceHeight = *(uint *)(ctx + 0x57c);
  surfaceWidth = *(uint *)(ctx + 0x578);
  cmdWrite[5] = (surfaceHeight - 1) * 0x800 | surfaceWidth - 1 | 0x80000000;
  cmdWrite[6] = 0x1130;
  cmdWrite[7] = 0x10120800;
  cmdWrite[8] = 0x1101;
  cmdWrite[9] = 0x10001492;
  cmdWrite[10] = 0x1111;
  cmdWrite[0xb] = 0;
  cmdWrite[0xc] = 0x1121;
  cmdWrite[0xd] = ((surfaceHeight >> 1) - 1) * 0x800 | (surfaceWidth >> 1) - 1 | 0x80000000;
  cmdWrite[0xe] = 0x1131;
  cmdWrite[0xf] = 0x18044803;
  cmdWrite[0x10] = ((unsigned char *)0x00001041U);
  cmdWrite[0x11] = 3;
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_constants)(cmdWrite + 0x12,&convertAndSourceRectShaderProgram_0000eb7c,7,&convertAndSourceRectShaderConstants_0000eb2c,5,3);
  *cmdWrite = 0x11a9;
  cmdWrite[1] = 0x1b00;
  cmdWrite[2] = 0x11aa;
  cmdWrite[3] = 0xf;
  cmdWrite[4] = 0x11ab;
  cmdWrite[5] = 0xf;
  cmdWrite[6] = 0x11ac;
  cmdWrite[7] = 0xf;
  i2dLo6 = *(undefined4 *)(ctx + 0x57c);
  i2dLo5 = *(undefined4 *)(ctx + 0x578);
  i2dHi1 = 0x43300000;
  i2dHi2 = 0x43300000;
  i2dHi3 = 0x43300000;
  i2dHi4 = 0x43300000;
  i2dHi6 = 0x43300000;
  i2dHi5 = 0x43300000;
  i2dLo1 = (int)*(short *)(ctx + 0x126) ^ 0x80000000;
  i2dLo2 = (int)*(short *)(ctx + 0x12a) ^ 0x80000000;
  i2dLo3 = (int)*(short *)(ctx + 0x124) ^ 0x80000000;
  i2dLo4 = (int)*(short *)(ctx + 0x128) ^ 0x80000000;
  dstTop = 0;
  dstLeft = 0;
  dstBottom = (float)((double)CONCAT44(0x43300000,i2dLo6) - 4503599627370496.0);
  srcLeft = (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0);
  srcRight = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0);
  srcBottom = (float)((double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0);
  srcTop = (float)((double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0);
  dstRight = (float)((double)CONCAT44(0x43300000,i2dLo5) - 4503599627370496.0);
  return ((int (*)())ava_emit_textured_quad)(cmdWrite + 8,&srcLeft,&dstLeft,i2dLo5,i2dLo6);
}

/* ava_render_pass_47 @ 0xbbc0 (864 bytes) */
int ava_render_pass_47(ctx, headerWord, secondWord, widthPixels, height, bytesPerPixel)
  int ctx;
  undefined4 headerWord;
  undefined4 secondWord;
  int widthPixels;
  uint height;
  int bytesPerPixel;
{
  undefined *mapMemoryType;
  uint *lastHeader;
  undefined4 cmdAfterClear;
  undefined4 *cmdWrite;
  uint widthWords;
  undefined4 dstLeft;
  float dstRight;
  undefined4 dstTop;
  float dstBottom;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  int wholeWords;
  int closingMapBase;
  int mapBase;
  int fillCount;
  
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  if (bytesPerPixel < 5) {
    wholeWords = widthPixels / (4 / bytesPerPixel);
    widthWords = wholeWords + (uint)(widthPixels != wholeWords * (4 / bytesPerPixel));
  }
  else {
    widthWords = (bytesPerPixel >> 2) * widthPixels;
  }
  cmdWrite = *(undefined4 **)(ctx + 0x34);
  if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x70) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                        ctx + 0x44,1);
    mapBase = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBase + 0x20;
    *(int *)(ctx + 0x30) = mapBase + 0x1c;
    *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
    *(undefined4 *)(mapBase + 0x1c) = 0;
    cmdWrite = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x70;
  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = cmdWrite;
  *cmdWrite = 0x47000000;
  cmdWrite[1] = headerWord;
  cmdWrite[2] = secondWord;
  cmdWrite = cmdWrite + 3;
  fillCount = 0xe;
  do {
    *cmdWrite = 0x80000000;
    cmdWrite = cmdWrite + 1;
    fillCount = fillCount + -1;
  } while (fillCount != 0);
  cmdAfterClear = ((int (*)())ava_emit_state_preamble)(cmdWrite);
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_stage_setup)(cmdAfterClear,1);
  *cmdWrite = 0x1100;
  cmdWrite[1] = 0xa92;
  cmdWrite[2] = 0x1110;
  cmdWrite[3] = 0;
  cmdWrite[4] = 0x1120;
  cmdWrite[5] = (height - 1) * 0x800 | widthWords - 1 | 0x80000000;
  cmdWrite[6] = 0x1130;
  cmdWrite[7] = 0xa60c;
  cmdWrite[8] = ((unsigned char *)0x00001041U);
  cmdWrite[9] = 1;
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_constants)(cmdWrite + 10,&renderPass47ShaderProgram_0000ecb4,2,0,0,1);
  *cmdWrite = 0x11a9;
  cmdWrite[1] = 0x1b00;
  cmdWrite[2] = 0x11aa;
  cmdWrite[3] = 0xf;
  cmdWrite[4] = 0x11ab;
  cmdWrite[5] = 0xf;
  cmdWrite[6] = 0x11ac;
  cmdWrite[7] = 0xf;
  i2dLo1 = widthWords ^ 0x80000000;
  i2dLo2 = height ^ 0x80000000;
  i2dHi2 = 0x43300000;
  i2dHi1 = 0x43300000;
  dstTop = 0;
  dstLeft = 0;
  dstBottom = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0);
  dstRight = (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0);
  ((int (*)())ava_emit_textured_quad)(cmdWrite + 8,0,&dstLeft,widthWords,height);
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                      ctx + 0x44,1);
  closingMapBase = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = closingMapBase + 0x20;
  *(int *)(ctx + 0x30) = closingMapBase + 0x1c;
  *(int *)(ctx + 0x38) = closingMapBase + 0x20 + *(int *)(closingMapBase + 0x10) * 4;
  *(undefined4 *)(closingMapBase + 0x1c) = 0;
  return;
}

/* ava_dcache_flush_range @ 0xbf20 (72 bytes) */
int ava_dcache_flush_range(ctx, address, length, unused1, unused2, unused3, unused4, unused5)
  int ctx;
  uint address;
  int length;
  undefined4 unused1;
  undefined4 unused2;
  undefined4 unused3;
  undefined4 unused4;
  undefined4 unused5;
{
  int offset;
  int span;
  int lineSize;
  
  lineSize = *(int *)(ctx + 0x144);
  offset = 0;
  span = (address & lineSize - 1U) + (length - lineSize);
  if (0 < span) {
    do {
      dataCacheBlockStore((-lineSize & address) + offset);
      offset = lineSize + offset;
    } while (offset < span);
  }
  dataCacheBlockFlush((-lineSize & address) + offset);
  return;
}

/* ava_dcache_flush_range_sync @ 0xbf70 (80 bytes) */
int ava_dcache_flush_range_sync(ctx, address, length, unused1, unused2, unused3, unused4, unused5)
  int ctx;
  uint address;
  int length;
  undefined4 unused1;
  undefined4 unused2;
  undefined4 unused3;
  undefined4 unused4;
  undefined4 unused5;
{
  int offset;
  int span;
  int lineSize;
  
  lineSize = *(int *)(ctx + 0x144);
  offset = 0;
  span = ((address & lineSize - 1U) + length) - lineSize;
  if (0 < span) {
    do {
      dataCacheBlockFlush((-lineSize & address) + offset);
      offset = offset + lineSize;
    } while (offset < span);
  }
  dataCacheBlockFlush((-lineSize & address) + offset);
  sync(0);
  instructionSynchronize();
  return;
}

/* ava_emit_deint_enable_packet @ 0xbfc0 (400 bytes) */
int ava_emit_deint_enable_packet(ctx)
  int ctx;
{
  undefined *mapMemoryType;
  uint *lastHeader;
  undefined4 *cmdWrite;
  int mapBase;
  
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  cmdWrite = *(undefined4 **)(ctx + 0x34);
  if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0x10) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                        ctx + 0x44,1);
    mapBase = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBase + 0x20;
    *(int *)(ctx + 0x30) = mapBase + 0x1c;
    *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
    *(undefined4 *)(mapBase + 0x1c) = 0;
    cmdWrite = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = cmdWrite + 0x10;
  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = cmdWrite;
  *cmdWrite = 0x15000000;
  cmdWrite[1] = 0x20202020;
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                      ctx + 0x44,1);
  mapBase = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = mapBase + 0x20;
  *(int *)(ctx + 0x30) = mapBase + 0x1c;
  *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
  *(undefined4 *)(mapBase + 0x1c) = 0;
  return;
}

/* ava_emit_deint_field_quad @ 0xc160 (848 bytes) */
int ava_emit_deint_field_quad(ctx, cmdPtr, srcDesc, fieldMode, flipFlag)
  int ctx;
  undefined4 *cmdPtr;
  int srcDesc;
  int fieldMode;
  int flipFlag;
{
  float vertexConstA;
  float vertexConstB;
  uint pitchBytes;
  uint quadWidth;
  undefined4 *padCursor;
  uint sizeWord;
  uint fieldHeight;
  float texOffsetA;
  float texOffsetB;
  int fillCount;
  int pitchWordsMinus1;
  
  if (fieldMode == 1) {
    pitchBytes = *(uint *)(ctx + 0x588);
    quadWidth = *(uint *)(ctx + 0x578);
    fieldHeight = *(uint *)(ctx + 0x57c) >> 1;
  }
  else {
    pitchBytes = *(uint *)(ctx + 0x588);
    quadWidth = *(uint *)(ctx + 0x578);
    fieldHeight = *(uint *)(ctx + 0x57c) >> 2;
  }
  quadWidth = quadWidth >> 2;
  fillCount = 0x18;
  padCursor = cmdPtr;
  do {
    *padCursor = 0x80000000;
    padCursor = padCursor + 1;
    fillCount = fillCount + -1;
  } while (fillCount != 0);
  cmdPtr[0x18] = 0x1120;
  sizeWord = quadWidth - 1 | (fieldHeight - 1) * 0x800 | 0x80000000;
  cmdPtr[0x19] = sizeWord;
  cmdPtr[0x1a] = 0x1140;
  pitchWordsMinus1 = (pitchBytes >> 1 & 0x7ffffffe) - 1;
  cmdPtr[0x1b] = pitchWordsMinus1;
  cmdPtr[0x1c] = 0x1121;
  cmdPtr[0x1d] = sizeWord;
  cmdPtr[0x1e] = 0x1141;
  cmdPtr[0x1f] = pitchWordsMinus1;
  cmdPtr[0x20] = 0x1122;
  cmdPtr[0x21] = sizeWord;
  cmdPtr[0x22] = 0x1142;
  cmdPtr[0x23] = pitchWordsMinus1;
  cmdPtr[0x24] = 0x1123;
  cmdPtr[0x25] = sizeWord;
  cmdPtr[0x26] = 0x1143;
  cmdPtr[0x27] = pitchWordsMinus1;
  cmdPtr[0x28] = 0x1124;
  cmdPtr[0x29] = sizeWord;
  cmdPtr[0x2a] = 0x1144;
  cmdPtr[0x2b] = pitchWordsMinus1;
  cmdPtr[0x2c] = 0x82d;
  cmdPtr[0x2d] = 4;
  cmdPtr[0x2e] = 0xc0103500;
  cmdPtr[0x2f] = 0x4003d;
  vertexConstB = FLOAT_0000d43c;
  vertexConstA = FLOAT_0000d430;
  if (flipFlag == 1) {
    if (*(int *)(srcDesc + 8) == 0) {
loopSetTexOffsetA:
      texOffsetA = FLOAT_0000d43c / (float)((double)CONCAT44(0x43300000,fieldHeight) - DOUBLE_0000d418);
      goto setTexOffsetB;
    }
  }
  else if (*(int *)(srcDesc + 8) != 0) goto loopSetTexOffsetA;
  texOffsetA = FLOAT_0000d438 / (float)((double)CONCAT44(0x43300000,fieldHeight) - DOUBLE_0000d418);
setTexOffsetB:
  texOffsetB = texOffsetA + FLOAT_0000d43c;
  texOffsetA = texOffsetA + FLOAT_0000d430;
  cmdPtr[0x30] = 0;
  cmdPtr[0x31] = 0;
  cmdPtr[0x32] = vertexConstA;
  cmdPtr[0x33] = texOffsetA;
  cmdPtr[0x34] = fieldHeight << 0x10;
  cmdPtr[0x35] = 0x10000;
  cmdPtr[0x36] = vertexConstA;
  cmdPtr[0x37] = texOffsetB;
  cmdPtr[0x38] = quadWidth | fieldHeight << 0x10;
  cmdPtr[0x39] = 0x00010001;
  cmdPtr[0x3a] = vertexConstB;
  cmdPtr[0x3b] = texOffsetB;
  cmdPtr[0x3c] = quadWidth;
  cmdPtr[0x3d] = 1;
  cmdPtr[0x3e] = vertexConstB;
  cmdPtr[0x3f] = texOffsetA;
  cmdPtr[0x40] = 0x1393;
  cmdPtr[0x41] = 10;
  return cmdPtr + 0x42;
}

/* ava_render_deinterlace_pass @ 0xc4b0 (1508 bytes) */
int ava_render_deinterlace_pass(ctx, frameInfo, unused1, frameArg)
  int ctx;
  char *frameInfo;
  undefined4 unused1;
  undefined4 frameArg;
{
  bool notLast;
  undefined *taskPortPtr;
  uint *lastHeader;
  undefined4 *programCursor;
  undefined4 *programEntry;
  int mapBaseOrProgramEnd;
  uint planeIndex;
  undefined4 *packet;
  
  taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
  packet = *(undefined4 **)(ctx + 0x34);
  if (*(undefined4 **)(ctx + 0x38) <= packet + 0x188) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)packet - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                        ctx + 0x44,1);
    mapBaseOrProgramEnd = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBaseOrProgramEnd + 0x20;
    *(int *)(ctx + 0x30) = mapBaseOrProgramEnd + 0x1c;
    *(int *)(ctx + 0x38) = mapBaseOrProgramEnd + 0x20 + *(int *)(mapBaseOrProgramEnd + 0x10) * 4;
    *(undefined4 *)(mapBaseOrProgramEnd + 0x1c) = 0;
    packet = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = packet + 0x188;
  *lastHeader = (int)packet - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = packet;
  *packet = 0x3d000000;
  packet[1] = (int)*frameInfo;
  packet[2] = (int)frameInfo[1];
  packet[3] = *(undefined4 *)(frameInfo + 8);
  packet[4] = frameArg;
  packet[5] = -0x80000000;
  packet[6] = -0x80000000;
  packet[7] = 0x80000000;
  packet[8] = 0x80000000;
  packet[9] = 0x80000000;
  programCursor = (undefined4 *)((int (*)())ava_emit_state_preamble)(packet + 10);
  *programCursor = 0x850;
  programCursor[1] = 0x102;
  programCursor[2] = 0x854;
  programCursor[3] = 0x6060006;
  programCursor[4] = 0x855;
  programCursor[5] = 0x2701;
  programCursor[6] = 0x878;
  programCursor[7] = 0xf688f688;
  programCursor[8] = 0x879;
  programCursor[9] = 0xf688f688;
  programCursor[10] = 0x824;
  programCursor[0xb] = 1;
  programCursor[0xc] = 0x825;
  programCursor[0xd] = 0x12;
  programCursor[0xe] = 0x000010c0;
  programCursor[0xf] = 0x40004;
  programCursor[0x10] = 0x10c1;
  programCursor[0x11] = 1;
  planeIndex = 0;
  mapBaseOrProgramEnd = 1;
  programCursor = programCursor + 0x12;
  do {
    programEntry = programCursor;
    *programEntry = ((unsigned char *)0x0000101d) + planeIndex;
    programEntry[1] = planeIndex << 1 | mapBaseOrProgramEnd << 6 | 0x28ffe000;
    programEntry[2] = planeIndex + 0x10c8;
    programEntry[3] = planeIndex | planeIndex << 5 | 0x10;
    notLast = planeIndex != 1;
    mapBaseOrProgramEnd = mapBaseOrProgramEnd + 2;
    planeIndex = planeIndex + 1;
    programCursor = programEntry + 4;
  } while (notLast);
  programEntry[4] = 0x1100;
  programEntry[5] = 0xa92;
  programEntry[6] = 0x1110;
  programEntry[7] = 0;
  programEntry[8] = 0x1130;
  programEntry[9] = 0x4000a60c;
  programEntry[10] = 0x1101;
  programEntry[0xb] = 0x10000a92;
  programEntry[0xc] = 0x1111;
  programEntry[0xd] = 0;
  programEntry[0xe] = 0x1131;
  programEntry[0xf] = 0x4800a60c;
  programEntry[0x10] = 0x1102;
  programEntry[0x11] = 0x20000a92;
  programEntry[0x12] = 0x1112;
  programEntry[0x13] = 0;
  programEntry[0x14] = 0x1132;
  programEntry[0x15] = 0x2800a60c;
  programEntry[0x16] = 0x1103;
  programEntry[0x17] = 0x30000a92;
  programEntry[0x18] = 0x1113;
  programEntry[0x19] = 0;
  programEntry[0x1a] = 0x1133;
  programEntry[0x1b] = 0x3000a60c;
  programEntry[0x1c] = 0x1104;
  programEntry[0x1d] = 0x40000a92;
  programEntry[0x1e] = 0x1114;
  programEntry[0x1f] = 0;
  programEntry[0x20] = 0x1134;
  programEntry[0x21] = 0x3800a60c;
  programEntry[0x22] = ((unsigned char *)0x00001041U);
  programEntry[0x23] = 0x1f;
  deinterlaceConstReg0X_0000f054 = 0.5647059;
  deinterlaceConstReg0W_0000f060 = 0.5647059;
  deinterlaceConstReg1W_0000f070 = 0.047058824;
  deinterlaceConstReg3W_0000f090 = 0.1254902;
  deinterlaceConstReg0Y_0000f058 = 0.5647059;
  deinterlaceConstReg0Z_0000f05c = 0.5647059;
  deinterlaceConstReg1X_0000f064 = 0.047058824;
  deinterlaceConstReg1Y_0000f068 = 0.047058824;
  deinterlaceConstReg1Z_0000f06c = 0.047058824;
  deinterlaceConstReg2X_0000f074 = 0.1254902;
  deinterlaceConstReg2Y_0000f078 = 0.1254902;
  deinterlaceConstReg2Z_0000f07c = 0.1254902;
  deinterlaceConstReg2W_0000f080 = 0.1254902;
  deinterlaceConstReg3X_0000f084 = 0.1254902;
  deinterlaceConstReg3Y_0000f088 = 0.1254902;
  deinterlaceConstReg3Z_0000f08c = 0.1254902;
  programCursor = (undefined4 *)((int (*)())ava_emit_shader_constants)(programEntry + 0x24,&deinterlaceShaderProgram_0000ece4,0x16,&deinterlaceConstReg0X_0000f054,6,9);
  *programCursor = 0x11a9;
  programCursor[1] = 0x1b00;
  programCursor[2] = 0x11aa;
  programCursor[3] = 0x1b00;
  programCursor[4] = 0x11ab;
  programCursor[5] = 0x1b00;
  programCursor[6] = 0x11ac;
  programCursor[7] = 0xf;
  packet[5] = (int)(programCursor + 8) - (int)packet >> 2;
  mapBaseOrProgramEnd = ((int (*)())ava_emit_deint_field_quad)(ctx,programCursor + 8,frameInfo,1,frameArg);
  packet[6] = mapBaseOrProgramEnd - (int)packet >> 2;
  ((int (*)())ava_emit_deint_field_quad)(ctx,mapBaseOrProgramEnd,frameInfo,2,frameArg);
  taskPortPtr = ptrTo_machTaskSelf_0000f1a0;
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)taskPortPtr,ctx + 0x40,
                      ctx + 0x44,1);
  mapBaseOrProgramEnd = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = mapBaseOrProgramEnd + 0x20;
  *(int *)(ctx + 0x30) = mapBaseOrProgramEnd + 0x1c;
  *(int *)(ctx + 0x38) = mapBaseOrProgramEnd + 0x20 + *(int *)(mapBaseOrProgramEnd + 0x10) * 4;
  *(undefined4 *)(mapBaseOrProgramEnd + 0x1c) = 0;
  return;
}

/* ava_deinterlace_frame @ 0xcaa0 (92 bytes) */
int ava_deinterlace_frame(ctx, arg1, arg2, arg3)
  int ctx;
  undefined4 arg1;
  undefined4 arg2;
  undefined4 arg3;
{
  if (*(int *)(ctx + 0x120) == 4) {
    ((int (*)())ava_render_deinterlace_pass)(ctx,arg1,arg2,arg3);
  }
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + ctx + 0xacc) =
       *(undefined4 *)(*(int *)(ctx + 0x40) + 0x18);
  return;
}

/* ava_render_subpicture_pass @ 0xcb00 (1136 bytes) */
int ava_render_subpicture_pass(ctx, srcPosPacked, srcSizePacked, headerWord, secondWord)
  int ctx;
  undefined4 srcPosPacked;
  undefined4 srcSizePacked;
  undefined4 headerWord;
  undefined4 secondWord;
{
  unsigned int ghidra_home[8] = { ctx, srcPosPacked, srcSizePacked, headerWord, secondWord, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint halfWidth;
  undefined *mapMemoryType;
  uint srcWidth;
  uint *lastHeader;
  undefined4 cmdAfterClear;
  undefined4 *cmdWrite;
  float srcLeft;
  float srcRight;
  float srcTop;
  float srcBottom;
  float dstLeft;
  float dstRight;
  float dstTop;
  float dstBottom;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 i2dHi3;
  uint i2dLo3;
  undefined4 i2dHi4;
  uint i2dLo4;
  undefined4 i2dHi5;
  uint i2dLo5;
  int mapBase;
  int fillCount;
  int srcHeight;
  int closingMapBase;
  
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  i2dHi4 = 0x43300000;
  i2dHi2 = 0x43300000;
  i2dHi1 = 0x43300000;
  i2dHi3 = 0x43300000;
  (*(short *)((unsigned char *)ghidra_home + 10)) = (short)srcSizePacked;
  (*(short *)((unsigned char *)ghidra_home + 6)) = (short)srcPosPacked;
  (*(short *)((unsigned char *)ghidra_home + 8)) = (short)((uint)srcSizePacked >> 0x10);
  (*(short *)((unsigned char *)ghidra_home + 4)) = (short)((uint)srcPosPacked >> 0x10);
  cmdWrite = *(undefined4 **)(ctx + 0x34);
  i2dLo2 = (int)(*(short *)((unsigned char *)ghidra_home + 6)) ^ 0x80000000;
  i2dLo4 = (int)(*(short *)((unsigned char *)ghidra_home + 10)) ^ 0x80000000;
  i2dLo1 = (int)(*(short *)((unsigned char *)ghidra_home + 4)) ^ 0x80000000;
  i2dLo3 = (int)(*(short *)((unsigned char *)ghidra_home + 8)) ^ 0x80000000;
  srcWidth = *(uint *)(ctx + 0x60);
  srcHeight = *(int *)(ctx + 100);
  halfWidth = srcWidth >> 1;
  srcTop = (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0);
  srcBottom = (float)((double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0);
  srcLeft = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0) * 0.5;
  srcRight = (float)((double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0) * 0.5;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = srcPosPacked;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = srcSizePacked;
  dstLeft = srcLeft;
  dstRight = srcRight;
  dstTop = srcTop;
  dstBottom = srcBottom;
  if (*(undefined4 **)(ctx + 0x38) <= cmdWrite + 0xa8) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                        ctx + 0x44,1);
    mapBase = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = mapBase + 0x20;
    *(int *)(ctx + 0x30) = mapBase + 0x1c;
    *(int *)(ctx + 0x38) = mapBase + 0x20 + *(int *)(mapBase + 0x10) * 4;
    *(undefined4 *)(mapBase + 0x1c) = 0;
    cmdWrite = *(undefined4 **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(undefined4 **)(ctx + 0x34) = cmdWrite + 0xa8;
  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = cmdWrite;
  *cmdWrite = 0x18000000;
  cmdWrite[1] = headerWord;
  cmdWrite[2] = 3;
  cmdWrite[3] = secondWord;
  cmdWrite = cmdWrite + 4;
  fillCount = 8;
  do {
    *cmdWrite = 0x80000000;
    cmdWrite = cmdWrite + 1;
    fillCount = fillCount + -1;
  } while (fillCount != 0);
  cmdAfterClear = ((int (*)())ava_emit_state_preamble)(cmdWrite);
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_stage_setup)(cmdAfterClear,1);
  *cmdWrite = 0x1100;
  cmdWrite[1] = 0xa92;
  cmdWrite[2] = 0x1110;
  cmdWrite[3] = 0;
  cmdWrite[4] = 0x1120;
  cmdWrite[5] = (srcHeight + -1) * 0x800 | (srcWidth >> 2) - 1 | 0x80000000;
  cmdWrite[6] = 0x1130;
  cmdWrite[7] = 0x10108802;
  cmdWrite[8] = 0x1140;
  cmdWrite[9] = 0xbf;
  cmdWrite[10] = 0x1101;
  cmdWrite[0xb] = 0x10000a92;
  cmdWrite[0xc] = 0x1111;
  cmdWrite[0xd] = 0;
  cmdWrite[0xe] = 0x1121;
  cmdWrite[0xf] = 0x8000000f;
  cmdWrite[0x10] = 0x1131;
  cmdWrite[0x11] = 0x1800a60e;
  cmdWrite[0x12] = 0x1141;
  cmdWrite[0x13] = 0xf;
  cmdWrite[0x14] = ((unsigned char *)0x00001041U);
  cmdWrite[0x15] = 3;
  i2dHi5 = 0x43300000;
  subpictureConstReg0X_0000f0b4 = (float)((double)CONCAT44(0x43300000,halfWidth) - 4503599627370496.0);
  subpictureConstReg0Y_0000f0b8 = subpictureConstReg0X_0000f0b4;
  subpictureConstReg0Z_0000f0bc = subpictureConstReg0X_0000f0b4;
  subpictureConstReg0W_0000f0c0 = subpictureConstReg0X_0000f0b4;
  i2dLo5 = halfWidth;
  cmdWrite = (undefined4 *)((int (*)())ava_emit_shader_constants)(cmdWrite + 0x16,&subpictureShaderProgram_0000eef4,9,&subpictureConstReg0X_0000f0b4,1,4);
  *cmdWrite = 0x11a9;
  cmdWrite[1] = 0x1b05;
  cmdWrite[2] = 0x11aa;
  cmdWrite[3] = 0xf;
  cmdWrite[4] = 0x11ab;
  cmdWrite[5] = 0xf;
  cmdWrite[6] = 0x11ac;
  cmdWrite[7] = 0xf;
  ((int (*)())ava_emit_textured_quad)(cmdWrite + 8,&srcLeft,&dstLeft,halfWidth,srcHeight);
  mapMemoryType = ptrTo_machTaskSelf_0000f1a0;
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)mapMemoryType,ctx + 0x40,
                      ctx + 0x44,1);
  closingMapBase = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = closingMapBase + 0x20;
  *(int *)(ctx + 0x30) = closingMapBase + 0x1c;
  *(int *)(ctx + 0x38) = closingMapBase + 0x20 + *(int *)(closingMapBase + 0x10) * 4;
  *(undefined4 *)(closingMapBase + 0x1c) = 0;
  return;
}

/* _savef24 @ 0xcf98 (12 bytes) */
int _savef24()
{
  return;
}

/* _savef27 @ 0xcfa4 (4 bytes) */
int _savef27()
{
  return;
}

/* _savef28 @ 0xcfa8 (24 bytes) */
int _savef28()
{
  return;
}

/* _restf24 @ 0xcfe8 (44 bytes) */
int _restf24()
{
  return;
}

