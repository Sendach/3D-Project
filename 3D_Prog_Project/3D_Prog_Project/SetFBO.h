#ifndef SETFBO_H
#define SETFBO_H

#include "ResourceManager.h"
#include <memory>


class SetFBO
{
public:
	SetFBO(std::shared_ptr<ResourceManager> resource) { this->resource = resource; };
	void setFbo();
private:
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
};
#endif
