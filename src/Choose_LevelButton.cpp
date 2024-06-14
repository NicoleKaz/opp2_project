#pragma once

#include "Choose_LevelButton.h"
#include "GameControler.h"
//#include "WithoutYouButton.h"
//#include "GreyhoundButton.h"
//#include "OnlyTheHorsesButton.h"
//#include "SpectreButton.h"


Choose_LevelButton::Choose_LevelButton(GameControler* game, sf::RenderWindow& window)
	:Command(game, window)
{
	//adding buttons to the submenu
	//m_levels_menu.add(WithoutYou, std::make_unique<WithoutYouButton>(m_game, m_window));
	//m_levels_menu.add(Greyhound, std::make_unique<GreyhoundButton>(m_game, m_window));
	//m_levels_menu.add(OnlyTheHorses, std::make_unique<OnlyTheHorsesButton>(m_game, m_window));
}

void Choose_LevelButton::execute()
{
	// כאשר לוחצים על כפתור המשחק, הפונקציה תבצע את הפעולות הנדרשות להתחלת המשחק
	m_game->chooseLevel();

}
