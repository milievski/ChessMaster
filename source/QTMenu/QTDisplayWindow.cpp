#include "QTDisplayWindow.h"


QTDisplayWindow::QTDisplayWindow(QString message) 
{

	message_l = new QLabel(message);
	this->resize(600,180);
	
    QPixmap bkgnd("QTMenu/Art/BoarderBox.png");
    
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

   QFont font("League Gothic",30, true );
  font.setBold(true);
  font.setItalic(true);
  message_l-> setFont(font);
	ok_b = new QPushButton("ok");

	QGridLayout *layout = new QGridLayout;
  layout-> setColumnMinimumWidth(0,95);
	layout -> addWidget(message_l,1,1,1,4);

    setLayout(layout);
    connect(ok_b, SIGNAL(clicked()), this, SLOT(closeWin()));
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    show();
    timers = new QTimer();
    timers->start(1500);
    connect(timers, SIGNAL(timeout()), this, SLOT(closeWin()));
}


void QTDisplayWindow::closeWin()
{
	close();
}