#include "PauseMenuQT.h"
#include <QtGui>
#include <QDialog>

#include <iostream>
PauseMenuQT::PauseMenuQT(QWidget *parent)  
{

  this->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
	this->setFixedSize(300,300);
  exitt = new QPushButton("exit");
	save  = new QPushButton("save");
	Main = new QPushButton("Main Menu");
  canncell = new QPushButton("canncell");



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

void PauseMenuQT::paintEvent(QPaintEvent *PE)
{

  QImage logo("QTMenu/Art/ChessMasterLogo.png");
  logo = logo.scaled(300, 100);
  QPainter paint(this); 

  paint.drawImage(0,0, logo);

}