#pragma once

#include "Command.h"
#include <LevelsMenu.h>
//#include "LevelsMenu.h"

class GameControler;

class PlayButton : public Command 
{
public:

	PlayButton(GameControler* game, sf::RenderWindow& window);
	void execute() override;

private:
	LevelsMenu m_levelsMenu;

};