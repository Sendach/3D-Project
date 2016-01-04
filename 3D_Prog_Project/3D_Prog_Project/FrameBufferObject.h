#ifndef FRAMEBUFFEROBJECT_H
#define FRAMEBUFFEROBJECT_H

#define GLEW_STATIC
#include "GL\glew.h"

class FrameBufferObject
{
public:
	void createDepthMap(int shadow_Width, int shadow_Height);
	void createGBuffer(int shadow_Width, int shadow_Height);
	void bindDepthMap();
	void bindGBuffer();

	GLuint depthMapFBO;
	GLuint depthMapTexture;

	GLuint gBuffer;
	GLuint gPosition, gNormal, gAlbedoSpec;
};
#endif
