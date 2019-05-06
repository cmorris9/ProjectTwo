#pragma once
#include "GameCharacter.h"
class BullyWugCheiftan : public GameCharacter
{
private:
	std::string Name;

public:
	int HitPoints;
	int AttckDamage;
	BullyWugCheiftan(std::string Name, int HitPoints);
	void SubtractDamage(int x);

	~BullyWugCheiftan();
};

