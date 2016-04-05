#include "TournamentMenuQT.h"
#include <iostream>
TournamentMenuQT::TournamentMenuQT(QWidget *parent )
{
  draw = false;
  font = new QFont("League Gothic",22, true );
  font->setBold(true);
  font->setItalic(true);
  font2 = new QFont ("League Gothic",22, true );
  font2->setBold(false);
  font2->setItalic(true);

  //Create all line edits 	
  Player1 = new QLineEdit();
  Player1->setFont(*font2); 
  Player2 = new QLineEdit();
  Player2->setFont(*font2); 
  Player3 = new QLineEdit();
  Player3->setFont(*font2); 
  Player4 = new QLineEdit();
  Player4->setFont(*font2); 
  Player5 = new QLineEdit();
  Player5->setFont(*font2); 
  Player6 = new QLineEdit();
  Player6->setFont(*font2); 
  Player7 = new QLineEdit();
  Player7->setFont(*font2); 
  Player8 = new QLineEdit();
  Player8->setFont(*font2); 

  //Create all line Discriptions
  Player1Label = new QLabel("                                         Player 1  :");
  Player1Label -> setFont(*font2); 
  Player2Label = new QLabel("                                         Player 2  :");
  Player2Label -> setFont(*font2); 
  Player3Label = new QLabel("                                         Player 3  :");
  Player3Label -> setFont(*font2); 
  Player4Label = new QLabel("                                         Player 4  :");
  Player4Label -> setFont(*font2); 
  Player5Label = new QLabel("                                         Player 5  :");
  Player5Label -> setFont(*font2); 
  Player6Label = new QLabel("                                         Player 6  :");
  Player6Label -> setFont(*font2);        
  Player7Label = new QLabel("                                         Player 7  :");
  Player7Label -> setFont(*font2); 
  Player8Label = new QLabel("                                         Player 8  :");
  Player8Label -> setFont(*font2); 
  PlayerNumberLabel = new QLabel("Please select the number of players: ");
  PlayerNumberLabel-> setFont(*font2); 
  gridLayout = new QGridLayout();

   numberPlayer = new QComboBox;
   numberPlayer->addItem("2");
   numberPlayer->addItem("4");
   numberPlayer->addItem("8");
   numberPlayer -> setFont(*font2); 

font2->setBold(true);
   Generate = new QPushButton("Generate");
  Generate->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
 	Generate->setMaximumHeight(30);
  Generate->setFont(*font2);
  Menu = new QPushButton("Main Menu");
  Menu->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
  Menu->setMaximumHeight(30);
  Menu->setFont(*font2);
  Exit = new QPushButton("Exit");
  Exit->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
  Exit->setMaximumHeight(30);
  Exit->setFont(*font2);
font2->setBold(false);
   gridLayout = new QGridLayout;
   gridLayout-> setRowMinimumHeight(0,20);
   gridLayout-> setColumnMinimumWidth(0,200);
   gridLayout -> addWidget(PlayerNumberLabel,1,1,1,1);
   
	gridLayout -> addWidget(numberPlayer,1,2,1,2);
  gridLayout -> addWidget(Player1Label,2,1,1,1);
  gridLayout -> addWidget(Player1,2,2,1,2);
    gridLayout -> addWidget(Player2Label,3,1,1,1);
  gridLayout -> addWidget(Player2,3,2,1,2);
    gridLayout -> addWidget(Player3Label,4,1,1,1);
  gridLayout -> addWidget(Player3,4,2,1,2);
    gridLayout -> addWidget(Player4Label,5,1,1,1);
  gridLayout -> addWidget(Player4,5,2,1,2);
    gridLayout -> addWidget(Player5Label,6,1,1,1);
  gridLayout -> addWidget(Player5,6,2,1,2);
    gridLayout -> addWidget(Player6Label,7,1,1,1);
  gridLayout -> addWidget(Player6,7,2,1,2);
    gridLayout -> addWidget(Player7Label,8,1,1,1);
  gridLayout -> addWidget(Player7,8,2,1,2);
    gridLayout -> addWidget(Player8Label,9,1,1,1);
  gridLayout -> addWidget(Player8,9,2,1,2);

  gridLayout -> addWidget(Generate,10,1,1,1);
  gridLayout -> addWidget(Menu,10,2,1,1);
  gridLayout -> addWidget(Exit,10,3,1,1);

   gridLayout-> setColumnMinimumWidth(4,300);
   setLayout(gridLayout);
   connect(Generate, SIGNAL(clicked()), this, SLOT(generate())); 
   connect(Menu, SIGNAL(clicked()), this, SLOT(mainMenu())); 
   connect(Exit, SIGNAL(clicked()), this, SLOT(CloseWin())); 
   connect(numberPlayer,SIGNAL(activated(int)), this, SLOT(changePlayers(int)));
   Player3Label->hide();
  Player4Label->hide();
  Player5Label->hide();
  Player6Label->hide();
  Player7Label->hide();
  Player8Label->hide();

  Player3->hide();
  Player4->hide();
  Player5->hide();
  Player6->hide();
  Player7->hide();
  Player8->hide();
}
void TournamentMenuQT::changePlayers(int n){

  if (n==0){
    generate2P();
  }
  else if (n==1){
    generate4P();
  }
  else{
    generate8P();
  }
}
void TournamentMenuQT::generate2P(){
  Player1Label->show();
  Player2Label->show();
  Player3Label->hide();
  Player4Label->hide();
  Player5Label->hide();
  Player6Label->hide();
  Player7Label->hide();
  Player8Label->hide();

  Player1->show();
  Player2->show();
  Player3->hide();
  Player4->hide();
  Player5->hide();
  Player6->hide();
  Player7->hide();
  Player8->hide();

}
void TournamentMenuQT::generate4P(){
  
  Player1Label->show();
  Player2Label->show();
  Player3Label->show();
  Player4Label->show();
  Player5Label->hide();
  Player6Label->hide();
  Player7Label->hide();
  Player8Label->hide();

  Player1->show();
  Player2->show();
  Player3->show();
  Player4->show();
  Player5->hide();
  Player6->hide();
  Player7->hide();
  Player8->hide();
}
void TournamentMenuQT::generate8P(){
  
  Player1Label->show();
  Player2Label->show();
  Player3Label->show();
  Player4Label->show();
  Player5Label->show();
  Player6Label->show();
  Player7Label->show();
  Player8Label->show();

  Player1->show();
  Player2->show();
  Player3->show();
  Player4->show();
  Player5->show();
  Player6->show();
  Player7->show();
  Player8->show();
}
void TournamentMenuQT::generate(){

  
  numberPlayer->hide();
  PlayerNumberLabel->hide();
  Player1Label->hide();
  Player2Label->hide();
  Player3Label->hide();
  Player4Label->hide();
  Player5Label->hide();
  Player6Label->hide();
  Player7Label->hide();
  Player8Label->hide();

  Player1->hide();
  Player2->hide();
  Player3->hide();
  Player4->hide();
  Player5->hide();
  Player6->hide();
  Player7->hide();
  Player8->hide();
  Generate->hide();
  gridLayout-> setRowMinimumHeight(0,800);
  draw = true;
  update();
}
void TournamentMenuQT::CloseWin()
{

  int temp = 3;
  emit newWindowFunction(temp);
  this->close();
}

void TournamentMenuQT::mainMenu()
{

  int temp = 11;
  emit newWindowFunction(temp);
}
void TournamentMenuQT::paintEvent(QPaintEvent *PE)
{

  QImage logo("QTMenu/Art/ChessMasterLogo.png");
  QImage backgroundMain{"QTMenu/Art/backgroundMain.png"};
  QPainter paint(this); 
  
  paint.drawImage(0,0,backgroundMain);
  if (draw){
    QImage UC("QTMenu/Art/underConstruction.png");
    paint.drawImage(375,100, logo);
    UC = UC.scaled(800, 800, Qt::KeepAspectRatio);
    paint.drawImage(435,210, UC);
  }

}