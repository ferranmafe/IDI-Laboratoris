#version 330 core

in vec3 vertex;
in vec3 color;

out vec3 fg_color;

void main()  {
    gl_Position = vec4 (vertex, 1.0);
    fg_color = color;
}
