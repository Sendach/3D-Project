#version 430 core
layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedoSpec;

out vec4 fragColor;
in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

//uniform sampler2D texture_diffuse1;
//uniform sampler2D texture_specular1;

void main()
{    
    // Store the fragment position vector in the first gbuffer texture
    gPosition = FragPos;
    // Also store the per-fragment normals into the gbuffer
    gNormal = normalize(Normal);
    // And the diffuse per-fragment color
    gAlbedoSpec.rgb = vec3(0.5f, 0.5f, 0.5f); //texture(texture_diffuse1, TexCoords).rgb;
    // Store specular intensity in gAlbedoSpec's alpha component
    gAlbedoSpec.a = 0.5f; //texture(texture_specular1, TexCoords).r;

    fragColor = vec4(gPosition, 1.0f);
}