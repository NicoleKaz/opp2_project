#pragma once

#include "Command.h"

class Controller;

class Level2_Button : public Command
{
public:
	Level2_Button(Controller*, sf::RenderWindow&);
	virtual void execute() override;

private:

};
