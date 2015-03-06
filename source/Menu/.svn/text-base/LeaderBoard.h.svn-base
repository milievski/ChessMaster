//*****************************************************************************
/// \file
/// \brief a base class for all menus.
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************



#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "GenericMenu.h"
#include <string>
using std::string;
#include <iomanip>
#include <iostream>
#include "../Players/Player.h"
#include "../Players/RegisteredPlayer.h"
#include "../Database.h"
#include "../Definitions.h"
#include <vector>
#include "MainMenu.h"
using std::vector;

using namespace std;
#include "../status.h"

class LeaderBoard : public GenericMenu
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

//*****************************************************************************
/// changed the color of the text being outputed
//
/// param[in] color is the color that you want the text to be.
/// param[in] type is the type of text you want (ex. bold, slash)
//*****************************************************************************
void Cprint(string color = "green", string type = "default");

//***************************************************************************
///Exit will be called by menufunc
/// if called will terminate the program.
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.
//***************************************************************************
   void exit(string &opt, GenericMenu* &ret);

//*****************************************************************************
/// main will open up the main menu.
//*****************************************************************************
   void main(bool &ml, bool &gl);



//*****************************************************************************
/// gets the top five players and puts them into the vector of registeredPlayers.
//*****************************************************************************
      void getPlayer();


};


#endif
