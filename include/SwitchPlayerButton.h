#pragma once

#include "Command.h"
//#include "LevelsMenu.h"

class GameControler;

class SwitchPlayerButton : public Command
{
public:

	SwitchPlayerButton(GameControler* game, sf::RenderWindow& window);
	void execute() override;

private:
	//LevelsMenu m_levels_menu;
	GameControler* m_game;
	//sf::RenderWindow& m_window;



};