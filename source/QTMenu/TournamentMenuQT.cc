#include "TournamentMenuQT.h"

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

  gridLayout = new QGridLayout();

 


}
void TournamentMenuQT::generate(int PlayerNumber){
	
	for (int i = 0; i < PlayerNumber;i++){
		
	}

}