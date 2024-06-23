#pragma once
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include <sstream>
#include <iomanip>
#include "SwitchPlayerButton.h"
#include "ScoreTableButton.h"
#include <ExitGame.h>
#include <Choose_LevelButton.h>
#include "Resources.h"
#include "HelpButton.h"
#include "PlayButton.h"
#include "ExitGame.h"
#include "Board.h"
#include "Menu.h"


class Controller
{
public:
	Controller();
	void run();

	void handleSwitchPlayer(const sf::Vector2f location);

	void handleSwitchPlayerMouseMoved(const sf::Vector2f location);

	Board& getBoard();
	
	/*
	void chooseBoxShip();
	void handleBoxShipPageClick(const sf::Vector2f);
	void handleBoxShipMouseMoved(const sf::Vector2f);
	Board& getBoard();
	*/

	Menu& getMenu();

	void startGame();
	void helpGame();
	void SwitchPlayer();
	void quitGame();
	void chooseLevel();


private:	
	//sf::Sprite& m_background;
	sf::RenderWindow m_window;
	//Resources& m_resource = Resources::instance();
	Menu m_menu;
	Board m_board;
	Resources m_resources;
	sf::View m_gameView;
	sf::Clock m_GameClock;

	void handleMenuMouseMoved(const sf::Vector2f);
	void handleClick(const sf::Vector2f);

	//bool m_game_over = false;
	//sf::Clock m_game_clock;
	////private functions
	//void setView();
	//void winLoop();
	//void createScoreBoard(sf::Sprite&, sf::Sprite&, sf::Text&, sf::Text&, int&,
	//	sf::Text&, sf::Text&, sf::RectangleShape&, sf::RectangleShape&) const;

};