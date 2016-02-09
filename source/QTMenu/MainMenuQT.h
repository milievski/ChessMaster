#ifndef MainMenuQT_H
#define MainMenuQT_H

#include <QMainWindow>
#include <QtGui>
#include <vector>


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
    
  private slots:
  void updateTime();


  private:

    //Time Progress Bars
    QProgressBar *hourBar;
    QProgressBar *minuteBar;
    QProgressBar *secondBar;

    //Date Progress Bars
    QProgressBar *dayBar;
    QProgressBar *monthBar;
    
    //Alarm Button
    QPushButton *alarmOne;
    QPushButton *alarmTwo;
    QPushButton *alarmThree;
    QPushButton *alarmFour;

    //Other Buttons
    QPushButton *nightDayB;
    QPushButton *yearB;
    QPushButton *quitB;

    //Labels
    QLabel *hourL;
    QLabel *minuteL;
    QLabel *secondL;
    QLabel *timeOfDayL;
    QLabel *dayL;
    QLabel *monthL;
    QLabel *yearL;

    //Time and Timer
    QTimer *updateT;



     
};

#endif