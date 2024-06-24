#pragma once

#include "Board.h"

Board::Board(sf::RenderWindow& window, const GameTextures player_texture)
    :m_window(window), m_gravity(0.0f, 9.8f), m_world(m_gravity), m_player_textures(player_texture)
{
    m_background.setTexture(Resources::instance().getGameTexture(Level_Background));
    m_background.scale(1.6f, 1.6f);
    m_background.setColor(sf::Color::White);
    //m_world.SetContactListener(&m_contact); //for the override function
}


void Board::switchPlayer(const GameTextures player_textures)
{
	//change the player box ship
	m_player_textures = player_textures;
}


//This function draws the board
void Board::drawBoard()
{
	m_window.draw(m_background);
	//m_window.draw(m_player->getSprite());
	//for (auto& object : m_moving_objects)
	//{
	//	object->draw(m_window);
	//}
	/*for (auto& object : m_static_objects)
	{
		object->draw(m_window);
	}*/
	for (int object = 0; object < m_static_objects.size(); object++)
	{
		m_static_objects[object]->draw(m_window);
	}
}

void Board::createLevel(const GameMaps level/*, const GameSounds sound*/)
{
	const sf::Image& m_source = Resources::instance().getMap(level);
	for (size_t y = 0; y < m_source.getSize().y; ++y)
	{
		for (size_t x = 0; x < m_source.getSize().x; ++x)
		{
			// The object location according to the pixel location
			const sf::Vector2f location(50 * x + 25, 50 * y + 25);

			// Get the pixel color
			sf::Color color = m_source.getPixel(x, y);

			// Create the corresponding object
			findObjectColor(color, location,x,y,m_source);
		}
	}
}

void Board::findObjectColor(const sf::Color& color, const sf::Vector2f& location,size_t x,size_t y, const sf::Image& m_source)
{
	if (color == sf::Color::White) 
	{
		return;
	}

	else if (color == sf::Color::Black) 
	{
		addFloor(location, x, y, m_source);
	}

	//else if (color == sf::Color::Cyan)
	//{
	//	// Create a blue object (e.g., an enemy)
	//	// Example: addEnemy(location);
	//}
	//else if (color == sf::Color(173, 216, 230))
	//{	
	//	addPlayer(location);
	//}
}

void Board::addFloor(const sf::Vector2f& location, size_t x, size_t y, const sf::Image& m_source)
{
	m_static_objects.push_back(Factory<StaticObject>::createObject(m_source.getPixel(x, y), m_world, location));

}

