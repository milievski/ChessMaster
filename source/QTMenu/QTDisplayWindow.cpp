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
	layout -> addWidget(message_l,1,0,1,4);

    setLayout(layout);
    connect(ok_b, SIGNAL(clicked()), this, SLOT(closeWin()));
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    show();

}


void QTDisplayWindow::closeWin()
{
	close();
}