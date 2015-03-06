#ifndef ROOKPIECE_H
#define ROOKPIECE_H
//*****************************************************************************
/// \file
/// \brief class for the Rook Piece
///
/// \author Marko Ilievski
/// \date October 27, 2014
//*****************************************************************************
#include <vector>
using std::vector;
#include "Piece.h"
//#include "../Rules/RookMove.h"
#include <string>
using std::string;
#include "../Rules/RookMove.h"

//*****************************************************************************
/// \brief a class for all Rook Piece`s.
//*****************************************************************************
class RookPiece : public Piece 
{
  public:
   
//*****************************************************************************
/// creates a Piece object
//*****************************************************************************
   RookPiece(int c=0);

   
//*****************************************************************************
/// gets the color of the Rook Piece 
//
/// \return int a 0 if white and 1 if black
//*****************************************************************************
   int getColor() const;


//*****************************************************************************
/// sets the Color of the Rook Piece
//
/// \param [in] colorOfPiece sets the Pawn Piece`s color
//***************************************************************************** 
   void setColor(int colorOfPiece);


//*****************************************************************************
/// Returns Rook to user 
//
/// \return a string that will return Rook Type.
 //*****************************************************************************
   string getType() const;


//*****************************************************************************
/// validates a move based on the Rook rules.  
//
/// \param [in] board A Board that will contain the currect board state
/// \param [in] ix A int that holds the x coordinate of where the piece is moving from
/// \param [in] iy A int that holds the y coordinate of where the piece is moving from
/// \param [in] dx A int that holds the x coordinate of where the piece is moving to
/// \param [in] dy A int that holds the y coordinate of where the piece is moving to 
//*****************************************************************************
   int validMove(vector< vector < Piece* > > gameBoard, int ix, int iy, int dx, int dy);
   
  private:
   int color;
   string Type;
};

#endif
