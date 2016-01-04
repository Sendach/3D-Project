#version 430 core

out vec4 fragColor;

in VS_OUT {
    vec2 texCoords;
    vec3 tangentLightPosition;
    vec3 tangentViewPosition;
    vec3 tangentFragPosition;
} fs_in;

uniform sampler2D objectTexture;
uniform sampler2D normalMap;  

void main()
{           
    // Obtain normal from normal map in range [0,1]
    vec3 normal = texture(normalMap, fs_in.texCoords).rgb;
   
    // Transform normal vector to range [-1,1]
    normal = normalize(normal * 2.0 - 1.0);   
    //normal = normal * -1;
    // Get diffuse color
    vec3 textureColor = texture(objectTexture, fs_in.texCoords).rgb;
    // Ambient
    float ambientStrenght = 0.1;
    vec3 ambient = ambientStrenght * textureColor;
    // Diffuse
    vec3 lightDir = normalize(fs_in.tangentLightPosition - fs_in.tangentFragPosition);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * textureColor;
    // Specular
    vec3 viewDir = normalize(fs_in.tangentViewPosition - fs_in.tangentFragPosition);
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 256.0);
    vec3 specular = textureColor * spec;
    
   vec3 lighting = vec3(ambient + diffuse + specular) ;
   fragColor = vec4(lighting, 1.0f);
}