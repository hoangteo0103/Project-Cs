#include "GameState.h"

GameState::GameState(RenderWindow* app)
    :State(app){}
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
    //cout << "ga" << endl ;
    this->updateKeyBinds();
    this->board.update();
}
void GameState::render(RenderTarget* target)
{
    this->board.render(this->app) ;
}
