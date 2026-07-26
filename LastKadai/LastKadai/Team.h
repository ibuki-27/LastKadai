#pragma once
#include<memory>
#include"Character.h"

class Team 
{
public:
	Team();
	Character& GetSwordman();
	Character& GetWizard();
	Character& GetSummoner();
	int GetStrength();
	void Damage(int damage);

private:
	int strength_;
	std::unique_ptr<Character> swordman_;
	std::unique_ptr<Character> wizard_;
	std::unique_ptr<Character> summoner_;
};