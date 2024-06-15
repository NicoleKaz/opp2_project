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
	//adding buttons to the submenu
	//m_levels_menu.add(WithoutYou, std::make_unique<WithoutYouButton>(m_game, m_window));
	//m_levels_menu.add(Greyhound, std::make_unique<GreyhoundButton>(m_game, m_window));
	//m_levels_menu.add(OnlyTheHorses, std::make_unique<OnlyTheHorsesButton>(m_game, m_window));
	//m_levels_menu.add(Spectre, std::make_unique<SpectreButton>(m_game, m_window));
}

void SwitchPlayerButton::execute()
{
    bool click = false;

    while (m_window.isOpen() && !click)
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
                click = true;
                break;
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
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            break;
        }
    }
}





