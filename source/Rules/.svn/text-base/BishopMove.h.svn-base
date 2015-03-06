//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
///
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef BISHOPMOVE_H
#define BISHOPMOVE_H
#include <vector>
using std::vector;

#include "Rule.h"
#include "PieceInWay.h"

class BishopMove : virtual Rule
{
  public:
   
//*****************************************************************************
///  BishopMove creates a BishopMove object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   BishopMove();
   
//*****************************************************************************
/// validMove checks if the move made by the user is a valid move for bishop to make a perfect angle(ex. x+1,y+1). if valid calls pieceinway. if invalid return 0.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);

};

#endif
