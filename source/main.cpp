//******************************************************************************
/// \auth michael wilson, Brandon Robertson
/// \brief main program function
/// \date Nov 11, 2014
//******************************************************************************
#include <iostream>
#include <string>
using std::string;
#include <cstdlib>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
//#include "Game.h"
//#include "ChessBoard.h"
#include "Menu/GenericMenu.h"
#include "Menu/MainMenu.h"
#include "Menu/PauseMenu.h"
#include "Menu/EndMenu.h"
#include "Menu/LeaderBoard.h"
#include "Menu/TournamentMenu.h"
#include "Menu/LoginMenu.h"
#include "chessGameGUI.h"
#include "status.h"

#include <QApplication>
#include "QTMenu/MainMenuQT.h"

int colorMine = 0;

//using namespace std;
//hello


int main(int argc, char *argv[])
{
       
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    status* info = new status();
    GenericMenu* menupointer = new MainMenu;
    GenericMenu* temp = NULL;
    string menu = "Main";
    printf("\033[00;32m");


    while (menu != "exit")
    {
      temp = menupointer->menufunc(menu, info);
      delete menupointer;
      menupointer = temp;
      temp = NULL; 
    }
    delete info;  
    delete menupointer;

    QApplication app(argc,argv);

  MainMenuQT window;
 window.setWindowTitle("Clock Window");
  //window.resize(800,600);
  window.show();

  return app.exec();
    
  }

