#version 430 core

out vec4 fragColor;

in vec2 texCoord;
in vec3 fragPos;
in vec3 normal;

uniform vec3 lightPosition;
uniform vec3 lightColor;

uniform sampler2D texture1; 

void main()
{
	
	vec3 color = texture(texture1, texCoord).rgb;
	//Ambient
	float ambientStrenght = 0.01;
	vec3 ambient = ambientStrenght * color;

	//Diffuse
	vec3 norm = normalize(normal);
	norm = norm * -1;
	vec3 lightDirection = normalize(lightPosition - fragPos);
	float diff = max(dot(norm, lightDirection), 0.0);
	vec3 diffuse = diff * color * 0.3;
 
	vec3 lighting = (ambient + diffuse);
	fragColor = vec4(lighting, 1.0f);
	
}