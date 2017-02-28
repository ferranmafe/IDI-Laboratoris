#version 330 core

out vec4 FragColor;

vec4 blanc = vec4(1.0, 1.0, 1.0, 1.0);
vec4 blau = vec4(0.0, 0.0, 1.0, 1.0);
vec4 roig = vec4(1.0, 0.0, 0.0, 1.0);
vec4 verd = vec4(0.0, 1.0, 0.0, 1.0);

void main() {
    if (gl_FragCoord.x < 400. && gl_FragCoord.y < 300.) FragColor = blanc;
    else if (gl_FragCoord.x > 400. && gl_FragCoord.y < 300.) FragColor = blau;
    else if (gl_FragCoord.x < 400. && gl_FragCoord.y > 300.) FragColor = roig;
    else FragColor = verd;
}

