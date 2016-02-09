#ifndef ENDMENUQT_H
#define ENDMENUQT_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>


  class QPushButton;
class QTableWidget;

class EndMenuQT : public QDialog
{
	Q_OBJECT
public:
	EndMenuQT(QWidget *parent = 0);
signals:


//public slot:


private:
	QPushButton *exitt, *save, *Main;

private slots:



};

#endif