#ifndef CHESSBOARDQT_H
#define CHESSBOARDQT_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>


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

private slots:
	void keyPressEvent(QKeyEvent *e);

private:
	QPushButton *exitt, *save, *Main;







};

#endif