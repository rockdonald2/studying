/*#include "iostream"

//TMP factorial func
template<unsigned n>
struct Factorial
{
    enum { value = n * Factorial<n-1>::value};
};

//ending termen
template<>
struct Factorial<0>
{
    enum { value = 1};
};

//factorial func, w/ long double 12bytes
long double factorialFunc(long double num)
{
    if (num > 1)
        return num * factorialFunc(num - 1);
    else {
        return 1;
    }
}

int main()
{
    std::cout << Factorial<5>::value << "\n";

    long double lD{5};
    std::cout << factorialFunc(lD);
    return 0;
}*/

/*#include "iostream"
#include "stdlib.h"
#include "time.h"

int guessNumber()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    static int number{ 0 };
    number = (rand() % 10) + 1;
    return number;
}

int getPlayerChoice()
{
    static int playerNumber{ 0 };
    std::cout << "Enter your guess: ";
    std::cin >> playerNumber;

    return playerNumber;
}

bool game()
{
    bool result{ false };
    static int maxTryOpportunities{ 5 };
    int number = guessNumber();
    int playerNumber{ 0 };

    std::cout << "Let's start the game. Guess a number from 1 to 10.\n";


    while (maxTryOpportunities)
    {
        playerNumber = getPlayerChoice();
        if (playerNumber == number)
        {
            std::cout << "You guessed it right. The number was: " << number << "\n";
            return true;
        }
        else
        {
            std::cout << "Wrong guess. Try again.\n";
            --maxTryOpportunities;
        }
    }

    return result;
}

int main()
{
    game();

    return 0;
}*/

