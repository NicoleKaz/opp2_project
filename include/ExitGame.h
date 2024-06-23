#pragma once

#include "Command.h"
//#include "Game.h"

//#include "LevelsMenu.h"

class Controller;

class ExitGame : public Command
{
public:

	ExitGame(Controller* game, sf::RenderWindow& window);

	void execute() override;

private:
	//LevelsMenu m_levels_menu;
	Controller* m_game;
	//sf::RenderWindow& m_window;
};