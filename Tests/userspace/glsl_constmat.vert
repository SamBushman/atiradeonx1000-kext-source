// Constant matrix folding and indexing (TParseContext::addConstMatrixNode / addConstVectorNode, TIntermConstantUnion::fold on matrices):
// glsl_probe IMAGE 1 0 3 glsl_constmat.vert. The rebuilt parser typed `m[1]` of a const mat2 as `const float` (yyparse's pair-result misread)
const mat2 a = mat2(1.0, 2.0, 3.0, 4.0) * mat2(2.0);
const mat3 b = mat3(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
const vec3 r = b * vec3(1.0, 0.5, 0.25);
const vec3 v = vec3(1.0, 2.0, 3.0);
const float d = v.z + v[1];
void main() {
    vec2 c = a[1];
    gl_Position = ftransform() + vec4(a[0], c) + vec4(r, b[2].y) + vec4(v.zyx, d);
}
