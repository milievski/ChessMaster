#include "LeaderBoardQT.h"
#include <QtGui>

LeaderBoardQT::LeaderBoardQT(QWidget *parent) : QDialog(parent)
{
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
   gradeTable->setColumnCount(4);
   m_TableHeader<<"PLayer Name"<<"Games Won" <<"Games Lost" << "Elo";
   gradeTable->setHorizontalHeaderLabels(m_TableHeader);
   //gradeTable->verticalHeader()->setVisible(fal);
   gradeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
   gradeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
   gradeTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
   //gradeTable->setShowGrid(false);
   gradeTable->setStyleSheet("background-color:white");


	for (unsigned int x = loopProtect; x < SIZE_LEADER;x++)
	{

		Playerptr->restoreMemento(names[x]);
		QTableWidgetItem *PlayerName = new QTableWidgetItem;
   		PlayerName->setText(QString::fromStdString(Playerptr->getName()));
		gradeTable->setItem(x,0,PlayerName);
		QTableWidgetItem *GamesW = new QTableWidgetItem;
   		GamesW->setText(QString::number(Playerptr->getGamesWon()));		
		gradeTable->setItem(x,1,GamesW);
		QTableWidgetItem *GamesL = new QTableWidgetItem;
   		GamesL->setText(QString::number(Playerptr->getGamesLost()));
		gradeTable->setItem(x,2,GamesL);
		QTableWidgetItem *Elo = new QTableWidgetItem;
   		Elo->setText(QString::number(Playerptr->getElo()));
		gradeTable->setItem(x,3,Elo);
		
		
	}

	//QWidget *centralWidget = new QWidget;
   	//setCentralWidget(centralWidget);
	exitt = new QPushButton("exit");
	Main = new QPushButton("Main Menu");

	QGridLayout *layout = new QGridLayout;
	layout-> setRowMinimumHeight(0,300);
   layout-> setColumnMinimumWidth(0,200);
   layout -> addWidget(gradeTable,1,1,1,2);
   layout -> addWidget(exitt,2,1,1,1);
   layout -> addWidget(Main,2,2,1,1);
   layout-> setColumnMinimumWidth(3,200);
    layout-> setRowMinimumHeight(2,80);
    layout -> addWidget(gradeTable,1,1,1,1);
    layout-> setRowMinimumHeight(4,80);
   setLayout(layout);
	


}
void LeaderBoardQT::paintEvent(QPaintEvent *PE)
{

  QImage logo("QTMenu/Art/ChessMasterLogo.png");
  QPainter paint(this); 
  paint.drawImage(375,100, logo);

}