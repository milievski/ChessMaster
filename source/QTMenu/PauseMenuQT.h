#ifndef PAUSEMENUQT_H
#define PAUSEMENUQT_H

#include <QWidget>
#include <QTimer>
#include <string>
#include <QMouseEvent>


  class QPushButton;

class PauseMenuQT : public QWidget
{
	Q_OBJECT
public:
	PauseMenuQT(QWidget *parent = 0);


public slot:


private:
	QPushButton *exitt, *save, *Main;

private slot:



};

#endif