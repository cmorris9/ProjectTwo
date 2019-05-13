#pragma once
#include "GameCharacter.h"

class Dwarf : public GameCharacter
{
private:
	std::string Name;
public:
	Dwarf(std::string Name, int HitPoints);
	~Dwarf();
	void SubtractDamage(int x);
};