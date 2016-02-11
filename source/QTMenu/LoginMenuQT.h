#ifndef LOGINMENUQT_H
#define LOGINMENUQT_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>
#include <iostream>
#include <string>
#include "../Players/Player.h"
#include "../status.h"
#include "../Players/RegisteredPlayer.h"


  class QPushButton;
  class QString;
  class QLineEdit;
class QTableWidget;

class LoginMenuQT : public QDialog
{
	Q_OBJECT
public:
	LoginMenuQT(QWidget *parent = 0);
signals:


//public slot:


private:
	void loadCreatePlayer(const QString &name, RegisteredPlayer* &p);
	

private slots:
void loadPlayerSlot(const QString &name);



};

#endif