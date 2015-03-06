#include "FriendlyPiece.h"
FriendlyPiece::FriendlyPiece()
{



}
   
int FriendlyPiece::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
	CheckTurn r;
	//checks if the space you are trying to move into is an Empty space if not checks the color to see it if it the same as the piece you are trying to move if it is an invalid move
	if (b[dx][dy]->getType() != "Empty")
		if( b[dx][dy]->getColor() == b[ix][iy]->getColor() )
			return 0;
	//if the move is valid it is move up the chain of command	
	return r.validMove(b,ix,iy,dx,dy);
}