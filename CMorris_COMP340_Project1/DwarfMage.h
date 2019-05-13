#pragma once
#include "GameCharacter.h"

class DwarfMage : public GameCharacter
{
private:
	std::string Name;
public:
	DwarfMage(std::string Name, int HitPoints);
	~DwarfMage();
	void SubtractDamage(int x);
};