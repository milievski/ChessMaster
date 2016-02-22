#ifndef CHESSBOARDQT_H
#define CHESSBOARDQT_H

#include "../ChessBoard.h"
#include "../Piece/Piece.h"
#include <string>
#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>
#include <QImage>


  class QPushButton;
class QTableWidget;
class QPixmap;

class ChessBoardQT : public QDialog
{
	Q_OBJECT
public:
	ChessBoardQT(QWidget *parent = 0);
	
signals:
	// opens the pause menu
	void newWindowFunction(int &win);

protected:
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
	ChessBoard *CBoard;
	bool blacksTurn;

	int BoardPosX, BoardPosY; // position of where the board is to make it easy to place pieces
	int BoardSize;

	   bool picked;
   int pickedx, pickedy;

	int screenHeight, screenWidth;

	int DeadBoardBlackXIndex;
	int DeadBoardWhiteXIndex;
	int DeadBoardBlackYIndex;
	int DeadBoardWhiteYIndex;
	int DeadBoardStartX;
	int sizeBefore;
};

#endif