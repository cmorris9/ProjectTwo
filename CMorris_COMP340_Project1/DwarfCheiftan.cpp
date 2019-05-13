#include "DwarfCheiftan.h"
#include "GameCharacter.h"


DwarfCheiftan::DwarfCheiftan(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 4;
}

DwarfCheiftan::~DwarfCheiftan()
{
}

void DwarfCheiftan::SubtractDamage(int x) {
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}