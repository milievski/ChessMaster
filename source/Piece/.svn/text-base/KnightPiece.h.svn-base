#ifndef KNIGHTPIECE_H
#define KNIGHTPIECE_H
//*****************************************************************************
/// \file
/// \brief class for the Knight Piece
///
/// \author Marko Ilievski
/// \date October 27, 2014
//*****************************************************************************
//#include "../Rules/KnightMove.h"
#include "Piece.h"
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "../Rules/KnightMove.h"

//*****************************************************************************
/// \brief a class for all Knight Piece`s.
//*****************************************************************************
class KnightPiece : public Piece 
{
  public:
   
//*****************************************************************************
/// creates a Piece object
//*****************************************************************************
   KnightPiece(int c=0);

   
//*****************************************************************************
/// gets the color of the Knight Piece 
//
/// \return int a 0 if white and 1 if black
//*****************************************************************************
   int getColor() const;


//*****************************************************************************
/// sets the Color of the Knight Piece
//
/// \param [in] colorOfPiece sets the Pawn Piece`s color
//***************************************************************************** 
   void setColor(int colorOfPiece);


//*****************************************************************************
/// Returns Knight to user 
//
/// \return a string that will return Knight Type.
 //*****************************************************************************
   string getType() const;


//*****************************************************************************
/// validates a move based on the Knight rules.  
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
