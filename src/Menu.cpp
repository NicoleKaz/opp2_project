#include "Menu.h"
#include <iostream>


//This functiones define the arrays
Menu::Menu(sf::RenderWindow& window)
	:m_window(window)
{
	//beckground sprite
	m_background.setTexture(Resources::instance().getMenuTexture(menuBackground));
	m_background.scale(1.5f, 1.6f);
	//title sprite
	m_title.setTexture(Resources::instance().getMenuTexture(Title));
	//the menu buttunes
	for (int button = PLAY; button <= EXIT; button++)
	{
		m_buttons[button].setTexture(Resources::instance().getButton((Button)button));
	}
	//the instruction page 
	/*for (int instruction = GAME_RULES; instruction <= GAME_RULES; instruction++)
	{
		m_instructionsPage[instruction].setTexture(Resources::instance().getInstruction((instructions)instruction));
	}
	m_instructionsPage[GAME_RULES].setColor(sf::Color::Color(255, 255, 255, 0));*/
	setPosition();
}

sf::Sprite Menu::getButton(const Button button) const
{
	return m_buttons[button];
}


//This function changes the color of the button as soon as the user hovers over it with the mouse
void Menu::ButtonPress(const Button button)
{
	m_buttons[button].setColor(sf::Color::Color(255, 255, 255, 150));
}

//This function changes the color of the button as soon as the user removes the mouse from the button
void Menu::ButtonRelease(const Button button)
{
	m_buttons[button].setColor(sf::Color::Color(255, 255, 255));
}


const std::pair<GameTextures, GameTextures> Menu::getPlayerTextures() const
{
	//returning the player textures picked by pair of box and ship
	switch (m_box_ship)
	{
	case BoxShip1:
		return std::pair<GameTextures, GameTextures>(PlayerBox1, PlayerShip1);
		break;

	case BoxShip2:
		return std::pair<GameTextures, GameTextures>(PlayerBox2, PlayerShip2);
		break;

	case BoxShip3:
		return std::pair<GameTextures, GameTextures>(PlayerBox3, PlayerShip3);
		break;

	case BoxShip4:
		return std::pair<GameTextures, GameTextures>(PlayerBox4, PlayerShip4);
		break;

	case BoxShip5:
		return std::pair<GameTextures, GameTextures>(PlayerBox5, PlayerShip5);
		break;

	case BoxShip6:
		return std::pair<GameTextures, GameTextures>(PlayerBox6, PlayerShip6);
		break;
	}
}

//this function showes the instructions page after the press
void Menu::displayRules()
{
	m_instructionsPage[GAME_RULES].setColor(sf::Color::Color(255, 255, 255, 255));
}

//adding new button to the menu
void Menu::add(const Button button, std::unique_ptr<Command> command)
{
	m_options.push_back(std::make_pair(m_buttons[button], std::move(command)));
}

//draw the game menu
void Menu::drawMenu(sf::RenderWindow& window)const
{
	window.draw(m_background);
	for (const auto& option : m_options)
	{
		window.draw(option.first);
	}
	window.draw(m_title);
}

void Menu::action(const sf::Vector2f& location) const
{
	for (const auto& option : m_options)
	{
		if (option.first.getGlobalBounds().contains(location))
		{
			option.second->execute();
		}
	}
}

void Menu::drawPlayer()const
{
	m_window.draw(m_background);
	for (int player = PLAYER1; player <= PLAYER3; player++)
	{
		m_window.draw(m_player[player]);
	}
	//m_window.draw(m_box_ship_text);
}

//this function set the position 
//this function set the position of the buttons and the title in the menu
void Menu::setPosition()
{
	//set the buttons
	m_buttons[PLAY].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[PLAY].getTextureRect().width) * 0.5,
		WINDOW_HEIGHT - m_buttons[PLAY].getTextureRect().height * 3.5));

	m_buttons[HELP].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[HELP].getTextureRect().width) * 0.75,
		WINDOW_HEIGHT - m_buttons[HELP].getTextureRect().height * 4));;

	m_buttons[SWITCH_PLAYER].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[SWITCH_PLAYER].getTextureRect().width) * 0.25,
		WINDOW_HEIGHT - m_buttons[SWITCH_PLAYER].getTextureRect().height * 4));

	m_buttons[SCORE_TABLE].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[SCORE_TABLE].getTextureRect().width) * 0.5,
		WINDOW_HEIGHT - m_buttons[SCORE_TABLE].getTextureRect().height * 2));

	m_buttons[EXIT].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[EXIT].getTextureRect().width) * 0.75,
		WINDOW_HEIGHT - m_buttons[EXIT].getTextureRect().height * 2));

	//set the title
	m_title.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.25, WINDOW_HEIGHT * 0.1));
	m_title.scale(sf::Vector2f(WINDOW_WIDTH * 0.5 / m_title.getTextureRect().width,
		WINDOW_WIDTH * 0.5 / m_title.getTextureRect().width));
}

////Returns the from the array
//sf::Sprite Menu::getInstructions(const Instructions object) const
//{
//	return m_instructionsPage[object];
//}
