#include "Resources.h"


Resources::Resources()
{
	loadTextures();
}

const sf::Texture& Resources::getMenuPlayer(const MenuPlayer player) const
{
	return m_menuPlayers[player];
}

//return the instruction
const sf::Texture& Resources::getInstruction(const Instructions instruction)const
{
	return m_instructionsTextures[instruction];
}


//const sf::Texture& Resources::getplayersMenuButtons(const LevelsMenuButtons button) const
//{
//	return m_level_menu_buttons[button];
//}


//loading all the textures
void Resources::loadTextures()
{
	m_menuTextures[menuBackground].loadFromFile("menuBackground.png");
	m_menuTextures[menuBackground].setSmooth(true);
	m_menuTextures[Title].loadFromFile("Title.png");
	m_menuTextures[Title].setSmooth(true);

	//menu buttons
	m_menuButton[PLAY].loadFromFile("Play.png");
	m_menuButton[HELP].loadFromFile("Help.png");
	m_menuButton[SWITCH_PLAYER].loadFromFile("Switch_Player.png");
//	m_menuButton[CHOOSE_LEVEL].loadFromFile("Sticker.png");
	m_menuButton[SCORE_TABLE].loadFromFile("ScoreTable.png");
	m_menuButton[EXIT].loadFromFile("Exit.png");

	m_menuPlayers[PLAYER1].loadFromFile("Player1.png");
	m_menuPlayers[PLAYER2].loadFromFile("Player2.png");
	m_menuPlayers[PLAYER3].loadFromFile("Player3.png");
	m_menuPlayers[PLAYER4].loadFromFile("Player4.png");

	m_menuLevel[level1].loadFromFile("Level1.png");
	//m_menuLevel[level2].loadFromFile("Level2.png");
	//m_menuLevel[level3].loadFromFile("Level3.png");

	m_instructionsTextures[GAME_RULES].loadFromFile("instructions.png");
	m_instructionsTextures[STICKER].loadFromFile("Sticker.png");	


	//game textures

	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
}

//
Resources& Resources::instance()
{
	static Resources Resource;
	return Resource;
}

//
const sf::Texture& Resources::getMenuTexture(const MenuTextures texture)const
{
	return m_menuTextures[texture];
}

const sf::Texture& Resources::getLevelsMenu(const MenuLevels button) const
{
	return m_menuLevel[button];

}

//tool bar font
const sf::Font& Resources::getFont() const
{
	return m_font;
}

//Buttones texture
const sf::Texture& Resources::getButton(const Button button)const
{
	return m_menuButton[button];;;
}

//return the sound
void Resources::playSound(Sound sound)
{
	//m_sound.setBuffer(m_soundVector[sound]);
	//m_sound.play();
}

//
const sf::Texture& Resources::getGameTexture(const GameTextures texture) const
{
	return m_game_textures[texture];
}