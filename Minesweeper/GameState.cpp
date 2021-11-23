#include "GameState.h"

GameState::GameState(RenderWindow* app)
    :State(app)
{

}
GameState ::~GameState()
{

}
void GameState::updateKeyBinds()
{
    this->checkForQuit() ;
}
void GameState::endState()
{
    cout <<"Ending " ;
}
void GameState::update()
{
    this->updateKeyBinds();
    if(Keyboard::isKeyPressed(Keyboard::A))
        cout << "A" <<endl;
}
void GameState::render(RenderTarget* target = nullptr)
{

}
