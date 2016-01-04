#ifndef MAIN_BUILDING_H
#define MAIN_BUILDING_H

#include "Scene.h"

class Main_Building : public Scene
{
public:
	Main_Building(std::shared_ptr<ResourceManager> resource);
private:
	//Fumnctions
	void update(Camera& camera);
	void draw(Camera& camera);

	//Variables
	glm::mat4 model;
	TransformObjects transformObject;
	RenderObjects renderObjects;
};
#endif
