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
	void ButtonPress(const MenuPlayer player);
	void ButtonRelease(const MenuPlayer player);
	//sf::Sprite getInstructions(const Instructions) const;

	void buttonRelease(const Button button);
	void buttonPress(const Button button);
	void add(const Button button, std::unique_ptr<Command> command);
	void drawMenu()const;

	void displayRules()const;

	void action(const sf::Vector2f& location) const;

	void choosePlayer(const MenuPlayer player);

	const sf::Sprite getPlayer(const MenuPlayer player) const;

	void drawPlayer() const;


	const GameTextures getPlayerTextures() const;

private:
	sf::RenderWindow& m_window;
	sf::Sprite m_background;
	sf::Sprite m_title;

	//arrays
	sf::Sprite m_buttons[MENU_BUTTONS];
	sf::Sprite m_instructionsPage[INSTRUCTIONS];
	sf::Sprite m_players[MENU_PLAYER];

	MenuPlayer m_player;

	void setPosition();


	typedef std::pair<const sf::Sprite, std::unique_ptr<Command>> option;
	std::vector<option> m_options;

	//sf::Sprite m_back_buttons[MENU_BUTTONS];
	//sf::Sprite m_instructions[MENU_INSTRUCTIONS];
	//sf::Sprite m_box_ships[MENU_BOX_SHIPS];
	//sf::RectangleShape m_box_ships_rect[MENU_BOX_SHIPS];
	//sf::Text m_box_ship_text;
	//sf::Sound m_menu_sound;

};
