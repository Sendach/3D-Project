#include "ResourceManager.h"
#include <iostream>


Model& ResourceManager::getModel(std::string modelName)
{
	return  this->_modelCache.getModel(modelName);
}
FrameBufferObject& ResourceManager::getFBO(std::string FBOName)
{
	return this->_FBOCache.getFBO(FBOName);
}

Shader ResourceManager::getShader(std::string shaderName)
{
	return this->_shaderCache.getShader(shaderName);
}

Texture ResourceManager::getTexture(std::string textuerName)
{
	return this->_textureCache.getTexture(textuerName);
	
}