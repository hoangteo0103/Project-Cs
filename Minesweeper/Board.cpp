#include "Board.h"

Board::Board()
{

    this->t.loadFromFile("images/tiles.jpg");
    s.setTexture(t);
    for (int i=1;i<=10;i++)
     for (int j=1;j<=10;j++)
      {
        sgrid[i][j]=10;
        if (rand()%5==0)  grid[i][j]=9;
        else grid[i][j]=0;
      }
    for (int i=1;i<=10;i++)
     for (int j=1;j<=10;j++)
      {
        int n=0;
        if (grid[i][j]==9) continue;
        if (grid[i+1][j]==9) n++;
        if (grid[i][j+1]==9) n++;
        if (grid[i-1][j]==9) n++;
        if (grid[i][j-1]==9) n++;
        if (grid[i+1][j+1]==9) n++;
        if (grid[i-1][j-1]==9) n++;
        if (grid[i-1][j+1]==9) n++;
        if (grid[i+1][j-1]==9) n++;
        grid[i][j]=n;
      }

}

Board::~Board()
{

}
void Board::update(Vector2f mousePosView)
{
    this->mousePosView = mousePosView ;
}
void Board::render(RenderTarget* target )
{
    for (int i=1;i<=10;i++)
         for (int j=1;j<=10;j++)
          {
           this->s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
           this->s.setPosition(i*w, j*w);
           if(this->s.getGlobalBounds().contains(mousePosView))
           {
            if(Mouse::isButtonPressed(Mouse::Left))
            sgrid[i][j] = grid[i][j];
            if(Mouse::isButtonPressed(Mouse::Right)) sgrid[i][j] = 11 ;
           }
           this->s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
           target->draw(s);
          }
}
