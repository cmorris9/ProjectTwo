#include "BugBearMage.h"
#include "GameCharacter.h"


BugBearMage::BugBearMage(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 2;
}

BugBearMage::~BugBearMage()
{
}

void BugBearMage::SubtractDamage(int x) {
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}