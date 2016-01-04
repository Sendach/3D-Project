#ifndef CAMERA_H
#define CAMERA_H

//GLEW
#define GLEW_STATIC
#include <gl\glew.h>
//GLM
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//SFML
#include <SFML\Graphics.hpp>
class Camera
{
public:
	//Functions
	Camera(){}
	Camera(glm::vec3 camerePosition);
	glm::mat4 getViewMatrix();
	void updateCameraVector();
	void updateCameraKeyboardMovement(float delta);
	void updateCameraMouseMovement(float delta, sf::RenderWindow& window, int screenWidth, int screenHeight);

	//Variables
	glm::vec3 cameraPosition;
	glm::vec3 currentUp; //Camera moves so the up changes
	glm::vec3 right;
	glm::vec3 worldUp; // glm::vec3(0.0, 1.0, 0.0); Used to get the right vector.
	glm::vec3 front;
	GLfloat yaw;
	 GLfloat pitch;
	GLfloat movementSpeed;
	GLfloat sensitivity;
	GLfloat lastX = -1.0f, lastY = -1.0f;
	int counter = 0;
};
#endif

