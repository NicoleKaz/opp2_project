#pragma once

#include "Command.h"

class GameControler;


class Player1Button : public Command
{
public:
    Player1Button(GameControler* game, sf::RenderWindow& window);
    void execute() override;
};
