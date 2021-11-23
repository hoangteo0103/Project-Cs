#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"


class MainMenuState :
    public State
{
private:
    RectangleShape background;

public:
    MainMenuState(RenderWindow* app);
    virtual ~MainMenuState();
    // Functions
    void updateKeyBinds();
    void endState() ;
    void update() ;
    void render(RenderTarget* target) ;

};

#endif // MAINMENUSTATE_H


