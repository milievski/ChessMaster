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
	void generate(int PlayerNumber);
signals:
	

public slots:
	/*
		void generate();

	*/
	void generate();

private:
	QPushButton *exitt, *save, *Main;
	QPushButton *Generate;
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

private slots:
	


};

#endif