#version 430 core

out vec4 color;

in vec2 texCoords;

uniform sampler2D objectTexture;

void main()
{
	vec3 textureColor = texture(objectTexture, texCoords).rgb;
	color =  vec4(textureColor, 1.0f);
}