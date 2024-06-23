#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <Resources.h>

class Controller;

class Command
{
public:
	Command(Controller*, sf::RenderWindow&);
	virtual ~Command() = default;
	virtual void execute() = 0;

protected:
	Controller* m_game;
	sf::RenderWindow& m_window;
	
};
