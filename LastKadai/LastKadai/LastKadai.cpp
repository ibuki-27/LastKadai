#include"FightGame.h"
#include<time.h>
#include<stdlib.h>

int main()
{
	srand((unsigned int)time(nullptr));

	FightGame game;

	game.Run();

	return 0;
}