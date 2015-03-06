#ifndef PIECE_H
#define PIECE_H
//*****************************************************************************
/// \file
/// \brief a base class for Piece`s
///
/// \author Marko Ilievski
/// \date October 27, 2014
//*****************************************************************************
#include <iostream>
using std::iostream;
#include <string>
using std::string;
#include <vector>
using std::vector;

//*****************************************************************************
/// \brief a a base class that will be inherited by all other Piece`s.
//*****************************************************************************
class Piece 
{
  public:

   

   virtual ~Piece() {};
//*****************************************************************************
/// gets the color of the Piece 
//
/// \return int a 0 if white and 1 if black
//*****************************************************************************
   virtual int getColor() const = 0;


//*****************************************************************************
/// sets the Color of the Piece
//
/// \param [in] colorOfPiece sets the Piece color
//***************************************************************************** 
   virtual void setColor(int colorOfPiece) = 0;


//*****************************************************************************
/// gets the type of Piece 
//
/// \return a string that will be the Piece Type.
//***************************************************************************** 
   virtual string getType() const = 0;


//*****************************************************************************
/// validates a move based on the Pieces Move attribute. This will be overwritten 
//
/// \param [in] board A Board that will contain the currect board state
/// \param [in] ix A int that holds the x coordinate of where the piece is moving from
/// \param [in] iy A int that holds the y coordinate of where the piece is moving from
/// \param [in] dx A int that holds the x coordinate of where the piece is moving to
/// \param [in] dy A int that holds the y coordinate of where the piece is moving to 
//*****************************************************************************
   virtual int validMove(vector< vector < Piece* > > gameBoard, int ix, int iy, int dx, int dy) = 0;
   
};

#endif
