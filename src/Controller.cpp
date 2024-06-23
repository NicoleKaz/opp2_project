#include "Controller.h"
#include <thread>
#include <chrono>
#include <iostream>



Controller::Controller()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Geometry Dash"),
    m_menu(m_window),
    m_board(m_window, m_menu.getPlayerTextures())
{
    m_window.setFramerateLimit(120);
    m_gameView.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_gameView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT/2);


    //adding menu buttons:
    m_menu.add(PLAY, std::make_unique<PlayButton>(this, m_window));
    m_menu.add(HELP, std::make_unique<HelpButton>(this, m_window));
    m_menu.add(SWITCH_PLAYER, std::make_unique<SwitchPlayerButton>(this, m_window));
   // m_menu.add(CHOOSE_LEVEL, std::make_unique<Choose_LevelButton>(this, m_window));
    m_menu.add(SCORE_TABLE, std::make_unique<ScoreTableButton>(this, m_window));
    m_menu.add(EXIT, std::make_unique<ExitGame>(this, m_window));
};



//this function is the game loop
void Controller::run()
{
    m_GameClock.restart();
    while (m_window.isOpen())
    {
        //display the first window 
        m_window.clear(sf::Color::Color(0, 0, 0));
        m_menu.drawMenu();
        m_window.display();
        //std::this_thread::sleep_for(std::chrono::seconds(5));

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                m_window.close();
                break;
            }
            case sf::Event::MouseButtonReleased:
            {
                //getting the click location, checking what button pressed
                const auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                // const int button = m_menu.getOptionFromUser(location);l

                 //performing the button action acordinglys
                m_menu.action(location);
                break;
            }
            //case sf::Event::MouseMoved:
            //{
            //    //indicate if the mouse on the buttons 
            //    const auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
            //    m_menu.handleMenuMouseMoved(location);
            //    break;
            //}

            }
        }
    }
}


void Controller::handleSwitchPlayer(const sf::Vector2f location)
{
	//loop to go over the buttons
	for (int player = PLAYER1; player <= PLAYER3; player++)
	{
		//check if a button preesed
		if ((m_menu.getPlayer((MenuPlayer)player).getGlobalBounds().contains(location)))
		{
            m_menu.choosePlayer((MenuPlayer)player);
            break;
		}
	}            
}

void Controller::handleSwitchPlayerMouseMoved(const sf::Vector2f location)
{
	//loop to go over the buttons
    for (int player = PLAYER1; player <= PLAYER3; player++)
    {
	    //check if a button preesed
	    if ((m_menu.getPlayer((MenuPlayer)player).getGlobalBounds().contains(location)))
	    {
		    m_menu.ButtonPress((MenuPlayer)player);
	    }
	    else
	    {
		    m_menu.ButtonRelease((MenuPlayer)player);
	    }
    }

}

Board& Controller::getBoard()
{
    return m_board;
}

//This function checks whether one of the buttons in menu has been pressed
void Controller::handleMenuMouseMoved(const sf::Vector2f location)
{
    //loop to go over the buttons
    for (int player = PLAY; player <= EXIT; player++)
    {
        //check if a button preesed
        if ((m_menu.getButton((Button)player).getGlobalBounds().contains(location)))
        {
            m_menu.ButtonPress((MenuPlayer)player);
        }
        else
        {
            m_menu.ButtonRelease((MenuPlayer)player);
        }
    }
}


//This function performs the action that is called after the user clicks one of the buttons in the menu
void Controller::handleClick(const sf::Vector2f location)
{
    //start the game
    if (m_menu.getButton(PLAY).getGlobalBounds().contains(location))
    {
        //rest the clocks
        //m_MoveClock.restart();
        //open the game window
        //init();
        m_GameClock.restart();
        startGame();
    }
    //exit the game
    if (m_menu.getButton(EXIT).getGlobalBounds().contains(location))
    {
        m_window.close();
    }
}

void Controller::startGame()
{
//    //As long as the user did not exit the game, this loop ran
//    while (m_window.isOpen() /*&& !m_game_over*/)
//    {
//		//The game window is cleared
//        m_window.clear(sf::Color::Color(0, 0, 0));
//        m_window.setView(m_gameView);
//        //Drawing the game board
//        m_board.drawBoard();
//		m_window.display();
//
//        for (auto event = sf::Event{}; m_window.pollEvent(event); )
//        {
//            switch (event.type)
//            {
//            case sf::Event::Closed:
//            {
//                m_window.close();
//                break;
//            }
//            case sf::Event::KeyReleased:
//            {
//                //update the player direction
//                if (event.key.code == sf::Keyboard::Right)
//                {
//                    m_board.rightReleased();
//                }
//                else if (event.key.code == sf::Keyboard::Left)
//                {
//                    m_board.leftReleased();
//                }
//                else if (event.key.code == sf::Keyboard::Space)
//                {
//                    m_board.spaceReleased();
//                }
//                else if (event.key.code == sf::Keyboard::Escape)
//                {
//                    //m_game_over = true;
//                }
//                break;
//            }
//            }
//        }
//        //Exit the game
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//        {
//            m_window.close();
//        }
//    }
}

Menu& Controller::getMenu()
{
    return m_menu;
}

void Controller::helpGame()
{

}

void Controller::SwitchPlayer()
{
}

void Controller::quitGame()
{
    m_window.close();
}

void Controller::chooseLevel()
{
}

