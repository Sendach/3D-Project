#version 430 core

out vec4 fragColor;

in vec2 texCoords;
in vec3 normal;

uniform sampler2D texture1; 

void main()
{
	
	fragColor = texture(texture1, texCoords);
	
}