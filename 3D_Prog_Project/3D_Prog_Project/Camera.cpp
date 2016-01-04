#include "Camera.h"

#include <iostream>
Camera::Camera(glm::vec3 cameraPosition)
{
	this->cameraPosition = cameraPosition;
	this->worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	this->front = glm::vec3(0.0f, 0.0f, -1.0f);
	this->yaw = -90.0f;
	this->pitch = 0.0f;
	this->movementSpeed = 150.0;
	this->sensitivity = 0.1;
}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(this->cameraPosition, this->cameraPosition + this->front, this->currentUp);

}

void Camera::updateCameraKeyboardMovement(float delta)
{
	GLfloat velocity = this->movementSpeed * delta;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->cameraPosition += this->front * velocity;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->cameraPosition -= this->front * velocity;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->cameraPosition += this->right * velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->cameraPosition -= this->right * velocity;
	}
	
}

void Camera::updateCameraMouseMovement(float delta, sf::RenderWindow& window, int screenWidth, int screenHeight)
{	
	GLfloat currentXWindow = sf::Mouse::getPosition(window).x, currentYWindow = sf::Mouse::getPosition(window).y;
	//std::cout << " X2 " << currentXWindow << " Y2 " << currentYWindow << std::endl;

	int counter = 1;

	
	if (currentXWindow > screenWidth || currentXWindow < 0)
	{
		sf::Mouse::setPosition(sf::Vector2i((float)screenWidth/(float)2, currentYWindow), window);
		lastX = (float)screenWidth / (float)2;
	}
	else if (currentYWindow > screenHeight || currentYWindow < 0)
	{
		sf::Mouse::setPosition(sf::Vector2i(currentXWindow, (float)screenHeight/(float)2), window);
		lastY = (float)screenHeight / (float)2;
	}
	else {
		counter = 1;
	}

	if (currentXWindow <= screenWidth && currentYWindow <= screenHeight )
	{
		GLfloat xOffset = currentXWindow - lastX;
		GLfloat yOffset = lastY - currentYWindow;
		lastX = currentXWindow;
		lastY = currentYWindow;

		xOffset *= this->sensitivity;
		yOffset *= this->sensitivity;

		this->yaw += xOffset;
		this->pitch += yOffset;

		if (this->pitch > 89.0f) { pitch = 89.0f; }
		if (pitch < -89.0f) { pitch = -89.0f; }

		this->updateCameraVector();
	}
}

void Camera::updateCameraVector()
{
	glm::vec3 front;
	front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	front.y = sin(glm::radians(this->pitch));
	front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->front = glm::normalize(front);
	this->right = glm::normalize(glm::cross(this->front, this->worldUp));
	this->currentUp = glm::normalize(glm::cross(this->right, front));
}