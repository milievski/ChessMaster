#include "status.h"
#include "Chat.h"
#include <unistd.h>
status::status()
{
   playerOne = new RegisteredPlayer;
   playerTwo = new RegisteredPlayer;
   theGame = new ChessBoard;
   replay = false;
   load = true;
   chat = new Chat;
}

status::~status()
{
   delete playerOne;
   delete playerTwo;
   delete theGame;
   delete chat;
}
void status::loadP1(RegisteredPlayer* player)
{

   playerOne = player;

}

void status::loadP2(RegisteredPlayer* player)
{

   playerTwo = player;
}	



RegisteredPlayer* status::getP1()
{
	return playerOne;
}

RegisteredPlayer* status::getP2()
{
	return playerTwo;
}


string status::getP1Name()
{
   return playerOne->getName();
}

string status::getP2Name()
{
   return playerTwo->getName();
}

bool status::isAI()
{
   //defaulting to false for the meantime untill AI is created and can be
   // properly flagged
   return false;

}

void status::Replay()
{
   if (replay == false)
      replay = true;
   else 
      replay = false;
}

bool status::isReplay()
{
   return replay;
}

ChessBoard* status::getGame()
{
   return theGame;
}
void status::setBoard(ChessBoard *tempBoard)
{
   theGame = tempBoard;
}

void status::setReplayVector(string fileName)
{

   Database data;


      replayVector = data.loadGame(fileName);
   

}
void status::setLoad(bool set)
{
   load = set;
}


vector<string> status::getReplayVector() 
{
   return replayVector;
}

bool status::isLoad() 
{
   return load;
}