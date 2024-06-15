#pragma once

#include "Level2_Button.h"
#include "GameControler.h"

Level2_Button::Level2_Button(GameControler* game, sf::RenderWindow& window)
	:Command(game, window)
{
}

void Level2_Button::execute()
{
	/*m_game->getMenu().stopSong();
	m_game->getBoard().createLevel(Map1, WithoutYou_Song);
	m_game->startGame();
	m_game->getMenu().playSong();*/
}
