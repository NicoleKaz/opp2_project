#pragma once

#include "Board.h"

Board::Board(sf::RenderWindow& window, const std::pair<GameTextures, GameTextures> player_texture)
    :m_window(window), m_gravity(0.0f, 9.8f),/* m_world(m_gravity),*/ m_player_textures(player_texture)
{
    m_background.setTexture(Resources::instance().getGameTexture(Level_Background));
    m_background.scale(1.6f, 1.6f);
    m_background.setColor(sf::Color::White);
    //m_world.SetContactListener(&m_contact); //for the override function
}


//This function draws the board
void Board::drawBoard(sf::RenderWindow& window)
{
	//Delete everything that was in the window until now
	window.clear(sf::Color::Color(210, 210, 210));
	//Draw 
	//for (int stick = 0; stick < m_stick.size(); stick++)
	//{
	//	window.draw(m_stick[stick]->getrec());
	//}
	////Draw the franme of the buttons
	//for (int rectangle = 0; rectangle < 4; rectangle++)
	//{
	//	window.draw(m_grid_frame[rectangle]);
	//}
}