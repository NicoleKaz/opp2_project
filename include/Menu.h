#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Command.h"



class Menu
{
public:

	Menu(sf::RenderWindow& window);

	sf::Sprite getMenuTexture(const MenuTextures texture) const;
	sf::Sprite getButton(const Button) const;
	void ButtonPress(const Button button);
	void ButtonRelease(const Button button);
	//sf::Sprite getInstructions(const Instructions) const;

	void buttonRelease(const Button button);
	void buttonPress(const Button button);
	void displayRules();
	void add(const Button button, std::unique_ptr<Command> command);
	void drawMenu(sf::RenderWindow&)const;

	const std::pair<GameTextures, GameTextures> getPlayerTextures() const;

private:
	sf::RenderWindow& m_window;
	sf::Sprite m_background;
	sf::Sprite m_title;

	//arrays
	sf::Sprite m_buttons[MENU_BUTTONS];
	sf::Sprite m_instructionsPage[INSTRUCTIONS];

	void setPosition();


	typedef std::pair<const sf::Sprite, std::unique_ptr<Command>> option;
	std::vector<option> m_options;

	sf::Sprite m_back_buttons[MENU_BUTTONS];
	//sf::Sprite m_instructions[MENU_INSTRUCTIONS];
	//sf::Sprite m_box_ships[MENU_BOX_SHIPS];
	//sf::RectangleShape m_box_ships_rect[MENU_BOX_SHIPS];
	//sf::Text m_box_ship_text;
	MenuBoxShips m_box_ship;
	//sf::Sound m_menu_sound;

};
