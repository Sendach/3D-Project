#version 430 core

in vec2 texCoord;
out vec4 color;

uniform sampler2D texture1; 
void main()
{
	vec4 texColor = texture(texture1, vec2(texCoord.x, 1- texCoord.y));
	color = texColor;
	//color = vec4(0.0, 0.0, 1.0, 1.0);
}