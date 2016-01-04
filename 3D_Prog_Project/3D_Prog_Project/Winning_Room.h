#ifndef WINNING_ROOM_H
#define WINNING_ROOM_H

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

class Winning_Room : public Scene
{
public:
	Winning_Room(std::shared_ptr<ResourceManager> resource);
	~Winning_Room() {}

	void update(Camera& camera);
	void draw(Camera& camera);
	void initialize();
	
};
#endif

