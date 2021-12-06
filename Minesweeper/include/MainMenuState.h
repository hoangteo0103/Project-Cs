#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "LeaderboardState.h"
#include "SelectionState.h"
#include "AuthorState.h"
#include "GameState.h"
class MainMenuState :
    public State
{
private:
    Texture t ;
    Sprite background;
    Font font ;
    map<string, Button* > buttons;
    void initFonts();
    void initButtons() ;

public:
    MainMenuState(RenderWindow* app, stack<State*> *states);
    virtual ~MainMenuState();
    // Functions
    bool checkSaved() ;
    void updateKeyBinds();
    void updateButtons();
    void endState() ;
    void update() ;
    void render(RenderTarget* target = NULL) ;
    void renderButtons(RenderTarget* target = NULL) ;

};

#endif // MAINMENUSTATE_H



