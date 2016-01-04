#include "Game_Room_1.h"
#include <iostream>
#include <string>

Game_Room_1::Game_Room_1(std::shared_ptr<ResourceManager> resource) : Scene(resource)
{
	this->direction = Direction::UP;
	chances = 0;
	amountOfChances = 3;
	movementSpeed = 250.0f;
}

void Game_Room_1::update(Camera& camera)
{
	resource->getShader("GameRoom").use();
	glm::mat4 view = camera.getViewMatrix();
	resource->getShader("GameRoom").setMatrix4fv("view", view);
}

void Game_Room_1::room1Controls(float delta, Camera& camera)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		camera.cameraPosition.z = 0.0f;
		
	}

	if (camera.cameraPosition.z < -325.0f && direction != Direction::STOP)
	{
		if (this->direction == Direction::UP)
		{
			//Checks if the player enters the room with the position in y above 10 or under 10. If above, bring it down to 10. If under, bring it up to 10.
			if (camera.cameraPosition.y >= 10.0f)
			{
				if (fabs(camera.cameraPosition.y - 10.0f) > 0.5f)
				{
					camera.cameraPosition.y -= movementSpeed * delta;
				}
			}
			else
			{
				if (fabs(camera.cameraPosition.y - 10.0f) > 0.5)
				{
					camera.cameraPosition.y += movementSpeed * delta;
				}
			}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				std::cin >> answer;
				if (answer == "0")
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
		
		if (direction == Direction::FORWARD)
		{
			if (fabs(camera.cameraPosition.z + 478.0f) > 0.5f)
			{
				camera.cameraPosition.z -= movementSpeed * delta;
			}
			if (chances == amountOfChances && fabs(camera.cameraPosition.z + 478.0f) < 0.5f)
			{
				direction = Direction::LEFT;
			}
			else if (chances != amountOfChances && fabs(camera.cameraPosition.z + 478.0f) < 0.5f)
			{
				direction = Direction::RIGHT;
			}
		}
		if (direction == Direction::RIGHT)
		{
			if (fabs(camera.cameraPosition.x - 161.0f) > 0.5f)
			{
				camera.cameraPosition.x += movementSpeed * delta;
			}
			if (fabs(camera.cameraPosition.x - 161.0f) < 0.5f)
			{
				direction = Direction::STOP;
			}
			
		}

		if (direction == Direction::LEFT)
		{
			if (fabs(camera.cameraPosition.x + 133.0f) > 0.5f)
			{
				camera.cameraPosition.x -= movementSpeed * delta;
			}
			if (chances == amountOfChances && fabs(camera.cameraPosition.x + 133.0f) < 0.5f)
			{
				camera.cameraPosition.x = 0.5f;
				camera.cameraPosition.y = -2.4f;
				camera.cameraPosition.z = -180.0f;
				direction = Direction::STOP;
			}
		}
	}
}

void Game_Room_1::draw(Camera& camera)
{
	
	resource->getShader("GameRoom").use();
	resource->getTexture("Question_1_Room").bindTexture();
	resource->getModel("Crate").bindVertexArray();

	//Building
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(-3.0f, 10.0f, -415.5f));
	model = glm::scale(model, glm::vec3(13.0f, 6.0f, 10.0f));
	resource->getShader("GameRoom").setMatrix4fv("model", model);
	glDrawArrays(GL_TRIANGLES, 0, resource->getModel("Crate").getModelSize());
	glBindVertexArray(0);

	//Quad
	resource->getTexture("Question_1_Quad").bindTexture();
	resource->getModel("Quad").bindVertexArray();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(-3.0f, 10.0f, -500.0f));
	model = glm::scale(model, glm::vec3(25.4f, 11.6f, 20.0f));
	resource->getShader("GameRoom").setMatrix4fv("model", model);
	glDrawArrays(GL_TRIANGLES, 0, resource->getModel("Quad").getModelSize());
	glBindVertexArray(0);

	//Doors
	float x[2] = { -137.0f, 122.5f };

	resource->getShader("Room_Doors").use();
	resource->getTexture("metal_Door").bindTexture();
	resource->getModel("Metal_Door").bindVertexArray();

	for (int i = 0; i < 2; i++)
	{
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(x[i], -10.0f, -480.0f));
		model = glm::scale(model, glm::vec3(5.0f));
		resource->getShader("Room_Doors").setMatrix4fv("model", model);
		glDrawArrays(GL_TRIANGLES, 0, resource->getModel("Metal_Door").getModelSize());
	}
	glBindVertexArray(0);
}
