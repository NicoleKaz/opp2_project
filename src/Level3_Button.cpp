#pragma once

#include "Level3_Button.h"
#include "Controller.h"

Level3_Button::Level3_Button(Controller* game, sf::RenderWindow& window)
	:Command(game, window)
{
}

void Level3_Button::execute()
{
	/*m_game->getMenu().stopSong();
	m_game->getBoard().createLevel(Map1, WithoutYou_Song);
	m_game->startGame();
	m_game->getMenu().playSong();*/
}
