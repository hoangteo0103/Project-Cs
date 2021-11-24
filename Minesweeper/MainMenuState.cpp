#include "MainMenuState.h"

void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
}
void MainMenuState::initButtons()
{

}
MainMenuState::MainMenuState(RenderWindow* app ,stack<State*> *states )
    :State(app,states)
{
    this->initFonts() ;
    this->buttons["GAME_STATE_BTN"] = new Button(100 , 100 , 150 , 50 ,
                                     &this->font , "New Game" , Color(70,70,70,200)
                                 ,Color(150,150,150,255) , Color(20,20,20,200) ) ;
    this->buttons["GAME_QUIT_BTN"] = new Button(150 , 150 , 150 , 50 ,
                                     &this->font , "Exit" , Color(70,70,70,200)
                                 ,Color(100,100,100,255) , Color(20,20,20,200) ) ;
    this->background.setSize(Vector2f(app->getSize().x, app->getSize().y));
    this->background.setFillColor(Color::Blue);
}
MainMenuState ::~MainMenuState()
{
   auto it = this->buttons.begin();
   for(it = this->buttons.begin(); it!=this->buttons.end() ; ++it)
   {
       delete it->second;
   }
}

void MainMenuState::updateKeyBinds()
{
    this->checkForQuit() ;
}
void MainMenuState::endState()
{
    cout <<"End MainMenu"<<endl;
}
void MainMenuState::updateButtons()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }
    if(this->buttons["GAME_STATE_BTN"]->isPressed())
    {
        this->states->push(new GameState(this->app , this->states)) ;
    }
    if(this->buttons["GAME_QUIT_BTN"]->isPressed())
    {
        this->quit = true ;
    }
}

void MainMenuState::update()
{
    this->updateMousePositions() ;
    this->updateKeyBinds();
    this->updateButtons() ;
    system("cls") ;
    cout << mousePosView.x <<' ' << mousePosView.y <<endl;

}
void MainMenuState::renderButtons(RenderTarget* target )
{
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }
}
void MainMenuState::render(RenderTarget* target )
{
    if (!target)
       target = this->app;

    target->draw(this->background);
    this->renderButtons(target);
}
