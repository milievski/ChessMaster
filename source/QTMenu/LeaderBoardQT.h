/*
	Authors: Michael Wilson, Marko Ilievski
	class: Human Computer Interaction
	file: 
	prof: Wendy Osborn
*/

#ifndef LEADERBOARDQT_H
#define LEADERBOARDQT_H

#include <QWidget>
#include <QtGui>
#include <QMainWindow>
#include <QTimer>
#include <string>
#include <QMouseEvent>
#include <vector>
#include "../Players/Player.h"
#include "../Players/RegisteredPlayer.h"
#include "../Database.h"
#include "../Definitions.h"

	class QPushButton;
	class QTableWidget;
	class QTableWidget;
	class QStringList;
	class KeyEvent;
	class QPushButton;
	class QPixmap;
	class QPalette;
	class QImage;

	class LeaderBoardQT : public QDialog
	{
		Q_OBJECT
	public:
	/*
			LeaderBoardQT(QWidget *parent = 0);
			constructor that sets up all buttons and style sheets

	*/
		LeaderBoardQT(QWidget *parent = 0);
		signals:
	/*
		void newWindowFunction(int &i);
		signal that gets emitted and tells the main QT window what menu it should show
	*/
		void newWindowFunction(int &i);


		public slots:
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

	protected:
	/*
		void paintEvent(QPaintEvent *PE);
		paint event used to paint stuff to the window

	*/
		void paintEvent(QPaintEvent *PE);


	private:

	/*

	*/
		QTableWidget* gradeTable;
		QStringList m_TableHeader;
		QPushButton *exitt, *Main;
		private slots:



	};

#endif