#ifndef SETTEXTURES_H
#define SETTEXTURES_H

#include "ResourceManager.h"
#include <memory>

class SetTextures
{
public:
	SetTextures(std::shared_ptr<ResourceManager> resource) { this->resource = resource; }
	void setupTexture();
private:
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
};
#endif
