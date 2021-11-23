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
    cout << "ga" << endl ;
    this->updateKeyBinds();
    if(Keyboard::isKeyPressed(Keyboard::A))
        cout << "A" <<endl;
}
void GameState::render(RenderTarget* target = nullptr)
{

}
