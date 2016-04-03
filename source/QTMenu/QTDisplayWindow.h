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
	QTDisplayWindow(QString	message);


private slots:
	void closeWin();

signals:
	void SendSaveSignal();
	

private:
	QPushButton *ok_b;
	QLabel *message_l;
	int seconds;
};