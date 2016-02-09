#include "PauseMenu"

PauseMenu::PauseMenu(QWidget *parent)
{

	exitt = new QPushButton("exit");
	save  = new QPushButton("save");
	main = new QPushButton("Main Menu");

	QGridLayout *layout = new QGridLayout;
   layout -> addWidget(exitt,0,0,1,1);
   layout -> addWidget(save,0,1,1,1);
   layout -> addWidget(main,0,2,1,1);
   setLayout(layout);

   connect(exitt, SIGNAL(clicked()), this, SLOT(close()));


}