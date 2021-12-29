#ifndef SelectionState_H
#define SelectionState_H
#include "State.h"
#include "Button.h"
#include "GameState.h"

class SelectionState :
    public State
{
private:
    Board board ;
    map<string, Button* > buttons;
    Font font ;
    Texture texture ;
    Sprite background;
    int sizeX , sizeY ;
    int numberOfBombs;
    void initFonts();
    void initButtons();
    void initCustom() ;

public:
    SelectionState(RenderWindow* app, stack<State*> *states);
    virtual ~SelectionState();
    // Functions
    void updateKeyBinds();
    void updateCustom() ;
    void updateButtons();
    void endState() ;
    void update() ;
    void render(RenderTarget* target = NULL) ;
    void renderButtons(RenderTarget* target = NULL) ;

};
#endif



