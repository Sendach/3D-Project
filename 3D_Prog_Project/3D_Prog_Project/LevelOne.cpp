#include "LevelOne.h"
#include "Main_Building.h"
#include "Room_Doors.h"
#include "Room_1.h"
#include "Room_2.h"
#include "Room_3.h"
#include "Room_4.h"
#include "Game_Room_1.h"
#include "Game_Room_2.h"
#include "Game_Room_3.h"
#include "Winning_Room.h"
#include "Door.h"

LevelOne::LevelOne(std::shared_ptr<ResourceManager> resource)
{
	this->resource = resource;

	std::shared_ptr<Door> door = std::make_shared<Door>(this->resource);
	LevelOneGameObjects.push_back(std::make_shared<Room_1>(this->resource));
	LevelOneGameObjects.push_back(std::make_shared<Room_Doors>(this->resource));
	LevelOneGameObjects.push_back(std::make_shared<Main_Building>(this->resource));
	LevelOneGameObjects.push_back(std::make_shared<Room_2>(this->resource));
	LevelOneGameObjects.push_back(std::make_shared<Room_3>(this->resource));
	LevelOneGameObjects.push_back(std::make_shared<Room_4>(this->resource));
	LevelOneGameObjects.push_back(std::make_shared<Game_Room_1>(this->resource));
	LevelOneGameObjects.push_back(std::make_shared<Game_Room_2>(this->resource));
	LevelOneGameObjects.push_back(std::make_shared<Game_Room_3>(this->resource));
	LevelOneGameObjects.push_back(std::make_shared<Winning_Room>(this->resource));

	

}
void LevelOne::update(Camera& camera)
{
	for (auto& gameObjects : LevelOneGameObjects)
	{
		gameObjects->update(camera);
	}

	
}

void LevelOne::render(Camera& camera)
{

	for (auto& gameObjects : LevelOneGameObjects)
	{
		gameObjects->draw(camera);
	}
}