/*
	Authors: Michael Wilson, Marko Ilievski
	class: Human Computer Interaction
	file: 
	prof: Wendy Osborn
*/

#ifndef PAUSEMENUQT_H
#define PAUSEMENUQT_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>
#include "getStringWindowQT.h"
#include "../Definitions.h"


class QPushButton;
class QTableWidget;
class QFont;

class PauseMenuQT : public QDialog
{
	Q_OBJECT
public:
	/*
		PauseMenuQT(QWidget *parent = 0);
		constructs the pause menu by setting up buttons and stylesheets
	*/
	PauseMenuQT(QWidget *parent = 0);
	
	/*
		void paintEvent(QPaintEvent *PE);
		paint event is used to paint to the back of the window

	*/
	void paintEvent(QPaintEvent *PE);
signals:
	/*
		void closeWin(int &i);
		this signals is sent to close the program
	*/
	void closeWin(int &i);
	/*
		void saveGameSignal();
		this signal tells the main window that we need to save the current game to the database

	*/
	void saveGameSignal();

//public slot:


private:
	QPushButton *exitt, *save, *Main, *canncell;
	getStringWindowQT *saveWin;
private slots:
	/*
		void sendSaveFlag();
		slot that emits the saveGameSignal 
		this is connected to the save button

	*/
	void sendSaveFlag();
	/*
		void saveGameSlot();
		creates the savegame window where the player can save their current game under a name
	*/
	void saveGameSlot();
	/*
		void closeWinSlot();
		close window slot will close the window and set the focus back to the window before it

	*/
	void closeWinSlot();
	/*
		void mainMenuSlot();
		connected to the mainmenu button 
		tells the main window the we want to close the program
	*/
	void mainMenuSlot();
	/*
		void canncellSlot();
		canncellslot will close this window but not the program, so you can see the window before it

	*/
	void canncellSlot();

};

#endif