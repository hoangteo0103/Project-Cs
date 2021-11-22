#ifndef GAME_H
#define GAME_H
#include "State.h"
using namespace sf;
using namespace std;
class Game
{
private:
    //Variables
    RenderWindow *app;
    Event sfEvent ;

    //Initialization
    void initWindow();

public:
    Game();
    int w = 32;
    virtual ~ Game() ;
    // Functions
    void updateSFMLEvents() ;
    void update();
    void render();
    void run();

};
#endif
