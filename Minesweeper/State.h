#ifndef STATE_H
#define STATE_H

#include "Board.h"
class State
{
protected:
    RenderWindow* app;
    bool quit ;
    Vector2i mousePosWindow ;
    Vector2f mousePosView  ;

public:
    State(RenderWindow* app);
    virtual ~State();
    // Functions
    const bool& getQuit() const ;
    virtual void checkForQuit() ;
    virtual void updateKeyBinds() = 0 ;
    virtual void updateMousePositions();
    virtual void endState() = 0 ;
    virtual void update() = 0 ;
    virtual void render(RenderTarget* target = nullptr) = 0 ;

};
#endif
