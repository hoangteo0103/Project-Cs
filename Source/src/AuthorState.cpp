#include "AuthorState.h"


void AuthorState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
    texture.loadFromFile("images/author.png") ;
    this->background.setTexture(texture) ;
}
AuthorState::AuthorState(RenderWindow* app ,  stack<State*> *states)
    :State(app,states)
{

    this->initFonts() ;
    this->buttons["BACK_TO_MENU_STATE"] = new Button(410, 628, 450 , 50 ,
                                     &this->font , "Back to Menu" , Color(0, 0, 0, 0)
                                 ,Color(10, 10, 10, 10) , Color(20,20,20,200) ) ;


}

AuthorState ::~AuthorState()
{
   auto it = this->buttons.begin();
   for(it = this->buttons.begin(); it!=this->buttons.end() ; ++it)
   {
       delete it->second;
   }
}
void AuthorState::updateKeyBinds()
{
    this->checkForQuit() ;
}
void AuthorState::endState()
{
    cout <<"End MainMenu"<<endl;
}
void AuthorState::updateButtons()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }
    if(this->buttons["BACK_TO_MENU_STATE"]->isPressed())
    {
        this->quit = true ;
    }
}

void AuthorState::update()
{

    this->updateMousePositions() ;
    this->updateKeyBinds();
    this->updateButtons() ;
}
void AuthorState::renderButtons(RenderTarget* target )
{
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }
}
void AuthorState::render(RenderTarget* target )
{
    if (!target)
       target = this->app;

    target->draw(this->background);
    this->renderButtons(target);
}



