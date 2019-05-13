#include "DwarfMage.h"
#include "GameCharacter.h"


DwarfMage::DwarfMage(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 2;
}

DwarfMage::~DwarfMage()
{
}

void DwarfMage::SubtractDamage(int x) {
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}