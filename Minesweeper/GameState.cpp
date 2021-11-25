#include "GameState.h"

void GameState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
}
GameState::GameState(RenderWindow* app ,  stack<State*> *states , int sizeX , int sizeY)
    :State(app,states)
{
    this->sizeX = sizeX ;
    this->sizeY = sizeY;
    this->initFonts() ;
    this->buttons["BACK_TO_MENU_STATE"] = new Button(600, 0 , 200 , 50 ,
                                     &this->font , "Back to Menu" , Color(70,70,70,200)
                                 ,Color(150,150,150,255) , Color(20,20,20,200) ) ;

}

GameState ::~GameState()
{
   auto it = this->buttons.begin();
   for(it = this->buttons.begin(); it!=this->buttons.end() ; ++it)
   {
       delete it->second;
   }
}

void GameState::updateKeyBinds()
{
    this->checkForQuit() ;
}
void GameState::endState()
{
    cout <<"End MainMenu"<<endl;
}
void GameState::updateButtons()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }
    if(this->buttons["BACK_TO_MENU_STATE"]->isPressed())
    {
        this->quit = true ;

        //this->states->push(new GameState(this->app , this->states)) ;
    }
    //if(this->buttons["GAME_QUIT_BTN"]->isPressed())
    //{
    //    this->quit = true ;
    //}
}

void GameState::update()
{
    this->updateMousePositions() ;
    this->updateKeyBinds();
    this->updateButtons() ;
    this->board.update(this->mousePosView) ;
    //system("cls") ;
    //cout << mousePosView.x <<' ' << mousePosView.y <<endl;

}
void GameState::renderButtons(RenderTarget* target )
{
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }
}
void GameState::render(RenderTarget* target )
{
    if (!target)
       target = this->app;
    this->board.render(target);
    this->renderButtons(target);
}


