#pragma once

#include "Command.h"
//#include "LevelsMenu.h"

class GameControler;

class PlayButton : public Command 
{
public:

	PlayButton(GameControler* game, sf::RenderWindow& window);

	void execute() override;

private:
	//LevelsMenu m_levels	_menu;
	GameControler* m_game;
	//sf::RenderWindow& m_window;
};