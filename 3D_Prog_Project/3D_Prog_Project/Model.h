#ifndef MODEL_H
#define MODEL_H

//Glew
#define GLEW_STATIC
#include <gl\glew.h>

//GLM
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Other Includes
#include <vector>
#include "OBJ_Loader.h"
#include "Normal_Mapping_Calculation.h"

class Model
{
public:
	Model(){}
	void takeInfo(std::vector<glm::vec3>& position, std::vector<glm::vec2>& texCoord, std::vector<glm::vec3>& normal, std::vector<glm::vec3>& tangent, std::vector<glm::vec3>& bitangent, bool normalMapping);
	Model setupMesh(std::string path, bool normalMapping);
	void bindVertexArray();
	GLsizei& getModelSize();

	void modelGenBuff(GLuint& tangentVerBuffer, GLuint& bitangentVerBuffer, GLuint& x);
	void modelBindBuff(GLuint& tangentVerBuffer, GLuint& bitangentVerBuffer, GLuint& x);
	void normalMappingGenBuff(bool normalMapping, GLuint& tangentVerBuffer, GLuint& bitangentVerBuffer);
	void normalMappingBindBuff(bool normalMapping, GLuint& tangentVerBuffer, GLuint& bitangentVerBuffer);

private:
	std::vector<glm::vec3> position;
	std::vector <glm::vec2> texCoord;
	std::vector<glm::vec3> normal;
	std::vector<glm::vec3> tangent;
	std::vector<glm::vec3> bitangent;
	
	GLuint vertexArrayBuffer;
	GLsizei sizeOfModel;

	
};
#endif
