#include "Leaderboardstate.h"


void LeaderboardState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
    texture.loadFromFile("images/highscore.png") ;
    this->background.setTexture(texture) ;
}
void LeaderboardState::initBeginner()
{
    ifstream ifs("Leaderboard/leaderboardBeginner.ini") ;
    vector<int > tmp ;
    int  time;
    while(ifs>>time)
    {
        tmp.push_back(time);
    }
    int x = 450, y = 220 ;
    for(int i = 0 ; i < tmp.size() ; i++ )
    {
        string label = to_string(i) + "a" ;
        string str_time = to_string(tmp[i]);
        this->buttons[label] = new Button(x,y, 150, 50,
                                          &this->font, str_time, Color::Black, Color::Black,Color::Black);
        y+=50;
    }
}
void LeaderboardState::initIntermediate()
{
    ifstream ifs("Leaderboard/leaderboardIntermediate.ini") ;
    vector<int > tmp ;
    int  time;
    while(ifs>>time)
    {
        tmp.push_back(time);
    }
    int x = 600, y = 220 ;
    for(int i = 0 ; i < tmp.size() ; i++ )
    {
        string label = to_string(i) + "b";
        string str_time = to_string(tmp[i]);
        this->buttons[label] = new Button(x,y, 150, 50,
                                          &this->font, str_time, Color::Black, Color::Black,Color::Black);
        y+=50;
    }
}
void LeaderboardState::initExpert()
{
    ifstream ifs("Leaderboard/leaderboardExpert.ini") ;
    vector<int > tmp ;
    int  time;
    while(ifs>>time)
    {
        tmp.push_back(time);
    }
    int x = 750, y = 220 ;
    for(int i = 0 ; i < tmp.size() ; i++ )
    {
        string label = to_string(i) + "c";
        string str_time = to_string(tmp[i]);
        this->buttons[label] = new Button(x,y, 150, 50,
                                          &this->font, str_time, Color::Black, Color::Black,Color::Black);
        y+=50;
    }
}
LeaderboardState::LeaderboardState(RenderWindow* app,  stack<State*> *states)
    :State(app,states)
{

    this->initFonts() ;
    this->buttons["BACK_TO_MENU_STATE"] = new Button(83, 83, 150, 50,
            &this->font, "Back to Menu", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->initBeginner();
    this->initIntermediate();
    this->initExpert();
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

    target->draw(this->background);
    this->renderButtons(target);
}



