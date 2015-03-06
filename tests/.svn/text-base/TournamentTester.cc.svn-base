#include <cppunit/extensions/HelperMacros.h>
#include "TournamentTester.h"
#include "../source/Tournament.h"

#include <vector>
using std::vector;

#include <map>
using std::map;

///Create variables to be used in testing
void TournamentTest::setUp() 
{

//2
vector<string> A = {"Alice", "Bob"};   
tourneyA = new Tournament(A);

//4
vector<string> B = {"Alice", "Bob", "Chris", "Dave"}; 
tourneyB = new Tournament(B);

//8
vector<string> C = {"Alice", "Bob", "Chris", "Dave", "Eric", "Frank", "George", "Hank"}; 
tourneyC = new Tournament(C);

//empty
vector<string> D; 
CPPUNIT_ASSERT_THROW(tourneyD = new Tournament(D), tournament_error);

//bad constructor
vector<string> E = {"Alice", "Bob", "Carl"}; 
CPPUNIT_ASSERT_THROW(tourneyE = new Tournament(E), tournament_error);



//map constructor
map<int, string> F;
F[1]  = ""; 
F[2]  = ""; 
F[3]  = "Eric"; 
F[4]  = "Alice"; 
F[5]  = "Dave"; 
F[6]  = "Eric"; 
F[7]  = "Hank"; 
F[8]  = "Alice"; 
F[9]  = "Bob"; 
F[10] = "Chris"; 
F[11] = "Dave"; 
F[12] = "Eric"; 
F[13] = "Frank"; 
F[14] = "George"; 
F[15] = "Hank"; 
tourneyF = new Tournament(F);

}

///Clean up any allocated variables
void TournamentTest::tearDown() 
{

//2
delete tourneyA;

//4
delete tourneyB;

//8
delete tourneyC;

//empty
delete tourneyD;

//bad constructor
delete tourneyE;

//map constructor
delete tourneyF;
}



///Testing get names
void TournamentTest::testGetNumPlayers()
{

CPPUNIT_ASSERT(tourneyA->getNumPlayers()==2);

CPPUNIT_ASSERT(tourneyB->getNumPlayers()==4);

CPPUNIT_ASSERT(tourneyC->getNumPlayers()==8);

CPPUNIT_ASSERT(tourneyF->getNumPlayers()==8);


}



///Testing get current match
void TournamentTest::testGetCurrentMatch()
{

CPPUNIT_ASSERT(tourneyA->getCurrentMatch()==1);

CPPUNIT_ASSERT(tourneyB->getCurrentMatch()==3);

CPPUNIT_ASSERT(tourneyC->getCurrentMatch()==7);

CPPUNIT_ASSERT(tourneyF->getCurrentMatch()==2);

}

///Testing get tournament size
void TournamentTest::testGetTournamentSize()
{

CPPUNIT_ASSERT(tourneyA->getTournamentSize()==3);

CPPUNIT_ASSERT(tourneyB->getTournamentSize()==7);

CPPUNIT_ASSERT(tourneyC->getTournamentSize()==15);

CPPUNIT_ASSERT(tourneyF->getTournamentSize()==15);

}

///Testing get next match
void TournamentTest::testGetNextMatch()
{

CPPUNIT_ASSERT(tourneyA->getNextMatch()==1);

CPPUNIT_ASSERT(tourneyB->getNextMatch()==2);

CPPUNIT_ASSERT(tourneyC->getNextMatch()==6);

CPPUNIT_ASSERT(tourneyF->getNextMatch()==1);

}

///Testing get match winner
void TournamentTest::testGetMatchWinner()
{
CPPUNIT_ASSERT(tourneyA->getMatchWinner(3)=="Bob");
CPPUNIT_ASSERT(tourneyA->getMatchWinner(2)=="Alice");
CPPUNIT_ASSERT(tourneyA->getMatchWinner(1)=="");


CPPUNIT_ASSERT(tourneyB->getMatchWinner(7)=="Dave");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(6)=="Chris");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(5)=="Bob");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(4)=="Alice");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(3)=="");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(2)=="");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(1)=="");


CPPUNIT_ASSERT(tourneyC->getMatchWinner(15)=="Hank");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(14)=="George");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(13)=="Frank");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(12)=="Eric");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(11)=="Dave");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(10)=="Chris");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(9)=="Bob");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(8)=="Alice");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(7)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(6)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(5)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(4)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(3)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(2)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(1)=="");


CPPUNIT_ASSERT(tourneyF->getMatchWinner(15)=="Hank");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(14)=="George");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(13)=="Frank");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(12)=="Eric");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(11)=="Dave");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(10)=="Chris");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(9)=="Bob");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(8)=="Alice");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(7)=="Hank");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(6)=="Eric");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(5)=="Dave");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(4)=="Alice");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(3)=="Eric");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(2)=="");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(1)=="");


}

///Testing set match winner
void TournamentTest::testSetMatchWinner()
{
CPPUNIT_ASSERT_THROW(tourneyA->setMatchWinner("Random"), tournament_error);
CPPUNIT_ASSERT_THROW(tourneyB->setMatchWinner("Random"), tournament_error);
CPPUNIT_ASSERT_THROW(tourneyC->setMatchWinner("Random"), tournament_error);
CPPUNIT_ASSERT_THROW(tourneyF->setMatchWinner("Random"), tournament_error);

tourneyA->setMatchWinner("Bob");
tourneyB->setMatchWinner("Dave");
tourneyC->setMatchWinner("George");
tourneyF->setMatchWinner("Alice");

CPPUNIT_ASSERT(tourneyA->getCurrentMatch()==1);

CPPUNIT_ASSERT(tourneyB->getCurrentMatch()==2);

CPPUNIT_ASSERT(tourneyC->getCurrentMatch()==6);

CPPUNIT_ASSERT(tourneyF->getCurrentMatch()==1);

CPPUNIT_ASSERT(tourneyA->getMatchWinner(3)=="Bob");
CPPUNIT_ASSERT(tourneyA->getMatchWinner(2)=="Alice");
CPPUNIT_ASSERT(tourneyA->getMatchWinner(1)=="Bob");


CPPUNIT_ASSERT(tourneyB->getMatchWinner(7)=="Dave");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(6)=="Chris");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(5)=="Bob");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(4)=="Alice");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(3)=="Dave");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(2)=="");
CPPUNIT_ASSERT(tourneyB->getMatchWinner(1)=="");


CPPUNIT_ASSERT(tourneyC->getMatchWinner(15)=="Hank");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(14)=="George");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(13)=="Frank");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(12)=="Eric");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(11)=="Dave");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(10)=="Chris");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(9)=="Bob");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(8)=="Alice");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(7)=="George");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(6)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(5)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(4)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(3)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(2)=="");
CPPUNIT_ASSERT(tourneyC->getMatchWinner(1)=="");


CPPUNIT_ASSERT(tourneyF->getMatchWinner(15)=="Hank");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(14)=="George");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(13)=="Frank");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(12)=="Eric");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(11)=="Dave");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(10)=="Chris");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(9)=="Bob");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(8)=="Alice");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(7)=="Hank");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(6)=="Eric");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(5)=="Dave");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(4)=="Alice");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(3)=="Eric");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(2)=="Alice");
CPPUNIT_ASSERT(tourneyF->getMatchWinner(1)=="");

}



