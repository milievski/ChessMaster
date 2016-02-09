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
  
   QGridLayout *gridLayout = new QGridLayout;

  

   centralWidget->setLayout(gridLayout);
   



}
void MainMenuQT::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Escape){
    	pMenu = new PauseMenuQT(this);
    	
    	pMenu->show();
    	//this->hide();
    	std::cerr << "Here" << std::endl;
    }
}