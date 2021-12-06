#ifndef LEADERBOARDSTATE_H
#define LeaderboardState_H
#include "State.h"
#include "Button.h"
#include "GameState.h"

class LeaderboardState :
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
    LeaderboardState(RenderWindow* app, stack<State*> *states);
    virtual ~LeaderboardState();
    // Functions
    void updateKeyBinds();
    void updateButtons();
    void endState() ;
    void update() ;
    void render(RenderTarget* target = NULL) ;
    void renderButtons(RenderTarget* target = NULL) ;

};
#endif




