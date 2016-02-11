#include "PauseMenuQT.h"
#include <QtGui>
#include <QDialog>
PauseMenuQT::PauseMenuQT(QWidget *parent) : QDialog(parent)
{

	exitt = new QPushButton("exit");
	save  = new QPushButton("save");
	Main = new QPushButton("Main Menu");

	QGridLayout *layout = new QGridLayout;
   layout -> addWidget(exitt,0,0,1,1);
   layout -> addWidget(save,0,1,1,1);
   layout -> addWidget(Main,0,2,1,1);
   setLayout(layout);

    this->showFullScreen();    
    this->hide();
    this->setWindowOpacity(true);
   connect(exitt, SIGNAL(clicked()), this, SLOT(closeWinSlot()));

}

void PauseMenuQT::closeWinSlot()
{
	emit closeWin();
}
