#ifndef GAME_ROOM_3_H
#define GAME_ROOM_3_H

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

class Game_Room_3 : public Scene
{
public:
	Game_Room_3(std::shared_ptr<ResourceManager> resource);
	~Game_Room_3() {}

	void update(Camera& camera);
	void draw(Camera& camera);
	void initialize();
	void room3Controls(float delta, Camera& camera);

	std::string answer;
	float movementSpeed;
	int amountOfChances;
	int chances;
	enum class Direction { FORWARD, BACKWARDS, LEFT, RIGHT, UP, DOWN, STOP, START };
	Direction direction;
};
#endif
