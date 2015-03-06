#include "BishopPiece.h"
#include <iostream>
using namespace std;
BishopPiece::BishopPiece(int c) : color{c}, Type{"Bishop"}
{

}
int BishopPiece::getColor() const
{
   return color;
}
void BishopPiece::setColor(int colorOfPiece)
{
   color = colorOfPiece;

}
string BishopPiece::getType() const
{
   return Type;
   
}

int BishopPiece::validMove(vector< vector < Piece* > > gameBoard, int ix, int iy, int dx, int dy)
{
   BishopMove r;
   return r.validMove(gameBoard,ix,iy,dx,dy);

}
