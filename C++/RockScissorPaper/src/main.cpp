/*
 * Author: Niklas 'schlook' Karlsson
 * Description:
 * Rock, scissor and paper game.
 */

// I collect all the include files
// That is needed for the project here.
#include "include.hpp"

// Declare returntype 0
auto main(int argc, const char **argv) -> decltype(0)
// Try someting
try
{
    game *Game = new game();

    // Endless loop
    while (true)
    {
        Game->start();
        Game->showResult();
        Game->showScore();
    }
    // Same as 0
    return 0x0;
}
// If we fail and threw something.
catch (const char *e)
{
    std::cerr << "[ERROR] " << e << std::endl;
}
catch (...)
{
    std::cerr << "[ERROR] unexpected error!" << std::endl;
}