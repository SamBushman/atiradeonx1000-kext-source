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
extern int gld_isBufferBackingIdle();
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
extern int gld_detachDrawable();
extern int _gldAttachDrawable();
extern int gld_latchValue178();
extern int _gldGetError();
extern int _gldCreateFence();
extern int _gldDestroyFence();
extern int _gldTestObject();
extern int _gldFinishObject();
extern int _gldCreateFramebuffer();
extern int _gldReclaimFramebuffer();
extern int _gldDestroyFramebuffer();
extern int gld_bindCurrentFramebuffer();
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
extern int gld_resolveProgramSlots();
extern int gld_decodeProgramOperandOffset();
extern int gld_decodeProgramOperandOffset_frag_0000973c();
extern int gld_decodeProgramOperandOffset_frag_00009750();
extern int gld_decodeProgramOperandOffset_frag_0000979c();
extern int gld_decodeProgramOperandOffset_frag_000097ac();
extern int gld_decodeProgramOperandOffset_frag_000097bc();
extern int gld_decodeProgramOperandOffset_frag_000097cc();
extern int gld_decodeProgramOperandOffset_frag_000097dc();
extern int gld_decodeProgramOperandOffset_frag_000097ec();
extern int gld_decodeProgramOperandOffset_frag_000097fc();
extern int gld_decodeProgramOperandOffset_frag_00009810();
extern int gld_decodeProgramOperandOffset_frag_00009880();
extern int gld_decodeProgramOperandOffset_frag_000098c8();
extern int gldAllocQueryRecord();
extern int gld_waitQueryStamp();
extern int _gldDestroyQuery();
extern int gld_releaseQueryMemory();
extern int gld_setQueryAgpRefBacking();
extern int _gldCreateQuery();
extern int gldFormatBitsPerPixel();
extern int gld_bitsFromRenderFlags();
extern int gldFormatAlphaBits();
extern int gld_channelBitsForFormat();
extern int gld_textureVariantClass();
extern int gldPixelUnitBytes();
extern int gldPixelRowBytes();
extern int gld_computePixelStoreLayout();
extern int gld_resolveBoundTextures();
extern int gld_textureMemoryBytes();
extern int gld_waitTextureStamp();
extern int gld_isTextureBackingIdle();
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
extern int gld_updateCurrentVertexArray();
extern int gld_waitVertexArrayStamp();
extern int gld_isVertexArrayBackingIdle();
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
extern int gld_setContextParameter();
extern int gld_applyPbufferToRenderFlags();
extern int gld_updateColorFormatIndex();
extern int gld_setIntegerEngineParam();
extern int gld_rendererStatusFlags();
extern int gld_fillCapsBlock();
extern int gld_encodePixelFormatFlags();
extern int gld_postDisplayNotification();
extern int gldRemoveDisplayNotificationObserver();
extern int gld_printApplicationPath();
extern int gld_classifyTextureVariant();
extern int glCopyPixels_impl();
extern int glDrawPixels_impl();
extern int gld_drawPixelsAtRasterPos();
extern int gld_drawPixelsDispatch();
extern int gld_selectSampleCount();
extern int gld_selectSampleGrid();
extern int gld_updateSampleConfig();
extern int gld_applySampleConfiguration();
extern int gld_needsMultisampleResolve();
extern int gld_isStampRetired();
extern int gld_submitRing();
extern int glFlush_impl();
extern int glFlush_impl_withSurfaceUpdate();
extern int _gldFlush();
extern int _gldFinish();
extern int gld_signalFence();
extern int glFinish_impl();
extern int gld_swapBuffersImpl();
extern int gld_validatePixelFormat();
extern int gld_expandPixelFormatVariants();
extern int gld_fillMaxPixelFormat();
extern int _gldFreeVertexBuffer();
extern int _gldCompleteVertexBuffer();
extern int _gldAllocVertexBuffer();
extern int gld_updateYInvertedFlag();
extern int noop_1b4f0();
extern int returnOne_1b500();
extern int gld_validateFramebuffer();
extern int gld_emitFramebufferState();
extern int dxt5EncodeAlphaBlock();
extern int dxt1DecodeColorIndex();
extern int dxtCompressImage();
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
extern int gld_buildVertexStreamLayout();
extern int gld_updateScissorRect();
extern int gld_clearBuffers();
extern int gldDisplayNotificationCallback();
extern int gld_resetNotificationSettings();
extern int gld_emitCopyRectPacket();
extern int gld_emitCopyBlitPacket();
extern int noop_22280();
extern uint _gldUpdateDispatch(int param_1,int param_2,uint *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int _gldInitDispatch();
extern int gld_emitDirtyStatePackets();
extern int gld_emitSurfaceCopyPacket();
extern int returnSecondArgument();
extern int gldEmitCurrentAttributeRegisters();
extern int gldEmitCurrentAttributeRegistersMasked();
extern int gld_emitPrimitiveVertices();
extern int gld_emitImmediateVertexList();
extern void gldPrimWrapperTriangles_23a24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8);
extern void gldPrimWrapperTriangleStrip_23a24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
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
extern int gld_initListHead();
extern int noop_24fc0();
extern int noop_24fd0();
extern double gld_gatherProgramConstants(int param_1,int param_2,float *param_3,double fparam_1);
extern int gld_releaseProgramObject();
extern int gld_deleteContextProgramObjects();
extern int gld_bindFragmentProgramRecord();
extern int gld_bindProgramRecord();
extern int gld_bindProgramObject();
extern int gld_getProgramParameter();
extern int gld_drawArraysDirect();
extern void gld_reserveVertexBufferSpace(int param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int gld_drawArraysStream();
extern uint gld_reserveDrawSpace(int param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int gld_buildVertexStreamCache();
extern int gld_readPixelsViaBlit();
extern int glReadPixels_entry();
extern int glReadPixels_impl();
extern int gld_drawPixelsAsPoints();
extern int gld_enterPointDrawState();
extern int gld_drawPixelsFromClientSurface();
extern int noop_2b3b0();
extern int gld_sumQueryCounters();
extern int _gldGetQueryInfo();
extern void gld_beginQuerySlot(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int gld_emitQueryBeginPacket();
extern void gld_emitStampFencePacket(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int gld_ensureRingSpace();
extern int gld_setStreamCursor();
extern int gld_getStreamCurrent();
extern int noop_2be80();
extern int gld_forwardToStream();
extern int gldTrimVertexCountToPrimitive();
extern int gldTrimVertexCountToPrimitiveMin();
extern void gld_revalidateStreamProgram(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,uint param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int gld_emitVapStreamControl();
extern int gld_emitStreamAddressRegisters();
extern int gld_validateStreamState();
extern int gld_buildHardwareStateBuffer();
extern int gld_initContextHardwareState();
extern int gldContextFreeResources();
extern int gld_submitRingIfNeeded();
extern uint gld_prepareDrawCount(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,undefined4 param_6,uint param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int gld_emitUnitObjectPacket();
extern int gld_emitUnitObjectPackets();
extern int gld_setSamplerMinFilter();
extern int gld_setSamplerMagFilter();
extern void gldPackColorForSurfaceFormat(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int gldTextureHasNonPowerOfTwoSize2();
extern int gld_buildTextureHardwareState();
extern int gld_applyAnisotropyOverride();
extern int gld_updateTextureSamplerState();
extern int window_mode_to_ati_format();
extern int gldTextureFormatCodeMatchesType();
extern int gldTextureFormatCodeFromFormatType();
extern int gld_selectTextureHardwareFormat();
extern int gldCompressedImageBytes();
extern int gld_buildTextureStatePacket();
extern int gld_compressAlphaBlock();
extern int gld_emitUnitClearPacket();
extern int gld_emitSingleUnitBinding();
extern int gld_emitBoundUnitObjects();
extern int floorLog2();
extern int gld_bindUnitObject();
extern int gld_deleteTextureForStream();
extern int gld_emitRenderTargetPacket();
extern int gldTextureHasNonPowerOfTwoSize();
extern int gld_createInternalTexture();
extern int gld_texelBytes();
extern int gld_getTextureFormatInfo();
extern int gldTextureFormatLookup();
extern int gldTextureFormatEntryForLevel();
extern int gld_readbackTextureLevel();
extern int _gldGetTextureLevel();
extern int gld_uploadTextureLevel();
extern int gldTextureMakeResident();
extern int gld_makeTextureResidentOrDelete();
extern int glGenerateMipmap_impl();
extern int glCopyTexSubImage_impl();
extern int glTexSubImage_impl();
extern int gld_testRendererAvailable();
extern int gldRendererFamilyString();
extern int _gldGetVersion();
extern int _gldGetString();
extern void gldPrimInlineLineStrip(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimInlineTriangleFan(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimInlineTriangles(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimInlineTriangleStrip(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimInlineQuads(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimInlineQuadStrip(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimInlinePolygon(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimInlinePoints(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimInlineLines(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void gldPrimInlineLineLoop(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int gld_updateProgramConstantsForDirtyBits();
extern int extvsDeclareProgramVariables();
extern int gld_bindVertexShaderSlot();
extern int extvsBuildProgramSymbolEntries();
extern int gld_uploadProgramStateConstants();
extern int gldDeleteVertexShaderObject();
extern int extvsTranslateShaderObject();
extern int gld_emitProgramConstantUpdates();
extern int gldUpdateTextureTargetDirtyMask();
extern int gld_updateUnitKindTable();
extern int gld_updateFragmentProgramState();
extern int gld_bindFragmentShaderSlot();
extern int gld_setFragmentShaderConstants();
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
extern int fragmentTranslateScalarMath2Src();
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
extern int gldReselectProgramStream();
extern void gldRebindCurrentProgram(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1);
extern int gldResetProgramEntry();
extern int arbfpRebindIfOverLimit();
extern int gldResetProgramEntryDefaults();
extern int gldInitProgramCacheEntry();
extern int gldUploadProgramState();
extern int gldSetProgramStreamMode();
extern int gldClearBoundSlot();
extern int gldRemoveProgramFromList();
extern int gldReleaseProgramEntry();
extern int gldFlushProgramCache();
extern int gldMarkAllProgramsDirty();
extern int gldGrowProgramHashTable();
extern int gldLookupProgramVariant();
extern int gldCopyProgramStreamState();
extern int gldEmitProgramStatePacket();
extern int noop_4c540();
extern int gldSetCurrentProgramObject();
extern int gldValidateVertexStreams();
extern int freeAndNullField();
extern int gldValidateHyperZ();
extern int gldValidateAlphaBlendEarlyZ();
extern void gldMarkProgramsDirtyByFlag(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1);
extern void gldValidateViewportPolygonOffset(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8);
extern int gldValidateDepthTest();
extern int gldValidateVertexOutputRouting();
extern int gldValidateTexEnvColor();
extern int gldEmitScissorRegs();
extern int gldEmitViewportAndGuardBand();
extern int gldEmitConstantFlushPacket();
extern int gldSetUnitScaleConstants();
extern double gldValidateTextureUnits(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int gldEmitRegisterPairPacket();
extern int gldDepthBiasScaledInt();
extern double gldValidatePolygonMode(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8);
extern int gldValidatePolygonOffset();
extern int gldValidatePointSize();
extern int gldValidateCullFace();
extern int gldFogColorChannelByte();
extern void gldValidateFog(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1);
extern int gldValidateScissor();
extern int gldInitStateDefaults();
extern int ffvpSetOutputRoute();
extern int extvsUpdateVertexAttributeConstants();
extern int gldValidateAlphaTest();
extern int gldValidateColorMask();
extern int gldEmitHardwareState();
extern int gldSetVertexPacketLimits();
extern int gldValidateStencil();
extern int gldValidateBlend();
extern double gldValidateViewport(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8);
extern int gldEmitDirtyStatePackets();
extern int extvsSelectHandlerTables();
extern int extvsSetStreamAndValidate();
extern int extvsGetSymbolStorageWord();
extern int extvsGetSymbolStorageKind();
extern int extvsMarkStateDirty();
extern int extvsSelectRegisterCode();
extern int noop_53060();
extern int extvsConstantsDirty();
extern int extvsClearConstantsDirty();
extern int extvsGetSymbolStorageInfo();
extern int extvsEnabledInputMask();
extern int extvsGetOrCreateStateSymbol();
extern int glGenSymbolsEXT_impl();
extern int extvsCreateVectorSymbolChain();
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
extern int extvsEmitSwizzleInstruction();
extern int glWriteMaskEXT_impl();
extern int glInsertComponentEXT_impl();
extern int glExtractComponentEXT_impl();
extern int glGenSymbolsEXT_impl5();
extern int extvsGetConstantUploadInfo();
extern int extvsCompactSymbolEntries();
extern int extvsMakeShaderCurrent();
extern int glSetLocalConstantEXT_impl();
extern int extvsBindCurrentVertexParameter();
extern int extvsFreeAllShaders();
extern int extvsReleaseState();
extern int extvsInitState();
extern int extvsAttachSharedState();
extern int extvsSymbolListGetIndex();
extern int extvsAppendSymbol();
extern int extvsResolveOperand();
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
extern int extvsRewriteHardwareInstructions();
extern int extvsPrepareHardwareProgram();
extern int vpUploadConstantArray();
extern int vpUploadConstantsWithFog();
extern int extvsComputeStateKey();
extern int extvsStateFree();
extern int gldLoadUnitFlagBits();
extern int extvsInitLimits();
extern int gldAllocListNode();
extern int gldFreeListNodes();
extern int gldDestroyListObject();
extern int extvsStateCacheCreate();
extern int extvsStateCacheFreeAll();
extern int extvsUploadSingleConstant();
extern int noop_62a60();
extern int extvsStateCacheInsert();
extern int extvsBuildStreamDescriptors();
extern int gldCurrentAttributePacketHeader();
extern int extvsBuildStreamBlock();
extern int gldCopyRouteRegisters();
extern int extvsApplyStreamDescriptors();
extern int extvsUploadProgramConstants();
extern int extvsValidateProgramState();
extern int extvsFlushConstantUploads();
extern int ffvpSelectLitProgramVariant();
extern int ffvpInitBuilderOutputSlots();
extern int ffvpSelectPassThroughVariant();
extern void vpFillConstantBank(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int ffvpUploadVariantConstants();
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
extern int arbEmitIlOp4e();
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
extern int vpStateUpdateFogConstants();
extern int vpStateApplyParameters();
extern int vpStateComputeKey();
extern int vpStateCacheInsert();
extern int noop_76c00();
extern int vpStateCacheLookup();
extern int vpStateSelectForDraw();
extern int noop_76e60();
extern int vpStateFree();
extern int ctxTempListCreate();
extern int ctxTempListFree();
extern int vpStateCacheCreate();
extern int vpStateCacheFreeAll();
extern int vpStateSetConstantVector();
extern int recordAllocCreate();
extern int recordCollectDependencies();
extern int depListRemove();
extern int recordClearBindingTables();
extern int arrayRemoveAt();
extern int recordDestFileIs0Or45();
extern int recordDestFileIs3Or1();
extern int recordGetWriteMask();
extern int recordIsSchedulable();
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
extern int recordMarkPairEmitted();
extern int recordFlagsPending20();
extern int recordFlagsPending2();
extern int recordCountSourceRegisterFiles();
extern int recordRetargetDestination();
extern int regBindingClear();
extern int chunkArenaAlloc();
extern int recordSourceFileIs2();
extern int recordGetWriteEnable();
extern int recordRetireBindings();
extern int recordSetWriteMask();
extern int depListAddEdge();
extern int recordGetSourceSelect();
extern int recordSetSourceSelect();
extern int recordAddTransitiveDependencies();
extern int recordLinkSourceToDefinition();
extern int recordSourcesAreDistinctTemps();
extern int recordFindScheduleConflict();
extern int chunkArenaResetCursor();
extern int chunkArenaFree();
extern int recordAllocFree();
extern int recordRemapComponents();
extern int recordPlanDestination();
extern int recordPickNextToEmit();
extern int recordProgramAllocateAndEmit();
extern int recordProgramBuildDependencies();
extern int ctxTempListPush();
extern int ctxTempListRemove();
extern int evsFoldConstantMoves();
extern int gldAllocAndUploadConstants();
extern int gldEmitProgramConstants();
extern int interpolatorMapInit();
extern int noop_83100();
extern int ffvpSetupVertexOutputRouting();
extern int ffvpBuildPassThroughProgram();
extern int gldEmitVertexRoutingPackets();
extern void ffvpValidateProgram(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern void ffvpValidateProgramForced(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int gldEmitInternalDrawSetupPackets();
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
extern int gldEmitPacket_reg880();
extern int gldSyncClipPlaneEnables();
extern int gldUploadClipPlanes();
extern int gldLodBiasToFixed(int param_1,double fparam_1,double fparam_2);
extern int gldUpdateLodBiasField();
extern int gldSaveRasterState();
extern int gldEnterInternalDrawState();
extern int gldLeaveInternalDrawState();
extern int arbfpUpdateConstantsFp24();
extern int arbfpInitResourceLimits();
extern int noop_879e0();
extern int arbfpInitUnitState();
extern int arbfpUnbindWorkAreaChecked();
extern int arbfpUnbindWorkArea();
extern int arbfpWorkAreaSizeA();
extern int arbfpWorkAreaSizeB();
extern int arbfpCompileFragmentProgram();
extern int arbfpBindFragmentProgram();
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
extern int gldCallHook1278();
extern int arbfpProgramObjectInit();
extern int arbfpProgramObjectFree();
extern int arbfpProgramString();
extern int arbfpProgramStringIL();
extern int arbfpFetchParameterValue();
extern int arbfpInitProgramState();
extern int arbfpGrowInstanceTable();
extern int arbfpLoadDefaultProgram();
extern int gldDrawInternalRect();
extern int gldFlushProgramStateForDraw();
extern int ffvpAssignOutputSlots();
extern int ffvpComputeOutputMasks();
extern void gldValidateState(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int gldEmitTclModeRegs();
extern int gldClearHwTclFlag();
extern int gldUpdateHwTclState();
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
extern int ffvpEmitVectorLength();
extern int ffvpEmitSphereMapCoord_0934f0();
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
extern int gldValidateVertexProgramState();
extern int ffvpBuildProgram();
extern int fpVariantCacheGrow();
extern int fpVariantCacheLookup();
extern void programFillStateConstants(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int arbProgramFindIndex();
extern int glProgramStringARB_impl();
extern int arbProgramEntryInit();
extern int glBindProgramARB_impl();
extern int glGenProgramsARB_impl();
extern int glGetProgramivARB_impl();
extern int arbProgramEntryFree();
extern int arbProgramTableRelease();
extern int glDeleteProgramsARB_impl();
extern int arbProgramTableInit();
extern int noop_a0f80();
extern int atifsInit();
extern int arbProgramTypeCode();
extern int arbProgramIsValid();
extern int gld_setUnitTargetBits();
extern int gld_getShaderTexUnitMask();
extern int gld_getFragmentShaderKind();
extern int gld_collectUsedTexCoordUnits();
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
extern uint gld_quantizePointSizeInt(int param_1,double fparam_1);
extern int gld_roundUpToPowerOfTwo();
extern int gld_isPointAttenuationActive();
extern int gld_scalePointSizeToPixels();
extern void gld_buildCoverageByteTable(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,int *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12);
extern void gld_buildCoverageRampTable(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int gld_setPrimitiveInputRegisters();
extern int gld_freePointMaskCache();
extern int gld_invalidateCachedPointMasks();
extern int gld_markBoundObjectsDirty();
extern int gld_refreshActivePointMask();
extern int gld_getActiveSampleIndex();
extern int gld_computePointSizePixels();
extern int gld_buildSmoothPointMask();
extern int gld_emitClearColorPacket();
extern int gld_updateSampleCoverage();
extern int gld_resetRasterStateForInternalDraw();
extern int gld_markFastClearFlag();
extern int gld_emitClearFillPacket();
extern int gld_emitInternalViewportPacket();
extern int gld_clearStreamBuffers();
extern int gld_callocBytes();
extern int noop_a6f80();
extern void gld_normalizeVec3(float *param_1,float *param_2,double fparam_1);
extern int gld_initContextDispatch();
extern int gldFreeEngineState();
extern int gld_updateDrawBufferConfig();
extern int gldMarkAllStateDirty();
extern int gld_buildActiveUnitList();
extern int gld_markDirty10();
extern int gld_clearStateBit28MarkDirty();
extern int noop_a7ed0();
extern int gld_updateTextureUnitState();
extern int gld_dropStaleTextureShadow();
extern int gld_clearPacketSlot();
extern int gld_copyTexCombinerSources();
extern double gld_updateInverseMatrix(int param_1,int param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int gld_transformClipPlanes();
extern int gld_updateProgramFlags();
extern int gld_updatePolygonModeFlags();
extern int gld_updateLightingFlags();
extern int gld_commitTexEnvUnits();
extern double gld_updatePointState(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12);
extern void gld_validateDirtyState(char *param_1,uint *param_2,char *param_3,undefined *param_4,uint param_5,char *param_6,undefined4 param_7,uint param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13);
extern int gld_selectProgramCallback();
extern int gld_convertDestOperand();
extern int gld_classifyOperand();
extern void gld_uploadParamConstants(int param_1,int param_2,undefined4 param_3,double fparam_1);
extern int gld_getBoundProgramId();
extern int gld_scanOperandRegisterCount();
extern int gld_scanProgramTokens();
extern int gld_emitUnitSelectTokens();
extern int gld_emitFormatConvertTokens();
extern int gld_emitInstructionTokens();
extern undefined4 gld_compileFragmentProgram(int param_1,int param_2,undefined4 param_3,uint *param_4,double fparam_1);
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
extern int gld_compileILProgram();
extern int gld_decodeProgramInterface();
extern void gld_storeConstantVec4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern void gld_emitSlotParamIfDirty(int param_1,int param_2,int *param_3,int param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int gld_emitTextureUnitScaleParams();
extern int noop_b5190();
extern int gld_emitSlotViewportTransforms();
extern int gld_emitSlotTransformParams();
extern int noop_b53f0();
extern int gld_emitProgramStatePackets();
extern int gld_compileFragmentProgramImage();
extern int gld_emitProgramConstants();
extern int gld_emitProgramStateAndConstants();
extern int gld_emitProgramStateOnly();
extern int gld_emitProgramConstantsOnly();
extern int gld_bindProgramStateAndEmit();
extern int gld_freeProgramImage();
extern int gld_destroyUnitCmdLists();
extern int gld_buildUnitSetupCmdList();
extern int ffpsBuildProgram();
extern double gld_updateUnitBiasRegisters(int param_1,int param_2,int param_3,int param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9);
extern int extvsInstReadsTempComponents();
extern int extvsOptimizeProgram();
extern void gld_emitLightingStatePacket(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1);
extern int gld_updateTexCombinerState();
extern int psnDecDecodeFragmentProgram();
extern int psnEncodeHwProgramPhased();
extern int psnCheckLimitsAndGenerate();
extern int psnRemapTempRegisters();
extern int psnPlanPhases();
extern int ilRemapSwizzleTriple();
extern int ilRemapSwizzleSingle();
extern int psnEncodeHwProgram();
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
extern int psnAnalyzeProgram();
extern int psnReallocateTemps();
extern int scCallbackFree();
extern int scCallbackGetFlagZero();
extern int scCallbackAppendFormatted();
extern int scCallbackFopen();
extern int scCallbackFclose();
extern int scCallbackFwrite();
extern int scCallbackFread();
extern int scCreateForContext();
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
extern int ilEmitShadowStateTokens();
extern int ilEmitPrologue();
extern int ilRecordRegisterUse();
extern int ilRemapSourceOperandRegister();
extern int ilMarkOperandRegisterUsed();
extern int ilMarkInstructionRegistersUsed();
extern int ilCopyInstructionRemapped();
extern int ilPushDclRecord();
extern void ilStoreFloat4Constant(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int ilAssembleProgram();
extern int ilRewriteForTextureState();
extern int scCreate();
extern int scDestroy();
extern int scSetCallbackTablesChecked();
extern int scCompile();
extern int scCheckHandle();
extern int scDisassembleIL();
extern int scDumpSrcShader();
extern int scDumpShader();
extern int scDumpShaderToString();
extern int vsOpcodeSourceCount();
extern int scDisassembleILImpl();
extern int scLogToSink();
extern int scDumpSrcShaderImpl();
extern int scDumpShaderImpl();
extern int scDumpShaderToStringImpl();
extern int noop_cdc20();
extern int scShaderStateFlag();
extern char * vsdisFormatFloat(undefined4 param_1,int param_2,char *param_3,double fparam_1);
extern int vsdisClearSinkRecord();
extern int vsdisClearSinkRecord2();
extern int scDisasmPrintf();
extern int vsDisasmSourceOperand();
extern int vsdisPrintInputDx();
extern int vsdisPrintOutputMapping();
extern int vsdisPrintShaderData();
extern int vsDisasmDestOperand();
extern int vsDisasmMathOpcode();
extern int vsDisasmVectorOpcode();
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
extern double psDisasmFormatRegister(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1);
extern int psDisasmFormatRgbSource();
extern int psDisasmFormatAlphaSource();
extern int psnDumpPixelShader();
extern int psnClearSinkRecord();
extern int psnClearSinkRecord2();
extern int scDumpPixelProgramPsn();
extern int scDumpPixelProgramToStringStub();
extern int scDumpPixelProgram();
extern int ffpsBuildRgbSourceOperand();
extern int ffpsBuildAlphaSourceOperand();
extern int ffpsEmitColorOutputMovs();
extern int ffpsEmitFogTokens();
extern int ffpsEmitDeclarations();
extern int ffpsEmitTexEnvCombine();
extern int ffpsEmitTexEnvLegacy();
extern int ffpsEmitTextureSamples();
extern int BitSet256__findNthSetBit();
extern undefined4 scStoreConstantComponent(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,double fparam_1);
extern int ConstBank__storeIntLane();
extern int ConstBank__storeBoolLane();
extern int scStoreIntConstantComponent();
extern int ConstBank__addMappedEntry();
extern int CompileInput__lacksFlag0x200000();
extern int CompileInput__getFloatConstCount();
extern int CompileInput__getIntConstCount();
extern int CompileInput__getBoolConstCount();
extern int CompileInput__readFloatConst();
extern int CompileInput__readIntConst();
extern int CompileInput__readBoolConst();
extern int Compiler__bumpStatsCounter100();
extern int Compiler__createFromRequest_da0c0();
extern int scSetCallbackTables();
extern int Compiler__getFailureCode();
extern int Object__setThreeWords();
extern int scDestroyCompilerObject();
extern int Compiler__createFromRequest();
extern double MiniFloat__decode(uint param_1,double fparam_1);
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
extern int Compiler__isCurrentHandle();
extern int Compiler__setDefaultOptions();
extern int Compiler__resetOutputBufferState();
extern int testBit24();
extern int Compiler__applyRequestFlags();
extern int Compiler__logf();
extern int Compiler__clearOutputChunks();
extern int noop_e0e9c();
extern int noop_e0ea0();
extern int isWhitespaceChar();
extern int Compiler__setOption();
extern int noop_e1388();
extern int noop_e138c();
extern int Compiler__setFlag31c();
extern int Compiler__resetPerStageState();
extern int Compiler__setSamplerCaps();
extern int Compiler__timerOutputFileName();
extern int Compiler__releaseOutputBuffer();
extern int Compiler__setTableEntry534();
extern int Compiler__setQueriedTableEntry4d4();
extern int Compiler__fail();
extern int Compiler__allocateOrFail();
extern int Compiler__propagateFlag5a1Bit1();
extern int Compiler__selectEntry534ByProgramFlags();
extern int Compiler__tryRetryAfterFailure();
extern int Compiler__selectBlockByProgramFlags();
extern int Compiler__setBitInSelectedBlockB8();
extern int Compiler__setBitInSelectedBlockD8();
extern int Compiler__setBitInSelectedBlock98();
extern int Compiler__getOrCreateSlotObject();
extern int Compiler__resetState();
extern int Compiler__init_e1920();
extern int Compiler__init_e1a48();
extern int Compiler__setHardwareFamily();
extern int Program__forwardMulOperandToUsers();
extern int Compiler__releaseChipAndPools();
extern int Compiler__compileStages();
extern int Compiler__compileWithRetry();
extern int Compiler__compile();
extern int MachineCodeWriter__accumulateStats();
extern int MachineCodeWriter__encodeBlockViaSink();
extern int EncoderState__emitBlock();
extern int EncoderState__sinkIsOverflowed();
extern int Block__accept();
extern int IfFooterStatic__accept();
extern int Block__getOrAllocSlotId();
extern int moduloDifference();
extern int IRStartCallRoutine__acceptCallPseudo();
extern int IREndCallRoutine__acceptCallPseudo();
extern int IRStartMakeCall__acceptCallPseudo();
extern int IREndMakeCall__acceptCallPseudo();
extern int IRInst__hasSourceWithKey();
extern int IRInst__foldConstantSourceSwizzle();
extern int Block__callVtable84OnInstsExceptOpcode57();
extern int ConstRecord__emitStores();
extern int EncoderState__emitInstruction();
extern int IRInst__redirectDestThroughNewMov();
extern int IRInst__lastSourceKeyEquals();
extern int MachineAssembler__vslot34_declareDestinationLanesByClass();
extern int MachineAssembler__visitIfHeaderStatic();
extern int EncoderState__destroy_e3244();
extern int EncoderState__destroy_e3308();
extern int EncoderState__init_e33cc();
extern int EncoderState__init();
extern int MachineCodeWriter__encodeProgram();
extern int IRInst__createMovForDest();
extern int IRInst__dropAppendedSources();
extern int Block__materializePendingMovs();
extern int ILReader__atFirstInst();
extern int setWord30();
extern int ILReader__currentOpcode();
extern int ILReader__lookupBoolConst();
extern int ILReader__appendIntConst();
extern int ILReader__readFloatConst();
extern int ILReader__lookupConstComponent();
extern int OpcodeRecord__getOperandByteB();
extern int ILReader__appendBoolConst();
extern void ILReader__appendFloatConst(int *param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int ILReader__topScopeOpcode();
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
extern int Scope__setBreakTarget();
extern int Block__getBranchInst();
extern int Block__setField0xb8AndChildren();
extern int Block__isAncestorOf();
extern int Block__nearestCommonAncestor();
extern int Block__vectorF8NonEmpty();
extern int Block__hasMultipleSuccessors();
extern int Block__hasMultiplePredecessors();
extern int Block__successorCount();
extern int Block__predecessorCount();
extern int Block__hasSuccessors();
extern int Block__vectorD4NonEmpty();
extern int Block__hasDominatedChildren();
extern int Block__popDefinitions();
extern int Block__lastBlockOfChain_e7a9c();
extern int Block__lastBlockOfChain_e7b9c();
extern int Block__resolveRedirect();
extern int EntryBlock__insertInstruction();
extern int Block__getLoopFooterRegister();
extern int Block__isInVectorD4Of();
extern int Block__findSimplePredecessor();
extern int Block__findSimpleSuccessor();
extern int Block__successorIndex();
extern int Block__predecessorIndex();
extern int Block__phiOperandIndexForPredecessor();
extern int Block__nextUnvisitedSuccessor();
extern int Program__allocateBitSetIndex();
extern int Block__getFirstRealInst();
extern int Block__insertAtStart();
extern int Block__verify();
extern int LoopHeader__verify();
extern int IfHeader__canFlatten();
extern int Block__createEntryExitInsts();
extern int Block__initVectors();
extern int Block__loopStep();
extern int Block__loopStart();
extern int Block__loopUnrollCount();
extern int Block__addDominatedChild();
extern int Block__appendPredecessor();
extern int Block__appendSuccessor();
extern int Block__connect();
extern int Block__replaceRegionEdges();
extern int Block__addDominanceFrontier();
extern int Block__getPredecessor();
extern int Block__getSuccessor();
extern int IfHeader__armsAreSimple();
extern int Block__bypass();
extern int Block__bypassAndDetach();
extern int Block__splitOutgoingEdge();
extern int Block__splitEdgeAndConnect();
extern int Block__splitIncomingEdge();
extern int Block__splitEdge();
extern int Block__recordDefinition();
extern int Block__loopBodyHasAllLaneFlags();
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
extern int Program__ensureVRegType13();
extern int callTargetSlot25();
extern int Program__registerFileOfIlType();
extern int Program__interpSlotOfIlType();
extern int Program__lookupTable8b68();
extern int Program__laneKindOfInterpSlot();
extern int Table__interpolatorKindToCode();
extern int Program__freeWorkArrays();
extern int Program__insertBlockBefore();
extern int Program__insertBlockAfter();
extern int Program__prependBlock();
extern int Program__appendBlock();
extern int Program__storeDominatorOrder();
extern int Program__getDominatorInfo();
extern int Program__getBlocksArray();
extern int Program__countInstructions();
extern int Program__findBranchingBlock();
extern int Program__splitMixedSourceKinds();
extern int Program__freezeVRegs();
extern int Program__propagateBlockFlagsFromSuccessors();
extern int KhanVs__vslot17_isSimpleInst();
extern int KhanPs__vslot17_isSimpleInst();
extern int IRInst__isFoldableByOpcodeFlags();
extern int IRInst__isForwardable();
extern int Program__insertMovAfter();
extern int Program__insertEntryInst();
extern int Program__dtor_ecfac();
extern int Program__dtor_ed124();
extern int HwLimits__vslot43_prependDefaultMov();
extern int IRInst__bindOperandRegisters();
extern int Program__beginPass();
extern int Program__groupLoadsIntoProjections();
extern int Program__ctor_edd98();
extern int Program__ctor_ee29c();
extern int Program__buildBlockArrayByKey();
extern int Program__addInst();
extern int Program__pinInputRegisters();
extern int Program__emitDepthExportScale();
extern int Program__expandSpecialDestinations();
extern int Program__splitExports();
extern int Program__initAndTranslate();
extern int Program__appendToVector3c8();
extern int Program__removeInst();
extern int Program__orderBlocksByDfs();
extern int Program__insertExitMarkerAndFlagBlocks();
extern int Program__trimOutputChain();
extern int IRInst__tryFoldOutputScale();
extern int Program__forwardMovIntoConsumers();
extern int Program__foldKind6IntoKind7Inst();
extern int Program__propagateMovThroughUses();
extern int pass_assign_slots();
extern int SelectWord__compose();
extern int SelectWord__isSplat();
extern int SelectWord__firstUsedComponent();
extern int Lane__isValid();
extern int SelectWord__areCompatible();
extern int SelectWord__matches();
extern int SelectWord__hasNonzeroLaneBytes();
extern int laneBytes__mapTwoThreeToOne();
extern int laneBytes__mergeOneAndTwo();
extern int SelectWord__markLanesWhereSecondIsOne();
extern int SelectWord__mergeWrittenLanes();
extern int SelectWord__fillUnusedLanes();
extern int SelectWord__markEqualLanes();
extern int laneBytes__commonSelect();
extern int SelectWord__firstWrittenComponent();
extern int SelectWord__firstUnwrittenComponent();
extern int IRInst__isLaneWritten();
extern int IRInst__writesAllLanes();
extern int SelectWord__isIdentity();
extern int IRInst__isSourceSelectIdentity();
extern int SelectWord__selectWhereMasked();
extern int SelectWord__clearReadComponents();
extern int SelectWord__clearReferencedLanes();
extern int SelectWord__maskUnused();
extern int SelectWord__readMask();
extern int SelectWord__fillUnusedWithFirstUsed();
extern int SelectWord__canonicalize();
extern int IRInst__clearSourceSelectsOfUnwrittenComponents();
extern int WriteMask__fromUsedComponents();
extern int WriteMask__fromUsedLanes();
extern int LaneBytes__buildSelectWordOfZeroLanes();
extern int laneBytes__clearSetLanes();
extern int SelectWord__splatComponent();
extern int SelectWord__isSingleComponentConstant();
extern int IRInst__destIsSingleComponent();
extern int laneMask__fromSelectBytes();
extern int WriteMask__fromSelectWord();
extern int laneBytes__selectWhereFirstIsOne();
extern int laneMask__fromUsedLanes();
extern int IRInst__countWrittenComponents();
extern int IRInst__destSelectHasZeroLane();
extern int IRInst__destSelectLane3IsX();
extern int IRInst__operandReadsXYZ();
extern int IRInst__operandReadsW();
extern int IRInst__operandSelectIsNotDefault();
extern int IRInst__computeSourceLaneMask();
extern int IRInst__computeSourceReadMask();
extern int IRInst__sourceReadMaskAvoidsDestKind1();
extern int IRInst__maskUnusedLanesOfOperand();
extern int IRInst__storeInvertedDestMask();
extern int IRInst__mergeDestMasksIntoFirst();
extern int IRInst__sourceLanesAllWritten_f485c();
extern int IRInst__sourceLanesAllWritten();
extern int IRInst__writeMasksOverlap();
extern int ConstRecords__fillFloat4();
extern int RegisterMap__nextTempIndex();
extern int isRegKindBelow21();
extern int Emitter__allocateConstantSlot();
extern int floatLess();
extern int BitSet__findFirstSet();
extern int noop_f4c44();
extern int ConstKey__compareOrdered();
extern int ConstKey__countPresentOperands();
extern int ConstRecord__findInTable();
extern int ConstRecord__insertSwizzleVariants();
extern int Compiler__getOrCreateLoadConstN();
extern int Compiler__getOrCreateLoadConst4();
extern int Compiler__getOrCreateLoadConst3();
extern int Compiler__getOrCreateLoadConst2();
extern int Compiler__getOrCreateLoadConst1();
extern int RegisterMap__findConstVector();
extern int IRInst__canFoldConstantSource();
extern int IRInst__sourceMatchesConstant();
extern int IRInst__getUniformSourceConstant();
extern int IRInst__operandIsNonNegativeFloatConst();
extern int RegisterMap__findConstVectorExact();
extern int Program__dumpConstantRegisters();
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
extern int Vector__findIndexOfKeyPair();
extern int DominatorTree__ctor_f7bf4();
extern int DominatorTree__ctor_f7cd8();
extern int DominatorTree__computeDominanceFrontiers();
extern int DominatorTree__free_f7f1c();
extern int DominatorTree__free();
extern int DominatorTree__dfsNumber();
extern int DominatorTree__compress();
extern int DominatorTree__eval();
extern int DominatorTree__compute();
extern int Program__computeDominators();
extern int OpcodeRecord__getField8();
extern int OpcodeRecord__getOperandCount();
extern int OpcodeRecord__getOperandByte();
extern int OpcodeRecord__getFieldC();
extern int OpcodeRecord__getTranslationKind();
extern int tableWordOrEight();
extern int remapSelect1To0();
extern int remapSelectSmall();
extern double IRInst__literalForLane(int param_1,int param_2,int param_3,int param_4);
extern int Program__applySourceTokenToOperand();
extern int OpcodeTemplate__tableOffsetForIlOpcode();
extern int OpcodeTemplate__lookup();
extern int IRInst__applyDescriptorSelects();
extern int IRInst__applyDescriptorSwizzle();
extern int Program__emitClampPair();
extern int Program__createInstForIlOpcode();
extern int Program__appendInst();
extern int Program__emitInputMerge();
extern int Program__lowerDestinationToken();
extern int Template__bindOperand();
extern int Program__createIfBlock();
extern int Program__createConstantVReg();
extern int Program__loadDefaultConstants();
extern int Program__translateILInstruction();
extern int Template__pushCallFrame();
extern int Program__translateILStream();
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
extern int Vslot__outDefaults_0_0_4();
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
extern int IRInst__canFoldConstantCompare();
extern int IRInst__foldConstantSourcesIntoClone();
extern int IRInst__foldCompareResultIntoCopy();
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
extern int HwLimits__installDefaults();
extern int Compiler__getResourceModel();
extern int Compiler__getThreadModel();
extern int Vslot__returnConst0x10c();
extern int KhanPs__vslot16_getConstant0xb5();
extern int HwLimits__vslot8_failNotSupported();
extern int HwLimits__vslot9_failNotSupported();
extern int Program__emitLoadVertexAttr();
extern int ChipShaders__release();
extern int KhanChip__ctor_10e050();
extern int KhanChip__ctor_10e114();
extern int FudoChip__ctor_10e1d8();
extern int FudoChip__ctor_10e2a0();
extern int RegKind__laneSourceCount();
extern int Array__firstIndexOfEntry();
extern int Lane__remapValue();
extern int PackEntry__computeLaneMap();
extern int Compare__ascendingByWrittenComponents();
extern int Index__scaleForMode();
extern int Vslot__outZeroReturnZero();
extern int Program__assignHwRegsToVertexLoads();
extern int IRInst__query68AndWord4fNotIn6_7();
extern int IRInst__query68AndWord4fIs18();
extern int IRInst__query68AndWord4fIn16_17();
extern int IRInst__query68AndWord4fNotMasked();
extern int LaneInfo__ctor_10e7b8();
extern int LaneInfo__ctor_10e814();
extern int Compare__descendingByRemappedKey();
extern int Compare__descendingByField140();
extern int PackEntry__assignLaneSources();
extern int PackEntry__activeLaneCount();
extern int PackEntry__laneNeedsZero();
extern int Program__callBackendFinish();
extern int PsBackend__bindExportRegisters();
extern int IRInst__destMaskHasGap();
extern int KhanPs__vslot87_assignInterpolatorBindings();
extern int PsBackend__assignInterpolatorRegisters();
extern int PackEntry__lanesFitVector();
extern int Program__classifyExportInsts();
extern int Program__countUsedInterpolatorSlots();
extern int Program__renumberExportInsts();
extern int Program__bindLinkRecordsToSlots();
extern int Program__assignExportSlotsByKind();
extern int Program__assignOutputExportSlots();
extern int Program__assignSharedExportSlots();
extern int PackEntry__bindToVectorRegister();
extern int Program__collectExportEntry();
extern int Program__packInterpolatorEntries();
extern int Program__packPsInputs();
extern int KhanVs__vslot88_assignOutputBindings();
extern int OpcodeTraits__getRecordTail();
extern int Opcode__getInfo();
extern int OpcodeTraits__flagBit0();
extern int Value__isBelow8();
extern int Value__isBelow7();
extern int Backend__bindingSlotsSequential();
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
extern int OpcodeSetup__mode9();
extern int OpcodeSetup__mode6();
extern int OpcodeSetup__mode1();
extern int OpcodeSetup__mode7();
extern int OpcodeSetup__mode8();
extern int OpcodeSetup__mode5();
extern int OpcodeSetup__mode3();
extern int OpcodeSetup__mode2();
extern int OpcodeTraits__instFlagBit2_113734();
extern int OpcodeTraits__flag1WithoutFlag7();
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
extern int Compiler__initStaticLocals();
extern int Value__lowHalfword();
extern int IRPhi__getUniqueSource();
extern int IRInst__allSourcesDefined();
extern int IRInst__sourcesAreSameValue();
extern int Program__noSuccessorHasMultipleSuccessors();
extern int Program__isPreassignedHwReg();
extern int ValueKey__loadSourceDefinitions();
extern int Program__insertPhiNodes();
extern int ValueKey__foldMovSources();
extern int Program__tryEliminateRedundantCopy();
extern int Program__computeHoistWeights();
extern int Program__assignVectorSlot();
extern int Block__appendCopyForDest();
extern int Program__foldUselessPhis();
extern int Program__sequentializeParallelCopies();
extern int Program__eliminatePhiCopies();
extern int Program__hoistInstructions();
extern int pass_ssa_build();
extern int Program__runSsaPipeline();
extern int VRegPool__constructByKind();
extern int VReg__popDefinition();
extern int ExportValue__vslot10();
extern int IRInst__bindSourceFromValue();
extern int VReg__currentDefinition();
extern int VReg__appendUser();
extern int ImmedConstBuffer__clone();
extern int VertexRegister__clone();
extern int VReg__setTopDefinition();
extern int VReg__pushDefinition();
extern int Owner__removeVectorEntry();
extern int Owner__replaceVectorEntry();
extern int VReg__addUse();
extern int VRegInfo__ctor_12379c();
extern int VRegInfo__ctor_1238e8();
extern int Interpolator__vslot10();
extern int ValueKey__createConstantMov();
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
extern int Table1ea904__hasFlag0x11();
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
extern int Object__sumWords4And8();
extern int Object__setWord0();
extern int VRegPool__canonicalizeKey();
extern int Program__decodeRegisterKey();
extern int VRegPool__destroyEntries();
extern int VRegPool__dtor_127470();
extern int VRegPool__find();
extern int VRegPool__create();
extern int VRegPool__findOrCreate();
extern int ConstKey__compare1();
extern int ConstKey__compare2();
extern int ConstKey__compare3();
extern int ConstKey__compare4();
extern int keyEqualsThreeWords();
extern int VRegPool__countEntriesWithQuery18();
extern int VRegPool__dtor_1278d0();
extern int VRegInfo__new_127994();
extern int KhanPs__vslot21_appendRegisterBinding();
extern int KhanPs__vslot78_getLimit_0x20Or0x40();
extern int KhanPs__vslot76_getBindingLimit();
extern int KhanPs__createSchedModels();
extern int LandingPad__resume_127fd8();
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
extern int Loop__unrollExceedsLimits();
extern int Compiler__noteUnrollCount();
extern int IRInst__hasOperandKindClass1();
extern int pass_optimize_control_flow();
extern int IfHeader__swapArms();
extern int Block__findLoopEntryPredecessor();
extern int Block__footerTargetOrSelf();
extern int Block__hasInstWithQuery28();
extern int Program__mergeBlockWithSuccessor();
extern int Block__walkToLoopFooter();
extern int Block__findRegionHeader();
extern int Program__emitMovFromField8c();
extern int Program__emitMovFromFieldA4();
extern int LoopInfo__setCounterPhi();
extern int IRInst__swapCompareOperands();
extern int Program__removeUnreachableBlocks();
extern int Block__bridgePredecessorToSuccessor();
extern int LoopInfo__convertToHardwareLoop();
extern int LoopInfo__init();
extern int Program__collapseIfRegion();
extern int Program__hasKillTexture();
extern int FudoPs__vslot69_shouldFlattenIf();
extern int Program__isTrivialBranchRegion();
extern int Program__rebaseInstRegisters();
extern int LoopInfo__matchCounterInit();
extern int LoopInfo__matchCounterStep();
extern int LoopInfo__matchExit();
extern int pass_loop_trans();
extern int Program__removeDeadRegion();
extern int pass_flatten_ifs();
extern int FudoPs__flattenIfs();
extern int Program__detachRegion();
extern int Program__foldConstantIfRegion();
extern int Program__getOrCreateLandingBlock();
extern int IfFooter__ctor_12e56c();
extern int Program__splitCriticalEdges();
extern int Program__predicatePendingIfs();
extern int Program__unrollLoop();
extern int Program__isRegionTrivial();
extern int pass_remove_empty_graphs();
extern int Array4__contains();
extern int RegAlloc__nextTempId();
extern int Program__markHwRegUsed();
extern int RegAlloc__testBit42c();
extern int RegAlloc__countUnassignedHwRegs();
extern int BitSet__setBit42c();
extern int RegAlloc__highestUnassignedInClass();
extern int RegAlloc__countUnassignedInClass();
extern int RegAlloc__allocateFirstFreeInClass();
extern int IRInst__chainLast();
extern int IRInst__chainLastOfPredecessor();
extern int IRInst__advanceToChainEnd();
extern int IRInst__chainEndNext();
extern int IRInst__chainEndSkippingFlag4000000();
extern int Record__field98IsBelow2();
extern int BitSet__testRegisterLane_130958();
extern int BitSet__testAnyLane();
extern int RegAlloc__testBit24();
extern int Program__isHwRegAllowed();
extern int IRInst__findChainNodeById();
extern int IRInst__findSameClassNode();
extern int RegAlloc__markReloadModifiers();
extern int RegAlloc__clearBit430();
extern int RegAlloc__classOfInst();
extern int RegAlloc__emitSpillReload();
extern int RegAlloc__cloneSourceDefAfter();
extern int IRInst__isQuery28OrOpcode93();
extern int Program__appendLoadFa();
extern int Program__prependLoad79();
extern int RegAlloc__laneDependsOnChain();
extern int Program__insertMemLoadFbAfter();
extern int RegAlloc__emitSpillStore();
extern int RegAlloc__initRegisterTables();
extern int RegAlloc__insertCopyBefore();
extern int RegAlloc__getOrCreateSpillSlot();
extern int RegAlloc__sumSlotCounts();
extern int RegAlloc__findFreeSpillSlot();
extern int RegAlloc__getCachedLoadFa();
extern int RegAlloc__setSpillSlotValue();
extern int RegAlloc__buildClassTables();
extern int HwLimits__buildInterferenceGraph();
extern int InterferenceGraph__addEdgesForInst();
extern int RegAlloc__insertSpillCode();
extern int RegAlloc__insertPendingReloads();
extern int RegAlloc__addDefinitionNodes();
extern int RegAlloc__run();
extern int InterferenceNode__setSpillSlot();
extern int InterferenceNode__getSpillSlot();
extern int NeighbourList__locateAppendSlot();
extern int pairIndex();
extern int InterferenceMatrix__setPair();
extern int InterferenceMatrix__testPair();
extern int InterferenceGraph__resolveNode();
extern int NeighbourList__removeResolvedNode();
extern int InterferenceGraph__storeAliasEntry();
extern int ColorGraph__countSameClassNeighbors();
extern int BitSet__clearAllWords();
extern int RegAlloc__registerOfInst();
extern int NeighbourList__reserveAppendSlot();
extern int storeAfterLocate();
extern int NeighbourList__free_135010();
extern int NeighbourList__free_135090();
extern int InterferenceNode__ctor_135110();
extern int InterferenceNode__ctor_1351c4();
extern int InterferenceState__clearNodeWord4();
extern int InterferenceGraph__addEdge();
extern int InterferenceGraph__addNeighbour();
extern int InterferenceGraph__appendToNodeList();
extern int InterferenceGraph__dtor_1357d4();
extern int InterferenceGraph__dtor_135900();
extern int InterferenceGraph__mergeNeighbourLists();
extern int InterferenceGraph__mergeNodes();
extern int ColorGraph__removeNodeUpdateDegrees();
extern int pass_color_graph();
extern int InterferenceGraph__ctor_136ec4();
extern int InterferenceGraph__ctor_13719c();
extern int InterferenceGraph__growNodeArray();
extern int InterferenceGraph__addNodes();
extern int RegAlloc__accumulateUseWeights();
extern int BitSet__testRegisterLane();
extern int IRInst__chainContainsOperandSource();
extern int Liveness__applyInstEffect();
extern int Program__freeBlockBitsets();
extern int Liveness__allocLiveTable();
extern int IRInst__laneWrittenInChain();
extern int IRInst__findLaneDefinition();
extern int Liveness__markUsedBits();
extern int HwLimits__computeBlockLiveness();
extern int Program__finishUsevectorChain();
extern int Mask__countSetBits4();
extern int Node__isNotAmong3();
extern int IRInst__noUseBetween();
extern int LaneStack__topFitsLaneCount();
extern int RewriteStack__topOrderFirstLane();
extern int Block__findEnclosingIfHeader();
extern int IRInst__isOpcodeInSet139344();
extern int Program__moveInterpFetchesOutOfIfs();
extern int IRInst__markOpcode13After12();
extern int Rewrite__tryFoldSourceLaneMask_001396d0();
extern undefined4 IRInst__sourceIsSplatConstant(undefined4 param_1,undefined4 param_2,double fparam_1);
extern int Inst__rewriteClampPattern_001398b4();
extern int Rewrite__tryPeepholesOnInst();
extern int Program__collectRewriteCandidates_00139d40();
extern int Block__scanBranchConeForFetchAndInterp();
extern int RewriteStack__popOrderKey();
extern int RewriteStack__pushOperandKeys();
extern int IRInst__getUsedComponentMask();
extern int IRInst__countUsersCoveringLanes_0013a774();
extern int Program__computeLaneInsertWords_0013a8a4();
extern int IRInst__findCommonUserBlock();
extern int Program__hoistFetchInsts();
extern int Program__eliminateDeadInstsAndRecountUses();
extern int Program__runPeepholeRewrite();
extern int Program__scanUsevectorChains();
extern int IRInst__getExtraOrPhiSource();
extern int IfHeader__convertInnerIfToCmov();
extern int pass_rewrite();
extern int Program__cloneProducersPerBlock_0013d3b8();
extern int Inst__swizzleThroughProducer_0013d820();
extern int Program__rewriteAttribShaderInsts_0013da3c();
extern int Inst__mergeIntoPartner_0013f3d4();
extern int Program__combineInstPairs_0013fc38();
extern int PostPack__initContext();
extern int PostPack__getReadMask();
extern int PostPack__instsCompatible();
extern int PostPack__getWriteMask();
extern int PostPack__getReadOnlyLaneMask();
extern int PostPack__laneSourcesMatch();
extern int PostPack__buildLaneMap();
extern int PostPack__swapInstLanes();
extern int PostPack__replaceUsesAndRemove();
extern int PostPack__orderingAllowsPair();
extern int PostPack__canPairInEitherOrder();
extern int PostPack__matchOperandLanes();
extern int PostPack__getNeededLaneMask();
extern int PostPack__canMoveLane();
extern int PostPack__assignCompactLanes();
extern int PostPack__tryAssignCompactLanes();
extern int PostPack__buildCandidate();
extern int PostPack__remapRootUsers_0014375c();
extern int PostPack__scoreCandidate();
extern int PostPack__rewriteLaneGroup();
extern int PostPack__applyCandidate();
extern int pass_post_pack_insts();
extern int PostPack__runPass();
extern int IRInst__getOperandSourceOrDefault();
extern int SelectWord__writtenLanesCoverRead();
extern int Target__acceptsSelect();
extern int IRInst__getOperandSourceThroughMix();
extern int Inst__sameSaturateAndScale();
extern int Inst__isPlainSingleUse();
extern int Inst__noIfHeaderBetweenBlocks();
extern int Inst__noBarrierBetween();
extern int Inst__allUsesCounted();
extern int Use__negationParityEqual();
extern int Inst__findDeepestChain();
extern int Use__sourceIsPlainSingleUse();
extern int Inst__opcodeOrSourcesDiffer();
extern int Inst__sameOpcodeAndSources();
extern int Inst__sameOrEquivalentSource();
extern int Inst__sourcesRelated();
extern int Inst__canFuseAddMul();
extern int Inst__constantLanesAllowFusion();
extern int IRInst__isOpcodeInSet147398();
extern int Inst__hoistToOperandBlock();
extern int Inst__deleteMergedSources();
extern int Inst__foldOutputScaleChain();
extern int Inst__trySwapOperandSources();
extern int Inst__foldOutputScaleIntoConstants();
extern int Inst__forwardSelectToProducer_0014846c();
extern int Inst__forwardSelectToProducer_001486e8();
extern int Inst__cloneSplatProducer_00148980();
extern int Inst__mergeLaneProducers_00148d8c();
extern int Inst__foldChainedDest_001494dc();
extern int Inst__operandModifiersAndSelectMatch();
extern int Inst__tryComposeSelectWithProducer_00149de4();
extern int Inst__extraSelectCoversDest();
extern int Inst__swizzleTextureFetchOutput();
extern int Inst__tryCopyPropagate();
extern int Inst__collapseMulSplatByDotOnes();
extern int Inst__collapseAddIntoMadMulAddend();
extern int Inst__collapseAddOfMulToMad();
extern int Inst__collapseMulOfAddWithUnitConstant();
extern int Inst__combineOperandSelects();
extern int Inst__matchOperandPairs();
extern int Inst__mergeSelectsFrom();
extern int Inst__collapseMadOfMulToDot2Add();
extern int Inst__collapseMadWithDot2AddToDot3();
extern int Inst__collapseDot3VectorTimesScaledVector();
extern int Inst__collapseThreeComponentSumToDot3();
extern int Inst__replaceDuplicateInst();
extern int Inst__reassociate_14e6e4();
extern int Inst__swapSharedTermBetweenUses();
extern int Inst__swapMatchedOperandsBetweenUses();
extern int Inst__reassociateUsePair();
extern int Inst__findReassociatePair();
extern int Inst__reassociate_150b94();
extern int Inst__collapseAddOfScaledMov();
extern int Inst__sourceOneMatchesConstant();
extern int Inst__mergeSplatSourceInsts_00151370();
extern int Inst__mergeSplatSourceInsts_00151a74();
extern int Inst__mergeSplatSourceInsts_001524b8();
extern int Inst__mergeAddWithSharedConstant_00152ea8();
extern int Inst__mergeMulWithSharedConstant_001541f0();
extern int Inst__mergeComponentMovsIntoCnd();
extern int Inst__threeSourcesAreRegisters_0015546c();
extern int Inst__mergeMinMaxWithSource_00155654();
extern int Inst__collapseAlgebraic_00155a60();
extern int Inst__destSelectsCompatible();
extern int Inst__collapseAssociativeChain_00156d48();
extern int Inst__distributeSplatOperand_00157b78();
extern int Inst__canShiftTargetField();
extern int Inst__collapseAlgebraic_00158264();
extern int Inst__shiftTargetField();
extern int Inst__shiftTargetFieldFromProducer();
extern int Inst__distributeResultScale();
extern int Inst__foldCndWithConstantCondition();
extern int Inst__normalizeCompareOpcode();
extern int Inst__foldCompareChain_00159b58();
extern int Inst__takeOutCommonFactor();
extern int Inst__foldMovIntoProducer();
extern int Inst__skipSplatChain();
extern int Inst__matchScaledSource();
extern int Inst__mergeAddAndMadSharedOperands();
extern int Inst__collapseAlgebraic_0015c6d4();
extern int Inst__collapseAlgebraic_0015ceb0();
extern int Inst__collapseMulOfExps();
extern undefined4 IRInst__getOtherOperandIfConstant(int param_1,int param_2,undefined4 param_3,undefined4 param_4,double fparam_1);
extern int Inst__collapseClampToSaturate();
extern int Inst__tryMix();
extern int Inst__insertMovForExtraSource_0015f44c();
extern int Inst__foldProducerIntoConsumer();
extern int Inst__foldPowOfConstant();
extern int Inst__mergeSplatSourceInsts_00161748();
extern int Inst__mergeSplatSourceInsts_001621c8();
extern int Inst__collapseIntoExtraSourceDispatch();
extern int Inst__collapseWithChainedSource();
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
extern int Program__findOrInsertEquivalentInst();
extern int Inst__rewriteSourceSelects_00165788();
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
extern int Scheduler__assignTempRegisters();
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
extern int SchedModel__countNodeResources();
extern int ResourceModel__vslot24();
extern int ResourceModel__vslot25();
extern int ResourceModel__vslot29();
extern int ResourceModel__vslot22();
extern int ResourceModel__vslot32();
extern int ResourceModel__vslot11();
extern int Inst__insertMovForOperand();
extern int ThreadModel__vslot4();
extern int ValueKey__anyLaneKeysEqual();
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
extern int ValueKey__producerIsOpcode2aFlagged();
extern int ValueKey__rewriteDuplicateLanesAsMov();
extern int ValueKey__computeSwizzleTo();
extern int SwizzleTable__eqKeys();
extern int ValueKey__propagateLaneValues();
extern int Compiler__findInPtrSet();
extern int Compiler__exprRecordForValueNumber();
extern int ValueKey__canonicalizeCommutativeOperands();
extern int ValueKey__markRegisterLiveInBlock();
extern int ValueKey__allRowsUniform();
extern int IRInst__isCndFloatOp();
extern int ValueKey__eliminateTrivialInst();
extern int ValueKey__tryMergeDestWith();
extern int ValueKey__fillSourceLaneUsage();
extern int ValueKey__init();
extern int ValueKey__initCopy();
extern int IRInst__allOperandsSplat();
extern int ValueKey__laneFlagsAllowDest();
extern int Program__eliminateRedundantInst();
extern int ValueKey__rewriteAsSwizzleMov();
extern int Compiler__valueNumberForExpr();
extern int ValueKey__fill();
extern int ValueKey__rebuild();
extern int ValueKey__simplifyAll();
extern int Compiler__internPointer();
extern int Compiler__findInScopes40c();
extern int Compiler__findInScopes408();
extern int ValueKey__internScopedKey();
extern int ValueKey__markUsesBetweenBlocks();
extern int Compiler__internLaneExpr();
extern int ValueKey__computeLaneFlags();
extern int Compiler__findInScopes404();
extern undefined4 * Compiler__internFloatConstant(int param_1,undefined4 param_2,undefined4 param_3,double fparam_1);
extern int ValueKey__initSourceLaneKinds();
extern int Program__valueNumberInst();
extern int Ptr__equalNonNull();
extern int IROperand__copyRegisterAndSelect();
extern int ValueKey__callTargetHook12c();
extern int noop_1762bc();
extern int Compiler__internLaneExprs1to3();
extern double KhanPs__vslot56_scaleFloat(double fparam_1);
extern int signToCompareCode();
extern undefined4 classifyConstantRange(double fparam_1);
extern int ValueKey__rowLanesAllEqual();
extern int ValueKey__findOrInsertLiteral(undefined4 param_1,int param_2,int param_3,double fparam_1);
extern int ValueKey__sourceWordIs4();
extern int ValueKey__sourceKindIs1();
extern int ValueKey__sourceKindIs4();
extern int ValueKey__compareValueNumbers();
extern int Opcode__isF9();
extern int Opcode__isOneOf1fOr32OrA7A8();
extern int ValueKey__setRowLiteral();
extern int FudoPs__vslot12_lookupTable6x();
extern int FudoPs__vslot11_isNotType2Or5();
extern int ValueKey__markUnsetLanesUnknown();
extern int ValueKey__replaceWithMovIfZero();
extern int ValueKey__allRowsKnown();
extern int ValueKey__rowKnown();
extern int ValueKey__lanesAreUnset();
extern int ValueKey__findKnownRowRecord();
extern int ValueKey__foldCompareLiterals();
extern int ValueKey__getRowLaneValue();
extern int ValueKey__evaluateConstantInst();
extern int ValueKey__evaluateConstantLane();
extern int Compiler__valueNumbersRelatedByFields20();
extern int Compiler__valueNumbersRelatedByFields28();
extern int ValueKey__valueNumbersRelated();
extern int ValueKey__compareClassForValueNumber();
extern int ValueKey__rangeClassForValueNumber();
extern int ValueKey__laneRelationHoldsOnWrittenLanes_176f44();
extern int ValueKey__laneRelationHoldsOnWrittenLanes_176fd4();
extern int Inst__writtenLanesAllMatchValue();
extern int ValueKey__commonLaneValue();
extern int ValueKey__computeLaneRangeClasses();
extern int ValueKey__computeLaneCompareCodes();
extern int ValueKey__sourcesEqualOnWrittenLanes();
extern undefined4 ValueKey__sourceIsSplatOfConstant(int param_1,int param_2,double fparam_1);
extern int ValueKey__flagZeroSelectLanes();
extern int ValueKey__createLaneRecordsKind20();
extern int ValueKey__foldLaneToZeroIfSourcesCancel();
extern int ValueKey__canonicalizeCompareCondition();
extern int ValueKey__createLaneRecordsForScaledOutput();
extern int ValueKey__createLaneRecordsKind28();
extern int ValueKey__cancelNegatedSourcePair();
extern int ValueKey__insertMovOfOperandLane_177b4c();
extern int ValueKey__insertMovOfReplacementLane();
extern int ValueKey__insertBinaryOfOperandsLane();
extern int ValueKey__insertMovOfOperandLane();
extern int ValueKey__evaluateConstantInstruction();
extern int ValueKey__classifyLaneRangeClass();
extern int ValueKey__classifyLaneCompareClass();
extern int IRInst__isOpcode8bOr8c();
extern int ValueKey__sourcesHaveNoModifiers();
extern int ValueKey__sourceSignKnown();
extern int ValueKey__allDotInputsConstant();
extern int ValueKey__singleLaneValueNumber();
extern int ValueKey__dotOperandSplatValue();
extern int ValueKey__evalLitLane();
extern int ValueKey__refreshExprRecordForOperand();
extern int ValueKey__insertTempCopyOfOperand();
extern int ValueKey__operandDefinitionIsFlagBit8();
extern int ValueKey__findLaneWithSameValue();
extern int ValueKey__operandLanesEqual();
extern int ValueKey__forwardSource3LaneIfEqual();
extern int ValueKey__foldCompareSameSourcesValueNumber();
extern int ValueKey__forwardSelectedSourceBySign();
extern int ValueKey__forwardSelectedSourceByPositive();
extern int ValueKey__foldLaneToZeroIfOppositeNegates();
extern int ValueKey__allOperandLanesEqual();
extern int Inst__allWrittenLanesSatisfy();
extern int ValueKey__forwardOtherSourceIfZero();
extern int ValueKey__forwardAddendIfMultiplicandZero();
extern int ValueKey__forwardSource1LaneIfEqual();
extern int ValueKey__forwardOtherSourceIfOne();
extern int ValueKey__forwardOperandByCompareToZero();
extern int ValueKey__setLiteralVec4Operand();
extern int ValueKey__setLiteralOperandsForOpcode();
extern int ValueKey__foldCompareOfFloatConstants();
extern int ValueKey__foldEqualSourcesCompareToLiteralOperands();
extern int ValueKey__foldCompareAgainstZero();
extern int ValueKey__foldDotPowerOfTwoIntoOutputScale();
extern int ValueKey__insertSplatMov();
extern int ValueKey__setOperandFromValueKey();
extern int ValueKey__commonLaneValue_17af58();
extern int ValueKey__sourceDefinedByUniformSelect();
extern int ValueKey__mixLiteralSources();
extern int ValueKey__rewriteUniformSwizzle();
extern int Inst__findLaneProducer();
extern int ValueKey__rewriteAsMovOfOperandLane();
extern int ValueKey__foldDot3SingleLaneSource();
extern int ValueKey__foldDot4UnitVectorSource();
extern int ValueKey__rewriteAsMovOfOperand();
extern int ValueKey__replaceWithSource2IfSourcesEqual23();
extern int ValueKey__foldModifierDifferenceIntoSource2();
extern int ValueKey__foldCompareAgainstZeroToSource();
extern int ValueKey__foldMulByPlusMinusOne();
extern int ValueKey__replaceWithSource1IfSourcesEqual();
extern int ValueKey__foldMinOfConstants();
extern int ValueKey__foldMaxOfConstants();
extern int ValueKey__foldMadZeroMultiplicand();
extern int ValueKey__foldAddOfZeroSource();
extern int ValueKey__rewriteAsMovOfReplacement();
extern int ValueKey__rewriteAsMovOfValueKey();
extern int ValueKey__rewriteAsMovOfVec4Constant();
extern int ValueKey__foldCompareSameSourcesToConstant();
extern int ValueKey__replaceWithZeroIfSourcesEqual();
extern int ValueKey__foldMulByZero();
extern int ValueKey__foldOppositeNegatesToZero();
extern int ValueKey__replaceWithLaneConstants();
extern int ValueKey__foldCompareOfConstants();
extern int ValueKey__evaluateLaneConstants();
extern int ValueKey__rewriteAsMovOfOperandWithScale();
extern int ValueKey__foldMulPowerOfTwoIntoOutputScale();
extern int ValueKey__foldEqualSourcesIntoOutputScale();
extern int ValueKey__rewriteAsBinaryOfOperands();
extern int ValueKey__foldMadZeroAddend();
extern int ValueKey__foldMadByPlusMinusOne();
extern int ValueKey__splitMadIntoMulAdd();
extern int ValueKey__rewriteAsAdd();
extern int ValueKey__foldDotOfSplatsIntoAdd();
extern int ValueKey__foldMulOfConstants();
extern int ValueKey__foldMinMaxOfNegatedPair();
extern int ValueKey__foldMaxOfNegatedPair();
extern int ValueKey__foldMinOfNegatedPair();
extern int ValueKey__splitDestinationToTemp();
extern int ValueKey__splitDestinationIfEligible();
extern int ValueKey__simplifyInstruction();
extern int ValueKey__createLaneRecordsByOpcode();
extern int ValueKey__canonicalizeConstantSources();
extern int ValueKey__simplifyModifiersAndAddressing();
extern int Inst__isFoldableSingleUse();
extern int Inst__compareScheduleSlack();
extern int Pass__recordFlaggedInstructions();
extern int RebuildState__computeNodeLevels();
extern int Block__flattenAndRebuildAddMulTree();
extern int ObjectVector__freeAllElements();
extern int Block__rebuildAddMulTreesWhereProfitable();
extern int pass_height_reduction();
extern int Block__moveProducersBefore();
extern int pass_minreg_order();
extern int compareIntsAscending();
extern int ObjectVector__allSatisfyPredicate24();
extern int Inst__isMulDotWithinLimits();
extern int Inst__splitAndMerge();
extern int IRInst__foldResultScaleIntoUsers();
extern int Inst__tryDp3Add();
extern int Inst__foldProducerIntoOperand();
extern int Inst__mergeSourceInstructions();
extern int Inst__foldSourceProducerIntoConsumer();
extern int Inst__r300ReassociateAddPair();
extern int Inst__foldSelectIntoUsers();
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
extern int Inst__sourceIsConstantRegisterNotKind3();
extern int SchedModel__fitsConstantLimit();
extern int SchedModel__assignConstantSelectors();
extern int R300SchedModel__vslot15();
extern int Inst__computeKey();
extern int Inst__compareForMerge();
extern int SchedModel__classifySlotUse();
extern int R300SchedModel__vslot19();
extern int R300SchedModel__vslot34();
extern int R300SchedModel__vslot26();
extern int R300SchedModel__vslot28();
extern int R300SchedModel__vslot16();
extern int PackNode__clearSlotRangeAndReassign();
extern int R300SchedModel__vslot11();
extern int R300SchedModel__vslot14();
extern int PackState__placeSourcesRecursive();
extern int PackState__buildSlotTable();
extern int PackState__countFreeSlots();
extern int ConstantSlots__tryAddToRow();
extern int ConstantSlots__tryAssignSourceToBothHalves();
extern int ConstantSlots__tryAssignPair();
extern int ConstantSlots__tryAssignSingle();
extern int PackState__tryPlaceInstructionSources();
extern int SchedModel__instructionFitsAlone();
extern int R300SchedModel__tryRewriteConsumerSelects();
extern int R300SchedModel__legalizeInstruction();
extern int R520SchedModel__vslot4_addInstruction();
extern int R520SchedModel__vslot3_canAddInstruction();
extern int R300SchedModel__vslot12();
extern int R300VSchedModel__vslot2_reset();
extern int ConstantSlots__rowsCompatible();
extern int R300VSchedModel__vslot13();
extern int R300VSchedModel__vslot28();
extern int R300VSchedModel__vslot14();
extern int R300VSchedModel__vslot17();
extern int R300VSchedModel__classifySourceBank();
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
extern int Inst__rewriteSetOpcodesWithLiterals();
extern int FudoPs__peepholeCombine();
extern int R520SchedModel__vslot21();
extern int R520SchedModel__vslot22();
extern int FudoPs__vslot29_convertInnerIfsToPredicates();
extern int TypedValueArray__init_193a8c();
extern int TypedValueArray__init();
extern int TypedValueArray__createWrapping();
extern int ArenaObject__freeBuffer();
extern int TypedValueArray__createForType();
extern int Arena__free();
extern int List__freeAllNodes();
extern int Arena__grow();
extern int Arena__alloc();
extern int Arena__allocZeroed();
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
extern int HashTable__remove();
extern int HashTable__find();
extern int HashTableIterator__advance();
extern int HashTableIterator__begin();
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
extern int R300MachineAssembler__emitFetchRecord();
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
extern int DestToken__componentWordMatchesLowFields();
extern int DestToken__componentWordMatchesHighFields();
extern int ilSkipRelativeAddressWords();
extern int ilSourceOperandWordCount();
extern int ilInstructionHeaderWordCount();
extern int ilDestinationOperandWordCount();
extern int Compiler__selectLimitsForShaderKind();
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
extern unsigned char powerOfTenDoubleTable;
extern unsigned char DAT_001aa4b0;
extern unsigned char DAT_001aa4b4;
extern unsigned char DAT_001aa4b8;
extern unsigned char DAT_001aa4bc;
extern unsigned char DAT_001aa4c0;
extern unsigned char programRecordSizeByType;
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
extern unsigned char swizzleXXXX_001aa7fc;
extern unsigned char swizzleXXXX_001aa800;
extern unsigned char swizzleXYZW_001aa804;
extern unsigned char DAT_001aa80c;
extern unsigned char swizzleXXXX_001aa810;
extern unsigned char DAT_001aa818[];
extern unsigned char DAT_001aa838;
extern unsigned char DAT_001aa83c;
extern unsigned char DAT_001aa840;
extern unsigned char swizzleYYYX_001aa850;
extern unsigned char swizzleYYXY_001aa854;
extern unsigned char swizzleYXYY_001aa858;
extern unsigned char swizzleXYYY_001aa85c;
extern unsigned char swizzleXXXX_001aa860;
extern unsigned char swizzleXYZW_001aa868;
extern unsigned char DAT_001aa86c;
extern unsigned char DAT_001aa87c;
extern unsigned char swizzleXYZW_001aa9a8;
extern unsigned char DAT_001aa9cc;
extern unsigned char DAT_001aa9d0;
extern unsigned char swizzleXXXX_001aa9dc;
extern unsigned char DAT_001aa9e0;
extern unsigned char DAT_001aa9e4;
extern unsigned char DAT_001aa9fc;
extern unsigned char DAT_001ab134;
extern unsigned char textPrintDoubleShortest_pow10Table;
extern unsigned char DAT_001ac5a4;
extern unsigned char DAT_001acec0;
extern unsigned char DAT_001ad5d8;
extern unsigned char swizzleXYZW_001af9bc;
extern unsigned char DAT_001af9c0;
extern unsigned char swizzleAllUnused_001af9c4;
extern unsigned char DAT_001af9c8;
extern unsigned char DAT_001af9cc;
extern unsigned char DAT_001af9d0;
extern unsigned char swizzleXYYY_001af9dc;
extern unsigned char DAT_001af9e0;
extern unsigned char DAT_001af9ec;
extern unsigned char swizzleAllUnused_001af9fc;
extern unsigned char DAT_001afa04;
extern unsigned char DAT_001afa08;
extern unsigned char DAT_001afa0c;
extern unsigned char DAT_001afa14;
extern unsigned char DAT_001afa18;
extern unsigned char DAT_001afee4;
extern unsigned char DAT_001afee8;
extern unsigned char swizzleXXXX_001afeec;
extern unsigned char DAT_001afef0;
extern unsigned char DAT_001afef8;
extern unsigned char DAT_001aff08;
extern unsigned char DAT_001aff0c;
extern unsigned char swizzleXXXX_001aff48;
extern unsigned char DAT_001aff4c;
extern unsigned char DAT_001aff50;
extern unsigned char DAT_001aff68;
extern unsigned char DAT_001aff74;
extern unsigned char DAT_001aff9c;
extern unsigned char swizzleWWWW_001affa4;
extern unsigned char DAT_001affb0;
extern unsigned char DAT_001affb8;
extern unsigned char DAT_001affc0;
extern unsigned char DAT_001affc4;
extern unsigned char DAT_001affc8;
extern unsigned char DAT_001affcc;
extern unsigned char DAT_001afffc;
extern unsigned char swizzleAllUnused_001b0000;
extern unsigned char swizzleXYZW_001b0004;
extern unsigned char DAT_001b0008;
extern unsigned char DAT_001b0014;
extern unsigned char DAT_001b001c;
extern unsigned char DAT_001b0020;
extern unsigned char swizzleAllUnused_001b0038;
extern unsigned char swizzleXYZW_001b003c;
extern unsigned char DAT_001b0040;
extern unsigned char swizzleYYYY_001b0044;
extern unsigned char swizzleYYYY_001b0048;
extern unsigned char DAT_001b004c;
extern unsigned char swizzleAllUnused_001b0050;
extern unsigned char swizzleYYYX_001b0054;
extern unsigned char swizzleXYYY_001b0058;
extern unsigned char swizzleXXXX_001b005c;
extern unsigned char DAT_001b0060;
extern unsigned char DAT_001b0160;
extern unsigned char DAT_001b0170;
extern unsigned char swizzleYYYY_001b0194;
extern unsigned char swizzleYYYY_001b0198;
extern unsigned char swizzleAllUnused_001b01a0;
extern unsigned char DAT_001b01a8;
extern unsigned char DAT_001b01ac;
extern unsigned char DAT_001b01b0;
extern unsigned char DAT_001b01b4;
extern unsigned char swizzleAllUnused_001b01b8;
extern unsigned char DAT_001b01bc;
extern unsigned char DAT_001b01d0;
extern unsigned char swizzleXYZW_001b01d8;
extern unsigned char swizzleAllUnused_001b01dc;
extern unsigned char DAT_001b01e0;
extern unsigned char DAT_001b01e8;
extern unsigned char DAT_001b01ec;
extern unsigned char DAT_001b01f0;
extern unsigned char DAT_001b01f4;
extern unsigned char swizzleYYYX_001b0210;
extern unsigned char DAT_001b0214;
extern unsigned char DAT_001b0218;
extern unsigned char DAT_001b021c;
extern unsigned char swizzleXYZW_001b0220;
extern unsigned char swizzleAllUnused_001b0224;
extern unsigned char DAT_001b0228;
extern unsigned char DAT_001b0240;
extern unsigned char DAT_001b0244;
extern unsigned char DAT_001b02ec;
extern unsigned char DAT_001b19e0;
extern unsigned char DAT_001b2994;
extern unsigned char swizzleXYZW_001b2a64;
extern unsigned char swizzleAllUnused_001b2a68;
extern unsigned char DAT_001b2a80;
extern unsigned char DAT_001b2a84;
extern unsigned char swizzleZZZZ_001b2ab4;
extern unsigned char swizzleYYYY_001b2ab8;
extern unsigned char swizzleXXXX_001b2abc;
extern unsigned char swizzleXYZW_001b2ac0;
extern unsigned char swizzleWWWW_001b2ac4;
extern unsigned char DAT_001b2ad0;
extern unsigned char DAT_001b2be8;
extern unsigned char DAT_001b2c14;
extern unsigned char swizzleWWWW_001b2d4c;
extern unsigned char swizzleYYYX_001b2d50;
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
extern unsigned char irInstFactoryTable;
extern unsigned char DAT_001ea500;
extern unsigned char regKindInfo_flagsWord;
extern unsigned char regKindInfo_byte4[];
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
extern unsigned char IrImmedConstLoad__opcodeInfo_guard;
extern unsigned char IrImmedConstBuffer__opcodeInfo_guard;
extern unsigned char IrGetResource__opcodeInfo_guard;
extern unsigned char IrEmitThenCut__opcodeInfo_guard;
extern unsigned char IrDyamicReturnSwitch__opcodeInfo_guard;
extern unsigned char IrCut__opcodeInfo_guard;
extern unsigned char IrLdBuffer__opcodeInfo_guard;
extern unsigned char IrSampleG__opcodeInfo_guard;
extern unsigned char IrSampleCLZ__opcodeInfo_guard;
extern unsigned char IrSampleL__opcodeInfo_guard;
extern unsigned char IrSampleC__opcodeInfo_guard;
extern unsigned char IrFetchLoad__opcodeInfo_guard;
extern unsigned char IrCbLoad__opcodeInfo_guard;
extern unsigned char IrWhileStart__opcodeInfo_guard;
extern unsigned char IrScratchStore__opcodeInfo_guard;
extern unsigned char IrScratchLoad__opcodeInfo_guard;
extern unsigned char IrMemInit__opcodeInfo_guard;
extern unsigned char IrDyamicReturn__opcodeInfo_guard;
extern unsigned char IrEmit__opcodeInfo_guard;
extern unsigned char IrPsColorFog__opcodeInfo_guard;
extern unsigned char IrMulLit__opcodeInfo_guard;
extern unsigned char IrNotInt__opcodeInfo_guard;
extern unsigned char IrXorInt__opcodeInfo_guard;
extern unsigned char IrOrInt__opcodeInfo_guard;
extern unsigned char IrAndInt__opcodeInfo_guard;
extern unsigned char IrRoundNearestEven__opcodeInfo_guard;
extern unsigned char IrCeil__opcodeInfo_guard;
extern unsigned char IrSetNE_Dx10__opcodeInfo_guard;
extern unsigned char IrSetGE_Dx10__opcodeInfo_guard;
extern unsigned char IrSetE_Dx10__opcodeInfo_guard;
extern unsigned char IrFetchShaderCall__opcodeInfo_guard;
extern unsigned char IrScatter__opcodeInfo_guard;
extern unsigned char IrCmovNE__opcodeInfo_guard;
extern unsigned char IrCmovGT__opcodeInfo_guard;
extern unsigned char IrCmovGE__opcodeInfo_guard;
extern unsigned char IrCmovEQ__opcodeInfo_guard;
extern unsigned char IrFetchTextureUncached__opcodeInfo_guard;
extern unsigned char IrFetchTextureLOD__opcodeInfo_guard;
extern unsigned char IrCndGEInt__opcodeInfo_guard;
extern unsigned char IrCndGE1__opcodeInfo_guard;
extern unsigned char IrCndGE__opcodeInfo_guard;
extern unsigned char IrCndGEFloat__opcodeInfo_guard;
extern unsigned char IrMad__opcodeInfo_guard;
extern unsigned char IrR300ExpBaseE__opcodeInfo_guard;
extern unsigned char IrDxLogp__opcodeInfo_guard;
extern unsigned char IrR300Expp__opcodeInfo_guard;
extern unsigned char IrPow__opcodeInfo_guard;
extern unsigned char IrLoad__opcodeInfo_guard;
extern unsigned char IrDp3Add__opcodeInfo_guard;
extern unsigned char IrMix__opcodeInfo_guard;
extern unsigned char IrDsy1__opcodeInfo_guard;
extern unsigned char IrDsy__opcodeInfo_guard;
extern unsigned char IrDsx1__opcodeInfo_guard;
extern unsigned char IrDsx__opcodeInfo_guard;
extern unsigned char IrCnd05__opcodeInfo_guard;
extern unsigned char IrPresubInvert__opcodeInfo_guard;
extern unsigned char IrPresubAdd__opcodeInfo_guard;
extern unsigned char IrPresubSub__opcodeInfo_guard;
extern unsigned char IrPresubBX2Neg__opcodeInfo_guard;
extern unsigned char IrOpSop__opcodeInfo_guard;
extern unsigned char IrOpDp__opcodeInfo_guard;
extern unsigned char IrAllocInterp__opcodeInfo_guard;
extern unsigned char IrAllocColor__opcodeInfo_guard;
extern unsigned char IrAllocMem__opcodeInfo_guard;
extern unsigned char IrAllocPos__opcodeInfo_guard;
extern unsigned char IrEndMakeCall__opcodeInfo_guard;
extern unsigned char IrEndCall__opcodeInfo_guard;
extern unsigned char IrStartMakeCall__opcodeInfo_guard;
extern unsigned char IrStartCallRoutine__opcodeInfo_guard;
extern unsigned char IrPhi__opcodeInfo_guard;
extern unsigned char IrCmp1S__opcodeInfo_guard;
extern unsigned char IrCmp1D__opcodeInfo_guard;
extern unsigned char IrCmp2__opcodeInfo_guard;
extern unsigned char IrEpilog__opcodeInfo_guard;
extern unsigned char IrProlog__opcodeInfo_guard;
extern unsigned char IrExit__opcodeInfo_guard;
extern unsigned char IrEntry__opcodeInfo_guard;
extern unsigned char IrHeader__opcodeInfo_guard;
extern unsigned char IrUndefined__opcodeInfo_guard;
extern unsigned char IrProjection__opcodeInfo_guard;
extern unsigned char IrMerge__opcodeInfo_guard;
extern unsigned char IrLoopStart__opcodeInfo_001fb464_guard;
extern unsigned char IrLoopStart__opcodeInfo_guard;
extern unsigned char IrPixelLoopFetch__opcodeInfo_guard;
extern unsigned char IrVertexLoopFetch__opcodeInfo_guard;
extern unsigned char IrLoadInterp__opcodeInfo_guard;
extern unsigned char IrLoadTempDefault__opcodeInfo_guard;
extern unsigned char IrLoadAbstractState__opcodeInfo_guard;
extern unsigned char IrLoadPhysical__opcodeInfo_guard;
extern unsigned char IrLoadTemp__opcodeInfo_guard;
extern unsigned char IrLoadConst__opcodeInfo_guard;
extern unsigned char IrMovaFloorInt__opcodeInfo_guard;
extern unsigned char IrMovaFloorGprInt__opcodeInfo_guard;
extern unsigned char IrMovaFloorFloat__opcodeInfo_guard;
extern unsigned char IrMovaFlr__opcodeInfo_guard;
extern unsigned char IrMovaFloor__opcodeInfo_guard;
extern unsigned char IrSubPrev__opcodeInfo_guard;
extern unsigned char IrMulPrev2__opcodeInfo_guard;
extern unsigned char IrMulPrev__opcodeInfo_guard;
extern unsigned char IrAddPrev__opcodeInfo_guard;
extern unsigned char IrPredSetRst__opcodeInfo_guard;
extern unsigned char IrPredSetClr__opcodeInfo_guard;
extern unsigned char IrPredSetPop__opcodeInfo_guard;
extern unsigned char IrPredSetInv__opcodeInfo_guard;
extern unsigned char IrPredSetGEInt__opcodeInfo_guard;
extern unsigned char IrPredSetGE__opcodeInfo_guard;
extern unsigned char IrPredSetLEInt__opcodeInfo_guard;
extern unsigned char IrPredSetLTInt__opcodeInfo_guard;
extern unsigned char IrPredSetGTInt__opcodeInfo_guard;
extern unsigned char IrPredSetGT__opcodeInfo_guard;
extern unsigned char IrPredSetNEInt__opcodeInfo_guard;
extern unsigned char IrPredSetNE__opcodeInfo_guard;
extern unsigned char IrPredSetEInt__opcodeInfo_guard;
extern unsigned char IrPredSetE__opcodeInfo_guard;
extern unsigned char IrKillOne__opcodeInfo_guard;
extern unsigned char IrCos__opcodeInfo_guard;
extern unsigned char IrSin__opcodeInfo_guard;
extern unsigned char IrSubConst1__opcodeInfo_guard;
extern unsigned char IrMulConst1__opcodeInfo_guard;
extern unsigned char IrAddConst1__opcodeInfo_guard;
extern unsigned char IrSubConst0__opcodeInfo_guard;
extern unsigned char IrMulConst0__opcodeInfo_guard;
extern unsigned char IrAddConst0__opcodeInfo_guard;
extern unsigned char IrFetchTextureMapGradients__opcodeInfo_guard;
extern unsigned char IrFetchTextureMapKill__opcodeInfo_guard;
extern unsigned char IrFetchTextureMapBias__opcodeInfo_guard;
extern unsigned char IrFetchTextureMapProj__opcodeInfo_guard;
extern unsigned char IrSetFilter4Weights__opcodeInfo_guard;
extern unsigned char IrSetGradientsV__opcodeInfo_guard;
extern unsigned char IrSetGradientsH__opcodeInfo_guard;
extern unsigned char IrSetTexLod__opcodeInfo_guard;
extern unsigned char IrGetWeights__opcodeInfo_guard;
extern unsigned char IrGetGradients__opcodeInfo_guard;
extern unsigned char IrGetCompTexLod__opcodeInfo_guard;
extern unsigned char IrGetBorderColorFraction__opcodeInfo_guard;
extern unsigned char IrFetchMultiSample__opcodeInfo_guard;
extern unsigned char IrFetchShadowMap__opcodeInfo_guard;
extern unsigned char IrFetch3DNoiseMap__opcodeInfo_guard;
extern unsigned char IrFetchTextureMap__opcodeInfo_guard;
extern unsigned char IrFetchVertex__opcodeInfo_guard;
extern unsigned char IrSqrt__opcodeInfo_guard;
extern unsigned char IrRecipSqrtIEEE__opcodeInfo_guard;
extern unsigned char IrRecipSqrtFF__opcodeInfo_guard;
extern unsigned char IrRecipSqrtClamp__opcodeInfo_guard;
extern unsigned char IrLogIEEE__opcodeInfo_guard;
extern unsigned char IrLogClamp__opcodeInfo_guard;
extern unsigned char IrExp__opcodeInfo_guard;
extern unsigned char IrSub__opcodeInfo_guard;
extern unsigned char IrNop1__opcodeInfo_guard;
extern unsigned char IrNop__opcodeInfo_guard;
extern unsigned char IrLit__opcodeInfo_guard;
extern unsigned char IrMov__opcodeInfo_guard;
extern unsigned char IrMovFloat__opcodeInfo_guard;
extern unsigned char IrExportRing__opcodeInfo_guard;
extern unsigned char IrExport__opcodeInfo_guard;
extern unsigned char IrExportFloat__opcodeInfo_guard;
extern unsigned char IrPredSetGEPushInt__opcodeInfo_guard;
extern unsigned char IrPredSetGEPush__opcodeInfo_guard;
extern unsigned char IrPredSetGTPushInt__opcodeInfo_guard;
extern unsigned char IrPredSetGTPush__opcodeInfo_guard;
extern unsigned char IrPredSetNEPushInt__opcodeInfo_guard;
extern unsigned char IrPredSetNEPush__opcodeInfo_guard;
extern unsigned char IrPredSetLEPushInt__opcodeInfo_guard;
extern unsigned char IrPredSetLTPushInt__opcodeInfo_guard;
extern unsigned char IrPredSetEPushInt__opcodeInfo_guard;
extern unsigned char IrPredSetEPush__opcodeInfo_guard;
extern unsigned char IrMovaRound__opcodeInfo_guard;
extern unsigned char IrMovaRoundFloat__opcodeInfo_guard;
extern unsigned char IrSetNEInt__opcodeInfo_guard;
extern unsigned char IrSetNE__opcodeInfo_guard;
extern unsigned char IrSetNEFloat__opcodeInfo_guard;
extern unsigned char IrSetGE_uint__opcodeInfo_guard;
extern unsigned char IrSetGEInt__opcodeInfo_guard;
extern unsigned char IrSetGE__opcodeInfo_guard;
extern unsigned char IrSetGEFloat__opcodeInfo_guard;
extern unsigned char IrSetGTUint__opcodeInfo_guard;
extern unsigned char IrSetGTInt__opcodeInfo_guard;
extern unsigned char IrSetGTDx10__opcodeInfo_guard;
extern unsigned char IrSetGT__opcodeInfo_guard;
extern unsigned char IrSetGTFloat__opcodeInfo_guard;
extern unsigned char IrSetEInt__opcodeInfo_guard;
extern unsigned char IrSetE__opcodeInfo_guard;
extern unsigned char IrSetEFloat__opcodeInfo_guard;
extern unsigned char IrCndGT1__opcodeInfo_guard;
extern unsigned char IrCndGTInt__opcodeInfo_guard;
extern unsigned char IrCndGT__opcodeInfo_guard;
extern unsigned char IrCndGTFloat__opcodeInfo_guard;
extern unsigned char IrCndE1__opcodeInfo_guard;
extern unsigned char IrCndEInt__opcodeInfo_guard;
extern unsigned char IrCndE__opcodeInfo_guard;
extern unsigned char IrCndEFloat__opcodeInfo_guard;
extern unsigned char IrKillNE__opcodeInfo_guard;
extern unsigned char IrKillNEFloat__opcodeInfo_guard;
extern unsigned char IrKillGE__opcodeInfo_guard;
extern unsigned char IrKillGEFloat__opcodeInfo_guard;
extern unsigned char IrKillGT__opcodeInfo_guard;
extern unsigned char IrKillGTFloat__opcodeInfo_guard;
extern unsigned char IrKillE__opcodeInfo_guard;
extern unsigned char IrKillEFloat__opcodeInfo_guard;
extern unsigned char IrDst__opcodeInfo_guard;
extern unsigned char IrDot2Add__opcodeInfo_001fbdb0_guard;
extern unsigned char IrDot2Add__opcodeInfo_guard;
extern unsigned char IrDot4IEEE__opcodeInfo_guard;
extern unsigned char IrDot4__opcodeInfo_guard;
extern unsigned char IrMulHiUInt__opcodeInfo_guard;
extern unsigned char IrMulLowUInt__opcodeInfo_guard;
extern unsigned char IrMulHiInt__opcodeInfo_guard;
extern unsigned char IrMulLowInt__opcodeInfo_guard;
extern unsigned char IrLshlInt__opcodeInfo_guard;
extern unsigned char IrLshrInt__opcodeInfo_guard;
extern unsigned char IrAshrInt__opcodeInfo_guard;
extern unsigned char IrUInt2F__opcodeInfo_guard;
extern unsigned char IrInt2F__opcodeInfo_guard;
extern unsigned char IrF2UInt__opcodeInfo_guard;
extern unsigned char IrF2Int__opcodeInfo_guard;
extern unsigned char IrDot3IEEE__opcodeInfo_guard;
extern unsigned char IrDot3__opcodeInfo_guard;
extern unsigned char IrCube__opcodeInfo_guard;
extern unsigned char IrTrunc__opcodeInfo_guard;
extern unsigned char IrTruncFloat__opcodeInfo_guard;
extern unsigned char IrRecipUInt__opcodeInfo_guard;
extern unsigned char IrRecipInt__opcodeInfo_guard;
extern unsigned char IrRecipIEEE__opcodeInfo_guard;
extern unsigned char IrRecipFF__opcodeInfo_guard;
extern unsigned char IrRecipClamp__opcodeInfo_guard;
extern unsigned char IrMinDx10__opcodeInfo_guard;
extern unsigned char IrMinUInt__opcodeInfo_guard;
extern unsigned char IrMinInt__opcodeInfo_guard;
extern unsigned char IrMin__opcodeInfo_guard;
extern unsigned char IrMinFloat__opcodeInfo_guard;
extern unsigned char IrMax4__opcodeInfo_guard;
extern unsigned char IrMaxDx10__opcodeInfo_guard;
extern unsigned char IrMax__opcodeInfo_guard;
extern unsigned char IrMaxUInt__opcodeInfo_guard;
extern unsigned char IrMaxInt__opcodeInfo_guard;
extern unsigned char IrMaxFloat__opcodeInfo_guard;
extern unsigned char IrFract__opcodeInfo_guard;
extern unsigned char IrFractFloat__opcodeInfo_guard;
extern unsigned char IrFloor__opcodeInfo_guard;
extern unsigned char IrFloorFloat__opcodeInfo_guard;
extern unsigned char IrMulAddIEEE__opcodeInfo_guard;
extern unsigned char IrMulAdd__opcodeInfo_guard;
extern unsigned char IrMulAddFloat__opcodeInfo_guard;
extern unsigned char IrMul__opcodeInfo_001fc10c_guard;
extern unsigned char IrMul__opcodeInfo_guard;
extern unsigned char IrMulFloat__opcodeInfo_guard;
extern unsigned char IrSubInt__opcodeInfo_guard;
extern unsigned char IrAddInt__opcodeInfo_guard;
extern unsigned char IrAdd__opcodeInfo_guard;
extern unsigned char IrAddFloat__opcodeInfo_guard;
extern unsigned char IrAlloc__opcodeInfo_guard;
extern unsigned char IrCondJmp__opcodeInfo_guard;
extern unsigned char IrRet__opcodeInfo_guard;
extern unsigned char IrImmedConstLoad__opcodeInfo;
/* issue #76 (supersedes/widens the earlier issue #75 descriptor-arena fix): the real arena
 * of 20-byte "format descriptor" records is BIGGER than first measured - re-scanning
 * part_036.c's own descriptor-base assignments (`DAT_xxx = PTR_DAT_yyy + 8;`) end to end finds
 * 252 records spanning 0x1fae10 to 0x1fc1d3 (5060 bytes), not the ~4100-byte subset
 * originally covered. Confirmed live: a second, different descriptor (for pixel format index
 * 19, reached via a post-CGLCreateContext call path) showed the exact same truncated-byte
 * symptom (0x13000000 instead of 0x13) at IrMulFloat__opcodeInfo_opcode, which sits past the old fix's upper
 * bound. Re-anchored the whole merge on IrImmedConstLoad__opcodeInfo (the arena's true lowest address) and folded
 * every symbol in the wider range - including the old anchor IrRoundNearestEven__opcodeInfo itself, now just
 * another slot - into one backing array via the same offset-preserving macro technique. */
#define IrImmedConstLoad__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 8))
#define IrImmedConstLoad__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 12))
#define IrImmedConstLoad__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 16))
#define IrImmedConstBuffer__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 20))
#define IrImmedConstBuffer__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 28))
#define IrImmedConstBuffer__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 32))
#define IrImmedConstBuffer__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 36))
#define IrGetResource__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 40))
#define IrGetResource__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 48))
#define IrGetResource__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 52))
#define IrGetResource__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 56))
#define IrEmitThenCut__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 60))
#define IrEmitThenCut__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 68))
#define IrEmitThenCut__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 72))
#define IrEmitThenCut__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 76))
#define IrDyamicReturnSwitch__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 80))
#define IrDyamicReturnSwitch__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 88))
#define IrDyamicReturnSwitch__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 92))
#define IrDyamicReturnSwitch__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 96))
#define IrCut__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 100))
#define IrCut__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 108))
#define IrCut__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 112))
#define IrCut__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 116))
#define IrLdBuffer__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 120))
#define IrLdBuffer__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 128))
#define IrLdBuffer__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 132))
#define IrLdBuffer__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 136))
#define IrSampleG__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 140))
#define IrSampleG__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 148))
#define IrSampleG__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 152))
#define IrSampleG__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 156))
#define IrSampleCLZ__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 160))
#define IrSampleCLZ__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 168))
#define IrSampleCLZ__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 172))
#define IrSampleCLZ__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 176))
#define IrSampleL__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 180))
#define IrSampleL__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 188))
#define IrSampleL__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 192))
#define IrSampleL__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 196))
#define IrSampleC__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 200))
#define IrSampleC__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 208))
#define IrSampleC__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 212))
#define IrSampleC__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 216))
#define IrFetchLoad__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 220))
#define IrFetchLoad__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 228))
#define IrFetchLoad__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 232))
#define IrFetchLoad__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 236))
#define IrCbLoad__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 240))
#define IrCbLoad__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 248))
#define IrCbLoad__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 252))
#define IrCbLoad__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 256))
#define IrWhileStart__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 260))
#define IrWhileStart__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 268))
#define IrWhileStart__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 272))
#define IrWhileStart__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 276))
#define IrScratchStore__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 280))
#define IrScratchStore__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 288))
#define IrScratchStore__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 292))
#define IrScratchStore__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 296))
#define IrScratchLoad__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 300))
#define IrScratchLoad__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 308))
#define IrScratchLoad__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 312))
#define IrScratchLoad__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 316))
#define IrMemInit__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 320))
#define IrMemInit__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 328))
#define IrMemInit__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 332))
#define IrMemInit__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 336))
#define IrDyamicReturn__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 340))
#define IrDyamicReturn__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 348))
#define IrDyamicReturn__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 352))
#define IrDyamicReturn__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 356))
#define IrEmit__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 360))
#define IrEmit__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 368))
#define IrEmit__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 372))
#define IrEmit__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 376))
#define IrPsColorFog__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 380))
#define IrPsColorFog__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 388))
#define IrPsColorFog__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 392))
#define IrPsColorFog__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 396))
#define IrMulLit__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 400))
#define IrMulLit__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 408))
#define IrMulLit__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 412))
#define IrMulLit__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 416))
#define IrNotInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 420))
#define IrNotInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 428))
#define IrNotInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 432))
#define IrNotInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 436))
#define IrXorInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 440))
#define IrXorInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 448))
#define IrXorInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 452))
#define IrXorInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 456))
#define IrOrInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 460))
#define IrOrInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 468))
#define IrOrInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 472))
#define IrOrInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 476))
#define IrAndInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 480))
#define IrAndInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 488))
#define IrAndInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 492))
#define IrAndInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 496))
#define IrRoundNearestEven__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 500))
/* issue #75 (follow-up #2, generalized): part_036.c populates a 4100-byte arena of 205
 * "format descriptor" records (20 bytes each: IrRoundNearestEven__opcodeInfo through IrMinFloat__opcodeInfo_word10), writing each
 * record's fields (a base pointer at +0, plus int fields at +8/+0xc/+0x10 - e.g.
 * `IrEntry__opcodeInfo_opcode = 0x87;`) via Ghidra-derived individual symbol names, one per referenced
 * offset - not as one real C array/struct. Every one of these 820 names was its own
 * INDEPENDENT `.zerofill` symbol, so our own linker had no reason to place them adjacently or
 * in the original relative order (same root cause as the check_cxa_atexit stack-locals bug and the
 * opcodeInfoTable array above, just at a much larger scale). Confirmed live: the very first
 * descriptor this driver actually reads (IrEntry__opcodeInfo+8, format index 135) came back as
 * 0x87000000 instead of 0x87 (a stray high byte from unrelated memory), and after fixing only
 * that one descriptor in isolation, IrEntry__opcodeInfo's OWN base-pointer field then read back as
 * 0x08000000 garbage too - a DIFFERENT descriptor's oversized/misplaced write bleeding across
 * our own linker's arbitrary layout. Fixing one descriptor at a time was chasing a moving
 * target, so this fixes the whole arena at once: IrRoundNearestEven__opcodeInfo (the arena's first record) stays
 * the one real scalar declaration, with its data.s zerofill enlarged to cover all 4100 bytes,
 * and every other name in the arena becomes a macro reading/writing the correct 4-byte slot
 * inside that single backing allocation. */
#define IrRoundNearestEven__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 8))
#define IrRoundNearestEven__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 12))
#define IrRoundNearestEven__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 16))
#define IrCeil__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 20))
#define IrCeil__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 28))
#define IrCeil__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 32))
#define IrCeil__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 36))
#define IrSetNE_Dx10__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 40))
#define IrSetNE_Dx10__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 48))
#define IrSetNE_Dx10__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 52))
#define IrSetNE_Dx10__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 56))
#define IrSetGE_Dx10__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 60))
#define IrSetGE_Dx10__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 68))
#define IrSetGE_Dx10__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 72))
#define IrSetGE_Dx10__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 76))
#define IrSetE_Dx10__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 80))
#define IrSetE_Dx10__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 88))
#define IrSetE_Dx10__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 92))
#define IrSetE_Dx10__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 96))
#define IrFetchShaderCall__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 100))
#define IrFetchShaderCall__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 108))
#define IrFetchShaderCall__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 112))
#define IrFetchShaderCall__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 116))
#define IrScatter__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 120))
#define IrScatter__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 128))
#define IrScatter__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 132))
#define IrScatter__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 136))
#define IrCmovNE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 140))
#define IrCmovNE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 148))
#define IrCmovNE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 152))
#define IrCmovNE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 156))
#define IrCmovGT__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 160))
#define IrCmovGT__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 168))
#define IrCmovGT__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 172))
#define IrCmovGT__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 176))
#define IrCmovGE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 180))
#define IrCmovGE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 188))
#define IrCmovGE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 192))
#define IrCmovGE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 196))
#define IrCmovEQ__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 200))
#define IrCmovEQ__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 208))
#define IrCmovEQ__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 212))
#define IrCmovEQ__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 216))
#define IrFetchTextureUncached__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 220))
#define IrFetchTextureUncached__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 228))
#define IrFetchTextureUncached__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 232))
#define IrFetchTextureUncached__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 236))
#define IrFetchTextureLOD__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 240))
#define IrFetchTextureLOD__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 248))
#define IrFetchTextureLOD__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 252))
#define IrFetchTextureLOD__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 256))
#define IrCndGEInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 260))
#define IrCndGEInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 268))
#define IrCndGEInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 272))
#define IrCndGEInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 276))
#define IrCndGE1__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 280))
#define IrCndGE1__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 288))
#define IrCndGE1__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 292))
#define IrCndGE1__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 296))
#define IrCndGE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 300))
#define IrCndGE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 308))
#define IrCndGE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 312))
#define IrCndGE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 316))
#define IrCndGEFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 320))
#define IrCndGEFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 328))
#define IrCndGEFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 332))
#define IrCndGEFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 336))
#define IrMad__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 340))
#define IrMad__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 348))
#define IrMad__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 352))
#define IrMad__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 356))
#define IrR300ExpBaseE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 360))
#define IrR300ExpBaseE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 368))
#define IrR300ExpBaseE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 372))
#define IrR300ExpBaseE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 376))
#define IrDxLogp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 380))
#define IrDxLogp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 388))
#define IrDxLogp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 392))
#define IrDxLogp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 396))
#define IrR300Expp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 400))
#define IrR300Expp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 408))
#define IrR300Expp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 412))
#define IrR300Expp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 416))
#define IrPow__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 420))
#define IrPow__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 428))
#define IrPow__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 432))
#define IrPow__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 436))
#define IrLoad__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 440))
#define IrLoad__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 448))
#define IrLoad__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 452))
#define IrLoad__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 456))
#define IrDp3Add__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 460))
#define IrDp3Add__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 468))
#define IrDp3Add__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 472))
#define IrDp3Add__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 476))
#define IrMix__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 480))
#define IrMix__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 488))
#define IrMix__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 492))
#define IrMix__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 496))
#define IrDsy1__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 500))
#define IrDsy1__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 508))
#define IrDsy1__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 512))
#define IrDsy1__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 516))
#define IrDsy__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 520))
#define IrDsy__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 528))
#define IrDsy__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 532))
#define IrDsy__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 536))
#define IrDsx1__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 540))
#define IrDsx1__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 548))
#define IrDsx1__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 552))
#define IrDsx1__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 556))
#define IrDsx__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 560))
#define IrDsx__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 568))
#define IrDsx__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 572))
#define IrDsx__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 576))
#define IrCnd05__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 580))
#define IrCnd05__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 588))
#define IrCnd05__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 592))
#define IrCnd05__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 596))
#define IrPresubInvert__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 600))
#define IrPresubInvert__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 608))
#define IrPresubInvert__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 612))
#define IrPresubInvert__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 616))
#define IrPresubAdd__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 620))
#define IrPresubAdd__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 628))
#define IrPresubAdd__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 632))
#define IrPresubAdd__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 636))
#define IrPresubSub__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 640))
#define IrPresubSub__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 648))
#define IrPresubSub__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 652))
#define IrPresubSub__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 656))
#define IrPresubBX2Neg__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 660))
#define IrPresubBX2Neg__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 668))
#define IrPresubBX2Neg__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 672))
#define IrPresubBX2Neg__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 676))
#define IrOpSop__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 680))
#define IrOpSop__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 688))
#define IrOpSop__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 692))
#define IrOpSop__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 696))
#define IrOpDp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 700))
#define IrOpDp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 708))
#define IrOpDp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 712))
#define IrOpDp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 716))
#define IrAllocInterp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 720))
#define IrAllocInterp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 728))
#define IrAllocInterp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 732))
#define IrAllocInterp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 736))
#define IrAllocColor__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 740))
#define IrAllocColor__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 748))
#define IrAllocColor__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 752))
#define IrAllocColor__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 756))
#define IrAllocMem__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 760))
#define IrAllocMem__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 768))
#define IrAllocMem__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 772))
#define IrAllocMem__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 776))
#define IrAllocPos__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 780))
#define IrAllocPos__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 788))
#define IrAllocPos__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 792))
#define IrAllocPos__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 796))
#define IrEndMakeCall__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 800))
#define IrEndMakeCall__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 808))
#define IrEndMakeCall__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 812))
#define IrEndMakeCall__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 816))
#define IrEndCall__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 820))
#define IrEndCall__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 828))
#define IrEndCall__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 832))
#define IrEndCall__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 836))
#define IrStartMakeCall__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 840))
#define IrStartMakeCall__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 848))
#define IrStartMakeCall__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 852))
#define IrStartMakeCall__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 856))
#define IrStartCallRoutine__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 860))
#define IrStartCallRoutine__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 868))
#define IrStartCallRoutine__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 872))
#define IrStartCallRoutine__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 876))
#define IrPhi__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 880))
#define IrPhi__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 888))
#define IrPhi__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 892))
#define IrPhi__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 896))
#define IrCmp1S__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 900))
#define IrCmp1S__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 908))
#define IrCmp1S__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 912))
#define IrCmp1S__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 916))
#define IrCmp1D__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 920))
#define IrCmp1D__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 928))
#define IrCmp1D__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 932))
#define IrCmp1D__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 936))
#define IrCmp2__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 940))
#define IrCmp2__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 948))
#define IrCmp2__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 952))
#define IrCmp2__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 956))
#define IrEpilog__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 960))
#define IrEpilog__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 968))
#define IrEpilog__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 972))
#define IrEpilog__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 976))
#define IrProlog__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 980))
#define IrProlog__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 988))
#define IrProlog__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 992))
#define IrProlog__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 996))
#define IrExit__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1000))
#define IrExit__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1008))
#define IrExit__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1012))
#define IrExit__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1016))
#define IrEntry__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1020))
#define IrEntry__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1028))
#define IrEntry__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1032))
#define IrEntry__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1036))
#define IrHeader__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1040))
#define IrHeader__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1048))
#define IrHeader__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1052))
#define IrHeader__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1056))
#define IrUndefined__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1060))
#define IrUndefined__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1068))
#define IrUndefined__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1072))
#define IrUndefined__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1076))
#define IrProjection__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1080))
#define IrProjection__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1088))
#define IrProjection__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1092))
#define IrProjection__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1096))
#define IrMerge__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1100))
#define IrMerge__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1108))
#define IrMerge__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1112))
#define IrMerge__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1116))
#define IrLoopStart__opcodeInfo_001fb464 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1120))
#define IrLoopStart__opcodeInfo_001fb464_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1128))
#define IrLoopStart__opcodeInfo_001fb464_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1132))
#define IrLoopStart__opcodeInfo_001fb464_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1136))
#define IrLoopStart__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1140))
#define IrLoopStart__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1148))
#define IrLoopStart__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1152))
#define IrLoopStart__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1156))
#define IrPixelLoopFetch__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1160))
#define IrPixelLoopFetch__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1168))
#define IrPixelLoopFetch__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1172))
#define IrPixelLoopFetch__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1176))
#define IrVertexLoopFetch__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1180))
#define IrVertexLoopFetch__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1188))
#define IrVertexLoopFetch__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1192))
#define IrVertexLoopFetch__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1196))
#define IrLoadInterp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1200))
#define IrLoadInterp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1208))
#define IrLoadInterp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1212))
#define IrLoadInterp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1216))
#define IrLoadTempDefault__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1220))
#define IrLoadTempDefault__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1228))
#define IrLoadTempDefault__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1232))
#define IrLoadTempDefault__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1236))
#define IrLoadAbstractState__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1240))
#define IrLoadAbstractState__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1248))
#define IrLoadAbstractState__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1252))
#define IrLoadAbstractState__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1256))
#define IrLoadPhysical__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1260))
#define IrLoadPhysical__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1268))
#define IrLoadPhysical__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1272))
#define IrLoadPhysical__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1276))
#define IrLoadTemp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1280))
#define IrLoadTemp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1288))
#define IrLoadTemp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1292))
#define IrLoadTemp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1296))
#define IrLoadConst__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1300))
#define IrLoadConst__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1308))
#define IrLoadConst__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1312))
#define IrLoadConst__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1316))
#define IrMovaFloorInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1320))
#define IrMovaFloorInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1328))
#define IrMovaFloorInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1332))
#define IrMovaFloorInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1336))
#define IrMovaFloorGprInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1340))
#define IrMovaFloorGprInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1348))
#define IrMovaFloorGprInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1352))
#define IrMovaFloorGprInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1356))
#define IrMovaFloorFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1360))
#define IrMovaFloorFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1368))
#define IrMovaFloorFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1372))
#define IrMovaFloorFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1376))
#define IrMovaFlr__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1380))
#define IrMovaFlr__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1388))
#define IrMovaFlr__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1392))
#define IrMovaFlr__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1396))
#define IrMovaFloor__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1400))
#define IrMovaFloor__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1408))
#define IrMovaFloor__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1412))
#define IrMovaFloor__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1416))
#define IrSubPrev__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1420))
#define IrSubPrev__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1428))
#define IrSubPrev__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1432))
#define IrSubPrev__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1436))
#define IrMulPrev2__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1440))
#define IrMulPrev2__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1448))
#define IrMulPrev2__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1452))
#define IrMulPrev2__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1456))
#define IrMulPrev__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1460))
#define IrMulPrev__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1468))
#define IrMulPrev__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1472))
#define IrMulPrev__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1476))
#define IrAddPrev__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1480))
#define IrAddPrev__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1488))
#define IrAddPrev__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1492))
#define IrAddPrev__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1496))
#define IrPredSetRst__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1500))
#define IrPredSetRst__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1508))
#define IrPredSetRst__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1512))
#define IrPredSetRst__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1516))
#define IrPredSetClr__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1520))
#define IrPredSetClr__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1528))
#define IrPredSetClr__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1532))
#define IrPredSetClr__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1536))
#define IrPredSetPop__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1540))
#define IrPredSetPop__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1548))
#define IrPredSetPop__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1552))
#define IrPredSetPop__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1556))
#define IrPredSetInv__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1560))
#define IrPredSetInv__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1568))
#define IrPredSetInv__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1572))
#define IrPredSetInv__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1576))
#define IrPredSetGEInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1580))
#define IrPredSetGEInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1588))
#define IrPredSetGEInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1592))
#define IrPredSetGEInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1596))
#define IrPredSetGE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1600))
#define IrPredSetGE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1608))
#define IrPredSetGE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1612))
#define IrPredSetGE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1616))
#define IrPredSetLEInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1620))
#define IrPredSetLEInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1628))
#define IrPredSetLEInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1632))
#define IrPredSetLEInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1636))
#define IrPredSetLTInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1640))
#define IrPredSetLTInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1648))
#define IrPredSetLTInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1652))
#define IrPredSetLTInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1656))
#define IrPredSetGTInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1660))
#define IrPredSetGTInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1668))
#define IrPredSetGTInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1672))
#define IrPredSetGTInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1676))
#define IrPredSetGT__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1680))
#define IrPredSetGT__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1688))
#define IrPredSetGT__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1692))
#define IrPredSetGT__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1696))
#define IrPredSetNEInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1700))
#define IrPredSetNEInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1708))
#define IrPredSetNEInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1712))
#define IrPredSetNEInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1716))
#define IrPredSetNE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1720))
#define IrPredSetNE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1728))
#define IrPredSetNE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1732))
#define IrPredSetNE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1736))
#define IrPredSetEInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1740))
#define IrPredSetEInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1748))
#define IrPredSetEInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1752))
#define IrPredSetEInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1756))
#define IrPredSetE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1760))
#define IrPredSetE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1768))
#define IrPredSetE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1772))
#define IrPredSetE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1776))
#define IrKillOne__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1780))
#define IrKillOne__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1788))
#define IrKillOne__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1792))
#define IrKillOne__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1796))
#define IrCos__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1800))
#define IrCos__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1808))
#define IrCos__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1812))
#define IrCos__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1816))
#define IrSin__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1820))
#define IrSin__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1828))
#define IrSin__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1832))
#define IrSin__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1836))
#define IrSubConst1__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1840))
#define IrSubConst1__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1848))
#define IrSubConst1__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1852))
#define IrSubConst1__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1856))
#define IrMulConst1__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1860))
#define IrMulConst1__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1868))
#define IrMulConst1__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1872))
#define IrMulConst1__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1876))
#define IrAddConst1__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1880))
#define IrAddConst1__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1888))
#define IrAddConst1__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1892))
#define IrAddConst1__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1896))
#define IrSubConst0__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1900))
#define IrSubConst0__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1908))
#define IrSubConst0__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1912))
#define IrSubConst0__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1916))
#define IrMulConst0__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1920))
#define IrMulConst0__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1928))
#define IrMulConst0__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1932))
#define IrMulConst0__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1936))
#define IrAddConst0__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1940))
#define IrAddConst0__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1948))
#define IrAddConst0__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1952))
#define IrAddConst0__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1956))
#define IrFetchTextureMapGradients__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1960))
#define IrFetchTextureMapGradients__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1968))
#define IrFetchTextureMapGradients__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1972))
#define IrFetchTextureMapGradients__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1976))
#define IrFetchTextureMapKill__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1980))
#define IrFetchTextureMapKill__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1988))
#define IrFetchTextureMapKill__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1992))
#define IrFetchTextureMapKill__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 1996))
#define IrFetchTextureMapBias__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2000))
#define IrFetchTextureMapBias__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2008))
#define IrFetchTextureMapBias__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2012))
#define IrFetchTextureMapBias__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2016))
#define IrFetchTextureMapProj__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2020))
#define IrFetchTextureMapProj__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2028))
#define IrFetchTextureMapProj__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2032))
#define IrFetchTextureMapProj__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2036))
#define IrSetFilter4Weights__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2040))
#define IrSetFilter4Weights__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2048))
#define IrSetFilter4Weights__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2052))
#define IrSetFilter4Weights__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2056))
#define IrSetGradientsV__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2060))
#define IrSetGradientsV__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2068))
#define IrSetGradientsV__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2072))
#define IrSetGradientsV__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2076))
#define IrSetGradientsH__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2080))
#define IrSetGradientsH__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2088))
#define IrSetGradientsH__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2092))
#define IrSetGradientsH__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2096))
#define IrSetTexLod__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2100))
#define IrSetTexLod__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2108))
#define IrSetTexLod__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2112))
#define IrSetTexLod__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2116))
#define IrGetWeights__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2120))
#define IrGetWeights__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2128))
#define IrGetWeights__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2132))
#define IrGetWeights__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2136))
#define IrGetGradients__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2140))
#define IrGetGradients__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2148))
#define IrGetGradients__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2152))
#define IrGetGradients__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2156))
#define IrGetCompTexLod__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2160))
#define IrGetCompTexLod__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2168))
#define IrGetCompTexLod__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2172))
#define IrGetCompTexLod__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2176))
#define IrGetBorderColorFraction__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2180))
#define IrGetBorderColorFraction__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2188))
#define IrGetBorderColorFraction__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2192))
#define IrGetBorderColorFraction__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2196))
#define IrFetchMultiSample__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2200))
#define IrFetchMultiSample__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2208))
#define IrFetchMultiSample__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2212))
#define IrFetchMultiSample__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2216))
#define IrFetchShadowMap__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2220))
#define IrFetchShadowMap__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2228))
#define IrFetchShadowMap__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2232))
#define IrFetchShadowMap__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2236))
#define IrFetch3DNoiseMap__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2240))
#define IrFetch3DNoiseMap__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2248))
#define IrFetch3DNoiseMap__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2252))
#define IrFetch3DNoiseMap__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2256))
#define IrFetchTextureMap__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2260))
#define IrFetchTextureMap__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2268))
#define IrFetchTextureMap__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2272))
#define IrFetchTextureMap__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2276))
#define IrFetchVertex__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2280))
#define IrFetchVertex__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2288))
#define IrFetchVertex__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2292))
#define IrFetchVertex__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2296))
#define IrSqrt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2300))
#define IrSqrt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2308))
#define IrSqrt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2312))
#define IrSqrt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2316))
#define IrRecipSqrtIEEE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2320))
#define IrRecipSqrtIEEE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2328))
#define IrRecipSqrtIEEE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2332))
#define IrRecipSqrtIEEE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2336))
#define IrRecipSqrtFF__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2340))
#define IrRecipSqrtFF__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2348))
#define IrRecipSqrtFF__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2352))
#define IrRecipSqrtFF__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2356))
#define IrRecipSqrtClamp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2360))
#define IrRecipSqrtClamp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2368))
#define IrRecipSqrtClamp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2372))
#define IrRecipSqrtClamp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2376))
#define IrLogIEEE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2380))
#define IrLogIEEE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2388))
#define IrLogIEEE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2392))
#define IrLogIEEE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2396))
#define IrLogClamp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2400))
#define IrLogClamp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2408))
#define IrLogClamp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2412))
#define IrLogClamp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2416))
#define IrExp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2420))
#define IrExp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2428))
#define IrExp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2432))
#define IrExp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2436))
#define IrSub__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2440))
#define IrSub__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2448))
#define IrSub__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2452))
#define IrSub__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2456))
#define IrNop1__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2460))
#define IrNop1__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2468))
#define IrNop1__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2472))
#define IrNop1__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2476))
#define IrNop__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2480))
#define IrNop__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2488))
#define IrNop__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2492))
#define IrNop__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2496))
#define IrLit__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2500))
#define IrLit__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2508))
#define IrLit__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2512))
#define IrLit__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2516))
#define IrMov__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2520))
#define IrMov__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2528))
#define IrMov__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2532))
#define IrMov__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2536))
#define IrMovFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2540))
#define IrMovFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2548))
#define IrMovFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2552))
#define IrMovFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2556))
#define IrExportRing__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2560))
#define IrExportRing__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2568))
#define IrExportRing__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2572))
#define IrExportRing__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2576))
#define IrExport__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2580))
#define IrExport__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2588))
#define IrExport__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2592))
#define IrExport__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2596))
#define IrExportFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2600))
#define IrExportFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2608))
#define IrExportFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2612))
#define IrExportFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2616))
#define IrPredSetGEPushInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2620))
#define IrPredSetGEPushInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2628))
#define IrPredSetGEPushInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2632))
#define IrPredSetGEPushInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2636))
#define IrPredSetGEPush__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2640))
#define IrPredSetGEPush__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2648))
#define IrPredSetGEPush__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2652))
#define IrPredSetGEPush__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2656))
#define IrPredSetGTPushInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2660))
#define IrPredSetGTPushInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2668))
#define IrPredSetGTPushInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2672))
#define IrPredSetGTPushInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2676))
#define IrPredSetGTPush__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2680))
#define IrPredSetGTPush__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2688))
#define IrPredSetGTPush__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2692))
#define IrPredSetGTPush__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2696))
#define IrPredSetNEPushInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2700))
#define IrPredSetNEPushInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2708))
#define IrPredSetNEPushInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2712))
#define IrPredSetNEPushInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2716))
#define IrPredSetNEPush__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2720))
#define IrPredSetNEPush__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2728))
#define IrPredSetNEPush__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2732))
#define IrPredSetNEPush__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2736))
#define IrPredSetLEPushInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2740))
#define IrPredSetLEPushInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2748))
#define IrPredSetLEPushInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2752))
#define IrPredSetLEPushInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2756))
#define IrPredSetLTPushInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2760))
#define IrPredSetLTPushInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2768))
#define IrPredSetLTPushInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2772))
#define IrPredSetLTPushInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2776))
#define IrPredSetEPushInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2780))
#define IrPredSetEPushInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2788))
#define IrPredSetEPushInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2792))
#define IrPredSetEPushInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2796))
#define IrPredSetEPush__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2800))
#define IrPredSetEPush__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2808))
#define IrPredSetEPush__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2812))
#define IrPredSetEPush__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2816))
#define IrMovaRound__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2820))
#define IrMovaRound__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2828))
#define IrMovaRound__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2832))
#define IrMovaRound__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2836))
#define IrMovaRoundFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2840))
#define IrMovaRoundFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2848))
#define IrMovaRoundFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2852))
#define IrMovaRoundFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2856))
#define IrSetNEInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2860))
#define IrSetNEInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2868))
#define IrSetNEInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2872))
#define IrSetNEInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2876))
#define IrSetNE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2880))
#define IrSetNE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2888))
#define IrSetNE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2892))
#define IrSetNE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2896))
#define IrSetNEFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2900))
#define IrSetNEFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2908))
#define IrSetNEFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2912))
#define IrSetNEFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2916))
#define IrSetGE_uint__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2920))
#define IrSetGE_uint__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2928))
#define IrSetGE_uint__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2932))
#define IrSetGE_uint__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2936))
#define IrSetGEInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2940))
#define IrSetGEInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2948))
#define IrSetGEInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2952))
#define IrSetGEInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2956))
#define IrSetGE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2960))
#define IrSetGE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2968))
#define IrSetGE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2972))
#define IrSetGE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2976))
#define IrSetGEFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2980))
#define IrSetGEFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2988))
#define IrSetGEFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2992))
#define IrSetGEFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 2996))
#define IrSetGTUint__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3000))
#define IrSetGTUint__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3008))
#define IrSetGTUint__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3012))
#define IrSetGTUint__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3016))
#define IrSetGTInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3020))
#define IrSetGTInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3028))
#define IrSetGTInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3032))
#define IrSetGTInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3036))
#define IrSetGTDx10__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3040))
#define IrSetGTDx10__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3048))
#define IrSetGTDx10__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3052))
#define IrSetGTDx10__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3056))
#define IrSetGT__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3060))
#define IrSetGT__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3068))
#define IrSetGT__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3072))
#define IrSetGT__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3076))
#define IrSetGTFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3080))
#define IrSetGTFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3088))
#define IrSetGTFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3092))
#define IrSetGTFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3096))
#define IrSetEInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3100))
#define IrSetEInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3108))
#define IrSetEInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3112))
#define IrSetEInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3116))
#define IrSetE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3120))
#define IrSetE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3128))
#define IrSetE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3132))
#define IrSetE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3136))
#define IrSetEFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3140))
#define IrSetEFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3148))
#define IrSetEFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3152))
#define IrSetEFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3156))
#define IrCndGT1__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3160))
#define IrCndGT1__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3168))
#define IrCndGT1__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3172))
#define IrCndGT1__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3176))
#define IrCndGTInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3180))
#define IrCndGTInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3188))
#define IrCndGTInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3192))
#define IrCndGTInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3196))
#define IrCndGT__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3200))
#define IrCndGT__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3208))
#define IrCndGT__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3212))
#define IrCndGT__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3216))
#define IrCndGTFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3220))
#define IrCndGTFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3228))
#define IrCndGTFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3232))
#define IrCndGTFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3236))
#define IrCndE1__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3240))
#define IrCndE1__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3248))
#define IrCndE1__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3252))
#define IrCndE1__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3256))
#define IrCndEInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3260))
#define IrCndEInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3268))
#define IrCndEInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3272))
#define IrCndEInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3276))
#define IrCndE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3280))
#define IrCndE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3288))
#define IrCndE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3292))
#define IrCndE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3296))
#define IrCndEFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3300))
#define IrCndEFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3308))
#define IrCndEFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3312))
#define IrCndEFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3316))
#define IrKillNE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3320))
#define IrKillNE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3328))
#define IrKillNE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3332))
#define IrKillNE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3336))
#define IrKillNEFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3340))
#define IrKillNEFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3348))
#define IrKillNEFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3352))
#define IrKillNEFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3356))
#define IrKillGE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3360))
#define IrKillGE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3368))
#define IrKillGE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3372))
#define IrKillGE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3376))
#define IrKillGEFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3380))
#define IrKillGEFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3388))
#define IrKillGEFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3392))
#define IrKillGEFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3396))
#define IrKillGT__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3400))
#define IrKillGT__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3408))
#define IrKillGT__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3412))
#define IrKillGT__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3416))
#define IrKillGTFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3420))
#define IrKillGTFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3428))
#define IrKillGTFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3432))
#define IrKillGTFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3436))
#define IrKillE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3440))
#define IrKillE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3448))
#define IrKillE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3452))
#define IrKillE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3456))
#define IrKillEFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3460))
#define IrKillEFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3468))
#define IrKillEFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3472))
#define IrKillEFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3476))
#define IrDst__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3480))
#define IrDst__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3488))
#define IrDst__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3492))
#define IrDst__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3496))
#define IrDot2Add__opcodeInfo_001fbdb0 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3500))
#define IrDot2Add__opcodeInfo_001fbdb0_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3508))
#define IrDot2Add__opcodeInfo_001fbdb0_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3512))
#define IrDot2Add__opcodeInfo_001fbdb0_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3516))
#define IrDot2Add__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3520))
#define IrDot2Add__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3528))
#define IrDot2Add__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3532))
#define IrDot2Add__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3536))
#define IrDot4IEEE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3540))
#define IrDot4IEEE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3548))
#define IrDot4IEEE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3552))
#define IrDot4IEEE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3556))
#define IrDot4__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3560))
#define IrDot4__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3568))
#define IrDot4__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3572))
#define IrDot4__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3576))
#define IrMulHiUInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3580))
#define IrMulHiUInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3588))
#define IrMulHiUInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3592))
#define IrMulHiUInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3596))
#define IrMulLowUInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3600))
#define IrMulLowUInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3608))
#define IrMulLowUInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3612))
#define IrMulLowUInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3616))
#define IrMulHiInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3620))
#define IrMulHiInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3628))
#define IrMulHiInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3632))
#define IrMulHiInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3636))
#define IrMulLowInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3640))
#define IrMulLowInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3648))
#define IrMulLowInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3652))
#define IrMulLowInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3656))
#define IrLshlInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3660))
#define IrLshlInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3668))
#define IrLshlInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3672))
#define IrLshlInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3676))
#define IrLshrInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3680))
#define IrLshrInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3688))
#define IrLshrInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3692))
#define IrLshrInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3696))
#define IrAshrInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3700))
#define IrAshrInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3708))
#define IrAshrInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3712))
#define IrAshrInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3716))
#define IrUInt2F__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3720))
#define IrUInt2F__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3728))
#define IrUInt2F__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3732))
#define IrUInt2F__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3736))
#define IrInt2F__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3740))
#define IrInt2F__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3748))
#define IrInt2F__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3752))
#define IrInt2F__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3756))
#define IrF2UInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3760))
#define IrF2UInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3768))
#define IrF2UInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3772))
#define IrF2UInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3776))
#define IrF2Int__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3780))
#define IrF2Int__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3788))
#define IrF2Int__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3792))
#define IrF2Int__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3796))
#define IrDot3IEEE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3800))
#define IrDot3IEEE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3808))
#define IrDot3IEEE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3812))
#define IrDot3IEEE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3816))
#define IrDot3__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3820))
#define IrDot3__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3828))
#define IrDot3__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3832))
#define IrDot3__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3836))
#define IrCube__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3840))
#define IrCube__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3848))
#define IrCube__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3852))
#define IrCube__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3856))
#define IrTrunc__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3860))
#define IrTrunc__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3868))
#define IrTrunc__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3872))
#define IrTrunc__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3876))
#define IrTruncFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3880))
#define IrTruncFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3888))
#define IrTruncFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3892))
#define IrTruncFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3896))
#define IrRecipUInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3900))
#define IrRecipUInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3908))
#define IrRecipUInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3912))
#define IrRecipUInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3916))
#define IrRecipInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3920))
#define IrRecipInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3928))
#define IrRecipInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3932))
#define IrRecipInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3936))
#define IrRecipIEEE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3940))
#define IrRecipIEEE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3948))
#define IrRecipIEEE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3952))
#define IrRecipIEEE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3956))
#define IrRecipFF__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3960))
#define IrRecipFF__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3968))
#define IrRecipFF__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3972))
#define IrRecipFF__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3976))
#define IrRecipClamp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3980))
#define IrRecipClamp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3988))
#define IrRecipClamp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3992))
#define IrRecipClamp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 3996))
#define IrMinDx10__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4000))
#define IrMinDx10__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4008))
#define IrMinDx10__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4012))
#define IrMinDx10__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4016))
#define IrMinUInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4020))
#define IrMinUInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4028))
#define IrMinUInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4032))
#define IrMinUInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4036))
#define IrMinInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4040))
#define IrMinInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4048))
#define IrMinInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4052))
#define IrMinInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4056))
#define IrMin__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4060))
#define IrMin__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4068))
#define IrMin__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4072))
#define IrMin__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4076))
#define IrMinFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4080))
#define IrMinFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4088))
#define IrMinFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4092))
#define IrMinFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrRoundNearestEven__opcodeInfo + 4096))
#define IrMax4__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4600))
#define IrMax4__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4608))
#define IrMax4__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4612))
#define IrMax4__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4616))
#define IrMaxDx10__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4620))
#define IrMaxDx10__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4628))
#define IrMaxDx10__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4632))
#define IrMaxDx10__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4636))
#define IrMax__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4640))
#define IrMax__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4648))
#define IrMax__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4652))
#define IrMax__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4656))
#define IrMaxUInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4660))
#define IrMaxUInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4668))
#define IrMaxUInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4672))
#define IrMaxUInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4676))
#define IrMaxInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4680))
#define IrMaxInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4688))
#define IrMaxInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4692))
#define IrMaxInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4696))
#define IrMaxFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4700))
#define IrMaxFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4708))
#define IrMaxFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4712))
#define IrMaxFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4716))
#define IrFract__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4720))
#define IrFract__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4728))
#define IrFract__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4732))
#define IrFract__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4736))
#define IrFractFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4740))
#define IrFractFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4748))
#define IrFractFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4752))
#define IrFractFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4756))
#define IrFloor__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4760))
#define IrFloor__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4768))
#define IrFloor__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4772))
#define IrFloor__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4776))
#define IrFloorFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4780))
#define IrFloorFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4788))
#define IrFloorFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4792))
#define IrFloorFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4796))
#define IrMulAddIEEE__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4800))
#define IrMulAddIEEE__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4808))
#define IrMulAddIEEE__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4812))
#define IrMulAddIEEE__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4816))
#define IrMulAdd__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4820))
#define IrMulAdd__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4828))
#define IrMulAdd__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4832))
#define IrMulAdd__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4836))
#define IrMulAddFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4840))
#define IrMulAddFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4848))
#define IrMulAddFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4852))
#define IrMulAddFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4856))
#define IrMul__opcodeInfo_001fc10c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4860))
#define IrMul__opcodeInfo_001fc10c_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4868))
#define IrMul__opcodeInfo_001fc10c_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4872))
#define IrMul__opcodeInfo_001fc10c_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4876))
#define IrMul__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4880))
#define IrMul__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4888))
#define IrMul__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4892))
#define IrMul__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4896))
#define IrMulFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4900))
#define IrMulFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4908))
#define IrMulFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4912))
#define IrMulFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4916))
#define IrSubInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4920))
#define IrSubInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4928))
#define IrSubInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4932))
#define IrSubInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4936))
#define IrAddInt__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4940))
#define IrAddInt__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4948))
#define IrAddInt__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4952))
#define IrAddInt__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4956))
#define IrAdd__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4960))
#define IrAdd__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4968))
#define IrAdd__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4972))
#define IrAdd__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4976))
#define IrAddFloat__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4980))
#define IrAddFloat__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4988))
#define IrAddFloat__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4992))
#define IrAddFloat__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 4996))
#define IrAlloc__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5000))
#define IrAlloc__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5008))
#define IrAlloc__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5012))
#define IrAlloc__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5016))
#define IrCondJmp__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5020))
#define IrCondJmp__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5028))
#define IrCondJmp__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5032))
#define IrCondJmp__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5036))
#define IrRet__opcodeInfo (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5040))
#define IrRet__opcodeInfo_opcode (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5048))
#define IrRet__opcodeInfo_word0c (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5052))
#define IrRet__opcodeInfo_word10 (*(unsigned char **)((unsigned char *)&IrImmedConstLoad__opcodeInfo + 5056))
extern int (*DAT_001fc1d4)();
extern int (*DAT_001fc1d8)();
extern int (*DAT_001fc1dc)();
extern int (*DAT_001fc1e0)();
extern unsigned char DAT_001fc1f0;
extern unsigned char DAT_001fc1f4;
extern unsigned char DAT_001fc1f8[];
extern unsigned char DAT_001fc1fc[];
extern unsigned char opcodeInfoTable;
/* issue #75 (follow-up, static-data version of the same bug class): opcodeInfoTable and this
 * whole run of individually-named DAT_ globals are, in the REAL stock binary, ONE SINGLE
 * contiguous array - Opcode__getInfo (part_032.c) reads it purely via pointer arithmetic
 * (`*(undefined4*)(&opcodeInfoTable + index*4)`), and part_036.c's giant format-table
 * initializer writes into it the exact same way, just via individually Ghidra-named slots
 * (because THAT code happens to reference each slot by absolute address instead of computed
 * index). Declaring every slot as its own INDEPENDENT `.zerofill` symbol - as this whole
 * decls.h did - only worked in the original binary because ITS compiler/linker happened to
 * lay them out contiguously and in order; our rebuild's linker has no reason to preserve that
 * adjacency (same root cause as the check_cxa_atexit local_28/local_24 stack-slot bug fixed
 * earlier in this same investigation, just for static/BSS storage instead of the stack).
 * Confirmed live: opcodeInfoTable's own `.zerofill` was only 60 bytes (15 entries), so a real
 * call site (`Opcode__getInfo(0x87)` = index 135, part_027.c:1155) read 480 bytes past its
 * allocated storage into unrelated memory (observed as 0xf0000000), even though part_036.c
 * DOES correctly execute `opcodeInfoTable_op135 = &IrEntry__opcodeInfo;` (the real value for index 135) -
 * it just lands in a completely separate, independent 4-byte allocation that the array-style
 * read never sees. Also: each of these individual slots was itself typed as a scalar
 * `unsigned char` (1 byte) despite always being assigned a real pointer value
 * (`NAME = &DAT_xxx;`), which would truncate every one of those writes down to 1 byte even if
 * the adjacency problem didn't exist.
 *
 * Fixed by enlarging opcodeInfoTable's own storage (data.s zerofill 60 -> 1200 bytes, 300
 * entries - comfortably past the highest confirmed real index, 249) and redirecting every one
 * of these previously-independent slot names into that same array via macros, so the write
 * side (part_036.c) and the read side (Opcode__getInfo) are provably the same physical storage
 * regardless of what our own linker does. Verified these 253 names have no OTHER use anywhere
 * in the corpus (never read directly, never have their own address taken) - only ever written
 * once each by part_036.c's initializer - so this substitution is safe. */
#define opcodeInfoTable_op15 (*(unsigned char **)(&opcodeInfoTable + 15*4))
#define opcodeInfoTable_op16 (*(unsigned char **)(&opcodeInfoTable + 16*4))
#define opcodeInfoTable_op17 (*(unsigned char **)(&opcodeInfoTable + 17*4))
#define opcodeInfoTable_op18 (*(unsigned char **)(&opcodeInfoTable + 18*4))
#define opcodeInfoTable_op19 (*(unsigned char **)(&opcodeInfoTable + 19*4))
#define opcodeInfoTable_op20 (*(unsigned char **)(&opcodeInfoTable + 20*4))
#define opcodeInfoTable_op21 (*(unsigned char **)(&opcodeInfoTable + 21*4))
#define opcodeInfoTable_op22 (*(unsigned char **)(&opcodeInfoTable + 22*4))
#define opcodeInfoTable_op23 (*(unsigned char **)(&opcodeInfoTable + 23*4))
#define opcodeInfoTable_op24 (*(unsigned char **)(&opcodeInfoTable + 24*4))
#define opcodeInfoTable_op25 (*(unsigned char **)(&opcodeInfoTable + 25*4))
#define opcodeInfoTable_op26 (*(unsigned char **)(&opcodeInfoTable + 26*4))
#define opcodeInfoTable_op27 (*(unsigned char **)(&opcodeInfoTable + 27*4))
#define opcodeInfoTable_op28 (*(unsigned char **)(&opcodeInfoTable + 28*4))
#define opcodeInfoTable_op29 (*(unsigned char **)(&opcodeInfoTable + 29*4))
#define opcodeInfoTable_op30 (*(unsigned char **)(&opcodeInfoTable + 30*4))
#define opcodeInfoTable_op31 (*(unsigned char **)(&opcodeInfoTable + 31*4))
#define opcodeInfoTable_op32 (*(unsigned char **)(&opcodeInfoTable + 32*4))
#define opcodeInfoTable_op33 (*(unsigned char **)(&opcodeInfoTable + 33*4))
#define opcodeInfoTable_op34 (*(unsigned char **)(&opcodeInfoTable + 34*4))
#define opcodeInfoTable_op35 (*(unsigned char **)(&opcodeInfoTable + 35*4))
#define opcodeInfoTable_op36 (*(unsigned char **)(&opcodeInfoTable + 36*4))
#define opcodeInfoTable_op37 (*(unsigned char **)(&opcodeInfoTable + 37*4))
#define opcodeInfoTable_op38 (*(unsigned char **)(&opcodeInfoTable + 38*4))
#define opcodeInfoTable_op39 (*(unsigned char **)(&opcodeInfoTable + 39*4))
#define opcodeInfoTable_op40 (*(unsigned char **)(&opcodeInfoTable + 40*4))
#define opcodeInfoTable_op41 (*(unsigned char **)(&opcodeInfoTable + 41*4))
#define opcodeInfoTable_op42 (*(unsigned char **)(&opcodeInfoTable + 42*4))
#define opcodeInfoTable_op43 (*(unsigned char **)(&opcodeInfoTable + 43*4))
#define opcodeInfoTable_op44 (*(unsigned char **)(&opcodeInfoTable + 44*4))
#define opcodeInfoTable_op45 (*(unsigned char **)(&opcodeInfoTable + 45*4))
#define opcodeInfoTable_op46 (*(unsigned char **)(&opcodeInfoTable + 46*4))
#define opcodeInfoTable_op47 (*(unsigned char **)(&opcodeInfoTable + 47*4))
#define opcodeInfoTable_op48 (*(unsigned char **)(&opcodeInfoTable + 48*4))
#define opcodeInfoTable_op49 (*(unsigned char **)(&opcodeInfoTable + 49*4))
#define opcodeInfoTable_op50 (*(unsigned char **)(&opcodeInfoTable + 50*4))
#define opcodeInfoTable_op51 (*(unsigned char **)(&opcodeInfoTable + 51*4))
#define opcodeInfoTable_op52 (*(unsigned char **)(&opcodeInfoTable + 52*4))
#define opcodeInfoTable_op53 (*(unsigned char **)(&opcodeInfoTable + 53*4))
#define opcodeInfoTable_op54 (*(unsigned char **)(&opcodeInfoTable + 54*4))
#define opcodeInfoTable_op55 (*(unsigned char **)(&opcodeInfoTable + 55*4))
#define opcodeInfoTable_op56 (*(unsigned char **)(&opcodeInfoTable + 56*4))
#define opcodeInfoTable_op57 (*(unsigned char **)(&opcodeInfoTable + 57*4))
#define opcodeInfoTable_op58 (*(unsigned char **)(&opcodeInfoTable + 58*4))
#define opcodeInfoTable_op59 (*(unsigned char **)(&opcodeInfoTable + 59*4))
#define opcodeInfoTable_op60 (*(unsigned char **)(&opcodeInfoTable + 60*4))
#define opcodeInfoTable_op61 (*(unsigned char **)(&opcodeInfoTable + 61*4))
#define opcodeInfoTable_op62 (*(unsigned char **)(&opcodeInfoTable + 62*4))
#define opcodeInfoTable_op63 (*(unsigned char **)(&opcodeInfoTable + 63*4))
#define opcodeInfoTable_op64 (*(unsigned char **)(&opcodeInfoTable + 64*4))
#define opcodeInfoTable_op65 (*(unsigned char **)(&opcodeInfoTable + 65*4))
#define opcodeInfoTable_op66 (*(unsigned char **)(&opcodeInfoTable + 66*4))
#define opcodeInfoTable_op67 (*(unsigned char **)(&opcodeInfoTable + 67*4))
#define opcodeInfoTable_op68 (*(unsigned char **)(&opcodeInfoTable + 68*4))
#define opcodeInfoTable_op69 (*(unsigned char **)(&opcodeInfoTable + 69*4))
#define opcodeInfoTable_op70 (*(unsigned char **)(&opcodeInfoTable + 70*4))
#define opcodeInfoTable_op71 (*(unsigned char **)(&opcodeInfoTable + 71*4))
#define opcodeInfoTable_op72 (*(unsigned char **)(&opcodeInfoTable + 72*4))
#define opcodeInfoTable_op73 (*(unsigned char **)(&opcodeInfoTable + 73*4))
#define opcodeInfoTable_op74 (*(unsigned char **)(&opcodeInfoTable + 74*4))
#define opcodeInfoTable_op75 (*(unsigned char **)(&opcodeInfoTable + 75*4))
#define opcodeInfoTable_op76 (*(unsigned char **)(&opcodeInfoTable + 76*4))
#define opcodeInfoTable_op77 (*(unsigned char **)(&opcodeInfoTable + 77*4))
#define opcodeInfoTable_op78 (*(unsigned char **)(&opcodeInfoTable + 78*4))
#define opcodeInfoTable_op79 (*(unsigned char **)(&opcodeInfoTable + 79*4))
#define opcodeInfoTable_op80 (*(unsigned char **)(&opcodeInfoTable + 80*4))
#define opcodeInfoTable_op81 (*(unsigned char **)(&opcodeInfoTable + 81*4))
#define opcodeInfoTable_op82 (*(unsigned char **)(&opcodeInfoTable + 82*4))
#define opcodeInfoTable_op83 (*(unsigned char **)(&opcodeInfoTable + 83*4))
#define opcodeInfoTable_op84 (*(unsigned char **)(&opcodeInfoTable + 84*4))
#define opcodeInfoTable_op85 (*(unsigned char **)(&opcodeInfoTable + 85*4))
#define opcodeInfoTable_op86 (*(unsigned char **)(&opcodeInfoTable + 86*4))
#define opcodeInfoTable_op87 (*(unsigned char **)(&opcodeInfoTable + 87*4))
#define opcodeInfoTable_op88 (*(unsigned char **)(&opcodeInfoTable + 88*4))
#define opcodeInfoTable_op89 (*(unsigned char **)(&opcodeInfoTable + 89*4))
#define opcodeInfoTable_op90 (*(unsigned char **)(&opcodeInfoTable + 90*4))
#define opcodeInfoTable_op91 (*(unsigned char **)(&opcodeInfoTable + 91*4))
#define opcodeInfoTable_op92 (*(unsigned char **)(&opcodeInfoTable + 92*4))
#define opcodeInfoTable_op93 (*(unsigned char **)(&opcodeInfoTable + 93*4))
#define opcodeInfoTable_op94 (*(unsigned char **)(&opcodeInfoTable + 94*4))
#define opcodeInfoTable_op95 (*(unsigned char **)(&opcodeInfoTable + 95*4))
#define opcodeInfoTable_op96 (*(unsigned char **)(&opcodeInfoTable + 96*4))
#define opcodeInfoTable_op97 (*(unsigned char **)(&opcodeInfoTable + 97*4))
#define opcodeInfoTable_op98 (*(unsigned char **)(&opcodeInfoTable + 98*4))
#define opcodeInfoTable_op99 (*(unsigned char **)(&opcodeInfoTable + 99*4))
#define opcodeInfoTable_op100 (*(unsigned char **)(&opcodeInfoTable + 100*4))
#define opcodeInfoTable_op101 (*(unsigned char **)(&opcodeInfoTable + 101*4))
#define opcodeInfoTable_op102 (*(unsigned char **)(&opcodeInfoTable + 102*4))
#define opcodeInfoTable_op103 (*(unsigned char **)(&opcodeInfoTable + 103*4))
#define opcodeInfoTable_op104 (*(unsigned char **)(&opcodeInfoTable + 104*4))
#define opcodeInfoTable_op105 (*(unsigned char **)(&opcodeInfoTable + 105*4))
#define opcodeInfoTable_op106 (*(unsigned char **)(&opcodeInfoTable + 106*4))
#define opcodeInfoTable_op107 (*(unsigned char **)(&opcodeInfoTable + 107*4))
#define opcodeInfoTable_op108 (*(unsigned char **)(&opcodeInfoTable + 108*4))
#define opcodeInfoTable_op109 (*(unsigned char **)(&opcodeInfoTable + 109*4))
#define opcodeInfoTable_op110 (*(unsigned char **)(&opcodeInfoTable + 110*4))
#define opcodeInfoTable_op111 (*(unsigned char **)(&opcodeInfoTable + 111*4))
#define opcodeInfoTable_op112 (*(unsigned char **)(&opcodeInfoTable + 112*4))
#define opcodeInfoTable_op113 (*(unsigned char **)(&opcodeInfoTable + 113*4))
#define opcodeInfoTable_op114 (*(unsigned char **)(&opcodeInfoTable + 114*4))
#define opcodeInfoTable_op115 (*(unsigned char **)(&opcodeInfoTable + 115*4))
#define opcodeInfoTable_op116 (*(unsigned char **)(&opcodeInfoTable + 116*4))
#define opcodeInfoTable_op117 (*(unsigned char **)(&opcodeInfoTable + 117*4))
#define opcodeInfoTable_op118 (*(unsigned char **)(&opcodeInfoTable + 118*4))
#define opcodeInfoTable_op119 (*(unsigned char **)(&opcodeInfoTable + 119*4))
#define opcodeInfoTable_op120 (*(unsigned char **)(&opcodeInfoTable + 120*4))
#define opcodeInfoTable_op121 (*(unsigned char **)(&opcodeInfoTable + 121*4))
#define opcodeInfoTable_op122 (*(unsigned char **)(&opcodeInfoTable + 122*4))
#define opcodeInfoTable_op123 (*(unsigned char **)(&opcodeInfoTable + 123*4))
#define opcodeInfoTable_op124 (*(unsigned char **)(&opcodeInfoTable + 124*4))
#define opcodeInfoTable_op125 (*(unsigned char **)(&opcodeInfoTable + 125*4))
#define opcodeInfoTable_op126 (*(unsigned char **)(&opcodeInfoTable + 126*4))
#define opcodeInfoTable_op127 (*(unsigned char **)(&opcodeInfoTable + 127*4))
#define opcodeInfoTable_op128 (*(unsigned char **)(&opcodeInfoTable + 128*4))
#define opcodeInfoTable_op129 (*(unsigned char **)(&opcodeInfoTable + 129*4))
#define opcodeInfoTable_op130 (*(unsigned char **)(&opcodeInfoTable + 130*4))
#define opcodeInfoTable_op131 (*(unsigned char **)(&opcodeInfoTable + 131*4))
#define opcodeInfoTable_op132 (*(unsigned char **)(&opcodeInfoTable + 132*4))
#define opcodeInfoTable_op133 (*(unsigned char **)(&opcodeInfoTable + 133*4))
#define opcodeInfoTable_op134 (*(unsigned char **)(&opcodeInfoTable + 134*4))
#define opcodeInfoTable_op135 (*(unsigned char **)(&opcodeInfoTable + 135*4))
#define opcodeInfoTable_op136 (*(unsigned char **)(&opcodeInfoTable + 136*4))
#define opcodeInfoTable_op137 (*(unsigned char **)(&opcodeInfoTable + 137*4))
#define opcodeInfoTable_op138 (*(unsigned char **)(&opcodeInfoTable + 138*4))
#define opcodeInfoTable_op139 (*(unsigned char **)(&opcodeInfoTable + 139*4))
#define opcodeInfoTable_op140 (*(unsigned char **)(&opcodeInfoTable + 140*4))
#define opcodeInfoTable_op141 (*(unsigned char **)(&opcodeInfoTable + 141*4))
#define opcodeInfoTable_op142 (*(unsigned char **)(&opcodeInfoTable + 142*4))
#define opcodeInfoTable_op143 (*(unsigned char **)(&opcodeInfoTable + 143*4))
#define opcodeInfoTable_op144 (*(unsigned char **)(&opcodeInfoTable + 144*4))
#define opcodeInfoTable_op145 (*(unsigned char **)(&opcodeInfoTable + 145*4))
#define opcodeInfoTable_op146 (*(unsigned char **)(&opcodeInfoTable + 146*4))
#define opcodeInfoTable_op147 (*(unsigned char **)(&opcodeInfoTable + 147*4))
#define opcodeInfoTable_op148 (*(unsigned char **)(&opcodeInfoTable + 148*4))
#define opcodeInfoTable_op149 (*(unsigned char **)(&opcodeInfoTable + 149*4))
#define opcodeInfoTable_op150 (*(unsigned char **)(&opcodeInfoTable + 150*4))
#define opcodeInfoTable_op151 (*(unsigned char **)(&opcodeInfoTable + 151*4))
#define opcodeInfoTable_op152 (*(unsigned char **)(&opcodeInfoTable + 152*4))
#define opcodeInfoTable_op153 (*(unsigned char **)(&opcodeInfoTable + 153*4))
#define opcodeInfoTable_op154 (*(unsigned char **)(&opcodeInfoTable + 154*4))
#define opcodeInfoTable_op155 (*(unsigned char **)(&opcodeInfoTable + 155*4))
#define opcodeInfoTable_op156 (*(unsigned char **)(&opcodeInfoTable + 156*4))
#define opcodeInfoTable_op157 (*(unsigned char **)(&opcodeInfoTable + 157*4))
#define opcodeInfoTable_op158 (*(unsigned char **)(&opcodeInfoTable + 158*4))
#define opcodeInfoTable_op159 (*(unsigned char **)(&opcodeInfoTable + 159*4))
#define opcodeInfoTable_op160 (*(unsigned char **)(&opcodeInfoTable + 160*4))
#define opcodeInfoTable_op161 (*(unsigned char **)(&opcodeInfoTable + 161*4))
#define opcodeInfoTable_op162 (*(unsigned char **)(&opcodeInfoTable + 162*4))
#define opcodeInfoTable_op163 (*(unsigned char **)(&opcodeInfoTable + 163*4))
#define opcodeInfoTable_op164 (*(unsigned char **)(&opcodeInfoTable + 164*4))
#define opcodeInfoTable_op165 (*(unsigned char **)(&opcodeInfoTable + 165*4))
#define opcodeInfoTable_op166 (*(unsigned char **)(&opcodeInfoTable + 166*4))
#define opcodeInfoTable_op167 (*(unsigned char **)(&opcodeInfoTable + 167*4))
#define opcodeInfoTable_op168 (*(unsigned char **)(&opcodeInfoTable + 168*4))
#define opcodeInfoTable_op169 (*(unsigned char **)(&opcodeInfoTable + 169*4))
#define opcodeInfoTable_op170 (*(unsigned char **)(&opcodeInfoTable + 170*4))
#define opcodeInfoTable_op171 (*(unsigned char **)(&opcodeInfoTable + 171*4))
#define opcodeInfoTable_op172 (*(unsigned char **)(&opcodeInfoTable + 172*4))
#define opcodeInfoTable_op173 (*(unsigned char **)(&opcodeInfoTable + 173*4))
#define opcodeInfoTable_op174 (*(unsigned char **)(&opcodeInfoTable + 174*4))
#define opcodeInfoTable_op175 (*(unsigned char **)(&opcodeInfoTable + 175*4))
#define opcodeInfoTable_op176 (*(unsigned char **)(&opcodeInfoTable + 176*4))
#define opcodeInfoTable_op177 (*(unsigned char **)(&opcodeInfoTable + 177*4))
#define opcodeInfoTable_op178 (*(unsigned char **)(&opcodeInfoTable + 178*4))
#define opcodeInfoTable_op179 (*(unsigned char **)(&opcodeInfoTable + 179*4))
#define opcodeInfoTable_op180 (*(unsigned char **)(&opcodeInfoTable + 180*4))
#define opcodeInfoTable_op181 (*(unsigned char **)(&opcodeInfoTable + 181*4))
#define opcodeInfoTable_op182 (*(unsigned char **)(&opcodeInfoTable + 182*4))
#define opcodeInfoTable_op183 (*(unsigned char **)(&opcodeInfoTable + 183*4))
#define opcodeInfoTable_op184 (*(unsigned char **)(&opcodeInfoTable + 184*4))
#define opcodeInfoTable_op185 (*(unsigned char **)(&opcodeInfoTable + 185*4))
#define opcodeInfoTable_op186 (*(unsigned char **)(&opcodeInfoTable + 186*4))
#define opcodeInfoTable_op187 (*(unsigned char **)(&opcodeInfoTable + 187*4))
#define opcodeInfoTable_op188 (*(unsigned char **)(&opcodeInfoTable + 188*4))
#define opcodeInfoTable_op189 (*(unsigned char **)(&opcodeInfoTable + 189*4))
#define opcodeInfoTable_op190 (*(unsigned char **)(&opcodeInfoTable + 190*4))
#define opcodeInfoTable_op191 (*(unsigned char **)(&opcodeInfoTable + 191*4))
#define opcodeInfoTable_op192 (*(unsigned char **)(&opcodeInfoTable + 192*4))
#define opcodeInfoTable_op193 (*(unsigned char **)(&opcodeInfoTable + 193*4))
#define opcodeInfoTable_op194 (*(unsigned char **)(&opcodeInfoTable + 194*4))
#define opcodeInfoTable_op195 (*(unsigned char **)(&opcodeInfoTable + 195*4))
#define opcodeInfoTable_op196 (*(unsigned char **)(&opcodeInfoTable + 196*4))
#define opcodeInfoTable_op197 (*(unsigned char **)(&opcodeInfoTable + 197*4))
#define opcodeInfoTable_op198 (*(unsigned char **)(&opcodeInfoTable + 198*4))
#define opcodeInfoTable_op199 (*(unsigned char **)(&opcodeInfoTable + 199*4))
#define opcodeInfoTable_op200 (*(unsigned char **)(&opcodeInfoTable + 200*4))
#define opcodeInfoTable_op201 (*(unsigned char **)(&opcodeInfoTable + 201*4))
#define opcodeInfoTable_op202 (*(unsigned char **)(&opcodeInfoTable + 202*4))
#define opcodeInfoTable_op203 (*(unsigned char **)(&opcodeInfoTable + 203*4))
#define opcodeInfoTable_op204 (*(unsigned char **)(&opcodeInfoTable + 204*4))
#define opcodeInfoTable_op205 (*(unsigned char **)(&opcodeInfoTable + 205*4))
#define opcodeInfoTable_op206 (*(unsigned char **)(&opcodeInfoTable + 206*4))
#define opcodeInfoTable_op207 (*(unsigned char **)(&opcodeInfoTable + 207*4))
#define opcodeInfoTable_op208 (*(unsigned char **)(&opcodeInfoTable + 208*4))
#define opcodeInfoTable_op209 (*(unsigned char **)(&opcodeInfoTable + 209*4))
#define opcodeInfoTable_op210 (*(unsigned char **)(&opcodeInfoTable + 210*4))
#define opcodeInfoTable_op211 (*(unsigned char **)(&opcodeInfoTable + 211*4))
#define opcodeInfoTable_op212 (*(unsigned char **)(&opcodeInfoTable + 212*4))
#define opcodeInfoTable_op213 (*(unsigned char **)(&opcodeInfoTable + 213*4))
#define opcodeInfoTable_op214 (*(unsigned char **)(&opcodeInfoTable + 214*4))
#define opcodeInfoTable_op215 (*(unsigned char **)(&opcodeInfoTable + 215*4))
#define opcodeInfoTable_op216 (*(unsigned char **)(&opcodeInfoTable + 216*4))
#define opcodeInfoTable_op217 (*(unsigned char **)(&opcodeInfoTable + 217*4))
#define opcodeInfoTable_op218 (*(unsigned char **)(&opcodeInfoTable + 218*4))
#define opcodeInfoTable_op219 (*(unsigned char **)(&opcodeInfoTable + 219*4))
#define opcodeInfoTable_op220 (*(unsigned char **)(&opcodeInfoTable + 220*4))
#define opcodeInfoTable_op221 (*(unsigned char **)(&opcodeInfoTable + 221*4))
#define opcodeInfoTable_op222 (*(unsigned char **)(&opcodeInfoTable + 222*4))
#define opcodeInfoTable_op223 (*(unsigned char **)(&opcodeInfoTable + 223*4))
#define opcodeInfoTable_op224 (*(unsigned char **)(&opcodeInfoTable + 224*4))
#define opcodeInfoTable_op225 (*(unsigned char **)(&opcodeInfoTable + 225*4))
#define opcodeInfoTable_op226 (*(unsigned char **)(&opcodeInfoTable + 226*4))
#define opcodeInfoTable_op227 (*(unsigned char **)(&opcodeInfoTable + 227*4))
#define opcodeInfoTable_op228 (*(unsigned char **)(&opcodeInfoTable + 228*4))
#define opcodeInfoTable_op229 (*(unsigned char **)(&opcodeInfoTable + 229*4))
#define opcodeInfoTable_op230 (*(unsigned char **)(&opcodeInfoTable + 230*4))
#define opcodeInfoTable_op231 (*(unsigned char **)(&opcodeInfoTable + 231*4))
#define opcodeInfoTable_op232 (*(unsigned char **)(&opcodeInfoTable + 232*4))
#define opcodeInfoTable_op233 (*(unsigned char **)(&opcodeInfoTable + 233*4))
#define opcodeInfoTable_op234 (*(unsigned char **)(&opcodeInfoTable + 234*4))
#define opcodeInfoTable_op235 (*(unsigned char **)(&opcodeInfoTable + 235*4))
#define opcodeInfoTable_op236 (*(unsigned char **)(&opcodeInfoTable + 236*4))
#define opcodeInfoTable_op237 (*(unsigned char **)(&opcodeInfoTable + 237*4))
#define opcodeInfoTable_op238 (*(unsigned char **)(&opcodeInfoTable + 238*4))
#define opcodeInfoTable_op239 (*(unsigned char **)(&opcodeInfoTable + 239*4))
#define opcodeInfoTable_op240 (*(unsigned char **)(&opcodeInfoTable + 240*4))
#define opcodeInfoTable_op241 (*(unsigned char **)(&opcodeInfoTable + 241*4))
#define opcodeInfoTable_op242 (*(unsigned char **)(&opcodeInfoTable + 242*4))
#define opcodeInfoTable_op243 (*(unsigned char **)(&opcodeInfoTable + 243*4))
#define opcodeInfoTable_op244 (*(unsigned char **)(&opcodeInfoTable + 244*4))
#define opcodeInfoTable_op245 (*(unsigned char **)(&opcodeInfoTable + 245*4))
#define opcodeInfoTable_op246 (*(unsigned char **)(&opcodeInfoTable + 246*4))
#define opcodeInfoTable_op247 (*(unsigned char **)(&opcodeInfoTable + 247*4))
#define opcodeInfoTable_op248 (*(unsigned char **)(&opcodeInfoTable + 248*4))
#define opcodeInfoTable_op249 (*(unsigned char **)(&opcodeInfoTable + 249*4))
#define opcodeInfoTable_op250 (*(unsigned char **)(&opcodeInfoTable + 250*4))
#define opcodeInfoTable_op251 (*(unsigned char **)(&opcodeInfoTable + 251*4))
#define opcodeInfoTable_op252 (*(unsigned char **)(&opcodeInfoTable + 252*4))
#define opcodeInfoTable_op253 (*(unsigned char **)(&opcodeInfoTable + 253*4))
#define opcodeInfoTable_op254 (*(unsigned char **)(&opcodeInfoTable + 254*4))
#define opcodeInfoTable_op255 (*(unsigned char **)(&opcodeInfoTable + 255*4))
#define opcodeInfoTable_op256 (*(unsigned char **)(&opcodeInfoTable + 256*4))
#define opcodeInfoTable_op257 (*(unsigned char **)(&opcodeInfoTable + 257*4))
#define opcodeInfoTable_op258 (*(unsigned char **)(&opcodeInfoTable + 258*4))
#define opcodeInfoTable_op259 (*(unsigned char **)(&opcodeInfoTable + 259*4))
#define opcodeInfoTable_op260 (*(unsigned char **)(&opcodeInfoTable + 260*4))
#define opcodeInfoTable_op261 (*(unsigned char **)(&opcodeInfoTable + 261*4))
#define opcodeInfoTable_op262 (*(unsigned char **)(&opcodeInfoTable + 262*4))
#define opcodeInfoTable_op263 (*(unsigned char **)(&opcodeInfoTable + 263*4))
#define opcodeInfoTable_op264 (*(unsigned char **)(&opcodeInfoTable + 264*4))
#define opcodeInfoTable_op265 (*(unsigned char **)(&opcodeInfoTable + 265*4))
#define opcodeInfoTable_op266 (*(unsigned char **)(&opcodeInfoTable + 266*4))
#define opcodeInfoTable_op267 (*(unsigned char **)(&opcodeInfoTable + 267*4))
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
 * bug hitting a *different* object - gld_initContextDispatch (part_015.c) wires up a 4-slot allocator
 * vtable {generic-alloc, calloc, realloc, free} at param_1+0x24c.."+0x258, and the calloc
 * slot (+0x250, read back later as param_1+0x10 inside gld_buildUnitSetupCmdList, part_016.c) was
 * PTR_001e8b14 - declared as a plain byte here, so the compiled read only got PTR_001e8b14's
 * top byte (observed live as the literal integer 1) instead of the real 4-byte pointer to
 * _calloc that data.s actually stores there (`.long _calloc`), crashing with pc=0 the moment
 * gld_buildUnitSetupCmdList called it as `(*pcVar8)(1, size)`. Confirmed the neighbors in this same data.s
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
