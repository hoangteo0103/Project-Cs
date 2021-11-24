#ifndef GameState_H
#define GameState_H
#include "State.h"
#include "Button.h"

class GameState :
    public State
{
private:
    Board board ;
    map<string , Button* > buttons;
    Font font ;
    void initFonts();
    void initButtons();

public:
    GameState(RenderWindow* app , stack<State*> *states);
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

