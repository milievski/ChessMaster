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


private slots:
	void keyPressEvent(QKeyEvent *e);

private:
	QPushButton *exitt, *save, *Main;





};

#endif