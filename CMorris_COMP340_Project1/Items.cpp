#include "Items.h"
#include <string>
#include <vector>


Item::Item()
{

}

Item::Item(std::string ItemName)
{
	
	this->WeapModifier = 0;
	this->ItemName = ItemName;
	this->IsHidden = false;
}


Item::~Item()
{                      
}

Item* Item::GenerateItems(int x)
{
	
	switch (x)
	{
	case 1:
		this->ItemName = "Sword";
		break;
	case 2:
		this->ItemName = "Health Potion";
		break;
	case 3:
		this->ItemName = "Key";
		break;
	case 4:
		this->ItemName = "Dirty Sock";
		break;
	default:
		this->ItemName = "Dirt";
		break;
	}
	return this;
}

std::string Item::getItemName()
{
	return this->ItemName;
}

void Item::ChangeWeapModifier(int x)
{
	//This will change the weapon modifier to account for spec. attck damage or healing points
	this->WeapModifier = x;
}