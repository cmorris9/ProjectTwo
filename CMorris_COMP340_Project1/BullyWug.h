#pragma once
#include "GameCharacter.h"
class BullyWug : public GameCharacter
{
private:
	std::string Name;
	
public:
	int HitPoints;
	int AttckDamage;
	BullyWug(std::string Name, int HitPoints);
	void SubtractDamage(int x);

	~BullyWug();
};

