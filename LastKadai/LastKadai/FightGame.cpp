#include<iostream>
#include"FightGame.h"

// 味方キャラの選択
Character& FightGame::SelectAllyCharacter()
{
	int choice;

	while (true)
	{
		std::cout << "味方キャラクターを選択してください\n" << std::endl;
		std::cout << "1. 剣士\n2. 魔法使い\n3. 召喚士" << std::endl;

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
			std::cout << "１～３を入力してください。" << std::endl;
		}
	}
}

// 敵キャラの選択
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

// 味方キャラの行動選択
int FightGame::SelectAllyAction()
{
	int choice;

	while (true)
	{
		std::cout << "行動を選択してください\n" << std::endl;
		std::cout << "1. 攻撃\n2. 防御" << std::endl;

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
			std::cout << "１～２を選択してください。" << std::endl;
		}
	}
}

// 敵キャラの行動選択
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

// ゲームループ関数
void FightGame::Run()
{
	while (ally_.GetStrength() > 0 && enemy_.GetStrength() > 0)
	{
		Character& allyCharacter = SelectAllyCharacter();
		Character& enemyCharacter = SelectEnemyCharacter();

		int allyAction = SelectAllyAction();
		int enemyAction = SelectEnemyAction();

		Battle(allyCharacter, enemyCharacter, allyAction, enemyAction);

		std::cout << "味方戦力 : " << ally_.GetStrength() << std::endl;
		std::cout << "敵戦力 : " << enemy_.GetStrength() << std::endl;
	}

	if (ally_.GetStrength() <= 0)
	{
		std::cout << "敵チームの勝利！" << std::endl;
	}
	else
	{
		std::cout << "味方チームの勝利！" << std::endl;
	}

}

// バトル判定関数
void FightGame::Battle(Character& allyCharacter, Character& enemyCharacter, int allyAction, int enemyAction)
{
	// 攻撃 vs 攻撃
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
			std::cout << "ドロー" << std::endl;
		}
	}

	// 味方攻撃 vs 敵防御
	if (allyAction == 1 && enemyAction == 2)
	{
		if (allyCharacter.GetName() == "剣士")
		{
			if (enemyCharacter.GetName() == "剣士")
			{
				std::cout << "ドロー" << std::endl;
			}
			else if (enemyCharacter.GetName() == "魔法使い")
			{
				std::cout << "カウンター発生！" << std::endl;
				ally_.Damage(allyCharacter.Attack() * 2);
			}
			else if (enemyCharacter.GetName() == "召喚士")
			{
				std::cout << "クリティカル発生！" << std::endl;
				enemy_.Damage(allyCharacter.Attack() * 2);
			}
		}
		else if (allyCharacter.GetName() == "魔法使い")
		{
			if (enemyCharacter.GetName() == "剣士")
			{
				std::cout << "クリティカル発生！" << std::endl;
				enemy_.Damage(allyCharacter.Attack() * 2);
			}
			else if (enemyCharacter.GetName() == "魔法使い")
			{
				std::cout << "ドロー" << std::endl;
			}
			else if (enemyCharacter.GetName() == "召喚士")
			{
				std::cout << "カウンター発生！" << std::endl;
				ally_.Damage(allyCharacter.Attack() * 2);
			}
		}
		else if (allyCharacter.GetName() == "召喚士")
		{
			if (enemyCharacter.GetName() == "剣士")
			{
				std::cout << "カウンター発生！" << std::endl;
				ally_.Damage(allyCharacter.Attack() * 2);
			}
			else if (enemyCharacter.GetName() == "魔法使い")
			{
				std::cout << "クリティカル発生！" << std::endl;
				enemy_.Damage(allyCharacter.Attack() * 2);
			}
			else if (enemyCharacter.GetName() == "召喚士")
			{
				std::cout << "ドロー" << std::endl;
			}
		}
	}

	// 味方防御 vs 敵攻撃
	if (allyAction == 2 && enemyAction == 1)
	{
		if (enemyCharacter.GetName() == "剣士")
		{
			if (allyCharacter.GetName() == "剣士")
			{
				std::cout << "ドロー" << std::endl;
			}
			else if (allyCharacter.GetName() == "魔法使い")
			{
				std::cout << "カウンター発生！" << std::endl;
				enemy_.Damage(enemyCharacter.Attack() * 2);
			}
			else if (allyCharacter.GetName() == "召喚士")
			{
				std::cout << "クリティカル発生！" << std::endl;
				ally_.Damage(enemyCharacter.Attack() * 2);
			}
		}
		else if (enemyCharacter.GetName() == "魔法使い")
		{
			if (allyCharacter.GetName() == "剣士")
			{
				std::cout << "クリティカル発生！" << std::endl;
				ally_.Damage(enemyCharacter.Attack() * 2);
			}
			else if (allyCharacter.GetName() == "魔法使い")
			{
				std::cout << "ドロー" << std::endl;
			}
			else if (allyCharacter.GetName() == "召喚士")
			{
				std::cout << "カウンター発生！" << std::endl;
				enemy_.Damage(enemyCharacter.Attack() * 2);
			}
		}
		else if (enemyCharacter.GetName() == "召喚士")
		{
			if (allyCharacter.GetName() == "剣士")
			{
				std::cout << "カウンター発生！" << std::endl;
				enemy_.Damage(enemyCharacter.Attack() * 2);
			}
			else if (allyCharacter.GetName() == "魔法使い")
			{
				std::cout << "クリティカル発生！" << std::endl;
				ally_.Damage(enemyCharacter.Attack() * 2);
			}
			else if (allyCharacter.GetName() == "召喚士")
			{
				std::cout << "ドロー" << std::endl;
			}
		}
	}

	// 味方防御 vs 敵防御
	if (allyAction == 2 && enemyAction == 2)
	{
		std::cout << "ドロー" << std::endl;
	}
}

FightGame::FightGame()
{

}