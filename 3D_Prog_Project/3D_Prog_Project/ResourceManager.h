#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "TextureCache.h"
#include "ShaderCache.h"
#include "ModelCache.h"
#include "FBOCache.h"
#include "Texture.h"
//Other Includes
#include <string>
#include <map>

class ResourceManager
{
public:
	ResourceManager(){ };
	//Shaders
	Shader getShader(std::string shaderName);
	//Textures
	Texture getTexture(std::string textuerName);
	//Models
	Model& getModel(std::string modelName);
	//FBO
	FrameBufferObject& getFBO(std::string FBOName);

	Texture textureObject;
	TextureCache _textureCache;
	ShaderCache _shaderCache;
	ModelCache _modelCache;
	FBOCache _FBOCache;
};
#endif