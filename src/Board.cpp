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
