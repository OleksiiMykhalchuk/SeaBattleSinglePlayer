#ifndef POSITION_H
#define POSITION_H

#include <QApplication>
#include <QVector>



class Position
{
public:
    Position();
int getX();
int getY();
int getFourDeckX(int index);
int getFourDeckY(int index);
int getThreeDeckX(int index);
int getThreeDeckY(int index);

private:
    int x;
    int y;
    class Coordinates{
    public:
        Coordinates(int x, int y);
        int x;
        int y;
    };

    QVector<Coordinates> fourDeckArr;
    int DeckNumber;
    bool vertical;
    void FourDeck();
public:
    QVector<Coordinates> threeDeckArr;
    int HowMany;
    void ThreeDeck();

protected:


};

#endif // POSITION_H
