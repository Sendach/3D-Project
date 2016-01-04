#version 430 core

layout(triangles) in;
layout (triangle_strip, max_vertices=3) out;
 

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 cameraFront;

in VS_OUT {
    vec2 texCoords;
} gs_In[];
 
out VS_OUT {
    vec2 texCoords;
} gs_Out;
 
 void main()
{

  vec3 p0 = gl_in[0].gl_Position.xyz;
  vec3 p1 = gl_in[1].gl_Position.xyz;
  vec3 p2 = gl_in[2].gl_Position.xyz;
  
  vec3 v0 = p1 - p0;
  vec3 v1 = p2 - p0;
  vec3 N = normalize(cross(v0,v1));
  vec3 normal = transpose(inverse(mat3(model))) * N;
  
  float cull = dot(normal,cameraFront);

  for(int i = 0; i < gl_in.length(); i++)
  {
   if(cull > 0)
    {
     // copy attributes
    gl_Position = projection * view * model * gl_in[i].gl_Position;
    gs_Out.texCoords = gs_In[i].texCoords;
  
    // done with the vertex
   
        EmitVertex();
    }
  }
    EndPrimitive();
}