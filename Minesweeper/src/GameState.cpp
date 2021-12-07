#include "GameState.h"

void GameState::Reset()
{
    this->ok = false ;
    this->isUpdated = false ;
    this->clock.Reset() ;
    this->board.initBoard(0) ;
    this->paused = false ;
}


void GameState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
    texture.loadFromFile("images/game1.png") ;
    this->background.setTexture(texture) ;
}
GameState::GameState(RenderWindow* app,  stack<State*> *states, int sizeX, int sizeY, int numberOfBombs, bool saved )
    :State(app,states)
{
    // Init
    this->ok = false ;
    this->isUpdated = false ;
    this->clock.Start() ;
    this->initFonts() ;


    // Init board
    this->sizeX = sizeX ;
    this->sizeY = sizeY;
    this->numberOfBombs = numberOfBombs;
    if(!saved)
        this->board.initSize(this->sizeX, this->sizeY, this->numberOfBombs) ;
    // Init time

    this->lblTime.setCharacterSize(30);
    this->lblTime.setPosition({600, 0 }) ;
    this->lblTime.setFillColor(Color::White);
    this->lblTime.setFont(font);
    this->ssTime<<"";
    this->board.initBoard(saved) ;
    // Init Buttons
    this->buttons["BACK_TO_MENU_STATE"] = new Button(1140, 600, 120, 50,
            &this->font, "MENU", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["PAUSE_MENU_STATE"] = new Button(1140, 655, 120, 50,
            &this->font, "PAUSE", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
}

GameState ::~GameState()
{
    //delete this->pmenu;
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
    this->quit = true ;
    cout <<"End MainMenu"<<endl;
}

void GameState::updatePaused()
{
    this->pmenu.updateMousePositions(mousePosView) ;
}

bool cmp(pair<int,int > a, pair<int,int > b )
{
    if(a.first!=b.first)
        return a.first > b.first;
    return a.second < b.second ;
}

void GameState::updateLeaderBoard()
{
    this->isUpdated = true ;
    int t = int(clock.GetElapsedSeconds());
    ifstream ifs("Leaderboard/leaderboard.ini") ;
    int time_now = t;
    int bomb_now = this->numberOfBombs ;
    vector<pair<int,int > > tmp;
    tmp.push_back({bomb_now, time_now}) ;
    int bomb,time ;
    while(ifs >> bomb >> time)
    {
        tmp.push_back({bomb, time});
    }
    sort(tmp.begin(), tmp.end(), cmp );
    ofstream ofs("Leaderboard/leaderboard.ini") ;
    for(int i = 0 ; i < min(10, (int) tmp.size()) ; i++)
    {
        ofs << tmp[i].first << ' ' << tmp[i].second << endl;
    }
    ofstream del("Save/PreviousBoard.ini") ;
    this->winState.initState(*app) ;
}

void GameState::saveBoard()
{
    this->board.save() ;
}

void GameState::updateWinState()
{
    if(this->ok)
    {
        this->againState.updateMousePositions(mousePosView);
        this->againState.update() ;
        if(this->againState.getYes())
        {
            this->Reset() ;
        }
        if(this->againState.getNo())
            this->endState() ;

    }
    else
    {
        this->winState.updateMousePositions(mousePosView) ;
        this->winState.update() ;
        if(this->winState.getOk())
        {
            this->ok = true ;
            this->againState.initState(*app) ;
        }
    }
}

void GameState::updateLoseState()
{
    ofstream del("Save/PreviousBoard.ini") ;
    if(!this->isUpdated)
    {
        this->loseState.initState(*app) ;
        this->isUpdated = true ;
    }
    if(this->ok)
    {
        this->againState.updateMousePositions(mousePosView);
        this->againState.update() ;
        if(this->againState.getYes())
        {
            this->Reset() ;
        }
        if(this->againState.getNo())
            this->endState() ;

    }
    else
    {

        this->loseState.updateMousePositions(mousePosView) ;
        this->loseState.update() ;

        if(this->loseState.getOk())
        {
            this->ok = true ;
            this->againState.initState(*app) ;
        }
    }
}

void GameState::updateButtons()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }
    if(this->buttons["BACK_TO_MENU_STATE"]->isPressed())
    {

        this->saveBoard();
        this->quit = true ;
    }
    if(this->buttons["PAUSE_MENU_STATE"]->isPressed())
    {
        this->paused = true ;
        this->pmenu.initState(*app) ;
        this->clock.Pause() ;
    }

}

void GameState::update()
{

    this->updateMousePositions() ;
    this->updateKeyBinds();
    if(!this->paused)
    {
        if(this->getWin())
        {
            this->clock.Pause() ;
            if(!this->isUpdated)
                this->updateLeaderBoard();
            this->updateWinState() ;
        }
        if(this->getLose())
        {
            this->clock.Pause() ;
            this->updateLoseState() ;
        }

        this->updateButtons() ;
        this->board.update(this->mousePosView) ;
        int t = int(clock.GetElapsedSeconds());
        ssTime.str("");
        ssTime <<"Time " <<t;
        this->lblTime.setString(ssTime.str());
        system("cls") ;
        cout << mousePosView.x <<' ' << mousePosView.y <<endl;
    }
    else
    {
        this->updatePaused();
        this->pmenu.update();
        if(this->pmenu.getResume() == true )
        {
            this->paused  = false  ;
            this->clock.Start() ;
        }
    }
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
    if(this->quit)
        return ;
    if (!target)
        target = this->app;
    target->draw(this->background);
    this->board.render(target);
    this->renderButtons(target);
    target->draw(this->lblTime);
    if(this->getLose())
    {
        if(!this->ok)
            this->loseState.render(*target) ;
        else
            this->againState.render(*target) ;
    }
    if(this->getWin())
    {
        if(!this->ok)
            this->winState.render(*target) ;
        else
            this->againState.render(*target) ;
    }
    if(this->paused) // pausemenu render
    {
        this->pmenu.render(*target) ;
    }
}


