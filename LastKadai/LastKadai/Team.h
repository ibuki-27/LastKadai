#pragma once
#include<memory>
#include"Character.h"

class Team 
{
public:
	Team();

private:
	int strength_;
	std::unique_ptr<Character> swordman_;
	std::unique_ptr<Character> wizard_;
	std::unique_ptr<Character> summoner_;
};