//*****************************************************************************
/// \file
/// \brief loginMenu class
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************

#include "LoginMenu.h"
#include <string>
using std::string;
#include <iomanip>
#include <iostream>
#include "MainMenu.h"
#include "../Players/Player.h"
#include "../Players/RegisteredPlayer.h"
#include "../Database.h"
#include "../Definitions.h"


using namespace std;

GenericMenu* LoginMenu::menufunc(string &opt, status* &info)
{
	string playerOne, playerTwo;
	Cprint("green", "bold");
	int curs=0, Ssize =0;
	char choice;
	const int OPT = 5;

//save exit resume
	while(true)
	{
		drawOption(curs, Ssize, info);

		cin>>choice;
		switch(choice)
		{
			case 's':
			{
				if(curs == OPT - 1)
				{
					curs=0;
					break;
				}
				else
				{
					curs++;
					break;
				}
			}
			case 'w':
			{
				if(curs == 0)
				{
					curs=OPT - 1;
					break;
				}
				else
				{
					curs--;
					break;
				}
			}
			case 'm':
			{
			   GenericMenu* ret;
			   RegisteredPlayer* genericPlayer = new RegisteredPlayer;
			   switch(curs)
			   {
			      case 0:
				 loadCreatePlayer(EnterName(),genericPlayer);
				 info->loadP1(genericPlayer);
				 break;
			      case 1:
				 loadCreatePlayer(EnterName(),genericPlayer);
				 info->loadP2(genericPlayer);
				 break;
			      case 2:info->loadP1(genericPlayer); break;
			      case 3:info->loadP2(genericPlayer); break;
			      case 4: main(opt, ret); return ret;
			   }
			}
		}
	}
}

void LoginMenu::main(string &opt, GenericMenu* &ret)
{
   opt = "menu";
   ret= new MainMenu;
}

void LoginMenu::loadCreatePlayer(const string &name, RegisteredPlayer* &p)
{

   Database data;
   //DOES PLAYEREXIST IS ALWAYS RETURNING TRUE, KILLS FUNCTIONALITY HERE
   if(data.doesPlayerExist(name))
   {
      p->restoreMemento(data.loadPlayer(name));
   }
   else
   {
      //SAVED PLAYERS IS NOT CREATING ANY FILES EITHER
      data.savePlayer(p->generateMemento(), name);
      p->restoreMemento(data.loadPlayer(name));
   }
   
}


void LoginMenu::Cprint(const string color,const string type)
{
  printf("\033[0m");
  if (color == "default") // clear
    printf("\033[0m");

  if (color == "red") // red 31
    printf("\033[00;31m");

  if (color == "green") // green 32
    printf("\033[00;32m");

  if (color == "blue") // blue 34
    printf("\033[00;34m");

  if (color == "magenta") // magenta 35
    printf("\033[00;35m");

  if (color == "cyan") // cyan 36
    printf("\033[00;36m");

  if (color == "grey") // grey 37
    printf("\033[00;37m");

  if (type == "bold") // bold 1
    printf("\033[1m");

  if (type == "slash") // slash 9
    printf("\033[9m");

  }

string LoginMenu::EnterName()
{
	string name;
	while(true)
	{

		system("clear");
	
		//***************************************************************
		//Addendum: using the line noskipws, tells  cin to not overlook whitespace
		// Howard suggests we could use cin.get() as well.

		//NEED TO FIX FOR SITUATION THAT PLAYER 1 wants to change their name
		// but a player 2 is already made and we dont want to have to change their name after

		//HOW DO WE GIVE THE PLAYERS TO THE GAME? WE SHOULD DEFINATELY NOT CREATE THE GAME IN HERE
		//AND HAVING MENUFUNC REFERENCE IT WOULD MEAN RE-EVALUATING ALL MENUFUNCS
		//***************************************************************
	    char choice;
		cout << "|-----------------------------------------------------------|" << endl;
		cout << "|                       Login / Register                    |" << endl;
		cout << "|---------|-------------------------------------------------|" << endl;
		cout << "| player" ": |";
		Cprint("red", "bold");
		cout << setw(49) << left << name;
		Cprint("green", "bold");
		cout << '|' << endl;
		cout << "|---------|-------------------------------------------------|" << endl;

		cin >> noskipws >> choice;


		if ( ( (choice > 'a' -1 && choice < 'z' +1) || (choice > 'A' -1 && choice <'Z' +1) ) && name.size() != 49)
		{	
		      name += choice;
		}
	
		else if (choice == '' && name.size() != 0)
		{	   
		   name.erase(name.end() -1);
		}
	
		if(choice == '\n')//check if players presses enter
		{

		  return name;

		}
	}
}

void LoginMenu::drawOption(int curs, int Ssize, status* &info)
{
		
		const int OPT = 5;
		//all button options are in options
		string option[OPT]= {"login first player", "login second player", "logout first player" , "logout second player" , "back"};
		system("clear");
		Cprint("green", "bold"); 
		cout << "|--------------------------|" << endl;
		cout << "|  login register menu     |" << endl;
		cout << "|--------------------------|" << endl;
		for(int x = 0; x < OPT;x++)
		{
			if (curs == x)
			{
				cout << '|';
				Cprint("red", "bold");
				cout << "{";

				Cprint("blue", "bold");

				cout <<  option[x];
				Ssize = 25 -option[x].size();

				Cprint("red", "bold");

				cout << "}";
				Cprint("green", "bold");
				cout << std::setw(Ssize) << right << '|' << endl;


			}
			else
			{
				Cprint("green", "bold");
				cout << "| ";
				cout << option[x];
				Ssize = 26 -option[x].size();
				cout << std::setw(Ssize) << right << '|' << endl;
			}

		}//displays currently logged in
		cout << "|--------------------------|" << endl << endl;

		Cprint("red", "bold");
		cout << "|-------------------------------------------|" << endl;
		cout << "|           currently logged in             |" << endl;
		cout << "|-------------------------------------------|" << endl;
		cout << "|player: " ;
		Cprint("green", "bold");
		cout << setw(35) << left << info->getP1Name();
		Cprint("red", "bold");
		cout << "|"  << endl;
		cout << "|-------------------------------------------|" << endl;
		cout << "|player: ";
		Cprint("green", "bold"); 
		cout << setw(35) << left << info->getP2Name();
		Cprint("red", "bold");
		cout << "|" << endl;
		cout << "|-------------------------------------------|" << endl;
		Cprint("green", "bold");
}
