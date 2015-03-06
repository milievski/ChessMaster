//*****************************************************************************
/// \file
/// \brief loginMenu header
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************

#ifndef LOGINMENU
#define LOGINMENU
#include "GenericMenu.h"
#include <iostream>
#include <string>
#include "../Players/Player.h"
#include "../status.h"
#include "../Players/RegisteredPlayer.h"
using std::string;

class LoginMenu : public GenericMenu
{
public:
//******************************************************************************
   /// \brief menufunc is the general handler for implementing the functionality
   /// of this menu class
   /// \param[in] opt a reference for the program to decide where it must go in
   /// the main
   /// param[in] status is a class to enable manipulation of the current game
   /// and players between classes
   //***************************************************************************
   
   GenericMenu* menufunc(string &opt, status* &info);

  private:

   //***************************************************************************
   /// \brief EnterName is the function that draws the screen for user input
   //***************************************************************************
   string EnterName();
   //***************************************************************************
   /// \brief main responsible for moving the program to the main menu
   /// param[in] opt is a string dictating where the program must go
   /// param[in] ret is a pointer to the next menu that will be displayed
   //***************************************************************************
   void main(string &opt, GenericMenu* &ret);
   //***************************************************************************
/// \brief loadCreatePlayer will work with the memento and database to
   ///retreive the information on a saved player, will default to create a
   /// player if they are not found
   /// param[in] name the name of the player to be found or created
   /// param[in] p a reference to the player class of the player retrieved
   //***************************************************************************
   void loadCreatePlayer(const string &name, RegisteredPlayer* &p);
   //***************************************************************************
   /// \brief cprint will change to output color of the text
   /// param[in] color  color to be chosen
   /// param[in] type  the type of printing to be used 
   //***************************************************************************
   void Cprint(const string color, const string type);
   //***************************************************************************
   /// \brief drawOption is the function responsible for drawing the options the
   /// user can select
   /// param[in] curs the cursor the user is currently on
   /// param[in] Ssize keeps the cursor from going to low or too high
   /// param[in] info is the a object for the state of the game and players
   /// allowing different menus to modify 
   //***************************************************************************
   	void drawOption(int curs, int Ssize, status* &info);
};
#endif
