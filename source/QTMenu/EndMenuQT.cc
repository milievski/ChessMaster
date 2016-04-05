#include "EndMenuQT.h"
#include "../Definitions.h"

EndMenuQT::EndMenuQT(int r = 0) 
{

	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
//this-> setStyleSheet("background-color:#2d1606");
	exitt = new QPushButton("Exit");
	leaderBoard = new QPushButton("Leader Board");
	Main = new QPushButton("Main Menu");

	 QFont font("League Gothic",18, true );
  	font.setBold(true);
  	font.setItalic(true);

	exitt->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
  	leaderBoard->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
  	Main->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
	exitt->setMaximumHeight(30);
    leaderBoard->setMaximumHeight(30);
    Main->setMaximumHeight(30);
 	exitt->setFont(font);
    leaderBoard->setFont(font);
    Main->setFont(font);

	connect( exitt, SIGNAL(clicked()), this, SLOT(exitSlot()));
	connect( leaderBoard, SIGNAL(clicked()), this, SLOT(leaderBoardSlot()));
	connect(Main , SIGNAL(clicked()), this, SLOT(mainMenuSlot()));


	QFont font2("League Gothic",30, true );
  	font2.setBold(true);
  	

  	if(r == 0 && colorMove%2 == 0)
    {
    	Message = new QLabel("Black is the winner!");
    }
    else if (r == 0 && colorMove%2 == 1) {
    	Message = new QLabel("White is the winner!");
    }
    else if (r == 2){
    	Message = new QLabel("Stale Mate!");
    }
    Message->setFont(font2);
	QGridLayout *gridLayout = new QGridLayout;

	gridLayout-> addWidget(Message, 0,0,1,3);
	gridLayout-> addWidget(exitt, 1,1,1,1);
	gridLayout-> addWidget(leaderBoard, 1,0,1,1);
    gridLayout-> addWidget(Main, 1,2,1,1);

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
void EndMenuQT::paintEvent(QPaintEvent *PE)
{


  QImage backgroundMain{"QTMenu/Art/backgroundMain.png"};
  QPainter paint(this); 

  paint.drawImage(0,0,backgroundMain);

}