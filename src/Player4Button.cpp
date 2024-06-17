#include "Player4Button.h"
#include "GameControler.h"

Player4Button::Player4Button(GameControler* game, sf::RenderWindow& window)
    : Command(game, window)
{
}

void Player4Button::execute()
{
    // Execute the player switch logic for Player 1
    m_game->getMenu().choosePlayer(PLAYER1);
    m_game->getBoard().switchPlayer(m_game->getMenu().getPlayerTextures());
}


