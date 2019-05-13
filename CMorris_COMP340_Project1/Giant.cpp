#include "Giant.h"
#include "GameCharacter.h"


Giant::Giant(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 3;
}

Giant::~Giant()
{
}

void Giant::SubtractDamage(int x) {
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}