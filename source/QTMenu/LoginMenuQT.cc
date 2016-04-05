#include "LoginMenuQT.h"

LoginMenuQT::LoginMenuQT(QWidget *parent)
{
   QFont font("League Gothic",22, true );
   font.setBold(true);
   font.setItalic(true);

   loginP1_b = new QPushButton("Login Player 1");
   loginP2_b = new QPushButton("Login Player 2");

   loginP1_b->setFont(font);
   loginP2_b->setFont(font);
   logoutP1_b = new QPushButton("Logout Player 1");
   logoutP2_b = new QPushButton("Logout Player 2");
   logoutP1_b->setFont(font);
   logoutP2_b->setFont(font);
   back_b = new QPushButton("Main Menu");
   back_b->setFont(font);
   player1_LE = new QLineEdit();
   player2_LE = new QLineEdit();

   connect(loginP1_b, SIGNAL(clicked()), this, SLOT(loginPlayr1()));
   connect(loginP2_b, SIGNAL(clicked()), this, SLOT(loginPlayr2()));
   connect(logoutP1_b, SIGNAL(clicked()), this, SLOT(logoutPlayr1()));
   connect(logoutP2_b, SIGNAL(clicked()), this, SLOT(logoutPlayr2()));


   player1_l = new QLabel("Player 1");
   player2_l = new QLabel("Player 2");
   player1_l->setFont(font);
   player2_l->setFont(font);
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
   gridLayout-> setRowMinimumHeight(0,350);
   gridLayout-> setColumnMinimumWidth(0,250);

   gridLayout -> addWidget(player1_l,1,1,1,2);
   gridLayout -> addWidget(player2_l,1,3,1,2);

   gridLayout -> addWidget(player1_LE,2,1,1,2);
   gridLayout -> addWidget(player2_LE,2,3,1,2);
   
   gridLayout -> addWidget(loginP1_b,3,2,1,1);
   gridLayout -> addWidget(logoutP1_b,3,1,1,1);

   gridLayout -> addWidget(loginP2_b,3,3,1,1);
   gridLayout -> addWidget(logoutP2_b,3,4,1,1);

   gridLayout -> addWidget(back_b,4,1,1,4);
   
   gridLayout-> setColumnMinimumWidth(5,250);
    gridLayout-> setRowMinimumHeight(5,200);
   setLayout(gridLayout);

   player1_l->setText( "PLayer 1: "+ QString::fromStdString(RegisteredPlayerr1 ));
   player2_l->setText( "PLayer 2: "+ QString::fromStdString(RegisteredPlayerr2 ));
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
   RegisteredPlayerr1 = player1_LE->text().toStdString();
   player1_l->setText( "PLayer 1: "+ player1_LE->text() );
   MessageWindow_W = new QTDisplayWindow("Logged in as: "+player1_LE->text());
   MessageWindow_W->show();
}

void LoginMenuQT::loginPlayr2() // slot
{
   RegisteredPlayerr2 = player2_LE->text().toStdString();
   player2_l->setText( "PLayer 2: "+ player2_LE->text() );
   MessageWindow_W = new QTDisplayWindow("Logged in as: "+player2_LE->text());
   MessageWindow_W->show();
}

void LoginMenuQT::logoutPlayr1() // slot
{
   RegisteredPlayerr1 = "";
   player1_LE->clear();
   player1_l->setText( "PLayer 1: ");
   MessageWindow_W = new QTDisplayWindow("         Logged out ");
   MessageWindow_W->show();
}

void LoginMenuQT::logoutPlayr2() // slot
{
   RegisteredPlayerr2 = "";
   player2_LE->clear();
   player2_l->setText( "PLayer 2: ");
   MessageWindow_W = new QTDisplayWindow("         Logged out ");
   MessageWindow_W->show();
}

void LoginMenuQT::mainMenu() // slot
{
   int temp = 5;
   emit newWindowFunction(temp);
}

void LoginMenuQT::paintEvent(QPaintEvent *PE)
{

  QImage logo("QTMenu/Art/ChessMasterLogo.png");
  QImage backgroundMain{"QTMenu/Art/backgroundMain.png"};
  QPainter paint(this); 
  
  paint.drawImage(0,0,backgroundMain);
  paint.drawImage(375,100, logo);
}