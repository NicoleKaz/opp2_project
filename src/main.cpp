#include "GameControler.h"
#include <iostream>
#include <thread>
#include <chrono>


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
