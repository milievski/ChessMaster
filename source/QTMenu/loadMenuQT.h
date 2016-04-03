/*
	Authors: Michael Wilson, Marko Ilievski
	class: Human Computer Interaction
	file: 
	prof: Wendy Osborn
*/

#ifndef LOADMENUQT_H
#define LOADMENUQT_H

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
#include "../ChessBoard.h"

class QPushButton;
class QTableWidget;
class QTableWidget;
class QStringList;
class KeyEvent;
class QPushButton;
class QPixmap;
class QPalette;
class QImage;

class loadMenuQT : public QDialog
{
	Q_OBJECT
public:
	/*
		loadMenuQT(QWidget *parent = 0);
		constructor for load menu
		sets up style sheets and buttons
	*/
	loadMenuQT(QWidget *parent = 0);
	/*
		int CoordinateReturn(char co);
		function that returns the int value of the char co
	*/	
	int CoordinateReturn(char co);
	/*
		ChessBoard *getBoard(){return map;};
		returns the board loaded from the current load menu
	*/	
	ChessBoard *getBoard(){return map;};

signals:
	/*
		void newWindowFunction(int &i);
		emits a signal telling the main window what window should be opened next
	*/	
	void newWindowFunction(int &i);


public slots:
	/*
		void getDoubleClicked(int x, int y);
		slot that is triggered when the table gets double clicked
	*/	
	void getDoubleClicked(int x, int y);
	/*
		void Replayer(QString name);
		replayer is a helper function that replayes a old game to set up a new board
	*/	
	void Replayer(QString name);
	/*
		void mainMenu();
		closes current window and tells the main window to open the main menu
	*/	
	void mainMenu();
	/*
		void CloseWin();
		this will tell the main window that the program needs to close
	*/	
	void CloseWin();

protected:
	/*
		void paintEvent(QPaintEvent *PE);
		this paints stuff to the background of the window
		used to paint logos
	*/	
	void paintEvent(QPaintEvent *PE);


private:
	ChessBoard *map;
	QTableWidget* gradeTable;
    QStringList m_TableHeader;
    QPushButton *exitt, *Main;
	private slots:
};

#endif