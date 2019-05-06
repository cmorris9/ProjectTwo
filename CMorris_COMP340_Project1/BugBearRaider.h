#pragma once
#include "GameCharacter.h"

class BugBearRaider : public GameCharacter
{
private:
	std::string Name;
public:
	BugBearRaider(std::string Name, int HitPoints);
	~BugBearRaider();
	void SubtractDamage(int x);
};

