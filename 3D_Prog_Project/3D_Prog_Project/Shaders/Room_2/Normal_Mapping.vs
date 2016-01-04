#version 430 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;
layout (location = 3) in vec3 tangent;
layout (location = 4) in vec3 bitangent;


out VS_OUT {
	vec2 texCoords;
	vec3 tangentLightPosition;
    vec3 tangentViewPosition;
    vec3 tangentFragPosition;
} vs_out;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{

	gl_Position = projection * view * model * vec4(position, 1.0f);

	vs_out.texCoords = texCoords;
	vec3 fraggy = vec3(model * vec4(position, 1.0));
	vec3 T = normalize(vec3(model * vec4(tangent, 0.0)));
	vec3 B = normalize(vec3(model * vec4(bitangent, 0.0)));
    vec3 N = normalize(vec3(model * vec4(normal, 0.0)));

    mat3 TBN = transpose(mat3(T,B,N));
    vs_out.tangentLightPosition = TBN * lightPos;
    vs_out.tangentViewPosition = TBN * viewPos;
    vs_out.tangentFragPosition = TBN * fraggy;	
}
