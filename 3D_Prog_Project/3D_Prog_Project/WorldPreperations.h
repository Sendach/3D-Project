#ifndef WORLDPREPERATIONS_H
#define WORLDPREPERATIONS_H

#include "setShaders.h"
#include "SetTextures.h"
#include "SetModels.h"
#include "SetProjection.h"
#include "SetFBO.h"


class WorldPreperations
{
public:
	
	WorldPreperations(std::shared_ptr<ResourceManager> resource);
	void setupWorld();
private:
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>();
	std::shared_ptr<SetShaders> _setShader;
	std::shared_ptr<SetTextures> _setTexture;
	std::shared_ptr<SetModels> _setModels;
	std::shared_ptr<SetProjection> _setProjection;
	std::shared_ptr<SetFBO> _setFBO;
};
#endif

