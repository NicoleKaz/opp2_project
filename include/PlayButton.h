#pragma once

#include "Command.h"
#include <LevelsMenu.h>
//#include "LevelsMenu.h"

class Controller;

class PlayButton : public Command 
{
public:

	PlayButton(Controller* game, sf::RenderWindow& window);
	void execute() override;

private:
	LevelsMenu m_levelsMenu;

};