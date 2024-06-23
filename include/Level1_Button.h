#pragma once

#include "Command.h"

class Controller;

class Level1_Button : public Command
{
public:
	Level1_Button(Controller*, sf::RenderWindow&);
	virtual void execute() override;

private:

};
