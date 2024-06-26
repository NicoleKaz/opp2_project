#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <vector>
#include "Resources.h"
//#include "MovingObject.h"
#include "StaticObject.h"
//#include "Player.h"
#include "Floor.h"
//#include "Coin.h"
//#include "Gate.h"
//#include "Spike.h"
//#include "Jumper.h"
//#include "MyContactListener.h"
//#include "Enemy.h"*/

class Board
{
public:
    //Board();
    Board(sf::RenderWindow&, const GameTextures);
    void switchPlayer(const GameTextures player_textures);
    //void drawBoard() const;
    void drawBoard();
    void createLevel(const GameMaps level/*, const GameSounds sound*/);
    void findObjectColor(const sf::Color& color, const sf::Vector2f& location, size_t x, size_t y, const sf::Image& m_source);
    void addFloor(const sf::Vector2f& location, size_t x, size_t y, const sf::Image& m_source);
    void moveObjects();
    const b2Vec2 getPlayerPosition() const;
    void viewBackground(const float addition);
    void swapGravity();
    void updateMovingDirections()const;
    void rightReleased() const;
    void leftReleased() const;
    void spaceReleased() const;
    void changeBoxShip(const std::pair<GameTextures, GameTextures>);
    void handleCollision();
    //void createLevel(const GameMaps, const GameSounds);
    const bool isWin() const;
    const int getCoins() const;
    void resetBoard();


private:
    sf::RenderWindow& m_window;
    b2Vec2 m_gravity;
    b2World m_world;
    GameTextures m_player_textures;

    //game objects:
   // std::vector < std::unique_ptr< MovingObject>>  m_moving_objects;
    std::vector < std::unique_ptr< StaticObject>>  m_static_objects;

    sf::Sprite m_background;
    //Player* m_player = nullptr;
    sf::Vector2f m_player_location;
    //MyContactListener m_contact;
    bool m_win = false;
//    sf::Sound m_game_song;

};