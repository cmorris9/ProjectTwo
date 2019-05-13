#pragma once
#include "GameCharacter.h"

class DwarfCheiftan : public GameCharacter
{
private:
	std::string Name;
public:
	DwarfCheiftan(std::string Name, int HitPoints);
	~DwarfCheiftan();
	void SubtractDamage(int x);
};