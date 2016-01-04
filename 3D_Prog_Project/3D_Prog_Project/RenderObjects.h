#ifndef RENDEROBJECTS_H
#define RENDEROBJECTS_H

//Glew
#define GLEW_STATIC
#include <GL/glew.h>
//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class RenderObjects
{
public:
	void render(int size);
	void unbind();
	
};
#endif
