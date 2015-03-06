#include "PieceInWay.h"
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
PieceInWay::PieceInWay()
{



}

int PieceInWay::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
	//checks if the moves that is made is passing though another piece 
	if ((ix != dx)&&(iy!=dy))
	{
		if ((dx>ix)&&(dy>iy))
		{
			//checks diagonals 
			for(int i=1;i<min((dy-iy),(dx-ix));i++)
			{
				if(b[ix+i][iy+i]->getType() != "Empty")
					return 0;
			}
		}
		if ((dx>ix)&&(dy<iy))
		{
			//checks diagonals for non empty sqaures 
			for(int i=1;i<min((iy-dy),(dx-ix));i++)
			{
				if(b[ix+i][iy-i]->getType() != "Empty")
					return 0;
			}
		}
		if ((dx<ix)&&(dy>iy))
		{
			//checks diagonals for non empty sqaures 
			for(int i=1;i<min((dy-iy),(ix-dx));i++)
			{
				if(b[ix-i][iy+i]->getType() != "Empty")
					return 0;
			}
		}
		if ((dx<ix)&&(dy<iy))
		{
			//checks diagonals for non empty sqaures 
			for(int i=1;i<min((iy-dy),(ix-dx));i++)
			{
				if(b[ix-i][iy-i]->getType() != "Empty")
					return 0;
			}
		}
	}
	else if (ix == dx)
	{
		//checks horizontal and vertical directions
		if(dy > iy)
		{
			for(int i = 1;i < dy-iy;i++)
			{
				if(b[ix][iy+i]->getType() != "Empty")
					return 0;
			}

		}
		if(dy < iy)
		{
			for(int i = 1;i < iy-dy;i++)
			{
				if(b[ix][iy-i]->getType() != "Empty")
					return 0;
			}

		}

	}
	//checks horizontal and vertical directions
	else if (iy == dy)
	{
		if(dx > ix)
		{
			for(int i = 1;i < dx-ix;i++)
			{
				if(b[ix+i][iy]->getType() != "Empty")
					return 0;
			}

		}
		if(dx < ix)
		{
			for(int i = 1;i < ix-dx;i++)
			{
				if(b[ix-i][iy]->getType() != "Empty")
					return 0;
			}

		}
	}
	
	FriendlyPiece r;
	return r.validMove(b,ix,iy,dx,dy);

}
