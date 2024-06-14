#pragma once

#include "Command.h"
//#include "LevelsMenu.h"

class GameControler;

class Choose_LevelButton : public Command
{
public:

	Choose_LevelButton(GameControler* game, sf::RenderWindow& window);

	void execute() override;

private:
	LevelsMenu m_levels_menu;

	GameControler* m_game;
	//sf::RenderWindow& m_window;
};