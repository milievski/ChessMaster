//******************************************************************************
/// \author   Zackery Shortt, Lukas Grasse
/// \brief    Player Class
/// \date November 12, 2014
//******************************************************************************

#include "Player.h"
#include "../Definitions.h"
#include "../Errors.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <fstream>
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

//*****************************************************************************
/// creates a memento object for RegisteredPlayer class
//
/// \param [in] elo The elo int to be stored
/// \param [in] gamesWon The gamesWon int to be stored
/// \param [in] gamesLost The gamesLost int to be stored
/// \param [in] tournamentsWon The tournamentsWon int to be stored  
//*****************************************************************************
  Memento::Memento(int elo, int gamesWon, int gamesLost, int tournamentsWon, string name)
  {
  //initialize state to Player variables  
  eloState = elo;
  gamesWonState = gamesWon;
  gamesLostState = gamesLost;
  tournamentsWonState = tournamentsWon;
  nameState = name;
  }

//*****************************************************************************
/// writes a memento object to the given osstream
//
/// \param [in] os the output stream to write the memento object to.(probably
///filestream)
/// \param [in] fileName a string for the file the memento object is written to   
//*****************************************************************************
  void Memento::writeMemento(Memento* memento, string fileName)
  {

  nameState = fileName;
  
  //location of saved memento object  
  string fileLoc = DATABASE_LOCATION + SAVED_PLAYERS_LOCATION + fileName;

  //location of player names
  string listLoc = DATABASE_LOCATION + SAVED_PLAYERS_LOCATION + "player_names.data";

  ofstream playerFile;
  ofstream listFile;

  playerFile.open(fileLoc);
  listFile.open(listLoc, ios::app);
  
  //file error check
  if(!(playerFile.is_open())) 
  {
    throw database_load_error("memento file failed to load");
  }

  //file error check
  if(!(listFile.is_open())) 
  {
    throw database_load_error("player list file failed to load");
  }

  //add player name to list of saved players
  listFile << fileName << endl;
  listFile.close();

  //write memento attributes to file
  playerFile << memento->eloState << endl;
  playerFile << memento->gamesWonState << endl;
  playerFile << memento->gamesLostState << endl;
  playerFile << memento->tournamentsWonState << endl;
  playerFile << memento->nameState << endl;
 
  playerFile.close();

  }

//*****************************************************************************
/// returns a memento object from the given file
//
/// \param [in] fileName a string for the file the memento object is read from
/// \return the memento object that is read from file   
//*****************************************************************************
  Memento* Memento::readMemento(string fileName)
  {

  string fileLoc = DATABASE_LOCATION + SAVED_PLAYERS_LOCATION + fileName;
  //cout << fileLoc;
  ifstream playerFile;

  playerFile.open(fileLoc);

  //file error check  
  if(!(playerFile.is_open())) 
  {
    throw database_load_error("memento failed to load");
  }


 //read attributes from file  
 playerFile >> eloState;
 playerFile >> gamesWonState;
 playerFile >> gamesLostState;
 playerFile >> tournamentsWonState;
 playerFile >> nameState;

  playerFile.close();
  
return this;

  }