#pragma once

#include "Level1_Button.h"
#include "Controller.h"

Level1_Button::Level1_Button(Controller* game, sf::RenderWindow& window)
	:Command(game, window)
{
}

void Level1_Button::execute()
{
	//m_game->getMenu().stopSong();
	
	m_game->getBoard().createLevel(Map1 /*WithoutYou_Song*/);
	//m_window.close();


	m_game->startGame();
	//m_game->getMenu().playSong();*/
}
	