#include "BullyWug.h"



BullyWug::BullyWug(std::string Name, int HitPoints) : GameCharacter(Name, HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
	this->AttckDmg = 1;
}


BullyWug::~BullyWug()
{

}

void BullyWug::SubtractDamage(int x)
{
	int HP = this->HitPoints;
	int newHP = HP - x;
	this->HitPoints = newHP;
}