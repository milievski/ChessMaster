//*****************************************************************************
/// \ReplayPlayer.h
/// \brief a class for ReplayPlayers
///
/// \author Zackery Shortt
/// \date October 27, 2014
//*****************************************************************************

#ifndef REPLAYPLAYER_H
#define REPLAYPLAYER_H

#include "Player.h"
#include "RegisteredPlayer.h"

class ReplayPlayer: public Player
{
  public:
   ReplayPlayer(){name = "QuickStix"};
//*****************************************************************************
/// creates a Player
//
/// \param [in] This is the Piece that will be moved
//*****************************************************************************
   nextMove(Piece p);


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
// This is the piece that will be moved
   Piece p;
   
};

#endif
