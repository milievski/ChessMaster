/*
	Authors: Michael Wilson, Marko Ilievski
	class: Human Computer Interaction
	file: 
	prof: Wendy Osborn
*/

#pragma once

#include "../ChessBoard.h"
#include "../Piece/Piece.h"
#include <string>
#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>
#include <QImage>
#include <QString>


class QPushButton;
class QTableWidget;
class QPixmap;
class QLabel;

class QTDisplayWindow : public QDialog
{
	Q_OBJECT
public:
	/*
		QTDisplayWindow(QString	message);
		constructs the window with the string that is passed in
	*/
	QTDisplayWindow(QString	message);


private slots:
	/*
		void closeWin();
		closes the window and sets the focus on the previous window
	*/
	void closeWin();

signals:
	/*
		void SendSaveSignal();
		sends the save signal that tells the program that we want to save the game
	*/
	void SendSaveSignal();
	

private:
	QPushButton *ok_b;
	QLabel *message_l;
	int seconds;
};