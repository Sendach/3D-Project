#ifndef DOOR_H
#define DOOR_H

//GLM
#include <glm/gtc/matrix_transform.hpp>

//Includes
#include "RenderObjects.h"
#include <memory>
#include "ResourceManager.h"
#include <string>

class Door
{
public:
	Door(){}
	Door(std::shared_ptr<ResourceManager> resource) { this->resource = resource; }
	void change(glm::mat4& model, glm::vec3& position, glm::vec3& rotation, float angle, glm::vec3& scale);
	void sendModel(std::string shaderName, glm::mat4& model);
	void drawDoor(int size);
private:
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
	RenderObjects renderObjects;
};
#endif
