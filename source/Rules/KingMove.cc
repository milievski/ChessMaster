#include "KingMove.h"

KingMove::KingMove()
{



}

int KingMove::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
	

	PieceInWay r;
	CastlingMove s;
	//Checks all the valid moves that the king could make 
	if((ix+1 == dx && iy == dy) || (ix == dx && iy+1 == dy) || (ix-1 == dx && iy == dy) || (ix == dx && iy-1 == dy) || (ix+1 == dx && iy+1 == dy) || (ix-1 == dx && iy+1 == dy) || (ix-1 == dx && iy-1 == dy) || (ix+1 == dx && iy-1 == dy))
	 {
	 	return r.validMove(b,ix,iy,dx,dy);
	 }
	else if ((ix == dx && iy+2 == dy)||(ix == dx && iy-2 == dy))
	{
		
		return s.validMove(b,ix,iy,dx,dy);
	}
   //returns 0 if the move that was not done was not a valid move.
   return 0;
   
   

}