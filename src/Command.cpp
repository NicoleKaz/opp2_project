#pragma once 

#include "Command.h"

Command::Command(Controller* game, sf::RenderWindow& window)
	:m_game(game), m_window(window)
{
}
