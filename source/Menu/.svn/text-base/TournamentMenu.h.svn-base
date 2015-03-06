//*****************************************************************************
/// \file
/// \brief a class for tournament menu.
///
/// \auth Michael Wilson, Brandon Robertson.
/// \date October 26, 2014
//*****************************************************************************
#ifndef TOURNAMENTMENU
#define TOURNAMENTMENU

#include "GenericMenu.h"
#include <string>
#include "../status.h"
#include "../Tournament.h"
//*****************************************************************************
/// TournamentMenu is a subclass of Generic menu.
//*****************************************************************************
class TournamentMenu : public GenericMenu
{
  public:
//*****************************************************************************
/// TournamentMenu intializes all the names that will be displayed in the tournament.
//*****************************************************************************
   TournamentMenu(){};


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
//*****************************************************************************
/// changed the color of the text being outputed
//
/// param[in] color is the color that you want the text to be.
/// param[in] type is the type of text you want (ex. bold, slash)
//*****************************************************************************
void Cprint(string color = "green", string type = "default");   

//*****************************************************************************
/// main will open up the main menu.
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.
//*****************************************************************************
void main(string &opt, GenericMenu* &ret);

//*****************************************************************************
/// exit will terminate the game
///param[in] opt the option that is supposed to be redirected to for a new menu
///param[in] curs is the position of the cursor on the menu
//*****************************************************************************
void exit(string &opt, GenericMenu* &ret);

//*****************************************************************************
///make a new tournament will prompt for input of num players, names, and 
///tournament name
///param[in] tourn is a pointer that will point to the created tournament
//*****************************************************************************
void makeTournament(Tournament* &tourn);
//*****************************************************************************
///will load a previously created tournament 
///param[in] tourn is a pointer that will point to the created tournament
//*****************************************************************************
void loadTournament(Tournament* &tourn);
//******************************************************************************
///Function will proceed to draw the menu portion for user selection in the
/// menu
///param[in] opt the option that is supposed to be redirected to for a new menu
///param[in] curs is the position of the cursor on the menu
//******************************************************************************
void drawMenu(int &opt, int &curs);

};



#endif
