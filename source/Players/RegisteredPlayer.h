//*****************************************************************************
/// \RegisteredPlayer.h
/// \brief a class for RegisteredPlayer which inherets from Player
///
/// \author Zackery Shortt
/// \date October 27, 2014
//*****************************************************************************
#ifndef REGISTEREDPLAYER_H
#define REGISTEREDPLAYER_H


#include <iostream>
#include <string>
#include "Player.h"
using std::string;





class RegisteredPlayer : public Player 
{
  public:
   
//*****************************************************************************
/// creates a RegisteredPlayer from the data base
//*****************************************************************************
  RegisteredPlayer(string name="Guest");

//*****************************************************************************
/// destructor for RegisteredPlayer 
//*****************************************************************************
   ~RegisteredPlayer();

//*****************************************************************************
/// returns a bool based on whether ELO has been sucessfully updated
/// The elo has been updated based on the end game score and if the player won
//*****************************************************************************
   bool setElo();


//*****************************************************************************
/// returns the ELO
//*****************************************************************************
   int getElo();
   
//*****************************************************************************
/// returns the Games won
//*****************************************************************************
   int getGamesWon();

//*****************************************************************************
/// returns a bool based on whether games won has been sucessfully updated
//*****************************************************************************
   bool incrementGamesWon();
   
//*****************************************************************************
/// returns the Games won
//*****************************************************************************
   int getGamesLost();

//*****************************************************************************
/// returns a bool based on whether games lost has been sucessfully updated
//*****************************************************************************
   bool incrementGamesLost();
   
//*****************************************************************************
/// returns the name of this player
//*****************************************************************************
   string getName();


//*****************************************************************************
/// Generates a Memento object
//
/// \return returns a memento object
//*****************************************************************************
   Memento* generateMemento();

//*****************************************************************************
/// Restores this RegisteredPlayer object from the Memento object
//
/// \param [in] memento the memento object to restore
//*****************************************************************************
   void restoreMemento(Memento* memento);
   
  private:
// elo is the players score compared to other players
// gamesWon, numbers of games won
// gamesLost, numbers of games lost
// tournamentsWon, numbers of tournaments won
   int elo;
   int gamesWon;
   int gamesLost;
   int tournamentsWon; 
   int player;
// name, name of person
   string name;
   
};



#endif
