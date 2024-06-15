#pragma once

#include "SwitchPlayerButton.h"
#include "GameControler.h"
//#include "WithoutYouButton.h"
//#include "GreyhoundButton.h"
//#include "OnlyTheHorsesButton.h"
//#include "SpectreButton.h"



SwitchPlayerButton::SwitchPlayerButton(GameControler* game, sf::RenderWindow& window)
	:Command(game, window)
{
}

void SwitchPlayerButton::execute()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        m_game->getMenu().drawPlayer();
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
                m_game->handleSwitchPlayer(location);
                m_game->getBoard().switchPlayer(m_game->getMenu().getPlayerTextures());
                return;               
            }
            case sf::Event::MouseMoved:
            {
                 // Indicate if the mouse on the buttons 
                 const auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                 m_game->handleSwitchPlayerMouseMoved(location);
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





