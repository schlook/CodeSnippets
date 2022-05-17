#ifndef STATS_H
#define STATS_H

#include "include.hpp"

class stats
{
public:
	stats(void)
	{
	}

	~stats(void)
	{
	}

protected:
	void tellScore(void)
	{
		std::cout << std::setfill(this->HEADER_SIGN) << std::setw(this->WIDTH) << "STATS";
		std::cout << std::setfill(this->HEADER_SIGN) << std::setw(this->WIDTH) << '\n';
		this->victories(this->LEXI[0], this->score.player);

		this->delay();

		this->victories(this->LEXI[1], this->score.computer);

		this->delay();

		if (score.player > score.computer)
		{
			std::cout << this->LEXI[2] << '\n';
		}
		else if (score.player < score.computer)
		{
			std::cout << this->LEXI[3] << '\n';
		}
		else if (score.player == score.computer)
		{
			std::cout << this->LEXI[4] << '\n';
		}
		else
		{
			std::cout << this->UNKNOWN << '\n';
		}

		std::cout << std::setfill(this->HEADER_SIGN) << std::setw(this->WIDTH) << "STATS";
		std::cout << std::setfill(this->HEADER_SIGN) << std::setw(this->WIDTH) << '\n';

		this->delay();
	}

	bool updatePlayer()
	{
		this->score.player++;

		return true;
	}

	bool updateComputer()
	{
		this->score.computer++;

		return true;
	}

	struct Score
	{
		unsigned int player = 0;
		unsigned int computer = 0;
	} score;

private:
	// Victory or victories
	const std::string VICTORY[2] = {" victory", " victories"};
	// Lexicon
	const std::string LEXI[5] = {"The player has ", "The computer has ",
								 "Player is in the lead ", "Computer is in the lead ",
								 "Nobody is in the lead! (tie) "};
	// The unkown side
	const std::string UNKNOWN = "You should not be getting this. Please try again!";
	const char HEADER_SIGN = '=';
	unsigned int WIDTH = 20;
	// How long to wait, in seconds
	unsigned int delaySeconds = 1;
	void delay(void)
	{
		std::this_thread::sleep_for(std::chrono::seconds(this->delaySeconds));
	}
	// Add to string and the score (s)
	void victories(const std::string addString, unsigned int s)
	{
		std::cout << addString << s << ((s > 1) ? this->VICTORY[1] : this->VICTORY[0]) << '\n';
	}
};

#endif