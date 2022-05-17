/*
 * Author: Niklas 'schlook' Karlsson
 * Description:
 * Rock, scissor and paper game.
 */

// I collect all the include files
// That is needed for the project here.
#include "include.hpp"
#include "menu.hpp"

// When using 'auto' keyword we can use decltype
// Set to 0 (return type)
auto main(int argc, const char **argv) -> decltype(0)
// Try someting
try
{
	// std::cout.imbue(std::locale("en_US.utf8"));
	/*
	 * Create pointer
	 * kind of the same as: maze *Maze = new maze();
	 * But std::unique_ptr is constexpr, 'compile-time constant'
	 */
	// auto RSP = std::unique_ptr<rsp>(new rsp);
	auto Menu = std::unique_ptr<menu>(new menu);

	// A do-while must have arguments that make it run at least ONCE.
	// This is a "blocking" loop (since 1 == 1 is true)
	do
	{
		Menu->start();

		Menu->begin();
		// Show results
		Menu->showResult();
		// Show some score
		Menu->showScore();
	} while (1 == 1);

	// The unique_ptr should free when out of scope
	// But just to be sure, we 'reset' it
	Menu.reset();

	// Same as 0
	return 0x0;
}
// If we fail and threw something.
catch (const char *e)
{
	// Using std::endl since this should be the last thing anyway
	std::cerr << "[ERROR] " << e << std::endl;
}
catch (std::string e)
{
	// Using std::endl since this should be the last thing anyway
	std::cerr << "[ERROR] " << e << std::endl;
}
catch (...)
{
	// Using std::endl since this should be the last thing anyway
	std::cerr << "[ERROR] unexpected error!" << std::endl;
}