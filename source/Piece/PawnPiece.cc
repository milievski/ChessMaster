#include "PawnPiece.h"
extern int colorMine;
PawnPiece::PawnPiece(int c) : color{c}
{
   Type = "Pawn";
}
int PawnPiece::getColor() const
{
   return color;
}
void PawnPiece::setColor(int colorOfPiece)
{
   color = colorOfPiece;

}
string PawnPiece::getType() const
{
   return Type;
}

int PawnPiece::validMove(vector< vector < Piece* > > gameBoard, int ix, int iy, int dx, int dy)
{
   PawnMove r;
   return r.validMove(gameBoard,ix,iy,dx,dy);
   

}
