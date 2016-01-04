#include "Main_Building.h"
#include <vector>

Main_Building::Main_Building(std::shared_ptr<ResourceManager> resource) : Scene(resource)
{
	
}

void Main_Building::update(Camera& camera)
{
	resource->getShader("Main_Building").use();

	glm::mat4 view = camera.getViewMatrix();
	resource->getShader("Main_Building").setMatrix4fv("view", camera.getViewMatrix());
}

void Main_Building::draw(Camera& camera)
{
	//Draw Main Building
	resource->getShader("Main_Building").use();
	resource->getTexture("darkBlueMetal").bindTexture();
	resource->getModel("Crate").bindVertexArray();
	
	model = glm::mat4();
	transformObject.transform(model, glm::vec3(0.0f, 1.0f, -15.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, glm::vec3(2.6, 2.6, 30.0));
	resource->getShader("Main_Building").setMatrix4fv("model", model);

	renderObjects.render(resource->getModel("Crate").getModelSize());
	glBindVertexArray(0);

}