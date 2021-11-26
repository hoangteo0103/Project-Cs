
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
    ifstream ifs("Leaderboard/leaderboard.ini") ;
    vector<pair<int , int > > tmp ;
    int bomb , time;
    while(ifs>>bomb>>time)
    {
        tmp.push_back({bomb,time});
    }
    int x = 400 , y = 200 ;
    for(int i = 0 ; i < tmp.size() ; i++ )
    {
        string dm = to_string(i);
        string dm1 = dm + "a";
        string str_bomb = to_string(tmp[i].first);
        string str_time = to_string(tmp[i].second);
        this->buttons[dm] = new Button(x,y, 150 , 50 ,
                &this->font , str_bomb , Color::Black , Color::Black,Color::Black);
        this->buttons[dm1] = new Button(x + 150,y, 150 , 50 ,
                &this->font , str_time , Color::Black , Color::Black,Color::Black);
        Color cc = Color::Red;
        this->buttons[dm]->setOutline(cc);
        this->buttons[dm1]->setOutline(cc);
        y+=50;

    }
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

    //system("cls") ;
    //cout << mousePosView.x <<' ' << mousePosView.y <<endl;

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



