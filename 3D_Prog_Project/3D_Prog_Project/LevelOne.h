#ifndef LEVELONE_H
#define LEVELONE_H
//Includes
#include <memory>
#include <vector>
//Glew
#define GLEW_STATIC
#include <gl\glew.h>
//Objects
#include "ResourceManager.h"
#include "Scene.h"




class LevelOne
{
public:
	LevelOne(std::shared_ptr<ResourceManager> resource);
	void update(Camera& camera);
	void render(Camera& camera);
private:
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
	//Vector of game objects
	std::vector<std::shared_ptr<Scene>> LevelOneGameObjects;

	
	
};
#endif
