#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include "Button.h"
class PauseMenu
{
private :
    RectangleShape background ;
    RectangleShape container;
    Font font ;
    Text menutext ;
    Vector2i mousePosWindow ;
    Vector2f mousePosView  ;

    map<string , Button* > buttons ;
    bool resume ;
    void initFonts();
public :
    PauseMenu();
    virtual ~PauseMenu() ;
    //functions
    void initState(RenderWindow& app) ;
    void updateButtons() ;
    const bool& getResume() const ;
    void updateMousePositions(Vector2f mousePosView);
    void update() ;
    void render(RenderTarget& target) ;
};
#endif // PAUSEMENU_H

