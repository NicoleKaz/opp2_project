#include "Resources.h"


Resources::Resources()
{
	loadTextures();
}

//loading all the textures
void Resources::loadTextures()
{
	m_menuTextures[menuBackground].loadFromFile("menuBackground.png");
	m_menuTextures[menuBackground].setSmooth(true);
	//m_menu_textures[Title].loadFromFile("Title.png");
	//m_menu_textures[Title].setSmooth(true);


	//menu buttons
	m_menuButton[PLAY].loadFromFile("Play.png");
	m_menuButton[HELP].loadFromFile("Help.png");
	m_menuButton[SWITCH_PLAYER].loadFromFile("Switch_Player.png");
	m_menuButton[SCORE_TABLE].loadFromFile("ScoreTable.png");
	m_menuButton[EXIT].loadFromFile("Exit.png");

	////loading all images
	//m_textureVec.resize(TextureObject::t_Total);
	//m_textureVec[TextureObject::t_wall].loadFromFile("wall.png");
	//m_textureVec[TextureObject::t_door].loadFromFile("door.png");
	//m_textureVec[TextureObject::t_cat].loadFromFile("cat.png");
	//m_textureVec[TextureObject::t_mouse].loadFromFile("mouse.png");
	//m_textureVec[TextureObject::t_cheese].loadFromFile("cheese.png");
	//m_textureVec[TextureObject::t_key].loadFromFile("key.png");
	//m_textureVec[TextureObject::t_present].loadFromFile("present.png");
	//m_textureVec[TextureObject::t_timeGift].loadFromFile("time.png");
	//m_textureVec[TextureObject::t_lifeGift].loadFromFile("life.png");
	//m_textureVec[TextureObject::t_freezeGift].loadFromFile("freeze.png");

	//loading all buttones
	for (int button = PLAY; button <= BACK; button++)
	{
		//m_menuButton[button].loadFromFile(m_ButtonFiles[button]);
		//m_menuButton[button].setSmooth(true);
	}

	//for (int instruction = GAME_RULES; instruction <= GAME_RULES; instruction++)
	//{
	//	//m_InstructionsTextures[instruction].loadFromFile(m_InstructionFiles[instruction]);
	//	//m_InstructionsTextures[instruction].setSmooth(true);
	//}
	//loading all soundes
	//for (int sound = CLICK; sound <= EXTRA_LIFE; sound++)
	//{
	//	sf::SoundBuffer sounddd;
	//	sounddd.loadFromFile(m_SoundFiles[sound]);
	//	m_soundVector.push_back(sounddd);
	//}
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
}

Resources::~Resources()
{}


Resources& Resources::instance()
{
	static Resources Resource;
	return Resource;
}

//return the obj texture
const sf::Texture& Resources::getTexture(TextureObject texObj) const
{
	return m_textureVec[texObj];
}

const sf::Texture& Resources::getMenuTexture(const MenuTextures texture) const
{
	return m_menuTextures[texture];
}

//tool bar font
const sf::Font& Resources::getFont() const
{
	return m_font;
}

//Buttones texture
sf::Texture& Resources::getButton(Button button)
{
	return m_menuButton[button];
}

//return the sound
void Resources::playSound(Sound sound)
{
//	m_sound.setBuffer(m_soundVector[sound]);
	//m_sound.play();
}

//return the instruction
sf::Texture& Resources::GetInstruction(Instructions instruction)
{
	return m_InstructionsTextures[instruction];
}

const sf::Texture& Resources::getGameTexture(const GameTextures texture) const
{
	return m_game_textures[texture];
}