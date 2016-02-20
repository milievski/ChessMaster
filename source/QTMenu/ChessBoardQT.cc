#include "ChessBoardQT.h"

ChessBoardQT::ChessBoardQT(QWidget *parent) : QDialog(parent)
{
   picked = false;
   QRect rec = QApplication::desktop()->screenGeometry();
   screenHeight = rec.height();
   screenWidth = rec.width();

	const int size = 80;
   BoardSize = (screenHeight-100)/8;
   selecterBox = QImage("QTMenu/Art/selecterBox.png");
   selecterBox = selecterBox.scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);
	SpriteSheet = new QImage("QTMenu/Art/PieceSpriteSheet.png");
	for(int x = 0; x < 6;x ++) // filling the pice sprites up with images
	{
		BlackSprites.push_back(QImage());
		WhiteSprites.push_back(QImage());
	}
	//king
	BlackSprites[0] = SpriteSheet->copy(4*size,0*size ,size ,size );
	WhiteSprites[0] = SpriteSheet->copy(1*size,0*size ,size ,size );
	//Queen
	BlackSprites[1] = SpriteSheet->copy(4*size,1*size ,size ,size );
	WhiteSprites[1] = SpriteSheet->copy(1*size,1*size ,size ,size );
	//Bishop
	BlackSprites[2] = SpriteSheet->copy(5*size,1*size ,size ,size );
	WhiteSprites[2] = SpriteSheet->copy(2*size,1*size ,size ,size );
	//Knight
	BlackSprites[3] = SpriteSheet->copy(3*size,1*size ,size ,size );
	WhiteSprites[3] = SpriteSheet->copy(0*size,1*size ,size ,size );
	//Rook
	BlackSprites[4] = SpriteSheet->copy(3*size,0*size ,size ,size );
	WhiteSprites[4] = SpriteSheet->copy(0*size,0*size ,size ,size );
	//Pawn
	BlackSprites[5] = SpriteSheet->copy(5*size,0*size ,size ,size );
	WhiteSprites[5] = SpriteSheet->copy(2*size,0*size ,size ,size );

	BoardPosX = 50;
	BoardPosY = 50;
	CBoard = new ChessBoard();


	

}
void ChessBoardQT::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Escape){
    	int temp = 1;
    	emit newWindowFunction(temp);
    	update();
    	
    }
}

void ChessBoardQT::paintEvent(QPaintEvent *PE)
{
   QPainter paint(this); 
   QImage BoardImage("QTMenu/Art/chessBoard.jpg");


   BoardImage = BoardImage.scaled(screenHeight-100, screenHeight-100, Qt::KeepAspectRatio);
   paint.drawImage(BoardPosX,BoardPosY, BoardImage);

   if(picked)
   {
      paint.drawImage(50+(pickedx * BoardSize) - BoardSize, 50+(pickedy * BoardSize)-BoardSize, selecterBox);
   }


   int tempCheck = 0, colour;
   Piece *tempPiece;
   string type;
   for(int y =0; y < 8; y++)
   {
   	for(int x = 0; x < 8; x++)
   	{
   		
   		tempPiece = CBoard->getPiece(x,y);
   		type = tempPiece->getType();
   		colour = tempPiece->getColor();
   		
   		if(colour == 1)//black
   		{
   			
   			if (type == "Queen")
   				paint.drawImage(BoardPosX + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[0]);
   			if (type == "King")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[1]);
   			if (type == "Bishop")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[2]);
   			if (type == "Knight")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[3]);
   			if (type == "Rook")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[4]);
   			if (type == "Pawn")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[5]);

   		}
   		else // white
   		{
    		if (type == "Queen")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[0]);
   			if (type == "King")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[1]);
   			if (type == "Bishop")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[2]);
   			if (type == "Knight")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[3]);
   			if (type == "Rook")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[4]);
   			if (type == "Pawn")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[5]);
   		}
   		

   	}
   
   }
   


}

void ChessBoardQT::mouseMoveEvent(QMouseEvent *e)
{
   if(e->buttons() == Qt::LeftButton)
   {
      //std::cerr << e->x() << " , " << e->y() << std::endl;
   }  
}
void ChessBoardQT::mousePressEvent(QMouseEvent *e)
{
   if(e->buttons() == Qt::LeftButton)
   {
      hitBoxDetect(e->x(), e->y());
      //std::cerr << e->x() << " , " << e->y() << std::endl;
      
   }  
}



void ChessBoardQT::hitBoxDetect(int x, int y)
{
   int hit = BoardSize; // hit is the distance between each piece on the board
   x += 50; // 50 is the offset of how far the board is from the top left corner
   y += 50; // 50 is the offset of how far the board is from the top left corner

   int boardx = x / hit;
   int boardy = y / hit;
   if(!picked)
   {
      picked = false;
      if(boardx > 0 && boardy >0 && boardx < 9 && boardy < 9)
      {
         std::cerr << "\n\n\n" << CBoard->getPiece(boardy-1,boardx-1)->getType();
         if("Empty" != CBoard->getPiece(boardy-1,boardx-1)->getType())
         {
            pickedx = boardx;
            pickedy = boardy;
            update();
            picked = true;
         }
      }

   }
   else
   {
      if(boardx > 0 && boardy >0 && boardx < 9 && boardy < 9)
      {
         CBoard->movePiece(pickedy-1, pickedx-1, boardy-1, boardx-1);
      }
      update();
      picked = !picked;
   }
   
   



}