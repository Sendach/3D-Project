#include "SetProjection.h"


SetProjection::SetProjection(std::shared_ptr<ResourceManager> resource) 
{ 
	this->resource = resource; 

	projection = glm::perspective(45.0f, 1600.0f / 900.0f, 0.1f, 3000.0f);
}

void SetProjection::setProjection()
{
	resource->getShader("Main_Building").use();
	resource->getShader("Main_Building").setMatrix4fv("projection", this->projection);

	resource->getShader("Room_Doors").use();
	resource->getShader("Room_Doors").setMatrix4fv("projection", this->projection);

	resource->getShader("Room_1").use();
	resource->getShader("Room_1").setMatrix4fv("projection", this->projection);

	resource->getShader("Main_Building_Light").use();
	resource->getShader("Main_Building_Light").setMatrix4fv("projection", this->projection);

	resource->getShader("Room_1_Light").use();
	resource->getShader("Room_1_Light").setMatrix4fv("projection", this->projection);

	resource->getShader("Room_1_Shadow_Mapping_Depth").use();
	resource->getShader("Room_1_Shadow_Mapping_Depth").setMatrix4fv("projection", this->projection);

	resource->getShader("Room_2").use();
	resource->getShader("Room_2").setMatrix4fv("projection", this->projection);

	resource->getShader("Normal_Mapping").use();
	resource->getShader("Normal_Mapping").setMatrix4fv("projection", this->projection);

	resource->getShader("GameRoom").use();
	resource->getShader("GameRoom").setMatrix4fv("projection", this->projection);

	resource->getShader("Quad").use();
	resource->getShader("Quad").setMatrix4fv("projection", this->projection);

	resource->getShader("Room_3").use();
	resource->getShader("Room_3").setMatrix4fv("projection", this->projection);

	resource->getShader("Room_3_Quad").use();
	resource->getShader("Room_3_Quad").setMatrix4fv("projection", this->projection);

	resource->getShader("Room_4").use();
	resource->getShader("Room_4").setMatrix4fv("projection", this->projection);

	resource->getShader("Deferred_Light_Cubes").use();
	resource->getShader("Deferred_Light_Cubes").setMatrix4fv("projection", this->projection);
}