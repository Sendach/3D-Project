#ifndef FBOCACHE_H
#define FBOCACHE_H

#include "FrameBufferObject.h"

#include <string>
#include <map>
class FBOCache
{
public:
	void setupFBO(int shadow_Width, int shadow_Height, std::string FBOName);
	FrameBufferObject& getFBO(std::string name);
private:
	std::map<std::string, FrameBufferObject> _frameBufferObjects;

};
#endif
