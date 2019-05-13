#include "GiantRaider.h"
#include "GameCharacter.h"


GiantRaider::GiantRaider(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 2;
}

GiantRaider::~GiantRaider()
{
}

void GiantRaider::SubtractDamage(int x) {
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}