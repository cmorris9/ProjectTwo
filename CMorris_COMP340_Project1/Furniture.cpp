#include "Furniture.h"
#include <string>
#include<vector>
#include <iostream>



Furniture::Furniture(std::string Name) 
{
	std::vector<Item*> HiddenItemVector;
	this->Name = Name;
	this->HiddenItemVector = HiddenItemVector;
}


Furniture::~Furniture()
{

}

std::string Furniture::getFurnName()
{
	return this->Name;
}

void Furniture::AddFurnItems(Item* item2Add)
{
	this->HiddenItemVector.push_back(item2Add);
}

std::vector<Item*> Furniture::FindHiddenItems()
{
	return this->HiddenItemVector;
}

Item* Furniture::getHiddenItem(std::string itemToTake)
{
	int x = 0;

	for (Item* s : HiddenItemVector) {
		x = x + 1;
		if (s->getItemName() == itemToTake)
			return s;
	}
	return this->HiddenItemVector[x];

}

void Furniture::PrintHiddenItems()
{
	int x = 0;
	for (Item* s : HiddenItemVector) {
		std::cout << "Item #" << x << ": ";
		std::cout << s->getItemName() << "\t" << std::endl;
		x += 1;
	}
}