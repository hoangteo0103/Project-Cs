#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow app(VideoMode(400 , 400 ) , "test" , Style :: Close | Style ::Resize);
    RectangleShape player (Vector2f(100.0f, 100.0f)) ;
    Texture t;
    t.loadFromFile("images/tiles.jpg");
    Sprite s(t) ;
    s.setTextureRect(IntRect(0,0,32,32));
    while(app.isOpen())
    {
        Event evnt ;
        while(app.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case Event::Closed:
                app.close();
                break;
            }
        }
        app.clear();
        app.draw(s);
        app.display();
    }
}
