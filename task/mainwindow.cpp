#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QPushButton>

#include <QIcon>

//#define DEBUG


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Sea Battle Single Player");
    QIcon i(":/icon/ico.jfif");
    this->setWindowIcon(i);

    ui->pushButton->hide();
    randomField();
    _File();
    buttonArray();


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::_File()
{
    QFile file("field.txt");


    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File Openned!";
    }
    else
    {
        qDebug() << "File Not Found!";
    }

    while(!file.atEnd())
    {
        line = file.readLine();

        character = line.size();
        for (int i=0;i<character ;i++ ) {
            array[row][i].push_back(line[i]);
        }
        row++;
    }

    qDebug() << count;

     file.close();
}

void MainWindow::buttonArray()
{
    for (int i = 0;i<SIZE ;i++ ) {
        for (int j = 0; j< SIZE;j++ ) {
            arr[i][j] = new QPushButton(this);
#ifdef DEBUG
            arr[i][j]->setText(array[i][j]);
#endif
            arr[i][j]->setProperty("myProperty", array[i][j]);
            arr[i][j]->setGeometry((1+j)*20,(1+i)*20,20,20);
            arr[i][j]->show();
            count++;
            connect(arr[i][j], SIGNAL(clicked()), this, SLOT(buttonClicked()));
        }
    }
}

void MainWindow::buttonClicked()
{
    press_count--;
    QPushButton *button = (QPushButton *)sender();
    QVariant property = sender()->property("myProperty");
    if(property.toInt())
        qDebug() << property.toInt()<<" Good job!!! You hit the ship!";
    else
        qDebug() << property.toInt()<<" Missed!!!";

    button->blockSignals(true);

    if(property.toInt() == 1)
    {
        button->setStyleSheet("background-color:red");
        score += 10;
        QApplication::beep();
    }
    else
        button->setStyleSheet("background-color:blue");

    QString str = QString::number(score);
    ui->score_label->setText(str);
    QString press = QString::number(press_count);
    ui->press_count->setText(press);

    if(press_count == 0)
    {
        for (int i = 0;i<SIZE ;i++ ) {
            for (int j = 0; j< SIZE;j++ ) {
                arr[i][j]->hide();
            }
        }




        QFont f("Arial", fontSize, QFont::Bold);
        newLabel->setText("I am sorry but you lost!!!");
        newLabel->setStyleSheet("color:red");
        //newLabel->setFixedSize(200, 60);
        newLabel->setMargin(Margin);
        newLabel->setGeometry(X-10,Y,Width,Height);
        newLabel->setFont(f);
        newLabel->show();

        ui->pushButton->show();
        qDebug()<<"I am sorry but you lost!!!";
    }

    if(score == 200)
    {
        for (int i = 0;i<SIZE ;i++ ) {
            for (int j = 0; j< SIZE;j++ ) {
                arr[i][j]->hide();
            }
        }

        QFont f("Arial", fontSize, QFont::Bold);
        newLabel->setText("Congratulations!!!\n You have won!!!");
        newLabel->setStyleSheet("color:green");
        //newLabel->setFixedSize(Width, Height);
        newLabel->setMargin(Margin);
        newLabel->setGeometry(X, Y, Width, Height);
        newLabel->setFont(f);
        newLabel->show();

        ui->pushButton->show();
        qDebug()<<"Congratulations!!! You have won!!!";
    }


}

void MainWindow::randomField()
{
    QFile file("field.txt");

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
        qDebug() << "Not Open";
    else
        qDebug() << "Open";
    srand(time(NULL));
    int Field = rand()%fieldsNumber;

    QTextStream out(&file);
    for (int i =0; i<SIZE ; i++ ) {
        for (int j =0; j<SIZE; j++) {
            out<<BattleField[Field][i][j];
        }
        out<<'\n';
    }
    file.close();
}




void MainWindow::on_pushButton_clicked()
{
    MainWindow::close();
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::on_actionInfo_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Info");
    QIcon i(":/icon/ico.jfif");
    msgBox.setWindowIcon(i);
    msgBox.setText("Sea Battle Game for Single Player.\nMade in a porpose of trial task to be hired by Luxoft Company");

    msgBox.exec();
}

