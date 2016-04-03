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
class QLineEdit;

class getStringWindowQT : public QDialog
{
	Q_OBJECT
public:
	/*
		getStringWindowQT(QString	message);
		this window displays the message as the main message
		also constructs a QLineEdit to gather string info to return
	*/
	getStringWindowQT(QString	message);
	/*
		getStringWindowQT();
		second constructor but has a default message
	*/	
	getStringWindowQT();
	/*
		~getStringWindowQT();
		window distructor
	*/	
	~getStringWindowQT();

private slots:
	/*
		void closeWin();
		close window will close this window 
	*/	
	void closeWin();

signals:
	/*
		void returnString();
		this signal tells the program that a string was saved
	*/	
	void returnString();

private:
	QPushButton *ok_b;
	QLineEdit *saveLine_le;

};