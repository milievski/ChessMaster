//*****************************************************************************
/// \file
/// \brief a base class for all menus.
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************
#ifndef GENERICMENU_H
#define GENERICMENU_H
#include <string>
using namespace std;
#include "../status.h"
//*****************************************************************************
/// GenericMenu super class of all menus.
//*****************************************************************************
class GenericMenu
{
  public:
   
//*****************************************************************************
/// destructor put in place for the sake of posible further suclasses needing adestructor.
//*****************************************************************************
   virtual ~GenericMenu() {};

//******************************************************************************
   /// \brief menufunc is the general handler for implementing the functionality
   /// of this menu class
   /// \param[in] opt a reference for the program to decide where it must go in
   /// the main
   /// param[in] status is a class to enable manipulation of the current game
   /// and players between classes
   //***************************************************************************
   virtual  GenericMenu* menufunc(string &opt, status* &info) = 0;
   

};



#endif
