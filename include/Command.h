#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <Resources.h>

class GameControler;

class Command
{
public:
	Command(GameControler*, sf::RenderWindow&);
	virtual ~Command() = default;
	virtual void execute() = 0;

protected:
	GameControler* m_game;
	sf::RenderWindow& m_window;
	
};
