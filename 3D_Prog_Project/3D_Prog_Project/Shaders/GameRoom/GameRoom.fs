#version 430 core

out vec4 color;

in VS_OUT {
	vec3 normal;
	vec3 fragPos;
	vec2 texCoords;
} fs_in;

uniform sampler2D objectTexture;
uniform vec3 lightPos;
void main()
{
	vec3 textureColor = texture(objectTexture, fs_in.texCoords).rgb;
		
	vec3 normal = normalize(fs_in.normal);
	normal = normal * -1;
	
	// Ambient
	float ambientStrenght = 0.2;
	vec3 ambient = ambientStrenght * textureColor;
	
	// Diffuse
	vec3 lightDir = normalize(lightPos - fs_in.fragPos);
	float diff = max(dot(lightDir, normal),0.0);
	vec3 diffuse = diff * textureColor;
	
	vec3 lighting = (ambient + diffuse);
	color = vec4(textureColor, 1.0);
}