#include "BishopMove.h"


BishopMove::BishopMove()
{

   
}
int BishopMove::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
	PieceInWay r;
  
   for(int i = 0; i < 8; i++)
   {	// checks if the move that is being made is legal for a bishop to make
      if((ix+i == dx && iy+i == dy) || (ix-i == dx && iy+i == dy) || (ix-i == dx && iy-i == dy) || (ix+i == dx && iy-i == dy))
	 //if the move made is one that a bishop can 
	 return r.validMove(b,ix,iy,dx,dy);
   }
   //returns 0 which means that the move made was not a valid move.
   return 0;

}
