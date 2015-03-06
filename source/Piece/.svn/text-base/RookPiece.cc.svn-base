#include "RookPiece.h"

RookPiece::RookPiece(int c) : color{c}, Type{"Rook"}
{

}

int RookPiece::getColor() const
{
   return color;
}

void RookPiece::setColor(int colorOfPiece)
{
   color = colorOfPiece;

}

string RookPiece::getType() const
{
   return Type;
   
}

int RookPiece::validMove(vector< vector < Piece* > > gameBoard, int ix, int iy, int dx, int dy)
{
   RookMove r;
   return r.validMove(gameBoard,ix,iy,dx,dy);

}
