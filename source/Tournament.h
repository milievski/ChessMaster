//*****************************************************************************
/// \file
/// \brief a concrete class for tournaments.
///
/// \author Lukas Grasse
/// \date October 27, 2014
//*****************************************************************************

#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;

#include "Errors.h"

//*****************************************************************************
/// \brief A concrete class representing a tournament for games
//*****************************************************************************
class Tournament 
{
  public:

//*****************************************************************************
/// creates a Tournament
//
/// \param [in] names A vector of strings containing the names of players
/// \param [in] tType tournamentType string   
//*****************************************************************************
   Tournament(vector<string> names, string tType="NORMAL");


//*****************************************************************************
/// creates a Tournament with rank map as parameter. Useful for creating using
/// the database loadTournament function   
//
/// \param [in] rank A map containing the name and rank of players
/// \param [in] tType tournamentType string   
//*****************************************************************************
   Tournament(map<int,string> tempRank, string tType="NORMAL");


   
//*****************************************************************************
/// gets a pointer to the vector of names in the tournament
//
/// \return returns a pointer to the vector of names in the tournament
//*****************************************************************************   
   const vector<string>* getNames() const;

   
//*****************************************************************************
/// intialize tournament
//*****************************************************************************  
   void generateOrder();

   

//*****************************************************************************
///returns the match currently being played
//
/// \return returns the rank int of the current spot being competed for
//*****************************************************************************   
   int getCurrentMatch() const;

   
//*****************************************************************************
///gets the size of the tournament
//
/// \return returns the an int of the size of the tournament
//*****************************************************************************     
   int getTournamentSize() const;

   
//*****************************************************************************
///gets the next tournament spot to be competed for
//
/// \return returns the rank int of the next spot to be competed for
//*****************************************************************************    
   int getNextMatch() const;
   
   //*****************************************************************************
///gets the number of players
//
/// \return returns the number of players
//*****************************************************************************    
   int getNumPlayers() const;

//*****************************************************************************
/// sets the winner of a match
//
/// \param [in] spot An int representing the spot won in the rank map
/// \param [in] player A string representing player that won the spot   
//*****************************************************************************   
   void setMatchWinner(string player);

   
//*****************************************************************************
/// gets the winner of a match
//
/// \param [in] spot An int representing the spot in the rank map
/// \return A string representing player that won the spot   
//***************************************************************************** 
  string& getMatchWinner(int spot);
   

  private:

// the names of the players still in the tournament  
   vector<string> names;

//the location of each player in the tournament.
//String represents name, and int represents location
//from top to bottom, left to right, in tournament pyramid. 
   map<int,string> rank;

//A string representing the tournament type.
//Types are round robin or single elimination
   string tournamentType;

//Size of tournament. Number represents count of initial contestants.    
   size_t tournamentSize;

//The current match being competed for.   
   size_t currentMatch;

  //Size of tournament. Number represents count of initial contestants.    
   size_t numPlayers;   
};

#endif
