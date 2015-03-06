//*****************************************************************************
/// \file
/// \brief PauseMenu class
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************

#ifndef PAUSEMENU_CC
#define PAUSEMENU_CC

#include "PauseMenu.h"
#include <string>
#include <iomanip>
#include <iostream>
#include "LeaderBoard.h"
#include "MainMenu.h"
#include "../Database.h"
#include "../ChessBoard.h"
#include "../chessGameGUI.h"
#include "../Database.h"
#include <unistd.h>
using std::string;

   GenericMenu* PauseMenu::menufunc(string &opt, status* &info)
{
	Cprint("green", "bold");
	int curs=0, Ssize =0;
	char choice;
	const int OPT = 4;
	string option[OPT]= {"Save","Resume","Main","Exit"};

//save exit resume
	while(true)
	{
		system("clear");
		Cprint("green", "bold"); 
		cout << "|----------------|" << endl;
		cout << "|   Pause Menu   |" << endl;
		cout << "|----------------|" << endl;

		for(int x = 0; x < OPT;x++)
		{
			if (curs == x)
			{
				cout << '|';
				Cprint("red", "bold");
				cout << "  {";

				Cprint("blue", "bold");

				cout <<  option[x];
				Ssize = 13 -option[x].size();

				Cprint("red", "bold");

				cout << "}";
				Cprint("green", "bold");
				cout << std::setw(Ssize) << right << '|' << endl;


			}
			else
			{
				Cprint("green", "bold");
				cout << "|   ";
				cout << option[x];
				Ssize = 14 -option[x].size();
				cout << std::setw(Ssize) << right << '|' << endl;
			}

		}
		cout << "|----------------|";
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
				switch(curs)
				{
	       		case 0: save(info, ret); return ret; //save
				   case 1: resume(opt,ret);return ret;
				   case 2: main(opt,ret); return ret;
				   case 3: exit(opt,ret);return ret;
	   			}
			}
		}
	}
}

void PauseMenu::Cprint(string color, string type)
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

void PauseMenu::save(status* info, GenericMenu* &ret)
{
Database data;
char choice;
bool saveCheck = false;
while(!saveCheck)
{
	string name = EnterName();

	if(name == "testSaver")
	{
		for (int x = 1 ; x < 10000; x++)
		{
			name = "";
			name = std::to_string(x);

			data.saveGame(info->getGame()->getGameHistory(), name);

		}
		return;
	}

	if(!data.doesPlayerExist(name))
	{
		data.saveGame(info->getGame()->getGameHistory(), name);
		saveCheck = true;
	}
	else
	{
		system("clear");
		cout << "do you wish to overWrite?" << endl << "y = yes" << endl << "n = no";
		cin >> choice;
		if (choice == 'y')
		{
			data.saveGame(info->getGame()->getGameHistory(), name);
			saveCheck = true;
		}
		else if (choice == 'n')
		{
			cout << "please try again...";
			sleep(1);
		}
	}
}
	ret = new chessGameGUI;
}

void PauseMenu::resume(string &opt, GenericMenu* &ret)
{
   opt = "chess";
    ret = new chessGameGUI;
}
void PauseMenu::main(string &opt, GenericMenu* &ret)
{
   opt = "menu";
   ret = new MainMenu;
}

void PauseMenu::exit(string &opt, GenericMenu* &ret)
{
   opt = "exit";
   ret = nullptr;
}

void PauseMenu::leaderBoard(string &opt, GenericMenu* &ret)
{
   opt = "menu";
   ret = new LeaderBoard;
}


string PauseMenu::EnterName()
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
		cout << "|                      save game name                       |" << endl;
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
#endif
