#ifndef SHADERCACHE_H
#define SHADERCACHE_H

//Glew
#define GLEW_STATIC
#include <GL/glew.h>

#include "Shader.h"

#include <string>
#include <map>
class ShaderCache
{
public:
	void setupShader(const GLchar* vertexPath, const GLchar* geometryPath, const GLchar* fragmentPath, std::string shaderName);
	Shader getShader(const std::string shaderName);
private:
	std::map<std::string, Shader> _shaders;
	


};
#endif
