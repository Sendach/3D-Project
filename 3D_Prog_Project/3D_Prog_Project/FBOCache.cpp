#include "FBOCache.h"

void FBOCache::setupFBO(int shadow_Width, int shadow_Height, std::string FBOName)
{
	auto FBOiterator = _frameBufferObjects.find(FBOName);

	if (FBOiterator == _frameBufferObjects.end())
	{
		FrameBufferObject fbo;

		if (FBOName[0] != 'g')
		{
			fbo.createDepthMap(shadow_Width, shadow_Height);
		}
		else {
			fbo.createGBuffer(shadow_Width, shadow_Height);
		}
		
		_frameBufferObjects.insert(make_pair(FBOName, fbo));
	}
}

FrameBufferObject& FBOCache::getFBO(std::string name)
{
	return _frameBufferObjects[name];
}
