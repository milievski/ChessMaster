#ifndef CHESSBOARDQT_H
#define CHESSBOARDQT_H

#include "../ChessBoard.h"
#include "../Piece/Piece.h"
#include "QTDisplayWindow.h"
#include <string>
#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>
#include <QImage>
#include "PauseMenuQT.h"
#include "QTClock.h"
#include "../Database.h"

  class QPushButton;
class QTableWidget;
class QPixmap;

class ChessBoardQT : public QDialog
{
	Q_OBJECT
public:
	ChessBoardQT(ChessBoard *oldGame = 0, QWidget *parent = 0);
	
signals:
	// opens the pause menu
	void newWindowFunction(int &win);


public slots:
	void saveGameSlot();
	void getTime(const int &time);


protected:
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent *PE);

private slots:
	void keyPressEvent(QKeyEvent *e);

private:
	void hitBoxDetect(int x, int y);

	QPushButton *exitt, *save, *Main;
	
	 // - king = 0, Queen = 1, Bishop = 2, Knight = 3, Rook = 4, Pawn = 5 
	std::vector< QImage > BlackSprites; 
	std::vector< QImage > WhiteSprites;
	QImage *SpriteSheet;
	QImage selecterBox;
	QImage *whiteDeadBoard;
	QImage *BlackDeadBoard;
	QImage *whiteTimer;
	QImage *blackTimer;
	QImage *TimeBackground;
	QImage *blacksTurn_i, *whitesTurn_i;
	QImage *turnIndicator_i;
	QImage *chatBox_i;

	ChessBoard *CBoard;
	bool blacksTurn;

	int BoardPosX, BoardPosY; // position of where the board is to make it easy to place pieces
	int BoardSize;


	// variables for picked up action
	bool picked; //if a piece is picked up it will be true
    int pickedx, pickedy; // comtains the coordinates of the piece that is picked up
    int pickedDrawx, pickedDrawy;
    QImage pickedImage;
    string pickedType;
    int pickedColor;
    //end variables for picked up action


	int screenHeight, screenWidth;

	int DeadBoardBlackXIndex;
	int DeadBoardWhiteXIndex;
	int DeadBoardBlackYIndex;
	int DeadBoardWhiteYIndex;
	int DeadBoardStartX;
	int sizeBefore;

	QTDisplayWindow *MessageWindow_W;
	
	QString timeBlack_l, timeWhite_l;
	QTClock *Timer_c;
	int timeBlack, timeWhite;

	PauseMenuQT *pauseMenu_m;
};

#endif