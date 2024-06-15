#pragma once

#include "Command.h"

class GameControler;


class Player3Button : public Command
{
public:
    Player3Button(GameControler* game, sf::RenderWindow& window);
    void execute() override;
};
