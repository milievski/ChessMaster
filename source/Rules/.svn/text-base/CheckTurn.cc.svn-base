#include "CheckTurn.h"
#include "../Definitions.h"

CheckTurn::CheckTurn()
{



}
   
//*****************************************************************************
/// validMove checks if the pieces left alive are the bishop and king or the knight and king it will return 2 else return 1.
//
/// \return an int 
//*****************************************************************************
int CheckTurn::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
	KingInCheck r;
	
	if( (b[ix][iy]->getColor() == 0) && (colorMove%2 == 0) )
	{	
		colorMove++;
		//this is if above is ture
		return r.validMove(b,ix,iy,dx,dy);
		

		
	}
	else if( (b[ix][iy]->getColor() == 1) && (colorMove%2 == 1) )
	{
		
		colorMove++;
		//this is if above is ture
		return r.validMove(b,ix,iy,dx,dy);

	}
	
	return 0;
	

}
