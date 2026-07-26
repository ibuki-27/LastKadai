#pragma once
#include"Team.h"
#include"Character.h"

class FightGame
{
public:
	FightGame();
	void Run();

private:
	Team ally_;
	Team enemy_;

	Character& SelectAllyCharacter();
	Character& SelectEnemyCharacter();

	int SelectAllyAction();
	int SelectEnemyAction();

	void Battle(Character& allyCharacter, Character& enemyCharacter, int allyAction, int enemyAction);

};