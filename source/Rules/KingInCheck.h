//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
///
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef KingInCheck_H
#define KINGInCheck_H
#include <vector>
using std::vector;
#include "Rule.h"

#include "ConsecutiveMove.h"
class KingInCheck : virtual Rule
{
  public:
   
//*****************************************************************************
///  KingInCheck creates a KingInCheck object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   KingInCheck();
   
//*****************************************************************************
/// validMove checks if the king is in check. if valid call CheckTure. if invalid return 0.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);
   bool CheckMate(vector< vector < Piece* > > &b, int x, int y);

};

#endif
