#include "PauseMenuQT.h"
#include <QtGui>
#include <QDialog>

#include <iostream>
PauseMenuQT::PauseMenuQT(QWidget *parent)  
{
  QFont font("League Gothic",18, true );
  font.setBold(true);
  font.setItalic(true);

  this-> setStyleSheet("background-color:#2d1606");
  this->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
	this->setFixedSize(300,300);
  exitt = new QPushButton("Exit");
	save  = new QPushButton("Save");
	Main = new QPushButton("Main Menu");
  canncell = new QPushButton("Cancel");

  exitt->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
  save->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
  Main->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
  canncell->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");

  exitt->setMaximumHeight(30);
    save->setMaximumHeight(30);
    Main->setMaximumHeight(30);
    canncell->setMaximumHeight(30);

  exitt->setFont(font);
    save->setFont(font);
    Main->setFont(font);
    canncell->setFont(font);

	QGridLayout *layout = new QGridLayout;
    layout -> setRowMinimumHeight(0,100);
   layout -> addWidget(exitt,1,0,1,1);
   layout -> addWidget(save,2,0,1,1);
   layout -> addWidget(Main,3,0,1,1);
   layout -> addWidget(canncell,4,0,1,1);
   setLayout(layout);


   connect(exitt, SIGNAL(clicked()), this, SLOT(closeWinSlot()));
   connect(Main, SIGNAL(clicked()), this, SLOT(mainMenuSlot()));
   connect(canncell, SIGNAL(clicked()), this, SLOT(canncellSlot()));
   connect(save, SIGNAL(clicked()), this, SLOT(saveGameSlot()));
}

void PauseMenuQT::closeWinSlot()
{
  int temp = 3;
	emit closeWin(temp);
}

void PauseMenuQT::mainMenuSlot()
{
  int temp = 2;
  emit closeWin(temp);
  close();

}
void PauseMenuQT::canncellSlot()
{

  this->hide();
  this->close();
}

void PauseMenuQT::saveGameSlot()
{
  saveWin = new getStringWindowQT();
  connect(saveWin, SIGNAL(returnString()), this, SLOT(sendSaveFlag()));
  saveWin->show();
}

void PauseMenuQT::paintEvent(QPaintEvent *PE)
{

  QImage logo("QTMenu/Art/ChessMasterLogo.png");
  logo = logo.scaled(300, 100);
  QPainter paint(this); 

  paint.drawImage(0,0, logo);

}

void PauseMenuQT::sendSaveFlag()
{
  emit saveGameSignal();
}