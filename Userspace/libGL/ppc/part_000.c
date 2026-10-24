#include "decls.h"

/* _CGLSetCurrentContext @ 0x92f279e4 (96 bytes) */
int _CGLSetCurrentContext(ctx)
  void *ctx;
{
  if (ctx == (void *)0x0) {
    ctx = _gll_noop;
  }
  *(undefined1 **)((int)ctx + 0xab0) = &STACKARG(0xffffffb0);
  _pthread_setspecific(_gll_pkey,ctx);
  _gll_cc = ctx;
  return 0;
}

/* dyld_stub_binding_helper @ 0x92f27a44 (48 bytes) */
int dyld_stub_binding_helper()
{
                    
                    
  (*dyld_lazy_symbol_binding_entry_point)();
  return;
}

/* _CGLGetCurrentContext @ 0x92f27a74 (168 bytes) */
int _CGLGetCurrentContext()
{
  void *context;
  void *result;
  
  result = (void *)0x0;
  if (_gll_cc != (void *)0x0) {
    context = _gll_cc;
    if (*(undefined1 **)((int)_gll_cc + 0xab0) != &STACKARG(0xffffffa0)) {
      context = _pthread_getspecific(_gll_pkey);
      result = _gll_noop;
      if (context == (void *)0x0) {
        _pthread_setspecific(_gll_pkey,_gll_noop);
        context = result;
      }
      _gll_cc = context;
      *(undefined1 **)((int)context + 0xab0) = &STACKARG(0xffffffa0);
    }
    result = (void *)0x0;
    if (context != _gll_noop) {
      result = context;
    }
  }
  return result;
}

/* _restf26 @ 0x92f27b4c (36 bytes) */
int _restf26()
{
  return;
}

/* _glGetIntegerv @ 0x92f27b70 (132 bytes) */
int _glGetIntegerv(pname, params, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 params;
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
                    
                    
  (*(code *)glContext[0x69])(*glContext,pname,params);
  return;
}

/* _glGetBooleanv @ 0x92f27bf4 (132 bytes) */
int _glGetBooleanv(pname, params, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 params;
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
                    
                    
  (*(code *)glContext[100])(*glContext,pname,params);
  return;
}

/* _glGetString @ 0x92f27c78 (124 bytes) */
int _glGetString(name, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 name;
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
                    
                    
  (*(code *)glContext[0x76])(*glContext,name);
  return;
}

/* _glViewport @ 0x92f27cf4 (148 bytes) */
int _glViewport(x, y, width, height, fwdReg5, fwdReg6, fwdReg7)
  undefined4 x;
  undefined4 y;
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
                    
                    
  (*(code *)glContext[0x150])(*glContext,x,y,width,height);
  return;
}

/* _glMatrixMode @ 0x92f27d88 (124 bytes) */
int _glMatrixMode(mode, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0xaf])(*glContext,mode);
  return;
}

/* _glLoadIdentity @ 0x92f27e04 (112 bytes) */
int _glLoadIdentity()
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
                    
                    
  (*(code *)glContext[0x9e])(*glContext);
  return;
}

/* _glShadeModel @ 0x92f27e74 (124 bytes) */
int _glShadeModel(mode, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0xfe])(*glContext,mode);
  return;
}

/* _glClearColor @ 0x92f27ef0 (160 bytes) */
void _glClearColor(double red,double green,double blue,double alpha)
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
                    
                    
  (*(code *)glContext[0xd])(red,green,blue,alpha,*glContext);
  return;
}

/* _savef26 @ 0x92f27fc0 (8 bytes) */
int _savef26()
{
  return;
}

/* _savef28 @ 0x92f27fc8 (24 bytes) */
int _savef28()
{
  return;
}

/* _glClearDepth @ 0x92f27fe0 (128 bytes) */
void _glClearDepth(double depth)
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
                    
                    
  (*(code *)glContext[0xe])(depth,*glContext);
  return;
}

/* _glEnable @ 0x92f28060 (124 bytes) */
int _glEnable(cap, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 cap;
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
                    
                    
  (*(code *)glContext[0x49])(*glContext,cap);
  return;
}

/* _glDepthFunc @ 0x92f280dc (124 bytes) */
int _glDepthFunc(func, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 func;
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
                    
                    
  (*(code *)glContext[0x3d])(*glContext,func);
  return;
}

/* _glHint @ 0x92f28158 (132 bytes) */
int _glHint(target, mode, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 mode;
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
                    
                    
  (*(code *)glContext[0x81])(*glContext,target,mode);
  return;
}

/* _glBlendFunc @ 0x92f281dc (132 bytes) */
int _glBlendFunc(sfactor, dfactor, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 sfactor;
  undefined4 dfactor;
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
                    
                    
  (*(code *)glContext[8])(*glContext,sfactor,dfactor);
  return;
}

/* _glLightfv @ 0x92f28260 (140 bytes) */
int _glLightfv(light, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 light;
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
                    
                    
  (*(code *)glContext[0x98])(*glContext,light,pname,params);
  return;
}

/* _glDisable @ 0x92f282ec (124 bytes) */
int _glDisable(cap, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 cap;
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
                    
                    
  (*(code *)glContext[0x40])(*glContext,cap);
  return;
}

/* _glClear @ 0x92f28368 (124 bytes) */
int _glClear(mask, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 mask;
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
                    
                    
  (*(code *)glContext[0xb])(*glContext,mask);
  return;
}

/* _glTranslatef @ 0x92f283e4 (160 bytes) */
void _glTranslatef(double x,double y,double z)
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
                    
                    
  (*(code *)glContext[0x136])(x,y,z,*glContext);
  return;
}

/* _glPolygonMode @ 0x92f28484 (132 bytes) */
int _glPolygonMode(face, mode, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 face;
  undefined4 mode;
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
                    
                    
  (*(code *)glContext[0xc9])(*glContext,face,mode);
  return;
}

/* _glRotatef @ 0x92f28508 (160 bytes) */
void _glRotatef(double angle,double x,double y,double z)
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
                    
                    
  (*(code *)glContext[0xf9])(angle,x,y,z,*glContext);
  return;
}

/* _glScalef @ 0x92f285a8 (160 bytes) */
void _glScalef(double x,double y,double z)
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
                    
                    
  (*(code *)glContext[0xfb])(x,y,z,*glContext);
  return;
}

/* _glMaterialfv @ 0x92f28648 (140 bytes) */
int _glMaterialfv(face, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 face;
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
                    
                    
  (*(code *)glContext[0xac])(*glContext,face,pname,params);
  return;
}

/* _glPushMatrix @ 0x92f286d4 (112 bytes) */
int _glPushMatrix()
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
                    
                    
  (*(code *)glContext[0xd3])(*glContext);
  return;
}

/* _glPopMatrix @ 0x92f28744 (112 bytes) */
int _glPopMatrix()
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
                    
                    
  (*(code *)glContext[0xce])(*glContext);
  return;
}

/* _glGenLists @ 0x92f287b4 (124 bytes) */
int _glGenLists(range, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 range;
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
                    
                    
  (*(code *)glContext[0x62])(*glContext,range);
  return;
}

/* _glNewList @ 0x92f28830 (132 bytes) */
int _glNewList(list, mode, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 list;
  undefined4 mode;
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
                    
                    
  (*(code *)glContext[0xb2])(*glContext,list,mode);
  return;
}

/* _glCullFace @ 0x92f288b4 (124 bytes) */
int _glCullFace(mode, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0x3a])(*glContext,mode);
  return;
}

/* _glLoadName @ 0x92f28930 (124 bytes) */
int _glLoadName(name, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 name;
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
                    
                    
  (*(code *)glContext[0xa1])(*glContext,name);
  return;
}

/* _glColor4f @ 0x92f289ac (160 bytes) */
void _glColor4f(double red,double green,double blue,double alpha)
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
                    
                    
  (*(code *)glContext[0x26])(red,green,blue,alpha,*glContext);
  return;
}

/* _glBegin @ 0x92f28a4c (124 bytes) */
int _glBegin(mode, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[5])(*glContext,mode);
  return;
}

/* _glVertex3d @ 0x92f28ac8 (160 bytes) */
void _glVertex3d(double x,double y,double z)
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
                    
                    
  (*(code *)glContext[0x13f])(x,y,z,*glContext);
  return;
}

/* _glEnd @ 0x92f28b68 (112 bytes) */
int _glEnd()
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
                    
                    
  (*(code *)glContext[0x4b])(*glContext);
  return;
}

/* _glLineWidth @ 0x92f28bd8 (128 bytes) */
void _glLineWidth(double width)
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
                    
                    
  (*(code *)glContext[0x9c])(width,*glContext);
  return;
}

/* _glStencilFunc @ 0x92f28c58 (140 bytes) */
int _glStencilFunc(func, ref, mask, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 func;
  undefined4 ref;
  undefined4 mask;
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
                    
                    
  (*(code *)glContext[0xff])(*glContext,func,ref,mask);
  return;
}

/* _glStencilOp @ 0x92f28ce4 (140 bytes) */
int _glStencilOp(fail, zfail, zpass, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 fail;
  undefined4 zfail;
  undefined4 zpass;
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
                    
                    
  (*(code *)glContext[0x101])(*glContext,fail,zfail,zpass);
  return;
}

/* _glColorMask @ 0x92f28d70 (148 bytes) */
int _glColorMask(red, green, blue, alpha, fwdReg5, fwdReg6, fwdReg7)
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
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
                    
                    
  (*(code *)glContext[0x32])(*glContext,red,green,blue,alpha);
  return;
}

/* _glDepthMask @ 0x92f28e04 (124 bytes) */
int _glDepthMask(flag, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 flag;
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
                    
                    
  (*(code *)glContext[0x3e])(*glContext,flag);
  return;
}

/* _glNormal3f @ 0x92f28e80 (160 bytes) */
void _glNormal3f(double nx,double ny,double nz)
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
                    
                    
  (*(code *)glContext[0xb7])(nx,ny,nz,*glContext);
  return;
}

/* _glVertex3f @ 0x92f28f20 (160 bytes) */
void _glVertex3f(double x,double y,double z)
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
                    
                    
  (*(code *)glContext[0x141])(x,y,z,*glContext);
  return;
}

/* _glEndList @ 0x92f28fc0 (112 bytes) */
int _glEndList()
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
                    
                    
  (*(code *)glContext[0x4c])(*glContext);
  return;
}

/* _glDeleteLists @ 0x92f29030 (132 bytes) */
int _glDeleteLists(list, range, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 list;
  undefined4 range;
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
                    
                    
  (*(code *)glContext[0x3b])(*glContext,list,range);
  return;
}

/* _glTranslated @ 0x92f290b4 (160 bytes) */
void _glTranslated(double x,double y,double z)
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
                    
                    
  (*(code *)glContext[0x135])(x,y,z,*glContext);
  return;
}

/* _glRotated @ 0x92f29154 (140 bytes) */
void _glRotated(double angle,double x,double y,double z)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff80);
  }
  (*(code *)glContext[0xf8])(angle,x,y,z,*glContext);
  return;
}

/* _glCallList @ 0x92f291e0 (124 bytes) */
int _glCallList(list, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 list;
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
                    
                    
  (*(code *)glContext[9])(*glContext,list);
  return;
}

/* _glReadBuffer @ 0x92f2925c (124 bytes) */
int _glReadBuffer(mode, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0xed])(*glContext,mode);
  return;
}

/* _glReadPixels @ 0x92f292d8 (172 bytes) */
int _glReadPixels(x, y, width, height, format, type, pixels)
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  undefined4 pixels;
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
                    
                    
  (*(code *)glContext[0xee])(*glContext,x,y,width,height,format,type,pixels);
  return;
}

/* _glPixelStorei @ 0x92f29384 (132 bytes) */
int _glPixelStorei(pname, param, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 param;
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
                    
                    
  (*(code *)glContext[0xc4])(*glContext,pname,param);
  return;
}

/* _glGenTextures @ 0x92f29408 (132 bytes) */
int _glGenTextures(n, textures, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 n;
  undefined4 textures;
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
                    
                    
  (*(code *)glContext[99])(*glContext,n,textures);
  return;
}

/* _glBindTexture @ 0x92f2948c (132 bytes) */
int _glBindTexture(target, texture, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 texture;
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
                    
                    
  (*(code *)glContext[6])(*glContext,target,texture);
  return;
}

/* _glTexParameteri @ 0x92f29510 (140 bytes) */
int _glTexParameteri(target, pname, param, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 pname;
  undefined4 param;
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
                    
                    
  (*(code *)glContext[0x131])(*glContext,target,pname,param);
  return;
}

/* _glTexCoord2f @ 0x92f2959c (144 bytes) */
void _glTexCoord2f(double s,double t)
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
                    
                    
  (*(code *)glContext[0x10c])(s,t,*glContext);
  return;
}

/* _glLightModeli @ 0x92f2962c (132 bytes) */
int _glLightModeli(pname, param, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 param;
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
                    
                    
  (*(code *)glContext[0x95])(*glContext,pname,param);
  return;
}

/* _glPushAttrib @ 0x92f296b0 (124 bytes) */
int _glPushAttrib(mask, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 mask;
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
                    
                    
  (*(code *)glContext[0xd1])(*glContext,mask);
  return;
}

/* _glTexEnvi @ 0x92f2972c (140 bytes) */
int _glTexEnvi(target, pname, param, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 pname;
  undefined4 param;
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
                    
                    
  (*(code *)glContext[0x125])(*glContext,target,pname,param);
  return;
}

/* _glMaterialf @ 0x92f297b8 (148 bytes) */
void _glMaterialf(undefined4 face,undefined4 pname,undefined4 paramShadow,undefined4 fwdReg4,undefined4 fwdReg5,undefined4 fwdReg6,undefined4 fwdReg7,double param)
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
                    
                    
  (*(code *)glContext[0xab])(param,*glContext,face,pname);
  return;
}

