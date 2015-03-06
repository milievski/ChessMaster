//*****************************************************************************
/// \Player.h
/// \brief a class for Players
///
/// \author Zackery Shortt, Lukas Grasse
/// \date October 27, 2014
//*****************************************************************************
 
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using std::string;

class Memento;

class Player 
{

  public:

  virtual ~Player(){};

  virtual string getName() = 0;

//*****************************************************************************
/// Generates a Memento object
//
/// \return returns a memento object
//*****************************************************************************
   virtual Memento* generateMemento() = 0;

//*****************************************************************************
/// Restores this RegisteredPlayer object from the Memento object
//
/// \param [in] memento the memento object to restore
//*****************************************************************************
   virtual void restoreMemento(Memento* memento) = 0;
   
   

};

class Memento
{

public:

//*****************************************************************************
/// creates a memento object for RegisteredPlayer class
//
/// \param [in] elo The elo int to be stored
/// \param [in] gamesWon The gamesWon int to be stored
/// \param [in] gamesLost The gamesLost int to be stored
/// \param [in] tournamentsWon The tournamentsWon int to be stored  
//*****************************************************************************
  Memento(int elo=0, int gamesWon=0, int gamesLost=0, int tournamentsWon=0, string name="Guest");

//*****************************************************************************
/// writes a memento object to the given osstream
//
/// \param [in] os the output stream to write the memento object to.(probably
///filestream)
/// \param [in] fileName a string for the file the memento object is written to   
//*****************************************************************************
  void writeMemento(Memento* memento, string fileName);

//*****************************************************************************
/// returns a memento object from the given file
//
/// \param [in] fileName a string for the file the memento object is read from
/// \return the memento object that is read from file   
//*****************************************************************************
  Memento* readMemento(string fileName);


private:
  
//friend of registered player class
  friend class RegisteredPlayer;
  

// state of elo int
  int eloState;

// state of gamesWon int
  int gamesWonState;

// state of gamesLost int
  int gamesLostState;

// state of tournamentsWon int
  int tournamentsWonState;

  string nameState;
};


#endif
