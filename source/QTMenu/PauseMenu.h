#pragma once
#include <QWidget>
#include "canvas.h"
#include <QTimer>
#include <string>
#include <QMouseEvent>


  class QPushButton;

class PauseMenu : public QWidget
{
	Q_OBJECT
public:
	PauseMenu(QWidget *parent = 0);


public slot:


private:
	QPushButton *exitt, *save, *Main;

private slot:



}