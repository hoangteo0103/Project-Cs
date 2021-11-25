
#include "SelectionState.h"


void SelectionState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
}
SelectionState::SelectionState(RenderWindow* app ,  stack<State*> *states)
    :State(app,states)
{
    this->initFonts() ;
    this->buttons["BACK_TO_MENU_STATE"] = new Button(0,0, 150 , 50 ,
                                     &this->font , "Back to Menu" , Color(70,70,70,200)
                                 ,Color(150,150,150,255) , Color(20,20,20,200) ) ;
    this->buttons["GAME_STATE"] = new Button(150, 150 , 150 , 50 ,
                                     &this->font , "Play" , Color(70,70,70,200)
                                 ,Color(150,150,150,255) , Color(20,20,20,200) ) ;

}

SelectionState ::~SelectionState()
{
   auto it = this->buttons.begin();
   for(it = this->buttons.begin(); it!=this->buttons.end() ; ++it)
   {
       delete it->second;
   }
}
void SelectionState::updateKeyBinds()
{
    this->checkForQuit() ;
}
void SelectionState::endState()
{
    cout <<"End MainMenu"<<endl;
}
void SelectionState::updateButtons()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }
    if(this->buttons["BACK_TO_MENU_STATE"]->isPressed())
    {
        this->quit = true ;
    }
    if(this->buttons["GAME_STATE"]->isPressed())
    {
       this->states->push(new GameState(this->app , this->states , 10 , 10 , 10)) ;
        this->quit = true ;
    }
}

void SelectionState::update()
{

    this->updateMousePositions() ;
    this->updateKeyBinds();
    this->updateButtons() ;

    system("cls") ;
    cout << mousePosView.x <<' ' << mousePosView.y <<endl;

}
void SelectionState::renderButtons(RenderTarget* target )
{
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }
}
void SelectionState::render(RenderTarget* target )
{
    if (!target)
       target = this->app;
    this->renderButtons(target);
}


