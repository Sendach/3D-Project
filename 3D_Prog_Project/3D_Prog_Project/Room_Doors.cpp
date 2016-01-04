#include "Room_Doors.h"

//Other Includes
#include <vector>

Room_Doors::Room_Doors(std::shared_ptr<ResourceManager> resource) : Scene(resource) 
{
	
}

void Room_Doors::update(Camera& camera)
{
	resource->getShader("Room_Doors").use();
	view = camera.getViewMatrix();

	resource->getShader("Room_Doors").setMatrix4fv("view", view);
}
void Room_Doors::draw(Camera& camera)
{

	float x_Axis[2] = { -30.5, 22.0 };
	float z_Axis[3] = { -140.0, -40.0, 60.0 };

	resource->getShader("Room_Doors").use();
	resource->getTexture("metal_Door").bindTexture();
	resource->getModel("Metal_Door").bindVertexArray();

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			model = glm::mat4();
			transformObject.transform(model, glm::vec3(x_Axis[i], -20.f, z_Axis[j]), glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, glm::vec3(5.0f));
			resource->getShader("Room_Doors").setMatrix4fv("model", model);
			renderObject.render(resource->getModel("Metal_Door").getModelSize());
		}
	}
	model = glm::mat4();
	transformObject.transform(model, glm::vec3(-2.0f, -20.f, -311.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, glm::vec3(5.0f));
	resource->getShader("Room_Doors").setMatrix4fv("model", model);
	renderObject.render(resource->getModel("Metal_Door").getModelSize());

	glBindVertexArray(0);
}