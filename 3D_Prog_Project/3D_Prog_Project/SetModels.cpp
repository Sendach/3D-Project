#include "SetModels.h"

void SetModels::setupModels()
{
	resource->_modelCache.setupModel("Models/Metal_Door.obj", "Metal_Door", false);
	resource->_modelCache.setupModel("Models/CrateB.obj", "Crate", false);
	resource->_modelCache.setupModel("Models/Quad.txt", "Quad", false);
	resource->_modelCache.setupModel("Models/Quad.txt", "Quad_Mapping", true);
}
