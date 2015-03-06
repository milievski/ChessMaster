//*****************************************************************************
/// \file
/// \brief a concrete class for chat functionality between players.
///
/// \author Lukas Grasse
/// \date October 27, 2014
//*****************************************************************************

#ifndef CHAT_H
#define CHAT_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <utility>
using std::pair;

//*****************************************************************************
/// \brief a concrete class for chat functionality between players.
//*****************************************************************************
class Chat 
{
  public:

//*****************************************************************************
/// creates a Chat object
//
/// \param [in] playerOneId A string that is the id of player 1
/// \param [in] playerTwoId A string that is the id of player 2
//*****************************************************************************
Chat(string playerOneId="guest", string playerTwoId="guest");


//*****************************************************************************
/// gets player 1's id
//
/// \return player 1's id as a string
//*****************************************************************************
string getPlayerOneId() const;


//*****************************************************************************
/// gets player 2's id
//
/// \return player 2's id as a string
//*****************************************************************************
string getPlayerTwoId() const;

//*****************************************************************************
/// sets Player 1's Id
//
/// \param [in] playerOneId A string that the id of player 1 is set to
//*****************************************************************************
void setPlayerOneId(string playerOneId);


//*****************************************************************************
/// sets Player 2's Id
//
/// \param [in] playerTwoId A string that the id of player 2 is set to
//*****************************************************************************
void setPlayerTwoId(string playerTwoId);


//*****************************************************************************
/// adds a new message
//
/// \param [in] a pair of strings that is the player id and the message to be
///posted
//*****************************************************************************
void postMessage(string name, string message);

//*****************************************************************************
/// gets a reference to vector of messages
//
/// \return A reference to a vector of pairs that stores the messages 
//*****************************************************************************
vector< pair<string, string> >& getMessages();
   
  private:

//player 1's id  	
string playerOneId;

//player 2's id
string playerTwoId;

//a vector containing pairs of strings. Each pair is of strings representing
//the player id and the message
vector< pair<string, string> > messages;

};

#endif
