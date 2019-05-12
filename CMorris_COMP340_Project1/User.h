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
	std::vector<Item*> Spellbook; // handles the spell "items" BL(05/12)
public:
	User(std::string Name, int HitPoints, std::vector<Item*> PlayerSatchel, std::vector<Item*> Spellbook);
	int HitPoints;
	~User();
	void Take(Item* RoomItem);
	void Attack(GameCharacter* enemy);
	void PlayerMenu(Room* currentRoom, std::string userInput);
	void SearchRoom(Room* CurrentRoom, std::string FurnItemToSearch);
	int RetreiveFromSatchel(std::string Items);
	void SubtractDamage(int x);

	void GenerateSpells(Item* spells);
	void DisplaySpellbook();
	int RetrieveSpell(std::string Spell);
	Item* getSpell(int Spellindex);

	Item* getSatchelItem(int index);


	void DisplaySatchelContents();



};

