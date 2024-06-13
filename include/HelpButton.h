#pragma once

#include "Command.h"
//#include "Game.h"

//#include "LevelsMenu.h"

class GameControler;

class HelpButton : public Command
{
public:

	HelpButton(GameControler* game, sf::RenderWindow& window);

	void execute() override;

private:
	//LevelsMenu m_levels_menu;
	GameControler* m_game;
	//sf::RenderWindow& m_window;
};