#ifndef GAME_ROOM_2_H
#define GAME_ROOM_2_H

//Glew
#define GLEW_STATIC
#include <GL/glew.h>
//Soil
#include <SOIL\SOIL.h>
//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//SFML
#include <SFML/Graphics.hpp>
//CLass Includes
#include "Scene.h"
#include <iostream>

class Game_Room_2 : public Scene
{
public:
	Game_Room_2(std::shared_ptr<ResourceManager> resource);
	~Game_Room_2() {}

	void update(Camera& camera);
	void draw(Camera& camera);
	void initialize();
	void room2Controls(float delta, Camera& camera);
	std::string answer;
	float movementSpeed;
	int amountOfChances;
	int chances;
	enum class Direction { FORWARD, BACKWARDS, LEFT, RIGHT, UP, DOWN, STOP, START };
	Direction direction;
};
#endif
