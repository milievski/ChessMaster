//*****************************************************************************
/// \file
/// \brief a concrete class for database functionality.
///
/// \author Lukas Grasse
/// \date October 27, 2014
//*****************************************************************************

#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <map>
using std::map;

#include "Definitions.h"

#include "Tournament.h"

#include "Players/RegisteredPlayer.h"


//*****************************************************************************
/// \brief a concrete class for database functionality for game programs.
//*****************************************************************************
class Database 
{
  public:

//*****************************************************************************
/// creates a Database object
//
/// \param [in] directoryLocation the location of the directory that the files
/// are stored in  	
//*****************************************************************************
	Database(string directoryLocation=DATABASE_LOCATION);  	

//*****************************************************************************  	
///loads a move by move play onto the gameHistory vector, then returns it.
//
/// \param [in] gameName the name of the game file to be loaded in
/// \return a vector of strings containing the moves to be performed to restore
/// game to previous state. (may also be used to replay game for replayPlayer)	
//*****************************************************************************  	
  	vector<string> loadGame(string gameName); 


//*****************************************************************************
///saves a vector of gameHistory to the gameName
//
/// \param [in] gameHistory a vector of strings containing the history of moves 
/// \param [in] gameName a string containing the file name to save the game to 	
//*****************************************************************************  	
  	void saveGame(vector<string> gameHistory, string gameName);

//*****************************************************************************
///returns the list of saved games found in the save game folder
//
/// \return	a vector of strings containing the names of saved game files
//*****************************************************************************  	
	vector<string> getSaveList();


//*****************************************************************************
///returns a vector of player Mementos containing the top “int” number of 
///players
//
/// \param [in] playerNum an int containing the number of top players to return
/// \return a vector of player Memento's containing the top players in 
/// decreasing order	
//*****************************************************************************	
	vector<Memento*> getTopPlayers(int playerNum=10);


//*****************************************************************************
///saves a memento object to given filename
//
/// \param [in] a memento object of a player to save to file.  	
//*****************************************************************************	
	void savePlayer(Memento* playerMemento, string playerName);


//*****************************************************************************
///returns memento object of player
//
/// \param [in] playerName a string of the player 
/// \return a player memento object	
//*****************************************************************************	
	Memento* loadPlayer(string playerName);

//*****************************************************************************
///saves a Tournament to file
//
/// \param [in] tournament a tournament that is saved to file
/// \param [in] fileName the fileName to save the tournament to	
//*****************************************************************************	
	void saveTournament(Tournament tournament, string fileName);

//*****************************************************************************
///loads tournament from file
//
/// \param [in] tournamentName the filename to load
/// \return a map containing the rank of everyone in the tournament	
//*****************************************************************************	
	map<int,string> loadTournament(string tournamentName);
   



//*****************************************************************************
//returns bool of whether or not player exists
//	
// paraqm[in] name a string of the players name	
// \return returns bool of whether or not player exists
//*****************************************************************************  	
	bool doesPlayerExist(string name); 

  private:
  	//the number of saved players
  	int playerCount;

//a string containing the directory location to load and save files
string directoryLocation;

};

#endif
