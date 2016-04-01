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
	LeaderBoardQT(QWidget *parent = 0);
signals:
	void newWindowFunction(int &i);


public slots:
void mainMenu();
void CloseWin();

protected:
	void paintEvent(QPaintEvent *PE);


private:

	QTableWidget* gradeTable;
    QStringList m_TableHeader;
    QPushButton *exitt, *Main;
private slots:



};

#endif