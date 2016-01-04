#include "Normal_Mapping_Calculation.h"

void Normal_Mapping_Calculation::calculate(std::vector<glm::vec3>& position, std::vector<glm::vec2> texCoords, std::vector<glm::vec3>& tangent, std::vector<glm::vec3>& bitangent)
{
	glm::vec3 tangentOne, tangentTwo, bitangentOne, bitangentTwo;

	glm::vec3 edgeOne, edgeTwo;
	glm::vec2 deltaUVOne, deltaUVTwo;

	//Triangle One
	//Calculating the two edges
	edgeOne = position[3] - position[1];
	edgeTwo = position[2] - position[1];
	//Calculating texCoordinate "edges
	deltaUVOne = texCoords[3] - texCoords[1];
	deltaUVTwo = texCoords[4] - texCoords[1];

	//Calculating determinant
	GLfloat deter = 1.0f / (deltaUVOne.x * deltaUVTwo.y - deltaUVTwo.x * deltaUVOne.y);

	tangentOne.x = deter * (deltaUVTwo.y * edgeOne.x - deltaUVOne.y * edgeTwo.x);
	tangentOne.y = deter * (deltaUVTwo.y * edgeOne.y - deltaUVOne.y * edgeTwo.y);
	tangentOne.z = deter * (deltaUVTwo.y * edgeOne.z - deltaUVOne.y * edgeTwo.z);
	tangentOne = glm::normalize(tangentOne);

	bitangentOne.x = deter * (-deltaUVTwo.x * edgeOne.x + deltaUVOne.x * edgeTwo.x);
	bitangentOne.y = deter * (-deltaUVTwo.x * edgeOne.y + deltaUVOne.x * edgeTwo.y);
	bitangentOne.z = deter * (-deltaUVTwo.x * edgeOne.z + deltaUVOne.x * edgeTwo.z);
	bitangentOne = glm::normalize(bitangentOne);

	//Triangle Two
	edgeOne = position[3] - position[1];
	edgeTwo = position[4] - position[1];
	deltaUVOne = texCoords[3] - texCoords[1];
	deltaUVTwo = texCoords[4] - texCoords[1];

	deter = 1.0f / (deltaUVOne.x * deltaUVTwo.y - deltaUVTwo.x * deltaUVOne.y);

	tangentTwo.x = deter * (deltaUVTwo.y * edgeOne.x - deltaUVOne.y * edgeTwo.x);
	tangentTwo.y = deter * (deltaUVTwo.y * edgeOne.y - deltaUVOne.y * edgeTwo.y);
	tangentTwo.z = deter * (deltaUVTwo.y * edgeOne.z - deltaUVOne.y * edgeTwo.z);
	tangentTwo = glm::normalize(tangentTwo);


	bitangentTwo.x = deter * (-deltaUVTwo.x * edgeOne.x + deltaUVOne.x * edgeTwo.x);
	bitangentTwo.y = deter * (-deltaUVTwo.x * edgeOne.y + deltaUVOne.x * edgeTwo.y);
	bitangentTwo.z = deter * (-deltaUVTwo.x * edgeOne.z + deltaUVOne.x * edgeTwo.z);
	bitangentTwo = glm::normalize(bitangentTwo);
	
	// First Triangle
	for (int i = 0; i < 3; i++)
	{
		tangent.push_back(tangentOne);
		bitangent.push_back(bitangentOne);
	}
	
	// Second Triangle
	for (int i = 0; i < 3; i++)
	{
		tangent.push_back(tangentTwo);
		bitangent.push_back(bitangentTwo);
	}
}
