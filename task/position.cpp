#include "position.h"



Position::Position()
{
    srand(time(NULL));
    x = rand()%9;
    y = rand()%9;
    FourDeck();
    ThreeDeck();
}

int Position::getX()
{
    return x;
}
int Position::getY()
{
    return y;
}

Position::Coordinates::Coordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Position::FourDeck()
{
    fourDeckArr.push_back(Coordinates(x,y));
    DeckNumber = 4;
    vertical = rand()%2;
    if(vertical)
    {
        for(int i=1; i<DeckNumber; i++)
        {
            if(x<7)
                x++;
            else
                x--;

            fourDeckArr.push_back(Coordinates(x,y));
        }
    }
    else
    {
        for(int i=1; i<DeckNumber; i++)
        {
            if(y<9)
                y++;
            else
                y--;

            fourDeckArr.push_back(Coordinates(x,y));
        }
    }
}

int Position::getFourDeckX(int index)
{
    return fourDeckArr[index].x;
}
int Position::getFourDeckY(int index)
{
    return fourDeckArr[index].y;
}

void Position::ThreeDeck()
{
    DeckNumber = 3;
    HowMany = 2;
    vertical = rand()%2;
    if((fourDeckArr[0].x == fourDeckArr[3].x) && fourDeckArr[0].x < 1)
    {
        x = fourDeckArr[0].x +2;
        y = fourDeckArr[0].y;
    }
    else if ((fourDeckArr[0].x == fourDeckArr[3].x) && fourDeckArr[0].x >8)
    {
        x = fourDeckArr[0].x -2;
        y = fourDeckArr[0].y;
    }
    else if ((fourDeckArr[0].y == fourDeckArr[3].y) && fourDeckArr[0].y < 1)
    {
        y = fourDeckArr[0].y +2;
        x = fourDeckArr[0].x;
    }
    else if ((fourDeckArr[0].y == fourDeckArr[3].y) && fourDeckArr[0].y >8)
    {
        y = fourDeckArr[0].y -2;
        x = fourDeckArr[0].x;
    }
    else
    {
        y = fourDeckArr[0].y + 2;
        x = fourDeckArr[0].x + 2;
    }
    if(vertical)
    {

        for(int i=0; i<DeckNumber;i++)
        {
            if(x<9)
                x++;
            else
                x--;
            threeDeckArr.push_back(Coordinates(x,y));
        }

    }
    else
    {
        for(int i=0; i<DeckNumber;i++)
        {
            if(y<9)
                y++;
            else
                y--;
            threeDeckArr.push_back(Coordinates(x,y));
        }
    }
}

int Position::getThreeDeckX(int index)
{
    return threeDeckArr[index].x;
}
int Position::getThreeDeckY(int index)
{
    return threeDeckArr[index].y;
}
