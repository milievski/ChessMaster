#include "NotEnoughPieces.h"

NotEnoughPieces::NotEnoughPieces()
{



}

int  NotEnoughPieces::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
	//did not implement thus all move will be valid
	MyKingInCheck r;
	 return r.validMove(b,ix,iy,dx,dy);
}