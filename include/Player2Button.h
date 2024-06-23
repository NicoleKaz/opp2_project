#pragma once

#include "Command.h"

class Controller;


class Player2Button : public Command
{
public:
    Player2Button(Controller* game, sf::RenderWindow& window);
    void execute() override;
};
