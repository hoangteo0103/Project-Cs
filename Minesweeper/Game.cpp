#include "Game.h"
using namespace std;
using namespace sf;
//Static Functions

//Initialize functions
void Game::initWindow()
{
     this->app = new RenderWindow(VideoMode(400, 400), "Minesweeper!");
}

// Constructor functions
Game::Game()
{
    this->initWindow();
}
Game::~Game()
{
    delete this->app;

}
void Game::updateSFMLEvents()
{
    while (this->app->isOpen())
    {

        while (this->app->pollEvent(this->sfEvent))
        {
            if (this->sfEvent.type == Event::Closed)
                this->app->close();
        }
    }
}
void Game::update()
{
    this->updateSFMLEvents();
}
void Game::render()
{
    this->app->clear();
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
