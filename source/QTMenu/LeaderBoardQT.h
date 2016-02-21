#ifndef LEADERBOARDQT_H
#define LEADERBOARDQT_H

#include <QWidget>
#include <QtGui>
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

class LeaderBoardQT : public QDialog
{
	Q_OBJECT
public:
	LeaderBoardQT(QWidget *parent = 0);
signals:


//public slot:
protected:
	void paintEvent(QPaintEvent *PE);


private:
	QPushButton *exitt, *save, *Main;
	QTableWidget* gradeTable;
    QStringList m_TableHeader;
private slots:



};

#endif