//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
//
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef FRIENDLYPIECE_H
#define FRIENDLYPIECE_H

#include "Rule.h"
#include "CheckTurn.h"
class FriendlyPiece : virtual Rule
{
  public:

//*****************************************************************************
///  FriendlyPiece creates a FriendlyPiece object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   FriendlyPiece();
   
//*****************************************************************************
/// validMove  checks if the there is a friendly piece in the place where your current piece wants to move. if valid calls KingInCheck. if invalid return 0.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);

};

#endif
