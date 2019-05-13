#pragma once
#include "GameCharacter.h"

class GiantCheiftan : public GameCharacter
{
private:
	std::string Name;
public:
	GiantCheiftan(std::string Name, int HitPoints);
	~GiantCheiftan();
	void SubtractDamage(int x);
};