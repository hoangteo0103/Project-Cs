#ifndef AUTHORSTATE_H
#define AuthorState_H
#include "State.h"
#include "Button.h"
#include "GameState.h"

class AuthorState :
    public State
{
private:

    map<string, Button* > buttons;
    Font font ;
    Texture texture ;
    Sprite background;
    void initFonts();
    void initButtons();

public:
    AuthorState(RenderWindow* app, stack<State*> *states);
    virtual ~AuthorState();
    // Functions
    void updateKeyBinds();
    void updateButtons();
    void endState() ;
    void update() ;
    void render(RenderTarget* target = NULL) ;
    void renderButtons(RenderTarget* target = NULL) ;

};

#endif // AUTHORSTATE_H_INCLUDED
