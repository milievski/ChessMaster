#include <vector>
using std::vector;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include "Chat.h"

//*****************************************************************************
/// creates a Chat object
//
/// \param [in] playerOneId A string that is the id of player 1
/// \param [in] playerTwoId A string that is the id of player 2
//*****************************************************************************
Chat::Chat(string playerOneId, string playerTwoId)
	:playerOneId{playerOneId}, playerTwoId{playerTwoId}
{


}


//*****************************************************************************
/// gets player 1's id
//
/// \return player 1's id as a string
//*****************************************************************************
string Chat::getPlayerOneId() const
{
return playerOneId;
}


//*****************************************************************************
/// gets player 2's id
//
/// \return player 2's id as a string
//*****************************************************************************
string Chat::getPlayerTwoId() const
{
return playerTwoId;
}

//*****************************************************************************
/// sets Player 1's Id
//
/// \param [in] playerOneId A string that the id of player 1 is set to
//*****************************************************************************
void Chat::setPlayerOneId(string pOneId)
{
playerOneId = pOneId;
}


//*****************************************************************************
/// sets Player 2's Id
//
/// \param [in] playerTwoId A string that the id of player 2 is set to
//*****************************************************************************
void Chat::setPlayerTwoId(string pTwoId)
{
playerTwoId = pTwoId;

}


//*****************************************************************************
/// adds a new message
//
/// \param [in] a pair of strings that is the player id and the message to be
///posted
//*****************************************************************************
void Chat::postMessage(string name, string message)
{
pair<string, string> newMessage;

newMessage = make_pair(name, message);

messages.push_back(newMessage);
}

//*****************************************************************************
/// gets a reference to vector of messages
//
/// \return A reference to a vector of pairs that stores the messages 
//*****************************************************************************
vector< pair<string, string> >& Chat::getMessages()
{
return messages;
}
   
  
