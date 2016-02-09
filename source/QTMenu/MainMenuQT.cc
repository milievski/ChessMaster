#include <QtGui>

#include "MainMenuQT.h"

#include <vector>
#include <iostream>
MainMenuQT::MainMenuQT()
{
  //Creating all the used widgets
  pauseMenu = new PauseMenuQT(this);
  endMenu = new EndMenuQT(this);
  leaderBoardMenu = new LeaderBoardQT(this);
  loginMenu = new LoginMenuQT(this);
  tournamentMenu = new TournamentMenuQT(this);
   
   //TODO - I Dont know what the hell this does
   QWidget *centralWidget = new QWidget;
   setCentralWidget(centralWidget);

   
    
   QGridLayout *gridLayout = new QGridLayout;

  

   centralWidget->setLayout(gridLayout);
   



}
//TODO what buttons should be handled at the main Menu
void MainMenuQT::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Escape){
    	pMenu = new PauseMenuQT(this);
    	connect(pMenu, SIGNAL(closeWin()), this, SLOT(close()));
    	pMenu->show();
    	std::cerr << "Here" << std::endl;
    }
}