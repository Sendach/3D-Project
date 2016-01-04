#version 430 core

out vec4 color;

in VS_OUT {
	vec2 texCoords;
	vec3 normal;
	vec3 fragPos;
} fs_in;

uniform sampler2D objectTexture;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{

	vec3 textureColor = texture(objectTexture, fs_in.texCoords).rgb;
	vec3 normal = normalize(fs_in.normal);
	normal = normal * -1;
	
	// Ambient
	float ambientStrenght = 0.1;
	vec3 ambient = ambientStrenght * textureColor;

	// Diffuse
	vec3 lightDir = normalize(lightPos - fs_in.fragPos);
	float diff = max(dot(lightDir, normal), 0.0);
	vec3 diffuse = diff * textureColor;

	// Specular
	vec3 viewDir = normalize(viewPos - fs_in.fragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = 0.0;
	vec3 halfwayDir = normalize(lightDir + viewDir);
	spec = pow(max(dot(normal, halfwayDir), 0.0), 256.0);
	vec3 specular = spec * textureColor;

	vec3 lighting = (ambient+ diffuse + specular);
	color = vec4(lighting, 1.0f);
}