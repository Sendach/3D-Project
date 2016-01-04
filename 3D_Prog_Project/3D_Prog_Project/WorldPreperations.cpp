#include "WorldPreperations.h"

WorldPreperations::WorldPreperations(std::shared_ptr<ResourceManager> resource)
{
	this->resource = resource;
	_setShader = std::make_shared<SetShaders>(resource);
	_setTexture = std::make_shared<SetTextures>(resource);
	_setModels = std::make_shared<SetModels>(resource);
	_setProjection = std::make_shared<SetProjection>(resource);
	_setFBO = std::make_shared<SetFBO>(resource);
}

void WorldPreperations::setupWorld()
{
	_setShader->setupShaders();
	_setTexture->setupTexture();
	_setModels->setupModels();
	_setProjection->setProjection();
	_setFBO->setFbo();
}