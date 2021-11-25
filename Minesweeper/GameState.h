#ifndef GameState_H
#define GameState_H
#include "State.h"
#include "Button.h"

class GameState :
    public State
{
private:
    Board board ;
    map<string, Button* > buttons;
    Font font ;
    int sizeX , sizeY ;
    int numberOfBombs;
    void initFonts();
    void initButtons();

public:
    GameState(RenderWindow* app, stack<State*> *states ,int sizeX , int sizeY , int numberOfBombs);
    virtual ~GameState();
    // Functions
    void updateKeyBinds();
    void updateButtons();
    void endState() ;
    void update() ;
    void render(RenderTarget* target = NULL) ;
    void renderButtons(RenderTarget* target = NULL) ;

};
#endif


