#include "LeaderBoardQT.h"

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
	
	

}
void LeaderBoardQT::paintEvent(QPaintEvent *PE)
{


	


}