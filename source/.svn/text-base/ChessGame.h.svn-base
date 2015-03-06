//*****************************************************************************
/// \ChessGame.h
/// \brief a class for Game
///
/// \author Zackery Shortt
/// \date October 28, 2014
//*****************************************************************************

#include <vector>

#ifndef CHESSGAME_H
#define CHESSGAME_H

//*****************************************************************************
/// \brief a class for ChessGame based on the Game class.
//*****************************************************************************
class ChessGame: public Game
{
  public:
   
//*****************************************************************************
/// Creates a ChessGame. 
//*****************************************************************************
   ChessGame();
   
//*****************************************************************************
/// destructor for ChessGame. 
//*****************************************************************************
   ~ChessGame();
   
//*****************************************************************************
/// This function returns a pointer to board
//
/// \return returns a pointer to deadBoard
//*****************************************************************************
   Board* getDeadBoard();
   
//*****************************************************************************
/// sets board
//
/// \param [in] This is the Board that deadBoard will be set to
//
/// \return returns a bool whether it was successful
//*****************************************************************************
   bool setDeadBoard(Board b);

//*****************************************************************************
/// undo a move
//
/// \return returns a bool whether it was successful
//*****************************************************************************
   bool undo();


//*****************************************************************************
/// gets a pointer to game history
//
/// \return returns a pointer to gameHistory
//*****************************************************************************
   const vector<string>* getGameHistory();
   

//*****************************************************************************
/// adds a move to game history
//
/// \param [in] move The move to add
//*****************************************************************************
  void addMove(string move);
   

//*****************************************************************************
/// gets a pointer to deadHistory
//
/// \return returns a pointer to deadHistory
//*****************************************************************************
   deadHistory* getDeadHistory();
   
  private:
// This is a board that holds all the dead peices
   Board deadBoard;
// This is the board that chess is played on
   ChessBoard GameBoard;
// This vector holds the history of the game
   vector<string> gameHistory;
// This vector holds the dead peices
   vector <Board> deadHistory;
// This bool holds the state of a stale mate
   bool staleMate;
   
};


#endif
