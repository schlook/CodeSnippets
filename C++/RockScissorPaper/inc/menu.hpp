#ifndef MENU_H
#define MENU_H

#include "include.hpp"
#include "rsp.hpp"

class menu : public rsp
{
public:
	menu(void)
	{
	}

	~menu(void)
	{
	}

	void begin(void)
	{
		// Instead of printing each line, loop through!
		for (const auto &L : this->LINES)
		{
			if (L.empty())
			{
				continue;
			}
			// From parent
			std::cout << L << " ";
			this->delay();
		}
		std::cout << this->SHOOT;

		while (true)
		{
			unsigned short int i = 1;
			for (const auto &L : this->LINES)
			{
				if (L.empty())
				{
					continue;
				}
				std::cout << i << " " << L << '\n';
				i++;
			}

			if (std::cin >> choice.player)
			{
				// Must be between 1 and 3
				if ((choice.player > 0) && (choice.player < sizeof(this->LINES)))
				{
					std::cout << "You have picked "
							  << this->num2word(choice.player) << '\n';
					// Stop the loop
					break;
				}
			}
			// If not, then start over
			std::cout << this->INVALID_OPTION << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

private:
	const std::string INVALID_OPTION = "Not a valid option. Please try again!";
	// How long to wait, in seconds
	unsigned int delaySeconds = 1;
	void delay(void)
	{
		std::this_thread::sleep_for(std::chrono::seconds(this->delaySeconds));
	}
};

#endif