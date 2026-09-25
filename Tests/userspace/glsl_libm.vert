// Constant math the GLSL front end folds at compile time with libm (sin, cos, pow, sqrt, floor, exp2, log2, ...): the ARB program carries the
// folded values, so stock and rebuilt outputs must agree digit for digit (Tests/userspace/glsl_probe.c IMAGE 1 0 3 glsl_libm.vert).
void main() {
    vec4 a = vec4(sin(0.5), cos(0.25), pow(2.0, 0.5), sqrt(3.0));
    vec4 b = vec4(floor(2.7), ceil(-1.2), exp2(1.5), log2(10.0));
    vec4 c = vec4(exp(1.0), log(2.0), tan(0.3), atan(1.0));
    vec4 d = vec4(asin(0.5), acos(0.5), fract(3.25), inversesqrt(4.0));
    gl_Position = ftransform() * a + b * c + d;
}
