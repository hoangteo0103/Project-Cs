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
    Texture t;
public:
    State();
    virtual ~State();
    // Functions
    virtual void update() = 0 ;
    virtual void render() = 0 ;

};
#endif
