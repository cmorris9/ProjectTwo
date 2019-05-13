//Room Class

#include "Room.h"
#include "Items.h"
#include <iostream>



Room::Room(std::string description)
{
	this->description = description;
}


Room::~Room()
{
}

std::string Room::getDescription() {
	return this->description;
}

void Room::PrintRoomItems() {
	int x = 0;
	for (Item* s : VisibleItems) {
		std::cout << "Item # " << x << ": ";
		std::cout << s->getItemName() << "\t" << std::endl;
		x += 1;
	}

}

Item* Room::GetItemFromItemVector(int x)
{
	Item* ItemToReturn = this->VisibleItems[x];
	this -> VisibleItems.pop_back();
	return ItemToReturn;

}

void Room::setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom) {
	this->northRoom = northRoom;
	this->southRoom = southRoom;
	this->eastRoom = eastRoom;
	this->westRoom = westRoom;
}

void Room::setRoomFurniture(Furniture* AddFurn) {
	this->RoomFurniture.push_back(AddFurn);

}

void Room::PrintFurniture() 
{
	
	int x = 0;
	for (Furniture* f : RoomFurniture) {
		std::cout << "Item # " << x << ": ";
		std::cout << f->getFurnName() << "\t" << std::endl;
		x += 1;
	}
}


Room* Room::getRoom(std::string direction) {
	if (direction == "north" && this->northRoom != nullptr) {
		return this->northRoom;
	}
	else if (direction == "east" && this->eastRoom != nullptr) {
		return this->eastRoom;
	}
	else if (direction == "south" && this->southRoom != nullptr) {
		return this->southRoom;
	}
	else if (direction == "west" && this->westRoom != nullptr) {
		return this->westRoom;
	}
	else {
		return this;
	}
}

void Room::setItemsInFurn(std::vector<Item*> items2Add)
{
	for (int i = 0; i < items2Add.size(); i++) {
		this->RoomFurniture.at(i)->AddFurnItems(items2Add.at(i));
	}

}

void Room::setVisibleItems(Item* item2Add)
{
	
	this->VisibleItems.push_back(item2Add);
}

void Room::setRoomEnemies(GameCharacter* testEnemy)
{
	
	this->RoomEnemies.push_back(testEnemy);
}

std::vector<GameCharacter*> Room::getRoomEnemies() {
	return this->RoomEnemies;

}

std::vector<Item*> Room::getRoomItemsVector(std::string FurnName)
{
	std::vector<Item*> EmptyList;
	for (Furniture* f : RoomFurniture)
	{
		
		if (FurnName == f->getFurnName())
		{
			EmptyList = f->HiddenItemVector;
			f->HiddenItemVector.clear();

		}
		else
		{
	
			return EmptyList;
		}

	}
	return EmptyList;
}

int Room::FindVisibleItems(std::string itemToTake)
{
	int x = 0;

	for (Item* s : VisibleItems) {

		if (s->getItemName() == itemToTake)
		{
			
			return x;

		}
		x = x + 1;
	}
	return -1;

}

void Room::PrintFurnitureItems(int x)
{
	std::vector<Furniture*> FList = this->RoomFurniture;
	Furniture* SelectedFurn = this->RoomFurniture[x];
	std::vector<Item*> IList = SelectedFurn->FindHiddenItems();
	if (IList.size() > 0)
	{
		int x = 0;
		for (Item* s : IList)
		{
			std::cout << "Item #" << x << ": ";
			std::cout << s->getItemName() << "\t" << std::endl;
			x += 1;
		}
	}
	else
		std::cout << "You found no Items!";
	
}