#include "Winning_Room.h"



Winning_Room::Winning_Room(std::shared_ptr<ResourceManager> resource) : Scene(resource)
{

}

void Winning_Room::initialize()
{

}

void Winning_Room::update(Camera& camera)
{

	//std::cout << camera.cameraPosition.x << " " << camera.cameraPosition.y << " " << camera.cameraPosition.z << std::endl;
	static int counter = 0;
	if (counter == 0) { initialize(); }

	resource->getShader("GameRoom").use();
	glm::mat4 view = camera.getViewMatrix();
	resource->getShader("GameRoom").setMatrix4fv("view", view);

	if (camera.cameraPosition.z <= -1111.0f && (camera.cameraPosition.x >= 106.0f && camera.cameraPosition.x <= 127.0))
	{
		camera.cameraPosition.x = 0.5f;
		camera.cameraPosition.y = -2.4f;
		camera.cameraPosition.z = -180.0f;
	}
}

void Winning_Room::draw(Camera& camera)
{
	resource->getShader("GameRoom").use();
	resource->getTexture("Winning_Room").bindTexture();
	resource->getModel("Crate").bindVertexArray();

	//Building
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(101.8f, 10.0f, -910.0f));
	model = glm::scale(model, glm::vec3(13.0f, 6.0f, 20.0f));
	resource->getShader("GameRoom").setMatrix4fv("model", model);
	glDrawArrays(GL_TRIANGLES, 0, resource->getModel("Crate").getModelSize());
	glBindVertexArray(0);

	//Doors
	float x[2] = { 227.5f, 487.5f };

	resource->getShader("Room_Doors").use();
	resource->getTexture("metal_Door").bindTexture();
	resource->getModel("Metal_Door").bindVertexArray();

	model = glm::mat4();
	model = glm::translate(model, glm::vec3(116, -45.0f, -1105.6f));
	model = glm::scale(model, glm::vec3(5.0f));
	model = glm::rotate(model, 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	resource->getShader("Room_Doors").setMatrix4fv("model", model);
	glDrawArrays(GL_TRIANGLES, 0, resource->getModel("Metal_Door").getModelSize());

	glBindVertexArray(0);
}
