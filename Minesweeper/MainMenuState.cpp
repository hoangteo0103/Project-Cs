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
    this->checkForQuit() ;
}
void MainMenuState::endState()
{
    cout <<"End MainMenu"<<endl;
}
void MainMenuState::update()
{
    this->updateKeyBinds();
}
void MainMenuState::render(RenderTarget* target)
{
    //if (!target)
    //   target = this->app;

    //target->draw(this->background);
}


