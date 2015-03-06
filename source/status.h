// Author michael wilson

#ifndef STATUS_H
#define STATUS_H
#include "Database.h"
#include "Players/Player.h"
#include "Players/RegisteredPlayer.h"
#include "Board.h"
#include "ChessBoard.h"
#include "Players/Player.h"
#include "Game.h"
#include "Chat.h"
#include <string>
using std::string;
#include <iostream>

class status
{

public:
//**********************************************************************
/// \brief constructor that sets up status.
//***********************************************************************	
   status();

//**********************************************************************
/// \brief destructor for status. deletes all heap memory.
//***********************************************************************	
   ~status();

//**********************************************************************
/// \brief loadp1 will load a registered player onto the playerOne object
//
/// \param[in] player is a pointer to the registered player that is going to 
/// be copied.
//***********************************************************************
	void loadP1(RegisteredPlayer* player);

//**********************************************************************
/// \brief loadp2 will load a registered player onto the playerOne object
//
/// \param[in] player is a pointer to the registered player that is going to 
/// be copied.
//***********************************************************************
	void loadP2(RegisteredPlayer* player);

//**********************************************************************
/// \brief Replay will is a switch that turns replay on or off.
//***********************************************************************
	void Replay();

//**********************************************************************
/// \brief isReplay will return the status of replay.
//
/// \return returns weather status is true or false.
//***********************************************************************
	bool isReplay();

//**********************************************************************
/// \brief isLoad will return weather load is true or false
//
/// \return return weather load is true or false.
//***********************************************************************
	bool isLoad();

//**********************************************************************
/// \brief setReplayVector will set the replay vector with the history
/// vector that is being passed in.
//
/// \param[in] filename is the string of the location of the vector of strings 
/// in database.
//***********************************************************************
	void setReplayVector(string fileName);

//**********************************************************************
/// \brief setLoad will set weather a game is being loaded or not.
//
/// \param[in] set is a bool value that will be coppied onto load.
//***********************************************************************
	void setLoad(bool set);

//**********************************************************************
/// \brief setReplayVector will set the replay vector with the history
/// vector that is being passed in.
//
/// \param[in] filename is the string of the location of the vector of strings 
/// in database.
//***********************************************************************
	vector<string> getReplayVector();
	
//**********************************************************************
/// \brief getP1 will return a player pointer to the player that is stored in status.
//
/// \return a pointer to the player being stored in status.
//***********************************************************************	
	RegisteredPlayer* getP1();

//**********************************************************************
/// \brief getP2 will return a player pointer to the player that is stored in status.
//
/// \return a pointer to the player being stored in status.
//***********************************************************************	
	RegisteredPlayer* getP2();

//**********************************************************************
/// \brief getGame will return a pointer to the chessboard being stored in status.
//
/// \return a pointer to the ChessBoard being stored in status.
//***********************************************************************	
	ChessBoard* getGame();

//**********************************************************************
/// \brief setBoard will set the chessboard in status to the one being passed in.
//
/// \param[in] tempBoard is the pointer to the chessboard that is being stored in status.
//***********************************************************************	
	void setBoard(ChessBoard *tempBoard);



//**********************************************************************
/// \brief getP1Name will return the a string containing player ones name.
//
/// \returns a string
//***********************************************************************	
	string getP1Name();

//**********************************************************************
/// \brief getP1Name will return the a string containing player ones name.
//
/// \returns a string
//***********************************************************************	
	string getP2Name();

//******************************************************************************
	///this function will return a boolean on if the player 2 is a AI player
	/// or not for the multiplayer functionality
//******************************************************************************
	bool isAI();

  private:
	Chat* chat;
	ChessBoard* theGame;
	RegisteredPlayer* playerOne;
	RegisteredPlayer* playerTwo;
	vector<string> replayVector;
	bool replay, load;


};
#endif
