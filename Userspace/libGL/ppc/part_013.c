#include "decls.h"

/* _glGetUniformfvARB @ 0x92f41f3c (140 bytes) */
int _glGetUniformfvARB(programObj, location, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 programObj;
  undefined4 location;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x274])(*glContext,programObj,location,params);
  return;
}

/* _glGetUniformivARB @ 0x92f41fc8 (140 bytes) */
int _glGetUniformivARB(programObj, location, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 programObj;
  undefined4 location;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x275])(*glContext,programObj,location,params);
  return;
}

/* _glGetShaderSourceARB @ 0x92f42054 (148 bytes) */
int _glGetShaderSourceARB(obj, maxLength, length, source, fwdReg5, fwdReg6, fwdReg7)
  undefined4 obj;
  undefined4 maxLength;
  undefined4 length;
  undefined4 source;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x276])(*glContext,obj,maxLength,length,source);
  return;
}

/* _glBindAttribLocationARB @ 0x92f420e8 (140 bytes) */
int _glBindAttribLocationARB(programObj, indexArg, name, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 programObj;
  undefined4 indexArg;
  undefined4 name;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x277])(*glContext,programObj,indexArg,name);
  return;
}

/* _glGetActiveAttribARB @ 0x92f42174 (172 bytes) */
int _glGetActiveAttribARB(programObj, indexArg, maxLength, length, size, type, name)
  undefined4 programObj;
  undefined4 indexArg;
  undefined4 maxLength;
  undefined4 length;
  undefined4 size;
  undefined4 type;
  undefined4 name;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x278])(*glContext,programObj,indexArg,maxLength,length,size,type,name);
  return;
}

/* _glGetAttribLocationARB @ 0x92f42220 (132 bytes) */
int _glGetAttribLocationARB(programObj, name, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 programObj;
  undefined4 name;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x279])(*glContext,programObj,name);
  return;
}

/* _glDrawBuffersARB @ 0x92f422a4 (132 bytes) */
int _glDrawBuffersARB(n, bufs, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 n;
  undefined4 bufs;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x28f])(*glContext,n,bufs);
  return;
}

/* _glLockArraysEXT @ 0x92f42328 (132 bytes) */
int _glLockArraysEXT(first, count, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 first;
  undefined4 count;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x154])(*glContext,first,count);
  return;
}

/* _glUnlockArraysEXT @ 0x92f423ac (112 bytes) */
int _glUnlockArraysEXT()
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffb0);
  }
                    
                    
  (*(code *)glContext[0x155])(*glContext);
  return;
}

/* _glActiveStencilFaceEXT @ 0x92f4241c (124 bytes) */
int _glActiveStencilFaceEXT(face, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 face;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x24a])(*glContext,face);
  return;
}

/* _glDepthBoundsEXT @ 0x92f42498 (144 bytes) */
void _glDepthBoundsEXT(double zmin,double zmax)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x28e])(zmin,zmax,*glContext);
  return;
}

/* _glColorTableEXT @ 0x92f42528 (164 bytes) */
int _glColorTableEXT(target, internalFormat, width, format, type, table, fwdReg7)
  undefined4 target;
  undefined4 internalFormat;
  undefined4 width;
  undefined4 format;
  undefined4 type;
  undefined4 table;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x197])(*glContext,target,internalFormat,width,format,type,table);
  return;
}

/* _glColorSubTableEXT @ 0x92f425cc (164 bytes) */
int _glColorSubTableEXT(target, start, count, format, type, data, fwdReg7)
  undefined4 target;
  undefined4 start;
  undefined4 count;
  undefined4 format;
  undefined4 type;
  undefined4 data;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x19e])(*glContext,target,start,count,format,type,data);
  return;
}

/* _glGetColorTableEXT @ 0x92f42670 (148 bytes) */
int _glGetColorTableEXT(target, format, type, data, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 format;
  undefined4 type;
  undefined4 data;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x19b])(*glContext,target,format,type,data);
  return;
}

/* _glGetColorTableParameterfvEXT @ 0x92f42704 (140 bytes) */
int _glGetColorTableParameterfvEXT(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 pname;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x19c])(*glContext,target,pname,params);
  return;
}

/* _glGetColorTableParameterivEXT @ 0x92f42790 (140 bytes) */
int _glGetColorTableParameterivEXT(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 pname;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x19d])(*glContext,target,pname,params);
  return;
}

/* _glSecondaryColor3bEXT @ 0x92f4281c (140 bytes) */
int _glSecondaryColor3bEXT(red, green, blue, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x183])(*glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3bvEXT @ 0x92f428a8 (124 bytes) */
int _glSecondaryColor3bvEXT(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x184])(*glContext,v);
  return;
}

/* _glSecondaryColor3dEXT @ 0x92f42924 (160 bytes) */
void _glSecondaryColor3dEXT(double red,double green,double blue)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x185])(red,green,blue,*glContext);
  return;
}

/* _glSecondaryColor3dvEXT @ 0x92f429c4 (124 bytes) */
int _glSecondaryColor3dvEXT(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x186])(*glContext,v);
  return;
}

/* _glSecondaryColor3fEXT @ 0x92f42a40 (160 bytes) */
void _glSecondaryColor3fEXT(double red,double green,double blue)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x187])(red,green,blue,*glContext);
  return;
}

/* _glSecondaryColor3fvEXT @ 0x92f42ae0 (124 bytes) */
int _glSecondaryColor3fvEXT(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x188])(*glContext,v);
  return;
}

/* _glSecondaryColor3iEXT @ 0x92f42b5c (140 bytes) */
int _glSecondaryColor3iEXT(red, green, blue, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x189])(*glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3ivEXT @ 0x92f42be8 (124 bytes) */
int _glSecondaryColor3ivEXT(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x18a])(*glContext,v);
  return;
}

/* _glSecondaryColor3sEXT @ 0x92f42c64 (140 bytes) */
int _glSecondaryColor3sEXT(red, green, blue, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x18b])(*glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3svEXT @ 0x92f42cf0 (124 bytes) */
int _glSecondaryColor3svEXT(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x18c])(*glContext,v);
  return;
}

/* _glSecondaryColor3ubEXT @ 0x92f42d6c (140 bytes) */
int _glSecondaryColor3ubEXT(red, green, blue, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x18d])(*glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3ubvEXT @ 0x92f42df8 (124 bytes) */
int _glSecondaryColor3ubvEXT(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x18e])(*glContext,v);
  return;
}

/* _glSecondaryColor3uiEXT @ 0x92f42e74 (140 bytes) */
int _glSecondaryColor3uiEXT(red, green, blue, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[399])(*glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3uivEXT @ 0x92f42f00 (124 bytes) */
int _glSecondaryColor3uivEXT(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[400])(*glContext,v);
  return;
}

/* _glSecondaryColor3usEXT @ 0x92f42f7c (140 bytes) */
int _glSecondaryColor3usEXT(red, green, blue, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x191])(*glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3usvEXT @ 0x92f43008 (124 bytes) */
int _glSecondaryColor3usvEXT(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x192])(*glContext,v);
  return;
}

/* _glSecondaryColorPointerEXT @ 0x92f43084 (148 bytes) */
int _glSecondaryColorPointerEXT(size, type, stride, pointer, fwdReg5, fwdReg6, fwdReg7)
  undefined4 size;
  undefined4 type;
  undefined4 stride;
  undefined4 pointer;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x193])(*glContext,size,type,stride,pointer);
  return;
}

/* _glFogCoordfEXT @ 0x92f43118 (128 bytes) */
void _glFogCoordfEXT(double coord)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x221])(coord,*glContext);
  return;
}

/* _glFogCoordfvEXT @ 0x92f43198 (124 bytes) */
int _glFogCoordfvEXT(coord, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 coord;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x222])(*glContext,coord);
  return;
}

/* _glFogCoorddEXT @ 0x92f43214 (128 bytes) */
void _glFogCoorddEXT(double coord)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x223])(coord,*glContext);
  return;
}

/* _glFogCoorddvEXT @ 0x92f43294 (124 bytes) */
int _glFogCoorddvEXT(coord, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 coord;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x224])(*glContext,coord);
  return;
}

/* _glFogCoordPointerEXT @ 0x92f43310 (140 bytes) */
int _glFogCoordPointerEXT(type, stride, pointer, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 type;
  undefined4 stride;
  undefined4 pointer;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x225])(*glContext,type,stride,pointer);
  return;
}

/* _glDrawRangeElementsEXT @ 0x92f4339c (164 bytes) */
int _glDrawRangeElementsEXT(mode, start, end, count, type, indices, fwdReg7)
  undefined4 mode;
  undefined4 start;
  undefined4 end;
  undefined4 count;
  undefined4 type;
  undefined4 indices;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x196])(*glContext,mode,start,end,count,type,indices);
  return;
}

/* _glBlendFuncSeparateEXT @ 0x92f43440 (148 bytes) */
int _glBlendFuncSeparateEXT(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha, fwdReg5, fwdReg6, fwdReg7)
  undefined4 sfactorRGB;
  undefined4 dfactorRGB;
  undefined4 sfactorAlpha;
  undefined4 dfactorAlpha;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x151])(*glContext,sfactorRGB,dfactorRGB,sfactorAlpha,dfactorAlpha);
  return;
}

/* _glMultiDrawArraysEXT @ 0x92f434d4 (148 bytes) */
int _glMultiDrawArraysEXT(mode, first, count, primcount, fwdReg5, fwdReg6, fwdReg7)
  undefined4 mode;
  undefined4 first;
  undefined4 count;
  undefined4 primcount;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x238])(*glContext,mode,first,count,primcount);
  return;
}

/* _glMultiDrawElementsEXT @ 0x92f43568 (156 bytes) */
int _glMultiDrawElementsEXT(mode, count, type, indices, primcount, fwdReg6, fwdReg7)
  undefined4 mode;
  undefined4 count;
  undefined4 type;
  undefined4 indices;
  undefined4 primcount;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x239])(*glContext,mode,count,type,indices,primcount);
  return;
}

/* _glBlendColorEXT @ 0x92f43604 (160 bytes) */
void _glBlendColorEXT(double red,double green,double blue,double alpha)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x152])(red,green,blue,alpha,*glContext);
  return;
}

/* _glBlendEquationEXT @ 0x92f436a4 (124 bytes) */
int _glBlendEquationEXT(mode, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 mode;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x153])(*glContext,mode);
  return;
}

/* _glBlendEquationSeparateEXT @ 0x92f43720 (132 bytes) */
int _glBlendEquationSeparateEXT(modeRGB, modeAlpha, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 modeRGB;
  undefined4 modeAlpha;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1cb])(*glContext,modeRGB,modeAlpha);
  return;
}

/* _glIsRenderbufferEXT @ 0x92f437a4 (128 bytes) */
int _glIsRenderbufferEXT(renderbuffer, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 renderbuffer;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffb0);
  }
  return (*(code *)glContext[0x29a])(*glContext,renderbuffer);
}

/* _glBindRenderbufferEXT @ 0x92f43824 (132 bytes) */
int _glBindRenderbufferEXT(target, renderbuffer, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 renderbuffer;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x29b])(*glContext,target,renderbuffer);
  return;
}

/* _glDeleteRenderbuffersEXT @ 0x92f438a8 (132 bytes) */
int _glDeleteRenderbuffersEXT(n, renderbuffers, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 n;
  undefined4 renderbuffers;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x29c])(*glContext,n,renderbuffers);
  return;
}

/* _glGenRenderbuffersEXT @ 0x92f4392c (132 bytes) */
int _glGenRenderbuffersEXT(n, renderbuffers, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 n;
  undefined4 renderbuffers;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x29d])(*glContext,n,renderbuffers);
  return;
}

/* _glRenderbufferStorageEXT @ 0x92f439b0 (148 bytes) */
int _glRenderbufferStorageEXT(target, internalformat, width, height, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x29e])(*glContext,target,internalformat,width,height);
  return;
}

/* _glGetRenderbufferParameterivEXT @ 0x92f43a44 (140 bytes) */
int _glGetRenderbufferParameterivEXT(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 pname;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x29f])(*glContext,target,pname,params);
  return;
}

/* _glIsFramebufferEXT @ 0x92f43ad0 (128 bytes) */
int _glIsFramebufferEXT(framebuffer, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 framebuffer;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffb0);
  }
  return (*(code *)glContext[0x2a0])(*glContext,framebuffer);
}

/* _glBindFramebufferEXT @ 0x92f43b50 (132 bytes) */
int _glBindFramebufferEXT(target, framebuffer, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 framebuffer;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x2a1])(*glContext,target,framebuffer);
  return;
}

/* _glDeleteFramebuffersEXT @ 0x92f43bd4 (132 bytes) */
int _glDeleteFramebuffersEXT(n, framebuffers, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 n;
  undefined4 framebuffers;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x2a2])(*glContext,n,framebuffers);
  return;
}

/* _glGenFramebuffersEXT @ 0x92f43c58 (132 bytes) */
int _glGenFramebuffersEXT(n, framebuffers, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 n;
  undefined4 framebuffers;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x2a3])(*glContext,n,framebuffers);
  return;
}

/* _glCheckFramebufferStatusEXT @ 0x92f43cdc (124 bytes) */
int _glCheckFramebufferStatusEXT(target, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x2a4])(*glContext,target);
  return;
}

/* _glFramebufferTexture1DEXT @ 0x92f43d58 (156 bytes) */
int _glFramebufferTexture1DEXT(target, attachment, textarget, texture, level, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 attachment;
  undefined4 textarget;
  undefined4 texture;
  undefined4 level;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x2a5])(*glContext,target,attachment,textarget,texture,level);
  return;
}

/* _glFramebufferTexture2DEXT @ 0x92f43df4 (156 bytes) */
int _glFramebufferTexture2DEXT(target, attachment, textarget, texture, level, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 attachment;
  undefined4 textarget;
  undefined4 texture;
  undefined4 level;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x2a6])(*glContext,target,attachment,textarget,texture,level);
  return;
}

/* _glFramebufferTexture3DEXT @ 0x92f43e90 (164 bytes) */
int _glFramebufferTexture3DEXT(target, attachment, textarget, texture, level, zoffset, fwdReg7)
  undefined4 target;
  undefined4 attachment;
  undefined4 textarget;
  undefined4 texture;
  undefined4 level;
  undefined4 zoffset;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x2a7])(*glContext,target,attachment,textarget,texture,level,zoffset);
  return;
}

/* _glFramebufferRenderbufferEXT @ 0x92f43f34 (148 bytes) */
int _glFramebufferRenderbufferEXT(target, attachment, renderbuffertarget, renderbuffer, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 attachment;
  undefined4 renderbuffertarget;
  undefined4 renderbuffer;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x2a8])(*glContext,target,attachment,renderbuffertarget,renderbuffer);
  return;
}

