//*****************************************************************************
/// \file
/// \brief a subclass of the rule class.
///
/// \author Michael Wilson.
/// \date October 27,2014
//*****************************************************************************

#ifndef CASTLINGMOVE_H
#define CASTLINGMOVE_H
#include <vector>
using std::vector;
#include "Rule.h"
#include "PieceInWay.h"

class CastlingMove : virtual Rule
{
  public:

//*****************************************************************************
///  CastlingMove creates a CastlingMove object
//
/// \param[in] b is a vector< vector < Piece* > > object
/// \param[in] ix is the x for the initial location
/// \param[in] iy is the y for the initial location
/// \param[in] dx is the x for the destination location
/// \param[in] dy is the y for the destination location
//*****************************************************************************
   CastlingMove();
   
//*****************************************************************************
/// validMove checks if the king is moved two squares towards a rock. if its not F the move made by the user is a valid move that sacrifices the Castling rule. if valid calls PieceInWay. if invalid return 0.
//
/// \return an int 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > &b, int ix, int iy, int dx, int dy);

};

#endif
