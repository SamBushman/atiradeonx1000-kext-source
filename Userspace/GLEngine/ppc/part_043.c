#include "decls.h"

/* _gleFeedbackLineStrip @ 0xcc278 (284 bytes) */
void _gleFeedbackLineStrip(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  double dVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  dVar1 = DOUBLE_00108d70;
  if (1 < param_3) {
    if (param_4 == 0) {
      uVar3 = 0x702;
      uVar2 = 0x702;
    }
    else if (param_4 == 1) {
      uVar2 = 0x707;
      uVar3 = 0x702;
    }
    else {
      uVar3 = 0x707;
      uVar2 = 0x707;
    }
    uVar5 = param_2 + 0x100;
    ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar2) - DOUBLE_00108d70))
    ;
    _gleFeedbackHitRecord(param_1,param_2);
    _gleFeedbackHitRecord(param_1,uVar5);
    uVar4 = (param_2 + param_3 * 0x100) - 0x100;
    if (uVar5 < uVar4) {
      do {
        uVar6 = uVar5 + 0x100;
        ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) - dVar1));
        _gleFeedbackHitRecord(param_1,uVar5);
        _gleFeedbackHitRecord(param_1,uVar6);
        uVar5 = uVar6;
      } while (uVar6 < uVar4);
    }
  }
  return;
}

/* _gleFeedbackLineLoop @ 0xcc394 (344 bytes) */
void _gleFeedbackLineLoop(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  double dVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  dVar1 = DOUBLE_00108d70;
  if (0 < param_3) {
    if (param_4 == 0) {
      uVar3 = 0x702;
      uVar2 = 0x702;
    }
    else if (param_4 == 1) {
      uVar2 = 0x707;
      uVar3 = 0x702;
    }
    else {
      uVar3 = 0x707;
      uVar2 = 0x707;
    }
    uVar5 = param_2 + 0x100;
    ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar2) - DOUBLE_00108d70))
    ;
    _gleFeedbackHitRecord(param_1,param_2);
    _gleFeedbackHitRecord(param_1,uVar5);
    uVar4 = (param_2 + param_3 * 0x100) - 0x100;
    if (uVar5 < uVar4) {
      uVar6 = uVar5;
      do {
        uVar5 = uVar6 + 0x100;
        ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) - dVar1));
        _gleFeedbackHitRecord(param_1,uVar6);
        _gleFeedbackHitRecord(param_1,uVar5);
        uVar6 = uVar5;
      } while (uVar5 < uVar4);
    }
    ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) - DOUBLE_00108d70))
    ;
    _gleFeedbackHitRecord(param_1,uVar5);
    _gleFeedbackHitRecord(param_1,param_2);
  }
  return;
}

/* _gleFeedbackLinesPtr @ 0xcc4ec (276 bytes) */
void _gleFeedbackLinesPtr(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  undefined4 *puVar1;
  double dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  dVar2 = DOUBLE_00108d70;
  if (1 < param_3) {
    if (param_4 == 0) {
      uVar4 = 0x702;
      uVar3 = 0x702;
    }
    else if (param_4 == 1) {
      uVar3 = 0x707;
      uVar4 = 0x702;
    }
    else {
      uVar4 = 0x707;
      uVar3 = 0x707;
    }
    puVar5 = param_2 + 2;
    ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) - DOUBLE_00108d70))
    ;
    _gleFeedbackHitRecord(param_1,*param_2);
    _gleFeedbackHitRecord(param_1,param_2[1]);
    if (puVar5 < param_2 + param_3 + -1) {
      do {
        ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar4) - dVar2));
        _gleFeedbackHitRecord(param_1,*puVar5);
        puVar1 = puVar5 + 1;
        puVar5 = puVar5 + 2;
        _gleFeedbackHitRecord(param_1,*puVar1);
      } while (puVar5 < param_2 + param_3 + -1);
    }
  }
  return;
}

/* _gleFeedbackPolygon @ 0xcc600 (480 bytes) */
void _gleFeedbackPolygon(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  uint uVar1;
  double dVar2;
  undefined4 uVar3;
  uint uVar4;
  
  dVar2 = DOUBLE_00108d70;
  uVar4 = param_4 & 3;
  uVar3 = 0x707;
  if (uVar4 != 1) {
    if (uVar4 == 0) {
      uVar4 = param_2 + param_3 * 0x100;
      for (; param_2 < uVar4; param_2 = param_2 + 0x100) {
        if ((*(char *)(param_2 + 0x7c) != '\0') && (*(char *)(param_2 + 0x7d) == '\0')) {
          ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f28);
          _gleFeedbackHitRecord(param_1,param_2);
        }
      }
      return;
    }
    if (uVar4 == 2) {
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                               DOUBLE_00108d58));
      uVar4 = param_2 + param_3 * 0x100;
      for (; param_2 < uVar4; param_2 = param_2 + 0x100) {
        _gleFeedbackHitRecord(param_1,param_2);
      }
      return;
    }
    if (uVar4 != 3) {
      return;
    }
    uVar3 = 0x702;
  }
  uVar4 = param_2;
  while (uVar1 = uVar4, uVar1 < (param_2 + param_3 * 0x100) - 0x100) {
    uVar4 = uVar1 + 0x100;
    if (*(char *)(uVar1 + 0x7c) != '\0') {
      ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) - dVar2));
      _gleFeedbackHitRecord(param_1,uVar1);
      _gleFeedbackHitRecord(param_1,uVar4);
      uVar3 = 0x702;
    }
  }
  if (*(char *)(uVar1 + 0x7c) != '\0') {
    ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f34);
    _gleFeedbackHitRecord(param_1,uVar1);
    _gleFeedbackHitRecord(param_1,param_2);
  }
  return;
}

/* _gleFeedbackTriangles @ 0xcc7e0 (612 bytes) */
double _gleFeedbackTriangles(undefined4 param_1,int param_2,int param_3,uint param_4,double fparam_1)
{
  uint uVar1;
  double dVar2;
  double dVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  dVar3 = DOUBLE_00108dd0;
  dVar2 = DOUBLE_00108d70;
  uVar1 = param_4 & 3;
  iVar5 = param_3 + -3;
  iVar6 = 0;
  if (uVar1 == 1) {
    if (-1 < iVar5) {
      do {
        uVar4 = 0x707;
        if (*(char *)(param_2 + 0x7c) != '\0') {
          ((void (*)())_gleFeedbackToken)(param_1,(double)(float)dVar3);
          _gleFeedbackHitRecord(param_1,param_2);
          fparam_1 = (double)_gleFeedbackHitRecord(param_1,param_2 + 0x100);
          uVar4 = 0x702;
        }
        if (*(char *)(param_2 + 0x17c) != '\0') {
          ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar4) - dVar2));
          _gleFeedbackHitRecord(param_1,param_2 + 0x100);
          fparam_1 = (double)_gleFeedbackHitRecord(param_1,param_2 + 0x200);
          uVar4 = 0x702;
        }
        if (*(char *)(param_2 + 0x27c) != '\0') {
          ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar4) - dVar2));
          _gleFeedbackHitRecord(param_1,param_2 + 0x200);
          fparam_1 = (double)_gleFeedbackHitRecord(param_1,param_2);
        }
        iVar6 = iVar6 + 3;
        param_2 = param_2 + 0x300;
      } while (iVar6 <= iVar5);
    }
  }
  else if (uVar1 == 0) {
    if (-1 < iVar5) {
      do {
        if (*(char *)(param_2 + 0x7c) != '\0') {
          ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f28);
          fparam_1 = (double)_gleFeedbackHitRecord(param_1,param_2);
        }
        if (*(char *)(param_2 + 0x17c) != '\0') {
          ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f28);
          fparam_1 = (double)_gleFeedbackHitRecord(param_1,param_2 + 0x100);
        }
        if (*(char *)(param_2 + 0x27c) != '\0') {
          ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f28);
          fparam_1 = (double)_gleFeedbackHitRecord(param_1,param_2 + 0x200);
        }
        iVar6 = iVar6 + 3;
        param_2 = param_2 + 0x300;
      } while (iVar6 <= iVar5);
    }
  }
  else if ((uVar1 == 2) && (-1 < iVar5)) {
    do {
      iVar6 = iVar6 + 3;
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f38);
      _gleFeedbackHitRecord(param_1,param_2);
      _gleFeedbackHitRecord(param_1,param_2 + 0x100);
      fparam_1 = (double)_gleFeedbackHitRecord(param_1,param_2 + 0x200);
      param_2 = param_2 + 0x300;
    } while (iVar6 <= iVar5);
  }
  return fparam_1;
}

/* _gleFeedbackTriangleFan @ 0xcca44 (472 bytes) */
double _gleFeedbackTriangleFan(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  
  uVar1 = param_5 & 3;
  iVar2 = param_4 + -2;
  iVar3 = 0;
  if (uVar1 == 1) {
    if (-1 < iVar2) {
      dVar5 = (double)FLOAT_00108f34;
      do {
        iVar4 = param_3 + 0x100;
        iVar3 = iVar3 + 1;
        ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f2c);
        _gleFeedbackHitRecord(param_1,param_2);
        _gleFeedbackHitRecord(param_1,param_3);
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,param_3);
        _gleFeedbackHitRecord(param_1,iVar4);
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,iVar4);
        _gleFeedbackHitRecord(param_1,param_2);
        param_3 = iVar4;
      } while (iVar3 <= iVar2);
    }
  }
  else if (uVar1 == 0) {
    if (-1 < iVar2) {
      dVar5 = (double)FLOAT_00108f28;
      do {
        iVar3 = iVar3 + 1;
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,param_2);
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,param_3);
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,param_3 + 0x100);
        param_3 = param_3 + 0x100;
      } while (iVar3 <= iVar2);
    }
  }
  else if ((uVar1 == 2) && (-1 < iVar2)) {
    iVar2 = param_4 + -1;
    do {
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f38);
      _gleFeedbackHitRecord(param_1,param_2);
      _gleFeedbackHitRecord(param_1,param_3);
      _gleFeedbackHitRecord(param_1,param_3 + 0x100);
      iVar2 = iVar2 + -1;
      param_3 = param_3 + 0x100;
    } while (iVar2 != 0);
  }
  return;
}

/* _gleFeedbackTriangleStrip @ 0xccc1c (764 bytes) */
double _gleFeedbackTriangleStrip(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double dVar7;
  
  uVar2 = param_4 & 3;
  iVar3 = param_3 + -3;
  iVar4 = 0;
  if (uVar2 == 1) {
    bVar1 = 0 < iVar3;
    if (-1 < iVar3) {
      dVar7 = (double)FLOAT_00108f34;
      do {
        iVar6 = param_2 + 0x100;
        iVar5 = param_2 + 0x200;
        ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f2c);
        _gleFeedbackHitRecord(param_1,param_2);
        _gleFeedbackHitRecord(param_1,iVar6);
        ((void (*)())_gleFeedbackToken)(param_1,dVar7);
        _gleFeedbackHitRecord(param_1,iVar6);
        _gleFeedbackHitRecord(param_1,iVar5);
        ((void (*)())_gleFeedbackToken)(param_1,dVar7);
        _gleFeedbackHitRecord(param_1,iVar5);
        _gleFeedbackHitRecord(param_1,param_2);
        if (bVar1) {
          ((void (*)())_gleFeedbackToken)(param_1,dVar7);
          _gleFeedbackHitRecord(param_1,iVar5);
          _gleFeedbackHitRecord(param_1,iVar6);
          ((void (*)())_gleFeedbackToken)(param_1,dVar7);
          _gleFeedbackHitRecord(param_1,iVar6);
          _gleFeedbackHitRecord(param_1,param_2 + 0x300);
          ((void (*)())_gleFeedbackToken)(param_1,dVar7);
          _gleFeedbackHitRecord(param_1,param_2 + 0x300);
          _gleFeedbackHitRecord(param_1,iVar5);
        }
        iVar4 = iVar4 + 2;
        bVar1 = iVar4 < iVar3;
        param_2 = iVar5;
      } while (iVar4 <= iVar3);
    }
  }
  else if (uVar2 == 0) {
    bVar1 = 0 < iVar3;
    if (-1 < iVar3) {
      dVar7 = (double)FLOAT_00108f28;
      do {
        iVar6 = param_2 + 0x200;
        ((void (*)())_gleFeedbackToken)(param_1,dVar7);
        _gleFeedbackHitRecord(param_1,param_2);
        ((void (*)())_gleFeedbackToken)(param_1,dVar7);
        _gleFeedbackHitRecord(param_1,param_2 + 0x100);
        ((void (*)())_gleFeedbackToken)(param_1,dVar7);
        _gleFeedbackHitRecord(param_1,iVar6);
        if (bVar1) {
          ((void (*)())_gleFeedbackToken)(param_1,dVar7);
          _gleFeedbackHitRecord(param_1,iVar6);
          ((void (*)())_gleFeedbackToken)(param_1,dVar7);
          _gleFeedbackHitRecord(param_1,param_2 + 0x100);
          ((void (*)())_gleFeedbackToken)(param_1,dVar7);
          _gleFeedbackHitRecord(param_1,param_2 + 0x300);
        }
        iVar4 = iVar4 + 2;
        bVar1 = iVar4 < iVar3;
        param_2 = iVar6;
      } while (iVar4 <= iVar3);
    }
  }
  else if ((uVar2 == 2) && (bVar1 = 0 < iVar3, -1 < iVar3)) {
    dVar7 = (double)FLOAT_00108f30;
    do {
      iVar6 = param_2 + 0x200;
      ((void (*)())_gleFeedbackToken)(param_1,dVar7);
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f38);
      _gleFeedbackHitRecord(param_1,param_2);
      _gleFeedbackHitRecord(param_1,param_2 + 0x100);
      _gleFeedbackHitRecord(param_1,iVar6);
      if (bVar1) {
        ((void (*)())_gleFeedbackToken)(param_1,dVar7);
        ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f38);
        _gleFeedbackHitRecord(param_1,iVar6);
        _gleFeedbackHitRecord(param_1,param_2 + 0x100);
        _gleFeedbackHitRecord(param_1,param_2 + 0x300);
      }
      iVar4 = iVar4 + 2;
      bVar1 = iVar4 < iVar3;
      param_2 = iVar6;
    } while (iVar4 <= iVar3);
  }
  return;
}

/* _gleFeedbackQuads @ 0xccf18 (508 bytes) */
double _gleFeedbackQuads(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  double dVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  dVar2 = DOUBLE_00108d70;
  uVar1 = param_4 & 3;
  iVar4 = param_3 + -4;
  iVar5 = 0;
  if (uVar1 == 1) {
    iVar6 = param_2;
    if (-1 < iVar4) {
      do {
        uVar3 = 0x707;
        iVar7 = iVar5 * 0x100 + param_2;
        iVar8 = 2;
        do {
          if (*(char *)(iVar7 + 0x7c) != '\0') {
            ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) - dVar2));
            _gleFeedbackHitRecord(param_1,iVar7);
            _gleFeedbackHitRecord(param_1,iVar7 + 0x100);
            uVar3 = 0x702;
          }
          iVar8 = iVar8 + -1;
          iVar7 = iVar7 + 0x100;
        } while (-1 < iVar8);
        if (*(char *)(iVar6 + 0x37c) != '\0') {
          ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) - dVar2));
          _gleFeedbackHitRecord(param_1,iVar6 + 0x300);
          _gleFeedbackHitRecord(param_1,iVar6);
        }
        iVar5 = iVar5 + 4;
        iVar6 = iVar6 + 0x400;
      } while (iVar5 <= iVar4);
    }
  }
  else if (uVar1 == 0) {
    if (-1 < iVar4) {
      do {
        iVar6 = 3;
        iVar8 = iVar5 * 0x100 + param_2;
        do {
          if (*(char *)(iVar8 + 0x7c) != '\0') {
            ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f28);
            _gleFeedbackHitRecord(param_1,iVar8);
          }
          iVar6 = iVar6 + -1;
          iVar8 = iVar8 + 0x100;
        } while (-1 < iVar6);
        iVar5 = iVar5 + 4;
      } while (iVar5 <= iVar4);
    }
  }
  else if ((uVar1 == 2) && (-1 < iVar4)) {
    do {
      iVar5 = iVar5 + 4;
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108ea8);
      _gleFeedbackHitRecord(param_1,param_2);
      _gleFeedbackHitRecord(param_1,param_2 + 0x100);
      _gleFeedbackHitRecord(param_1,param_2 + 0x200);
      _gleFeedbackHitRecord(param_1,param_2 + 0x300);
      param_2 = param_2 + 0x400;
    } while (iVar5 <= iVar4);
  }
  return;
}

/* _gleFeedbackQuadStrip @ 0xcd114 (552 bytes) */
double _gleFeedbackQuadStrip(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  
  uVar1 = param_4 & 3;
  iVar2 = param_3 + -4;
  iVar3 = 0;
  if (uVar1 == 1) {
    if (-1 < iVar2) {
      dVar5 = (double)FLOAT_00108f34;
      do {
        ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f2c);
        iVar3 = iVar3 + 2;
        _gleFeedbackHitRecord(param_1,param_2);
        _gleFeedbackHitRecord(param_1,param_2 + 0x100);
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        iVar4 = param_2 + 0x200;
        _gleFeedbackHitRecord(param_1,param_2 + 0x100);
        _gleFeedbackHitRecord(param_1,param_2 + 0x300);
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,param_2 + 0x300);
        _gleFeedbackHitRecord(param_1,iVar4);
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,iVar4);
        _gleFeedbackHitRecord(param_1,param_2);
        param_2 = iVar4;
      } while (iVar3 <= iVar2);
    }
  }
  else if (uVar1 == 0) {
    if (-1 < iVar2) {
      dVar5 = (double)FLOAT_00108f28;
      do {
        iVar3 = iVar3 + 2;
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,param_2);
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,param_2 + 0x100);
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,param_2 + 0x300);
        ((void (*)())_gleFeedbackToken)(param_1,dVar5);
        _gleFeedbackHitRecord(param_1,param_2 + 0x200);
        param_2 = param_2 + 0x200;
      } while (iVar3 <= iVar2);
    }
  }
  else if ((uVar1 == 2) && (-1 < iVar2)) {
    do {
      iVar3 = iVar3 + 2;
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108ea8);
      _gleFeedbackHitRecord(param_1,param_2);
      _gleFeedbackHitRecord(param_1,param_2 + 0x100);
      _gleFeedbackHitRecord(param_1,param_2 + 0x300);
      _gleFeedbackHitRecord(param_1,param_2 + 0x200);
      param_2 = param_2 + 0x200;
    } while (iVar3 <= iVar2);
  }
  return;
}

/* _gleTestFence @ 0xcd33c (212 bytes) */
int _gleTestFence(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  iVar3 = 1;
  iVar4 = 0;
  if (param_2 == 0) {
    iVar2 = _gleLookupHashObject(param_1 + 0x543c,param_3);
    iVar4 = iVar3;
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
      }
    }
    else {
      iVar5 = param_1 + 0x10000;
      uVar6 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        puVar7 = (undefined4 *)(iVar2 + 0x10);
        do {
          bVar1 = iVar4 != 0;
          iVar4 = 0;
          if ((bVar1) &&
             (iVar3 = (**(code **)(*(int *)(iVar5 + -0x777c) + 0x1c0))
                                (*(undefined4 *)(iVar5 + -0x7a54),0,*puVar7), iVar3 != 0)) {
            iVar4 = 1;
          }
          uVar6 = uVar6 + 1;
          iVar5 = iVar5 + 0x2e0;
          puVar7 = puVar7 + 1;
        } while (uVar6 < *(byte *)(param_1 + 0x85a4));
      }
    }
  }
  return iVar4;
}

/* _gleFinishFence @ 0xcd410 (172 bytes) */
void _gleFinishFence(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  if (param_2 == 0) {
    iVar3 = _gleLookupHashObject(param_1 + 0x543c,param_3);
    if (iVar3 == 0) {
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
      }
    }
    else {
      iVar5 = param_1 + 0x10000;
      uVar6 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        puVar7 = (undefined4 *)(iVar3 + 0x10);
        do {
          piVar1 = (int *)(iVar5 + -0x777c);
          uVar4 = *puVar7;
          uVar6 = uVar6 + 1;
          puVar7 = puVar7 + 1;
          puVar2 = (undefined4 *)(iVar5 + -0x7a54);
          iVar5 = iVar5 + 0x2e0;
          (**(code **)(*piVar1 + 0x1c4))(*puVar2,0,uVar4);
        } while (uVar6 < *(byte *)(param_1 + 0x85a4));
      }
    }
  }
  return;
}

/* _gleBindRenderbuffer @ 0xcd4bc (268 bytes) */
void _gleBindRenderbuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 *puVar4;
  
  iVar2 = *(int *)(param_1 + 0x5148);
  puVar4 = (undefined4 *)0x0;
  if (param_2 != 0) {
    puVar4 = (undefined4 *)_gleLookupHashObject(((unsigned char *)0x00001004) + iVar2,param_2);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)_malloc(0xaac);
      puVar1 = PTR__gleFreeTextureObject_00112154;
      *puVar4 = 0;
      puVar4[2] = 1;
      puVar4[3] = puVar1;
      puVar4[1] = param_2;
      _gleInitializeGLTexture(0x2000,1,puVar4 + 4,in_r6,in_r7,in_r8,1);
      *(undefined2 *)((int)puVar4 + 0x4e) = 0x85bf;
      *(undefined2 *)(puVar4 + 0x12) = 0x812f;
      *(undefined2 *)(puVar4 + 0x13) = 0x2600;
      *(undefined2 *)(puVar4 + 0x11) = 0x812f;
      *(undefined2 *)((int)puVar4 + 0x46) = 0x812f;
      *(undefined2 *)((int)puVar4 + 0x4a) = 0x2600;
      _gleCreatePluginTexture(param_1,puVar4 + 4);
      _gleAddHashNameAndObject(param_1,((unsigned char *)0x00001004) + iVar2,puVar4);
    }
    puVar4[2] = puVar4[2] + 1;
  }
  iVar2 = *(int *)(param_1 + 0x7448);
  if ((iVar2 != 0) && (iVar3 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar3, iVar3 == 0)) {
    _gleFreeTextureObject(param_1,iVar2);
  }
  *(undefined4 **)(param_1 + 0x7448) = puVar4;
  return;
}

/* _gleRenderbufferStorage @ 0xcd5c8 (612 bytes) */
void _gleRenderbufferStorage(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  uint param_3;
  int param_4;
  int param_5;
{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar10 = *(int *)(param_1 + 0x7448);
  if (iVar10 == 0) {
    return;
  }
  iVar9 = iVar10 + 0x10;
  if ((((param_3 == 0x1902) || (param_3 == 0x81a5)) || (param_3 == 0x81a6)) || (param_3 == 0x81a7))
  {
    uVar8 = 0x1902;
  }
  else {
    if (((param_3 != 0x1901) && (param_3 != 0x8d46)) &&
       ((param_3 != 0x8d47 && ((param_3 != 0x8d48 && (param_3 != 0x8d49)))))) {
      uVar8 = 0x80e1;
      uVar7 = 0x8367;
      goto LAB_000cd6a0;
    }
    uVar8 = 0x1901;
  }
  uVar7 = 0x1405;
LAB_000cd6a0:
  iVar11 = iVar10 + 0xd4;
  if ((*(byte *)(iVar10 + 0xdf) & 0x20) != 0) {
    _gleDeletePluginTextureLevel(param_1,iVar9,iVar11,0,0);
    if (*(int *)(iVar10 + 0xe8) != 0) {
      bVar1 = *(byte *)(iVar10 + 0xdf);
      if ((bVar1 & 1) == 0) {
        _gleFreeTextureLevel(param_1,iVar9,iVar11);
        bVar1 = *(byte *)(iVar10 + 0xdf);
      }
      else {
        *(undefined4 *)(iVar10 + 0xe8) = 0;
      }
      *(byte *)(iVar10 + 0xdf) = bVar1 & 0xef;
    }
    *(byte *)(iVar10 + 0xdf) = *(byte *)(iVar10 + 0xdf) & 0xdf;
  }
  _gleCreateTextureLevel(param_1,iVar9,iVar11,param_3 & 0xffff,param_4,param_5,1,0,uVar8,uVar7,0,0);
  if ((param_4 != 0) && (param_5 != 0)) {
    _gleCreatePluginTextureLevel(param_1,iVar9,iVar11,0,0,param_3 & 0xffff);
  }
  iVar9 = *(int *)(param_1 + 0x744c);
  if (iVar9 != 0) {
    iVar4 = iVar9 + 0x10;
    piVar3 = (int *)(iVar9 + 0xd4);
    iVar11 = 0;
    iVar9 = iVar4;
    do {
      iVar2 = *piVar3;
      piVar3 = piVar3 + 1;
      if (iVar2 == iVar10) {
        *(undefined4 *)(iVar9 + 0x20) = param_2;
        iVar2 = 0;
        *(undefined4 *)(iVar9 + 0x28) = 0;
        *(undefined4 *)(iVar9 + 0x24) = 0;
        *(undefined4 *)(iVar9 + 0x2c) = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar6 = (undefined4 *)(iVar4 + 0xe0);
          puVar5 = (undefined4 *)(iVar10 + 0x10);
          do {
            uVar8 = *puVar5;
            iVar2 = iVar2 + 1;
            puVar5 = puVar5 + 1;
            *puVar6 = uVar8;
            puVar6 = puVar6 + 8;
          } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      iVar11 = iVar11 + 1;
      iVar4 = iVar4 + 4;
      iVar9 = iVar9 + 0x18;
    } while (iVar11 < 6);
  }
  return;
}

/* _gleCreatePluginFramebuffer @ 0xcd82c (132 bytes) */
void _gleCreatePluginFramebuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = param_1 + 0x10000;
  iVar4 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    iVar5 = param_2;
    iVar6 = param_2 + 0xe0;
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      iVar4 = iVar4 + 1;
      (**(code **)(*piVar1 + 0x1fc))(*puVar2,iVar5,param_2 + 0x20,iVar6);
      iVar5 = iVar5 + 4;
      iVar6 = iVar6 + 0x20;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleDestroyPluginFramebuffer @ 0xcd8b0 (120 bytes) */
void _gleDestroyPluginFramebuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 + 0x10000;
  iVar5 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      iVar3 = iVar5 * 4;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      iVar5 = iVar5 + 1;
      (**(code **)(*piVar1 + 0x204))(*puVar2,*(undefined4 *)(iVar3 + param_2));
      *(undefined4 *)(iVar3 + param_2) = 0;
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleCreateFramebufferObject @ 0xcd928 (344 bytes) */
int _gleCreateFramebufferObject(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  puVar5 = (undefined4 *)_gleVecAlloc((uint)*(byte *)(param_1 + 0x85a4) * 0x20 + 0xf0);
  puVar1 = PTR__gleFreeFramebufferObject_00110e20;
  puVar5[2] = 1;
  puVar5[3] = puVar1;
  puVar5[1] = param_2;
  puVar3 = puVar5 + 0x35;
  *puVar5 = 0;
  iVar6 = 6;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 8;
  puVar5[0x3b] = 1;
  puVar3 = puVar5 + 4;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 3;
  *(undefined2 *)(puVar5 + 0x30) = 0x8ce0;
  puVar2 = (undefined2 *)((int)puVar5 + 0xc2);
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 6;
  *(undefined2 *)(puVar5 + 0x32) = 0x8ce0;
  puVar5[0x34] = 0;
  puVar3 = puVar5;
  do {
    puVar3[0xc] = 0;
    puVar3[0xd] = 0;
    puVar3[0xe] = 0;
    puVar3[0xf] = 0;
    puVar3[0x11] = 0;
    puVar3[0x10] = 0;
    puVar3 = puVar3 + 6;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 0;
  puVar3 = puVar5;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      puVar4 = puVar3 + 0x3c;
      iVar7 = 6;
      do {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      puVar5[0x42] = 0;
      iVar6 = iVar6 + 1;
      puVar5[0x43] = 0;
      puVar5 = puVar5 + 8;
      puVar3 = puVar3 + 8;
    } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleFreeFramebufferObject @ 0xcda80 (116 bytes) */
void _gleFreeFramebufferObject(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 5;
  ((void (*)())_gleDestroyPluginFramebuffer)(param_1,param_2 + 0x10);
  piVar4 = (int *)(param_2 + 0xd4);
  do {
    iVar2 = *piVar4;
    piVar4 = piVar4 + 1;
    if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar1, iVar1 == 0))
    {
      _gleFreeTextureObject(param_1,iVar2);
    }
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  _gleVecFree(param_2);
  return;
}

/* _gleUpdateFramebufferDirtyBits @ 0xcdaf4 (192 bytes) */
void _gleUpdateFramebufferDirtyBits(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_2 + 0xdc) != 0) {
    return;
  }
  iVar1 = 0;
  while ((iVar2 = *(int *)(iVar1 * 4 + param_2 + 0xc4), iVar2 == 0 ||
         (iVar3 = param_2 + iVar1 * 0x18,
         *(int *)(iVar3 + 0x30) ==
         *(int *)(iVar2 + *(int *)(iVar3 + 0x24) * 0x168 + *(int *)(iVar3 + 0x28) * 0x18 + 0xd4))))
  {
    iVar1 = iVar1 + 1;
    if (5 < iVar1) {
      return;
    }
  }
  iVar1 = 0;
  *(undefined4 *)(param_2 + 0xdc) = 1;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      *(undefined4 *)(param_2 + 0xf8) = 1;
      iVar1 = iVar1 + 1;
      *(undefined4 *)(param_2 + 0xfc) = 0;
      param_2 = param_2 + 0x20;
    } while (iVar1 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  return;
}

/* _gleBindFramebuffer @ 0xcdbb4 (1100 bytes) */
void _gleBindFramebuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  byte bVar8;
  undefined4 *puVar7;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  uVar15 = *(undefined4 *)(param_1 + 0x5148);
  if (param_2 == 0) {
    uVar13 = 0;
    iVar4 = 0;
    bVar1 = true;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      puVar6 = (undefined4 *)(param_1 + 0x8880);
      do {
        *puVar6 = 0;
        uVar13 = uVar13 + 1;
        puVar6 = puVar6 + 0xb8;
        bVar1 = true;
      } while (uVar13 < *(byte *)(param_1 + 0x85a4));
    }
  }
  else {
    iVar4 = _gleLookupHashObject(uVar15,param_2);
    bVar1 = iVar4 == 0;
    if (bVar1) {
      iVar4 = ((int (*)())_gleCreateFramebufferObject)(param_1,param_2);
      iVar9 = iVar4 + 0x10;
      ((void (*)())_gleCreatePluginFramebuffer)(param_1,iVar9);
      _gleAddHashNameAndObject(param_1,uVar15,iVar4);
      bVar1 = iVar4 == 0;
    }
    else {
      iVar9 = iVar4 + 0x10;
    }
    uVar13 = 0;
    piVar10 = (int *)(iVar4 + 0xd4);
    iVar12 = iVar4;
    do {
      iVar2 = *piVar10;
      piVar10 = piVar10 + 1;
      if (iVar2 != 0) {
        iVar16 = iVar2 + 0x10;
        iVar11 = *(int *)(iVar12 + 0x34);
        uVar14 = *(uint *)(iVar12 + 0x38);
        iVar3 = iVar16 + iVar11 * 0x168 + uVar14 * 0x18;
        if (*(int *)(iVar2 + 0x30) == 0) {
LAB_000cdca4:
          iVar5 = *(int *)(param_1 + 0x5148);
        }
        else {
          iVar5 = *(int *)(param_1 + 0x5148);
          if (*(int *)(iVar2 + 0x30) !=
              *(int *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x8054)) {
            _gleSynchronizePluginTextureLevels(param_1,iVar16);
            goto LAB_000cdca4;
          }
        }
        *(undefined4 *)(iVar2 + 0x30) =
             *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x8054);
        *(byte *)(iVar3 + 0xcf) = *(byte *)(iVar3 + 0xcf) | 0x80;
        if (*(int *)(iVar3 + 0xd8) != 0) {
          bVar8 = *(byte *)(iVar3 + 0xcf);
          if (((bVar8 & 1) == 0) && (*(short *)(iVar2 + 0x4e) == -0x7a43)) {
            _gleFreeTextureLevel(param_1,iVar16,iVar3 + 0xc4);
            bVar8 = *(byte *)(iVar3 + 0xcf);
          }
          iVar5 = iVar11 * 2 + iVar16;
          *(byte *)(iVar3 + 0xcf) = bVar8 & 0xef;
          *(ushort *)(iVar5 + 0xa0) =
               *(ushort *)(iVar5 + 0xa0) &
               ((ushort)(-2 << (uVar14 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (uVar14 & 0x1f)));
        }
        *(byte *)(iVar3 + 0xcf) = *(byte *)(iVar3 + 0xcf) | 0x40;
        if ((((*(uint *)(iVar2 + 0x7c) & 0x8000) != 0) && ((int)*(short *)(iVar2 + 0x70) == uVar14))
           && (uVar14 = uVar14 + 1, (int)uVar14 <= (int)(uint)*(byte *)(iVar2 + 0x93))) {
          iVar3 = iVar11 * 2 + iVar16;
          iVar11 = uVar14 * 0x18 + iVar11 * 0x168 + iVar16 + 0xc4;
          do {
            if (*(int *)(iVar11 + 0x14) != 0) {
              if (((*(byte *)(iVar11 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x4e) == -0x7a43)) {
                _gleFreeTextureLevel(param_1,iVar16,iVar11);
              }
              *(byte *)(iVar11 + 0xb) = *(byte *)(iVar11 + 0xb) & 0xef;
              *(ushort *)(iVar3 + 0xa0) =
                   *(ushort *)(iVar3 + 0xa0) & ~(ushort)(1 << (uVar14 & 0x3f));
            }
            uVar14 = uVar14 + 1;
            *(byte *)(iVar11 + 0xb) = *(byte *)(iVar11 + 0xb) | 0x40;
            iVar11 = iVar11 + 0x18;
          } while ((int)uVar14 <= (int)(uint)*(byte *)(iVar2 + 0x93));
        }
      }
      uVar13 = uVar13 + 1;
      iVar12 = iVar12 + 0x18;
    } while (uVar13 < 6);
    uVar13 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      puVar6 = (undefined4 *)(iVar4 + 0x10);
      puVar7 = (undefined4 *)(param_1 + 0x8880);
      do {
        uVar15 = *puVar6;
        uVar13 = uVar13 + 1;
        puVar6 = puVar6 + 1;
        *puVar7 = uVar15;
        puVar7 = puVar7 + 0xb8;
      } while (uVar13 < *(byte *)(param_1 + 0x85a4));
    }
    ((void (*)())_gleUpdateFramebufferDirtyBits)(param_1,iVar9);
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;
  }
  iVar9 = *(int *)(param_1 + 0x744c);
  *(int *)(param_1 + 0x744c) = iVar4;
  if (bVar1) {
    uVar15 = 0;
  }
  else {
    uVar15 = *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar4 + 0x10);
  }
  fparam_1 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x4778))
                               (*(undefined4 *)(param_1 + 0x4688), 0x5b, uVar15, 0);
  *(undefined1 *)(param_1 + 0x7582) = *(undefined1 *)(*(int *)(param_1 + 0x468c) + 0x25);
  if ((bVar1) ||
     ((*(int *)(iVar4 + 0xec) == 0 &&
      (((iVar9 == 0 || (*(short *)(iVar9 + 0xca) != *(short *)(iVar4 + 0xca))) ||
       (*(short *)(iVar9 + 0xcc) != *(short *)(iVar4 + 0xcc))))))) {
    ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  }
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000180;
  if (iVar9 != 0) {
    iVar12 = 6;
    piVar10 = (int *)(iVar9 + 0xd4);
    iVar4 = iVar9;
    do {
      iVar2 = *piVar10;
      piVar10 = piVar10 + 1;
      if (iVar2 != 0) {
        iVar2 = iVar2 + *(int *)(iVar4 + 0x34) * 0x168 + *(int *)(iVar4 + 0x38) * 0x18;
        *(byte *)(iVar2 + 0xdf) = *(byte *)(iVar2 + 0xdf) & 0x7f;
      }
      iVar4 = iVar4 + 0x18;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    iVar4 = *(int *)(iVar9 + 8) + -1;
    *(int *)(iVar9 + 8) = iVar4;
    if (iVar4 == 0) {
      ((void (*)())_gleFreeFramebufferObject)(param_1,iVar9);
      return;
    }
  }
  return;
}

/* _gleFramebufferTexture @ 0xce000 (852 bytes) */
void _gleFramebufferTexture(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  uint param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  undefined4 *puVar9;
  
  iVar3 = *(int *)(param_1 + 0x744c) + 0x10;
  iVar6 = param_2 * 4 + iVar3;
  *(undefined4 *)(*(int *)(param_1 + 0x744c) + 0xec) = 1;
  iVar8 = *(int *)(iVar6 + 0xc4);
  *(int *)(iVar6 + 0xc4) = param_4;
  if (iVar8 != 0) {
    iVar6 = param_2 * 0x18 + iVar3;
    iVar6 = iVar8 + *(int *)(iVar6 + 0x24) * 0x168 + *(int *)(iVar6 + 0x28) * 0x18;
    *(byte *)(iVar6 + 0xdf) = *(byte *)(iVar6 + 0xdf) & 0x7f;
  }
  if (param_4 == 0) {
    iVar6 = iVar3 + param_2 * 0x18;
    *(undefined4 *)(iVar6 + 0x20) = 0;
    *(undefined4 *)(iVar6 + 0x30) = 0;
    uVar4 = 0;
    *(undefined4 *)(iVar6 + 0x24) = 0;
    *(undefined4 *)(iVar6 + 0x28) = 0;
    *(undefined4 *)(iVar6 + 0x2c) = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      puVar9 = (undefined4 *)(param_2 * 4 + iVar3 + 0xe0);
      do {
        *puVar9 = 0;
        uVar4 = uVar4 + 1;
        *(undefined4 *)(iVar3 + 0xf8) = 1;
        puVar9 = puVar9 + 8;
        *(undefined4 *)(iVar3 + 0xfc) = 0;
        iVar3 = iVar3 + 0x20;
      } while (uVar4 < *(byte *)(param_1 + 0x85a4));
    }
  }
  else {
    iVar6 = iVar3 + param_2 * 0x18;
    *(undefined4 *)(iVar6 + 0x20) = param_3;
    *(undefined4 *)(iVar6 + 0x2c) = param_7;
    *(undefined4 *)(iVar6 + 0x30) = 0;
    *(int *)(iVar6 + 0x24) = param_5;
    uVar4 = 0;
    *(uint *)(iVar6 + 0x28) = param_6;
    puVar9 = (undefined4 *)(param_4 + 0x10);
    iVar6 = param_6 * 0x18 + param_5 * 0x168;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      puVar2 = (undefined4 *)(param_2 * 4 + iVar3 + 0xe0);
      puVar5 = puVar9;
      do {
        uVar1 = *puVar5;
        uVar4 = uVar4 + 1;
        *(undefined4 *)(iVar3 + 0xf8) = 1;
        puVar5 = puVar5 + 1;
        *puVar2 = uVar1;
        puVar2 = puVar2 + 8;
        *(undefined4 *)(iVar3 + 0xfc) = 0;
        iVar3 = iVar3 + 0x20;
      } while (uVar4 < *(byte *)(param_1 + 0x85a4));
    }
    *(undefined4 *)(param_4 + 0x30) =
         *(undefined4 *)
          ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
    iVar3 = puVar9[param_5 * 0x5a + param_6 * 6 + 0x36];
    *(byte *)((int)puVar9 + iVar6 + 0xcf) = *(byte *)((int)puVar9 + iVar6 + 0xcf) | 0x80;
    if (iVar3 != 0) {
      bVar7 = *(byte *)((int)puVar9 + iVar6 + 0xcf);
      if (((bVar7 & 1) == 0) && (*(short *)(param_4 + 0x4e) == -0x7a43)) {
        _gleFreeTextureLevel(param_1,puVar9,puVar9 + param_5 * 0x5a + param_6 * 6 + 0x31);
        bVar7 = *(byte *)((int)puVar9 + iVar6 + 0xcf);
      }
      *(byte *)((int)puVar9 + iVar6 + 0xcf) = bVar7 & 0xef;
      *(ushort *)((int)puVar9 + param_5 * 2 + 0xa0) =
           *(ushort *)((int)puVar9 + param_5 * 2 + 0xa0) &
           ((ushort)(-2 << (param_6 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_6 & 0x1f)));
    }
    *(byte *)((int)puVar9 + iVar6 + 0xcf) = *(byte *)((int)puVar9 + iVar6 + 0xcf) | 0x40;
    if ((((*(uint *)(param_4 + 0x7c) & 0x8000) != 0) && ((int)*(short *)(param_4 + 0x70) == param_6)
        ) && (uVar4 = param_6 + 1, (int)uVar4 <= (int)(uint)*(byte *)(param_4 + 0x93))) {
      puVar5 = puVar9 + param_5 * 0x5a + uVar4 * 6 + 0x31;
      do {
        if (puVar5[5] != 0) {
          if (((*(byte *)((int)puVar5 + 0xb) & 1) == 0) && (*(short *)(param_4 + 0x4e) == -0x7a43))
          {
            _gleFreeTextureLevel(param_1,puVar9,puVar5);
          }
          *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) & 0xef;
          *(ushort *)((int)puVar9 + param_5 * 2 + 0xa0) =
               *(ushort *)((int)puVar9 + param_5 * 2 + 0xa0) & ~(ushort)(1 << (uVar4 & 0x3f));
        }
        uVar4 = uVar4 + 1;
        *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) | 0x40;
        puVar5 = puVar5 + 6;
      } while ((int)uVar4 <= (int)(uint)*(byte *)(param_4 + 0x93));
    }
    *(int *)(param_4 + 8) = *(int *)(param_4 + 8) + 1;
  }
  if ((iVar8 != 0) && (iVar3 = *(int *)(iVar8 + 8) + -1, *(int *)(iVar8 + 8) = iVar3, iVar3 == 0)) {
    _gleFreeTextureObject(param_1,iVar8);
  }
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  return;
}

/* _gleCheckFramebufferAttachmentCompleteness @ 0xce354 (196 bytes) */
double _gleCheckFramebufferAttachmentCompleteness(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int *param_3;
  int param_4;
{
  int iVar1;
  
  param_3[5] = 1;
  iVar1 = param_2 + param_3[1] * 0x168 + param_3[2] * 0x18;
  param_3[4] = *(int *)(iVar1 + 0xc4);
  if (*(short *)(iVar1 + 200) == 0) {
    return;
  }
  if (*(short *)(iVar1 + 0xca) == 0) {
    return;
  }
  if (*param_3 == 1) {
    if ((int)((uint)*(ushort *)(iVar1 + 0xcc) + (uint)*(byte *)(iVar1 + 0xce)) <= param_3[3]) {
      return;
    }
    if (param_3[3] < (int)-(uint)*(byte *)(iVar1 + 0xce)) {
      return;
    }
  }
  if (((param_4 < 4) && (*(short *)(param_2 + 0x26) != 0x1907)) &&
     (*(short *)(param_2 + 0x26) != 0x1908)) {
    return;
  }
  if ((param_4 == 4) && (*(short *)(param_2 + 0x26) != 0x1902)) {
    return;
  }
  if ((param_4 == 5) && (*(short *)(param_2 + 0x26) != 0x1901)) {
    return;
  }
  param_3[5] = 0;
  return;
}

/* _gleUpdateFramebufferCompleteness @ 0xce418 (588 bytes) */
void _gleUpdateFramebufferCompleteness(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  ushort *puVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int local_50 [8];
  
  sVar8 = 0;
  *(undefined1 *)(param_1 + 0x759d) = 0;
  *(undefined4 *)(param_2 + 0xdc) = 0;
  *(undefined2 *)(param_2 + 0xba) = 0;
  iVar9 = 0;
  *(undefined2 *)(param_2 + 0xbc) = 0;
  piVar11 = (int *)(param_2 + 0xc4);
  uVar10 = 0;
  iVar12 = param_2;
  do {
    iVar5 = *piVar11;
    piVar11 = piVar11 + 1;
    uVar4 = uVar10;
    if (iVar5 != 0) {
      iVar3 = iVar5 + 0x10 + *(int *)(iVar12 + 0x24) * 0x168 + *(int *)(iVar12 + 0x28) * 0x18;
      if (*(int *)(iVar12 + 0x30) != *(int *)(iVar3 + 0xc4)) {
        fparam_1 = (double)((double (*)())_gleCheckFramebufferAttachmentCompleteness)(param_1,iVar5 + 0x10,iVar12 + 0x20,iVar9);
      }
      if (*(int *)(iVar12 + 0x34) != 0) {
        uVar2 = 0x8cd6;
        goto LAB_000ce630;
      }
      if (*(short *)(param_2 + 0xba) == 0) {
        *(undefined2 *)(param_2 + 0xba) = *(undefined2 *)(iVar3 + 200);
        *(undefined2 *)(param_2 + 0xbc) = *(undefined2 *)(iVar3 + 0xca);
      }
      else if ((*(short *)(param_2 + 0xba) != *(short *)(iVar3 + 200)) ||
              (*(short *)(param_2 + 0xbc) != *(short *)(iVar3 + 0xca))) {
        *(undefined4 *)(param_2 + 0xc0) = 0x8cd9;
        return;
      }
      if (iVar9 < 4) {
        if (sVar8 == 0) {
          sVar8 = *(short *)(iVar5 + 0x88);
        }
        else if (sVar8 != *(short *)(iVar5 + 0x88)) {
          uVar2 = 0x8cda;
          goto LAB_000ce630;
        }
      }
      uVar4 = 0;
      if (uVar10 != 0) {
        piVar6 = local_50;
        do {
          iVar5 = *piVar6;
          piVar6 = piVar6 + 1;
          if (iVar5 == iVar3 + 0xc4) {
            uVar2 = 0x8cd8;
            goto LAB_000ce630;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar10);
      }
      uVar4 = uVar10 + 1;
      local_50[uVar10] = iVar3 + 0xc4;
    }
    iVar9 = iVar9 + 1;
    iVar12 = iVar12 + 0x18;
    uVar10 = uVar4;
  } while (iVar9 < 6);
  if (uVar4 == 0) {
    uVar2 = 0x8cd7;
  }
  else {
    iVar12 = 0;
    puVar7 = (ushort *)(param_2 + 0xb0);
    do {
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
      if ((uVar1 != 0) && (*(int *)((uVar1 - 0x8ce0) * 4 + param_2 + 0xc4) == 0)) {
        uVar2 = 0x8cdb;
        goto LAB_000ce630;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < 4);
    if ((*(ushort *)(param_2 + 0xb8) == 0) ||
       (*(int *)((*(ushort *)(param_2 + 0xb8) - 0x8ce0) * 4 + param_2 + 0xc4) != 0)) {
      ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(undefined4 *)(param_2 + 0xc0) = 0;
      *(undefined1 *)(param_1 + 0x759d) = 1;
      return;
    }
    uVar2 = 0x8cdc;
  }
LAB_000ce630:
  *(undefined4 *)(param_2 + 0xc0) = uVar2;
  return;
}

/* _gleCheckFramebufferStatus @ 0xce664 (1200 bytes) */
int _gleCheckFramebufferStatus(int param_1,int param_2,int *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  
  if (*(int *)(param_2 + 0xdc) != 0) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    fparam_1 = fparam_1;
  }
  if (*(int *)(param_2 + 0xc0) != 0) {
    return *(int *)(param_2 + 0xc0);
  }
  iVar5 = *(int *)(param_1 + 0x50ac);
  if (iVar5 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1_00;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar4 = *(int *)(param_1 + 0x744c);
    piVar7 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar4 + 0x10,param_3,param_4,param_5,param_6,iVar5,fparam_1,fparam_2,
                 fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000ce7a4:
      uVar6 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar5 = 0;
      piVar3 = (int *)(param_1 + 0x324);
      do {
        iVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        if (iVar4 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
      uVar6 = *(uint *)(param_1 + 0x31c);
      if ((uVar6 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000ce7a4;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar6 = uVar6 & 0x17000000;
    }
    else {
      uVar6 = uVar6 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar7 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar6 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar7 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar6 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
        uVar6 = (**(code **)(param_1 + 0x4788))
                          (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar7);
        if ((((uVar6 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
            ((uVar6 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
           (fparam_1 = extraout_f1_02, (uVar6 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
        {
          if ((uVar6 & 4) == 0) {
            uVar6 = uVar6 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar6);
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
      }
    }
    iVar5 = 0;
    param_3 = piVar7;
    do {
      iVar5 = iVar5 + 1;
      *param_3 = 0;
      param_3 = param_3 + 1;
    } while (iVar5 < 0x13);
  }
  if (-1 < *(int *)((uint)*(byte *)(param_1 + 0x85a8) * 0x20 + param_2 + 0xfc)) goto LAB_000cead8;
  iVar5 = *(int *)(param_1 + 0x50ac);
  if (iVar5 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1_03;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_000cead8;
  iVar4 = *(int *)(param_1 + 0x744c);
  piVar7 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar4 != 0) && (*(int *)(iVar4 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar4 + 0x10,param_3,param_4,param_5,param_6,iVar5,fparam_1,fparam_2,fparam_3
               ,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000ce9d4:
    uVar6 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar5 = 0;
    piVar3 = (int *)(param_1 + 0x324);
    do {
      iVar4 = *piVar3;
      piVar3 = piVar3 + 1;
      if (iVar4 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 9);
    uVar6 = *(uint *)(param_1 + 0x31c);
    if ((uVar6 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_000ce9d4;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar6 = uVar6 & 0x17000000;
  }
  else {
    uVar6 = uVar6 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar7 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar6 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar7 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar6 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar6 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar7);
      if ((((uVar6 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar6 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar6 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar6 & 4) == 0) {
          uVar6 = uVar6 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar6);
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
  }
  iVar5 = 0x13;
  do {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
LAB_000cead8:
  iVar5 = 0x8cdd;
  if ((*(uint *)((uint)*(byte *)(param_1 + 0x85a8) * 0x20 + param_2 + 0xfc) & 1) == 0) {
    iVar5 = 0x8cd5;
  }
  return iVar5;
}

/* _gleSynchronizePluginFramebuffer @ 0xceb14 (172 bytes) */
int _gleSynchronizePluginFramebuffer(param_1)
  int param_1;
{
  int iVar1;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 0x744c) != 0) {
    piVar3 = (int *)(*(int *)(param_1 + 0x744c) + 0xd4);
    iVar2 = 5;
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      if (iVar1 != 0) {
        _gleSynchronizePluginTextureLevels(param_1,iVar1 + 0x10);
      }
      iVar2 = iVar2 + -1;
    } while (-1 < iVar2);
    iVar1 = (uint)*(byte *)(param_1 + 0x85a6) * 4 + *(int *)(param_1 + 0x744c);
    iVar2 = (uint)*(byte *)(param_1 + 0x85a6) * 0x2e0 + param_1;
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x8884) + 0x138))
                      (*(undefined4 *)(iVar2 + 0x85ac),0x5b,*(undefined4 *)(iVar1 + 0x10),0,in_r7,
                       in_r8,iVar1);
  }
  *(undefined1 *)(param_1 + 0x7582) = *(undefined1 *)(*(int *)(param_1 + 0x468c) + 0x25);
  return iVar2;
}

/* _gleFreeFramebufferState @ 0xcebc0 (256 bytes) */
void _gleFreeFramebufferState(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x744c);
  iVar2 = *(int *)(param_1 + 0x7448);
  if (iVar3 != 0) {
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    iVar1 = *(int *)(iVar3 + 8) + -1;
    *(int *)(iVar3 + 8) = iVar1;
    if (iVar1 == 0) {
      ((void (*)())_gleFreeFramebufferObject)(param_1,iVar3);
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (iVar2 != 0) {
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    iVar3 = *(int *)(iVar2 + 8) + -1;
    *(int *)(iVar2 + 8) = iVar3;
    if (iVar3 == 0) {
      _gleFreeTextureObject(param_1,iVar2);
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return;
    }
  }
  return;
}

/* _gleGenerateMipmap @ 0xcecc0 (208 bytes) */
void _gleGenerateMipmap(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  puVar3 = (undefined4 *)_gleLookUpNonProxyTexture(param_1,param_2);
  if ((*(ushort *)(puVar3 + 9) & 0xf) != 2) {
    iVar5 = 6;
    if ((*(ushort *)(puVar3 + 9) & 0xf) != 0) {
      iVar5 = 1;
    }
    iVar6 = 0;
    if (iVar5 != 0) {
      do {
        iVar7 = iVar6 + 1;
        _gleGenMipmapsToLevel
                  (param_1,puVar3,iVar6,(int)*(short *)(puVar3 + 0x18),
                   (int)*(short *)((int)puVar3 + 0x62),0);
        iVar6 = iVar7;
      } while (iVar7 < iVar5);
    }
    iVar5 = param_1 + 0x10000;
    iVar6 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        piVar1 = (int *)(iVar5 + -0x777c);
        uVar4 = *puVar3;
        iVar6 = iVar6 + 1;
        puVar3 = puVar3 + 1;
        puVar2 = (undefined4 *)(iVar5 + -0x7a54);
        iVar5 = iVar5 + 0x2e0;
        (**(code **)(*piVar1 + 0x154))(*puVar2,uVar4,0x80);
      } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
  }
  return;
}

/* _gleFogExp2 @ 0xced90 (56 bytes) */
double _gleFogExp2(int param_1,float fparam_1)
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)*(float *)(param_1 + 0x3150) * fparam_1);
  fVar2 = *(float *)(param_1 + 0x24);
  fVar1 = fVar1 * -fVar1;
  return (double)(fVar2 / ((((*(float *)(param_1 + 0x38) * fVar1 - *(float *)(param_1 + 0x34)) *
                             fVar1 + *(float *)(param_1 + 0x30)) * fVar1 - fVar2) * fVar1 + fVar2));
}

/* _gleLFSParse @ 0xcedc8 (612 bytes) */
void _gleLFSParse(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_40 [7];
  
  iVar9 = *(int *)(param_1 + 0x5424);
  piVar7 = (int *)0x0;
  uVar6 = *(undefined4 *)(iVar9 + 0x14);
  iVar8 = *(int *)(iVar9 + 0x4e4);
  if (*(int *)(iVar9 + 0x4cc) != 0) {
    _gleVecFree(*(int *)(iVar9 + 0x4cc));
    *(undefined4 *)(iVar9 + 0x4cc) = 0;
  }
  if (iVar8 != 0) {
    _LFSStreamFree(iVar8);
  }
  iVar8 = ((int (*)())_LFSParserCreate)();
  ((int (*)())_LFSParserAttachString)(iVar8,uVar6,1);
  iVar3 = _LFSStreamCreate();
  ((void (*)())_LFSParserAttachStream)(iVar8,iVar3);
  iVar4 = ((int (*)())_LFSParserParse)(iVar8);
  if (iVar4 == 0) {
    *(undefined4 *)(iVar9 + 0x4e8) = 0;
    uVar5 = 0;
    do {
      if (uVar5 == 0) {
        piVar7 = *(int **)(iVar3 + 4);
      }
      if (uVar5 == 1) {
        piVar7 = *(int **)(iVar3 + 0xc);
      }
      for (iVar4 = *piVar7; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x4c)) {
        if (*(int *)(iVar4 + 8) == 5) {
          switch(*(undefined4 *)(iVar4 + 0xc)) {
          case 0:
            uVar1 = *(uint *)(iVar9 + 0x4e8) | 1;
            break;
          case 1:
            uVar1 = *(uint *)(iVar9 + 0x4e8) | 2;
            break;
          case 2:
            uVar1 = *(uint *)(iVar9 + 0x4e8) | 4;
            break;
          case 3:
            uVar1 = *(uint *)(iVar9 + 0x4e8) | 8;
            break;
          case 4:
            uVar1 = *(uint *)(iVar9 + 0x4e8) | 0x10;
            break;
          case 5:
            uVar1 = *(uint *)(iVar9 + 0x4e8) | 0x20;
            break;
          case 6:
            uVar1 = *(uint *)(iVar9 + 0x4e8) | 0x40;
            break;
          case 7:
            uVar1 = *(uint *)(iVar9 + 0x4e8) | 0x80;
            break;
          default:
            goto switchD_000ceebc_default;
          }
          *(uint *)(iVar9 + 0x4e8) = uVar1;
        }
switchD_000ceebc_default: ;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 2);
    for (iVar4 = **(int **)(iVar3 + 0x10); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x4c)) {
      iVar2 = iVar4 + 4;
      iVar10 = 3;
      do {
        if (*(int *)(iVar2 + 0x14) == 4) {
          if (*(int *)(iVar2 + 0x18) == 0) {
            uVar5 = *(uint *)(iVar9 + 0x4e8) | 0x100;
          }
          else {
            if (*(int *)(iVar2 + 0x18) != 1) goto LAB_000cefac;
            uVar5 = *(uint *)(iVar9 + 0x4e8) | 0x200;
          }
          *(uint *)(iVar9 + 0x4e8) = uVar5;
        }
LAB_000cefac:
        iVar2 = iVar2 + 0x10;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    *(int *)(iVar9 + 0x4e4) = iVar3;
    _LFSStreamGetStream(iVar3,0,local_40);
    uVar6 = _gleVecAlloc(local_40[0] << 2);
    *(undefined4 *)(iVar9 + 0x4cc) = uVar6;
    _LFSStreamGetStream(iVar3,uVar6,local_40);
    **(undefined1 **)(param_1 + 0x5418) = 0;
    *(undefined4 *)(param_1 + 0x541c) = 0xffffffff;
  }
  else {
    _snprintf(*(char **)(param_1 + 0x5418),0x600,"Error on line %i: %s;",*(int *)(iVar8 + 0x460) + 1
              ,iVar8 + 0x5c);
    *(undefined4 *)(param_1 + 0x541c) = 0;
  }
  ((void (*)())_LFSParserFree)(iVar8);
  return;
}

/* _LFSParserCreate @ 0xcf04c (60 bytes) */
int _LFSParserCreate()
{
  undefined4 uVar1;
  
  uVar1 = _calloc(0x46c,1);
  ((int (*)())_LFSParserInit)(uVar1);
  return uVar1;
}

/* _LFSParserInit @ 0xcf088 (12 bytes) */
int _LFSParserInit(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = _memset(param_1,0,0x46c);
  return uVar1;
}

/* _LFSParserShutdown @ 0xcf094 (12 bytes) */
int _LFSParserShutdown(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())_LFSParserAttachString)(param_1,0,0);
  return uVar1;
}

/* _LFSParserFree @ 0xcf0a0 (48 bytes) */
void _LFSParserFree(param_1)
  undefined4 param_1;
{
  ((int (*)())_LFSParserShutdown)(param_1);
  _free(param_1);
  return;
}

/* _LFSParserAttachStream @ 0xcf0d0 (64 bytes) */
void _LFSParserAttachStream(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if (*(int *)(param_1 + 0x14) != 0) {
    _LFSStreamFree(*(int *)(param_1 + 0x14));
  }
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

/* _LFSParserCheckForNewline @ 0xcf110 (96 bytes) */
int _LFSParserCheckForNewline(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 *param_5;
{
  char cVar1;
  
  if (param_3 + 1U < param_4) {
    cVar1 = *(char *)(param_2 + param_3);
    if ((cVar1 == '\r') && (*(char *)(param_2 + param_3 + 1) == '\n')) {
      *param_5 = 2;
      return true;
    }
  }
  else {
    cVar1 = *(char *)(param_2 + param_3);
  }
  if (cVar1 == '\n') {
    return true;
  }
  return cVar1 == '\r';
}

/* _LFSParserPreprocessString @ 0xcf170 (568 bytes) */
int _LFSParserPreprocessString(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  int local_40 [5];
  
  uVar6 = 0;
  uVar3 = _strlen(param_2);
  bVar2 = false;
  iVar7 = 0;
  if (uVar3 != 0) {
    do {
      local_40[0] = 1;
      if (bVar2) {
        iVar4 = ((int (*)())_LFSParserCheckForNewline)(param_1,param_2,uVar6,uVar3,local_40);
        if ((iVar4 != 0) || (*(char *)(param_2 + uVar6) == '\0')) {
          bVar2 = false;
        }
LAB_000cf24c:
        iVar7 = iVar7 + 1;
      }
      else {
        cVar1 = *(char *)(param_2 + uVar6);
        if (cVar1 != '#') {
          if (((((cVar1 == '[') || (cVar1 == ']')) || (cVar1 == '=')) ||
              ((cVar1 == '{' || (cVar1 == '}')))) ||
             ((cVar1 == ';' || ((cVar1 == '.' || (cVar1 == ',')))))) {
            iVar7 = iVar7 + 2;
          }
          goto LAB_000cf24c;
        }
        bVar2 = true;
      }
      uVar6 = uVar6 + local_40[0];
    } while (uVar6 < uVar3);
  }
  uVar6 = 0;
  puVar5 = (undefined1 *)_calloc(iVar7 + 1,1);
  bVar2 = false;
  puVar8 = puVar5;
  if (uVar3 != 0) {
    do {
      local_40[0] = 1;
      if (bVar2) {
        iVar7 = ((int (*)())_LFSParserCheckForNewline)(param_1,param_2,uVar6,uVar3,local_40);
        if (iVar7 != 0) {
          *puVar8 = 10;
          bVar2 = false;
          puVar8 = puVar8 + 1;
        }
        if (*(char *)(param_2 + uVar6) == '\0') {
          bVar2 = false;
          *puVar8 = 0;
          goto LAB_000cf37c;
        }
      }
      else {
        cVar1 = *(char *)(param_2 + uVar6);
        if (cVar1 == '#') {
          bVar2 = true;
        }
        else {
          if ((((cVar1 == '[') || (cVar1 == ']')) || (cVar1 == '=')) ||
             (((cVar1 == '{' || (cVar1 == '}')) ||
              ((cVar1 == ';' || ((cVar1 == '.' || (cVar1 == ',')))))))) {
            *puVar8 = 0x20;
            puVar8[1] = cVar1;
            puVar8 = puVar8 + 2;
            *puVar8 = 0x20;
          }
          else {
            iVar7 = ((int (*)())_LFSParserCheckForNewline)(param_1,param_2,uVar6,uVar3,local_40);
            if (iVar7 == 0) {
              *puVar8 = *(undefined1 *)(param_2 + uVar6);
            }
            else {
              *puVar8 = 10;
            }
          }
LAB_000cf37c:
          puVar8 = puVar8 + 1;
        }
      }
      uVar6 = uVar6 + local_40[0];
    } while (uVar6 < uVar3);
  }
  return puVar5;
}

/* _LFSParserAttachString @ 0xcf3a8 (252 bytes) */
int _LFSParserAttachString(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_20 [4];
  
  if (*param_1 == 0) {
    if (param_2 != 0) {
      if (param_3 == 0) {
        iVar1 = _strlen(param_2);
        iVar2 = _calloc(iVar1 + 1,1);
        *param_1 = iVar2;
        _memmove(iVar2,param_2,iVar1);
      }
      else {
        iVar1 = ((int (*)())_LFSParserPreprocessString)(param_1,param_2);
        *param_1 = iVar1;
      }
      uVar4 = 0;
      uVar3 = _strlen(*param_1);
      param_1[2] = 0;
      param_1[1] = uVar3;
      if (uVar3 != 0) {
        do {
          local_20[0] = 1;
          iVar1 = ((int (*)())_LFSParserCheckForNewline)(param_1,*param_1,uVar4,uVar3,local_20);
          if (iVar1 != 0) {
            param_1[2] = param_1[2] + 1;
          }
          uVar3 = param_1[1];
          uVar4 = uVar4 + local_20[0];
        } while (uVar4 < uVar3);
      }
    }
  }
  else {
    _free(*param_1);
    param_1[1] = 0;
    *param_1 = 0;
  }
  return;
}

/* _LFSParserEatWhiteSpace @ 0xcf4a4 (76 bytes) */
void _LFSParserEatWhiteSpace(param_1)
  int *param_1;
{
  uint uVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = param_1[3];
    if (iVar2 == param_1[1]) {
      return;
    }
    uVar1 = (uint)*(byte *)(*param_1 + iVar2);
    if ((1 < uVar1 - 9) && (uVar1 != 0x20)) break;
    param_1[3] = iVar2 + 1;
    if (uVar1 == 10) {
      param_1[4] = param_1[4] + 1;
    }
  }
  return;
}

/* _LFSParserGetCharacter @ 0xcf4f0 (252 bytes) */
int _LFSParserGetCharacter(param_1, param_2, param_3)
  int *param_1;
  byte *param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  
  bVar1 = param_3 == 0;
  bVar3 = false;
  bVar2 = false;
  do {
    if (bVar1) {
      iVar4 = param_1[3];
      if (iVar4 == param_1[1]) {
        return 1;
      }
    }
    else {
      if (param_1[3] == 0) {
        return 1;
      }
      iVar4 = param_1[3] + -1;
      param_1[3] = iVar4;
    }
    *param_2 = *(byte *)(*param_1 + iVar4);
    if (bVar1) {
      param_1[3] = param_1[3] + 1;
    }
    uVar5 = (uint)*param_2;
    if (uVar5 == 10) {
      if (bVar1) {
        iVar4 = param_1[4] + 1;
      }
      else {
        iVar4 = param_1[4] + -1;
      }
      param_1[4] = iVar4;
      uVar5 = (uint)*param_2;
    }
    if ((uVar5 - 9 < 2) || ((char)uVar5 == ' ')) {
      if (param_1[3] == param_1[1]) {
        *param_2 = 0x20;
        goto LAB_000cf5b0;
      }
      bVar2 = true;
    }
    else {
LAB_000cf5b0:
      if (bVar2) {
        *param_2 = 0x20;
        if (bVar1) {
          iVar4 = param_1[3] + -1;
        }
        else {
          iVar4 = param_1[3] + 1;
        }
        param_1[3] = iVar4;
      }
      bVar3 = true;
    }
    if (bVar3) {
      return 0;
    }
  } while( true );
}

/* _LFSParserRewind @ 0xcf5ec (92 bytes) */
int _LFSParserRewind(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  undefined1 auStack_20 [20];
  
  iVar1 = 0;
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      iVar1 = ((int (*)())_LFSParserGetCharacter)(param_1,auStack_20,1);
      if (param_2 == 0) {
        return iVar1;
      }
    } while (iVar1 == 0);
  }
  return iVar1;
}

/* _LFSParserGetPart @ 0xcf648 (188 bytes) */
int _LFSParserGetPart(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  char local_30 [16];
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = *(undefined4 *)(param_1 + 0xc);
  local_1c = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x45c) = local_20;
  *(undefined4 *)(param_1 + 0x460) = local_1c;
  local_30[0] = '\0';
  ((void (*)())_LFSParserEatWhiteSpace)(param_1);
  uVar2 = 0;
  do {
    iVar1 = ((int (*)())_LFSParserGetCharacter)(param_1,local_30,0);
    if (iVar1 != 0) break;
    if (local_30[0] == ' ') {
      ((int (*)())_LFSParserRewind)(param_1,1);
      break;
    }
    *(char *)(param_2 + uVar2) = local_30[0];
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xff);
  *(undefined1 *)(param_2 + uVar2) = 0;
  if ((uVar2 == 0) || (uVar2 == 0xff)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* _LFSParserGetScalars @ 0xcf704 (400 bytes) */
int _LFSParserGetScalars(param_1, param_2, param_3)
  int param_1;
  float *param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  char local_350 [256];
  char local_250 [256];
  undefined1 auStack_150 [256];
  undefined4 local_50;
  undefined4 local_4c;
  char *local_40 [7];
  
  uVar1 = 0;
  if (*param_3 != 0) {
    local_50 = *(undefined4 *)(param_1 + 0xc);
    local_4c = *(undefined4 *)(param_1 + 0x10);
    iVar3 = 0;
    do {
      iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_350);
      if (iVar2 == 0) {
        return 8;
      }
      local_50 = *(undefined4 *)(param_1 + 0xc);
      local_4c = *(undefined4 *)(param_1 + 0x10);
      iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_250);
      if (iVar2 == 0) {
        return 8;
      }
      if (local_250[0] == '.') {
        iVar2 = ((int (*)())_LFSParserGetPart)(param_1,auStack_150);
        if (iVar2 == 0) {
          return 8;
        }
        _strcat(local_350,local_250);
        _strcat(local_350,auStack_150);
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = local_4c;
        *(undefined4 *)(param_1 + 0xc) = local_50;
      }
      dVar4 = (double)((double (*)())_gle_strtod)(local_350,local_40);
      *param_2 = (float)dVar4;
      if (local_40[0] == local_350) {
        uVar1 = 9;
        goto LAB_000cf86c;
      }
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 1;
      uVar1 = 0;
      if (iVar3 == *param_3) goto LAB_000cf878;
      local_50 = *(undefined4 *)(param_1 + 0xc);
      local_4c = *(undefined4 *)(param_1 + 0x10);
      iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_350);
      if (iVar2 == 0) {
        return 8;
      }
    } while (local_350[0] == ',');
    uVar1 = 10;
LAB_000cf86c:
    *(undefined4 *)(param_1 + 0x10) = local_4c;
    *(undefined4 *)(param_1 + 0xc) = local_50;
LAB_000cf878:
    *param_3 = iVar3;
  }
  return uVar1;
}

/* _LFSParserParseArray @ 0xcf894 (188 bytes) */
int _LFSParserParseArray(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  char local_130 [256];
  undefined4 local_30 [4];
  int local_20 [5];
  
  local_20[0] = 1;
  iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_130);
  iVar2 = 8;
  if ((((iVar1 != 0) && (iVar2 = 0x10, local_130[0] == '[')) &&
      (iVar2 = ((int (*)())_LFSParserGetScalars)(param_1,local_30,local_20), iVar2 == 0)) &&
     (iVar2 = 0x10, local_20[0] == 1)) {
    *param_2 = local_30[0];
    iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_130);
    iVar2 = 8;
    if (iVar1 != 0) {
      iVar2 = (uint)(local_130[0] != ']') * 0x10;
    }
  }
  return iVar2;
}

/* _LFSParserParseRegister @ 0xcf950 (356 bytes) */
int _LFSParserParseRegister(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  uint *param_3;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  char local_110;
  undefined1 auStack_10f [259];
  
  iVar4 = ((int (*)())_LFSParserGetPart)(param_1,&local_110);
  if (iVar4 == 0) {
    return 8;
  }
  iVar4 = _memcmp(&local_110,"color0",7);
  if (iVar4 == 0) {
    *param_2 = 4;
    *param_3 = 0;
    return 0;
  }
  iVar4 = _memcmp(&local_110,"color1",7);
  uVar2 = 4;
  if (iVar4 == 0) {
LAB_000cfa84:
    *param_2 = uVar2;
    uVar3 = 1;
LAB_000cfa8c:
    *param_3 = uVar3;
  }
  else {
    if (local_110 == 'c') {
      *param_2 = 2;
      uVar3 = _atoi(auStack_10f);
      bVar1 = 8 < uVar3;
      *param_3 = uVar3;
      uVar2 = 5;
    }
    else {
      if (local_110 < 'd') {
        if (local_110 != '0') {
          if (local_110 != '1') {
            return 5;
          }
          uVar2 = 3;
          goto LAB_000cfa84;
        }
        uVar3 = 0;
        *param_2 = 3;
        goto LAB_000cfa8c;
      }
      if (local_110 == 'r') {
        *param_2 = 1;
        uVar3 = _atoi(auStack_10f);
        bVar1 = 6 < uVar3;
        *param_3 = uVar3;
        uVar2 = 0x1d;
      }
      else {
        if (local_110 != 't') {
          return 5;
        }
        *param_2 = 5;
        uVar3 = _atoi(auStack_10f);
        bVar1 = 6 < uVar3;
        *param_3 = uVar3;
        uVar2 = 0x1e;
      }
    }
    if (bVar1) {
      return uVar2;
    }
  }
  return 0;
}

/* _LFSParserParseDestinationMask @ 0xcfab4 (244 bytes) */
int _LFSParserParseDestinationMask(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char local_110 [264];
  
  uVar4 = ((int (*)())_LFSParserGetPart)(param_1,local_110);
  iVar5 = 8;
  if (uVar4 != 0) {
    *(undefined4 *)(param_2 + 8) = 0;
    uVar3 = 0;
    iVar5 = 0;
    if (uVar4 != 0) {
      do {
        cVar1 = local_110[uVar3];
        if (cVar1 == 'b') {
          if ((*(uint *)(param_2 + 8) & 0x40000) == 0) {
            uVar2 = *(uint *)(param_2 + 8) | 0x40000;
            goto LAB_000cfb70;
          }
LAB_000cfb78:
          iVar5 = 6;
        }
        else {
          if (cVar1 < 'c') {
            if ((cVar1 == 'a') && ((*(uint *)(param_2 + 8) & 0x80000) == 0)) {
              uVar2 = *(uint *)(param_2 + 8) | 0x80000;
              goto LAB_000cfb70;
            }
            goto LAB_000cfb78;
          }
          if (cVar1 != 'g') {
            if ((cVar1 == 'r') && ((*(uint *)(param_2 + 8) & 0x10000) == 0)) {
              uVar2 = *(uint *)(param_2 + 8) | 0x10000;
              goto LAB_000cfb70;
            }
            goto LAB_000cfb78;
          }
          if ((*(uint *)(param_2 + 8) & 0x20000) != 0) goto LAB_000cfb78;
          uVar2 = *(uint *)(param_2 + 8) | 0x20000;
LAB_000cfb70:
          *(uint *)(param_2 + 8) = uVar2;
        }
        uVar3 = uVar3 + 1;
      } while ((uVar3 < uVar4) && (iVar5 == 0));
    }
  }
  return iVar5;
}

/* _LFSParserParseDestinationModifiers @ 0xcfba8 (460 bytes) */
int _LFSParserParseDestinationModifiers(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char local_120 [256];
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_120);
  uVar3 = 8;
  if (iVar2 != 0) {
    iVar2 = _memcmp(local_120,"2x",3);
    uVar1 = 0x1000;
    if (iVar2 != 0) {
      iVar2 = _memcmp(local_120,"4x",3);
      uVar1 = 0x2000;
      if (iVar2 != 0) {
        iVar2 = _memcmp(local_120,"8x",3);
        uVar1 = 0x3000;
        if (iVar2 != 0) {
          iVar2 = _memcmp(local_120,"half",5);
          uVar1 = 0x4000;
          if (iVar2 != 0) {
            iVar2 = _memcmp(local_120,"quarter",8);
            uVar1 = 0x5000;
            if (iVar2 != 0) {
              iVar2 = _memcmp(local_120,"eighth",7);
              uVar1 = 0x6000;
              if (iVar2 != 0) {
                iVar2 = _memcmp(local_120,"sat",4);
                if (iVar2 != 0) {
                  return 7;
                }
                uVar1 = *(uint *)(param_2 + 0xc) | 0x8000;
              }
            }
          }
        }
      }
    }
    *(uint *)(param_2 + 0xc) = uVar1;
    local_20 = *(undefined4 *)(param_1 + 0xc);
    local_1c = *(undefined4 *)(param_1 + 0x10);
    iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_120);
    uVar3 = 8;
    if (iVar2 != 0) {
      if (local_120[0] == '.') {
        iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_120);
        uVar3 = 8;
        if (iVar2 != 0) {
          iVar2 = _memcmp(local_120,"sat",4);
          uVar3 = 7;
          if (iVar2 == 0) {
            uVar3 = 0;
            *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 0x8000;
          }
        }
      }
      else {
        uVar3 = 0;
        *(undefined4 *)(param_1 + 0x10) = local_1c;
        *(undefined4 *)(param_1 + 0xc) = local_20;
      }
    }
  }
  return uVar3;
}

/* _LFSParserParseDestination @ 0xcfd74 (308 bytes) */
int _LFSParserParseDestination(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  char local_130 [256];
  undefined4 local_30;
  undefined4 local_2c;
  int local_20;
  int local_1c [4];
  
  iVar1 = ((int (*)())_LFSParserParseRegister)(param_1,&local_20,local_1c);
  if (iVar1 != 0) {
    return iVar1;
  }
  param_2[2] = 0xf0000;
  param_2[1] = local_1c[0];
  *param_2 = local_20;
  if (local_20 != 1) {
    return 5;
  }
  local_30 = *(undefined4 *)(param_1 + 0xc);
  local_2c = *(undefined4 *)(param_1 + 0x10);
  iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_130);
  if (iVar1 == 0) {
    return 8;
  }
  if (local_130[0] == '.') {
    local_30 = *(undefined4 *)(param_1 + 0xc);
    local_2c = *(undefined4 *)(param_1 + 0x10);
    iVar1 = ((int (*)())_LFSParserParseDestinationMask)(param_1,param_2);
    if (iVar1 == 0) {
      local_30 = *(undefined4 *)(param_1 + 0xc);
      local_2c = *(undefined4 *)(param_1 + 0x10);
      iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_130);
      if (iVar1 == 0) {
        return 8;
      }
      if (local_130[0] != '.') goto LAB_000cfe58;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = local_2c;
      *(undefined4 *)(param_1 + 0xc) = local_30;
    }
    iVar1 = ((int (*)())_LFSParserParseDestinationModifiers)(param_1,param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  else {
LAB_000cfe58:
    *(undefined4 *)(param_1 + 0x10) = local_2c;
    *(undefined4 *)(param_1 + 0xc) = local_30;
  }
  return 0;
}

/* _LFSParserParseSourceModifier @ 0xcfea8 (336 bytes) */
int _LFSParserParseSourceModifier(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char local_120 [256];
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar3 = 0;
  do {
    iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_120);
    if (iVar2 == 0) {
      return 8;
    }
    iVar2 = _memcmp(local_120,"neg",4);
    if (iVar2 == 0) {
      uVar1 = *(uint *)(param_2 + 0xc) | 0x100;
    }
    else {
      iVar2 = _memcmp(local_120,"2x",3);
      if (iVar2 == 0) {
        uVar1 = *(uint *)(param_2 + 0xc) | 0x200;
      }
      else {
        iVar2 = _memcmp(local_120,"bias",5);
        if (iVar2 == 0) {
          uVar1 = *(uint *)(param_2 + 0xc) | 0x400;
        }
        else {
          iVar2 = _memcmp(local_120,"comp",5);
          if (iVar2 != 0) {
            return 0xb;
          }
          uVar1 = *(uint *)(param_2 + 0xc) | 0x800;
        }
      }
    }
    *(uint *)(param_2 + 0xc) = uVar1;
    local_20 = *(undefined4 *)(param_1 + 0xc);
    local_1c = *(undefined4 *)(param_1 + 0x10);
    iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_120);
    if (iVar2 == 0) {
      return 8;
    }
    if (local_120[0] != '.') {
      *(undefined4 *)(param_1 + 0x10) = local_1c;
      *(undefined4 *)(param_1 + 0xc) = local_20;
      return 0;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  return 0;
}

/* _LFSParserParseSourceVar @ 0xcfff8 (540 bytes) */
int _LFSParserParseSourceVar(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  char local_130 [256];
  undefined4 local_30;
  undefined4 local_2c;
  int local_20;
  int local_1c [4];
  
  iVar1 = ((int (*)())_LFSParserParseRegister)(param_1,&local_20,local_1c);
  if (iVar1 != 0) {
    return iVar1;
  }
  *param_2 = local_20;
  param_2[1] = local_1c[0];
  if (local_20 == 2) {
    iVar1 = *(int *)**(undefined4 **)(param_1 + 0x14);
    while( true ) {
      if (iVar1 == 0) {
        return 0x12;
      }
      if (*(int *)(iVar1 + 8) == local_1c[0]) break;
      iVar1 = *(int *)(iVar1 + 0x4c);
    }
  }
  local_30 = *(undefined4 *)(param_1 + 0xc);
  local_2c = *(undefined4 *)(param_1 + 0x10);
  iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_130);
  if (iVar1 == 0) {
    return 8;
  }
  if (local_130[0] != '.') goto LAB_000d01ec;
  local_30 = *(undefined4 *)(param_1 + 0xc);
  local_2c = *(undefined4 *)(param_1 + 0x10);
  iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_130);
  if (iVar1 == 0) {
    return 8;
  }
  iVar2 = _memcmp(local_130,"r",2);
  iVar1 = 0x1000;
  if (iVar2 == 0) {
LAB_000d0164:
    param_2[2] = iVar1;
  }
  else {
    iVar2 = _memcmp(local_130,"g",2);
    iVar1 = 0x2000;
    if (iVar2 == 0) goto LAB_000d0164;
    iVar2 = _memcmp(local_130,"b",2);
    iVar1 = 0x3000;
    if (iVar2 == 0) goto LAB_000d0164;
    iVar1 = _memcmp(local_130,"a",2);
    if (iVar1 == 0) {
      iVar1 = 0x4000;
      goto LAB_000d0164;
    }
    *(undefined4 *)(param_1 + 0x10) = local_2c;
    *(undefined4 *)(param_1 + 0xc) = local_30;
    iVar1 = ((int (*)())_LFSParserParseSourceModifier)(param_1,param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  if (param_2[2] == 0) {
    return 0;
  }
  local_30 = *(undefined4 *)(param_1 + 0xc);
  local_2c = *(undefined4 *)(param_1 + 0x10);
  iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_130);
  if (iVar1 == 0) {
    return 8;
  }
  if (local_130[0] == '.') {
    iVar1 = ((int (*)())_LFSParserParseSourceModifier)(param_1,param_2);
    if (iVar1 == 0) {
      return 0;
    }
    return iVar1;
  }
LAB_000d01ec:
  *(undefined4 *)(param_1 + 0x10) = local_2c;
  *(undefined4 *)(param_1 + 0xc) = local_30;
  return 0;
}

/* _LFSParserParseOperation @ 0xd0214 (1192 bytes) */
int _LFSParserParseOperation(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  char local_190 [256];
  uint local_90;
  undefined1 auStack_8c [8];
  uint local_84;
  int local_7c [15];
  int local_40 [8];
  
  uVar5 = 0;
  _memset(&local_90,0,0x44);
  local_40[0] = 0;
  local_40[1] = 0;
  uVar4 = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  local_40[4] = 0;
  local_40[5] = 0;
  local_40[6] = 0;
  local_40[7] = 0;
  iVar3 = ((int (*)())_LFSParserGetPart)(param_1,local_190);
  if (iVar3 == 0) {
    return 8;
  }
  iVar3 = _memcmp(local_190,"MOV",4);
  if (iVar3 == 0) {
    local_90 = 0;
  }
  else {
    iVar3 = _memcmp(local_190,"ADD",4);
    local_90 = 0x100;
    if (iVar3 != 0) {
      iVar3 = _memcmp(local_190,"MUL",4);
      local_90 = 0x200;
      if (iVar3 != 0) {
        iVar3 = _memcmp(local_190,"SUB",4);
        local_90 = 0x300;
        if (iVar3 != 0) {
          iVar3 = _memcmp(local_190,"DOT3",5);
          local_90 = 0x400;
          if (iVar3 != 0) {
            iVar3 = _memcmp(local_190,"DOT4",5);
            local_90 = 0x500;
            if (iVar3 != 0) {
              iVar3 = _memcmp(local_190,"MAD",4);
              local_90 = 0x600;
              if (iVar3 != 0) {
                iVar3 = _memcmp(local_190,"LERP",5);
                local_90 = 0x700;
                if (iVar3 != 0) {
                  iVar3 = _memcmp(local_190,"CND",4);
                  local_90 = 0x800;
                  if (iVar3 != 0) {
                    iVar3 = _memcmp(local_190,"CND0",5);
                    local_90 = 0x900;
                    if (iVar3 != 0) {
                      iVar3 = _memcmp(local_190,"DOT2ADD",8);
                      if (iVar3 != 0) {
                        return 3;
                      }
                      local_90 = 0xa00;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_90 == 0) {
    uVar4 = 1;
  }
  else if (local_90 < 0x501) {
    uVar4 = 2;
  }
  else if (local_90 < 0xa01) {
    uVar4 = 3;
  }
  iVar3 = ((int (*)())_LFSParserParseDestination)(param_1,auStack_8c);
  if (iVar3 != 0) {
    return iVar3;
  }
  uVar6 = 0;
  if (uVar4 != 0) {
    piVar7 = local_7c;
    do {
      iVar3 = ((int (*)())_LFSParserGetPart)(param_1,local_190);
      if (iVar3 == 0) {
        return 8;
      }
      if (local_190[0] != ',') {
        return 10;
      }
      iVar3 = ((int (*)())_LFSParserParseSourceVar)(param_1,piVar7);
      if (local_7c[uVar6 * 4] == 2) {
        if (local_40[local_7c[uVar6 * 4 + 1]] == 0) {
          uVar5 = uVar5 + 1;
        }
        local_40[local_7c[uVar6 * 4 + 1]] = local_40[local_7c[uVar6 * 4 + 1]] + 1;
      }
      if ((*(char *)(param_1 + 0x19) != '\x03') && (local_7c[uVar6 * 4] == 4)) {
        return 0x14;
      }
      if ((local_7c[uVar6 * 4] == 4) && (local_7c[uVar6 * 4 + 1] == 1)) {
        if ((local_84 & 0x80000) == 0) {
          if (local_7c[uVar6 * 4 + 2] == 0x4000) {
            return 0x1c;
          }
        }
        else {
          iVar2 = local_7c[uVar6 * 4 + 2];
          if (((iVar2 != 0x1000) && (iVar2 != 0x2000)) && (iVar2 != 0x3000)) {
            return 0x1c;
          }
        }
      }
      if (iVar3 != 0) {
        return iVar3;
      }
      uVar6 = uVar6 + 1;
      piVar7 = piVar7 + 4;
    } while (uVar6 < uVar4);
    if (2 < uVar5) {
      return 0x13;
    }
  }
  uVar4 = (uint)*(byte *)(param_1 + 0x19);
  bVar1 = false;
  uVar5 = *(uint *)(uVar4 * 0x10 + param_1 + 0x1c);
  if (uVar5 != 0) {
    if (((((uVar5 & 0x10000) != 0) || ((uVar5 & 0x20000) != 0)) || ((uVar5 & 0x40000) != 0)) &&
       (((*(uint *)(uVar4 * 0x10 + param_1 + 0x1c) & 0x80000) == 0 && (local_84 == 0x80000)))) {
      bVar1 = true;
    }
    iVar3 = uVar4 * 0x10 + param_1;
    *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 1;
    *(undefined4 *)((uint)*(byte *)(param_1 + 0x19) * 0x10 + param_1 + 0x1c) = 0;
    uVar4 = (uint)*(byte *)(param_1 + 0x19);
    if (bVar1) goto LAB_000d064c;
  }
  if (((local_84 & 0x70000) == 0) || ((local_84 & 0x80000) != 0)) {
    iVar3 = uVar4 * 0x10 + param_1;
    *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 1;
  }
  else {
    iVar3 = uVar4 * 0x10 + param_1;
    if (7 < *(uint *)(iVar3 + 0x20)) {
      return 0x16;
    }
    *(uint *)(iVar3 + 0x1c) = local_84;
  }
  uVar4 = (uint)*(byte *)(param_1 + 0x19);
LAB_000d064c:
  iVar3 = 0x16;
  if (*(uint *)(uVar4 * 0x10 + param_1 + 0x20) < 9) {
    if (uVar4 == 2) {
      _LFSStreamAddPreliminaryPassOperation(*(undefined4 *)(param_1 + 0x14),&local_90);
    }
    else {
      if (uVar4 != 3) {
        return 0xc;
      }
      _LFSStreamAddOutputPassOperation(*(undefined4 *)(param_1 + 0x14),&local_90);
    }
    iVar3 = 0;
  }
  return iVar3;
}

/* _LFSParserParseRegisterInit @ 0xd06bc (940 bytes) */
int _LFSParserParseRegisterInit(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  char local_140 [256];
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_20 [5];
  
  piVar5 = (int *)0x0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_140);
  iVar3 = 8;
  if (iVar2 != 0) {
    iVar2 = _memcmp(local_140,"PassTexCoord",0xd);
    if (iVar2 == 0) {
      local_40 = 0;
    }
    else {
      iVar2 = _memcmp(local_140,"SampleMap",10);
      if (iVar2 != 0) {
        return 3;
      }
      local_40 = 0x10;
    }
    iVar3 = ((int (*)())_LFSParserParseRegister)(param_1,local_20,&local_34);
    if ((iVar3 == 0) && (iVar3 = 5, local_20[0] == 1)) {
      iVar3 = 0x17;
      iVar2 = (uint)*(byte *)(param_1 + 0x19) * 0x10 + param_1 + local_34;
      if (*(char *)(iVar2 + 0x24) == '\0') {
        *(undefined1 *)(iVar2 + 0x24) = 1;
        iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_140);
        iVar3 = 8;
        if (((((iVar2 != 0) && (iVar3 = 10, local_140[0] == ',')) &&
             (iVar3 = ((int (*)())_LFSParserParseRegister)(param_1,&local_3c,&local_38), iVar3 == 0)) &&
            ((local_3c == 1 || (iVar3 = 5, local_3c == 5)))) &&
           ((*(char *)(param_1 + 0x19) != '\x02' || (iVar3 = 0x18, local_3c != 1)))) {
          iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_140);
          iVar3 = 8;
          if ((iVar2 != 0) && (iVar3 = 0xe, local_140[0] == '.')) {
            iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_140);
            iVar3 = 8;
            if (iVar2 != 0) {
              iVar2 = _memcmp(local_140,"str",4);
              if (iVar2 == 0) {
                iVar2 = 0;
              }
              else {
                iVar3 = _memcmp(local_140,"stq",4);
                iVar2 = 0x100;
                if (iVar3 != 0) {
                  iVar3 = _memcmp(local_140,"str_dr",7);
                  iVar2 = 0x200;
                  if (iVar3 != 0) {
                    iVar2 = _memcmp(local_140,"stq_dq",7);
                    if (iVar2 != 0) {
                      return 0xe;
                    }
                    iVar2 = 0x300;
                  }
                }
              }
              local_30 = iVar2;
              if (local_3c == 5) {
                uVar4 = 0;
                do {
                  if (uVar4 == 0) {
                    piVar5 = *(int **)(*(int *)(param_1 + 0x14) + 4);
                  }
                  else if (uVar4 == 1) {
                    piVar5 = *(int **)(*(int *)(param_1 + 0x14) + 0xc);
                  }
                  for (iVar2 = *piVar5; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
                    if ((*(int *)(iVar2 + 8) == 5) && (*(int *)(iVar2 + 0xc) == local_38)) {
                      if (local_30 == 0) {
                        iVar3 = *(int *)(iVar2 + 0x14);
                        if ((iVar3 != 0x200) && (iVar3 != 0)) {
                          return 0x19;
                        }
                      }
                      else {
                        iVar3 = *(int *)(iVar2 + 0x14);
                      }
                      if (((local_30 == 0x100) && (iVar3 != 0x300)) && (iVar3 != 0x100)) {
                        return 0x19;
                      }
                      if (((iVar3 == 0) && (local_30 != 0x200)) && (local_30 != 0)) {
                        return 0x19;
                      }
                      if (((iVar3 == 0x100) && (local_30 != 0x300)) && (local_30 != 0x100)) {
                        return 0x19;
                      }
                    }
                  }
                  uVar4 = uVar4 + 1;
                } while (uVar4 < 2);
              }
              cVar1 = *(char *)(param_1 + 0x19);
              if (((cVar1 == '\x03') && (local_3c == 1)) &&
                 ((local_30 == 0x100 || (local_30 == 0x300)))) {
                iVar3 = 0x1a;
              }
              else {
                if (cVar1 == '\x02') {
                  _LFSStreamAddPreliminaryPassRegisterInit
                            (*(undefined4 *)(param_1 + 0x14),&local_40);
                }
                else {
                  if (cVar1 != '\x03') {
                    return 0xc;
                  }
                  _LFSStreamAddOutputPassRegisterInit(*(undefined4 *)(param_1 + 0x14),&local_40);
                }
                iVar3 = 0;
              }
            }
          }
        }
      }
    }
  }
  return iVar3;
}

/* _LFSParserParseConstantBinding @ 0xd0a68 (748 bytes) */
int _LFSParserParseConstantBinding(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  char local_160 [256];
  int local_60;
  int local_5c;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  float local_40 [4];
  longlong local_30;
  longlong local_28;
  int local_20 [5];
  
  local_60 = 0;
  local_50 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  iVar1 = ((int (*)())_LFSParserParseRegister)(param_1,local_20,&local_5c);
  if ((iVar1 == 0) && (iVar1 = 5, local_20[0] == 2)) {
    for (iVar1 = *(int *)**(undefined4 **)(param_1 + 0x14); iVar1 != 0;
        iVar1 = *(int *)(iVar1 + 0x4c)) {
      if (*(int *)(iVar1 + 8) == local_5c) {
        return 0x11;
      }
    }
    iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_160);
    iVar1 = 8;
    if ((iVar2 != 0) && (iVar1 = 0xf, local_160[0] == '=')) {
      iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_160);
      iVar1 = 8;
      if (iVar2 != 0) {
        iVar1 = _memcmp(local_160,"program",8);
        if (iVar1 == 0) {
          iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_160);
          if (iVar1 == 0) {
            return 8;
          }
          if (local_160[0] != '.') {
            return 0xf;
          }
          iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_160);
          if (iVar1 == 0) {
            return 8;
          }
          iVar1 = _memcmp(local_160,"env",4);
          if (iVar1 == 0) {
            local_60 = iVar1;
            iVar1 = ((int (*)())_LFSParserParseArray)(param_1,local_40);
            if (iVar1 != 0) {
              return iVar1;
            }
            if (DOUBLE_00108d80 <= (double)local_40[0]) {
              local_58 = (uint)(int)((double)local_40[0] - DOUBLE_00108d80);
              local_28 = (longlong)(int)local_58;
              local_58 = local_58 ^ 0x80000000;
            }
            else {
              local_58 = (uint)(int)local_40[0];
              local_30 = (longlong)(int)local_58;
            }
          }
          else {
            iVar1 = _memcmp(local_160,"local",6);
            if (iVar1 != 0) {
              return 0xf;
            }
            local_60 = 2;
            iVar1 = ((int (*)())_LFSParserParseArray)(param_1,local_40);
            if (iVar1 != 0) {
              return iVar1;
            }
            if (DOUBLE_00108d80 <= (double)local_40[0]) {
              local_50 = (uint)(int)((double)local_40[0] - DOUBLE_00108d80);
              local_30 = (longlong)(int)local_50;
              local_50 = local_50 ^ 0x80000000;
            }
            else {
              local_50 = (uint)(int)local_40[0];
              local_28 = (longlong)(int)local_50;
            }
          }
        }
        else {
          iVar1 = _memcmp(local_160,"{",2);
          if (iVar1 != 0) {
            return 0xf;
          }
          local_60 = 1;
          local_20[1] = 4;
          local_40[0] = 0.0;
          local_40[3] = 0.0;
          local_40[2] = 0.0;
          local_40[1] = 0.0;
          ((int (*)())_LFSParserGetScalars)(param_1,local_40,local_20 + 1);
          iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_160);
          if (iVar1 == 0) {
            return 8;
          }
          if (local_160[0] != '}') {
            return 0xf;
          }
          local_54 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 0x14) + 8);
          _LFSStreamAddConstant(*(int *)(param_1 + 0x14),local_40);
        }
        _LFSStreamAddConstantBinding(*(undefined4 *)(param_1 + 0x14),&local_60);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}

/* _LFSParserParseInstruction @ 0xd0d54 (516 bytes) */
int _LFSParserParseInstruction(param_1)
  int param_1;
{
  int iVar1;
  char local_120 [256];
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = *(undefined4 *)(param_1 + 0xc);
  local_1c = *(undefined4 *)(param_1 + 0x10);
  iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_120);
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = _memcmp(local_120,"StartConstants",0xf);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x3a) = 1;
    *(undefined1 *)(param_1 + 0x19) = 1;
    goto LAB_000d0f14;
  }
  iVar1 = _memcmp(local_120,"EndConstants",0xd);
  if (iVar1 != 0) {
    iVar1 = _memcmp(local_120,"StartPrelimPass",0x10);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x19) = 2;
      *(undefined1 *)(param_1 + 0x4a) = 1;
      goto LAB_000d0f14;
    }
    iVar1 = _memcmp(local_120,"EndPass",8);
    if (iVar1 != 0) {
      iVar1 = _memcmp(local_120,"StartOutputPass",0x10);
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x19) = 3;
        *(undefined1 *)(param_1 + 0x5a) = 1;
      }
      else {
        iVar1 = _memcmp(local_120,"CONSTANT",9);
        if (iVar1 == 0) {
          if (*(char *)(param_1 + 0x19) != '\x01') {
            return 0xd;
          }
          iVar1 = ((int (*)())_LFSParserParseConstantBinding)(param_1);
        }
        else {
          iVar1 = _memcmp(local_120,"PassTexCoord",0xd);
          if ((iVar1 == 0) || (iVar1 = _memcmp(local_120,"SampleMap",10), iVar1 == 0)) {
            *(undefined4 *)(param_1 + 0x10) = local_1c;
            *(undefined4 *)(param_1 + 0xc) = local_20;
            iVar1 = ((int (*)())_LFSParserParseRegisterInit)(param_1);
          }
          else {
            *(undefined4 *)(param_1 + 0x10) = local_1c;
            *(undefined4 *)(param_1 + 0xc) = local_20;
            iVar1 = ((int (*)())_LFSParserParseOperation)(param_1);
          }
        }
        if (iVar1 != 0) {
          return iVar1;
        }
      }
      goto LAB_000d0f14;
    }
  }
  *(undefined1 *)(param_1 + 0x19) = 0;
LAB_000d0f14:
  iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_120);
  if (iVar1 == 0) {
    return 8;
  }
  if (local_120[0] == ';') {
    return 0;
  }
  return 2;
}

/* _LFSParserParseVersion @ 0xd0f58 (160 bytes) */
int _LFSParserParseVersion(param_1)
  undefined4 param_1;
{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  char local_120 [16];
  char local_110 [256];
  
  uVar4 = 0;
  pcVar3 = local_110;
  do {
    iVar1 = ((int (*)())_LFSParserGetCharacter)(param_1,local_120,0);
    if (iVar1 != 0) {
      return 8;
    }
    *pcVar3 = local_120[0];
    if (local_120[0] != ' ') {
      pcVar3 = pcVar3 + 1;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0xc);
  iVar1 = _memcmp(local_110,"!!ATIfs1.0",10);
  uVar2 = 0x1f;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}

/* _LFSParserParse @ 0xd0ff8 (136 bytes) */
int _LFSParserParse(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = ((int (*)())_LFSParserParseVersion)(param_1);
  while (iVar1 == 0) {
    iVar1 = ((int (*)())_LFSParserParseInstruction)(param_1);
  }
  if ((iVar1 == 1) &&
     ((*(char *)(param_1 + 0x4a) == '\0' ||
      (iVar1 = 0x15, *(int *)(*(int *)(*(int *)(param_1 + 0x14) + 8) + 8) != 0)))) {
    iVar1 = 0;
  }
  else {
    ((void (*)())_LFSParserBuildErrorString)(param_1,iVar1);
  }
  return iVar1;
}

/* _LFSParserBuildErrorString @ 0xd1080 (580 bytes) */
void _LFSParserBuildErrorString(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_120 [256];
  undefined4 local_20;
  undefined4 local_1c;
  
  switch(param_2) {
  default:
    pcVar2 = "";
    break;
  case 1:
    pcVar2 = "end of stream";
    break;
  case 2:
    pcVar2 = "missing semicolon";
    break;
  case 3:
    pcVar2 = "unrecognised instruction";
    break;
  case 4:
    pcVar2 = "invalid program header";
    break;
  case 5:
    pcVar2 = "invalid register";
    break;
  case 6:
    pcVar2 = "malformed destination mask";
    break;
  case 7:
    pcVar2 = "malformed destination modifier";
    break;
  case 8:
    pcVar2 = "unexpected end of file";
    break;
  case 9:
    pcVar2 = "invalid identifier name";
    break;
  case 10:
    pcVar2 = "missing comma";
    break;
  case 0xb:
    pcVar2 = "malformed source modifier";
    break;
  case 0xc:
    pcVar2 = "operation outside of pass block";
    break;
  case 0xd:
    pcVar2 = "constant binding outside of constant block";
    break;
  case 0xe:
    pcVar2 = "malformed source selector";
    break;
  case 0xf:
    pcVar2 = "malformed constant binding";
    break;
  case 0x10:
    pcVar2 = "malformed array specifier";
    break;
  case 0x11:
    pcVar2 = "SEMANTIC RESTRICTION #1 - constant already bound";
    break;
  case 0x12:
    pcVar2 = "SEMANTIC RESTRICTION #1 - constant not bound";
    break;
  case 0x13:
    pcVar2 = "SEMANTIC RESTRICTION #2 - greater than 2 constant arguments";
    break;
  case 0x14:
    pcVar2 = "SEMANTIC RESTRICTION #3 - color arguments used in non output pass";
    break;
  case 0x15:
    pcVar2 = "SEMANTIC RESTRICTION #4 - no alu operations in preliminary pass";
    break;
  case 0x16:
    pcVar2 = "SEMANTIC RESTRICTION #5 - excess color/alpha pairs in pass";
    break;
  case 0x17:
    pcVar2 = "SEMANTIC RESTRICTION #6 - destination register overwritten in same pass";
    break;
  case 0x18:
    pcVar2 = "SEMANTIC RESTRICTION #7 - register init with register argument in preliminary pass";
    break;
  case 0x19:
    pcVar2 = "SEMANTIC RESTRICTION #8 - same texture coordinate with selector exists";
    break;
  case 0x1a:
    pcVar2 = "SEMANTIC RESTRICTION #9 - this selector is not allowed in the output pass";
    break;
  case 0x1b:
    pcVar2 = "SEMANTIC RESTRICTION #10 - no writemask is allowed for this instruction";
    break;
  case 0x1c:
    pcVar2 = "SEMANTIC RESTRICTION #11 - alpha component cannot be read for secondary color";
    break;
  case 0x1d:
    pcVar2 = "SEMANTIC RESTRICTION #12 - register number exceeds supported";
    break;
  case 0x1e:
    pcVar2 = "SEMANTIC RESTRICTION #13 - texture unit number exceeds supported";
    break;
  case 0x1f:
    pcVar2 = "missing or invalid version token";
  }
  local_20 = *(undefined4 *)(param_1 + 0xc);
  local_1c = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x45c);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x460);
  iVar1 = ((int (*)())_LFSParserGetPart)(param_1,auStack_120);
  if (iVar1 == 0) {
    _sprintf((char *)(param_1 + 0x5c),"%s",pcVar2);
  }
  else {
    _sprintf((char *)(param_1 + 0x5c),"%s (hint: \'%s\')",pcVar2,auStack_120);
  }
  *(undefined4 *)(param_1 + 0xc) = local_20;
  *(undefined4 *)(param_1 + 0x10) = local_1c;
  return;
}

/* _LFSStreamChunkCreate @ 0xd1344 (12 bytes) */
int _LFSStreamChunkCreate()
{
  undefined4 uVar1;
  
  uVar1 = _calloc(0x50,1);
  return uVar1;
}

/* _LFSStreamChunkCreateFromChunk @ 0xd1350 (64 bytes) */
int _LFSStreamChunkCreateFromChunk(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())_LFSStreamChunkCreate)();
  _memcpy(uVar1,param_1,0x50);
  return uVar1;
}

/* _LFSStreamChunkGetStream @ 0xd1394 (408 bytes) */
int _LFSStreamChunkGetStream(param_1, param_2, param_3, param_4)
  byte *param_1;
  undefined4 param_2;
  undefined4 *param_3;
  int param_4;
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_20 [8];
  
  *param_3 = 1;
  bVar1 = *param_1;
  local_20[0] = 0;
  if (bVar1 != 2) {
    if (2 < bVar1) {
      if (bVar1 != 3) {
        if (bVar1 != 4) {
          return 0;
        }
        *param_3 = 4;
        _memmove(local_20,param_1 + param_4 * 4 + 4,4);
        return local_20[0];
      }
      uVar4 = *(uint *)(param_1 + 4);
      uVar5 = *(int *)(param_1 + 8) << 0x14 | uVar4 | 0x60000000;
      if (uVar4 == 1) {
        iVar3 = *(int *)(param_1 + 0x10);
      }
      else if (uVar4 == 0) {
        iVar3 = *(int *)(param_1 + 0xc);
      }
      else {
        if (uVar4 != 2) {
          return uVar5;
        }
        iVar3 = *(int *)(param_1 + 0x14);
      }
      return uVar5 | iVar3 << 0xc;
    }
    if (bVar1 != 1) {
      return 0;
    }
    return *(int *)(param_1 + 0xc) << 0x14 | *(int *)(param_1 + 0x10) << 0xc |
           *(uint *)(param_1 + 0x14) | *(uint *)(param_1 + 4) | *(uint *)(param_1 + 8) | 0x20000000;
  }
  uVar4 = *(uint *)(param_1 + 4);
  uVar2 = 2;
  if ((uVar4 != 0) && (uVar2 = 3, 0x500 < uVar4)) {
    if (0xa00 < uVar4) goto LAB_000d1440;
    uVar2 = 4;
  }
  *param_3 = uVar2;
LAB_000d1440:
  if (param_4 == 0) {
    uVar4 = *(int *)(param_1 + 0xc) << 0x14 | *(uint *)(param_1 + 0x10) | *(uint *)(param_1 + 0x14)
            | *(uint *)(param_1 + 4) | 0x30000000;
  }
  else {
    iVar3 = param_4 + -1;
    uVar4 = *(int *)(param_1 + iVar3 * 0x10 + 0x1c) << 0x14 |
            *(uint *)(param_1 + iVar3 * 0x10 + 0x20) | *(uint *)(param_1 + iVar3 * 0x10 + 0x24) |
            *(uint *)(param_1 + iVar3 * 0x10 + 0x18) | 0x40000000;
  }
  return uVar4;
}

/* _LFSStreamChunkCompare @ 0xd152c (124 bytes) */
int _LFSStreamChunkCompare(param_1, param_2)
  char *param_1;
  char *param_2;
{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if (*param_1 == *param_2) {
    iVar1 = _memcmp(param_1 + 4,param_2 + 4,0x14);
    bVar2 = true;
    if (iVar1 == 0) {
      iVar1 = _memcmp(param_1 + 4,param_2 + 4,0x44);
      bVar2 = iVar1 != 0;
    }
  }
  return bVar2;
}

/* _LFSStreamChunkOutputDebugInfo @ 0xd15a8 (684 bytes) */
void _LFSStreamChunkOutputDebugInfo(param_1)
  byte *param_1;
{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  _puts("LFSStreamChunk {");
  bVar1 = *param_1;
  if (bVar1 == 2) {
    _puts("      operation {");
    _printf("         type = 0x%lx;\n",*(undefined4 *)(param_1 + 4));
    uVar8 = 0;
    pbVar10 = param_1;
    do {
      uVar9 = uVar8 + 1;
      _printf("         sourcevar[%i] {\n",uVar8);
      _printf("            registertype = 0x%lx;\n",*(undefined4 *)(pbVar10 + 0x18));
      _printf("            registerindex = %i;\n",*(undefined4 *)(pbVar10 + 0x1c));
      _printf("            replicate = 0x%lx;\n",*(undefined4 *)(pbVar10 + 0x20));
      _printf("            modifiers = 0x%lx;\n",*(undefined4 *)(pbVar10 + 0x24));
      _puts("         };");
      pbVar10 = pbVar10 + 0x10;
      uVar8 = uVar9;
    } while (uVar9 < 3);
    _puts("         destvar {");
    _printf("            registertype = 0x%lx;\n",*(undefined4 *)(param_1 + 8));
    _printf("            registerindex = %i;\n",*(undefined4 *)(param_1 + 0xc));
    _printf("            mask = 0x%lx;\n",*(undefined4 *)(param_1 + 0x10));
    _printf("            modifiers = 0x%lx;\n",*(undefined4 *)(param_1 + 0x14));
    _puts("         };");
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 != 1) goto LAB_000d1838;
      _puts("      registerinit {");
      _printf("         type = 0x%lx;\n",*(undefined4 *)(param_1 + 4));
      _puts("         source {");
      _printf("            registertype = 0x%lx;\n",*(undefined4 *)(param_1 + 8));
      _printf("            registerindex = %i;\n",*(undefined4 *)(param_1 + 0xc));
      _puts("         };");
      _printf("         destregisterindex = %i;\n",*(undefined4 *)(param_1 + 0x10));
      uVar7 = *(undefined4 *)(param_1 + 0x14);
      pcVar6 = "         selector = 0x%lx;\n";
    }
    else {
      if (bVar1 != 3) {
        if (bVar1 == 4) {
          dVar11 = (double)*(float *)(param_1 + 4);
          dVar13 = (double)*(float *)(param_1 + 8);
          dVar12 = (double)*(float *)(param_1 + 0xc);
          local_30 = (undefined4)((ulonglong)(double)*(float *)(param_1 + 0x10) >> 0x20);
          uVar7 = local_30;
          local_30 = (undefined4)((ulonglong)dVar11 >> 0x20);
          uVar2 = local_30;
          uStack_2c = SUB84(dVar11,0);
          uVar4 = uStack_2c;
          local_30 = (undefined4)((ulonglong)dVar13 >> 0x20);
          uVar3 = local_30;
          uStack_2c = SUB84(dVar13,0);
          uVar5 = uStack_2c;
          local_30 = (undefined4)((ulonglong)dVar12 >> 0x20);
          uStack_2c = SUB84(dVar12,0);
          _printf("      constant = { %f, %f, %f, %f }\n;",dVar11,dVar13,dVar12,
                  (double)*(float *)(param_1 + 0x10),uVar2,uVar4,uVar3,uVar5,local_30,uStack_2c,
                  uVar7);
        }
        goto LAB_000d1838;
      }
      _puts("      constantbinding {");
      _printf("         type = 0x%lx;\n",*(undefined4 *)(param_1 + 4));
      _printf("         constantindex = %i;\n",*(undefined4 *)(param_1 + 8));
      _printf("         envparameterindex = %i;\n",*(undefined4 *)(param_1 + 0xc));
      _printf("         inlineconstantindex = %i;\n",*(undefined4 *)(param_1 + 0x10));
      uVar7 = *(undefined4 *)(param_1 + 0x14);
      pcVar6 = "         localparameterindex = %i;\n";
    }
    _printf(pcVar6,uVar7);
  }
  _puts("      };");
LAB_000d1838:
  _puts("   };");
  return;
}

