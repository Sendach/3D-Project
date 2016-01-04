#version 430 core

out vec4 fragColor;

in VS_OUT {
	vec3 fragPos;
	vec3 normal;
	vec2 texCoords;
	vec4 fragPosLightSpace;
} fs_in;


uniform sampler2D diffuseTexture;
uniform sampler2D shadowMap;

uniform bool normalChange;

uniform vec3 lightPos;
uniform vec3 viewPos;

float ShadowCalculation(vec4 fragPosLightSpace)
{
 	vec3 lightDir = normalize(lightPos - fs_in.fragPos);
 	vec3 normal = normalize(fs_in.normal);
 	if(normalChange){	normal = normal * -1; }
 	
	//perform perspective divide
	vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
	// Transform to [0,1] range
	projCoords = projCoords * 0.5 + 0.5;
	float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);  
	// Get cloests depth value from light's perspective
	float closestDepth = texture(shadowMap, projCoords.xy).r;
	// Get depth of current fragment from light's perspective
	float currentDepth = projCoords.z;

	float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;  

	return shadow;

}
void main()
{
	vec3 textureColor = texture(diffuseTexture, fs_in.texCoords).rgb;
	vec3 normal = normalize(fs_in.normal);

	if(normalChange){	normal = normal * -1; }
	
	// Ambient
	float ambientStrenght = 0.3;
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
	spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
	vec3 specular = spec * textureColor;

	// Calculate Shadow
	float shadow = ShadowCalculation(fs_in.fragPosLightSpace);
	vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular));
	fragColor = vec4(lighting, 1.0);
}