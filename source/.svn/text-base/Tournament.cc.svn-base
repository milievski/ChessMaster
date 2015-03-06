#include "Tournament.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;


//*****************************************************************************
/// creates a Tournament
//
/// \param [in] names A vector of strings containing the names of players
/// \param [in] tType tournamentType string   
//*****************************************************************************
   Tournament::Tournament(vector<string> names, string tType) 
            : names{names}, tournamentType{tType}, tournamentSize{2*names.size()-1},
            currentMatch{tournamentSize-names.size()}, numPlayers{names.size()}
   {
   
   if(!((names.size()&(names.size()-1))==0))
      throw tournament_error("Must have even number of players");   

   if(names.size()==0)
      throw tournament_error("Must not be empty"); 
   
   //initialize map positions
   this->generateOrder();
   }


//*****************************************************************************
/// creates a Tournament with rank map as parameter. Useful for creating using
/// the database loadTournament function   
//
/// \param [in] rank A map containing the name and rank of players
/// \param [in] tType tournamentType string   
//*****************************************************************************
   Tournament::Tournament(map<int,string> tempRank, string tType) 
      : rank{tempRank}, tournamentType{tType}, tournamentSize{tempRank.size()}
   {

      int tempMatch= 1;
      for(unsigned int i=1; i<= tempRank.size(); i++) 
      {
      if (tempRank[i]==""||tempRank[i]=="\n")
      tempMatch++;


}

      //number of players is the size of map +1 and divided by 2
      numPlayers = (tempRank.size()+1)/2;
      
      //current match is one less than temp match
      currentMatch = tempMatch-1;

   }


   
//*****************************************************************************
/// gets a pointer to the vector of names in the tournament
//
/// \return returns a pointer to the vector of names in the tournament
//*****************************************************************************   
   const vector<string>* Tournament::getNames() const 
   {
   const vector<string>* data = &names;
   return data;
   }

   
//*****************************************************************************
/// assigns players to tournament rank map, at the first level
//*****************************************************************************  
   void Tournament::generateOrder() 
   {
   //initialize empty places to spaces
   for(unsigned int i=1; i<=tournamentSize; i++) 
   {
   rank[i]="";
   }

   //add names to last row of tournament
   for(unsigned int i=0; i< names.size(); i++) 
   {
   rank[tournamentSize-names.size()+i+1] = names[i];
   }
 

   }

   

//*****************************************************************************
///returns the match currently being played
//
/// \return returns the rank int of the current spot being competed for
//*****************************************************************************   
   int Tournament::getCurrentMatch() const 
   {
   return currentMatch;
   }

   
//*****************************************************************************
///gets the size of the tournament
//
/// \return returns the an int of the size of the tournament
//*****************************************************************************     
   int Tournament::getTournamentSize() const 
   {

   return tournamentSize;

   }

   
//*****************************************************************************
///gets the next tournament spot to be competed for
//
/// \return returns the rank int of the next spot to be competed for
//*****************************************************************************    
   int Tournament::getNextMatch() const 
   {
  if(currentMatch>1) 
   {
      return currentMatch-1;
   }
   
   else 
   {
      return currentMatch;
   }
}


//*****************************************************************************
///gets the number of player in the tournament
//
/// \return returns the number of players in the tournament
//*****************************************************************************    
   int Tournament::getNumPlayers() const 
   {
   return numPlayers;
   }   
   

//*****************************************************************************
/// sets the winner of a match
//
/// \param [in] spot An int representing the spot won in the rank map
/// \param [in] player A string representing player that won the spot   
//*****************************************************************************   
   void Tournament::setMatchWinner(string player) 
   {
  //check children to make sure only a child advances to current match winner
   if(!(rank[currentMatch*2]==player||rank[currentMatch*2+1]==player))
      throw tournament_error("Winner must be a child of current match");

   //set winner
   rank[currentMatch] = player;
   
   //if tournament is not over change current match to next current match
   if(currentMatch>1) 
      {
      currentMatch--;
      }
   }

   
//*****************************************************************************
/// gets the winner of a match
//
/// \param [in] spot An int representing the spot in the rank map
/// \return A string representing player that won the spot   
//***************************************************************************** 
   string& Tournament::getMatchWinner(int spot) 
   {
      string& winnerName = rank[spot];
   return winnerName;
   }
   
