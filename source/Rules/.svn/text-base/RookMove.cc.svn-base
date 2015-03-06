#include "RookMove.h"

RookMove::RookMove()
{



}
int RookMove::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
   PieceInWay r;
  //checks all possible move that could be made for a rook
   for(int i = 0; i < 8; i++)
   {
      if((ix+i == dx && iy == dy) || (ix == dx && iy+i == dy) || (ix-i == dx && iy == dy) || (ix == dx && iy-i == dy))
	 return r.validMove(b,ix,iy,dx,dy);
   }
   
   
   return 0;

}
