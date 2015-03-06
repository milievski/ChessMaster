//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
///
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef PROMOTION_H
#define PROMOTION_H
#include <vector>
using std::vector;
#include "Rule.h"
#include "PieceInWay.h"
class Promotion : virtual Rule
{
  public:
   
//*****************************************************************************
///  Promotion creates a Promotion object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   Promotion();
   
//*****************************************************************************
/// validMove if the location at where the pawn is requesting to move is at the end of the vector< vector < Piece* > > return 3(so the pawn moves to that location and gets promoted) if the location at where the pawn requested to be is not at the end of the vector< vector < Piece* > > then go to PieceInWay.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);

};

#endif
