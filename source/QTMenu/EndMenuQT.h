/*
	Authors: Michael Wilson, Marko Ilievski
	class: Human Computer Interaction
	file: 
	prof: Wendy Osborn
*/

#ifndef ENDMENUQT_H
#define ENDMENUQT_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>


  class QPushButton;
class QTableWidget;
class QLabel;
class EndMenuQT : public QDialog
{
	Q_OBJECT
public:
	/*
		EndMenuQT(QWidget *parent = 0);
		constructor for endmenu, sets up all buttons and style sheets
	*/
	EndMenuQT(int r);
	void paintEvent(QPaintEvent *PE);
signals:
  	/*
		void recieveWindow(int &newWin);
		signal that tells the main window what whindow should be showed
	*/
    void recieveWindow(int &newWin);


public slots:
	/*
		void leaderBoardSlot();
		leaderBoardSlot the gets connected to the leaderboard button
		emits the recievewindow signal to the main window

	*/
	void leaderBoardSlot();
	/*
		void mainMenuSlot();
		this is a slot that is connected to the mainmenu button
		it emits and signal that tells the main QT window that it needs to show the main window
	*/
	void mainMenuSlot();
	/*
		void exitSlot();
		exit slots is connected to the exit button
		this will tell the main QT window that we want to shut down the entire program

	*/
	void exitSlot();


private:
	/*
		buttons, enough said
	*/
	QPushButton *exitt, *leaderBoard, *Main;
	QLabel *Message;


};

#endif