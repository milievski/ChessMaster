#ifndef CHESSGAMEGUI
#define CHESSGAMEGUI

#include "Menu/GenericMenu.h"
#include "ChessBoard.h"
#include "Board.h"
#include <string>
using std::string;
#include <iostream>
#include <iomanip>
#include "status.h"

class chessGameGUI : public GenericMenu
{
public:
	~chessGameGUI(){};

   //******************************************************************************
   /// \brief menufunc is the general handler for implementing the functionality
   /// of this menu class
   /// \param[in] opt a reference for the program to decide where it must go in
   /// the main
   /// param[in] status is a class to enable manipulation of the current game
   /// and players between classes
   //******************************************************************************
	GenericMenu* menufunc(string &opt, status* &info);

private:

//*****************************************************************************
/// changed the color of the text being outputed
//
/// param[in] color is the color that you want the text to be.
/// param[in] type is the type of text you want (ex. bold, slash)
//*****************************************************************************
	void Cprint(string color, string type);\


//*****************************************************************************
/// \brief draws the board with all the pieces in there correct location
//
/// param[in] Dmap is a chessboard pointer that will be used to draw the board.
/// param[in] cursror is the location at where the cursor is on the board.
/// param[in] select is the location where the user selected a piece.
//*****************************************************************************
	void drawBoard(ChessBoard* &Dmap, int cursor[], int select[]);

//*****************************************************************************
/// \brief replayer replicates a game being played so you can "replay" or rewatch the game.
//
/// param[in] info is status object that all the menus use.
//*****************************************************************************
	void Replayer(status *info);

//*****************************************************************************
/// CoordinateReturn will convert the character to a integer value as a y coordinate
//
/// param[in] co is the character that will be converted into an integer.
/// \return a integer that was converted from a character.
//*****************************************************************************
	int CoordinateReturn(char co);
	
	 vector<string> moves;
};


#endif
