#include "GiantCheiftan.h"
#include "GameCharacter.h"


GiantCheiftan::GiantCheiftan(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 4;
}

GiantCheiftan::~GiantCheiftan()
{
}

void GiantCheiftan::SubtractDamage(int x) {
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}