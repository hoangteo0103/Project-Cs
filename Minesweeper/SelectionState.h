#ifndef SelectionState_H
#define SelectionState_H
#include "State.h"
#include "Button.h"
#include "GameState.h"
#include "MainMenuState.h"

class SelectionState :
    public State
{
private:
    Board board ;

    map<string, Button* > buttons;
    Font font ;

    int Sz_x , Sz_y ;
    int numberOfBombs;
    void initFonts();
    void initButtons();

public:
    SelectionState(RenderWindow* app, stack<State*> *
                   );
    virtual ~SelectionState();
    // Functions
    void updateKeyBinds();
    void updateButtons();
    void endState() ;
    void update() ;
    void render(RenderTarget* target = NULL) ;
    void renderButtons(RenderTarget* target = NULL) ;

};
#endif



