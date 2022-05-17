#ifndef RSP_H
#define RSP_H

#include "include.hpp"
#include "stats.hpp"

class rsp : public stats
{
public:
	/*
	 * Constructor
	 */
	rsp(void)
	{
		// Here we can assign class-variables and other things
	}

	/*
	 * Destructor
	 */
	~rsp(void)
	{
		// Delete some stuff here
	}

	/*
	 * Start method, call when to start the game, generate new number each time
	 */
	void start(void)
	{
		// Set random device to r
		std::random_device r;
		// Choose a random mean between 1 and 3
		std::default_random_engine comp(r());
		// We only need a number from 1 to 3
		std::uniform_int_distribution<unsigned short int> uniform_dist(1, 3);
		// Set the mean between 1 and 3 (going to be same, alot)
		choice.computer = uniform_dist(comp);
	}

	// Show the user it's results
	void showResult(void)
	{
		if ((this->choice.computer > 0) && (this->choice.player > 0))
		{
			// Tell what he computer rolled.
			std::cout << "The computer chose "
					  << this->num2word(this->choice.computer)
					  << std::endl;
			/*
			 * All scenarios where it's a tie
			 * Meaning if the computers choice
			 * is the same as the player choice
			 * then it is a tie!
			 * No matter the result.
			 */
			if (choice.computer == choice.player)
			{
				std::cout << WHO_WON[2];
			}
			/*
			 * All scenarios where the player win
			 * 1 (rock) gets beaten by 3 (paper)
			 * 2 (scissor) gets beaten by 1 (rock)
			 * 3 (paper) gets beaten by 2 (scissor)
			 */
			else if (((this->choice.computer == 1) && (this->choice.player == 3)) ||
					 ((this->choice.computer == 2) && (this->choice.player == 1)) ||
					 (this->choice.computer == 3) && (this->choice.player == 2))
			{
				std::cout << WHO_WON[0];
				this->updatePlayer();
			}
			/*
			 * All scenarios where the computer wins
			 * 1 (rock) beats 2 (scissor)
			 * 2 (scissor) beats 3 (paper)
			 * 3 (paper) beats 1 (rock)
			 */
			else if (((this->choice.computer == 1) && (this->choice.player == 2)) ||
					 ((this->choice.computer == 2) && (this->choice.player == 3)) ||
					 (this->choice.computer == 3) && (this->choice.player == 1))
			{
				std::cout << WHO_WON[1];
				this->updateComputer();
			}
			/*
			 * Anything out of the unusual
			 */
			else
			{
				throw this->OUT_OF_RANGE;
			}
		}
	}

	/*
	 * Translate a number into a word
	 * 1 = Rock
	 * 2 = Scissor
	 * 3 = Paper
	 */
	std::string num2word(unsigned int choice)
	{
		// Switch the choice (plyaer or computer)
		switch (choice)
		{
		case 1:
			return this->LINES[0];
		case 2:
			return this->LINES[1];
		case 3:
			return this->LINES[2];
		case 0:
		default:
			/*
			 * If somethings not right
			 * Dont add anything here, we'll return it
			 * below anyway
			 */
			break;
		}
		// If something didn't match the cases in the switch
		return this->OUT_OF_RANGE;
	}

	void showScore(void)
	{
		this->tellScore();
	}

protected:
	enum class hand : unsigned int
	{
		ERROR = 0,
		ROCK = 1,
		SCISSOR = 2,
		PAPER = 3
	};

	const std::string LINES[4] = {"Rock", "Scissor", "Paper"};
	const std::string SHOOT = "Shoot!\n";

	// start at zero
	struct Choice
	{
		unsigned short int player = 0;
		unsigned short int computer = 0;
	} choice;

	// "Hidden" from the outside.
private:
	// Loop through these.
	const std::string WHO_WON[3] = {"\e[0;32mYou won!\e[0m\n",
									"\e[0;31mThe computer won!\e[0m\n",
									"\e[41mIt's a tie!\e[0m\n"};

	const std::string OUT_OF_RANGE = "Choice is out of range!\n";
	// How long to wait, in seconds
	unsigned int delaySeconds = 1;
	void delay(void)
	{
		std::this_thread::sleep_for(std::chrono::seconds(this->delaySeconds));
	}
};

#endif