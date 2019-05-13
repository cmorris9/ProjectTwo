#include "BullyWugMage.h"
#include "GameCharacter.h"


BullyWugMage::BullyWugMage(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 2;
}

BullyWugMage::~BullyWugMage()
{
}

void BullyWugMage::SubtractDamage(int x) {
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}