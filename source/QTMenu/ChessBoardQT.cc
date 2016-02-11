#include "ChessBoardQT.h"

ChessBoardQT::ChessBoardQT(QWidget *parent) : QDialog(parent)
{

	

}
void ChessBoardQT::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Escape){
    	emit newWindowFunction(1);
    	//connect(pauseMenu, SIGNAL(closeWin()), this, SLOT(close()));
    	//pauseMenu->show();
    	
    }
}