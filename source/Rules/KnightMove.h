//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
///
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef KNIGHTMOVE_H
#define KNIGHTMOVE_H
#include <vector>
using std::vector;
#include "Rule.h"
#include "FriendlyPiece.h"


class KnightMove : virtual Rule
{
  public:
   
//*****************************************************************************
///  KnightMove creates a KnightMove object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   KnightMove();
   
//*****************************************************************************
/// validMove if the knights requested location id ((y+2 or y - 2) and (x+1 or x -1)) or (( y+1 or y -1) and (x + 2 or x -2)) then go to FriendlyPiece rule else return 0.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);

};

#endif
