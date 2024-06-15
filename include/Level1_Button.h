#pragma once

#include "Command.h"

class GameControler;

class Level1_Button : public Command
{
public:
	Level1_Button(GameControler*, sf::RenderWindow&);
	virtual void execute() override;

private:

};
