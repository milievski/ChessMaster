#include "KingPiece.h"

KingPiece::KingPiece(int c) : color{c}, Type{"King"}
{

}
int KingPiece::getColor() const
{
   return color;
}
void KingPiece::setColor(int colorOfPiece)
{
   color = colorOfPiece;

}
string KingPiece::getType() const
{
   return Type;
   
}

int KingPiece::validMove(vector< vector < Piece* > > gameBoard, int ix, int iy, int dx, int dy)
{
   KingMove r;
   return r.validMove (gameBoard,ix,iy,dx,dy);


}
