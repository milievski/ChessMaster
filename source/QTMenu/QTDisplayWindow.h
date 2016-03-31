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

class QTDisplayWindow : public QDialog
{
	Q_OBJECT
public:
	QTDisplayWindow(QString	message);
	QTDisplayWindow();
	~QTDisplayWindow();

private slots:
	void closeWin();

private:
	QPushButton *ok_b;

};