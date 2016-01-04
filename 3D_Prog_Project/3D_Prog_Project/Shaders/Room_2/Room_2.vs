#version 430 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;
layout (location = 3) in vec3 tangent;
layout (location = 4) in vec3 bitangent;


out VS_OUT {
	vec2 texCoords;
	vec3 normal;
	vec3 fragPos;
} vs_out;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

void main()
{

	gl_Position = projection * view * model * vec4(position, 1.0f);
	vs_out.texCoords = texCoords;
	vs_out.normal = transpose(inverse(mat3(model))) * normal;
	vs_out.fragPos = vec3(model * vec4(position, 1.0));
}
