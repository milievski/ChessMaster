//*****************************************************************************
/// \file
/// \brief tournament class.
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************

#include <iostream>
#include <string>
using std::string;
#include <iomanip>
#include "TournamentMenu.h"
#include "GenericMenu.h"
#include "MainMenu.h"
#include <cassert>
#include "../Tournament.h"
#include "../Database.h"
#include "../Players/Player.h"
#include <map>

using namespace std;

   GenericMenu* TournamentMenu::menufunc(string &opt, status* &info)
{
   bool isFirstVisit = true; 
   //determine the height the tree will be
   int height, spacingStart=0, spacingMiddle=10;

//draw the tournament from the top down!
   int curs = 0;
   
   int OPT = 3;
   Tournament* tour = nullptr;  
   while(true)
   {
      system("clear");
     
      if(!isFirstVisit && tour != nullptr)
      {  
	 Cprint("green");

	 assert(tour->getNumPlayers() == 2 || tour->getNumPlayers() == 4 || tour->getNumPlayers() == 8);	
		 
	 switch(tour->getNumPlayers())
	 {
	    case 2: height = 2; spacingStart = 10; spacingMiddle = 30;;break;
	    case 4: height = 3; spacingStart = 30; spacingMiddle = 70;break;
	    case 8: height = 4; spacingStart = 70; spacingMiddle = 150;break;
	    default: assert(false && "ERROR NUM TOURNAMENT PLAYERS != 2 || 4 || 8");
	 }
	 int counterRanks=1;
	 int playersAtLvl = 1;
	 for (int i=height-1; i>=0; i--)
	 {
	    //draw each individual box, each box is made of 3 rows ****************
	    for (int j=0;j<playersAtLvl; j++)//drawing the top row to a level
	    {
	       if(j==0)
	       {
		  cout<<setw(spacingStart)<<"";
	       }
	       cout<<"**********";
	       if(i != height-1)
	       {
		  cout<<setw(spacingMiddle)<<"";
	       }
	    }
	    cout<<endl;
	    //*********************************************************************

	 
	    string colorChoice;
	    switch(i)
	    {
	       case 3: colorChoice="red"; break;
	       case 2: colorChoice="blue"; break;
	       case 1: colorChoice="magenta"; break;
	       case 0: colorChoice="cyan"; break;
	    };

	 
	    //drawing the middle row to a level*********************************
	    for (int j=0;j<playersAtLvl; j++)
	    {
	       if(j==0)
	       {
		  cout<<setw(spacingStart)<<"";
	       }
	       int fspacing, lspacing;
	       fspacing = (8- (tour->getMatchWinner(counterRanks)).size() )/2;
	       lspacing = fspacing; 
	       if ((8- (tour->getMatchWinner(counterRanks)).size())%2 !=  0)
	       {
		  lspacing++;
	       }
	       cout<<"*"<<setw(fspacing)<<"";
	       Cprint(colorChoice);
	       cout<<tour->getMatchWinner(counterRanks);
	       Cprint("green");
	       cout<<setw(lspacing)<<""<<"*";
	       counterRanks++;
	       if(i!=height-1)
	       {
		  cout<<setw(spacingMiddle)<<"";
	       }	
	    }
	    cout<<endl;
	    //*********************************************************************
      
	    //drawing the bottom row to a level************************************
	    for (int j=0;j<playersAtLvl; j++)
	    {
	       if(j==0)
	       {
		  cout<<setw(spacingStart)<<"";
	       }
	       cout<<"**********";
	       if(i!=height-1)
	       {
		  cout<<setw(spacingMiddle)<<"";
	       }
	    }
//******************************************************************************

	 
	    cout<<endl;
	    spacingMiddle = spacingStart;
	    spacingStart = (spacingStart-10)/2;
	    playersAtLvl *=2;
	 }
      }
      drawMenu(OPT, curs);
      GenericMenu* ret;
      char choice;

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
	    switch(curs)
	    {
	       case 0:
		  makeTournament(tour);
		  isFirstVisit =false;
		  break;
	       case 1:
		  try
		  { 
		     loadTournament(tour);
		  }

		  catch(database_load_error e)
		  {
		     cout << "Error Loading/Making Tournament" << " Returning to main menu." << endl << endl;
		     main(opt, ret);
		     return ret; 
		  }
		  isFirstVisit =false;
		  break;
	       case 2:
		  main(opt, ret);
		  return ret; 
	    }	 
      }
      
   }
}
 
void TournamentMenu::main(string &opt, GenericMenu* &ret)
{
   opt = "menu";
   ret = new MainMenu;
}

void TournamentMenu::exit(string &opt, GenericMenu* &ret)
{
   opt = "exit";
   ret = nullptr;
}

void TournamentMenu::makeTournament(Tournament* &tourn)
{
   Database Data(DATABASE_LOCATION);
//   vector<Memento*> memento = Data.getTopPlayers(8);
//   Player* player = new RegisteredPlayer;
   char players;
   int intPlayers;
   char nameChar = 'q';
   string tournamentName;
   vector<string> names;
   bool invalidInput = true;
   while(true)
   { 
	 while(invalidInput)
	 {
	    cout<<endl<<"Please input the number of players you would like,"
		<<" valid input is 2 , 4 , 8, press ESC to cancel"<<endl;
	    cin>>players;
	    intPlayers = players-'0';
	    if(intPlayers == 2 || intPlayers == 4 || intPlayers == 8 || players == 27)
	    {
	       invalidInput = false;
	    }
	 }
      	 if(players != 27)
	 {
	    for(int i=0; i < intPlayers; i++)
	    {
	       string name ="";
	       while(nameChar != '\n')
	       {   
		  system("clear");
		  cout<<"Pease input the Name for the Player"<<i+1<<" (case_sensitive)"<<endl;	       	       
		  cout<<name<<endl;
		  cin>>noskipws>>nameChar;
		  if(nameChar != ' ' && nameChar != '\n')
		  {
		     name+=nameChar;	    
		  }
	       }
	       names.push_back(name);
	       nameChar = 'q';
	    }
	       while(nameChar != '\n')
	       {
	    
		  system("clear");
		  cout<<"Pease input the Name for the Tournament (case_sensitive)"<<endl;
		  cout<<tournamentName<<endl;
		  cin>>noskipws>>nameChar;
		  if(nameChar != ' ' && nameChar != '\n')
		  {
		     tournamentName+=nameChar;
		  }
	       }

	    
      }
      switch(players)
      {
	 case '2':
	 {
	    if(tourn != nullptr)
	    {
	       delete tourn;
	    }
	    tourn = new Tournament(names);
	    Data.saveTournament(*tourn, tournamentName);
	    return;
	 }

	 case '4':
	 {
	    if(tourn != nullptr)
	    {
	       delete tourn;
	    }
	    tourn = new Tournament(names);
	    Data.saveTournament(*tourn, tournamentName);
	    return;
	 }

	 case '8':
	 {
	    if(tourn != nullptr)
	    {
	       delete tourn;
	    }
	    tourn = new Tournament(names);
	    Data.saveTournament(*tourn, tournamentName);
	    return;
	 }

      
	 case 27:
	 {
	    return;
	 }

	 default: break;
      }
   }
     

}
void TournamentMenu::loadTournament(Tournament* &tourn)
{
   Database data(DATABASE_LOCATION);
   string tournamentName ="";
   char nameChar;
   map<int,string> output;

   while(nameChar != '\n')
   {

      system("clear");
      cout<<"Pease input the Name for the Tournament (case_sensitive)"<<endl;
      cout<<tournamentName<<endl;
      cin>>noskipws>>nameChar;
      if(nameChar != '\n' && nameChar != ' ')
      {
      tournamentName+=nameChar;
      }	
   }

   if(tourn != nullptr)
   {
      delete tourn;
   }
   tourn=new Tournament(data.loadTournament(tournamentName));
   return;
}

void TournamentMenu::drawMenu(int &OPT, int &curs)
{
   int Ssize;
   string option[] ={ "Make Tournament", "Load Tournament", "Main"};
   Cprint("green", "bold"); 
   cout << "|--------------------------|" << endl;
   cout << "|     Tournament Menu      |" << endl;
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
      
   }
   cout << "|--------------------------|" << endl << endl;
}
   

     
void TournamentMenu::Cprint(string color, string type)
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
