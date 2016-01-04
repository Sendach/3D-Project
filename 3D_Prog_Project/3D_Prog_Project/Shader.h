#ifndef SHADER_H
#define SHADER_H

#define GLEW_STATIC
#include <GL/glew.h>

//GLM
#include <glm/glm.hpp>
class Shader
{
public:
	Shader(){}
	GLuint Program;
	Shader setupShader(const GLchar* vertexPath, const GLchar* geometryPath,  const GLchar* fragmentPath);
	void use();

	//Uniform
	void Shader::setInteger(const GLchar *name, GLint value);
	void setVector3f(const GLchar* name, const glm::vec3& vector);
	void setMatrix4fv(const GLchar* name, const glm::mat4& matrix);

};
#endif
