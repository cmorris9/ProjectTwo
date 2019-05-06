#pragma once
#include "GameCharacter.h"

class Dragon : public GameCharacter
{
private:
	std::string Name;
public:
	Dragon(std::string Name, int HitPoints);
	~Dragon();
	void SubtractDamage(int x);
};

