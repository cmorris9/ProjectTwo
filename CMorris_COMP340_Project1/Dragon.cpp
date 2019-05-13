#include "Dragon.h"
#include "GameCharacter.h"


Dragon::Dragon(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 7;
}

Dragon::~Dragon()
{
}

void Dragon::SubtractDamage(int x) {
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}