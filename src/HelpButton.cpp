#include "HelpButton.h"
#include "GameControler.h"
#include <iostream>



HelpButton::HelpButton(GameControler* game, sf::RenderWindow& window)
    : Command(game, window) {
}

void HelpButton::execute()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        m_game->getMenu().displayRules();
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
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
