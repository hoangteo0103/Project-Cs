#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"
#include "Button.h"
class MainMenuState :
    public State
{
private:
    RectangleShape background ;
    Font font ;
    void initFonts();
public:
    MainMenuState(RenderWindow* app);
    virtual ~MainMenuState();
    // Functions
    void updateKeyBinds();
    void endState() ;
    void update() ;
    void render(RenderTarget* target = NULL) ;

};

#endif // MAINMENUSTATE_H


