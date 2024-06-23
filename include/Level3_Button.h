#pragma once

#include "Command.h"

class Controller;

class Level3_Button : public Command
{
public:
	Level3_Button(Controller*, sf::RenderWindow&);
	virtual void execute() override;

private:

};
