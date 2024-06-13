#pragma once

#include "HelpButton.h"
#include "Game.h"
#include "WithoutYouButton.h"
#include "GreyhoundButton.h"
#include "OnlyTheHorsesButton.h"
#include "SpectreButton.h"


HelpButton::HelpButton(GameControler* game, sf::RenderWindow& window)
	:Command(game, window)
{
	//adding buttons to the submenu
	//m_levels_menu.add(WithoutYou, std::make_unique<WithoutYouButton>(m_game, m_window));
	//m_levels_menu.add(Greyhound, std::make_unique<GreyhoundButton>(m_game, m_window));
	//m_levels_menu.add(OnlyTheHorses, std::make_unique<OnlyTheHorsesButton>(m_game, m_window));
	//m_levels_menu.add(Spectre, std::make_unique<SpectreButton>(m_game, m_window));
}

void HelpButton::execute()
{
	// ���� ������ �� ����� �����, �������� ���� �� ������� ������� ������ �����
	m_game->helpGame();
}
