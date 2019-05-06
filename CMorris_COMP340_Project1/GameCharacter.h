#pragma once
#include <string>

class GameCharacter
{
private:
	std::string Name;

public:
	int HitPoints;
	int AttckDmg = 0;
	GameCharacter(std::string Name, int HitPoints);
	~GameCharacter();
	std::string GetName();
	void SubtractDamage(int x);

	int GetHitPoints();

};

