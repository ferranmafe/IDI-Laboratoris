#version 330 core

in vec3 fg_color;
out vec4 FragColor;

void main() {
    FragColor = vec4(fg_color, 1.0);
}

