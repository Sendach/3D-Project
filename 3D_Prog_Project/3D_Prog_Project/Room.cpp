#include "Room.h"


void Room::change(glm::mat4 & model, glm::vec3 & position, glm::vec3 & rotation, float angle, glm::vec3 & scale)
{
	model = glm::translate(model, position);
	model = glm::rotate(model, angle, rotation);
	model = glm::scale(model, scale);
}

void Room::sendModel(std::string shaderName, glm::mat4 & model)
{
	resource->getShader(shaderName).setMatrix4fv("model", model);
}

void Room::drawRoom(int size)
{
	renderObjects.render(size);
}
