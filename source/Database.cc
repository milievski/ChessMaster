//*****************************************************************************
//file
//brief a concrete class for database functionality.
//
//author Lukas Grasse
//date October 27, 2014
//*****************************************************************************

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::getline;

#include <utility>
using std::pair;

#include <map>
using std::map;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <fstream>
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;



#include "Tournament.h"
#include "Database.h"
#include "Definitions.h"
#include "Errors.h"

#include "Players/RegisteredPlayer.h"


//*****************************************************************************
// creates a Database object
//
// param: directoryLocation the location of the directory that the files
// are stored in  	
//*****************************************************************************
	Database::Database(string directoryLocation) : directoryLocation{directoryLocation}
	{

	//open file storing number of players	
	string numFile = directoryLocation + SAVED_PLAYERS_LOCATION + "playernum.data";

	ifstream theFile;

	theFile.open(numFile);
	
	//error check for file
	if(!(theFile.is_open())) 
	{
		throw database_load_error("num file failed to load");
	}

	//read number of players
	theFile >> playerCount;

	theFile.close();

	}  	

//*****************************************************************************  	
//loads a move by move play onto the gameHistory vector, then returns it.
//
// param: gameName the name of the game file to be loaded in
// return a vector of strings containing the moves to be performed to restore
// game to previous state. (may also be used to replay game for replayPlayer)	
//*****************************************************************************  	
  	vector<string> Database::loadGame(string gameName) 
  	{
	
	//open file of game location
	string fileLoc = directoryLocation + SAVED_GAMES_LOCATION + gameName;

	ifstream gameFile;

	gameFile.open(fileLoc);
	
	//error check for file
	if(!(gameFile.is_open())) 
	{
		throw database_load_error("game failed to load");
	}
	
	//temp string
	string move;

	//vector of game moves 
	vector<string> moves;

	while(getline(gameFile, move)) 
	{
		moves.push_back(move);
	}

	gameFile.close();
	
	return moves;

  	} 


//*****************************************************************************
//saves a vector of gameHistory to the gameName
//
// param: gameHistory a vector of strings containing the history of moves 
// param: gameName a string containing the file name to save the game to 	
//*****************************************************************************  	
  	void Database::saveGame(vector<string> gameHistory, string gameName) 
  	{

  	//location to store game	
	string fileLoc = directoryLocation + SAVED_GAMES_LOCATION + gameName;

	//file storing list of saved games
	string listLoc = directoryLocation + SAVED_GAMES_LOCATION + "saved_games_listing.data";

	ofstream gameFile;
	ofstream listFile;

	gameFile.open(fileLoc);
	listFile.open(listLoc, ios::app);

	//error check for file
	if(!(gameFile.is_open())) 
	{
		throw database_load_error("game save file failed to load");
	}

	//error check for file
	if(!(listFile.is_open())) 
	{
		throw database_load_error("list save file failed to load");
	}

	//add name to list of saved games
	listFile << gameName << endl;
	listFile.close();

	//save moves from game to file
	for(unsigned int i=0; i<gameHistory.size(); i++) 
	{
		gameFile << gameHistory[i] << endl;
	}

	gameFile.close();

  	}

//*****************************************************************************
//returns the list of saved games found in the save game folder
//
// return	a vector of strings containing the names of saved game files
//*****************************************************************************  	
	vector<string> Database::getSaveList() 
	{

	fstream gamesFile;

	//file storing list of saved games
	gamesFile.open(directoryLocation + SAVED_GAMES_LOCATION + "saved_games_listing.data");

	//error check for file
	if(!(gamesFile.is_open())) 
	{
		throw database_load_error("games save list file failed to load");
	}
	
	//temp string
	string name;

	//vector storing list of saved games
	vector<string> names;

	//add names to vector
	while(getline(gamesFile, name)) 
	{
		names.push_back(name);
	}

	gamesFile.close();
	return names;

	}


//*****************************************************************************
//returns bool of whether or not player exists
//	
// paraqm[in] name a string of the players name	
// \return returns bool of whether or not player exists
//*****************************************************************************  	
	bool Database::doesPlayerExist(string nameTest) 
	{


	fstream playerFile;

	//list of saved players
	playerFile.open(directoryLocation + SAVED_PLAYERS_LOCATION + "player_names.data");

	//error check for file
	if(!(playerFile.is_open())) 
	{
		throw database_load_error("player list file failed to load");
	}
	
	//temp string
	string name;

	//vector to store names
	vector<string> names;

	//load file of names
	while(getline(playerFile, name)) 
	{
		names.push_back(name);
	}

	playerFile.close();
	
	//check if player is in list
	for(auto n : names) 
	{
	if(nameTest==n)
		return true;
	}

	return false;

	}


//*****************************************************************************
//returns a vector of player Mementos containing the top “int” number of 
//players
//
// param: playerNum an int containing the number of top players to return
// return a vector of player Memento's containing the top players in 
// decreasing order	
//*****************************************************************************	
	vector<Memento*> Database::getTopPlayers(int playerNum) 
	{

	//vector of player mementos
	vector<Memento*> a;

	//list of player names
	string numFile = directoryLocation + SAVED_PLAYERS_LOCATION + "player_names.data";

	ifstream theFile;

	theFile.open(numFile);
	
	//error check for file	
	if(!(theFile.is_open())) 
	{
		throw database_load_error("num file failed to load");
	}

	//temp string
	string name;
	
	//read names
		while(getline(theFile, name)) 
		{ 
			// temp memento pointer
			Memento *temp = new Memento;
			
			//attempt to restore memento from file using player name
			try
			{
				temp->readMemento(name);
			}
			catch(database_load_error e)
			{
				//skip player if no saved data exists
				continue;	
			}
			
			//add memento to vector
			a.push_back(temp);

		}

	theFile.close();
	return a;
	}


//*****************************************************************************
//saves a memento object to given filename
//
// param: a memento object of a player to save to file.  	
//*****************************************************************************	
	void Database::savePlayer(Memento* playerMemento, string playerName) 
	{

	//get number of players from file
	string numFile = directoryLocation + SAVED_PLAYERS_LOCATION + "playernum.data";

	ifstream theFile;

	theFile.open(numFile);
	
	//error check for file	
	if(!(theFile.is_open())) 
	{
		throw database_load_error("num file failed to load");
	}

	//get number of players from file
	theFile >> playerCount;

	theFile.close();

	//check if player already exists
	if(!(doesPlayerExist(playerName))) 
	{

	//increment number of saved players
	playerCount++;	

	string numFile = directoryLocation + SAVED_PLAYERS_LOCATION + "playernum.data";

	ofstream theFile;

	theFile.open(numFile);
	
	//get number of players from file	
	if(!(theFile.is_open())) 
	{
		throw database_load_error("num file failed to load");
	}

	//save new player number
	theFile << playerCount;

	theFile.close();


	}

	//save player to file
	playerMemento->writeMemento(playerMemento, playerName);

	}


//*****************************************************************************
//returns memento object of player
//
// param: playerName a string of the player 
// return a player memento object	
//*****************************************************************************	
	Memento* Database::loadPlayer(string playerName) 
	{

	//restore memento object from file and return pointer
	 Memento *a = new Memento(1, 1, 1, 1, "test");
	 a->readMemento(playerName);
	 return a;

	}

//*****************************************************************************
//saves a Tournament to file
//
// param: tournament a tournament that is saved to file
// param: fileName the fileName to save the tournament to	
//*****************************************************************************	
	void Database::saveTournament(Tournament tournament, string fileName) 
	{

	//location of tournament to save
	string fileLoc = directoryLocation + SAVED_TOURNAMENT_LOCATION + fileName;

	ofstream tournamentFile;
	
	tournamentFile.open(fileLoc);

	//error check for file	
	if(!(tournamentFile.is_open())) 
	{
		throw database_load_error("tournament save file failed to load");
	}

	//write tournament to file
	for(int i=1; i<=tournament.getTournamentSize(); i++) 
	{
		tournamentFile << tournament.getMatchWinner(i) << endl;
	}

	tournamentFile.close();


	}

//*****************************************************************************
//loads tournament from file
//
// param: tournamentName the filename to load
// return a map containing the rank of everyone in the tournament	
//*****************************************************************************	
	map<int,string> Database::loadTournament(string tournamentName) 
	{

	//map of players and positions
	map<int, string> a;

	//location of tournament to load
	string fileLoc = directoryLocation + SAVED_TOURNAMENT_LOCATION + tournamentName;

	ifstream tournamentFile;

	tournamentFile.open(fileLoc);

	//error check for file	
	if(!(tournamentFile.is_open())) 
	{
		throw database_load_error("tournament save file failed to load");
	}

	//load tournament into map of players and positions
	int index=1;
	string temp;
	while(getline(tournamentFile, temp)) 
	{
			
			a[index] = temp;

			index++; 
		}

	tournamentFile.close();

	//return map
	return a;
	}
   

