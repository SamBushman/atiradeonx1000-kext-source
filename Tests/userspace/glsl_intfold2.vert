// Vector integer / bool constant folding (TIntermConstantUnion::fold over components): glsl_probe IMAGE 1 0 3 glsl_intfold2.vert
void main() {
    const ivec4 v = ivec4(7, 5, 17, 6) - ivec4(3, 1, 4, 2);
    const ivec4 w = ivec4(7, 5, 17, 6) / ivec4(3, 2, 4, 2);
    const ivec4 n = -ivec4(1, 2, 3, 4);
    const ivec2 m = ivec2(3, 4) * ivec2(5, 6);
    gl_Position = ftransform() + vec4(v) + vec4(w) + vec4(n) + vec4(m, m);
}
