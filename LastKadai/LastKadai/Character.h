#pragma once
#include <string>

class Character
{
private:
	std::string name_;
	int attackPower_;
	bool isDefending_;

public:
	Character(std::string name, int attackPower);
	int Attack();
    void Defense();

};