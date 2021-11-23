#include "State.h"
using namespace std;
using namespace sf;
State::State(RenderWindow* app)
{
    this->app = app ;
    this->quit = false;


}
State::~State()
{
}
const bool& State::getQuit() const
{
    return this->quit;
}
void State::checkForQuit()
{
    if(Keyboard::isKeyPressed(Keyboard::Enter))
    {
        this->quit = true ;
    }

}
