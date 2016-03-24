#include "QTDisplayWindow.h"


QTDisplayWindow::QTDisplayWindow(QString message, QDialog *parent) : QDialog(parent)
{

	QLabel* message_l = new QLabel(message);
	ok_b = new QPushButton("ok");

	QGridLayout *layout = new QGridLayout;
	layout -> addWidget(message_l,0,0,1,4);
    layout -> addWidget(ok_b,1,1,1,2);
    setLayout(layout);
    connect(ok_b, SIGNAL(clicked()), this, SLOT(closeWin()));
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    show();

}
QTDisplayWindow::QTDisplayWindow()
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

QTDisplayWindow::~QTDisplayWindow()
{
	delete ok_b;
}

void QTDisplayWindow::closeWin()
{
	close();
}