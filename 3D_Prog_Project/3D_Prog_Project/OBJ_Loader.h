#ifndef OBJ_Loader_H
#define OBJ_Loader_H

//Glew
#define GLEW_STATIC
#include <GL/glew.h>
//GLM
#include <glm/glm.hpp>
//Other Includes
#include <string>
#include <vector>

class OBJ_Loader
{
public:
	
	static bool loadOBJ(std::string path, std::vector<glm::vec3>& out_position, std::vector<glm::vec3>& out_normals, std::vector<glm::vec2>& out_uvs);

private:


};
#endif
