#include "Room_2.h"


Room_2::Room_2(std::shared_ptr<ResourceManager> resource) : Scene(resource)
{

}

void Room_2::initialize()
{
	room_2_Light->setLightPosition(glm::vec3(117.0f, 150.0f, 41.0f));

	resource->getShader("Normal_Mapping").use();
	resource->getShader("Normal_Mapping").setInteger("objectTexture", 0);
	resource->getShader("Normal_Mapping").setInteger("normalMap", 1);
}

void Room_2::update(Camera& camera)
{
	static int counter = 0;
	if (counter == 0) {
		initialize();
		counter++;
	}

	view = camera.getViewMatrix();
	resource->getShader("Room_2").use();
	resource->getShader("Room_2").setMatrix4fv("view", view);
	resource->getShader("Room_2").setVector3f("lightPos", room_2_Light->getLightPosition());
	resource->getShader("Room_2").setVector3f("viewPos", camera.cameraPosition);

	resource->getShader("Normal_Mapping").use();
	resource->getShader("Normal_Mapping").setMatrix4fv("view", view);
	resource->getShader("Normal_Mapping").setVector3f("lightPos", room_2_Light->getLightPosition());
	resource->getShader("Normal_Mapping").setVector3f("viewPos", camera.cameraPosition);

	//std::cout << camera.cameraPosition.x << " " << camera.cameraPosition.y << " " << camera.cameraPosition.z << std::endl;
}

void Room_2::draw(Camera& camera)
{
	resource->getModel("Quad_Mapping").bindVertexArray();

	
	glActiveTexture(GL_TEXTURE1);
	resource->getTexture("brickwall_normal").bindTexture();
	glActiveTexture(GL_TEXTURE0);
	resource->getTexture("brickwall").bindTexture();

	resource->getShader("Normal_Mapping").use();

	model = glm::mat4();
	transformObject.transform(model, glm::vec3(120.0f, 5.0f, 180.0f), glm::vec3(1.0f, 0.0f, 0.0f), -135.0f, glm::vec3(4.0f));
	resource->getShader("Normal_Mapping").setMatrix4fv("model", model);
	renderObject.render(resource->getModel("Quad_Mapping").getModelSize());

	renderObject.unbind();

	//Draw Room
	resource->getModel("Crate").bindVertexArray();
	resource->getTexture("dark_grey_metal").bindTexture();
	resource->getShader("Room_2").use();

	model = glm::mat4();
	transformObject.transform(model, glm::vec3(106.1f, 5.0f, 131.0f), glm::vec3(1.0f), 0.0f, glm::vec3(8.0f, 15.0f, 8.0f));
	resource->getShader("Room_2").setMatrix4fv("model", model);
	renderObject.render(resource->getModel("Crate").getModelSize());

	renderObject.unbind();

	// Non-Mapped Brick Wall
	resource->getModel("Quad").bindVertexArray();
	resource->getTexture("brickwall").bindTexture();
	resource->getShader("Room_2").use();

	model = glm::mat4();
	transformObject.transform(model, glm::vec3(80.1f, 5.f, 180.0f), glm::vec3(1.0f, 0.0f, 0.0f), 45.0f, glm::vec3(4.0f));
	resource->getShader("Room_2").setMatrix4fv("model", model);
	renderObject.render(resource->getModel("Quad").getModelSize());

	renderObject.unbind();
}