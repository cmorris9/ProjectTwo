#include "BugBearRaider.h"
#include "GameCharacter.h"

BugBearRaider::BugBearRaider(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 6;
}


BugBearRaider::~BugBearRaider()
{
}

void BugBearRaider::SubtractDamage(int x)
{
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}