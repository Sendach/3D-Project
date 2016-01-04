#ifndef ROOMS_1_H	
#define ROOMS_1_H

#include "Scene.h"

class Room_1 : public Scene
{
public:
	Room_1(std::shared_ptr<ResourceManager> resource);

private:
	void update(Camera& camera);
	void draw(Camera& camera);

	// Creates a depth Map
	void createDepthMap();

	// Render Scene as usual
	void renderSceneNormalPerspective(Camera& camera);
	// Render Scene Light Perspective
	void renderSceneLightPerspective();

	glm::mat4 lightProjection, lightView;

	GLfloat near_plane, far_plane;

	void initialize();
	//Depth Map Frame Buffer Object
	GLuint depthMapFBO;
	// Texture Width & Height
	const GLuint shadow_Width = 1024, shadow_Height = 1024;

	std::shared_ptr<Light> room_1_Light = std::make_shared<Light>(resource);
	
	//Light Space Matrix
	glm::mat4 lightSpaceMatrix;
	GLuint depthMapTexture;

	int counter;

	glm::mat4 model;
	glm::mat4 view;

	TransformObjects transformObjecT;
	RenderObjects renderObject;
};
#endif
