#include<sstream>
#include "Combat.h"
#include "GameCharacter.h"
#include "User.h"
#include "Room.h"
#include <iostream>
#include <cstdlib> 






Combat::Combat(User* PlayerOne)
{
	this->PlayerOne = PlayerOne;
}


Combat::~Combat()
{
}

void Combat::CombatCheck(Room* currentRoom, std::string userInput)
{
	//Check if room enemy list is greater than 0, if so engage combat
	std::vector<GameCharacter*> TestList = currentRoom->getRoomEnemies();
	if (TestList.size() > 0)
		StartFight(currentRoom, userInput);
	
}

void Combat::StartFight(Room* currentRoom, std::string userInput)
{
	//engaging in combat with enemy
	std::string userInput1 = "";
	std::cout << "AN enemy " + currentRoom->RoomEnemies[0]->GetName();
	std::cout << " Jumps out at you!!!!!!!!!!!!!!!\n";
	PlayerOne = this->PlayerOne;
	std::vector<GameCharacter*>EnemyList = currentRoom->RoomEnemies;
	int EnemyHP = EnemyList[0]->HitPoints;

	while (PlayerOne->HitPoints > 0 && EnemyHP > 0)
	{
		
		std::vector<std::string> Commands;
		std::cout << "You are now fighting! Select what combat Action to use!\n";
		std::getline(std::cin, userInput1);
		std::istringstream iss(userInput1);
		std::string word;
		while (iss >> word)
		{
			Commands.push_back(word);
		}
		
		if (Commands.size() > 1 && Commands[1] == "item")
		{
			std::string userInput2 = "";
			std::cout << "You use a weapon!\n";
			std::cout << "Which would you like to use?\n";
			std::getline(std::cin, userInput2);
			int ItemIndex = PlayerOne->RetreiveFromSatchel(userInput2);
			if (ItemIndex < 0)
			{
				std::cout << "You cannot find this item anywhere!\n";
				break;
			}
			Item* CurrentItem = PlayerOne->getSatchelItem(ItemIndex);
			std::cout << "You deal a devastating blow with the ";
			std::cout << CurrentItem->getItemName();
			std::cout << " dealing out " + std::to_string(CurrentItem->WeapModifier);
			std::cout << " damage!!!\n";
			EnemyHP = EnemyHP - (CurrentItem->WeapModifier);
			std::cout << "Rem. HP: " + std::to_string(EnemyHP);
			std::cout << " \n";
		}
		else if (Commands.size() > 1 && Commands[1] == "hands")
		{
			//simple hand combat will only remove constant damage each time
			std::cout << "With your bare hands you begin to pummel the enemy ";
			std::cout << " dealing out " + std::to_string(2);
			std::cout << " damage!!!\n";
			EnemyHP = EnemyHP - 2;
			std::cout << "Rem. HP: " + std::to_string(EnemyHP);
			std::cout << " \n";
		}
		else if (Commands.size() > 1 && Commands[1] == "dash")
		{
			//will disengage the enemy and leave the player standing in the same room, if they do not leave immediatly
			//they will be engaged again in combat with the same enemy
			std::cout << "You run!\n";
			std::cout << " \n";
			break;

		}
		else
			continue;
			
		if (Commands.size() > 1 && EnemyHP > 0)
		{
			//If enemy health isnt 0 at his turn, then he will deal damage
			std::cout << "Still standing the " << EnemyList[0]->GetName();
			std::cout << "slashes back at you and deals " + std::to_string(EnemyList[0]->AttckDmg);
			std::cout << " damage!\n";
			PlayerOne->SubtractDamage(EnemyList[0]->AttckDmg);
			std::cout << std::to_string(PlayerOne->HitPoints) + "\n";
			std::cout << " \n";
		}
		else if (Commands.size() > 1 && EnemyHP < 1)
		{
			//Could use an adjustment, but this just checks to make sure the slain enemy is not the boss, boss gets different
			//cinematic death which can be altered here, currently Red Dragon is this maps boss
			if (currentRoom->RoomEnemies[0]->GetName() != "Red Dragon")
			{
				std::cout << "You have slain the enemy!!\n";
				std::cout << " \n";
				currentRoom->RoomEnemies.clear();
			}
			else
			{
				std::cout << "The red dragon lets out an unearthly shrill!!\n";
				std::cout << "Its eyes roll in the back of his head, and letting out his last breath he smashes into the floor\n";
				std::cout << "You are a hero!!!! And now the game is over\n";


				std::cout << " \n";
				std::cout << "Please exit and feel free to run it again!\n ";
				std::string FinalInput = "";
				//std::cout << "Player Menu: (A) Move (B) Search (C) Take  (D) Display Satchel/Inventory contents  **[Type QUIT to exit]**\n";
				std::getline(std::cin, FinalInput);
				currentRoom->RoomEnemies.clear();
				while (FinalInput != "QUIT")
				{
					if (FinalInput == "QUIT")
					{
						break;
					}
					else
						continue;
				}
				break;
			}
		}
		else
		{
			std::cout << "There was an error with your selection!";
			std::cout << " \n";
		}
	
	}
	if (PlayerOne->HitPoints < 1)
	{
		std::cout << " \n";
		std::cout << "You grasp your chest, looking down at a gaping wound, you realize this is the end\n";
		std::cout << "YOU ARE DEAD......        please exit";
		std::cin.clear(); 
		std::cin.ignore(INT_MAX, '\n');
		std::cin.get();
	}
		
	
}
