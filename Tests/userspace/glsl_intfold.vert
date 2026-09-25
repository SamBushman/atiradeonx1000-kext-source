// Integer / bool constant folding in the GLSL front end (TIntermConstantUnion::fold): the folded values reach the ARB program as PARAMs, so stock
// and rebuilt must agree (glsl_probe IMAGE 1 0 3 glsl_intfold.vert).
void main() {
    const int a = 7 - 3;
    const int b = -5;
    const int c = 17 / 4;
    const int d = 6 * 7;
    const bool e = !(a > 2);
    gl_Position = ftransform() + vec4(float(a), float(b), float(c), float(d)) + vec4(e ? 1.0 : 2.0);
}
