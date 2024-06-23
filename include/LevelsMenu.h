#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Resources.h>
#include "Command.h"

class LevelsMenu
{
public:
	LevelsMenu(Controller*, sf::RenderWindow&);
	void drawLevelsMenu()const;
	const int getOptionFromUser(const sf::Vector2f)const;
	void action(const sf::Vector2f& location) const;
	void add(const MenuLevels, std::unique_ptr<Command>);
	void handleMouseMoved(const sf::Vector2f location);


private:

	sf::RenderWindow& m_window;
	Controller* m_game;
	sf::Sprite m_background;
	sf::Sprite m_buttons[MENU_BUTTONS];
	sf::Sprite m_menuLevel[LEVEL_MENU];
	sf::Sprite m_back_buttons[MENU_BUTTONS];

	typedef std::pair<const sf::Sprite, std::unique_ptr<Command>> option;
	std::vector<option> m_options;

	void locateObjects();

};
