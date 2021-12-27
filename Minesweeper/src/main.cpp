#include "Game.h"
#include<conio.h>
using namespace sf;
int main()
{
    srand(time(0));
    Game game;
    game.run() ;
    getch() ;
    return 0;
}

