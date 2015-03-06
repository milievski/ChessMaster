//*****************************************************************************
/// \file
/// \brief a class that creates the Chess Board.
///
/// \author Marko Ilievski
/// \date October 27, 2014
//*****************************************************************************


#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include "Board.h"
#include "Piece/Piece.h"
#include "Piece/KingPiece.h"
#include "Piece/QueenPiece.h"
#include "Piece/RookPiece.h"
#include "Piece/BishopPiece.h"
#include "Piece/KnightPiece.h"
#include "Piece/PawnPiece.h"
#include "Definitions.h"

//*****************************************************************************
/// \brief a concrete class for creating a chess board which games will be played on.
//*****************************************************************************
class ChessBoard
{
  public:
//*****************************************************************************
/// Creates a chess Board object. 
//*****************************************************************************
   ChessBoard();

   ~ChessBoard();
   void setUpChessBoard();

//*****************************************************************************
/// undo`s to the previouse move on the board
//
/// \return the previose board state
//*****************************************************************************   
   bool undo(string str= "delete later");

   
//*****************************************************************************
/// returns the dead Board
//
/// \return the dead Board
//*****************************************************************************
   vector<Piece*> getDeadBoard();

//*****************************************************************************
/// sets the DeadBoard
//
/// \param [in] b sets a new dead Board
//*****************************************************************************    
   void setDeadBoard(Piece* p);

   Piece * getPiece(int row, int col);

   Piece* popDeadBoard();
   

//*****************************************************************************
/// validates a move based on the Pieces Move attribute. 
//
/// \param [in] board A Board that will contain the currect board state
/// \param [in] ix A int that holds the x coordinate of where the piece is moving from
/// \param [in] iy A int that holds the y coordinate of where the piece is moving from
/// \param [in] dx A int that holds the x coordinate of where the piece is moving to
/// \param [in] dy A int that holds the y coordinate of where the piece is moving to 
//*****************************************************************************   
   int movePiece(int ix,int iy, int dx, int dy);
   vector<string> getGameHistory();
  private:
   Board *CBoard;
   
   vector< Piece* > deadHistory;
   
};

#endif
