#pragma once
#include "GameCharacter.h"

class BullyWugMage : public GameCharacter
{
private:
	std::string Name;
public:
	BullyWugMage(std::string Name, int HitPoints);
	~BullyWugMage();
	void SubtractDamage(int x);
};