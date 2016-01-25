#include "dice.h"
#include <iostream>
#include "pokemon.h"
#include "colosseum.h"
#include "dice.h"


int main ()
{

pokemon p1;

pokemon p2;

colosseum c1;


char playAgain = 'y';

    while ((playAgain == 'y') || (playAgain == 'Y'))
    {
        std::cout << "Player 1 build your pokemon \n";

        std::cout << "=============================== \n";

        c1.userBuild(p1);

        std::cout << "Player 2 build your pokemon \n";

        std::cout << "=============================== \n";

        c1.userBuild(p2);

        c1.play(p1, p2);

        std::cout << "Do you want to play again? Enter (y/n) \n\n\n";

        std::cin >> playAgain;

    }




return 0;
}
