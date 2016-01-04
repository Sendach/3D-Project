#include "Model.h"

void Model::takeInfo(std::vector<glm::vec3>& position, std::vector<glm::vec2>& texCoord, std::vector<glm::vec3>& normal, std::vector<glm::vec3>& tangent, std::vector<glm::vec3>& bitangent, bool normalMapping)
{
	this->position = position;
	this->texCoord = texCoord;
	this->normal = normal;

	//We'll check if we want normal mapping by checking if these vectors are empty
	if (normalMapping)
	{
		this->tangent = tangent;
		this->bitangent = bitangent;
	}
}

Model Model::setupMesh(std::string path, bool normalMapping)
{
	GLuint posVerBuffer, texCoordVerBuffer, normalVerBuffer, tangentVerBuffer, bitangentVerBuffer;
	OBJ_Loader::loadOBJ(path, this->position, this->normal, this->texCoord);

	//Generate Vertex Array
	glGenVertexArrays(1, &vertexArrayBuffer);

	//Generate required buffers
	modelGenBuff(posVerBuffer, texCoordVerBuffer, normalVerBuffer);

	//If normalMapping is true, generate the buffers
	normalMappingGenBuff(normalMapping, tangentVerBuffer, bitangentVerBuffer);

	//Bind Vertex Array
	glBindVertexArray(vertexArrayBuffer);

	//Bind required buffers
	modelBindBuff(posVerBuffer, texCoordVerBuffer, normalVerBuffer);

	//If normalMapping is true, bind the buffers and send them to the GPU
	normalMappingBindBuff(normalMapping, tangentVerBuffer, bitangentVerBuffer);

	//Unbind Vertex Array
	glBindVertexArray(0);

	//Save size of the model so it can be accessed
	
	sizeOfModel = position.size();

	//Return the loaded model
	return *this;
}

void Model::modelGenBuff(GLuint& posVerBuffer, GLuint& texCoordVerBuffer, GLuint& normalVerBuffer)
{
	glGenBuffers(1, &posVerBuffer);
	glGenBuffers(1, &texCoordVerBuffer);
	glGenBuffers(1, &normalVerBuffer);
}

void Model::modelBindBuff(GLuint& posVerBuffer, GLuint& texCoordVerBuffer, GLuint& normalVerBuffer)
{
	//Position
	glBindBuffer(GL_ARRAY_BUFFER, posVerBuffer);
	glBufferData(GL_ARRAY_BUFFER, position.size() * sizeof(glm::vec3), &position[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0); // Position

																	//Normal
	glBindBuffer(GL_ARRAY_BUFFER, normalVerBuffer);
	glBufferData(GL_ARRAY_BUFFER, normal.size() * sizeof(glm::vec3), &normal[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0); // Normal

																	//Texture
	glBindBuffer(GL_ARRAY_BUFFER, texCoordVerBuffer);
	glBufferData(GL_ARRAY_BUFFER, texCoord.size() * sizeof(glm::vec2), &texCoord[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0); // Texture
}

void Model::normalMappingGenBuff(bool normalMapping, GLuint& tangentVerBuffer, GLuint& bitangentVerBuffer)
{
	if (normalMapping)
	{
		glGenBuffers(1, &tangentVerBuffer);
		glGenBuffers(1, &bitangentVerBuffer);
	}
}

void Model::normalMappingBindBuff(bool normalMapping, GLuint& tangentVerBuffer, GLuint& bitangentVerBuffer)
{
	Normal_Mapping_Calculation::calculate(position, texCoord, tangent, bitangent);

	if (normalMapping)
	{
		//Tangent
		glBindBuffer(GL_ARRAY_BUFFER, tangentVerBuffer);
		glBufferData(GL_ARRAY_BUFFER, tangent.size() * sizeof(glm::vec3), &tangent[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0); // Tangent

																		//Tangent
		glBindBuffer(GL_ARRAY_BUFFER, bitangentVerBuffer);
		glBufferData(GL_ARRAY_BUFFER, bitangent.size() * sizeof(glm::vec3), &bitangent[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0); // Tangent
	}

}

void Model::bindVertexArray()
{
	glBindVertexArray(this->vertexArrayBuffer);
}


GLsizei& Model::getModelSize()
{
	return this->sizeOfModel;
}