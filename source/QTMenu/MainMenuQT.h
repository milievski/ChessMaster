#ifndef MainMenuQT_H
#define MainMenuQT_H

#include <QMainWindow>
#include <QtGui>
#include <vector>
#include "PauseMenuQT.h"
#include "TournamentMenuQT.h"
#include "LoginMenuQT.h"
#include "LeaderBoardQT.h"
#include "EndMenuQT.h"

class KeyEvent;
class QPushButton;



class MainMenuQT: public QMainWindow
{
  Q_OBJECT
  public:

    MainMenuQT();
    void keyPressEvent(QKeyEvent *e);
  private slots:

    

  private:

  	QPushButton *onePlayer, *twoPlayer, *load, *replay, *options, *eexit;
  	PauseMenuQT *pauseMenu;
    EndMenuQT *endMenu;
    LeaderBoardQT *leaderBoardMenu;
    LoginMenuQT *loginMenu;
    TournamentMenuQT *tournamentMenu;


     
};

#endif