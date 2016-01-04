#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

//Glew
#define GLEW_STATIC
#include <GL/glew.h>

#include "Texture.h"

#include <string>
#include <map>

class TextureCache
{
public:
	void setupTexture(const GLchar* path, const std::string textureName);
	Texture getTexture(const std::string textureName);
private:
	std::map<std::string, Texture> _textures;
	
};
#endif

