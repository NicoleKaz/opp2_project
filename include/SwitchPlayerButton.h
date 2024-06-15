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

};