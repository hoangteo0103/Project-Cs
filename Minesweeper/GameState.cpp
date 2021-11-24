#include "GameState.h"

GameState::GameState(RenderWindow* app ,  stack<State*> *states)
    :State(app,states){}
GameState ::~GameState()
{

}
void GameState::updateKeyBinds()
{
    this->checkForQuit() ;
}
void GameState::endState()
{
    cout <<"Ending GameState" ;
}
void GameState::update()
{
    this->updateMousePositions() ;
    this->updateKeyBinds();
    //if(Mouse::isButtonPressed(Mouse::Left))
    //this->board.update(mousePosWindow.x , mousePosWindow.y) ;
}
void GameState::render(RenderTarget* target)
{
    this->board.render(this->app) ;
}
