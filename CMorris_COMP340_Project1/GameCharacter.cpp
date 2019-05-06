#include "GameCharacter.h"



GameCharacter::GameCharacter(std::string Name, int HitPoints)
{
	this->Name = Name;
	this->HitPoints = HitPoints;
}


GameCharacter::~GameCharacter()
{
}

std::string GameCharacter::GetName()
{
	return this->Name;
}

int GameCharacter::GetHitPoints()
{
	return this->HitPoints;
}

void GameCharacter::SubtractDamage(int x)
{
	int CurrentHitPoints = this->HitPoints;
	int NewHitPoints = CurrentHitPoints - x;
	this->HitPoints = NewHitPoints;
}
