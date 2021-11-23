#include "MainMenuState.h"

MainMenuState::MainMenuState(RenderWindow* app)
    :State(app)
{
    //this->background->setSize(Vector2f(app->getsize().x, this->app->getsize().y));
    //this->background->setFillcolor(Color::Blue);
}
MainMenuState ::~MainMenuState()
{

}
void MainMenuState::updateKeyBinds()
{

}
void MainMenuState::endState()
{

}
void MainMenuState::update()
{
    this->checkForQuit() ;
    //cout << 1 << endl;
}
void MainMenuState::render(RenderTarget* target)
{
    //if (!target)
    //   target = this->app;

    //target->draw(this->background);
}


