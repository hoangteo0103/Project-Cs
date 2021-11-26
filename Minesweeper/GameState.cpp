#include "GameState.h"

void GameState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
}
GameState::GameState(RenderWindow* app ,  stack<State*> *states , int sizeX , int sizeY , int numberOfBombs)
    :State(app,states)
{

    this->initFonts() ;
    this->sizeX = sizeX ;
    this->sizeY = sizeY;
    this->numberOfBombs = numberOfBombs;
    this->board.initSize(this->sizeX , this->sizeY , this->numberOfBombs) ;
    this->lblTime.setCharacterSize(30);
    this->lblTime.setPosition({400, 0 }) ;
    this->lblTime.setFillColor(Color::White);
    this->lblTime.setFont(font);
    this->ssTime<<"";

    this->board.initBoard() ;
    this->buttons["BACK_TO_MENU_STATE"] = new Button(1000, 0 , 200 , 50 ,
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
const bool& GameState::getLose() const
{
    return this->board.getLose();
}
const bool& GameState::getWin() const
{
    return this->board.getWin();
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
    if(this->getWin())
    {
        Time t = clock.getElapsedTime() ;
        ifstream ifs("Leaderboard/leaderboard.ini") ;
        int time_now = int(t.asSeconds());
        int bomb_now = this->numberOfBombs ;
        vector<pair<int ,int > > tmp;
        tmp.push_back({bomb_now , time_now}) ;
        int bomb ,time ;
        while(ifs >> bomb >> time)
        {
            tmp.push_back({bomb , time});
        }
        sort(tmp.rbegin() , tmp.rend());
        ofstream ofs("Leaderboard/leaderboard.ini") ;
        for(int i = 0 ; i < min(10 , (int) tmp.size()) ; i++)
        {
            ofs << tmp[i].first << ' ' << tmp[i].second << endl;
        }
        exit(0);
    }
    if(this->getLose())
    {
        exit(0) ;
    }
    this->updateMousePositions() ;
    this->updateKeyBinds();
    this->updateButtons() ;
    this->board.update(this->mousePosView) ;
    Time t = clock.getElapsedTime() ;
    ssTime.str("");
    ssTime <<"Time " <<int(t.asSeconds());
    this->lblTime.setString(ssTime.str());
    system("cls") ;
    cout << mousePosView.x <<' ' << mousePosView.y <<endl;

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
    target->draw(this->lblTime);
}


