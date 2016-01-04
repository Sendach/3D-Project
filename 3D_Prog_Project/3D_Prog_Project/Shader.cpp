#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Shader Shader::setupShader(const GLchar* vertexPath, const GLchar* geometryPath,  const GLchar* fragmentPath)
{
	std::string vertexCode, geometryCode, fragmentCode;
	std::ifstream vShaderFile, gShaderFile, fShaderFile;

	// ensures ifstream objects can throw exceptions:
	vShaderFile.exceptions(std::ifstream::badbit);
	if (geometryPath != nullptr)
	{
		gShaderFile.exceptions(std::ifstream::badbit);
	}
	
	fShaderFile.exceptions(std::ifstream::badbit);
	try
	{
		// Open files
		vShaderFile.open(vertexPath);
		if (geometryPath != nullptr) { gShaderFile.open(geometryPath); }
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, gShaderStream,fShaderStream;
		// Read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		if (geometryPath != nullptr) { gShaderStream << gShaderFile.rdbuf(); }
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		if (geometryPath != nullptr) { gShaderFile.close(); }
		fShaderFile.close();
		// Convert stream into string
		vertexCode = vShaderStream.str();
		if (geometryPath != nullptr) { geometryCode = gShaderStream.str(); }
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* gShaderCode = geometryCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();
	
	GLuint vertex = 0, geometry = 0, fragment = 0;
	GLint success;
	GLchar infoLog[512];
	// Vertex Shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, nullptr);
	glCompileShader(vertex);
	// Print compile errors if any
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << "Shader: " << vertexPath << "\n" << infoLog << std::endl;
	}
	//Geometry Shader
	if (geometryPath != nullptr)
	{

		geometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometry, 1, &gShaderCode, nullptr);
		glCompileShader(geometry);
		glGetShaderiv(geometry, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(geometry, 512, nullptr, infoLog);
			std::cout << "ERROR::SHADER::GEOMETRY::COMPILATION_FAILED\n" << "Shader: " << geometryPath << "\n" << infoLog << std::endl;
		}
	}
	// Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, nullptr);
	glCompileShader(fragment);
	// Print compile errors if any
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << "Shader: " << fragmentPath << "\n" << infoLog << std::endl;
	}

	// Shader Program
	this->Program = glCreateProgram();
	glAttachShader(this->Program, vertex);
	if (geometryPath != nullptr) { glAttachShader(this->Program, geometry); }
	glAttachShader(this->Program, fragment);
	glLinkProgram(this->Program);
	// Print linking errors if any
	glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->Program, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << "VerShad: " << infoLog << std::endl;
	}

	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (geometryPath != nullptr) glDeleteShader(geometry);

	return *this;
}

void Shader::use()
{
	glUseProgram(this->Program);
}


void Shader::setInteger(const GLchar *name, GLint value)
{
	glUniform1i(glGetUniformLocation(this->Program, name), value);
}
void Shader::setVector3f(const GLchar* name, const glm::vec3& vector)
{
	glUniform3f(glGetUniformLocation(this->Program, name), vector.x, vector.y, vector.z);
}

void Shader::setMatrix4fv(const GLchar* name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(glGetUniformLocation(this->Program, name), 1, GL_FALSE, glm::value_ptr(matrix));
}