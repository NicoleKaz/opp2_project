#include "GameControler.h"
#include <iostream>

int main()
{
    try
    {
        GameControler game;
        game.run();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}
