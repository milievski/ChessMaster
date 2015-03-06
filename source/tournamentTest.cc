#include <iostream>
#include <vector>
#include "Tournament.h"
#include "RegisteredPlayer.h"

using namespace std;


void printTourney (Tournament tourney) {

	int num=1;
for(int i=1; i<=tourney.getTournamentSize(); i++) 
{
	
if(num==1)
	cout << "                   ";

else if(num<4)
	cout << "           ";

else if(num<8)
	cout << "     ";


cout << i << ":";


if(i==tourney.getCurrentMatch())
	cout << " * "; 
else
cout << tourney.getMatchWinner(i) << ' ';



	if(num==i) 
	{
	num = num*2+1;
	cout << endl << endl;
	}


}
cout << endl;
}

int main() {

vector<string> players;

players.push_back("A");
players.push_back("B");
players.push_back("C");
players.push_back("D");
players.push_back("E");
players.push_back("F");
players.push_back("G");
players.push_back("H");


Tournament tourney(players, "elimination");

printTourney(tourney);

tourney.setMatchWinner("G");

printTourney(tourney);

cout << tourney.getMatchWinner(7) << endl;

vector<Memento*> testPlayers;

	return 0;
}