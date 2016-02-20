#include <QtGui>

#include "MainMenuQT.h"

#include <vector>
#include <iostream>
MainMenuQT::MainMenuQT()
{
  //Creating all the used widgets
  
  //Help
  endMenu = new EndMenuQT(this);
  leaderBoardMenu = new LeaderBoardQT(this);
  loginMenu = new LoginMenuQT(this);
  tournamentMenu = new TournamentMenuQT(this);
  chessBoard = new ChessBoardQT(this); 

    //connections for the menus
  connect(chessBoard, SIGNAL(newWindowFunction(int &)), this ,SLOT(recieveWindow(int &)));

  //Creating all the buttons that will be created on this screen
  onePlayer = new QPushButton("One Player");
  twoPlayer = new QPushButton("Two Player");
  load = new QPushButton("Load");
  replay = new QPushButton("Replay");
  options = new QPushButton("Options");
  eexit = new QPushButton("Exit"); 


  //button set up
    onePlayer->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
    twoPlayer->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
    load->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
    replay->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
    options->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
    eexit->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
    eexit->setMaximumHeight(60);
    options->setMaximumHeight(60);
    replay->setMaximumHeight(60);
    load->setMaximumHeight(60);
    twoPlayer->setMaximumHeight(60);
    onePlayer->setMaximumHeight(60);
    // onePlayer 
    // twoPlayer
    // load
    // options
    // eexit

    
   //TODO - I Dont know what the hell this does
   QWidget *centralWidget = new QWidget;
   setCentralWidget(centralWidget);

   //TODO Make button style sheet
   //Creating the connections for the buttons
    connect(onePlayer, SIGNAL(clicked()), this, SLOT(OpenChessBoard())); 
    connect(twoPlayer, SIGNAL(clicked()), this, SLOT(OpenChessBoard())); 
    //connect(load, SIGNAL(clicked()), this, SLOT(OpenWindow(endMenu))); 
    //connect(leaderBoardMenu, SIGNAL(clicked()), this, SLOT(OpenWindow(leaderBoardMenu))); 
    //connect(loginMenu, SIGNAL(clicked()), this, SLOT(OpenWindow(loginMenu))); 
    connect(eexit, SIGNAL(clicked()), this, SLOT(close())); 

    
  //setLayout(layout);
   QGridLayout *gridLayout = new QGridLayout;
    gridLayout-> setRowMinimumHeight(0,300);
   gridLayout-> setColumnMinimumWidth(0,500);

   gridLayout -> addWidget(onePlayer,1,1,1,1);
   

   gridLayout -> addWidget(twoPlayer,2,1,1,1);
   

   gridLayout -> addWidget(load,3,1,1,1);
   
   gridLayout -> addWidget(replay,4,1,1,1);
   

   gridLayout -> addWidget(options,5,1,1,1);
   

   gridLayout -> addWidget(eexit,6,1,1,1);  
   

   gridLayout-> setColumnMinimumWidth(2,500);
    gridLayout-> setRowMinimumHeight(7,100);

   centralWidget->setLayout(gridLayout);
   



}
//TODO Making this open all ex (widget * target) 
void MainMenuQT::OpenChessBoard(){
  chessBoard->showFullScreen();

 // this->hide();

}

//TODO what buttons should be handled at the main Menu
void MainMenuQT::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Escape){
    	pauseMenu = new PauseMenuQT(this);
    	connect(pauseMenu, SIGNAL(closeWin()), this, SLOT(close()));
    	pauseMenu->show();
    	std::cerr << "Here" << std::endl;
    }
}

void MainMenuQT::recieveWindow(int &newWin)
{
  switch (newWin)
  {
    //this->hide();
    case 1:
      //delete pauseMenu;
      pauseMenu = new PauseMenuQT(this);
      connect(pauseMenu, SIGNAL(closeWin()), this, SLOT(close()));
      pauseMenu->show();
    case 2:
      this->show();
  }

}
void MainMenuQT::paintEvent(QPaintEvent *PE)
{

  QImage logo("QTMenu/Art/ChessMasterLogo.png");
  QPainter paint(this); 
  paint.drawImage(375,100, logo);

}