#include<iostream>
#include<stdlib.h>
#include"Character.h"

Character::Character(std::string name, int attackPower)
{
	name_ = name;
	attackPower_ = attackPower;
	isDefending_ = false;
}

int Character::Attack()
{
	return attackPower_;
}

void Character::Defense()
{
	isDefending_ = true;
}


