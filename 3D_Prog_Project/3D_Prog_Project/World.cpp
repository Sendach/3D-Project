#include "World.h"

World::World(std::shared_ptr<ResourceManager> resource)
{
	this->resource = resource;
	prepare = std::make_shared<WorldPreperations>(this->resource);
	levelOne = std::make_shared<LevelOne>(this->resource);
}

void World::initialize()
{
	prepare->setupWorld();
}

void World::update(Camera& camera)
{
	levelOne->update(camera);
}

void World::render(Camera& camera)
{
	levelOne->render(camera);
}