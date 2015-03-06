//*****************************************************************************
/// \file
/// \brief LeaderBoard class
///
/// \author Michael Wilson, Brandon Robertson.
/// \date October 26,2014
//*****************************************************************************

#include "LeaderBoard.h"
#include "MainMenu.h"
#include "../Database.h"


  GenericMenu* LeaderBoard::menufunc(string &opt, status* &info)
{
	Database data;
	vector<Memento*> names;
	names = data.getTopPlayers();
	RegisteredPlayer *Playerptr = new RegisteredPlayer;

	unsigned int curs = 0, loopProtect = 0;
	unsigned int SIZE_LEADER = names.size();
		if(names.size() == 0)
		return new MainMenu;


		char choice;	
	if (names.size() > 9)
		SIZE_LEADER = 9;

	while (true)
	{
		system("clear");
		printf("\033[09;32m");
		cout << "|    |                    |      |       |         |";
		printf("\033[00;32m");
		cout << endl << "| #  |        ";
		printf("\033[01;31m");
		cout <<"Name";
		printf("\033[00;32m");
		cout << "        |" ;
		printf("\033[0;35m");
		cout << "wins" ;
		printf("\033[00;32m");
		cout <<"  | " ;
		printf("\033[1;36m");
		cout <<  "loses";
		printf("\033[00;32m");
		cout << " |  ";
		printf("\033[0;34m");
		cout << "ELO";
		printf("\033[00;32m");
		cout << "    |" << endl;
		printf("\033[09;32m");
		cout << "|    |                    |      |       |         |" << endl;
		printf("\033[00;32m");



		if (curs > 3 && curs < names.size() -4)
		{
			loopProtect = curs - 4;
			SIZE_LEADER = curs + 5;
		}

		for (unsigned int x = loopProtect; x < SIZE_LEADER;x++)
		{

			cout << "|" << std::setw(4) << left <<  x  << "|"; 

			Playerptr->restoreMemento(names[x]);

			if (curs == x)
			{
				
			printf("\033[01;33m");
			cout << " " << std::setw(19) << left  << Playerptr->getName();
			printf("\033[00;32m");
			cout << '|';
			printf("\033[01;33m");
			cout << std::setw(6) << left<< Playerptr->getGamesWon();
			printf("\033[00;32m");
			cout << '|';
			printf("\033[01;33m");
			cout << std::setw(7) << left << Playerptr->getGamesLost();
			printf("\033[00;32m");
			cout << '|';
			printf("\033[01;33m");
			cout << std::setw(9) << left<< Playerptr->getElo();
			printf("\033[00;32m");
		}
		else
		{

			printf("\033[01;31m");
			cout << " " << std::setw(19) << left  << Playerptr->getName();
			printf("\033[00;32m");
			cout << '|';

			printf("\033[0;35m");
			cout << std::setw(6) << left<< Playerptr->getGamesWon();
			printf("\033[00;32m");

			cout << '|';

			printf("\033[1;36m");
			cout << std::setw(7) << left << Playerptr->getGamesLost();
			printf("\033[00;32m");

			cout << '|';

			printf("\033[0;34m");
			cout << std::setw(9) << left<<  Playerptr->getElo();
			printf("\033[00;32m");
		}

			cout << '|' << endl;
			printf("\033[09;32m");
			cout << "|    |                    |      |       |         |" << endl;
			printf("\033[00;32m");
		}
				cout << "press esc to go back!" << endl;
		
		cin >> choice;
		if(choice == 27)
		{
			return new MainMenu;
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

void LeaderBoard::Cprint(string color, string type)
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

void LeaderBoard::exit(string &opt, GenericMenu* &ret)
{

}

void LeaderBoard::main(bool &ml, bool &gl)
{

}
   
void LeaderBoard::getPlayer()
{

}


