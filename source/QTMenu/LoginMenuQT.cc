#include "LoginMenuQT.h"

LoginMenuQT::LoginMenuQT(QWidget *parent)
{
   loginP1_b = new QPushButton("Login Player 1");
   loginP2_b = new QPushButton("Login Player 2");
   logoutP1_b = new QPushButton("Logout Player 1");
   logoutP2_b = new QPushButton("Logout Player 2");
   back_b = new QPushButton("back");
   player1_LE = new QLineEdit();
   player2_LE = new QLineEdit();

   player1_l = new QLabel("player1");
   player2_l = new QLabel("player2");
   player1_l -> setMaximumHeight(60);
   player2_l -> setMaximumHeight(60);

   back_b ->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
   logoutP2_b -> setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
   logoutP1_b -> setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
   loginP2_b -> setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
   loginP1_b -> setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");

   back_b -> setMaximumHeight(60);
   logoutP2_b -> setMaximumHeight(60);
   logoutP1_b -> setMaximumHeight(60);
   loginP2_b -> setMaximumHeight(60);
   loginP1_b -> setMaximumHeight(60);

   connect(back_b, SIGNAL(clicked()), this, SLOT(mainMenu()));


   QGridLayout *gridLayout = new QGridLayout;
   gridLayout-> setRowMinimumHeight(0,250);
   gridLayout-> setColumnMinimumWidth(0,500);

   gridLayout -> addWidget(player1_l,1,1,1,2);
   gridLayout -> addWidget(player2_l,1,2,1,2);

   gridLayout -> addWidget(player1_LE,2,1,1,2);
   gridLayout -> addWidget(player2_LE,2,3,1,2);
   
   gridLayout -> addWidget(loginP1_b,3,2,1,1);
   gridLayout -> addWidget(logoutP1_b,3,1,1,1);

   gridLayout -> addWidget(loginP2_b,3,3,1,1);
   gridLayout -> addWidget(logoutP2_b,3,4,1,1);

   gridLayout -> addWidget(back_b,4,1,1,4);
   
   gridLayout-> setColumnMinimumWidth(5,500);
    gridLayout-> setRowMinimumHeight(5,75);
   setLayout(gridLayout);
   
}


void LoginMenuQT::loadCreatePlayer(const QString &name, RegisteredPlayer* &p)
{

   Database data;
   //DOES PLAYEREXIST IS ALWAYS RETURNING TRUE, KILLS FUNCTIONALITY HERE
   if(data.doesPlayerExist(name.toStdString()))
   {
      p->restoreMemento(data.loadPlayer(name.toStdString()));
   }
   else
   {
      //SAVED PLAYERS IS NOT CREATING ANY FILES EITHER
      data.savePlayer(p->generateMemento(), name.toStdString());
      p->restoreMemento(data.loadPlayer(name.toStdString()));
   }
   
}



void LoginMenuQT::loginPlayr1() // slot
{
   // login player 1
}

void LoginMenuQT::loginPlayr2() // slot
{
   // login player 2
}

void LoginMenuQT::logoutPlayr1() // slot
{
   // login player 1
}

void LoginMenuQT::logoutPlayr2() // slot
{
   // login player 2
}

void LoginMenuQT::mainMenu() // slot
{
   int temp = 5;
   emit newWindowFunction(temp);
}

