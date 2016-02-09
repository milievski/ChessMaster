#ifndef PAUSEMENUQT_H
#define PAUSEMENUQT_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>


  class QPushButton;
class QTableWidget;

class PauseMenuQT : public QDialog
{
	Q_OBJECT
public:
	PauseMenuQT(QWidget *parent = 0);
signals:

//public slot:


private:
	QPushButton *exitt, *save, *Main;

//private slot:



};

#endif