#include "ChessBoard.h"
#include <iostream>

ChessBoard::ChessBoard() 
{
      CBoard = new Board;
      setUpChessBoard();

}
ChessBoard::~ChessBoard()
{


}

void ChessBoard::setUpChessBoard()
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

bool ChessBoard::undo(string str)
{
   
   CBoard->MoveHistory();
   return true;
   
}

vector<Piece*> ChessBoard::getDeadBoard(){
   return deadHistory;
}

void ChessBoard::setDeadBoard(Piece* p){
   deadHistory.push_back(p);

}

Piece* ChessBoard::getPiece(int row, int col){
   
   Piece* returnPiece = CBoard->getPiece(row,col);
   return returnPiece;
}

Piece* ChessBoard::popDeadBoard(){
   if(!deadHistory.empty())
   {
      Piece* returnPiece = deadHistory[deadHistory.size()-1];
      deadHistory.pop_back();
      return returnPiece;
   }   
   else
   {
      return nullptr;
   }
}

int ChessBoard::movePiece(int ix,int iy, int dx, int dy){
   Piece* Movepiece = CBoard->getPiece(ix,iy);
   int colourOfPiece = Movepiece->getColor();
   int checker = CBoard->movePiece(ix,iy,dx,dy);
   if (checker == 4)
   {
      CBoard->setPiece(dx,dy,new QueenPiece(colourOfPiece));
      CBoard->setNull(ix,iy);
      return 1;
   }
   else if (checker == 5)
   {
      CBoard->setPiece(dx,dy,Movepiece);
      CBoard->setNull(ix,iy);
      return 5;
   }
   else if (checker == 6)
   {
      CBoard->setPiece(dx,dy,Movepiece);
      if (dy == iy+2)
      {
         CBoard->setPiece(dx,dy-1,new RookPiece(colourOfPiece));
         CBoard->setNull(ix,dy+1);
         CBoard->setNull(ix,iy);
         colorMove++;
      }
      else 
      {
         CBoard->setPiece(dx,dy-1,new RookPiece(colourOfPiece));
         CBoard->setNull(ix,dy-2);
         CBoard->setNull(ix,iy);
         colorMove++;
      }
     
      return 1;
   }
   else if (checker == 1)
   {
      CBoard->setPiece(dx,dy,Movepiece);
    
      CBoard->setNull(ix,iy);  
      return 1;    
   }
   else return checker;
   
}

vector<string> ChessBoard::getGameHistory()
{
   vector<string> r = CBoard->getBoardHistory();
   std::cout <<"ChessBoard  " << r.size() << std::endl;
   return r;
}