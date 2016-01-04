#include "setShaders.h"

void SetShaders::setupShaders()
{
	resource->_shaderCache.setupShader("Shaders/Main_Building/Main_Building.vs", nullptr, "Shaders/Main_Building/Main_Building.fs", "Main_Building");
	resource->_shaderCache.setupShader("Shaders/Doors/Room_Doors.vs", nullptr, "Shaders/Doors/Room_Doors.fs", "Room_Doors");
	resource->_shaderCache.setupShader("Shaders/Room_1/Room_1.vs", nullptr, "Shaders/Room_1/Room_1.fs", "Room_1");
	resource->_shaderCache.setupShader("Shaders/Main_Building/Main_Building_Light.vs", nullptr, "Shaders/Main_Building/Main_Building_Light.fs", "Main_Building_Light");
	resource->_shaderCache.setupShader("Shaders/Room_1/Room_1_Light.vs", nullptr, "Shaders/Room_1/Room_1_Light.fs", "Room_1_Light");
	resource->_shaderCache.setupShader("Shaders/Room_1/Room_1_Shadow_Mapping_Depth.vs", nullptr, "Shaders/Room_1/Room_1_Shadow_Mapping_Depth.fs", "Room_1_Shadow_Mapping_Depth");
	resource->_shaderCache.setupShader("Shaders/Room_2/Room_2.vs", nullptr, "Shaders/Room_2/Room_2.fs", "Room_2");
	resource->_shaderCache.setupShader("Shaders/Room_2/Normal_Mapping.vs", nullptr, "Shaders/Room_2/Normal_Mapping.fs", "Normal_Mapping");
	resource->_shaderCache.setupShader("Shaders/GameRoom/GameRoom.vs", nullptr, "Shaders/GameRoom/GameRoom.fs", "GameRoom");
	resource->_shaderCache.setupShader("Shaders/Quads.vs", nullptr, "Shaders/Quads.fs", "Quad");
	resource->_shaderCache.setupShader("Shaders/Room_3/Room_3.vs", nullptr, "Shaders/Room_3/Room_3.fs", "Room_3");
	resource->_shaderCache.setupShader("Shaders/Room_3/Room_3_Quad.vs", "Shaders/Room_3/Room_3_Quad.gs", "Shaders/Room_3/Room_3_Quad.fs", "Room_3_Quad");

	resource->_shaderCache.setupShader("Shaders/Room_4/Room_4.vs", nullptr, "Shaders/Room_4/Room_4.fs", "Room_4");
	resource->_shaderCache.setupShader("Shaders/Room_4/Deferred_Light_Cubes.vs", nullptr, "Shaders/Room_4/Deferred_Light_Cubes.fs", "Deferred_Light_Cubes");
	resource->_shaderCache.setupShader("Shaders/Room_4/gBuffer.vs", nullptr, "Shaders/Room_4/gBuffer.fs", "gBuffer");
}
