//*****************************************************************************
/// \file
/// \brief mainMenu class
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************


#ifndef MAINMENU_CC
#define MAINMENU_CC

#include "MainMenu.h"
#include "GenericMenu.h"
#include <iostream>
#include <iomanip>
#include "LeaderBoard.h"
#include "TournamentMenu.h"
#include "LoginMenu.h"
#include "../chessGameGUI.h"
#include "../status.h"
#include "../Players/Player.h"
#include "../Database.h"
#include "../Errors.h"



GenericMenu* MainMenu::menufunc(string &opt, status* &info)
{
	Cprint("green", "bold");
	unsigned int curs=0, Ssize =0;
	char choice;
	const unsigned int OPT = 8;
	string option[OPT]= {"One Player","Two Player", "LeaderBoard", "Tournament","Load", "replay", "login/Register" ,"Exit"};

//save exit resume
	while(true)
	{
		system("clear");
		Cprint("green", "bold"); 
		cout << "|----------------|" << endl;
		cout << "|  Main Menu     |" << endl;
		cout << "|----------------|" << endl;
		for(unsigned int x = 0; x < OPT;x++)
		{
			if (curs == x)
			{
				cout << '|';
				Cprint("red", "bold");
				cout << "{";

				Cprint("blue", "bold");

				cout <<  option[x];
				Ssize = 15 -option[x].size();

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
				Ssize = 16 -option[x].size();
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
				   case 0: onePlayer(opt, ret, info); return ret;
				   case 1: twoPlayer(opt, ret, info); return ret;
				   	case 2: leaderBoard(opt,ret); return ret;
				   	case 3: Tournament(opt,ret); return ret;
				   	
				   	case 4: 
				   	load(opt,ret, info); 
				   	if (ret != nullptr)
				   		return ret;
				   	else
				   		break;
				   	break;

				   	case 5: 
				   	replay(opt,ret, info); 
				   	if (ret != nullptr)
				   		return ret;
				   	else
				   		break;
				   	break;

				   	case 6:	loginRegister(opt, ret); return ret;
				   	case 7: exit(opt,ret);return ret;
	   			}
			}
		}
	}
}

void MainMenu::Cprint(string color, string type)
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

void MainMenu::onePlayer(string &opt, GenericMenu* &ret, status* &info)
{//Single player needs to set the second player to be an AI
   ret = new chessGameGUI;
   opt = "Game";
   

}

void MainMenu::twoPlayer(string &opt, GenericMenu* &ret, status* &info)
{// the second player should be defaulted, no change in status necessary here
   //except if the player played a single player, then player 2 needs to become a guest
   ret = new chessGameGUI;
   opt = "Game";
   if(info->isAI()==true)
   {
      info->loadP2(new RegisteredPlayer());
   }
      

}

void MainMenu::load(string &opt, GenericMenu* &ret, status* info)
{

	string name = EnterName();
	if (name != "")
	{
		try
		{
			info->setReplayVector(name);

		}
		catch(database_load_error e)
		{
			cout << "no files in database";
		}
 		info->setLoad(true);
 		info->Replay();
 		ret = new chessGameGUI;
 	}
 	else
 	{
 		ret = nullptr;
 	}
 }


void MainMenu::replay(string &opt, GenericMenu* &ret, status* info)
{

	string name = EnterName();
	if (name != "")
	{
		try
		{
			info->setReplayVector(name);

		}
		catch(database_load_error e)
		{
			cout << "no files in database";
		}
 		info->setLoad(false);
 		info->Replay();
 		ret = new chessGameGUI;
 	}
 	else
 	{
 		ret = nullptr;
 	}
}

void MainMenu::loginRegister(string &opt, GenericMenu* &ret)
{
	ret = new LoginMenu;
	opt = "Menu";
	
}

void MainMenu::exit(string &opt,GenericMenu* &ret)
{						
   opt = "exit";
   ret = nullptr;
}
void MainMenu::Tournament(string &opt,GenericMenu* &ret)
{
	opt = "Menu";
	ret = new TournamentMenu;
}

void MainMenu::leaderBoard(string &opt,GenericMenu* &ret)
{
	opt = "Menu";
	ret = new LeaderBoard;
}

string MainMenu::EnterName()
{
	Cprint("green");
	Database data;
	vector<string> names;
	names = data.getSaveList();
	if(names.size() == 0)
		return "";


	unsigned int curs = 0, loopProtect = 0;
	unsigned int SIZE_LEADER = names.size();

	char choice;	
	if (names.size() > 9)
		SIZE_LEADER = 9;

	while (true)
	{ 	// title
		system("clear");
		printf("\033[09;32m");
		cout << "|    |                                             |" << endl;
		Cprint("green");
		cout << "| #  |          LoadFile Name                      |" << endl;
		Cprint("green", "slash");
		cout << "|    |                                             |" << endl;
		printf("\033[00;32m");

			if (curs > 3 && curs < names.size() -4)
			{
				loopProtect = curs - 4;
				SIZE_LEADER = curs + 5;
			}

		for (unsigned int x = loopProtect; x < SIZE_LEADER;x++)
		{

				cout << "|" << std::setw(4) << left << x << "|"; 



		if (curs == x)
		{
			printf("\033[01;33m");
			cout << " " << std::setw(44) << left  << names[x];
			printf("\033[00;32m");
	
		}
		else
		{

			printf("\033[01;31m");
			cout << " " << std::setw(44) << left  << names[x];
			printf("\033[00;32m");
			
		}

			cout << '|' << endl;
			printf("\033[09;32m");
			cout << "|                                                 |" << endl;
			printf("\033[00;32m");
		}
				cout << "press esc to go back!" << endl;
		
		cin >> choice;
		if (choice == 27)
			return "";
		if(choice == 'm')
		{
			return names[curs];
		}

		else if(choice == 's' && curs != names.size() - 1)
		{
			curs++;
		}
		else if(choice == 'w' && curs != 0 )
		{
			curs--;
		}

	}

}

#endif
