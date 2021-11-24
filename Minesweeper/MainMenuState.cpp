#include "MainMenuState.h"

void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
}
MainMenuState::MainMenuState(RenderWindow* app)
    :State(app)
{
    this->initFonts() ;
    this->background.setSize(Vector2f(app->getSize().x, app->getSize().y));
    this->background.setFillColor(Color::Blue);
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
    this->updateMousePositions() ;
    this->updateKeyBinds();
    system("cls") ;
    cout << mousePosView.x <<' ' << mousePosView.y <<endl;
   // if(MouseButtonPressed::Mouse::Left) cout << 1;
}
void MainMenuState::render(RenderTarget* target )
{
    if (!target)
       target = this->app;

    target->draw(this->background);
}


