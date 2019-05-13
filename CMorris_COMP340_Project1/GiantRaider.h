#pragma once
#include "GameCharacter.h"

class GiantRaider : public GameCharacter
{
private:
	std::string Name;
public:
	GiantRaider(std::string Name, int HitPoints);
	~GiantRaider();
	void SubtractDamage(int x);
};