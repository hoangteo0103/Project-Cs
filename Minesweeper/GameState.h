#ifndef GameState_H
#define GameState_H
#include "State.h"
class GameState :
    public State
{
private:

public:
    GameState(RenderWindow* app);
    virtual ~GameState();
    // Functions
    void endState() ;
    void update() ;
    void render(RenderTarget* target) ;

};
#endif

