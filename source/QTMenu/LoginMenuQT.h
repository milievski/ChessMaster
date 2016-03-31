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
class QLabel;

class LoginMenuQT : public QDialog
{
	Q_OBJECT
public:
	LoginMenuQT(QWidget *parent = 0);


signals:
	void newWindowFunction(int &win);

private slots:
	void mainMenu();
	void loginPlayr1();
	void loginPlayr2();
	void logoutPlayr1();
	void logoutPlayr2();


private:
	void loadCreatePlayer(const QString &name, RegisteredPlayer* &p);

	QPushButton *loginP1_b, *loginP2_b, *logoutP1_b, *logoutP2_b, *back_b;
	QLineEdit *player1_LE, *player2_LE;
	QLabel *player1_l, *player2_l;



};

#endif