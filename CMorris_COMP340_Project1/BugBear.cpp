#include "BugBear.h"
#include "GameCharacter.h"



BugBear::BugBear(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 4;
}


BugBear::~BugBear()
{

}

void BugBear::SubtractDamage(int x)
{
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}