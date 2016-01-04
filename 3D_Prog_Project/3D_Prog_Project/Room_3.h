#ifndef ROOM_3_H
#define ROOM_3_H

#include "Scene.h"
class Room_3 : public Scene
{
public:
	Room_3(std::shared_ptr<ResourceManager> resource) : Scene(resource) {}
	~Room_3() {}

	void initialize();
	void update(Camera& camera);
	void draw(Camera& camera);

	glm::mat4 model;
	glm::mat4 view;

	TransformObjects transformObject;
	RenderObjects renderObject;

};
#endif
