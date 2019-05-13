#include "Dwarf.h"
#include "GameCharacter.h"


Dwarf::Dwarf(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 3;
}

Dwarf::~Dwarf()
{
}

void Dwarf::SubtractDamage(int x) {
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}