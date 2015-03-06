//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
///
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef PIECEINWAY_H
#define PIECEINWAY_H
#include <vector>
using std::vector;
#include "Rule.h"
#include "FriendlyPiece.h"
class PieceInWay : virtual Rule
{
  public:

//*****************************************************************************
///  PieceInWay creates a PieceInWay object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   PieceInWay();

   
//*****************************************************************************
/// validMove checks if there is any piece in between where the piece currently is and where it wants to move. if valid calls FriendlyPiece. if invalid return 0.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);

};

#endif
