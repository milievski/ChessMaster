 #include "CastlingMove.h"
 CastlingMove::CastlingMove()
 {



 }
 int CastlingMove::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
 {
 	//checks if the king is trying to castle to the left hand side
 	if (iy+2 == dy)
 	{
 		//checks if the spaces between the king and the rook are all empty
 		if ((b[ix][iy+1]->getType() == "Empty") && (b[ix][iy+2]->getType() == "Empty"))
 		{
 			//returns 6 which means that there was a castle
 			return 6;
 		}
 	}

 	//checks if the king is trying to castle to the right hand side
 	else if (iy-2 == dy)
 	{
 		//checks if the spaces between the king and the rook are all empty
 		if ((b[ix][iy-1]->getType() == "Empty") && (b[ix][iy-2]->getType() == "Empty") && (b[ix][iy-3]->getType() == "Empty"))
 		{
 			//returns 6 which means that there was a castle
 			return 6;
 		}
 	}
 	//if there is any piece between the rook and the king a zero is returned which means that the move that was made was not a valid move
 	return 0;
 }
