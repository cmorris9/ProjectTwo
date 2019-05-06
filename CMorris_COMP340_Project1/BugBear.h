#pragma once
#include "GameCharacter.h"

class BugBear : public GameCharacter
{
private:
	std::string Name;
public:
	BugBear(std::string Name, int HitPoints);
	~BugBear();
	void SubtractDamage(int x);
};

