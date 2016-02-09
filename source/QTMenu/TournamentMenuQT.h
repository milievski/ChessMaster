#ifndef TOURNAMENTMENUQT_H
#define TOURNAMENTMENUQT_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>


  class QPushButton;
class QTableWidget;

class TournamentMenuQT : public QDialog
{
	Q_OBJECT
public:
	TournamentMenuQT(QWidget *parent = 0);
signals:
	

//public slot:


private:
	QPushButton *exitt, *save, *Main;

private slots:
	


};

#endif