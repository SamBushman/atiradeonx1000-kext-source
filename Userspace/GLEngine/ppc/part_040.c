#include "decls.h"

/* _gleInterpolEyeAllFlatw @ 0xb9c7c (640 bytes) */
void _gleInterpolEyeAllFlatw(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startTexCoordQ;
  float startWord16;
  float startWord13;
  float clipYThenNdcY;
  float startTexCoordR;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endTexCoordQ;
  float startWord09;
  float endTexCoordT;
  float startWord0a;
  float endTexCoordR;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  float clipXThenNdcX;
  float startTexCoordT;
  float startWord1e;
  float endWord13;
  float windowScaleZ;
  float startWord0b;
  uint clipOutcode;
  uint texEnableMask;
  uint texUnit;
  int endVertexAtUnit;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  startWord13 = startVertex[0x13];
  endWord13 = *(float *)(endVertex + 0x4c);
  outVertex[0x17] =
       (edgeT * (*(float *)(endVertex + 0x5c) - startVertex[0x17]) + startVertex[0x17]);
  outVertex[0x13] =
       (edgeT * (endWord13 - startWord13) + startWord13);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        if (startVertex == outVertex) {
          return;
        }
        *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
        *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
        *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
        outVertex[0x12] = startVertex[0x12];
        *(undefined8 *)(outVertex + 0x14) = *(undefined8 *)(startVertex + 0x14);
        startWord16 = startVertex[0x16];
        outVertex[0x1d] = startVertex[0x1d];
        startWord1e = startVertex[0x1e];
        outVertex[0x16] = startWord16;
        outVertex[0x1e] = startWord1e;
        return;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           (edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20]);
      outVertex[texUnit * 4 + 0x21] =
           (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outVertex[texUnit * 4 + 0x22] =
           (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outVertex[texUnit * 4 + 0x23] =
           (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeAllSmooth @ 0xb9efc (892 bytes) */
void _gleInterpolEyeAllSmooth(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float outTexCoordS;
  float startWord10;
  float endWord0d;
  float startWord13;
  char startFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord11;
  float endWord0e;
  float endWord13;
  float windowScaleZ;
  float startWord0b;
  float clipYThenNdcY;
  float outTexCoordR;
  float endWord10;
  float startWord15;
  float startWord0c;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float outTexCoordQ;
  float endWord11;
  float endWord15;
  float endWord0c;
  float startWord09;
  float startWord0a;
  float outInvW;
  float startWord0f;
  float endWord09;
  float startWord0e;
  float endWord0a;
  float startWord0d;
  float startClipX;
  float endWord0f;
  float endClipZ;
  float negClipW;
  float startWord14;
  float endClipX;
  float endClipY;
  float endWord14;
  float startClipZ;
  float startWord16;
  float endWord16;
  uint texMaskRemaining;
  int endVertexAtUnit;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  float startClipW;
  float endTexCoordT;
  float endClipW;
  float startTexCoordS;
  float startTexCoordR;
  float startTexCoordT;
  float endTexCoordQ;
  float endTexCoordS;
  float endTexCoordR;
  float startTexCoordQ;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  clipOutcode = 0;
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord13 = startVertex[0x13];
  texUnit = 0;
  endWord13 = *(float *)(endVertex + 0x4c);
  startWord0c = startVertex[0xc];
  endWord0c = *(float *)(endVertex + 0x30);
  startWord0f = startVertex[0xf];
  startWord0e = startVertex[0xe];
  startWord0d = startVertex[0xd];
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x17] =
       (edgeT * (*(float *)(endVertex + 0x5c) - startVertex[0x17]) + startVertex[0x17]);
  outVertex[0x13] = (edgeT * (endWord13 - startWord13) + startWord13)
  ;
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  startWord14 = startVertex[0x14];
  endWord14 = *(float *)(endVertex + 0x50);
  outVertex[0xc] = (edgeT * (endWord0c - startWord0c) + startWord0c);
  startWord15 = startVertex[0x15];
  endWord15 = *(float *)(endVertex + 0x54);
  startWord16 = startVertex[0x16];
  endWord16 = *(float *)(endVertex + 0x58);
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  outVertex[0x14] =
       (edgeT * (endWord14 - startWord14) + startWord14);
  outVertex[0x15] = (edgeT * (endWord15 - startWord15) + startWord15)
  ;
  outVertex[0x16] =
       (edgeT * (endWord16 - startWord16) + startWord16);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        startWord10 = startVertex[0x10];
        startWord11 = startVertex[0x11];
        endWord10 = *(float *)(endVertex + 0x40);
        endWord11 = *(float *)(endVertex + 0x44);
        outVertex[0x12] =
             (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
        outVertex[0x10] =
             (edgeT * (endWord10 - startWord10) + startWord10);
        outVertex[0x11] =
             (edgeT * (endWord11 - startWord11) + startWord11);
        if (startVertex != outVertex) {
          outVertex[0x1d] = startVertex[0x1d];
          outVertex[0x1e] = startVertex[0x1e];
        }
        return;
      }
    }
    else {
      startTexCoordQ = (double)startVertex[texUnit * 4 + 0x23];
      startTexCoordS = (double)startVertex[texUnit * 4 + 0x20];
      startTexCoordT = (double)startVertex[texUnit * 4 + 0x21];
      startTexCoordR = (double)startVertex[texUnit * 4 + 0x22];
      if (startFlagByte7f == '\0') {
        startClipW = (double)startVertex[7];
        startTexCoordQ = (double)(startTexCoordQ * startClipW);
        startTexCoordS = (double)(startTexCoordS * startClipW);
        startTexCoordT = (double)(startTexCoordT * startClipW);
        startTexCoordR = (double)(startTexCoordR * startClipW);
      }
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endTexCoordQ = (double)*(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = (double)*(float *)(endVertexAtUnit + 0x80);
      endTexCoordT = (double)*(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = (double)*(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = (double)*(float *)(endVertex + 0x1c);
        endTexCoordQ = (double)(endTexCoordQ * endClipW);
        endTexCoordS = (double)(endTexCoordS * endClipW);
        endTexCoordT = (double)(endTexCoordT * endClipW);
        endTexCoordR = (double)(endTexCoordR * endClipW);
      }
      outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
      outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        outTexCoordQ = outTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        outTexCoordT = outTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = outTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = outTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeAllSmoothw @ 0xba278 (804 bytes) */
void _gleInterpolEyeAllSmoothw(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startTexCoordQ;
  float startWord10;
  float endWord0d;
  float startWord13;
  float clipXThenNdcX;
  float startTexCoordT;
  float startWord11;
  float endWord0e;
  float endWord13;
  float windowScaleZ;
  float startWord0b;
  float clipYThenNdcY;
  float startTexCoordR;
  float endWord10;
  float startWord15;
  float startWord0c;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endTexCoordQ;
  float endWord11;
  float endWord15;
  float endWord0c;
  float startWord09;
  float endTexCoordT;
  float startWord0f;
  float startWord0a;
  float endTexCoordR;
  float startWord0e;
  float endWord09;
  float endWord0a;
  float startWord0d;
  float startClipX;
  float endWord0f;
  float endClipZ;
  float negClipW;
  float startWord14;
  float endClipX;
  float endClipY;
  float endWord14;
  float startClipZ;
  float startWord16;
  float endWord16;
  uint texMaskRemaining;
  uint clipOutcode;
  uint texEnableMask;
  uint texUnit;
  int endVertexAtUnit;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  clipOutcode = 0;
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  startWord13 = startVertex[0x13];
  endWord13 = *(float *)(endVertex + 0x4c);
  startWord0c = startVertex[0xc];
  endWord0c = *(float *)(endVertex + 0x30);
  startWord0f = startVertex[0xf];
  startWord0e = startVertex[0xe];
  startWord0d = startVertex[0xd];
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x17] =
       (edgeT * (*(float *)(endVertex + 0x5c) - startVertex[0x17]) + startVertex[0x17]);
  outVertex[0x13] = (edgeT * (endWord13 - startWord13) + startWord13)
  ;
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  startWord14 = startVertex[0x14];
  endWord14 = *(float *)(endVertex + 0x50);
  outVertex[0xc] = (edgeT * (endWord0c - startWord0c) + startWord0c);
  startWord15 = startVertex[0x15];
  endWord15 = *(float *)(endVertex + 0x54);
  startWord16 = startVertex[0x16];
  endWord16 = *(float *)(endVertex + 0x58);
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  outVertex[0x14] =
       (edgeT * (endWord14 - startWord14) + startWord14);
  outVertex[0x15] = (edgeT * (endWord15 - startWord15) + startWord15)
  ;
  outVertex[0x16] =
       (edgeT * (endWord16 - startWord16) + startWord16);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        startWord10 = startVertex[0x10];
        startWord11 = startVertex[0x11];
        endWord10 = *(float *)(endVertex + 0x40);
        endWord11 = *(float *)(endVertex + 0x44);
        outVertex[0x12] =
             (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
        outVertex[0x10] =
             (edgeT * (endWord10 - startWord10) + startWord10);
        outVertex[0x11] =
             (edgeT * (endWord11 - startWord11) + startWord11);
        if (startVertex != outVertex) {
          outVertex[0x1d] = startVertex[0x1d];
          outVertex[0x1e] = startVertex[0x1e];
        }
        return;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           (edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20]);
      outVertex[texUnit * 4 + 0x21] =
           (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outVertex[texUnit * 4 + 0x22] =
           (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outVertex[texUnit * 4 + 0x23] =
           (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO0000 @ 0xba59c (732 bytes) */
uint _gleInterpolClipNO0000(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float fVar4;
  float startWord12;
  float clipYThenNdcY;
  float windowScaleZ;
  float clipZThenNdcZ;
  float fVar7;
  float endClipX;
  float fVar9;
  float fVar10;
  float fVar11;
  float startWord1e;
  float windowBiasZ;
  uint clipOutcode;
  
  fVar4 = *(float *)(endVertex + 0x1c);
  fVar11 = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  fVar7 = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  fVar9 = *(float *)(endVertex + 0x14);
  fVar10 = *(float *)(endVertex + 0x18);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      fVar10 = (fVar7 + clipZThenNdcZ) / ((fVar7 + clipZThenNdcZ) - (fVar4 + fVar10));
      fVar4 = fVar10 * (fVar4 - fVar7) + fVar7;
      clipZThenNdcZ = -fVar4;
      if (fVar4 < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      fVar10 = (fVar7 - clipZThenNdcZ) / ((fVar7 - clipZThenNdcZ) - (fVar4 - fVar10));
      fVar4 = fVar10 * (fVar4 - fVar7) + fVar7;
      clipZThenNdcZ = fVar4;
    }
    insideFrustum = clipOutcode == 0;
    fVar7 = fVar10 * (endClipX - fVar11) + fVar11;
    clipYThenNdcY = fVar10 * (fVar9 - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000ba7a0;
    fVar11 = -fVar4;
    if (clipYThenNdcY < fVar11) {
      clipOutcode = 4;
    }
    else {
      if (!(fVar4 <= clipYThenNdcY)) goto LAB_000ba700;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        fVar11 = (fVar7 + fVar11) / ((fVar7 + fVar11) - (fVar4 + endClipX));
        fVar4 = fVar11 * (fVar4 - fVar7) + fVar7;
        fVar7 = -fVar4;
        clipOutcode = (uint)(fVar4 <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        fVar11 = (fVar7 - fVar11) / ((fVar7 - fVar11) - (fVar4 - endClipX));
        fVar7 = fVar11 * (fVar4 - fVar7) + fVar7;
        fVar4 = fVar7;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = fVar11 * (fVar9 - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = fVar11 * (fVar10 - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000ba7a0;
    }
    if (clipPlane == 4) {
      fVar9 = (fVar7 + clipYThenNdcY) / ((fVar7 + clipYThenNdcY) - (fVar4 + fVar9));
      fVar4 = fVar9 * (fVar4 - fVar7) + fVar7;
      clipYThenNdcY = -fVar4;
      clipOutcode = (uint)(fVar4 <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      fVar9 = (fVar7 - clipYThenNdcY) / ((fVar7 - clipYThenNdcY) - (fVar4 - fVar9));
      clipYThenNdcY = fVar9 * (fVar4 - fVar7) + fVar7;
      fVar4 = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    fVar7 = fVar9 * (endClipX - fVar11) + fVar11;
    clipZThenNdcZ = fVar9 * (fVar10 - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000ba7a0;
    fVar11 = -fVar4;
LAB_000ba700:
    if (fVar7 < fVar11) {
      clipOutcode = 0x10;
    }
    else {
      if (!(fVar4 <= fVar7)) goto LAB_000ba7a0;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000ba7a0:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = fVar7;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = fVar4;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (fVar4 != FLOAT_00108e54) {
      fVar4 = FLOAT_00108e54 / fVar4;
      fVar7 = fVar7 * fVar4;
      clipYThenNdcY = clipYThenNdcY * fVar4;
      clipZThenNdcZ = clipZThenNdcZ * fVar4;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar7 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar4;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  if (startVertex != outVertex) {
    *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
    *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
    *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
    *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
    *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
    startWord12 = startVertex[0x12];
    outVertex[0x1d] = startVertex[0x1d];
    startWord1e = startVertex[0x1e];
    outVertex[0x12] = startWord12;
    outVertex[0x1e] = startWord1e;
  }
  return clipOutcode;
}

/* _gleInterpolClipNO0010 @ 0xba878 (752 bytes) */
uint _gleInterpolClipNO0010(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord12;
  float windowBiasZ;
  float clipZThenNdcZ;
  float clipWThenInvW;
  float negClipW;
  float endClipX;
  float endClipY;
  float endClipZ;
  float endClipW;
  float edgeT;
  float clipYThenNdcY;
  float startWord1e;
  float windowScaleZ;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000baa7c;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000ba9dc;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000baa7c;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000baa7c;
    negClipW = -clipWThenInvW;
LAB_000ba9dc:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000baa7c;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000baa7c:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  outVertex[0x13] = edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13];
  if (startVertex != outVertex) {
    *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
    *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
    *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
    *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
    *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
    startWord12 = startVertex[0x12];
    outVertex[0x1d] = startVertex[0x1d];
    startWord1e = startVertex[0x1e];
    outVertex[0x12] = startWord12;
    outVertex[0x1e] = startWord1e;
  }
  return clipOutcode;
}

/* _gleInterpolClipNO0100 @ 0xbab68 (868 bytes) */
uint _gleInterpolClipNO0100(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float outTexCoordR;
  float endTexCoordS;
  float startWord12;
  float windowBiasZ;
  float clipZThenNdcZ;
  float endTexCoordR;
  float outInvW;
  float clipWThenInvW;
  float endToOutTexCoordQ;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endClipX;
  float endClipY;
  float endClipZ;
  float endClipW2;
  float edgeT;
  float clipYThenNdcY;
  float endToOutTexCoordT;
  float startWord1e;
  float windowScaleZ;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bad6c;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000baccc;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bad6c;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bad6c;
    negClipW = -clipWThenInvW;
LAB_000baccc:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bad6c;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bad6c:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  endTexCoordS = *(float *)(endVertex + 0x80);
  endToOutTexCoordT = *(float *)(endVertex + 0x84);
  endTexCoordR = *(float *)(endVertex + 0x88);
  endToOutTexCoordQ = *(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    endClipW = *(float *)(endVertex + 0x1c);
    endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
    endTexCoordS = endTexCoordS * endClipW;
    endToOutTexCoordT = endToOutTexCoordT * endClipW;
    endTexCoordR = endTexCoordR * endClipW;
  }
  outTexCoordS = edgeT * (endTexCoordS - startVertex[0x20]) + startVertex[0x20];
  endToOutTexCoordT = edgeT * (endToOutTexCoordT - startVertex[0x21]) + startVertex[0x21];
  endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - startVertex[0x23]) + startVertex[0x23];
  outTexCoordR = edgeT * (endTexCoordR - startVertex[0x22]) + startVertex[0x22];
  if (insideFrustum) {
    outInvW = outVertex[3];
    endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    endToOutTexCoordT = endToOutTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = endToOutTexCoordT;
  outVertex[0x22] = outTexCoordR;
  outVertex[0x23] = endToOutTexCoordQ;
  if (startVertex != outVertex) {
    *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
    *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
    *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
    *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
    *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
    startWord12 = startVertex[0x12];
    outVertex[0x1d] = startVertex[0x1d];
    startWord1e = startVertex[0x1e];
    outVertex[0x12] = startWord12;
    outVertex[0x1e] = startWord1e;
  }
  return clipOutcode;
}

/* _gleInterpolClipNO0100w @ 0xbaecc (812 bytes) */
uint _gleInterpolClipNO0100w(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord12;
  float startWord21;
  float windowBiasZ;
  float clipZThenNdcZ;
  float startWord23;
  float clipWThenInvW;
  float endWord23;
  float negClipW;
  float endWord21;
  float endClipX;
  float endClipY;
  float endWord22;
  float endClipZ;
  float endClipW;
  float edgeT;
  float clipYThenNdcY;
  float startWord1e;
  float startWord22;
  float windowScaleZ;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bb0d0;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bb030;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bb0d0;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bb0d0;
    negClipW = -clipWThenInvW;
LAB_000bb030:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bb0d0;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bb0d0:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord21 = startVertex[0x21];
  startWord22 = startVertex[0x22];
  startWord23 = startVertex[0x23];
  endWord23 = *(float *)(endVertex + 0x8c);
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  outVertex[0x20] = edgeT * (*(float *)(endVertex + 0x80) - startVertex[0x20]) + startVertex[0x20];
  outVertex[0x23] = edgeT * (endWord23 - startWord23) + startWord23;
  outVertex[0x21] = edgeT * (endWord21 - startWord21) + startWord21;
  outVertex[0x22] = edgeT * (endWord22 - startWord22) + startWord22;
  if (startVertex != outVertex) {
    *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
    *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
    *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
    *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
    *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
    startWord12 = startVertex[0x12];
    outVertex[0x1d] = startVertex[0x1d];
    startWord1e = startVertex[0x1e];
    outVertex[0x12] = startWord12;
    outVertex[0x1e] = startWord1e;
  }
  return clipOutcode;
}

/* _gleInterpolClipNO0110 @ 0xbb1f8 (888 bytes) */
uint _gleInterpolClipNO0110(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  char endFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordR;
  float endTexCoordS;
  float startWord12;
  float windowBiasZ;
  float clipZThenNdcZ;
  float endTexCoordR;
  float outInvW;
  float clipWThenInvW;
  float endToOutTexCoordQ;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endClipX;
  float endClipY;
  float endClipZ;
  float endClipW2;
  float edgeT;
  float clipYThenNdcY;
  float endToOutTexCoordT;
  float startWord1e;
  float windowScaleZ;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bb3fc;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bb35c;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bb3fc;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bb3fc;
    negClipW = -clipWThenInvW;
LAB_000bb35c:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bb3fc;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bb3fc:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  endFlagByte7f = *(char *)(endVertex + 0x7f);
  outVertex[0x13] = edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13];
  endTexCoordS = *(float *)(endVertex + 0x80);
  endToOutTexCoordT = *(float *)(endVertex + 0x84);
  endTexCoordR = *(float *)(endVertex + 0x88);
  endToOutTexCoordQ = *(float *)(endVertex + 0x8c);
  if (endFlagByte7f == '\0') {
    endClipW = *(float *)(endVertex + 0x1c);
    endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
    endTexCoordS = endTexCoordS * endClipW;
    endToOutTexCoordT = endToOutTexCoordT * endClipW;
    endTexCoordR = endTexCoordR * endClipW;
  }
  outTexCoordS = edgeT * (endTexCoordS - startVertex[0x20]) + startVertex[0x20];
  endToOutTexCoordT = edgeT * (endToOutTexCoordT - startVertex[0x21]) + startVertex[0x21];
  endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - startVertex[0x23]) + startVertex[0x23];
  outTexCoordR = edgeT * (endTexCoordR - startVertex[0x22]) + startVertex[0x22];
  if (insideFrustum) {
    outInvW = outVertex[3];
    endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    endToOutTexCoordT = endToOutTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = endToOutTexCoordT;
  outVertex[0x22] = outTexCoordR;
  outVertex[0x23] = endToOutTexCoordQ;
  if (startVertex != outVertex) {
    *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
    *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
    *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
    *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
    *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
    startWord12 = startVertex[0x12];
    outVertex[0x1d] = startVertex[0x1d];
    startWord1e = startVertex[0x1e];
    outVertex[0x12] = startWord12;
    outVertex[0x1e] = startWord1e;
  }
  return clipOutcode;
}

/* _gleInterpolClipNO0110w @ 0xbb570 (832 bytes) */
uint _gleInterpolClipNO0110w(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord12;
  float startWord21;
  float windowBiasZ;
  float clipZThenNdcZ;
  float startWord23;
  float clipWThenInvW;
  float endWord23;
  float negClipW;
  float endWord21;
  float endClipX;
  float endClipY;
  float endWord22;
  float endClipZ;
  float endClipW;
  float edgeT;
  float clipYThenNdcY;
  float startWord1e;
  float startWord22;
  float windowScaleZ;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bb774;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bb6d4;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bb774;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bb774;
    negClipW = -clipWThenInvW;
LAB_000bb6d4:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bb774;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bb774:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  outVertex[0x13] = edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13];
  startWord21 = startVertex[0x21];
  startWord22 = startVertex[0x22];
  startWord23 = startVertex[0x23];
  endWord23 = *(float *)(endVertex + 0x8c);
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  outVertex[0x20] = edgeT * (*(float *)(endVertex + 0x80) - startVertex[0x20]) + startVertex[0x20];
  outVertex[0x21] = edgeT * (endWord21 - startWord21) + startWord21;
  outVertex[0x23] = edgeT * (endWord23 - startWord23) + startWord23;
  outVertex[0x22] = edgeT * (endWord22 - startWord22) + startWord22;
  if (startVertex != outVertex) {
    *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
    *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
    *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
    *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
    *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
    startWord12 = startVertex[0x12];
    outVertex[0x1d] = startVertex[0x1d];
    startWord1e = startVertex[0x1e];
    outVertex[0x12] = startWord12;
    outVertex[0x1e] = startWord1e;
  }
  return clipOutcode;
}

/* _gleInterpolClipNO0200 @ 0xbb8b0 (924 bytes) */
uint _gleInterpolClipNO0200(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float endToOutTexCoordQ;
  float startWord12;
  float windowScaleZ;
  float clipZThenNdcZ;
  float endToOutTexCoordT;
  float clipWThenInvW;
  float endTexCoordR;
  float outInvW;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endClipX;
  float endClipY;
  float endClipZ;
  float endClipW2;
  float edgeT;
  uint texMaskRemaining;
  float clipYThenNdcY;
  float outTexCoordR;
  float endTexCoordS;
  float startWord1e;
  float windowBiasZ;
  uint texEnableMask;
  uint clipOutcode;
  int endVertexAtUnit;
  uint texUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bbab4;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bba14;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bbab4;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bbab4;
    negClipW = -clipWThenInvW;
LAB_000bba14:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bbab4;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bbab4:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  texUnit = 0;
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        if (startVertex != outVertex) {
          *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
          *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
          *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
          *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
          *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
          startWord12 = startVertex[0x12];
          outVertex[0x1d] = startVertex[0x1d];
          startWord1e = startVertex[0x1e];
          outVertex[0x12] = startWord12;
          outVertex[0x1e] = startWord1e;
        }
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endToOutTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = *(float *)(endVertexAtUnit + 0x80);
      endToOutTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = *(float *)(endVertex + 0x1c);
        endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
        endTexCoordS = endTexCoordS * endClipW;
        endToOutTexCoordT = endToOutTexCoordT * endClipW;
        endTexCoordR = endTexCoordR * endClipW;
      }
      outTexCoordS = edgeT * (endTexCoordS - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20];
      endToOutTexCoordT = edgeT * (endToOutTexCoordT - startVertex[texUnit * 4 + 0x21]) + startVertex[texUnit * 4 + 0x21];
      outTexCoordR = edgeT * (endTexCoordR - startVertex[texUnit * 4 + 0x22]) + startVertex[texUnit * 4 + 0x22];
      endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - startVertex[texUnit * 4 + 0x23]) + startVertex[texUnit * 4 + 0x23];
      if (insideFrustum) {
        outInvW = outVertex[3];
        endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        endToOutTexCoordT = endToOutTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = endToOutTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = endToOutTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO0200w @ 0xbbc4c (868 bytes) */
uint _gleInterpolClipNO0200w(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startTexCoordQ;
  float startWord12;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startTexCoordR;
  float clipWThenInvW;
  float endTexCoordQ;
  float negClipW;
  float endTexCoordT;
  float endClipX;
  float endTexCoordR;
  float endClipY;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint texMaskRemaining;
  float clipYThenNdcY;
  float startTexCoordT;
  float startWord1e;
  float windowBiasZ;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  int endVertexAtUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bbe50;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bbdb0;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bbe50;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bbe50;
    negClipW = -clipWThenInvW;
LAB_000bbdb0:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bbe50;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bbe50:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  texUnit = 0;
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        if (startVertex != outVertex) {
          *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
          *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
          *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
          *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
          *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
          startWord12 = startVertex[0x12];
          outVertex[0x1d] = startVertex[0x1d];
          startWord1e = startVertex[0x1e];
          outVertex[0x12] = startWord12;
          outVertex[0x1e] = startWord1e;
        }
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) +
           startVertex[texUnit * 4 + 0x20];
      outVertex[texUnit * 4 + 0x21] = edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT;
      outVertex[texUnit * 4 + 0x22] = edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR;
      outVertex[texUnit * 4 + 0x23] = edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO0210 @ 0xbbfb0 (944 bytes) */
uint _gleInterpolClipNO0210(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float endToOutTexCoordQ;
  float startWord12;
  float windowScaleZ;
  float clipZThenNdcZ;
  float endToOutTexCoordT;
  float clipWThenInvW;
  float endTexCoordR;
  float outInvW;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endClipX;
  float endClipY;
  float endClipZ;
  float endClipW2;
  float edgeT;
  uint texMaskRemaining;
  float clipYThenNdcY;
  float outTexCoordR;
  float endTexCoordS;
  float startWord1e;
  float windowBiasZ;
  uint texEnableMask;
  uint clipOutcode;
  int endVertexAtUnit;
  uint texUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bc1b4;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bc114;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bc1b4;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bc1b4;
    negClipW = -clipWThenInvW;
LAB_000bc114:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bc1b4;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bc1b4:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  outVertex[0x13] = edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13];
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        if (startVertex != outVertex) {
          *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
          *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
          *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
          *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
          *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
          startWord12 = startVertex[0x12];
          outVertex[0x1d] = startVertex[0x1d];
          startWord1e = startVertex[0x1e];
          outVertex[0x12] = startWord12;
          outVertex[0x1e] = startWord1e;
        }
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endToOutTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = *(float *)(endVertexAtUnit + 0x80);
      endToOutTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = *(float *)(endVertex + 0x1c);
        endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
        endTexCoordS = endTexCoordS * endClipW;
        endToOutTexCoordT = endToOutTexCoordT * endClipW;
        endTexCoordR = endTexCoordR * endClipW;
      }
      outTexCoordS = edgeT * (endTexCoordS - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20];
      endToOutTexCoordT = edgeT * (endToOutTexCoordT - startVertex[texUnit * 4 + 0x21]) + startVertex[texUnit * 4 + 0x21];
      outTexCoordR = edgeT * (endTexCoordR - startVertex[texUnit * 4 + 0x22]) + startVertex[texUnit * 4 + 0x22];
      endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - startVertex[texUnit * 4 + 0x23]) + startVertex[texUnit * 4 + 0x23];
      if (insideFrustum) {
        outInvW = outVertex[3];
        endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        endToOutTexCoordT = endToOutTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = endToOutTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = endToOutTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO0210w @ 0xbc360 (888 bytes) */
uint _gleInterpolClipNO0210w(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startTexCoordQ;
  float startWord12;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startTexCoordR;
  float clipWThenInvW;
  float endTexCoordQ;
  float negClipW;
  float endTexCoordT;
  float endClipX;
  float endTexCoordR;
  float endClipY;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint texMaskRemaining;
  float clipYThenNdcY;
  float startTexCoordT;
  float startWord1e;
  float windowBiasZ;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  int endVertexAtUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bc564;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bc4c4;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bc564;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bc564;
    negClipW = -clipWThenInvW;
LAB_000bc4c4:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bc564;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bc564:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  outVertex[0x13] = edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13];
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        if (startVertex != outVertex) {
          *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
          *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
          *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
          *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
          *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
          startWord12 = startVertex[0x12];
          outVertex[0x1d] = startVertex[0x1d];
          startWord1e = startVertex[0x1e];
          outVertex[0x12] = startWord12;
          outVertex[0x1e] = startWord1e;
        }
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) +
           startVertex[texUnit * 4 + 0x20];
      outVertex[texUnit * 4 + 0x21] = edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT;
      outVertex[texUnit * 4 + 0x22] = edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR;
      outVertex[texUnit * 4 + 0x23] = edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO1000 @ 0xbc6d8 (740 bytes) */
uint _gleInterpolClipNO1000(int glContext,int startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord0f;
  float windowBiasZ;
  float clipYThenNdcY;
  float startWord0d;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startWord0e;
  float clipWThenInvW;
  float endWord0f;
  float negClipW;
  float endWord0d;
  float endClipX;
  float endClipY;
  float endWord0e;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = *(float *)(startVertex + 0x10);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  clipZThenNdcZ = *(float *)(startVertex + 0x18);
  clipWThenInvW = *(float *)(startVertex + 0x1c);
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bc8dc;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bc83c;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bc8dc;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bc8dc;
    negClipW = -clipWThenInvW;
LAB_000bc83c:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bc8dc;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bc8dc:
  startFlagByte7c = *(byte *)(startVertex + 0x7c);
  startFlagByte7e = *(byte *)(startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord0f = *(float *)(startVertex + 0x3c);
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = edgeT * (*(float *)(endVertex + 0x30) - *(float *)(startVertex + 0x30)) +
                 *(float *)(startVertex + 0x30);
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  return clipOutcode;
}

/* _gleInterpolClipNO1001 @ 0xbc9bc (824 bytes) */
uint _gleInterpolClipNO1001(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord0b;
  float startWord11;
  float windowBiasZ;
  float clipYThenNdcY;
  float startWord09;
  float startWord12;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startWord0a;
  float endWord11;
  float clipWThenInvW;
  float endWord0b;
  float endWord12;
  float negClipW;
  float endWord09;
  float endClipX;
  float endClipY;
  float endWord0a;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bcbc0;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bcb20;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bcbc0;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bcbc0;
    negClipW = -clipWThenInvW;
LAB_000bcb20:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bcbc0;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bcbc0:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord11 = startVertex[0x11];
  startWord12 = startVertex[0x12];
  endWord11 = *(float *)(endVertex + 0x44);
  endWord12 = *(float *)(endVertex + 0x48);
  outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
  outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
  outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
  if (startVertex != outVertex) {
    outVertex[0x1d] = startVertex[0x1d];
    outVertex[0x1e] = startVertex[0x1e];
  }
  startWord0b = startVertex[0xb];
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord0b = *(float *)(endVertex + 0x2c);
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
  outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
  outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
  outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
  return clipOutcode;
}

/* _gleInterpolClipNO1010 @ 0xbccf4 (760 bytes) */
uint _gleInterpolClipNO1010(int glContext,int startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord0f;
  float windowBiasZ;
  float clipYThenNdcY;
  float startWord0c;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startWord0d;
  float clipWThenInvW;
  float endWord0f;
  float negClipW;
  float endWord0c;
  float endClipX;
  float endClipY;
  float startWord0e;
  float endClipZ;
  float endWord0d;
  float endClipW;
  float endWord0e;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = *(float *)(startVertex + 0x10);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  clipZThenNdcZ = *(float *)(startVertex + 0x18);
  clipWThenInvW = *(float *)(startVertex + 0x1c);
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bcef8;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bce58;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bcef8;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bcef8;
    negClipW = -clipWThenInvW;
LAB_000bce58:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bcef8;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bcef8:
  startFlagByte7c = *(byte *)(startVertex + 0x7c);
  startFlagByte7e = *(byte *)(startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord0f = *(float *)(startVertex + 0x3c);
  startWord0c = *(float *)(startVertex + 0x30);
  startWord0d = *(float *)(startVertex + 0x34);
  endWord0f = *(float *)(endVertex + 0x3c);
  endWord0c = *(float *)(endVertex + 0x30);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0d = *(float *)(endVertex + 0x34);
  outVertex[0x13] =
       edgeT * (*(float *)(endVertex + 0x4c) - *(float *)(startVertex + 0x4c)) +
       *(float *)(startVertex + 0x4c);
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = edgeT * (endWord0c - startWord0c) + startWord0c;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  return clipOutcode;
}

/* _gleInterpolClipNO1011 @ 0xbcfec (844 bytes) */
uint _gleInterpolClipNO1011(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord0b;
  float startWord10;
  float windowBiasZ;
  float clipYThenNdcY;
  float startWord09;
  float startWord11;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startWord0a;
  float endWord10;
  float clipWThenInvW;
  float endWord0b;
  float endWord11;
  float negClipW;
  float endWord09;
  float startWord12;
  float endClipX;
  float endClipY;
  float endWord0a;
  float endWord12;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bd1f0;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bd150;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bd1f0;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bd1f0;
    negClipW = -clipWThenInvW;
LAB_000bd150:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bd1f0;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bd1f0:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord10 = startVertex[0x10];
  startWord11 = startVertex[0x11];
  endWord10 = *(float *)(endVertex + 0x40);
  endWord11 = *(float *)(endVertex + 0x44);
  startWord12 = startVertex[0x12];
  outVertex[0x13] = edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13];
  endWord12 = *(float *)(endVertex + 0x48);
  outVertex[0x10] = edgeT * (endWord10 - startWord10) + startWord10;
  outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
  outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
  if (startVertex != outVertex) {
    outVertex[0x1d] = startVertex[0x1d];
    outVertex[0x1e] = startVertex[0x1e];
  }
  startWord0b = startVertex[0xb];
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord0b = *(float *)(endVertex + 0x2c);
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
  outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
  outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
  outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
  return clipOutcode;
}

/* _gleInterpolClipNO1100 @ 0xbd338 (876 bytes) */
uint _gleInterpolClipNO1100(int glContext,int startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  char endFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordR;
  float endTexCoordS;
  float startWord0d;
  float windowBiasZ;
  float clipYThenNdcY;
  float endToOutTexCoordT;
  float startWord0e;
  float windowScaleZ;
  float clipZThenNdcZ;
  float endTexCoordR;
  float outInvW;
  float startWord0f;
  float clipWThenInvW;
  float endToOutTexCoordQ;
  float endWord0d;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endWord0e;
  float endClipX;
  float endClipY;
  float endWord0f;
  float endClipZ;
  float endClipW2;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = *(float *)(startVertex + 0x10);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  clipZThenNdcZ = *(float *)(startVertex + 0x18);
  clipWThenInvW = *(float *)(startVertex + 0x1c);
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bd53c;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bd49c;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bd53c;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bd53c;
    negClipW = -clipWThenInvW;
LAB_000bd49c:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bd53c;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bd53c:
  startFlagByte7c = *(byte *)(startVertex + 0x7c);
  startFlagByte7e = *(byte *)(startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  endFlagByte7f = *(char *)(endVertex + 0x7f);
  outVertex[0xc] = edgeT * (*(float *)(endVertex + 0x30) - *(float *)(startVertex + 0x30)) +
                 *(float *)(startVertex + 0x30);
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  endTexCoordS = *(float *)(endVertex + 0x80);
  endToOutTexCoordT = *(float *)(endVertex + 0x84);
  endTexCoordR = *(float *)(endVertex + 0x88);
  endToOutTexCoordQ = *(float *)(endVertex + 0x8c);
  if (endFlagByte7f == '\0') {
    endClipW = *(float *)(endVertex + 0x1c);
    endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
    endTexCoordS = endTexCoordS * endClipW;
    endToOutTexCoordT = endToOutTexCoordT * endClipW;
    endTexCoordR = endTexCoordR * endClipW;
  }
  outTexCoordS = edgeT * (endTexCoordS - *(float *)(startVertex + 0x80)) + *(float *)(startVertex + 0x80);
  endToOutTexCoordT = edgeT * (endToOutTexCoordT - *(float *)(startVertex + 0x84)) + *(float *)(startVertex + 0x84);
  endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - *(float *)(startVertex + 0x8c)) + *(float *)(startVertex + 0x8c);
  outTexCoordR = edgeT * (endTexCoordR - *(float *)(startVertex + 0x88)) + *(float *)(startVertex + 0x88);
  if (insideFrustum) {
    outInvW = outVertex[3];
    endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    endToOutTexCoordT = endToOutTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x23] = endToOutTexCoordQ;
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = endToOutTexCoordT;
  outVertex[0x22] = outTexCoordR;
  return clipOutcode;
}

/* _gleInterpolClipNO1100w @ 0xbd6a4 (820 bytes) */
uint _gleInterpolClipNO1100w(int glContext,int startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord23;
  float startWord0d;
  float windowBiasZ;
  float clipYThenNdcY;
  float startWord21;
  float startWord0e;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startWord22;
  float startWord0f;
  float clipWThenInvW;
  float endWord23;
  float endWord0d;
  float negClipW;
  float endWord21;
  float endWord0e;
  float endClipX;
  float endClipY;
  float endWord22;
  float endWord0f;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = *(float *)(startVertex + 0x10);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  clipZThenNdcZ = *(float *)(startVertex + 0x18);
  clipWThenInvW = *(float *)(startVertex + 0x1c);
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bd8a8;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bd808;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bd8a8;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bd8a8;
    negClipW = -clipWThenInvW;
LAB_000bd808:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bd8a8;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bd8a8:
  startFlagByte7c = *(byte *)(startVertex + 0x7c);
  startFlagByte7e = *(byte *)(startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0xc] = edgeT * (*(float *)(endVertex + 0x30) - *(float *)(startVertex + 0x30)) +
                 *(float *)(startVertex + 0x30);
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  startWord23 = *(float *)(startVertex + 0x8c);
  startWord21 = *(float *)(startVertex + 0x84);
  startWord22 = *(float *)(startVertex + 0x88);
  endWord23 = *(float *)(endVertex + 0x8c);
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  outVertex[0x20] =
       edgeT * (*(float *)(endVertex + 0x80) - *(float *)(startVertex + 0x80)) +
       *(float *)(startVertex + 0x80);
  outVertex[0x21] = edgeT * (endWord21 - startWord21) + startWord21;
  outVertex[0x23] = edgeT * (endWord23 - startWord23) + startWord23;
  outVertex[0x22] = edgeT * (endWord22 - startWord22) + startWord22;
  return clipOutcode;
}

/* _gleInterpolClipNO1101 @ 0xbd9d8 (960 bytes) */
uint _gleInterpolClipNO1101(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float outTexCoordQ;
  float endTexCoordS;
  float startWord0b;
  float startWord11;
  float windowBiasZ;
  float clipYThenNdcY;
  float outTexCoordR;
  float endTexCoordT;
  float startWord09;
  float startWord12;
  float windowScaleZ;
  float clipZThenNdcZ;
  float endTexCoordR;
  float startWord0a;
  float endWord11;
  float outInvW;
  float clipWThenInvW;
  float endTexCoordQ;
  float endWord0b;
  float endWord12;
  float negClipW;
  float outTexCoordT;
  float endWord09;
  float endClipW;
  float endClipX;
  float outTexCoordS;
  float endWord0a;
  float endClipY;
  float endClipZ;
  float endClipW2;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bdbdc;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bdb3c;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bdbdc;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bdbdc;
    negClipW = -clipWThenInvW;
LAB_000bdb3c:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bdbdc;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bdbdc:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  endTexCoordS = *(float *)(endVertex + 0x80);
  endTexCoordT = *(float *)(endVertex + 0x84);
  endTexCoordR = *(float *)(endVertex + 0x88);
  endTexCoordQ = *(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    endClipW = *(float *)(endVertex + 0x1c);
    endTexCoordQ = endTexCoordQ * endClipW;
    endTexCoordS = endTexCoordS * endClipW;
    endTexCoordT = endTexCoordT * endClipW;
    endTexCoordR = endTexCoordR * endClipW;
  }
  outTexCoordS = edgeT * (endTexCoordS - startVertex[0x20]) + startVertex[0x20];
  outTexCoordT = edgeT * (endTexCoordT - startVertex[0x21]) + startVertex[0x21];
  outTexCoordR = edgeT * (endTexCoordR - startVertex[0x22]) + startVertex[0x22];
  outTexCoordQ = edgeT * (endTexCoordQ - startVertex[0x23]) + startVertex[0x23];
  if (insideFrustum) {
    outInvW = outVertex[3];
    outTexCoordQ = outTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    outTexCoordT = outTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = outTexCoordT;
  outVertex[0x22] = outTexCoordR;
  outVertex[0x23] = outTexCoordQ;
  startWord11 = startVertex[0x11];
  startWord12 = startVertex[0x12];
  endWord11 = *(float *)(endVertex + 0x44);
  endWord12 = *(float *)(endVertex + 0x48);
  outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
  outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
  outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
  if (startVertex != outVertex) {
    outVertex[0x1d] = startVertex[0x1d];
    outVertex[0x1e] = startVertex[0x1e];
  }
  startWord0b = startVertex[0xb];
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord0b = *(float *)(endVertex + 0x2c);
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
  outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
  outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
  outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
  return clipOutcode;
}

/* _gleInterpolClipNO1101w @ 0xbdd98 (904 bytes) */
uint _gleInterpolClipNO1101w(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord0b;
  float startWord11;
  float startWord21;
  float windowBiasZ;
  float clipYThenNdcY;
  float startWord09;
  float startWord12;
  float startWord22;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startWord0a;
  float endWord11;
  float startWord23;
  float clipWThenInvW;
  float endWord0b;
  float endWord12;
  float endWord21;
  float negClipW;
  float endWord09;
  float endWord22;
  float endClipX;
  float endClipY;
  float endWord0a;
  float endWord23;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bdf9c;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bdefc;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bdf9c;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bdf9c;
    negClipW = -clipWThenInvW;
LAB_000bdefc:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bdf9c;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bdf9c:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord21 = startVertex[0x21];
  startWord22 = startVertex[0x22];
  startWord23 = startVertex[0x23];
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  endWord23 = *(float *)(endVertex + 0x8c);
  outVertex[0x20] = edgeT * (*(float *)(endVertex + 0x80) - startVertex[0x20]) + startVertex[0x20];
  outVertex[0x21] = edgeT * (endWord21 - startWord21) + startWord21;
  outVertex[0x22] = edgeT * (endWord22 - startWord22) + startWord22;
  outVertex[0x23] = edgeT * (endWord23 - startWord23) + startWord23;
  startWord11 = startVertex[0x11];
  startWord12 = startVertex[0x12];
  endWord11 = *(float *)(endVertex + 0x44);
  endWord12 = *(float *)(endVertex + 0x48);
  outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
  outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
  outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
  if (startVertex != outVertex) {
    outVertex[0x1d] = startVertex[0x1d];
    outVertex[0x1e] = startVertex[0x1e];
  }
  startWord0b = startVertex[0xb];
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord0b = *(float *)(endVertex + 0x2c);
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
  outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
  outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
  outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
  return clipOutcode;
}

/* _gleInterpolClipNO1110 @ 0xbe120 (896 bytes) */
uint _gleInterpolClipNO1110(int glContext,int startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  char endFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordR;
  float endTexCoordS;
  float startWord0c;
  float windowBiasZ;
  float clipYThenNdcY;
  float endToOutTexCoordT;
  float startWord0d;
  float windowScaleZ;
  float clipZThenNdcZ;
  float endTexCoordR;
  float outInvW;
  float startWord0f;
  float clipWThenInvW;
  float endToOutTexCoordQ;
  float endWord0c;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endWord0d;
  float endClipX;
  float endClipY;
  float startWord0e;
  float endClipZ;
  float endWord0f;
  float endClipW2;
  float endWord0e;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = *(float *)(startVertex + 0x10);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  clipZThenNdcZ = *(float *)(startVertex + 0x18);
  clipWThenInvW = *(float *)(startVertex + 0x1c);
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000be324;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000be284;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000be324;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000be324;
    negClipW = -clipWThenInvW;
LAB_000be284:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000be324;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000be324:
  startFlagByte7c = *(byte *)(startVertex + 0x7c);
  startFlagByte7e = *(byte *)(startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord0c = *(float *)(startVertex + 0x30);
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0c = *(float *)(endVertex + 0x30);
  endWord0d = *(float *)(endVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x13] =
       edgeT * (*(float *)(endVertex + 0x4c) - *(float *)(startVertex + 0x4c)) +
       *(float *)(startVertex + 0x4c);
  endWord0e = *(float *)(endVertex + 0x38);
  endFlagByte7f = *(char *)(endVertex + 0x7f);
  outVertex[0xc] = edgeT * (endWord0c - startWord0c) + startWord0c;
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  endTexCoordS = *(float *)(endVertex + 0x80);
  endToOutTexCoordT = *(float *)(endVertex + 0x84);
  endTexCoordR = *(float *)(endVertex + 0x88);
  endToOutTexCoordQ = *(float *)(endVertex + 0x8c);
  if (endFlagByte7f == '\0') {
    endClipW = *(float *)(endVertex + 0x1c);
    endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
    endTexCoordS = endTexCoordS * endClipW;
    endToOutTexCoordT = endToOutTexCoordT * endClipW;
    endTexCoordR = endTexCoordR * endClipW;
  }
  outTexCoordS = edgeT * (endTexCoordS - *(float *)(startVertex + 0x80)) + *(float *)(startVertex + 0x80);
  endToOutTexCoordT = edgeT * (endToOutTexCoordT - *(float *)(startVertex + 0x84)) + *(float *)(startVertex + 0x84);
  endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - *(float *)(startVertex + 0x8c)) + *(float *)(startVertex + 0x8c);
  outTexCoordR = edgeT * (endTexCoordR - *(float *)(startVertex + 0x88)) + *(float *)(startVertex + 0x88);
  if (insideFrustum) {
    outInvW = outVertex[3];
    endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    endToOutTexCoordT = endToOutTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x23] = endToOutTexCoordQ;
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = endToOutTexCoordT;
  outVertex[0x22] = outTexCoordR;
  return clipOutcode;
}

/* _gleInterpolClipNO1110w @ 0xbe4a0 (840 bytes) */
uint _gleInterpolClipNO1110w(int glContext,int startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord23;
  float startWord0c;
  float windowBiasZ;
  float clipYThenNdcY;
  float startWord21;
  float startWord0d;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startWord22;
  float startWord0f;
  float clipWThenInvW;
  float endWord23;
  float endWord0c;
  float negClipW;
  float endWord21;
  float endWord0d;
  float endClipX;
  float endClipY;
  float endWord22;
  float startWord0e;
  float endClipZ;
  float endWord0f;
  float endClipW;
  float endWord0e;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = *(float *)(startVertex + 0x10);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  clipZThenNdcZ = *(float *)(startVertex + 0x18);
  clipWThenInvW = *(float *)(startVertex + 0x1c);
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000be6a4;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000be604;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000be6a4;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000be6a4;
    negClipW = -clipWThenInvW;
LAB_000be604:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000be6a4;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000be6a4:
  startFlagByte7c = *(byte *)(startVertex + 0x7c);
  startFlagByte7e = *(byte *)(startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord0c = *(float *)(startVertex + 0x30);
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0c = *(float *)(endVertex + 0x30);
  endWord0d = *(float *)(endVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x13] =
       edgeT * (*(float *)(endVertex + 0x4c) - *(float *)(startVertex + 0x4c)) +
       *(float *)(startVertex + 0x4c);
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = edgeT * (endWord0c - startWord0c) + startWord0c;
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  startWord23 = *(float *)(startVertex + 0x8c);
  startWord21 = *(float *)(startVertex + 0x84);
  startWord22 = *(float *)(startVertex + 0x88);
  endWord23 = *(float *)(endVertex + 0x8c);
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  outVertex[0x20] =
       edgeT * (*(float *)(endVertex + 0x80) - *(float *)(startVertex + 0x80)) +
       *(float *)(startVertex + 0x80);
  outVertex[0x21] = edgeT * (endWord21 - startWord21) + startWord21;
  outVertex[0x23] = edgeT * (endWord23 - startWord23) + startWord23;
  outVertex[0x22] = edgeT * (endWord22 - startWord22) + startWord22;
  return clipOutcode;
}

/* _gleInterpolClipNO1111 @ 0xbe7e8 (980 bytes) */
uint _gleInterpolClipNO1111(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  char endFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordQ;
  float endTexCoordS;
  float startWord0b;
  float startWord11;
  float windowBiasZ;
  float clipYThenNdcY;
  float outTexCoordR;
  float endTexCoordT;
  float startWord09;
  float startWord12;
  float windowScaleZ;
  float clipZThenNdcZ;
  float endTexCoordR;
  float startWord0a;
  float endWord11;
  float outInvW;
  float clipWThenInvW;
  float endTexCoordQ;
  float endWord0b;
  float endWord12;
  float negClipW;
  float outTexCoordT;
  float endWord09;
  float endClipW;
  float endClipX;
  float outTexCoordS;
  float endWord0a;
  float endClipY;
  float endClipZ;
  float endClipW2;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000be9ec;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000be94c;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000be9ec;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000be9ec;
    negClipW = -clipWThenInvW;
LAB_000be94c:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000be9ec;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000be9ec:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  endFlagByte7f = *(char *)(endVertex + 0x7f);
  outVertex[0x13] = edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13];
  endTexCoordS = *(float *)(endVertex + 0x80);
  endTexCoordT = *(float *)(endVertex + 0x84);
  endTexCoordR = *(float *)(endVertex + 0x88);
  endTexCoordQ = *(float *)(endVertex + 0x8c);
  if (endFlagByte7f == '\0') {
    endClipW = *(float *)(endVertex + 0x1c);
    endTexCoordQ = endTexCoordQ * endClipW;
    endTexCoordS = endTexCoordS * endClipW;
    endTexCoordT = endTexCoordT * endClipW;
    endTexCoordR = endTexCoordR * endClipW;
  }
  outTexCoordS = edgeT * (endTexCoordS - startVertex[0x20]) + startVertex[0x20];
  outTexCoordT = edgeT * (endTexCoordT - startVertex[0x21]) + startVertex[0x21];
  outTexCoordR = edgeT * (endTexCoordR - startVertex[0x22]) + startVertex[0x22];
  outTexCoordQ = edgeT * (endTexCoordQ - startVertex[0x23]) + startVertex[0x23];
  if (insideFrustum) {
    outInvW = outVertex[3];
    outTexCoordQ = outTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    outTexCoordT = outTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = outTexCoordT;
  outVertex[0x22] = outTexCoordR;
  outVertex[0x23] = outTexCoordQ;
  startWord11 = startVertex[0x11];
  startWord12 = startVertex[0x12];
  endWord11 = *(float *)(endVertex + 0x44);
  endWord12 = *(float *)(endVertex + 0x48);
  outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
  outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
  outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
  if (startVertex != outVertex) {
    outVertex[0x1d] = startVertex[0x1d];
    outVertex[0x1e] = startVertex[0x1e];
  }
  startWord0b = startVertex[0xb];
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord0b = *(float *)(endVertex + 0x2c);
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
  outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
  outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
  outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
  return clipOutcode;
}

/* _gleInterpolClipNO1111w @ 0xbebbc (924 bytes) */
uint _gleInterpolClipNO1111w(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startWord0b;
  float startWord11;
  float startWord21;
  float windowBiasZ;
  float clipYThenNdcY;
  float startWord09;
  float startWord12;
  float startWord22;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startWord0a;
  float endWord11;
  float startWord23;
  float clipWThenInvW;
  float endWord0b;
  float endWord12;
  float endWord21;
  float negClipW;
  float endWord09;
  float endWord22;
  float endClipX;
  float endClipY;
  float endWord0a;
  float endWord23;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint clipOutcode;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bedc0;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bed20;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bedc0;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bedc0;
    negClipW = -clipWThenInvW;
LAB_000bed20:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bedc0;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bedc0:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  outVertex[0x13] = edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13];
  startWord21 = startVertex[0x21];
  startWord22 = startVertex[0x22];
  startWord23 = startVertex[0x23];
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  endWord23 = *(float *)(endVertex + 0x8c);
  outVertex[0x20] = edgeT * (*(float *)(endVertex + 0x80) - startVertex[0x20]) + startVertex[0x20];
  outVertex[0x21] = edgeT * (endWord21 - startWord21) + startWord21;
  outVertex[0x22] = edgeT * (endWord22 - startWord22) + startWord22;
  outVertex[0x23] = edgeT * (endWord23 - startWord23) + startWord23;
  startWord11 = startVertex[0x11];
  startWord12 = startVertex[0x12];
  endWord11 = *(float *)(endVertex + 0x44);
  endWord12 = *(float *)(endVertex + 0x48);
  outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
  outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
  outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
  if (startVertex != outVertex) {
    outVertex[0x1d] = startVertex[0x1d];
    outVertex[0x1e] = startVertex[0x1e];
  }
  startWord0b = startVertex[0xb];
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord0b = *(float *)(endVertex + 0x2c);
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
  outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
  outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
  outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
  return clipOutcode;
}

/* _gleInterpolClipNO1200 @ 0xbef58 (932 bytes) */
uint _gleInterpolClipNO1200(int glContext,int startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float endToOutTexCoordQ;
  float startWord0d;
  float windowScaleZ;
  float clipYThenNdcY;
  float outTexCoordR;
  float endTexCoordS;
  float startWord0e;
  float windowBiasZ;
  float clipZThenNdcZ;
  float endToOutTexCoordT;
  float startWord0f;
  float clipWThenInvW;
  float endTexCoordR;
  float outInvW;
  float endWord0d;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endWord0e;
  float endClipX;
  float endClipY;
  float endWord0f;
  float endClipZ;
  float endClipW2;
  float edgeT;
  uint texMaskRemaining;
  int startVertexAtUnit;
  uint texEnableMask;
  uint clipOutcode;
  int endVertexAtUnit;
  uint texUnit;
  
  clipXThenNdcX = *(float *)(startVertex + 0x10);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  clipZThenNdcZ = *(float *)(startVertex + 0x18);
  clipWThenInvW = *(float *)(startVertex + 0x1c);
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bf15c;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bf0bc;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bf15c;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bf15c;
    negClipW = -clipWThenInvW;
LAB_000bf0bc:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bf15c;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bf15c:
  startFlagByte7c = *(byte *)(startVertex + 0x7c);
  startFlagByte7e = *(byte *)(startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0xc] = edgeT * (*(float *)(endVertex + 0x30) - *(float *)(startVertex + 0x30)) +
                 *(float *)(startVertex + 0x30);
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        return clipOutcode;
      }
    }
    else {
      startVertexAtUnit = texUnit * 0x10 + startVertex;
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endToOutTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = *(float *)(endVertexAtUnit + 0x80);
      endToOutTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = *(float *)(endVertex + 0x1c);
        endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
        endTexCoordS = endTexCoordS * endClipW;
        endToOutTexCoordT = endToOutTexCoordT * endClipW;
        endTexCoordR = endTexCoordR * endClipW;
      }
      outTexCoordS = edgeT * (endTexCoordS - *(float *)(startVertexAtUnit + 0x80)) + *(float *)(startVertexAtUnit + 0x80);
      endToOutTexCoordT = edgeT * (endToOutTexCoordT - *(float *)(startVertexAtUnit + 0x84)) + *(float *)(startVertexAtUnit + 0x84);
      outTexCoordR = edgeT * (endTexCoordR - *(float *)(startVertexAtUnit + 0x88)) + *(float *)(startVertexAtUnit + 0x88);
      endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - *(float *)(startVertexAtUnit + 0x8c)) + *(float *)(startVertexAtUnit + 0x8c);
      if (insideFrustum) {
        outInvW = outVertex[3];
        endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        endToOutTexCoordT = endToOutTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = endToOutTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = endToOutTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO1200w @ 0xbf2fc (876 bytes) */
uint _gleInterpolClipNO1200w(int glContext,int startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startTexCoordQ;
  float startWord0d;
  float windowScaleZ;
  float clipYThenNdcY;
  float startTexCoordT;
  float startWord0e;
  float windowBiasZ;
  float clipZThenNdcZ;
  float startTexCoordR;
  float startWord0f;
  float clipWThenInvW;
  float endTexCoordQ;
  float endWord0d;
  float negClipW;
  float endTexCoordT;
  float endWord0e;
  float endClipX;
  float endTexCoordR;
  float endWord0f;
  float endClipY;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint texMaskRemaining;
  uint texEnableMask;
  uint clipOutcode;
  int startVertexAtUnit;
  uint texUnit;
  int endVertexAtUnit;
  
  clipXThenNdcX = *(float *)(startVertex + 0x10);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  clipZThenNdcZ = *(float *)(startVertex + 0x18);
  clipWThenInvW = *(float *)(startVertex + 0x1c);
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bf500;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bf460;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bf500;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bf500;
    negClipW = -clipWThenInvW;
LAB_000bf460:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bf500;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bf500:
  startFlagByte7c = *(byte *)(startVertex + 0x7c);
  startFlagByte7e = *(byte *)(startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0xc] = edgeT * (*(float *)(endVertex + 0x30) - *(float *)(startVertex + 0x30)) +
                 *(float *)(startVertex + 0x30);
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        return clipOutcode;
      }
    }
    else {
      startVertexAtUnit = texUnit * 0x10 + startVertex;
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = *(float *)(startVertexAtUnit + 0x8c);
      startTexCoordT = *(float *)(startVertexAtUnit + 0x84);
      startTexCoordR = *(float *)(startVertexAtUnit + 0x88);
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           edgeT * (*(float *)(endVertexAtUnit + 0x80) - *(float *)(startVertexAtUnit + 0x80)) +
           *(float *)(startVertexAtUnit + 0x80);
      outVertex[texUnit * 4 + 0x21] = edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT;
      outVertex[texUnit * 4 + 0x22] = edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR;
      outVertex[texUnit * 4 + 0x23] = edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO1201 @ 0xbf668 (1016 bytes) */
uint _gleInterpolClipNO1201(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float endToOutTexCoordQ;
  float startWord0b;
  float startWord11;
  float windowScaleZ;
  float clipYThenNdcY;
  float outTexCoordR;
  float endTexCoordS;
  float startWord09;
  float startWord12;
  float windowBiasZ;
  float clipZThenNdcZ;
  float endToOutTexCoordT;
  float startWord0a;
  float endWord11;
  float clipWThenInvW;
  float endTexCoordR;
  float outInvW;
  float endWord0b;
  float endWord12;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endWord09;
  float endClipX;
  float endClipY;
  float endWord0a;
  float endClipZ;
  float endClipW2;
  float edgeT;
  uint texMaskRemaining;
  uint texEnableMask;
  uint clipOutcode;
  int endVertexAtUnit;
  uint texUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bf86c;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bf7cc;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bf86c;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bf86c;
    negClipW = -clipWThenInvW;
LAB_000bf7cc:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bf86c;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bf86c:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  texUnit = 0;
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        startWord11 = startVertex[0x11];
        startWord12 = startVertex[0x12];
        endWord11 = *(float *)(endVertex + 0x44);
        endWord12 = *(float *)(endVertex + 0x48);
        outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
        outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
        outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
        if (startVertex != outVertex) {
          outVertex[0x1d] = startVertex[0x1d];
          outVertex[0x1e] = startVertex[0x1e];
        }
        startWord0b = startVertex[0xb];
        startWord09 = startVertex[9];
        startWord0a = startVertex[10];
        endWord0b = *(float *)(endVertex + 0x2c);
        endWord09 = *(float *)(endVertex + 0x24);
        endWord0a = *(float *)(endVertex + 0x28);
        outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
        outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
        outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
        outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endToOutTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = *(float *)(endVertexAtUnit + 0x80);
      endToOutTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = *(float *)(endVertex + 0x1c);
        endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
        endTexCoordS = endTexCoordS * endClipW;
        endToOutTexCoordT = endToOutTexCoordT * endClipW;
        endTexCoordR = endTexCoordR * endClipW;
      }
      outTexCoordS = edgeT * (endTexCoordS - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20];
      endToOutTexCoordT = edgeT * (endToOutTexCoordT - startVertex[texUnit * 4 + 0x21]) + startVertex[texUnit * 4 + 0x21];
      outTexCoordR = edgeT * (endTexCoordR - startVertex[texUnit * 4 + 0x22]) + startVertex[texUnit * 4 + 0x22];
      endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - startVertex[texUnit * 4 + 0x23]) + startVertex[texUnit * 4 + 0x23];
      if (insideFrustum) {
        outInvW = outVertex[3];
        endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        endToOutTexCoordT = endToOutTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = endToOutTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = endToOutTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO1201w @ 0xbfa60 (960 bytes) */
uint _gleInterpolClipNO1201w(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startTexCoordQ;
  float startWord0b;
  float startWord11;
  float windowScaleZ;
  float clipYThenNdcY;
  float startTexCoordT;
  float startWord09;
  float startWord12;
  float windowBiasZ;
  float clipZThenNdcZ;
  float startTexCoordR;
  float startWord0a;
  float endWord11;
  float clipWThenInvW;
  float endTexCoordQ;
  float endWord0b;
  float endWord12;
  float negClipW;
  float endTexCoordT;
  float endWord09;
  float endClipX;
  float endTexCoordR;
  float endWord0a;
  float endClipY;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint texMaskRemaining;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  int endVertexAtUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000bfc64;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bfbc4;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000bfc64;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000bfc64;
    negClipW = -clipWThenInvW;
LAB_000bfbc4:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000bfc64;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000bfc64:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  texUnit = 0;
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        startWord11 = startVertex[0x11];
        startWord12 = startVertex[0x12];
        endWord11 = *(float *)(endVertex + 0x44);
        endWord12 = *(float *)(endVertex + 0x48);
        outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
        outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
        outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
        if (startVertex != outVertex) {
          outVertex[0x1d] = startVertex[0x1d];
          outVertex[0x1e] = startVertex[0x1e];
        }
        startWord0b = startVertex[0xb];
        startWord09 = startVertex[9];
        startWord0a = startVertex[10];
        endWord0b = *(float *)(endVertex + 0x2c);
        endWord09 = *(float *)(endVertex + 0x24);
        endWord0a = *(float *)(endVertex + 0x28);
        outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
        outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
        outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
        outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) +
           startVertex[texUnit * 4 + 0x20];
      outVertex[texUnit * 4 + 0x21] = edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT;
      outVertex[texUnit * 4 + 0x22] = edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR;
      outVertex[texUnit * 4 + 0x23] = edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO1210 @ 0xbfe20 (952 bytes) */
uint _gleInterpolClipNO1210(int glContext,int startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float endToOutTexCoordQ;
  float startWord0c;
  float windowScaleZ;
  float clipYThenNdcY;
  float outTexCoordR;
  float endTexCoordS;
  float startWord0d;
  float windowBiasZ;
  float clipZThenNdcZ;
  float endToOutTexCoordT;
  float startWord0f;
  float clipWThenInvW;
  float endTexCoordR;
  float outInvW;
  float endWord0c;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endWord0d;
  float endClipX;
  float endClipY;
  float startWord0e;
  float endClipZ;
  float endWord0f;
  float endClipW2;
  float endWord0e;
  float edgeT;
  uint texMaskRemaining;
  int startVertexAtUnit;
  uint texEnableMask;
  uint clipOutcode;
  int endVertexAtUnit;
  uint texUnit;
  
  clipXThenNdcX = *(float *)(startVertex + 0x10);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  clipZThenNdcZ = *(float *)(startVertex + 0x18);
  clipWThenInvW = *(float *)(startVertex + 0x1c);
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000c0024;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000bff84;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000c0024;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000c0024;
    negClipW = -clipWThenInvW;
LAB_000bff84:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000c0024;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000c0024:
  startFlagByte7c = *(byte *)(startVertex + 0x7c);
  startFlagByte7e = *(byte *)(startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  startWord0c = *(float *)(startVertex + 0x30);
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0c = *(float *)(endVertex + 0x30);
  endWord0d = *(float *)(endVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x13] =
       edgeT * (*(float *)(endVertex + 0x4c) - *(float *)(startVertex + 0x4c)) +
       *(float *)(startVertex + 0x4c);
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = edgeT * (endWord0c - startWord0c) + startWord0c;
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        return clipOutcode;
      }
    }
    else {
      startVertexAtUnit = texUnit * 0x10 + startVertex;
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endToOutTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = *(float *)(endVertexAtUnit + 0x80);
      endToOutTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = *(float *)(endVertex + 0x1c);
        endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
        endTexCoordS = endTexCoordS * endClipW;
        endToOutTexCoordT = endToOutTexCoordT * endClipW;
        endTexCoordR = endTexCoordR * endClipW;
      }
      outTexCoordS = edgeT * (endTexCoordS - *(float *)(startVertexAtUnit + 0x80)) + *(float *)(startVertexAtUnit + 0x80);
      endToOutTexCoordT = edgeT * (endToOutTexCoordT - *(float *)(startVertexAtUnit + 0x84)) + *(float *)(startVertexAtUnit + 0x84);
      outTexCoordR = edgeT * (endTexCoordR - *(float *)(startVertexAtUnit + 0x88)) + *(float *)(startVertexAtUnit + 0x88);
      endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - *(float *)(startVertexAtUnit + 0x8c)) + *(float *)(startVertexAtUnit + 0x8c);
      if (insideFrustum) {
        outInvW = outVertex[3];
        endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        endToOutTexCoordT = endToOutTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = endToOutTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = endToOutTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO1210w @ 0xc01d8 (896 bytes) */
uint _gleInterpolClipNO1210w(int glContext,int startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startTexCoordQ;
  float startWord0c;
  float windowScaleZ;
  float clipYThenNdcY;
  float startTexCoordT;
  float startWord0d;
  float windowBiasZ;
  float clipZThenNdcZ;
  float startTexCoordR;
  float startWord0f;
  float clipWThenInvW;
  float endTexCoordQ;
  float endWord0c;
  float negClipW;
  float endTexCoordT;
  float endWord0d;
  float endClipX;
  float endTexCoordR;
  float startWord0e;
  float endClipY;
  float endClipZ;
  float endWord0f;
  float endClipW;
  float endWord0e;
  float edgeT;
  uint texMaskRemaining;
  uint texEnableMask;
  uint clipOutcode;
  int startVertexAtUnit;
  uint texUnit;
  int endVertexAtUnit;
  
  clipXThenNdcX = *(float *)(startVertex + 0x10);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  clipZThenNdcZ = *(float *)(startVertex + 0x18);
  clipWThenInvW = *(float *)(startVertex + 0x1c);
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000c03dc;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000c033c;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000c03dc;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000c03dc;
    negClipW = -clipWThenInvW;
LAB_000c033c:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000c03dc;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000c03dc:
  startFlagByte7c = *(byte *)(startVertex + 0x7c);
  startFlagByte7e = *(byte *)(startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  startWord0c = *(float *)(startVertex + 0x30);
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0c = *(float *)(endVertex + 0x30);
  endWord0d = *(float *)(endVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x13] =
       edgeT * (*(float *)(endVertex + 0x4c) - *(float *)(startVertex + 0x4c)) +
       *(float *)(startVertex + 0x4c);
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = edgeT * (endWord0c - startWord0c) + startWord0c;
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        return clipOutcode;
      }
    }
    else {
      startVertexAtUnit = texUnit * 0x10 + startVertex;
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = *(float *)(startVertexAtUnit + 0x8c);
      startTexCoordT = *(float *)(startVertexAtUnit + 0x84);
      startTexCoordR = *(float *)(startVertexAtUnit + 0x88);
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           edgeT * (*(float *)(endVertexAtUnit + 0x80) - *(float *)(startVertexAtUnit + 0x80)) +
           *(float *)(startVertexAtUnit + 0x80);
      outVertex[texUnit * 4 + 0x21] = edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT;
      outVertex[texUnit * 4 + 0x22] = edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR;
      outVertex[texUnit * 4 + 0x23] = edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO1211 @ 0xc0558 (1036 bytes) */
uint _gleInterpolClipNO1211(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float endToOutTexCoordQ;
  float startWord0b;
  float startWord11;
  float windowScaleZ;
  float clipYThenNdcY;
  float outTexCoordR;
  float endTexCoordS;
  float startWord09;
  float startWord12;
  float windowBiasZ;
  float clipZThenNdcZ;
  float endToOutTexCoordT;
  float startWord0a;
  float endWord11;
  float clipWThenInvW;
  float endTexCoordR;
  float outInvW;
  float endWord0b;
  float endWord12;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endWord09;
  float endClipX;
  float endClipY;
  float endWord0a;
  float endClipZ;
  float endClipW2;
  float edgeT;
  uint texMaskRemaining;
  uint texEnableMask;
  uint clipOutcode;
  int endVertexAtUnit;
  uint texUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000c075c;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000c06bc;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000c075c;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000c075c;
    negClipW = -clipWThenInvW;
LAB_000c06bc:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000c075c;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000c075c:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  outVertex[0x13] = edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13];
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        startWord11 = startVertex[0x11];
        startWord12 = startVertex[0x12];
        endWord11 = *(float *)(endVertex + 0x44);
        endWord12 = *(float *)(endVertex + 0x48);
        outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
        outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
        outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
        if (startVertex != outVertex) {
          outVertex[0x1d] = startVertex[0x1d];
          outVertex[0x1e] = startVertex[0x1e];
        }
        startWord0b = startVertex[0xb];
        startWord09 = startVertex[9];
        startWord0a = startVertex[10];
        endWord0b = *(float *)(endVertex + 0x2c);
        endWord09 = *(float *)(endVertex + 0x24);
        endWord0a = *(float *)(endVertex + 0x28);
        outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
        outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
        outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
        outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endToOutTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = *(float *)(endVertexAtUnit + 0x80);
      endToOutTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = *(float *)(endVertex + 0x1c);
        endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
        endTexCoordS = endTexCoordS * endClipW;
        endToOutTexCoordT = endToOutTexCoordT * endClipW;
        endTexCoordR = endTexCoordR * endClipW;
      }
      outTexCoordS = edgeT * (endTexCoordS - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20];
      endToOutTexCoordT = edgeT * (endToOutTexCoordT - startVertex[texUnit * 4 + 0x21]) + startVertex[texUnit * 4 + 0x21];
      outTexCoordR = edgeT * (endTexCoordR - startVertex[texUnit * 4 + 0x22]) + startVertex[texUnit * 4 + 0x22];
      endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - startVertex[texUnit * 4 + 0x23]) + startVertex[texUnit * 4 + 0x23];
      if (insideFrustum) {
        outInvW = outVertex[3];
        endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        endToOutTexCoordT = endToOutTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = endToOutTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = endToOutTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipNO1211w @ 0xc0964 (980 bytes) */
uint _gleInterpolClipNO1211w(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startTexCoordQ;
  float startWord0b;
  float startWord11;
  float windowScaleZ;
  float clipYThenNdcY;
  float startTexCoordT;
  float startWord09;
  float startWord12;
  float windowBiasZ;
  float clipZThenNdcZ;
  float startTexCoordR;
  float startWord0a;
  float endWord11;
  float clipWThenInvW;
  float endTexCoordQ;
  float endWord0b;
  float endWord12;
  float negClipW;
  float endTexCoordT;
  float endWord09;
  float endClipX;
  float endTexCoordR;
  float endWord0a;
  float endClipY;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint texMaskRemaining;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  int endVertexAtUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000c0b68;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000c0ac8;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000c0b68;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000c0b68;
    negClipW = -clipWThenInvW;
LAB_000c0ac8:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000c0b68;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000c0b68:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  outVertex[0x13] = edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13];
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        startWord11 = startVertex[0x11];
        startWord12 = startVertex[0x12];
        endWord11 = *(float *)(endVertex + 0x44);
        endWord12 = *(float *)(endVertex + 0x48);
        outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
        outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
        outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
        if (startVertex != outVertex) {
          outVertex[0x1d] = startVertex[0x1d];
          outVertex[0x1e] = startVertex[0x1e];
        }
        startWord0b = startVertex[0xb];
        startWord09 = startVertex[9];
        startWord0a = startVertex[10];
        endWord0b = *(float *)(endVertex + 0x2c);
        endWord09 = *(float *)(endVertex + 0x24);
        endWord0a = *(float *)(endVertex + 0x28);
        outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
        outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
        outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
        outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) +
           startVertex[texUnit * 4 + 0x20];
      outVertex[texUnit * 4 + 0x21] = edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT;
      outVertex[texUnit * 4 + 0x22] = edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR;
      outVertex[texUnit * 4 + 0x23] = edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipAllFlat @ 0xc0d38 (980 bytes) */
uint _gleInterpolClipAllFlat(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float endToOutTexCoordQ;
  float startWord16;
  float startWord13;
  float windowScaleZ;
  float clipZThenNdcZ;
  float endToOutTexCoordT;
  float clipWThenInvW;
  float endTexCoordR;
  float outInvW;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endClipX;
  float endClipY;
  float endClipZ;
  float endClipW2;
  float edgeT;
  uint texMaskRemaining;
  float clipYThenNdcY;
  float outTexCoordR;
  float endTexCoordS;
  float startWord1e;
  float endWord13;
  float windowBiasZ;
  uint texEnableMask;
  uint clipOutcode;
  int endVertexAtUnit;
  uint texUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000c0f3c;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000c0e9c;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000c0f3c;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000c0f3c;
    negClipW = -clipWThenInvW;
LAB_000c0e9c:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000c0f3c;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000c0f3c:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  startWord13 = startVertex[0x13];
  endWord13 = *(float *)(endVertex + 0x4c);
  outVertex[0x17] = edgeT * (*(float *)(endVertex + 0x5c) - startVertex[0x17]) + startVertex[0x17];
  outVertex[0x13] = edgeT * (endWord13 - startWord13) + startWord13;
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        if (startVertex != outVertex) {
          *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
          *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
          *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
          *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
          *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
          outVertex[0x12] = startVertex[0x12];
          *(undefined8 *)(outVertex + 0x14) = *(undefined8 *)(startVertex + 0x14);
          startWord16 = startVertex[0x16];
          outVertex[0x1d] = startVertex[0x1d];
          startWord1e = startVertex[0x1e];
          outVertex[0x16] = startWord16;
          outVertex[0x1e] = startWord1e;
        }
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endToOutTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = *(float *)(endVertexAtUnit + 0x80);
      endToOutTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = *(float *)(endVertex + 0x1c);
        endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
        endTexCoordS = endTexCoordS * endClipW;
        endToOutTexCoordT = endToOutTexCoordT * endClipW;
        endTexCoordR = endTexCoordR * endClipW;
      }
      outTexCoordS = edgeT * (endTexCoordS - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20];
      endToOutTexCoordT = edgeT * (endToOutTexCoordT - startVertex[texUnit * 4 + 0x21]) + startVertex[texUnit * 4 + 0x21];
      outTexCoordR = edgeT * (endTexCoordR - startVertex[texUnit * 4 + 0x22]) + startVertex[texUnit * 4 + 0x22];
      endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - startVertex[texUnit * 4 + 0x23]) + startVertex[texUnit * 4 + 0x23];
      if (insideFrustum) {
        outInvW = outVertex[3];
        endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        endToOutTexCoordT = endToOutTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = endToOutTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = endToOutTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipAllFlatw @ 0xc110c (924 bytes) */
uint _gleInterpolClipAllFlatw(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startTexCoordQ;
  float startWord16;
  float startWord13;
  float windowScaleZ;
  float clipZThenNdcZ;
  float startTexCoordR;
  float clipWThenInvW;
  float endTexCoordQ;
  float negClipW;
  float endTexCoordT;
  float endClipX;
  float endTexCoordR;
  float endClipY;
  float endClipZ;
  float endClipW;
  float edgeT;
  uint texMaskRemaining;
  float clipYThenNdcY;
  float startTexCoordT;
  float startWord1e;
  float endWord13;
  float windowBiasZ;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  int endVertexAtUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000c1310;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000c1270;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000c1310;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000c1310;
    negClipW = -clipWThenInvW;
LAB_000c1270:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000c1310;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000c1310:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  startWord13 = startVertex[0x13];
  endWord13 = *(float *)(endVertex + 0x4c);
  outVertex[0x17] = edgeT * (*(float *)(endVertex + 0x5c) - startVertex[0x17]) + startVertex[0x17];
  outVertex[0x13] = edgeT * (endWord13 - startWord13) + startWord13;
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        if (startVertex != outVertex) {
          *(undefined8 *)(outVertex + 8) = *(undefined8 *)(startVertex + 8);
          *(undefined8 *)(outVertex + 10) = *(undefined8 *)(startVertex + 10);
          *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
          *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
          *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
          outVertex[0x12] = startVertex[0x12];
          *(undefined8 *)(outVertex + 0x14) = *(undefined8 *)(startVertex + 0x14);
          startWord16 = startVertex[0x16];
          outVertex[0x1d] = startVertex[0x1d];
          startWord1e = startVertex[0x1e];
          outVertex[0x16] = startWord16;
          outVertex[0x1e] = startWord1e;
        }
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) +
           startVertex[texUnit * 4 + 0x20];
      outVertex[texUnit * 4 + 0x21] = edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT;
      outVertex[texUnit * 4 + 0x22] = edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR;
      outVertex[texUnit * 4 + 0x23] = edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipAllSmooth @ 0xc14a8 (1196 bytes) */
uint _gleInterpolClipAllSmooth(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float endToOutTexCoordQ;
  float startWord0b;
  float startWord11;
  float endWord0d;
  float startWord13;
  float windowScaleZ;
  float clipYThenNdcY;
  float outTexCoordR;
  float endTexCoordS;
  float startWord09;
  float startWord12;
  float endWord0e;
  float endWord13;
  float windowBiasZ;
  float clipZThenNdcZ;
  float endToOutTexCoordT;
  float startWord0a;
  float endWord11;
  float startWord15;
  float startWord0c;
  float clipWThenInvW;
  float endTexCoordR;
  float outInvW;
  float endWord0b;
  float endWord12;
  float endWord15;
  float endWord0c;
  float negClipW;
  float outTexCoordS;
  float endClipW;
  float endWord09;
  float startWord0f;
  float endClipX;
  float endClipY;
  float endWord0a;
  float startWord0e;
  float endClipZ;
  float startWord0d;
  float endClipW2;
  float endWord0f;
  float startWord14;
  float endWord14;
  float startWord16;
  float endWord16;
  float edgeT;
  uint texMaskRemaining;
  uint texEnableMask;
  uint clipOutcode;
  int endVertexAtUnit;
  uint texUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW2 = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW2 + endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW2 - endClipZ));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000c16ac;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000c160c;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW2 + endClipX));
        clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW2 - endClipX));
        clipXThenNdcX = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000c16ac;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW2 + endClipY));
      clipWThenInvW = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW2 - endClipY));
      clipYThenNdcY = edgeT * (endClipW2 - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000c16ac;
    negClipW = -clipWThenInvW;
LAB_000c160c:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000c16ac;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000c16ac:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  startWord13 = startVertex[0x13];
  endWord13 = *(float *)(endVertex + 0x4c);
  startWord0c = startVertex[0xc];
  endWord0c = *(float *)(endVertex + 0x30);
  startWord0f = startVertex[0xf];
  startWord0e = startVertex[0xe];
  startWord0d = startVertex[0xd];
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x17] = edgeT * (*(float *)(endVertex + 0x5c) - startVertex[0x17]) + startVertex[0x17];
  outVertex[0x13] = edgeT * (endWord13 - startWord13) + startWord13;
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  startWord14 = startVertex[0x14];
  endWord14 = *(float *)(endVertex + 0x50);
  outVertex[0xc] = edgeT * (endWord0c - startWord0c) + startWord0c;
  startWord15 = startVertex[0x15];
  endWord15 = *(float *)(endVertex + 0x54);
  startWord16 = startVertex[0x16];
  endWord16 = *(float *)(endVertex + 0x58);
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  outVertex[0x14] = edgeT * (endWord14 - startWord14) + startWord14;
  outVertex[0x15] = edgeT * (endWord15 - startWord15) + startWord15;
  outVertex[0x16] = edgeT * (endWord16 - startWord16) + startWord16;
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        startWord11 = startVertex[0x11];
        startWord12 = startVertex[0x12];
        endWord11 = *(float *)(endVertex + 0x44);
        endWord12 = *(float *)(endVertex + 0x48);
        outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
        outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
        outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
        if (startVertex != outVertex) {
          outVertex[0x1d] = startVertex[0x1d];
          outVertex[0x1e] = startVertex[0x1e];
        }
        startWord0b = startVertex[0xb];
        startWord09 = startVertex[9];
        startWord0a = startVertex[10];
        endWord0b = *(float *)(endVertex + 0x2c);
        endWord09 = *(float *)(endVertex + 0x24);
        endWord0a = *(float *)(endVertex + 0x28);
        outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
        outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
        outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
        outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endToOutTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = *(float *)(endVertexAtUnit + 0x80);
      endToOutTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = *(float *)(endVertex + 0x1c);
        endToOutTexCoordQ = endToOutTexCoordQ * endClipW;
        endTexCoordS = endTexCoordS * endClipW;
        endToOutTexCoordT = endToOutTexCoordT * endClipW;
        endTexCoordR = endTexCoordR * endClipW;
      }
      outTexCoordS = edgeT * (endTexCoordS - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20];
      endToOutTexCoordT = edgeT * (endToOutTexCoordT - startVertex[texUnit * 4 + 0x21]) + startVertex[texUnit * 4 + 0x21];
      outTexCoordR = edgeT * (endTexCoordR - startVertex[texUnit * 4 + 0x22]) + startVertex[texUnit * 4 + 0x22];
      endToOutTexCoordQ = edgeT * (endToOutTexCoordQ - startVertex[texUnit * 4 + 0x23]) + startVertex[texUnit * 4 + 0x23];
      if (insideFrustum) {
        outInvW = outVertex[3];
        endToOutTexCoordQ = endToOutTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        endToOutTexCoordT = endToOutTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = endToOutTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = endToOutTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolClipAllSmoothw @ 0xc1954 (1140 bytes) */
uint _gleInterpolClipAllSmoothw(int glContext,float *startVertex,int endVertex,float *outVertex,uint clipPlane,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool insideFrustum;
  byte startFlagByte7c;
  byte startFlagByte7e;
  float clipXThenNdcX;
  float startTexCoordQ;
  float startWord0b;
  float startWord11;
  float endWord0d;
  float startWord13;
  float windowScaleZ;
  float clipYThenNdcY;
  float startTexCoordT;
  float startWord09;
  float startWord12;
  float endWord0e;
  float endWord13;
  float windowBiasZ;
  float clipZThenNdcZ;
  float startTexCoordR;
  float startWord0a;
  float endWord11;
  float startWord15;
  float startWord0c;
  float clipWThenInvW;
  float endTexCoordQ;
  float endWord0b;
  float endWord12;
  float endWord15;
  float endWord0c;
  float negClipW;
  float endTexCoordT;
  float endWord09;
  float startWord0f;
  float endClipX;
  float endTexCoordR;
  float endWord0a;
  float startWord0e;
  float endClipY;
  float endClipZ;
  float startWord0d;
  float endClipW;
  float endWord0f;
  float startWord14;
  float endWord14;
  float startWord16;
  float endWord16;
  float edgeT;
  uint texMaskRemaining;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  int endVertexAtUnit;
  
  clipXThenNdcX = startVertex[4];
  clipYThenNdcY = startVertex[5];
  clipZThenNdcZ = startVertex[6];
  clipWThenInvW = startVertex[7];
  endClipX = *(float *)(endVertex + 0x10);
  endClipY = *(float *)(endVertex + 0x14);
  endClipZ = *(float *)(endVertex + 0x18);
  endClipW = *(float *)(endVertex + 0x1c);
  if (clipPlane < 3) {
    if (clipPlane == 1) {
      edgeT = (clipWThenInvW + clipZThenNdcZ) / ((clipWThenInvW + clipZThenNdcZ) - (endClipW + endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = -clipWThenInvW;
      if (clipWThenInvW < FLOAT_00108e50) {
        clipOutcode = 2;
      }
      else {
        clipOutcode = 0;
      }
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipZThenNdcZ) / ((clipWThenInvW - clipZThenNdcZ) - (endClipW - endClipZ));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipZThenNdcZ = clipWThenInvW;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
    if (!insideFrustum) goto LAB_000c1b58;
    negClipW = -clipWThenInvW;
    if (clipYThenNdcY < negClipW) {
      clipOutcode = 4;
    }
    else {
      if (!(clipWThenInvW <= clipYThenNdcY)) goto LAB_000c1ab8;
      clipOutcode = 8;
    }
  }
  else {
    if (8 < clipPlane) {
      if (clipPlane == 0x10) {
        edgeT = (clipWThenInvW + clipXThenNdcX) / ((clipWThenInvW + clipXThenNdcX) - (endClipW + endClipX));
        clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipXThenNdcX = -clipWThenInvW;
        clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 5;
      }
      else {
        clipOutcode = 0;
        edgeT = (clipWThenInvW - clipXThenNdcX) / ((clipWThenInvW - clipXThenNdcX) - (endClipW - endClipX));
        clipXThenNdcX = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
        clipWThenInvW = clipXThenNdcX;
      }
      insideFrustum = clipOutcode == 0;
      clipYThenNdcY = edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY;
      clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
      goto LAB_000c1b58;
    }
    if (clipPlane == 4) {
      edgeT = (clipWThenInvW + clipYThenNdcY) / ((clipWThenInvW + clipYThenNdcY) - (endClipW + endClipY));
      clipWThenInvW = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipYThenNdcY = -clipWThenInvW;
      clipOutcode = (uint)(clipWThenInvW <= FLOAT_00108e50) << 3;
    }
    else {
      clipOutcode = 0;
      edgeT = (clipWThenInvW - clipYThenNdcY) / ((clipWThenInvW - clipYThenNdcY) - (endClipW - endClipY));
      clipYThenNdcY = edgeT * (endClipW - clipWThenInvW) + clipWThenInvW;
      clipWThenInvW = clipYThenNdcY;
    }
    insideFrustum = clipOutcode == 0;
    clipXThenNdcX = edgeT * (endClipX - clipXThenNdcX) + clipXThenNdcX;
    clipZThenNdcZ = edgeT * (endClipZ - clipZThenNdcZ) + clipZThenNdcZ;
    if (!insideFrustum) goto LAB_000c1b58;
    negClipW = -clipWThenInvW;
LAB_000c1ab8:
    if (clipXThenNdcX < negClipW) {
      clipOutcode = 0x10;
    }
    else {
      if (!(clipWThenInvW <= clipXThenNdcX)) goto LAB_000c1b58;
      clipOutcode = 0x20;
    }
  }
  insideFrustum = clipOutcode == 0;
LAB_000c1b58:
  startFlagByte7c = *(byte *)(startVertex + 0x1f);
  startFlagByte7e = *(byte *)((int)startVertex + 0x7e);
  outVertex[4] = clipXThenNdcX;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  outVertex[7] = clipWThenInvW;
  outVertex[0x1f] = GH_U2F((unsigned int)(((uint)startFlagByte7c << 0x18 | (uint)startFlagByte7e << 8 | clipOutcode | 0x10000)));
  if (insideFrustum) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  startWord13 = startVertex[0x13];
  endWord13 = *(float *)(endVertex + 0x4c);
  startWord0c = startVertex[0xc];
  endWord0c = *(float *)(endVertex + 0x30);
  startWord0f = startVertex[0xf];
  startWord0e = startVertex[0xe];
  startWord0d = startVertex[0xd];
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x17] = edgeT * (*(float *)(endVertex + 0x5c) - startVertex[0x17]) + startVertex[0x17];
  outVertex[0x13] = edgeT * (endWord13 - startWord13) + startWord13;
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  startWord14 = startVertex[0x14];
  endWord14 = *(float *)(endVertex + 0x50);
  outVertex[0xc] = edgeT * (endWord0c - startWord0c) + startWord0c;
  startWord15 = startVertex[0x15];
  endWord15 = *(float *)(endVertex + 0x54);
  startWord16 = startVertex[0x16];
  endWord16 = *(float *)(endVertex + 0x58);
  outVertex[0xd] = edgeT * (endWord0d - startWord0d) + startWord0d;
  outVertex[0xe] = edgeT * (endWord0e - startWord0e) + startWord0e;
  outVertex[0xf] = edgeT * (endWord0f - startWord0f) + startWord0f;
  outVertex[0x14] = edgeT * (endWord14 - startWord14) + startWord14;
  outVertex[0x15] = edgeT * (endWord15 - startWord15) + startWord15;
  outVertex[0x16] = edgeT * (endWord16 - startWord16) + startWord16;
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        startWord11 = startVertex[0x11];
        startWord12 = startVertex[0x12];
        endWord11 = *(float *)(endVertex + 0x44);
        endWord12 = *(float *)(endVertex + 0x48);
        outVertex[0x10] = edgeT * (*(float *)(endVertex + 0x40) - startVertex[0x10]) + startVertex[0x10];
        outVertex[0x11] = edgeT * (endWord11 - startWord11) + startWord11;
        outVertex[0x12] = edgeT * (endWord12 - startWord12) + startWord12;
        if (startVertex != outVertex) {
          outVertex[0x1d] = startVertex[0x1d];
          outVertex[0x1e] = startVertex[0x1e];
        }
        startWord0b = startVertex[0xb];
        startWord09 = startVertex[9];
        startWord0a = startVertex[10];
        endWord0b = *(float *)(endVertex + 0x2c);
        endWord09 = *(float *)(endVertex + 0x24);
        endWord0a = *(float *)(endVertex + 0x28);
        outVertex[8] = edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8];
        outVertex[0xb] = edgeT * (endWord0b - startWord0b) + startWord0b;
        outVertex[9] = edgeT * (endWord09 - startWord09) + startWord09;
        outVertex[10] = edgeT * (endWord0a - startWord0a) + startWord0a;
        return clipOutcode;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) +
           startVertex[texUnit * 4 + 0x20];
      outVertex[texUnit * 4 + 0x21] = edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT;
      outVertex[texUnit * 4 + 0x22] = edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR;
      outVertex[texUnit * 4 + 0x23] = edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleSelectArrayInterpFunc @ 0xc1dc8 (544 bytes) */
int _gleSelectArrayInterpFunc(glContext, param_2)
  int glContext;
  int param_2;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined **ppuVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = 0;
  if ((*(int *)(glContext + 0x4e1c) != 0x1c00) ||
     ((*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 4) != 0)) {
    uVar6 = 0x18;
  }
  uVar7 = uVar6;
  if ((((*(int *)(glContext + 0x34f4) == 0x1d01) &&
       (uVar7 = uVar6 + 0xc, *(char *)(glContext + 0x30aa) != '\0')) &&
      (*(char *)(glContext + 0x4664) == '\0')) && (*(int *)(glContext + 0x5434) == 0)) {
    uVar7 = uVar6 + 0xd;
  }
  uVar6 = _gleTexEnableBits(glContext);
  *(uint *)(glContext + 0x5150) = uVar6;
  if (((uVar6 != 0) || (uVar8 = uVar7, *(int *)(glContext + 0x4e1c) == 0x1c01)) &&
     ((uVar8 = uVar7 + 4, (uVar6 & 0xfffffffe) != 0 && (*(int *)(glContext + 0x4e1c) == 0x1c00)))) {
    uVar8 = uVar7 + 8;
  }
  if ((*(char *)(glContext + 0x316a) != '\0') && (*(int *)(glContext + 0x4e1c) == 0x1c00)) {
    uVar8 = uVar8 + 2;
  }
  if ((*(short *)(0x3170 + glContext + 4) == 0x1102) ||
     ((*(char *)(glContext + 0x4fea) != '\0' &&
      (((*(char *)(glContext + 0x30aa) == '\0' || (*(char *)(glContext + 0x4664) != '\0')) ||
       (*(int *)(glContext + 0x5434) != 0)))))) {
    uVar8 = uVar8 / 0xc;
    puVar1 = PTR__gleInterpolClipAllSmoothw_00110678;
    puVar2 = PTR__gleInterpolClipAllFlatw_0011067c;
    puVar3 = PTR__gleInterpolClipAllSmooth_00110680;
    puVar4 = PTR__gleInterpolClipAllFlat_00110684;
    if (param_2 == 0) {
      puVar1 = PTR__gleInterpolEyeAllSmoothw_00110688;
      puVar2 = PTR__gleInterpolEyeAllFlatw_0011068c;
      puVar3 = PTR__gleInterpolEyeAllSmooth_00110690;
      puVar4 = PTR__gleInterpolEyeAllFlat_00110694;
    }
    if (uVar8 == 1) {
      return puVar3;
    }
    if (uVar8 < 2) {
      if (uVar8 == 0) {
        return puVar4;
      }
    }
    else {
      if (uVar8 == 2) {
        return puVar2;
      }
      if (uVar8 == 3) {
        return puVar1;
      }
    }
  }
  if (param_2 == 0) {
    ppuVar5 = &_eye_interp_funcs;
  }
  else {
    ppuVar5 = &_clip_interp_funcs;
  }
  return ppuVar5[uVar8];
}

/* _gleSetEyeInterpFunc @ 0xc1fe8 (104 bytes) */
void _gleSetEyeInterpFunc(int glContext,undefined4 forwardedArg2,undefined4 forwardedArg3,undefined4 forwardedArg4,undefined4 forwardedArg5,undefined4 forwardedArg6,undefined4 forwardedArg7,undefined4 forwardedArg8,double forwardedFloatArg1)
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE =
       (code *)_gleBuildInterpolateFunc(glContext,0,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6,forwardedArg7,forwardedArg8);
  *(code **)(glContext + 0x49c8) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*((int (*)(int,int,int,int,double))UNRECOVERED_JUMPTABLE))(glContext, forwardedArg2, forwardedArg3, forwardedArg4, forwardedFloatArg1);
  return;
}

/* _gleShrinkFuncCache @ 0xc2054 (68 bytes) */
void _gleShrinkFuncCache(param_1, param_2)
  int param_1;
  int param_2;
{
  if (0 < param_2) {
    do {
      ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(param_1 + 4));
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

/* _gleDeleteFuncCacheElem @ 0xc2098 (24 bytes) */
void _gleDeleteFuncCacheElem(glContext)
  int *glContext;
{
  int *piVar1;
  
  piVar1 = (int *)glContext[1];
  *piVar1 = *glContext;
  *(int **)(*glContext + 4) = piVar1;
  _gleDCBFree(glContext);
  return;
}

/* _gleRTCAddAChunk_c20b0 @ 0xc20b0 (48 bytes) */
int _gleRTCAddAChunk_c20b0(srcCursor, dstCursor)
  int *srcCursor;
  int *dstCursor;
{
  int word;
  int copiedWords;
  
  copiedWords = 0;
  word = *srcCursor;
  while (word != 0) {
    *dstCursor = word;
    copiedWords = copiedWords + 1;
    srcCursor = srcCursor + 1;
    dstCursor = dstCursor + 1;
    word = *srcCursor;
  }
  return copiedWords;
}

/* _gleBuildInterpFunc @ 0xc20e0 (876 bytes) */
int _gleBuildInterpFunc(glContext, param_2)
  int glContext;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  undefined *codeChunk;
  int iVar5;
  int chunkWordCount;
  char cVar7;
  
  uVar2 = *(uint *)(glContext + 0x498c);
  cVar7 = (*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 3) == 1;
  if (0x20 < *(ushort *)(glContext + 0x4990)) {
    cVar7 = cVar7 << 1;
  }
  iVar3 = _gleCreateFuncCacheElem(*(undefined4 *)(glContext + 0x49b8),0x130);
  if (iVar3 == 0) {
    return PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar3 + 8) = param_2;
  if (*(short *)(glContext + 0x49c2) == *(short *)(glContext + 0x49c0)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar3 + 4));
  }
  else {
    *(short *)(glContext + 0x49c2) = *(short *)(glContext + 0x49c2) + 1;
  }
  bVar1 = (uVar2 >> 0xf & 1) == 0;
  if (bVar1) {
    codeChunk = &_gleVAPrologRTC_10b2d0;
  }
  else {
    codeChunk = &_gleVASwapPrologRTC;
  }
  iVar5 = ((int (*)())_gleRTCAddAChunk_c20b0)(codeChunk,iVar3 + 0x20);
  iVar5 = iVar3 + 0x20 + iVar5 * 4;
  if ((param_2 & 0x10) == 0) {
    if ((param_2 & 8) == 0) {
      if ((param_2 & 4) == 0) {
        codeChunk = &_gleVASetOffsetsGr;
      }
      else {
        codeChunk = &_gleVASetOffsetsFogGr;
      }
    }
    else if ((param_2 & 4) == 0) {
      codeChunk = &_gleVASetOffsetsTex;
    }
    else {
      codeChunk = &_gleVASetOffsetsFogTex;
    }
  }
  else if ((param_2 & 4) == 0) {
    codeChunk = &_gleVASetOffsetsTex2;
  }
  else {
    codeChunk = &_gleVASetOffsetsFogTex2;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c20b0)(codeChunk,iVar5);
  iVar5 = iVar5 + chunkWordCount * 4;
  if (bVar1) {
    codeChunk = &_gleVALoadVertices;
  }
  else {
    codeChunk = &_gleVASwapLoadVertices;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c20b0)(codeChunk,iVar5);
  iVar5 = iVar5 + chunkWordCount * 4;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0) {
    codeChunk = &_gleVAInterpVertex;
  }
  else {
    codeChunk = &_gleVAInterpVertexAV;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c20b0)(codeChunk,iVar5);
  iVar5 = iVar5 + chunkWordCount * 4;
  if (bVar1) {
    codeChunk = &_gleVAStoreVertex;
  }
  else {
    codeChunk = &_gleVASwapStoreVertex;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c20b0)(codeChunk,iVar5);
  iVar5 = iVar5 + chunkWordCount * 4;
  if ((param_2 & 2) != 0) {
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c20b0)(&_gleVAInterpColor,iVar5);
    iVar5 = iVar5 + chunkWordCount * 4;
  }
  if ((param_2 & 4) == 0) {
    codeChunk = &_gleVANoFog;
  }
  else if (bVar1) {
    codeChunk = &_gleVAInterpFog;
  }
  else {
    codeChunk = &_gleVASwapInterpFog;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c20b0)(codeChunk,iVar5);
  iVar5 = iVar5 + chunkWordCount * 4;
  if ((param_2 & 8) != 0) {
    if (bVar1) {
      codeChunk = &_gleVAInterpTexCoord0;
    }
    else {
      codeChunk = &_gleVASwapInterpTexCoord0;
    }
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c20b0)(codeChunk,iVar5);
    iVar5 = iVar5 + chunkWordCount * 4;
  }
  if ((param_2 & 0x10) != 0) {
    if (bVar1) {
      codeChunk = &_gleVAInterpTexCoord1;
    }
    else {
      codeChunk = &_gleVASwapInterpTexCoord1;
    }
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c20b0)(codeChunk,iVar5);
    iVar5 = iVar5 + chunkWordCount * 4;
  }
  if (cVar7 == '\x01') {
    codeChunk = &_gleVASingleFlushDataRTC_10b2f0;
  }
  else {
    if (cVar7 != '\x02') goto LAB_000c23b8;
    codeChunk = &_gleVADoubleFlushDataRTC_10b318;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c20b0)(codeChunk,iVar5);
  iVar5 = iVar5 + chunkWordCount * 4;
LAB_000c23b8:
  if (bVar1) {
    codeChunk = &_gleVAEpilogRTC_10b348;
  }
  else {
    codeChunk = &_gleVASwapEpilogRTC;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c20b0)(codeChunk,iVar5);
  iVar5 = ((iVar5 + chunkWordCount * 4) - iVar3) + -0x20 >> 2;
  if (iVar5 < 0x131) {
    iVar3 = _gleShrinkFuncCacheElem(iVar3,iVar5);
    puVar4 = PTR__glePushInstructions_00112054;
    *(int *)(glContext + 0x49b8) = iVar3;
    (**(code **)puVar4)(iVar5,(undefined *)(iVar3 + 0x20));
    return (undefined *)(iVar3 + 0x20);
  }
                    
  _exit(1);
}

/* _gleRTCBuildABranch_c244c @ 0xc244c (12 bytes) */
int _gleRTCBuildABranch_c244c(branchInstruction, branchWordOffset)
  uint branchInstruction;
  uint branchWordOffset;
{
  return (branchWordOffset & 0x3fff) << 2 | branchInstruction & 0xffff0003;
}

/* _gleRTCAddAChunk_c2458 @ 0xc2458 (48 bytes) */
int _gleRTCAddAChunk_c2458(srcCursor, dstCursor)
  int *srcCursor;
  int *dstCursor;
{
  int word;
  int copiedWords;
  
  copiedWords = 0;
  word = *srcCursor;
  while (word != 0) {
    *dstCursor = word;
    copiedWords = copiedWords + 1;
    srcCursor = srcCursor + 1;
    dstCursor = dstCursor + 1;
    word = *srcCursor;
  }
  return copiedWords;
}

/* _gleBuildCompileFuncTCLNO @ 0xc2488 (1528 bytes) */
int _gleBuildCompileFuncTCLNO(glContext, param_2)
  int glContext;
  uint param_2;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int chunkWordCount2;
  int iVar7;
  int chunkWordCountThenCodeCursor;
  int chunkWordCount3;
  int chunkWordCountThenCodeCursor2;
  int chunkWordCount;
  undefined *puVar11;
  undefined *codeChunk;
  undefined4 uVar12;
  uint uVar13;
  undefined4 *puVar14;
  
  bVar2 = false;
  iVar6 = -(param_2 >> 0x12 & 0x21);
  uVar13 = *(uint *)(glContext + 0x498c) >> 0xf & 1;
  uVar3 = (uint)((*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 3) == 1) *
          ((int)(*(ushort *)(glContext + 0x4990) + 0x1f) >> 5) & 0xff;
  iVar7 = _gleCreateFuncCacheElem(*(undefined4 *)(glContext + 0x49b4),0x180);
  if (iVar7 == 0) {
    return PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar7 + 8) = param_2;
  if (*(short *)(glContext + 0x49be) == *(short *)(glContext + 0x49bc)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar7 + 4));
  }
  else {
    *(short *)(glContext + 0x49be) = *(short *)(glContext + 0x49be) + 1;
  }
  bVar1 = uVar3 == 1;
  chunkWordCountThenCodeCursor = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAPrologNoTransRTC,iVar7 + 0x20);
  chunkWordCountThenCodeCursor = iVar7 + 0x20 + chunkWordCountThenCodeCursor * 4;
  if (bVar1) {
    codeChunk = &_gleVASingleFlushSetupRTC;
LAB_000c2584:
    chunkWordCount3 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount3 * 4;
  }
  else if (uVar3 == 2) {
    codeChunk = &_gleVADoubleFlushSetupRTC;
    goto LAB_000c2584;
  }
  if ((param_2 >> 0x10 & 0x21) == 0x21) {
    chunkWordCountThenCodeCursor2 = ((int (*)())_gleRTCAddAChunk_c2458)((&_vertex_load_array)[param_2 >> 0xc & 0xf],chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor + chunkWordCountThenCodeCursor2 * 4;
    if (iVar6 < 0) {
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreVertXYZWRTC,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount * 4;
      if (uVar13 != 0) {
        codeChunk = &_gleVASwapStoreVertXYZWRTC;
        goto LAB_000c2674;
      }
    }
    else {
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreVertXYZRTC,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount * 4;
      if (uVar13 != 0) {
        codeChunk = &_gleVASwapStoreVertXYZRTC;
        goto LAB_000c2674;
      }
    }
  }
  else {
    bVar2 = true;
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor;
    if (iVar6 < 0) {
      if (uVar13 == 0) {
        codeChunk = &_gleVACopyVertXYZWRTC;
      }
      else {
        codeChunk = &_gleVASwapCopyVertXYZWRTC;
      }
    }
    else if (uVar13 == 0) {
      codeChunk = &_gleVACopyVertXYZRTC;
    }
    else {
      codeChunk = &_gleVASwapCopyVertXYZRTC;
    }
LAB_000c2674:
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount * 4;
  }
  bVar5 = uVar13 == 0;
  bVar4 = -1 < iVar6;
  uVar13 = param_2 >> 0x11 & 0x21;
  if (uVar13 == 0x20) {
    bVar2 = true;
    if (bVar4) {
      codeChunk = &_gleVAColorFuncCopy12;
    }
    else {
      codeChunk = &_gleVAColorFuncCopy16;
    }
LAB_000c2734:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      codeChunk = &_gleVAColorFuncCurrent;
LAB_000c26ec:
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (bVar4) {
        if (bVar5) {
          codeChunk = &_gleVAStoreColor12;
        }
        else {
          codeChunk = &_gleVASwapColor12;
        }
      }
      else if (bVar5) {
        codeChunk = &_gleVAStoreColor16;
      }
      else {
        codeChunk = &_gleVASwapColor16;
      }
      goto LAB_000c2734;
    }
  }
  else if (uVar13 == 0x21) {
    codeChunk = *(undefined **)((int)&_color_func_array + (param_2 >> 6 & 0x3c));
    goto LAB_000c26ec;
  }
  uVar13 = param_2 >> 0x13 & 0x21;
  if (uVar13 == 0x20) {
    bVar2 = true;
    if (bVar4) {
      codeChunk = &_gleVATex0FuncCopyST16;
    }
    else {
      codeChunk = &_gleVATex0FuncCopySTQ20;
    }
    goto LAB_000c280c;
  }
  if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      codeChunk = &_gleVATex0LoadCurrent;
LAB_000c27ac:
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (bVar4) {
        chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex0ST16,chunkWordCountThenCodeCursor2);
        chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
        if (!bVar5) {
          codeChunk = &_gleVASwapTex0ST16;
          goto LAB_000c280c;
        }
      }
      else {
        chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex0STQ20,chunkWordCountThenCodeCursor2);
        chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
        if (!bVar5) {
          codeChunk = &_gleVASwapTex0STQ20;
LAB_000c280c:
          chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
          chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
        }
      }
    }
  }
  else if (uVar13 == 0x21) {
    codeChunk = *(undefined **)((int)&_tex0_func_array + (param_2 >> 2 & 0x3c));
    goto LAB_000c27ac;
  }
  uVar13 = param_2 >> 0x14 & 0x21;
  if (uVar13 == 0x20) {
    bVar2 = true;
    if (bVar4) {
      codeChunk = &_gleVATex1FuncCopyST24;
    }
    else {
      codeChunk = &_gleVATex1FuncCopySTQ32;
    }
LAB_000c291c:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVATex1LoadCurrent,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (!bVar4) goto LAB_000c28d0;
LAB_000c28f8:
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex1ST24,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (!bVar5) {
        codeChunk = &_gleVASwapTex1ST24;
        goto LAB_000c291c;
      }
    }
  }
  else if (uVar13 == 0x21) {
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)((&_tex1_func_array)[param_2 & 0xf],chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    if (bVar4) goto LAB_000c28f8;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(*(undefined4 *)((int)&_tex1_tcl_array + (param_2 & 0xc)),chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
LAB_000c28d0:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex1STQ32,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    if (!bVar5) {
      codeChunk = &_gleVASwapTex1STQ32;
      goto LAB_000c291c;
    }
  }
  if (bVar1) {
    codeChunk = &_gleVASingleFlushDataRTC_10c068;
LAB_000c2950:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if (uVar3 == 2) {
    codeChunk = &_gleVADoubleFlushDataRTC_10c070;
    goto LAB_000c2950;
  }
  if (bVar2) {
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAIncOldDataRTC,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAEndLoopRTC,chunkWordCountThenCodeCursor2);
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  puVar14 = (undefined4 *)(chunkWordCountThenCodeCursor2 + -4);
  if (bVar1) {
    codeChunk = &_gleVASingleFlushDataRTC_10c068;
  }
  else {
    if (uVar3 != 2) goto LAB_000c29e8;
    codeChunk = &_gleVADoubleCompleteDataRTC;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVACompleteFlushDataRTC_10c098,chunkWordCountThenCodeCursor2);
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
LAB_000c29e8:
  iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAEpilogNoTransRTC,chunkWordCountThenCodeCursor2);
  uVar12 = ((int (*)())_gleRTCBuildABranch_c244c)(*puVar14,chunkWordCountThenCodeCursor - (int)puVar14 >> 2);
  *puVar14 = uVar12;
  iVar6 = ((chunkWordCountThenCodeCursor2 + iVar6 * 4) - iVar7) + -0x20 >> 2;
  if (iVar6 < 0x181) {
    iVar7 = _gleShrinkFuncCacheElem(iVar7,iVar6);
    puVar11 = PTR__glePushInstructions_00112054;
    *(int *)(glContext + 0x49b4) = iVar7;
    (**(code **)puVar11)(iVar6,(undefined *)(iVar7 + 0x20));
    return (undefined *)(iVar7 + 0x20);
  }
                    
  _exit(1);
}

/* _gleBuildCompileFuncNO @ 0xc2a80 (1512 bytes) */
int _gleBuildCompileFuncNO(glContext, param_2)
  int glContext;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined *puVar6;
  undefined *codeChunk;
  int chunkWordCountThenCodeCursor;
  int emittedWordCount;
  int chunkWordCount;
  int chunkWordCountThenCodeCursor2;
  int chunkWordCount2;
  undefined4 uVar10;
  char cVar11;
  uint uVar12;
  undefined4 *puVar13;
  
  bVar3 = false;
  uVar12 = *(uint *)(glContext + 0x498c) >> 0xf & 1;
  cVar11 = (*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 3) == 1;
  if (0x20 < *(ushort *)(glContext + 0x4990)) {
    cVar11 = cVar11 << 1;
  }
  iVar5 = _gleCreateFuncCacheElem(*(undefined4 *)(glContext + 0x49b4),0x180);
  if (iVar5 == 0) {
    return PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar5 + 8) = param_2;
  if (*(short *)(glContext + 0x49be) == *(short *)(glContext + 0x49bc)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar5 + 4));
  }
  else {
    *(short *)(glContext + 0x49be) = *(short *)(glContext + 0x49be) + 1;
  }
  uVar2 = param_2 >> 0x10;
  if ((uVar2 & 0x21) == 0x21) {
    codeChunk = &_gleVAPrologRTC_10bb18;
  }
  else {
    codeChunk = &_gleVAPrologNoTransRTC;
  }
  bVar1 = cVar11 == '\x01';
  chunkWordCountThenCodeCursor = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,iVar5 + 0x20);
  chunkWordCountThenCodeCursor = iVar5 + 0x20 + chunkWordCountThenCodeCursor * 4;
  if (bVar1) {
    codeChunk = &_gleVASingleFlushSetupRTC;
LAB_000c2b8c:
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount * 4;
  }
  else if (cVar11 == '\x02') {
    codeChunk = &_gleVADoubleFlushSetupRTC;
    goto LAB_000c2b8c;
  }
  if ((uVar2 & 0x21) == 0x21) {
    chunkWordCountThenCodeCursor2 = ((int (*)())_gleRTCAddAChunk_c2458)(*(undefined4 *)((int)&_vertex_func_array + (param_2 >> 10 & 0x3c)),chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor + chunkWordCountThenCodeCursor2 * 4;
    if ((param_2 & 0x10000000) == 0) {
      codeChunk = &_gleVALoadClipVertRTC;
    }
    else {
      codeChunk = &_gleVALoadVertRTC;
    }
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    if (uVar12 != 0) {
      codeChunk = &_gleVASwapStoreVertXYZWRTC;
      goto LAB_000c2c2c;
    }
  }
  else {
    bVar3 = true;
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor;
    if (uVar12 == 0) {
      codeChunk = &_gleVACopyVertXYZWRTC;
    }
    else {
      codeChunk = &_gleVASwapCopyVertXYZWRTC;
    }
LAB_000c2c2c:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  bVar4 = uVar12 == 0;
  uVar12 = param_2 >> 0x11 & 0x21;
  if (uVar12 == 0x20) {
    codeChunk = &_gleVAColorFuncCopy16;
    bVar3 = true;
LAB_000c2cc4:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if (uVar12 < 0x21) {
    if (uVar12 == 1) {
      codeChunk = &_gleVAColorFuncCurrent;
LAB_000c2c98:
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (bVar4) {
        codeChunk = &_gleVAStoreColor16;
      }
      else {
        codeChunk = &_gleVASwapColor16;
      }
      goto LAB_000c2cc4;
    }
  }
  else if (uVar12 == 0x21) {
    codeChunk = *(undefined **)((int)&_color_func_array + (param_2 >> 6 & 0x3c));
    goto LAB_000c2c98;
  }
  uVar12 = param_2 >> 0x13 & 0x21;
  if (uVar12 == 0x20) {
    codeChunk = &_gleVATex0FuncCopyST;
    bVar3 = true;
LAB_000c2e14:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if (uVar12 < 0x21) {
    if (uVar12 == 1) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVATex0LoadCurrent,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVATexWDivideSTQ,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex0STQ,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (!bVar4) {
        chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVASwapTex0ST,chunkWordCountThenCodeCursor2);
        chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
LAB_000c2e08:
        codeChunk = &_gleVASwapTex0Q;
        goto LAB_000c2e14;
      }
    }
  }
  else if (uVar12 == 0x21) {
    uVar12 = param_2 >> 4 & 0xf;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)((&_tex0_func_array)[uVar12],chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(*(undefined4 *)((int)&_tex0_divide_array + (param_2 >> 4 & 0xc)),chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    if (uVar12 < 0xc) {
      codeChunk = &_gleVAStoreTex0ST;
    }
    else {
      codeChunk = &_gleVAStoreTex0STQ;
    }
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    if (!bVar4) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVASwapTex0ST,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (uVar12 >= 0xc) goto LAB_000c2e08;
    }
  }
  uVar12 = param_2 >> 0x14 & 0x21;
  if (uVar12 == 0x20) {
    codeChunk = &_gleVATex1FuncCopySTQ;
    bVar3 = true;
LAB_000c2ef0:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if (uVar12 < 0x21) {
    if (uVar12 == 1) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVATex1LoadCurrent,chunkWordCountThenCodeCursor2);
      codeChunk = &_gleVATexWDivideSTQ;
LAB_000c2eb8:
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex1STQ,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (!bVar4) {
        codeChunk = &_gleVASwapTex1STQ;
        goto LAB_000c2ef0;
      }
    }
  }
  else if (uVar12 == 0x21) {
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)((&_tex1_func_array)[param_2 & 0xf],chunkWordCountThenCodeCursor2);
    codeChunk = *(undefined **)((int)&_tex1_divide_array + (param_2 & 0xc));
    goto LAB_000c2eb8;
  }
  if (bVar1) {
    codeChunk = &_gleVASingleFlushDataRTC_10c068;
LAB_000c2f20:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if (cVar11 == '\x02') {
    codeChunk = &_gleVADoubleFlushDataRTC_10c070;
    goto LAB_000c2f20;
  }
  if (bVar3) {
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAIncOldDataRTC,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAEndLoopRTC,chunkWordCountThenCodeCursor2);
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  puVar13 = (undefined4 *)(chunkWordCountThenCodeCursor2 + -4);
  if (bVar1) {
    codeChunk = &_gleVASingleFlushDataRTC_10c068;
  }
  else {
    if (cVar11 != '\x02') goto LAB_000c2fb8;
    codeChunk = &_gleVADoubleCompleteDataRTC;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVACompleteFlushDataRTC_10c098,chunkWordCountThenCodeCursor2);
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
LAB_000c2fb8:
  if ((uVar2 & 0x21) == 0x21) {
    codeChunk = &_gleVAEpilogRTC_10bd34;
  }
  else {
    codeChunk = &_gleVAEpilogNoTransRTC;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c2458)(codeChunk,chunkWordCountThenCodeCursor2);
  uVar10 = ((int (*)())_gleRTCBuildABranch_c244c)(*puVar13,chunkWordCountThenCodeCursor - (int)puVar13 >> 2);
  *puVar13 = uVar10;
  emittedWordCount = ((chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4) - iVar5) + -0x20 >> 2;
  if (emittedWordCount < 0x181) {
    iVar5 = _gleShrinkFuncCacheElem(iVar5,emittedWordCount);
    puVar6 = PTR__glePushInstructions_00112054;
    *(int *)(glContext + 0x49b4) = iVar5;
    (**(code **)puVar6)(emittedWordCount,(undefined *)(iVar5 + 0x20));
    return (undefined *)(iVar5 + 0x20);
  }
                    
  _exit(1);
}

/* _gleRTCBuildABranch_c3068 @ 0xc3068 (12 bytes) */
int _gleRTCBuildABranch_c3068(branchInstruction, branchWordOffset)
  uint branchInstruction;
  uint branchWordOffset;
{
  return (branchWordOffset & 0x3fff) << 2 | branchInstruction & 0xffff0003;
}

/* _gleRTCAddAChunk_c3074 @ 0xc3074 (48 bytes) */
int _gleRTCAddAChunk_c3074(srcCursor, dstCursor)
  int *srcCursor;
  int *dstCursor;
{
  int word;
  int copiedWords;
  
  copiedWords = 0;
  word = *srcCursor;
  while (word != 0) {
    *dstCursor = word;
    copiedWords = copiedWords + 1;
    srcCursor = srcCursor + 1;
    dstCursor = dstCursor + 1;
    word = *srcCursor;
  }
  return copiedWords;
}

/* _gleBuildCompileFuncTCLAV @ 0xc30a4 (1992 bytes) */
int _gleBuildCompileFuncTCLAV(glContext, param_2)
  int glContext;
  uint param_2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  undefined **ppuVar6;
  int iVar7;
  undefined *puVar8;
  undefined *codeChunk;
  int chunkWordCountThenCodeCursor2;
  int emittedWordCount;
  int chunkWordCount;
  int chunkWordCountThenCodeCursor;
  int chunkWordCount2;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  
  bVar4 = false;
  uVar14 = *(uint *)(*(int *)(glContext + 0x468c) + 0x94);
  iVar7 = (uint)*(ushort *)(glContext + 0x4990) * 2;
  uVar13 = *(uint *)(glContext + 0x498c);
  uVar5 = iVar7 + 0x1fU >> 5;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x40) != 0) {
    uVar5 = iVar7 + 0x7fU >> 7;
  }
  uVar5 = (uint)((uVar14 & 3) == 1) * (uVar5 & 0xff);
  bVar1 = -1 < (int)-(param_2 >> 0x12 & 0x21);
  bVar3 = false;
  if ((!bVar1) && ((uVar14 & 8) != 0)) {
    bVar3 = true;
  }
  iVar7 = _gleCreateFuncCacheElem(*(undefined4 *)(glContext + 0x49b4),0x310);
  if (iVar7 == 0) {
    return PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar7 + 8) = param_2;
  if (*(short *)(glContext + 0x49be) == *(short *)(glContext + 0x49bc)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar7 + 4));
  }
  else {
    *(short *)(glContext + 0x49be) = *(short *)(glContext + 0x49be) + 1;
  }
  if ((*(uint *)PTR__gle_processor_0011204c & 0x40) == 0) {
    codeChunk = &_gleVAPrologNoTransAVRTC;
  }
  else {
    codeChunk = &_gleVAPrologNoTransAVRTC_128;
  }
  bVar2 = (uVar13 >> 0xf & 1) == 0;
  chunkWordCountThenCodeCursor2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,iVar7 + 0x20);
  chunkWordCountThenCodeCursor2 = iVar7 + 0x20 + chunkWordCountThenCodeCursor2 * 4;
  if (!bVar2) {
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVALoadSwapVectAVRTC,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount * 4;
  }
  chunkWordCountThenCodeCursor = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAStartLoopAVRTC,chunkWordCountThenCodeCursor2);
  chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor2 + chunkWordCountThenCodeCursor * 4;
  if ((param_2 >> 0x10 & 0x21) == 0x21) {
    uVar13 = param_2 >> 0xc & 0xf;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)((&_vertex_load_array_av)[uVar13],chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    if (bVar1) {
      if (uVar13 < 4) {
        codeChunk = &_gleVAVertFillZAV;
        goto LAB_000c3264;
      }
    }
    else {
      codeChunk = *(undefined **)((int)&_vertex_fill_array_av + (param_2 >> 0xc & 0xc));
LAB_000c3264:
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    }
    if ((*(uint *)PTR__gle_processor_0011204c & 0x40) == 0) {
      codeChunk = &_gleVAIncVertAVRTC;
    }
    else {
      codeChunk = &_gleVAIncVertAVRTC_128;
    }
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    if (!bVar2) {
      codeChunk = &_gleVASwapVertAVRTC;
      goto LAB_000c32cc;
    }
  }
  else {
    codeChunk = &_gleVALoadOldVertAVRTC;
    bVar4 = true;
LAB_000c32cc:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
  }
  if (bVar1) {
    codeChunk = &_gleVAStoreVertXYZAVRTC;
  }
  else {
    codeChunk = &_gleVAStoreVertXYZWAVRTC;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor);
  uVar13 = param_2 >> 0x11 & 0x21;
  chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
  if (uVar13 == 0x20) {
    bVar4 = true;
    if (bVar1) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAColorLoadCopyInt12AV,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
      puVar8 = &_gleVAStoreColorInt12AV;
    }
    else {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAColorLoadCopyInt16AV,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
      puVar8 = &_gleVAStoreColorInt16AV;
    }
LAB_000c342c:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
  }
  else if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAColorLoadCurrentAV,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
      if (bVar2) {
        if (bVar1) {
          puVar8 = &_gleVAStoreColor12AV;
        }
        else {
          puVar8 = &_gleVAStoreColor16AV;
        }
      }
      else if (bVar1) {
        puVar8 = &_gleVASwapStoreColor12AV;
      }
      else {
        puVar8 = &_gleVASwapStoreColor16AV;
      }
      goto LAB_000c342c;
    }
  }
  else if (uVar13 == 0x21) {
    uVar13 = param_2 >> 6 & 0x3c;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(*(undefined4 *)((int)&_color_func_array_av + uVar13),chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    if (bVar2) {
      if (bVar1) {
        ppuVar6 = &_color_func_store_12av;
      }
      else {
        ppuVar6 = &_color_func_store_16av;
      }
    }
    else if (bVar1) {
      ppuVar6 = &_color_func_swap_store_12av;
    }
    else {
      ppuVar6 = &_color_func_swap_store_16av;
    }
    puVar8 = *(undefined **)(uVar13 + (int)ppuVar6);
    goto LAB_000c342c;
  }
  uVar13 = param_2 >> 0x13 & 0x21;
  if (uVar13 == 0x20) {
    bVar4 = true;
    if (bVar3) {
      codeChunk = &_gleVATex0FuncCopySTRQ20AV;
    }
    else if (bVar1) {
      codeChunk = &_gleVATex0FuncCopyST16AV;
    }
    else {
      codeChunk = &_gleVATex0FuncCopySTQ20AV;
    }
LAB_000c3584:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
  }
  else if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATex0LoadCurrentAV,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
      if (!bVar2) {
        chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,chunkWordCountThenCodeCursor);
        chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
      }
      if (bVar3) goto LAB_000c3560;
LAB_000c356c:
      if (bVar1) {
        codeChunk = &_gleVAStoreTex0ST16AV;
      }
      else {
        codeChunk = &_gleVAStoreTex0STQ20AV;
      }
      goto LAB_000c3584;
    }
  }
  else if (uVar13 == 0x21) {
    uVar13 = param_2 >> 4 & 0xf;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)((&_tex0_func_array_av)[uVar13],chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    if (!bVar3) {
      if (!bVar1) goto LAB_000c34ac;
    }
    else {
      if (uVar13 < 8) {
        codeChunk = &_gleVATexSetRTo0AndQTo1AV;
      }
      else {
LAB_000c34ac:
        if (0xb < uVar13) goto LAB_000c34cc;
        codeChunk = &_gleVATexSetQTo1AV;
      }
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    }
LAB_000c34cc:
    if (!bVar2) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    }
    if (!bVar3) goto LAB_000c356c;
LAB_000c3560:
    codeChunk = &_gleVAStoreTex0STRQ20AV;
    goto LAB_000c3584;
  }
  uVar13 = param_2 >> 0x14 & 0x21;
  if (uVar13 == 0x20) {
    bVar4 = true;
    if (bVar3) {
      codeChunk = &_gleVATex1FuncCopySTRQ36AV;
    }
    else if (bVar1) {
      codeChunk = &_gleVATex1FuncCopyST24AV;
    }
    else {
      codeChunk = &_gleVATex1FuncCopySTQ32AV;
    }
LAB_000c36dc:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
  }
  else if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATex1FuncCurrentAV,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
      if (!bVar2) {
        chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,chunkWordCountThenCodeCursor);
        chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
      }
      if (bVar3) goto LAB_000c36b8;
LAB_000c36c4:
      if (bVar1) {
        codeChunk = &_gleVAStoreTex1ST24AV;
      }
      else {
        codeChunk = &_gleVAStoreTex1STQ32AV;
      }
      goto LAB_000c36dc;
    }
  }
  else if (uVar13 == 0x21) {
    uVar13 = param_2 & 0xf;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)((&_tex1_func_array_av)[uVar13],chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    if (!bVar3) {
      if (!bVar1) goto LAB_000c3604;
    }
    else {
      if (uVar13 < 8) {
        codeChunk = &_gleVATexSetRTo0AndQTo1AV;
      }
      else {
LAB_000c3604:
        if (0xb < uVar13) goto LAB_000c3624;
        codeChunk = &_gleVATexSetQTo1AV;
      }
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    }
LAB_000c3624:
    if (!bVar2) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    }
    if (!bVar3) goto LAB_000c36c4;
LAB_000c36b8:
    codeChunk = &_gleVAStoreTex1STRQ36AV;
    goto LAB_000c36dc;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAIncDataAVRTC,chunkWordCountThenCodeCursor);
  chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
  if (uVar5 == 2) {
    codeChunk = &_gleVADoubleFlushDataAVRTC;
  }
  else if (uVar5 < 3) {
    if (uVar5 != 1) goto LAB_000c3774;
    if ((*(uint *)PTR__gle_processor_0011204c & 0x40) == 0) {
      codeChunk = &_gleVASingleFlushDataAVRTC;
    }
    else {
      codeChunk = &_gleVASingleFlushDataAVRTC_128;
    }
  }
  else {
    if (uVar5 != 3) goto LAB_000c3774;
    codeChunk = &_gleVATripleFlushDataAVRTC;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor);
  chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
LAB_000c3774:
  if (bVar4) {
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAIncOldDataAVRTC,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAEndLoopAVRTC,chunkWordCountThenCodeCursor);
  chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
  puVar15 = (undefined4 *)(chunkWordCountThenCodeCursor + -4);
  if (uVar5 - 1 < 3) {
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVACompleteFlushDataRTC_10d8a4,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAEpilogNoTransAVRTC,chunkWordCountThenCodeCursor);
  uVar12 = ((int (*)())_gleRTCBuildABranch_c3068)(*puVar15,chunkWordCountThenCodeCursor2 - (int)puVar15 >> 2);
  *puVar15 = uVar12;
  emittedWordCount = ((chunkWordCountThenCodeCursor + chunkWordCount2 * 4) - iVar7) + -0x20 >> 2;
  if (emittedWordCount < 0x311) {
    iVar7 = _gleShrinkFuncCacheElem(iVar7,emittedWordCount);
    puVar8 = PTR__glePushInstructions_00112054;
    *(int *)(glContext + 0x49b4) = iVar7;
    (**(code **)puVar8)(emittedWordCount,(undefined *)(iVar7 + 0x20));
    return (undefined *)(iVar7 + 0x20);
  }
                    
  _exit(1);
}

/* _gleBuildCompileFuncAV @ 0xc386c (2036 bytes) */
int _gleBuildCompileFuncAV(glContext, param_2)
  int glContext;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int chunkWordCount3;
  undefined **ppuVar8;
  int iVar9;
  undefined *puVar10;
  undefined *codeChunk;
  int chunkWordCountThenCodeCursor;
  int chunkWordCount;
  int chunkWordCountThenCodeCursor2;
  int iVar13;
  int chunkWordCount2;
  undefined4 uVar14;
  undefined4 *puVar15;
  
  bVar4 = false;
  iVar7 = (uint)((*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 3) == 1) *
          ((uint)*(ushort *)(glContext + 0x4990) * 2 + 0x1f >> 5 & 0xff);
  uVar5 = *(uint *)(glContext + 0x498c);
  iVar9 = _gleCreateFuncCacheElem(*(undefined4 *)(glContext + 0x49b4),0x310);
  if (iVar9 == 0) {
    return PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar9 + 8) = param_2;
  if (*(short *)(glContext + 0x49be) == *(short *)(glContext + 0x49bc)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar9 + 4));
  }
  else {
    *(short *)(glContext + 0x49be) = *(short *)(glContext + 0x49be) + 1;
  }
  uVar2 = param_2 >> 0x10;
  if ((uVar2 & 0x21) == 0x21) {
    codeChunk = &_gleVAPrologAVRTC;
  }
  else {
    codeChunk = &_gleVAPrologNoTransAVRTC;
  }
  uVar3 = param_2 >> 0x12;
  chunkWordCountThenCodeCursor = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,iVar9 + 0x20);
  uVar6 = uVar3 & 0x21;
  chunkWordCountThenCodeCursor = iVar9 + 0x20 + chunkWordCountThenCodeCursor * 4;
  if (((uVar6 != 0x20) && (0x20 < uVar6)) && (uVar6 == 0x21)) {
    uVar6 = param_2 >> 0x18 & 0xc;
    if (uVar6 == 8) {
      codeChunk = &_gleVAFogExpInitAVRTC;
LAB_000c39bc:
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount * 4;
    }
    else if (uVar6 < 9) {
      if (uVar6 == 4) {
        codeChunk = &_gleVAFogLinearInitAVRTC;
        goto LAB_000c39bc;
      }
    }
    else if (uVar6 == 0xc) {
      codeChunk = &_gleVAFogExp2InitAVRTC;
      goto LAB_000c39bc;
    }
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAFogAllInitAVRTC,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount * 4;
  }
  bVar1 = (uVar5 >> 0xf & 1) == 0;
  if (!bVar1) {
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVALoadSwapVectAVRTC,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount * 4;
  }
  chunkWordCountThenCodeCursor2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAStartLoopAVRTC,chunkWordCountThenCodeCursor);
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor + chunkWordCountThenCodeCursor2 * 4;
  if (((uVar2 & 0x21) == 0x21) || ((uVar3 & 0x21) == 0x21)) {
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(*(undefined4 *)((int)&_vertex_load_array_av + (param_2 >> 10 & 0x3c)),chunkWordCountThenCodeCursor2
                       );
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + iVar13 * 4;
  }
  if ((uVar3 & 0x21) == 0x20) {
    codeChunk = &_gleVAFogFuncCopyAV;
LAB_000c3b0c:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if ((uVar3 & 0x21) == 0x21) {
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(*(undefined4 *)((int)&_vertex_fill_array_av + (param_2 >> 0xc & 0xc)),chunkWordCountThenCodeCursor2
                       );
    uVar5 = param_2 >> 0x18 & 0xc;
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + iVar13 * 4;
    if (uVar5 == 8) {
      codeChunk = &_gleVAFogExpCalcAVRTC;
LAB_000c3ad8:
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    }
    else if (uVar5 < 9) {
      if (uVar5 == 4) {
        codeChunk = &_gleVAFogLinearCalcAVRTC;
        goto LAB_000c3ad8;
      }
    }
    else if (uVar5 == 0xc) {
      codeChunk = &_gleVAFogExp2CalcAVRTC;
      goto LAB_000c3ad8;
    }
    if (bVar1) {
      codeChunk = &_gleVAFogStoreAV;
    }
    else {
      codeChunk = &_gleVAFogSwapAV;
    }
    goto LAB_000c3b0c;
  }
  if ((uVar2 & 0x21) == 0x21) {
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(*(undefined4 *)((int)&_vertex_func_array_av + (param_2 >> 0xc & 0xc)),chunkWordCountThenCodeCursor2
                       );
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + iVar13 * 4;
    if ((param_2 & 0x10000000) == 0) {
      codeChunk = &_gleVALoadClipVertAVRTC;
    }
    else {
      codeChunk = &_gleVALoadVertAVRTC;
    }
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    if (!bVar1) {
      codeChunk = &_gleVASwapVertAVRTC;
      goto LAB_000c3bb8;
    }
  }
  else {
    bVar4 = true;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVALoadOldVertAVRTC,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    if (bVar1) {
      codeChunk = &_gleVASplatOOWAVRTC;
    }
    else {
      codeChunk = &_gleVASplatSwapOOWAVRTC;
    }
LAB_000c3bb8:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAStoreVertXYZWAVRTC,chunkWordCountThenCodeCursor2);
  uVar5 = param_2 >> 0x11 & 0x21;
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  if (uVar5 == 0x20) {
    bVar4 = true;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAColorLoadCopyInt16AV,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    puVar10 = &_gleVAStoreColorInt16AV;
LAB_000c3cac:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if (uVar5 < 0x21) {
    if (uVar5 == 1) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAColorLoadCurrentAV,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (bVar1) {
        puVar10 = &_gleVAStoreColor16AV;
      }
      else {
        puVar10 = &_gleVASwapStoreColor16AV;
      }
      goto LAB_000c3cac;
    }
  }
  else if (uVar5 == 0x21) {
    uVar5 = param_2 >> 6 & 0x3c;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(*(undefined4 *)((int)&_color_func_array_av + uVar5),chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    if (bVar1) {
      ppuVar8 = &_color_func_store_16av;
    }
    else {
      ppuVar8 = &_color_func_swap_store_16av;
    }
    puVar10 = *(undefined **)(uVar5 + (int)ppuVar8);
    goto LAB_000c3cac;
  }
  uVar5 = param_2 >> 0x13 & 0x21;
  if (uVar5 == 0x20) {
    bVar4 = true;
    if ((uVar3 & 0x21) == 0) {
      codeChunk = &_gleVATex0FuncCopyST20AV;
    }
    else {
      codeChunk = &_gleVATex0FuncCopyST24AV;
    }
LAB_000c3df0:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if (uVar5 < 0x21) {
    if (uVar5 == 1) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATex0LoadCurrentAV,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATexWDivideAV,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (!bVar1) {
        chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,chunkWordCountThenCodeCursor2);
        chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      }
LAB_000c3dd4:
      if ((uVar3 & 0x21) == 0) {
        codeChunk = &_gleVAStoreTex0AndQW20AV;
      }
      else {
        codeChunk = &_gleVAStoreTex0AndQW24AV;
      }
      goto LAB_000c3df0;
    }
  }
  else if (uVar5 == 0x21) {
    uVar5 = param_2 >> 4 & 0xf;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)((&_tex0_func_array_av)[uVar5],chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATexWDivideAV,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    if (!bVar1) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    }
    if (0xb < uVar5) goto LAB_000c3dd4;
    if ((uVar3 & 0x21) == 0) {
      codeChunk = &_gleVAStoreTex0ST20AV;
    }
    else {
      codeChunk = &_gleVAStoreTex0ST24AV;
    }
    goto LAB_000c3df0;
  }
  uVar5 = param_2 >> 0x14 & 0x21;
  if (uVar5 == 0x20) {
    bVar4 = true;
    if ((uVar3 & 0x21) == 0) {
      codeChunk = &_gleVATex1FuncCopySTQ28AV;
    }
    else {
      codeChunk = &_gleVATex1FuncCopySTQ32AV;
    }
LAB_000c3ef0:
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  else if (uVar5 < 0x21) {
    if (uVar5 == 1) {
      codeChunk = &_gleVATex1FuncCurrentAV;
LAB_000c3e90:
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
LAB_000c3ea0:
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATexWDivideAV,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      if (!bVar1) {
        chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,chunkWordCountThenCodeCursor2);
        chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
      }
      if ((uVar3 & 0x21) == 0) {
        codeChunk = &_gleVAStoreTex1STQ28AV;
      }
      else {
        codeChunk = &_gleVAStoreTex1STQ32AV;
      }
      goto LAB_000c3ef0;
    }
  }
  else if (uVar5 == 0x21) {
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)((&_tex1_func_array_av)[param_2 & 0xf],chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
    if ((param_2 & 0xf) < 0xc) {
      codeChunk = &_gleVATexSetQTo1AV;
      goto LAB_000c3e90;
    }
    goto LAB_000c3ea0;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAIncDataAVRTC,chunkWordCountThenCodeCursor2);
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  if (iVar7 == 2) {
    codeChunk = &_gleVADoubleFlushDataAVRTC;
  }
  else {
    if (iVar7 != 3) goto LAB_000c3f50;
    codeChunk = &_gleVATripleFlushDataAVRTC;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor2);
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
LAB_000c3f50:
  if (bVar4) {
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAIncOldDataAVRTC,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  }
  chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAEndLoopAVRTC,chunkWordCountThenCodeCursor2);
  chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount2 * 4;
  puVar15 = (undefined4 *)(chunkWordCountThenCodeCursor2 + -4);
  if (iVar7 - 2U < 2) {
    chunkWordCount3 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVACompleteFlushDataRTC_10d8a4,chunkWordCountThenCodeCursor2);
    chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount3 * 4;
  }
  if ((uVar2 & 0x21) == 0x21) {
    codeChunk = &_gleVAEpilogAVRTC;
  }
  else {
    codeChunk = &_gleVAEpilogNoTransAVRTC;
  }
  iVar7 = ((int (*)())_gleRTCAddAChunk_c3074)(codeChunk,chunkWordCountThenCodeCursor2);
  uVar14 = ((int (*)())_gleRTCBuildABranch_c3068)(*puVar15,chunkWordCountThenCodeCursor - (int)puVar15 >> 2);
  *puVar15 = uVar14;
  iVar7 = ((chunkWordCountThenCodeCursor2 + iVar7 * 4) - iVar9) + -0x20 >> 2;
  if (iVar7 < 0x311) {
    iVar9 = _gleShrinkFuncCacheElem(iVar9,iVar7);
    puVar10 = PTR__glePushInstructions_00112054;
    *(int *)(glContext + 0x49b4) = iVar9;
    (**(code **)puVar10)(iVar7,(undefined *)(iVar9 + 0x20));
    return (undefined *)(iVar9 + 0x20);
  }
                    
  _exit(1);
}

/* _gleEmitTransformInstructions @ 0xc4060 (1100 bytes) */
int _gleEmitTransformInstructions(param_1, param_2, param_3, param_4, param_5, param_6)
  uint *param_1;
  uint param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  uint uVar1;
  uint uVar2;
  int *srcCursor;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int remaining;
  int *srcCursor2;
  int iVar12;
  int iVar13;
  int iVar14;
  int remaining2;
  int iVar15;
  
  uVar4 = param_5 * 0x200000 + 0x600000;
  iVar15 = 3;
  srcCursor2 = (int *)(param_3 + 0x3c);
  iVar13 = param_5 + 3;
  iVar12 = param_3 + 0xc;
  do {
    uVar1 = iVar15 << 1;
    iVar14 = -1;
    uVar6 = 0xc0;
    remaining = 3;
    uVar7 = 6;
    do {
      uVar2 = param_2 << (uVar1 & 0x3e) & uVar6;
      uVar5 = uVar2 >> (uVar7 & 0x3f);
      if (uVar5 - 1 < 2) {
        iVar14 = param_4 + remaining;
        param_2 = param_2 | uVar6 >> (uVar1 & 0x3e);
        break;
      }
      if (((remaining == 3) && (param_6 != 0)) && (uVar2 == 0)) {
        uVar5 = 2;
        param_2 = param_2 | uVar6 >> (uVar1 & 0x3e);
        iVar14 = *srcCursor2;
        break;
      }
      remaining = remaining + -1;
      uVar6 = uVar6 << 8;
      uVar7 = uVar7 + 8;
    } while (-1 < remaining);
    if (remaining == -1) {
      uVar6 = 0xc0;
      remaining = 3;
      do {
        if ((param_2 << (uVar1 & 0x3e) & uVar6) == 0) {
          param_2 = param_2 | uVar6 >> (uVar1 & 0x3e);
          *param_1 = uVar4 | (param_4 + remaining) * 0x10000 |
                     *(int *)((remaining * 4 + iVar15) * 4 + param_3) << 6 | 0xec000032;
          param_1 = param_1 + 1;
          break;
        }
        remaining = remaining + -1;
        uVar6 = uVar6 << 8;
      } while (-1 < remaining);
    }
    if (-1 < iVar14) {
      uVar6 = 0xc0;
      remaining = 3;
      uVar2 = param_4 * 0x10000 + 0x30000;
      uVar7 = param_4 * 0x800 + 0x1800;
      uVar9 = 6;
      do {
        uVar8 = (param_2 << (uVar1 & 0x3e) & uVar6) >> (uVar9 & 0x3f);
        if (uVar8 - 1 < 2) {
          param_2 = param_2 | uVar6 >> (uVar1 & 0x3e);
          if (uVar5 == 2) {
            uVar7 = uVar4 | iVar14 << 0x10 | uVar7;
            if (uVar8 == 2) {
              uVar7 = uVar4 | (param_4 + remaining) * 0x10000 | iVar14 << 0xb | 0xec00002a;
            }
            else {
LAB_000c42a8:
              uVar7 = uVar7 | 0xec000028;
            }
            *param_1 = uVar7;
          }
          else {
            if (uVar8 == 2) {
              uVar7 = uVar4 | (param_4 + remaining) * 0x10000 | iVar14 << 0xb;
              goto LAB_000c42a8;
            }
            *param_1 = uVar4 | uVar2 | iVar14 << 0xb | 0xec00002a;
            param_1 = param_1 + 1;
            *param_1 = uVar4 | iVar13 << 0xb | 0xfc000050;
          }
          param_1 = param_1 + 1;
          break;
        }
        remaining = remaining + -1;
        uVar6 = uVar6 << 8;
        uVar9 = uVar9 + 8;
        uVar7 = uVar7 - 0x800;
        uVar2 = uVar2 - 0x10000;
      } while (-1 < remaining);
      if (remaining == -1) {
        uVar6 = 0xc0;
        remaining = 3;
        srcCursor = (int *)(iVar12 + 0x30);
        uVar7 = param_4 * 0x10000 + 0x30000;
        do {
          if ((param_2 << (uVar1 & 0x3e) & uVar6) == 0) {
            param_2 = param_2 | uVar6 >> (uVar1 & 0x3e);
            if (uVar5 == 2) {
              uVar1 = uVar4 | (param_4 + remaining) * 0x10000 | iVar14 << 0xb |
                      *(int *)((remaining * 4 + iVar15) * 4 + param_3) << 6 | 0xec00003a;
            }
            else {
              uVar1 = uVar4 | uVar7 | iVar14 << 0xb | *srcCursor << 6 | 0xec000038;
            }
            *param_1 = uVar1;
            param_1 = param_1 + 1;
            break;
          }
          remaining = remaining + -1;
          uVar6 = uVar6 << 8;
          uVar7 = uVar7 - 0x10000;
          srcCursor = srcCursor + -4;
        } while (-1 < remaining);
        if (remaining == -1) {
          if (uVar5 == 2) {
            uVar1 = uVar4 | iVar14 << 0xb | 0xfc000090;
          }
          else {
            uVar1 = uVar4 | iVar14 << 0xb | 0xfc000050;
          }
          *param_1 = uVar1;
          param_1 = param_1 + 1;
        }
      }
    }
    iVar15 = iVar15 + -1;
    iVar12 = iVar12 + -4;
    iVar13 = iVar13 + -1;
    uVar4 = uVar4 - 0x200000;
    srcCursor2 = srcCursor2 + -1;
    if (iVar15 < 0) {
      iVar12 = 0;
      do {
        remaining = 3;
        iVar15 = param_5 + 3;
        iVar13 = param_3 + 0xc;
        do {
          uVar2 = param_4 * 0x800 + 0x1800;
          uVar5 = iVar15 << 0x15 | iVar15 << 0x10;
          uVar1 = 0xc0;
          remaining2 = 3;
          uVar4 = remaining << 1;
          uVar7 = 6;
          uVar6 = uVar2;
          do {
            uVar9 = (param_2 << (uVar4 & 0x3e) & uVar1) >> (uVar7 & 0x3f);
            if (uVar9 - 1 < 2) {
              param_2 = param_2 | uVar1 >> (uVar4 & 0x3e);
              if (uVar9 == 2) {
                uVar1 = uVar5 | uVar6 | 0xec00002a;
              }
              else {
                uVar1 = uVar5 | uVar2 | 0xec000028;
              }
              *param_1 = uVar1;
              param_1 = param_1 + 1;
              break;
            }
            remaining2 = remaining2 + -1;
            uVar1 = uVar1 << 8;
            uVar7 = uVar7 + 8;
            uVar6 = uVar6 - 0x800;
            uVar2 = uVar2 - 0x800;
          } while (-1 < remaining2);
          if (remaining2 == -1) {
            uVar1 = 0xc0;
            remaining2 = 3;
            srcCursor2 = (int *)(iVar13 + 0x30);
            uVar6 = param_4 * 0x10000 + 0x30000;
            do {
              if ((param_2 << (uVar4 & 0x3e) & uVar1) == 0) {
                param_2 = param_2 | uVar1 >> (uVar4 & 0x3e);
                *param_1 = iVar15 << 0x15 | uVar6 | iVar15 << 0xb | *srcCursor2 << 6 | 0xec00003a;
                param_1 = param_1 + 1;
                break;
              }
              remaining2 = remaining2 + -1;
              uVar1 = uVar1 << 8;
              uVar6 = uVar6 - 0x10000;
              srcCursor2 = srcCursor2 + -4;
            } while (-1 < remaining2);
          }
          remaining = remaining + -1;
          iVar13 = iVar13 + -4;
          iVar15 = iVar15 + -1;
        } while (-1 < remaining);
        iVar12 = iVar12 + 1;
        if (2 < iVar12) {
          return param_1;
        }
      } while( true );
    }
  } while( true );
}

/* _gleRTCBuildABranch_c44ac @ 0xc44ac (12 bytes) */
int _gleRTCBuildABranch_c44ac(branchInstruction, branchWordOffset)
  uint branchInstruction;
  uint branchWordOffset;
{
  return (branchWordOffset & 0x3fff) << 2 | branchInstruction & 0xffff0003;
}

/* _gleRTCAddAChunk_c44b8 @ 0xc44b8 (48 bytes) */
int _gleRTCAddAChunk_c44b8(srcCursor, dstCursor)
  int *srcCursor;
  int *dstCursor;
{
  int word;
  int copiedWords;
  
  copiedWords = 0;
  word = *srcCursor;
  while (word != 0) {
    *dstCursor = word;
    copiedWords = copiedWords + 1;
    srcCursor = srcCursor + 1;
    dstCursor = dstCursor + 1;
    word = *srcCursor;
  }
  return copiedWords;
}

/* _gleSetModelviewFuncAll @ 0xc44e8 (100 bytes) */
void _gleSetModelviewFuncAll(glContext, forwardedArg2, forwardedArg3)
  int glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(*_gleBuildModelviewTransformFunc)(glContext,0,forwardedArg3);
  *(code **)(glContext + 0x5064) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,forwardedArg2,forwardedArg3);
  return;
}

/* _gleSetModelviewFuncW1 @ 0xc454c (100 bytes) */
void _gleSetModelviewFuncW1(glContext, forwardedArg2, forwardedArg3)
  int glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(*_gleBuildModelviewTransformFunc)(glContext,1,forwardedArg3);
  *(code **)(glContext + 0x5064) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,forwardedArg2,forwardedArg3);
  return;
}

/* _gleSetModelviewFuncZ0W1 @ 0xc45b0 (100 bytes) */
void _gleSetModelviewFuncZ0W1(glContext, forwardedArg2, forwardedArg3)
  int glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(*_gleBuildModelviewTransformFunc)(glContext,3,forwardedArg3);
  *(code **)(glContext + 0x5064) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,forwardedArg2,forwardedArg3);
  return;
}

/* _gleTransformModelviewBlend @ 0xc4614 (76 bytes) */
void _gleTransformModelviewBlend(unusedArg1, vertexCursor, vertexCount)
  undefined4 unusedArg1;
  uint vertexCursor;
  int vertexCount;
{
  uint vertexEndThenRemaining;
  
  vertexEndThenRemaining = vertexCursor + vertexCount * 0x100;
  if (vertexEndThenRemaining <= vertexCursor) {
    return;
  }
  vertexEndThenRemaining = (vertexEndThenRemaining - vertexCursor) + 0xff >> 8;
  do {
    *(undefined4 *)(vertexCursor + 0x20) = *(undefined4 *)(vertexCursor + 0xf0);
    *(undefined4 *)(vertexCursor + 0x24) = *(undefined4 *)(vertexCursor + 0xf4);
    *(undefined4 *)(vertexCursor + 0x28) = *(undefined4 *)(vertexCursor + 0xf8);
    *(undefined4 *)(vertexCursor + 0x2c) = *(undefined4 *)(vertexCursor + 0xfc);
    vertexCursor = vertexCursor + 0x100;
    vertexEndThenRemaining = vertexEndThenRemaining - 1;
  } while (vertexEndThenRemaining != 0);
  return;
}

/* _gleBuildModelviewTransformFuncAV_body @ 0xc4664 (1236 bytes) */
int _gleBuildModelviewTransformFuncAV_body(glContext, inputFlags)
  int glContext;
  uint inputFlags;
{
  uint matrixClassKey;
  uint matrixIdentifier;
  uint variantFlags;
  int funcCacheElem;
  int codeWordCount;
  int chunkWordCount;
  undefined *puVar5;
  undefined *codeChunk;
  int chunkWordCount2;
  undefined4 branchInstruction;
  undefined4 *loopStart;
  undefined4 *codeEnd;
  undefined4 *codeCursor;
  undefined4 *bodyCursor;
  uint matrixShapeBits;
  uint fogMode;
  int *cacheHead;
  int *cacheScan;
  
  if (*(char *)(glContext + 0x4661) != '\0') {
    return (int *)PTR__gleTransformModelviewBlend_001109f8;
  }
  matrixIdentifier = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(glContext,glContext + 0x1cc0);
  *(uint *)(glContext + 0x5090) = matrixIdentifier;
  matrixShapeBits = matrixIdentifier;
  if (((inputFlags & 2) != 0) && (matrixShapeBits = matrixIdentifier | 0xff00, (matrixIdentifier & 0xc0c000c) == 0xc0c000c)) {
    matrixShapeBits = matrixIdentifier & 0xffff00ff | 0xfb00;
  }
  variantFlags = inputFlags | *(ushort *)(glContext + 0x4fe8);
  if (*(short *)(0x3170 + glContext + 4) == 0x1102) {
    variantFlags = variantFlags | 0x20;
  }
  if ((*(byte *)(glContext + 0x50b4) & 1) == 0) {
    if ((variantFlags & 0x10) == 0) {
      matrixShapeBits = matrixShapeBits & 0xc0c0c0c | 0xb3e3f3f2;
    }
    else {
      matrixShapeBits = 0xbfeffbfe;
    }
  }
  matrixClassKey = matrixShapeBits;
  if ((matrixShapeBits != 0xbfeffbfe) && (matrixClassKey = 0x3fcff3fc, (matrixShapeBits & 0x3fcff3fc) != 0x3fcff3fc)) {
    matrixClassKey = 0;
  }
  cacheHead = *(int **)(glContext + 0x5094);
  cacheScan = cacheHead;
  do {
    if (matrixClassKey == cacheScan[2] && variantFlags == cacheScan[3]) {
      if (cacheScan != cacheHead) {
        _gleMoveFuncCacheElem(cacheHead,cacheScan);
        *(int **)(glContext + 0x5094) = cacheScan;
      }
      return cacheScan + 8;
    }
    cacheScan = (int *)*cacheScan;
  } while (cacheScan != cacheHead);
  funcCacheElem = _gleCreateFuncCacheElem(cacheScan,0x70);
  if (funcCacheElem == 0) {
    return (int *)PTR__gleRTCNoop_00112058;
  }
  *(uint *)(funcCacheElem + 8) = matrixClassKey;
  *(uint *)(funcCacheElem + 0xc) = variantFlags;
  if (*(short *)(glContext + 0x509a) == *(short *)(glContext + 0x5098)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(funcCacheElem + 4));
  }
  else {
    *(short *)(glContext + 0x509a) = *(short *)(glContext + 0x509a) + 1;
  }
  codeEnd = (undefined4 *)(funcCacheElem + 0x20);
  if ((matrixClassKey == 0xbfeffbfe) && ((variantFlags & 0xc) == 0)) goto LAB_000c4ac0;
  fogMode = variantFlags & 0xc;
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_glePrologAVRTC_10f1c8,codeEnd);
  loopStart = codeEnd + chunkWordCount;
  if (matrixClassKey != 0xbfeffbfe) {
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadMatrixPtrRTC_10f0a4,loopStart);
    if ((variantFlags & 2) == 0) {
      codeChunk = &_gleLoadMatrixVectorsRTC_10f20c;
    }
    else {
      codeChunk = &_gleLoadMatrixVectorsZ0RTC_10f22c;
    }
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c44b8)(codeChunk,loopStart + chunkWordCount);
    loopStart = loopStart + chunkWordCount + chunkWordCount2;
  }
  if (fogMode == 8) {
    codeChunk = &_gleFogExpInitAVRTC;
LAB_000c48cc:
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(codeChunk,loopStart);
    loopStart = loopStart + chunkWordCount;
  }
  else if (fogMode < 9) {
    if (fogMode == 4) {
      codeChunk = &_gleFogLinearInitAVRTC;
      goto LAB_000c48cc;
    }
  }
  else if (fogMode == 0xc) {
    codeChunk = &_gleFogExp2InitAVRTC;
    goto LAB_000c48cc;
  }
  if (matrixClassKey == 0) {
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadVectorsRTC_10f248,loopStart);
    codeCursor = loopStart + chunkWordCount;
    if ((variantFlags & 1) == 0) {
      if ((variantFlags & 2) == 0) {
        codeChunk = &_gleFullMatrixMultRTC_10f274;
      }
      else {
        codeChunk = &_gleFullMatrixMultZ0RTC_10f2b8;
      }
    }
    else if ((variantFlags & 2) == 0) {
      codeChunk = &_gleFullMatrixMultW1RTC_10f2ec;
    }
    else {
      codeChunk = &_gleFullMatrixMultZ0W1RTC_10f320;
    }
LAB_000c4998:
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(codeChunk,codeCursor);
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleStoreVectorsRTC_10f260,codeCursor + chunkWordCount);
    bodyCursor = codeCursor + chunkWordCount + chunkWordCount2;
  }
  else {
    bodyCursor = loopStart;
    if (matrixClassKey == 0x3fcff3fc) {
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleDiagMatrixSetupRTC_10f344,loopStart);
      loopStart = loopStart + chunkWordCount;
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadVectorsRTC_10f248,loopStart);
      codeCursor = loopStart + chunkWordCount;
      codeChunk = &_gleDiagMatrixMultRTC_10f35c;
      goto LAB_000c4998;
    }
  }
  if (fogMode != 0) {
    if ((variantFlags & 0x10) == 0) {
      if (matrixClassKey == 0xbfeffbfe) {
        chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadVectorsToDstRTC,bodyCursor);
        bodyCursor = bodyCursor + chunkWordCount;
      }
      if ((variantFlags & 0x20) == 0) goto LAB_000c4a24;
      codeChunk = &_gleFogStoreCoordAVRTC;
    }
    else {
      codeChunk = &_gleFogLoadCoordAVRTC;
    }
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(codeChunk,bodyCursor);
    bodyCursor = bodyCursor + chunkWordCount;
  }
LAB_000c4a24:
  if (fogMode == 8) {
    codeChunk = &_gleFogExpAVRTC;
LAB_000c4a68:
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(codeChunk,bodyCursor);
    bodyCursor = bodyCursor + chunkWordCount;
  }
  else if (fogMode < 9) {
    if (fogMode == 4) {
      codeChunk = &_gleFogLinearAVRTC;
      goto LAB_000c4a68;
    }
  }
  else if (fogMode == 0xc) {
    codeChunk = &_gleFogExp2AVRTC;
    goto LAB_000c4a68;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleIncVertex2PtrRTC,bodyCursor);
  bodyCursor = bodyCursor + chunkWordCount;
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleEpilogAVRTC_10f1fc,bodyCursor);
  codeEnd = bodyCursor + chunkWordCount;
  branchInstruction = ((int (*)())_gleRTCBuildABranch_c44ac)(*bodyCursor,(int)loopStart - (int)bodyCursor >> 2);
  *bodyCursor = branchInstruction;
LAB_000c4ac0:
  codeWordCount = (int)codeEnd + (-0x1c - funcCacheElem) >> 2;
  *codeEnd = 0x4e800020;
  if (codeWordCount < 0x71) {
    funcCacheElem = _gleShrinkFuncCacheElem(funcCacheElem,codeWordCount);
    puVar5 = PTR__glePushInstructions_00112054;
    *(int *)(glContext + 0x5094) = funcCacheElem;
    (**(code **)puVar5)(codeWordCount,(int *)(funcCacheElem + 0x20));
    return (int *)(funcCacheElem + 0x20);
  }
                    
  _exit(1);
}

/* _gleBuildModelviewTransformFuncNO @ 0xc4b38 (1852 bytes) */
int _gleBuildModelviewTransformFuncNO(glContext, param_2)
  int glContext;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined *codeChunk;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int chunkWordCount;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  uint uVar14;
  uint *puVar15;
  uint *puVar16;
  uint *codeCursor;
  int iVar18;
  int local_70 [15];
  int local_34;
  
  if (*(char *)(glContext + 0x4661) != '\0') {
    return (int *)PTR__gleTransformModelviewBlend_001109f8;
  }
  uVar3 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(glContext,glContext + 0x1cc0);
  *(uint *)(glContext + 0x5090) = uVar3;
  uVar14 = uVar3;
  if (((param_2 & 2) != 0) && (uVar14 = uVar3 | 0xff00, (uVar3 & 0xc0c000c) == 0xc0c000c)) {
    uVar14 = uVar3 & 0xffff00ff | 0xfb00;
  }
  uVar3 = param_2 | *(ushort *)(glContext + 0x4fe8);
  if (*(short *)(0x3170 + glContext + 4) == 0x1102) {
    uVar3 = uVar3 | 0x20;
  }
  if ((*(byte *)(glContext + 0x50b4) & 1) == 0) {
    if ((uVar3 & 0x10) == 0) {
      uVar14 = uVar14 & 0xc0c0c0c | 0xb3e3f3f2;
    }
    else {
      uVar14 = 0xbfeffbfe;
    }
  }
  piVar12 = *(int **)(glContext + 0x5094);
  piVar13 = piVar12;
  do {
    if (uVar14 == piVar13[2] && uVar3 == piVar13[3]) {
      if (piVar13 != piVar12) {
        _gleMoveFuncCacheElem(piVar12,piVar13);
        *(int **)(glContext + 0x5094) = piVar13;
      }
      return piVar13 + 8;
    }
    piVar13 = (int *)*piVar13;
  } while (piVar13 != piVar12);
  iVar4 = _gleCreateFuncCacheElem(piVar13,0x60);
  if (iVar4 == 0) {
    return (int *)PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar4 + 8) = uVar14;
  *(uint *)(iVar4 + 0xc) = uVar3;
  if (*(short *)(glContext + 0x509a) == *(short *)(glContext + 0x5098)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar4 + 4));
  }
  else {
    *(short *)(glContext + 0x509a) = *(short *)(glContext + 0x509a) + 1;
  }
  puVar16 = (uint *)(iVar4 + 0x20);
  if ((uVar14 == 0xbfeffbfe) && ((uVar3 & 0xc) == 0)) goto LAB_000c5204;
  uVar11 = uVar3 & 0xc;
  iVar8 = 8;
  if (uVar11 == 8) {
LAB_000c4cfc:
    iVar8 = 0xe;
  }
  else if (uVar11 < 9) {
    if (uVar11 == 4) {
      iVar8 = 0xc;
    }
  }
  else if (uVar11 == 0xc) goto LAB_000c4cfc;
  uVar10 = 0;
  iVar18 = 0x10;
  bVar1 = false;
  uVar6 = 0;
  piVar13 = local_70;
  do {
    if ((uVar14 << ((uVar6 & 0x1f) << 1) & 0xc0000000) == 0) {
      *piVar13 = iVar8;
      bVar1 = true;
      if (0xd < iVar8) {
        uVar10 = uVar10 - 8;
        *puVar16 = iVar8 << 0x15 | uVar10 & 0xffff | 0xd8010000;
        puVar16 = puVar16 + 1;
      }
      iVar8 = iVar8 + 1;
    }
    uVar6 = uVar6 + 1;
    piVar13 = piVar13 + 1;
    iVar18 = iVar18 + -1;
  } while (iVar18 != 0);
  if (bVar1) {
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadMatrixPtrRTC_10f0a4,puVar16);
    puVar16 = puVar16 + chunkWordCount;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadCounterRTC_10f0ac,puVar16);
  codeCursor = puVar16 + chunkWordCount;
  uVar10 = 0;
  uVar6 = 0;
  iVar8 = 0x10;
  do {
    if ((uVar14 << (uVar6 & 0x3f) & 0xc0000000) == 0) {
      *codeCursor = *(int *)((int)local_70 + uVar10) << 0x15 | uVar10 & 0xffff | 0xc0060000;
      codeCursor = codeCursor + 1;
    }
    uVar6 = uVar6 + 2;
    uVar10 = uVar10 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 4;
  uVar6 = 0;
  uVar7 = 3;
  uVar10 = 0xe00000;
  do {
    if ((uVar14 << ((uVar7 & 0x1f) << 1) & 0xc0c0c0c0) == 0xc0c0c0c0) {
      if (uVar6 == 0) {
        uVar2 = uVar10 | 0xc0030020;
        uVar6 = uVar7;
      }
      else {
        uVar2 = uVar10 | (uVar6 + 4) * 0x800 | 0xfc000090;
      }
      *codeCursor = uVar2;
      codeCursor = codeCursor + 1;
    }
    uVar7 = uVar7 - 1;
    uVar10 = uVar10 - 0x200000;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uVar6 = uVar14;
  if ((uVar3 & 1) == 0) {
    uVar10 = 3;
  }
  else {
    uVar10 = uVar14 & 0x3030303;
    if (uVar10 == 0x3030302) {
LAB_000c4ee8:
      uVar7 = 1;
      uVar6 = uVar14 | 0x3030303;
    }
    else if (uVar10 == 0x3030301) {
      *codeCursor = 0xc064002c;
      codeCursor[1] = 0xfce01850;
      uVar7 = 4;
      codeCursor = codeCursor + 2;
      uVar6 = uVar14 | 0x3030303;
    }
    else {
      uVar7 = 0;
      if (uVar10 == 0x3030300) {
        *codeCursor = local_34 << 0xb | 0xfce00090;
        codeCursor = codeCursor + 1;
        goto LAB_000c4ee8;
      }
    }
    if (uVar7 < 4) {
      do {
        if ((uVar6 >> ((uVar7 & 0x1f) << 1) & 3) - 1 < 2) {
          *codeCursor = 0xc064002c;
          codeCursor = codeCursor + 1;
          break;
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < 4);
    }
    uVar10 = 2;
  }
  if (uVar11 == 8) {
LAB_000c4f70:
    codeChunk = &_gleFogExpInitRTC;
LAB_000c4f78:
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(codeChunk,codeCursor);
    codeCursor = codeCursor + chunkWordCount;
  }
  else if (uVar11 < 9) {
    if (uVar11 == 4) {
      codeChunk = &_gleFogLinearInitRTC;
      goto LAB_000c4f78;
    }
  }
  else if (uVar11 == 0xc) goto LAB_000c4f70;
  uVar2 = uVar10 * 10;
  uVar7 = uVar10 * 4 + 0x20;
  puVar16 = codeCursor;
  do {
    uVar9 = 0xc0c0c0c0 >> ((uVar10 & 0x1f) << 1);
    if (((uVar6 & uVar9) == (uVar9 & ~(0x40000000 >> (uVar2 & 0x3f)))) &&
       (((uVar10 != 2 || (uVar11 == 0)) || ((uVar3 & 0x10) != 0)))) {
      uVar6 = uVar6 | uVar9;
    }
    uVar9 = 0xff000000 >> ((uVar10 & 7) << 3);
    if ((uVar6 & uVar9) != uVar9) {
      *puVar16 = uVar10 << 0x15 | uVar7 & 0xffff | 0xc0040000;
      puVar16 = puVar16 + 1;
    }
    uVar10 = uVar10 - 1;
    uVar2 = uVar2 - 10;
    uVar7 = uVar7 - 4;
  } while (-1 < (int)uVar10);
  puVar16 = (uint *)((int (*)())_gleEmitTransformInstructions)(puVar16,uVar6,local_70,0,4,uVar3 & 1);
  iVar8 = 4;
  uVar7 = 3;
  uVar6 = 0x2c;
  uVar10 = 0xe00000;
  uVar2 = 0x1e;
  do {
    uVar9 = 0xc0c0c0c0 >> ((uVar7 & 0x1f) << 1);
    if ((uVar14 & uVar9) != (uVar9 & ~(0x40000000 >> (uVar2 & 0x3f)))) {
      *puVar16 = uVar10 | uVar6 & 0xffff | 0xd0040000;
      puVar16 = puVar16 + 1;
    }
    uVar7 = uVar7 - 1;
    uVar2 = uVar2 - 10;
    uVar10 = uVar10 - 0x200000;
    uVar6 = uVar6 - 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if ((uVar3 & 0x10) == 0) {
    if ((uVar3 & 0x20) != 0) {
      codeChunk = &_gleFogStoreCoordRTC;
      goto LAB_000c50d8;
    }
  }
  else {
    codeChunk = &_gleFogLoadCoordRTC;
LAB_000c50d8:
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(codeChunk,puVar16);
    puVar16 = puVar16 + chunkWordCount;
  }
  if (uVar11 == 8) {
    if ((*(uint *)PTR__gle_processor_0011204c & 1) == 0) {
      codeChunk = &_gleFogExpNORTC;
    }
    else {
      codeChunk = &_gleFogExpGRRTC;
    }
LAB_000c516c:
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(codeChunk,puVar16);
    puVar16 = puVar16 + chunkWordCount;
  }
  else if (uVar11 < 9) {
    if (uVar11 == 4) {
      codeChunk = &_gleFogLinearNORTC;
      goto LAB_000c516c;
    }
  }
  else if (uVar11 == 0xc) {
    if ((*(uint *)PTR__gle_processor_0011204c & 1) == 0) {
      codeChunk = &_gleFogExp2NORTC;
    }
    else {
      codeChunk = &_gleFogExp2GRRTC;
    }
    goto LAB_000c516c;
  }
  uVar11 = 0;
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleEndLoopRTC_10f0b4,puVar16);
  uVar3 = 0;
  puVar16 = puVar16 + chunkWordCount;
  piVar13 = local_70;
  puVar15 = puVar16 + -1;
  iVar8 = 0x10;
  do {
    if (((uVar14 << ((uVar3 & 0x1f) << 1) & 0xc0000000) == 0) && (0xd < *piVar13)) {
      uVar11 = uVar11 - 8;
      *puVar16 = *piVar13 << 0x15 | uVar11 & 0xffff | 0xc8010000;
      puVar16 = puVar16 + 1;
    }
    uVar3 = uVar3 + 1;
    piVar13 = piVar13 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uVar14 = ((int (*)())_gleRTCBuildABranch_c44ac)(*puVar15,(int)codeCursor - (int)puVar15 >> 2);
  *puVar15 = uVar14;
LAB_000c5204:
  iVar8 = (int)puVar16 + (-0x1c - iVar4) >> 2;
  *puVar16 = 0x4e800020;
  if (iVar8 < 0x61) {
    iVar4 = _gleShrinkFuncCacheElem(iVar4,iVar8);
    puVar5 = PTR__glePushInstructions_00112054;
    *(int *)(glContext + 0x5094) = iVar4;
    (**(code **)puVar5)(iVar8,(int *)(iVar4 + 0x20));
    return (int *)(iVar4 + 0x20);
  }
                    
  _exit(1);
}

