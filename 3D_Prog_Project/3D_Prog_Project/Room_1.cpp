#include "Room_1.h"


Room_1::Room_1(std::shared_ptr<ResourceManager> resource) : Scene(resource)
{
	counter = 0;
	near_plane = 1.0f, far_plane = 500.0f;
	lightProjection = glm::ortho(-150.0f, 150.0f, -150.0f, 150.0f, near_plane, far_plane);
}

void Room_1::initialize()
{
	//Create Depth map
	resource->getFBO("Shadow_Mapping").createDepthMap(shadow_Width, shadow_Height);
	// Tell shader which Texture sampler is what.

	resource->getShader("Room_1").use();
	resource->getShader("Room_1").setInteger("diffuseTexture", 0);
	resource->getShader("Room_1").setInteger("shadowMap", 1);


	room_1_Light->setLightPosition(glm::vec3(-111.0f, 152.0f, 93.0f));
	lightView = glm::lookAt(room_1_Light->getLightPosition(), room_1_Light->getLightPosition() + glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0));
	lightSpaceMatrix = lightProjection * lightView;
}

void Room_1::update(Camera& camera)
{
	if (counter == 0) {
		initialize();
		counter++;
	}
}

void Room_1::renderSceneNormalPerspective(Camera& camera)
{
	float translateX[2] = { -52.0f, -150.0f };
	float translateY[2] = { -125.0f, -120.0f };

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, 1600, 900);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	resource->getShader("Room_1").use();
	view = camera.getViewMatrix();
	resource->getShader("Room_1").setMatrix4fv("view", view);
	resource->getShader("Room_1").setVector3f("lightPos", room_1_Light->getLightPosition());
	resource->getShader("Room_1").setVector3f("viewPos", camera.cameraPosition);
	resource->getShader("Room_1").setMatrix4fv("lightSpaceMatrix", lightSpaceMatrix);

	glActiveTexture(GL_TEXTURE1);
	resource->getFBO("Shadow_Mapping").bindDepthMap();

	glActiveTexture(GL_TEXTURE0);
	resource->getTexture("lightBlueMetal").bindTexture();

	//Draw Room
	model = glm::mat4();
	transformObjecT.transform(model, glm::vec3(-106.1f, 5.0f, 115.0f), glm::vec3(0.0f, 1.0f, 0.0f), 180.0f, glm::vec3(8.0f, 15.0f, 8.0f));
	resource->getShader("Room_1").setMatrix4fv("model", model);

	//We are using the same model for the room and the boxes. Since we want the normals to change to point inside or outside, we send in true or false.
	resource->getShader("Room_1").setInteger("normalChange", true);
	renderObject.render(resource->getModel("Crate").getModelSize());


	resource->getTexture("wood").bindTexture();
	resource->getShader("Room_1").setInteger("normalChange", false);

	for (int j = 0; j < 2; j++)
	{
		model = glm::mat4();
		transformObjecT.transform(model, glm::vec3(translateX[j], translateY[j], 150.0f), glm::vec3(1.0f, 0.0f, 0.0f), j * -45.0f, glm::vec3(1.0, 1.0, 1.0));
		resource->getShader("Room_1").setMatrix4fv("model", model);
		renderObject.render(resource->getModel("Crate").getModelSize());
	}
	model = glm::mat4();
	transformObjecT.transform(model, glm::vec3(-101.0f, -136.0f, 125.0f), glm::vec3(0.0f, 1.0f, 1.0f), counter * glm::radians(90.0f), glm::vec3(0.2));
	resource->getShader("Room_1").setMatrix4fv("model", model);
	renderObject.render(resource->getModel("Crate").getModelSize());

	renderObject.unbind();
	counter++;
}

void Room_1::renderSceneLightPerspective()
{
	float translateX[2] = { -52.0f, -150.0f };
	float translateY[2] = { -125.0f, -120.0f };

	static int counter = 0;
	//Bind and use model and the shader.
	resource->getModel("Crate").bindVertexArray();
	resource->getShader("Room_1_Shadow_Mapping_Depth").use();

	//Pass the lightSpaceMatrix to the shader
	resource->getShader("Room_1_Shadow_Mapping_Depth").setMatrix4fv("lightSpaceMatrix", lightSpaceMatrix);

	//Draw Building
	model = glm::mat4();
	transformObjecT.transform(model, glm::vec3(-106.1f, 5.0f, 115.0f), glm::vec3(0.0f, 1.0f, 0.0f), 180.0f, glm::vec3(8.0f, 15.0f, 8.0f));
	resource->getShader("Room_1_Shadow_Mapping_Depth").setMatrix4fv("model", model);
	resource->getShader("Room_1").setInteger("normalChange", true);
	renderObject.render(resource->getModel("Crate").getModelSize());

	//Reverse Normal for the boxes, so the normal pointes out instead of the default in.
	resource->getShader("Room_1").setInteger("normalChange", false);

	//Draw boxes
	for (int j = 0; j < 2; j++)
	{
		model = glm::mat4();
		transformObjecT.transform(model, glm::vec3(translateX[j], translateY[j], 150.0f), glm::vec3(1.0f, 0.0f, 0.0f), j * -45.0f, glm::vec3(1.0, 1.0, 1.0));
		resource->getShader("Room_1_Shadow_Mapping_Depth").setMatrix4fv("model", model);
		renderObject.render(resource->getModel("Crate").getModelSize());
	}

	model = glm::mat4();
	transformObjecT.transform(model, glm::vec3(-101.0f, -136.0f, 125.0f), glm::vec3(0.0f, 1.0f, 1.0f), counter * glm::radians(90.0f), glm::vec3(0.2));
	resource->getShader("Room_1_Shadow_Mapping_Depth").setMatrix4fv("model", model);
	renderObject.render(resource->getModel("Crate").getModelSize());

	counter++;
}

void Room_1::draw(Camera& camera)
{
	

	renderSceneLightPerspective();
	renderSceneNormalPerspective(camera);
}