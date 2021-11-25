#ifndef Board_H
#define Board_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include<bits/stdc++.h>

using namespace sf;
using namespace std;
class Board
{
private :
protected:
    Texture t ;
    Sprite s ;
    Vector2f mousePosView;
    int w = 32 ;
    int x, y ;
    int sizeX , sizeY ;
    int numberOfBombs ;
    int grid[12][12];
    int sgrid[12][12];

public :
    Board();
    virtual ~Board() ;
    virtual void openNeighbour(int u ,int v);
    virtual void initSize(int width , int height , int numberOfBombs) ;
    virtual void initBoard() ;
    virtual void update(Vector2f mousPosView) ;
    virtual void render(RenderTarget* target ) ;
};

#endif // Board_H

