#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

out vec3 vertex;
out vec3 normal;

out vec3 matamb;
out vec3 matdiff;
out vec3 matspec;
out float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;
uniform vec3 posFocus;
uniform vec3 colFocus;

out vec3 fcolor;

void main()
{
    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}
