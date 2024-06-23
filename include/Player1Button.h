#pragma once

#include "Command.h"

class Controller;


class Player1Button : public Command
{
public:
    Player1Button(Controller* game, sf::RenderWindow& window);
    void execute() override;
};
