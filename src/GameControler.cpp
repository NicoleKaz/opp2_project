#include "GameControler.h"


GameControler::GameControler()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Geometry Dash"),
    m_menu(m_window),
    m_board(m_window, m_menu.getPlayerTextures())
{
    m_window.setFramerateLimit(120);
    m_gameView.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_gameView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    //adding menu buttons:
    m_menu.add(Play, std::make_unique<PlayButton>(this, m_window));
    m_menu.add(Help, std::make_unique<HelpButton>(this, m_window));
    m_menu.add(Box, std::make_unique<BoxButton>(this, m_window));
    m_menu.add(Score_Table, std::make_unique<ScoreTableButton>(this, m_window));
};