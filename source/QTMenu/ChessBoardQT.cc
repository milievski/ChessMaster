#include "ChessBoardQT.h"

ChessBoardQT::ChessBoardQT(QWidget *parent) : QDialog(parent)
{
	const int size = 80;
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
	CBoard = new Board();
	setUpChessBoard();

	

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
   QImage BoardImage("QTMenu/Art/ChessBoardArt.jpg");
   paint.drawImage(BoardPosX-50,BoardPosY-50, BoardImage);
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
   		
   		if(colour == 0)//black
   		{
   			
   			if (type == "King")
   				paint.drawImage(BoardPosX + (y * 75), BoardPosX + (x*75), BlackSprites[0]);
   			if (type == "Queen")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), BlackSprites[1]);
   			if (type == "Bishop")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), BlackSprites[2]);
   			if (type == "Knight")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), BlackSprites[3]);
   			if (type == "Rook")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), BlackSprites[4]);
   			if (type == "Pawn")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), BlackSprites[5]);

   		}
   		else // white
   		{
    		if (type == "King")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), WhiteSprites[0]);
   			if (type == "Queen")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), WhiteSprites[1]);
   			if (type == "Bishop")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), WhiteSprites[2]);
   			if (type == "Knight")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), WhiteSprites[3]);
   			if (type == "Rook")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), WhiteSprites[4]);
   			if (type == "Pawn")
   				paint.drawImage(BoardPosY + (y * 75), BoardPosX + (x*75), WhiteSprites[5]);
   		}
   		

   	}
   
   }
   


}

void ChessBoardQT::setUpChessBoard()
{
   //set all pawns
   for(int i = 0; i < 8;i++)
   {
      CBoard->setPiece(1,i,new PawnPiece(0));
      CBoard->setPiece(6,i,new PawnPiece(1));
   }

   //setting up the four Rooks
   CBoard->setPiece(0,0, new RookPiece(0));
   CBoard->setPiece(0,7, new RookPiece(0));
   CBoard->setPiece(7,0, new RookPiece(1));
   CBoard->setPiece(7,7, new RookPiece(1));

   //setting up four Knights
   CBoard->setPiece(0,1, new KnightPiece(0));
   CBoard->setPiece(0,6, new KnightPiece(0));
   CBoard->setPiece(7,1, new KnightPiece(1));
   CBoard->setPiece(7,6, new KnightPiece(1));

   //setting up for bishop
   CBoard->setPiece(0,2, new BishopPiece(0));
   CBoard->setPiece(0,5, new BishopPiece(0));
   CBoard->setPiece(7,2, new BishopPiece(1));
   CBoard->setPiece(7,5, new BishopPiece(1));

   //set up queen
   CBoard->setPiece(0,3, new QueenPiece(0));
   CBoard->setPiece(7,3, new QueenPiece(1));
   
   //set up king
   CBoard->setPiece(0,4, new KingPiece(0));
   CBoard->setPiece(7,4, new KingPiece(1));
}