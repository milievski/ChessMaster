/*
	Authors: Michael Wilson, Marko Ilievski
	class: Human Computer Interaction
	file: 
	prof: Wendy Osborn
*/

#ifndef TOURNAMENTMENUQT_H
#define TOURNAMENTMENUQT_H

#include <QWidget>
#include <QtGui> 
#include <QTimer>
#include <string>
#include <vector>
#include <QMouseEvent>


class QPushButton;
class QLineEdit;
class QLabel;
class QFont;


class TournamentMenuQT : public QDialog
{
	Q_OBJECT
public:
	/*
		TournamentMenuQT(QWidget *parent = 0);
		constructs the windows buttons and style sheets
	*/
	TournamentMenuQT(QWidget *parent = 0);
	void paintEvent(QPaintEvent *PE);
	/*
		void generate(int PlayerNumber);
		
	*/
	void generate2P();
	void generate4P();
	void generate8P();
signals:
	
	void newWindowFunction(int &win);
public slots:
	
	void changePlayers(int n);
	void generate();
		/*
		void mainMenu();
		this slot is connected to the main menu button,
		it will emit the newWindowFunction with the main menu integer

	*/
		void mainMenu();
	/*
		void CloseWin();
		this is a slot that closes the entire program
		it emits the newWindowFunction signal to tell the main window that the program needs to shut down

	*/
		void CloseWin();

private:
	
	QPushButton *exitt, *save, *Main;
	QPushButton *Generate, *Menu, *Exit;
	QLabel *Player1Label;
   	QLabel *Player2Label;
   	QLabel *Player3Label;
   	QLabel *Player4Label;
   	QLabel *Player5Label;
   	QLabel *Player6Label;
   	QLabel *Player7Label;
   	QLabel *Player8Label;
   	QLabel *PlayerNumberLabel;

	QLineEdit *Player1;
	QLineEdit *Player2;
	QLineEdit *Player3;
	QLineEdit *Player4;
	QLineEdit *Player5;
	QLineEdit *Player6;
	QLineEdit *Player7;
	QLineEdit *Player8;

	QComboBox *numberPlayer;

	QFont *font;
	QFont *font2;

	QGridLayout *gridLayout;
	bool draw;
private slots:
	


};

#endif