#ifndef ROOM_2_H
#define ROOM_2_H

#include "Scene.h"

class Room_2 : public Scene
{
public:
	Room_2(std::shared_ptr<ResourceManager> resource);
private:
	void update(Camera& camera);
	void draw(Camera& camera);
	void initialize();
	
	std::shared_ptr<Light> room_2_Light = std::make_shared<Light>();

	GLuint normal_mapping_VAO;
	GLuint VAO;

	glm::mat4 model;
	glm::mat4 view;

	TransformObjects transformObject;
	RenderObjects renderObject;
};
#endif

