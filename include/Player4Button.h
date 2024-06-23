#pragma once

#include "Command.h"

class Controller;


class Player4Button : public Command
{
public:
    Player4Button(Controller* game, sf::RenderWindow& window);
    void execute() override;
};
