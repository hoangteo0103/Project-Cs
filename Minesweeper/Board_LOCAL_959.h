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
    bool isLose , isWin;
    bool onDisplay[50][50] ;
    int sizeX , sizeY ;
    int numberOfBombs ;
    int grid[50][50];
    int sgrid[50][50];

public :
    Board();
    virtual ~Board() ;
    virtual void checkWin();
    virtual void save() ;
    const bool& getLose() const ;
    const bool& getWin() const ;
    virtual void openNeighbour(int u ,int v);
    virtual void initSize(int width , int height , int numberOfBombs) ;
    virtual void initBoard() ;
    virtual void update(Vector2f mousPosView) ;
    virtual void render(RenderTarget* target ) ;
};

#endif // Board_H

