#include "SetTextures.h"

void SetTextures::setupTexture()
{
	resource->_textureCache.setupTexture("Textures/darkBlueMetal.jpg", "darkBlueMetal");
	resource->_textureCache.setupTexture("Textures/metal_Door.png", "metal_Door");
	resource->_textureCache.setupTexture("Textures/lightBlueMetal.jpg", "lightBlueMetal");
	resource->_textureCache.setupTexture("Textures/wood.jpg", "wood");
	resource->_textureCache.setupTexture("Textures/dark_grey_metal.jpg", "dark_grey_metal");
	resource->_textureCache.setupTexture("Textures/brickwall.jpg", "brickwall");
	resource->_textureCache.setupTexture("Textures/brickwall_normal.jpg", "brickwall_normal");
	resource->_textureCache.setupTexture("Textures/ShadowMapping.png", "ShadowMapping");
	resource->_textureCache.setupTexture("Textures/GameRoomTexture/Question_1.jpg", "Question_1_Room");
	resource->_textureCache.setupTexture("Textures/GameRoomQuestions/Question_1_Text.jpg", "Question_1_Quad");
	resource->_textureCache.setupTexture("Textures/GameRoomTexture/Question_2.jpg", "Question_2_Room");
	resource->_textureCache.setupTexture("Textures/GameRoomQuestions/Question_2_Text.png", "Question_2_Quad");
	resource->_textureCache.setupTexture("Textures/GameRoomTexture/Question_3.jpg", "Question_3_Room");
	resource->_textureCache.setupTexture("Textures/GameRoomQuestions/Question_3_Text.jpg", "Question_3_Quad");
	resource->_textureCache.setupTexture("Textures/GameRoomTexture/Winning_Room.jpg", "Winning_Room");
	resource->_textureCache.setupTexture("Textures/desert.jpg", "desert");
	resource->_textureCache.setupTexture("Textures/light_water.jpg", "light_water");
	resource->_textureCache.setupTexture("Textures/Dark_Texture.jpg", "Dark_Texture");
}