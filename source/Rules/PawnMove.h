//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
///
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef PAWNMOVE_H
#define PAWNMOVE_H
#include <vector>
using std::vector;
#include "Rule.h"
#include "PawnCapture.h"
#include "Promotion.h"
#include <algorithm>
class PawnMove : public Rule
{
  public:
   
//*****************************************************************************
///  PawnMove creates a PawnMove object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   PawnMove();
   
//*****************************************************************************
/// validMove checks if the move made by the user is a valid move or Pawns to make. if invalid calls PawnCapture. if invalid return 0.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);

};

#endif
