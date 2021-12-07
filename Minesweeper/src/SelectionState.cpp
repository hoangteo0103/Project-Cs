
#include "SelectionState.h"


void SelectionState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
    texture.loadFromFile("images/selection_back.png") ;
    this->background.setTexture(texture) ;
}
void SelectionState::initCustom()
{
    this->buttons["HEIGHT"] = new Button(340, 400, 150, 45,
            &this->font, "10", Color(70,70,70,200)
            ,Color(70,70,70,200), Color(70,70,70,200) ) ;
    this->buttons["WIDTH"] = new Button(340, 460, 150, 45,
            &this->font, "10", Color(70,70,70,200)
            ,Color(70,70,70,200), Color(70,70,70,200) ) ;
    this->buttons["BOMB"] = new Button(340, 520, 150, 45,
            &this->font, "10", Color(70,70,70,200)
            ,Color(70,70,70,200), Color(70,70,70,200) ) ;

    this->buttons["CUSTOM_STATE"] = new Button(340, 580, 150, 45,
            &this->font, "CUSTOM", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["DECREASE_HEIGHT_1"] = new Button(180, 400, 150, 45,
            &this->font, "-1", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["DECREASE_HEIGHT_5"] = new Button(20, 400, 150, 45,
            &this->font, "-5", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["DECREASE_WIDTH_1"] = new Button(180, 460, 150, 45,
            &this->font, "-1", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["DECREASE_WIDTH_5"] = new Button(20, 460, 150, 45,
            &this->font, "-5", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["INCREASE_HEIGHT_1"] = new Button(500, 400, 150, 45,
            &this->font, "+1", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["INCREASE_HEIGHT_5"] = new Button(660, 400, 150, 45,
            &this->font, "+5", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["INCREASE_WIDTH_1"] = new Button(500, 460, 150, 45,
            &this->font, "+1", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["INCREASE_WIDTH_5"] = new Button(660, 460, 150, 45,
            &this->font, "+5", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["INCREASE_BOMB_1"] = new Button(500, 520, 150, 45,
            &this->font, "+1", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["INCREASE_BOMB_5"] = new Button(660, 520, 150, 45,
            &this->font, "+5", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["DECREASE_BOMB_1"] = new Button(180, 520, 150, 45,
            &this->font, "-1", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->buttons["DECREASE_BOMB_5"] = new Button(20, 520, 150, 45,
            &this->font, "-5", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
}
void SelectionState::initButtons()
{
    this->buttons["BACK_TO_MENU_STATE"] = new Button(500, 630, 150, 45,
            &this->font, "Back to Menu", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;

    this->buttons["BEGINNER_STATE"] = new Button(220, 197, 150, 45,
            &this->font, "Beginner", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;

    this->buttons["INTERMEDIATE_STATE"] = new Button(275, 255, 150, 45,
            &this->font, "Intermediate", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;

    this->buttons["EXPERT_STATE"] = new Button(320, 315, 150, 45,
            &this->font, "Expert", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    this->initCustom() ;
}
SelectionState::SelectionState(RenderWindow* app,  stack<State*> *states)
    :State(app,states)
{
    this->sizeX = this->sizeY = 10 ;
    this->numberOfBombs = 10 ;
    this->initFonts() ;
    this->initButtons()  ;

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
void SelectionState::updateCustom()
{
    if(this->buttons["CUSTOM_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->app, this->states, this->sizeX, this->sizeY, this->numberOfBombs,  0 )) ;
        this->quit = true ;
    }
    if(this->buttons["DECREASE_HEIGHT_1"]->isPressed() && this->sizeY > 5)
    {
        this->sizeY--;
    }
    if(this->buttons["DECREASE_WIDTH_1"]->isPressed() && this->sizeX > 5)
    {
        this->sizeX--;
    }
    if(this->buttons["DECREASE_HEIGHT_5"]->isPressed() && this->sizeY >=10)
    {
        this->sizeY-=5;
    }
    if(this->buttons["DECREASE_WIDTH_5"]->isPressed() && this->sizeX >=10)
    {
        this->sizeX-=5;
    }
    if(this->buttons["INCREASE_HEIGHT_1"]->isPressed() && this->sizeY < 30)
    {
        this->sizeY++;
    }
    if(this->buttons["INCREASE_WIDTH_1"]->isPressed() && this->sizeX  < 30)
    {
        this->sizeX++;
    }
    if(this->buttons["INCREASE_HEIGHT_5"]->isPressed() && this->sizeY <=25)
    {
        this->sizeY+=5;
    }
    if(this->buttons["INCREASE_WIDTH_5"]->isPressed() && this->sizeX <=25)
    {
        this->sizeX+=5;
    }

    this->buttons["HEIGHT"]->updateText(to_string(this->sizeY));
    this->buttons["WIDTH"]->updateText(to_string(this->sizeX));
    int MaxBomb = this->sizeX * this->sizeY - 1 ;

    if(this->buttons["DECREASE_BOMB_1"]->isPressed() && this->numberOfBombs > 1)
    {
        this->numberOfBombs--;
    }
    if(this->buttons["DECREASE_BOMB_5"]->isPressed() && this->numberOfBombs >=6)
    {
        this->numberOfBombs-=5;
    }
    if(this->buttons["INCREASE_BOMB_1"]->isPressed() && this->numberOfBombs < MaxBomb)
    {
        this->numberOfBombs++;
    }
    if(this->buttons["INCREASE_BOMB_5"]->isPressed() && this->numberOfBombs + 5 <=MaxBomb)
    {
        this->numberOfBombs+=5;
    }
    this->buttons["BOMB"]->updateText(to_string(this->numberOfBombs));


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
    if(this->buttons["BEGINNER_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->app, this->states, 10, 10, 10, 0 )) ;
        // this->states->push(new GameState(this->app , this->states , 9 , 9 ,8)) ;
        this->quit = true ;
    }

    if(this->buttons["INTERMEDIATE_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->app, this->states, 16, 16, 40, 0 )) ;
        this->quit = true ;
    }

    if(this->buttons["EXPERT_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->app, this->states, 30, 16, 99,  0 )) ;
        this->quit = true ;
    }
    this->updateCustom() ;

}

void SelectionState::update()
{

    this->updateMousePositions() ;
    this->updateKeyBinds();
    this->updateButtons() ;

    system("cls") ;
    cout << this->sizeX << ' ' << this->sizeY << endl;
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
    target->draw(this->background);
    this->renderButtons(target);
}


