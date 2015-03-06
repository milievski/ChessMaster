#include "QueenPiece.h"

QueenPiece::QueenPiece(int c) : color{c}, Type{"Queen"}
{

}
int QueenPiece::getColor() const
{
   return color;
}
void QueenPiece::setColor(int colorOfPiece)
{
   color = colorOfPiece;

}
string QueenPiece::getType() const
{
   return Type;
   
}

int QueenPiece::validMove(vector< vector < Piece* > > gameBoard, int ix, int iy, int dx, int dy)
{
   QueenMove r;
   return r.validMove(gameBoard,ix,iy,dx,dy);

return 1;
}
