#include "MyKingInCheck.h"
#include <iostream>
MyKingInCheck::MyKingInCheck()
{



}

int  MyKingInCheck::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
	
	
	//std:: cout << "Here" << std::endl;
	int kingx, kingy;

	//this finds the location of the enemy king 
	for (int x=0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
			if ((b[x][y]->getType() == "King") && (b[x][y]->getColor() == b[ix][iy]->getColor()))
			{
				kingx = x;
				kingy = y;

			}
	}

	//Checking both vertical and horrizontal possitions if there is a queen or rook that could attack the king
	for(int i = 0; i < 7-kingx; i++)
   {
   	std:: cout << "HEre" << 7-kingx << std::endl;
      if ((b[kingx+i][kingy]->getType() == "Rook") || (b[kingx+i][kingy]->getType() == "Queen"))
      	    return 5;

      if (b[kingx+i][kingy]->getType() != "Empty")
   	  		break;
   }

   //Checking both vertical and horrizontal possitions if there is a queen or rook that could attack the king
   for(int i = 0; i < kingx; i++)
   {
   		std:: cout << "HEre x 2 " << kingx << std::endl;
   		if ((b[kingx-i][kingy]->getType() == "Rook") || (b[kingx-i][kingy]->getType() == "Queen"))
      	    return 5;

      	if (b[kingx-i][kingy]->getType() != "Empty")
   	  		break;
   	}

//Checking both vertical and horrizontal possitions if there is a queen or rook that could attack the king
   for(int i = 0; i < 7-kingy; i++)
   {
   		if ((b[kingx][kingy+i]->getType() == "Rook") || (b[kingx+i][kingy]->getType() == "Queen"))
      	    return 5;

    	if (b[kingx][kingy+i]->getType() != "Empty")
   	  		break;
   }

   //Checking both vertical and horrizontal possitions if there is a queen or rook that could attack the king
   for(int i = 0; i < kingy; i++)
   {
		if ((b[kingx][kingy-i]->getType() == "Rook") || (b[kingx+i][kingy]->getType() == "Queen"))
      	    return 5;

    	if (b[kingx][kingy-i]->getType() != "Empty")
   	  		break;
   }


	/*//Checking both all other possible attack roots ie degnoal 
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
		
*/
			
	 return 1;
}