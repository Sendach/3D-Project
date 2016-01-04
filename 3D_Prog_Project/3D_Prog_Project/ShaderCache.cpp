#include "ShaderCache.h"

void ShaderCache::setupShader(const GLchar* vertexPath, const GLchar* geometryPath, const GLchar* fragmentPath, std::string shaderName)
{	
	auto shaderIterator = _shaders.find(shaderName);

	if (shaderIterator == _shaders.end())
	{
		Shader shader;
		shader.setupShader(vertexPath, geometryPath, fragmentPath);

		_shaders.insert(make_pair(shaderName, shader));
	}
}

Shader ShaderCache::getShader(const std::string shaderName)
{
	return this->_shaders[shaderName];
}