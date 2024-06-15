#pragma once

#include "Choose_LevelButton.h"
#include "GameControler.h"
#include "Level1_Button.h"
#include "Level2_Button.h"
#include "Level3_Button.h"
//#include "GreyhoundButton.h"
//#include "OnlyTheHorsesButton.h"
//#include "SpectreButton.h"


Choose_LevelButton::Choose_LevelButton(GameControler* game, sf::RenderWindow& window)
	:Command(game, window), m_levelsMenu(m_game, m_window)
{
	//adding buttons to the submenu
	m_levelsMenu.add(level1, std::make_unique<Level1_Button>(m_game, m_window));
	m_levelsMenu.add(level2, std::make_unique<Level2_Button>(m_game, m_window));
	m_levelsMenu.add(level3, std::make_unique<Level3_Button>(m_game, m_window));
}

//void Choose_LevelButton::execute()
//{
//
//
//
//	// כאשר לוחצים על כפתור המשחק, הפונקציה תבצע את הפעולות הנדרשות להתחלת המשחק
//	m_game->chooseLevel();


void Choose_LevelButton::execute()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        m_levelsMenu.drawLevelsMenu();  // Draw the player menu
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::MouseButtonReleased:
            {
                // Getting the click location, checking what button pressed
                const auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

                // Performing the button action accordingly
                m_levelsMenu.handleAction(location);
                return;
            }
            case sf::Event::MouseMoved:
            {
                // Indicate if the mouse is on the buttons
                const auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                m_levelsMenu.handleMouseMoved(location);
                break;
            }
            case sf::Event::Closed:
                m_window.close();
                return;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            return;
        }
    }
}

