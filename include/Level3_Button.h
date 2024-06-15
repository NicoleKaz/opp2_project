#pragma once

#include "Command.h"

class GameControler;

class Level3_Button : public Command
{
public:
	Level3_Button(GameControler*, sf::RenderWindow&);
	virtual void execute() override;

private:

};
