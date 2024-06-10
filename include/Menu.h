#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"


class Menu
{
public:

	Menu(sf::RenderWindow& window);

	const sf::Texture& getMenuSprite(const MenuTextures texture) const;

	sf::Sprite getButton(const Button) const;
	sf::Sprite getInstructions(const Instructions) const;

	void buttonRelease(const Button button);
	void buttonPress(const Button button);
	void displayRules();
	sf::Sprite& getBackground() { return m_background; }


private:
	sf::RenderWindow& m_window;
	//members
	//const int m_WINDOW_HEIGHT;
	//const int m_WINDOW_WIDTH;
	sf::Sprite m_background;

	//arrays
	sf::Sprite m_buttons[MENU_BUTTONS];
	sf::Sprite m_instructionsPage[INSTRUCTIONS];
	void setPosition();





	sf::Sprite m_buttons[MENU_BUTTONS];
	sf::Sprite m_back_buttons[MENU_BUTTONS];
	sf::Sprite m_instructions[MENU_INSTRUCTIONS];
	sf::Sprite m_box_ships[MENU_BOX_SHIPS];
	sf::RectangleShape m_box_ships_rect[MENU_BOX_SHIPS];
	sf::Text m_box_ship_text;
	MenuBoxShips m_box_ship;
	sf::Sound m_menu_sound;

};
