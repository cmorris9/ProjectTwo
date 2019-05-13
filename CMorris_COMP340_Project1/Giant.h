#pragma once
#include "GameCharacter.h"

class Giant : public GameCharacter
{
private:
	std::string Name;
public:
	Giant(std::string Name, int HitPoints);
	~Giant();
	void SubtractDamage(int x);
};