#ifndef LEADERBOARDQT_H
#define LEADERBOARDQT_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>


  class QPushButton;
class QTableWidget;

class LeaderBoardQT : public QDialog
{
	Q_OBJECT
public:
	LeaderBoardQT(QWidget *parent = 0);
signals:


//public slot:


private:
	QPushButton *exitt, *save, *Main;

private slots:



};

#endif