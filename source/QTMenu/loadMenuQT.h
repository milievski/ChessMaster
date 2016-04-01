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
	loadMenuQT(QWidget *parent = 0);
	  int CoordinateReturn(char co);
	  ChessBoard *getBoard(){return map;};

signals:
	void newWindowFunction(int &i);


public slots:
void getDoubleClicked(int x, int y);
void Replayer(QString name);
void mainMenu();
void CloseWin();

protected:
	void paintEvent(QPaintEvent *PE);


private:
	ChessBoard *map;
	QTableWidget* gradeTable;
    QStringList m_TableHeader;
    QPushButton *exitt, *Main;
	private slots:
};

#endif