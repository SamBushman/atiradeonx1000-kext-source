/* issue: comprehensive #define fix - decls.h names hundreds of functions/data WITH
 * a leading underscore (matching Ghidra's naming for both internal helpers and
 * imported system calls), but gcc automatically adds ONE MORE leading underscore on
 * top of that when compiling. Apple's stock ld silently reconciles this; ld64
 * (required for this PPC binary's size - stock ld breaks on large PPC links) does
 * not, and needs every real system/CoreFoundation/IOKit call and every one of these
 * data symbols to resolve to the name it actually expects. Renaming each identifier
 * via #define (applied to its declaration AND every call/reference site,
 * transparently) so the compiled symbol matches exactly. */
#define _aniso aniso
#define _aoffimmi aoffimmi
#define _calloc calloc
#define _ceil ceil
#define _CFDictionaryCreate CFDictionaryCreate
#define _CFDictionaryGetValue CFDictionaryGetValue
#define _CFNotificationCenterAddObserver CFNotificationCenterAddObserver
#define _CFNotificationCenterGetDistributedCenter CFNotificationCenterGetDistributedCenter
#define _CFNotificationCenterPostNotification CFNotificationCenterPostNotification
#define _CFNotificationCenterRemoveObserver CFNotificationCenterRemoveObserver
#define _CFNumberCreate CFNumberCreate
#define _CFNumberGetValue CFNumberGetValue
#define _CFRelease CFRelease
#define _CFStringCreateWithCString CFStringCreateWithCString
#define _cmpval cmpval
#define _coordmode coordmode
#define _cos cos
#define ___cxa_guard_acquire __cxa_guard_acquire
#define ___cxa_guard_release __cxa_guard_release
#define _divcomp divcomp
#define _dlopen dlopen
#define _dlsym dlsym
#define _ecvt ecvt
#define _elem elem
#define _elemOffset elemOffset
#define _exit exit
#define _exportStream exportStream
#define _fclose fclose
#define _fgets fgets
#define _floor floor
#define _fmtw fmtw
#define _fmtx fmtx
#define _fmty fmty
#define _fmtz fmtz
#define _fopen fopen
#define _fread fread
#define _free free
#define _frexp frexp
#define _fwrite fwrite
#define _getenv getenv
#define _getpid getpid
#define _gldAllocVertexBuffer gldAllocVertexBuffer
#define _gldAttachDrawable gldAttachDrawable
#define _gldChoosePixelFormat gldChoosePixelFormat
#define _gldCompleteVertexBuffer gldCompleteVertexBuffer
#define _gldCreateBuffer gldCreateBuffer
#define _gldCreateContext gldCreateContext
#define _gldCreateFence gldCreateFence
#define _gldCreateFramebuffer gldCreateFramebuffer
#define _gldCreatePipelineProgram gldCreatePipelineProgram
#define _gldCreateQuery gldCreateQuery
#define _gldCreateShared gldCreateShared
#define _gldCreateTexture gldCreateTexture
#define _gldCreateTextureLevel gldCreateTextureLevel
#define _gldCreateVertexArray gldCreateVertexArray
#define _gldDeleteTexture gldDeleteTexture
#define _gldDeleteTextureLevel gldDeleteTextureLevel
#define _gldDestroyBuffer gldDestroyBuffer
#define _gldDestroyContext gldDestroyContext
#define _gldDestroyFence gldDestroyFence
#define _gldDestroyFramebuffer gldDestroyFramebuffer
#define _gldDestroyMemoryPluginData gldDestroyMemoryPluginData
#define _gldDestroyPipelineProgram gldDestroyPipelineProgram
#define _gldDestroyPixelFormat gldDestroyPixelFormat
#define _gldDestroyQuery gldDestroyQuery
#define _gldDestroyShared gldDestroyShared
#define _gldDestroyVertexArray gldDestroyVertexArray
#define _gldFinish gldFinish
#define _gldFinishMemoryPluginData gldFinishMemoryPluginData
#define _gldFinishObject gldFinishObject
#define _gldFlush gldFlush
#define _gldFlushBuffer gldFlushBuffer
#define _gldFlushVertexArray gldFlushVertexArray
#define _gldFreeVertexBuffer gldFreeVertexBuffer
#define _gldGetError gldGetError
#define _gldGetInteger gldGetInteger
#define _gldGetMemoryPluginData gldGetMemoryPluginData
#define _gldGetPipelineProgramInfo gldGetPipelineProgramInfo
#define _gldGetQueryInfo gldGetQueryInfo
#define _gldGetRendererInfo gldGetRendererInfo
#define _gldGetString gldGetString
#define _gldGetTextureLevel gldGetTextureLevel
#define _gldGetTextureLevelInfo gldGetTextureLevelInfo
#define _gldGetVersion gldGetVersion
#define _gldInitDispatch gldInitDispatch
#define _gldInitializeLibrary gldInitializeLibrary
#define _gldIsTextureResident gldIsTextureResident
#define _gldModifyPipelineProgram gldModifyPipelineProgram
#define _gldModifyTexture gldModifyTexture
#define _gldModifyTextureLevel gldModifyTextureLevel
#define _gldModifyVertexArray gldModifyVertexArray
#define _gldPageoffBuffer gldPageoffBuffer
#define _gldReclaimBuffer gldReclaimBuffer
#define _gldReclaimContext gldReclaimContext
#define _gldReclaimFramebuffer gldReclaimFramebuffer
#define _gldReclaimTexture gldReclaimTexture
#define _gldReclaimVertexArray gldReclaimVertexArray
#define _gldRelatePipelineProgram gldRelatePipelineProgram
#define _gldSetInteger gldSetInteger
#define _gldSetMemoryPluginData gldSetMemoryPluginData
#define _gldTerminateLibrary gldTerminateLibrary
#define _gldTestMemoryPluginData gldTestMemoryPluginData
#define _gldTestObject gldTestObject
#define _gldUpdateDispatch gldUpdateDispatch
#define _glgConvertType glgConvertType
#define _glgPixelCenters glgPixelCenters
#define _glgProcessPixels glgProcessPixels
#define _glpFreePPShaderLinearize glpFreePPShaderLinearize
#define _glpFreePPShaderToProgram glpFreePPShaderToProgram
#define _glpPPShaderLinearize glpPPShaderLinearize
#define _glpPPShaderToProgram glpPPShaderToProgram
#define _glpUniformToFloat glpUniformToFloat
#define _id id
#define _index index
#define _interp interp
#define _IOConnectAddClient IOConnectAddClient
#define _IOConnectMapMemory IOConnectMapMemory
#define _io_connect_method_scalarI_scalarO io_connect_method_scalarI_scalarO
#define _io_connect_method_scalarI_structureI io_connect_method_scalarI_structureI
#define _io_connect_method_structureI_structureO io_connect_method_structureI_structureO
#define _IOServiceClose IOServiceClose
#define _IOServiceOpen IOServiceOpen
#define __keymgr_get_and_lock_processwide_ptr _keymgr_get_and_lock_processwide_ptr
#define __keymgr_set_and_unlock_processwide_ptr _keymgr_set_and_unlock_processwide_ptr
#define _lodbias lodbias
#define _log log
#define _logf logf
#define _longjmp longjmp
#define _mag mag
#define _malloc malloc
#define _matrix matrix
#define _memcmp memcmp
#define _memcpy memcpy
#define _memmove memmove
#define _memset memset
#define _min min
#define _mip mip
#define _neg neg
#define _NSAddressOfSymbol NSAddressOfSymbol
#define _NSIsSymbolNameDefinedWithHint NSIsSymbolNameDefinedWithHint
#define _NSLookupAndBindSymbolWithHint NSLookupAndBindSymbolWithHint
#define _param param
#define _pclose pclose
#define _popen popen
#define _pow pow
#define _pthread_mutexattr_init pthread_mutexattr_init
#define _pthread_mutexattr_settype pthread_mutexattr_settype
#define _pthread_mutex_destroy pthread_mutex_destroy
#define _pthread_mutex_init pthread_mutex_init
#define _pthread_mutex_lock pthread_mutex_lock
#define _pthread_mutex_unlock pthread_mutex_unlock
#define _puts puts
#define _realloc realloc
#define _relop relop
#define _resource resource
#define _rindex rindex
#define _round round
#define _sampler sampler
#define _setjmp setjmp
#define _shadowmode shadowmode
#define _sin sin
#define _sqrt sqrt
#define _sqrtf sqrtf
#define _stage stage
#define _stateStride stateStride
#define _strcat strcat
#define _strchr strchr
#define _strcmp strcmp
#define _strcpy strcpy
#define _strlcpy strlcpy
#define _strlen strlen
#define _strncmp strncmp
#define _type type
#define _UNK_001aa7f4 UNK_001aa7f4
#define _UNK_001aa7f8 UNK_001aa7f8
#define _UNK_001aa848 UNK_001aa848
#define _UNK_001aa84c UNK_001aa84c
#define _UNK_001af9d8 UNK_001af9d8
#define _UNK_001b2a7c UNK_001b2a7c
#define __Unwind_Resume _Unwind_Resume
#define _usage usage
#define _usageIndex usageIndex
#define _usleep usleep
#define _valloc valloc
#define _vfree vfree
#define _volmag volmag
#define _volmin volmin
#define _w w
#define _x x
#define _xoffset xoffset
#define _y y
#define _yoffset yoffset
#define _z z
#define _zeroop zeroop
#define _zoffset zoffset

#include "ghidra_c.h"

extern int dyld_stub_binding_helper();
extern int dyld_func_lookup_stub();
extern int cxa_atexit_check_2();
extern int cxa_atexit_check_1();
extern int check_cxa_atexit();
extern int find_atexit_10_3();
extern int _strcmp_stub_00001af4();
extern int dyld_func_lookup_stub_00001b14();
extern int get_globals();
extern int __keymgr_set_and_unlock_processwide_ptr_stub_00001d44();
extern int check_cxa_atexit_stub_00001d64();
extern int dlsym_stub_00001d84();
extern int find_atexit_10_3_stub_00001da4();
extern int dlopen_stub_00001dc4();
extern int calloc_stub_00001de4();
extern int __keymgr_get_and_lock_processwide_ptr_stub_00001e04();
extern int add_routine();
extern int __keymgr_set_and_unlock_processwide_ptr_stub_00001f30();
extern int malloc_stub_00001f50();
extern int run_routines();
extern int __keymgr_get_and_lock_processwide_ptr_stub_00002094();
extern int free_stub_000020b4();
extern int __keymgr_set_and_unlock_processwide_ptr_stub_000020d4();
extern int cxa_atexit_wrapper();
extern int run_routines_stub_0000222c();
extern int __keymgr_set_and_unlock_processwide_ptr_stub_0000224c();
extern int __keymgr_get_and_lock_processwide_ptr_stub_0000226c();
extern int our_atexit();
extern int __keymgr_set_and_unlock_processwide_ptr_stub_00002348();
extern int run_routines_stub_00002368();
extern int __keymgr_get_and_lock_processwide_ptr_stub_00002388();
extern int atexit_common();
extern int malloc_stub_00002648();
extern int __keymgr_set_and_unlock_processwide_ptr_stub_00002668();
extern int add_routine_stub_00002688();
extern int get_globals_stub_000026a8();
extern int cxa_atexit();
extern int atexit_common_stub_00002728();
extern int atexit();
extern int atexit_common_stub_000027a4();
extern int gld_clearSoftwareColorBuffer();
extern void glAccum_impl(int param_1,undefined4 param_2,double fparam_1);
extern int _gldSetInteger();
extern int _gldGetInteger();
extern int _gldCreateBuffer();
extern int gld_waitBufferStamp();
extern int FUN_00005eb0();
extern int _gldFlushBuffer();
extern int _gldGetMemoryPluginData();
extern int _gldSetMemoryPluginData();
extern int _gldFinishMemoryPluginData();
extern int _gldTestMemoryPluginData();
extern int _gldDestroyMemoryPluginData();
extern int _gldReclaimBuffer();
extern int _gldDestroyBuffer();
extern int gld_setBufferAgpRefBacking();
extern int gld_setBufferNewTextureBacking();
extern int _gldCreateContext();
extern int _gldDestroyContext();
extern int _gldCreateShared();
extern int _gldDestroyShared();
extern int _gldReclaimContext();
extern int FUN_00007020();
extern int _gldAttachDrawable();
extern int FUN_00007810();
extern int _gldGetError();
extern int _gldCreateFence();
extern int _gldDestroyFence();
extern int _gldTestObject();
extern int _gldFinishObject();
extern int _gldCreateFramebuffer();
extern int _gldReclaimFramebuffer();
extern int _gldDestroyFramebuffer();
extern int FUN_00007d50();
extern int gldDepthBitsToFormatMask();
extern int gldColorBitsToFormatMask();
extern int gldAlphaBitsToFormatMask();
extern int _gldChoosePixelFormat();
extern int _gldDestroyPixelFormat();
extern int _gldGetRendererInfo();
extern int _gldInitializeLibrary();
extern int _gldTerminateLibrary();
extern int _gldIsTextureResident();
extern int _gldCreateTexture();
extern int _gldCreateTextureLevel();
extern int _gldModifyTexture();
extern int _gldModifyTextureLevel();
extern int _gldGetTextureLevelInfo();
extern int _gldDeleteTextureLevel();
extern int _gldReclaimTexture();
extern int _gldDeleteTexture();
extern int _gldCreatePipelineProgram();
extern int _gldModifyPipelineProgram();
extern int _gldRelatePipelineProgram();
extern int _gldGetPipelineProgramInfo();
extern int _gldDestroyPipelineProgram();
extern int FUN_000095e0();
extern int FUN_000096b0();
extern int FUN_0000973c();
extern int FUN_00009750();
extern int FUN_0000979c();
extern int FUN_000097ac();
extern int FUN_000097bc();
extern int FUN_000097cc();
extern int FUN_000097dc();
extern int FUN_000097ec();
extern int FUN_000097fc();
extern int FUN_00009810();
extern int FUN_00009880();
extern int FUN_000098c8();
extern int gldAllocQueryRecord();
extern int gld_waitQueryStamp();
extern int _gldDestroyQuery();
extern int gld_releaseQueryMemory();
extern int gld_setQueryAgpRefBacking();
extern int _gldCreateQuery();
extern int gldFormatBitsPerPixel();
extern int FUN_0000a0f0();
extern int gldFormatAlphaBits();
extern int FUN_0000a180();
extern int gld_textureVariantClass();
extern int gldPixelUnitBytes();
extern int gldPixelRowBytes();
extern int gld_computePixelStoreLayout();
extern int gld_resolveBoundTextures();
extern int gld_textureMemoryBytes();
extern int gld_waitTextureStamp();
extern int FUN_0000abf0();
extern int gld_ensureTextureBackingSized2();
extern int gld_ensureTextureAgpRefBacking();
extern int gld_setTextureAgpRefBacking();
extern int gld_setTextureNewTextureBacking();
extern int gld_ensureTextureSurfaceBacking();
extern int gld_ensureTextureGlobalBacking();
extern int gldFlushDataCacheRange();
extern int gldFlushDataCacheRangeSync();
extern int _gldCreateVertexArray();
extern int _gldFlushVertexArray();
extern int FUN_0000b750();
extern int gld_waitVertexArrayStamp();
extern int FUN_0000b980();
extern int _gldModifyVertexArray();
extern int _gldReclaimVertexArray();
extern int _gldDestroyVertexArray();
extern int gld_setVertexArrayAgpRefBacking();
extern int gld_setVertexArrayNewTextureBacking();
extern double powerOfTenDouble(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
extern char * textPrintDoubleShortest(undefined4 param_1,undefined4 param_2,char *param_3,uint param_4,double fparam_1,double fparam_2);
extern double parseDecimalDouble(char *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6);
extern int textBufferEnsureRoom();
extern int arbIrPrintCcAndSaturateSuffix();
extern int arbIrPrintPrecisionSuffix();
extern int textPrintDecimalDigits();
extern int textPrintSignedDecimal();
extern int arbIrPrintDeclSizeSuffix();
extern int arbIrPrintSourceSizeSuffix();
extern int arbIrPrintDestinationOperand();
extern int arbIrPrintSizeTypeSuffix();
extern int arbIrPrintSourceOperand();
extern int arbIrPrintTextureOperand();
extern int arbProgramIrToText();
extern void glBitmap_impl(int param_1,float *param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,double fparam_1,double fparam_2);
extern int gld_bufferEnumToIndex();
extern int FUN_00017100();
extern int FUN_00017160();
extern int FUN_00017260();
extern int gld_setIntegerEngineParam();
extern int FUN_00017720();
extern int gld_fillCapsBlock();
extern int FUN_00017a40();
extern int gld_postDisplayNotification();
extern int gldRemoveDisplayNotificationObserver();
extern int gld_printApplicationPath();
extern int FUN_00018090();
extern int glCopyPixels_impl();
extern int glDrawPixels_impl();
extern int gld_drawPixelsAtRasterPos();
extern int gld_drawPixelsDispatch();
extern int FUN_000199f0();
extern int FUN_00019ad0();
extern int gld_updateSampleConfig();
extern int FUN_00019db0();
extern int FUN_0001a010();
extern int gld_isStampRetired();
extern int gld_submitRing();
extern int glFlush_impl();
extern int glFlush_impl_withSurfaceUpdate();
extern int _gldFlush();
extern int _gldFinish();
extern int gld_signalFence();
extern int glFinish_impl();
extern int FUN_0001a9d0();
extern int gld_validatePixelFormat();
extern int gld_expandPixelFormatVariants();
extern int gld_fillMaxPixelFormat();
extern int _gldFreeVertexBuffer();
extern int _gldCompleteVertexBuffer();
extern int _gldAllocVertexBuffer();
extern int gld_updateYInvertedFlag();
extern int noop_1b4f0();
extern int returnOne_1b500();
extern int FUN_0001b510();
extern int gld_emitFramebufferState();
extern int dxt5EncodeAlphaBlock();
extern int dxt1DecodeColorIndex();
extern int FUN_0001c380();
extern int dxtDecompressImage();
extern uint floatToHalfBits(double fparam_1);
extern int gld_validateVertexArrayStreams();
extern int gldComputeVertexChunking();
extern int gld_prepareVertexArrayBacking();
extern int gld_startPacket();
extern int _gldPageoffBuffer();
extern int returnZero_1e270();
extern int gld_prepareBufferBacking();
extern int gld_prepareVertexArrayBuffers();
extern int copyIndices16Swapped_prefetch_entry();
extern int copyIndices16Swapped_prefetch();
extern int copyIndices16Swapped_dcbz_entry();
extern int copyIndices16Swapped_dcbz();
extern int gld_drawVertexArray();
extern int FUN_0001fd00();
extern int FUN_00020210();
extern int FUN_00020330();
extern int gldDisplayNotificationCallback();
extern int FUN_00020b00();
extern int FUN_00020b30();
extern int FUN_00021c70();
extern int noop_22280();
extern uint _gldUpdateDispatch(int param_1,int param_2,uint *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int _gldInitDispatch();
extern int FUN_00022eb0();
extern int FUN_000230d0();
extern int returnSecondArgument();
extern int gldEmitCurrentAttributeRegisters();
extern int FUN_00023870();
extern int gld_emitPrimitiveVertices();
extern int FUN_00024190();
extern void FUN_000242f0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8);
extern void FUN_00024370(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperTriangleFan_23a24(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperQuads_23a24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperQuadStrip_23a24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperPolygon_23a24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperPolygon_24190(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperPoints_23a24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperPoints_24190(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperLines_23a24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperLines_24190(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperLineLoop_23a24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimWrapperLineStrip_23a24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gld_drawElementsImmediate(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined *param_6,uint *param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_00024fb0();
extern int noop_24fc0();
extern int noop_24fd0();
extern double FUN_00024fe0(int param_1,int param_2,float *param_3,double fparam_1);
extern int FUN_00025bf0();
extern int FUN_00025da0();
extern int FUN_00025ec0();
extern int FUN_00026440();
extern int FUN_00026650();
extern int FUN_000269a0();
extern int FUN_00026bf0();
extern void FUN_00026f80(int param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_00027150();
extern uint FUN_000273a0(int param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_00027990();
extern int gld_readPixelsViaBlit();
extern int glReadPixels_entry();
extern int glReadPixels_impl();
extern int FUN_00029c00();
extern int FUN_0002a260();
extern int gld_drawPixelsFromClientSurface();
extern int noop_2b3b0();
extern int gld_sumQueryCounters();
extern int _gldGetQueryInfo();
extern void FUN_0002b740(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_0002b7f0();
extern void FUN_0002bbc4(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_0002be00();
extern int FUN_0002be60();
extern int FUN_0002be70();
extern int noop_2be80();
extern int FUN_0002be90();
extern int gldTrimVertexCountToPrimitive();
extern int gldTrimVertexCountToPrimitiveMin();
extern void FUN_0002c020(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,uint param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_0002c0c0();
extern int FUN_0002c180();
extern int FUN_0002c230();
extern int FUN_0002c6c0();
extern int gld_initContextHardwareState();
extern int gldContextFreeResources();
extern int FUN_0002cc10();
extern uint FUN_0002cc30(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,undefined4 param_6,uint param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_0002cd50();
extern int FUN_0002ce40();
extern int FUN_0002d030();
extern int FUN_0002d210();
extern void gldPackColorForSurfaceFormat(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int gldTextureHasNonPowerOfTwoSize2();
extern int FUN_0002ddf0();
extern int FUN_0002ebc0();
extern int FUN_0002ee30();
extern int window_mode_to_ati_format();
extern int gldTextureFormatCodeMatchesType();
extern int gldTextureFormatCodeFromFormatType();
extern int FUN_0002fac0();
extern int gldCompressedImageBytes();
extern int FUN_00030420();
extern int FUN_000305b0();
extern int FUN_000307a0();
extern int FUN_00030840();
extern int FUN_000308c0();
extern int floorLog2();
extern int FUN_000309c0();
extern int FUN_00030a50();
extern int FUN_00030a60();
extern int gldTextureHasNonPowerOfTwoSize();
extern int FUN_00030c50();
extern int FUN_00030f00();
extern int FUN_00030f60();
extern int gldTextureFormatLookup();
extern int gldTextureFormatEntryForLevel();
extern int FUN_00031340();
extern int _gldGetTextureLevel();
extern int FUN_00031940();
extern int gldTextureMakeResident();
extern int FUN_000341a0();
extern int glGenerateMipmap_impl();
extern int FUN_000353a0();
extern int glTexSubImage_impl();
extern int gld_testRendererAvailable();
extern int gldRendererFamilyString();
extern int _gldGetVersion();
extern int _gldGetString();
extern void FUN_00039330(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void FUN_00039610(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void FUN_00039a60(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void FUN_00039d40(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void FUN_0003a020(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void FUN_0003a300(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void FUN_0003a5e0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void FUN_0003a8c0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void FUN_0003aba0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void FUN_0003ae80(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_0003b160();
extern int FUN_0003b280();
extern int FUN_0003b5b0();
extern int FUN_0003b620();
extern int FUN_0003b870();
extern int gldDeleteVertexShaderObject();
extern int FUN_0003c400();
extern int FUN_0003d590();
extern int gldUpdateTextureTargetDirtyMask();
extern int FUN_0003e250();
extern int FUN_0003e320();
extern int FUN_0003e3a0();
extern int FUN_0003e420();
extern int gldDeleteFragmentShaderObject();
extern int atifsReplayTextureOps();
extern int atifsReplayColorAlphaOps();
extern int atifsReplayProgram();
extern int fpilEmitAngleConstants();
extern int fpilClassifyDestination();
extern int fpilBuildDestinationToken();
extern int fpilSetComponentSelect();
extern int fpilEmitScalarConstant();
extern int fpilReserveTokens();
extern int fpilMapConstantRegister();
extern int fpilTranslateSource();
extern int fpilTranslateSourceWithSwizzle();
extern int freeIfNonNull();
extern int fpilDestroyTranslator();
extern int fpilCreateTranslator();
extern int fpilTranslateDestination();
extern int fpilEmitEmptyProgram();
extern int fpilEmitMoveFromTemp();
extern int fpilEmitInstruction();
extern int fragmentTranslateSimpleOp();
extern int fragmentTranslateRep();
extern int fragmentTranslateDdy();
extern int fragmentTranslateScalarMath();
extern int fragmentTranslateScalarMathBody();
extern int FUN_00040ac4();
extern int fragmentTranslateTrig();
extern int fragmentTranslateAngleConvert();
extern int fragmentTranslateMod();
extern int fragmentTranslateAtn();
extern int fragmentTranslateRfr();
extern int fragmentTranslateFfw();
extern int fragmentTranslateDst();
extern int fragmentTranslateIf();
extern int fragmentTranslateRfl();
extern int fragmentTranslateWhile();
extern int fragmentTranslateDsl();
extern int fragmentTranslateSel();
extern int fragmentTranslateAll();
extern int fragmentTranslateAny();
extern int fragmentTranslateArithmetic();
extern int fragmentInstructionToIL();
extern int fragmentProgramToIL();
extern uint floatToFp24(double fparam_1);
extern double fp24ToFloat(uint param_1);
extern int FUN_0004a860();
extern void FUN_0004a8f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1);
extern int FUN_0004a990();
extern int FUN_0004aa00();
extern int FUN_0004aa90();
extern int FUN_0004ab60();
extern int FUN_0004ac90();
extern int FUN_0004b190();
extern int FUN_0004b480();
extern int FUN_0004b520();
extern int FUN_0004b5d0();
extern int FUN_0004b710();
extern int FUN_0004b7d0();
extern int FUN_0004b980();
extern int FUN_0004bbf0();
extern int FUN_0004c100();
extern int FUN_0004c260();
extern int noop_4c540();
extern int FUN_0004c560();
extern int FUN_0004c720();
extern int freeAndNullField();
extern int FUN_0004ce30();
extern int FUN_0004d100();
extern void FUN_0004d620(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1);
extern void FUN_0004d770(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8);
extern int gldValidateDepthTest();
extern int FUN_0004dbe0();
extern int gldValidateTexEnvColor();
extern int gldEmitScissorRegs();
extern int gldEmitViewportAndGuardBand();
extern int FUN_0004ddc0();
extern int FUN_0004de30();
extern double FUN_0004def0(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_0004e880();
extern int FUN_0004e990();
extern double gldValidatePolygonMode(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8);
extern int FUN_0004eba0();
extern int FUN_0004ed90();
extern int gldValidateCullFace();
extern int FUN_0004f160();
extern void FUN_0004f2e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1);
extern int gldValidateScissor();
extern int gldInitStateDefaults();
extern int FUN_0004fc80();
extern int FUN_0004fd80();
extern int gldValidateAlphaTest();
extern int FUN_00050140();
extern int gldEmitHardwareState();
extern int FUN_00050ef0();
extern int gldValidateStencil();
extern int gldValidateBlend();
extern double FUN_000520c0(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8);
extern int FUN_00052280();
extern int FUN_00052cc0();
extern int FUN_00052e60();
extern int FUN_00052ee0();
extern int FUN_00052f60();
extern int FUN_00053000();
extern int FUN_00053040();
extern int noop_53060();
extern int extvsConstantsDirty();
extern int extvsClearConstantsDirty();
extern int FUN_000530c0();
extern int FUN_00053190();
extern int extvsGetOrCreateStateSymbol();
extern int glGenSymbolsEXT_impl();
extern int FUN_000534c0();
extern int extvsShaderOp1Explicit();
extern int extvsShaderOp2Explicit();
extern int extvsShaderOp3Explicit();
extern int glSwizzleEXT_impl();
extern int extvsBeginShader();
extern int extvsEndShader();
extern int extvsFindShaderIndex();
extern int extvsGetShaderById();
extern int extvsBindShader();
extern int extvsReserveSymbolIds();
extern int extvsDeleteShaderObject();
extern int glDeleteVertexShaderEXT_impl();
extern int glShaderOp1EXT_impl();
extern int glShaderOp2EXT_impl();
extern int glShaderOp3EXT_impl();
extern int FUN_00054080();
extern int glWriteMaskEXT_impl();
extern int glInsertComponentEXT_impl();
extern int glExtractComponentEXT_impl();
extern int glGenSymbolsEXT_impl5();
extern int FUN_00054470();
extern int FUN_00054590();
extern int FUN_000546d0();
extern int glSetLocalConstantEXT_impl();
extern int extvsBindCurrentVertexParameter();
extern int extvsFreeAllShaders();
extern int extvsReleaseState();
extern int extvsInitState();
extern int extvsAttachSharedState();
extern int extvsSymbolListGetIndex();
extern int extvsAppendSymbol();
extern int FUN_00054f50();
extern int extvsOperandDataType();
extern int extvsFreeSymbolData();
extern int extvsFreeShaderObject();
extern int extvsAppendInstruction();
extern int extvsCreateSymbol();
extern int extvsSymbolListGetSymbol();
extern int extvsInitSymbolListWithMVP();
extern int extvsInitShaderObject();
extern int extvsRefreshBoundVertexPrograms();
extern int extvsAllocConstantRegisters();
extern int extvsAllocTempRegisters();
extern int extvsOperandUsesTempSlot();
extern int extvsFreeDeadTempSlots();
extern int extvsEncodeSourceOperand();
extern int extvsEncodeSourceSwizzle();
extern int extvsOperandsConflictInBank();
extern int extvsAllocTempSlot();
extern int extvsEmitIndex();
extern int extvsEmitSingleSourceInstruction();
extern int extvsEmitDot3();
extern int extvsEmitDot4();
extern int extvsEmitMul();
extern int extvsEmitAdd();
extern int extvsEmitMad();
extern int extvsEmitFrc();
extern int extvsEmitMax();
extern int extvsEmitMin();
extern int extvsEmitSetGreaterEqual();
extern int extvsEmitSetLessThan();
extern int extvsEmitClamp();
extern int extvsEmitFlr();
extern int extvsEmitRnd();
extern int extvsEmitExp();
extern int extvsEmitLog();
extern int extvsEmitPow();
extern int extvsEmitRcp();
extern int extvsEmitRsq();
extern int extvsEmitSub();
extern int extvsEmitCrs();
extern int extvsEmitMmul();
extern int extvsEmitMov();
extern int extvsEmitSwizzle();
extern int extvsEmitWriteMask();
extern int extvsEmitOp879c();
extern int extvsEmitOp879d();
extern int extvsEmitLit();
extern int extvsEmitDst();
extern int extvsEmitExpp();
extern int extvsEmitLogp();
extern int extvsEmitMova();
extern int extvsEmitFogOutput();
extern int popFirstNonNull32();
extern int extvsAssignVertexInputs();
extern int FUN_0005f540();
extern int extvsPrepareHardwareProgram();
extern int vpUploadConstantArray();
extern int vpUploadConstantsWithFog();
extern int extvsComputeStateKey();
extern int extvsStateFree();
extern int FUN_00062370();
extern int extvsInitLimits();
extern int FUN_00062410();
extern int FUN_00062490();
extern int FUN_00062510();
extern int extvsStateCacheCreate();
extern int extvsStateCacheFreeAll();
extern int FUN_00062940();
extern int noop_62a60();
extern int extvsStateCacheInsert();
extern int extvsBuildStreamDescriptors();
extern int gldCurrentAttributePacketHeader();
extern int FUN_00064230();
extern int FUN_00064720();
extern int FUN_00064850();
extern int FUN_00064a10();
extern int FUN_00064f40();
extern int FUN_000651e0();
extern int FUN_00065370();
extern int FUN_00065610();
extern int FUN_000656b0();
extern void FUN_000659d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int FUN_00065c40();
extern int noop_65c80();
extern int arbEmitIlHeader();
extern int arbEmitIlEnd();
extern int arbEmitIlDp4();
extern int arbEmitIlMov();
extern int arbEmitIlMul();
extern int arbEmitIlAdd();
extern int arbEmitIlMad();
extern int arbEmitIlAddMad3Src();
extern int arbEmitIlMulMaxMin2Src();
extern int arbEmitIlMin();
extern int arbEmitIlMax();
extern int arbEmitIlSetCompare5();
extern int arbEmitIlSetCompare2();
extern int arbEmitIlRnd();
extern int arbEmitIlRcp();
extern int arbEmitIlRsq();
extern int arbEmitIlExp();
extern int arbEmitIlExn();
extern int arbEmitIlPow();
extern int FUN_0006e460();
extern int arbEmitIlMovMadMov();
extern int evsTokenBufPush();
extern int evsAllocLocalConstantRegisters();
extern int evsAllocConstantsForOperand();
extern int evsAllocLocalRegisters();
extern int evsOperandUsesTempSlot();
extern int noop_70c50();
extern int noop_70c60();
extern int evsFindFreeOutputRegister();
extern int evsAllocTempSlot();
extern int evsEmitFogOutput();
extern int evsAssignVertexInputs();
extern int evsEncodeSource();
extern int evsEncodeDestination();
extern int evsAppendInstruction();
extern int evsEmitMova();
extern int evsEmitLogp();
extern int evsEmitExpp();
extern int evsEmitDst();
extern int evsEmitLit();
extern int evsEmitOp879d();
extern int evsEmitOp879c();
extern int evsEmitOp879b();
extern int evsEmitOp879a();
extern int evsEmitMovOp8799();
extern int evsEmitMmul();
extern int evsEmitCrs();
extern int evsEmitSub();
extern int evsEmitRsq();
extern int evsEmitRcp();
extern int evsEmitPow();
extern int evsEmitLog();
extern int evsEmitExp();
extern int evsEmitRnd();
extern int evsEmitFlr();
extern int evsEmitClamp();
extern int evsEmitSetCompare5();
extern int evsEmitSetCompare2();
extern int evsEmitMin();
extern int evsEmitMax();
extern int evsEmitFrc();
extern int evsEmitMad();
extern int evsEmitAdd();
extern int evsEmitMul();
extern int evsEmitDp4();
extern int evsEmitDp3();
extern int evsEmitMov();
extern int evsEmitIndexOrMove();
extern int FUN_00076770();
extern int FUN_000768e0();
extern int FUN_00076ac0();
extern int vpStateCacheInsert();
extern int noop_76c00();
extern int vpStateCacheLookup();
extern int FUN_00076c60();
extern int noop_76e60();
extern int vpStateFree();
extern int FUN_00076fe0();
extern int FUN_00077030();
extern int vpStateCacheCreate();
extern int vpStateCacheFreeAll();
extern int vpStateSetConstantVector();
extern int FUN_000774c0();
extern int FUN_00077560();
extern int depListRemove();
extern int FUN_000776b0();
extern int arrayRemoveAt();
extern int FUN_000777b0();
extern int FUN_00077800();
extern int recordGetWriteMask();
extern int FUN_00077860();
extern int regBindingSet();
extern int regBindingSetFixedRegister();
extern int recordSourceFileIs1();
extern int recordDestFileIs0();
extern int recordCombinedWriteMask();
extern int recordRegisterIsAssignable();
extern int recordFindFreeTempRegister();
extern int recordSourceFileIs0();
extern int recordOpcodeSourceMask();
extern int recordMarkDependentsDirty();
extern int recordAssignDestinationRegister();
extern int FUN_00078950();
extern int FUN_00078990();
extern int FUN_000789d0();
extern int recordCountSourceRegisterFiles();
extern int recordRetargetDestination();
extern int regBindingClear();
extern int chunkArenaAlloc();
extern int recordSourceFileIs2();
extern int recordGetWriteEnable();
extern int FUN_00078f80();
extern int recordSetWriteMask();
extern int depListAddEdge();
extern int recordGetSourceSelect();
extern int recordSetSourceSelect();
extern int FUN_00079b00();
extern int recordLinkSourceToDefinition();
extern int FUN_00079e10();
extern int FUN_00079e70();
extern int chunkArenaResetCursor();
extern int chunkArenaFree();
extern int FUN_0007a110();
extern int FUN_0007a1a0();
extern int FUN_0007a4a0();
extern int FUN_0007aae0();
extern int recordProgramAllocateAndEmit();
extern int recordProgramBuildDependencies();
extern int FUN_0007dcd0();
extern int FUN_0007dd30();
extern int evsFoldConstantMoves();
extern int FUN_00082900();
extern int FUN_00082c50();
extern int interpolatorMapInit();
extern int noop_83100();
extern int ffvpSetupVertexOutputRouting();
extern int ffvpBuildPassThroughProgram();
extern int gldEmitVertexRoutingPackets();
extern void ffvpValidateProgram(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void ffvpValidateProgramForced(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_00083c90();
extern int arbEmitRecord3Src_op44();
extern int arbEmitRecord2Src_op01();
extern int arbEmitRecord1Src_op02();
extern int arbEmitRecord2Src_op02();
extern int arbEmitRecord2Src_op03();
extern int arbEmitRecord3Src_op04();
extern int arbEmitRecord3Src_op0b();
extern int arbEmitRecord3Src_op0c();
extern int arbEmitRecord2Src_op08();
extern int arbEmitRecord2Src_op07();
extern int arbEmitRecord2Src_op0a();
extern int arbEmitRecord2Src_op09();
extern int arbEmitRecord1Src_op0e();
extern int arbEmitRecord1Src_op47();
extern int arbEmitRecord1Src_op49();
extern int arbEmitRecord1Src_op4b();
extern int arbEmitRecord1Src_op43();
extern int arbEmitRecord2Src_op45();
extern int arbEmitRecord2Src_op4f();
extern int FUN_00086710();
extern int FUN_000867b0();
extern int FUN_00086840();
extern int FUN_00086930(int param_1,double fparam_1,double fparam_2);
extern int FUN_00086a10();
extern int FUN_00086a80();
extern int FUN_00086ba0();
extern int FUN_000872e0();
extern int arbfpUpdateConstantsFp24();
extern int arbfpInitResourceLimits();
extern int noop_879e0();
extern int FUN_000879f0();
extern int FUN_00087cd0();
extern int FUN_00087da0();
extern int FUN_00087e60();
extern int FUN_00087e70();
extern int FUN_00087e80();
extern int FUN_00088190();
extern int arbfpLookupKeyword();
extern int arbLexNumber();
extern int arbNextToken();
extern int arbSetError();
extern int arbErrorOutOfMemory();
extern int arbAllocVariable();
extern int arbParseVariableName();
extern int arbErrorInternal();
extern int arbExpectToken();
extern int arbComponentLetterToIndex();
extern int arbAllocBindingEntry();
extern int arbInternConstant();
extern int arbDeclareVariable();
extern int arbParseResultBinding();
extern int arbParseOptionalSign();
extern double arbParseFloatConstant(int param_1);
extern int arbParseLocalParamNumber();
extern int arbParseEnvParamNumber();
extern int arbParseTexCoordNumber();
extern int arbParseMatrixRowNumber();
extern int arbParseLightNumber();
extern int arbParseParamBinding();
extern int arbParseFragmentAttribBinding();
extern int arbParseComponentToken();
extern int arbParseSourceRegister();
extern int arbParseExtendedSwizzleSelector();
extern int arbParseDestRegister();
extern int arbParseSwizzleSuffix();
extern int arbfpParseScalarSourceOperand();
extern int arbParseProgramText();
extern int arbfpInternParameter();
extern int arbValidateProgram();
extern int arbfpUpdateStateForProgram();
extern int arbfpBindProgram();
extern int FUN_0008dc40();
extern int arbfpProgramObjectInit();
extern int arbfpProgramObjectFree();
extern int arbfpProgramString();
extern int arbfpProgramStringIL();
extern int arbfpFetchParameterValue();
extern int arbfpInitProgramState();
extern int arbfpGrowInstanceTable();
extern int arbfpLoadDefaultProgram();
extern int FUN_0008f7f0();
extern int FUN_0008fb70();
extern int FUN_0008fc70();
extern int FUN_000900a0();
extern void gldValidateState(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int FUN_00090840();
extern int FUN_00090960();
extern int FUN_00090990();
extern int ffvpAllocTempRegister();
extern int ffvpFreeTempRegister();
extern int ffvpResolveMaterialSource();
extern int ffvpResolveFixedSource();
extern int noop_914c0();
extern int ffvpEmitEyePositionMad();
extern int ffvpEmitEyePositionDp4();
extern int ffvpEmitEyeDistanceSquared();
extern int ffvpEmitInverseW();
extern int ffvpEmitEyeNormal();
extern int ffvpEmitNormalizedNormal();
extern int ffvpEmitRescaledNormal();
extern int ffvpEmitBlendWeights();
extern int ffvpEmitInverseEyeDistance();
extern int ffvpEmitEyeVector();
extern int ffvpEmitReflectionVector();
extern int ffvpEmitSphereMapCoord();
extern int ffvpEmitFogExp2();
extern int ffvpCreateBuilder();
extern int ffvpEmitPositionPassThrough();
extern int ffvpEmitColorPassThrough();
extern int ffvpEmitTexCoordPassThrough();
extern int ffvpEmitPointSizePassThrough();
extern int ffvpEmitFogPassThrough();
extern int FUN_00093390();
extern int FUN_000934f0();
extern int ffvpEmitBlendedEyeNormal();
extern int ffvpPrepareRescaledNormal();
extern int ffvpPrepareNormalizedNormal();
extern int ffvpEmitBlendedClipPosition();
extern int ffvpEmitBlendedEyePosition();
extern int ffvpEmitInverseEyeDistance_955a0();
extern int ffvpEmitEyeVector_955c0();
extern int ffvpPrepareBlendWeights();
extern int ffvpEmitProjectedPosition();
extern int ffvpEmitEyePosition();
extern int ffvpEmitClipPosition();
extern int ffvpPrepareEyeNormal();
extern int ffvpPrepareFogExp2();
extern int ffvpEmitTexCoordGen();
extern int ffvpEmitSceneColor();
extern int ffvpEmitDirectionalLight();
extern int ffvpEmitLight();
extern int ffvpEmitPointSizeAttenuation();
extern int ffvpEmitFogDistance();
extern int ffvpFinishProgram();
extern int fpVariantProgramFree();
extern int ffvpEmitFogLinear();
extern int ffvpPrepareFogLinear();
extern int ffvpEmitFogExp();
extern int ffvpEmitColorOutputs();
extern int ffvpPrepareFogExp();
extern int ffvpEmitFogTexCoord();
extern int vec4StoreAtIndex();
extern int mat4StoreAtIndex();
extern int paramListCreate();
extern int ffvpInitContextState();
extern int ffvpAnalyzeLightState();
extern int fpVariantCacheFlush();
extern int fpVariantCacheInsert();
extern int fpVariantEntryRecomputeDependencies();
extern int ffvpBuildLightKey();
extern int ffvpBuildFogKey();
extern int ffvpBuildBlendKey();
extern int ffvpUpdateLightModelFlags();
extern int ffvpRunStateHook();
extern int FUN_0009d3b0();
extern int ffvpBuildProgram();
extern int fpVariantCacheGrow();
extern int fpVariantCacheLookup();
extern void programFillStateConstants(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int arbProgramFindIndex();
extern int glProgramStringARB_impl();
extern int FUN_000a0350();
extern int glBindProgramARB_impl();
extern int glGenProgramsARB_impl();
extern int glGetProgramivARB_impl();
extern int arbProgramEntryFree();
extern int arbProgramTableRelease();
extern int glDeleteProgramsARB_impl();
extern int FUN_000a0ef0();
extern int noop_a0f80();
extern int FUN_000a0f90();
extern int FUN_000a1040();
extern int FUN_000a1060();
extern int FUN_000a1090();
extern int FUN_000a1160();
extern int FUN_000a11a0();
extern int FUN_000a11f0();
extern int glGenFragmentShadersATI_impl();
extern int glBindFragmentShaderATI_impl();
extern int glDeleteFragmentShaderATI_impl();
extern int glBeginFragmentShaderATI_impl();
extern int glEndFragmentShaderATI_impl();
extern int glPassTexCoordATI_impl();
extern int glSampleMapATI_impl();
extern int glColorFragmentOp1ATI_impl();
extern int glColorFragmentOp2ATI_impl();
extern int glColorFragmentOp3ATI_impl();
extern int glAlphaFragmentOp1ATI_impl();
extern int glAlphaFragmentOp2ATI_impl();
extern int glAlphaFragmentOp3ATI_impl();
extern int glSetFragmentShaderConstantATI_impl();
extern int atifsResetState();
extern int atifsFreeShaderTable();
extern int atifsReleaseShaderTable();
extern int atifsUnshareShaderTable();
extern int atifsCreateShaderTable();
extern int atifsPackArgument();
extern int atifsCountPassOps();
extern int atifsSetShaderValid();
extern int atifsInitShader();
extern int atifsFreeShader();
extern int atifsAddTextureOp();
extern int atifsAddColorOp();
extern int atifsAddAlphaOp();
extern int atifsSetConstant();
extern uint FUN_000a3560(int param_1,double fparam_1);
extern int FUN_000a3610();
extern int FUN_000a3670();
extern int FUN_000a36b0();
extern void FUN_000a3790(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,int *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12);
extern void FUN_000a3a60(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int FUN_000a3be0();
extern int FUN_000a43f0();
extern int FUN_000a4490();
extern int FUN_000a4550();
extern int FUN_000a46d0();
extern int FUN_000a4760();
extern int FUN_000a4770();
extern int FUN_000a4980();
extern int FUN_000a5c40();
extern int FUN_000a5ec0();
extern int FUN_000a6140();
extern int FUN_000a64d0();
extern int FUN_000a6500();
extern int FUN_000a6860();
extern int FUN_000a6cb0();
extern int FUN_000a6f70();
extern int noop_a6f80();
extern void FUN_000a6f90(float *param_1,float *param_2,double fparam_1);
extern int FUN_000a7050();
extern int gldFreeEngineState();
extern int FUN_000a7a60();
extern int gldMarkAllStateDirty();
extern int FUN_000a7d10();
extern int FUN_000a7e80();
extern int FUN_000a7ea0();
extern int noop_a7ed0();
extern int FUN_000a7ee0();
extern int FUN_000a82c0();
extern int FUN_000a8320();
extern int FUN_000a8340();
extern double FUN_000a8630(int param_1,int param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int FUN_000a8a00();
extern int FUN_000a8c00();
extern int FUN_000a8d70();
extern int FUN_000a8e20();
extern int FUN_000a9070();
extern double FUN_000a9640(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12);
extern void FUN_000a9ac0(char *param_1,uint *param_2,char *param_3,undefined *param_4,uint param_5,char *param_6,undefined4 param_7,uint param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int FUN_000ab900();
extern int FUN_000ab940();
extern int FUN_000ab9b0();
extern void FUN_000abab0(int param_1,int param_2,undefined4 param_3,double fparam_1);
extern int FUN_000abb60();
extern int FUN_000abbd0();
extern int FUN_000abd10();
extern int FUN_000ac540();
extern int FUN_000ac720();
extern int FUN_000aec40();
extern undefined4 FUN_000afe40(int param_1,int param_2,undefined4 param_3,uint *param_4,double fparam_1);
extern int ilTokenBufPush();
extern int atifsEmitFinalColorClamp();
extern int atifsEmitAddSecondaryColor();
extern int atifsEmitMoveWithWriteMask();
extern int atifsEmitSourceOperand();
extern int atifsEmitDestinationOperand();
extern int atifsEmitTextureOps();
extern int atifsEmitClearTemp0();
extern int atifsEmitInputDeclarations();
extern int atifsCompileCurrentShader();
extern int noop_b43f0();
extern int FUN_000b4400();
extern int FUN_000b4cd0();
extern void FUN_000b4f50(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern void FUN_000b5010(int param_1,int param_2,int *param_3,int param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int FUN_000b50a0();
extern int noop_b5190();
extern int FUN_000b51a0();
extern int FUN_000b5320();
extern int noop_b53f0();
extern int FUN_000b5400();
extern int FUN_000b57a0();
extern int FUN_000b5a60();
extern int FUN_000b5b60();
extern int FUN_000b5ba0();
extern int FUN_000b5bd0();
extern int FUN_000b5c00();
extern int FUN_000b5f40();
extern int FUN_000b5fb0();
extern int FUN_000b6020();
extern int FUN_000b6580();
extern double FUN_000b6f20(int param_1,int param_2,int param_3,int param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int extvsInstReadsTempComponents();
extern int extvsOptimizeProgram();
extern void FUN_000bd9a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1);
extern int FUN_000bda40();
extern int FUN_000bde70();
extern int FUN_000be460();
extern int FUN_000bee40();
extern int FUN_000bef40();
extern int FUN_000bf400();
extern int FUN_000bf910();
extern int FUN_000bfcc0();
extern int FUN_000bfed0();
extern int psnDecRecomputeSourceUsage();
extern int psnDecCanonicalizeEntry();
extern int psnDecDecodeHwInstruction();
extern int psnDecTrySwapAddressSlots();
extern int psnDecSortAddressSlots();
extern int psnDecEncodeHwWords();
extern int psnDecAllocateTempsAndCompact();
extern int psnMaskIsSingleComponent();
extern int psnDecAlphaDestIs();
extern int psnDecAlphaComponentReadsReg();
extern int psnDecAnySourceIsReg();
extern int psnDecAnyPartialSourceIsReg();
extern int psnDecMaskCoveredByDests();
extern int psnDecFirstFreeAddressSlot();
extern int psnDecHasFreeAddressSlot();
extern int psnDecRetargetSourceReg();
extern int psnDecReplaceSourceAddress();
extern int psnDecReadsRegMask();
extern int psnDecSourceHasPartialMask();
extern int psnDecDestMatchesRegMask();
extern int psnDecCanFoldIntoSlot();
extern int psnDecSwapAddressSlotsInSources();
extern int psnDecTryRebindAddressWithRollback();
extern int psnConstantComponentsAreOne();
extern int psnDecRangeHasConflict();
extern int psnDecTryMergeAddressSlots();
extern int psnProgramToDecoded();
extern int psnDecodedToProgram();
extern int psnAccumulateRgbSelectRead();
extern int psnAccumulateAlphaSelectRead();
extern int psnRaReleaseUse();
extern int psnRaAssignDefinition();
extern int FUN_000c5e60();
extern int psnReallocateTemps();
extern int scCallbackFree();
extern int scCallbackGetFlagZero();
extern int scCallbackAppendFormatted();
extern int scCallbackFopen();
extern int scCallbackFclose();
extern int scCallbackFwrite();
extern int scCallbackFread();
extern int FUN_000c6ff0();
extern int ilFreeRecordList();
extern int ilSelectorOneToThreeOrZero();
extern int ilRecordInputSemantic();
extern int ilRecordDefinedConstantPrimary();
extern int ilRecordDefinedConstantSecondary();
extern int ilAllocLowestFreeBit8();
extern int ilNextCounterValue();
extern int ilPopFreeRegister();
extern int ilEmitProjectiveDivide();
extern int ilEmitShadowCompare();
extern int FUN_000c7930();
extern int ilEmitPrologue();
extern int FUN_000c8600();
extern int ilRemapSourceOperandRegister();
extern int ilMarkOperandRegisterUsed();
extern int ilMarkInstructionRegistersUsed();
extern int ilCopyInstructionRemapped();
extern int ilPushDclRecord();
extern void ilStoreFloat4Constant(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int ilAssembleProgram();
extern int ilRewriteForTextureState();
extern int FUN_000cd05c();
extern int scDestroy();
extern int FUN_000cd1b0();
extern int FUN_000cd1c4();
extern int scCheckHandle();
extern int scDisassembleIL();
extern int scDumpSrcShader();
extern int scDumpShader();
extern int scDumpShaderToString();
extern int FUN_000cd290();
extern int scDisassembleILImpl();
extern int scLogToSink();
extern int scDumpSrcShaderImpl();
extern int scDumpShaderImpl();
extern int scDumpShaderToStringImpl();
extern int noop_cdc20();
extern int scShaderStateFlag();
extern char * FUN_000cdc3c(undefined4 param_1,int param_2,char *param_3,double fparam_1);
extern int vsdisClearSinkRecord();
extern int vsdisClearSinkRecord2();
extern int FUN_000ce050();
extern int FUN_000ce148();
extern int vsdisPrintInputDx();
extern int vsdisPrintOutputMapping();
extern int vsdisPrintShaderData();
extern int FUN_000cea6c();
extern int FUN_000ced58();
extern int FUN_000cf2ec();
extern int vsdisFlowOpcodeName();
extern int vsdisPrintFlowInstruction();
extern int vsDisassembleLine();
extern int vsDisassemble();
extern int vsDisassembleToString();
extern int vsDisassembleVertexProgram();
extern int psnReportError();
extern int psnFormatRegister();
extern int psnFormatRgbSource();
extern int psnFormatAlphaSource();
extern int psnNormalizeProgram();
extern int psnSwizzleIsAlphaSourceForm();
extern double FUN_000d10dc(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1);
extern int FUN_000d13a4();
extern int FUN_000d1624();
extern int FUN_000d183c();
extern int psnClearSinkRecord();
extern int psnClearSinkRecord2();
extern int scDumpPixelProgramPsn();
extern int scDumpPixelProgramToStringStub();
extern int scDumpPixelProgram();
extern int ffpsBuildRgbSourceOperand();
extern int ffpsBuildAlphaSourceOperand();
extern int FUN_000d5390();
extern int FUN_000d55c0();
extern int ffpsEmitDeclarations();
extern int ffpsEmitTexEnvCombine();
extern int ffpsEmitTexEnvLegacy();
extern int FUN_000d8450();
extern int FUN_000d9b58();
extern undefined4 scStoreConstantComponent(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,double fparam_1);
extern int FUN_000d9c90();
extern int FUN_000d9d74();
extern int FUN_000d9e58();
extern int FUN_000d9e98();
extern int FUN_000d9f3c();
extern int FUN_000d9f80();
extern int FUN_000d9fa0();
extern int FUN_000d9fc0();
extern int FUN_000d9fe0();
extern int FUN_000da028();
extern int FUN_000da070();
extern int FUN_000da09c();
extern int FUN_000da0c0();
extern int scSetCallbackTables();
extern int FUN_000da420();
extern int FUN_000da438();
extern int scDestroyCompilerObject();
extern int FUN_000da4b8();
extern double FUN_000da78c(uint param_1,double fparam_1);
extern int ildisInitContext();
extern int ildisSkipToken();
extern int ildisSetIndent();
extern int returnZero_da8f4();
extern int returnZero_da8fc();
extern int ildisAppendf();
extern int ildisFlushLine();
extern int ildisAppendIndentedf();
extern int ildisPrintNegateComponents();
extern int ildisComponentSelectChar();
extern int ildisPrintSwizzle();
extern int ildisPrintResultModifiers();
extern int ildisPrintElementFormat();
extern int ildisPrintFormatXyzw();
extern int ildisModComponentChar();
extern int ildisPrintDestinationWriteMask();
extern int ildisPrintUnsigned();
extern int ildisPrintCmpVal();
extern int ildisPrintUsage();
extern void ildisPrintFixedPoint(undefined4 param_1,uint param_2,uint param_3,uint param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12);
extern int ildisPrintTexelOffsets();
extern int ildisPrintSignedField();
extern int ildisPrintAddressOffsetImmediate();
extern int ildisPrintResourceSampler();
extern int ildisPrintAnisoMode();
extern int ildisPrintMipFilter();
extern int ildisPrintFilterName();
extern int ildisPrintFilterModes();
extern int ildisPrintShadowMode();
extern int ildisPrintBoundComponent();
extern int ildisPrintDclvoutOperands();
extern int ildisPrintDclpinOperands();
extern int ildisPrintDclvOperands();
extern int ildisPrintDclpiOperands();
extern int ildisPrintResourceType();
extern int ildisPrintDclptCoordMode();
extern int ildisPrintDcldefComponent();
extern int ildisPrintDcldefComponents();
extern int ildisPrintZeroOp();
extern int ildisPrintOutputTopology();
extern int ildisPrintInputPrimitive();
extern int ildisPrintStage();
extern int ildisPrintTexldmsModifiers();
extern int ildisPrintNormalizeFlag();
extern int ildisPrintRoundFlag();
extern int ildisPrintSampleFlag();
extern int ildisPrintCentroidFlag();
extern int ildisPrintSampleModifiers();
extern int ildisPrintLoadModifiers();
extern int ildisPrintMatrixMode();
extern int ildisPrintRelop();
extern int ildisPrintHeader();
extern int ildisPrintRegisterType();
extern int ildisPrintSourceOperand();
extern int ildisPrintDestinationOperand();
extern int ildisPrintDestAnd3Sources();
extern int ildisPrintDestAnd2Sources();
extern int ildisPrintDestAnd1Source();
extern int ildisPrintInstruction();
extern int ildisRun();
extern int ildisPrintProgram();
extern int ildisDisassembleTokens();
extern int ildisDisassembleBody();
extern int Compiler__setOptionBit();
extern int Compiler__clearOptionBit();
extern int Compiler__isOptionEnabled();
extern int FUN_000e0830();
extern int FUN_000e0850();
extern int FUN_000e0ca8();
extern int testBit24();
extern int FUN_000e0cd0();
extern int Compiler__logf();
extern int FUN_000e0e28();
extern int noop_e0e9c();
extern int noop_e0ea0();
extern int isWhitespaceChar();
extern int Compiler__setOption();
extern int noop_e1388();
extern int noop_e138c();
extern int FUN_000e13a8();
extern int FUN_000e13b4();
extern int FUN_000e144c();
extern int Compiler__timerOutputFileName();
extern int Compiler__releaseOutputBuffer();
extern int Compiler__setTableEntry534();
extern int FUN_000e14e4();
extern int Compiler__fail();
extern int Compiler__allocateOrFail();
extern int Compiler__propagateFlag5a1Bit1();
extern int Compiler__selectEntry534ByProgramFlags();
extern int FUN_000e161c();
extern int Compiler__selectBlockByProgramFlags();
extern int Compiler__setBitInSelectedBlockB8();
extern int Compiler__setBitInSelectedBlockD8();
extern int Compiler__setBitInSelectedBlock98();
extern int FUN_000e180c();
extern int Compiler__resetState();
extern int FUN_000e1920();
extern int FUN_000e1a48();
extern int Compiler__setHardwareFamily();
extern int Program__forwardMulOperandToUsers();
extern int Compiler__releaseChipAndPools();
extern int FUN_000e2094();
extern int FUN_000e2524();
extern int FUN_000e2668();
extern int FUN_000e2780();
extern int FUN_000e280c();
extern int FUN_000e2838();
extern int FUN_000e284c();
extern int Block__accept();
extern int IfFooterStatic__accept();
extern int FUN_000e2a04();
extern int moduloDifference();
extern int IRStartCallRoutine__acceptCallPseudo();
extern int IREndCallRoutine__acceptCallPseudo();
extern int IRStartMakeCall__acceptCallPseudo();
extern int IREndMakeCall__acceptCallPseudo();
extern int FUN_000e2acc();
extern int FUN_000e2b68();
extern int FUN_000e2bf4();
extern int ConstRecord__emitStores();
extern int FUN_000e2ee4();
extern int FUN_000e2f04();
extern int IRInst__lastSourceKeyEquals();
extern int MachineAssembler__vslot34_declareDestinationLanesByClass();
extern int MachineAssembler__visitIfHeaderStatic();
extern int FUN_000e3244();
extern int FUN_000e3308();
extern int FUN_000e33cc();
extern int FUN_000e3544();
extern int MachineCodeWriter__encodeProgram();
extern int IRInst__createMovForDest();
extern int FUN_000e3af4();
extern int FUN_000e3b88();
extern int FUN_000e43ec();
extern int setWord30();
extern int ILReader__currentOpcode();
extern int ILReader__lookupBoolConst();
extern int ILReader__appendIntConst();
extern int ILReader__readFloatConst();
extern int FUN_000e468c();
extern int FUN_000e4710();
extern int ILReader__appendBoolConst();
extern void ILReader__appendFloatConst(int *param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int FUN_000e47f4();
extern int ILReader__dtor_e4830();
extern int ILReader__dtor_e4934();
extern int ILReader__fetchToken();
extern int ILReader__decodeInstruction();
extern int ILReader__beginRewrittenReplay_e5384();
extern int ILReader__beginRewrittenReplay_e547c();
extern int ILReader__ctor_e5570();
extern int ILReader__ctor_e59f0();
extern int ILReader__nextInstruction();
extern int Block__detach();
extern int Block__appendInst();
extern int Block__prependInst();
extern int Block__insertInstBefore();
extern int Block__insertInstAfter();
extern int Block__isSimple();
extern int LoopHeader__getKindName();
extern int FUN_000e77f4();
extern int Block__getBranchInst();
extern int Block__setField0xb8AndChildren();
extern int Block__isAncestorOf();
extern int Block__nearestCommonAncestor();
extern int Block__vectorF8NonEmpty();
extern int Block__hasMultipleSuccessors();
extern int FUN_000e79b8();
extern int Block__successorCount();
extern int Block__predecessorCount();
extern int Block__hasSuccessors();
extern int Block__vectorD4NonEmpty();
extern int Block__hasDominatedChildren();
extern int Block__popDefinitions();
extern int FUN_000e7a9c();
extern int FUN_000e7b9c();
extern int Block__resolveRedirect();
extern int EntryBlock__insertInstruction();
extern int FUN_000e7d5c();
extern int Block__isInVectorD4Of();
extern int Block__findSimplePredecessor();
extern int Block__findSimpleSuccessor();
extern int FUN_000e7fe0();
extern int Block__predecessorIndex();
extern int Block__phiOperandIndexForPredecessor();
extern int FUN_000e80cc();
extern int Program__allocateBitSetIndex();
extern int FUN_000e83bc();
extern int FUN_000e8424();
extern int Block__verify();
extern int LoopHeader__verify();
extern int IfHeader__canFlatten();
extern int Block__createEntryExitInsts();
extern int FUN_000e8a08();
extern int FUN_000e8bac();
extern int FUN_000e8c14();
extern int FUN_000e8c7c();
extern int FUN_000e8ce4();
extern int Block__appendPredecessor();
extern int Block__appendSuccessor();
extern int Block__connect();
extern int Block__replaceRegionEdges();
extern int FUN_000e910c();
extern int Block__getPredecessor();
extern int Block__getSuccessor();
extern int FUN_000e9294();
extern int Block__bypass();
extern int Block__bypassAndDetach();
extern int FUN_000e977c();
extern int FUN_000e9910();
extern int FUN_000e9948();
extern int FUN_000e9adc();
extern int Block__recordDefinition();
extern int FUN_000e9cc8();
extern int Block__ctor_e9d68();
extern int Block__clone();
extern int Block__ctor_e9f00();
extern int Block__ctor_ea020();
extern int Block__ctor_ea148();
extern int Block__dtor_ea270();
extern int AnyBlock__ctor_ea3c0();
extern int AnyBlock__ctor_ea478();
extern int IfHeader__ctor_ea530();
extern int IfHeader__ctor_ea600();
extern int IfHeader__ctor_ea6d0();
extern int PostLoopFooter__ctor_ea828();
extern int ExitBlock__ctor_eaae8();
extern int ExitBlock__ctor_eab2c();
extern int EntryBlock__ctor_eab70();
extern int EntryBlock__ctor_eabbc();
extern int BreakOrContinueBlock__ctor_eac08();
extern int BreakOrContinueBlock__ctor_eac60();
extern int PostLoopFooter__ctor_eacb8();
extern int PostLoopFooter__clone();
extern int PostLoopFooter__ctor_ead80();
extern int LoopFooter__ctor_eadd0();
extern int LoopFooter__clone();
extern int LoopFooter__ctor_eae98();
extern int LoopHeader__ctor_eaee8();
extern int LoopHeader__clone();
extern int LoopHeader__ctor_eafe4();
extern int IfFooter__ctor_eb068();
extern int IfFooter__clone();
extern int IfFooter__ctor_eb124();
extern int IfHeader__ctor_eb168();
extern int IfHeader__clone();
extern int IfHeader__ctor_eb248();
extern int FuncEndBlock__ctor_eb2b0();
extern int FuncEndBlock__clone();
extern int FuncEndBlock__ctor_eb378();
extern int PostLoopFooter__ctor_eb3c8();
extern int IfHeader__ctor_eb688();
extern int IfFooterStatic__ctor_eb7e0();
extern int IfFooterStatic__ctor_eb824();
extern int IfFooterStatic__clone();
extern int IfHeaderStatic__ctor_eb8e0();
extern int IfHeaderStatic__ctor_eb924();
extern int IfHeaderStatic__clone();
extern int IfHeaderStatic__ctor_eb9e0();
extern int IfHeaderStatic__ctor_ebac8();
extern int Block__dtor();
extern int Block__deleting_dtor();
extern int BreakBlock__ctor_ebe70();
extern int BreakBlock__ctor_ebeb4();
extern int BreakBlock__clone();
extern int ContinueBlock__ctor_ebf70();
extern int ContinueBlock__ctor_ebfb4();
extern int ContinueBlock__clone();
extern int BreakBlock__ctor_ec070();
extern int BreakBlock__ctor_ec0c8();
extern int ContinueBlock__ctor_ec120();
extern int ContinueBlock__ctor_ec178();
extern int FUN_000ec1d0();
extern int callTargetSlot25();
extern int Program__registerFileOfIlType();
extern int Program__interpSlotOfIlType();
extern int Program__lookupTable8b68();
extern int Program__laneKindOfInterpSlot();
extern int Table__interpolatorKindToCode();
extern int Program__freeWorkArrays();
extern int Program__insertBlockBefore();
extern int Program__insertBlockAfter();
extern int FUN_000ec3e8();
extern int FUN_000ec42c();
extern int FUN_000ec468();
extern int FUN_000ec4f0();
extern int Program__getBlocksArray();
extern int FUN_000ec658();
extern int FUN_000ec6b0();
extern int FUN_000ec728();
extern int FUN_000ec8e4();
extern int FUN_000ec920();
extern int KhanVs__vslot17_isSimpleInst();
extern int KhanPs__vslot17_isSimpleInst();
extern int FUN_000ecb90();
extern int IRInst__isForwardable();
extern int FUN_000ecd28();
extern int FUN_000eced0();
extern int FUN_000ecfac();
extern int FUN_000ed124();
extern int HwLimits__vslot43_prependDefaultMov();
extern int IRInst__bindOperandRegisters();
extern int Program__beginPass();
extern int FUN_000ed89c();
extern int Program__ctor_edd98();
extern int Program__ctor_ee29c();
extern int FUN_000ee7a0();
extern int Program__addInst();
extern int FUN_000eea24();
extern int FUN_000eec50();
extern int FUN_000eee4c();
extern int FUN_000ef204();
extern int FUN_000ef498();
extern int Program__appendToVector3c8();
extern int Program__removeInst();
extern int FUN_000efa4c();
extern int Program__insertExitMarkerAndFlagBlocks();
extern int FUN_000f019c();
extern int FUN_000f04d4();
extern int FUN_000f07a8();
extern int FUN_000f14f8();
extern int FUN_000f1d7c();
extern int FUN_000f29f4();
extern int SelectWord__compose();
extern int SelectWord__isSplat();
extern int FUN_000f2cac();
extern int FUN_000f2d08();
extern int SelectWord__areCompatible();
extern int SelectWord__matches();
extern int FUN_000f2e18();
extern int laneBytes__mapTwoThreeToOne();
extern int laneBytes__mergeOneAndTwo();
extern int SelectWord__markLanesWhereSecondIsOne();
extern int SelectWord__mergeWrittenLanes();
extern int SelectWord__fillUnusedLanes();
extern int SelectWord__markEqualLanes();
extern int laneBytes__commonSelect();
extern int SelectWord__firstWrittenComponent();
extern int SelectWord__firstUnwrittenComponent();
extern int FUN_000f313c();
extern int FUN_000f3154();
extern int SelectWord__isIdentity();
extern int IRInst__isSourceSelectIdentity();
extern int SelectWord__selectWhereMasked();
extern int SelectWord__clearReadComponents();
extern int FUN_000f32cc();
extern int SelectWord__maskUnused();
extern int SelectWord__readMask();
extern int SelectWord__fillUnusedWithFirstUsed();
extern int FUN_000f3470();
extern int IRInst__clearSourceSelectsOfUnwrittenComponents();
extern int FUN_000f366c();
extern int WriteMask__fromUsedLanes();
extern int FUN_000f370c();
extern int laneBytes__clearSetLanes();
extern int SelectWord__splatComponent();
extern int SelectWord__isSingleComponentConstant();
extern int IRInst__destIsSingleComponent();
extern int laneMask__fromSelectBytes();
extern int WriteMask__fromSelectWord();
extern int FUN_000f3968();
extern int FUN_000f39d0();
extern int IRInst__countWrittenComponents();
extern int FUN_000f3a90();
extern int FUN_000f3ae0();
extern int FUN_000f3b10();
extern int FUN_000f3b68();
extern int FUN_000f3bc0();
extern int IRInst__computeSourceLaneMask();
extern int IRInst__computeSourceReadMask();
extern int FUN_000f45f8();
extern int IRInst__maskUnusedLanesOfOperand();
extern int FUN_000f472c();
extern int FUN_000f47a8();
extern int FUN_000f485c();
extern int IRInst__sourceLanesAllWritten();
extern int FUN_000f497c();
extern int FUN_000f4a24();
extern int FUN_000f4a5c();
extern int isRegKindBelow21();
extern int FUN_000f4a84();
extern int floatLess();
extern int BitSet__findFirstSet();
extern int noop_f4c44();
extern int ConstKey__compareOrdered();
extern int ConstKey__countPresentOperands();
extern int FUN_000f4d80();
extern int ConstRecord__insertSwizzleVariants();
extern int Compiler__getOrCreateLoadConstN();
extern int FUN_000f5248();
extern int Compiler__getOrCreateLoadConst3();
extern int Compiler__getOrCreateLoadConst2();
extern int Compiler__getOrCreateLoadConst1();
extern int RegisterMap__findConstVector();
extern int IRInst__canFoldConstantSource();
extern int IRInst__sourceMatchesConstant();
extern int IRInst__getUniformSourceConstant();
extern int FUN_000f5e8c();
extern int RegisterMap__findConstVectorExact();
extern int FUN_000f60c4();
extern int Compiler__getOrCreateConstVectorN();
extern int Compiler__getOrCreateConstVector4();
extern int Compiler__getOrCreateConstVector3();
extern int Compiler__getOrCreateConstVector2();
extern int Compiler__getOrCreateConstVector1();
extern int Program__findOrCreateConstInst();
extern int IRInst__setConstantOperand();
extern int IRInst__makeLiteralVec4Int();
extern int IRInst__setIntConstantOperand4();
extern void IRInst__makeLiteralVec4Float(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int FUN_000f7b10();
extern int FUN_000f7bf4();
extern int FUN_000f7cd8();
extern int DominatorTree__computeDominanceFrontiers();
extern int FUN_000f7f1c();
extern int FUN_000f8044();
extern int DominatorTree__dfsNumber();
extern int DominatorTree__compress();
extern int DominatorTree__eval();
extern int DominatorTree__compute();
extern int FUN_000f88b4();
extern int FUN_000f8960();
extern int FUN_000f8970();
extern int FUN_000f8980();
extern int FUN_000f8994();
extern int FUN_000f89a4();
extern int tableWordOrEight();
extern int remapSelect1To0();
extern int remapSelectSmall();
extern double IRInst__literalForLane(int param_1,int param_2,int param_3,int param_4);
extern int Program__applySourceTokenToOperand();
extern int FUN_000f8c88();
extern int FUN_000f8ccc();
extern int FUN_000f8d50();
extern int IRInst__applyDescriptorSwizzle();
extern int FUN_000f9038();
extern int FUN_000f9140();
extern int Program__appendInst();
extern int FUN_000f94dc();
extern int FUN_000f9a58();
extern int FUN_000fa958();
extern int FUN_000fadc4();
extern int Program__createConstantVReg();
extern int FUN_000fb230();
extern int FUN_000fb3d4();
extern int FUN_000fd50c();
extern int FUN_000fd5c8();
extern int IROperand__setModifierBits();
extern int floatToFixedSaturate(undefined4 param_1,int param_2,uint param_3,double fparam_1);
extern double constantZeroFloat( void);
extern int isLessThan2();
extern int setSelectedConstantWord();
extern int IRInst__cloneInto();
extern int IRInst__saveCounters();
extern int IRInst__restoreCounters();
extern int IRInst__copyBodyFrom();
extern int operandsHaveSameConstant();
extern int IRInst__unlinkAndClearFlag0();
extern int IRInst__useCount();
extern int RegKind__vectorWidthKind();
extern int RegKind__laneCount();
extern int IRLoadInterp__setLaneKindAndIndex();
extern int IRLoadInterp__laneIndex_104180();
extern int IRLoadInterp__setLane();
extern int IRLoadInterp__laneIndex();
extern int IRInst__firstOperandWithSelectNot4();
extern int IRVertexFetch__initSemantics();
extern int FUN_00104364();
extern int IRInst__vslot28_hasFlag0x4000AndClass0x24();
extern int instClassTableIsIdentity();
extern int IRInst__create();
extern int IRInst__clone();
extern int IRInst__replaceExtraData();
extern int IRInst__allSelectsAreHwConstants();
extern int IRInst__isProjectionOfClass26or3a();
extern int IRInst__isProjectionOfClass44();
extern int IRInst__setHardwareRegisterAndAdd();
extern int IRInst__setOperandRef();
extern int IROperand__copyFrom();
extern int IROperand__copyModifiersAndSelect();
extern int Inst__isBeforeOrSame();
extern int Inst__nearestCommonAncestorBlock();
extern void IRInst__setExtraFixed3_4_1048d4(int param_1,double fparam_1);
extern void IRInst__setExtraFixed3_4_10490c(int param_1,double fparam_1);
extern void IRInst__setExtraFixed3_4_104944(int param_1,double fparam_1);
extern int IRInst__hasSingleUse();
extern int IRInst__hasTwoUses();
extern int IRInst__hasNoUses();
extern int IRInst__appendSource();
extern int IRLoadInterp__laneUsed();
extern int IRLoadInterp__laneSelects();
extern int IRLoadInterp__laneKind();
extern int IROperand__init();
extern int IRInst__initOperandRecord();
extern int IRInst__resetFields();
extern int IRInst__readLastOperand();
extern int IRInst__applyChannelMask();
extern int IRLoadConst__removeFromListEx();
extern int IRLoadInterp__laneKind_104ee4();
extern int IRInst__switchOpcodeVariant();
extern int IRInst__opcodeIsInSet();
extern int IRInst__ctor_10502c();
extern int IRInst__ctor_1051b0();
extern int IRInst__setOperandSourceRaw();
extern int IRInst__getOperandRecord();
extern int IRInst__getOperandSource();
extern int IRInst__isProjectionOfOpcode2a();
extern int IRInst__deleteIfUnused();
extern int IRInst__dropCounterAndDeleteIfUnused();
extern int IRInst__decrementSourceUseCounts();
extern int IRInst__removeFromSourceUserLists();
extern int IRInst__removeFromList();
extern int IRInst__detachWhenTracking();
extern int IRInst__removeFromListEx();
extern int IRInst__getDefiningField128();
extern int IRInst__firstLiteralSourceValue();
extern int IRInst__operandKindClass();
extern int IRInst__copyOperandFrom();
extern int IRInst__appendOperandRef();
extern int IRInst__addToUseLists();
extern int IRInst__setOperandSource();
extern int IRInst__replaceOperandsReferencing();
extern int IRInst__setOperandSourceIfLegal();
extern int IRInst__getOrCreateOperandRecord();
extern int IRInst__validate();
extern int IRProjection__validate();
extern int IRPresub2__validate();
extern int IRPhiNode__validate();
extern int IRInst__setExtraOperandSource();
extern int IRInst__insertSourceBeforeLast();
extern int IRInst__setLastOperandFromRecord();
extern int IRMix__validate();
extern int IRPresub1__validate();
extern int IRInst__isCoalescableMov();
extern int IRFetch__ctor_106ffc();
extern int IRFetch__ctor_10704c();
extern int IRPseudo__ctor_10709c();
extern int IRPseudo__ctor();
extern int IRAlu__ctor_107154();
extern int IRAlu__ctor_1071a8();
extern int IRMemStore__ctor_1071fc();
extern int IRVertexFetch__ctor_107250();
extern int IRVertexFetch__ctor_1072d0();
extern int IRVertexFetch__new();
extern int IRVertexFetch__ctor_1073dc();
extern int IRVertexFetch__ctor_107420();
extern int IRLoadConst__vslot75();
extern int IRTextureFetch__ctor_1074e0();
extern int IRTextureFetchGradients__ctor_107600();
extern int IRTextureFetch__ctor_10764c();
extern int IRTextureFetch__new();
extern int IRLoadConst__vslot59();
extern int IRTextureFetchGradients__ctor_107864();
extern int IRLoadConst__vslot71();
extern int IRMemLoad__ctor_10792c();
extern int IRMemLoad__ctor_107980();
extern int IRMemStore__ctor_1079d4();
extern int IRZeroary__ctor_107a28();
extern int IRNop__ctor_107a74();
extern int IRLoadConst__vslot41();
extern int IRNop__ctor_107b4c();
extern int IRZeroary__ctor_107ba8();
extern int IRZeroary__new();
extern int IRLoadConst__vslot51();
extern int IRUnary__ctor_107cec();
extern int IRMov__ctor_107d38();
extern int IRInst__reinitAsUnary();
extern int IRUnary__new_107df4();
extern int IRLoadConst__vslot43();
extern int IRBinary__ctor_107eec();
extern int IRKill2__ctor_107f38();
extern int IRCmp2__ctor_107fd0();
extern int IRLoadConst__vslot55();
extern int IRCmp2__ctor_1080e0();
extern int IRInst__reinitAsBinary();
extern int IRBinary__new_1081c0();
extern int IRLoadConst__vslot47();
extern int IRTrinary__ctor_1082b8();
extern int IRInst__reinitAsTrinary();
extern int IRTrinary__new_108350();
extern int IRLoadConst__vslot49();
extern int IRInst__reinitAsMov();
extern int IRMov__new_1084b8();
extern int IRLoadConst__vslot45();
extern int IRExport__ctor_1085b0();
extern int IRGeomExport__ctor_1086e8();
extern int IRGeomExport__ctor_108770();
extern int IRGeomExport__ctor_1087f0();
extern int IRExportColorAndFog__ctor_108870();
extern int IRExportColorAndFog__ctor_1088c4();
extern int IRExport__ctor_108918();
extern int IRGeomExport__ctor_108a50();
extern int IRLoadConst__vslot77();
extern int IRKill2__ctor_108b54();
extern int IRLoadConst__vslot53();
extern int IRHeader__ctor_108c68();
extern int IRHeader__ctor_108cbc();
extern int IREntry__ctor_108d10();
extern int IREntry__ctor_108d5c();
extern int IRExit__ctor_108da8();
extern int IRExit__ctor_108df4();
extern int IRLoad__ctor_108e40();
extern int IRUndefined__ctor_108e8c();
extern int IRLoadConst__vslot63();
extern int IRUndefined__ctor_108f5c();
extern int IRUndefined__ctor_108fb0();
extern int IRUndefined__ctor_10900c();
extern int IRLoadMemBufferIndex__ctor_109068();
extern int IRLoadMemBufferIndex__ctor_1090b4();
extern int IRLoadMemBuffer__ctor_109100();
extern int IRLoadMemBuffer__ctor_10914c();
extern int IRLoadInterp__ctor_109198();
extern int IRLoadInterp__ctor_109270();
extern int IRLoadTemp__ctor_109348();
extern int IRLoadTemp__ctor_1093b8();
extern int IRLoadTemp__ctor_109428();
extern int IRLoadTemp__new_109480();
extern int IRLoadTemp__ctor_1094fc();
extern int IRLoadTemp__ctor_109554();
extern int IRLoadTemp__ctor_1095b4();
extern int IRLoadConst__ctor_109614();
extern int IRLoadConst__ctor_1096bc();
extern int IRLoadVertex__ctor_109764();
extern int IRLoadVertex__new_109810();
extern int IRLoadVertex__ctor_10988c();
extern int IRLoadConst__ctor_109938();
extern int IRLoadConst__ctor_1099dc();
extern int IRLoad__ctor_109a80();
extern int IRImmedConstBuff__ctor_109acc();
extern int IRImmedConstBuff__ctor_109b20();
extern int IRImmedConstBuff__new_109b74();
extern int IRMerge__ctor_109bf0();
extern int IRMerge__ctor_109c4c();
extern int IRMerge__ctor_109ca8();
extern int IRMerge__ctor_109cfc();
extern int IRLoadConst__vslot79();
extern int IRProjection__ctor_109dcc();
extern int IRProjection__ctor_109e28();
extern int IRLoadConst__vslot61();
extern int IRPresub1__ctor_109f00();
extern int IRPresub1__ctor_109f50();
extern int IRLoadConst__vslot67();
extern int IRPresub2__ctor_10a01c();
extern int IRPresub2__ctor_10a070();
extern int IRLoadConst__vslot69();
extern int IRMix__ctor_10a140();
extern int IRMix__ctor_10a1c0();
extern int IRLoadConst__vslot73();
extern int IRPhiNode__ctor_10a2bc();
extern int IRPhiNode__ctor_10a398();
extern int IRLoopStart__ctor_10a474();
extern int IRLoopStart__ctor_10a50c();
extern int IRLoadConst__vslot65();
extern int IRCmp1S__ctor_10a620();
extern int IRCmp1S__ctor_10a6bc();
extern int IRLoadConst__vslot57();
extern int IRStartMakeCall__ctor_10a7d4();
extern int IRStartMakeCall__ctor_10a83c();
extern int IRStartCallRoutine__ctor_10a8a4();
extern int IRStartCallRoutine__ctor_10a90c();
extern int IREndMakeCall__ctor_10a974();
extern int IREndMakeCall__ctor_10a9cc();
extern int IREndCallRoutine__ctor_10aa24();
extern int IREndCallRoutine__ctor_10aa7c();
extern double outputScaleFromExponent(int param_1);
extern undefined4 isOutputScaleValue(double fparam_1);
extern int outputScaleExponent(double fparam_1);
extern undefined4 tryOutputScaleExponent(undefined4 param_1,undefined4 *param_2,double fparam_1);
extern int IRInst__swapOperands();
extern int IRInst__newOpcode8c();
extern int IRInst__replaceBodyKeepLinks();
extern int IRInst__scaleByOutputScale();
extern int IRInst__cloneIfPresub();
extern int IRInst__clampOutputValue();
extern int IRInst__findConstantOperandWithValue(int *param_1,undefined4 param_2,int *param_3,double fparam_1);
extern int IRInst__applyNegateModifier();
extern int IRInst__applyAbsModifier();
extern int IRInst__createCompareConstInst(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,double fparam_1);
extern int IRInst__isOperandConstZero();
extern int IRInst__getCompareCondition();
extern bool evaluateCompareFloats(undefined4 param_1,double fparam_1,double fparam_2);
extern int IRInst__setCompareCondition();
extern int IRInst__foldCompareConstResult();
extern int IRInst__compareResultIsConstant();
extern int IRInst__retargetOpcode();
extern int IRInst__retargetOpcodeFromOperands();
extern void IRInst__setLiteralOperandAndSource(int param_1,undefined4 param_2,int param_3,int param_4,double fparam_1);
extern int IRInst__createWithConstantOperands(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,double fparam_1);
extern int IRInst__reduceTernaryToBinary();
extern int IRInst__removeDefaultSelectOperands();
extern int FUN_0010c47c();
extern int FUN_0010c670();
extern int FUN_0010cb48();
extern int IRInst__foldMovSourceSelect();
extern int IRInst__replaceWithMovOfSource();
extern int IRInst__canonicalizeCommutativeOperands();
extern int IRInst__convertCompareToBinaryAlu();
extern int IRInst__foldConstantFactor();
extern int HwLimits__vslot24_resetBindingTables();
extern int HwLimits__dtor_10dad8();
extern int HwLimits__dtor_10db58();
extern int BitSet__setBit();
extern int BitSet__clearBit();
extern int BitSet__initDefault();
extern int BitSet__testBit();
extern int HwLimits__vslot77_getBindingLimitsDefault();
extern int HwLimits__vslot10_failNotSupported();
extern int HwLimits__vslot20_createInstWithOwner();
extern int FUN_0010dd54();
extern int Compiler__getResourceModel();
extern int Compiler__getThreadModel();
extern int FUN_0010dde4();
extern int KhanPs__vslot16_getConstant0xb5();
extern int HwLimits__vslot8_failNotSupported();
extern int HwLimits__vslot9_failNotSupported();
extern int FUN_0010de6c();
extern int FUN_0010defc();
extern int KhanChip__ctor_10e050();
extern int KhanChip__ctor_10e114();
extern int FudoChip__ctor_10e1d8();
extern int FudoChip__ctor_10e2a0();
extern int FUN_0010e368();
extern int FUN_0010e3b4();
extern int FUN_0010e40c();
extern int FUN_0010e460();
extern int FUN_0010e4ec();
extern int FUN_0010e530();
extern int FUN_0010e55c();
extern int FUN_0010e56c();
extern int FUN_0010e634();
extern int FUN_0010e690();
extern int FUN_0010e6e8();
extern int FUN_0010e744();
extern int FUN_0010e7b8();
extern int FUN_0010e814();
extern int FUN_0010e870();
extern int FUN_0010e8c4();
extern int FUN_0010e8e4();
extern int FUN_0010e95c();
extern int FUN_0010e9d0();
extern int FUN_0010ea30();
extern int FUN_0010ead4();
extern int FUN_0010ecb8();
extern int KhanPs__vslot87_assignInterpolatorBindings();
extern int FUN_0010ef68();
extern int FUN_0010f38c();
extern int FUN_0010f4d4();
extern int FUN_0010f704();
extern int FUN_0010f87c();
extern int FUN_0010fa24();
extern int FUN_0010fb54();
extern int FUN_0010fc88();
extern int FUN_0010fd98();
extern int FUN_0010ff24();
extern int FUN_00110020();
extern int FUN_001102e0();
extern int Program__packPsInputs();
extern int KhanVs__vslot88_assignOutputBindings();
extern int OpcodeTraits__getRecordTail();
extern int Opcode__getInfo();
extern int OpcodeTraits__flagBit0();
extern int FUN_00112fc4();
extern int FUN_00112fd4();
extern int FUN_00112fe4();
extern int OpcodeTraits__flagBit2();
extern int OpcodeTraits__flagBit3();
extern int OpcodeTraits__flagBit6();
extern int OpcodeTraits__flagBit7();
extern int OpcodeTraits__flagBit8();
extern int OpcodeTraits__flagBit9();
extern int OpcodeTraits__flagBit10();
extern int OpcodeTraits__flagBit12();
extern int OpcodeTraits__flagBit13();
extern int OpcodeTraits__getField4();
extern int OpcodeTraits__getInstClass();
extern int OpcodeTraits__getFieldC();
extern int OpcodeTraits__getField34();
extern int OpcodeTraits__instFlagBit2();
extern int OpcodeInfo__getResultMode();
extern double mulFloatZeroAnnihilates(double fparam_1,double fparam_2);
extern int FUN_0011358c();
extern int FUN_001135a8();
extern int FUN_001135c0();
extern int FUN_001135ec();
extern int FUN_0011363c();
extern int FUN_00113690();
extern int FUN_001136e4();
extern int FUN_0011370c();
extern int FUN_00113734();
extern int FUN_0011379c();
extern int IrRecipSqrtClamp__opcodeInfo_atexit_dtor_op65();
extern int IrRecipSqrtFF__opcodeInfo_atexit_dtor_op66();
extern int IrRecipSqrtIEEE__opcodeInfo_atexit_dtor_op67();
extern int IrRecipClamp__opcodeInfo_atexit_dtor_op62();
extern int IrRecipFF__opcodeInfo_atexit_dtor_op63();
extern int IrRecipIEEE__opcodeInfo_atexit_dtor_op64();
extern int IrMulFloat__opcodeInfo_atexit_dtor_op19();
extern int IrMul__opcodeInfo_atexit_dtor_op54();
extern int IrLogClamp__opcodeInfo_atexit_dtor_op58();
extern int IrLogIEEE__opcodeInfo_atexit_dtor_op59();
extern int IrLoopStart__opcodeInfo_atexit_dtor_001fb478();
extern int IrLoopStart__opcodeInfo_atexit_dtor_op129();
extern int IrDot2Add__opcodeInfo_atexit_dtor_op30();
extern int IrAdd__opcodeInfo_atexit_dtor_op52();
extern int IrOpDp__opcodeInfo_atexit_dtor_op151();
extern int IrAllocInterp__opcodeInfo_atexit_dtor_op150();
extern int IrAllocColor__opcodeInfo_atexit_dtor_op149();
extern int IrAllocMem__opcodeInfo_atexit_dtor_op148();
extern int IrAllocPos__opcodeInfo_atexit_dtor_op147();
extern int IrEndMakeCall__opcodeInfo_atexit_dtor_op146();
extern int IrEndCall__opcodeInfo_atexit_dtor_op145();
extern int IrStartMakeCall__opcodeInfo_atexit_dtor_op144();
extern int IrStartCallRoutine__opcodeInfo_atexit_dtor_op143();
extern int IrPhi__opcodeInfo_atexit_dtor_op142();
extern int IrCmp1S__opcodeInfo_atexit_dtor_op141();
extern int IrCmp1D__opcodeInfo_atexit_dtor_op140();
extern int IrCmp2__opcodeInfo_atexit_dtor_op139();
extern int IrEpilog__opcodeInfo_atexit_dtor_op138();
extern int IrProlog__opcodeInfo_atexit_dtor_op137();
extern int IrExit__opcodeInfo_atexit_dtor_op136();
extern int IrEntry__opcodeInfo_atexit_dtor_op135();
extern int IrHeader__opcodeInfo_atexit_dtor_op134();
extern int IrUndefined__opcodeInfo_atexit_dtor_op133();
extern int IrProjection__opcodeInfo_atexit_dtor_op132();
extern int IrMerge__opcodeInfo_atexit_dtor_op131();
extern int IrPixelLoopFetch__opcodeInfo_atexit_dtor_op128();
extern int IrVertexLoopFetch__opcodeInfo_atexit_dtor_op127();
extern int IrLoadInterp__opcodeInfo_atexit_dtor_op126();
extern int IrLoadTempDefault__opcodeInfo_atexit_dtor_op125();
extern int IrLoadAbstractState__opcodeInfo_atexit_dtor_op124();
extern int IrLoadPhysical__opcodeInfo_atexit_dtor_op123();
extern int IrLoadTemp__opcodeInfo_atexit_dtor_op122();
extern int IrLoadConst__opcodeInfo_atexit_dtor_op121();
extern int IrMovaFloorInt__opcodeInfo_atexit_dtor_op193();
extern int IrMovaFloorGprInt__opcodeInfo_atexit_dtor_op192();
extern int IrMovaFloorFloat__opcodeInfo_atexit_dtor_op191();
extern int IrMovaFlr__opcodeInfo_atexit_dtor_op166();
extern int IrMovaFloor__opcodeInfo_atexit_dtor_op100();
extern int IrSubPrev__opcodeInfo_atexit_dtor_op98();
extern int IrMulPrev2__opcodeInfo_atexit_dtor_op97();
extern int IrMulPrev__opcodeInfo_atexit_dtor_op96();
extern int IrAddPrev__opcodeInfo_atexit_dtor_op95();
extern int IrPredSetRst__opcodeInfo_atexit_dtor_op90();
extern int IrPredSetClr__opcodeInfo_atexit_dtor_op89();
extern int IrPredSetPop__opcodeInfo_atexit_dtor_op88();
extern int IrPredSetInv__opcodeInfo_atexit_dtor_op87();
extern int IrPredSetGEInt__opcodeInfo_atexit_dtor_op212();
extern int IrPredSetGE__opcodeInfo_atexit_dtor_op86();
extern int IrPredSetLEInt__opcodeInfo_atexit_dtor_op215();
extern int IrPredSetLTInt__opcodeInfo_atexit_dtor_op214();
extern int IrPredSetGTInt__opcodeInfo_atexit_dtor_op211();
extern int IrPredSetGT__opcodeInfo_atexit_dtor_op85();
extern int IrPredSetNEInt__opcodeInfo_atexit_dtor_op213();
extern int IrPredSetNE__opcodeInfo_atexit_dtor_op84();
extern int IrPredSetEInt__opcodeInfo_atexit_dtor_op210();
extern int IrPredSetE__opcodeInfo_atexit_dtor_op83();
extern int IrKillOne__opcodeInfo_atexit_dtor_op82();
extern int IrCos__opcodeInfo_atexit_dtor_op77();
extern int IrSin__opcodeInfo_atexit_dtor_op76();
extern int IrSubConst1__opcodeInfo_atexit_dtor_op75();
extern int IrMulConst1__opcodeInfo_atexit_dtor_op74();
extern int IrAddConst1__opcodeInfo_atexit_dtor_op73();
extern int IrSubConst0__opcodeInfo_atexit_dtor_op72();
extern int IrMulConst0__opcodeInfo_atexit_dtor_op71();
extern int IrAddConst0__opcodeInfo_atexit_dtor_op70();
extern int IrFetchTextureMapGradients__opcodeInfo_atexit_dtor_op120();
extern int IrFetchTextureMapKill__opcodeInfo_atexit_dtor_op119();
extern int IrSetGE_Dx10__opcodeInfo_atexit_dtor_op187();
extern int IrSetE_Dx10__opcodeInfo_atexit_dtor_op185();
extern int IrFetchShaderCall__opcodeInfo_atexit_dtor_op181();
extern int IrScatter__opcodeInfo_atexit_dtor_op180();
extern int IrCmovNE__opcodeInfo_atexit_dtor_op179();
extern int IrCmovGT__opcodeInfo_atexit_dtor_op178();
extern int IrCmovGE__opcodeInfo_atexit_dtor_op177();
extern int IrCmovEQ__opcodeInfo_atexit_dtor_op176();
extern int IrFetchTextureUncached__opcodeInfo_atexit_dtor_op175();
extern int IrFetchTextureLOD__opcodeInfo_atexit_dtor_op174();
extern int IrCndGEInt__opcodeInfo_atexit_dtor_op238();
extern int IrCndGE1__opcodeInfo_atexit_dtor_op172();
extern int IrCndGE__opcodeInfo_atexit_dtor_op244();
extern int IrCndGEFloat__opcodeInfo_atexit_dtor_op37();
extern int IrMad__opcodeInfo_atexit_dtor_op170();
extern int IrR300ExpBaseE__opcodeInfo_atexit_dtor_op169();
extern int IrDxLogp__opcodeInfo_atexit_dtor_op168();
extern int IrR300Expp__opcodeInfo_atexit_dtor_op167();
extern int IrPow__opcodeInfo_atexit_dtor_op165();
extern int IrLoad__opcodeInfo_atexit_dtor_op164();
extern int IrDp3Add__opcodeInfo_atexit_dtor_op163();
extern int IrMix__opcodeInfo_atexit_dtor_op162();
extern int IrDsy1__opcodeInfo_atexit_dtor_op161();
extern int IrDsy__opcodeInfo_atexit_dtor_op160();
extern int IrDsx1__opcodeInfo_atexit_dtor_op159();
extern int IrDsx__opcodeInfo_atexit_dtor_op158();
extern int IrCnd05__opcodeInfo_atexit_dtor_op157();
extern int IrPresubInvert__opcodeInfo_atexit_dtor_op156();
extern int IrPresubAdd__opcodeInfo_atexit_dtor_op155();
extern int IrPresubSub__opcodeInfo_atexit_dtor_op154();
extern int IrPresubBX2Neg__opcodeInfo_atexit_dtor_op153();
extern int IrOpSop__opcodeInfo_atexit_dtor_op152();
extern int IrMinDx10__opcodeInfo_atexit_dtor_op184();
extern int IrMinUInt__opcodeInfo_atexit_dtor_op202();
extern int IrMinInt__opcodeInfo_atexit_dtor_op200();
extern int IrMin__opcodeInfo_atexit_dtor_op61();
extern int IrMinFloat__opcodeInfo_atexit_dtor_op25();
extern int IrMax4__opcodeInfo_atexit_dtor_op24();
extern int IrMaxDx10__opcodeInfo_atexit_dtor_op183();
extern int IrMax__opcodeInfo_atexit_dtor_op60();
extern int IrMaxUInt__opcodeInfo_atexit_dtor_op201();
extern int IrMaxInt__opcodeInfo_atexit_dtor_op199();
extern int IrMaxFloat__opcodeInfo_atexit_dtor_op23();
extern int IrFract__opcodeInfo_atexit_dtor_op57();
extern int IrFractFloat__opcodeInfo_atexit_dtor_op22();
extern int IrAddInt__opcodeInfo_atexit_dtor_op198();
extern int IrAlloc__opcodeInfo_atexit_dtor_op17();
extern int IrCondJmp__opcodeInfo_atexit_dtor_op16();
extern int IrMul__opcodeInfo_atexit_dtor_001fc120();
extern int IrRet__opcodeInfo_atexit_dtor_op15();
extern int IrFloor__opcodeInfo_atexit_dtor_op56();
extern int IrFloorFloat__opcodeInfo_atexit_dtor_op21();
extern int IrMulAddIEEE__opcodeInfo_atexit_dtor_op240();
extern int IrMulAdd__opcodeInfo_atexit_dtor_op241();
extern int IrMulAddFloat__opcodeInfo_atexit_dtor_op20();
extern int IrSubInt__opcodeInfo_atexit_dtor_op203();
extern int IrFetchTextureMapBias__opcodeInfo_atexit_dtor_op118();
extern int IrFetchTextureMapProj__opcodeInfo_atexit_dtor_op117();
extern int IrSetFilter4Weights__opcodeInfo_atexit_dtor_op116();
extern int IrSetGradientsV__opcodeInfo_atexit_dtor_op115();
extern int IrSetGradientsH__opcodeInfo_atexit_dtor_op114();
extern int IrSetTexLod__opcodeInfo_atexit_dtor_op113();
extern int IrGetWeights__opcodeInfo_atexit_dtor_op112();
extern int IrGetGradients__opcodeInfo_atexit_dtor_op111();
extern int IrGetCompTexLod__opcodeInfo_atexit_dtor_op110();
extern int IrGetBorderColorFraction__opcodeInfo_atexit_dtor_op109();
extern int IrFetchMultiSample__opcodeInfo_atexit_dtor_op108();
extern int IrFetchShadowMap__opcodeInfo_atexit_dtor_op107();
extern int IrFetch3DNoiseMap__opcodeInfo_atexit_dtor_op106();
extern int IrFetchTextureMap__opcodeInfo_atexit_dtor_op105();
extern int IrFetchVertex__opcodeInfo_atexit_dtor_op104();
extern int IrSqrt__opcodeInfo_atexit_dtor_op68();
extern int IrExp__opcodeInfo_atexit_dtor_op55();
extern int IrSub__opcodeInfo_atexit_dtor_op53();
extern int IrNop1__opcodeInfo_atexit_dtor_op103();
extern int IrNop__opcodeInfo_atexit_dtor_op51();
extern int IrLit__opcodeInfo_atexit_dtor_op50();
extern int IrMov__opcodeInfo_atexit_dtor_op102();
extern int IrMovFloat__opcodeInfo_atexit_dtor_op49();
extern int IrExportRing__opcodeInfo_atexit_dtor_op249();
extern int IrExport__opcodeInfo_atexit_dtor_op101();
extern int IrExportFloat__opcodeInfo_atexit_dtor_op48();
extern int IrPredSetGEPushInt__opcodeInfo_atexit_dtor_op219();
extern int IrPredSetGEPush__opcodeInfo_atexit_dtor_op47();
extern int IrPredSetGTPushInt__opcodeInfo_atexit_dtor_op218();
extern int IrPredSetGTPush__opcodeInfo_atexit_dtor_op46();
extern int IrPredSetNEPushInt__opcodeInfo_atexit_dtor_op217();
extern int IrPredSetNEPush__opcodeInfo_atexit_dtor_op45();
extern int IrPredSetLEPushInt__opcodeInfo_atexit_dtor_op221();
extern int IrPredSetLTPushInt__opcodeInfo_atexit_dtor_op220();
extern int IrPredSetEPushInt__opcodeInfo_atexit_dtor_op216();
extern int IrPredSetEPush__opcodeInfo_atexit_dtor_op44();
extern int IrMovaRound__opcodeInfo_atexit_dtor_op99();
extern int IrMovaRoundFloat__opcodeInfo_atexit_dtor_op43();
extern int IrSetNEInt__opcodeInfo_atexit_dtor_op209();
extern int IrSetNE__opcodeInfo_atexit_dtor_op94();
extern int IrSetNEFloat__opcodeInfo_atexit_dtor_op42();
extern int IrSetGE_uint__opcodeInfo_atexit_dtor_op208();
extern int IrSetGEInt__opcodeInfo_atexit_dtor_op206();
extern int IrSetGE__opcodeInfo_atexit_dtor_op93();
extern int IrSetGEFloat__opcodeInfo_atexit_dtor_op41();
extern int IrSetGTUint__opcodeInfo_atexit_dtor_op207();
extern int IrSetGTInt__opcodeInfo_atexit_dtor_op205();
extern int IrSetGTDx10__opcodeInfo_atexit_dtor_op186();
extern int IrSetGT__opcodeInfo_atexit_dtor_op92();
extern int IrSetGTFloat__opcodeInfo_atexit_dtor_op40();
extern int IrSetEInt__opcodeInfo_atexit_dtor_op204();
extern int IrSetE__opcodeInfo_atexit_dtor_op91();
extern int IrSetEFloat__opcodeInfo_atexit_dtor_op39();
extern int IrCndGT1__opcodeInfo_atexit_dtor_op173();
extern int IrCndGTInt__opcodeInfo_atexit_dtor_op237();
extern int IrCndGT__opcodeInfo_atexit_dtor_op243();
extern int IrCndGTFloat__opcodeInfo_atexit_dtor_op38();
extern int IrCndE1__opcodeInfo_atexit_dtor_op171();
extern int IrCndEInt__opcodeInfo_atexit_dtor_op236();
extern int IrCndE__opcodeInfo_atexit_dtor_op242();
extern int IrCndEFloat__opcodeInfo_atexit_dtor_op36();
extern int IrKillNE__opcodeInfo_atexit_dtor_op81();
extern int IrKillNEFloat__opcodeInfo_atexit_dtor_op35();
extern int IrKillGE__opcodeInfo_atexit_dtor_op80();
extern int IrKillGEFloat__opcodeInfo_atexit_dtor_op34();
extern int IrKillGT__opcodeInfo_atexit_dtor_op79();
extern int IrKillGTFloat__opcodeInfo_atexit_dtor_op33();
extern int IrKillE__opcodeInfo_atexit_dtor_op78();
extern int IrKillEFloat__opcodeInfo_atexit_dtor_op32();
extern int IrDst__opcodeInfo_atexit_dtor_op31();
extern int IrDot4IEEE__opcodeInfo_atexit_dtor_op222();
extern int IrDot4__opcodeInfo_atexit_dtor_op29();
extern int IrMulHiUInt__opcodeInfo_atexit_dtor_op233();
extern int IrMulLowUInt__opcodeInfo_atexit_dtor_op232();
extern int IrMulHiInt__opcodeInfo_atexit_dtor_op231();
extern int IrMulLowInt__opcodeInfo_atexit_dtor_op230();
extern int IrLshlInt__opcodeInfo_atexit_dtor_op229();
extern int IrLshrInt__opcodeInfo_atexit_dtor_op228();
extern int IrAshrInt__opcodeInfo_atexit_dtor_op227();
extern int IrUInt2F__opcodeInfo_atexit_dtor_op226();
extern int IrInt2F__opcodeInfo_atexit_dtor_op225();
extern int IrF2UInt__opcodeInfo_atexit_dtor_op264();
extern int IrF2Int__opcodeInfo_atexit_dtor_op224();
extern int IrDot3IEEE__opcodeInfo_atexit_dtor_op223();
extern int IrDot3__opcodeInfo_atexit_dtor_op28();
extern int IrCube__opcodeInfo_atexit_dtor_op27();
extern int IrTrunc__opcodeInfo_atexit_dtor_op69();
extern int IrTruncFloat__opcodeInfo_atexit_dtor_op26();
extern int IrRecipUInt__opcodeInfo_atexit_dtor_op235();
extern int IrRecipInt__opcodeInfo_atexit_dtor_op234();
extern int IrCbLoad__opcodeInfo_atexit_dtor_op254();
extern int IrWhileStart__opcodeInfo_atexit_dtor_op253();
extern int IrScratchStore__opcodeInfo_atexit_dtor_op252();
extern int IrScratchLoad__opcodeInfo_atexit_dtor_op251();
extern int IrMemInit__opcodeInfo_atexit_dtor_op250();
extern int IrDyamicReturn__opcodeInfo_atexit_dtor_op248();
extern int IrEmit__opcodeInfo_atexit_dtor_op247();
extern int IrPsColorFog__opcodeInfo_atexit_dtor_op246();
extern int IrMulLit__opcodeInfo_atexit_dtor_op245();
extern int IrNotInt__opcodeInfo_atexit_dtor_op197();
extern int IrXorInt__opcodeInfo_atexit_dtor_op196();
extern int IrOrInt__opcodeInfo_atexit_dtor_op195();
extern int IrAndInt__opcodeInfo_atexit_dtor_op194();
extern int IrRoundNearestEven__opcodeInfo_atexit_dtor_op190();
extern int IrCeil__opcodeInfo_atexit_dtor_op189();
extern int IrSetNE_Dx10__opcodeInfo_atexit_dtor_op188();
extern int IrDyamicReturnSwitch__opcodeInfo_atexit_dtor_op262();
extern int IrCut__opcodeInfo_atexit_dtor_op261();
extern int IrLdBuffer__opcodeInfo_atexit_dtor_op260();
extern int IrSampleG__opcodeInfo_atexit_dtor_op259();
extern int IrSampleCLZ__opcodeInfo_atexit_dtor_op258();
extern int IrSampleL__opcodeInfo_atexit_dtor_op257();
extern int IrSampleC__opcodeInfo_atexit_dtor_op256();
extern int IrFetchLoad__opcodeInfo_atexit_dtor_op255();
extern int IrImmedConstLoad__opcodeInfo_atexit_dtor_op267();
extern int IrImmedConstBuffer__opcodeInfo_atexit_dtor_op266();
extern int IrGetResource__opcodeInfo_atexit_dtor_op265();
extern int IrEmitThenCut__opcodeInfo_atexit_dtor_op263();
extern int IrDot2Add__opcodeInfo_atexit_dtor_001fbdc4();
extern int IrAddFloat__opcodeInfo_atexit_dtor_op18();
extern int FUN_00115fa0();
extern int FUN_0011e6ec();
extern int IRPhi__getUniqueSource();
extern int IRInst__allSourcesDefined();
extern int IRInst__sourcesAreSameValue();
extern int FUN_0011e894();
extern int Program__isPreassignedHwReg();
extern int ValueKey__loadSourceDefinitions();
extern int FUN_0011eaa0();
extern int ValueKey__foldMovSources();
extern int Program__tryEliminateRedundantCopy();
extern int FUN_0011f578();
extern int FUN_0011f7fc();
extern int FUN_0011f8a0();
extern int Program__foldUselessPhis();
extern int FUN_0011ff7c();
extern int FUN_00120cd4();
extern int FUN_00121000();
extern int pass_ssa_build();
extern int FUN_00122de8();
extern int FUN_00122e90();
extern int VReg__popDefinition();
extern int ExportValue__vslot10();
extern int FUN_00122f28();
extern int VReg__currentDefinition();
extern int FUN_0012306c();
extern int ImmedConstBuffer__clone();
extern int VertexRegister__clone();
extern int VReg__setTopDefinition();
extern int VReg__pushDefinition();
extern int FUN_001234d8();
extern int FUN_001235b8();
extern int VReg__addUse();
extern int VRegInfo__ctor_12379c();
extern int VRegInfo__ctor_1238e8();
extern int Interpolator__vslot10();
extern int FUN_00123c08();
extern int TempValue__clone();
extern int ExportSlot__clone();
extern int Resource__clone();
extern int FixedValue__clone();
extern int FixedValue__ctor_1245a8();
extern int FixedValue__ctor_124724();
extern int VertexRegister__ctor_1248a0();
extern int VertexRegister__ctor_1248ec();
extern int TempValue__ctor_124938();
extern int PrimitiveIndex__ctor_12499c();
extern int StandardIndex__ctor_124b24();
extern int StandardIndex__ctor_124c94();
extern int TempValue__ctor_124e04();
extern int ExportValue__ctor_124e68();
extern int ExportValue__ctor_1250dc();
extern int Interpolator__ctor_125350();
extern int Interpolator__ctor_1257b0();
extern int Physical__ctor_125c10();
extern int Physical__ctor_125c8c();
extern int Resource__ctor_125d08();
extern int Resource__ctor_125d60();
extern int PrimitiveIndex__ctor_125db8();
extern int AddrIndexedSet__ctor_125f40();
extern int AddrIndexedSet__ctor_125f94();
extern int LoopRegister__ctor_125fe8();
extern int LoopRegister__ctor_126034();
extern int LoopIndexedOutputSet__ctor_126080();
extern int ExportAddress__ctor_1260f4();
extern int ExportAddress__ctor_12614c();
extern int ImmedConstBuffer__ctor_1261a4();
extern int ImmedConstBuffer__ctor_1261e8();
extern int ExportSlot__ctor_12622c();
extern int ExportSlot__ctor_126378();
extern int LoopIndexedConstSet__ctor_1264c4();
extern int LoopIndexedConstSet__ctor_126538();
extern int LoopIndexedInputSet__ctor_1265ac();
extern int LoopIndexedInputSet__ctor_126620();
extern int LoopIndexedOutputSet__ctor_126694();
extern int RegKind__flagBit7();
extern int RegKind__flagBit8();
extern int RegKind__flagBit0();
extern int RegKind__flagBit6();
extern int FUN_001267b8();
extern int ImmedConstBuffer__vslot283();
extern int RegKind__flagBit1();
extern int RegKind__flagBit9();
extern int RegKind__byte4();
extern int ImmedConstBuffer__vslot235();
extern int ImmedConstBuffer__vslot15();
extern int ImmedConstBuffer__vslot23();
extern int ImmedConstBuffer__vslot83();
extern int ImmedConstBuffer__vslot67();
extern int ImmedConstBuffer__vslot71();
extern int ImmedConstBuffer__vslot35();
extern int ImmedConstBuffer__vslot167();
extern int ImmedConstBuffer__vslot171();
extern int LoopIndexedSet__ctor_126de4();
extern int ImmedConstBuffer__vslot183();
extern int ImmedConstBuffer__vslot179();
extern int ImmedConstBuffer__vslot175();
extern int ImmedConstBuffer__vslot187();
extern int ImmedConstBuffer__vslot191();
extern int ImmedConstBuffer__vslot79();
extern int ImmedConstBuffer__vslot39();
extern int ConstKey__lanes1();
extern int ConstKey__lanes2();
extern int ConstKey__lanes3();
extern int ConstKey__lanes4();
extern int FUN_001272b4();
extern int FUN_001272cc();
extern int FUN_001272d4();
extern int FUN_00127324();
extern int FUN_0012740c();
extern int FUN_00127470();
extern int FUN_00127534();
extern int FUN_001275a0();
extern int FUN_00127608();
extern int ConstKey__compare1();
extern int ConstKey__compare2();
extern int ConstKey__compare3();
extern int ConstKey__compare4();
extern int keyEqualsThreeWords();
extern int FUN_00127850();
extern int FUN_001278d0();
extern int VRegInfo__new_127994();
extern int KhanPs__vslot21_appendRegisterBinding();
extern int KhanPs__vslot78_getLimit_0x20Or0x40();
extern int KhanPs__vslot76_getBindingLimit();
extern int KhanPs__createSchedModels();
extern int FUN_00127fd8();
extern int KhanPs__vslot62_lookupTableEntry();
extern int KhanPs__vslot90_isProgramKind1();
extern int KhanPs__getOpcodeTraits();
extern int KhanPs__vslot35_publishLimitsAndBindingTables();
extern int KhanPs__vslot8_failNotSupported();
extern int KhanPs__vslot58_matchImmediateConstantCode();
extern int KhanPs__vslot73_seedValueNumbers();
extern int KhanPs__vslot74_seedConstantValueNumbers();
extern int KhanPs__vslot85_findOrEncodeConstantVector();
extern int KhanPs__vslot59_tryEncodeSourceConstant();
extern int KhanPs__vslot9_createCompareInst();
extern int KhanPs__vslot5_materializeSpecialRegister();
extern int KhanPs__vslot75_registerConstantMultiples();
extern int KhanPs__ctor_128fd0();
extern int KhanPs__ctor_129130();
extern int FudoVs__createSchedModels();
extern int KhanVs__vslot76_getBindingLimits();
extern int KhanVs__vslot77_getBindingLimits();
extern int KhanVs__vslot80_getLimit_0x14();
extern undefined4 KhanVs__vslot60_isZeroOrOne(double fparam_1);
extern int KhanVs__vslot73_noOp();
extern int KhanVs__vslot99_matchesRegisterMapEntry();
extern int KhanVs__vslot35_publishLimitsAndBindingTables();
extern int KhanVs__getOpcodeTraits();
extern int FudoVs__vslot8_failNotSupported();
extern int KhanVs__vslot22_appendRegisterBindingWithLaneArrays();
extern int KhanVs__vslot21_appendRegisterBinding();
extern int KhanVs__vslot100_appendIdentityRegisterBinding();
extern int KhanVs__vslot58_matchImmediateConstantCode();
extern int KhanVs__vslot74();
extern int KhanVs__vslot59_tryEncodeSourceConstant();
extern int KhanVs__vslot71_canCombineSources();
extern int KhanVs__vslot85_findOrEncodeConstantVector();
extern int KhanVs__vslot9_createCompareInst();
extern int KhanVs__vslot89_assignLoadBindings();
extern int KhanVs__vslot75_registerConstantMultiples();
extern int KhanVs__createSchedModels();
extern int KhanVs__ctor_12a578();
extern int KhanVs__ctor_12a6c0();
extern int FudoVs__ctor_12a808();
extern int FudoVs__ctor_12a8bc();
extern int KhanVs__vslot96_installHardwareTables();
extern int FudoVs__vslot96_installHardwareTables();
extern int KhanPs__vslot96_installHardwareTables();
extern int FUN_0012aa78();
extern int FUN_0012aae0();
extern int FUN_0012ab04();
extern int pass_optimize_control_flow();
extern int IfHeader__swapArms();
extern int FUN_0012ac58();
extern int FUN_0012ae1c();
extern int FUN_0012ae6c();
extern int FUN_0012aef0();
extern int FUN_0012afe8();
extern int FUN_0012b140();
extern int FUN_0012b248();
extern int FUN_0012b2d8();
extern int LoopInfo__setCounterPhi();
extern int FUN_0012b3f8();
extern int FUN_0012b520();
extern int FUN_0012b64c();
extern int LoopInfo__convertToHardwareLoop();
extern int LoopInfo__init();
extern int FUN_0012bb48();
extern int Program__hasKillTexture();
extern int FudoPs__vslot69_shouldFlattenIf();
extern int FUN_0012c2dc();
extern int FUN_0012c3d0();
extern int LoopInfo__matchCounterInit();
extern int LoopInfo__matchCounterStep();
extern int LoopInfo__matchExit();
extern int pass_loop_trans();
extern int FUN_0012cfa4();
extern int pass_flatten_ifs();
extern int FudoPs__flattenIfs();
extern int FUN_0012dd58();
extern int Program__foldConstantIfRegion();
extern int FUN_0012e488();
extern int IfFooter__ctor_12e56c();
extern int FUN_0012e8c0();
extern int FUN_0012eacc();
extern int FUN_0012f0f8();
extern int Program__isRegionTrivial();
extern int pass_remove_empty_graphs();
extern int FUN_001303f4();
extern int FUN_00130424();
extern int Program__markHwRegUsed();
extern int FUN_00130478();
extern int FUN_001304a4();
extern int BitSet__setBit42c();
extern int FUN_00130594();
extern int FUN_0013061c();
extern int FUN_00130690();
extern int FUN_00130728();
extern int FUN_001307cc();
extern int FUN_001307f8();
extern int FUN_001308e0();
extern int FUN_00130904();
extern int FUN_00130944();
extern int FUN_00130958();
extern int FUN_0013097c();
extern int FUN_001309bc();
extern int Program__isHwRegAllowed();
extern int FUN_00130a08();
extern int FUN_00130a78();
extern int FUN_00130abc();
extern int FUN_00130bd4();
extern int FUN_00130bfc();
extern int FUN_00130c8c();
extern int FUN_00130da0();
extern int FUN_00130e68();
extern int FUN_00130ec0();
extern int FUN_00130f64();
extern int FUN_00131008();
extern int FUN_001311cc();
extern int FUN_001312f4();
extern int FUN_001314b8();
extern int FUN_001315f8();
extern int FUN_001318a4();
extern int FUN_001319d0();
extern int FUN_00131a80();
extern int FUN_00131c10();
extern int FUN_00131c74();
extern int FUN_00131d08();
extern int HwLimits__buildInterferenceGraph();
extern int FUN_001330f4();
extern int FUN_0013323c();
extern int FUN_00133fe4();
extern int FUN_00134400();
extern int FUN_00134658();
extern int FUN_00134aa8();
extern int FUN_00134ab0();
extern int FUN_00134ab8();
extern int pairIndex();
extern int InterferenceMatrix__setPair();
extern int InterferenceMatrix__testPair();
extern int FUN_00134bf0();
extern int FUN_00134c18();
extern int FUN_00134cd4();
extern int ColorGraph__countSameClassNeighbors();
extern int FUN_00134db0();
extern int FUN_00134de8();
extern int FUN_00134ef4();
extern int storeAfterLocate();
extern int FUN_00135010();
extern int FUN_00135090();
extern int FUN_00135110();
extern int FUN_001351c4();
extern int FUN_00135278();
extern int FUN_00135334();
extern int FUN_0013555c();
extern int FUN_00135684();
extern int FUN_001357d4();
extern int FUN_00135900();
extern int FUN_00135a2c();
extern int FUN_00135c20();
extern int ColorGraph__removeNodeUpdateDegrees();
extern int pass_color_graph();
extern int FUN_00136ec4();
extern int FUN_0013719c();
extern int FUN_00137474();
extern int FUN_00137694();
extern int FUN_001378e8();
extern int BitSet__testRegisterLane();
extern int FUN_00137e98();
extern int FUN_00137f14();
extern int FUN_00138080();
extern int FUN_00138130();
extern int FUN_00138240();
extern int FUN_001382b8();
extern int FUN_00138390();
extern int HwLimits__computeBlockLiveness();
extern int Program__finishUsevectorChain();
extern int FUN_00139008();
extern int FUN_00139034();
extern int FUN_0013905c();
extern int FUN_00139190();
extern int FUN_0013922c();
extern int FUN_00139294();
extern int IRInst__isOpcodeInSet139344();
extern int Program__moveInterpFetchesOutOfIfs();
extern int IRInst__markOpcode13After12();
extern int FUN_001396d0();
extern undefined4 IRInst__sourceIsSplatConstant(undefined4 param_1,undefined4 param_2,double fparam_1);
extern int FUN_001398b4();
extern int FUN_00139c78();
extern int FUN_00139d40();
extern int Block__scanBranchConeForFetchAndInterp();
extern int FUN_0013a240();
extern int FUN_0013a38c();
extern int FUN_0013a644();
extern int FUN_0013a774();
extern int FUN_0013a8a4();
extern int FUN_0013b1e8();
extern int Program__hoistFetchInsts();
extern int Program__eliminateDeadInstsAndRecountUses();
extern int FUN_0013c210();
extern int Program__scanUsevectorChains();
extern int FUN_0013ca84();
extern int IfHeader__convertInnerIfToCmov();
extern int pass_rewrite();
extern int FUN_0013d3b8();
extern int FUN_0013d820();
extern int FUN_0013da3c();
extern int FUN_0013f3d4();
extern int FUN_0013fc38();
extern int FUN_00140e5c();
extern int FUN_00140e70();
extern int FUN_00140e7c();
extern int FUN_00141044();
extern int FUN_00141090();
extern int FUN_00141100();
extern int FUN_001411dc();
extern int FUN_00141458();
extern int FUN_001415a4();
extern int FUN_001416b4();
extern int PostPack__canPairInEitherOrder();
extern int FUN_00141930();
extern int FUN_001427a4();
extern int FUN_00142974();
extern int FUN_00142fdc();
extern int FUN_00143664();
extern int PostPack__buildCandidate();
extern int FUN_0014375c();
extern int FUN_00143e40();
extern int FUN_001440e4();
extern int FUN_0014532c();
extern int pass_post_pack_insts();
extern int FUN_0014657c();
extern int IRInst__getOperandSourceOrDefault();
extern int FUN_00146624();
extern int FUN_00146670();
extern int IRInst__getOperandSourceThroughMix();
extern int FUN_0014675c();
extern int FUN_00146788();
extern int FUN_001467e8();
extern int FUN_00146868();
extern int FUN_0014694c();
extern int Use__negationParityEqual();
extern int FUN_00146b0c();
extern int Use__sourceIsPlainSingleUse();
extern int Inst__opcodeOrSourcesDiffer();
extern int FUN_00146edc();
extern int FUN_0014700c();
extern int FUN_00147044();
extern int Inst__canFuseAddMul();
extern int FUN_00147238();
extern int IRInst__isOpcodeInSet147398();
extern int FUN_001474c8();
extern int FUN_00147704();
extern int FUN_001479f8();
extern int FUN_00147b8c();
extern int FUN_00147f54();
extern int FUN_0014846c();
extern int FUN_001486e8();
extern int FUN_00148980();
extern int FUN_00148d8c();
extern int FUN_001494dc();
extern int FUN_00149d54();
extern int FUN_00149de4();
extern int FUN_0014a898();
extern int Inst__swizzleTextureFetchOutput();
extern int Inst__tryCopyPropagate();
extern int Inst__collapseMulSplatByDotOnes();
extern int Inst__collapseAddIntoMadMulAddend();
extern int Inst__collapseAddOfMulToMad();
extern int Inst__collapseMulOfAddWithUnitConstant();
extern int FUN_0014c534();
extern int FUN_0014c604();
extern int FUN_0014c9d0();
extern int Inst__collapseMadOfMulToDot2Add();
extern int Inst__collapseMadWithDot2AddToDot3();
extern int Inst__collapseDot3VectorTimesScaledVector();
extern int Inst__collapseThreeComponentSumToDot3();
extern int FUN_0014e2dc();
extern int Inst__reassociate_14e6e4();
extern int Inst__swapSharedTermBetweenUses();
extern int Inst__swapMatchedOperandsBetweenUses();
extern int Inst__reassociateUsePair();
extern int FUN_001507d0();
extern int Inst__reassociate_150b94();
extern int Inst__collapseAddOfScaledMov();
extern int FUN_00151318();
extern int FUN_00151370();
extern int FUN_00151a74();
extern int FUN_001524b8();
extern int FUN_00152ea8();
extern int FUN_001541f0();
extern int Inst__mergeComponentMovsIntoCnd();
extern int FUN_0015546c();
extern int FUN_00155654();
extern int Inst__collapseAlgebraic_00155a60();
extern int FUN_00156cb8();
extern int FUN_00156d48();
extern int FUN_00157b78();
extern int FUN_0015800c();
extern int Inst__collapseAlgebraic_00158264();
extern int FUN_00158988();
extern int FUN_00158b78();
extern int Inst__distributeResultScale();
extern int Inst__foldCndWithConstantCondition();
extern int FUN_00159794();
extern int FUN_00159b58();
extern int Inst__takeOutCommonFactor();
extern int FUN_0015b4a4();
extern int FUN_0015b8b8();
extern int FUN_0015b974();
extern int Inst__mergeAddAndMadSharedOperands();
extern int Inst__collapseAlgebraic_0015c6d4();
extern int Inst__collapseAlgebraic_0015ceb0();
extern int Inst__collapseMulOfExps();
extern undefined4 IRInst__getOtherOperandIfConstant(int param_1,int param_2,undefined4 param_3,undefined4 param_4,double fparam_1);
extern int Inst__collapseClampToSaturate();
extern int Inst__tryMix();
extern int FUN_0015f44c();
extern int Inst__foldProducerIntoConsumer();
extern int FUN_00160eb0();
extern int FUN_00161748();
extern int FUN_001621c8();
extern int Inst__collapseIntoExtraSourceDispatch();
extern int FUN_00162dfc();
extern int Inst__tryCollapseSimilar();
extern int Inst__hoistScalarMulOutOfDot();
extern int Inst__mergeMovAndMadByLanes();
extern int Scheduler__compareNodes();
extern int Scheduler__updateFetchBatchMode();
extern int VRegKey__equals();
extern int VRegKey__hash();
extern int Scheduler__findFreeHwRegister();
extern int IRInst__needsNoSchedulerNode();
extern int Scheduler__getDependencyLatency();
extern int IRInst__writesTrackedRegister();
extern int Scheduler__computeBlockRegisterSets();
extern int FUN_00165604();
extern int FUN_00165788();
extern int Scheduler__assignFreshVirtualRegister();
extern int Scheduler__addDataDependencyEdge();
extern int Scheduler__createNode();
extern int Scheduler__findOrCreateExternalNode();
extern int Scheduler__expandPresubToAdd();
extern int Scheduler__copyFetchInEdge();
extern int Scheduler__hasOtherFlaggedProducer();
extern int Scheduler__isNodeReady();
extern int Scheduler__freeNodes();
extern int Scheduler__computeNodePriorities();
extern int SchedNode__getLastConsumerCycle();
extern int Scheduler__findFreeTempRegister();
extern int Scheduler__createCopyNode();
extern int Scheduler__insertOperandCopy();
extern int Scheduler__addOperandDependencyEdges();
extern int Scheduler__transformDotProduct();
extern int Scheduler__packDotProductCandidates();
extern int Scheduler__markGlobalValues();
extern int Scheduler__buildDependencyGraph();
extern int Scheduler__buildCoScheduleGroups();
extern int FUN_0016c1fc();
extern int Scheduler__commitBundle();
extern int Scheduler__allocateRegisterForNode();
extern int Scheduler__releaseOperandsOfIssuedNode();
extern int Scheduler__issueNode();
extern int Scheduler__tryReuseAddressRegister();
extern int Scheduler__tryReuseLoopIndexLoad();
extern int Scheduler__enqueueReadyNode();
extern int Scheduler__splitAddressRegisterUses();
extern int Scheduler__advanceCycle();
extern int Scheduler__onNodeReady();
extern int Scheduler__selectNextNode();
extern int Scheduler__scheduleCycle();
extern int Scheduler__updateSuccessorsAfterIssue();
extern int Scheduler__issueDeadNode();
extern int Scheduler__scheduleBlock();
extern int pass_sched_preprocess_and_schedule_inst();
extern int Scheduler__run();
extern int SchedModel__resetCounters();
extern int ResourceModel__vslot23();
extern int SchedModel__countIssuedNode();
extern int SchedModel__uncountNode();
extern int FUN_00172204();
extern int ResourceModel__vslot24();
extern int ResourceModel__vslot25();
extern int ResourceModel__vslot29();
extern int ResourceModel__vslot22();
extern int ResourceModel__vslot32();
extern int ResourceModel__vslot11();
extern int FUN_001725c4();
extern int ThreadModel__vslot4();
extern int FUN_001729bc();
extern int ValueKey__maybeRefineSources();
extern int ValueKey__swapSources12();
extern int ExprRecordTable__hashByValueNumber();
extern int ExprRecordTable__eqByValueNumber();
extern int ExprRecordTable__hashByExpr();
extern int ExprRecordTable__eqByExpr();
extern int PtrSet__hashPtr();
extern int PtrSet__eqNonNullPtr();
extern int KeyLaneTable__hashByOpcode();
extern int KeyLaneTable__eqKeys();
extern int ScopedExprTable__hashKey();
extern int ScopedExprTable__eqKeys();
extern int returnZero_172dfc();
extern int LaneMatchTable__eqKeys();
extern int SwizzleTable__hashKey();
extern int Compiler__nextValueNumber();
extern int Compiler__nextNegativeValueNumber();
extern int Compiler__peekValueNumber();
extern int Compiler__resetValueNumbers();
extern int returnZero_172f24();
extern int ValueKey__initResultLaneValues();
extern int noop_172fb0();
extern int noop_172fb4();
extern int FUN_00172fb8();
extern int FUN_00173018();
extern int ValueKey__computeSwizzleTo();
extern int SwizzleTable__eqKeys();
extern int ValueKey__propagateLaneValues();
extern int Compiler__findInPtrSet();
extern int Compiler__exprRecordForValueNumber();
extern int ValueKey__canonicalizeCommutativeOperands();
extern int FUN_0017343c();
extern int FUN_0017356c();
extern int IRInst__isCndFloatOp();
extern int FUN_00173638();
extern int FUN_00173754();
extern int ValueKey__fillSourceLaneUsage();
extern int ValueKey__init();
extern int ValueKey__initCopy();
extern int FUN_00173a48();
extern int FUN_00173af8();
extern int Program__eliminateRedundantInst();
extern int FUN_00173cdc();
extern int Compiler__valueNumberForExpr();
extern int ValueKey__fill();
extern int ValueKey__rebuild();
extern int FUN_001745f0();
extern int FUN_001746c8();
extern int FUN_001747c4();
extern int FUN_00174888();
extern int FUN_0017494c();
extern int FUN_00174b04();
extern int FUN_00174ce0();
extern int FUN_00174e0c();
extern int FUN_001758d8();
extern undefined4 * FUN_00175a3c(int param_1,undefined4 param_2,undefined4 param_3,double fparam_1);
extern int FUN_00175b40();
extern int Program__valueNumberInst();
extern int Ptr__equalNonNull();
extern int IROperand__copyRegisterAndSelect();
extern int FUN_0017629c();
extern int noop_1762bc();
extern int FUN_001762c0();
extern double KhanPs__vslot56_scaleFloat(double fparam_1);
extern int signToCompareCode();
extern undefined4 classifyConstantRange(double fparam_1);
extern int ValueKey__rowLanesAllEqual();
extern int ValueKey__findOrInsertLiteral(undefined4 param_1,int param_2,int param_3,double fparam_1);
extern int FUN_001764e0();
extern int ValueKey__sourceKindIs1();
extern int ValueKey__sourceKindIs4();
extern int FUN_00176534();
extern int FUN_00176564();
extern int FUN_00176574();
extern int FUN_001765a4();
extern int FudoPs__vslot12_lookupTable6x();
extern int FudoPs__vslot11_isNotType2Or5();
extern int FUN_0017662c();
extern int FUN_001766bc();
extern int FUN_0017672c();
extern int FUN_001767d8();
extern int ValueKey__lanesAreUnset();
extern int FUN_001768d4();
extern int FUN_00176954();
extern int FUN_001769f4();
extern int FUN_00176a94();
extern int FUN_00176c40();
extern int FUN_00176d6c();
extern int FUN_00176e20();
extern int FUN_00176ec0();
extern int FUN_00176ed4();
extern int FUN_00176f0c();
extern int FUN_00176f44();
extern int FUN_00176fd4();
extern int Inst__writtenLanesAllMatchValue();
extern int FUN_001770e4();
extern int FUN_001771b0();
extern int FUN_0017729c();
extern int FUN_0017737c();
extern undefined4 FUN_0017740c(int param_1,int param_2,double fparam_1);
extern int FUN_00177548();
extern int FUN_001775d8();
extern int FUN_001776b8();
extern int FUN_00177748();
extern int FUN_001778e0();
extern int FUN_001779f0();
extern int ValueKey__cancelNegatedSourcePair();
extern int FUN_00177b4c();
extern int FUN_00177cd0();
extern int FUN_00177e14();
extern int FUN_00178024();
extern int FUN_001781a4();
extern int FUN_00178338();
extern int FUN_00178648();
extern int IRInst__isOpcode8bOr8c();
extern int FUN_001789f0();
extern int FUN_00178a98();
extern int FUN_00178b1c();
extern int FUN_00178c84();
extern int FUN_00178d78();
extern int FUN_00178e90();
extern int FUN_00179064();
extern int FUN_00179138();
extern int FUN_001792f0();
extern int FUN_001793d8();
extern int FUN_00179608();
extern int FUN_001797d0();
extern int ValueKey__foldCompareSameSourcesValueNumber();
extern int FUN_0017994c();
extern int FUN_00179a34();
extern int FUN_00179b28();
extern int FUN_00179bbc();
extern int Inst__allWrittenLanesSatisfy();
extern int FUN_00179cc0();
extern int FUN_00179db0();
extern int FUN_00179e74();
extern int FUN_00179f38();
extern int FUN_0017a034();
extern int FUN_0017a130();
extern int FUN_0017a294();
extern int FUN_0017a3d4();
extern int FUN_0017a748();
extern int FUN_0017a8a4();
extern int ValueKey__foldDotPowerOfTwoIntoOutputScale();
extern int FUN_0017ad24();
extern int FUN_0017ae28();
extern int FUN_0017af58();
extern int FUN_0017b020();
extern int ValueKey__mixLiteralSources();
extern int FUN_0017b96c();
extern int FUN_0017bc58();
extern int FUN_0017bd78();
extern int ValueKey__foldDot3SingleLaneSource();
extern int ValueKey__foldDot4UnitVectorSource();
extern int FUN_0017c244();
extern int ValueKey__replaceWithSource2IfSourcesEqual23();
extern int FUN_0017c4a4();
extern int FUN_0017c5e0();
extern int ValueKey__foldMulByPlusMinusOne();
extern int ValueKey__replaceWithSource1IfSourcesEqual();
extern int FUN_0017c910();
extern int FUN_0017cb14();
extern int FUN_0017cd18();
extern int FUN_0017cdbc();
extern int FUN_0017ce7c();
extern int FUN_0017d06c();
extern int FUN_0017d26c();
extern int ValueKey__foldCompareSameSourcesToConstant();
extern int ValueKey__replaceWithZeroIfSourcesEqual();
extern int ValueKey__foldMulByZero();
extern int FUN_0017d610();
extern int FUN_0017d6ac();
extern int FUN_0017d9b8();
extern int FUN_0017dbdc();
extern int FUN_0017e02c();
extern int ValueKey__foldMulPowerOfTwoIntoOutputScale();
extern int FUN_0017e338();
extern int FUN_0017e3f4();
extern int ValueKey__foldMadZeroAddend();
extern int ValueKey__foldMadByPlusMinusOne();
extern int FUN_0017e7e0();
extern int FUN_0017ebb0();
extern int FUN_0017ee68();
extern int FUN_0017f1f8();
extern int ValueKey__foldMinMaxOfNegatedPair();
extern int ValueKey__foldMaxOfNegatedPair();
extern int ValueKey__foldMinOfNegatedPair();
extern int FUN_0017f5a4();
extern int FUN_0017f78c();
extern int FUN_0017f7ec();
extern int FUN_00180154();
extern int ValueKey__canonicalizeConstantSources();
extern int ValueKey__simplifyModifiersAndAddressing();
extern int FUN_00181928();
extern int FUN_001819b4();
extern int FUN_00181ab0();
extern int FUN_00181b80();
extern int FUN_00181f00();
extern int FUN_00183ac8();
extern int FUN_00183b9c();
extern int FUN_0018401c();
extern int FUN_0018413c();
extern int pass_minreg_order();
extern int compareIntsAscending();
extern int FUN_00184bf0();
extern int FUN_00184cd8();
extern int Inst__splitAndMerge();
extern int IRInst__foldResultScaleIntoUsers();
extern int Inst__tryDp3Add();
extern int FUN_00185da4();
extern int FUN_00186510();
extern int FUN_00186a88();
extern int Inst__r300ReassociateAddPair();
extern int FUN_00187ad8();
extern int Inst__r300Peephole_1882a4();
extern int KhanPs__peepholeCombine();
extern int Inst__movAndShiftUseVector();
extern int KhanPs__vslot27_optimizeInstruction();
extern int KhanVs__vslot29_swapIfArmsWhenNotFlattenable();
extern int KhanVs__peepholeCombine();
extern int KhanVs__vslot27_optimizeInstruction();
extern int PackState__reset();
extern int PackState__copy();
extern int R520SchedModel__vslot2_reset();
extern int KhanPs__vslot31_isNotTextureFetch();
extern int KhanPs__vslot65_isEncodableSourceSwizzle();
extern int SelectWord__isDefaultAfterCanonicalise();
extern int SelectWord__matchesDefaultPattern();
extern int SelectWord__matchesAnyKnownPattern();
extern int KhanPs__vslot66_callHelper189788();
extern int FUN_001897fc();
extern int SchedModel__fitsConstantLimit();
extern int SchedModel__assignConstantSelectors();
extern int R300SchedModel__vslot15();
extern int FUN_00189c24();
extern int FUN_00189ce0();
extern int FUN_00189df4();
extern int R300SchedModel__vslot19();
extern int R300SchedModel__vslot34();
extern int R300SchedModel__vslot26();
extern int R300SchedModel__vslot28();
extern int R300SchedModel__vslot16();
extern int FUN_0018b1bc();
extern int R300SchedModel__vslot11();
extern int R300SchedModel__vslot14();
extern int FUN_0018bc94();
extern int PackState__buildSlotTable();
extern int PackState__countFreeSlots();
extern int FUN_0018c7f4();
extern int FUN_0018c980();
extern int FUN_0018cdd8();
extern int FUN_0018d388();
extern int FUN_0018d4b4();
extern int SchedModel__instructionFitsAlone();
extern int R300SchedModel__tryRewriteConsumerSelects();
extern int R300SchedModel__legalizeInstruction();
extern int R520SchedModel__vslot4_addInstruction();
extern int R520SchedModel__vslot3_canAddInstruction();
extern int R300SchedModel__vslot12();
extern int R300VSchedModel__vslot2_reset();
extern int FUN_0018f850();
extern int R300VSchedModel__vslot13();
extern int R300VSchedModel__vslot28();
extern int R300VSchedModel__vslot14();
extern int R300VSchedModel__vslot17();
extern int FUN_00190100();
extern int R300VSchedModel__vslot4_addInstruction();
extern int R300VSchedModel__vslot3_canAddInstruction();
extern int R300VSchedModel__vslot27();
extern int R300VSchedModel__vslot19();
extern int R300VSchedModel__vslot12();
extern undefined4 isLiteralZeroHalfOrOne(double fparam_1);
extern undefined4 FudoPs__encodeImmediateFloat(int param_1,undefined4 param_2,uint *param_3,uint *param_4,double fparam_1);
extern int FudoPs__encodeUniformImmediate();
extern int FudoPs__vslot85_findOrEncodeConstantVector();
extern int FudoPs__vslot59_tryEncodeSourceConstant();
extern int FudoChip__vslot2();
extern int FudoPs__classifyLiteralOperand();
extern int FudoPs__createSchedModels();
extern int FudoPs__ctor_191efc();
extern int FudoPs__ctor_1920e0();
extern int FUN_001922c4();
extern int FudoPs__peepholeCombine();
extern int R520SchedModel__vslot21();
extern int R520SchedModel__vslot22();
extern int FudoPs__vslot29_convertInnerIfsToPredicates();
extern int FUN_00193a8c();
extern int FUN_00193ae4();
extern int FUN_00193b3c();
extern int FUN_00193be8();
extern int FUN_00193c00();
extern int Arena__free();
extern int List__freeAllNodes();
extern int Arena__grow();
extern int Arena__alloc();
extern int FUN_00193e74();
extern int Arena__bytesInUse();
extern int DList__isEmpty();
extern int DListNode__unlinkAndDelete();
extern int DList__insertBefore();
extern int DList__pushBack();
extern int DList__insertAfter();
extern int DList__pushFront();
extern int DList__initSentinel();
extern int DListNode__clear();
extern int DList__unlink();
extern int DList__count();
extern int DListNode__ctor_194060();
extern int DListNode__init();
extern int Vector__shellSort();
extern int Vector__removeAt();
extern int Vector__elementRefGrow();
extern int Vector__insertAt();
extern int Vector__removeValue();
extern int HashTable__destroy_1943f0();
extern int HashTable__destroy_194504();
extern int HashTable__findEntry();
extern int FUN_00194720();
extern int HashTable__find();
extern int FUN_00194938();
extern int FUN_00194a94();
extern int HashTable__grow();
extern int HashTable__insert();
extern int HashTable__grow_194e44();
extern int HashTable__insert_1950e0();
extern int disjointSetFindRoot();
extern int storeIndexedWord();
extern int psnOutputScaleCode();
extern int anyEnabledLaneSelectsW();
extern int anyEnabledLaneSelectsXyz();
extern int lanesToRgbMask();
extern int packSourceModifier();
extern int R300MachineAssembler__vslot12_assembleNodeAndMarkChildren();
extern int R300MachineAssembler__vslot6_noOp();
extern int R300MachineAssembler__vslot8_returnsTrue();
extern int R300MachineAssembler__vslot3_noOp();
extern int R300MachineAssembler__vslot9_getRecordBufferWords();
extern int psnLiteralAddressFromRegisterWord();
extern int R300MachineAssembler__callSlot65();
extern int R300MachineAssembler__declareNodeRegistersThunk();
extern int R300MachineAssembler__vslot65_declareNodeRegisters();
extern int R300MachineAssembler__vslot2_exceedsInstructionLimit();
extern int R300MachineAssembler__vslot38_returnsFalse();
extern int R300MachineAssembler__vslot36_noOp();
extern int R300MachineAssembler__vslot39_noOp();
extern int R300MachineAssembler__vslot40_noOp();
extern int R300MachineAssembler__vslot41_noOp();
extern int R300MachineAssembler__vslot42_noOp();
extern int R300MachineAssembler__vslot29_noOp();
extern int R300MachineAssembler__vslot43_noOp();
extern int R300MachineAssembler__vslot44_noOp();
extern int opcodeInfoRgbHwOpcode();
extern int opcodeInfoAlphaHwOpcode();
extern int R300MachineAssembler__callSlot14();
extern int R300MachineAssembler__vslot16_noOp();
extern int R300MachineAssembler__vslot19_noOp();
extern int R300MachineAssembler__vslot20_noOp();
extern int R300MachineAssembler__vslot21_noOp();
extern int R300MachineAssembler__vslot22_noOp();
extern int R300MachineAssembler__initNopAluRecord();
extern int R300MachineAssembler__setRsColorFields();
extern int R300MachineAssembler__setRsTexCoordFields();
extern int R300MachineAssembler__rgbSelectForSrcpSwizzle();
extern int R300MachineAssembler__alphaSelectForSrcpComponent();
extern int R300MachineAssembler__rgbSelectForAlphaSource();
extern int R300MachineAssembler__rgbSelectForSourceSwizzle();
extern int R300MachineAssembler__alphaSelectForAlphaSource();
extern int R300MachineAssembler__alphaSelectForColorComponent();
extern int R300MachineAssembler__setAluSourceAddresses();
extern int R300MachineAssembler__setAlphaOpcode();
extern int R300MachineAssembler__setAlphaTempWriteEnable();
extern int R300MachineAssembler__closeTextureIndirectionLevel();
extern int R300MachineAssembler__writeHeaderRecord();
extern int R300MachineAssembler__beginNextRecord();
extern int R300MachineAssembler__vslot4_finishProgram();
extern int R300MachineAssembler__assembleAsOpcodeInfo31();
extern int R300MachineAssembler__trackMaxLevelAndAssemble();
extern int R300MachineAssembler__vslot5_beginProgram();
extern int R300MachineAssembler__noteFetchTextureUnit();
extern int FUN_0019651c();
extern int R300MachineAssembler__resolveSourceRegister();
extern int R300MachineAssembler__setAluSourceSelectsAndModifiers();
extern int R300MachineAssembler__setRgbOpcode();
extern int R300MachineAssembler__create();
extern int R300MachineAssembler__dtor_196dbc();
extern int R300MachineAssembler__dtor();
extern int MachineAssembler__dtor_196e3c();
extern int R300MachineAssembler__placeInstructionConstants();
extern int R300MachineAssembler__assembleBlock();
extern int R300MachineAssembler__classifyAluOperation();
extern int R300MachineAssembler__emitTexRecord();
extern int R300MachineAssembler__rgbSelectForLiteralFloat();
extern int R300MachineAssembler__alphaSelectForLiteralFloat();
extern int R300MachineAssembler__setTempDestination();
extern int R300MachineAssembler__setOutputDestination();
extern int R300MachineAssembler__assembleAluInstruction();
extern int maxSigned();
extern int R300VMachineAssembler__finishProgram();
extern int R300VMachineAssembler__clearInstructionByte3();
extern int R300VMachineAssembler__nextInstruction();
extern int R300VMachineAssembler__logStatistics();
extern int R300VMachineAssembler__copyControlFlowToOutput();
extern int R300VMachineAssembler__vslot_noOp_19a508();
extern int R300VMachineAssembler__vslot_noOp_19a50c();
extern int R300VMachineAssembler__clearCurrentInstruction();
extern int opcodeInfoIsVsFlagBit2();
extern int R300VMachineAssembler__transitionState();
extern int R300VMachineAssembler__vslot2_exceedsLimits();
extern int R300VMachineAssembler__vslot49_advanceInstruction();
extern int R300VMachineAssembler__vslot48_declareAndAssemble();
extern int vsSourceSelectForConstant();
extern int copyLaneWord();
extern int R300VMachineAssembler__vslot15_assembleUnlessConstantMove();
extern int R300VMachineAssembler__vslot16_noOp();
extern int R300VMachineAssembler__vslot18_callSlot14();
extern int R300VMachineAssembler__vslot19_callSlot14();
extern int R300VMachineAssembler__vslot43_beginLoop();
extern int R300VMachineAssembler__vslot44_endLoopBody();
extern int R300VMachineAssembler__appendControlFlowEntry();
extern int R300VMachineAssembler__vslot45_endLoop();
extern int R300VMachineAssembler__vslot46_leaveLoop();
extern int R300VMachineAssembler__vslot27_assembleOrFail();
extern int R300VMachineAssembler__vslot25_assembleOrFail();
extern int R300VMachineAssembler__vslot28_assembleChildOrFail();
extern int R300VMachineAssembler__vslot38_appendCallEntry();
extern int R300VMachineAssembler__vslot42_noOp();
extern int R300VMachineAssembler__init();
extern int R300VMachineAssembler__vslot6_setLoopStack();
extern int R300VMachineAssembler__vslot24_assembleWithTarget();
extern int R300VMachineAssembler__vslot30_assembleBlockThenSlot40();
extern int R300VMachineAssembler__vslot37_patchControlFlowTarget();
extern int R300VMachineAssembler__findFoldableMovePair();
extern int R300VMachineAssembler__assembleBlock();
extern int R300VMachineAssembler__vslot40_endControlFlowBlock();
extern int R300VMachineAssembler__vslot39_appendBranchEntry();
extern int R300VMachineAssembler__vslot29_endIfBlock();
extern int R300VMachineAssembler__create();
extern int MachineAssembler__dtor_19b91c();
extern int MachineAssembler__dtor_19b9ac();
extern int R300VMachineAssembler__deleting_dtor();
extern int R300VMachineAssembler__encodeDestinationWord();
extern int R300VMachineAssembler__encodeSourceOperand();
extern int R300VMachineAssembler__encodeDualMathOperands();
extern int R300VMachineAssembler__vslot14_assembleInstruction();
extern int R300VMachineAssembler__getOrAllocateScratchRegister();
extern int R520VMachineAssembler__vslot33_noOp();
extern int R520VMachineAssembler__vslot12_visitNode();
extern int R520VMachineAssembler__getOrCreateConstantZeroInst();
extern int R520VMachineAssembler__vslot37_closeConditional();
extern int R520VMachineAssembler__vslot32_assembleWithPredicateClear();
extern int R520VMachineAssembler__vslot27_assembleLoopHeader();
extern int R520VMachineAssembler__vslot30_assembleBlockThenSlot40();
extern int R520VMachineAssembler__deleting_dtor();
extern int R520VMachineAssembler__init();
extern int R520VMachineAssembler__create();
extern int MachineAssembler__dtor_19deb0();
extern int MachineAssembler__dtor_19df54();
extern int R520VMachineAssembler__vslot28_assembleIfEnd();
extern int R520VMachineAssembler__vslot31_assembleWithPredicateRestore();
extern int R520VMachineAssembler__vslot25_assembleConditionalBlock();
extern int R520VMachineAssembler__vslot6_setLoopStack();
extern int R520VMachineAssembler__vslot24_assembleWithPredicateSet();
extern int psnPackedLaneComponent();
extern int psnPackedLaneSource();
extern int psnPackedNegateMask();
extern int psnPackedLaneNegate();
extern int FUN_0019eb30();
extern int FUN_0019ebdc();
extern int ilSkipRelativeAddressWords();
extern int ilSourceOperandWordCount();
extern int ilInstructionHeaderWordCount();
extern int ilDestinationOperandWordCount();
extern int FUN_0019ee74();
extern int FudoPs__vslot96_installHardwareTables();
extern int R520MachineAssembler__vslot5_beginProgram();
extern int R520MachineAssembler__setRsColorFields();
extern int R520MachineAssembler__setRsTexCoordFields();
extern int R520MachineAssembler__clearCurrentRecord();
extern int R520MachineAssembler__initNopAluRecord();
extern int R520MachineAssembler__vslot65_declareNodeRegisters();
extern int R520MachineAssembler__vslot59_selectForSrcpSwizzle();
extern int R520MachineAssembler__vslot60_selectForSrcpComponent();
extern int R520MachineAssembler__vslot61_selectForAlphaSource();
extern int R520MachineAssembler__vslot62_selectForSourceSwizzle();
extern int R520MachineAssembler__vslot64_selectForColorComponent();
extern int R520MachineAssembler__vslot63_selectForAlphaComponent();
extern int R520MachineAssembler__setAluSourceAddresses();
extern int R520MachineAssembler__setAlphaOpcode();
extern int R520MachineAssembler__vslot77_setRecordByteB();
extern int R520MachineAssembler__writeHeaderRecord();
extern int R520MachineAssembler__vslot9_getRecordWordsUsed();
extern int R520MachineAssembler__vslot38_appendBranchRecord();
extern int R520MachineAssembler__vslot80_setRecordByte9();
extern int R520MachineAssembler__vslot55_tryEncodeImmediateLiteral();
extern int R520MachineAssembler__vslot67_selectForConstantLanes();
extern int R520MachineAssembler__beginNextRecord();
extern int R520MachineAssembler__vslot4_finishProgram();
extern int R520MachineAssembler__vslot79_setTexCompareFlags();
extern int R520MachineAssembler__vslot31_assembleChildrenAndMark();
extern int R520MachineAssembler__vslot24_assembleWithTarget();
extern int R520MachineAssembler__setRgbOpcode();
extern int R520MachineAssembler__vslot86_resolveSourceRegister();
extern int R520MachineAssembler__vslot53_selectBitsForLiteralFloat();
extern int R520MachineAssembler__vslot54_selectBitsForAlphaLiteral();
extern int R520MachineAssembler__vslot66_selectBitsForLiteralLanes();
extern int R520MachineAssembler__vslot71_setAluSourceSelectsAndModifiers();
extern int evaluateConstantComparison();
extern int R520MachineAssembler__vslot29_patchBranchTarget();
extern int R520MachineAssembler__vslot26_assembleThenAppendRecord();
extern int R520MachineAssembler__create();
extern int R520MachineAssembler__terminateOpenBranches();
extern int R520MachineAssembler__vslot30_assembleThenTerminate();
extern int R520MachineAssembler__vslot28_endLoop();
extern int R520MachineAssembler__vslot72_setTempDestination();
extern int R520MachineAssembler__vslot74_setPredicateSetDestination();
extern int R520MachineAssembler__vslot73_setOutputDestination();
extern int R520MachineAssembler__vslot23_emitTexRecord();
extern int R520MachineAssembler__emitCompareToPredicate();
extern int R520MachineAssembler__vslot39_appendLoopStartRecord();
extern int R520MachineAssembler__appendBranchEndRecord();
extern int R520MachineAssembler__emitConditionalBranch();
extern int R520MachineAssembler__vslot27_assembleIf();
extern int R520MachineAssembler__vslot32_assembleBranchEnd();
extern int R520MachineAssembler__appendLoopRecord();
extern int R520MachineAssembler__vslot25_assembleLoop();
extern int R520MachineAssembler__vslot37_closeBranch();
extern int _savef14();
extern int _savef22();
extern int _savef24();
extern int _savef25();
extern int _savef26();
extern int _savef27();
extern int _savef28();
extern int _restf14();
extern int printf_LDBLStub_1a32d0();
extern int printf_LDBLStub_1a337c();
extern int printf_LDBLStub_1a3428();
extern int printf_LDBLStub_1a34d4();
extern int stub_getrealaddr();
extern int IRPseudo__getKindName();
extern int MachineAssembler__dtor_1cd7ec();
extern int DListNode__dtor();
extern int DListNode__deleting_dtor();
extern int IRPseudo__dtor();
extern int IRPseudo__deleting_dtor();
extern int IRInst__dtor_1cd908();
extern int IRInst__dtor_1cd970();
extern int IRInst__dtor_1cd9c4();
extern int IRInst__dtor_1cda2c();
extern int IRInst__dtor_1cda80();
extern int IRInst__dtor_1cdae8();
extern int IRInst__dtor_1cdb3c();
extern int IRInst__dtor_1cdba4();
extern int Block__getKindName();
extern int EntryBlock__getKindName();
extern int AnyBlock__getKindName();
extern int ExitBlock__getKindName();
extern int LoopFooter__getKindName();
extern int PostLoopFooter__getKindName();
extern int IfHeader__getKindName();
extern int IfHeaderStatic__getKindName();
extern int IfFooter__getKindName();
extern int IfFooterStatic__getKindName();
extern int BreakBlock__getKindName();
extern int ContinueBlock__getKindName();
extern int FuncEndBlock__getKindName();
extern int EntryBlock__deleting_dtor();
extern int AnyBlock__dtor();
extern int AnyBlock__deleting_dtor();
extern int FuncEndBlock__dtor();
extern int FuncEndBlock__deleting_dtor();
extern int LoopHeader__dtor();
extern int LoopHeader__deleting_dtor();
extern int LoopFooter__dtor();
extern int LoopFooter__deleting_dtor();
extern int PostLoopFooter__dtor();
extern int PostLoopFooter__deleting_dtor();
extern int IfHeader__dtor_1ce158();
extern int IfHeader__deleting_dtor();
extern int IfHeader__dtor_1ce1e4();
extern int IfHeader__dtor_1ce208();
extern int IfFooter__dtor_1ce270();
extern int IfFooter__deleting_dtor();
extern int IfFooter__dtor_1ce2fc();
extern int IfFooter__dtor_1ce320();
extern int BreakOrContinueBlock__dtor();
extern int BreakOrContinueBlock__deleting_dtor();
extern int ContinueBlock__deleting_dtor();
extern int ExitBlock__dtor();
extern int ExitBlock__deleting_dtor();
extern int EntryBlock__dtor();
extern int BreakBlock__dtor();
extern int BreakBlock__deleting_dtor();
extern int ContinueBlock__dtor();
extern int IREntry__getKindName();
extern int IRExit__getKindName();
extern int IRLoad__getKindName();
extern int IRLoadMemBuffer__getKindName();
extern int IRLoadMemBufferIndex__getKindName();
extern int IRImmedConstBuff__getKindName();
extern int IRLoadConst__getKindName();
extern int IRLoadTemp__getKindName();
extern int IRLoadVertex__getKindName();
extern int IRLoadInterp__getKindName();
extern int IRUndefined__getKindName();
extern int IRMerge__getKindName();
extern int IRProjection__getKindName();
extern int IRPresub1__getKindName();
extern int IRPresub2__getKindName();
extern int IRMix__getKindName();
extern int IRPhiNode__getKindName();
extern int IRAlu__getKindName();
extern int IRFetch__getKindName();
extern int IRCmp2__getKindName();
extern int IRCmp1S__getKindName();
extern int IRLoopStart__getKindName();
extern int IRInst__dtor_1cecc0();
extern int IRInst__dtor_1cecf4();
extern int IRInst__dtor_1ced3c();
extern int IRInst__deleting_dtor();
extern int IRInst__dtor_1cedb8();
extern int IRInst__dtor_1cedec();
extern int IRInst__dtor_1cee34();
extern int IRInst__dtor_1cee7c();
extern int IRInst__dtor_1ceec4();
extern int IRInst__dtor_1cef0c();
extern int IRInst__dtor_1cef40();
extern int IRInst__dtor_1cef74();
extern int IRInst__dtor_1cefbc();
extern int IRInst__dtor_1ceff0();
extern int IRInst__dtor_1cf038();
extern int IRInst__dtor_1cf06c();
extern int IRInst__dtor_1cf0b4();
extern int IRInst__dtor_1cf0e8();
extern int IRInst__dtor_1cf130();
extern int IRInst__dtor_1cf178();
extern int IRInst__dtor_1cf1ac();
extern int IRInst__dtor_1cf1f4();
extern int IRInst__dtor_1cf228();
extern int IRInst__dtor_1cf270();
extern int IRInst__dtor_1cf2a4();
extern int IRInst__dtor_1cf2ec();
extern int IRInst__dtor_1cf320();
extern int IRInst__dtor_1cf368();
extern int IRInst__dtor_1cf39c();
extern int IRInst__dtor_1cf3e4();
extern int IRInst__dtor_1cf418();
extern int IRInst__dtor_1cf44c();
extern int IRInst__dtor_1cf494();
extern int IRInst__dtor_1cf4c8();
extern int IRInst__dtor_1cf510();
extern int IRInst__dtor_1cf544();
extern int IRInst__dtor_1cf58c();
extern int IRInst__dtor_1cf5c0();
extern int IRInst__dtor_1cf608();
extern int IRInst__dtor_1cf63c();
extern int IRInst__dtor_1cf670();
extern int IRInst__dtor_1cf6b8();
extern int IRInst__dtor_1cf6ec();
extern int IRInst__dtor_1cf734();
extern int IRInst__dtor_1cf768();
extern int IRInst__dtor_1cf7b0();
extern int IRInst__dtor_1cf7e4();
extern int IRInst__dtor_1cf82c();
extern int IRInst__dtor_1cf860();
extern int IRInst__dtor_1cf8a8();
extern int IRInst__dtor_1cf8dc();
extern int IRInst__dtor_1cf924();
extern int IRInst__dtor_1cf958();
extern int IRInst__dtor_1cf98c();
extern int IRInst__dtor_1cf9d4();
extern int IRInst__dtor_1cfa08();
extern int IRInst__dtor_1cfa50();
extern int IRInst__dtor_1cfa84();
extern int IRInst__dtor_1cfacc();
extern int IRInst__dtor_1cfb00();
extern int IRInst__dtor_1cfb48();
extern int IRInst__dtor_1cfb7c();
extern int IRInst__dtor_1cfbc4();
extern int IRInst__dtor_1cfbf8();
extern int IRInst__dtor_1cfc40();
extern int IRInst__dtor_1cfc74();
extern int IRInst__dtor_1cfcbc();
extern int IRInst__dtor_1cfcf0();
extern int IRInst__dtor_1cfd38();
extern int IRInst__dtor_1cfd6c();
extern int IRInst__dtor_1cfdb4();
extern int IRInst__dtor_1cfde8();
extern int IRInst__dtor_1cfe30();
extern int IRInst__dtor_1cfe64();
extern int IRInst__dtor_1cfeac();
extern int IRInst__dtor_1cfee0();
extern int IRInst__dtor_1cff28();
extern int IRInst__dtor_1cff5c();
extern int HwLimits__dtor();
extern int HwLimits__deleting_dtor();
extern int HwLimits__vslot7_initInterpolatorTypeDescriptor();
extern int HwLimits__vslot40_initTypeDescriptorB();
extern int HwLimits__vslot70_initExportValueTypeDescriptor();
extern int HwChip__dtor();
extern int HwChip__deleting_dtor();
extern int OpcodeInfo__dtor();
extern int OpcodeInfo__deleting_dtor();
extern int IrAddFloat__vslot5_getValueKeyTransformLevel();
extern int IrCos__fold();
extern int IrLogInternal__fold();
extern int IrRecipSqrtInternal__fold();
extern int IrRecipInternal__fold();
extern int IrSin__fold();
extern int IrSqrt__fold();
extern int IrExp__fold();
extern int IrInt2F__fold();
extern int IrUInt2F__fold();
extern int IrMulAddFloat__fold();
extern int IrFloorFloat__fold();
extern int IrFractFloat__fold();
extern int IrDot3__foldVector();
extern int IrDot4__foldVector();
extern int IrDot2Add__foldVector();
extern int IrCndEFloat__fold();
extern int IrCndGEFloat__fold();
extern int IrCndGTFloat__fold();
extern int IrSetGTFloat__fold();
extern int IrAddInt__vslot5_getValueKeyTransformLevel();
extern int IrMulFloat__fold();
extern int IrRecipSqrtClamp__deleting_dtor();
extern int IrRecipSqrtClamp__dtor();
extern int IrRecipSqrtFF__deleting_dtor();
extern int IrRecipSqrtFF__dtor();
extern int IrRecipSqrtIEEE__deleting_dtor();
extern int IrRecipSqrtIEEE__dtor();
extern int IrRecipClamp__deleting_dtor();
extern int IrRecipClamp__dtor();
extern int IrRecipFF__deleting_dtor();
extern int IrRecipFF__dtor();
extern int IrRecipIEEE__deleting_dtor();
extern int IrRecipIEEE__dtor();
extern int IrMulFloat__deleting_dtor();
extern int IrMulFloat__dtor();
extern int IrMul__deleting_dtor();
extern int IrMul__dtor();
extern int IrLogClamp__deleting_dtor();
extern int IrLogClamp__dtor();
extern int IrLogIEEE__deleting_dtor();
extern int IrLogIEEE__dtor();
extern int IrDot2Add__deleting_dtor();
extern int IrDot2Add__dtor();
extern int IrAdd__deleting_dtor();
extern int IrAdd__dtor();
extern int IrImmedConstLoad__dtor();
extern int IrImmedConstLoad__deleting_dtor();
extern int IrImmedConstBuffer__dtor();
extern int IrImmedConstBuffer__deleting_dtor();
extern int IrGetResource__dtor();
extern int IrGetResource__deleting_dtor();
extern int IrEmitThenCut__dtor();
extern int IrEmitThenCut__deleting_dtor();
extern int IrDyamicReturnSwitch__dtor();
extern int IrDyamicReturnSwitch__deleting_dtor();
extern int IrCut__dtor();
extern int IrCut__deleting_dtor();
extern int IrLdBuffer__dtor();
extern int IrLdBuffer__deleting_dtor();
extern int IrSampleG__dtor();
extern int IrSampleG__deleting_dtor();
extern int IrSampleCLZ__dtor();
extern int IrSampleCLZ__deleting_dtor();
extern int IrSampleL__dtor();
extern int IrSampleL__deleting_dtor();
extern int IrSampleC__dtor();
extern int IrSampleC__deleting_dtor();
extern int IrFetchLoad__dtor();
extern int IrFetchLoad__deleting_dtor();
extern int IrCbLoad__dtor();
extern int IrCbLoad__deleting_dtor();
extern int IrWhileStart__dtor();
extern int IrWhileStart__deleting_dtor();
extern int IrScratchStore__dtor();
extern int IrScratchStore__deleting_dtor();
extern int IrScratchLoad__dtor();
extern int IrScratchLoad__deleting_dtor();
extern int IrMemInit__dtor();
extern int IrMemInit__deleting_dtor();
extern int IrDyamicReturn__dtor();
extern int IrDyamicReturn__deleting_dtor();
extern int IrEmit__dtor();
extern int IrEmit__deleting_dtor();
extern int IrPsColorFog__dtor();
extern int IrPsColorFog__deleting_dtor();
extern int IrMulLit__dtor();
extern int IrMulLit__deleting_dtor();
extern int IrNotInt__dtor();
extern int IrNotInt__deleting_dtor();
extern int IrXorInt__dtor();
extern int IrXorInt__deleting_dtor();
extern int IrOrInt__dtor();
extern int IrOrInt__deleting_dtor();
extern int IrAndInt__dtor();
extern int IrAndInt__deleting_dtor();
extern int IrRoundNearestEven__dtor();
extern int IrRoundNearestEven__deleting_dtor();
extern int IrCeil__dtor();
extern int IrCeil__deleting_dtor();
extern int IrSetNE_Dx10__dtor();
extern int IrSetNE_Dx10__deleting_dtor();
extern int IrSetGE_Dx10__dtor();
extern int IrSetGE_Dx10__deleting_dtor();
extern int IrSetE_Dx10__dtor();
extern int IrSetE_Dx10__deleting_dtor();
extern int IrFetchShaderCall__dtor();
extern int IrFetchShaderCall__deleting_dtor();
extern int IrScatter__dtor();
extern int IrScatter__deleting_dtor();
extern int IrCmovNE__dtor();
extern int IrCmovNE__deleting_dtor();
extern int IrCmovGT__dtor();
extern int IrCmovGT__deleting_dtor();
extern int IrCmovGE__dtor();
extern int IrCmovGE__deleting_dtor();
extern int IrCmovEQ__dtor();
extern int IrCmovEQ__deleting_dtor();
extern int IrFetchTextureUncached__dtor();
extern int IrFetchTextureUncached__deleting_dtor();
extern int IrFetchTextureLOD__dtor();
extern int IrFetchTextureLOD__deleting_dtor();
extern int IrCndGEInt__dtor();
extern int IrCndGEInt__deleting_dtor();
extern int IrCndGE1__dtor();
extern int IrCndGE1__deleting_dtor();
extern int IrCndGE__dtor();
extern int IrCndGE__deleting_dtor();
extern int IrCndGEFloat__dtor();
extern int IrCndGEFloat__deleting_dtor();
extern int IrMad__dtor();
extern int IrMad__deleting_dtor();
extern int IrR300ExpBaseE__dtor();
extern int IrR300ExpBaseE__deleting_dtor();
extern int IrDxLogp__dtor();
extern int IrDxLogp__deleting_dtor();
extern int IrR300Expp__dtor();
extern int IrR300Expp__deleting_dtor();
extern int IrPow__dtor();
extern int IrPow__deleting_dtor();
extern int IrLoad__dtor();
extern int IrLoad__deleting_dtor();
extern int IrDp3Add__dtor();
extern int IrDp3Add__deleting_dtor();
extern int IrMix__dtor();
extern int IrMix__deleting_dtor();
extern int IrDsy1__dtor();
extern int IrDsy1__deleting_dtor();
extern int IrDsy__dtor();
extern int IrDsy__deleting_dtor();
extern int IrDsx1__dtor();
extern int IrDsx1__deleting_dtor();
extern int IrDsx__dtor();
extern int IrDsx__deleting_dtor();
extern int IrCnd05__dtor();
extern int IrCnd05__deleting_dtor();
extern int IrPresubInvert__dtor();
extern int IrPresubInvert__deleting_dtor();
extern int IrPresubAdd__dtor();
extern int IrPresubAdd__deleting_dtor();
extern int IrPresubSub__dtor();
extern int IrPresubSub__deleting_dtor();
extern int IrPresubBX2Neg__dtor();
extern int IrPresubBX2Neg__deleting_dtor();
extern int IrOpSop__dtor();
extern int IrOpSop__deleting_dtor();
extern int IrOpDp__dtor();
extern int IrOpDp__deleting_dtor();
extern int IrAllocInterp__dtor();
extern int IrAllocInterp__deleting_dtor();
extern int IrAllocColor__dtor();
extern int IrAllocColor__deleting_dtor();
extern int IrAllocMem__dtor();
extern int IrAllocMem__deleting_dtor();
extern int IrAllocPos__dtor();
extern int IrAllocPos__deleting_dtor();
extern int IrEndMakeCall__dtor();
extern int IrEndMakeCall__deleting_dtor();
extern int IrEndCall__dtor();
extern int IrEndCall__deleting_dtor();
extern int IrStartMakeCall__dtor();
extern int IrStartMakeCall__deleting_dtor();
extern int IrStartCallRoutine__dtor();
extern int IrStartCallRoutine__deleting_dtor();
extern int IrPhi__dtor();
extern int IrPhi__deleting_dtor();
extern int IrCmp1S__dtor();
extern int IrCmp1S__deleting_dtor();
extern int IrCmp1D__dtor();
extern int IrCmp1D__deleting_dtor();
extern int IrCmp2__dtor();
extern int IrCmp2__deleting_dtor();
extern int IrEpilog__dtor();
extern int IrEpilog__deleting_dtor();
extern int IrProlog__dtor();
extern int IrProlog__deleting_dtor();
extern int IrExit__dtor();
extern int IrExit__deleting_dtor();
extern int IrEntry__dtor();
extern int IrEntry__deleting_dtor();
extern int IrHeader__dtor();
extern int IrHeader__deleting_dtor();
extern int IrUndefined__dtor();
extern int IrUndefined__deleting_dtor();
extern int IrProjection__dtor();
extern int IrProjection__deleting_dtor();
extern int IrMerge__dtor();
extern int IrMerge__deleting_dtor();
extern int IrLoopIndex__dtor();
extern int IrLoopIndex__deleting_dtor();
extern int IrLoopStart__dtor();
extern int IrLoopStart__deleting_dtor();
extern int IrPixelLoopFetch__dtor();
extern int IrPixelLoopFetch__deleting_dtor();
extern int IrVertexLoopFetch__dtor();
extern int IrVertexLoopFetch__deleting_dtor();
extern int IrLoadInterp__dtor();
extern int IrLoadInterp__deleting_dtor();
extern int IrLoadTempDefault__dtor();
extern int IrLoadTempDefault__deleting_dtor();
extern int IrLoadAbstractState__dtor();
extern int IrLoadAbstractState__deleting_dtor();
extern int IrLoadPhysical__dtor();
extern int IrLoadPhysical__deleting_dtor();
extern int IrLoadTemp__dtor();
extern int IrLoadTemp__deleting_dtor();
extern int IrLoadConst__dtor();
extern int IrLoadConst__deleting_dtor();
extern int IrMovaFloorInt__dtor();
extern int IrMovaFloorInt__deleting_dtor();
extern int IrMovaFloorGprInt__dtor();
extern int IrMovaFloorGprInt__deleting_dtor();
extern int IrMovaFloorFloat__dtor();
extern int IrMovaFloorFloat__deleting_dtor();
extern int IrMovaFlr__dtor();
extern int IrMovaFlr__deleting_dtor();
extern int IrMovaFloor__dtor();
extern int IrMovaFloor__deleting_dtor();
extern int IrSubPrev__dtor();
extern int IrSubPrev__deleting_dtor();
extern int IrMulPrev2__dtor();
extern int IrMulPrev2__deleting_dtor();
extern int IrMulPrev__dtor();
extern int IrMulPrev__deleting_dtor();
extern int IrAddPrev__dtor();
extern int IrAddPrev__deleting_dtor();
extern int IrPredSetRst__dtor();
extern int IrPredSetRst__deleting_dtor();
extern int IrPredSetClr__dtor();
extern int IrPredSetClr__deleting_dtor();
extern int IrPredSetPop__dtor();
extern int IrPredSetPop__deleting_dtor();
extern int IrPredSetInv__dtor();
extern int IrPredSetInv__deleting_dtor();
extern int IrPredSetGEInt__dtor();
extern int IrPredSetGEInt__deleting_dtor();
extern int IrPredSetGE__dtor();
extern int IrPredSetGE__deleting_dtor();
extern int IrPredSetLEInt__dtor();
extern int IrPredSetLEInt__deleting_dtor();
extern int IrPredSetLTInt__dtor();
extern int IrPredSetLTInt__deleting_dtor();
extern int IrPredSetGTInt__dtor();
extern int IrPredSetGTInt__deleting_dtor();
extern int IrPredSetGT__dtor();
extern int IrPredSetGT__deleting_dtor();
extern int IrPredSetNEInt__dtor();
extern int IrPredSetNEInt__deleting_dtor();
extern int IrPredSetNE__dtor();
extern int IrPredSetNE__deleting_dtor();
extern int IrPredSetEInt__dtor();
extern int IrPredSetEInt__deleting_dtor();
extern int IrPredSetE__dtor();
extern int IrPredSetE__deleting_dtor();
extern int IrKillOne__dtor();
extern int IrKillOne__deleting_dtor();
extern int IrCos__dtor();
extern int IrCos__deleting_dtor();
extern int IrSin__dtor();
extern int IrSin__deleting_dtor();
extern int IrSubConst1__dtor();
extern int IrSubConst1__deleting_dtor();
extern int IrMulConst1__dtor();
extern int IrMulConst1__deleting_dtor();
extern int IrAddConst1__dtor();
extern int IrAddConst1__deleting_dtor();
extern int IrSubConst0__dtor();
extern int IrSubConst0__deleting_dtor();
extern int IrMulConst0__dtor();
extern int IrMulConst0__deleting_dtor();
extern int IrAddConst0__dtor();
extern int IrAddConst0__deleting_dtor();
extern int IrFetchTextureMapGradients__dtor();
extern int IrFetchTextureMapGradients__deleting_dtor();
extern int IrFetchTextureMapKill__dtor();
extern int IrFetchTextureMapKill__deleting_dtor();
extern int IrFetchTextureMapBias__dtor();
extern int IrFetchTextureMapBias__deleting_dtor();
extern int IrFetchTextureMapProj__dtor();
extern int IrFetchTextureMapProj__deleting_dtor();
extern int IrSetFilter4Weights__dtor();
extern int IrSetFilter4Weights__deleting_dtor();
extern int IrSetGradientsV__dtor();
extern int IrSetGradientsV__deleting_dtor();
extern int IrSetGradientsH__dtor();
extern int IrSetGradientsH__deleting_dtor();
extern int IrSetTexLod__dtor();
extern int IrSetTexLod__deleting_dtor();
extern int IrGetWeights__dtor();
extern int IrGetWeights__deleting_dtor();
extern int IrGetGradients__dtor();
extern int IrGetGradients__deleting_dtor();
extern int IrGetCompTexLod__dtor();
extern int IrGetCompTexLod__deleting_dtor();
extern int IrGetBorderColorFraction__dtor();
extern int IrGetBorderColorFraction__deleting_dtor();
extern int IrFetchMultiSample__dtor();
extern int IrFetchMultiSample__deleting_dtor();
extern int IrFetchShadowMap__dtor();
extern int IrFetchShadowMap__deleting_dtor();
extern int IrFetch3DNoiseMap__dtor();
extern int IrFetch3DNoiseMap__deleting_dtor();
extern int IrFetchTextureMap__dtor();
extern int IrFetchTextureMap__deleting_dtor();
extern int IrFetchVertex__dtor();
extern int IrFetchVertex__deleting_dtor();
extern int IrSqrt__dtor();
extern int IrSqrt__deleting_dtor();
extern int IrRecipSqrtInternal__dtor();
extern int IrRecipSqrtInternal__deleting_dtor();
extern int IrLogInternal__dtor();
extern int IrLogInternal__deleting_dtor();
extern int IrExp__dtor();
extern int IrExp__deleting_dtor();
extern int IrSub__dtor();
extern int IrSub__deleting_dtor();
extern int IrNop1__dtor();
extern int IrNop1__deleting_dtor();
extern int IrNop__dtor();
extern int IrNop__deleting_dtor();
extern int IrLit__dtor();
extern int IrLit__deleting_dtor();
extern int IrMov__dtor();
extern int IrMov__deleting_dtor();
extern int IrMovFloat__dtor();
extern int IrMovFloat__deleting_dtor();
extern int IrExportRing__dtor();
extern int IrExportRing__deleting_dtor();
extern int IrExport__dtor();
extern int IrExport__deleting_dtor();
extern int IrExportFloat__dtor();
extern int IrExportFloat__deleting_dtor();
extern int IrPredSetGEPushInt__dtor();
extern int IrPredSetGEPushInt__deleting_dtor();
extern int IrPredSetGEPush__dtor();
extern int IrPredSetGEPush__deleting_dtor();
extern int IrPredSetGTPushInt__dtor();
extern int IrPredSetGTPushInt__deleting_dtor();
extern int IrPredSetGTPush__dtor();
extern int IrPredSetGTPush__deleting_dtor();
extern int IrPredSetNEPushInt__dtor();
extern int IrPredSetNEPushInt__deleting_dtor();
extern int IrPredSetNEPush__dtor();
extern int IrPredSetNEPush__deleting_dtor();
extern int IrPredSetLEPushInt__dtor();
extern int IrPredSetLEPushInt__deleting_dtor();
extern int IrPredSetLTPushInt__dtor();
extern int IrPredSetLTPushInt__deleting_dtor();
extern int IrPredSetEPushInt__dtor();
extern int IrPredSetEPushInt__deleting_dtor();
extern int IrPredSetEPush__dtor();
extern int IrPredSetEPush__deleting_dtor();
extern int IrMovaRound__dtor();
extern int IrMovaRound__deleting_dtor();
extern int IrMovaRoundFloat__dtor();
extern int IrMovaRoundFloat__deleting_dtor();
extern int IrSetNEInt__dtor();
extern int IrSetNEInt__deleting_dtor();
extern int IrSetNE__dtor();
extern int IrSetNE__deleting_dtor();
extern int IrSetNEFloat__dtor();
extern int IrSetNEFloat__deleting_dtor();
extern int IrSetGE_uint__dtor();
extern int IrSetGE_uint__deleting_dtor();
extern int IrSetGEInt__dtor();
extern int IrSetGEInt__deleting_dtor();
extern int IrSetGE__dtor();
extern int IrSetGE__deleting_dtor();
extern int IrSetGEFloat__dtor();
extern int IrSetGEFloat__deleting_dtor();
extern int IrSetGTUint__dtor();
extern int IrSetGTUint__deleting_dtor();
extern int IrSetGTInt__dtor();
extern int IrSetGTInt__deleting_dtor();
extern int IrSetGTDx10__dtor();
extern int IrSetGTDx10__deleting_dtor();
extern int IrSetGT__dtor();
extern int IrSetGT__deleting_dtor();
extern int IrSetGTFloat__dtor();
extern int IrSetGTFloat__deleting_dtor();
extern int IrSetEInt__dtor();
extern int IrSetEInt__deleting_dtor();
extern int IrSetE__dtor();
extern int IrSetE__deleting_dtor();
extern int IrSetEFloat__dtor();
extern int IrSetEFloat__deleting_dtor();
extern int IrCndGT1__dtor();
extern int IrCndGT1__deleting_dtor();
extern int IrCndGTInt__dtor();
extern int IrCndGTInt__deleting_dtor();
extern int IrCndGT__dtor();
extern int IrCndGT__deleting_dtor();
extern int IrCndGTFloat__dtor();
extern int IrCndGTFloat__deleting_dtor();
extern int IrCndE1__dtor();
extern int IrCndE1__deleting_dtor();
extern int IrCndEInt__dtor();
extern int IrCndEInt__deleting_dtor();
extern int IrCndE__dtor();
extern int IrCndE__deleting_dtor();
extern int IrCndEFloat__dtor();
extern int IrCndEFloat__deleting_dtor();
extern int IrKillNE__dtor();
extern int IrKillNE__deleting_dtor();
extern int IrKillNEFloat__dtor();
extern int IrKillNEFloat__deleting_dtor();
extern int IrKillGE__dtor();
extern int IrKillGE__deleting_dtor();
extern int IrKillGEFloat__dtor();
extern int IrKillGEFloat__deleting_dtor();
extern int IrKillGT__dtor();
extern int IrKillGT__deleting_dtor();
extern int IrKillGTFloat__dtor();
extern int IrKillGTFloat__deleting_dtor();
extern int IrKillE__dtor();
extern int IrKillE__deleting_dtor();
extern int IrKillEFloat__dtor();
extern int IrKillEFloat__deleting_dtor();
extern int IrDst__dtor();
extern int IrDst__deleting_dtor();
extern int IrDot2AddIEEE__dtor();
extern int IrDot2AddIEEE__deleting_dtor();
extern int IrDot4IEEE__dtor();
extern int IrDot4IEEE__deleting_dtor();
extern int IrDot4__dtor();
extern int IrDot4__deleting_dtor();
extern int IrMulHiUInt__dtor();
extern int IrMulHiUInt__deleting_dtor();
extern int IrMulLowUInt__dtor();
extern int IrMulLowUInt__deleting_dtor();
extern int IrMulHiInt__dtor();
extern int IrMulHiInt__deleting_dtor();
extern int IrMulLowInt__dtor();
extern int IrMulLowInt__deleting_dtor();
extern int IrLshlInt__dtor();
extern int IrLshlInt__deleting_dtor();
extern int IrLshrInt__dtor();
extern int IrLshrInt__deleting_dtor();
extern int IrAshrInt__dtor();
extern int IrAshrInt__deleting_dtor();
extern int IrUInt2F__dtor();
extern int IrUInt2F__deleting_dtor();
extern int IrInt2F__dtor();
extern int IrInt2F__deleting_dtor();
extern int IrF2UInt__dtor();
extern int IrF2UInt__deleting_dtor();
extern int IrF2Int__dtor();
extern int IrF2Int__deleting_dtor();
extern int IrDot3IEEE__dtor();
extern int IrDot3IEEE__deleting_dtor();
extern int IrDot3__dtor();
extern int IrDot3__deleting_dtor();
extern int IrCube__dtor();
extern int IrCube__deleting_dtor();
extern int IrTrunc__dtor();
extern int IrTrunc__deleting_dtor();
extern int IrTruncFloat__dtor();
extern int IrTruncFloat__deleting_dtor();
extern int IrRecipUInt__dtor();
extern int IrRecipUInt__deleting_dtor();
extern int IrRecipInt__dtor();
extern int IrRecipInt__deleting_dtor();
extern int IrRecipInternal__dtor();
extern int IrRecipInternal__deleting_dtor();
extern int IrMinDx10__dtor();
extern int IrMinDx10__deleting_dtor();
extern int IrMinUInt__dtor();
extern int IrMinUInt__deleting_dtor();
extern int IrMinInt__dtor();
extern int IrMinInt__deleting_dtor();
extern int IrMin__dtor();
extern int IrMin__deleting_dtor();
extern int IrMinFloat__dtor();
extern int IrMinFloat__deleting_dtor();
extern int IrMax4__dtor();
extern int IrMax4__deleting_dtor();
extern int IrMaxDx10__dtor();
extern int IrMaxDx10__deleting_dtor();
extern int IrMax__dtor();
extern int IrMax__deleting_dtor();
extern int IrMaxUInt__dtor();
extern int IrMaxUInt__deleting_dtor();
extern int IrMaxInt__dtor();
extern int IrMaxInt__deleting_dtor();
extern int IrMaxFloat__dtor();
extern int IrMaxFloat__deleting_dtor();
extern int IrFract__dtor();
extern int IrFract__deleting_dtor();
extern int IrFractFloat__dtor();
extern int IrFractFloat__deleting_dtor();
extern int IrFloor__dtor();
extern int IrFloor__deleting_dtor();
extern int IrFloorFloat__dtor();
extern int IrFloorFloat__deleting_dtor();
extern int IrMulAddIEEE__dtor();
extern int IrMulAddIEEE__deleting_dtor();
extern int IrMulAdd__dtor();
extern int IrMulAdd__deleting_dtor();
extern int IrMulAddFloat__dtor();
extern int IrMulAddFloat__deleting_dtor();
extern int IrMulIEEE__dtor();
extern int IrMulIEEE__deleting_dtor();
extern int IrSubInt__dtor();
extern int IrSubInt__deleting_dtor();
extern int IrAddInt__dtor();
extern int IrAddInt__deleting_dtor();
extern int IrAddFloat__dtor();
extern int IrAddFloat__deleting_dtor();
extern int IrAlloc__dtor();
extern int IrAlloc__deleting_dtor();
extern int IrCondJmp__dtor();
extern int IrCondJmp__deleting_dtor();
extern int IrRet__dtor();
extern int IrRet__deleting_dtor();
extern int VRegInfo__dtor();
extern int VRegInfo__deleting_dtor();
extern int ImmedConstBuffer__deleting_dtor();
extern int TempValue__dtor_1d79f4();
extern int TempValue__dtor_1d7a3c();
extern int TempValue__dtor_1d7a70();
extern int TempValue__dtor_1d7ab8();
extern int Physical__dtor();
extern int Physical__deleting_dtor();
extern int AddrIndexedSet__dtor();
extern int AddrIndexedSet__deleting_dtor();
extern int LoopRegister__dtor();
extern int LoopRegister__deleting_dtor();
extern int LoopIndexedSet__dtor();
extern int LoopIndexedSet__deleting_dtor();
extern int ExportAddress__dtor();
extern int ExportAddress__deleting_dtor();
extern int ExportValue__dtor();
extern int ExportValue__deleting_dtor();
extern int Interpolator__dtor();
extern int Interpolator__deleting_dtor();
extern int TempValue__dtor_1d7e50();
extern int TempValue__deleting_dtor();
extern int ExportSlot__dtor();
extern int ExportSlot__deleting_dtor();
extern int Resource__dtor();
extern int Resource__deleting_dtor();
extern int VertexRegister__dtor();
extern int VertexRegister__deleting_dtor();
extern int FixedValue__dtor();
extern int FixedValue__deleting_dtor();
extern int ImmedConstBuffer__dtor();
extern int LoopIndexedConstSet__dtor();
extern int LoopIndexedConstSet__deleting_dtor();
extern int LoopIndexedInputSet__dtor();
extern int LoopIndexedInputSet__deleting_dtor();
extern int LoopIndexedOutputSet__dtor();
extern int LoopIndexedOutputSet__deleting_dtor();
extern int KhanPs__deleting_dtor();
extern int KhanChip__deleting_dtor();
extern int KhanChip__dtor();
extern int KhanPs__dtor();
extern int KhanVs__deleting_dtor_1d84ac();
extern int KhanVs__dtor_1d84e0();
extern int KhanVs__deleting_dtor_1d8514();
extern int KhanVs__dtor_1d8548();
extern int MirrorBlock__getKindName();
extern int MirrorBlock__deleting_dtor();
extern int MirrorBlock__dtor();
extern int SchedNode__dtor();
extern int SchedNode__deleting_dtor();
extern int ResourceModel__deleting_dtor();
extern int ThreadModel__deleting_dtor();
extern int ThreadModel__dtor();
extern int ResourceModel__dtor();
extern int R300SchedModel__dtor();
extern int R300VSchedModel__dtor();
extern int R300VSchedModel__deleting_dtor();
extern int FudoChip__deleting_dtor();
extern int FudoPs__deleting_dtor();
extern int FudoChip__dtor();
extern int FudoPs__dtor();
extern int R520SchedModel__deleting_dtor();
extern int R520SchedModel__dtor();
extern int R520MachineAssembler__deleting_dtor();
extern int R520MachineAssembler__dtor();
extern int Count();
extern int LoopStart();
extern int LoopStep();
extern int Rewrite();
extern int Target();
extern int _CFDictionaryCreate();
extern int _CFDictionaryGetValue();
extern int _CFNotificationCenterAddObserver();
extern int _CFNotificationCenterGetDistributedCenter();
extern int _CFNotificationCenterPostNotification();
extern int _CFNotificationCenterRemoveObserver();
extern int _CFNumberCreate();
extern int _CFNumberGetValue();
extern int _CFRelease();
extern int _CFStringCreateWithCString();
extern int _IOConnectAddClient();
extern int _IOConnectMapMemory();
extern int _IOServiceClose();
extern int _IOServiceOpen();
extern int _NSAddressOfSymbol();
extern int _NSIsSymbolNameDefinedWithHint();
extern int _NSLookupAndBindSymbolWithHint();
extern int __Unwind_Resume();
extern int ___cxa_guard_acquire();
extern int ___cxa_guard_release();
extern int __keymgr_get_and_lock_processwide_ptr();
extern int __keymgr_set_and_unlock_processwide_ptr();
extern int _aniso();
extern int _aoffimmi();
extern int _calloc();
extern double _ceil();
extern int _cmpval();
extern int _coordmode();
extern double _cos();
extern int _divcomp();
extern int _dlopen();
extern int _dlsym();
extern int _ecvt();
extern int _elem();
extern int _elemOffset();
extern int _exit();
extern int _exportStream();
extern int _fclose();
extern int _fgets();
extern double _floor();
extern int _fmtw();
extern int _fmtx();
extern int _fmty();
extern int _fmtz();
extern int _fopen();
extern int _fread();
extern int _free();
extern double _frexp();
extern int _fwrite();
extern int _getenv();
extern int _getpid();
extern int _glgConvertType();
extern int _glgPixelCenters();
extern int _glgProcessPixels();
extern int _glpFreePPShaderLinearize();
extern int _glpFreePPShaderToProgram();
extern int _glpPPShaderLinearize();
extern int _glpPPShaderToProgram();
extern int _glpUniformToFloat();
extern int _id();
extern int _index();
extern int _interp();
extern int _io_connect_method_scalarI_scalarO();
extern int _io_connect_method_scalarI_structureI();
extern int _io_connect_method_structureI_structureO();
extern int _lodbias();
extern double _log();
extern float _logf();
extern int _longjmp();
extern int _mag();
extern int _malloc();
extern int _matrix();
extern int _memcmp();
extern int _memcpy();
extern int _memmove();
extern int _memset();
extern int _min();
extern int _mip();
extern int _neg();
extern int _param();
extern int _pclose();
extern int _popen();
extern double _pow();
extern int _pthread_mutex_destroy();
extern int _pthread_mutex_init();
extern int _pthread_mutex_lock();
extern int _pthread_mutex_unlock();
extern int _pthread_mutexattr_init();
extern int _pthread_mutexattr_settype();
extern int _puts();
extern int _realloc();
extern int _relop();
extern int _resource();
extern int _rindex();
extern double _round();
extern int _sampler();
extern int _setjmp();
extern int _shadowmode();
extern double _sin();
extern double _sqrt();
extern float _sqrtf();
extern int _stage();
extern int _stateStride();
extern int _strcat();
extern int _strchr();
extern int _strcmp();
extern int _strcpy();
extern int _strlcpy();
extern int _strlen();
extern int _strncmp();
extern int _type();
extern int _usage();
extern int _usageIndex();
extern int _usleep();
extern int _valloc();
extern int _vfree();
extern int _volmag();
extern int _volmin();
extern int _w();
extern int _x();
extern int _xoffset();
extern int _y();
extern int _yoffset();
extern int _z();
extern int _zeroop();
extern int _zoffset();
extern int abs();
extern int builtin_strncpy();
extern int cmp();
extern int cnd();
extern int component();
extern double cos();
extern int d();
extern int d2a();
extern int dp();
extern int dp3();
extern int dp4();
extern int ex2();
extern int frc();
extern int instruction();
extern int invalidRegUsage();
extern int kill();
extern int ln2();
extern int lookup();
extern int lookup_dxdy();
extern int lookup_lod();
extern int lookup_lodbias();
extern int lookup_proj();
extern int lookup_uncached();
extern int mad();
extern int max();
extern int mdh();
extern int mdv();
extern int min();
extern int nab();
extern int neg();
extern int operator_delete();
extern int packed();
extern int rcp();
extern int rsq();
extern int s();
extern double sin();
extern int sop();
extern int storeWordConditionalIndexed();
extern int te();
extern int thunk_FUN_00053b60();
extern int thunk_FUN_00054a90();
extern int thunk_FUN_000a2330();
extern int thunk_FUN_001268a4();
extern int thunk_FUN_001307f8();
extern int thunk_FUN_00134de8();
extern unsigned char DAT_001aa3a8;
extern unsigned char DAT_001aa4b0;
extern unsigned char DAT_001aa4b4;
extern unsigned char DAT_001aa4b8;
extern unsigned char DAT_001aa4bc;
extern unsigned char DAT_001aa4c0;
extern unsigned char DAT_001aa4c4;
extern unsigned char DAT_001aa4e8;
extern unsigned char DAT_001aa4ec;
extern unsigned char DAT_001aa4f0;
extern unsigned char DAT_001aa4f4;
extern unsigned char DAT_001aa4f8;
extern unsigned char DAT_001aa4fc;
extern unsigned char DAT_001aa500;
extern unsigned char DAT_001aa504;
extern unsigned char DAT_001aa508;
extern unsigned char DAT_001aa50c;
extern unsigned char DAT_001aa510;
extern unsigned char DAT_001aa554;
extern unsigned char DAT_001aa558;
extern unsigned char DAT_001aa55c;
extern unsigned char DAT_001aa560;
extern unsigned char DAT_001aa564;
extern unsigned char DAT_001aa568;
extern unsigned char DAT_001aa56c;
extern unsigned char DAT_001aa570;
extern unsigned char DAT_001aa584;
extern unsigned char DAT_001aa588;
extern unsigned char DAT_001aa58c;
extern unsigned char DAT_001aa5f0;
extern unsigned char DAT_001aa5f4;
extern unsigned char DAT_001aa5f8;
extern unsigned char DAT_001aa5fc;
extern unsigned char DAT_001aa600[];
extern unsigned char DAT_001aa758[];
extern unsigned char DAT_001aa760[];
extern unsigned char DAT_001aa761;
extern unsigned char DAT_001aa764[];
extern unsigned char DAT_001aa7a8;
extern unsigned char DAT_001aa7d0;
extern unsigned char DAT_001aa7dc;
extern unsigned char DAT_001aa7e8;
extern unsigned char DAT_001aa7fc;
extern unsigned char DAT_001aa800;
extern unsigned char DAT_001aa804;
extern unsigned char DAT_001aa80c;
extern unsigned char DAT_001aa810;
extern unsigned char DAT_001aa818[];
extern unsigned char DAT_001aa838;
extern unsigned char DAT_001aa83c;
extern unsigned char DAT_001aa840;
extern unsigned char DAT_001aa850;
extern unsigned char DAT_001aa854;
extern unsigned char DAT_001aa858;
extern unsigned char DAT_001aa85c;
extern unsigned char DAT_001aa860;
extern unsigned char DAT_001aa868;
extern unsigned char DAT_001aa86c;
extern unsigned char DAT_001aa87c;
extern unsigned char DAT_001aa9a8;
extern unsigned char DAT_001aa9cc;
extern unsigned char DAT_001aa9d0;
extern unsigned char DAT_001aa9dc;
extern unsigned char DAT_001aa9e0;
extern unsigned char DAT_001aa9e4;
extern unsigned char DAT_001aa9fc;
extern unsigned char DAT_001ab134;
extern unsigned char DAT_001abfb4;
extern unsigned char DAT_001ac5a4;
extern unsigned char DAT_001acec0;
extern unsigned char DAT_001ad5d8;
extern unsigned char DAT_001af9bc;
extern unsigned char DAT_001af9c0;
extern unsigned char DAT_001af9c4;
extern unsigned char DAT_001af9c8;
extern unsigned char DAT_001af9cc;
extern unsigned char DAT_001af9d0;
extern unsigned char DAT_001af9dc;
extern unsigned char DAT_001af9e0;
extern unsigned char DAT_001af9ec;
extern unsigned char DAT_001af9fc;
extern unsigned char DAT_001afa04;
extern unsigned char DAT_001afa08;
extern unsigned char DAT_001afa0c;
extern unsigned char DAT_001afa14;
extern unsigned char DAT_001afa18;
extern unsigned char DAT_001afee4;
extern unsigned char DAT_001afee8;
extern unsigned char DAT_001afeec;
extern unsigned char DAT_001afef0;
extern unsigned char DAT_001afef8;
extern unsigned char DAT_001aff08;
extern unsigned char DAT_001aff0c;
extern unsigned char DAT_001aff48;
extern unsigned char DAT_001aff4c;
extern unsigned char DAT_001aff50;
extern unsigned char DAT_001aff68;
extern unsigned char DAT_001aff74;
extern unsigned char DAT_001aff9c;
extern unsigned char DAT_001affa4;
extern unsigned char DAT_001affb0;
extern unsigned char DAT_001affb8;
extern unsigned char DAT_001affc0;
extern unsigned char DAT_001affc4;
extern unsigned char DAT_001affc8;
extern unsigned char DAT_001affcc;
extern unsigned char DAT_001afffc;
extern unsigned char DAT_001b0000;
extern unsigned char DAT_001b0004;
extern unsigned char DAT_001b0008;
extern unsigned char DAT_001b0014;
extern unsigned char DAT_001b001c;
extern unsigned char DAT_001b0020;
extern unsigned char DAT_001b0038;
extern unsigned char DAT_001b003c;
extern unsigned char DAT_001b0040;
extern unsigned char DAT_001b0044;
extern unsigned char DAT_001b0048;
extern unsigned char DAT_001b004c;
extern unsigned char DAT_001b0050;
extern unsigned char DAT_001b0054;
extern unsigned char DAT_001b0058;
extern unsigned char DAT_001b005c;
extern unsigned char DAT_001b0060;
extern unsigned char DAT_001b0160;
extern unsigned char DAT_001b0170;
extern unsigned char DAT_001b0194;
extern unsigned char DAT_001b0198;
extern unsigned char DAT_001b01a0;
extern unsigned char DAT_001b01a8;
extern unsigned char DAT_001b01ac;
extern unsigned char DAT_001b01b0;
extern unsigned char DAT_001b01b4;
extern unsigned char DAT_001b01b8;
extern unsigned char DAT_001b01bc;
extern unsigned char DAT_001b01d0;
extern unsigned char DAT_001b01d8;
extern unsigned char DAT_001b01dc;
extern unsigned char DAT_001b01e0;
extern unsigned char DAT_001b01e8;
extern unsigned char DAT_001b01ec;
extern unsigned char DAT_001b01f0;
extern unsigned char DAT_001b01f4;
extern unsigned char DAT_001b0210;
extern unsigned char DAT_001b0214;
extern unsigned char DAT_001b0218;
extern unsigned char DAT_001b021c;
extern unsigned char DAT_001b0220;
extern unsigned char DAT_001b0224;
extern unsigned char DAT_001b0228;
extern unsigned char DAT_001b0240;
extern unsigned char DAT_001b0244;
extern unsigned char DAT_001b02ec;
extern unsigned char DAT_001b19e0;
extern unsigned char DAT_001b2994;
extern unsigned char DAT_001b2a64;
extern unsigned char DAT_001b2a68;
extern unsigned char DAT_001b2a80;
extern unsigned char DAT_001b2a84;
extern unsigned char DAT_001b2ab4;
extern unsigned char DAT_001b2ab8;
extern unsigned char DAT_001b2abc;
extern unsigned char DAT_001b2ac0;
extern unsigned char DAT_001b2ac4;
extern unsigned char DAT_001b2ad0;
extern unsigned char DAT_001b2be8;
extern unsigned char DAT_001b2c14;
extern unsigned char DAT_001b2d4c;
extern unsigned char DAT_001b2d50;
extern unsigned char DAT_001b2d54;
extern unsigned char DAT_001b2d58;
extern unsigned char DAT_001b2d5c;
extern unsigned char DAT_001b2d60;
extern unsigned char DAT_001b2d64;
extern unsigned char DAT_001b2d68;
extern unsigned char DAT_001b2d70;
extern unsigned char DAT_001b2eb8;
extern unsigned char DAT_001b40f0;
extern unsigned char DAT_001b81b8;
extern unsigned char DAT_001b9d04;
extern unsigned char DAT_001d91f0;
extern unsigned char DAT_001d92a8;
extern unsigned char DAT_001d9358;
extern unsigned char DAT_001d9408;
extern unsigned char DAT_001d94b8;
extern unsigned char DAT_001d9568;
extern unsigned char DAT_001d9594;
extern unsigned char DAT_001d9644;
extern unsigned char DAT_001d96f4;
extern unsigned char DAT_001d9778;
extern unsigned char DAT_001d9888;
extern unsigned char DAT_001d98b0;
extern unsigned char DAT_001d9960;
extern unsigned char DAT_001d9a10;
extern unsigned char DAT_001d9ac0;
extern unsigned char DAT_001d9b70;
extern unsigned char DAT_001d9b9c;
extern unsigned char DAT_001d9c4c;
extern unsigned char DAT_001d9cfc;
extern unsigned char DAT_001d9dac;
extern unsigned char DAT_001d9dd8;
extern unsigned char DAT_001d9eb0;
extern unsigned char DAT_001d9f34;
extern unsigned char DAT_001d9f3c;
extern unsigned char DAT_001d9f3e;
extern unsigned char DAT_001d9f40;
extern unsigned char DAT_001d9f44;
extern unsigned char DAT_001d9f48;
extern unsigned char DAT_001d9f4c;
extern unsigned char DAT_001d9f50;
extern unsigned char DAT_001d9f54;
extern unsigned char DAT_001d9fa0;
extern unsigned char DAT_001da00c;
extern unsigned char DAT_001da054;
extern unsigned char DAT_001da1bc;
extern unsigned char DAT_001da36c;
extern unsigned char DAT_001da500;
extern unsigned char DAT_001da50c;
extern unsigned char DAT_001da630;
extern unsigned char DAT_001dac00[];
extern unsigned char DAT_001dac08;
extern unsigned char DAT_001dac34;
extern unsigned char DAT_001dac38;
extern unsigned char DAT_001dac3c;
extern unsigned char DAT_001dac40;
extern unsigned char DAT_001db2d4;
extern unsigned char DAT_001db2d8;
extern unsigned char DAT_001db2e0;
extern unsigned char DAT_001db2e4;
extern unsigned char DAT_001db2e8;
extern unsigned char DAT_001db2f0;
extern unsigned char DAT_001db2f4;
extern unsigned char DAT_001db344;
extern unsigned char DAT_001db348;
extern unsigned char DAT_001db368;
extern unsigned char DAT_001db440;
extern unsigned char DAT_001db5b8;
extern unsigned char DAT_001db5bc;
extern unsigned char DAT_001db5c0;
extern unsigned char DAT_001db5c4;
extern unsigned char DAT_001db928;
extern unsigned char DAT_001db92c;
extern unsigned char DAT_001db930;
extern unsigned char DAT_001db934;
extern unsigned char DAT_001db938;
extern unsigned char DAT_001db98c;
extern unsigned char DAT_001db998;
extern unsigned char DAT_001db9a8;
extern unsigned char DAT_001dba44;
extern unsigned char DAT_001dba98;
extern unsigned char DAT_001dbab8;
extern unsigned char DAT_001dbca8;
extern unsigned char DAT_001dbcac;
extern unsigned char DAT_001dbcb0;
extern unsigned char DAT_001dbcb4;
extern unsigned char DAT_001dbcb8;
extern unsigned char DAT_001dbcbc;
extern unsigned char DAT_001dbcc0;
extern unsigned char DAT_001dbcc4;
extern unsigned char DAT_001dbcc8;
extern unsigned char DAT_001dbccc;
extern unsigned char DAT_001dbcd0;
extern unsigned char DAT_001dbcd4;
extern unsigned char DAT_001dbcd8;
extern unsigned char DAT_001dbcdc;
extern unsigned char DAT_001dbce0;
extern unsigned char DAT_001dbce4;
extern unsigned char DAT_001dbce8;
extern unsigned char DAT_001dbcec;
extern unsigned char DAT_001dbcf0;
extern unsigned char DAT_001dbcf4;
extern unsigned char DAT_001dbcf8;
extern unsigned char DAT_001dbcfc;
extern unsigned char DAT_001dbd00;
extern unsigned char DAT_001dbd04;
extern unsigned char DAT_001dbd08;
extern unsigned char DAT_001dbd0c;
extern unsigned char DAT_001dbd10;
extern unsigned char DAT_001dbd14;
extern unsigned char DAT_001dbd18;
extern unsigned char DAT_001dbd1c;
extern unsigned char DAT_001dbd20;
extern unsigned char DAT_001dbd24;
extern unsigned char DAT_001dbd28;
extern unsigned char DAT_001dbd2c;
extern unsigned char DAT_001dbd30;
extern unsigned char DAT_001dbd34;
extern unsigned char DAT_001dbd38;
extern unsigned char DAT_001dbd3c;
extern unsigned char DAT_001dbd40;
extern unsigned char DAT_001dbd44;
extern unsigned char DAT_001dbd48;
extern unsigned char DAT_001dbd4c;
extern unsigned char DAT_001dbd50;
extern unsigned char DAT_001dbd54;
extern unsigned char DAT_001dbd58;
extern unsigned char DAT_001dbd5c;
extern unsigned char DAT_001dbd60;
extern unsigned char DAT_001dbd64;
extern unsigned char DAT_001dbd68;
extern unsigned char DAT_001dbd6c;
extern unsigned char DAT_001dbd70;
extern unsigned char DAT_001dbd74;
extern unsigned char DAT_001dbd78;
extern unsigned char DAT_001dbd7c;
extern unsigned char DAT_001dbd80;
extern unsigned char DAT_001dbd84;
extern unsigned char DAT_001dbd88;
extern unsigned char DAT_001dbd8c;
extern unsigned char DAT_001dbd90;
extern unsigned char DAT_001dbd94;
extern unsigned char DAT_001dbda4;
extern unsigned char DAT_001dbda8;
extern unsigned char DAT_001dbdac;
extern unsigned char DAT_001dbdb0;
extern unsigned char DAT_001dbdb4;
extern unsigned char DAT_001dbdb8;
extern unsigned char DAT_001dbdbc;
extern unsigned char DAT_001dbdc0;
extern unsigned char DAT_001dbdfc;
extern unsigned char DAT_001dbea4;
extern unsigned char DAT_001dbeac;
extern unsigned char DAT_001dbec4;
extern unsigned char DAT_001dbed4;
extern unsigned char DAT_001dbf2c;
extern unsigned char DAT_001dbf70;
extern unsigned char DAT_001dbf90;
extern unsigned char DAT_001dbf94;
extern unsigned char DAT_001dc58c[];
extern unsigned char DAT_001dca64;
extern unsigned char DAT_001df1fc;
extern unsigned char DAT_001e1994;
extern unsigned char DAT_001e1c1c;
extern unsigned char DAT_001e1c2c;
extern unsigned char DAT_001e1c30;
extern unsigned char DAT_001e25f4;
extern unsigned char DAT_001e2604;
extern unsigned char DAT_001e2608;
extern unsigned char DAT_001e3520;
extern unsigned char DAT_001e39a4;
extern unsigned char DAT_001e3a54;
extern unsigned char DAT_001e59b4;
extern unsigned char DAT_001e5a44;
extern unsigned char DAT_001e5ad4;
extern unsigned char DAT_001e5b64;
extern unsigned char DAT_001e5bf4;
extern unsigned char DAT_001e5c84;
extern unsigned char DAT_001e5d14;
extern unsigned char DAT_001e5da4;
extern unsigned char DAT_001e5e34;
extern unsigned char DAT_001e5ec4;
extern unsigned char DAT_001e5f54;
extern unsigned char DAT_001e6014;
extern unsigned char DAT_001e60a4;
extern unsigned char DAT_001e6134;
extern unsigned char DAT_001e6158[];
extern unsigned char DAT_001e6170;
extern unsigned char DAT_001e6188;
extern unsigned char DAT_001e61a0[];
extern unsigned char DAT_001e61b8;
extern unsigned char DAT_001e61d0[];
extern unsigned char DAT_001e61e8;
extern unsigned char DAT_001e6668;
extern unsigned char DAT_001e66cc;
extern unsigned char DAT_001e6730;
extern int (*DAT_001e8740)();
extern int (*DAT_001e8744)();
extern unsigned char DAT_001ea4fc;
extern unsigned char DAT_001ea500;
extern unsigned char DAT_001ea904;
extern unsigned char DAT_001ea908[];
extern unsigned char DAT_001f3a54;
extern unsigned char *DAT_001f65e0;
extern unsigned char DAT_001f65e4[];
extern unsigned char DAT_001f65e5[];
extern unsigned char DAT_001f65e6[];
extern unsigned char DAT_001f65e7;
extern unsigned char DAT_001f8514;
extern unsigned char DAT_001fa5e4;
extern unsigned char DAT_001fa5e8;
extern unsigned char DAT_001fa5f8;
extern unsigned char DAT_001fa5fc;
extern unsigned char DAT_001fa600;
extern unsigned char DAT_001fa604;
extern unsigned char DAT_001fa608;
extern unsigned char DAT_001fa60c;
extern unsigned char DAT_001fa610;
extern unsigned char DAT_001fa614;
extern unsigned char DAT_001fa618;
extern unsigned char *DAT_001fa61c;
extern unsigned char DAT_001fa620;
extern unsigned char DAT_001fa628;
extern unsigned char DAT_001fa630;
extern unsigned char DAT_001fa638;
extern unsigned char DAT_001fa640;
extern unsigned char DAT_001fa648;
extern unsigned char DAT_001fa650;
extern unsigned char DAT_001fa658;
extern unsigned char DAT_001fa660;
extern unsigned char DAT_001fa668;
extern unsigned char DAT_001fa670;
extern unsigned char DAT_001fa678;
extern unsigned char DAT_001fa680;
extern unsigned char DAT_001fa688;
extern unsigned char DAT_001fa690;
extern unsigned char DAT_001fa698;
extern unsigned char DAT_001fa6a0;
extern unsigned char DAT_001fa6a8;
extern unsigned char DAT_001fa6b0;
extern unsigned char DAT_001fa6b8;
extern unsigned char DAT_001fa6c0;
extern unsigned char DAT_001fa6c8;
extern unsigned char DAT_001fa6d0;
extern unsigned char DAT_001fa6d8;
extern unsigned char DAT_001fa6e0;
extern unsigned char DAT_001fa6e8;
extern unsigned char DAT_001fa6f0;
extern unsigned char DAT_001fa6f8;
extern unsigned char DAT_001fa700;
extern unsigned char DAT_001fa708;
extern unsigned char DAT_001fa710;
extern unsigned char DAT_001fa718;
extern unsigned char DAT_001fa720;
extern unsigned char DAT_001fa728;
extern unsigned char DAT_001fa730;
extern unsigned char DAT_001fa738;
extern unsigned char DAT_001fa740;
extern unsigned char DAT_001fa748;
extern unsigned char DAT_001fa750;
extern unsigned char DAT_001fa758;
extern unsigned char DAT_001fa760;
extern unsigned char DAT_001fa768;
extern unsigned char DAT_001fa770;
extern unsigned char DAT_001fa778;
extern unsigned char DAT_001fa780;
extern unsigned char DAT_001fa788;
extern unsigned char DAT_001fa790;
extern unsigned char DAT_001fa798;
extern unsigned char DAT_001fa7a0;
extern unsigned char DAT_001fa7a8;
extern unsigned char DAT_001fa7b0;
extern unsigned char DAT_001fa7b8;
extern unsigned char DAT_001fa7c0;
extern unsigned char DAT_001fa7c8;
extern unsigned char DAT_001fa7d0;
extern unsigned char DAT_001fa7d8;
extern unsigned char DAT_001fa7e0;
extern unsigned char DAT_001fa7e8;
extern unsigned char DAT_001fa7f0;
extern unsigned char DAT_001fa7f8;
extern unsigned char DAT_001fa800;
extern unsigned char DAT_001fa808;
extern unsigned char DAT_001fa810;
extern unsigned char DAT_001fa818;
extern unsigned char DAT_001fa820;
extern unsigned char DAT_001fa828;
extern unsigned char DAT_001fa830;
extern unsigned char DAT_001fa838;
extern unsigned char DAT_001fa840;
extern unsigned char DAT_001fa848;
extern unsigned char DAT_001fa850;
extern unsigned char DAT_001fa858;
extern unsigned char DAT_001fa860;
extern unsigned char DAT_001fa868;
extern unsigned char DAT_001fa870;
extern unsigned char DAT_001fa878;
extern unsigned char DAT_001fa880;
extern unsigned char DAT_001fa888;
extern unsigned char DAT_001fa890;
extern unsigned char DAT_001fa898;
extern unsigned char DAT_001fa8a0;
extern unsigned char DAT_001fa8a8;
extern unsigned char DAT_001fa8b0;
extern unsigned char DAT_001fa8b8;
extern unsigned char DAT_001fa8c0;
extern unsigned char DAT_001fa8c8;
extern unsigned char DAT_001fa8d0;
extern unsigned char DAT_001fa8d8;
extern unsigned char DAT_001fa8e0;
extern unsigned char DAT_001fa8e8;
extern unsigned char DAT_001fa8f0;
extern unsigned char DAT_001fa8f8;
extern unsigned char DAT_001fa900;
extern unsigned char DAT_001fa908;
extern unsigned char DAT_001fa910;
extern unsigned char DAT_001fa918;
extern unsigned char DAT_001fa920;
extern unsigned char DAT_001fa928;
extern unsigned char DAT_001fa930;
extern unsigned char DAT_001fa938;
extern unsigned char DAT_001fa940;
extern unsigned char DAT_001fa948;
extern unsigned char DAT_001fa950;
extern unsigned char DAT_001fa958;
extern unsigned char DAT_001fa960;
extern unsigned char DAT_001fa968;
extern unsigned char DAT_001fa970;
extern unsigned char DAT_001fa978;
extern unsigned char DAT_001fa980;
extern unsigned char DAT_001fa988;
extern unsigned char DAT_001fa990;
extern unsigned char DAT_001fa998;
extern unsigned char DAT_001fa9a0;
extern unsigned char DAT_001fa9a8;
extern unsigned char DAT_001fa9b0;
extern unsigned char DAT_001fa9b8;
extern unsigned char DAT_001fa9c0;
extern unsigned char DAT_001fa9c8;
extern unsigned char DAT_001fa9d0;
extern unsigned char DAT_001fa9d8;
extern unsigned char DAT_001fa9e0;
extern unsigned char DAT_001fa9e8;
extern unsigned char DAT_001fa9f0;
extern unsigned char DAT_001fa9f8;
extern unsigned char DAT_001faa00;
extern unsigned char DAT_001faa08;
extern unsigned char DAT_001faa10;
extern unsigned char DAT_001faa18;
extern unsigned char DAT_001faa20;
extern unsigned char DAT_001faa28;
extern unsigned char DAT_001faa30;
extern unsigned char DAT_001faa38;
extern unsigned char DAT_001faa40;
extern unsigned char DAT_001faa48;
extern unsigned char DAT_001faa50;
extern unsigned char DAT_001faa58;
extern unsigned char DAT_001faa60;
extern unsigned char DAT_001faa68;
extern unsigned char DAT_001faa70;
extern unsigned char DAT_001faa78;
extern unsigned char DAT_001faa80;
extern unsigned char DAT_001faa88;
extern unsigned char DAT_001faa90;
extern unsigned char DAT_001faa98;
extern unsigned char DAT_001faaa0;
extern unsigned char DAT_001faaa8;
extern unsigned char DAT_001faab0;
extern unsigned char DAT_001faab8;
extern unsigned char DAT_001faac0;
extern unsigned char DAT_001faac8;
extern unsigned char DAT_001faad0;
extern unsigned char DAT_001faad8;
extern unsigned char DAT_001faae0;
extern unsigned char DAT_001faae8;
extern unsigned char DAT_001faaf0;
extern unsigned char DAT_001faaf8;
extern unsigned char DAT_001fab00;
extern unsigned char DAT_001fab08;
extern unsigned char DAT_001fab10;
extern unsigned char DAT_001fab18;
extern unsigned char DAT_001fab20;
extern unsigned char DAT_001fab28;
extern unsigned char DAT_001fab30;
extern unsigned char DAT_001fab38;
extern unsigned char DAT_001fab40;
extern unsigned char DAT_001fab48;
extern unsigned char DAT_001fab50;
extern unsigned char DAT_001fab58;
extern unsigned char DAT_001fab60;
extern unsigned char DAT_001fab68;
extern unsigned char DAT_001fab70;
extern unsigned char DAT_001fab78;
extern unsigned char DAT_001fab80;
extern unsigned char DAT_001fab88;
extern unsigned char DAT_001fab90;
extern unsigned char DAT_001fab98;
extern unsigned char DAT_001faba0;
extern unsigned char DAT_001faba8;
extern unsigned char DAT_001fabb0;
extern unsigned char DAT_001fabb8;
extern unsigned char DAT_001fabc0;
extern unsigned char DAT_001fabc8;
extern unsigned char DAT_001fabd0;
extern unsigned char DAT_001fabd8;
extern unsigned char DAT_001fabe0;
extern unsigned char DAT_001fabe8;
extern unsigned char DAT_001fabf0;
extern unsigned char DAT_001fabf8;
extern unsigned char DAT_001fac00;
extern unsigned char DAT_001fac08;
extern unsigned char DAT_001fac10;
extern unsigned char DAT_001fac18;
extern unsigned char DAT_001fac20;
extern unsigned char DAT_001fac28;
extern unsigned char DAT_001fac30;
extern unsigned char DAT_001fac38;
extern unsigned char DAT_001fac40;
extern unsigned char DAT_001fac48;
extern unsigned char DAT_001fac50;
extern unsigned char DAT_001fac58;
extern unsigned char DAT_001fac60;
extern unsigned char DAT_001fac68;
extern unsigned char DAT_001fac70;
extern unsigned char DAT_001fac78;
extern unsigned char DAT_001fac80;
extern unsigned char DAT_001fac88;
extern unsigned char DAT_001fac90;
extern unsigned char DAT_001fac98;
extern unsigned char DAT_001faca0;
extern unsigned char DAT_001faca8;
extern unsigned char DAT_001facb0;
extern unsigned char DAT_001facb8;
extern unsigned char DAT_001facc0;
extern unsigned char DAT_001facc8;
extern unsigned char DAT_001facd0;
extern unsigned char DAT_001facd8;
extern unsigned char DAT_001face0;
extern unsigned char DAT_001face8;
extern unsigned char DAT_001facf0;
extern unsigned char DAT_001facf8;
extern unsigned char DAT_001fad00;
extern unsigned char DAT_001fad08;
extern unsigned char DAT_001fad10;
extern unsigned char DAT_001fad18;
extern unsigned char DAT_001fad20;
extern unsigned char DAT_001fad28;
extern unsigned char DAT_001fad30;
extern unsigned char DAT_001fad38;
extern unsigned char DAT_001fad40;
extern unsigned char DAT_001fad48;
extern unsigned char DAT_001fad50;
extern unsigned char DAT_001fad58;
extern unsigned char DAT_001fad60;
extern unsigned char DAT_001fad68;
extern unsigned char DAT_001fad70;
extern unsigned char DAT_001fad78;
extern unsigned char DAT_001fad80;
extern unsigned char DAT_001fad88;
extern unsigned char DAT_001fad90;
extern unsigned char DAT_001fad98;
extern unsigned char DAT_001fada0;
extern unsigned char DAT_001fada8;
extern unsigned char DAT_001fadb0;
extern unsigned char DAT_001fadb8;
extern unsigned char DAT_001fadc0;
extern unsigned char DAT_001fadc8;
extern unsigned char DAT_001fadd0;
extern unsigned char DAT_001fadd8;
extern unsigned char DAT_001fade0;
extern unsigned char DAT_001fade8;
extern unsigned char DAT_001fadf0;
extern unsigned char DAT_001fadf8;
extern unsigned char DAT_001fae00;
extern unsigned char DAT_001fae08;
extern unsigned char DAT_001fae10;
/* issue #76 (supersedes/widens the earlier issue #75 descriptor-arena fix): the real arena
 * of 20-byte "format descriptor" records is BIGGER than first measured - re-scanning
 * part_036.c's own descriptor-base assignments (`DAT_xxx = PTR_DAT_yyy + 8;`) end to end finds
 * 252 records spanning 0x1fae10 to 0x1fc1d3 (5060 bytes), not the ~4100-byte subset
 * originally covered. Confirmed live: a second, different descriptor (for pixel format index
 * 19, reached via a post-CGLCreateContext call path) showed the exact same truncated-byte
 * symptom (0x13000000 instead of 0x13) at DAT_001fc13c, which sits past the old fix's upper
 * bound. Re-anchored the whole merge on DAT_001fae10 (the arena's true lowest address) and folded
 * every symbol in the wider range - including the old anchor DAT_001fb004 itself, now just
 * another slot - into one backing array via the same offset-preserving macro technique. */
#define DAT_001fae18 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 8))
#define DAT_001fae1c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 12))
#define DAT_001fae20 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 16))
#define DAT_001fae24 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 20))
#define DAT_001fae2c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 28))
#define DAT_001fae30 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 32))
#define DAT_001fae34 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 36))
#define DAT_001fae38 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 40))
#define DAT_001fae40 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 48))
#define DAT_001fae44 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 52))
#define DAT_001fae48 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 56))
#define DAT_001fae4c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 60))
#define DAT_001fae54 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 68))
#define DAT_001fae58 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 72))
#define DAT_001fae5c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 76))
#define DAT_001fae60 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 80))
#define DAT_001fae68 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 88))
#define DAT_001fae6c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 92))
#define DAT_001fae70 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 96))
#define DAT_001fae74 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 100))
#define DAT_001fae7c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 108))
#define DAT_001fae80 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 112))
#define DAT_001fae84 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 116))
#define DAT_001fae88 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 120))
#define DAT_001fae90 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 128))
#define DAT_001fae94 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 132))
#define DAT_001fae98 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 136))
#define DAT_001fae9c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 140))
#define DAT_001faea4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 148))
#define DAT_001faea8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 152))
#define DAT_001faeac (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 156))
#define DAT_001faeb0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 160))
#define DAT_001faeb8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 168))
#define DAT_001faebc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 172))
#define DAT_001faec0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 176))
#define DAT_001faec4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 180))
#define DAT_001faecc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 188))
#define DAT_001faed0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 192))
#define DAT_001faed4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 196))
#define DAT_001faed8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 200))
#define DAT_001faee0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 208))
#define DAT_001faee4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 212))
#define DAT_001faee8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 216))
#define DAT_001faeec (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 220))
#define DAT_001faef4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 228))
#define DAT_001faef8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 232))
#define DAT_001faefc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 236))
#define DAT_001faf00 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 240))
#define DAT_001faf08 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 248))
#define DAT_001faf0c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 252))
#define DAT_001faf10 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 256))
#define DAT_001faf14 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 260))
#define DAT_001faf1c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 268))
#define DAT_001faf20 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 272))
#define DAT_001faf24 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 276))
#define DAT_001faf28 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 280))
#define DAT_001faf30 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 288))
#define DAT_001faf34 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 292))
#define DAT_001faf38 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 296))
#define DAT_001faf3c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 300))
#define DAT_001faf44 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 308))
#define DAT_001faf48 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 312))
#define DAT_001faf4c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 316))
#define DAT_001faf50 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 320))
#define DAT_001faf58 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 328))
#define DAT_001faf5c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 332))
#define DAT_001faf60 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 336))
#define DAT_001faf64 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 340))
#define DAT_001faf6c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 348))
#define DAT_001faf70 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 352))
#define DAT_001faf74 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 356))
#define DAT_001faf78 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 360))
#define DAT_001faf80 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 368))
#define DAT_001faf84 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 372))
#define DAT_001faf88 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 376))
#define DAT_001faf8c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 380))
#define DAT_001faf94 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 388))
#define DAT_001faf98 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 392))
#define DAT_001faf9c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 396))
#define DAT_001fafa0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 400))
#define DAT_001fafa8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 408))
#define DAT_001fafac (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 412))
#define DAT_001fafb0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 416))
#define DAT_001fafb4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 420))
#define DAT_001fafbc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 428))
#define DAT_001fafc0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 432))
#define DAT_001fafc4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 436))
#define DAT_001fafc8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 440))
#define DAT_001fafd0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 448))
#define DAT_001fafd4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 452))
#define DAT_001fafd8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 456))
#define DAT_001fafdc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 460))
#define DAT_001fafe4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 468))
#define DAT_001fafe8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 472))
#define DAT_001fafec (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 476))
#define DAT_001faff0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 480))
#define DAT_001faff8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 488))
#define DAT_001faffc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 492))
#define DAT_001fb000 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 496))
#define DAT_001fb004 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 500))
/* issue #75 (follow-up #2, generalized): part_036.c populates a 4100-byte arena of 205
 * "format descriptor" records (20 bytes each: DAT_001fb004 through DAT_001fc004), writing each
 * record's fields (a base pointer at +0, plus int fields at +8/+0xc/+0x10 - e.g.
 * `DAT_001fb408 = 0x87;`) via Ghidra-derived individual symbol names, one per referenced
 * offset - not as one real C array/struct. Every one of these 820 names was its own
 * INDEPENDENT `.zerofill` symbol, so our own linker had no reason to place them adjacently or
 * in the original relative order (same root cause as the check_cxa_atexit stack-locals bug and the
 * DAT_001fc2b0 array above, just at a much larger scale). Confirmed live: the very first
 * descriptor this driver actually reads (DAT_001fb400+8, format index 135) came back as
 * 0x87000000 instead of 0x87 (a stray high byte from unrelated memory), and after fixing only
 * that one descriptor in isolation, DAT_001fb400's OWN base-pointer field then read back as
 * 0x08000000 garbage too - a DIFFERENT descriptor's oversized/misplaced write bleeding across
 * our own linker's arbitrary layout. Fixing one descriptor at a time was chasing a moving
 * target, so this fixes the whole arena at once: DAT_001fb004 (the arena's first record) stays
 * the one real scalar declaration, with its data.s zerofill enlarged to cover all 4100 bytes,
 * and every other name in the arena becomes a macro reading/writing the correct 4-byte slot
 * inside that single backing allocation. */
#define DAT_001fb00c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 8))
#define DAT_001fb010 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 12))
#define DAT_001fb014 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 16))
#define DAT_001fb018 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 20))
#define DAT_001fb020 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 28))
#define DAT_001fb024 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 32))
#define DAT_001fb028 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 36))
#define DAT_001fb02c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 40))
#define DAT_001fb034 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 48))
#define DAT_001fb038 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 52))
#define DAT_001fb03c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 56))
#define DAT_001fb040 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 60))
#define DAT_001fb048 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 68))
#define DAT_001fb04c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 72))
#define DAT_001fb050 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 76))
#define DAT_001fb054 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 80))
#define DAT_001fb05c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 88))
#define DAT_001fb060 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 92))
#define DAT_001fb064 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 96))
#define DAT_001fb068 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 100))
#define DAT_001fb070 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 108))
#define DAT_001fb074 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 112))
#define DAT_001fb078 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 116))
#define DAT_001fb07c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 120))
#define DAT_001fb084 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 128))
#define DAT_001fb088 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 132))
#define DAT_001fb08c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 136))
#define DAT_001fb090 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 140))
#define DAT_001fb098 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 148))
#define DAT_001fb09c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 152))
#define DAT_001fb0a0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 156))
#define DAT_001fb0a4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 160))
#define DAT_001fb0ac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 168))
#define DAT_001fb0b0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 172))
#define DAT_001fb0b4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 176))
#define DAT_001fb0b8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 180))
#define DAT_001fb0c0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 188))
#define DAT_001fb0c4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 192))
#define DAT_001fb0c8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 196))
#define DAT_001fb0cc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 200))
#define DAT_001fb0d4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 208))
#define DAT_001fb0d8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 212))
#define DAT_001fb0dc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 216))
#define DAT_001fb0e0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 220))
#define DAT_001fb0e8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 228))
#define DAT_001fb0ec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 232))
#define DAT_001fb0f0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 236))
#define DAT_001fb0f4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 240))
#define DAT_001fb0fc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 248))
#define DAT_001fb100 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 252))
#define DAT_001fb104 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 256))
#define DAT_001fb108 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 260))
#define DAT_001fb110 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 268))
#define DAT_001fb114 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 272))
#define DAT_001fb118 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 276))
#define DAT_001fb11c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 280))
#define DAT_001fb124 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 288))
#define DAT_001fb128 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 292))
#define DAT_001fb12c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 296))
#define DAT_001fb130 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 300))
#define DAT_001fb138 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 308))
#define DAT_001fb13c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 312))
#define DAT_001fb140 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 316))
#define DAT_001fb144 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 320))
#define DAT_001fb14c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 328))
#define DAT_001fb150 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 332))
#define DAT_001fb154 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 336))
#define DAT_001fb158 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 340))
#define DAT_001fb160 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 348))
#define DAT_001fb164 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 352))
#define DAT_001fb168 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 356))
#define DAT_001fb16c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 360))
#define DAT_001fb174 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 368))
#define DAT_001fb178 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 372))
#define DAT_001fb17c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 376))
#define DAT_001fb180 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 380))
#define DAT_001fb188 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 388))
#define DAT_001fb18c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 392))
#define DAT_001fb190 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 396))
#define DAT_001fb194 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 400))
#define DAT_001fb19c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 408))
#define DAT_001fb1a0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 412))
#define DAT_001fb1a4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 416))
#define DAT_001fb1a8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 420))
#define DAT_001fb1b0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 428))
#define DAT_001fb1b4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 432))
#define DAT_001fb1b8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 436))
#define DAT_001fb1bc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 440))
#define DAT_001fb1c4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 448))
#define DAT_001fb1c8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 452))
#define DAT_001fb1cc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 456))
#define DAT_001fb1d0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 460))
#define DAT_001fb1d8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 468))
#define DAT_001fb1dc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 472))
#define DAT_001fb1e0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 476))
#define DAT_001fb1e4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 480))
#define DAT_001fb1ec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 488))
#define DAT_001fb1f0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 492))
#define DAT_001fb1f4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 496))
#define DAT_001fb1f8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 500))
#define DAT_001fb200 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 508))
#define DAT_001fb204 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 512))
#define DAT_001fb208 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 516))
#define DAT_001fb20c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 520))
#define DAT_001fb214 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 528))
#define DAT_001fb218 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 532))
#define DAT_001fb21c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 536))
#define DAT_001fb220 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 540))
#define DAT_001fb228 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 548))
#define DAT_001fb22c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 552))
#define DAT_001fb230 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 556))
#define DAT_001fb234 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 560))
#define DAT_001fb23c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 568))
#define DAT_001fb240 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 572))
#define DAT_001fb244 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 576))
#define DAT_001fb248 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 580))
#define DAT_001fb250 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 588))
#define DAT_001fb254 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 592))
#define DAT_001fb258 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 596))
#define DAT_001fb25c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 600))
#define DAT_001fb264 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 608))
#define DAT_001fb268 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 612))
#define DAT_001fb26c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 616))
#define DAT_001fb270 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 620))
#define DAT_001fb278 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 628))
#define DAT_001fb27c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 632))
#define DAT_001fb280 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 636))
#define DAT_001fb284 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 640))
#define DAT_001fb28c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 648))
#define DAT_001fb290 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 652))
#define DAT_001fb294 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 656))
#define DAT_001fb298 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 660))
#define DAT_001fb2a0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 668))
#define DAT_001fb2a4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 672))
#define DAT_001fb2a8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 676))
#define DAT_001fb2ac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 680))
#define DAT_001fb2b4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 688))
#define DAT_001fb2b8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 692))
#define DAT_001fb2bc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 696))
#define DAT_001fb2c0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 700))
#define DAT_001fb2c8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 708))
#define DAT_001fb2cc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 712))
#define DAT_001fb2d0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 716))
#define DAT_001fb2d4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 720))
#define DAT_001fb2dc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 728))
#define DAT_001fb2e0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 732))
#define DAT_001fb2e4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 736))
#define DAT_001fb2e8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 740))
#define DAT_001fb2f0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 748))
#define DAT_001fb2f4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 752))
#define DAT_001fb2f8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 756))
#define DAT_001fb2fc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 760))
#define DAT_001fb304 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 768))
#define DAT_001fb308 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 772))
#define DAT_001fb30c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 776))
#define DAT_001fb310 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 780))
#define DAT_001fb318 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 788))
#define DAT_001fb31c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 792))
#define DAT_001fb320 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 796))
#define DAT_001fb324 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 800))
#define DAT_001fb32c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 808))
#define DAT_001fb330 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 812))
#define DAT_001fb334 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 816))
#define DAT_001fb338 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 820))
#define DAT_001fb340 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 828))
#define DAT_001fb344 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 832))
#define DAT_001fb348 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 836))
#define DAT_001fb34c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 840))
#define DAT_001fb354 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 848))
#define DAT_001fb358 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 852))
#define DAT_001fb35c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 856))
#define DAT_001fb360 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 860))
#define DAT_001fb368 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 868))
#define DAT_001fb36c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 872))
#define DAT_001fb370 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 876))
#define DAT_001fb374 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 880))
#define DAT_001fb37c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 888))
#define DAT_001fb380 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 892))
#define DAT_001fb384 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 896))
#define DAT_001fb388 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 900))
#define DAT_001fb390 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 908))
#define DAT_001fb394 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 912))
#define DAT_001fb398 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 916))
#define DAT_001fb39c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 920))
#define DAT_001fb3a4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 928))
#define DAT_001fb3a8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 932))
#define DAT_001fb3ac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 936))
#define DAT_001fb3b0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 940))
#define DAT_001fb3b8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 948))
#define DAT_001fb3bc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 952))
#define DAT_001fb3c0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 956))
#define DAT_001fb3c4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 960))
#define DAT_001fb3cc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 968))
#define DAT_001fb3d0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 972))
#define DAT_001fb3d4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 976))
#define DAT_001fb3d8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 980))
#define DAT_001fb3e0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 988))
#define DAT_001fb3e4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 992))
#define DAT_001fb3e8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 996))
#define DAT_001fb3ec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1000))
#define DAT_001fb3f4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1008))
#define DAT_001fb3f8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1012))
#define DAT_001fb3fc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1016))
#define DAT_001fb400 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1020))
#define DAT_001fb408 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1028))
#define DAT_001fb40c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1032))
#define DAT_001fb410 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1036))
#define DAT_001fb414 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1040))
#define DAT_001fb41c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1048))
#define DAT_001fb420 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1052))
#define DAT_001fb424 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1056))
#define DAT_001fb428 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1060))
#define DAT_001fb430 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1068))
#define DAT_001fb434 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1072))
#define DAT_001fb438 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1076))
#define DAT_001fb43c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1080))
#define DAT_001fb444 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1088))
#define DAT_001fb448 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1092))
#define DAT_001fb44c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1096))
#define DAT_001fb450 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1100))
#define DAT_001fb458 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1108))
#define DAT_001fb45c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1112))
#define DAT_001fb460 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1116))
#define DAT_001fb464 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1120))
#define DAT_001fb46c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1128))
#define DAT_001fb470 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1132))
#define DAT_001fb474 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1136))
#define DAT_001fb478 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1140))
#define DAT_001fb480 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1148))
#define DAT_001fb484 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1152))
#define DAT_001fb488 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1156))
#define DAT_001fb48c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1160))
#define DAT_001fb494 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1168))
#define DAT_001fb498 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1172))
#define DAT_001fb49c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1176))
#define DAT_001fb4a0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1180))
#define DAT_001fb4a8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1188))
#define DAT_001fb4ac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1192))
#define DAT_001fb4b0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1196))
#define DAT_001fb4b4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1200))
#define DAT_001fb4bc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1208))
#define DAT_001fb4c0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1212))
#define DAT_001fb4c4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1216))
#define DAT_001fb4c8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1220))
#define DAT_001fb4d0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1228))
#define DAT_001fb4d4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1232))
#define DAT_001fb4d8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1236))
#define DAT_001fb4dc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1240))
#define DAT_001fb4e4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1248))
#define DAT_001fb4e8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1252))
#define DAT_001fb4ec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1256))
#define DAT_001fb4f0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1260))
#define DAT_001fb4f8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1268))
#define DAT_001fb4fc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1272))
#define DAT_001fb500 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1276))
#define DAT_001fb504 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1280))
#define DAT_001fb50c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1288))
#define DAT_001fb510 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1292))
#define DAT_001fb514 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1296))
#define DAT_001fb518 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1300))
#define DAT_001fb520 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1308))
#define DAT_001fb524 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1312))
#define DAT_001fb528 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1316))
#define DAT_001fb52c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1320))
#define DAT_001fb534 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1328))
#define DAT_001fb538 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1332))
#define DAT_001fb53c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1336))
#define DAT_001fb540 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1340))
#define DAT_001fb548 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1348))
#define DAT_001fb54c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1352))
#define DAT_001fb550 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1356))
#define DAT_001fb554 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1360))
#define DAT_001fb55c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1368))
#define DAT_001fb560 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1372))
#define DAT_001fb564 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1376))
#define DAT_001fb568 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1380))
#define DAT_001fb570 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1388))
#define DAT_001fb574 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1392))
#define DAT_001fb578 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1396))
#define DAT_001fb57c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1400))
#define DAT_001fb584 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1408))
#define DAT_001fb588 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1412))
#define DAT_001fb58c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1416))
#define DAT_001fb590 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1420))
#define DAT_001fb598 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1428))
#define DAT_001fb59c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1432))
#define DAT_001fb5a0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1436))
#define DAT_001fb5a4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1440))
#define DAT_001fb5ac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1448))
#define DAT_001fb5b0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1452))
#define DAT_001fb5b4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1456))
#define DAT_001fb5b8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1460))
#define DAT_001fb5c0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1468))
#define DAT_001fb5c4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1472))
#define DAT_001fb5c8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1476))
#define DAT_001fb5cc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1480))
#define DAT_001fb5d4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1488))
#define DAT_001fb5d8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1492))
#define DAT_001fb5dc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1496))
#define DAT_001fb5e0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1500))
#define DAT_001fb5e8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1508))
#define DAT_001fb5ec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1512))
#define DAT_001fb5f0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1516))
#define DAT_001fb5f4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1520))
#define DAT_001fb5fc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1528))
#define DAT_001fb600 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1532))
#define DAT_001fb604 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1536))
#define DAT_001fb608 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1540))
#define DAT_001fb610 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1548))
#define DAT_001fb614 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1552))
#define DAT_001fb618 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1556))
#define DAT_001fb61c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1560))
#define DAT_001fb624 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1568))
#define DAT_001fb628 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1572))
#define DAT_001fb62c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1576))
#define DAT_001fb630 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1580))
#define DAT_001fb638 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1588))
#define DAT_001fb63c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1592))
#define DAT_001fb640 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1596))
#define DAT_001fb644 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1600))
#define DAT_001fb64c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1608))
#define DAT_001fb650 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1612))
#define DAT_001fb654 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1616))
#define DAT_001fb658 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1620))
#define DAT_001fb660 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1628))
#define DAT_001fb664 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1632))
#define DAT_001fb668 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1636))
#define DAT_001fb66c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1640))
#define DAT_001fb674 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1648))
#define DAT_001fb678 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1652))
#define DAT_001fb67c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1656))
#define DAT_001fb680 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1660))
#define DAT_001fb688 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1668))
#define DAT_001fb68c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1672))
#define DAT_001fb690 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1676))
#define DAT_001fb694 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1680))
#define DAT_001fb69c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1688))
#define DAT_001fb6a0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1692))
#define DAT_001fb6a4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1696))
#define DAT_001fb6a8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1700))
#define DAT_001fb6b0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1708))
#define DAT_001fb6b4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1712))
#define DAT_001fb6b8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1716))
#define DAT_001fb6bc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1720))
#define DAT_001fb6c4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1728))
#define DAT_001fb6c8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1732))
#define DAT_001fb6cc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1736))
#define DAT_001fb6d0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1740))
#define DAT_001fb6d8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1748))
#define DAT_001fb6dc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1752))
#define DAT_001fb6e0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1756))
#define DAT_001fb6e4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1760))
#define DAT_001fb6ec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1768))
#define DAT_001fb6f0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1772))
#define DAT_001fb6f4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1776))
#define DAT_001fb6f8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1780))
#define DAT_001fb700 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1788))
#define DAT_001fb704 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1792))
#define DAT_001fb708 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1796))
#define DAT_001fb70c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1800))
#define DAT_001fb714 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1808))
#define DAT_001fb718 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1812))
#define DAT_001fb71c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1816))
#define DAT_001fb720 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1820))
#define DAT_001fb728 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1828))
#define DAT_001fb72c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1832))
#define DAT_001fb730 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1836))
#define DAT_001fb734 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1840))
#define DAT_001fb73c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1848))
#define DAT_001fb740 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1852))
#define DAT_001fb744 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1856))
#define DAT_001fb748 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1860))
#define DAT_001fb750 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1868))
#define DAT_001fb754 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1872))
#define DAT_001fb758 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1876))
#define DAT_001fb75c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1880))
#define DAT_001fb764 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1888))
#define DAT_001fb768 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1892))
#define DAT_001fb76c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1896))
#define DAT_001fb770 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1900))
#define DAT_001fb778 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1908))
#define DAT_001fb77c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1912))
#define DAT_001fb780 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1916))
#define DAT_001fb784 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1920))
#define DAT_001fb78c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1928))
#define DAT_001fb790 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1932))
#define DAT_001fb794 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1936))
#define DAT_001fb798 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1940))
#define DAT_001fb7a0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1948))
#define DAT_001fb7a4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1952))
#define DAT_001fb7a8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1956))
#define DAT_001fb7ac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1960))
#define DAT_001fb7b4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1968))
#define DAT_001fb7b8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1972))
#define DAT_001fb7bc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1976))
#define DAT_001fb7c0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1980))
#define DAT_001fb7c8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1988))
#define DAT_001fb7cc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1992))
#define DAT_001fb7d0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 1996))
#define DAT_001fb7d4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2000))
#define DAT_001fb7dc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2008))
#define DAT_001fb7e0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2012))
#define DAT_001fb7e4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2016))
#define DAT_001fb7e8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2020))
#define DAT_001fb7f0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2028))
#define DAT_001fb7f4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2032))
#define DAT_001fb7f8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2036))
#define DAT_001fb7fc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2040))
#define DAT_001fb804 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2048))
#define DAT_001fb808 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2052))
#define DAT_001fb80c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2056))
#define DAT_001fb810 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2060))
#define DAT_001fb818 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2068))
#define DAT_001fb81c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2072))
#define DAT_001fb820 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2076))
#define DAT_001fb824 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2080))
#define DAT_001fb82c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2088))
#define DAT_001fb830 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2092))
#define DAT_001fb834 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2096))
#define DAT_001fb838 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2100))
#define DAT_001fb840 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2108))
#define DAT_001fb844 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2112))
#define DAT_001fb848 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2116))
#define DAT_001fb84c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2120))
#define DAT_001fb854 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2128))
#define DAT_001fb858 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2132))
#define DAT_001fb85c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2136))
#define DAT_001fb860 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2140))
#define DAT_001fb868 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2148))
#define DAT_001fb86c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2152))
#define DAT_001fb870 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2156))
#define DAT_001fb874 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2160))
#define DAT_001fb87c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2168))
#define DAT_001fb880 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2172))
#define DAT_001fb884 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2176))
#define DAT_001fb888 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2180))
#define DAT_001fb890 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2188))
#define DAT_001fb894 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2192))
#define DAT_001fb898 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2196))
#define DAT_001fb89c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2200))
#define DAT_001fb8a4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2208))
#define DAT_001fb8a8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2212))
#define DAT_001fb8ac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2216))
#define DAT_001fb8b0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2220))
#define DAT_001fb8b8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2228))
#define DAT_001fb8bc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2232))
#define DAT_001fb8c0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2236))
#define DAT_001fb8c4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2240))
#define DAT_001fb8cc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2248))
#define DAT_001fb8d0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2252))
#define DAT_001fb8d4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2256))
#define DAT_001fb8d8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2260))
#define DAT_001fb8e0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2268))
#define DAT_001fb8e4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2272))
#define DAT_001fb8e8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2276))
#define DAT_001fb8ec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2280))
#define DAT_001fb8f4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2288))
#define DAT_001fb8f8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2292))
#define DAT_001fb8fc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2296))
#define DAT_001fb900 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2300))
#define DAT_001fb908 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2308))
#define DAT_001fb90c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2312))
#define DAT_001fb910 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2316))
#define DAT_001fb914 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2320))
#define DAT_001fb91c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2328))
#define DAT_001fb920 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2332))
#define DAT_001fb924 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2336))
#define DAT_001fb928 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2340))
#define DAT_001fb930 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2348))
#define DAT_001fb934 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2352))
#define DAT_001fb938 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2356))
#define DAT_001fb93c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2360))
#define DAT_001fb944 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2368))
#define DAT_001fb948 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2372))
#define DAT_001fb94c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2376))
#define DAT_001fb950 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2380))
#define DAT_001fb958 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2388))
#define DAT_001fb95c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2392))
#define DAT_001fb960 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2396))
#define DAT_001fb964 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2400))
#define DAT_001fb96c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2408))
#define DAT_001fb970 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2412))
#define DAT_001fb974 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2416))
#define DAT_001fb978 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2420))
#define DAT_001fb980 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2428))
#define DAT_001fb984 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2432))
#define DAT_001fb988 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2436))
#define DAT_001fb98c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2440))
#define DAT_001fb994 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2448))
#define DAT_001fb998 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2452))
#define DAT_001fb99c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2456))
#define DAT_001fb9a0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2460))
#define DAT_001fb9a8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2468))
#define DAT_001fb9ac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2472))
#define DAT_001fb9b0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2476))
#define DAT_001fb9b4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2480))
#define DAT_001fb9bc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2488))
#define DAT_001fb9c0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2492))
#define DAT_001fb9c4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2496))
#define DAT_001fb9c8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2500))
#define DAT_001fb9d0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2508))
#define DAT_001fb9d4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2512))
#define DAT_001fb9d8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2516))
#define DAT_001fb9dc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2520))
#define DAT_001fb9e4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2528))
#define DAT_001fb9e8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2532))
#define DAT_001fb9ec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2536))
#define DAT_001fb9f0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2540))
#define DAT_001fb9f8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2548))
#define DAT_001fb9fc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2552))
#define DAT_001fba00 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2556))
#define DAT_001fba04 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2560))
#define DAT_001fba0c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2568))
#define DAT_001fba10 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2572))
#define DAT_001fba14 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2576))
#define DAT_001fba18 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2580))
#define DAT_001fba20 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2588))
#define DAT_001fba24 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2592))
#define DAT_001fba28 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2596))
#define DAT_001fba2c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2600))
#define DAT_001fba34 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2608))
#define DAT_001fba38 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2612))
#define DAT_001fba3c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2616))
#define DAT_001fba40 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2620))
#define DAT_001fba48 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2628))
#define DAT_001fba4c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2632))
#define DAT_001fba50 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2636))
#define DAT_001fba54 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2640))
#define DAT_001fba5c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2648))
#define DAT_001fba60 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2652))
#define DAT_001fba64 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2656))
#define DAT_001fba68 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2660))
#define DAT_001fba70 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2668))
#define DAT_001fba74 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2672))
#define DAT_001fba78 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2676))
#define DAT_001fba7c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2680))
#define DAT_001fba84 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2688))
#define DAT_001fba88 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2692))
#define DAT_001fba8c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2696))
#define DAT_001fba90 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2700))
#define DAT_001fba98 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2708))
#define DAT_001fba9c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2712))
#define DAT_001fbaa0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2716))
#define DAT_001fbaa4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2720))
#define DAT_001fbaac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2728))
#define DAT_001fbab0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2732))
#define DAT_001fbab4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2736))
#define DAT_001fbab8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2740))
#define DAT_001fbac0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2748))
#define DAT_001fbac4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2752))
#define DAT_001fbac8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2756))
#define DAT_001fbacc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2760))
#define DAT_001fbad4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2768))
#define DAT_001fbad8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2772))
#define DAT_001fbadc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2776))
#define DAT_001fbae0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2780))
#define DAT_001fbae8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2788))
#define DAT_001fbaec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2792))
#define DAT_001fbaf0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2796))
#define DAT_001fbaf4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2800))
#define DAT_001fbafc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2808))
#define DAT_001fbb00 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2812))
#define DAT_001fbb04 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2816))
#define DAT_001fbb08 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2820))
#define DAT_001fbb10 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2828))
#define DAT_001fbb14 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2832))
#define DAT_001fbb18 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2836))
#define DAT_001fbb1c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2840))
#define DAT_001fbb24 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2848))
#define DAT_001fbb28 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2852))
#define DAT_001fbb2c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2856))
#define DAT_001fbb30 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2860))
#define DAT_001fbb38 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2868))
#define DAT_001fbb3c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2872))
#define DAT_001fbb40 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2876))
#define DAT_001fbb44 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2880))
#define DAT_001fbb4c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2888))
#define DAT_001fbb50 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2892))
#define DAT_001fbb54 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2896))
#define DAT_001fbb58 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2900))
#define DAT_001fbb60 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2908))
#define DAT_001fbb64 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2912))
#define DAT_001fbb68 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2916))
#define DAT_001fbb6c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2920))
#define DAT_001fbb74 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2928))
#define DAT_001fbb78 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2932))
#define DAT_001fbb7c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2936))
#define DAT_001fbb80 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2940))
#define DAT_001fbb88 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2948))
#define DAT_001fbb8c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2952))
#define DAT_001fbb90 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2956))
#define DAT_001fbb94 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2960))
#define DAT_001fbb9c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2968))
#define DAT_001fbba0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2972))
#define DAT_001fbba4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2976))
#define DAT_001fbba8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2980))
#define DAT_001fbbb0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2988))
#define DAT_001fbbb4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2992))
#define DAT_001fbbb8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 2996))
#define DAT_001fbbbc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3000))
#define DAT_001fbbc4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3008))
#define DAT_001fbbc8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3012))
#define DAT_001fbbcc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3016))
#define DAT_001fbbd0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3020))
#define DAT_001fbbd8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3028))
#define DAT_001fbbdc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3032))
#define DAT_001fbbe0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3036))
#define DAT_001fbbe4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3040))
#define DAT_001fbbec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3048))
#define DAT_001fbbf0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3052))
#define DAT_001fbbf4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3056))
#define DAT_001fbbf8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3060))
#define DAT_001fbc00 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3068))
#define DAT_001fbc04 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3072))
#define DAT_001fbc08 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3076))
#define DAT_001fbc0c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3080))
#define DAT_001fbc14 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3088))
#define DAT_001fbc18 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3092))
#define DAT_001fbc1c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3096))
#define DAT_001fbc20 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3100))
#define DAT_001fbc28 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3108))
#define DAT_001fbc2c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3112))
#define DAT_001fbc30 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3116))
#define DAT_001fbc34 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3120))
#define DAT_001fbc3c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3128))
#define DAT_001fbc40 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3132))
#define DAT_001fbc44 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3136))
#define DAT_001fbc48 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3140))
#define DAT_001fbc50 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3148))
#define DAT_001fbc54 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3152))
#define DAT_001fbc58 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3156))
#define DAT_001fbc5c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3160))
#define DAT_001fbc64 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3168))
#define DAT_001fbc68 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3172))
#define DAT_001fbc6c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3176))
#define DAT_001fbc70 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3180))
#define DAT_001fbc78 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3188))
#define DAT_001fbc7c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3192))
#define DAT_001fbc80 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3196))
#define DAT_001fbc84 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3200))
#define DAT_001fbc8c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3208))
#define DAT_001fbc90 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3212))
#define DAT_001fbc94 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3216))
#define DAT_001fbc98 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3220))
#define DAT_001fbca0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3228))
#define DAT_001fbca4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3232))
#define DAT_001fbca8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3236))
#define DAT_001fbcac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3240))
#define DAT_001fbcb4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3248))
#define DAT_001fbcb8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3252))
#define DAT_001fbcbc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3256))
#define DAT_001fbcc0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3260))
#define DAT_001fbcc8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3268))
#define DAT_001fbccc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3272))
#define DAT_001fbcd0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3276))
#define DAT_001fbcd4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3280))
#define DAT_001fbcdc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3288))
#define DAT_001fbce0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3292))
#define DAT_001fbce4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3296))
#define DAT_001fbce8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3300))
#define DAT_001fbcf0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3308))
#define DAT_001fbcf4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3312))
#define DAT_001fbcf8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3316))
#define DAT_001fbcfc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3320))
#define DAT_001fbd04 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3328))
#define DAT_001fbd08 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3332))
#define DAT_001fbd0c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3336))
#define DAT_001fbd10 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3340))
#define DAT_001fbd18 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3348))
#define DAT_001fbd1c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3352))
#define DAT_001fbd20 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3356))
#define DAT_001fbd24 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3360))
#define DAT_001fbd2c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3368))
#define DAT_001fbd30 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3372))
#define DAT_001fbd34 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3376))
#define DAT_001fbd38 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3380))
#define DAT_001fbd40 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3388))
#define DAT_001fbd44 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3392))
#define DAT_001fbd48 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3396))
#define DAT_001fbd4c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3400))
#define DAT_001fbd54 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3408))
#define DAT_001fbd58 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3412))
#define DAT_001fbd5c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3416))
#define DAT_001fbd60 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3420))
#define DAT_001fbd68 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3428))
#define DAT_001fbd6c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3432))
#define DAT_001fbd70 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3436))
#define DAT_001fbd74 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3440))
#define DAT_001fbd7c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3448))
#define DAT_001fbd80 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3452))
#define DAT_001fbd84 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3456))
#define DAT_001fbd88 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3460))
#define DAT_001fbd90 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3468))
#define DAT_001fbd94 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3472))
#define DAT_001fbd98 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3476))
#define DAT_001fbd9c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3480))
#define DAT_001fbda4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3488))
#define DAT_001fbda8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3492))
#define DAT_001fbdac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3496))
#define DAT_001fbdb0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3500))
#define DAT_001fbdb8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3508))
#define DAT_001fbdbc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3512))
#define DAT_001fbdc0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3516))
#define DAT_001fbdc4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3520))
#define DAT_001fbdcc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3528))
#define DAT_001fbdd0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3532))
#define DAT_001fbdd4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3536))
#define DAT_001fbdd8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3540))
#define DAT_001fbde0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3548))
#define DAT_001fbde4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3552))
#define DAT_001fbde8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3556))
#define DAT_001fbdec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3560))
#define DAT_001fbdf4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3568))
#define DAT_001fbdf8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3572))
#define DAT_001fbdfc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3576))
#define DAT_001fbe00 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3580))
#define DAT_001fbe08 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3588))
#define DAT_001fbe0c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3592))
#define DAT_001fbe10 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3596))
#define DAT_001fbe14 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3600))
#define DAT_001fbe1c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3608))
#define DAT_001fbe20 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3612))
#define DAT_001fbe24 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3616))
#define DAT_001fbe28 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3620))
#define DAT_001fbe30 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3628))
#define DAT_001fbe34 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3632))
#define DAT_001fbe38 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3636))
#define DAT_001fbe3c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3640))
#define DAT_001fbe44 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3648))
#define DAT_001fbe48 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3652))
#define DAT_001fbe4c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3656))
#define DAT_001fbe50 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3660))
#define DAT_001fbe58 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3668))
#define DAT_001fbe5c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3672))
#define DAT_001fbe60 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3676))
#define DAT_001fbe64 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3680))
#define DAT_001fbe6c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3688))
#define DAT_001fbe70 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3692))
#define DAT_001fbe74 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3696))
#define DAT_001fbe78 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3700))
#define DAT_001fbe80 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3708))
#define DAT_001fbe84 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3712))
#define DAT_001fbe88 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3716))
#define DAT_001fbe8c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3720))
#define DAT_001fbe94 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3728))
#define DAT_001fbe98 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3732))
#define DAT_001fbe9c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3736))
#define DAT_001fbea0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3740))
#define DAT_001fbea8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3748))
#define DAT_001fbeac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3752))
#define DAT_001fbeb0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3756))
#define DAT_001fbeb4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3760))
#define DAT_001fbebc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3768))
#define DAT_001fbec0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3772))
#define DAT_001fbec4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3776))
#define DAT_001fbec8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3780))
#define DAT_001fbed0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3788))
#define DAT_001fbed4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3792))
#define DAT_001fbed8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3796))
#define DAT_001fbedc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3800))
#define DAT_001fbee4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3808))
#define DAT_001fbee8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3812))
#define DAT_001fbeec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3816))
#define DAT_001fbef0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3820))
#define DAT_001fbef8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3828))
#define DAT_001fbefc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3832))
#define DAT_001fbf00 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3836))
#define DAT_001fbf04 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3840))
#define DAT_001fbf0c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3848))
#define DAT_001fbf10 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3852))
#define DAT_001fbf14 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3856))
#define DAT_001fbf18 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3860))
#define DAT_001fbf20 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3868))
#define DAT_001fbf24 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3872))
#define DAT_001fbf28 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3876))
#define DAT_001fbf2c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3880))
#define DAT_001fbf34 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3888))
#define DAT_001fbf38 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3892))
#define DAT_001fbf3c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3896))
#define DAT_001fbf40 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3900))
#define DAT_001fbf48 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3908))
#define DAT_001fbf4c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3912))
#define DAT_001fbf50 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3916))
#define DAT_001fbf54 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3920))
#define DAT_001fbf5c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3928))
#define DAT_001fbf60 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3932))
#define DAT_001fbf64 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3936))
#define DAT_001fbf68 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3940))
#define DAT_001fbf70 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3948))
#define DAT_001fbf74 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3952))
#define DAT_001fbf78 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3956))
#define DAT_001fbf7c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3960))
#define DAT_001fbf84 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3968))
#define DAT_001fbf88 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3972))
#define DAT_001fbf8c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3976))
#define DAT_001fbf90 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3980))
#define DAT_001fbf98 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3988))
#define DAT_001fbf9c (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3992))
#define DAT_001fbfa0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 3996))
#define DAT_001fbfa4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4000))
#define DAT_001fbfac (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4008))
#define DAT_001fbfb0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4012))
#define DAT_001fbfb4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4016))
#define DAT_001fbfb8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4020))
#define DAT_001fbfc0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4028))
#define DAT_001fbfc4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4032))
#define DAT_001fbfc8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4036))
#define DAT_001fbfcc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4040))
#define DAT_001fbfd4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4048))
#define DAT_001fbfd8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4052))
#define DAT_001fbfdc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4056))
#define DAT_001fbfe0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4060))
#define DAT_001fbfe8 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4068))
#define DAT_001fbfec (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4072))
#define DAT_001fbff0 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4076))
#define DAT_001fbff4 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4080))
#define DAT_001fbffc (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4088))
#define DAT_001fc000 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4092))
#define DAT_001fc004 (*(unsigned char **)((unsigned char *)&DAT_001fb004 + 4096))
#define DAT_001fc008 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4600))
#define DAT_001fc010 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4608))
#define DAT_001fc014 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4612))
#define DAT_001fc018 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4616))
#define DAT_001fc01c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4620))
#define DAT_001fc024 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4628))
#define DAT_001fc028 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4632))
#define DAT_001fc02c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4636))
#define DAT_001fc030 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4640))
#define DAT_001fc038 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4648))
#define DAT_001fc03c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4652))
#define DAT_001fc040 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4656))
#define DAT_001fc044 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4660))
#define DAT_001fc04c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4668))
#define DAT_001fc050 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4672))
#define DAT_001fc054 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4676))
#define DAT_001fc058 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4680))
#define DAT_001fc060 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4688))
#define DAT_001fc064 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4692))
#define DAT_001fc068 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4696))
#define DAT_001fc06c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4700))
#define DAT_001fc074 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4708))
#define DAT_001fc078 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4712))
#define DAT_001fc07c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4716))
#define DAT_001fc080 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4720))
#define DAT_001fc088 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4728))
#define DAT_001fc08c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4732))
#define DAT_001fc090 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4736))
#define DAT_001fc094 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4740))
#define DAT_001fc09c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4748))
#define DAT_001fc0a0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4752))
#define DAT_001fc0a4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4756))
#define DAT_001fc0a8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4760))
#define DAT_001fc0b0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4768))
#define DAT_001fc0b4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4772))
#define DAT_001fc0b8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4776))
#define DAT_001fc0bc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4780))
#define DAT_001fc0c4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4788))
#define DAT_001fc0c8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4792))
#define DAT_001fc0cc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4796))
#define DAT_001fc0d0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4800))
#define DAT_001fc0d8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4808))
#define DAT_001fc0dc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4812))
#define DAT_001fc0e0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4816))
#define DAT_001fc0e4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4820))
#define DAT_001fc0ec (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4828))
#define DAT_001fc0f0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4832))
#define DAT_001fc0f4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4836))
#define DAT_001fc0f8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4840))
#define DAT_001fc100 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4848))
#define DAT_001fc104 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4852))
#define DAT_001fc108 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4856))
#define DAT_001fc10c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4860))
#define DAT_001fc114 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4868))
#define DAT_001fc118 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4872))
#define DAT_001fc11c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4876))
#define DAT_001fc120 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4880))
#define DAT_001fc128 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4888))
#define DAT_001fc12c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4892))
#define DAT_001fc130 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4896))
#define DAT_001fc134 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4900))
#define DAT_001fc13c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4908))
#define DAT_001fc140 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4912))
#define DAT_001fc144 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4916))
#define DAT_001fc148 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4920))
#define DAT_001fc150 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4928))
#define DAT_001fc154 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4932))
#define DAT_001fc158 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4936))
#define DAT_001fc15c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4940))
#define DAT_001fc164 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4948))
#define DAT_001fc168 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4952))
#define DAT_001fc16c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4956))
#define DAT_001fc170 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4960))
#define DAT_001fc178 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4968))
#define DAT_001fc17c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4972))
#define DAT_001fc180 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4976))
#define DAT_001fc184 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4980))
#define DAT_001fc18c (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4988))
#define DAT_001fc190 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4992))
#define DAT_001fc194 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 4996))
#define DAT_001fc198 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5000))
#define DAT_001fc1a0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5008))
#define DAT_001fc1a4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5012))
#define DAT_001fc1a8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5016))
#define DAT_001fc1ac (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5020))
#define DAT_001fc1b4 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5028))
#define DAT_001fc1b8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5032))
#define DAT_001fc1bc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5036))
#define DAT_001fc1c0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5040))
#define DAT_001fc1c8 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5048))
#define DAT_001fc1cc (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5052))
#define DAT_001fc1d0 (*(unsigned char **)((unsigned char *)&DAT_001fae10 + 5056))
extern int (*DAT_001fc1d4)();
extern int (*DAT_001fc1d8)();
extern int (*DAT_001fc1dc)();
extern int (*DAT_001fc1e0)();
extern unsigned char DAT_001fc1f0;
extern unsigned char DAT_001fc1f4;
extern unsigned char DAT_001fc1f8[];
extern unsigned char DAT_001fc1fc[];
extern unsigned char DAT_001fc2b0;
/* issue #75 (follow-up, static-data version of the same bug class): DAT_001fc2b0 and this
 * whole run of individually-named DAT_ globals are, in the REAL stock binary, ONE SINGLE
 * contiguous array - Opcode__getInfo (part_032.c) reads it purely via pointer arithmetic
 * (`*(undefined4*)(&DAT_001fc2b0 + index*4)`), and part_036.c's giant format-table
 * initializer writes into it the exact same way, just via individually Ghidra-named slots
 * (because THAT code happens to reference each slot by absolute address instead of computed
 * index). Declaring every slot as its own INDEPENDENT `.zerofill` symbol - as this whole
 * decls.h did - only worked in the original binary because ITS compiler/linker happened to
 * lay them out contiguously and in order; our rebuild's linker has no reason to preserve that
 * adjacency (same root cause as the check_cxa_atexit local_28/local_24 stack-slot bug fixed
 * earlier in this same investigation, just for static/BSS storage instead of the stack).
 * Confirmed live: DAT_001fc2b0's own `.zerofill` was only 60 bytes (15 entries), so a real
 * call site (`Opcode__getInfo(0x87)` = index 135, part_027.c:1155) read 480 bytes past its
 * allocated storage into unrelated memory (observed as 0xf0000000), even though part_036.c
 * DOES correctly execute `DAT_001fc4cc = &DAT_001fb400;` (the real value for index 135) -
 * it just lands in a completely separate, independent 4-byte allocation that the array-style
 * read never sees. Also: each of these individual slots was itself typed as a scalar
 * `unsigned char` (1 byte) despite always being assigned a real pointer value
 * (`NAME = &DAT_xxx;`), which would truncate every one of those writes down to 1 byte even if
 * the adjacency problem didn't exist.
 *
 * Fixed by enlarging DAT_001fc2b0's own storage (data.s zerofill 60 -> 1200 bytes, 300
 * entries - comfortably past the highest confirmed real index, 249) and redirecting every one
 * of these previously-independent slot names into that same array via macros, so the write
 * side (part_036.c) and the read side (Opcode__getInfo) are provably the same physical storage
 * regardless of what our own linker does. Verified these 253 names have no OTHER use anywhere
 * in the corpus (never read directly, never have their own address taken) - only ever written
 * once each by part_036.c's initializer - so this substitution is safe. */
#define DAT_001fc2ec (*(unsigned char **)(&DAT_001fc2b0 + 15*4))
#define DAT_001fc2f0 (*(unsigned char **)(&DAT_001fc2b0 + 16*4))
#define DAT_001fc2f4 (*(unsigned char **)(&DAT_001fc2b0 + 17*4))
#define DAT_001fc2f8 (*(unsigned char **)(&DAT_001fc2b0 + 18*4))
#define DAT_001fc2fc (*(unsigned char **)(&DAT_001fc2b0 + 19*4))
#define DAT_001fc300 (*(unsigned char **)(&DAT_001fc2b0 + 20*4))
#define DAT_001fc304 (*(unsigned char **)(&DAT_001fc2b0 + 21*4))
#define DAT_001fc308 (*(unsigned char **)(&DAT_001fc2b0 + 22*4))
#define DAT_001fc30c (*(unsigned char **)(&DAT_001fc2b0 + 23*4))
#define DAT_001fc310 (*(unsigned char **)(&DAT_001fc2b0 + 24*4))
#define DAT_001fc314 (*(unsigned char **)(&DAT_001fc2b0 + 25*4))
#define DAT_001fc318 (*(unsigned char **)(&DAT_001fc2b0 + 26*4))
#define DAT_001fc31c (*(unsigned char **)(&DAT_001fc2b0 + 27*4))
#define DAT_001fc320 (*(unsigned char **)(&DAT_001fc2b0 + 28*4))
#define DAT_001fc324 (*(unsigned char **)(&DAT_001fc2b0 + 29*4))
#define DAT_001fc328 (*(unsigned char **)(&DAT_001fc2b0 + 30*4))
#define DAT_001fc32c (*(unsigned char **)(&DAT_001fc2b0 + 31*4))
#define DAT_001fc330 (*(unsigned char **)(&DAT_001fc2b0 + 32*4))
#define DAT_001fc334 (*(unsigned char **)(&DAT_001fc2b0 + 33*4))
#define DAT_001fc338 (*(unsigned char **)(&DAT_001fc2b0 + 34*4))
#define DAT_001fc33c (*(unsigned char **)(&DAT_001fc2b0 + 35*4))
#define DAT_001fc340 (*(unsigned char **)(&DAT_001fc2b0 + 36*4))
#define DAT_001fc344 (*(unsigned char **)(&DAT_001fc2b0 + 37*4))
#define DAT_001fc348 (*(unsigned char **)(&DAT_001fc2b0 + 38*4))
#define DAT_001fc34c (*(unsigned char **)(&DAT_001fc2b0 + 39*4))
#define DAT_001fc350 (*(unsigned char **)(&DAT_001fc2b0 + 40*4))
#define DAT_001fc354 (*(unsigned char **)(&DAT_001fc2b0 + 41*4))
#define DAT_001fc358 (*(unsigned char **)(&DAT_001fc2b0 + 42*4))
#define DAT_001fc35c (*(unsigned char **)(&DAT_001fc2b0 + 43*4))
#define DAT_001fc360 (*(unsigned char **)(&DAT_001fc2b0 + 44*4))
#define DAT_001fc364 (*(unsigned char **)(&DAT_001fc2b0 + 45*4))
#define DAT_001fc368 (*(unsigned char **)(&DAT_001fc2b0 + 46*4))
#define DAT_001fc36c (*(unsigned char **)(&DAT_001fc2b0 + 47*4))
#define DAT_001fc370 (*(unsigned char **)(&DAT_001fc2b0 + 48*4))
#define DAT_001fc374 (*(unsigned char **)(&DAT_001fc2b0 + 49*4))
#define DAT_001fc378 (*(unsigned char **)(&DAT_001fc2b0 + 50*4))
#define DAT_001fc37c (*(unsigned char **)(&DAT_001fc2b0 + 51*4))
#define DAT_001fc380 (*(unsigned char **)(&DAT_001fc2b0 + 52*4))
#define DAT_001fc384 (*(unsigned char **)(&DAT_001fc2b0 + 53*4))
#define DAT_001fc388 (*(unsigned char **)(&DAT_001fc2b0 + 54*4))
#define DAT_001fc38c (*(unsigned char **)(&DAT_001fc2b0 + 55*4))
#define DAT_001fc390 (*(unsigned char **)(&DAT_001fc2b0 + 56*4))
#define DAT_001fc394 (*(unsigned char **)(&DAT_001fc2b0 + 57*4))
#define DAT_001fc398 (*(unsigned char **)(&DAT_001fc2b0 + 58*4))
#define DAT_001fc39c (*(unsigned char **)(&DAT_001fc2b0 + 59*4))
#define DAT_001fc3a0 (*(unsigned char **)(&DAT_001fc2b0 + 60*4))
#define DAT_001fc3a4 (*(unsigned char **)(&DAT_001fc2b0 + 61*4))
#define DAT_001fc3a8 (*(unsigned char **)(&DAT_001fc2b0 + 62*4))
#define DAT_001fc3ac (*(unsigned char **)(&DAT_001fc2b0 + 63*4))
#define DAT_001fc3b0 (*(unsigned char **)(&DAT_001fc2b0 + 64*4))
#define DAT_001fc3b4 (*(unsigned char **)(&DAT_001fc2b0 + 65*4))
#define DAT_001fc3b8 (*(unsigned char **)(&DAT_001fc2b0 + 66*4))
#define DAT_001fc3bc (*(unsigned char **)(&DAT_001fc2b0 + 67*4))
#define DAT_001fc3c0 (*(unsigned char **)(&DAT_001fc2b0 + 68*4))
#define DAT_001fc3c4 (*(unsigned char **)(&DAT_001fc2b0 + 69*4))
#define DAT_001fc3c8 (*(unsigned char **)(&DAT_001fc2b0 + 70*4))
#define DAT_001fc3cc (*(unsigned char **)(&DAT_001fc2b0 + 71*4))
#define DAT_001fc3d0 (*(unsigned char **)(&DAT_001fc2b0 + 72*4))
#define DAT_001fc3d4 (*(unsigned char **)(&DAT_001fc2b0 + 73*4))
#define DAT_001fc3d8 (*(unsigned char **)(&DAT_001fc2b0 + 74*4))
#define DAT_001fc3dc (*(unsigned char **)(&DAT_001fc2b0 + 75*4))
#define DAT_001fc3e0 (*(unsigned char **)(&DAT_001fc2b0 + 76*4))
#define DAT_001fc3e4 (*(unsigned char **)(&DAT_001fc2b0 + 77*4))
#define DAT_001fc3e8 (*(unsigned char **)(&DAT_001fc2b0 + 78*4))
#define DAT_001fc3ec (*(unsigned char **)(&DAT_001fc2b0 + 79*4))
#define DAT_001fc3f0 (*(unsigned char **)(&DAT_001fc2b0 + 80*4))
#define DAT_001fc3f4 (*(unsigned char **)(&DAT_001fc2b0 + 81*4))
#define DAT_001fc3f8 (*(unsigned char **)(&DAT_001fc2b0 + 82*4))
#define DAT_001fc3fc (*(unsigned char **)(&DAT_001fc2b0 + 83*4))
#define DAT_001fc400 (*(unsigned char **)(&DAT_001fc2b0 + 84*4))
#define DAT_001fc404 (*(unsigned char **)(&DAT_001fc2b0 + 85*4))
#define DAT_001fc408 (*(unsigned char **)(&DAT_001fc2b0 + 86*4))
#define DAT_001fc40c (*(unsigned char **)(&DAT_001fc2b0 + 87*4))
#define DAT_001fc410 (*(unsigned char **)(&DAT_001fc2b0 + 88*4))
#define DAT_001fc414 (*(unsigned char **)(&DAT_001fc2b0 + 89*4))
#define DAT_001fc418 (*(unsigned char **)(&DAT_001fc2b0 + 90*4))
#define DAT_001fc41c (*(unsigned char **)(&DAT_001fc2b0 + 91*4))
#define DAT_001fc420 (*(unsigned char **)(&DAT_001fc2b0 + 92*4))
#define DAT_001fc424 (*(unsigned char **)(&DAT_001fc2b0 + 93*4))
#define DAT_001fc428 (*(unsigned char **)(&DAT_001fc2b0 + 94*4))
#define DAT_001fc42c (*(unsigned char **)(&DAT_001fc2b0 + 95*4))
#define DAT_001fc430 (*(unsigned char **)(&DAT_001fc2b0 + 96*4))
#define DAT_001fc434 (*(unsigned char **)(&DAT_001fc2b0 + 97*4))
#define DAT_001fc438 (*(unsigned char **)(&DAT_001fc2b0 + 98*4))
#define DAT_001fc43c (*(unsigned char **)(&DAT_001fc2b0 + 99*4))
#define DAT_001fc440 (*(unsigned char **)(&DAT_001fc2b0 + 100*4))
#define DAT_001fc444 (*(unsigned char **)(&DAT_001fc2b0 + 101*4))
#define DAT_001fc448 (*(unsigned char **)(&DAT_001fc2b0 + 102*4))
#define DAT_001fc44c (*(unsigned char **)(&DAT_001fc2b0 + 103*4))
#define DAT_001fc450 (*(unsigned char **)(&DAT_001fc2b0 + 104*4))
#define DAT_001fc454 (*(unsigned char **)(&DAT_001fc2b0 + 105*4))
#define DAT_001fc458 (*(unsigned char **)(&DAT_001fc2b0 + 106*4))
#define DAT_001fc45c (*(unsigned char **)(&DAT_001fc2b0 + 107*4))
#define DAT_001fc460 (*(unsigned char **)(&DAT_001fc2b0 + 108*4))
#define DAT_001fc464 (*(unsigned char **)(&DAT_001fc2b0 + 109*4))
#define DAT_001fc468 (*(unsigned char **)(&DAT_001fc2b0 + 110*4))
#define DAT_001fc46c (*(unsigned char **)(&DAT_001fc2b0 + 111*4))
#define DAT_001fc470 (*(unsigned char **)(&DAT_001fc2b0 + 112*4))
#define DAT_001fc474 (*(unsigned char **)(&DAT_001fc2b0 + 113*4))
#define DAT_001fc478 (*(unsigned char **)(&DAT_001fc2b0 + 114*4))
#define DAT_001fc47c (*(unsigned char **)(&DAT_001fc2b0 + 115*4))
#define DAT_001fc480 (*(unsigned char **)(&DAT_001fc2b0 + 116*4))
#define DAT_001fc484 (*(unsigned char **)(&DAT_001fc2b0 + 117*4))
#define DAT_001fc488 (*(unsigned char **)(&DAT_001fc2b0 + 118*4))
#define DAT_001fc48c (*(unsigned char **)(&DAT_001fc2b0 + 119*4))
#define DAT_001fc490 (*(unsigned char **)(&DAT_001fc2b0 + 120*4))
#define DAT_001fc494 (*(unsigned char **)(&DAT_001fc2b0 + 121*4))
#define DAT_001fc498 (*(unsigned char **)(&DAT_001fc2b0 + 122*4))
#define DAT_001fc49c (*(unsigned char **)(&DAT_001fc2b0 + 123*4))
#define DAT_001fc4a0 (*(unsigned char **)(&DAT_001fc2b0 + 124*4))
#define DAT_001fc4a4 (*(unsigned char **)(&DAT_001fc2b0 + 125*4))
#define DAT_001fc4a8 (*(unsigned char **)(&DAT_001fc2b0 + 126*4))
#define DAT_001fc4ac (*(unsigned char **)(&DAT_001fc2b0 + 127*4))
#define DAT_001fc4b0 (*(unsigned char **)(&DAT_001fc2b0 + 128*4))
#define DAT_001fc4b4 (*(unsigned char **)(&DAT_001fc2b0 + 129*4))
#define DAT_001fc4b8 (*(unsigned char **)(&DAT_001fc2b0 + 130*4))
#define DAT_001fc4bc (*(unsigned char **)(&DAT_001fc2b0 + 131*4))
#define DAT_001fc4c0 (*(unsigned char **)(&DAT_001fc2b0 + 132*4))
#define DAT_001fc4c4 (*(unsigned char **)(&DAT_001fc2b0 + 133*4))
#define DAT_001fc4c8 (*(unsigned char **)(&DAT_001fc2b0 + 134*4))
#define DAT_001fc4cc (*(unsigned char **)(&DAT_001fc2b0 + 135*4))
#define DAT_001fc4d0 (*(unsigned char **)(&DAT_001fc2b0 + 136*4))
#define DAT_001fc4d4 (*(unsigned char **)(&DAT_001fc2b0 + 137*4))
#define DAT_001fc4d8 (*(unsigned char **)(&DAT_001fc2b0 + 138*4))
#define DAT_001fc4dc (*(unsigned char **)(&DAT_001fc2b0 + 139*4))
#define DAT_001fc4e0 (*(unsigned char **)(&DAT_001fc2b0 + 140*4))
#define DAT_001fc4e4 (*(unsigned char **)(&DAT_001fc2b0 + 141*4))
#define DAT_001fc4e8 (*(unsigned char **)(&DAT_001fc2b0 + 142*4))
#define DAT_001fc4ec (*(unsigned char **)(&DAT_001fc2b0 + 143*4))
#define DAT_001fc4f0 (*(unsigned char **)(&DAT_001fc2b0 + 144*4))
#define DAT_001fc4f4 (*(unsigned char **)(&DAT_001fc2b0 + 145*4))
#define DAT_001fc4f8 (*(unsigned char **)(&DAT_001fc2b0 + 146*4))
#define DAT_001fc4fc (*(unsigned char **)(&DAT_001fc2b0 + 147*4))
#define DAT_001fc500 (*(unsigned char **)(&DAT_001fc2b0 + 148*4))
#define DAT_001fc504 (*(unsigned char **)(&DAT_001fc2b0 + 149*4))
#define DAT_001fc508 (*(unsigned char **)(&DAT_001fc2b0 + 150*4))
#define DAT_001fc50c (*(unsigned char **)(&DAT_001fc2b0 + 151*4))
#define DAT_001fc510 (*(unsigned char **)(&DAT_001fc2b0 + 152*4))
#define DAT_001fc514 (*(unsigned char **)(&DAT_001fc2b0 + 153*4))
#define DAT_001fc518 (*(unsigned char **)(&DAT_001fc2b0 + 154*4))
#define DAT_001fc51c (*(unsigned char **)(&DAT_001fc2b0 + 155*4))
#define DAT_001fc520 (*(unsigned char **)(&DAT_001fc2b0 + 156*4))
#define DAT_001fc524 (*(unsigned char **)(&DAT_001fc2b0 + 157*4))
#define DAT_001fc528 (*(unsigned char **)(&DAT_001fc2b0 + 158*4))
#define DAT_001fc52c (*(unsigned char **)(&DAT_001fc2b0 + 159*4))
#define DAT_001fc530 (*(unsigned char **)(&DAT_001fc2b0 + 160*4))
#define DAT_001fc534 (*(unsigned char **)(&DAT_001fc2b0 + 161*4))
#define DAT_001fc538 (*(unsigned char **)(&DAT_001fc2b0 + 162*4))
#define DAT_001fc53c (*(unsigned char **)(&DAT_001fc2b0 + 163*4))
#define DAT_001fc540 (*(unsigned char **)(&DAT_001fc2b0 + 164*4))
#define DAT_001fc544 (*(unsigned char **)(&DAT_001fc2b0 + 165*4))
#define DAT_001fc548 (*(unsigned char **)(&DAT_001fc2b0 + 166*4))
#define DAT_001fc54c (*(unsigned char **)(&DAT_001fc2b0 + 167*4))
#define DAT_001fc550 (*(unsigned char **)(&DAT_001fc2b0 + 168*4))
#define DAT_001fc554 (*(unsigned char **)(&DAT_001fc2b0 + 169*4))
#define DAT_001fc558 (*(unsigned char **)(&DAT_001fc2b0 + 170*4))
#define DAT_001fc55c (*(unsigned char **)(&DAT_001fc2b0 + 171*4))
#define DAT_001fc560 (*(unsigned char **)(&DAT_001fc2b0 + 172*4))
#define DAT_001fc564 (*(unsigned char **)(&DAT_001fc2b0 + 173*4))
#define DAT_001fc568 (*(unsigned char **)(&DAT_001fc2b0 + 174*4))
#define DAT_001fc56c (*(unsigned char **)(&DAT_001fc2b0 + 175*4))
#define DAT_001fc570 (*(unsigned char **)(&DAT_001fc2b0 + 176*4))
#define DAT_001fc574 (*(unsigned char **)(&DAT_001fc2b0 + 177*4))
#define DAT_001fc578 (*(unsigned char **)(&DAT_001fc2b0 + 178*4))
#define DAT_001fc57c (*(unsigned char **)(&DAT_001fc2b0 + 179*4))
#define DAT_001fc580 (*(unsigned char **)(&DAT_001fc2b0 + 180*4))
#define DAT_001fc584 (*(unsigned char **)(&DAT_001fc2b0 + 181*4))
#define DAT_001fc588 (*(unsigned char **)(&DAT_001fc2b0 + 182*4))
#define DAT_001fc58c (*(unsigned char **)(&DAT_001fc2b0 + 183*4))
#define DAT_001fc590 (*(unsigned char **)(&DAT_001fc2b0 + 184*4))
#define DAT_001fc594 (*(unsigned char **)(&DAT_001fc2b0 + 185*4))
#define DAT_001fc598 (*(unsigned char **)(&DAT_001fc2b0 + 186*4))
#define DAT_001fc59c (*(unsigned char **)(&DAT_001fc2b0 + 187*4))
#define DAT_001fc5a0 (*(unsigned char **)(&DAT_001fc2b0 + 188*4))
#define DAT_001fc5a4 (*(unsigned char **)(&DAT_001fc2b0 + 189*4))
#define DAT_001fc5a8 (*(unsigned char **)(&DAT_001fc2b0 + 190*4))
#define DAT_001fc5ac (*(unsigned char **)(&DAT_001fc2b0 + 191*4))
#define DAT_001fc5b0 (*(unsigned char **)(&DAT_001fc2b0 + 192*4))
#define DAT_001fc5b4 (*(unsigned char **)(&DAT_001fc2b0 + 193*4))
#define DAT_001fc5b8 (*(unsigned char **)(&DAT_001fc2b0 + 194*4))
#define DAT_001fc5bc (*(unsigned char **)(&DAT_001fc2b0 + 195*4))
#define DAT_001fc5c0 (*(unsigned char **)(&DAT_001fc2b0 + 196*4))
#define DAT_001fc5c4 (*(unsigned char **)(&DAT_001fc2b0 + 197*4))
#define DAT_001fc5c8 (*(unsigned char **)(&DAT_001fc2b0 + 198*4))
#define DAT_001fc5cc (*(unsigned char **)(&DAT_001fc2b0 + 199*4))
#define DAT_001fc5d0 (*(unsigned char **)(&DAT_001fc2b0 + 200*4))
#define DAT_001fc5d4 (*(unsigned char **)(&DAT_001fc2b0 + 201*4))
#define DAT_001fc5d8 (*(unsigned char **)(&DAT_001fc2b0 + 202*4))
#define DAT_001fc5dc (*(unsigned char **)(&DAT_001fc2b0 + 203*4))
#define DAT_001fc5e0 (*(unsigned char **)(&DAT_001fc2b0 + 204*4))
#define DAT_001fc5e4 (*(unsigned char **)(&DAT_001fc2b0 + 205*4))
#define DAT_001fc5e8 (*(unsigned char **)(&DAT_001fc2b0 + 206*4))
#define DAT_001fc5ec (*(unsigned char **)(&DAT_001fc2b0 + 207*4))
#define DAT_001fc5f0 (*(unsigned char **)(&DAT_001fc2b0 + 208*4))
#define DAT_001fc5f4 (*(unsigned char **)(&DAT_001fc2b0 + 209*4))
#define DAT_001fc5f8 (*(unsigned char **)(&DAT_001fc2b0 + 210*4))
#define DAT_001fc5fc (*(unsigned char **)(&DAT_001fc2b0 + 211*4))
#define DAT_001fc600 (*(unsigned char **)(&DAT_001fc2b0 + 212*4))
#define DAT_001fc604 (*(unsigned char **)(&DAT_001fc2b0 + 213*4))
#define DAT_001fc608 (*(unsigned char **)(&DAT_001fc2b0 + 214*4))
#define DAT_001fc60c (*(unsigned char **)(&DAT_001fc2b0 + 215*4))
#define DAT_001fc610 (*(unsigned char **)(&DAT_001fc2b0 + 216*4))
#define DAT_001fc614 (*(unsigned char **)(&DAT_001fc2b0 + 217*4))
#define DAT_001fc618 (*(unsigned char **)(&DAT_001fc2b0 + 218*4))
#define DAT_001fc61c (*(unsigned char **)(&DAT_001fc2b0 + 219*4))
#define DAT_001fc620 (*(unsigned char **)(&DAT_001fc2b0 + 220*4))
#define DAT_001fc624 (*(unsigned char **)(&DAT_001fc2b0 + 221*4))
#define DAT_001fc628 (*(unsigned char **)(&DAT_001fc2b0 + 222*4))
#define DAT_001fc62c (*(unsigned char **)(&DAT_001fc2b0 + 223*4))
#define DAT_001fc630 (*(unsigned char **)(&DAT_001fc2b0 + 224*4))
#define DAT_001fc634 (*(unsigned char **)(&DAT_001fc2b0 + 225*4))
#define DAT_001fc638 (*(unsigned char **)(&DAT_001fc2b0 + 226*4))
#define DAT_001fc63c (*(unsigned char **)(&DAT_001fc2b0 + 227*4))
#define DAT_001fc640 (*(unsigned char **)(&DAT_001fc2b0 + 228*4))
#define DAT_001fc644 (*(unsigned char **)(&DAT_001fc2b0 + 229*4))
#define DAT_001fc648 (*(unsigned char **)(&DAT_001fc2b0 + 230*4))
#define DAT_001fc64c (*(unsigned char **)(&DAT_001fc2b0 + 231*4))
#define DAT_001fc650 (*(unsigned char **)(&DAT_001fc2b0 + 232*4))
#define DAT_001fc654 (*(unsigned char **)(&DAT_001fc2b0 + 233*4))
#define DAT_001fc658 (*(unsigned char **)(&DAT_001fc2b0 + 234*4))
#define DAT_001fc65c (*(unsigned char **)(&DAT_001fc2b0 + 235*4))
#define DAT_001fc660 (*(unsigned char **)(&DAT_001fc2b0 + 236*4))
#define DAT_001fc664 (*(unsigned char **)(&DAT_001fc2b0 + 237*4))
#define DAT_001fc668 (*(unsigned char **)(&DAT_001fc2b0 + 238*4))
#define DAT_001fc66c (*(unsigned char **)(&DAT_001fc2b0 + 239*4))
#define DAT_001fc670 (*(unsigned char **)(&DAT_001fc2b0 + 240*4))
#define DAT_001fc674 (*(unsigned char **)(&DAT_001fc2b0 + 241*4))
#define DAT_001fc678 (*(unsigned char **)(&DAT_001fc2b0 + 242*4))
#define DAT_001fc67c (*(unsigned char **)(&DAT_001fc2b0 + 243*4))
#define DAT_001fc680 (*(unsigned char **)(&DAT_001fc2b0 + 244*4))
#define DAT_001fc684 (*(unsigned char **)(&DAT_001fc2b0 + 245*4))
#define DAT_001fc688 (*(unsigned char **)(&DAT_001fc2b0 + 246*4))
#define DAT_001fc68c (*(unsigned char **)(&DAT_001fc2b0 + 247*4))
#define DAT_001fc690 (*(unsigned char **)(&DAT_001fc2b0 + 248*4))
#define DAT_001fc694 (*(unsigned char **)(&DAT_001fc2b0 + 249*4))
#define DAT_001fc698 (*(unsigned char **)(&DAT_001fc2b0 + 250*4))
#define DAT_001fc69c (*(unsigned char **)(&DAT_001fc2b0 + 251*4))
#define DAT_001fc6a0 (*(unsigned char **)(&DAT_001fc2b0 + 252*4))
#define DAT_001fc6a4 (*(unsigned char **)(&DAT_001fc2b0 + 253*4))
#define DAT_001fc6a8 (*(unsigned char **)(&DAT_001fc2b0 + 254*4))
#define DAT_001fc6ac (*(unsigned char **)(&DAT_001fc2b0 + 255*4))
#define DAT_001fc6b0 (*(unsigned char **)(&DAT_001fc2b0 + 256*4))
#define DAT_001fc6b4 (*(unsigned char **)(&DAT_001fc2b0 + 257*4))
#define DAT_001fc6b8 (*(unsigned char **)(&DAT_001fc2b0 + 258*4))
#define DAT_001fc6bc (*(unsigned char **)(&DAT_001fc2b0 + 259*4))
#define DAT_001fc6c0 (*(unsigned char **)(&DAT_001fc2b0 + 260*4))
#define DAT_001fc6c4 (*(unsigned char **)(&DAT_001fc2b0 + 261*4))
#define DAT_001fc6c8 (*(unsigned char **)(&DAT_001fc2b0 + 262*4))
#define DAT_001fc6cc (*(unsigned char **)(&DAT_001fc2b0 + 263*4))
#define DAT_001fc6d0 (*(unsigned char **)(&DAT_001fc2b0 + 264*4))
#define DAT_001fc6d4 (*(unsigned char **)(&DAT_001fc2b0 + 265*4))
#define DAT_001fc6d8 (*(unsigned char **)(&DAT_001fc2b0 + 266*4))
#define DAT_001fc6dc (*(unsigned char **)(&DAT_001fc2b0 + 267*4))
extern unsigned char *PTR_001e88a4;
extern unsigned char *PTR_001e88a8;
/* issue #75: this whole cluster (b0-c0) was declared as plain bytes (missing the pointer
 * asterisk every OTHER "PTR_"-named global near it correctly has, e.g. PTR_DAT_001e88ac) -
 * but data.s defines EACH of them as a real 4-byte pointer to a well-known system global
 * (__cpu_capabilities, _mach_task_self_, _kCFCopyStringDictionaryKeyCallBacks,
 * _kCFTypeDictionaryValueCallBacks, _kCFAllocatorDefault respectively). gld_testRendererAvailable
 * (part_005.c) casts PTR_001e88b4's VALUE directly to a pointer and dereferences it
 * (`*(undefined4*)PTR_001e88b4`); with the wrong, truncated 1-byte type, that read only the
 * pointer's low byte (observed live as 0xa0) and crashed dereferencing THAT as an address -
 * confirmed live on real hardware to recur immediately afterward, identically, for
 * PTR_001e88b0 too, in gldCreateContext. Fixed the whole cluster together rather than
 * one at a time.
 *
 * Follow-up (still issue #75): PTR_001e8a3c/8a58/8aa4/8b14 below turned out to be the SAME
 * bug hitting a *different* object - FUN_000a7050 (part_015.c) wires up a 4-slot allocator
 * vtable {generic-alloc, calloc, realloc, free} at param_1+0x24c.."+0x258, and the calloc
 * slot (+0x250, read back later as param_1+0x10 inside FUN_000b6020, part_016.c) was
 * PTR_001e8b14 - declared as a plain byte here, so the compiled read only got PTR_001e8b14's
 * top byte (observed live as the literal integer 1) instead of the real 4-byte pointer to
 * _calloc that data.s actually stores there (`.long _calloc`), crashing with pc=0 the moment
 * FUN_000b6020 called it as `(*pcVar8)(1, size)`. Confirmed the neighbors in this same data.s
 * region (_free/_realloc/_memcpy, same 4-slot-vtable pattern) share the identical bug.
 *
 * Given three confirmed live crashes from this exact class in one session, ran the deferred
 * "dedicated audit" of all 616 "extern unsigned char PTR_*" declarations rather than fixing
 * these in isolation: for every one lacking the asterisk, mechanically checked data.s's real
 * definition. 548 of 611 are backed by a single 4-byte ".long" slot - genuinely scalar pointer
 * variables exactly like this cluster - and got the missing "*" added below in this same pass
 * (verified per-symbol against data.s, not guessed). The remaining 63 are multi-entry arrays
 * (real vtables with 2-4 ".long" entries, e.g. PTR_FUN_001e97a0) where a plain scalar
 * declaration doesn't have this failure mode as long as call sites take &NAME rather than a
 * bare value - left alone, flagged here as still worth checking if a future crash points at
 * one of them specifically. */
extern unsigned char *PTR_001e88b0;
extern unsigned char *PTR_001e88b4;
extern unsigned char *PTR_001e88b8;
extern unsigned char *PTR_001e88bc;
extern unsigned char *PTR_001e88c0;
extern unsigned char *PTR_001e8a3c;
extern unsigned char *PTR_001e8a58;
extern unsigned char *PTR_001e8aa4;
extern unsigned char *PTR_001e8b14;
extern unsigned char *PTR_DAT_001dbdd4[];
extern unsigned char *PTR_DAT_001dbe3c[];
extern unsigned char *PTR_DAT_001dbe84[];
extern unsigned char PTR_DAT_001dc75c;
extern unsigned char *PTR_DAT_001dc76c[];
extern unsigned char *PTR_DAT_001dc77c[];
extern unsigned char *PTR_DAT_001dc78c[];
extern unsigned char PTR_DAT_001e1c34;
extern unsigned char PTR_DAT_001e260c;
extern unsigned char PTR_DAT_001e2630;
extern unsigned char PTR_DAT_001e269c;
extern unsigned char PTR_DAT_001e27bc;
extern unsigned char *PTR_DAT_001e88ac;
extern unsigned char *PTR_DAT_001e88c8;
extern unsigned char *PTR_DAT_001e88cc;
extern unsigned char *PTR_DAT_001e88d0;
extern unsigned char *PTR_DAT_001e8994;
extern unsigned char *PTR_DAT_001e8998;
extern unsigned char *PTR_DAT_001e899c;
extern unsigned char *PTR_DAT_001e8ae4;
extern unsigned char *PTR_DAT_001e8b48;
extern unsigned char *PTR_DAT_001e8b4c;
extern unsigned char *PTR_DAT_001e8b50;
extern unsigned char *PTR_DAT_001e8b54;
extern unsigned char *PTR_DAT_001e8b58;
extern unsigned char *PTR_DAT_001e8b5c;
extern unsigned char *PTR_DAT_001e8b60;
extern unsigned char *PTR_DAT_001e8b64;
extern unsigned char *PTR_DAT_001e8b68;
extern unsigned char *PTR_DAT_001e8b6c;
extern unsigned char *PTR_DAT_001e8b70;
extern unsigned char *PTR_DAT_001e8b74;
extern unsigned char *PTR_DAT_001e8b78;
extern unsigned char *PTR_DAT_001e8b7c;
extern unsigned char *PTR_DAT_001e8b80;
extern unsigned char *PTR_DAT_001e8b84;
extern unsigned char *PTR_DAT_001e8b88;
extern unsigned char *PTR_DAT_001e8b8c;
extern unsigned char *PTR_DAT_001e8b90;
extern unsigned char *PTR_DAT_001e8b94;
extern unsigned char *PTR_DAT_001e8b98;
extern unsigned char *PTR_DAT_001e8b9c;
extern unsigned char *PTR_DAT_001e8ba0;
extern unsigned char *PTR_DAT_001e8ba4;
extern unsigned char *PTR_DAT_001e8ba8;
extern unsigned char *PTR_DAT_001e8bac;
extern unsigned char *PTR_DAT_001e8bb0;
extern unsigned char *PTR_DAT_001e8bb4;
extern unsigned char *PTR_DAT_001e8bb8;
extern unsigned char *PTR_DAT_001e8bbc;
extern unsigned char *PTR_DAT_001e8bc0;
extern unsigned char *PTR_DAT_001e8bc4;
extern unsigned char *PTR_DAT_001e8bc8;
extern unsigned char *PTR_DAT_001e8bcc;
extern unsigned char *PTR_DAT_001e8bd0;
extern unsigned char *PTR_DAT_001e8bd4;
extern unsigned char *PTR_DAT_001e8bd8;
extern unsigned char *PTR_DAT_001e8bdc;
extern unsigned char *PTR_DAT_001e8be0;
extern unsigned char *PTR_DAT_001e8be4;
extern unsigned char *PTR_DAT_001e8be8;
extern unsigned char *PTR_DAT_001e8bec;
extern unsigned char *PTR_DAT_001e8bf0;
extern unsigned char *PTR_DAT_001e8bf4;
extern unsigned char *PTR_DAT_001e8bf8;
extern unsigned char *PTR_DAT_001e8bfc;
extern unsigned char *PTR_DAT_001e8c00;
extern unsigned char *PTR_DAT_001e8c04;
extern unsigned char *PTR_DAT_001e8c08;
extern unsigned char *PTR_DAT_001e8c0c;
extern unsigned char *PTR_DAT_001e8c10;
extern unsigned char *PTR_DAT_001e8c14;
extern unsigned char *PTR_DAT_001e8c18;
extern unsigned char *PTR_DAT_001e8c1c;
extern unsigned char *PTR_DAT_001e8c20;
extern unsigned char *PTR_DAT_001e8c24;
extern unsigned char *PTR_DAT_001e8c28;
extern unsigned char *PTR_DAT_001e8c2c;
extern unsigned char *PTR_DAT_001e8c30;
extern unsigned char *PTR_DAT_001e8c34;
extern unsigned char *PTR_DAT_001e8c38;
extern unsigned char *PTR_DAT_001e8c3c;
extern unsigned char *PTR_DAT_001e8c40;
extern unsigned char *PTR_DAT_001e8c44;
extern unsigned char *PTR_DAT_001e8c48;
extern unsigned char *PTR_DAT_001e8c4c;
extern unsigned char *PTR_DAT_001e8c50;
extern unsigned char *PTR_DAT_001e8c54;
extern unsigned char *PTR_DAT_001e8c58;
extern unsigned char *PTR_DAT_001e8c5c;
extern unsigned char *PTR_DAT_001e8c64;
extern unsigned char *PTR_DAT_001e8c68;
extern unsigned char *PTR_DAT_001e8c6c;
extern unsigned char *PTR_DAT_001e8c70;
extern unsigned char *PTR_DAT_001e8c74;
extern unsigned char *PTR_DAT_001e8c78;
extern unsigned char *PTR_DAT_001e8c80;
extern unsigned char *PTR_DAT_001e8c84;
extern unsigned char *PTR_DAT_001e8c88;
extern unsigned char *PTR_DAT_001e8c8c;
extern unsigned char *PTR_DAT_001e8c90;
extern unsigned char *PTR_DAT_001e8c94;
extern unsigned char *PTR_DAT_001e8c98;
extern unsigned char *PTR_DAT_001e8c9c;
extern unsigned char *PTR_DAT_001e8ca0;
extern unsigned char *PTR_DAT_001e8ca4;
extern unsigned char *PTR_DAT_001e8ca8;
extern unsigned char *PTR_DAT_001e8cac;
extern unsigned char *PTR_DAT_001e8cb0;
extern unsigned char *PTR_DAT_001e8cb4;
extern unsigned char *PTR_DAT_001e8cb8;
extern unsigned char *PTR_DAT_001e8cbc;
extern unsigned char *PTR_DAT_001e8cc0;
extern unsigned char *PTR_DAT_001e8cc4;
extern unsigned char *PTR_DAT_001e8cc8;
extern unsigned char *PTR_DAT_001e8ccc;
extern unsigned char *PTR_DAT_001e8cd0;
extern unsigned char *PTR_DAT_001e8cd4;
extern unsigned char *PTR_DAT_001e8cd8;
extern unsigned char *PTR_DAT_001e8cdc;
extern unsigned char *PTR_DAT_001e8ce0;
extern unsigned char *PTR_DAT_001e8ce4;
extern unsigned char *PTR_DAT_001e8ce8;
extern unsigned char *PTR_DAT_001e8cec;
extern unsigned char *PTR_DAT_001e8cf0;
extern unsigned char *PTR_DAT_001e8cf4;
extern unsigned char *PTR_DAT_001e8cf8;
extern unsigned char *PTR_DAT_001e8cfc;
extern unsigned char *PTR_DAT_001e8d00;
extern unsigned char *PTR_DAT_001e8d04;
extern unsigned char *PTR_DAT_001e8d08;
extern unsigned char *PTR_DAT_001e8d0c;
extern unsigned char *PTR_DAT_001e8d10;
extern unsigned char *PTR_DAT_001e8d14;
extern unsigned char *PTR_DAT_001e8d18;
extern unsigned char *PTR_DAT_001e8d1c;
extern unsigned char *PTR_DAT_001e8d20;
extern unsigned char *PTR_DAT_001e8d24;
extern unsigned char *PTR_DAT_001e8d28;
extern unsigned char *PTR_DAT_001e8d2c;
extern unsigned char *PTR_DAT_001e8d30;
extern unsigned char *PTR_DAT_001e8d34;
extern unsigned char *PTR_DAT_001e8d38;
extern unsigned char *PTR_DAT_001e8d3c;
extern unsigned char *PTR_DAT_001e8d40;
extern unsigned char *PTR_DAT_001e8d44;
extern unsigned char *PTR_DAT_001e8d48;
extern unsigned char *PTR_DAT_001e8d4c;
extern unsigned char *PTR_DAT_001e8d50;
extern unsigned char *PTR_DAT_001e8d54;
extern unsigned char *PTR_DAT_001e8d58;
extern unsigned char *PTR_DAT_001e8d5c;
extern unsigned char *PTR_DAT_001e8d60;
extern unsigned char *PTR_DAT_001e8d64;
extern unsigned char *PTR_DAT_001e8d68;
extern unsigned char *PTR_DAT_001e8d6c;
extern unsigned char *PTR_DAT_001e8d70;
extern unsigned char *PTR_DAT_001e8d74;
extern unsigned char *PTR_DAT_001e8d78;
extern unsigned char *PTR_DAT_001e8d7c;
extern unsigned char *PTR_DAT_001e8d80;
extern unsigned char *PTR_DAT_001e8d84;
extern unsigned char *PTR_DAT_001e8d88;
extern unsigned char *PTR_DAT_001e8d8c;
extern unsigned char *PTR_DAT_001e8d90;
extern unsigned char *PTR_DAT_001e8d94;
extern unsigned char *PTR_DAT_001e8d98;
extern unsigned char *PTR_DAT_001e8d9c;
extern unsigned char *PTR_DAT_001e8da0;
extern unsigned char *PTR_DAT_001e8da4;
extern unsigned char *PTR_DAT_001e8da8;
extern unsigned char *PTR_DAT_001e8dac;
extern unsigned char *PTR_DAT_001e8db0;
extern unsigned char *PTR_DAT_001e8db4;
extern unsigned char *PTR_DAT_001e8db8;
extern unsigned char *PTR_DAT_001e8dbc;
extern unsigned char *PTR_DAT_001e8dc0;
extern unsigned char *PTR_DAT_001e8dc4;
extern unsigned char *PTR_DAT_001e8dc8;
extern unsigned char *PTR_DAT_001e8dcc;
extern unsigned char *PTR_DAT_001e8dd0;
extern unsigned char *PTR_DAT_001e8dd4;
extern unsigned char *PTR_DAT_001e8dd8;
extern unsigned char *PTR_DAT_001e8ddc;
extern unsigned char *PTR_DAT_001e8de0;
extern unsigned char *PTR_DAT_001e8de4;
extern unsigned char *PTR_DAT_001e8de8;
extern unsigned char *PTR_DAT_001e8dec;
extern unsigned char *PTR_DAT_001e8df0;
extern unsigned char *PTR_DAT_001e8df4;
extern unsigned char *PTR_DAT_001e8df8;
extern unsigned char *PTR_DAT_001e8dfc;
extern unsigned char *PTR_DAT_001e8e00;
extern unsigned char *PTR_DAT_001e8e04;
extern unsigned char *PTR_DAT_001e8e08;
extern unsigned char *PTR_DAT_001e8e0c;
extern unsigned char *PTR_DAT_001e8e10;
extern unsigned char *PTR_DAT_001e8e14;
extern unsigned char *PTR_DAT_001e8e18;
extern unsigned char *PTR_DAT_001e8e1c;
extern unsigned char *PTR_DAT_001e8e20;
extern unsigned char *PTR_DAT_001e8e24;
extern unsigned char *PTR_DAT_001e8e28;
extern unsigned char *PTR_DAT_001e8e2c;
extern unsigned char *PTR_DAT_001e8e30;
extern unsigned char *PTR_DAT_001e8e34;
extern unsigned char *PTR_DAT_001e8e38;
extern unsigned char *PTR_DAT_001e8e3c;
extern unsigned char *PTR_DAT_001e8e40;
extern unsigned char *PTR_DAT_001e8e44;
extern unsigned char *PTR_DAT_001e8e48;
extern unsigned char *PTR_DAT_001e8e4c;
extern unsigned char *PTR_DAT_001e8e50;
extern unsigned char *PTR_DAT_001e8e54;
extern unsigned char *PTR_DAT_001e8e58;
extern unsigned char *PTR_DAT_001e8e5c;
extern unsigned char *PTR_DAT_001e8e60;
extern unsigned char *PTR_DAT_001e8e64;
extern unsigned char *PTR_DAT_001e8e68;
extern unsigned char *PTR_DAT_001e8e6c;
extern unsigned char *PTR_DAT_001e8e70;
extern unsigned char *PTR_DAT_001e8e74;
extern unsigned char *PTR_DAT_001e8e78;
extern unsigned char *PTR_DAT_001e8e7c;
extern unsigned char *PTR_DAT_001e8e80;
extern unsigned char *PTR_DAT_001e8e84;
extern unsigned char *PTR_DAT_001e8e88;
extern unsigned char *PTR_DAT_001e8e8c;
extern unsigned char *PTR_DAT_001e8e90;
extern unsigned char *PTR_DAT_001e8e94;
extern unsigned char *PTR_DAT_001e8e98;
extern unsigned char *PTR_DAT_001e8e9c;
extern unsigned char *PTR_DAT_001e8ea0;
extern unsigned char *PTR_DAT_001e8ea4;
extern unsigned char *PTR_DAT_001e8ea8;
extern unsigned char *PTR_DAT_001e8eac;
extern unsigned char *PTR_DAT_001e8eb0;
extern unsigned char *PTR_DAT_001e8eb4;
extern unsigned char *PTR_DAT_001e8eb8;
extern unsigned char *PTR_DAT_001e8ebc;
extern unsigned char *PTR_DAT_001e8ec0;
extern unsigned char *PTR_DAT_001e8ec4;
extern unsigned char *PTR_DAT_001e8ec8;
extern unsigned char *PTR_DAT_001e8ecc;
extern unsigned char *PTR_DAT_001e8ed0;
extern unsigned char *PTR_DAT_001e8ed4;
extern unsigned char *PTR_DAT_001e8ed8;
extern unsigned char *PTR_DAT_001e8edc;
extern unsigned char *PTR_DAT_001e8ee0;
extern unsigned char *PTR_DAT_001e8ee4;
extern unsigned char *PTR_DAT_001e8ee8;
extern unsigned char *PTR_DAT_001e8eec;
extern unsigned char *PTR_DAT_001e8ef0;
extern unsigned char *PTR_DAT_001e8ef4;
extern unsigned char *PTR_DAT_001e8ef8;
extern unsigned char *PTR_DAT_001e8efc;
extern unsigned char *PTR_DAT_001e8f00;
extern unsigned char *PTR_DAT_001e8f04;
extern unsigned char *PTR_DAT_001e8f08;
extern unsigned char *PTR_DAT_001e8f0c;
extern unsigned char *PTR_DAT_001e8f10;
extern unsigned char *PTR_DAT_001e8f14;
extern unsigned char *PTR_DAT_001e8f18;
extern unsigned char *PTR_DAT_001e8f1c;
extern unsigned char *PTR_DAT_001e8f20;
extern unsigned char *PTR_DAT_001e8f24;
extern unsigned char *PTR_DAT_001e8f28;
extern unsigned char *PTR_DAT_001e8f2c;
extern unsigned char *PTR_DAT_001e8f30;
extern unsigned char *PTR_DAT_001e8f34;
extern unsigned char *PTR_DAT_001e8f38;
extern unsigned char *PTR_DAT_001e8f3c;
extern unsigned char *PTR_DAT_001e8f40;
extern unsigned char *PTR_DAT_001e8f44;
extern unsigned char *PTR_DAT_001e8f48;
extern unsigned char *PTR_DAT_001e8f4c;
extern unsigned char *PTR_DAT_001e8f50;
extern unsigned char *PTR_DAT_001e8f54;
extern unsigned char *PTR_DAT_001e8f58;
extern unsigned char *PTR_DAT_001e8f5c;
extern unsigned char *PTR_DAT_001e8f60;
extern unsigned char *PTR_DAT_001e8f64;
extern unsigned char *PTR_DAT_001e8f68;
extern unsigned char *PTR_DAT_001e8f6c;
extern unsigned char *PTR_DAT_001e8f70;
extern unsigned char *PTR_DAT_001e8f74;
extern unsigned char *PTR_DAT_001e8f78;
extern unsigned char *PTR_DAT_001e8f7c;
extern unsigned char *PTR_DAT_001e8f80;
extern unsigned char *PTR_DAT_001e8f84;
extern unsigned char *PTR_DAT_001e8f88;
extern unsigned char *PTR_DAT_001e8f8c;
extern unsigned char *PTR_DAT_001e8f90;
extern unsigned char *PTR_DAT_001e8f94;
extern unsigned char *PTR_DAT_001e8f98;
extern unsigned char *PTR_DAT_001e8f9c;
extern unsigned char *PTR_DAT_001e8fa0;
extern unsigned char *PTR_DAT_001e8fa4;
extern unsigned char *PTR_DAT_001e8fa8;
extern unsigned char *PTR_DAT_001e8fac;
extern unsigned char *PTR_DAT_001e8fb0;
extern unsigned char *PTR_DAT_001e8fb4;
extern unsigned char *PTR_DAT_001e8fb8;
extern unsigned char *PTR_DAT_001e8fbc;
extern unsigned char *PTR_DAT_001e8fc0;
extern unsigned char *PTR_DAT_001e8fc4;
extern unsigned char *PTR_DAT_001e8fc8;
extern unsigned char *PTR_DAT_001e8fcc;
extern unsigned char *PTR_DAT_001e8fd0;
extern unsigned char *PTR_DAT_001e8fd4;
extern unsigned char *PTR_DAT_001e8fd8;
extern unsigned char *PTR_DAT_001e8fdc;
extern unsigned char *PTR_DAT_001e8fe0;
extern unsigned char *PTR_DAT_001e8fe4;
extern unsigned char *PTR_DAT_001e8fe8;
extern unsigned char *PTR_DAT_001e8fec;
extern unsigned char *PTR_DAT_001e8ff0;
extern unsigned char *PTR_DAT_001e8ff4;
extern unsigned char *PTR_DAT_001e8ff8;
extern unsigned char *PTR_DAT_001e8ffc;
extern unsigned char *PTR_DAT_001e9000;
extern unsigned char *PTR_DAT_001e9004;
extern unsigned char *PTR_DAT_001e9008;
extern unsigned char *PTR_DAT_001e900c;
extern unsigned char *PTR_DAT_001e9010;
extern unsigned char *PTR_DAT_001e9014;
extern unsigned char *PTR_DAT_001e9018;
extern unsigned char *PTR_DAT_001e901c;
extern unsigned char *PTR_DAT_001e9020;
extern unsigned char *PTR_DAT_001e9024;
extern unsigned char *PTR_DAT_001e9028;
extern unsigned char *PTR_DAT_001e902c;
extern unsigned char *PTR_DAT_001e9030;
extern unsigned char *PTR_DAT_001e9034;
extern unsigned char *PTR_DAT_001e9038;
extern unsigned char *PTR_DAT_001e903c;
extern unsigned char *PTR_DAT_001e9040;
extern unsigned char *PTR_DAT_001e9044;
extern unsigned char *PTR_DAT_001e9048;
extern unsigned char *PTR_DAT_001e904c;
extern unsigned char *PTR_DAT_001e9050;
extern unsigned char *PTR_DAT_001e9054;
extern unsigned char *PTR_DAT_001e9058;
extern unsigned char *PTR_DAT_001e905c;
extern unsigned char *PTR_DAT_001e9060;
extern unsigned char *PTR_DAT_001e9064;
extern unsigned char *PTR_DAT_001e9068;
extern unsigned char *PTR_DAT_001e906c;
extern unsigned char *PTR_DAT_001e9070;
extern unsigned char *PTR_DAT_001e9074;
extern unsigned char *PTR_DAT_001e9078;
extern unsigned char *PTR_DAT_001e907c;
extern unsigned char *PTR_DAT_001e9080;
extern unsigned char *PTR_DAT_001e9084;
extern unsigned char *PTR_DAT_001e9088;
extern unsigned char *PTR_DAT_001e908c;
extern unsigned char *PTR_DAT_001e90c8;
extern unsigned char *PTR_DAT_001e90cc;
extern unsigned char *PTR_DAT_001e90d0;
extern unsigned char *PTR_DAT_001e90d4;
extern unsigned char *PTR_DAT_001e90d8;
extern unsigned char *PTR_DAT_001e90dc;
extern unsigned char *PTR_DAT_001e90e0;
extern unsigned char *PTR_DAT_001e90e4;
extern unsigned char *PTR_DAT_001e90e8;
extern unsigned char *PTR_DAT_001e90ec;
extern unsigned char *PTR_DAT_001e90f0;
extern unsigned char *PTR_DAT_001e90f4;
extern unsigned char *PTR_DAT_001e90f8;
extern unsigned char *PTR_DAT_001e90fc;
extern unsigned char *PTR_DAT_001e9100;
extern unsigned char *PTR_DAT_001e9104;
extern unsigned char *PTR_DAT_001e9108;
extern unsigned char *PTR_DAT_001e9110;
extern unsigned char *PTR_DAT_001e9114;
extern unsigned char *PTR_DAT_001e9118;
extern unsigned char *PTR_DAT_001e911c;
extern unsigned char *PTR_DAT_001e9120;
extern unsigned char *PTR_DAT_001e9124;
extern unsigned char *PTR_DAT_001e9128;
extern unsigned char *PTR_DAT_001e912c;
extern unsigned char *PTR_DAT_001e9130;
extern unsigned char *PTR_DAT_001e9134;
extern unsigned char *PTR_DAT_001e9138;
extern unsigned char *PTR_DAT_001e913c;
extern unsigned char *PTR_DAT_001e9140;
extern unsigned char *PTR_DAT_001e9144;
extern unsigned char *PTR_DAT_001e9148;
extern unsigned char *PTR_DAT_001e914c;
extern unsigned char *PTR_DAT_001e9770;
extern unsigned char *PTR_DAT_001e9774;
extern unsigned char PTR_DAT_001e9778;
extern unsigned char *PTR_DAT_001e9f78[];
extern unsigned char *PTR_DAT_001e9f7c[];
extern unsigned char *PTR_DAT_001e9f80[];
extern unsigned char PTR_DAT_001eb328;
extern unsigned char PTR_DAT_001f4850;
extern unsigned char *PTR_FUN_001db2dc[];
extern unsigned char *PTR_FUN_001db2ec[];
extern unsigned char *PTR_FUN_001db9b8[];
extern int (*PTR_FUN_001dba14)();
extern unsigned char PTR_FUN_001dbb0c;
extern int (*PTR_FUN_001e8754)();
/* issue #74 side-fix: pre-existing gap, unrelated to the free-related fixes in this same
 * session - these two PTR_ symbols are real, defined data (confirmed present in data.s) but
 * were never declared here, so x_unowned_code_part_000.c/007.c (the only two files that
 * reference them) have always failed to compile with "undeclared identifier", silently
 * dropping several exported _gld* symbols from the link and only surfacing as a hard link
 * failure once every other export happened to need one of them. Declared using the same
 * conventions as their neighbors: PTR_FUN_001e876c is dereferenced as a function pointer
 * (`(*(code*)PTR_FUN_001e876c)(...)`); PTR_orph_1d8910_001eb328 is used via `&`, i.e. a plain
 * byte variable, matching PTR_FUN_001dbb0c's own declaration style just above. */
extern int (*PTR_FUN_001e876c)();
extern unsigned char PTR_orph_1d8910_001eb328;
extern unsigned char *PTR_FUN_001e88c4;
extern unsigned char *PTR_FUN_001e88d4;
extern unsigned char *PTR_FUN_001e88d8;
extern unsigned char *PTR_FUN_001e88dc;
extern unsigned char *PTR_FUN_001e88e0;
extern unsigned char *PTR_FUN_001e88e4;
extern unsigned char *PTR_FUN_001e88e8;
extern unsigned char *PTR_FUN_001e88ec;
extern unsigned char *PTR_FUN_001e88f0;
extern unsigned char *PTR_FUN_001e88f4;
extern unsigned char *PTR_FUN_001e88f8;
extern unsigned char *PTR_FUN_001e88fc;
extern unsigned char *PTR_FUN_001e8900;
extern unsigned char *PTR_FUN_001e8908;
extern unsigned char *PTR_FUN_001e890c;
extern unsigned char *PTR_FUN_001e8910;
extern unsigned char *PTR_FUN_001e8914;
extern unsigned char *PTR_FUN_001e8918;
extern unsigned char *PTR_FUN_001e891c;
extern unsigned char *PTR_FUN_001e8920;
extern unsigned char *PTR_FUN_001e8924;
extern unsigned char *PTR_FUN_001e8928;
extern unsigned char *PTR_FUN_001e892c;
extern unsigned char *PTR_FUN_001e8930;
extern unsigned char *PTR_FUN_001e8934;
extern unsigned char *PTR_FUN_001e8938;
extern unsigned char *PTR_FUN_001e893c;
extern unsigned char *PTR_FUN_001e8940;
extern unsigned char *PTR_FUN_001e8944;
extern unsigned char *PTR_FUN_001e8948;
extern unsigned char *PTR_FUN_001e894c;
extern unsigned char *PTR_FUN_001e8950;
extern unsigned char *PTR_FUN_001e8954;
extern unsigned char *PTR_FUN_001e8958;
extern unsigned char *PTR_FUN_001e895c;
extern unsigned char *PTR_FUN_001e8960;
extern unsigned char *PTR_FUN_001e8964;
extern unsigned char *PTR_FUN_001e8968;
extern unsigned char *PTR_FUN_001e896c;
extern unsigned char *PTR_FUN_001e8970;
extern unsigned char *PTR_FUN_001e8974;
extern unsigned char *PTR_FUN_001e8980;
extern unsigned char *PTR_FUN_001e8984;
extern unsigned char *PTR_FUN_001e8988;
extern unsigned char *PTR_FUN_001e898c;
extern unsigned char *PTR_FUN_001e8990;
extern unsigned char *PTR_FUN_001e89a0;
extern unsigned char *PTR_FUN_001e89a4;
extern unsigned char *PTR_FUN_001e89a8;
extern unsigned char *PTR_FUN_001e89ac;
extern unsigned char *PTR_FUN_001e89b0;
extern unsigned char *PTR_FUN_001e89b4;
extern unsigned char *PTR_FUN_001e89b8;
extern unsigned char *PTR_FUN_001e89bc;
extern unsigned char *PTR_FUN_001e89c0;
extern unsigned char *PTR_FUN_001e89c4;
extern unsigned char *PTR_FUN_001e89c8;
extern unsigned char *PTR_FUN_001e89d0;
extern unsigned char *PTR_FUN_001e89d8;
extern unsigned char *PTR_FUN_001e89dc;
extern unsigned char *PTR_FUN_001e89e0;
extern unsigned char *PTR_FUN_001e89e4;
extern unsigned char *PTR_FUN_001e89e8;
extern unsigned char *PTR_FUN_001e89ec;
extern unsigned char *PTR_FUN_001e89f0;
extern unsigned char *PTR_FUN_001e89f4;
extern unsigned char *PTR_FUN_001e89f8;
extern unsigned char *PTR_FUN_001e89fc;
extern unsigned char *PTR_FUN_001e8a00;
extern unsigned char *PTR_FUN_001e8a04;
extern unsigned char *PTR_FUN_001e8a08;
extern unsigned char *PTR_FUN_001e8a0c;
extern unsigned char *PTR_FUN_001e8a10;
extern unsigned char *PTR_FUN_001e8a14;
extern unsigned char *PTR_FUN_001e8a18;
extern unsigned char *PTR_FUN_001e8a1c;
extern unsigned char *PTR_FUN_001e8a20;
extern unsigned char *PTR_FUN_001e8a24;
extern unsigned char *PTR_FUN_001e8a28;
extern unsigned char *PTR_FUN_001e8a2c;
extern unsigned char *PTR_FUN_001e8a30;
extern unsigned char *PTR_FUN_001e8a34;
extern unsigned char *PTR_FUN_001e8a38;
extern unsigned char *PTR_FUN_001e8a40;
extern unsigned char *PTR_FUN_001e8a44;
extern unsigned char *PTR_FUN_001e8a48;
extern unsigned char *PTR_FUN_001e8a4c;
extern unsigned char *PTR_FUN_001e8a50;
extern unsigned char *PTR_FUN_001e8a54;
extern unsigned char *PTR_FUN_001e8a5c;
extern unsigned char *PTR_FUN_001e8a60;
extern unsigned char *PTR_FUN_001e8a64;
extern unsigned char *PTR_FUN_001e8a68;
extern unsigned char *PTR_FUN_001e8a6c;
extern unsigned char *PTR_FUN_001e8a70;
extern unsigned char *PTR_FUN_001e8a74;
extern unsigned char *PTR_FUN_001e8a78;
extern unsigned char *PTR_FUN_001e8a7c;
extern unsigned char *PTR_FUN_001e8a80;
extern unsigned char *PTR_FUN_001e8a84;
extern unsigned char *PTR_FUN_001e8a88;
extern unsigned char *PTR_FUN_001e8a8c;
extern unsigned char *PTR_FUN_001e8a90;
extern unsigned char *PTR_FUN_001e8a94;
extern unsigned char *PTR_FUN_001e8a98;
extern unsigned char *PTR_FUN_001e8a9c;
extern unsigned char *PTR_FUN_001e8aa0;
extern unsigned char *PTR_FUN_001e8aa8;
extern unsigned char *PTR_FUN_001e8aac;
extern unsigned char *PTR_FUN_001e8ab0;
extern unsigned char *PTR_FUN_001e8ab4;
extern unsigned char *PTR_FUN_001e8ab8;
extern unsigned char *PTR_FUN_001e8abc;
extern unsigned char *PTR_FUN_001e8ac0;
extern unsigned char *PTR_FUN_001e8ac4;
extern unsigned char *PTR_FUN_001e8ac8;
extern unsigned char *PTR_FUN_001e8acc;
extern unsigned char *PTR_FUN_001e8ad0;
extern unsigned char *PTR_FUN_001e8ad4;
extern unsigned char *PTR_FUN_001e8ad8;
extern unsigned char *PTR_FUN_001e8adc;
extern unsigned char *PTR_FUN_001e8ae0;
extern unsigned char *PTR_FUN_001e8ae8;
extern unsigned char *PTR_FUN_001e8aec;
extern unsigned char *PTR_FUN_001e8af0;
extern unsigned char *PTR_FUN_001e8af4;
extern unsigned char *PTR_FUN_001e8af8;
extern unsigned char *PTR_FUN_001e8afc;
extern unsigned char *PTR_FUN_001e8b00;
extern unsigned char *PTR_FUN_001e8b04;
extern unsigned char *PTR_FUN_001e8b08;
extern unsigned char *PTR_FUN_001e8b0c;
extern unsigned char *PTR_FUN_001e8b10;
extern unsigned char *PTR_FUN_001e8b18;
extern unsigned char *PTR_FUN_001e8b1c;
extern unsigned char *PTR_FUN_001e8b20;
extern unsigned char *PTR_FUN_001e8b24;
extern unsigned char *PTR_FUN_001e8b28;
extern unsigned char *PTR_FUN_001e8b2c;
extern unsigned char *PTR_FUN_001e8b30;
extern unsigned char *PTR_FUN_001e8b34;
extern unsigned char *PTR_FUN_001e8b38;
extern unsigned char *PTR_FUN_001e8b3c;
extern unsigned char *PTR_FUN_001e8b40;
extern unsigned char *PTR_FUN_001e8c7c;
extern unsigned char *PTR_FUN_001e9090;
extern unsigned char *PTR_FUN_001e9094;
extern unsigned char *PTR_FUN_001e9098;
extern unsigned char *PTR_FUN_001e909c;
extern unsigned char *PTR_FUN_001e90a0;
extern unsigned char *PTR_FUN_001e90a4;
extern unsigned char *PTR_FUN_001e90a8;
extern unsigned char *PTR_FUN_001e90ac;
extern unsigned char *PTR_FUN_001e90b0;
extern unsigned char *PTR_FUN_001e90b4;
extern unsigned char *PTR_FUN_001e90b8;
extern unsigned char *PTR_FUN_001e90bc;
extern unsigned char *PTR_FUN_001e90c0;
extern unsigned char *PTR_FUN_001e90c4;
extern unsigned char *PTR_FUN_001e9150[];
extern unsigned char PTR_FUN_001e97a0;
extern unsigned char PTR_FUN_001e9848;
extern unsigned char PTR_FUN_001e98f0;
extern unsigned char PTR_FUN_001e9998;
extern unsigned char PTR_FUN_001e9a40;
extern unsigned char PTR_FUN_001e9b08;
extern unsigned char PTR_FUN_001e9b60;
extern unsigned char PTR_FUN_001e9bb8;
extern unsigned char PTR_FUN_001e9c10;
extern unsigned char PTR_FUN_001e9c68;
extern unsigned char PTR_FUN_001e9cc0;
extern unsigned char PTR_FUN_001e9d18;
extern unsigned char PTR_FUN_001e9d70;
extern unsigned char PTR_FUN_001e9dc8;
extern unsigned char PTR_FUN_001e9e20;
extern unsigned char PTR_FUN_001e9e78;
extern unsigned char PTR_FUN_001e9ed0;
extern unsigned char PTR_FUN_001e9f28;
extern unsigned char PTR_FUN_001e9fc8;
extern unsigned char PTR_FUN_001ea070;
extern unsigned char PTR_FUN_001ea118;
extern unsigned char PTR_FUN_001ea1c0;
extern unsigned char PTR_FUN_001ea268;
extern unsigned char PTR_FUN_001ea310;
extern unsigned char PTR_FUN_001ea3b8;
extern unsigned char PTR_FUN_001ea460;
extern unsigned char PTR_FUN_001ea5b0;
extern unsigned char PTR_FUN_001ea748;
extern unsigned char PTR_FUN_001ea780;
extern unsigned char PTR_FUN_001ea7b8;
extern unsigned char PTR_FUN_001ea7f0;
extern unsigned char PTR_FUN_001ea828;
extern unsigned char PTR_FUN_001ea860;
extern unsigned char PTR_FUN_001ea898;
extern unsigned char PTR_FUN_001ea8d0;
extern unsigned char PTR_FUN_001ead68;
extern unsigned char PTR_FUN_001ead88;
extern unsigned char PTR_FUN_001eaf20;
extern unsigned char PTR_FUN_001eb0c0;
extern unsigned char PTR_FUN_001eb260;
extern unsigned char PTR_FUN_001eb2f0;
extern unsigned char PTR_FUN_001eb3c0;
extern unsigned char PTR_FUN_001eb450;
extern unsigned char PTR_FUN_001eb5e8;
extern unsigned char PTR_FUN_001eb608;
extern unsigned char PTR_FUN_001eb6a0;
extern unsigned char PTR_FUN_001eb808;
extern unsigned char PTR_FUN_001eb8d8;
extern unsigned char PTR_FUN_001eb9a8;
extern unsigned char *PTR_LAB_001e8904;
extern unsigned char *PTR_LAB_001e89cc;
extern unsigned char *PTR_LAB_001e89d4;
extern unsigned char *PTR_PTR_001e8c60;
extern unsigned char *PTR_PTR_001e910c;
extern unsigned char *PTR__gldFinish_001e8978;
extern unsigned char *PTR__gldFlush_001e897c;
extern unsigned char PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0;
extern unsigned char PTR_s_0xaa_0_JUMP_NONE_NONE_NONE_001dc2d8;
extern unsigned char *PTR_s_1D_001e9158[];
extern unsigned char *PTR_s_IF_b_001dc2cc[];
extern unsigned char PTR_s_OPT_IGNORE_DEFINED_CONSTANTS_001dc444;
extern unsigned char *PTR_s__position_001dc3f4[];
extern unsigned char UNK_001aa574;
extern unsigned char UNK_001aa9bc;
extern unsigned char UNK_001aa9c0;
extern unsigned char UNK_001aa9c4;
extern unsigned char UNK_001aa9d4;
extern unsigned char UNK_001aaa2c;
extern unsigned char UNK_001ada48;
extern unsigned char UNK_001af9d4;
extern unsigned char UNK_001afee0;
extern unsigned char UNK_001aff54;
extern unsigned char UNK_001affdc;
extern unsigned char UNK_001affe0;
extern unsigned char UNK_001affe4;
extern unsigned char UNK_001affe8;
extern unsigned char UNK_001affec;
extern unsigned char UNK_001afff0;
extern unsigned char UNK_001afff4;
extern unsigned char UNK_001afff8;
extern unsigned char UNK_001b0018;
extern unsigned char UNK_001b019c;
extern unsigned char UNK_001b0208;
extern unsigned char UNK_001b020c;
extern unsigned char UNK_001b29e4;
extern unsigned char UNK_001dc660;
extern unsigned char UNK_001dc66c;
extern unsigned char UNK_001e915c;
extern unsigned char UNK_001e9160;
extern unsigned char _UNK_001aa7f4;
extern unsigned char _UNK_001aa7f8;
extern unsigned char _UNK_001aa848;
extern unsigned char _UNK_001aa84c;
extern unsigned char _UNK_001af9d8;
extern unsigned char _UNK_001b2a7c;
/* issue #76: Ghidra "s_" string-literal symbols (the bytes AT this address ARE the string data
 * itself, not a pointer stored elsewhere) were declared as `unsigned char *` (a pointer
 * variable) throughout this file, instead of an array. Call sites that take `&NAME` explicitly
 * happen to still work (numerically identical address either way), but plain array-index or
 * pass-by-name syntax (`NAME[n]`, `foo(NAME)`) - with a pointer type - dereferences this
 * symbol's own storage as if it held a pointer value first. Confirmed live: s__LDBL128_001aa0b4
 * (part_054.c, building a "$LDBL128" symbol-name suffix for an NSLookupAndBindSymbol call)
 * crashed exactly that way (`lwz r2,0(r2); addi r2,r2,8; lbz r0,0(r2)` - an extra leading
 * dereference reading garbage, then indexing through it). Fixed the whole class at once now
 * that a real crash proved the pattern, rather than one at a time. */
extern unsigned char s_0_001a450c[];
extern unsigned char s_12_001a445c[];
extern unsigned char s_16_001a4458[];
extern unsigned char s_1D_001a4524[];
extern unsigned char s_1_001a442c[];
extern unsigned char s_2D_001a4528[];
extern unsigned char s_32_001a4454[];
extern unsigned char s_3D_001a452c[];
extern unsigned char s_ADDRESS_adr0_001a4700[];
extern unsigned char s_APPLE_no_altivec_001a4664[];
extern unsigned char s_APPLE_no_runtime_compile_001a4648[];
extern unsigned char s_ARB_draw_buffers_001a46e8[];
extern unsigned char s_ARB_fog_exp2_001a45f0[];
extern unsigned char s_ARB_fog_exp_001a45e4[];
extern unsigned char s_ARB_fog_linear_001a4600[];
extern unsigned char s_ARB_fragment_program_shadow_001a46a4[];
extern unsigned char s_ARB_position_invariant_001a45cc[];
extern unsigned char s_ARB_precision_hint_fastest_001a4610[];
extern unsigned char s_ARB_precision_hint_nicest_001a462c[];
extern unsigned char s_ATTRIB_att_001a4738[];
extern unsigned char s_B_001a4450[];
extern unsigned char s_CUBE_001a4530[];
extern unsigned char s_C_001a4428[];
extern unsigned char s_Du_001a64b4;
extern unsigned char s_END_001a4bb0[];
extern unsigned char s_EQ_001a4b64[];
extern unsigned char s_FL_001a4b7c[];
extern unsigned char s_F_001a4448[];
extern unsigned char s_GE_001a4b68[];
extern unsigned char s_GT_001a4b6c[];
extern unsigned char s_H_001a443c[];
extern unsigned char s_IL_backcolor_001a62f0[];
extern unsigned char s_IL_color_001a62e4[];
extern unsigned char s_IL_fog_001a6300[];
extern unsigned char s_IL_generic_001a6308[];
extern unsigned char s_IL_pointsize_001a62d4[];
extern unsigned char s_IL_pos_001a62cc[];
extern unsigned char s_IL_unknown_001a6314[];
extern unsigned char s_I_001a444c[];
extern unsigned char s_LE_001a4b70[];
extern unsigned char s_LONG_OUTPUT_res_001a4a3c[];
extern unsigned char s_LONG_TEMP_001a4720[];
extern unsigned char s_LT_001a4b74[];
extern unsigned char s_MUL_V_001df634;
extern unsigned char s_NE_001a4b78[];
extern unsigned char s_NV_fragment_program2_001a468c[];
extern unsigned char s_NV_fragment_program_001a4678[];
extern unsigned char s_NV_vertex_program2_001a46c0[];
extern unsigned char s_NV_vertex_program3_001a46d4[];
extern unsigned char s_OPTION_001a45c4[];
extern unsigned char s_OUTPUT_res_001a4a30[];
extern unsigned char s_PARAM_prm_001a4828[];
extern unsigned char s_RECT_001a4538[];
extern unsigned char s_R_001a4438[];
extern unsigned char s_SHADOW1D_001a4558[];
extern unsigned char s_SHADOW2D_001a454c[];
extern unsigned char s_SHADOWRECT_001a4540[];
extern unsigned char s_SHORT_OUTPUT_res_001a4a4c[];
extern unsigned char s_SHORT_TEMP_001a472c[];
extern unsigned char s_TEMP_001a4718[];
extern unsigned char s_TR_001a4b60[];
extern unsigned char s_Unkown_Target__error__001a45a8[];
extern unsigned char s_X_001a4440[];
extern unsigned char s__001a4134[];
extern unsigned char s__001a45c0[];
extern unsigned char s__001a4844[];
extern unsigned char s__001a4b4c[];
extern unsigned char s__001a4b5c[];
extern unsigned char s__1_001a4510[];
extern unsigned char s__EQ_001a44a8[];
extern unsigned char s__FL_001a44d8[];
extern unsigned char s__GE_001a44b0[];
extern unsigned char s__GT_001a44b8[];
extern unsigned char s__LDBL128_001aa0b4[];
extern unsigned char s__LE_001a44c0[];
extern unsigned char s__LT_001a44c8[];
extern unsigned char s__NE_001a44d0[];
extern unsigned char s__SAT_001a4430[];
extern unsigned char s__TR_001a44a0[];
extern unsigned char s___001a4444[];
extern unsigned char s___001a4464[];
extern unsigned char s___001a4468[];
extern unsigned char s___001a4488[];
extern unsigned char s___001a448c[];
extern unsigned char s___001a44e0[];
extern unsigned char s___001a44e4[];
extern unsigned char s___001a44f4[];
extern unsigned char s___001a44f8[];
extern unsigned char s___001a46fc[];
extern unsigned char s___001a4834[];
extern unsigned char s___001a49dc[];
extern unsigned char s___001a49e0[];
extern unsigned char s___001a4a2c[];
extern unsigned char s___001a4b58[];
extern unsigned char s___ARBfp1_0_001a4584[];
extern unsigned char s___ARBfragmentshader_001a4590[];
extern unsigned char s___ARBvertexshader_001a4570[];
extern unsigned char s___ARBvp1_0_001a4564[];
extern unsigned char s___ILfs1_0_001a5d2c[];
extern unsigned char s____001a4520[];
extern unsigned char s____001a4878[];
extern unsigned char s____001a4a24[];
extern unsigned char s_____001a4838[];
extern unsigned char s_____Fixed_constant_data_not_curr_001a49e4[];
extern unsigned char s______001a6f98[];
extern unsigned char s___adr_001a4710[];
extern unsigned char s___color_001a4918[];
extern unsigned char s___eye__001a48ec[];
extern unsigned char s___fragment__001a4750[];
extern unsigned char s___object__001a4904[];
extern unsigned char s___plane_001a4928[];
extern unsigned char s___vertex__001a4744[];
extern unsigned char s__adr_001a4470[];
extern unsigned char s__back_primary_001a4ab4[];
extern unsigned char s__back_secondary_001a4ad8[];
extern unsigned char s__front_primary_001a4aa4[];
extern unsigned char s__front_secondary_001a4ac4[];
extern unsigned char s__line_001a82e8;
extern unsigned char s__line_adj_001a82fc;
extern unsigned char s__line_strip_001a82c4;
extern unsigned char s__p_001a74dc[];
extern unsigned char s__point_001a82e0[];
extern unsigned char s__point_list_001a82b8;
extern unsigned char s__triangle_001a82f0;
extern unsigned char s__triangle_adj_001a8308;
extern unsigned char s__triangle_strip_001a82d0;
extern unsigned char s__w_001a4484[];
extern unsigned char s__w_001a4508[];
extern unsigned char s__x_001a4478[];
extern unsigned char s__x_001a44fc[];
extern unsigned char s__y_001a447c[];
extern unsigned char s__y_001a4500[];
extern unsigned char s__z_001a4480[];
extern unsigned char s__z_001a4504[];
extern unsigned char s_abs__001a6f88[];
extern unsigned char s_adr_001a44f0[];
extern unsigned char s_alpha_001a77e8[];
extern unsigned char s_alu_wait_001a7364[];
extern unsigned char s_ambient_001a47f4[];
extern unsigned char s_att_001a44e8[];
extern unsigned char s_attenuation_001a488c[];
extern unsigned char s_attrib__001a47d0[];
extern unsigned char s_back__001a47ec[];
extern unsigned char s_clip__001a4920[];
extern unsigned char s_color__001a4990[];
extern unsigned char s_color_primary_001a476c[];
extern unsigned char s_color_secondary_001a477c[];
extern unsigned char s_depth_range_001a4948[];
extern unsigned char s_diffuse_001a47fc[];
extern unsigned char s_emission_001a4810[];
extern unsigned char s_env__001a4868[];
extern unsigned char s_eq_001a77d8[];
extern unsigned char s_fog_color_001a4930[];
extern unsigned char s_fog_params_001a493c[];
extern unsigned char s_fogcoord_001a4794[];
extern unsigned char s_front__001a47e4[];
extern unsigned char s_frontfacing_001a47a0[];
extern unsigned char s_ge_001a77e0[];
extern unsigned char s_gs_001a8394[];
extern unsigned char s_half_001a4898[];
extern unsigned char s_ign_unc_001a734c[];
extern unsigned char s_inverse__001a49bc[];
extern unsigned char s_invtrans__001a49c8[];
extern unsigned char s_label__001a4b50[];
extern unsigned char s_label__001a4ba4[];
extern unsigned char s_light__001a4870[];
extern unsigned char s_lightmodel__001a48cc[];
extern unsigned char s_lightmodel_ambient_001a48b8[];
extern unsigned char s_lightprod__001a48ac[];
extern unsigned char s_local__001a4860[];
extern unsigned char s_lt_001a77dc[];
extern unsigned char s_main__001a4b44[];
extern unsigned char s_material__001a47d8[];
extern unsigned char s_matrix__001a4974[];
extern unsigned char s_matrixindex__001a47c0[];
extern unsigned char s_modelview__001a4998[];
extern unsigned char s_mvp__001a4988[];
extern unsigned char s_nab__001a6f90[];
extern unsigned char s_ne_001a77e4[];
extern unsigned char s_neg__001a6f80[];
extern unsigned char s_normal_001a478c[];
extern unsigned char s_normalscale_001a4a18[];
extern unsigned char s_ox_001a64a8[];
extern unsigned char s_point_attenuation_001a4960[];
extern unsigned char s_point_size_001a4954[];
extern unsigned char s_position_001a4760[];
extern unsigned char s_prm_001a44ec[];
extern unsigned char s_program__001a484c[];
extern unsigned char s_program__001a49a4[];
extern unsigned char s_projection__001a497c[];
extern unsigned char s_ps_001a8390[];
extern unsigned char s_q_001a4900[];
extern unsigned char s_r_001a48fc[];
extern unsigned char s_res_001a446c[];
extern unsigned char s_result_attrib__001a4b0c[];
extern unsigned char s_result_clipVertex_001a4b30[];
extern unsigned char s_result_color_001a4a94[];
extern unsigned char s_result_depth_001a4afc[];
extern unsigned char s_result_eyePosition_001a4b1c[];
extern unsigned char s_result_fogcoord_001a4a70[];
extern unsigned char s_result_pointsize_001a4a80[];
extern unsigned char s_result_position_001a4a60[];
extern unsigned char s_result_texcoord__001a4ae8[];
extern unsigned char s_row__001a49d4[];
extern unsigned char s_s_001a48f4[];
extern unsigned char s_scenecolor_001a48d8[];
extern unsigned char s_sem_grab_001a73ac[];
extern unsigned char s_sem_wait_001a7358[];
extern unsigned char s_shininess_001a481c[];
extern unsigned char s_specular_001a4804[];
extern unsigned char s_spot_direction_001a487c[];
extern unsigned char s_spotcutoff_001a48a0[];
extern unsigned char s_srcp_001a6fa0[];
extern unsigned char s_state__001a4858[];
extern unsigned char s_t_001a48f8[];
extern unsigned char s_texcoord__001a47ac[];
extern unsigned char s_texenv__001a4910[];
extern unsigned char s_texgen__001a48e4[];
extern unsigned char s_texture__001a4514[];
extern unsigned char s_tmp_001a4460[];
extern unsigned char s_transpose__001a49b0[];
extern unsigned char s_vs_001a838c[];
extern unsigned char s_w_001a449c[];
extern unsigned char s_weight__001a47b8[];
extern unsigned char s_x_001a4490[];
extern unsigned char s_y_001a4494[];
extern unsigned char s_z_001a4498[];
extern MACH_HEADER_t MACH_HEADER;
extern float FLOAT_001aa0cc;
extern float FLOAT_001aa0d0;
extern float FLOAT_001aa0d4;
extern float FLOAT_001aa0d8;
extern float FLOAT_001aa0dc;
extern float FLOAT_001aa0e0;
extern float FLOAT_001aa0e4;
extern float FLOAT_001aa0e8;
extern float FLOAT_001aa0ec;
extern float FLOAT_001aa0f0;
extern float FLOAT_001aa0f4;
extern float FLOAT_001aa0f8;
extern float FLOAT_001aa0fc;
extern float FLOAT_001aa100;
extern float FLOAT_001aa104;
extern float FLOAT_001aa108;
extern float FLOAT_001aa10c;
extern float FLOAT_001aa110;
extern float FLOAT_001aa114;
extern float FLOAT_001aa118;
extern float FLOAT_001aa128;
extern float FLOAT_001aa12c;
extern float FLOAT_001aa130;
extern float FLOAT_001aa134;
extern float FLOAT_001aa138;
extern float FLOAT_001aa13c;
extern float FLOAT_001aa140;
extern float FLOAT_001aa144;
extern float FLOAT_001aa148;
extern float FLOAT_001aa14c;
extern float FLOAT_001aa150;
extern float FLOAT_001aa154;
extern float FLOAT_001aa158;
extern float FLOAT_001aa164;
extern float FLOAT_001aa168;
extern float FLOAT_001aa170;
extern float FLOAT_001aa174;
extern float FLOAT_001aa178;
extern float FLOAT_001aa17c;
extern float FLOAT_001aa180;
extern float FLOAT_001aa184;
extern float FLOAT_001aa188;
extern float FLOAT_001aa18c;
extern float FLOAT_001aa190;
extern float FLOAT_001aa194;
extern float FLOAT_001aa198;
extern float FLOAT_001aa19c;
extern float FLOAT_001aa1a8;
extern float FLOAT_001aa1ac;
extern float FLOAT_001aa1b0;
extern float FLOAT_001aa1b4;
extern float FLOAT_001aa1b8;
extern float FLOAT_001aa1bc;
extern float FLOAT_001aa1c0;
extern float FLOAT_001aa1c4;
extern float FLOAT_001aa1cc;
extern float FLOAT_001aa1d0;
extern double DOUBLE_001aa1e0;
extern double DOUBLE_001aa1e8;
extern double DOUBLE_001aa1f0;
extern double DOUBLE_001aa1f8;
extern double DOUBLE_001aa200;
extern double DOUBLE_001aa208;
extern double DOUBLE_001aa210;
extern double DOUBLE_001aa218;
extern double DOUBLE_001aa220;
extern double DOUBLE_001aa228;
extern double DOUBLE_001aa230;
extern double DOUBLE_001aa238;
extern double DOUBLE_001aa240;
extern double DOUBLE_001aa248;
extern double DOUBLE_001aa250;
extern double DOUBLE_001aa258;
extern double DOUBLE_001aa268;
extern double DOUBLE_001aa270;
extern double DOUBLE_001aa278;
extern double DOUBLE_001aa280;
extern double DOUBLE_001aa288;
extern double DOUBLE_001aa290;
extern double DOUBLE_001aa298;
extern double DOUBLE_001aa2a0;
extern double DOUBLE_001aa2a8[];
#include "extra_decls.h"
#include "gld_ctx_fields.h"
#include "arb_ctx_fields.h"
#include "prog_ctx_fields.h"
#include "comp_ctx_fields.h"
