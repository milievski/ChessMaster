//*****************************************************************************
/// \file
/// \brief EndMenu
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************
#include "EndMenu.h"
#include <string>
#include <iomanip>
#include <iostream>
#include "LeaderBoard.h"
#include "MainMenu.h"
using std::string;

GenericMenu* EndMenu::menufunc(string &opt, status* &info)
{
	//curs is the cursor and sSize is the to make sure the boarder at the end is alligned properly
   	int curs=0, Ssize =0;
   	//choice is the character that will be what the person presses on the keyboard.
   	char choice;
   	//numButtons is the amount of buttons in the menu!
   	const int numButtons = 3;
   	string option[numButtons]= {"Leaderboard","Main","Exit"};

	//save exit resume
   	while(true)
   	{	//displays title
      	system("clear");
      	Cprint("green", "slash");
      	cout << "|                |"<< endl; 
      	Cprint("green");
      	cout << "| End Game Menu  |" << endl;
      	Cprint("green", "slash");
      	cout << "|                |" << endl;
      	Cprint("green");
      	for(int x = 0; x < numButtons;x++)
      	{
	 	if (curs == x)//displays the braces around the item that the cursor is over.
	 	{
	 		cout << '|';
	      	Cprint("red", "bold");
	    	cout << "   {";
	    	Cprint("blue", "bold");

	    	cout <<  option[x];
	    	Ssize = 12 -option[x].size();

	       	Cprint("red", "bold");

	       	cout << "}";
	       	Cprint("green");
	       	cout << std::setw(Ssize) << right << '|' << endl;
	 	}
	 	else
	 	{
	     	Cprint("green");
	    	cout << "|    ";
	 		cout << option[x];
	 		Cprint("green");
	 		Ssize = 13 -option[x].size();
	 		cout << std::setw(Ssize) << right << '|' << endl;
	 	}    
      }
      	Cprint("green", "slash");
      	cout << "|                |";
      	Cprint("green");
      	cin>>choice;
      	switch(choice)
      	{
	 	case 's'://moves cursor down
	 	{
	    	if(curs == numButtons -1)
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
	 	case 'w': // moves cursor up
	 	{
	    if(curs == 0)
	    {
	        curs = numButtons -1;
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
	    	GenericMenu* ret = nullptr;
	    	switch(curs)// three choices 
	    	{
	       		case 0: leaderboard(opt,ret); return ret;
	       		case 1: main(opt,ret); return ret;
	       		case 2: exit(opt, ret); return ret;
	    	}
	    
	 	}
		}
	}
}

void EndMenu::Cprint(string color, string type)
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
void EndMenu::main(string &opt, GenericMenu* &ret)
{
   opt = "menu";
   ret = new MainMenu;
}


void EndMenu::exit(string &opt, GenericMenu* &ret)
{
   opt = "exit";
   ret = nullptr;
}


void EndMenu::leaderboard(string &opt, GenericMenu* &ret)
{
   opt = "leaderboard";
   ret = new LeaderBoard;
   
}
