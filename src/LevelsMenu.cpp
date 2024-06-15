#pragma once

#include "LevelsMenu.h"

LevelsMenu::LevelsMenu(GameControler* game, sf::RenderWindow& window)
	: m_game(game), m_window(window)
{
	m_background.setTexture(Resources::instance().getMenuTexture(menuBackground));
	m_background.scale(1.6f, 1.6f);

	for (int button = level1; button <= level3; button++)
	{
		m_buttons[button].setTexture(Resources::instance().getLevelsMenu((MenuLevels)button));
	}
	locateObjects();
}


void LevelsMenu::drawLevelsMenu() const
{
	m_window.draw(m_background);
	for (int button = 0; button < m_options.size(); button++)
	{
		m_window.draw(m_buttons[button]);
	}
}

void LevelsMenu::handleMouseMoved(const sf::Vector2f& location)
{
	//for (auto& option : m_options)
	//{
	//	if (option.first.getGlobalBounds().contains(location))
	//	{
	//		option.first.setColor(sf::Color::Yellow);  // Highlight on hover
	//	}
	//	else
	//	{
	//		option.first.setColor(sf::Color::White);  // Reset color
	//	}
	//}
}

void LevelsMenu::handleAction(const sf::Vector2f& location)
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




const int LevelsMenu::getOptionFromUser(const sf::Vector2f location) const
{
	//check if the button contains the click location 
	for (int button = level1; button < m_options.size(); button++)
	{
		if (m_options[button].first.getGlobalBounds().contains(location))
		{
			//return the button we clicked at
			return button;
		}
	}
	//no button
	return m_options.size() + 1;
}

void LevelsMenu::performAction(const int action)const
{
	//if no button pressed
	if (action > m_options.size())
		return;

	m_options[action].second->execute();
}

void LevelsMenu::add(const MenuLevels button, std::unique_ptr<Command> command)
{
	//adding new button to the menu
	m_options.emplace_back(option(m_buttons[button], move(command)));
}


void LevelsMenu::handleLevelMenuMouseMoved(const sf::Vector2f location)
{
	//indicate the location of the mouse 
	for (int button = level1; button < m_options.size(); button++)
	{
		if (m_options[button].first.getGlobalBounds().contains(location))
		{
			//bolding the button
			ButtonPress(MenuLevels(button));
		}
		else
		{
			//unbolding the button
			ButtonRelease(MenuLevels(button));
		}
	}
}

void LevelsMenu::ButtonPress(const MenuLevels button)
{
	m_buttons[button].setColor(sf::Color::Color(255, 255, 255, 150));
}

void LevelsMenu::ButtonRelease(const MenuLevels button)
{
	m_buttons[button].setColor(sf::Color::Color(255, 255, 255));
}

void LevelsMenu::locateObjects()
{
	//level buttons
	m_buttons[level1].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[level1].getTextureRect().width) * 0.25,
		(WINDOW_HEIGHT - m_buttons[level1].getTextureRect().height) * 0.25));

	m_buttons[level2].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[level2].getTextureRect().width) * 0.75,
		(WINDOW_HEIGHT - m_buttons[level2].getTextureRect().height) * 0.25));

	m_buttons[level3].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[level3].getTextureRect().width) * 0.25,
		(WINDOW_HEIGHT - m_buttons[level3].getTextureRect().height) * 0.75));

	/*m_buttons[Spectre].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[Spectre].getTextureRect().width) * 0.75,
		(WINDOW_HEIGHT - m_buttons[Spectre].getTextureRect().height) * 0.75));*/
}
