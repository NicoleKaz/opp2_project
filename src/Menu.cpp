#include "Menu.h"


//This functiones define the arrays
Menu::Menu(sf::RenderWindow& window)
	:m_window(window)
{
	//beckground sprite
	m_background.setTexture(Resources::instance().getMenuTexture(menuBackground));
	m_background.scale(1.6f, 1.6f);

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




//this function showes the instructions page after the press
void Menu::displayRules()
{
	m_instructionsPage[GAME_RULES].setColor(sf::Color::Color(255, 255, 255, 255));
}

//this function set the position 
void Menu::setPosition()
{
	//resize Buttons 
	m_buttons[PLAY].scale(sf::Vector2f(WINDOW_WIDTH * 0.195 / m_buttons[PLAY].getTextureRect().width,
		WINDOW_WIDTH * 0.195 / m_buttons[PLAY].getTextureRect().width));

	m_buttons[HELP].scale(sf::Vector2f(WINDOW_WIDTH * 0.195 / m_buttons[HELP].getTextureRect().width,
		WINDOW_WIDTH * 0.195 / m_buttons[HELP].getTextureRect().width));

	m_buttons[EXIT].scale(sf::Vector2f(WINDOW_WIDTH * 0.195 / m_buttons[EXIT].getTextureRect().width,
		WINDOW_WIDTH * 0.195 / m_buttons[EXIT].getTextureRect().width));

	m_buttons[BACK].scale(sf::Vector2f(WINDOW_WIDTH * 0.12 / m_buttons[BACK].getTextureRect().width,
		WINDOW_WIDTH * 0.12 / m_buttons[BACK].getTextureRect().width));

	m_buttons[VIDEO_PLAY].scale(sf::Vector2f(WINDOW_WIDTH * 0.12 / m_buttons[VIDEO_PLAY].getTextureRect().width,
		WINDOW_WIDTH * 0.12 / m_buttons[VIDEO_PLAY].getTextureRect().width));

	m_buttons[SCORE_TABLE].scale(sf::Vector2f(WINDOW_WIDTH * 0.12 / m_buttons[SCORE_TABLE].getTextureRect().width,
		WINDOW_WIDTH * 0.12 / m_buttons[SCORE_TABLE].getTextureRect().width));

	//resize Instructions:	
	m_instructionsPage[GAME_RULES].scale(sf::Vector2f(2.4f, 1.3f));

	//locate menu:
	m_buttons[PLAY].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[PLAY].getTextureRect().width) * 0.5,
		WINDOW_HEIGHT - m_buttons[PLAY].getTextureRect().height * 1.5 * 3));

	m_buttons[HELP].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[HELP].getTextureRect().width) * 0.5,
		WINDOW_HEIGHT - m_buttons[HELP].getTextureRect().height * 1.5 * 2));

	m_buttons[EXIT].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[EXIT].getTextureRect().width) * 0.5,
		WINDOW_HEIGHT - m_buttons[EXIT].getTextureRect().height * 1.5 * 1));

	m_buttons[VIDEO_PLAY].setPosition(sf::Vector2f(WINDOW_WIDTH * 0.88, WINDOW_HEIGHT * 0.73));

	m_buttons[BACK].setPosition(sf::Vector2f(WINDOW_WIDTH * 0.85, WINDOW_HEIGHT * 0.85));

	//locate Instructions:
	m_instructionsPage[GAME_RULES].setPosition(sf::Vector2f(WINDOW_WIDTH * 0.0, WINDOW_HEIGHT * 0.0));
}

//Returns the button from the array
//sf::Sprite Menu::getButton(const object) const
//{
//	return m_buttons[object];
//}
//
////make the shadow on the butten
//void Menu::buttonRelease(const button button)
//{
//	m_buttons[button].setColor(sf::Color::Color(255, 255, 255));
//}
//
////make the shadow on the butten
//void Menu::buttonPress(const button button)
//{
//	m_buttons[button].setColor(sf::Color::Color(255, 255, 255, 150));
//}
//
//
//
////Returns the from the array
//sf::Sprite Menu::getInstructions(const Instructions object) const
//{
//	return m_instructionsPage[object];
//}
