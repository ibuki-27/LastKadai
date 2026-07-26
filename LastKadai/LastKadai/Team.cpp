#include"Team.h"
#include"Swordman.h"
#include"Wizard.h"
#include"Summoner.h"

Team::Team()
{
	strength_ = 300;

	swordman_ = std::unique_ptr<Character>(new Swordman());
	wizard_ = std::unique_ptr<Character>(new Wizard());
	summoner_ = std::unique_ptr<Character>(new Summoner());
}

Character& Team::GetSwordman()
{
	return *swordman_;
}

Character& Team::GetWizard()
{
	return *wizard_;
}

Character& Team::GetSummoner()
{
	return *summoner_;
}

int Team::GetStrength()
{
	return strength_;
}