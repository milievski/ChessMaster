#include "Promotion.h"
Promotion::Promotion()
{


   
}
int Promotion::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy)
{
   //Checks if promotion is possible retunr 4 which is promotion
   PieceInWay r;
   //White
   if(b[ix][iy]->getColor() == 0)
   {
      //checks if the final location is at the final square
      if(dx == 7)
          return 4;
   }
   //Black
   else if(b[ix][iy]->getColor() == 1)
   {
      //checks if the final location is at the final square return 4 if this is true
      if(dx == 0)
	 return 4;
   }
   
   return r.validMove(b,ix,iy,dx,dy);
}
