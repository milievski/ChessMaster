#include "NotEnoughPieces.h"

NotEnoughPieces::NotEnoughPieces()
{



}

int  NotEnoughPieces::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
	//did not implement thus all move will be valid
	MyKingInCheck r;

	int whitePieces = 0;
	int blackPieces = 0;

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (b[i][j]->getType() != "Empty")
				if (b[i][j]->getColor() == 0)
					whitePieces++;
				else
					blackPieces++;
		}

	}
	if (whitePieces == 1 && blackPieces == 1){
		return 2;
	}
	else
	 	return r.validMove(b,ix,iy,dx,dy);
}