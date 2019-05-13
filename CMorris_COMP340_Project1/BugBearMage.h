#pragma once
#include "GameCharacter.h"

class BugBearMage : public GameCharacter
{
private:
	std::string Name;
public:
	BugBearMage(std::string Name, int HitPoints);
	~BugBearMage();
	void SubtractDamage(int x);
};