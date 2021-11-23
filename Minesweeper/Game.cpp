#include "Game.h"
using namespace std;
using namespace sf;
//Static Functions

//Initialize functions
void Game::initWindow()
{
    ifstream ifs("Data/window.ini") ;
    string title = "NONE";
    VideoMode Size(400,400);
    if(ifs.is_open())
    {
        getline(ifs, title) ;
        ifs >> Size.width >> Size.height ;
    }
    this->app = new RenderWindow(Size, title);
}
void Game::initStates()
{
    this->states.push(new GameState(this->app)) ;
}

// Constructor functions
Game::Game()
{
    this->initWindow();
    this->initStates();
}
Game::~Game()
{
    delete this->app;
    while(!this->states.empty())
    {
        delete this->states.top() ;
        this->states.pop() ;
    }

}
void Game::endApplication()
{
    cout << 1 ;
}
void Game::updateSFMLEvents()
{

        while (this->app->pollEvent(this->sfEvent))
        {
            if (this->sfEvent.type == Event::Closed)
                this->app->close();
        }
}
void Game::update()
{
    this->updateSFMLEvents();

    if(!this->states.empty())
    {
        this->states.top()->update();
        if(this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top() ;
            this->states.pop() ;
        }
    }
}
void Game::render()
{
    this->app->clear();

    if(!this->states.empty())
        this->states.top()->render();
    else
    {
        this->endApplication();
        this->app->close();
    }
    this->app->display();
}
void Game::run()
{
    while(this->app->isOpen())
    {
        this->update();
        this->render();
    }
}
