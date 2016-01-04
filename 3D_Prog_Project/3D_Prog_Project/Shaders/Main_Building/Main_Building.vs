#version 430 core

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec3 vertex_normal;
layout (location = 2) in vec2 vertex_texCoord;


out vec2 texCoord;
out vec3 normal;
out vec3 fragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(vertex_position, 1.0f);
	fragPos = vec3(model * vec4(vertex_position, 1.0f));
	normal = mat3(transpose(inverse(model))) * vertex_normal;
	texCoord = vertex_texCoord;
}