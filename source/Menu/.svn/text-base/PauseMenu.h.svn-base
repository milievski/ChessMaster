//*****************************************************************************
/// \file
/// \brief a base class for all menus.
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************

#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include "GenericMenu.h"
#include "../status.h"
//*****************************************************************************
/// PauseMenu is a subclass of Generic Menu.
//*****************************************************************************
class PauseMenu : public GenericMenu
{
  public:

//*****************************************************************************
/// PauseMenu intializes all the buttons and assigns the buttons a sprite.
//*****************************************************************************
   PauseMenu(){};

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
/// save saves all progress to file
/// param[in] info is the class that holds global variables for players and
/// the game
/// param[in] ret is a pointer of genericMenu type that is pointing to the
/// menu to be opened
//*****************************************************************************
   void save(status* info, GenericMenu* &ret);

//*****************************************************************************
/// exit will terminate the game
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.   
//*****************************************************************************
   void exit(string &opt, GenericMenu* &ret);

//*****************************************************************************
/// Resume returns back to the game.
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.   
//*****************************************************************************
   void resume(string &opt, GenericMenu* &ret);

//*****************************************************************************
/// main will open up the main menu.
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.   
//*****************************************************************************
   void main(string &opt, GenericMenu* &ret);

//*****************************************************************************
///leaderboard will open up the leaderboard.
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.   
//*****************************************************************************
   void leaderBoard(string &opt, GenericMenu* &ret);


//*****************************************************************************
/// \brief Enter name will be a interface to enter a name.
///
/// \return string of the name that was entered.
//*****************************************************************************
   string EnterName();


};

#endif
