//*****************************************************************************
/// \ChessGame.cc
/// \brief a class for ChessGame, inherits from Game
///
/// \author Zackery Shortt
/// \date November 14, 2014
//*****************************************************************************


#inlcude "ChessGame.h"

ChessGame::ChessGame() : staleMate(false)
{
}

ChessGame::~ChessGame()
{
}

Board* ChessGame::getDeadBoard()
{
   return deadBoard;
}

bool ChessGame::setdeadBoard(Board b)
{
   if(*deadBoard = b)
      return true;
   return false;
}

bool ChessGame::undo()//use board undo
{
   if(gameHistory.pop_back())
      return true;
   return false;
}

const vector<string>* ChessGame::getGameHistory()
{
   return gameHistory;
}

void ChessGame::addMove(string move)
{
   gameHistory.push_back(move);
}

