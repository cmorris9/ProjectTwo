#pragma once
#include <string>
#include <vector>

class Item
{
private:
	std::string ItemName;
	std::vector<Item*> ItemVector;
	bool IsHidden;

public:
	Item();
	Item(std::string ItemName);
	~Item();
	int WeapModifier;
	Item* GenerateItems(int x);
	void ChangeWeapModifier(int x);

	std::string getItemName();


};

