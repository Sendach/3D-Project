#include "Light.h"


void Light::setLightPosition(glm::vec3 lightPos)
{
	this->lightPosition = lightPos;
}

glm::vec3 Light::getLightPosition()
{
	return this->lightPosition;

}

void Light::setLightColor(glm::vec3 lightColor)
{
	this->lightColor = lightColor;
}

glm::vec3 Light::getLightColor()
{
	return this->lightColor;
}

void Light::update(Camera& camera, std::string shader)
{
	resource->getShader(shader).use();
	//View
	glm::mat4 view = camera.getViewMatrix();
	resource->getShader(shader).setMatrix4fv("view", view);
	
}

void Light::draw(std::string model)
{
	//Draw Light
	resource->getModel(model).bindVertexArray();
	glDrawArrays(GL_TRIANGLES, 0, resource->getModel(model).getModelSize());
	glBindVertexArray(0);
}