#ifndef SETMODELS_H
#define SETMODELS_H

#include "ResourceManager.h"
#include <memory>

class SetModels
{
public:
	SetModels(std::shared_ptr<ResourceManager> resource) { this->resource = resource; }
	void setupModels();

private:
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
};
#endif

