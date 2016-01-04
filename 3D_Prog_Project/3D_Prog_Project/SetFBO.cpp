#include "SetFBO.h"

void SetFBO::setFbo()
{
	resource->_FBOCache.setupFBO(1024, 1024, "Shadow_Mapping");
	resource->_FBOCache.setupFBO(1900, 1600, "gBuffer");
}
