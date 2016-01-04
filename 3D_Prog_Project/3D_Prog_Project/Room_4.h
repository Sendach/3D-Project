#ifndef ROOM_4_H
#define ROOM_4_h

#include "Scene.h"
class Room_4 : public Scene
{
public:
	Room_4(std::shared_ptr<ResourceManager> resource);
	
private:
	void initialize();
	void update(Camera& camera);
	void draw(Camera& camera);
	void createLights();
	//Variables
	glm::mat4 model;
	glm::mat4 view;

	RenderObjects renderObject;
	TransformObjects transformObject;

	std::vector<Light> lightPositions;
	const GLuint nrOfLights = 4;


};
#endif