#pragma once

#include "Command.h"

class GameControler;


class Player2Button : public Command
{
public:
    Player2Button(GameControler* game, sf::RenderWindow& window);
    void execute() override;
};
