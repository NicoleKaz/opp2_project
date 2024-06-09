#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"


class Menu
{
public:

	Menu(sf::RenderWindow& window);

	sf::Sprite getButton(const Button) const;
	sf::Sprite getInstructions(const Instructions) const;

	void buttonRelease(const Button button);
	void buttonPress(const Button button);
	void displayRules();

private:
	//members
	const int m_WINDOW_HEIGHT;
	const int m_WINDOW_WIDTH;
	sf::Sprite m_background;

	//arrays
	sf::Sprite m_buttons[BUTTONS];
	sf::Sprite m_instructionsPage[INSTRUCTIONS];
	void setPosition();
};
