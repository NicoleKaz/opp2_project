//#pragma once
//
//#include "Command.h"
//#include <LevelsMenu.h>
//
//class Controller;
//
//class Choose_LevelButton : public Command
//{
//public:
//
//	Choose_LevelButton(Controller* game, sf::RenderWindow& window);
//	void execute() override;
//
//private:
//
//	sf::Sprite m_background;
//	sf::Sprite m_menuLevel[LEVEL_MENU];
//	sf::Sprite m_back_buttons[3];
//	void locateObjects();
//	LevelsMenu m_levelsMenu;
//};