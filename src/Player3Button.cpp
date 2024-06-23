#include "Player3Button.h"
#include "Controller.h"

Player3Button::Player3Button(Controller* game, sf::RenderWindow& window)
    : Command(game, window)
{
}

void Player3Button::execute()
{
    // Execute the player switch logic for Player 1
    m_game->getMenu().choosePlayer(PLAYER1);
    m_game->getBoard().switchPlayer(m_game->getMenu().getPlayerTextures());
}


