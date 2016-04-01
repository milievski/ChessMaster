#include "getStringWindowQT.h"


getStringWindowQT::getStringWindowQT(QString message) 
{

	QLabel* message_l = new QLabel(message);
	ok_b = new QPushButton("save");
	saveLine_le = new QLineEdit();

	QGridLayout *layout = new QGridLayout;
	layout -> addWidget(message_l,0,0,1,4);
	layout -> addWidget(saveLine_le,0,1,1,4);
    layout -> addWidget(ok_b,1,2,1,2);
    setLayout(layout);
    connect(ok_b, SIGNAL(clicked()), this, SLOT(closeWin()));
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    show();

}
getStringWindowQT::getStringWindowQT()
{
	QLabel* message_l = new QLabel("hello");
	ok_b = new QPushButton("ok");

	QGridLayout *layout = new QGridLayout;
	layout -> addWidget(message_l,0,0,1,4);
    layout -> addWidget(ok_b,1,1,1,2);
    setLayout(layout);
    connect(ok_b, SIGNAL(clicked()), this, SLOT(closeWin()));
    //setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
}

getStringWindowQT::~getStringWindowQT()
{
	delete ok_b;
}

void getStringWindowQT::closeWin()
{
	close();
}