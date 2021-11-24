#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include<bits/stdc++.h>

using namespace sf;
using namespace std;
enum button_states{BTN_IDLE = 0 ,BTN_HOVER = 1 , BTN_ACTIVE = 2 };
class Button
{
private :
    short unsigned buttonState ;
    bool pressed ;
    bool hover ;
    RectangleShape shape;
    Font* font ;
    Text text;

    Color idleColor ;
    Color hoverColor ;
    Color activeColor ;

public :
    Button(float x , float y , float width , float height , Font* font ,
           string text ,Color idleColor,Color hoverColor , Color activeColor);
    ~Button() ;
    void update(const Vector2f mousePos) ;
    void render(RenderTarget* target);
};
#endif // BUTTON_H
