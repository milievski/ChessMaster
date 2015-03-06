#ifndef PAWNPIECE_H
#define PAWNPIECE_H
//*****************************************************************************
/// \file
/// \brief class for the Pawn Piece
///
/// \author Marko Ilievski
/// \date October 27, 2014
//*****************************************************************************

#include "Piece.h"
//#include "../Rules/PawnMove.h"
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "../Rules/PawnMove.h"

//*****************************************************************************
/// \brief a class for all Pawn Piece`s.
//*****************************************************************************
class PawnPiece : public Piece 
{
  public:
   
//*****************************************************************************
/// creates a Piece object
//*****************************************************************************
   PawnPiece(int c=0);

   
//*****************************************************************************
/// gets the color of the Pawn Piece 
//
/// \return int a 0 if white and 1 if black
//*****************************************************************************
   int getColor() const;


//*****************************************************************************
/// sets the Color of the Pawn Piece
//
/// \param [in] colorOfPiece sets the Pawn Piece`s color
//***************************************************************************** 
   void setColor(int colorOfPiece);


//*****************************************************************************
/// Returns Pawn to user 
//
/// \return a string that will return Pawn Type.
 //*****************************************************************************
   string getType() const;


//*****************************************************************************
/// validates a move based on the Pawn rules.  
//
/// \param [in] board A Board that will contain the currect board state
/// \param [in] ix A int that holds the x coordinate of where the piece is moving from
/// \param [in] iy A int that holds the y coordinate of where the piece is moving from
/// \param [in] dx A int that holds the x coordinate of where the piece is moving to
/// \param [in] dy A int that holds the y coordinate of where the piece is moving to 
//*****************************************************************************
  virtual int validMove(vector< vector < Piece* > > gameBoard, int ix, int iy, int dx, int dy);
   
  private:
   int color;
   string Type;
};

#endif
