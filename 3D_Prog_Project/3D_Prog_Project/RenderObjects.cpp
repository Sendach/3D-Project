#include "RenderObjects.h"

void RenderObjects::render(int size)
{
	glDrawArrays(GL_TRIANGLES, 0, size);
}

void RenderObjects::unbind()
{
	glBindVertexArray(0);
}
