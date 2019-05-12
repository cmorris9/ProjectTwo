//The starting main file written by Professor Esteves

#include <list>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Items.h"
#include "BullyWug.h"
#include "BullwugCheiftan.h"
#include "BugBear.h"
#include "BugBearRaider.h"
#include "User.h"
#include "Dragon.h"

int main() {
	std::vector<Item*> Satchel;

	User* PlayerOne = new User("PlayerOne", 40, Satchel);
	std::vector<Room*> rooms;
	std::vector<Item*> Items;
	Room* currentRoom = nullptr;
	std::string userInput = "";
	std::string userInput2 = "";

	//room description design
	rooms.push_back(new Room(" The room reeks of fire and burnt flesh. Bones and debris litter the floor and only a single chair sit in front of you.\n Two large damaged doors sit closed to your east and west. "));
	rooms.push_back(new Room("Opening the door a giant low, oblong pile of rubble lie near the center of this small room.\n You notice a shiny object underneath the top surface. The pile resembles cairns used to bury dead adventurers. Doors sit to the south and west. "));
	rooms.push_back(new Room("The east door to this room swings open easily on well-oiled hinges. Beyond it you see that the chamber walls have been disguised by wood paneling.\n A torn, well stuffed seat lay in the south corner of the room along with a small table in front. A hallway enterance can be seen to the south "));
	rooms.push_back(new Room("You open the south door to a torture chamber. Several devices of degradation, pain, and death stand about the room,\n all of them showing signs of regular use. The wood of the rack is worn smooth by struggling bodies,\n and the iron maiden appears to be occupied by a corpse. An open bookcase exposes a doorway to the west "));
	rooms.push_back(new Room("A long hallway with only a north and south enterance you see a semitranslucent figure hang in the air, studded with crossbow bolts\n and with blood pouring from every wound. It reaches toward you in a pleading gesture, points to the south opening,\n and then vanishes. Once it has gone, you notice a chest sitting on the puddle of blood. "));
	rooms.push_back(new Room("When looking into this chamber, you're confronted by a thousand reflections of yourself looking back.\n Mirrored walls set at different angles fill the room. A path seems to wind through the mirrors, although you can't tell where it leads. "));
	rooms.push_back(new Room("This room looks like it was designed by drow. Rusted metal tiles create a huge mosaic of a spider in the floor,\n and grate barrels litter the floor. Chainlink doors can be seen at the south and east. "));
	rooms.push_back(new Room("Thick cobwebs fill the corners of the room, immediatly 3 enterance ways can be seen, two of which to the east and west.\n Wisps of webbing hang from the ceiling and waver in a wind you can barely feel. At the south corner of the ceiling\n has a particularly large clot of webbing within which a goblin's bones are tangled, below which is a door. . "));
	rooms.push_back(new Room("A liquid - filled pit extends to every wall of this chamber.The liquid lies about 10 feet below your feet,\n and is so murky that you can't see its bottom. The room smells sour. A rope bridge extends from your door on the north side\n to the room's other exit at the south. "));
	rooms.push_back(new Room("You poke your head through a monsterous oak door, and look upon a room of titanic size. It is clearly an enormous mausoleum built to the proportions of giants.\n Huge niches are set into the walls within which you can discern giant bones.\n Stern-looking statues of stone giants stand 20 feet tall against the walls, and in the center of the room lies a 15-foot-long sarcophagus.  "));



	//Creating all the furniture objects that will hold item vectors
	Furniture* chair = new Furniture("chair");
	Furniture* table = new Furniture("table");
	Furniture* pile = new Furniture("pile");
	Furniture* seat = new Furniture("seat");
	Furniture* devices = new Furniture("device");
	Furniture* corpse = new Furniture("corpse");
	Furniture* bookcase = new Furniture("bookcase");
	Furniture* chest = new Furniture("chest");
	Furniture* grating = new Furniture("grating");
	Furniture* webs = new Furniture("webs");





	//creataing the items that will be hidden in the furniture objects
	Item* sword = new Item("sword");
	sword->ChangeWeapModifier(12);
	Item* spear = new Item("spear");
	spear->ChangeWeapModifier(7);
	Item* dagger = new Item("dagger");
	dagger->ChangeWeapModifier(2);
	Item* bible = new Item("bible");
	bible->ChangeWeapModifier(0);
	Item* rock = new Item("rock");
	rock->ChangeWeapModifier(1);
	Item* goldCoins = new Item("Gold Coins");
	goldCoins->ChangeWeapModifier(0);
	Item* BattleAxe = new Item("BattleAxe");
	BattleAxe->ChangeWeapModifier(10);

	//creating some of our enemy objects to put in the room
	BullyWug* Bully = new BullyWug("BullyWug", 10);
	BullyWugCheiftan* BullywugCheiftan = new BullyWugCheiftan("BullyWug Cheif", 18);
	BugBearRaider* BugRaider = new BugBearRaider("BugBear Raider", 25);
	BugBear* Bug = new BugBear("BugBear", 15);
	Dragon* RedDragon = new Dragon("Red Dragon", 35);


	//designing the map, and setting up the rooms
	//North East South West for set rooms
	rooms[0]->setRooms(nullptr, rooms[1], nullptr, rooms[2]);
	rooms[1]->setRooms(nullptr, nullptr, rooms[3], rooms[0]);
	rooms[2]->setRooms(nullptr, rooms[0], rooms[4], nullptr);
	rooms[3]->setRooms(rooms[1], nullptr, nullptr, rooms[5]);
	rooms[4]->setRooms(rooms[2], rooms[5], rooms[7], rooms[6]);
	rooms[5]->setRooms(nullptr, rooms[3], rooms[9], rooms[4]);
	rooms[6]->setRooms(nullptr, rooms[4], nullptr, rooms[7]);
	rooms[7]->setRooms(nullptr, rooms[4], rooms[8], rooms[6]);
	rooms[8]->setRooms(rooms[7], nullptr, rooms[9], nullptr);
	rooms[9]->setRooms(rooms[8], nullptr, nullptr, nullptr);


	//setting up the furniture items in the room that the items will be hidden in
	rooms[0]->setRoomFurniture(chair);
	rooms[1]->setRoomFurniture(pile);
	rooms[2]->setRoomFurniture(seat);
	rooms[2]->setRoomFurniture(table);
	rooms[3]->setRoomFurniture(devices);
	rooms[3]->setRoomFurniture(corpse);
	rooms[3]->setRoomFurniture(bookcase);
	rooms[4]->setRoomFurniture(chest);
	rooms[6]->setRoomFurniture(grating);
	rooms[7]->setRoomFurniture(webs);
	
	//place the items in the furniture
	rooms[0]->setItemsInFurn(dagger);
	rooms[1]->setItemsInFurn(spear);
	rooms[2]->setItemsInFurn(bible);
	rooms[2]->setItemsInFurn(rock);
	rooms[3]->setItemsInFurn(BattleAxe);
	rooms[3]->setItemsInFurn(sword);
	rooms[3]->setItemsInFurn(dagger);
	rooms[4]->setItemsInFurn(goldCoins);
	rooms[6]->setItemsInFurn(sword);
	rooms[7]->setItemsInFurn(BattleAxe);

	//set the enemies in the rooms
	rooms[3]->setRoomEnemies(Bug);
	rooms[2]->setRoomEnemies(Bully);
	rooms[5]->setRoomEnemies(BugRaider);
	rooms[6]->setRoomEnemies(Bug);
	rooms[8]->setRoomEnemies(BullywugCheiftan);
	rooms[9]->setRoomEnemies(RedDragon);





	std::cout << "Welcome to THE GOOD LOOKING ADVENTURERS: REVENGE OF THE BULLYWUG\n";
	std::cout << "A Text Based adventure game based off true events\n";
	std::cout << "Rated M for Mature\n";
	std::cout << "For commands type 'help' or type 'QUIT' to exit\n ";

	std::cout << "\n";

	std::cout << "As you approach the dark abandoned castle, the smell of whisky and frogs scortches your nostrils\n";
	std::cout << "With only a empty satchel on your back, you pry open the front door and enter the first room\n";
	std::cout << "\n";

	currentRoom = rooms[0];//starting point

	//This holds the event loop which prompts the user with the action menu
	PlayerOne->PlayerMenu(currentRoom, userInput);

	return 0;
}