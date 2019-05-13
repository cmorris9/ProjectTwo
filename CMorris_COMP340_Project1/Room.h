//Room Class

#pragma once
#include "items.h"
#include "BullyWug.h"
#include"Furniture.h"
#include <string>
#include <vector>

class Room
{
public:
	//These only pertain to Navigation
	Room(std::string description);
	~Room();
	std::string getDescription();
	void setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);
	Room* getRoom(std::string direction);

	//Adding item
	void setRoomFurniture(Furniture* AddFurn);
	void PrintFurniture();
	void setItemsInFurn(std::vector<Item*> item2Add);
	void setVisibleItems(Item* item2Add);
	void PrintRoomItems();
	void PrintFurnitureItems(int x);
	Item* GetItemFromItemVector(int x);
	int FindVisibleItems(std::string itemToTake);
	std::vector<Item*> getRoomItemsVector(std::string FurnName);

	std::vector<GameCharacter*> RoomEnemies;

	void setRoomEnemies(GameCharacter* testEnemy);
	std::vector<GameCharacter*> getRoomEnemies();


private:
	// These only pertain to navigation
	Item* testItem;
	Furniture* testFurn;
	std::vector<Furniture*> RoomFurniture;
	std::vector<Item*> VisibleItems;

	std::string description;
	Room* northRoom;
	Room* eastRoom;
	Room* southRoom;
	Room* westRoom;
	//First adding item	
};
