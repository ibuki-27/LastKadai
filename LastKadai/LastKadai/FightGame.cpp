#include<iostream>
#include"FightGame.h"

// –¡•ûƒLƒƒƒ‰‚Ì‘I‘ð
Character& FightGame::SelectAllyCharacter()
{
	int choice;

	while (true)
	{
		std::cout << "–¡•ûƒLƒƒƒ‰ƒNƒ^[‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢\n" << std::endl;
		std::cout << "1. Œ•Žm\n2. –‚–@Žg‚¢\n3. ¢Š«Žm" << std::endl;

		std::cin >> choice;

		if (choice == 1)
		{
			return ally_.GetSwordman();
		}
		else if (choice == 2)
		{
			return ally_.GetWizard();
		}
		else if (choice == 3)
		{
			return ally_.GetSummoner();
		}
		else
		{
			std::cout << "‚P`‚R‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;
		}
	}
}

// “GƒLƒƒƒ‰‚Ì‘I‘ð
Character& FightGame::SelectEnemyCharacter()
{
	int randomValue = rand() % 3;

	if (randomValue == 0)
	{
		return enemy_.GetSwordman();
	}
	else if (randomValue == 1)
	{
		return enemy_.GetWizard();
	}
	else
	{
		return enemy_.GetSummoner();
	}
}

// –¡•ûƒLƒƒƒ‰‚Ìs“®‘I‘ð
int FightGame::SelectAllyAction()
{
	int choice;

	while (true)
	{
		std::cout << "s“®‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢\n" << std::endl;
		std::cout << "1. UŒ‚\n2. –hŒä" << std::endl;

		std::cin >> choice;

		if (choice == 1)
		{
			return choice;
		}
		else if (choice == 2)
		{
			return choice;
		}
		else
		{
			std::cout << "‚P`‚Q‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;
		}
	}
}

// “GƒLƒƒƒ‰‚Ìs“®‘I‘ð
int FightGame::SelectEnemyAction()
{
	int randomValue = rand() % 2 + 1;

	if (randomValue == 1)
	{
		return randomValue;
	}
	else
	{
		return randomValue;
	}
}

// ƒQ[ƒ€ƒ‹[ƒvŠÖ”
void FightGame::Run()
{
	while (ally_.GetStrength() > 0 && enemy_.GetStrength() > 0)
	{
		Character& allyCharacter = SelectAllyCharacter();
		Character& enemyCharacter = SelectEnemyCharacter();

		int allyAction = SelectAllyAction();
		int enemyAction = SelectEnemyAction();

		Battle(allyCharacter, enemyCharacter, allyAction, enemyAction);
	}
}

// ƒoƒgƒ‹”»’èŠÖ”
void FightGame::Battle(Character& allyCharacter, Character& enemyCharacter, int allyAction, int enemyAction)
{
	// UŒ‚ vs UŒ‚
	if (allyAction == 1 && enemyAction == 1)
	{
		if (allyCharacter.Attack() > enemyCharacter.Attack())
		{
			enemy_.Damage(allyCharacter.Attack());
		}
		else if (enemyCharacter.Attack() > allyCharacter.Attack())
		{
			ally_.Damage(enemyCharacter.Attack());
		}
		else
		{
			std::cout << "ƒhƒ[" << std::endl;
		}
	}

	// –¡•ûUŒ‚ vs “G–hŒä
	if (allyAction == 1 && enemyAction == 2)
	{
		if (allyCharacter.GetName() == "Œ•Žm")
		{
			if (enemyCharacter.GetName() == "Œ•Žm")
			{
				std::cout << "ƒhƒ[" << std::endl;
			}
			else if (enemyCharacter.GetName() == "–‚–@Žg‚¢")
			{
				ally_.Damage(allyCharacter.Attack() * 2);
			}
			else if (enemyCharacter.GetName() == "¢Š«Žm")
			{
				enemy_.Damage(allyCharacter.Attack() * 2);
			}
		}
	}
}