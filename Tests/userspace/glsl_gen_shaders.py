#!/usr/bin/env python3
"""gen_shaders.py OUTDIR - write the GLSL differential-test corpus: NAME.vert / NAME.frag (language by extension).
Hand-written to exercise the front end (scanner, preprocessor, parser, type checker, intermediate tree, code generator) and its error paths."""
import os, sys
out = sys.argv[1]
os.makedirs(out, exist_ok=True)
S = {}

def add(name, lang, src):
    S['%s.%s' % (name, lang)] = src

# ---- valid vertex shaders -------------------------------------------------------------------------------------------------
add('v_min', 'vert', 'void main() { gl_Position = ftransform(); }\n')
add('v_mvp', 'vert', 'uniform mat4 mvp;\nattribute vec4 pos;\nvarying vec4 col;\nvoid main() { gl_Position = mvp * pos; col = gl_Color; }\n')
add('v_texcoord', 'vert', 'varying vec2 uv;\nvoid main() { uv = gl_MultiTexCoord0.xy; gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; }\n')
add('v_light', 'vert', '''varying vec3 n; varying vec3 l;
uniform vec3 lightpos;
void main() {
  vec4 p = gl_ModelViewMatrix * gl_Vertex;
  n = normalize(gl_NormalMatrix * gl_Normal);
  l = normalize(lightpos - p.xyz);
  gl_Position = gl_ProjectionMatrix * p;
}
''')
add('v_struct', 'vert', '''struct Light { vec3 pos; vec4 color; float atten[3]; };
uniform Light lights[2];
varying vec4 c;
void main() {
  c = vec4(0.0);
  for (int i = 0; i < 2; i++) c += lights[i].color * lights[i].atten[1];
  gl_Position = ftransform();
}
''')
add('v_func', 'vert', '''float sq(float x) { return x * x; }
vec2 sq(vec2 x) { return x * x; }
vec3 sq(vec3 x) { return x * x; }
varying vec3 v;
void main() { v = sq(gl_Vertex.xyz); float f = sq(gl_Vertex.w); gl_Position = vec4(v * f, 1.0); }
''')
add('v_builtins', 'vert', '''varying vec4 r;
void main() {
  vec4 a = gl_Vertex;
  r = vec4(sin(a.x), cos(a.y), tan(a.z), abs(a.w));
  r += vec4(pow(a.x, 2.0), exp(a.y), log(a.z), sqrt(abs(a.w)));
  r += vec4(floor(a.x), ceil(a.y), fract(a.z), mod(a.w, 3.0));
  r += min(a, vec4(1.0)) + max(a, vec4(0.0)) + clamp(a, 0.0, 1.0) + mix(a, r, 0.5);
  r.x += dot(a, r) + length(a.xyz) + distance(a.xy, r.xy);
  r.xyz += cross(a.xyz, r.xyz) + normalize(a.xyz) + reflect(a.xyz, r.xyz);
  r += step(0.5, a) + smoothstep(0.0, 1.0, a) + sign(a);
  gl_Position = ftransform();
}
''')
add('v_matrix', 'vert', '''uniform mat3 m3; uniform mat2 m2;
varying vec3 o;
void main() {
  mat4 m = gl_ModelViewMatrix * mat4(1.0);
  o = m3 * gl_Vertex.xyz;
  vec2 t = m2 * gl_Vertex.xy;
  m[1] = vec4(t, 0.0, 1.0);
  m[2][3] = 2.0;
  o += (transpose_free(m)).xyz;
  gl_Position = m * gl_Vertex;
}
vec4 transpose_free(mat4 m) { return m[0] + m[1] + m[2] + m[3]; }
''')
add('v_matrix2', 'vert', '''uniform mat3 m3; uniform mat2 m2;
vec4 flat_sum(mat4 m) { return m[0] + m[1] + m[2] + m[3]; }
varying vec3 o;
void main() {
  mat4 m = gl_ModelViewMatrix * mat4(1.0);
  o = m3 * gl_Vertex.xyz;
  vec2 t = m2 * gl_Vertex.xy;
  m[1] = vec4(t, 0.0, 1.0);
  m[2][3] = 2.0;
  o += flat_sum(m).xyz;
  gl_Position = m * gl_Vertex;
}
''')
add('v_loops', 'vert', '''varying float acc;
void main() {
  float a = 0.0;
  for (int i = 0; i < 8; ++i) { if (i == 3) continue; if (i > 6) break; a += float(i); }
  int j = 0;
  while (j < 4) { a *= 2.0; j++; }
  do { a -= 1.0; j--; } while (j > 0);
  acc = a;
  gl_Position = ftransform();
}
''')
add('v_arrays', 'vert', '''uniform float w[8]; uniform vec4 pal[4];
varying vec4 c;
void main() {
  float s = 0.0;
  for (int i = 0; i < 8; i++) s += w[i];
  c = pal[int(s) & 3];
  vec3 loc[3];
  loc[0] = vec3(1.0); loc[1] = vec3(2.0); loc[2] = loc[0] + loc[1];
  c.xyz += loc[2];
  gl_Position = ftransform();
}
''')
add('v_swizzle', 'vert', '''varying vec4 c;
void main() {
  vec4 a = gl_Vertex;
  c = a.wzyx;
  c.xy = a.zw;
  c.rgb = a.abg;
  vec2 b = a.xx;
  c.zw = b.yx;
  gl_Position = ftransform();
}
''')
add('v_ternary', 'vert', '''varying float f;
void main() {
  float x = gl_Vertex.x;
  f = x > 0.0 ? (x < 1.0 ? x : 1.0) : 0.0;
  bool b = x > 2.0 && x < 4.0 || x == 9.0;
  f += b ? 1.0 : 2.0;
  bvec3 bv = lessThan(gl_Vertex.xyz, vec3(0.0));
  if (any(bv)) f += 1.0;
  if (all(not(bv))) f += 2.0;
  gl_Position = ftransform();
}
''')
add('v_ints', 'vert', '''varying float f;
void main() {
  int a = 7; int b = 3;
  int c = a / b + a % b - (a << 1) ;
  ivec2 iv = ivec2(a, b);
  ivec4 i4 = ivec4(iv, iv);
  f = float(c) + float(i4.w) + float(iv.x * iv.y);
  gl_Position = ftransform();
}
''')
add('v_const', 'vert', '''const float PI = 3.14159265;
const vec3 AXIS = vec3(1.0, 0.0, 0.0);
const int N = 4;
varying vec3 v;
void main() {
  float a[N];
  for (int i = 0; i < N; i++) a[i] = PI * float(i);
  v = AXIS * (a[1] + a[3]);
  gl_Position = ftransform();
}
''')
add('v_inout', 'vert', '''void swap(inout float a, inout float b) { float t = a; a = b; b = t; }
void split(in vec2 v, out float x, out float y) { x = v.x; y = v.y; }
varying vec2 o;
void main() {
  float a = 1.0, b = 2.0;
  swap(a, b);
  float x, y;
  split(vec2(a, b), x, y);
  o = vec2(x, y);
  gl_Position = ftransform();
}
''')
add('v_recurse_free', 'vert', '''float f1(float x) { return x + 1.0; }
float f2(float x) { return f1(x) * 2.0; }
float f3(float x) { return f2(f1(x)); }
varying float o;
void main() { o = f3(gl_Vertex.x); gl_Position = ftransform(); }
''')
add('v_pp_define', 'vert', '''#define SCALE 2.0
#define MUL(a, b) ((a) * (b))
#define VEC vec4(1.0, 2.0, 3.0, 4.0)
#ifdef SCALE
#define BOOST 3.0
#else
#define BOOST 1.0
#endif
#if defined(BOOST) && BOOST > 2.0
varying vec4 c;
#endif
void main() { c = MUL(VEC, SCALE) * BOOST; gl_Position = ftransform(); }
''')
add('v_pp_line', 'vert', '''#version 110
#line 100
varying vec4 c;
#pragma optimize(on)
void main() { c = vec4(1.0); gl_Position = ftransform(); }
''')
add('v_pp_ext', 'vert', '''#extension GL_ARB_texture_rectangle : enable
varying vec4 c;
void main() { c = vec4(1.0); gl_Position = ftransform(); }
''')
add('v_pp_ifchain', 'vert', '''#define A 1
#define B 2
#if A == 1
  #if B == 3
    varying float x;
  #elif B == 2
    varying float y;
  #else
    varying float z;
  #endif
#endif
void main() { y = 1.0; gl_Position = ftransform(); }
''')
add('v_pp_undef', 'vert', '''#define T 1
#undef T
#ifndef T
varying float t;
#endif
void main() { t = 0.0; gl_Position = ftransform(); }
''')
add('v_pp_nested_macro', 'vert', '''#define A(x) B(x) + 1.0
#define B(x) C(x, x)
#define C(x, y) ((x) * (y))
varying float o;
void main() { o = A(gl_Vertex.x); gl_Position = ftransform(); }
''')
add('v_pp_comments', 'vert', '''// line comment
/* block
   comment */ varying float o; // trailing
void main() { /* inline */ o = 1.0; // end
  gl_Position = ftransform(); }
''')
add('v_struct2', 'vert', '''struct A { float x; vec3 y; };
struct B { A a; A arr[2]; mat2 m; };
uniform B ub;
varying vec3 o;
void main() {
  B b = ub;
  b.a.x = 2.0;
  b.arr[1].y = vec3(1.0);
  o = b.a.y + b.arr[0].y + b.arr[1].y + vec3(b.m[0], 0.0);
  gl_Position = ftransform();
}
''')
add('v_ctor', 'vert', '''varying vec4 o;
void main() {
  vec4 a = vec4(1.0);
  vec4 b = vec4(vec2(1.0, 2.0), 3.0, 4.0);
  vec4 c = vec4(vec3(1.0), 2.0);
  mat2 m = mat2(1.0, 2.0, 3.0, 4.0);
  mat3 m3 = mat3(m[0], 0.0, m[1], 0.0, 0.0, 0.0, 1.0);
  bvec2 bb = bvec2(true, false);
  o = a + b + c + vec4(m[1], m3[2].xy) + vec4(float(bb.x));
  gl_Position = ftransform();
}
''')
add('v_bigexpr', 'vert', 'varying float f;\nvoid main() {\n  float a = gl_Vertex.x;\n  f = ' + ' + '.join('(a * %d.0)' % i for i in range(1, 60)) + ';\n  gl_Position = ftransform();\n}\n')
add('v_manydecl', 'vert', 'varying float f;\nvoid main() {\n' + ''.join('  float v%d = gl_Vertex.x + %d.0;\n' % (i, i) for i in range(1, 120)) + '  f = ' + ' + '.join('v%d' % i for i in range(1, 120)) + ';\n  gl_Position = ftransform();\n}\n')
add('v_manyfuncs', 'vert', ''.join('float fn%d(float x) { return x + %d.0; }\n' % (i, i) for i in range(1, 80)) + 'varying float f;\nvoid main() { f = ' + ' + '.join('fn%d(gl_Vertex.x)' % i for i in range(1, 80)) + '; gl_Position = ftransform(); }\n')
add('v_manyvarying', 'vert', ''.join('varying vec4 t%d;\n' % i for i in range(8)) + 'void main() {\n' + ''.join('  t%d = gl_Vertex * %d.0;\n' % (i, i + 1) for i in range(8)) + '  gl_Position = ftransform();\n}\n')
add('v_manyuniforms', 'vert', ''.join('uniform vec4 u%d;\n' % i for i in range(40)) + 'varying vec4 c;\nvoid main() { c = ' + ' + '.join('u%d' % i for i in range(40)) + '; gl_Position = ftransform(); }\n')
add('v_deepnest', 'vert', 'varying float f;\nvoid main() {\n  float a = gl_Vertex.x; f = 0.0;\n' + '  if (a > 0.0) {\n' * 20 + '  f = 1.0;\n' + '  }\n' * 20 + '  gl_Position = ftransform();\n}\n')
add('v_longident', 'vert', 'varying float ' + 'a' * 300 + ';\nvoid main() { ' + 'a' * 300 + ' = 1.0; gl_Position = ftransform(); }\n')
add('v_mat_ops', 'vert', '''uniform mat4 a, b; uniform vec4 v;
varying vec4 o;
void main() {
  mat4 c = a * b;
  c = c + a - b;
  c *= 2.0;
  o = c * v + v * c;
  o += (a * v).wzyx;
  gl_Position = c * gl_Vertex;
}
''')
add('v_builtin_vars', 'vert', '''varying vec4 c;
void main() {
  c = gl_Color + gl_SecondaryColor + vec4(gl_Normal, gl_FogCoord);
  gl_FrontColor = c;
  gl_BackColor = c;
  gl_FrontSecondaryColor = c;
  gl_TexCoord[0] = gl_MultiTexCoord0;
  gl_TexCoord[1] = gl_TextureMatrix[1] * gl_MultiTexCoord1;
  gl_FogFragCoord = gl_FogCoord;
  gl_PointSize = 4.0;
  gl_ClipVertex = gl_ModelViewMatrix * gl_Vertex;
  gl_Position = ftransform();
}
''')
add('v_light_params', 'vert', '''varying vec4 c;
void main() {
  c = gl_LightSource[0].diffuse * gl_FrontMaterial.diffuse + gl_LightModel.ambient + gl_LightSource[1].position + vec4(gl_Fog.density) + gl_EyePlaneS[0];
  gl_Position = ftransform();
}
''')
add('v_noise', 'vert', '''varying vec4 c;
void main() { c = vec4(noise1(gl_Vertex.x), noise2(gl_Vertex.xy), noise3(gl_Vertex.xyz).x, noise4(gl_Vertex).w); gl_Position = ftransform(); }
''')
add('v_vec_cmp', 'vert', '''varying vec4 c;
void main() {
  vec4 a = gl_Vertex; vec4 b = gl_Color;
  bvec4 e = equal(a, b), ne = notEqual(a, b), lt = lessThan(a, b), le = lessThanEqual(a, b), gt = greaterThan(a, b), ge = greaterThanEqual(a, b);
  c = vec4(float(any(e)), float(all(ne)), float(any(lt) || any(le)), float(any(gt) && any(ge)));
  if (a == b) c.x = 1.0;
  gl_Position = ftransform();
}
''')

# ---- valid fragment shaders -----------------------------------------------------------------------------------------------
add('f_min', 'frag', 'void main() { gl_FragColor = vec4(1.0); }\n')
add('f_tex', 'frag', 'uniform sampler2D t; varying vec2 uv;\nvoid main() { gl_FragColor = texture2D(t, uv) * gl_Color; }\n')
add('f_texall', 'frag', '''uniform sampler1D t1; uniform sampler2D t2; uniform sampler3D t3; uniform samplerCube tc; uniform sampler2DShadow ts;
varying vec4 c;
void main() {
  vec4 r = texture1D(t1, c.x) + texture2D(t2, c.xy) + texture3D(t3, c.xyz) + textureCube(tc, c.xyz);
  r += shadow2D(ts, c.xyz);
  r += texture2DProj(t2, c) + texture2DLod(t2, c.xy, 1.0);
  gl_FragColor = r;
}
''')
add('f_discard', 'frag', 'varying vec4 c;\nvoid main() { if (c.a < 0.5) discard; gl_FragColor = c; }\n')
add('f_derivs', 'frag', 'varying vec2 uv;\nvoid main() { gl_FragColor = vec4(dFdx(uv.x), dFdy(uv.y), fwidth(uv.x), 1.0); }\n')
add('f_fragdata', 'frag', 'varying vec4 c;\nvoid main() { gl_FragData[0] = c; gl_FragData[1] = c * 0.5; gl_FragDepth = c.z; }\n')
add('f_frontfacing', 'frag', 'varying vec4 c;\nvoid main() { gl_FragColor = gl_FrontFacing ? c : c.bgra; }\n')
add('f_fragcoord', 'frag', 'void main() { gl_FragColor = vec4(gl_FragCoord.xy / 100.0, gl_FragCoord.z, gl_FragCoord.w); }\n')
add('f_pointcoord', 'frag', 'void main() { gl_FragColor = vec4(gl_PointCoord, 0.0, 1.0); }\n')
add('f_lighting', 'frag', '''varying vec3 n; varying vec3 l;
uniform vec4 diffuse;
void main() {
  float d = max(dot(normalize(n), normalize(l)), 0.0);
  vec3 h = normalize(l + vec3(0.0, 0.0, 1.0));
  float s = pow(max(dot(normalize(n), h), 0.0), 32.0);
  gl_FragColor = diffuse * d + vec4(s);
}
''')
add('f_loop', 'frag', '''varying vec2 uv; uniform sampler2D t;
void main() {
  vec4 a = vec4(0.0);
  for (int i = -2; i <= 2; i++) for (int j = -2; j <= 2; j++) a += texture2D(t, uv + vec2(float(i), float(j)) * 0.01);
  gl_FragColor = a / 25.0;
}
''')
add('f_struct', 'frag', '''struct Mat { vec4 amb; vec4 dif; float sh; };
uniform Mat m;
varying vec3 n;
Mat mix2(Mat a, Mat b, float t) { Mat r; r.amb = mix(a.amb, b.amb, t); r.dif = mix(a.dif, b.dif, t); r.sh = mix(a.sh, b.sh, t); return r; }
void main() { Mat z = mix2(m, m, 0.5); gl_FragColor = z.amb + z.dif * z.sh * dot(n, n); }
''')
add('f_precision_free', 'frag', 'varying float x;\nvoid main() { float y = x * x * x * x * x; gl_FragColor = vec4(y, exp2(x), log2(abs(x)), inversesqrt(abs(x) + 1.0)); }\n')
add('f_bigbody', 'frag', 'varying vec4 c;\nvoid main() {\n  vec4 a = c;\n' + ''.join('  a = a * 0.99 + vec4(%d.0) * 0.001;\n' % i for i in range(200)) + '  gl_FragColor = a;\n}\n')
add('f_many_if', 'frag', 'varying float x;\nvoid main() {\n  float r = 0.0;\n' + ''.join('  if (x > %d.0) r += %d.0; else r -= 1.0;\n' % (i, i) for i in range(60)) + '  gl_FragColor = vec4(r);\n}\n')
add('f_func_out', 'frag', '''void f(out vec4 o, in float a, inout float b) { o = vec4(a + b); b += 1.0; }
varying float x;
void main() { vec4 o; float b = x; f(o, x, b); gl_FragColor = o + vec4(b); }
''')
add('f_bool', 'frag', '''varying vec4 c;
void main() {
  bool a = c.x > 0.5, b = c.y > 0.5;
  bool x = a && b, y = a || b, z = a ^^ b, w = !a;
  gl_FragColor = vec4(float(x), float(y), float(z), float(w));
}
''')
add('f_matrix_frag', 'frag', '''uniform mat3 m; varying vec3 v;
void main() { vec3 r = m * v; r = v * m; mat3 t = m * m; gl_FragColor = vec4(r + t[0], 1.0); }
''')
add('f_compat', 'frag', '''uniform sampler2D s0, s1, s2, s3;
varying vec2 uv;
void main() { gl_FragColor = texture2D(s0, uv) + texture2D(s1, uv) * texture2D(s2, uv) - texture2D(s3, uv); }
''')

# ---- shaders that must fail (error paths, exceptions, info log formatting) ---------------------------------------------------------
E = {}
def err(name, lang, src): add('e_' + name, lang, src)
err('syntax1', 'vert', 'void main() { gl_Position = ; }\n')
err('syntax2', 'vert', 'void main( { gl_Position = ftransform(); }\n')
err('syntax3', 'vert', 'void main() { gl_Position = ftransform() }\n')
err('syntax4', 'vert', 'void main() { if (true { } }\n')
err('undeclared', 'vert', 'void main() { gl_Position = foo; }\n')
err('undeclared_fn', 'vert', 'void main() { gl_Position = bar(1.0); }\n')
err('type_mismatch', 'vert', 'void main() { float f = vec4(1.0); gl_Position = ftransform(); }\n')
err('type_mismatch2', 'vert', 'void main() { vec3 v = vec4(1.0); gl_Position = ftransform(); }\n')
err('bad_ctor', 'vert', 'void main() { vec4 v = vec4(1.0, 2.0); gl_Position = v; }\n')
err('bad_ctor2', 'vert', 'void main() { mat2 m = mat2(1.0, 2.0, 3.0); gl_Position = ftransform(); }\n')
err('wrong_args', 'vert', 'float f(float a, float b) { return a + b; }\nvoid main() { gl_Position = vec4(f(1.0)); }\n')
err('redef_var', 'vert', 'void main() { float a; float a; gl_Position = ftransform(); }\n')
err('redef_fn', 'vert', 'void f() {}\nvoid f() {}\nvoid main() { gl_Position = ftransform(); }\n')
err('no_main', 'vert', 'float f(float a) { return a; }\n')
err('no_main_frag', 'frag', 'varying float f;\n')
err('empty', 'vert', '')
err('only_ws', 'frag', '   \n\n\t\n')
err('write_const', 'vert', 'const float c = 1.0;\nvoid main() { c = 2.0; gl_Position = ftransform(); }\n')
err('write_uniform', 'vert', 'uniform float u;\nvoid main() { u = 2.0; gl_Position = ftransform(); }\n')
err('write_attr', 'vert', 'attribute float a;\nvoid main() { a = 2.0; gl_Position = ftransform(); }\n')
err('write_varying_frag', 'frag', 'varying float v;\nvoid main() { v = 1.0; gl_FragColor = vec4(v); }\n')
err('bad_swizzle', 'vert', 'void main() { vec2 v = vec2(1.0); gl_Position = vec4(v.xyz, 1.0); }\n')
err('bad_swizzle2', 'vert', 'void main() { vec4 v = vec4(1.0); gl_Position = v.xr; }\n')
err('bad_index', 'vert', 'void main() { float a[3]; a[5] = 1.0; gl_Position = ftransform(); }\n')
err('neg_index', 'vert', 'uniform float u[2];\nvoid main() { gl_Position = vec4(u[-1]); }\n')
err('div_zero_const', 'vert', 'void main() { int a = 1 / 0; gl_Position = ftransform(); }\n')
err('bad_return', 'vert', 'float f() { return vec2(1.0); }\nvoid main() { gl_Position = ftransform(); }\n')
err('missing_return', 'vert', 'float f() { }\nvoid main() { gl_Position = ftransform(); }\n')
err('return_in_void', 'vert', 'void f() { return 1.0; }\nvoid main() { gl_Position = ftransform(); }\n')
err('break_outside', 'vert', 'void main() { break; gl_Position = ftransform(); }\n')
err('continue_outside', 'vert', 'void main() { continue; gl_Position = ftransform(); }\n')
err('discard_vert', 'vert', 'void main() { discard; }\n')
err('recursion', 'vert', 'float f(float x) { return f(x); }\nvoid main() { gl_Position = vec4(f(1.0)); }\n')
err('bad_cond', 'vert', 'void main() { if (1.0) { } gl_Position = ftransform(); }\n')
err('bad_ternary', 'vert', 'void main() { float a = true ? 1.0 : vec2(1.0); gl_Position = ftransform(); }\n')
err('bad_op', 'vert', 'void main() { vec3 a; vec4 b; vec4 c = a + b; gl_Position = c; }\n')
err('bad_op2', 'vert', 'void main() { bool a; float c = a * 2.0; gl_Position = vec4(c); }\n')
err('bad_mat', 'vert', 'void main() { mat3 a; mat4 b; mat4 c = a * b; gl_Position = c[0]; }\n')
err('int_float', 'vert', 'void main() { int i = 1.0; gl_Position = ftransform(); }\n')
err('struct_undef', 'vert', 'void main() { Foo f; gl_Position = ftransform(); }\n')
err('struct_field', 'vert', 'struct S { float a; };\nvoid main() { S s; s.b = 1.0; gl_Position = ftransform(); }\n')
err('unterminated_comment', 'vert', 'void main() { /* oops \n gl_Position = ftransform(); }\n')
err('bad_char', 'vert', 'void main() { gl_Position = ftransform(); } @ \n')
err('bad_number', 'vert', 'void main() { float a = 1.2.3; gl_Position = ftransform(); }\n')
err('bad_hex', 'vert', 'void main() { int a = 0xZZ; gl_Position = ftransform(); }\n')
err('big_int', 'vert', 'void main() { int a = 99999999999999999999; gl_Position = ftransform(); }\n')
err('pp_error', 'vert', '#error stop here\nvoid main() { gl_Position = ftransform(); }\n')
err('pp_unterminated_if', 'vert', '#if 1\nvoid main() { gl_Position = ftransform(); }\n')
err('pp_endif_alone', 'vert', '#endif\nvoid main() { gl_Position = ftransform(); }\n')
err('pp_else_alone', 'vert', '#else\nvoid main() { gl_Position = ftransform(); }\n')
err('pp_bad_directive', 'vert', '#frobnicate\nvoid main() { gl_Position = ftransform(); }\n')
err('pp_macro_args', 'vert', '#define F(a, b) a + b\nvoid main() { float x = F(1.0); gl_Position = vec4(x); }\n')
err('pp_macro_unterminated', 'vert', '#define F(a) a\nvoid main() { float x = F(1.0; gl_Position = vec4(x); }\n')
err('pp_redefine', 'vert', '#define A 1\n#define A 2\nvoid main() { gl_Position = vec4(A); }\n')
err('pp_bad_version', 'vert', '#version 9999\nvoid main() { gl_Position = ftransform(); }\n')
err('pp_bad_extension', 'vert', '#extension GL_NOPE_nope : require\nvoid main() { gl_Position = ftransform(); }\n')
err('pp_recursive_macro', 'vert', '#define A A + 1\nvoid main() { gl_Position = vec4(A); }\n')
err('pp_div_zero', 'vert', '#if 1 / 0\n#endif\nvoid main() { gl_Position = ftransform(); }\n')
err('pp_bad_expr', 'vert', '#if (1 +\n#endif\nvoid main() { gl_Position = ftransform(); }\n')
err('pp_line_bad', 'vert', '#line abc\nvoid main() { gl_Position = ftransform(); }\n')
err('deep_parens', 'vert', 'void main() { float a = ' + '(' * 200 + '1.0' + ')' * 200 + '; gl_Position = vec4(a); }\n')
err('unbalanced', 'vert', 'void main() { { { gl_Position = ftransform(); }\n')
err('many_errors', 'vert', 'void main() {\n' + ''.join('  undefined_%d = %d;\n' % (i, i) for i in range(60)) + '}\n')
err('varying_vert_int', 'vert', 'varying int v;\nvoid main() { gl_Position = ftransform(); }\n')
err('uniform_init', 'vert', 'uniform float u = 1.0;\nvoid main() { gl_Position = ftransform(); }\n')
err('attr_frag', 'frag', 'attribute float a;\nvoid main() { gl_FragColor = vec4(a); }\n')
err('sampler_local', 'frag', 'void main() { sampler2D s; gl_FragColor = vec4(1.0); }\n')
err('sampler_assign', 'frag', 'uniform sampler2D a, b;\nvoid main() { a = b; gl_FragColor = vec4(1.0); }\n')
err('builtin_redecl', 'vert', 'float sin(float x) { return x; }\nvoid main() { gl_Position = ftransform(); }\n')
err('bad_const_init', 'vert', 'uniform float u;\nconst float c = u;\nvoid main() { gl_Position = vec4(c); }\n')
err('unsized_array', 'vert', 'void main() { float a[]; gl_Position = ftransform(); }\n')
err('array_size_neg', 'vert', 'void main() { float a[-1]; gl_Position = ftransform(); }\n')
err('array_size_var', 'vert', 'uniform int n;\nvoid main() { float a[n]; gl_Position = ftransform(); }\n')
err('void_var', 'vert', 'void main() { void v; gl_Position = ftransform(); }\n')
err('func_in_func', 'vert', 'void main() { void g() {} gl_Position = ftransform(); }\n')
err('main_args', 'vert', 'void main(float x) { gl_Position = ftransform(); }\n')
err('main_ret', 'vert', 'float main() { return 1.0; }\n')
err('bad_lvalue', 'vert', 'void main() { 1.0 = 2.0; gl_Position = ftransform(); }\n')
err('bad_lvalue2', 'vert', 'void main() { vec4 a; vec4 b; (a + b) = a; gl_Position = ftransform(); }\n')
err('dup_swizzle_write', 'vert', 'void main() { vec4 a; a.xx = vec2(1.0); gl_Position = a; }\n')
err('gl_write_frag', 'frag', 'void main() { gl_Position = vec4(1.0); }\n')
err('inout_const', 'vert', 'void f(inout float a) { a = 1.0; }\nvoid main() { f(1.0); gl_Position = ftransform(); }\n')
err('out_swizzle_dup', 'vert', 'void f(out vec2 a) { a = vec2(1.0); }\nvoid main() { vec4 v; f(v.xx); gl_Position = v; }\n')
err('huge_shader_error_late', 'vert', ''.join('float g%d;\n' % i for i in range(150)) + 'void main() { gl_Position = nosuch; }\n')

for k, v in S.items():
    open(os.path.join(out, k), 'w').write(v)
print(len(S), 'shaders')

