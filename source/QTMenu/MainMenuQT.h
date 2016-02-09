#ifndef MainMenuQT_H
#define MainMenuQT_H

#include <QMainWindow>
#include <QtGui>
#include <vector>
#include "PauseMenuQT.h"

class KeyEvent;
class QLabel;
class QComboBox;
class QPushButton;
class QTableWidget;
class QStringList;
class QTimer;
class QTime;
class QDate;

class MainMenuQT: public QMainWindow
{
  Q_OBJECT
  public:

    MainMenuQT();
    void keyPressEvent(QKeyEvent *e);
  private slots:

    

  private:
  	PauseMenuQT *pMenu;
    



     
};

#endif