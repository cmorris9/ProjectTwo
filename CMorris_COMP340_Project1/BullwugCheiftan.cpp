#include "BullwugCheiftan.h"
#include "GameCharacter.h"



BullyWugCheiftan::BullyWugCheiftan(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 3;
}


BullyWugCheiftan::~BullyWugCheiftan()
{

}

void BullyWugCheiftan::SubtractDamage(int x)
{
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}