#pragma once
#include "User.h"
#include "GameCharacter.h"
#include "Room.h"

class Combat
{
private:
	User* PlayerOne;
	GameCharacter* Enemy;
public:
	Combat(User* PlayerOne);
	~Combat();
	void CombatCheck(Room* currentRoom, std::string userInput);
	void StartFight(Room* currentRoom, std::string userInput);

};

