#ifndef CHESSBOARDQT_H
#define CHESSBOARDQT_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>


  class QPushButton;
class QTableWidget;

class ChessBoardQT : public QDialog
{
	Q_OBJECT
public:
	ChessBoardQT(QWidget *parent = 0);
signals:


//public slot:


private:
	QPushButton *exitt, *save, *Main;

private slots:



};

#endif