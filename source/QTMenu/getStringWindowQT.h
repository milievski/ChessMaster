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
	getStringWindowQT(QString	message);
	getStringWindowQT();
	~getStringWindowQT();

private slots:
	void closeWin();

signals:
	void returnString();

private:
	QPushButton *ok_b;
	QLineEdit *saveLine_le;

};