#include "Door.h"


void Door::change(glm::mat4 & model, glm::vec3 & position, glm::vec3 & rotation, float angle, glm::vec3 & scale)
{
	model = glm::translate(model, position);
	model = glm::rotate(model, angle, rotation);
	model = glm::scale(model, scale);
}

void Door::sendModel(std::string shaderName, glm::mat4& model)
{
	resource->getShader(shaderName).setMatrix4fv("model", model);
}

void Door::drawDoor(int size)
{
	renderObjects.render(size);
}

