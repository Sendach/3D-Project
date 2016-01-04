#ifndef WORLD_H
#define WORLD_H

//Glew
#define GLEW_STATIC
#include <GL/glew.h>
//Class Includes
#include "ResourceManager.h"
//Other Includes
#include <memory>
#include "WorldPreperations.h"
#include "LevelOne.h"
class World
{
public:
	World(){}
	World(std::shared_ptr<ResourceManager> resource);
	~World() {};
	void initialize();
	void update(Camera& camera);
	void render(Camera& camera);

private:
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
	std::shared_ptr<WorldPreperations> prepare;
	std::shared_ptr<LevelOne> levelOne;
};
#endif