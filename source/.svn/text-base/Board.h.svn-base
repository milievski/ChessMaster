//*****************************************************************************
/// \file
/// \brief a class that creates the Board.
///
/// \author Marko Ilievski
/// \date October 27, 2014
//*****************************************************************************

#ifndef BOARD_H
#define BOARD_H
#include "Piece/Piece.h"
#include <iostream>
#include "Piece/BishopPiece.h"
#include "Piece/PawnPiece.h"
#include "Piece/RookPiece.h"
#include "Piece/QueenPiece.h"
#include "Piece/KingPiece.h"
#include "Piece/KnightPiece.h"
#include "Piece/KnightPiece.h"
#include "Piece/EmptyPiece.h"
#include "Definitions.h"
#include <string>
using std::string;
#include <vector>
using std::vector;


//*****************************************************************************
/// \brief a concrete class for creating a board which games will be played on.
//*****************************************************************************
class Board 
{
  public:
//*****************************************************************************
/// Creates a Board object. As well as declaires vector of Piece`s that will be on the board.
//*****************************************************************************
   Board(int h= 8, int w=8);

      
//*****************************************************************************
/// Removes all the Piece`s that where on the board.
//****************************************************************************  
   ~Board();


//*****************************************************************************
/// Given a x and y coordinate and return the piece that is on that square
//
/// \param [in] x A int that contains the x coordinate
/// \param [in] y A int that contains the y coordinate
/// \return a Piece that is currently on the x and y square   
//***************************************************************************** 
   Piece * getPiece(int x, int y);


//*****************************************************************************
/// gets player 2's id
//
/// \param [in] x A int that contains the x coordinate
/// \param [in] y A int that contains the y coordinate
/// \param [in] p A Piece that will be inserted   
/// \return if the insert was successful
//*****************************************************************************
   void setPiece(int x, int y, Piece* p);

   void setNull(int x, int y);
 
//*****************************************************************************
/// sets the height of the Board to one provided by the user
//
/// \param [in] newHeight a new height which the board will be set to
//***************************************************************************** 
   void setHeight(int newHeight);

//*****************************************************************************
/// gets the height of the Board to one provided by the user
//
/// \param [in] newHeight a new height which the board will be set to
//***************************************************************************** 
   int getHeight();


//*****************************************************************************
/// returns the width of the Board
//
/// \return the width of the Board
//***************************************************************************** 
   int getWidth();


//*****************************************************************************
/// tsets the width of the Board to one provided by the user
//
/// \param [in] newWidth a new width which the board will be set to
//***************************************************************************** 
   void setWidth(int newWidth);


   //*****************************************************************************
/// validates a move based on the Pieces Move attribute. This will be overwritten 
//
/// \param [in] board A Board that will contain the currect board state
/// \param [in] ix A int that holds the x coordinate of where the piece is moving from
/// \param [in] iy A int that holds the y coordinate of where the piece is moving from
/// \param [in] dx A int that holds the x coordinate of where the piece is moving to
/// \param [in] dy A int that holds the y coordinate of where the piece is moving to 
//*****************************************************************************
   int movePiece(int ix,int iy, int dx, int dy);
   void MoveHistory(int cur1=0, int cur2=0, int des1=0, int des2=0, bool onOrOff = false);
   vector<string> getBoardHistory();
  private:

  char convertToChar(int con);

  vector< vector < Piece* > > gamePieces;
  vector<string> history;
  int height,width;
   


};

#endif
