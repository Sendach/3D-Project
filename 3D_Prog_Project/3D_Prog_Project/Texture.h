#ifndef TEXTURE_H
#define TEXTURE_H

#define GLEW_STATIC
#include <GL\glew.h>

//Soil
#include <SOIL\SOIL.h>

class Texture
{
public:
	Texture() {};
	GLuint TextureID;
	Texture loadTexture(const GLchar* path);
	void bindTexture();
	//This one is for depth buffers.
	void bindTextureV2(const GLuint& textureID);
};
#endif

