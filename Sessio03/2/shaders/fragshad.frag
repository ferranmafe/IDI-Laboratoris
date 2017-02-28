#version 330 core

out vec4 FragColor;

void main() {
    if (((int(gl_FragCoord.y) / 10) % 2) == 0)  FragColor = vec4(0, 0, 0, 1);
    else discard;
}

