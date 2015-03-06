//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
///
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef QUEENMOVE_H
#define QUEENMOVE_H
#include <vector>
using std::vector;
#include "Rule.h"
#include "PieceInWay.h"
class QueenMove : virtual Rule
{
  public:
   
//*****************************************************************************
///  QueenMove creates a QueenMove object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   QueenMove();
   
//*****************************************************************************
/// validMove if the queens requested location is either on the x axis or on the y axis, or if it is a on a perfect angle(ex. x+1, y+1) if any are true go to PieceInWay, else return 0.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);

};

#endif
