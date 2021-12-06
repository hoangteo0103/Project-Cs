#include "Board.h"
void Board::loadFromFile()
{

    this->isLose = false;
    this->isWin = false ;
    ifstream ifs("Save/PreviousBoard.ini") ;
    ifs >> this->sizeX  >> this->sizeY >> this->numberOfBombs ;
    for(int i = 1 ; i <= this->sizeX ; i++ )
    {
        for(int j = 1  ; j <= this->sizeY ; j++)
            ifs >> grid[i][j]  ;
    }
    for(int i = 1 ; i <= this->sizeX ; i++ )
    {
        for(int j = 1  ; j <= this->sizeY ; j++)
            ifs >> sgrid[i][j] ;
    }
    for(int i = 1 ; i <= this->sizeX ; i++ )
    {
        for(int j = 1  ; j <= this->sizeY ; j++)
            ifs >> onDisplay[i][j] ;
    }
    this->startPos_x = 600 - (this->sizeX * 32) / 2;
    this->startPos_y = 360 - (this->sizeY * 32) / 2;
}
void Board::initBoard(bool saved )
{
    if(saved)
    {
        this->loadFromFile() ;
        return ;
    }
    this->isLose = false;
    this->isWin = false ;
    memset(onDisplay, false, sizeof(onDisplay)) ;
    x = 0, y = 0 ;
    int numNow = 0 ;
    for (int i=1; i<=this->sizeX; i++)
        for (int j=1; j<=this->sizeY; j++)
        {
            onDisplay[i][j] = false;
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
    this->startPos_x = 600 - (this->sizeX * 32) / 2;
    this->startPos_y = 360 - (this->sizeY * 32) / 2;
}
void Board::save()
{
    ofstream ofs("Save/PreviousBoard.ini") ;
    ofs << this->sizeX << ' ' << this->sizeY << ' ' << this->numberOfBombs << endl ;
    for(int i = 1 ; i <= this->sizeX ; i++ )
    {
        for(int j = 1  ; j <= this->sizeY ; j++)
            ofs << grid[i][j] << ' '  ;
        ofs << endl ;
    }
    for(int i = 1 ; i <= this->sizeX ; i++ )
    {
        for(int j = 1  ; j <= this->sizeY ; j++)
            ofs << sgrid[i][j] << ' '  ;
        ofs << endl ;
    }
    for(int i = 1 ; i <= this->sizeX ; i++ )
    {
        for(int j = 1  ; j <= this->sizeY ; j++)
            ofs << onDisplay[i][j] << ' '  ;
        ofs << endl ;
    }
}
void Board::initSize(int width, int height, int numberOfBombs)
{

    this->sizeX = width ;
    this->sizeY = height ;
    this->startPos_x = 600 - (this->sizeX * 32) / 2;
    this->startPos_y = 360 - (this->sizeY * 32) / 2;
    this->numberOfBombs = numberOfBombs ;
}
Board::Board()
{
    this->isLose = false;
    this->isWin = false;
    this->t.loadFromFile("images/tiles.jpg");
    s.setTexture(t);
}

Board::~Board()
{

}
void Board::checkWin()
{
    for(int i = 1 ; i <=this->sizeX ; i++)
        for(int j = 1 ; j <=this->sizeY ; j++)
        {
            if(grid[i][j] == 9)
                continue ;
            if(onDisplay[i][j] == false)
                return ;
        }
    this->isWin = true ;

}
const bool& Board::getLose() const
{
    return this->isLose;
}
const bool& Board::getWin() const
{
    return this->isWin;
}
void Board::openNeighbour(int u,int v)
{

    if( u < 1 || v < 1 || u > this->sizeX || v > this->sizeY) ;
    if(onDisplay[u][v])
        return ;
    if(grid[u][v] == 10 || sgrid[u][v] == 11 )
        return ;
    if(grid[u][v]<=8)
    {
        if(sgrid[u][v]==10)
        {
            sgrid[u][v] = grid[u][v] ;
        }
        else
            return ;
    }
    onDisplay[u][v] = true ;
    if(grid[u][v] == 0 && sgrid[u][v] == 0 )
    {
        this->openNeighbour(u + 1, v );
        this->openNeighbour(u - 1, v );
        this->openNeighbour(u + 1, v + 1);
        this->openNeighbour(u + 1, v - 1);
        this->openNeighbour(u - 1, v + 1 );
        this->openNeighbour(u - 1, v - 1);
        this->openNeighbour(u, v - 1);
        this->openNeighbour(u, v + 1);
    }
}
void Board::update(Vector2f mousePosView)
{
    this->checkWin();
    this->mousePosView = mousePosView ;
    for (int i=1; i<=this->sizeX; i++)
        for (int j=1; j<=this->sizeY; j++)
        {
            int new_x = this->startPos_x + i * w ;
            int new_y = this->startPos_y + j * w ;
            this->s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
            this->s.setPosition(new_x , new_y);
            if(this->s.getGlobalBounds().contains(mousePosView))
            {
                int click = 0 ;
                while(Mouse::isButtonPressed(Mouse::Left))
                {
                    click = 1 ;

                }
                if(click==1)
                {
                    x = i, y = j ;
                    if(onDisplay[x][y])
                        continue ;
                    if(grid[x][y] == 9)
                    {
                        sgrid[x][y] = 9 ;
                        continue ;
                    }
                    this->openNeighbour( x,y) ;
                }
                while(Mouse::isButtonPressed(Mouse::Right))
                {
                    click = 2;

                }
                if(click==2)
                {
                    x = i, y = j ;
                    if(onDisplay[x][y])
                        continue ;
                    sgrid[i][j] = (sgrid[i][j]==11) ? 10 : 11 ;
                }
                if(click)
                    break ;


            }
        }
    if(this->sgrid[x][y] == 9)
        this->isLose = true ;
}
void Board::render(RenderTarget* target )
{
    for (int i=1; i<=this->sizeX; i++)
        for (int j=1; j<=this->sizeY; j++)
        {
            int new_x = this->startPos_x + i * w ;
            int new_y = this->startPos_y + j * w ;
            if(this->isLose || this->isWin)
                sgrid[i][j] = grid[i][j];
            s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
            s.setPosition(new_x, new_y);
            target->draw(s);
        }
    x = 0, y = 0 ;
}

