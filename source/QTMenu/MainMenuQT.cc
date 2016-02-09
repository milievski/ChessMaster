#include <QtGui>

#include "MainMenuQT.h"

#include <vector>
#include <iostream>
MainMenuQT::MainMenuQT()
{

   QFont Smallfont("Arial", 20);
   QFont Largefont("Arial", 28);
   
   QWidget *centralWidget = new QWidget;
   setCentralWidget(centralWidget);
  

   alarmOne = new QPushButton("Alarm One");
   alarmOne->setFont(Smallfont);
   alarmTwo = new QPushButton("Alarm Two");
   alarmTwo->setFont(Smallfont);
   alarmThree = new QPushButton("Alarm Three");
   alarmThree->setFont(Smallfont);
   alarmFour = new QPushButton("Alarm Four");
   alarmFour->setFont(Smallfont);

   nightDayB = new QPushButton("AM");
   nightDayB->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   nightDayB->setFont(Largefont);
   yearB = new QPushButton("2016");
   yearB ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   yearB->setFont(Largefont);
   quitB = new QPushButton("Quit");
   quitB ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   quitB->setFont(Largefont);

   //Labels
   hourL = new QLabel("Hours");
   hourL->setAlignment(Qt::AlignCenter);
   hourL->setFont(Smallfont);
   minuteL = new QLabel("Minutes");
   minuteL->setAlignment(Qt::AlignCenter);
   minuteL->setFont(Smallfont);
   secondL = new QLabel("Seconds");
   secondL->setAlignment(Qt::AlignCenter);
   secondL->setFont(Smallfont);
   dayL =  new QLabel("Day");
   dayL->setAlignment(Qt::AlignCenter);
   dayL->setFont(Smallfont);
   monthL =  new QLabel("Month");
   monthL->setAlignment(Qt::AlignCenter);
   monthL->setFont(Smallfont);
   yearL =  new QLabel("Year");
   yearL->setAlignment(Qt::AlignCenter);
   yearL->setFont(Smallfont);
   timeOfDayL =  new QLabel("Time of Day");
   timeOfDayL->setAlignment(Qt::AlignCenter);
   timeOfDayL->setFont(Smallfont);


   //Progress Bars
   hourBar = new QProgressBar();
   hourBar-> setMinimum(0);
   hourBar-> setMaximum(12);
   hourBar->setValue(1);
   hourBar->setMaximumHeight(500);
   hourBar-> setFont(Largefont);
   hourBar->setInvertedAppearance(true);
   

   minuteBar = new QProgressBar();
   minuteBar-> setMinimum(0);
   minuteBar-> setMaximum(60);
   minuteBar->setValue(30);
   minuteBar->setMaximumHeight(500);
   minuteBar-> setFont(Largefont);
   minuteBar->setInvertedAppearance(true);

   secondBar = new QProgressBar();
   secondBar-> setMinimum(0);
   secondBar-> setMaximum(60);
   secondBar->setValue(10);
   secondBar->setMaximumHeight(500);
   secondBar-> setFont(Largefont);
   secondBar->setInvertedAppearance(true);
   
   dayBar = new QProgressBar();
   dayBar-> setMinimum(0);
   dayBar-> setMaximum(60);
   dayBar->setValue(30);
   dayBar->setMaximumHeight(500);
   dayBar-> setFont(Largefont);
   dayBar->setInvertedAppearance(true);

   monthBar = new QProgressBar();
   monthBar-> setMinimum(0);
   monthBar-> setMaximum(12);
   monthBar->setValue(10);
   //monthBar->setFormat("Feb");
   monthBar->setMaximumHeight(500);
   monthBar-> setFont(Largefont);
   monthBar->setInvertedAppearance(true);
   

   //Timer
   updateT = new QTimer(this);


   //Connections
   connect(updateT, SIGNAL(timeout()), this, SLOT(updateTime())); 
   updateT->start(20);

   //Layout
   QGridLayout *gridLayout = new QGridLayout;

   //First Layer
   gridLayout->addWidget(alarmOne,0,0,1,1);
   gridLayout->addWidget(alarmTwo,0,1,1,1);
   gridLayout->addWidget(alarmThree,0,2,1,1);
   gridLayout->addWidget(alarmFour,0,3,1,1);

   //Second Layer
   gridLayout->addWidget(hourBar,1,1,2,1);
   gridLayout->addWidget(minuteBar,1,2,2,1);
   gridLayout->addWidget(secondBar,1,3,2,1);   
   gridLayout->addWidget(nightDayB,1,0,2,1); 
   gridLayout-> setRowMinimumHeight(1,85);
   
   //Forth Layer
   
   gridLayout->addWidget(timeOfDayL,3,0,1,1);
   gridLayout->addWidget(hourL,3,1,1,1);
   gridLayout->addWidget(minuteL,3,2,1,1);
   gridLayout->addWidget(secondL,3,3,1,1);  

   gridLayout->addWidget(monthBar,4,1,2,1);
   gridLayout->addWidget(dayBar,4,2,2,1);
   gridLayout->addWidget(quitB,4,3,3,1);   
   gridLayout->addWidget(yearB,4,0,2,1);
   gridLayout-> setRowMinimumHeight(4,85);     


   gridLayout->addWidget(yearL,6,0,1,1);
   gridLayout->addWidget(monthL,6,1,1,1);
   gridLayout->addWidget(dayL,6,2,1,1);

   centralWidget->setLayout(gridLayout);
   



}

void MainMenuQT::updateTime(){
   updateT->start(10);
   QTime curTime = QTime::currentTime();
   int s = curTime.second();
   int m = curTime.minute();
   int h = curTime.hour();
   if (h < 12)
   {
      nightDayB->setText("AM");
      nightDayB-> setStyleSheet("background-color:#FFFF00");
      if(h== 0)
         h=1;
   }
   if (h >= 12){
      
         nightDayB->setText("PM");
         nightDayB-> setStyleSheet("background-color:#0000A0");
      if (h>12)
         h -= 12;

   }
   secondBar->setFormat(QString::number(s));
   secondBar->setValue(s);
   minuteBar->setFormat(QString::number(m));
   minuteBar->setValue(m);
   hourBar->setFormat(QString::number(h));
   hourBar->setValue(h);

   QDate date = QDate::currentDate();
   int d = date.day();
   int mon = date.month();
   int y = date.year();
   int maxd = date.daysInMonth();
   dayBar->setFormat(QString::number(d));
   dayBar->setValue(d);
   dayBar-> setMaximum(maxd);
   monthBar->setFormat(QString::number(mon));
   monthBar->setValue(mon);


}
