#include "Room_3.h"

void Room_3::initialize()
{
}

void Room_3::update(Camera& camera)
{
	
	static int counter = 0;
	if (counter == 0) { initialize(); }

	view = camera.getViewMatrix();

	resource->getShader("Room_3").use();
	resource->getShader("Room_3").setMatrix4fv("view", view);

	resource->getShader("Room_3_Quad").use();
	resource->getShader("Room_3_Quad").setMatrix4fv("view", view);
}

void Room_3::draw(Camera& camera)
{
	static float counter = 0;

	//Room
	resource->getShader("Room_3").use();
	resource->getTexture("desert").bindTexture();
	resource->getModel("Crate").bindVertexArray();

	model = glm::mat4();
	transformObject.transform(model, glm::vec3(-286.5f, 5.0f, -41.5f), glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, glm::vec3(26.0f, 11.0f, 7.5f));
	resource->getShader("Room_3").setMatrix4fv("model", model);
	renderObject.render(resource->getModel("Crate").getModelSize());
	
	//Quad
	resource->getShader("Room_3_Quad").use();
	resource->getTexture("light_water").bindTexture();
	resource->getModel("Quad").bindVertexArray();

	//Set in front of camera to calculate backface culling
	resource->getShader("Room_3_Quad").setVector3f("cameraFront", camera.front);

	model = glm::mat4();
	transformObject.transform(model, glm::vec3(-330.5f, 25.0f, -41.5f), glm::vec3(0.0f, 1.0f, 0.0f), counter * glm::radians(-25.0f), glm::vec3(4.0f, 4.0f, 1.0f));
	resource->getShader("Room_3_Quad").setMatrix4fv("model", model);
	renderObject.render(resource->getModel("Quad").getModelSize());

	renderObject.unbind();
	counter = counter + 0.1;
}