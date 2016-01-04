#version 430 core

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec3 vertex_normal;
layout (location = 2) in vec2 vertex_texCoord;

out VS_OUT {
	vec3 fragPos;
	vec3 normal;
	vec2 texCoords;
	vec4 fragPosLightSpace;
} vs_out;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform mat4 lightSpaceMatrix;

void main()
{
	gl_Position = projection * view * model * vec4(vertex_position, 1.0);
	vs_out.fragPos = vec3(model * vec4(vertex_position, 1.0));
	vs_out.normal = transpose(inverse(mat3(model))) * vertex_normal;
	vs_out.texCoords = vertex_texCoord;
	vs_out.fragPosLightSpace = lightSpaceMatrix * vec4(vs_out.fragPos, 1.0);
}