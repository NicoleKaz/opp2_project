﻿file(GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        ${MY_SOURCE_FILES}
        "../include/Controller.h"
        "Controller.cpp"
        "../include/Menu.h"
        "Resources.cpp"
        "../include/Resources.h"
        "Board.cpp"
        "../include/Board.h"
        "../include/Command.h"
        "Command.cpp"
        "../include/PlayButton.h"
        "PlayButton.cpp"
        "../include/HelpButton.h"
        "HelpButton.cpp"
        "../include/SwitchPlayerButton.h"
        "../include/ScoreTableButton.h"
        "ScoreTableButton.cpp"
        "../include/ExitGame.h"
        "ExitGame.cpp"
        "../include/Choose_LevelButton.h"
        "../include/Menu.h"
        "Menu.cpp"
        "../include/Resources.h"
        "../include/Controller.h"
        "SwitchPlayerButton.cpp"
        "Choose_LevelButton.cpp"
        "../include/Player1Button.h"
        "Player1Button.cpp"
        "../include/PlayersMenu.h"
        "PlayersMenu.cpp"
        "../include/Player2Button.h"
        "../include/Player3Button.h"
        "Player2Button.cpp"
        "Player3Button.cpp"
        "../include/LevelsMenu.h"
        "LevelsMenu.cpp"
 "../include/Level2_Button.h" "../include/Level3_Button.h" "Level2_Button.cpp" "Level3_Button.cpp" "Player4Button.cpp" "StaticObject.cpp" "../include/StaticObject.h" "../include/Factory.h" "../include/GameObject.h" "GameObject.cpp" "../include/floor.h" "../include/Floor.h" "Floor.cpp")
