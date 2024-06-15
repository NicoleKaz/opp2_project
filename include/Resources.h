#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <string.h>
#include <vector>

//enum
enum Instructions { GAME_RULES, STICKER };
enum Button { PLAY, HELP, SWITCH_PLAYER,CHOOSE_LEVEL, SCORE_TABLE, EXIT };
enum ButtonHelp {BACK, VIDEO_PLAY};
enum Direction { Up, Down, Right, Left, Stay };
enum ToolBarWord { LIFE, SCORE, LEVEL, TIME, KEYCOUNTER };
enum Sound { CLICK, MINUS_LIFE, EAT, CLOCK_SOUND, DOOR_SOUND, FREEZE_SOUND, KEY_SOUND, GAME_OVER, WIN, EXTRA_LIFE };
enum Music { SONG, SECOND_END };
enum Object { MOUSE, KEY, WALL, DOOR, CHEESE, PRESENT, ADD_LIFE, FREEZE, ADD_TIME };
enum MenuTextures { menuBackground, Title};
enum MenuPlayer { PLAYER1, PLAYER2, PLAYER3};



enum GameTextures {
	Floor, Level_Background, First_Player, Second_Player, Third_Player, PlayerBox4, PlayerBox5, PlayerBox6,
	PlayerShip1, PlayerShip2, PlayerShip3, PlayerShip4, PlayerShip5, PlayerShip6, Spike1, Spike2, Spikes,
	Coin, Cube1, Cube2, CubeCube, Gate1, Gate2, Gate3, Gate4, Gate5, Jumper1, Jumper2, Rectangle,
	Enemy1SpriteSheet, Enemy2SpriteSheet, Enemy1, Enemy2, ScoreBoard
};


//consts
const int MENU_BUTTONS = 6;
const int MENU_PLAYER = 3;
const int INSTRUCTIONS = 2;
const int GAME_OBJECTS = 9;
const int TOOL_BAR = 5;
const int SOUNDS = 10;
const int MUSIC = 2;
const float SPRITE_SIZE = 400.f;
const int MENU_TEXTURES = 2;

const int GAME_TEXTURES = 34;


//window
const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 1400;


class Resources
{
public:
	Resources(); //private so there will be no duplicates
	const sf::Texture& getMenuPlayer(const MenuPlayer player) const;
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;
	static Resources& instance(); //static so the resources will called once

	const sf::Font& getFont() const;
	const sf::Texture& getInstruction(const Instructions)const;
	const sf::Texture& getGameTexture(const GameTextures texture) const;
	const sf::Texture& getMenuTexture(const MenuTextures)const;
	const sf::Texture& getButton(const Button)const;
	void playSound(Sound);

private:
	void loadTextures();
	sf::Texture m_menuTextures[MENU_TEXTURES];
	sf::Texture m_menuButton[MENU_BUTTONS];
	sf::Texture m_instructionsTextures[INSTRUCTIONS];
	sf::Texture m_game_textures[GAME_TEXTURES];
	sf::Texture m_menuPlayers[MENU_PLAYER];


	std::vector<sf::Texture> m_MenuTexture;

	sf::Font m_font;
	sf::CircleShape player;
	//sf::Sound m_sound;
//	sf::Music m_music;

	//std::vector<sf::Texture> m_textureVec;
	//std::vector<sf::SoundBuffer> m_soundVector;
//	std::vector<sf::Music> m_musicVector;
	/*std::string m_ButtonFiles[BUTTONS] = { "Play.png", "Help.png", "Exit.png" , "VideoPlay.png" , "Back.png" };
	std::string m_MusicFiles[MUSIC] = { "Song.wav","5_second_end.wav" };
	std::string m_InstructionFiles[INSTRUCTIONS] = { "GameRules.png" };
	std::string m_SoundFiles[SOUNDS] = { "Click.ogg", "MinusLife.ogg", "Eat.ogg", "ClockSound.ogg",
									"DoorSound.ogg" , "FreezeSound.ogg" ,
									 "KeySound.ogg" , "GameOver.ogg","win.ogg", "ExtraLifeSound.ogg" };*/
};