#ifndef ROOM_DOORS_H
#define ROOM_DOORS_H

#include "Scene.h"

class Room_Doors : public Scene
{
public:
	Room_Doors(std::shared_ptr<ResourceManager> resource);
private:
	//Functions
	void draw(Camera& camera);
	void update(Camera& camera);

	//Variables
	glm::mat4 model;
	glm::mat4 view;

	
	TransformObjects transformObject;
	RenderObjects renderObject;
};
#endif

