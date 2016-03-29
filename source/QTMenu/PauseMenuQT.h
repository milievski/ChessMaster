#ifndef PAUSEMENUQT_H
#define PAUSEMENUQT_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>


  class QPushButton;
class QTableWidget;
class QFont;

class PauseMenuQT : public QDialog
{
	Q_OBJECT
public:
	PauseMenuQT(QWidget *parent = 0);
	void paintEvent(QPaintEvent *PE);
signals:
	void closeWin(int &i);

//public slot:


private:
	QPushButton *exitt, *save, *Main, *canncell;

private slots:
	void closeWinSlot();
	void mainMenuSlot();
	void canncellSlot();

};

#endif