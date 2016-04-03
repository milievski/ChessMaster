/*
	Authors: Michael Wilson, Marko Ilievski
	class: Human Computer Interaction
	file: 
	prof: Wendy Osborn
*/


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
	//constructor
	// sets up chessboard if you pass one in
	ChessBoardQT(ChessBoard *oldGame = 0, QWidget *parent = 0);
	/*
		void loadCreatePlayer(const string &name, RegisteredPlayer* &p)
		 - helper function that loads the player if the player exsists,
		 else it creates a new player in "p"
	*/
	void loadCreatePlayer(const string &name, RegisteredPlayer* &p);
signals:
	/*
		void newWindowFunction(int &win);
		 - signal with the integer value of the window that needs to be opened next
	*/
	void newWindowFunction(int &win);


public slots:
	/*
		void saveGameSlot();
		save game is a slot that creates a savegamewindow to save the game
	*/
	void saveGameSlot();
	/*
		void getTime(const int &time);
		get time is connected to the timer that updates the clock in game
	*/
	void getTime(const int &time);


protected:
	/*
		void mouseReleaseEvent(QMouseEvent *e);
		when the mouse is released so we can move pieces on release of a button
	*/
	void mouseReleaseEvent(QMouseEvent *e);
	/*
		void mouseMoveEvent(QMouseEvent *e);
		keeps track of where the mouse is so the piece will move with your mouse
	*/
	void mouseMoveEvent(QMouseEvent *e);
	/*
			void mousePressEvent(QMouseEvent *e);
			picks a piece up when you click initialy

	*/
	void mousePressEvent(QMouseEvent *e);
	/*
			void paintEvent(QPaintEvent *PE);
			- paints everything on the window, basicly the board and pieces

	*/
	void paintEvent(QPaintEvent *PE);

private slots:
	/*
			void keyPressEvent(QKeyEvent *e);
			key press event is to check if esc is clicked for pause menu
	*/
	void keyPressEvent(QKeyEvent *e);

private:
	/*
		QString IntToString(int min, int sec);
		- helper class that converts an integer into a string ( for the time )
	*/
	QString IntToString(int min, int sec);
	/*
		void hitBoxDetect(int x, int y);
		determines if the spot you clicked was in the board and if it hit a "piece"
	*/
	void hitBoxDetect(int x, int y);

	QPushButton *exitt, *save, *Main;
	
	// all the images in the board
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
	// deadboard variables
	int DeadBoardBlackXIndex;
	int DeadBoardWhiteXIndex;
	int DeadBoardBlackYIndex;
	int DeadBoardWhiteYIndex;
	int DeadBoardStartX;
	int sizeBefore;

	QTDisplayWindow *MessageWindow_W;
	
	QString timeBlack_l, timeWhite_l;
	QTClock *Timer_c;
	int timeBlackm, timeWhitem;
	int timeBlacks, timeWhites;
	bool initTime;

	PauseMenuQT *pauseMenu_m;
};

#endif