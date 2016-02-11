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
#include "ChessBoardQT.h"

class KeyEvent;
class QPushButton;
class QPixmap;
class QPalette;

class MainMenuQT: public QMainWindow
{
  Q_OBJECT
  public:

    MainMenuQT();
    void keyPressEvent(QKeyEvent *e);
public slots:
    // slot recieves an intiger that determines the next window
    void recieveWindow(int &newWin);
   

  private slots:
    void OpenChessBoard();
    

  private:
    QPixmap *backroundButton;
    QPalette *pallet;
  	QPushButton *onePlayer, *twoPlayer, *load, *replay, *options, *eexit;
  	PauseMenuQT *pauseMenu;
    EndMenuQT *endMenu;
    LeaderBoardQT *leaderBoardMenu;
    LoginMenuQT *loginMenu;
    TournamentMenuQT *tournamentMenu;
    ChessBoardQT *chessBoard;

     
};

#endif