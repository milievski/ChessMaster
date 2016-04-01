#include "loadMenuQT.h"
#include <QtGui>

loadMenuQT::loadMenuQT(QWidget *parent) : QDialog(parent)
{
	QFont font("League Gothic",22, true );
  font.setBold(true);
  font.setItalic(true);
  QFont font2("League Gothic",18, true );
  font2.setBold(false);
  font2.setItalic(true);

  Database data;
  vector<string> names;

  names = data.getSaveList();


  unsigned int curs = 0, loopProtect = 0;
  unsigned int SIZE_LEADER = names.size();
  if(names.size() == 0)
    close();

  gradeTable = new QTableWidget(this);
  connect(gradeTable, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(getDoubleClicked(int,int)));
  gradeTable->setRowCount(SIZE_LEADER);
  gradeTable->setColumnCount(1);
  m_TableHeader<<"saved games";

  gradeTable->setHorizontalHeaderLabels(m_TableHeader);
   //gradeTable->verticalHeader()->setVisible(fal);
  gradeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
  gradeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
  gradeTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
   //gradeTable->setShowGrid(false);
  gradeTable->setStyleSheet("background-color:white");
  gradeTable->setFont(font2);
  gradeTable->horizontalHeader()->setFont(font2);
  for (unsigned int x = loopProtect; x < SIZE_LEADER;x++)
  {

    QTableWidgetItem *PlayerName = new QTableWidgetItem;
    PlayerName->setTextAlignment(Qt::AlignHCenter);
    PlayerName->setText(QString::fromStdString(names[x]));
    gradeTable->setItem(x,0,PlayerName);

  }


  exitt = new QPushButton("Exit");
  connect(exitt, SIGNAL(clicked()), this, SLOT(CloseWin()));
  Main = new QPushButton("Main Menu");
  connect(Main, SIGNAL(clicked()), this, SLOT(mainMenu()));

  exitt->setMaximumHeight(60);
  Main->setMaximumHeight(60);

  exitt->setFont(font);
  Main->setFont(font);

  exitt->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");
  Main->setStyleSheet("border-image:url(QTMenu/Art/woodbackground.png);");

  QGridLayout *layout = new QGridLayout;
  layout-> setRowMinimumHeight(0,300);
  layout-> setColumnMinimumWidth(0,200);
  layout -> addWidget(gradeTable,1,1,1,2);
  layout -> addWidget(exitt,2,1,1,1);
  layout -> addWidget(Main,2,2,1,1);
  layout-> setColumnMinimumWidth(2,600);

  layout-> setColumnMinimumWidth(3,200);
  layout-> setRowMinimumHeight(2,80);
  layout -> addWidget(gradeTable,1,1,1,1);
  layout-> setRowMinimumHeight(4,80);
  setLayout(layout);



}
void loadMenuQT::paintEvent(QPaintEvent *PE)
{

  QImage logo("QTMenu/Art/ChessMasterLogo.png");
  QPainter paint(this); 
  paint.drawImage(375,100, logo);

}

void loadMenuQT::CloseWin()
{
  int temp = 3;
  emit newWindowFunction(temp);
}

void loadMenuQT::mainMenu()
{
  int temp = 7;
  emit newWindowFunction(temp);
}

void loadMenuQT::Replayer(QString name)
{

  Database data;
  std::vector<string> moves = data.loadGame(name.toStdString());

  map = new ChessBoard;
  int size= moves.size();
  int c[2] = {1,1}, current[2], destination[2], selected[2];



  for(int x = 0; x < size; x++)
  {
        //converts string from memory to coordinate changes.
    current[1] = CoordinateReturn(moves[x].at(0))-1;
    current[0] = (moves[x].at(1) - '0') ;
    destination[1] = CoordinateReturn(moves[x].at(3)-1);
    destination[0] = (moves[x].at(4) - '0') ;
        //moves the pieces with the corrdinate loaded from file
    map->movePiece(current[0], current[1], destination[0], destination[1]);
  }
      // updates the board to the map that was just loaded into status.
      //info->setBoard(map);

}
int loadMenuQT::CoordinateReturn(char co)
{
  switch(co)
  {
    case 'a':
    return 1;
    case 'b':
    return 2;
    case 'c':
    return 3;
    case 'd':
    return 4;
    case 'e':
    return 5;
    case 'f':
    return 6;
    case 'g':
    return 7;
    case 'h':
    return 8;
    default:
    return 0;
  }
}

void loadMenuQT::getDoubleClicked(int x, int y)
{
  QTableWidgetItem *temp = gradeTable->item(x,y);
  QString ret = temp->text();
  Replayer(ret);
  std::cerr << x << " , " << y << " = " << ret.toStdString() << std::endl;
  int temper = 10;
  emit newWindowFunction(temper);
}