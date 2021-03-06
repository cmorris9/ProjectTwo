#include "User.h"
#include<sstream>
#include"Combat.h"
#include"Items.h"




User::User(std::string Name, int HitPoints, std::vector<Item*> PlayerSatchel) : GameCharacter(Name, HitPoints)
{
	this->PlayerSatchel = PlayerSatchel;
	this->HitPoints = HitPoints;
}


User::~User()
{

}


void User::Take(Item* RoomItem) 
{

	this->PlayerSatchel.push_back(RoomItem);
	std::cout << "You added " + RoomItem->getItemName();
	std::cout << " \n";

}



void User::SearchRoom(Room* CurrentRoom, std::string FurnItemToSearch)
{
	std::vector<Item*> ItemsToFind = CurrentRoom->getRoomItemsVector(FurnItemToSearch);
	if (ItemsToFind.size() > 0)
	{
		int x = 0;
		for (Item* s : ItemsToFind)
		{
			CurrentRoom->setVisibleItems(s);
			std::cout << "You Found a ";
			std::cout << s->getItemName() << "\t" << std::endl;
			std::cout << "\n";

		}
	}
	else
	{
		std::cout << "You are either going blind or nothings here!\n";
		std::cout << "\n";

	}
	//std::vector<Item*> CurrentItems;
	//CurrentRoom->PrintRoomItems();
	//CurrentItems = CurrentRoom->getRoomItemsVector();
}

void User::DisplaySatchelContents()
{
	int x = 0;
	if (PlayerSatchel.size() == 0)
	{
		std::cout << "You have no items in your satchel!\n";
		std::cout << "\n";
	}
	else
	{
		for (Item* s : PlayerSatchel) {
			std::cout << "Inventory #: " << x << s->getItemName() << std::endl;
			x += 1;
		}
	}
}

int User::RetreiveFromSatchel(std::string Items)
{
	int x = 0;

	for (Item* s : PlayerSatchel) {

		if (s->getItemName() == Items)
		{

			return x;

		}
		x = x + 1;
	}
	return -1;
}

Item* User::getSatchelItem(int index)
{
	return this->PlayerSatchel[index];
}

void User::Attack(GameCharacter* enemy)
{

}

void User::SubtractDamage(int x)
{
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}


void User::PlayerMenu(Room* currentRoom, std::string userInput)
{
	//starting point
	std::string userInput2 = "";
	
	while (userInput != "QUIT") {
		std::vector<std::string> Commands;
		std::cout << currentRoom->getDescription() << std::endl;
		std::cout << " \n";
		Combat* InitCombat = new Combat(this);
		InitCombat->CombatCheck(currentRoom, userInput);

		if (currentRoom != nullptr) {
			//std::cout << currentRoom->getDescription() << std::endl;

			std::cout << "What Would You Like To Do?\n ";
			//std::cout << "Player Menu: (A) Move (B) Search (C) Take  (D) Display Satchel/Inventory contents  **[Type QUIT to exit]**\n";
			std::getline(std::cin, userInput2);
			std::istringstream iss(userInput2);
			std::string word;
			while (iss >> word)
			{
				Commands.push_back(word);
			}
			

			if (Commands[0] == "move" && Commands.size() > 1)
			{
				//std::getline(std::cin, userInput);
				currentRoom = currentRoom->getRoom(Commands[1]);
			}
			else if (Commands[0] == "search" && Commands.size() > 1)
			{
				currentRoom->PrintRoomItems();
				SearchRoom(currentRoom, Commands[1]);
			
			}
			else if (Commands[0] == "take" && Commands.size() > 1)
			{
				//std::cout << "HiddenItems: \n";
				//currentRoom->PrintRoomItems();
				//std::cout << "What Items Would You Like To Take? (Enter Integer Item #)\n";
				//std::getline(std::cin, userInput);
				int CurrentRoomItem = currentRoom->FindVisibleItems(Commands[1]);
				Take(currentRoom->GetItemFromItemVector(CurrentRoomItem));
			


			}
			else if (Commands[0] == "help")
			{
				std::cout << " \n";
				std::cout << "Typed Command examples (all lowercase): 'move south', 'satchel', 'search' 'chair', 'take dagger'.\n";
				std::cout << "Typed Combat Command examples (all lowercase): 'use item', 'use hands', 'use dash'.\n";
				std::cout << "In Combat, once 'use item' is selected, type the satchel item you want to use, example 'dagger'.\n";
				std::cout << " \n";


			}
			else if (Commands[0] == "satchel")
			{
				std::cout << " \n ";
				DisplaySatchelContents();

				std::cout << "\nSelect Item from your satchel or type 'close'\n";
				std::getline(std::cin, userInput2);

				int ItemIndex = RetreiveFromSatchel(userInput2);

				if (ItemIndex < 0)
				{
					std::cout << "You cannot find this item anywhere!\n";
					break;
				}
				else
				{
					Item* CurrentItem = this->getSatchelItem(ItemIndex);
					std::cout << "From your satchel you retreive a " + CurrentItem;

				}


			}
			else if (Commands[0] == "QUIT")
				break;
			else
				std::cout << "Do not recognize command, type 'help' if stuck\n";
				continue;
			Commands.clear();

			//currentRoom->PrintRoomItems();
			//Now instead of printing it, retrieve the items, display them with an index, and put in satchel if index selected

			//Check for enemies in room. Can hide enemies behind objects and suprise user
			// Or we can make the enemies immediatly visible in room. 
		

		}
	
	}
}
