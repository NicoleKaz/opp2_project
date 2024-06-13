#pragma once 

#include "Command.h"

Command::Command(GameControler* game, sf::RenderWindow& window)
	:m_game(game), m_window(window)
{
}
