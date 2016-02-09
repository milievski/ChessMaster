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
   

  //Creating all the buttons that will be created on this screen
  onePlayer = new QPushButton("One Player");
  twoPlayer = new QPushButton("Two Player");
  load = new QPushButton("Load");
  replay = new QPushButton("Replay");
  options = new QPushButton("Options");
  eexit = new QPushButton("Exit"); 

   //TODO - I Dont know what the hell this does
   QWidget *centralWidget = new QWidget;
   setCentralWidget(centralWidget);


    
   QGridLayout *gridLayout = new QGridLayout;
   gridLayout -> addWidget(onePlayer,0,0,1,1);
   gridLayout -> addWidget(twoPlayer,1,0,1,1);
   gridLayout -> addWidget(load,2,0,1,1);
   gridLayout -> addWidget(replay,3,0,1,1);
   gridLayout -> addWidget(options,4,0,1,1);
   gridLayout -> addWidget(eexit,5,0,1,1);
   //setLayout(layout);
  

   centralWidget->setLayout(gridLayout);
   



}
//TODO what buttons should be handled at the main Menu
void MainMenuQT::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Escape){
    	
    	connect(pauseMenu, SIGNAL(closeWin()), this, SLOT(close()));
    	pauseMenu->show();
    	std::cerr << "Here" << std::endl;
    }
}