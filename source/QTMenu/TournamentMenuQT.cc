#include "TournamentMenuQT.h"
#include <iostream>
TournamentMenuQT::TournamentMenuQT(QWidget *parent )
{
  font = new QFont("League Gothic",22, true );
  font->setBold(true);
  font->setItalic(true);
  font2 = new QFont ("League Gothic",18, true );
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
  Player1Label = new QLabel("Player 1");
  Player1Label -> setFont(*font2); 
  Player2Label = new QLabel("Player 2");
  Player2Label -> setFont(*font2); 
  Player3Label = new QLabel("Player 3");
  Player3Label -> setFont(*font2); 
  Player4Label = new QLabel("Player 4");
  Player4Label -> setFont(*font2); 
  Player5Label = new QLabel("Player 5");
  Player5Label -> setFont(*font2); 
  Player6Label = new QLabel("Player 6");
  Player6Label -> setFont(*font2); 
  Player7Label = new QLabel("Player 7");
  Player7Label -> setFont(*font2); 
  Player8Label = new QLabel("Player 8");
  Player8Label -> setFont(*font2); 
  PlayerNumberLabel = new QLabel("Please select the number of players: ");
  PlayerNumberLabel-> setFont(*font2); 
  gridLayout = new QGridLayout();

   numberPlayer = new QComboBox;
   numberPlayer->addItem("2");
   numberPlayer->addItem("4");
   numberPlayer->addItem("8");
   numberPlayer -> setFont(*font2); 

   Generate = new QPushButton("Generate");
  Generate->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
 	Generate->setMaximumHeight(30);
  Generate->setFont(*font2);

   gridLayout = new QGridLayout;
   gridLayout-> setRowMinimumHeight(0,150);
   gridLayout-> setColumnMinimumWidth(0,300);
   gridLayout -> addWidget(PlayerNumberLabel,1,1,1,1);

   gridLayout -> addWidget(numberPlayer,1,2,1,1);
	gridLayout -> addWidget(Generate,1,3,1,1);
   gridLayout-> setColumnMinimumWidth(4,300);
   setLayout(gridLayout);
   connect(Generate, SIGNAL(clicked()), this, SLOT(generate())); 

}
void TournamentMenuQT::generate(){
	PlayerNumberLabel->hide();
}

void TournamentMenuQT::paintEvent(QPaintEvent *PE)
{

  QImage logo("QTMenu/Art/ChessMasterLogo.png");
  QImage backgroundMain{"QTMenu/Art/backgroundMain.png"};
  QPainter paint(this); 
  paint.drawImage(375,100, logo);
  paint.drawImage(0,0,backgroundMain);

}