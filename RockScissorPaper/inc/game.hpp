#include "include.hpp"

class game
{
public:
    /*
     * Constructor
     */
    game(void)
    {
        // Stuff that shall be init first
    }

    /* 
     * Destructor
     */
    ~game(void)
    {
        // Delete some stuff here
    }

    /*
     * Start method, call when to start the game
     */
    void start(void)
    {
        // Set random device to r
        std::random_device r;
        // Choose a random mean between 1 and 3
        std::default_random_engine e1(r());
        // We only need a number from 1 to 3
        std::uniform_int_distribution<unsigned short int> uniform_dist(1, 3);
        // Set the mean between 1 and 3 (going to be same, alot)
        this->cChoice = uniform_dist(e1);
        // Call the menu method
        this->menu();
    }

    /*
     * Menu method
     */
    void menu(void)
    {
        // Loop as long as it's true
        while (true)
        {
            std::cout << "Please make a choice: " << std::endl
                      << "1. Paper" << std::endl
                      << "2. Scissor" << std::endl
                      << "3. Paper" << std::endl;

            if (std::cin >> this->pChoice)
            {
                // Must be between 1 and 3
                if ((this->pChoice > 0) && (this->pChoice < 4))
                {
                    std::cout << "You have picked "
                              << this->num2word(this->pChoice)
                              << std::endl;
                    // Stop the loop
                    break;
                }
            }
            // If not, then start over
            std::cout << "Not a valid option. Please try again!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    /*
     * Translate a number into a word
     * 1 = Rock
     * 2 = Scissor
     * 3 = Paper
     */
    const char *num2word(unsigned int choice)
    {
        // Switch the choice (plyaer or computer)
        switch (choice)
        {
        case 1:
            return "rock";
        case 2:
            return "scissor";
        case 3:
            return "paper";
        default:
            /* 
             * If somethings not right
             * Dont add anything here, we'll return it
             * below anyway
             */
            break;
        }
        // If something didn't match the cases in the switch
        return "Choice out of range!";
    }

    // Show the user it's results
    void showResult(void)
    {
        //
        std::cout << "_Rock_" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "_Scissor_" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "_Paper_" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if ((this->pChoice > 0) && (this->cChoice > 0))
        {
            // Tell what he computer rolled.
            std::cout << "The game picked "
                      << this->num2word(this->cChoice)
                      << std::endl;
            /*
             * All scenarios where it's a tie
             * Meaning if the computers choice
             * is the same as the player choice
             * then it is a tie! 
             * No matter the result.
             */
            if (this->cChoice == this->pChoice)
            {
                std::cout << "It's a tie!" << std::endl;
            }
            /*
             * All scenarios where the player win
             * 1 (rock) gets beaten by 3 (paper)
             * 2 (scissor) gets beaten by 1 (rock)
             * 3 (paper) gets beaten by 2 (scissor)
             */
            else if (((this->cChoice == 1) && (this->pChoice == 3)) ||
                     ((this->cChoice == 2) && (this->pChoice == 1)) ||
                     (this->cChoice == 3) && (this->pChoice == 2))
            {
                std::cout << "You won!" << std::endl;
                this->player++;
            }
            /*
             * All scenarios where the computer wins
             * 1 (rock) beats 2 (scissor)
             * 2 (scissor) beats 3 (paper)
             * 3 (paper) beats 1 (rock)
             */
            else if (((this->cChoice == 1) && (this->pChoice == 2)) ||
                     ((this->cChoice == 2) && (this->pChoice == 3)) ||
                     (this->cChoice == 3) && (this->pChoice == 1))
            {
                std::cout << "The bot won!" << std::endl;
                this->computer++;
            }
            /*
             * Anything out of the unusual
             */
            else
            {
                throw "Choice is out of range!";
            }
        }
    }

    // "Hidden" from the outside.
private:
    int player;
    int computer;
    int pChoice = 0, cChoice = 0;
};