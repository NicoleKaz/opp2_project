#include "Resources.h"


Resources::Resources()
{
	loadTextures();
}

const sf::Texture& Resources::getMenuPlayer(const MenuPlayer player) const
{
	return m_menuPlayers[player];
}


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
	m_menuButton[CHOOSE_LEVEL].loadFromFile("Choose_Level.png");
	m_menuButton[SCORE_TABLE].loadFromFile("ScoreTable.png");
	m_menuButton[EXIT].loadFromFile("Exit.png");

	m_menuPlayers[PLAYER1].loadFromFile("Player1.png");
	m_menuPlayers[PLAYER2].loadFromFile("Player2.png");
	m_menuPlayers[PLAYER3].loadFromFile("Player3.png");

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

//tool bar font
const sf::Font& Resources::getFont() const
{
	return m_font;
}

//Buttones texture
const sf::Texture& Resources::getButton(const Button button)const
{
	return m_menuButton[button];
}

//return the sound
void Resources::playSound(Sound sound)
{
	//m_sound.setBuffer(m_soundVector[sound]);
	//m_sound.play();
}

//return the instruction
sf::Texture& Resources::GetInstruction(Instructions instruction)
{
	return m_InstructionsTextures[instruction];
}

//
const sf::Texture& Resources::getGameTexture(const GameTextures texture) const
{
	return m_game_textures[texture];
}