#include "Room_4.h"

Room_4::Room_4(std::shared_ptr<ResourceManager> resource) : Scene(resource)
{

}


void Room_4::initialize()
{
	createLights();
}

void Room_4::update(Camera & camera)
{
	static int counter = 0;
	if (counter == 0) {	initialize(); }

	view = camera.getViewMatrix();

	resource->getShader("Room_4").use();
	resource->getShader("Room_4").setMatrix4fv("view", view);

	resource->getShader("Deferred_Light_Cubes").use();
	resource->getShader("Deferred_Light_Cubes").setMatrix4fv("view", view);
}

void Room_4::draw(Camera & camera)
{
	float xTranslate[2] = { 120.0f, 160.0f };
	float yTranslate[2] = { -40.0f, -60.0f };
	float zTranslate[2] = { -20.0f, -5.0f };

	//Room 4
	resource->getModel("Crate").bindVertexArray();
	resource->getTexture("Dark_Texture").bindTexture();
	resource->getShader("Room_4").use();

	model = glm::mat4();
	transformObject.transform(model, glm::vec3(106.1f, -45.0f, -10.0f), glm::vec3(1.0f), 0.0f, glm::vec3(8.0f, 7.0f, 6.0f));
	resource->getShader("Room_4").setMatrix4fv("model", model);
	renderObject.render(resource->getModel("Crate").getModelSize());

	//resource->getFBO("gBuffer").bindGBuffer();
	//Cubes
	resource->getTexture("wood").bindTexture();
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			model = glm::mat4();
			transformObject.transform(model, glm::vec3(140.0f, yTranslate[i], zTranslate[j]), glm::vec3(1.0f), 0.0f, glm::vec3(0.5));
			resource->getShader("Room_4").setMatrix4fv("model", model);
			renderObject.render(resource->getModel("Crate").getModelSize());
		}
	}
	//glDisable(GL_TEXTURE_2D);

	//Light Cubes

	resource->getShader("Deferred_Light_Cubes").use();
	for (int i = 0; i < (nrOfLights / 2); i++)
	{
		for (int j = 0; j < (nrOfLights/2); j++)
		{
			model = glm::mat4();
			transformObject.transform(model, glm::vec3(xTranslate[i], yTranslate[j], zTranslate[j]), glm::vec3(1.0f), 0.0f, glm::vec3(0.25f));
			resource->getShader("Deferred_Light_Cubes").setMatrix4fv("model", model);
			renderObject.render(resource->getModel("Crate").getModelSize());
		}
	}
	renderObject.unbind();
}

void Room_4::createLights()
{
	float xTranslate[2] = { 120.0f, 160.0f };
	float yTranslate[2] = { -40.0f, -60.0f };
	float zTranslate[2] = { -20.0f, -5.0f };

	//So the vector goes from 0-3, since it's a double-for-loop.
	static int change = 0;
	for (int i = 0; i < (nrOfLights / 2); i++)
	{
		for (int j = 0; j < (nrOfLights / 2); j++)
		{
			lightPositions.push_back(Light());
			lightPositions[j + change].setLightPosition(glm::vec3(xTranslate[i], yTranslate[j], zTranslate[j]));
		}
		change = 2;
	}
}
