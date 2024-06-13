#include "GameControler.h"


GameControler::GameControler()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Geometry Dash"),
    m_menu(m_window),
    m_board(m_window, m_menu.getPlayerTextures())
{
    m_window.setFramerateLimit(120);
    m_gameView.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_gameView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);


    ////adding menu buttons:
    //m_menu.add(Play, std::make_unique<PlayButton>(this, m_window));
    //m_menu.add(Help, std::make_unique<HelpButton>(this, m_window));
    //m_menu.add(Box, std::make_unique<BoxButton>(this, m_window));
    //m_menu.add(Score_Table, std::make_unique<ScoreTableButton>(this, m_window));
};


//this function is the game loop
void GameControler::run()
{
    //loadMusic();
    //music.play();
    //game loop

    while (m_window.isOpen())
    {
        //display the first window 
        sf::Sprite& m_background = m_menu.getBackground();
        m_background.scale(sf::Vector2f(2.35f, 1.35f));
        m_window.clear(sf::Color::Color(0, 0, 0));
        m_window.draw(m_background);
        drawMenu();
        m_window.display();

        //event from user mouse
        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: //closes the window from the console
                m_window.close();
                break;

            case sf::Event::MouseButtonReleased: //where was preesed
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                handleClick(location, music, musicEnd);
                break;
            }

            case sf::Event::MouseMoved: //shadow 
            {
                auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                handleMouseMoved(location, PLAY, EXIT);
            }
            }
        }
        //exit from the window 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }
    }
}

