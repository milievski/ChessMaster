//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
///
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef ROOKMOVE_H
#define ROOKMOVE_H
#include <vector>
using std::vector;
#include "Rule.h"
#include "PieceInWay.h"

class RookMove : public Rule
{
  public:
   
//*****************************************************************************
///  RookMove creates a RookMove object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   RookMove();
   
//*****************************************************************************
/// validMove if the rook requested location is either going strictly on the x axis or strictly on the y axis then go to PieceInWay else return 0.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector<vector<Piece*> > &b, int ix, int iy, int dx, int dy);

};

#endif
