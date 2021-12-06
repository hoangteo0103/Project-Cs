#include "MainMenuState.h"

void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }

    t.loadFromFile("images/background_menu.png") ;
    this->background.setTexture(t) ;
}
void MainMenuState::initButtons()
{

}
MainMenuState::MainMenuState(RenderWindow* app,stack<State*> *states )
    :State(app,states)
{
    this->initFonts() ;
    this->buttons["GAME_STATE_BTN"] = new Button(200, 100, 400, 50,
            &this->font, "New Game", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;

    this->buttons["CONTINUE_STATE_BTN"] = new Button(200, 160, 400, 50,
            &this->font, "Continue", Color(70,70,70,200)
            ,Color(100,100,100,255), Color(20,20,20,200) ) ;

    this->buttons["HIGH_SCORE_BTN"] = new Button(200, 220, 400, 50,
            &this->font, "High Score", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;

    this->buttons["AUTHOR_STATE_BTN"] = new Button(200, 280, 400, 50,
            &this->font, "Author", Color(70,70,70,200)
            ,Color(100,100,100,255), Color(20,20,20,200) ) ;

    this->buttons["GAME_QUIT_BTN"] = new Button(200, 340, 400, 50,
            &this->font, "Exit", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;

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
bool MainMenuState::checkSaved()
{
    ifstream ifs("Save/PreviousBoard.ini") ;
    int a ;
    ifs >> a ;
    if( a <= 0 )
        return false;
    return true ;
}
void MainMenuState::updateButtons()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }
    if(this->buttons["GAME_STATE_BTN"]->isPressed())
    {
        this->states->push(new SelectionState(this->app, this->states)) ;
    }
    if(this->buttons["HIGH_SCORE_BTN"]->isPressed())
    {
        this->states->push(new LeaderboardState(this->app, this->states)) ;
    }
    if(this->buttons["GAME_QUIT_BTN"]->isPressed())
    {
        this->quit = true ;
    }
    if(this->buttons["CONTINUE_STATE_BTN"]->isPressed())
    {
        if(this->checkSaved())
            this->states->push(new GameState(this->app, this->states, 0, 0, 0,  1)) ;
    }
    if(this->buttons["AUTHOR_STATE_BTN"]->isPressed())
    {
        this->states->push(new AuthorState(this->app, this->states)) ;
    }
}

void MainMenuState::update()
{
    this->updateMousePositions() ;
    this->updateKeyBinds();
    this->updateButtons() ;
    //system("cls") ;
    //cout << mousePosView.x <<' ' << mousePosView.y <<endl;

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


