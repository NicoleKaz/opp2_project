#pragma once

#include "Command.h"
//#include "Game.h"

//#include "LevelsMenu.h"

class GameControler;

class ExitGame : public Command
{
public:

	ExitGame(GameControler* game, sf::RenderWindow& window);

	void execute() override;

private:
	//LevelsMenu m_levels_menu;
	GameControler* m_game;
	//sf::RenderWindow& m_window;
};