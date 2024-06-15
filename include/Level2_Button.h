#pragma once

#include "Command.h"

class GameControler;

class Level2_Button : public Command
{
public:
	Level2_Button(GameControler*, sf::RenderWindow&);
	virtual void execute() override;

private:

};
