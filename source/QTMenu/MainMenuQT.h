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
#include "loadMenuQT.h"
#include "../ChessBoard.h"

class KeyEvent;
class QPushButton;
class QPixmap;
class QPalette;
class QImage;

class MainMenuQT: public QMainWindow
{
  Q_OBJECT
  public:

    MainMenuQT();
    void keyPressEvent(QKeyEvent *e);
    void paintEvent(QPaintEvent *PE);

public slots:
    // slot recieves an intiger that determines the next window
    void recieveWindow(int &newWin);

  private slots:
    void OpenChessBoard();
    void OpenLeaderBoard();
    void OpenLoginMenu();
    void OpenTournamentMenu();
    void OpenloadMenu();
  private:

    QPixmap *backroundButton;
    QPalette *pallet;
  	QPushButton *onePlayer, *twoPlayer, *load, *replay, *login, *leaderBoard, *eexit;
  	PauseMenuQT *pauseMenu;
    EndMenuQT *endMenu;
    LeaderBoardQT *leaderBoardMenu;
    LoginMenuQT *loginMenu;
    TournamentMenuQT *tournamentMenu;
    ChessBoardQT *chessBoard_qt;
    loadMenuQT *loadMenu;

     
};

#endif