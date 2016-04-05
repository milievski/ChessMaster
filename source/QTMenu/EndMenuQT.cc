#include "EndMenuQT.h"

EndMenuQT::EndMenuQT(QWidget *parent) 
{

	exitt = new QPushButton("exit");
	leaderBoard = new QPushButton("leaderBoard");
	Main = new QPushButton("Main Menu");

	connect( exitt, SIGNAL(clicked()), this, SLOT(exitSlot()));
	connect( leaderBoard, SIGNAL(clicked()), this, SLOT(leaderBoardSlot()));
	connect(Main , SIGNAL(clicked()), this, SLOT(mainMenuSlot()));


	QGridLayout *gridLayout = new QGridLayout;

	gridLayout-> addWidget(exitt, 2,0,1,2);
	gridLayout-> addWidget(leaderBoard, 0,0,1,2);
    gridLayout-> addWidget(Main, 1,0,1,2);

    setLayout(gridLayout);
}

void EndMenuQT::leaderBoardSlot()
{
	int temp = 9;
	emit recieveWindow(temp);
	close();
}

void EndMenuQT::mainMenuSlot()
{
	int temp = 2;
	emit recieveWindow(temp);
	close();
}

void EndMenuQT::exitSlot()
{
	int temp = 4;
	emit recieveWindow(temp);
	close();
}