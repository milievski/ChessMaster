#include "loadMenuQT.h"
#include <QtGui>

loadMenuQT::loadMenuQT(QWidget *parent) : QDialog(parent)
{
	QFont font("League Gothic",22, true );
  font.setBold(true);
  font.setItalic(true);
  QFont font2("League Gothic",18, true );
  font2.setBold(false);
  font2.setItalic(true);

	Database data;
	vector<Memento*> names;
	names = data.getTopPlayers();
	RegisteredPlayer *Playerptr = new RegisteredPlayer;

	unsigned int curs = 0, loopProtect = 0;
	unsigned int SIZE_LEADER = names.size();
	if(names.size() == 0)
		close();

	gradeTable = new QTableWidget(this);
   gradeTable->setRowCount(SIZE_LEADER);
   gradeTable->setColumnCount(1);
   m_TableHeader<<"saved games";

   gradeTable->setHorizontalHeaderLabels(m_TableHeader);
   //gradeTable->verticalHeader()->setVisible(fal);
   gradeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
   gradeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
   gradeTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
   //gradeTable->setShowGrid(false);
   gradeTable->setStyleSheet("background-color:white");
   gradeTable->setFont(font2);
   gradeTable->horizontalHeader()->setFont(font2);

	for (unsigned int x = loopProtect; x < SIZE_LEADER;x++)
	{

		Playerptr->restoreMemento(names[x]);
		QTableWidgetItem *PlayerName = new QTableWidgetItem;
		PlayerName->setTextAlignment(Qt::AlignHCenter);
   		PlayerName->setText(QString::fromStdString(Playerptr->getName()));
		gradeTable->setItem(x,0,PlayerName);
		QTableWidgetItem *GamesW = new QTableWidgetItem;
		GamesW->setTextAlignment(Qt::AlignHCenter);
   		GamesW->setText(QString::number(Playerptr->getGamesWon()));		
		gradeTable->setItem(x,1,GamesW);
		QTableWidgetItem *GamesL = new QTableWidgetItem;
		GamesL->setTextAlignment(Qt::AlignHCenter);
   		GamesL->setText(QString::number(Playerptr->getGamesLost()));
		gradeTable->setItem(x,2,GamesL);
		QTableWidgetItem *Elo = new QTableWidgetItem;
		Elo->setTextAlignment(Qt::AlignHCenter);
   		Elo->setText(QString::number(Playerptr->getElo()));
		gradeTable->setItem(x,3,Elo);
		
		
	}


	exitt = new QPushButton("Exit");
  connect(exitt, SIGNAL(clicked()), this, SLOT(CloseWin()));
	Main = new QPushButton("Main Menu");
  connect(Main, SIGNAL(clicked()), this, SLOT(mainMenu()));

	exitt->setMaximumHeight(60);
    Main->setMaximumHeight(60);
    
    exitt->setFont(font);
    Main->setFont(font);

    exitt->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
    Main->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");

	QGridLayout *layout = new QGridLayout;
	layout-> setRowMinimumHeight(0,300);
   layout-> setColumnMinimumWidth(0,200);
   layout -> addWidget(gradeTable,1,1,1,2);
   layout -> addWidget(exitt,2,1,1,1);
   layout -> addWidget(Main,2,2,1,1);
   layout-> setColumnMinimumWidth(2,600);
   
   layout-> setColumnMinimumWidth(3,200);
    layout-> setRowMinimumHeight(2,80);
    layout -> addWidget(gradeTable,1,1,1,1);
    layout-> setRowMinimumHeight(4,80);
   setLayout(layout);
	


}
void loadMenuQT::paintEvent(QPaintEvent *PE)
{

  QImage logo("QTMenu/Art/ChessMasterLogo.png");
  QPainter paint(this); 
  paint.drawImage(375,100, logo);

}

void loadMenuQT::CloseWin()
{
  int temp = 3;
  emit newWindowFunction(temp);
}

void loadMenuQT::mainMenu()
{
  int temp = 6;
  emit newWindowFunction(temp);
}