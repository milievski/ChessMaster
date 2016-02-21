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
  

    //connections for the menus
  

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

void MainMenuQT::OpenChessBoard(){
  chessBoard = new ChessBoardQT(this); 
  connect(chessBoard, SIGNAL(newWindowFunction(int &)), this ,SLOT(recieveWindow(int &)));
  chessBoard->showFullScreen();



}



//TODO what buttons should be handled at the main Menu
void MainMenuQT::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Escape){
    	pauseMenu = new PauseMenuQT(this);
    	connect(pauseMenu, SIGNAL(closeWin(int &)), this, SLOT(recieveWindow(int &)));
    	pauseMenu->showFullScreen();
    	std::cerr << "Here" << std::endl;
    }
}

void MainMenuQT::recieveWindow(int &newWin)
{
  switch (newWin)
  {
    //this->hide();
    case 1:
    {
      //delete pauseMenu;
    std::cerr << "HereHHH";
      pauseMenu = new PauseMenuQT(this);
      connect(pauseMenu, SIGNAL(closeWin(int &)), this, SLOT(recieveWindow(int &)));
      pauseMenu->show();
      break;
    }
    case 2:
    {
      chessBoard->close();
      this->showFullScreen();
      break;
    }
    case 3:
    {

    }
    case 4:
    {
      close();
      break;
    }
  }

}
void MainMenuQT::paintEvent(QPaintEvent *PE)
{

  QImage logo("QTMenu/Art/ChessMasterLogo.png");
  QPainter paint(this); 
  paint.drawImage(375,100, logo);

}