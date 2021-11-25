#include "Board.h"
void Board::initBoard()
{
    x = 0, y = 0 ;
    int numNow = 0 ;
    for (int i=1; i<=this->sizeX; i++)
        for (int j=1; j<=this->sizeY; j++)
        {
            sgrid[i][j]=10;
            if (rand()%5==0&& this->numberOfBombs > numNow)
                grid[i][j]=9, numNow++;
            else
                grid[i][j]=0;
        }
    for (int i=1; i<=this->sizeX; i++)
        for (int j=1; j<=this->sizeY; j++)
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
void Board::initSize(int width, int height, int numberOfBombs)
{
    this->sizeX = width ;
    this->sizeY = height ;
    this->numberOfBombs = numberOfBombs ;
}
Board::Board()
{
    this->t.loadFromFile("images/tiles.jpg");
    s.setTexture(t);
}

Board::~Board()
{

}
void Board::openNeighbour(int u,int v)
{
    if( u > this->sizeX || v > this->sizeY || v < 1 || u < 1)
        return ;
    cout << u << ' ' << v << endl;
    if(grid[u][v]!=9)
    {
        if(sgrid[u][v]==10)
        {
            sgrid[u][v] = grid[u][v] ;
        }
    }
    if(grid[u][v] == 0 && sgrid[u][v] == 0 )
    {
        this->openNeighbour(u + 1, v );
        this->openNeighbour(u - 1, v );
        this->openNeighbour(u + 1, v + 1);
        this->openNeighbour(u + 1, v - 1);
        this->openNeighbour(u - 1, v + 1 );
        this->openNeighbour(u - 1, v - 1);
        this->openNeighbour(u , v - 1);
        this->openNeighbour(u , v + 1);
    }
}
void Board::update(Vector2f mousePosView)
{
    this->mousePosView = mousePosView ;
    for (int i=1; i<=this->sizeX; i++)
        for (int j=1; j<=this->sizeY; j++)
        {
            this->s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
            this->s.setPosition(i*w, j*w);
            if(this->s.getGlobalBounds().contains(mousePosView))
            {
                x = i, y = j ;
                if(Mouse::isButtonPressed(Mouse::Left))
                    sgrid[i][j] = grid[i][j];
                if(Mouse::isButtonPressed(Mouse::Right))
                {
                    sgrid[i][j] = sgrid[i][j]==11 ? 10 : 11 ;
                }
                break ;
                if(sgrid[x][y] == 0 )
                {
                    this->openNeighbour( x,y) ;
                }
            }
        }
}
void Board::render(RenderTarget* target )
{

    for (int i=1; i<=this->sizeX; i++)
        for (int j=1; j<=this->sizeY; j++)
        {
            if(sgrid[x][y] == 9)
                sgrid[i][j] = grid[i][j];
            s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
            s.setPosition(i*w, j*w);
            target->draw(s);
        }
    x = 0, y = 0 ;
}

