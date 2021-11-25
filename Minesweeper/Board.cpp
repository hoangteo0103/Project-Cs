#include "Board.h"
void Board::initBoard()
{
    x = 0 , y = 0 ;
    for (int i=1; i<=10; i++)
        for (int j=1; j<=10; j++)
        {
            sgrid[i][j]=10;
            if (rand()%5==0)
                grid[i][j]=9;
            else
                grid[i][j]=0;
        }
    for (int i=1; i<=10; i++)
        for (int j=1; j<=10; j++)
        {
            int n=0;
            if (grid[i][j]==9)
                continue;
            if (grid[i+1][j]==9)
                n++;
            if (grid[i][j+1]==9)
                n++;
            if (grid[i-1][j]==9)
                n++;
            if (grid[i][j-1]==9)
                n++;
            if (grid[i+1][j+1]==9)
                n++;
            if (grid[i-1][j-1]==9)
                n++;
            if (grid[i-1][j+1]==9)
                n++;
            if (grid[i+1][j-1]==9)
                n++;
            grid[i][j]=n;
        }
}
Board::Board()
{
    this->initBoard();
    this->t.loadFromFile("images/tiles.jpg");
    s.setTexture(t);
}

Board::~Board()
{

}
void Board::update(Vector2f mousePosView)
{
    this->mousePosView = mousePosView ;
    for (int i=1; i<=10; i++)
        for (int j=1; j<=10; j++)
        {
            this->s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
            this->s.setPosition(i*w, j*w);
            if(this->s.getGlobalBounds().contains(mousePosView))
            {
                x = i, y = j ;
                if(Mouse::isButtonPressed(Mouse::Left))
                    sgrid[i][j] = grid[i][j];
                if(Mouse::isButtonPressed(Mouse::Right))
                    sgrid[i][j] = 11 ;
                break ;
            }
        }
}
void Board::render(RenderTarget* target )
{
    for (int i=1; i<=10; i++)
        for (int j=1; j<=10; j++)
        {
            if(sgrid[x][y] == 9)
                sgrid[i][j] = grid[i][j];
            s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
            s.setPosition(i*w, j*w);
            target->draw(s);
        }
    x = 0, y = 0 ;
}

