#include "Game_Room_3.h"

#include <iostream>
Game_Room_3::Game_Room_3(std::shared_ptr<ResourceManager> resource) : Scene(resource)
{
	direction = Direction::START;
	movementSpeed = 150.0f;
	chances = 0;
	amountOfChances = 3;
}

void Game_Room_3::initialize()
{
}

void Game_Room_3::update(Camera& camera)
{
	static int counter = 0;
	if (counter == 0) { initialize(); }

	resource->getShader("GameRoom").use();

	glm::mat4 view = camera.getViewMatrix();
	resource->getShader("GameRoom").setMatrix4fv("view", view);
}

void Game_Room_3::room3Controls(float delta, Camera& camera)
{

	if (camera.cameraPosition.z <= -589.0 && direction != Direction::STOP)
	{
		if (direction == Direction::START)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				std::cin >> answer;
				if (answer == "M" || answer == "m" || answer == "the letter m" || answer == "letter m" || answer == "Letter M" || answer == "The letter M")
				{
					direction = Direction::FORWARD;
				}
				else
				{
					this->chances = this->chances + 1;
				}
				if (chances == amountOfChances)
				{
					direction = Direction::FORWARD;
				}
			}
		}
		if (direction == Direction::FORWARD)
		{
			std::cout << fabs(camera.cameraPosition.z - (-728.0f)) << std::endl;
			if (fabs(camera.cameraPosition.z + 728.0f) > 0.5f)
			{
				camera.cameraPosition.z -= movementSpeed * delta;
			}

			if (chances == amountOfChances && fabs(camera.cameraPosition.z + 728.0f) < 0.5f)
			{
				direction = Direction::RIGHT;
			}
			else if (chances != amountOfChances && fabs(camera.cameraPosition.z + 728.0f) < 0.5f)
			{
				direction = Direction::LEFT;
			}
		}
		if (direction == Direction::RIGHT)
		{
			if (fabs(camera.cameraPosition.x - 488.0f) > 0.5f)
			{
				camera.cameraPosition.x += movementSpeed * delta;
			}
			if (chances == amountOfChances && fabs(camera.cameraPosition.x - 488.0f) < 0.5f)
			{
				camera.cameraPosition.x = 0.5f;
				camera.cameraPosition.y = -2.4f;
				camera.cameraPosition.z = -180.0f;
				direction = Direction::STOP;
			}
		}
		if (direction == Direction::LEFT)
		{
			//camera.cameraPosition.x is about 352. fabs(352 - 189) = 169. camera.cameraPosition.x will keep going down until until camera.camerPosition - 189 is under 0.5.
			if (fabs(camera.cameraPosition.x - 189.0f) > 0.5f)
			{
				camera.cameraPosition.x -= movementSpeed * delta;
			}
			if (chances != amountOfChances && fabs(camera.cameraPosition.x - 189.0f) < 0.5f)
			{
				if (fabs(camera.cameraPosition.z + 730.0f) > 0.5f)
				{
					camera.cameraPosition.z -= movementSpeed * delta;
				}

				if (fabs(camera.cameraPosition.z + 730.0f) < 0.5f)
				{
					direction = Direction::STOP;
				}
				
			}
		}
	}

	
}


void Game_Room_3::draw(Camera& camera)
{
	resource->getShader("GameRoom").use();
	resource->getTexture("Question_3_Room").bindTexture();
	resource->getModel("Crate").bindVertexArray();

	//Building
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(362.0f, 10.0f, -665.6f));
	model = glm::scale(model, glm::vec3(13.0f, 6.0f, 10.0f));
	resource->getShader("GameRoom").setMatrix4fv("model", model);
	glDrawArrays(GL_TRIANGLES, 0, resource->getModel("Crate").getModelSize());
	glBindVertexArray(0);

	//Quad
	resource->getTexture("Question_3_Quad").bindTexture();
	resource->getModel("Quad").bindVertexArray();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(362.0f, 10.0f, -750.0f));
	model = glm::scale(model, glm::vec3(25.6f, 11.6f, 20.0f));
	resource->getShader("GameRoom").setMatrix4fv("model", model);
	glDrawArrays(GL_TRIANGLES, 0, resource->getModel("Quad").getModelSize());
	glBindVertexArray(0);

	//Doors
	float x[2] = { 227.5f, 487.5f };

	resource->getShader("Room_Doors").use();
	resource->getTexture("metal_Door").bindTexture();
	resource->getModel("Metal_Moor").bindVertexArray();

	for (int i = 0; i < 2; i++)
	{
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(x[i], -10.0f, -730.0f));
		model = glm::scale(model, glm::vec3(5.0f));
		resource->getShader("Room_Doors").setMatrix4fv("model", model);
		glDrawArrays(GL_TRIANGLES, 0, resource->getModel("Metal_Door").getModelSize());
	}
	glBindVertexArray(0);

}