//*****************************************************************************
/// \RegisteredPlayer.cc
/// \brief a class for RegisteredPlayer which inherets from Player
///
/// \author Zackery Shortt
/// \date November 17, 2014
//*****************************************************************************

#include <iostream>
#include <string>
#include <stdexcept>
using std::string;
#include "RegisteredPlayer.h"

RegisteredPlayer::RegisteredPlayer(string n) : elo(0), gamesWon(1), gamesLost(1), tournamentsWon(0), player(0),name(n)
{
  
}

RegisteredPlayer::~RegisteredPlayer()
{
}

bool RegisteredPlayer::setElo()
{
   if(gamesLost < 1)
      return false;
   elo = (gamesWon*1000)/gamesLost;
   return true;
}

int RegisteredPlayer::getElo()
{
   return elo;
}

int RegisteredPlayer::getGamesWon()
{
   return gamesWon;
}

bool RegisteredPlayer::incrementGamesWon()
{
   gamesWon += 1;
   return true;
}

int RegisteredPlayer::getGamesLost()
{
   return gamesLost;
}

bool RegisteredPlayer::incrementGamesLost()
{
   gamesLost += 1;
   return true;
}

string RegisteredPlayer::getName()
{
   return name;
}

Memento* RegisteredPlayer::generateMemento()
{
   //create memento and return it
   Memento *memento = new Memento(elo, gamesWon,gamesLost,tournamentsWon, name);
   return memento;
}

void RegisteredPlayer::restoreMemento(Memento* memento)
{

//restore player variables from parameter memento variables   
elo = (*memento).eloState;
gamesWon = (*memento).gamesWonState;
gamesLost = (*memento).gamesLostState;
tournamentsWon = (*memento).tournamentsWonState;
name = (*memento).nameState;
}




