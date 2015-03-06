#include "KingInCheck.h"

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
KingInCheck::KingInCheck(){



}

int KingInCheck::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy){
	ConsecutiveMove r;
	
	///Checks if the king is still on the board if it is not this will result in an end of game
	if (CheckMate(b,dx,dy))
		{
			return 3;

		}
	
	int kingx, kingy;

	//this finds the location of the enemy king 
	for (int x=0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
			if ((b[x][y]->getType() == "King") && (b[x][y]->getColor() != b[ix][iy]->getColor()))
			{
				kingx = x;
				kingy = y;
			}
	}

	//checks if a pawn will be in a possition to check the king
	//there is two possiblity for this which are the if the color of the king is white then the pawns would be in foront and if black they pawn would be behind
	if (b[kingx][kingy]->getColor() == 0)
	{
		//checks if there is a black pawn that is attaking the white king at cordinats 1,1 or 1,-1 for the kings postition
		if((b[ix][iy]->getType() == "Pawn")&&((dx == kingx+1)&&(dy == kingy+1)) )
		{
			if (b[ix][iy]->getColor() == 1)
				//returns 5 which means that the king is in check
				return 5;
		}
		else if((b[ix][iy]->getType() == "Pawn")&&((dx == kingx+1)&&(dy == kingy-1)))
		{
			if (b[ix][iy]->getColor() == 1)
				//returns 5 which means that the king is in check
			return 5;
		}
		
	}
	//checks if a pawn will be in a possition to check the king
	//there is two possiblity for this which are the if the color of the king is white then the pawns would be in foront and if black they pawn would be behind
	else if (b[kingx][kingy]->getColor() == 1)
	{
		//checks if there is a white pawn that is attaking the black king at cordinats 1,1 or 1,-1 for the kings postition
		if((b[ix][iy]->getType() == "Pawn")&&((dx == kingx-1)&&(dy == kingy+1)))
		{
			if (b[ix][iy]->getColor() == 0)
				//returns 5 which means that the king is in check
			return 5;
		}
		else if((b[ix][iy]->getType() == "Pawn")&&((dx == kingx-1)&&(dy == kingy-1)) )
		{
			if (b[ix][iy]->getColor() == 0)
				//returns 5 which means that the king is in check
			return 5;
		}
	}

	//Knight
	if (b[ix][iy]->getType() == "Knight") 
	{
		//checks for all the ways that a knight can exits
		if((kingx+2 == dx)&&(kingy+1 == dy))
			//returns 5 which means that the king is in check
			return 5;
		if((kingx+1 == dx)&&(kingy+2 == dy))
			//returns 5 which means that the king is in check
			return 5;
		if((kingx-2 == dx)&&(kingy+1 == dy))
			//returns 5 which means that the king is in check
			return 5;
		if((kingx-1 == dx)&&(kingy+2 == dy))
			//returns 5 which means that the king is in check
			return 5;
		if((kingx+2 == dx)&&(kingy-1 == dy))
			//returns 5 which means that the king is in check
			return 5;
		if((kingx+1 == dx)&&(kingy-2 == dy))
			//returns 5 which means that the king is in check
			return 5;
		if((kingx-2 == dx)&&(kingy-1 == dy))
			//returns 5 which means that the king is in check
			return 5;
		if((kingx-1 == dx)&&(kingy-2 == dy))
			//returns 5 which means that the king is in check
			return 5;
	
	}

	//Checking both vertical and horrizontal possitions if there is a queen or rook that could attack the king
	for(int i = 1; i < 7-kingx; i++)
   {
   	  if (((b[ix][iy]->getType() == "Queen") || (b[ix][iy]->getType() == "Rook")) && ((kingx+i == dx)&& (kingy == dy)))
   	  		//returns 5 which means that the king is in check
   	  		return 5;
      
      if (b[kingx+i][kingy]->getType() != "Empty")
      	    break;
   }
   //Checking both vertical and horrizontal possitions if there is a queen or rook that could attack the king
   for(int i = 1; i < kingx; i++)
   {
   		if (((b[ix][iy]->getType() == "Queen") || (b[ix][iy]->getType() == "Rook")) && ((kingx-i == dx)&& (kingy == dy)))
   			//returns 5 which means that the king is in check
   	  		return 5;
   		
      
      if (b[kingx-i][kingy]->getType() != "Empty")
      	    break;
   }

  
//Checking both vertical and horrizontal possitions if there is a queen or rook that could attack the king
   for(int i = 1; i < 7-kingy; i++)
   {
   	if ((((b[ix][iy]->getType() == "Queen") || (b[ix][iy]->getType() == "Rook")) && ((kingx == dx)&& (kingy+i == dy))))
   	  		return 5;
      
      if (b[kingx][kingy+i]->getType() != "Empty")
      	    break;
   }
   //Checking both vertical and horrizontal possitions if there is a queen or rook that could attack the king
   for(int i = 1; i < kingy; i++)
   {
   	  if (((b[ix][iy]->getType() == "Queen") || (b[ix][iy]->getType() == "Rook")) && ((kingx == dx)&& (kingy-i == dy)))
   	  	//returns 5 which means that the king is in check
   	  		return 5;
      
      if (b[kingx][kingy-i]->getType() != "Empty")
      	    break;
   }


	//Checking both all other possible attack roots ie degnoal 
			for(int i=1;i<=min((7-kingy),(7-kingx));i++)
			{
				if(((b[ix][iy]->getType() == "Queen") || (b[ix][iy]->getType() == "Bishop")) && ((kingx+i == dx)&& (kingy+i == dy)))
					//returns 5 which means that the king is in check
					return 5;
				if(b[kingx+i][kingy+i]->getType() != "Empty")
					break;
			}
		
	//Checking both all other possible attack roots ie degnoal 
			for(int i=1;i<=min((kingy),(7-kingx));i++)
			{
				if(((b[ix][iy]->getType() == "Queen") || (b[ix][iy]->getType() == "Bishop")) && ((kingx+i == dx)&& (kingy-i == dy)))
					//returns 5 which means that the king is in check
					return 5;
				if(b[kingx+i][kingy-i]->getType() != "Empty")
					break;
			}
		
	//Checking both all other possible attack roots ie degnoal 
			for(int i=1;i<=min((7-kingy),(kingx));i++)
			{
				if(((b[ix][iy]->getType() == "Queen") || (b[ix][iy]->getType() == "Bishop")) && ((kingx-i == dx)&& (kingy+i == dy)))
					//returns 5 which means that the king is in check
					return 5;
				if(b[kingx-i][kingy+i]->getType() != "Empty")
					break;
			}
		
	//Checking both all other possible attack roots ie degnoal 
			for(int i=1;i<=min((kingy),(kingx));i++)
			{
				if(((b[ix][iy]->getType() == "Queen") || (b[ix][iy]->getType() == "Bishop")) && ((kingx-i == dx)&& (kingy-i == dy)))
					//returns 5 which means that the king is in check
					return 5;
				if(b[kingx-i][kingy-i]->getType() != "Empty")
					break;
			}
		

			
	 return r.validMove(b,ix,iy,dx,dy);
   

}

bool KingInCheck::CheckMate(vector< vector < Piece* > > &b,int ix, int iy){
	if ((b[ix][iy]->getType() == "King"))
		return true;

	else return false;

}