#pragma once

#include "Command.h"

class GameControler;


class Player4Button : public Command
{
public:
    Player4Button(GameControler* game, sf::RenderWindow& window);
    void execute() override;
};
