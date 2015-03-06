#include "ConsecutiveMove.h"

ConsecutiveMove::ConsecutiveMove()
{



}
int ConsecutiveMove::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
	NotEnoughPieces r;
	//checks if the move that was made is the 50th move whihc would result in a stale mate
	if((colorMove == 50)||(colorMove == 151))
		//returns a 2 which stale mate 
		return 2;
	//checks if the piece that is being moved is a pawn which will just reset the conter
	else if (b[ix][iy]->getType() == "Pawn")
	{
		//if it was an odd value this means that it was an odd move the counter is set to 101
		if (colorMove%2 == 1)
			colorMove=101;
		//if it was an odd value this means that it was an even move the counter is set to 0
		else if(colorMove%2 == 0)
			colorMove=0;
	}
	//if everything is ok then the rules is moved up the chain of command to the vaild rule of not eought Piece.
	return r.validMove(b, ix, iy, dx, dy);

}