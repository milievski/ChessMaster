#include "PawnMove.h"



PawnMove::PawnMove(){
  
   
}

int PawnMove::validMove(vector< vector < Piece* > > &b,int ix, int iy, int dx, int dy){
   
   PawnCapture r;
   Promotion p;
   //White
   
   //checks all possible move that a white pawned can make
   if(b[ix][iy]->getColor() == 0)
   {
    //check if the white pawn is taking a piece
      if((ix+1 == dx && iy+1 == dy)||(ix+1 == dx && iy-1 == dy))
      {
         return r.validMove(b, ix, iy, dx, dy);
      }
      //check if pawn is moving forward
      else if(ix+1 == dx && iy == dy)
      { 
         if(b[dx][dy]->getType() == "Empty")
         {
	        return p.validMove(b, ix, iy, dx, dy);
         }
      }
      //check if it can the white pawn can move two spaces
      else if(ix+2 == dx && iy == dy)
      {
     	   if(ix == 1)
	     {
            if(b[dx][dy]->getType() == "Empty")
         {
             if(b[ix+1][iy]->getType() == "Empty")
	        return p.validMove(b, ix, iy, dx, dy);
        }
	     }
      }
   }
   //Black
   //checks all possible move that a black pawned can make
   if(b[ix][iy]->getColor() == 1)
   {
    //check if the black pawn is taking a piece
   if((ix-1 == dx && iy-1 == dy)||(ix-1 == dx && iy+1 == dy))
   {
      return r.validMove(b, ix, iy, dx, dy);
   }
   //check if pawn is moving forward
   else if(ix-1 == dx && iy == dy)
   {
      if(b[dx][dy]->getType() == "Empty")
      {
	 return p.validMove(b, ix, iy, dx, dy);
      }
   }
   //check if it can the black pawn can move two spaces
   else if(ix-2 == dx && iy == dy)
   {
      
	 if(ix == 6)
	 {
	    if(b[dx][dy]->getType() == "Empty")
         {
             if(b[ix-1][iy]->getType() == "Empty")
           return p.validMove(b, ix, iy, dx, dy);
        }
	 }
      }
   }
   
   
   //returns 0 if the value is not valid
   return 0;


}
