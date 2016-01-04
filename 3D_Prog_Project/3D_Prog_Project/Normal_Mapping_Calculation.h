#ifndef NORMAL_MAPPING_CALCULATION_H
#define NORMAL_MAPPING_CALCULATION_H

//Glew
#define GLEW_STATIC
#include <gl\glew.h>

//GLM
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Other Includes
#include <vector>

class Normal_Mapping_Calculation
{
public:
	static void calculate(std::vector<glm::vec3>& position, std::vector<glm::vec2> texCoords, std::vector<glm::vec3>& tangent, std::vector<glm::vec3>& bitangent);
};
#endif