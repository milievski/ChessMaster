//*****************************************************************************
/// \file
/// \brief a base class for all menus.
///
/// \author Marko Ilievski
/// \date March 7,2016
//*****************************************************************************

#ifndef MYKINGINCHECK_H
#define MYKINGINCHECK_H
#include <vector>
using std::vector;
#include "Rule.h"

class MyKingInCheck : virtual Rule
{
  public:

//*****************************************************************************
///  NotEnoughPieces creates a NotEnoughPieces object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   MyKingInCheck();

   
//*****************************************************************************
/// validMove checks if the pieces left alive are the bishop and king or the knight and king it will return 2 else return 1.
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);

};

#endif
