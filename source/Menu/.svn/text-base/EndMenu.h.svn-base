//*****************************************************************************
/// \file
/// \brief a base class for all menus.
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************

#ifndef ENDMENU_H
#define ENDMENU_H

#include "GenericMenu.h"
#include <string>
using std::string;
#include "../status.h"
//*****************************************************************************
/// EndMenu is a subclass of GenericMenu.
//*****************************************************************************
class EndMenu : public GenericMenu
{
  public:
//******************************************************************************
/// \brief menufunc is the general handler for implementing the functionality
/// of this menu class
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] status is a class to enable manipulation of the current game
/// and players between classes
/// param[in] info is the class that holds global variables for players and
/// the game
//***************************************************************************
   GenericMenu* menufunc(string &opt, status* &info);

  private:

//*****************************************************************************
/// changed the color of the text being outputed
//
/// param[in] color is the color that you want the text to be.
/// param[in] type is the type of text you want (ex. bold, slash)
   
//*****************************************************************************
void Cprint(string color = "green", string type = "default");

//*****************************************************************************
/// main will open up the main menu.
///param[in] opt will be the option that the menu is changing to
///param[in] ret will be a pointer to the option that is to be changed to, in
/// in this case it refers to a main menu 
//*****************************************************************************
void main(string &opt, GenericMenu* &ret );

//*****************************************************************************
/// exit will terminate the game
///param[in] opt will be the option that the menu is changing to
///param[in] ret will be a pointer to the option that is to be changed to, in
/// in this case it refers to the exit
//*****************************************************************************
void exit(string &opt, GenericMenu* &ret);

//*****************************************************************************
/// leaderboard shows the users rank on a leaderboard of other users ranks.
///param[in] opt will be the option that the menu is changing to
///param[in] ret will be a pointer to the option that is to be changed to, in
/// in this case it refers to a leaderboard
//*****************************************************************************
void leaderboard(string &opt, GenericMenu* &ret);
 
};

#endif
