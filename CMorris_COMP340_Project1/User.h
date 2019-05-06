#pragma once
#include "Items.h"
#include "GameCharacter.h"
#include "Room.h"
#include <vector>
#include <iostream>

class User : public GameCharacter
{
private:
	std::vector<Item*> PlayerSatchel;
public:
	User(std::string Name, int HitPoints, std::vector<Item*> PlayerSatchel);
	int HitPoints;
	~User();
	void Take(Item* RoomItem);
	void Attack(GameCharacter* enemy);
	void PlayerMenu(Room* currentRoom, std::string userInput);
	void SearchRoom(Room* CurrentRoom, std::string FurnItemToSearch);
	int RetreiveFromSatchel(std::string Items);
	void SubtractDamage(int x);

	Item* getSatchelItem(int index);


	void DisplaySatchelContents();



};

