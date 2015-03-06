//*****************************************************************************
/// \AIPlayer.h
/// \brief a class for AIPlayer
///
/// \author Zackery Shortt
/// \date October 27, 2014
//*****************************************************************************

#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"
#include "RegisteredPlayer.h"

class AIPlayer: public Player
{
  public:
   
//*****************************************************************************
/// creates a AIPlayer object for AIPlayer class
//
/// \param [in] name The name of the AI
//*****************************************************************************
   AIPlayer(){name = "LinuxLarry"};
   
//*****************************************************************************
/// \return returns the name of the AI
//*****************************************************************************
   string getName();
   
//*****************************************************************************
/// creates a move for Board
//
/// \param [in] This is the board that has a move
//*****************************************************************************
   void nextMove(Board b);

//*****************************************************************************
/// Generates a Memento object
//
/// \return returns a memento object
//*****************************************************************************
   Memento generateMemento();

//*****************************************************************************
/// Restores this RegisteredPlayer object from the Memento object
//
/// \param [in] memento the memento object to restore
//*****************************************************************************
   void restoreMemento(Memento memento);
  private:
// this is a board
   Board b;
};

#endif
