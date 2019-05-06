#pragma once
#include <vector>
#include "Items.h"

class Furniture
{
private:
	std::string Name;
	

public:
	std::vector<Item*> HiddenItemVector;
	void PrintHiddenItems();
	Furniture(std::string Name);
	~Furniture();
	void AddFurnItems(Item* item2Add);
	std::string getFurnName();
	std::vector<Item*> FindHiddenItems();
	Item* getHiddenItem(std::string itemToTake);


};

