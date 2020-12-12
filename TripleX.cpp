#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "You are a secret agent breaking into a level " << Difficulty << " secure server room.\n";
    std::cout << "You need to enter the correct codes to continue.\n";      
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    int GuessA, GuessB, GuessC;

    std::cout << std::endl;
    std::cout << "* There are 3 numbers in the code.\n";
    std::cout << "* The codes add up to: " << CodeSum << std::endl;
    std::cout << "* And the codes multiply to: " << CodeProduct << "\n\n";

    std::cout << "Enter First Number (0-9): ";
    std::cin >> GuessA;
    std::cout << "\nEnter Second Number (0-9): ";
    std::cin >> GuessB;
    std::cout << "\nEnter Third Number (0-9): ";
    std::cin >> GuessC;
    std::cout << std::endl;
 
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    if (GuessSum == CodeSum && GuessProduct == CodeProduct && Difficulty < 5)
    {
        std::cout << "********************";
        std::cout << " Nice job!!! Move to level " << ++Difficulty << ".";
        std::cout << "********************\n\n";
        return true;
    }
    else if (GuessSum == CodeSum && GuessProduct == CodeProduct && Difficulty == 5)
    {
        std::cout << "************";
        std::cout << " Awesome!!! You have mastered each level and win the game! ";
        std::cout << "************\n\n";
        return true;
    }
    else
    {
        std::cout << "****************************";
        std::cout << " You lose!!! Try again. ";
        std::cout << "****************************\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //seeds rand() to create a new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errros
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }
        
    }
    
    
    return 0;
}