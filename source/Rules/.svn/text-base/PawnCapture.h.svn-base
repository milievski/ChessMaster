//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
///
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef PAWNCAPTURE_H
#define PAWNCAPTURE_H
#include <vector>
using std::vector;
#include "Rule.h"
#include "Promotion.h"

class PawnCapture : virtual Rule
{
  public:
   
//*****************************************************************************
///  PawnCapture creates a PawnCapture object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   PawnCapture();
   
//*****************************************************************************
/// validMove if the player is trying to move forward go to promotion class. if that is false, check if there is an valid attack for pawn, return 1 else return 0.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);
};

#endif
