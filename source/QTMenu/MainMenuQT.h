/*
  Authors: Michael Wilson, Marko Ilievski
  class: Human Computer Interaction
  file: 
  prof: Wendy Osborn
*/

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
    /*
        MainMenuQT();
        constructor that sets up buttons and style sheets in the main menu
    */
    MainMenuQT();
    /*
        void keyPressEvent(QKeyEvent *e);
        detects if a key is pressed, we used it to toggle the pause menu
    */
    void keyPressEvent(QKeyEvent *e);
    /*
        void paintEvent(QPaintEvent *PE);
        paintevent is used to paint to the back of the screen
        we used it for the logo
    */
    void paintEvent(QPaintEvent *PE);

public slots:

    /*
        void recieveWindow(int &newWin);
        recieve window will recieve information on what window should be opened
        newWin is the int value of what window is to be opened
    */
    void recieveWindow(int &newWin);

  private slots:
    /*
        void OpenChessBoard();
        slot connected to player 1 button 
        this will start a new chess game with a fresh board
    */
    void OpenChessBoard();
    /*
        void OpenLeaderBoard();
        opens the leaderboardMenuQT 
    */
    void OpenLeaderBoard();
    /*
        void OpenLoginMenu();
        opens the login menu
        connected to leaderBoard button

    */
    void OpenLoginMenu();
    /*
        void OpenTournamentMenu();
        opens the tournament menu 
        connected to the tournament button
    */
    void OpenTournamentMenu();
    /*
        void OpenloadMenu();
        opens the load menu where people can load old games
    */
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