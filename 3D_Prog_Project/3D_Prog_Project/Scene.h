#ifndef SCENE_H
#define SCENE_H

//Class Includes
#include "Camera.h"
#include <vector>
#include "ResourceManager.h"
#include <memory>
#include "TransformObjects.h"
#include "Light.h"
#include "RenderObjects.h"

class Scene
{
public:
	Scene(){}
	Scene(std::shared_ptr<ResourceManager> resource) { this->resource = resource; }
	virtual void update(Camera& camera) = 0 ;
	virtual void draw(Camera& camera) = 0;
protected:
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
	
};
#endif
