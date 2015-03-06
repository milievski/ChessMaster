//*****************************************************************************
/// \file
/// \brief mainMenu header
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************
#ifndef MAINMENU_H
#define MAINMENU_H
#include "GenericMenu.h"
#include "../status.h"

class MainMenu : public GenericMenu
{
  public:
   
   MainMenu(){};


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
///1Player will be called by menufunc
/// create a game with one human player
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.
/// param[in] info is a classs holding global members for the players and
/// game
//***************************************************************************
void onePlayer(string &opt, GenericMenu* &ret,status* &info);

//***************************************************************************
///2player will be called by an menufunc
///create a game with two human players
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.
/// param[in] info is a classs holding global members for the players and
/// game
//***************************************************************************
void twoPlayer(string &opt, GenericMenu* &ret, status* &info);

//***************************************************************************
///Load will be called by menufunc
/// if called will make appropriate call for database
/// to load and start a saved game
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.
/// param[in] info is a classs holding global members for the players and
/// game
//***************************************************************************
   void load(string &opt, GenericMenu* &ret, status* info);

//***************************************************************************
///Replay will be called by menufunc
/// if called will make appropriate call for database
/// to load and replay a previous game
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.
   /// param[in] info is a classs holding global members for the players and
/// game
//***************************************************************************
   void replay(string &opt, GenericMenu* &ret, status* info);

//***************************************************************************
///Exit will be called by menufunc
/// if called will terminate the program.
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.   
//***************************************************************************
   void exit(string &opt, GenericMenu* &ret);

//***************************************************************************
///Login/Register will be called by an Event function,
/// if called will prompt the user login,
/// if the name does not exist, will register them.
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.   
//***************************************************************************
   void loginRegister(string &opt, GenericMenu* &ret);

//***************************************************************************
/// Tournament will be called by menufunc
/// this will show the user of a tournament.
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.   
//***************************************************************************
   void Tournament(string &opt,GenericMenu* &ret);
//***************************************************************************
/// LeaderBoard will be called by menufunc
/// this will show the user the LeaderBoard
/// \param[in] opt a reference for the program to decide where it must go in
/// the main
/// param[in] ret is a pointer of genericMenu tpye that is the pointer 
/// pointing at the current menu that is open.   
//***************************************************************************
  void leaderBoard(string &opt,GenericMenu* &ret);

//***************************************************************************
/// \brief EnterName is the function that draws the screen for user input
//***************************************************************************
   string EnterName();

};

  
#endif
