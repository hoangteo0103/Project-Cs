#ifndef GameState_H
#define GameState_H
#include "State.h"
class GameState :
    public State
{
private:
    Board board ;

public:
    GameState(RenderWindow* app , stack<State*> *states);
    virtual ~GameState();
    // Functions
    void updateKeyBinds();
    void endState() ;
    void update() ;
    void render(RenderTarget* target) ;

};
#endif

