#include "PlayersMenu.h"
#include "Resources.h"

PlayersMenu::PlayersMenu(sf::RenderWindow& window)
    : m_window(window)
{
    m_background.setTexture(Resources::instance().getMenuTexture(menuBackground));
    m_background.scale(1.5f, 1.6f);
    
    for (int player = PLAYER1; player <= PLAYER3;player++)
    {
        m_player[player].setTexture(Resources::instance().getMenuPlayer((MenuPlayer)player));
    }
    locateObjects();
}





void PlayersMenu::locateObjects()
{
    //level buttons
    m_player[PLAYER1].setPosition(sf::Vector2f((WINDOW_WIDTH - m_player[PLAYER1].getTextureRect().width) * 0.25,
        (WINDOW_HEIGHT - m_player[PLAYER1].getTextureRect().height) * 0.25));

    m_player[PLAYER2].setPosition(sf::Vector2f((WINDOW_WIDTH - m_player[PLAYER2].getTextureRect().width) * 0.75,
        (WINDOW_HEIGHT - m_player[PLAYER2].getTextureRect().height) * 0.25));

    m_player[PLAYER3].setPosition(sf::Vector2f((WINDOW_WIDTH - m_player[PLAYER3].getTextureRect().width) * 0.25,
        (WINDOW_HEIGHT - m_player[PLAYER3].getTextureRect().height) * 0.75));

    //m_player[Spectre].setPosition(sf::Vector2f((WINDOW_WIDTH - m_player[Spectre].getTextureRect().width) * 0.75,
    //    (WINDOW_HEIGHT - m_player[Spectre].getTextureRect().height) * 0.75));
}

void PlayersMenu::drawPlayer()const 
{
    m_window.draw(m_background);
    for (int player = PLAYER1; player <= PLAYER3; player++)
    {
        m_window.draw(m_player[player]);
    }
    //m_window.draw(m_box_ship_text);
}

void PlayersMenu::add(const MenuPlayer player, std::unique_ptr<Command> command)
{
    // Adding new player button to the menu
    m_options.emplace_back(options(m_player[player], std::move(command)));
}


void PlayersMenu::handleAction(const sf::Vector2f& location)
{
    for (auto& option : m_options)
    {
        if (option.first.getGlobalBounds().contains(location))
        {
            option.second->execute();
            break;
        }
    }
}

void PlayersMenu::handleMouseMoved(const sf::Vector2f& location)
{
    for (auto& option : m_options)
    {
        if (option.first.getGlobalBounds().contains(location))
        {
            option.first.setColor(sf::Color::Yellow);  // Highlight on hover
        }
        else
        {
            option.first.setColor(sf::Color::White);  // Reset color
        }
    }
}
