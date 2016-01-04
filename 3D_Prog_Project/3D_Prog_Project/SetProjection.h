#ifndef SETPROJECTION_H
#define SETPROJECTION_H

#include "ResourceManager.h"
#include <memory>

//Glew
#define GLEW_STATIC
#include <GL/glew.h>

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class SetProjection
{
public:
	SetProjection(std::shared_ptr<ResourceManager> resource);
	void setProjection();

private:
	glm::mat4 projection;
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
};
#endif

