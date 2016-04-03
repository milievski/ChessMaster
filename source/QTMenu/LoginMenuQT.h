/*
	Authors: Michael Wilson, Marko Ilievski
	class: Human Computer Interaction
	file: 
	prof: Wendy Osborn
*/

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
	/*
		LoginMenuQT(QWidget *parent = 0);
		constructor that sets up the loginMenus buttons and stylesheets

	*/
	LoginMenuQT(QWidget *parent = 0);


signals:
	/*
		void newWindowFunction(int &win);
		signal that sends a int to the main window that tells it what window should be opened next
	*/
	void newWindowFunction(int &win);

private slots:
	/*
		void mainMenu();
		this is a slot that closes the entire program
		it emits the newWindowFunction signal to tell the main window that the program needs to shut down

	*/
	void mainMenu();
	/*
		void loginPlayr1();
		loginPlayer1 sets what ever is in player1_LE to the registered player1 string

	*/
	void loginPlayr1();
	/*
		void loginPlayr2();
		loginPlayer2 sets what ever is in player12LE to the registered player2 string

	*/
	void loginPlayr2();
	/*
		void logoutPlayr1();
		the second player gets logged out

	*/
	void logoutPlayr1();
	/*
		void logoutPlayr2();
		the first player gets logged out

	*/
	void logoutPlayr2();


private:
	/*
		void loadCreatePlayer(const QString &name, RegisteredPlayer* &p);
		helper function that loads the registered player into p with the name,
		if the player does not exsist it creates a new one
	*/
	void loadCreatePlayer(const QString &name, RegisteredPlayer* &p);

	QPushButton *loginP1_b, *loginP2_b, *logoutP1_b, *logoutP2_b, *back_b;
	QLineEdit *player1_LE, *player2_LE;
	QLabel *player1_l, *player2_l;



};

#endif