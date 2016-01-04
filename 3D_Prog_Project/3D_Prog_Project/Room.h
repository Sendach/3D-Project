#ifndef ROOM_H
#define ROOM_H

//GLM
#include <glm/gtc/matrix_transform.hpp>

//Includes
#include "RenderObjects.h"
#include <memory>
#include "ResourceManager.h"
#include <string>

class Room
{
public:
	Room() {}
	Room(std::shared_ptr<ResourceManager> resource) { this->resource = resource; }
	void change(glm::mat4& model, glm::vec3& position, glm::vec3& rotation, float angle, glm::vec3& scale);
	void sendModel(std::string shaderName, glm::mat4& model);
	void drawRoom(int size);
private:
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
	RenderObjects renderObjects;
};
#endif
