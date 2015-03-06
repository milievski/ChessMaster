#include "PawnCapture.h"

PawnCapture::PawnCapture(){

   
}
int PawnCapture::validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy){
   Promotion r;
   //checks if the there is an enemy piece where the pawn is attempting to chapture a piece
   if (b[dx][dy]->getType() != "Empty")
  	 if(b[ix][iy]->getColor() != b[dx][dy]->getColor())
   		return r.validMove(b, ix, iy, dx, dy);
   
	//return 0 if its not vaild
	return 0;

}   	