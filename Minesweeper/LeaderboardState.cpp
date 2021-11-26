
#include "Leaderboardstate.h"


void LeaderboardState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
}
LeaderboardState::LeaderboardState(RenderWindow* app ,  stack<State*> *states)
    :State(app,states)
{
    this->initFonts() ;
    this->buttons["BACK_TO_MENU_STATE"] = new Button(0,0, 150 , 50 ,
                                     &this->font , "Back to Menu" , Color(70,70,70,200)
                                 ,Color(150,150,150,255) , Color(20,20,20,200) ) ;

}

LeaderboardState ::~LeaderboardState()
{
   auto it = this->buttons.begin();
   for(it = this->buttons.begin(); it!=this->buttons.end() ; ++it)
   {
       delete it->second;
   }
}
void LeaderboardState::updateKeyBinds()
{
    this->checkForQuit() ;
}
void LeaderboardState::endState()
{
    cout <<"End MainMenu"<<endl;
}
void LeaderboardState::updateButtons()
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

void LeaderboardState::update()
{

    this->updateMousePositions() ;
    this->updateKeyBinds();
    this->updateButtons() ;

    system("cls") ;
    cout << mousePosView.x <<' ' << mousePosView.y <<endl;

}
void LeaderboardState::renderButtons(RenderTarget* target )
{
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }
}
void LeaderboardState::render(RenderTarget* target )
{
    if (!target)
       target = this->app;
    this->renderButtons(target);
}



