#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QDebug>
#include <QIODevice>
#include <QByteArray>
#include <QString>

#include <QLabel>
#include <QPushButton>

#include <QVector>

#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void _File();
    void buttonArray();

private slots:
    void buttonClicked();

    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void on_actionInfo_triggered();

private:

    static const int BUFFER = 100;
    QByteArray array[BUFFER][BUFFER];
    int row = 0;
    QByteArray line;
    int character;
    int count = 0;
    int fieldsNumber = 6;
    int SIZE = 10;

    int score = 0;
    int press_count = 60;

    QLabel *newLabel = new QLabel(this);

    int fontSize = 10;
    int X = 40;
    int Y = 50;
    int Width = 400;
    int Height = 120;
    int Margin = 30;

    QPushButton *arr[100][100];
    Ui::MainWindow *ui;

    void randomField();

    //predefine variants ship's arrangement
    int BattleField [6][10][10] = {
     {
                    {0,0,0,1,1,1,1,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {1,0,0,1,0,0,1,1,0,0},
                    {1,0,0,1,0,0,0,0,0,0},
                    {1,0,0,1,0,0,1,1,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {1,0,0,1,0,0,0,1,0,0},
                    {1,0,0,0,0,1,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,1}
      },
         {
                      {1,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,1,1,1,0,1},
                      {1,0,0,1,0,0,0,0,0,1},
                      {1,0,0,1,0,1,1,1,0,1},
                      {0,0,0,0,0,0,0,0,0,1},
                      {1,0,0,1,0,0,0,1,0,0},
                      {0,0,0,0,0,1,0,0,0,0},
                      {0,0,0,0,0,1,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0}
      },
        {
                      {0,0,0,0,1,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,1,1,1},
                      {1,1,0,0,0,0,0,0,0,0},
                      {0,0,0,1,0,1,1,1,0,1},
                      {0,0,0,1,0,0,0,0,0,1},
                      {1,0,0,0,0,0,0,0,0,1},
                      {0,0,0,0,0,1,0,0,0,1},
                      {0,0,0,0,0,1,0,0,0,0},
                      {0,0,0,1,0,0,0,1,0,0}
        },
        {
                      {1,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,1,1,1,0,0},
                      {1,0,0,1,0,0,0,0,0,0},
                      {1,0,0,1,0,1,1,1,0,0},
                      {0,0,0,0,0,0,0,0,0,0},
                      {1,0,0,1,0,1,0,1,0,0},
                      {0,0,0,0,0,1,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0},
                      {0,0,1,1,1,1,0,0,0,0}
        },
        {
                      {1,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,1,1,1,0,1},
                      {1,0,0,1,0,0,0,0,0,1},
                      {1,0,0,1,0,0,0,0,0,0},
                      {1,0,0,0,0,0,0,0,0,1},
                      {1,0,0,0,0,0,0,1,0,0},
                      {0,0,0,0,0,1,0,0,0,0},
                      {0,0,0,0,0,1,0,0,0,0},
                      {0,0,0,1,0,0,0,1,1,1}
        },
        {
                      {1,1,1,1,0,1,0,0,1,0},
                      {0,0,0,0,0,1,0,0,0,0},
                      {0,0,0,0,0,1,0,0,0,1},
                      {1,0,0,1,0,0,0,0,0,0},
                      {1,0,0,1,0,1,1,1,0,0},
                      {0,0,0,0,0,0,0,0,0,1},
                      {1,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,1,0,0,0,0},
                      {0,0,0,0,0,1,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0}
        }
    };

};
#endif // MAINWINDOW_H
