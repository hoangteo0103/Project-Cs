#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include<bits/stdc++.h>
using namespace sf;
using namespace std;
class State
{
private:
    RenderWindow* app;
    bool quit ;

public:
    State(RenderWindow* app);
    virtual ~State();
    // Functions
    const bool& getQuit() const ;
    virtual void checkForQuit() ;
    virtual void updateKeyBinds() = 0 ;
    virtual void endState() = 0 ;
    virtual void update() = 0 ;
    virtual void render(RenderTarget* target = nullptr) = 0 ;

};
#endif
