#version 430 core

out vec4 color;

in VS_OUT {
    vec2 texCoords;
 
} fs_In;

uniform sampler2D objectTexture;

void main()
{
	vec3 textureColor = texture(objectTexture, fs_In.texCoords).rgb;
	color =  vec4(textureColor, 1.0f);
}