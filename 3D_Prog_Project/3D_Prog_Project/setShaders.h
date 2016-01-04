#ifndef SETSHADERS_H
#define SETSHADERS_H

#include "ResourceManager.h"
#include <memory>

class SetShaders
{
public:
	SetShaders(std::shared_ptr<ResourceManager> resource) { this->resource = resource; }
	 void setupShaders();
private:
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
};
#endif
