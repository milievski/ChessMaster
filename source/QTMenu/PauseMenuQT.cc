#include "PauseMenuQT.h"
#include <QtGui>
#include <QDialog>
PauseMenuQT::PauseMenuQT(QWidget *parent) : QDialog(parent)
{

	exitt = new QPushButton("exit");
	save  = new QPushButton("save");
	Main = new QPushButton("Main Menu");
  canncell = new QPushButton("canncell");


	QGridLayout *layout = new QGridLayout;
   layout -> addWidget(exitt,0,0,1,1);
   layout -> addWidget(save,0,1,1,1);
   layout -> addWidget(Main,0,2,1,1);
   layout -> addWidget(canncell,0,3,1,1);
   setLayout(layout);


    this->setWindowState(this->windowState() ^ Qt::WindowFullScreen);
    //this->setWindowOpacity(true);


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
  close();
}