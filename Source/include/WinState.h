#ifndef WINSTATE_H
#define WINSTATE_H
#include "Button.h"
class WinState
{
private :
    RectangleShape background ;
    RectangleShape container;
    Font font ;
    Text menutext ;
    Vector2i mousePosWindow ;
    Vector2f mousePosView  ;

    map<string , Button* > buttons ;
    bool ok ;
    void initFonts();
public :
    WinState();
    virtual ~WinState() ;
    //functions
    void initState(RenderWindow& app) ;
    void updateButtons() ;
    const bool& getOk() const ;
    void updateMousePositions(Vector2f mousePosView);
    void update() ;
    void render(RenderTarget& target) ;
};
#endif // PAUSEMENU_H
