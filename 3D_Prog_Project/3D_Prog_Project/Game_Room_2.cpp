#include "Game_Room_2.h"



Game_Room_2::Game_Room_2(std::shared_ptr<ResourceManager> resource) : Scene(resource)
{
	this->direction = Direction::START;
	chances = 0;
	amountOfChances = 3;
	movementSpeed = 150.0f;
}

void Game_Room_2::initialize()
{
	
}

void Game_Room_2::update(Camera& camera)
{
	
}

void Game_Room_2::room2Controls(float delta, Camera& camera)
{
	if (camera.cameraPosition.x > 160.5f && direction != Direction::STOP)
	{
		if (direction == Direction::START)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				std::cin >> answer;
				if (answer == "Nothing" || answer == "nothing")
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
			if (std::fabs(camera.cameraPosition.x - 352.0f) < 0.5f)
			{
				std::cout << "lol: " << fabs(camera.cameraPosition.x - 352.0f);
			}
			
			if (std::fabs(camera.cameraPosition.x - 352.0f) > 0.5f)
			{
				camera.cameraPosition.x += movementSpeed * delta;
			}

			if (chances == amountOfChances && std::fabs(camera.cameraPosition.x - 352.0f) < 0.5f)
			{
				direction = Direction::RIGHT;
			}
			else if (chances != amountOfChances && std::fabs(camera.cameraPosition.x - 352.0f) < 0.5f)
			{
				direction = Direction::LEFT;
			}
		}

		if (direction == Direction::LEFT)
		{
			if (std::fabs(camera.cameraPosition.z + 590.0f) > 0.5f)
			{
				camera.cameraPosition.z -= movementSpeed * delta;
			}

			if (std::fabs(camera.cameraPosition.z + 590.0f) < 0.5f)
			{
				direction = Direction::STOP;
			}
		}

		if (direction == Direction::RIGHT)
		{
			
			if (std::fabs(camera.cameraPosition.z - (-388.0f)) > 0.5f)
			{
				camera.cameraPosition.z += movementSpeed * delta;
			}
			if (chances == amountOfChances && std::fabs(camera.cameraPosition.z - (-388.0f)) < 0.5f)
			{
				camera.cameraPosition.x = 0.5f;
				camera.cameraPosition.y = -2.4f;
				camera.cameraPosition.z = -180.0f;
				direction = Direction::STOP;
			}
		}
		
	}
}

void Game_Room_2::draw(Camera& camera)
{
	resource->getShader("GameRoom").use();
	resource->getTexture("Question_2_Room").bindTexture();
	resource->getModel("Crate").bindVertexArray();

	//Building
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(257.2f, 10.0f, -475.5f));
	model = glm::scale(model, glm::vec3(13.0f, 6.0f, 9.0f));
	resource->getShader("GameRoom").setMatrix4fv("model", model);
	glDrawArrays(GL_TRIANGLES, 0, resource->getModel("Crate").getModelSize());
	glBindVertexArray(0);

	//Quad
	resource->getTexture("Question_2_Quad").bindTexture();
	resource->getModel("Quad").bindVertexArray();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(380.0f, 10.0f, -473.0f));
	model = glm::rotate(model, -90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(16.0f, 11.6f, 150.0f));
	resource->getShader("GameRoom").setMatrix4fv("model", model);
	glDrawArrays(GL_TRIANGLES, 0, resource->getModel("Quad").getModelSize());
	glBindVertexArray(0);

	//Doors
	float z[2] = {-561.3f, -381.3f };

	resource->getShader("Room_Doors").use();
	resource->getTexture("metal_Door").bindTexture();
	resource->getModel("Metal_Door").bindVertexArray();

	for (int i = 0; i < 2; i++)
	{
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(350.0, -10.0f, z[i]));
		model = glm::scale(model, glm::vec3(5.0f));
		model = glm::rotate(model, 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		resource->getShader("Room_Doors").setMatrix4fv("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 528);
	}
	glBindVertexArray(0);
}
